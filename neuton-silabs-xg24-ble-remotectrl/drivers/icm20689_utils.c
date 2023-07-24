// ///////////////////////// Package Header Files ////////////////////////////
#include "icm20689_utils.h"
// ////////////////////// Package Group Header Files /////////////////////////
#include <sl_icm20689.h>
#include <sl_icm20689_config.h>
// /////////////////// Application Global Header Files ///////////////////////
#include <gpiointerrupt.h>
#include <em_cmu.h>
// /////////////////// 3rd Party Software Header Files ///////////////////////
// ////////////////////// Standard C++ Header Files //////////////////////////
// /////////////////////// Standard C Header Files ///////////////////////////
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////

static icm20689_config_t icm20689_ctx_ = {0};

//////////////////////////////////////////////////////////////////////////////

static void data_ready_callback_(uint8_t interrupt_no, void *ctx)
{
    if (icm20689_ctx_.on_data_rdy)
        icm20689_ctx_.on_data_rdy();
}

//////////////////////////////////////////////////////////////////////////////

sl_status_t icm20689_init(const icm20689_config_t* const p_config)
{
    if (p_config == NULL)
        return false;

    icm20689_ctx_ = *p_config;

    sl_status_t status;

    status = sl_icm20689_init();
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_enable_interrupt(false, false);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_enable_sensor(false, false, false);
    EFM_ASSERT((status == SL_STATUS_OK));

    sl_icm20689_set_sample_rate(icm20689_ctx_.datarate);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_accel_set_full_scale(icm20689_ctx_.accel_fullscale);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_gyro_set_full_scale(icm20689_ctx_.gyro_fullscale);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_enable_sensor(icm20689_ctx_.sensors.accel,
                                       icm20689_ctx_.sensors.gyro,
                                       false);
    EFM_ASSERT((status == SL_STATUS_OK));

    sl_icm20689_set_sample_rate(icm20689_ctx_.datarate);

    /* 246Hz BW for the accelerometer and 200Hz for the gyroscope */
    status = sl_icm20689_accel_set_bandwidth(sl_accelBandwidthDlpf218_1_0Hz);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_gyro_set_bandwidth(sl_gyroBandwidthDlpf176Hz);
    EFM_ASSERT((status == SL_STATUS_OK));

    /* Disable the FIFO */
    status = sl_icm20689_write_register(ICM20689_REG_CONFIG,
                                        ICM20689_CONFIG_BIT_FIFO_MODE);
    EFM_ASSERT((status == SL_STATUS_OK));

    /* Enable gyro low power mode */
    status = sl_icm20689_write_register(ICM20689_REG_LP_MODE_CFG, 1 << 7);
    EFM_ASSERT((status == SL_STATUS_OK));

    status = sl_icm20689_enable_interrupt(true, false);
    EFM_ASSERT((status == SL_STATUS_OK));

    unsigned int interrupt;

    CMU_ClockEnable(cmuClock_GPIO, true);

    GPIO_PinModeSet(SL_ICM20689_INT_PORT,
                    SL_ICM20689_INT_PIN,
                    gpioModeInput, 0U);

    GPIOINT_Init();

    interrupt = GPIOINT_CallbackRegisterExt(
        SL_ICM20689_INT_PIN,
        (GPIOINT_IrqCallbackPtrExt_t)data_ready_callback_,
        NULL);

    EFM_ASSERT(interrupt != INTERRUPT_UNAVAILABLE);

    GPIO_ExtIntConfig(SL_ICM20689_INT_PORT,
                      SL_ICM20689_INT_PIN,
                      interrupt,
                      true,
                      false,
                      true);

    return status;
}

//////////////////////////////////////////////////////////////////////////////

sl_status_t icm20689_read_raw_accel(int16_t accel_raw_data[3])
{
    int16_t temp;
    uint8_t raw_data[6] = {0};

    /* Read the six raw data registers into data array */
    sl_status_t status = sl_icm20689_read_register(ICM20689_REG_ACCEL_XOUT_H, 6, &raw_data[0]);

    if (status != SL_STATUS_OK)
        return status;

    /* Convert the MSB and LSB into a signed 16-bit value and multiply by the resolution to get the dps value */
    temp = ((int16_t)raw_data[0] << 8) | raw_data[1];
    accel_raw_data[0] = temp;

    temp = ((int16_t)raw_data[2] << 8) | raw_data[3];
    accel_raw_data[1] = temp;

    temp = ((int16_t)raw_data[4] << 8) | raw_data[5];
    accel_raw_data[2] = temp;

    return status;
}

//////////////////////////////////////////////////////////////////////////////

sl_status_t icm20689_read_raw_gyro(int16_t gyro_raw_data[3])
{
    int16_t temp;
    uint8_t raw_data[6] = {0};

    /* Read the six raw data registers into data array */
    sl_status_t status = sl_icm20689_read_register(ICM20689_REG_GYRO_XOUT_H, 6, &raw_data[0]);

    if (status != SL_STATUS_OK)
        return status;

    /* Convert the MSB and LSB into a signed 16-bit value and multiply by the resolution to get the dps value */
    temp = ((int16_t)raw_data[0] << 8) | raw_data[1];
    gyro_raw_data[0] = temp;

    temp = ((int16_t)raw_data[2] << 8) | raw_data[3];
    gyro_raw_data[1] = temp;

    temp = ((int16_t)raw_data[4] << 8) | raw_data[5];
    gyro_raw_data[2] = temp;

    return status;
}

//////////////////////////////////////////////////////////////////////////////

sl_status_t icm20689_start(void)
{
    return sl_icm20689_enable_sleep_mode(false);
}

//////////////////////////////////////////////////////////////////////////////

sl_status_t icm20689_stop(void)
{
    return sl_icm20689_enable_sleep_mode(true);
}
