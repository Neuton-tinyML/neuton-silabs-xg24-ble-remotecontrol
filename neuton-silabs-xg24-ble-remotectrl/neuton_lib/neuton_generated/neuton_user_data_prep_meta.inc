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

/** Defines input(also used for LAG) features MIN scaling factor
 */
static const neuton_input_t INPUT_FEATURES_SCALE_MIN[] = { 0 };

/** Defines input(also used for LAG) features MAX scaling factor
 */
static const neuton_input_t INPUT_FEATURES_SCALE_MAX[] = { 0 };

/** Defines which unique input features is used for LAG features processing,
 *  one bit for one unique feature, starting from LSB
 */
static const neuton_u8_t INPUT_FEATURES_USED_FOR_LAGS_MASK[] = { 0x00 };

/** Defines DSP feature calculation masks used as neuton_dsp_features_mask_t,
 *  32 bit for one unique feature, @ref neuton_dsp_features_mask_t to see bitmask
 */
static const neuton_u32_t DSP_FEATURES_CALCULATION_MASK[] = {
	-862257152, 1318780928, 1318780928, -828702720, -895811584, -828702720 };

/** Defines DSP feature calculation arguments used by DSP pipeline,
 *  32 bit for one feature argument
 */
static const neuton_input_t DSP_FEATURES_CALCULATION_ARGS[] = {
	25000, 10000, 15000, 19000, 25000, 9000 };

/** Defines DSP features MAX scaling factor
 */
static const neuton_feature_t DSP_FEATURES_SCALE_MIN[] = {
	-32768, -8070, -8209, 11, 15, 0, 0, 47, 15, -32768, -16416, -21262, 11,
	15, 1, 0, 0, 26, -32768, -8164, -12218, 12, 16, 1, 0, 0, 18, -32768, -2429,
	-7763, 2, 4, 1, 0, 0, 5, 3, -32768, -216, -8192, 3, 4, 1, 0, 31, 4, -32768,
	-2473, -8924, 3, 4, 1, 0, 0, 5, 3 };

/** Defines DSP features MIN scaling factor
 */
static const neuton_feature_t DSP_FEATURES_SCALE_MAX[] = {
	14376, 32767, 19805, 22347, 23727, 28, 11, 22633, 6264, 15840, 32767, 16039,
	18413, 20281, 60, 39, 35, 21262, 15672, 32767, 15753, 21508, 22693, 60,
	53, 11, 22411, 2145, 32767, 7114, 19377, 21095, 61, 57, 9, 19993, 4005,
	1695, 32767, 5761, 21735, 23615, 59, 7, 21657, 4853, 1052, 32767, 9062,
	22784, 23494, 63, 40, 10, 23516, 3996 };

