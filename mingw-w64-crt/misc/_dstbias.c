/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

#undef _dstbias
static long _dstbias = -3600; /* pre-msvcrt40 uses fixed one hour dst bias */
long * __MINGW_IMP_SYMBOL(_dstbias) = &_dstbias;
