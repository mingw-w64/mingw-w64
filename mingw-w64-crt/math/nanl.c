/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include "fp_consts.h"

extern const union _ieee_rep __QNANL;

/* FIXME */
long double nanl(const char * tagp __attribute__((unused)))
{
#if __SIZEOF_LONG_DOUBLE__ == __SIZEOF_DOUBLE__
  return nan("");
#else
  return __QNANL.ldouble_val;
#endif
}
