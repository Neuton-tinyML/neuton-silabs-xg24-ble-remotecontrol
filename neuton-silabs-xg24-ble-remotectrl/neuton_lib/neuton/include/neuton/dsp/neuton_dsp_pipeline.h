/**
 *
 * @defgroup neuton_dsp_pipeline Features computation in pipeline
 * @{
 * @ingroup neuton_dsp
 *
 * @brief
 *
 */
#ifndef _NEUTON_DSP_PIPELINE_H_
#define _NEUTON_DSP_PIPELINE_H_

#include <neuton/dsp/pipeline/neuton_dsp_pipeline_types.h>

#ifdef   __cplusplus
extern "C"
{
#endif

/**
 * @brief Compute DSP features from floating-point vector
 * 
 * @param[in]   p_input             Pointer to the input vector
 * @param[in]   num                 Number of samples in the input vector
 * @param[in]   mask                The mask that determines which features will be computed in runtime,
 *                                  also consider compile-time config "neuton_dsp_pipeline_config_f32.h"
 * @param[in]   get_argument        Callback for getting feature argument while feature computation
 * @param[out]  p_features          Pointer to the output feature buffer
 * 
 * @return neuton_u16_t Number of DSP features fetched into p_features buffer
 */
neuton_u16_t neuton_dsp_pipeline_compute_f32(const neuton_f32_t* p_input, neuton_u16_t num,
                                            const neuton_dsp_features_mask_t mask,
                                            neuton_dsp_get_feature_arg_cb_t get_argument,
                                            neuton_f32_t* p_features);

/**
 * @brief Compute DSP features from INT8 fixed-point vector
 * 
 * @param[in]   p_input             Pointer to the input vector
 * @param[in]   num                 Number of samples in the input vector
 * @param[in]   mask                The mask that determines which features will be computed in runtime,
 *                                  also consider compile-time config "neuton_dsp_pipeline_config_i8.h"
 * @param[in]   get_argument        Callback for getting feature argument while feature computation
 * @param[out]  p_features          Pointer to the output feature buffer
 * 
 * @return neuton_u16_t Number of features fetched into p_features buffer
 */
neuton_u16_t neuton_dsp_pipeline_compute_i8(const neuton_i8_t* p_input, neuton_u16_t num,
                                            const neuton_dsp_features_mask_t mask,
                                            neuton_dsp_get_feature_arg_cb_t get_argument,
                                            neuton_i16_t* p_features);

/**
 * @brief Compute DSP features from INT16 fixed-point vector
 * 
 * @param[in]   p_input             Pointer to the input vector
 * @param[in]   num                 Number of samples in the input vector
 * @param[in]   mask                The mask that determines which features will be computed in runtime,
 *                                  also consider compile-time config "neuton_dsp_pipeline_config_i16.h"
 * @param[in]   get_argument        Callback for getting feature argument while feature computation
 * @param[out]  p_features          Pointer to the output feature buffer
 * 
 * @return neuton_u16_t Number of features fetched into p_features buffer
 */
neuton_u16_t neuton_dsp_pipeline_compute_i16(const neuton_i16_t* p_input, neuton_u16_t num,
                                            const neuton_dsp_features_mask_t mask,
                                            neuton_dsp_get_feature_arg_cb_t get_argument,
                                            neuton_i32_t* p_features);
#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_PIPELINE_H_ */

/**
 * @}
 */
