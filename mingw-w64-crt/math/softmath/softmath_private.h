/*
* ====================================================
* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
*
* Developed at SunPro, a Sun Microsystems, Inc. business.
* Permission to use, copy, modify, and distribute this
* software is freely granted, provided that this notice
* is preserved.
* ====================================================
*/

#include <math.h>
#include <inttypes.h>
#include <errno.h>

/* NAN builtins for gcc, as they are not part of math.h  */
#ifndef NANF
#define NANF __builtin_nanf ("")
#endif
#ifndef NANL
#define NANL __builtin_nanl ("")
#endif

extern double bsd__ieee754_fmod(double, double);
extern float bsd__ieee754_fmodf(float, float);
extern double bsd__ieee754_pow(double, double);
extern float bsd__ieee754_powf(float, float);
extern double bsd__ieee754_remainder(double, double);
extern float bsd__ieee754_remainderf(float, float);

static inline double softmath_fact(double number)
{
    if (number <= 0)
        return 1;

    return number * softmath_fact(number - 1);
}

static inline float softmath_expf(float x)
{
    float result = 0.0;
    int n;

    for(n = 0; n < 64; n++)
    {
        result += (bsd__ieee754_powf(x, n) / softmath_fact(n));
        if (isnan(result) || isinf(result))
            break;
    }

    return result;
}

static inline double softmath_log(double x)
{
    int n, aprox = 8 / (x / 2);
    double result = 0.0;

    if (x == 0.0)
        return -HUGE_VALF;
    else if (x < 0.0001)
        aprox = 32768;

    if (aprox < 30)
        aprox = 30;

    for(n = 0; n < aprox; n++)
    {
        result += bsd__ieee754_pow((x - 1.0) / (x + 1.0), 2 * n + 1) * (1.0 / (2.0 * n + 1.0));
        if (isinf(result))
            break;
    }
    result *= 2;

    return result;
}

static inline float softmath_logf(float x)
{
    int n, aprox = 8 / (x / 2);
    float result = 0.0;

    if (x == 0.0)
        return -HUGE_VALF;
    else if (x < 0.0001)
        aprox = 32768;

    if (aprox < 30)
        aprox = 30;

    for(n = 0; n < aprox; n++)
    {
        result += bsd__ieee754_powf((x - 1.0) / (x + 1.0), 2 * n + 1) * (1.0 / (2.0 * n + 1.0));
        if (isinf(result))
            break;
    }
    result *= 2;

    return result;
}
