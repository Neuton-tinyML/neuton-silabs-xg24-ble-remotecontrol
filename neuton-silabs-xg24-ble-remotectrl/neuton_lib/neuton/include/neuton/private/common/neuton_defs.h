#ifndef _NEUTON_DEFINITIONS_H_
#define _NEUTON_DEFINITIONS_H_

#include <neuton/neuton_platform.h>

#define NEUTON_USE_LOOPUNROLL           (0)
#define NEUTON_USE_MATH_ROUNDING        (0)

#define NEUTON_INT_TO_F32_PRECISION_FACTOR  (100)

#define CONCAT2x(a,b) a ## _ ## b 
#define CONCAT2(a,b) CONCAT2x(a,b)

#define CONCAT3x(a,b,c) a ## _ ## b ## _ ## c
#define CONCAT3(a,b,c) CONCAT3x(a,b,c)

#define CONCAT4x(a,b,c,d) a ## _ ## b ## _ ## c ## _ ## d
#define CONCAT4(a,b,c,d) CONCAT4x(a,b,c,d)

#define FUNCTION_NAME(name, postfix)    CONCAT2(name, postfix)


#endif /* _NEUTON_DEFINITIONS_H_ */