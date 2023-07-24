#ifndef _NEUTON_PLATFORM_H_
#define _NEUTON_PLATFORM_H_

#include "neuton_debug.h"

#define __NEUTON_STATIC_FORCEINLINE static inline
#define __NEUTON_STATIC_INLINE static inline

#if defined ( __GNUC__ )
#define __NEUTON_WEAK           __attribute__((weak))
#define __NEUTON_ALIGN(x)       __attribute__((aligned(x)))
#define __NEUTON_ALIGNED        __attribute__ ((aligned))
#define __NEUTON_PACKED         __attribute__((__packed__))
#elif defined (__ICCARM__)
#define __NEUTON_WEAK           __weak
#define __NEUTON_PACKED         __packed
#define __NEUTON_ALIGNED        __attribute__ ((aligned))
#define __NEUTON_ALIGN(x)       __attribute__((aligned(x)))
#elif defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
#define __NEUTON_WEAK           __attribute__((weak))
#define __NEUTON_ALIGN(x)       __attribute__((aligned(x)))
#define __NEUTON_ALIGNED        __attribute__ ((aligned))
#define __NEUTON_PACKED         __attribute__((packed))
#else
#define __NEUTON_WEAK          __attribute__((weak)) 
#define __NEUTON_ALIGN(x)      __attribute__((aligned(x)))
#define __NEUTON_ALIGNED       __attribute__ ((aligned))
#define __NEUTON_PACKED        __attribute__((__packed__))
#endif

#define NEUTON_INT8_MAX                 ((neuton_i8_t)(0x7F))
#define NEUTON_INT8_MIN                 ((neuton_i8_t)(0x80))
#define NEUTON_INT8_ABSMAX              ((neuton_i8_t)(0x7F))
#define NEUTON_INT8_ABSMIN              ((neuton_i8_t)0)
#define NEUTON_INT8_QFACTOR              (128)
#define NEUTON_INT8_SIGN_BIT            (neuton_i8_t)(1 << 7)
#define NEUTON_INT8_CHECK_SIGN(x)       (bool)((x) & NEUTON_INT8_SIGN_BIT)

#define NEUTON_INT16_MAX                ((neuton_i16_t)(0x7FFF))
#define NEUTON_INT16_MIN                ((neuton_i16_t)(0x8000))
#define NEUTON_INT16_ABSMAX             ((neuton_i16_t)(0x7FFF))
#define NEUTON_INT16_ABSMIN             ((neuton_i16_t)0)
#define NEUTON_INT16_QFACTOR             (32768)
#define NEUTON_INT16_SIGN_BIT           (neuton_i16_t)(1 << 15)
#define NEUTON_INT16_CHECK_SIGN(x)      (bool)((x) & NEUTON_INT16_SIGN_BIT)

#define NEUTON_INT32_MAX                ((neuton_i32_t)(0x7FFFFFFFL))
#define NEUTON_INT32_MIN                ((neuton_i32_t)(0x80000000L))
#define NEUTON_INT32_ABSMAX             ((neuton_i32_t)(0x7FFFFFFFL))
#define NEUTON_INT32_ABSMIN             ((neuton_i32_t)0)
#define NEUTON_INT32_QFACTOR             (2147483648)
#define NEUTON_INT32_SIGN_BIT           (neuton_i32_t)(1 << 31)
#define NEUTON_INT32_CHECK_SIGN(x)      (bool)((x) & NEUTON_INT32_SIGN_BIT)

#define NEUTON_F32_MAX                  ((neuton_f32_t)3.402823466e+38F)
#define NEUTON_F32_MIN                  -NEUTON_F32_MAX
#define NEUTON_F32_NP_MIN               ((neuton_f32_t)1.175494351e-38F)    // min normalized positive value
#define NEUTON_F32_CHECK_SIGN(x)        (bool)(signbit(x))
#define NEUTON_F32_EPSILON              ((neuton_f32_t)1.192092896e-07F)    // smallest such that 1.0+FLT_EPSILON != 1.0

#define NEUTON_UNUSED(x)                ((void)(x))

#define NEUTON_VOID_VALUE

#endif /* _NEUTON_PLATFORM_H_ */