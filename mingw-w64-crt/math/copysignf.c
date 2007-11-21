/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

float copysignf(float x, float y)
{
  unsigned int ix,iy;
  ix = ((unsigned int *) &x)[0];
  iy = ((unsigned int *) &y)[0];
  ((unsigned int *) &x)[0] = (ix & 0x7fffffff) | (iy & 0x80000000);
  return x;
}
