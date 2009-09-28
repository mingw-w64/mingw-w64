/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

double
round (double x)
{
  double res;
  if (x >= 0.0)
    {
      res = ceil (x);
      if (res - x > 0.5)
	res -= 1.0;
    }
  else
    {
      res = ceil (-x);
      if (res + x > 0.5)
	res -= 1.0;
      res = -res;
    }
  return res;
}
