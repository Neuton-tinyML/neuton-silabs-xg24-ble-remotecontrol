#ifndef _NEUTON_NN_FE_CONFIG_RESOLVER_H_
#define _NEUTON_NN_FE_CONFIG_RESOLVER_H_

// ////////////////////// User config compatibility resolver start ///////////

#ifndef NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN
#define NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN             0
#endif

#ifndef NEUTON_DSP_PIPELINE_COMPUTE_AMDF
#define NEUTON_DSP_PIPELINE_COMPUTE_AMDF                0
#endif

// ////////////////////// User config compatibility resolver end /////////////

#define NEUTON_DSP_USE_STAT_PIPELINE        (NEUTON_DSP_PIPELINE_COMPUTE_MIN      || NEUTON_DSP_PIPELINE_COMPUTE_MAX     || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_MIN_MAX  || NEUTON_DSP_PIPELINE_COMPUTE_RANGE   || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_MEAN     || NEUTON_DSP_PIPELINE_COMPUTE_RMS     || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_STD      || NEUTON_DSP_PIPELINE_COMPUTE_ZCR     || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_MCR      || NEUTON_DSP_PIPELINE_COMPUTE_TCR     || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_MAD      || NEUTON_DSP_PIPELINE_COMPUTE_SKEW    || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_KUR      || NEUTON_DSP_PIPELINE_COMPUTE_MOMENTS ||\
                                             NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF   || NEUTON_DSP_PIPELINE_COMPUTE_P2P_HF  ||\
                                             NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF_HF || NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN || \
                                             NEUTON_DSP_PIPELINE_COMPUTE_AMDF)

#define NEUTON_DSP_PIPELINE_STAT_FEATURES_CNT       (NEUTON_DSP_PIPELINE_COMPUTE_MIN          + NEUTON_DSP_PIPELINE_COMPUTE_MAX     + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_RANGE         + NEUTON_DSP_PIPELINE_COMPUTE_MEAN    + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_RMS           + NEUTON_DSP_PIPELINE_COMPUTE_STD     + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_ZCR           + NEUTON_DSP_PIPELINE_COMPUTE_MCR     + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_TCR           + NEUTON_DSP_PIPELINE_COMPUTE_MAD     + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_SKEW          + NEUTON_DSP_PIPELINE_COMPUTE_KUR     + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF        + NEUTON_DSP_PIPELINE_COMPUTE_P2P_HF  + \
                                                    NEUTON_DSP_PIPELINE_COMPUTE_ABSMEAN       + NEUTON_DSP_PIPELINE_COMPUTE_AMDF  + \
                                                    (2 * NEUTON_DSP_PIPELINE_COMPUTE_MOMENTS) + \
                                                    (2 * NEUTON_DSP_PIPELINE_COMPUTE_MIN_MAX) + \
                                                    (2 * NEUTON_DSP_PIPELINE_COMPUTE_P2P_LF_HF))

#define NEUTON_DSP_USE_SPECTR_PIPELINE              (NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS)
#define NEUTON_DSP_PIPELINE_SPECTR_FEATURES_CNT     (NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_FREQ + NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_AMPL)

#define NEUTON_DSP_PIPELINE_USED_TSS_AND_SUM   ((NEUTON_DSP_PIPELINE_COMPUTE_RMS &&  \
                                               (NEUTON_DSP_PIPELINE_COMPUTE_MEAN || NEUTON_DSP_PIPELINE_COMPUTE_STD)))

#define NEUTON_DSP_PIPELINE_STAT_USED_CTX       (NEUTON_DSP_PIPELINE_USED_TSS_AND_SUM || \
                                                NEUTON_DSP_PIPELINE_COMPUTE_MOMENTS || \
                                                (NEUTON_DSP_PIPELINE_COMPUTE_MEAN && NEUTON_DSP_PIPELINE_COMPUTE_MAD) || \
                                                (NEUTON_DSP_PIPELINE_COMPUTE_MEAN && NEUTON_DSP_PIPELINE_COMPUTE_MCR))

#define NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS   (NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_FREQ || NEUTON_DSP_PIPELINE_COMPUTE_SPECTR_PEAKS_AMPL)

#endif /* _NEUTON_NN_FE_CONFIG_RESOLVER_H_ */