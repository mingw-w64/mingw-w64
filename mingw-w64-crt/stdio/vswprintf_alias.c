/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdarg.h>
#include <stddef.h>

/* Intentionally not including stdio.h, as it unconditionally defines the
 * vswprintf inline, and it can't be renamed with "#define vswprintf othername"
 * either, as stdio.h contains "#undef vswprintf". */

int __cdecl __ms_vswprintf(wchar_t *ws, size_t n, const wchar_t *format, va_list arg);

int __cdecl vswprintf(wchar_t *ws, size_t n, const wchar_t *format, va_list arg);
int __cdecl vswprintf(wchar_t *ws, size_t n, const wchar_t *format, va_list arg)
{
  return __ms_vswprintf(ws, n, format, arg);
}
