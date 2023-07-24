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

/**
 *
 * @defgroup neuton_remotectrl_app Neuton BLE Remote Control Demo Application
 * @{
 *
 * @details     This demo application allows the user to connect Silabs xG24 devkit to a PC and 
 *              use it to control the keyboard or music with different gestures.
 * 
 *              The Neuton model can recognize 6 different gestures:
 *                  - Swipe Right
 *                  - Swipe Left
 *                  - Double Tap
 *                  - Double Thumb
 *                  - Rotation Clockwise (Right)
 *                  - Rotation Counter Clockwise (Left)
 *              More information about gestures you can find in the README.md file
 * 
 *              You can choose application behavior via neuton_remotectrl_app_set_mode() API call,
 *              @see  neuton_remotectrl_mode_t for more details.
 *
 */
#ifndef NEUTON_REMOTE_CONTROL_APPLICATION_H_
#define NEUTON_REMOTE_CONTROL_APPLICATION_H_

#include <stdint.h>

/**
 * @brief Application remote control mode
 *
 */
typedef enum neuton_remotectrl_mode_e
{
    /**
     * NEUTON_REMOTECTRL_MODE_PRESENTATION used for slides control:
     * - Swipe Right                       = KEY_ARROW_RIGHT (Next slide)
     * - Swipe Left                        = KEY_ARROW_LEFT  (Previous slide)
     * - Double Tap                        = KEY_F5          (Enter fullscreen mode)
     * - Double Thumb                      = KEY_ESC         (Exit fullscreen mode)
     * - Rotation Clockwise (Right)        = Not used
     * - Rotation Counter Clockwise (Left) = Not used
     *
     */
    NEUTON_REMOTECTRL_MODE_PRESENTATION = 0,

    /**
     * NEUTON_REMOTE_CTRL_MUSIC used for music/media control:
     * - Swipe Right                       = KEY_MEDIA_NEXT_TRACK  (Next track)
     * - Swipe Left                        = KEY_MEDIA_PREV_TRACK  (Previous track)
     * - Double Tap                        = KEY_MEDIA_PLAYPAUSE   (Play/Pause)
     * - Double Thumb                      = KEY_MEDIA_MUTE        (Mute)
     * - Rotation Clockwise (Right)        = KEY_MEDIA_VOLUMEUP    (Volume Up)
     * - Rotation Counter Clockwise (Left) = KEY_MEDIA_VOLUMEDOWN  (Volume Down)
     */
    NEUTON_REMOTECTRL_MODE_MUSIC
} neuton_remotectrl_mode_t;

/**
 * @brief Initialize Ble Remote Control Demo application 
 * 
 */
void neuton_remotectrl_app_init(void);

/**
 * @brief Main process of Ble Remote Control Demo application
 * 
 */
void neuton_remotectrl_app_dowork(void);

/**
 * @brief Set remote control mode @see neuton_remotectrl_mode_t for details
 *
 * @param[in] mode  Keyboard control mode @ref neuton_remotectrl_mode_t
 *
 */
void neuton_remotectrl_app_set_mode(const neuton_remotectrl_mode_t mode);


#endif /* NEUTON_REMOTE_CONTROL_APPLICATION_H_ */

/**
 * @}
 */
