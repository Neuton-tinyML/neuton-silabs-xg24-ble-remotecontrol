#ifndef _NEUTON_COMMON_TYPES_H_
#define _NEUTON_COMMON_TYPES_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef   __cplusplus
extern "C"
{
#endif

/**
 * @brief 8-bit signed integer type definition.
 */
typedef int8_t neuton_i8_t;

/**
 * @brief 8-bit unsigned integer type definition.
 */
typedef uint8_t neuton_u8_t;

/**
 * @brief 16-bit signed integer type definition.
 */
typedef int16_t neuton_i16_t;

/**
 * @brief 16-bit unsigned integer type definition.
 */
typedef uint16_t neuton_u16_t;

/**
  * @brief 32-bit signed integer type definition.
  */
typedef int32_t neuton_i32_t;

/**
 * @brief 32-bit unsigned integer type definition.
 */
typedef uint32_t neuton_u32_t;

/**
 * @brief 64-bit signed integer type definition.
 */
typedef int64_t neuton_i64_t;

/**
 * @brief 64-bit unsigned integer type definition.
 */
typedef uint64_t neuton_u64_t;

/**
 * @brief 32-bit floating-point type definition.
 */
typedef float   neuton_f32_t;

/**
 * @brief 64-bit floating-point type definition.
 */
typedef double  neuton_f64_t;

/**
 * @brief Generic Neuton operation status code
 */
typedef enum neuton_status_e
{
    /** Operation successful */
    NEUTON_STATUS_SUCCESS,

    /** The operation failed with an unspecified error */
    NEUTON_STATUS_UNSPECIFIED_ERROR,

    /** The argument supplied to the operation was invalid */
    NEUTON_STATUS_INVALID_ARGUMENT,

    /** The argument supplied to the operation was NULL */
    NEUTON_STATUS_NULL_ARGUMENT,

    /** The requested operation was not available */
    NEUTON_STATUS_UNAVAILABLE,

    /** The operation or service not supported */
    NEUTON_STATUS_NOT_SUPPORTED
} neuton_status_t;

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_COMMON_TYPES_H_ */