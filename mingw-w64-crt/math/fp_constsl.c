/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include "fp_consts.h"

const union _ieee_rep __QNANL = { __LONG_DOUBLE_QNAN_REP };
const union _ieee_rep __SNANL  = { __LONG_DOUBLE_SNAN_REP };
const union _ieee_rep __INFL = { __LONG_DOUBLE_INF_REP };
const union _ieee_rep __DENORML = { __LONG_DOUBLE_DENORM_REP };


#undef nanl
/* FIXME */
long double nanl (const char * tagp __attribute__((unused)) )
  { return __QNANL.ldouble_val; } 
