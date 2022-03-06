/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>
#include <math.h>

#undef __setusermatherr
void __setusermatherr(__UNUSED_PARAM(int (__cdecl *f)(struct _exception *))) { }
