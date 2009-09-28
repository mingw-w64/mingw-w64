/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
long double fabsl (long double x);

long double
fabsl (long double x)
{
  long double res = 0.0L;
  asm ("fabs;" : "=t" (res) : "0" (x));
  return res;
}
