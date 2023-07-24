#ifndef _NEUTON_DSP_PIPELINE_CONFIG_I8_H_
#define _NEUTON_DSP_PIPELINE_CONFIG_I8_H_

#ifdef NEUTON_DSP_PIPELINE_USE_DEFAULT_CONFIG_I8

#ifdef NEUTON_LIB_WARNINGS_ENABLE
#warning "User config for i8 dsp pipeline is not defined, default configuration is used"
#endif // NEUTON_LIB_WARNINGS_ENABLE

#include "neuton_dsp_pipeline_config_template.h"

#else

#include <neuton_generated/neuton_user_config.h>

#endif // NEUTON_DSP_PIPELINE_USE_DEFAULT_CONFIG_I8

#endif /* _NEUTON_DSP_PIPELINE_CONFIG_I8_H_ */