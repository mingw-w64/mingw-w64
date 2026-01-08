/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

#include "pi_const.h"

long double __cdecl atan2pil(long double y, long double x)
{
  return atan2l(y, x) / __pi_type(y);
}
