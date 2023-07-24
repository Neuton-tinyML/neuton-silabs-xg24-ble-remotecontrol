/**
 *
 * @defgroup neuton_dsp_pipeline_stat Statistical features
 * @{
 * @ingroup neuton_dsp_pipeline
 *
 * @brief
 *
 */
#ifndef _NEUTON_DSP_PIPELINE_STAT_H_
#define _NEUTON_DSP_PIPELINE_STAT_H_

#include "neuton_dsp_pipeline_types.h"

#ifdef   __cplusplus
extern "C"
{
#endif

/**
 * @brief Compute DSP statistical features from floating-point vector
 * 
 * @param[in]   p_input         Pointer to the input vector
 * @param[in]   num             Number of samples in the input vector
 * @param[in]   feature_mask    The mask that determines which features will be extracted in runtime,
 *                              also consider compile-time config "neuton_dsp_pipeline_config_f32.h"
 * @param[in]   get_argument    Callback for getting feature argument while feature computation
 * @param[out]  p_features      Pointer to the output feature buffer
 *  
 * @return neuton_u8_t Number of features fetched into p_features buffer
 */
neuton_u8_t neuton_dsp_pipeline_stat_compute_f32(const neuton_f32_t* p_input, neuton_u16_t num,
                                                const neuton_dsp_stat_features_mask_t feature_mask,
                                                neuton_dsp_get_feature_arg_cb_t get_argument,
                                                neuton_f32_t* p_features);

/**
 * @brief Compute DSP statistical features from INT8 fixed-point vector
 * 
 * @param[in]   p_input         Pointer to the input vector
 * @param[in]   num             Number of samples in the input vector
 * @param[in]   feature_mask    The mask that determines which features will be extracted in runtime,
 *                              also consider compile-time config "neuton_dsp_pipeline_config_i8.h"
 * @param[in]   get_argument    Callback for getting feature argument while feature computation
 * @param[out]  p_features      Pointer to the output feature buffer
 *  
 * @return neuton_u8_t Number of features fetched into p_features buffer
 */
neuton_u8_t neuton_dsp_pipeline_stat_compute_i8(const neuton_i8_t* p_input, neuton_u16_t num,
                                                const neuton_dsp_stat_features_mask_t feature_mask,
                                                neuton_dsp_get_feature_arg_cb_t get_argument,
                                                neuton_i16_t* p_features);

/**
 * @brief Compute DSP statistical features from INT16 fixed-point vector
 * 
 * @param[in]   p_input         Pointer to the input vector
 * @param[in]   num             Number of samples in the input vector
 * @param[in]   feature_mask    The mask that determines which features will be extracted in runtime,
 *                              also consider compile-time config "neuton_dsp_pipeline_config_i16.h"
 * @param[in]   get_argument    Callback for getting feature argument while feature computation
 * @param[out]  p_features      Pointer to the output feature buffer
 *  
 * @return neuton_u8_t Number of features fetched into p_features buffer
 */
neuton_u8_t neuton_dsp_pipeline_stat_compute_i16(const neuton_i16_t* p_input, neuton_u16_t num,
                                                const neuton_dsp_stat_features_mask_t feature_mask,
                                                neuton_dsp_get_feature_arg_cb_t get_argument,
                                                neuton_i32_t* p_features);

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_PIPELINE_STAT_H_ */

/**
 * @}
 */
