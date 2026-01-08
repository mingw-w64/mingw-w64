/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

#include "pi_const.h"

float __cdecl cospif(float x)
{
  x = fmodf(x, 2.0F);
  return cosf(x * __pi_type(x));
}
