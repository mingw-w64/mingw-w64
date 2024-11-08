/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* This source file is i386-only */
#if defined(_X86_) || defined(__i386__)

#include <math.h>

float __cdecl _copysignf(float aX, float aY)
{
  return copysignf(aX, aY);
}

float (__cdecl *__MINGW_IMP_SYMBOL(_copysignf))(float, float) = _copysignf;

#endif
