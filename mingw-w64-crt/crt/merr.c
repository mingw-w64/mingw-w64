/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>

const int __defaultmatherr = 1; /* non-tentative */

int __cdecl _matherr(struct _exception *pexcept __attribute__((unused)))
{
  return 0;
}
