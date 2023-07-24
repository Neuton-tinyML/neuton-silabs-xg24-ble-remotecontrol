// ///////////////////////// Package Header Files ////////////////////////////
#include "neuton_remotectrl_app.h"
#include "neuton_result_postprocessing.h"
// ////////////////////// Package Group Header Files /////////////////////////
#include <neuton/neuton.h>
// /////////////////// Application Global Header Files ///////////////////////
#include <drivers/icm20689_utils.h>
#include <app_log.h>
#include <bluetooth/bluetooth.h>
#include <sl_simple_led_instances.h>
#include <sl_simple_button_instances.h>
// /////////////////// 3rd Party Software Header Files ///////////////////////
// ////////////////////// Standard C++ Header Files //////////////////////////
// /////////////////////// Standard C Header Files ///////////////////////////

//////////////////////////////////////////////////////////////////////////////


#define BLE_SEND_KEY_RESET_TIMEOUT_MS               (20U)
#define BLE_HOLD_KEY_RESET_TIMEOUT_MS               (550U)
#define BLE_AFTER_HOLD_KEY_RESET_TIMEOUT_MS         (180U)
#define BLE_ADVERTISING_LED_TOGGLE_PERIOD_MS        (500U)
#define BLE_CONNECTED_LED_TOGGLE_PERIOD_MS          (100U)
#define PREDICTION_TIMEOUT_MS                       (800U)
#define PREDICTION_TIMEOUT_US                       (PREDICTION_TIMEOUT_MS * 1000)
#define SLEEPTIMER_TICK_TO_US(x)                    ((uint64_t)(float)(x) * 30.5)
#define SLEEPTIMER_TICK_TO_MS(x)                    (SLEEPTIMER_TICK_TO_US(x) / 1000)

#define ICM20689_DATA_RATE_HZ                       (100)
#define ACCEL_AXIS_NUM                              (3U)
#define GYRO_AXIS_NUM                               (3U)
#define NEUTON_INPUT_DATA_LEN                       (ACCEL_AXIS_NUM + GYRO_AXIS_NUM)
#define BUTTON_PRESSED_STATE                        (1U)

//////////////////////////////////////////////////////////////////////////////

typedef enum
{
  LED_STATE_BLE_ADVERTISING_LED_ON = 0,///< LED_STATE_BLE_ADVERTISING_LED_ON
  LED_STATE_BLE_ADVERTISING_LED_OFF,   ///< LED_STATE_BLE_ADVERTISING_LED_OFF
  LED_STATE_BLE_CONNECTED_LED_ON,      ///< LED_STATE_BLE_CONNECTED_LED_ON
  LED_STATE_BLE_CONNECTED_LED_OFF,     ///< LED_STATE_BLE_CONNECTED_LED_OFF
} led_state_t;

typedef enum
{
  LED_INSTANCE_ID_RED = 0,    ///< LED_INSTANCE_ID_RED
  LED_INSTANCE_ID_GREEN       ///< LED_INSTANCE_ID_GREEN
} led_instance_id_t;

//////////////////////////////////////////////////////////////////////////////

static void icm20689_data_rdy_cb_(void);
static void neuton_prediction_subscriber_(const neuton_class_label_t class_label, 
                                        const float probability,
                                        const char* class_name);
static void send_bt_keyboard_key_(const neuton_class_label_t class_label);
static void led_indication_(void);

//////////////////////////////////////////////////////////////////////////////

/** ICM20689 sensor data ready flag */
static volatile bool icm20689_data_ready_ = false;

/** ICM20689 sensor operating configuration */
static icm20689_config_t icm20689_config_ = 
{
    .sensors =
    {
        .accel = true,
        .gyro = true
    },
     .datarate = ICM20689_DATA_RATE_HZ,
     .accel_fullscale = sl_accelFullscale4G,
     .gyro_fullscale = sl_gyroFullscale1000Dps,
     .on_data_rdy = &icm20689_data_rdy_cb_
};

/** Context of last sent keyboard key */
static struct
{
    uint32_t send_time_ms;
    uint16_t key_reset_timeout_ms;
    uint8_t previous_key;
    bool reset_send_request;
} bt_key_ctx_ = {0};

/** Current keyboard control mode */
static neuton_remotectrl_mode_t keyboard_ctrl_mode_ = NEUTON_REMOTECTRL_MODE_PRESENTATION;

/** Current active led color indication*/
static const sl_led_t* p_active_led_ = NULL;

/** Current active led indication state */
static led_state_t next_led_state_ = LED_STATE_BLE_ADVERTISING_LED_OFF;

//////////////////////////////////////////////////////////////////////////////

void neuton_remotectrl_app_init(void)
{
    app_log_info("Neuton.AI Gesture Recognition Demo for Remote Control Device\r\n");

    /** Setup power manager */
    sl_power_manager_add_em_requirement(SL_POWER_MANAGER_EM1);

    /** Initialize ICM20689 IMU sensor */
    sl_status_t err = icm20689_init(&icm20689_config_);
    EFM_ASSERT((err == SL_STATUS_OK));

    /** Initialize Neuton.AI library */
    neuton_nn_setup();

    EFM_ASSERT((neuton_nn_uniq_inputs_num() == NEUTON_INPUT_DATA_LEN));

    app_log_info("Neuton.AI solution id: %s\r\n", neuton_nn_solution_id_str());

    /** Enable user button */
    sl_button_enable(&sl_button_btn0);

    /** Set initial LED indication color */
    p_active_led_ =  sl_simple_led_array[LED_INSTANCE_ID_RED];
}

//////////////////////////////////////////////////////////////////////////////

void neuton_remotectrl_app_dowork(void)
{
    /** Handle LED indication */
    led_indication_();

    /** Check if there is a need to send RESET_KEY to release keyboard */
    if (bt_key_ctx_.reset_send_request)
    {
        uint64_t timestamp_ms = SLEEPTIMER_TICK_TO_MS(
            sl_sleeptimer_get_tick_count64());

        if ((timestamp_ms - bt_key_ctx_.send_time_ms) > bt_key_ctx_.key_reset_timeout_ms)
        {
            bt_key_ctx_.reset_send_request = false;
            bt_key_ctx_.previous_key = 0;
            sl_bt_reset_report();
        }
    }

    /** Check if the new sensor data samples is ready to read */
    if (!icm20689_data_ready_)
        return;

    icm20689_data_ready_ = false;

    neuton_input_t input_data[NEUTON_INPUT_DATA_LEN];
    sl_status_t err;

    /** Read real-time sensor data point */
    err = icm20689_read_raw_accel(input_data);
    EFM_ASSERT((err == SL_STATUS_OK));

    err = icm20689_read_raw_gyro(input_data + ACCEL_AXIS_NUM);
    EFM_ASSERT((err == SL_STATUS_OK));

    /** Feeding real-time sensor data point to Neuton library to collect data window */
    neuton_inference_input_t* p_input = neuton_nn_feed_inputs(input_data, NEUTON_INPUT_DATA_LEN);

    /** Check if input data window is ready for inference */
    if (p_input)
    {
        neuton_u16_t predicted_target;
        const neuton_output_t* p_probabilities;

        /** Run Neuton model inference */
        neuton_i16_t targets_num = neuton_nn_run_inference(p_input, &predicted_target,
                                                           &p_probabilities);

        /** Handle Neuton inference results if the prediction was successful */
        if (targets_num > 0)
        {
            neuton_result_postprocess(predicted_target, p_probabilities[predicted_target],
                                        neuton_prediction_subscriber_);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

void neuton_remotectrl_app_set_mode(const neuton_remotectrl_mode_t mode)
{
    keyboard_ctrl_mode_ = mode;
}

//////////////////////////////////////////////////////////////////////////////

static void icm20689_data_rdy_cb_(void)
{
    icm20689_data_ready_ = true;
}

//////////////////////////////////////////////////////////////////////////////

static void neuton_prediction_subscriber_(const neuton_class_label_t class_label, 
                                        const float probability,
                                        const char* class_name)
{
    if (class_label > NEUTON_LABEL_UNKNOWN)
    {
        static uint32_t last_prediction_time_ms_ = 0;
        uint32_t current_time_ms = SLEEPTIMER_TICK_TO_MS(sl_sleeptimer_get_tick_count64());

        /** For classes NEUTON_LABEL_ROTATION_RIGHT & NEUTON_LABEL_ROTATION_LEFT there is no timeout,
         * since the movements must be repetitive in time
         */
        if ((class_label == NEUTON_LABEL_ROTATION_RIGHT) ||
            (class_label == NEUTON_LABEL_ROTATION_LEFT) ||
            (current_time_ms - last_prediction_time_ms_) > PREDICTION_TIMEOUT_MS)
        {
            last_prediction_time_ms_ = current_time_ms;

            app_log_info("Predicted class: %s, with probability %0.3f\r", class_name, probability);

            send_bt_keyboard_key_(class_label);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////

static void send_bt_keyboard_key_(const neuton_class_label_t class_label)
{
  bt_key_ctx_.key_reset_timeout_ms = BLE_SEND_KEY_RESET_TIMEOUT_MS;

  if (keyboard_ctrl_mode_ == NEUTON_REMOTECTRL_MODE_PRESENTATION)
  {
      switch (class_label)
      {
      case NEUTON_LABEL_SWIPE_LEFT:
          current_report_page = REPORT_PAGE_KEYBOARD;
          current_key = KEY_ARROW_LEFT;
          break;
      case NEUTON_LABEL_SWIPE_RIGHT:
          current_report_page = REPORT_PAGE_KEYBOARD;
          current_key = KEY_ARROW_RIGHT;
          break;
      case NEUTON_LABEL_DOUBLE_TAP:
          current_report_page = REPORT_PAGE_KEYBOARD;
          current_key = KEY_F5;
          break;
      case NEUTON_LABEL_DOUBLE_THUMB:
          current_report_page = REPORT_PAGE_KEYBOARD;
          current_key = KEY_ESC;
          break;
      default:
          return;
      }
  }
  else // keyboard_ctrl_mode_ == NEUTON_REMOTECTRL_MODE_MUSIC
  {
      switch(class_label)
      {
        case NEUTON_LABEL_SWIPE_LEFT:
          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_PREV_TRACK;
          break;
        case NEUTON_LABEL_SWIPE_RIGHT:
          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_NEXT_TRACK;
          break;
        case NEUTON_LABEL_DOUBLE_TAP:
          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_PLAYPAUSE;
          break;
        case NEUTON_LABEL_DOUBLE_THUMB:
          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_MUTE;
          break;
        case NEUTON_LABEL_ROTATION_LEFT:
          if (bt_key_ctx_.previous_key == KEY_MEDIA_VOLUMEDOWN)
            bt_key_ctx_.key_reset_timeout_ms = BLE_AFTER_HOLD_KEY_RESET_TIMEOUT_MS;
          else
            bt_key_ctx_.key_reset_timeout_ms = BLE_HOLD_KEY_RESET_TIMEOUT_MS;

          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_VOLUMEDOWN;
          break;
        case NEUTON_LABEL_ROTATION_RIGHT:
          if (bt_key_ctx_.previous_key  == KEY_MEDIA_VOLUMEUP)
            bt_key_ctx_.key_reset_timeout_ms = BLE_AFTER_HOLD_KEY_RESET_TIMEOUT_MS;
          else
            bt_key_ctx_.key_reset_timeout_ms = BLE_HOLD_KEY_RESET_TIMEOUT_MS;

          current_report_page = REPORT_PAGE_MEDIA;
          current_key = KEY_MEDIA_VOLUMEUP;
          break;
        default:
          return;
      }
    }

    /** Check if the reset key was sent after the previous key */
    if (bt_key_ctx_.reset_send_request == false)
    {
        /** Request the Bluetooth stack to send keyboard key */
        sl_bt_external_signal(1);
    }

    /** Request RESET key to release keyboard */
    bt_key_ctx_.send_time_ms = SLEEPTIMER_TICK_TO_MS(sl_sleeptimer_get_tick_count64());
    bt_key_ctx_.reset_send_request = true;
    bt_key_ctx_.previous_key = current_key;
}

//////////////////////////////////////////////////////////////////////////////

static void led_indication_(void)
{
  static uint32_t previous_toggle_time = 0;

  static const uint32_t LED_STATE_VS_PERIOD_MS[] =
  {
      [LED_STATE_BLE_ADVERTISING_LED_ON]  = 25,
      [LED_STATE_BLE_ADVERTISING_LED_OFF] = 1000,
      [LED_STATE_BLE_CONNECTED_LED_ON]    = 25,
      [LED_STATE_BLE_CONNECTED_LED_OFF]   = 200,
  };

  uint32_t current_time_ms = SLEEPTIMER_TICK_TO_MS(sl_sleeptimer_get_tick_count64());

  if (current_time_ms - previous_toggle_time >= LED_STATE_VS_PERIOD_MS[next_led_state_])
  {
      sl_led_toggle(p_active_led_);
      previous_toggle_time = current_time_ms;

      switch(next_led_state_)
      {
        case LED_STATE_BLE_ADVERTISING_LED_ON:
          next_led_state_ = sl_bt_is_connected() ? LED_STATE_BLE_CONNECTED_LED_OFF : LED_STATE_BLE_ADVERTISING_LED_OFF;
          break;
        case LED_STATE_BLE_ADVERTISING_LED_OFF:
          next_led_state_ = LED_STATE_BLE_ADVERTISING_LED_ON;
          break;
        case LED_STATE_BLE_CONNECTED_LED_ON:
          next_led_state_ = sl_bt_is_connected() ? LED_STATE_BLE_CONNECTED_LED_OFF : LED_STATE_BLE_ADVERTISING_LED_OFF;
          break;
        case LED_STATE_BLE_CONNECTED_LED_OFF:
          next_led_state_ = LED_STATE_BLE_CONNECTED_LED_ON;
          break;
        default:
          return;
      }
  }
}

//////////////////////////////////////////////////////////////////////////////

// Weak redefinition of button handler
void sl_button_on_change(const sl_button_t* p_handle)
{
    if (p_handle->get_state(p_handle) == BUTTON_PRESSED_STATE)
    {
        /** Change LED indication state */
        sl_led_turn_off(p_active_led_);
        next_led_state_ = sl_bt_is_connected() ?
                            LED_STATE_BLE_CONNECTED_LED_OFF :
                            LED_STATE_BLE_ADVERTISING_LED_OFF;

        /** Change Keyboard control mode and led indication color by user button click */
        if (keyboard_ctrl_mode_ == NEUTON_REMOTECTRL_MODE_PRESENTATION)
        {
            keyboard_ctrl_mode_ = NEUTON_REMOTECTRL_MODE_MUSIC;
            p_active_led_ = sl_simple_led_array[LED_INSTANCE_ID_GREEN];
        }
        else
        {
            keyboard_ctrl_mode_ = NEUTON_REMOTECTRL_MODE_PRESENTATION;
            p_active_led_ = sl_simple_led_array[LED_INSTANCE_ID_RED];
        }
    }
}
