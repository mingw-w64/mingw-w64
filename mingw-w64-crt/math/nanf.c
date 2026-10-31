/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include "fp_consts.h"

extern const union _ieee_rep __QNANF;

/* FIXME */
float nanf(const char * tagp __attribute__((unused)))
{
  return __QNANF.float_val;
}
