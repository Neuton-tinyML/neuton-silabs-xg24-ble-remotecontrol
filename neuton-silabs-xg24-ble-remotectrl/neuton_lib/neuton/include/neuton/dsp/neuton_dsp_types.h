#ifndef _NEUTON_DSP_TYPES_H_
#define _NEUTON_DSP_TYPES_H_

#include "pipeline/neuton_dsp_pipeline_types.h"
#include <neuton/neuton_common_types.h>

#ifdef   __cplusplus
extern "C"
{
#endif


/**
 * @brief Statistics context flags that indicating the presence of values ​​to use
 * 
 */
typedef union neuton_dsp_stat_ctx_flags_u
{
    struct
    {
      bool sum      : 1;
      bool tss      : 1;
      bool var      : 1;
      bool abssum   : 1;
    } is;
    neuton_u8_t all;
} neuton_dsp_stat_ctx_flags_t;

/**
 * @brief Macro definitions for setting flags of @ref neuton_dsp_stat_ctx_flags_t
 * 
 */
#define NEUTON_DSP_STAT_CTX_EMPTY              (0)
#define NEUTON_DSP_STAT_CTX_SUM_FLAG           (1 << 0)
#define NEUTON_DSP_STAT_CTX_TSS_FLAG           (1 << 1)
#define NEUTON_DSP_STAT_CTX_VAR_FLAG           (1 << 2)
#define NEUTON_DSP_STAT_CTX_ABSSUM_FLAG        (1 << 4)

#define NEUTON_DSP_STAT_CTX_SUM_TSS_FLAGS       (NEUTON_DSP_STAT_CTX_SUM_FLAG | NEUTON_DSP_STAT_CTX_TSS_FLAG)
#define NEUTON_DSP_STAT_CTX_SUM_VAR_FLAGS       (NEUTON_DSP_STAT_CTX_SUM_FLAG | NEUTON_DSP_STAT_CTX_VAR_FLAG)
#define NEUTON_DSP_STAT_CTX_SUM_TSS_VAR_FLAGS   (NEUTON_DSP_STAT_CTX_SUM_TSS_FLAGS | NEUTON_DSP_STAT_CTX_VAR_FLAG)
#define NEUTON_DSP_STAT_CTX_TSS_VAR_FLAGS       (NEUTON_DSP_STAT_CTX_TSS_FLAG | NEUTON_DSP_STAT_CTX_VAR_FLAG)

/**
 * @brief Reset utility macro for @ref neuton_dsp_stat_ctx_f32_t context structure
 * 
 */
#define NEUTON_DSP_STAT_CTX_RESET(ctx) \
      ctx.flags.all = NEUTON_DSP_STAT_CTX_EMPTY

/**
 * @brief  Floating-point statistics reusable context, in which is used to store derived or intermediate 
 *          metrics to simplify / speed up the calculation of dependent metrics
 */
typedef struct neuton_dsp_stat_ctx_f32_s
{
  struct
  {
    /* Absolute Sum of vector elements */
    neuton_f32_t abssum;
    /* Sum of vector elements */
    neuton_f32_t sum;
    /* Total sum of squares of vector elements */
    neuton_f32_t tss;
    /* Variance of vector elements */
    neuton_f32_t var;
  } value;

  neuton_dsp_stat_ctx_flags_t flags;
} neuton_dsp_stat_ctx_f32_t;

/**
 * @brief  INT8 statistics reusable context, in which is used to store derived or intermediate 
 *          metrics to simplify / speed up the calculation of dependent metrics
 */
typedef struct neuton_dsp_stat_ctx_i8_s
{
  struct
  {
    /* Absolute Sum of vector elements */
    neuton_u32_t abssum;
    /* Sum of vector elements */
    neuton_i32_t sum;
    /* Total sum of squares of vector elements */
    neuton_u32_t tss;
    /* Variance of vector elements */
    neuton_i16_t var;
  } value;

  neuton_dsp_stat_ctx_flags_t flags;
} neuton_dsp_stat_ctx_i8_t;

/**
 * @brief  INT16 statistics reusable context, in which is used to store derived or intermediate 
 *          metrics to simplify / speed up the calculation of dependent metrics
 */
typedef struct neuton_dsp_stat_ctx_i16_s
{
  struct
  {
    /* Absolute Sum of vector elements */
    neuton_u32_t abssum;
    /* Sum of vector elements */
    neuton_i32_t sum;
    /* Total sum of squares of vector elements */
    neuton_u64_t tss;
    /* Variance of vector elements */
    neuton_i32_t var;
  } value;

  neuton_dsp_stat_ctx_flags_t flags;
} neuton_dsp_stat_ctx_i16_t;

/**
 * @brief  INT32 statistics reusable context, in which is used to store derived or intermediate 
 *          metrics to simplify / speed up the calculation of dependent metrics
 */
typedef struct neuton_dsp_stat_ctx_i32_s
{
  struct
  {
    /* Absolute Sum of vector elements */
    neuton_u64_t abssum;
    /* Sum of vector elements */
    neuton_i64_t sum;
    /* Total sum of squares of vector elements */
    neuton_u64_t tss;
    /* Variance of vector elements */
    neuton_i64_t var;
  } value;

  neuton_dsp_stat_ctx_flags_t flags;
} neuton_dsp_stat_ctx_i32_t;

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_DSP_TYPES_H_ */