/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
float fabsf (float x);

float
fabsf (float x)
{
#ifdef __x86_64__
  return __builtin_fabsf (x);
#else
  float res = 0.0F;
  asm ("fabs;" : "=t" (res) : "0" (x));
  return res;
#endif
}
