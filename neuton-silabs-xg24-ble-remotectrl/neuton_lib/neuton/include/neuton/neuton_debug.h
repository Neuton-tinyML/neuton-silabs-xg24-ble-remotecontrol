/**
 *
 * @defgroup neuton_debug Debug Utils
 * @{
 *
 * @brief
 *
 */

#ifndef _NEUTON_DEBUG_H_
#define _NEUTON_DEBUG_H_

/**
 * @brief Macro for return values ​​to indicate potential divide-by-zero in the DSP functions
 * 
 */
#ifndef NEUTON_DSP_ZERO_DIV_FLAG
#define NEUTON_DSP_ZERO_DIV_FLAG       0
#endif

#ifdef NEUTON_DSP_ENABLE_RUNTIME_CHECKS

/**
 * @brief Macro for verifying that the provided condition is true. It will cause the exterior
 *        function to return an error value if it is not.
 *
 * @param[in] is_true     Boolean condition to check.
 * @param[in] ret_val     The value to be returned if the checks fails
 */
#define NEUTON_DSP_RETURN_IF(is_true, ret_val)      \
do                                                  \
{                                                   \
    if ((is_true))                                  \
    {                                               \
        return ret_val;                             \
    }                                               \
} while(0)

#else
#define NEUTON_DSP_RETURN_IF(...);
#endif // NEUTON_DSP_ENABLE_RUNTIME_CHECKS

#endif /* _NEUTON_DEBUG_H_ */

/**
 * @}
 */
