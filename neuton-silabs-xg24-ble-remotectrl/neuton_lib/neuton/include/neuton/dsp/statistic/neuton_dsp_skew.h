/**
 *
 * @defgroup neuton_dsp_statistic_skew Skewness
 * @{
 * @ingroup neuton_dsp_statistic
 *
 * @brief
 *
 */
#ifndef _NEUTON_DSP_STAT_SKEW_FUNCTIONS_H_
#define _NEUTON_DSP_STAT_SKEW_FUNCTIONS_H_

#include <neuton/neuton_types.h>

#ifdef   __cplusplus
extern "C"
{
#endif


/**
 * @brief Calculate Skewness of values of a floating-point vector.
 * @note Can return NEUTON_DSP_ZERO_DIV_FLAG if NEUTON_DSP_ENABLE_RUNTIME_CHECKS is defined.
 *
 * @param[in]       p_input   Pointer to the input vector
 * @param[in]       num       Number of samples in input vector
 * @param[in, out]  p_ctx     Optional pointer to the statistics context, this function will use
 *                            <pre> p_ctx->value.sum and/or p_ctx->value.var </pre> for calculation if it exist,
 *                            the calculated value of variance will be written to context for further use
 *
 * @return  neuton_f32_t  Skewness value of the vector
 */
neuton_f32_t neuton_dsp_skew_f32(const neuton_f32_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_f32_t* p_ctx);

/**
 * @brief Calculate Skewness value of a floating-point vector ​​using values ​​in increments of 'stride'.
 * @note Can return NEUTON_DSP_ZERO_DIV_FLAG if NEUTON_DSP_ENABLE_RUNTIME_CHECKS is defined.
 *
 * @param[in]       p_input   Pointer to the input vector
 * @param[in]       num       Number of samples with 'stride' in input vector
 * @param[in]       stride    Vector element offset stride
 * @param[in, out]  p_ctx     Optional pointer to the statistics context, this function will use
 *                            <pre> p_ctx->value.sum and/or p_ctx->value.var </pre> for calculation if it exist,
 *                            the calculated value of variance will be written to context for further use
 *
 * @return  neuton_f32_t  Skewness value of the vector
 */
neuton_f32_t neuton_dsp_skew_f32_s(const neuton_f32_t* p_input, neuton_u16_t num, 
                                    size_t stride, neuton_dsp_stat_ctx_f32_t* p_ctx);

/**
 * @brief Calculate Skewness of values of a INT8 vector.
 * @note Can return NEUTON_DSP_ZERO_DIV_FLAG if NEUTON_DSP_ENABLE_RUNTIME_CHECKS is defined.
 *
 * @param[in]       p_input   Pointer to the input vector
 * @param[in]       num       Number of samples in input vector
 * @param[in, out]  p_ctx     Optional pointer to the statistics context, this function will use
 *                            <pre> p_ctx->value.sum and/or p_ctx->value.var </pre> for calculation if it exist,
 *                            the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i16_t  Skewness value of the vector in integer format with high float correlation
 */
neuton_i16_t neuton_dsp_skew_i8(const neuton_i8_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_i8_t* p_ctx);

/**
 * @brief Calculate Skewness of values of a INT16 vector.
 * @note Can return NEUTON_DSP_ZERO_DIV_FLAG if NEUTON_DSP_ENABLE_RUNTIME_CHECKS is defined.
 *
 * @param[in]       p_input   Pointer to the input vector
 * @param[in]       num       Number of samples in input vector
 * @param[in, out]  p_ctx     Optional pointer to the statistics context, this function will use
 *                            <pre> p_ctx->value.sum and/or p_ctx->value.var </pre> for calculation if it exist,
 *                            the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i32_t  Skewness value of the vector in integer format with high float correlation
 */
neuton_i32_t neuton_dsp_skew_i16(const neuton_i16_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_i16_t* p_ctx);

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_STAT_SKEW_FUNCTIONS_H_ */

/**
 * @}
 */
