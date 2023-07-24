/* 2023-06-09T11:22:25Z */

/* ----------------------------------------------------------------------
Copyright (c) 2022-2023 Neuton.AI, Inc.
*
The source code and its binary form are being made available on the following terms:
Redistribution, use, and modification are permitted provided that the following
conditions are met:
*
1. Redistributions of source code and/or its binary form must retain the above copyright notice,
* this list of conditions (and the disclaimer) either in the body of the source code or in
* the documentation and/or other materials provided with the distribution of the binary form, as
applicable.
*
2. The name of the copyright holder may not be used to endorse or promote products derived from this
* source code or its binary form without specific prior written permission of Neuton.AI, Inc.
*
3. Disclaimer. THIS SOURCE CODE AND ITS BINARY FORM ARE PROVIDED BY THE COPYRIGHT HOLDER "AS IS".
* THE COPYRIGHT HOLDER HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
* BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE HELD LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS
* OF THIRD PARTIES; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOURCE CODE OR ITS BINARY FORM, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------- */

#ifndef ICM20689_UTILS_H_
#define ICM20689_UTILS_H_

#include <sl_icm20689.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief 
 * 
 */
typedef void (*icm20689_on_data_rdy_cb_t)(void);

/**
 * @brief ICM20689 IMU sensor configuration
 * 
 */
typedef struct
{
    /** Sensors to enable */
    struct
    {
        bool accel : 1;
        bool gyro : 1;
    } sensors;

    /** Output data rate, Hz*/
    float datarate;

    /** Accelerometer full scale */
    sl_accel_full_scale_t accel_fullscale;

    /** Gyroscope full scale */
    sl_gyro_full_scale_t gyro_fullscale;

    /** Data Ready Callback */
    icm20689_on_data_rdy_cb_t on_data_rdy;
} icm20689_config_t;

/**
 * @brief Initialize ICM20689 IMU sensor
 * 
 * @param[in] p_config      Sensor configuration @ref icm20689_config_t
 * 
 * @return @ref sl_status_t 
 */
sl_status_t icm20689_init(const icm20689_config_t* const p_config);

/**
 * @brief Start ICM20689 IMU sensor data sampling, wake up from sleep mode
 * 
 * @return @ref sl_status_t 
 */
sl_status_t icm20689_start(void);

/**
 * @brief Stop ICM20689 IMU sensor data sampling, put to sleep mode
 * 
 * @return @ref sl_status_t 
 */
sl_status_t icm20689_stop(void);

/**
 * @brief Read Accelerometer RAW data
 * 
 * @param[out] accel_raw_data    XYZ-axis of accelerometer
 * 
 * @return @ref sl_status_t
 */
sl_status_t icm20689_read_raw_accel(int16_t accel_raw_data[3]);

/**
 * @brief Read Gyroscope RAW data
 * 
 * @param[out] gyro_raw_data    XYZ-axis of gyroscope
 * 
 * @return @ref sl_status_t 
 */
sl_status_t icm20689_read_raw_gyro(int16_t gyro_raw_data[3]);


#endif /* ICM20689_UTILS_H_ */
