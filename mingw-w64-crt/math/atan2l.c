/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
long double
atan2l (long double y, long double x)
{
  long double res;
  asm ("fpatan" : "=t" (res) : "u" (y), "0" (x) : "st(1)");
  return res;
}
