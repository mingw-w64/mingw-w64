/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <errno.h>

double remquo(double x, double y, int *quo)
{
  if (isnan(x))
    return x;
  if (isnan(y))
    return y;
  if (isinf(x) || y == 0)
    return NAN;
  double div = x/y;
  double integral;
  double frac = modf(div, &integral);
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
    *quo = round(div);
  return x - *quo * y;
}
