/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT
#include <wchar.h>

int __cdecl mbsinit(const mbstate_t *_P)
{
  return (!_P || _P->_Wchar == 0);
}
