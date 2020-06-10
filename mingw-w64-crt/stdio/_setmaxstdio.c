/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>

int __cdecl _setmaxstdio(int _Max) {
  if (_Max < _IOB_ENTRIES || _Max > _getmaxstdio())
    return -1;
  return _Max;
}
int __cdecl (*__MINGW_IMP_SYMBOL(_setmaxstdio))(int) = _setmaxstdio;
