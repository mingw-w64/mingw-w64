/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

double exp2(double x)
{
    return pow(2, x);
}

float exp2f(float x)
{
    return powf(2, x);
}

long double exp2l(long double x)
{
#if defined(__aarch64__) || defined(_ARM64_)
    return exp2(x);
#else
#error Not supported on your platform yet
#endif
}
