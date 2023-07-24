/**
 *
 * @defgroup neuton_dsp_statistic_var Variance
 * @{
 * @ingroup neuton_dsp_statistic
 *
 * @brief
 *
 */
#ifndef _NEUTON_DSP_STAT_VAR_FUNCTIONS_H_
#define _NEUTON_DSP_STAT_VAR_FUNCTIONS_H_

#include <neuton/neuton_types.h>

#ifdef   __cplusplus
extern "C"
{
#endif

/**
 * @brief Calculate Variance value of a floating-point vector.
 * @details This function uses internal accumulator of neuton_f32_t size, 
 *          for calculating sum of squares of values, so it will lose precision if
 *          values ​​less than 10e-4
 *
 * @param[in]        p_input   Pointer to the input vector
 * @param[in]        num       Number of samples in input vector
 * @param[in, out]   p_ctx     Optional pointer to the statistics context,
 *                             this function will use <pre> p_ctx->value.sum </pre> for calculation if it exist
 *                             the calculated value of variance will be written to context for further use
 *
 * @return  neuton_f32_t  Variance value of the vector
 */
neuton_f32_t neuton_dsp_var_f32(const neuton_f32_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_f32_t* p_ctx);

/**
 * @brief Calculate Variance value of a floating-point vector ​​using values ​​in increments of 'stride'.
 * @details This function uses internal accumulator of neuton_f32_t size, 
 *          for calculating sum of squares of values, so it will lose precision if
 *          values ​​less than 10e-4
 *
 * @param[in]        p_input   Pointer to the input vector
 * @param[in]        num       Number of samples with 'stride' in input vector
 * @param[in]        stride    Vector element offset stride
 * @param[in, out]   p_ctx     Optional pointer to the statistics context,
 *                             this function will use <pre> p_ctx->value.sum </pre> for calculation if it exist
 *                             the calculated value of variance will be written to context for further use
 *
 * @return  neuton_f32_t  Variance value of the vector
 */
neuton_f32_t neuton_dsp_var_f32_s(const neuton_f32_t* p_input, neuton_u16_t num,
                                size_t stride, neuton_dsp_stat_ctx_f32_t* p_ctx);

/**
 * @brief Calculate Variance value of a INT8 fixed-point vector.
 *
 * @param[in]        p_input   Pointer to the input vector
 * @param[in]        num       Number of samples in input vector
 * @param[in, out]   p_ctx     Optional pointer to the statistics context, this function will use
 *                              <pre> p_ctx->value.sum and/or p_ctx->value.tss </pre> for calculation if it exist,
 *                             the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i16_t  Variance value of the vector
 */
neuton_i16_t neuton_dsp_var_i8(const neuton_i8_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_i8_t* p_ctx);

/**
 * @brief Calculate Variance value of a INT8 fixed-point vector ​​using values ​​in increments of 'stride'.
 *
 * @param[in]       p_input         Pointer to the input vector
 * @param[in]       num             Number of samples with 'stride' in input vector
 * @param[in]       stride          Vector element offset stride
 * @param[in, out]   p_ctx          Optional pointer to the statistics context, this function will use
 *                                   <pre> p_ctx->value.sum and/or p_ctx->value.tss </pre> for calculation if it exist,
 *                                  the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i16_t  Variance value of the vector
 */
neuton_i16_t neuton_dsp_var_i8_s(const neuton_i8_t* p_input, neuton_u16_t num,
                                 size_t stride, neuton_dsp_stat_ctx_i8_t* p_ctx);


/**
 * @brief Calculate Variance value of a INT16 fixed-point vector.
 *
 * @param[in]        p_input   Pointer to the input vector
 * @param[in]        num       Number of samples in input vector
 * @param[in, out]   p_ctx     Optional pointer to the statistics context, this function will use 
 *                              <pre> p_ctx->value.sum and/or p_ctx->value.tss </pre> for calculation if it exist,
 *                             the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i32_t  Variance value of the vector
 */
neuton_i32_t neuton_dsp_var_i16(const neuton_i16_t* p_input, neuton_u16_t num,
                                neuton_dsp_stat_ctx_i16_t* p_ctx);

/**
 * @brief Calculate Variance value of a INT16 fixed-point vector ​​using values ​​in increments of 'stride'.
 *
 * @param[in]        p_input         Pointer to the input vector
 * @param[in]        num             Number of samples with 'stride' in input vector
 * @param[in]        stride          Vector element offset stride
 * @param[in, out]   p_ctx           Optional pointer to the statistics context, this function will use
 *                                    <pre> p_ctx->value.sum and/or p_ctx->value.tss </pre> for calculation if it exist,
 *                                   the calculated value of variance will be written to context for further use
 *
 * @return  neuton_i32_t  Variance value of the vector
 */
neuton_i32_t neuton_dsp_var_i16_s(const neuton_i16_t* p_input, neuton_u16_t num,
                                 size_t stride, neuton_dsp_stat_ctx_i16_t* p_ctx);

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_STAT_VAR_FUNCTIONS_H_ */

/**
 * @}
 */
