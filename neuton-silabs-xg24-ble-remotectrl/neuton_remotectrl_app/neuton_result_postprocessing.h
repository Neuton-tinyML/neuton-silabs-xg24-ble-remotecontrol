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
#ifndef NEUTON_RESULT_POSTPROCESSING_H__
#define NEUTON_RESULT_POSTPROCESSING_H__

#include <stdint.h>

typedef enum
{
    NEUTON_LABEL_IDLE,            ///< NEUTON_LABEL_IDLE
    NEUTON_LABEL_UNKNOWN,         ///< NEUTON_LABEL_UNKNOWN
    NEUTON_LABEL_SWIPE_RIGHT,     ///< NEUTON_LABEL_SWIPE_RIGHT
    NEUTON_LABEL_SWIPE_LEFT,      ///< NEUTON_LABEL_SWIPE_LEFT
    NEUTON_LABEL_DOUBLE_TAP,      ///< NEUTON_LABEL_DOUBLE_TAP
    NEUTON_LABEL_DOUBLE_THUMB,    ///< NEUTON_LABEL_DOUBLE_THUMB
    NEUTON_LABEL_ROTATION_RIGHT,  ///< NEUTON_LABEL_ROTATION_RIGHT
    NEUTON_LABEL_ROTATION_LEFT,   /// < NEUTON_LABEL_ROTATION_LEFT
} neuton_class_label_t;

/**
 * @brief Inference Result (prediction) ready user callback
 * 
 * @param[in] class_label   Label of the predicted class @ref neuton_class_label_t
 * @param[in] probability   Probability of the predicted class   
 * @param[in] class_name    Name of predicted class, null-terminated string
 * 
 */
typedef void (*neuton_result_rdy_cb_t)(const neuton_class_label_t class_label, 
                                        const float probability,
                                        const char* class_name);

/**
 * @brief Postprocess the Neuton library RAW inference output
 * 
 * @param[in] predicted_target  Neuton predicted target, @ref neuton_nn_run_inference(...)
 * @param[in] probability       Neuton predicted probability of the target, @ref neuton_nn_run_inference(...)
 * @param[in] cb                Inference Result (prediction) ready user callback, @ref neuton_result_rdy_cb_t 
 */
void neuton_result_postprocess(const uint16_t predicted_target, const float probability,
                                neuton_result_rdy_cb_t cb);



#endif /* NEUTON_RESULT_POSTPROCESSING_H__ */
