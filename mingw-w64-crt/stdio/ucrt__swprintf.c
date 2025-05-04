/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT
#include <stdio.h>
#include <stdarg.h>

int __cdecl _swprintf(wchar_t * restrict dest, const wchar_t * restrict format, ...)
{
  int ret;
  va_list args;
  va_start(args, format);
  ret = __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, dest, (size_t)-1, format, NULL, args);
  va_end(args);
  return ret;
}
int __cdecl (*__MINGW_IMP_SYMBOL(_swprintf))(wchar_t * restrict, const wchar_t * restrict, ...) = _swprintf;
