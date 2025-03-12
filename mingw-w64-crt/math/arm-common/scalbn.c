/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

double scalbn(double x, int exp)
{
    return x * exp2(exp);
}

float scalbnf(float x, int exp)
{
    return x * exp2f(exp);
}

long double scalbnl(long double x, int exp)
{
    return scalbn(x, exp);
}

double scalbln(double x, long exp)
{
    return x * exp2(exp);
}

float scalblnf(float x, long exp)
{
    return x * exp2f(exp);
}

long double scalblnl(long double x, long exp)
{
    return scalbln(x, exp);
}
