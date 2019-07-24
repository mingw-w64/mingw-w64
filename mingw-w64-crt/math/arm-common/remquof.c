/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <errno.h>

float remquof(float x, float y, int *quo)
{
  if (isnan(x))
    return x;
  if (isnan(y))
    return y;
  if (isinf(x) || y == 0)
    return NAN;
  float div = x/y;
  float integral;
  float frac = modff(div, &integral);
  int iintegral = (int)integral;
  if (frac == 0.5) {
    if (iintegral & 1)
      *quo = iintegral + 1;
    else
      *quo = iintegral;
  } else if (frac == -0.5) {
    if (iintegral & 1)
      *quo = iintegral - 1;
    else
      *quo = iintegral;
  } else
    *quo = roundf(div);
  return x - *quo * y;
}
