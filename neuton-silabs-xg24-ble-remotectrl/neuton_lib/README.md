# Neuton C Library

Neuton, our unique neural network framework, natively creates incredibly compact and accurate models that can easily be deployed into your firmware project using an automatically generated archive with a C library.

The library is written in accordance with the C99 standard, so it is universal and does not have strict requirements for the hardware. The ability to use the library depends mainly on the amount of memory available for its operation.

# How to integrate Neuton into your firmware project 

## Neuton folder structure

There are only two folders that should be added to your project for integrating Neuton:
 * `neuton` - main framework folder in which all Neuton algorithms, utilities, are located;
    * for **Non-enterprise** users, only precompiled libraries are available in the `./neuton/lib` folder
    * for **Enterprise** users, Neuton source code is available in the `./neuton/source` folder
 * `neuton_generated` - folder containing all user solution-specific files (neural network model, data preprocessing configuration, etc).

Also, you should add folder where  `./neuton_generated` is located and `./neuton/include` folder to your project INCLUDE paths.

## Use Neuton in your project

First of all, you need to include the main header file of Neuton:
``` C
#include <neuton/neuton.h>
```
For making an inference with Neuton, there are only 3 functions that you should use:
* `neuton_nn_setup` - Set up the internal components of Neuton, should be called first and once;
* `neuton_nn_feed_inputs` - Feed and prepare live input features for model inference;
* `neuton_nn_run_inference` - Run live input features into a Neuton machine learning algorithm (or “ML model”) to calculate an output;

### Feed input values

Make an array with model raw input features(signal data). Inputs count and order should be **the same** as in the training dataset.

``` C
neuton_input_t raw_inputs[] = {
    raw_input_0,
    raw_input_1,
    // ...
    raw_input_N
};
```
Pass this input array to the `neuton_nn_feed_inputs` function.
``` C
neuton_nn_setup();

neuton_inference_input_t* p_input = neuton_nn_feed_inputs(raw_inputs, neuton_nn_uniq_inputs_num());

if (p_input != NULL)
{
    //make inference
}
```
In case the Neuton solution needs to collect a data window, you can use the following sample-by-sample feed algorithm:
``` C
neuton_nn_setup();

for (size_t i = 0; i < neuton_nn_input_window_size(); i++)
{
    neuton_inference_input_t* p_input = neuton_nn_feed_inputs(raw_inputs, neuton_nn_uniq_inputs_num());
    if (p_input != NULL)
    {
        //make inference
        break;
    }
    raw_inputs += neuton_nn_uniq_inputs_num();
}
```
Or feed all input samples at once:
``` C
neuton_nn_setup();

neuton_inference_input_t* p_input;
p_input = neuton_nn_feed_inputs(raw_inputs, neuton_nn_uniq_inputs_num() * neuton_nn_input_window_size());

if (p_input != NULL)
{
    //make inference
}
```
###	Run Inference

When input buffer is ready for running inference, you should call `neuton_nn_run_inference` with three arguments:
* `p_input` - Input features for model inference, obtained from @ref neuton_nn_feed_inputs() API call
* `p_index` - Index of predicted target(class) with highest probability;
* `pp_outputs` - Pointer to pointer to the internal buffer with all predicted outputs, contains predicted target variable (for regression task) or probabilities of each class (binary/multi classification tasks).

### Wrapping everything together

``` C
/** Setup Neuton */
neuton_nn_setup();

/** Feed and prepare raw inputs for the model inference */
neuton_inference_input_t* p_input;
p_input = neuton_nn_feed_inputs(raw_inputs, neuton_nn_uniq_inputs_num() * neuton_nn_input_window_size());

/** Run inference */
if (p_input)
{
    neuton_u16_t predicted_target;
    const neuton_output_t* probabilities;
    neuton_i16_t outputs_num = neuton_nn_run_inference(p_input, &predicted_target, &probabilities);

    if (outputs_num > 0)
    {
        printf("Predicted target %d with probability %f\r\n", predicted_target, probabilities[predicted_target]);

        printf("All probabilities:\r\n");
        for (size_t i = 0; i < outputs_num; i++)
            printf("%f,", probabilities[i]);
    }
}
```

### Additional solution information API

You can use the following API to get solution information:
* `neuton_nn_solution_id_str` - Get solution ID in string format;
* `neuton_nn_uniq_inputs_num` - Get number of unique input features on which the model was trained;
* `neuton_nn_input_window_size` - Get input features window size in feature samples(vectors);
* `neuton_nn_model_neurons_num` - Get number of model neurons;
* `neuton_nn_model_weights_num` - Get number of model weights;
* `neuton_nn_model_outputs_num` - Get number of model outputs (predicted targets);
* `neuton_nn_model_task` - Get model task : NEUTON_NN_TASK_MULT_CLASS, NEUTON_NN_TASK_BIN_CLASS, NEUTON_NN_TASK_REGRESSION
* `neuton_nn_model_size` - Get model size in bytes (flash usage)
* `neuton_nn_model_bitdepth` - Get model bit depth (8/16/32 bit)
* `neuton_nn_input_scaling` - Get solution input scaling type: NEUTON_NN_INPUT_SCALING_UNIFIED, NEUTON_NN_INPUT_SCALING_UNIQUE