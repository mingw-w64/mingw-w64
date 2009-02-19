/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

double copysign(double x, double y)
{
  unsigned int hx,hy;
  hx = ((unsigned int *)&x)[1];
  hy = ((unsigned int *)&y)[1];
  ((unsigned int *)&x)[1] =  (hx & 0x7fffffff) | (hy & 0x80000000);
  return x;
}
