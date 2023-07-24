/**
 *
 * @defgroup neuton_dsp_spectral_findpeaks Find Peaks
 * @{
 * @ingroup neuton_dsp_spectral
 *
 * @brief
 *
 */
#ifndef _NEUTON_DSP_SPECTRAL_FINDPEAKS_FUNCTIONS_H_
#define _NEUTON_DSP_SPECTRAL_FINDPEAKS_FUNCTIONS_H_

#include <neuton/neuton_types.h>
#include <neuton/neuton_platform.h>

#ifdef   __cplusplus
extern "C"
{
#endif

//TODO Refactoring
//TODO Update findpeaks algorithm to be able find N peaks

#define NEUTON_FIND_PEAKS_MAX_NUM                   3

/**
 * @brief Finds peaks indexes in the floating-point vector
 * 
 * @param[in] p_input           Pointer to the input vector
 * @param[in] num               Number of samples in the input vector
 * @param[out] p_peaks_index    Pointer to the output buffer for found peak indexes in the input vector
 * @param[out] p_peaks_ampl     Optional pointer to the output buffer for found peak amplitudes
 */
void neuton_dsp_findpeaks_f32(neuton_f32_t* p_input, neuton_u16_t num, 
                                neuton_u16_t p_peaks_index[3U], neuton_f32_t* p_peaks_ampl);

/**
 * @brief Finds peaks indexes in the INT8 fixed-point
 * 
 * @param[in] p_input           Pointer to the input vector
 * @param[in] num               Number of samples in the input vector
 * @param[out] p_peaks_index    Pointer to the output buffer for found peak indexes in the input vector
 * @param[out] p_peaks_ampl     Optional pointer to the output buffer for found peak amplitudes
 */
void neuton_dsp_findpeaks_i8(neuton_i8_t* p_input, neuton_u16_t num, 
                                neuton_u16_t p_peaks_index[3U], neuton_i8_t* p_peaks_ampl);

/**
 * @brief Finds peaks indexes in the INT16 fixed-point
 * 
 * @param[in] p_input           Pointer to the input vector
 * @param[in] num               Number of samples in the input vector
 * @param[out] p_peaks_index    Pointer to the output buffer for found peak indexes in the input vector
 * @param[out] p_peaks_ampl     Optional pointer to the output buffer for found peak amplitudes
 */
void neuton_dsp_findpeaks_i16(neuton_i16_t* p_input, neuton_u16_t num, 
                            neuton_u16_t p_peaks_index[3U], neuton_i16_t* p_peaks_ampl);

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_SPECTRAL_FINDPEAKS_FUNCTIONS_H_ */

/**
 * @}
 */
