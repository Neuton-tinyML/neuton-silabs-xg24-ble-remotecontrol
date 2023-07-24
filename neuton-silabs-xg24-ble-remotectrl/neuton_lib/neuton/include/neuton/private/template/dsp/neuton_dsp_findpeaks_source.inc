#include <neuton/private/common/neuton_defs.h>

#ifndef FPEAKS_INPUT_TYPE
    #error "FPEAKS_INPUT_TYPE is not defined!"
#endif

#define INPUT_T     CONCAT3(neuton, FPEAKS_INPUT_TYPE, t)

// ///////////////////////////////////////////////////////////////////////////

void FUNCTION_NAME(neuton_dsp_findpeaks, FPEAKS_INPUT_TYPE)(INPUT_T* p_input, 
                                                            neuton_u16_t num,  
                                                            neuton_u16_t p_peaks_index[3U],
                                                            INPUT_T* p_peaks_ampl)
{
    p_input[0] = 0; // remove constant component of the signal

    INPUT_T left = 0;
    INPUT_T right = 0;
    for (neuton_u16_t i = 0; i < num; ++i)
    {
        left = right;
        right = (i == num - 1 ? 0 : p_input[i + 1] - p_input[i]);
        if (left > 0 && right <= 0)
        {
            // there is an extremmum
            if (p_input[i] > p_input[p_peaks_index[0]])
            {
                p_peaks_index[2] = p_peaks_index[1];
                p_peaks_index[1] = p_peaks_index[0];
                p_peaks_index[0] = i;
            }
            else if (p_input[i] > p_input[p_peaks_index[1]])
            {
                p_peaks_index[2] = p_peaks_index[1];
                p_peaks_index[1] = i;
            }
            else if (p_input[i] > p_input[p_peaks_index[2]])
            {
                p_peaks_index[2] = i;
            }
        }
    }

    if (p_peaks_ampl)
    {
        for (size_t i = 0; i < NEUTON_FIND_PEAKS_MAX_NUM; i++)
            p_peaks_ampl[i] = p_input[p_peaks_index[i]];
    }
}