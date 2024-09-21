/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>

_onexit_t __cdecl _onexit(_onexit_t func)
{
  return atexit((void (__cdecl *)(void))func) == 0 ? func : NULL;
}
_onexit_t __cdecl (*__MINGW_IMP_SYMBOL(_onexit))(_onexit_t func) = _onexit;
