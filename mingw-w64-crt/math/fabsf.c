/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
float
fabsf (float x)
{
  float res;
  asm ("fabs;" : "=t" (res) : "0" (x));
  return res;
}
