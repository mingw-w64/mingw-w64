/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

#include "pi_const.h"

float __cdecl atanpif(float x)
{
  return atanf(x) / __pi_type(x);
}
