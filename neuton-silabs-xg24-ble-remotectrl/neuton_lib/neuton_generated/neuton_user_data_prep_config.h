/* 2023-07-13T18:07:47Z */

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

#ifndef _NEUTON_USER_DATA_PREPARATION_CONFIG_H_
#define _NEUTON_USER_DATA_PREPARATION_CONFIG_H_

/** User input features type */
#define NEUTON_NN_INPUT_TYPE NEUTON_NN_INPUT_TYPE_INT16

/** Number of unique features in the original input sample */
#define NEUTON_NN_INPUT_UNIQ_FEATURES_NUM 6

/** Number of unique features actually used by NN from the original input sample */
#define NEUTON_NN_INPUT_UNIQ_FEATURES_USED_NUM 6

/** Number of input feature samples that should be collected in the input window
 *  feature_sample = 1 * NEUTON_NN_INPUT_UNIQ_FEATURES_NUM
 */
#define NEUTON_NN_INPUT_FEATURE_WINDOW_SIZE 85

/** Number of input feature samples on that the input window is shifted */
#define NEUTON_NN_INPUT_FEATURE_WINDOW_SHIFT 25

/** Number of lag features used from input features window  */
#define NEUTON_NN_LAG_FEATURES_NUM 0

/** Determines if NN used only input unprocessed features for inference */
#define NEUTON_NN_USE_INPUT_FEATURES 0

/** Determines the presence of a unique scaling factors for each input(LAG) feature  */
#define NEUTON_NN_USE_UNIQ_INPUT_SCALING 0

/** The maximum number of DSP features that user used for all unique input features */
#define NEUTON_NN_DSP_FEATURES_NUM 56

/** Determines the presence of a unique mask for DSP feature calculation for each unique input feature */
#define NEUTON_NN_USE_UNIQ_DSP_MASK 1

/** Determines if features use feature clipping */
#define NEUTON_NN_USE_FEATURE_CLIPPING 1


/** Defines the statistical features to be used in the compiled image */
#define NEUTON_DSP_PIPELINE_COMPUTE_MIN 1
#define NEUTON_DSP_PIPELINE_COMPUTE_MAX 1
#define NEUTON_DSP_PIPELINE_COMPUTE_MIN_MAX 1
#define NEUTON_DSP_PIPELINE_COMPUTE_RANGE 0
#define NEUTON_DSP_PIPELINE_COMPUTE_MEAN 1
#define NEUTON_DSP_PIPELINE_COMPUTE_RMS 0
#define NEUTON_DSP_PIPELINE_COMPUTE_STD 1
#define NEUTON_DSP_PIPELINE_COMPUTE_ZCR 1
#define NEUTON_DSP_PIPELINE_COMPUTE_MCR 1
#define NEUTON_DSP_PIPELINE_COMPUTE_TCR 1
#define NEUTON_DSP_PIPELINE_COMPUTE_MAD 1
#define NEUTON_DSP_PIPELINE_COMPUTE_SKEW 0
#define NEUTON_DSP_PIPELINE_COMPUTE_KUR 0
#define NEUTON_DSP_PIPELINE_COMPUTE_MOMENTS 0
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF 0
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_HF 0
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF_HF 0
#define NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN 1
#define NEUTON_DSP_PIPELINE_COMPUTE_AMDF 1

#define NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_FREQ 0
#define NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_AMPL 0

#endif /* _NEUTON_USER_DATA_PREPARATION_CONFIG_H_ */
