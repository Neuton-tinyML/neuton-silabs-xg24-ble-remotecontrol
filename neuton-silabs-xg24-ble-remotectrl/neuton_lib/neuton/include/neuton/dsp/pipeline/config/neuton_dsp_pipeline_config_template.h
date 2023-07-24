#ifndef _NEUTON_DSP_PIPELINE_CONFIG_TEMPLATE_H_
#define _NEUTON_DSP_PIPELINE_CONFIG_TEMPLATE_H_

/** Defines the statistical features to be included in the pipeline */
#define NEUTON_DSP_PIPELINE_COMPUTE_MIN               0
#define NEUTON_DSP_PIPELINE_COMPUTE_MAX               0
#define NEUTON_DSP_PIPELINE_COMPUTE_MIN_MAX           1
#define NEUTON_DSP_PIPELINE_COMPUTE_RANGE             1
#define NEUTON_DSP_PIPELINE_COMPUTE_MEAN              1
#define NEUTON_DSP_PIPELINE_COMPUTE_RMS               1
#define NEUTON_DSP_PIPELINE_COMPUTE_STD               1
#define NEUTON_DSP_PIPELINE_COMPUTE_ZCR               1
#define NEUTON_DSP_PIPELINE_COMPUTE_MCR               1
#define NEUTON_DSP_PIPELINE_COMPUTE_TCR               1
#define NEUTON_DSP_PIPELINE_COMPUTE_MAD               1
#define NEUTON_DSP_PIPELINE_COMPUTE_SKEW              0
#define NEUTON_DSP_PIPELINE_COMPUTE_KUR               0
#define NEUTON_DSP_PIPELINE_COMPUTE_MOMENTS           1
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF            0
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_HF            0
#define NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF_HF         1
#define NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN           1
#define NEUTON_DSP_PIPELINE_COMPUTE_AMDF              1

/** Defines the spectral features to be included in the pipeline */
#define NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_FREQ   1
#define NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_AMPL   1


#endif /* _NEUTON_DSP_PIPELINE_CONFIG_TEMPLATE_H_ */