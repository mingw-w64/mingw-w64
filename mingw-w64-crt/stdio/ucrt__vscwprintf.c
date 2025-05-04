/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT
#include <stdio.h>

int __cdecl _vscwprintf(const wchar_t * restrict format, va_list args)
{
  return __stdio_common_vswprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR, NULL, 0, format, NULL, args);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_vscwprintf))(const wchar_t * restrict, va_list) = _vscwprintf;
