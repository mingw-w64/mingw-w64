/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw.h>

#undef _wctime
#undef _wctime32

_CRTIMP wchar_t *__cdecl _wctime(const __time32_t *_Time);

wchar_t *__cdecl _wctime32(const __time32_t *_Time);

wchar_t *__cdecl _wctime32(const __time32_t *_Time)
{
  return _wctime (_Time);
}

