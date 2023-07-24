/**
 *
 * @defgroup neuton_nn Neural Network
 * @{
 * @ingroup neuton
 *
 * @brief
 *
 */
#ifndef _NEUTON_NN_H_
#define _NEUTON_NN_H_

#include <neuton_generated/neuton_user_types.h>
#include <neuton/neuton_types.h>

#ifdef   __cplusplus
extern "C"
{
#endif

/**
 * @brief Neuton model task types
 */
typedef enum neuton_nn_task_e
{
    /** Multiclass classification task */
    NEUTON_NN_TASK_MULT_CLASS   = 0,

    /** Binary classification task*/
    NEUTON_NN_TASK_BIN_CLASS    = 1,

    /** Regression task */
    NEUTON_NN_TASK_REGRESSION   = 2
} neuton_nn_task_t;

/**
 * @brief Neuton input scaling type
 */
typedef enum neuton_nn_input_scaling_e
{
    /** Uses unified(one) scaling factor for all input features */
    NEUTON_NN_INPUT_SCALING_UNIFIED   = 0,

    /** Uses unique scaling factors for each individual input feature */
    NEUTON_NN_INPUT_SCALING_UNIQUE    = 1,

    /** Input features is not used by solution */
    NEUTON_NN_INPUT_SCALING_UNDEFINED  = 2,
} neuton_nn_input_scaling_t;

/**
 * @brief Prepared inputs for model inference,
 *        can only be obtained using the @ref neuton_nn_feed_inputs() API call.
 */
struct neuton_inference_input_s;
typedef struct neuton_inference_input_s neuton_inference_input_t;

/**
 * @brief Set up the internal components of the Neuton, 
 *        should be called first and once
 */
void neuton_nn_setup(void);

/**
 * @brief Feed and prepare live input features for model inference
 * @warning @ref neuton_nn_setup() should be called once prior to use
 * 
 * @param[in] p_input   Array of the input features 
 * @param[in] num       Number of the input features in array, should be a multiple of @ref neuton_nn_uniq_inputs_num()
 *  
 * @return Prepared inputs for model inference, or Null if it is not ready
 */
neuton_inference_input_t* neuton_nn_feed_inputs(const neuton_input_t* p_input, neuton_u16_t num);
 
/**
 * @brief Running live input features into a Neuton machine learning algorithm (or “ML model”) to calculate an output
 * 
 * @param[in]  p_input        Input features for model inference, obtained from @ref neuton_nn_feed_inputs() API call
 * @param[out] p_index        Index of predicted target(class) with highest probability 
 * @param[out] pp_outputs     Pointer to store pointer to the internal buffer with all predicted outputs,
 *                            contains predicted target variable (for regression task) or probabilities 
 *                            of each class (binary/multi classification)
 * 
 * @return neuton_i16_t -1 on error, otherwise number of the predicted outputs 
 */
neuton_i16_t neuton_nn_run_inference(neuton_inference_input_t* p_input, 
                                    neuton_u16_t* p_index, const neuton_output_t** pp_outputs);

/**
 * @brief Get number of unique input features on which the model was trained,
 *         e.g for features {x, y, z} -> number of unique input features = 3
 */
neuton_u16_t neuton_nn_uniq_inputs_num(void);

/**
 * @brief Get input features window size in feature samples(vectors),
 *         e.g for input window {x, y, z, ..., xn, yn, zn} -> window size = n
 */
neuton_u16_t neuton_nn_input_window_size(void);

/**
 * @brief Get number of model neurons
 */
neuton_u16_t neuton_nn_model_neurons_num(void);

/**
 * @brief Get number of model weights
 */
neuton_u16_t neuton_nn_model_weights_num(void);

/**
 * @brief Get number of model outputs (predicted targets)
 */
neuton_u16_t neuton_nn_model_outputs_num(void);

/**
 * @brief Get model task @ref neuton_nn_task_t
 */
neuton_nn_task_t neuton_nn_model_task(void);

/**
 * @brief Get model size in bytes (flash usage)
 */
neuton_u16_t neuton_nn_model_size(void);

/**
 * @brief Get model bit depth (8/16/32 bit)
 */
neuton_u8_t neuton_nn_model_bitdepth(void);

/**
 * @brief Return true if model inference support float calculation, otherwise false
 */
bool neuton_nn_model_inference_float_support(void);

/**
 * @brief Get solution ID in string format
 */
const char* neuton_nn_solution_id_str(void);

/**
 * @brief Get solution input scaling type @ref neuton_nn_input_scaling_t
 */
neuton_nn_input_scaling_t neuton_nn_input_scaling(void);

/**
 * @brief Get a pointer to an array of DSP features masks, the mask describes which DSP functions are used to extract the features.
 * 
 * @param[in, out] pp_masks_arr     Pointer to DSP features mask array, can be null if DSP features is not used 
 *
 * @return Number of DSP features masks in array, e.g array length:
 *            0 - if it is not exist, DSP features are not used.
 *            1 - if set of DSP features is the same for all unique inputs @ref neuton_nn_uniq_inputs_num()
 *            N - if set of DSP features is different for atleast one unique input
 */
neuton_u16_t neuton_nn_dsp_features_used(const neuton_dsp_features_mask_t** pp_masks_arr);

#ifdef   __cplusplus
}
#endif

#endif /* _NEUTON_NN_H_ */

/**
 * @}
 */
