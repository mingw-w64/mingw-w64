/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdarg.h>
#include <stddef.h>

/* Intentionally not including stdio.h, as it unconditionally defines the
 * vswprintf inline, and it can't be renamed with "#define vsnwprintf othername"
 * either, as stdio.h contains "#undef vsnwprintf". */

int __cdecl __ms_vsnwprintf(wchar_t *buffer, size_t n, const wchar_t *format, va_list argptr);

int __cdecl vsnwprintf(wchar_t *buffer, size_t n, const wchar_t *format, va_list argptr);
int __cdecl vsnwprintf(wchar_t *buffer, size_t n, const wchar_t *format, va_list argptr)
{
  return __ms_vsnwprintf(buffer, n, format, argptr);
}
