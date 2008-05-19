/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

float
roundf (float x)
{
  float res;
  if (x >= 0.0F)
    {
      res = ceilf (x);
      if (res - x > 0.5F)
	res -= 1.0F;
    }
  else
    {
      res = ceilf (-x);
      if (res + x > 0.5F)
	res -= 1.0F;
      res = -res;
    }
  return res;
}
