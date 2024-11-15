/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdarg.h>
#include <stddef.h>

/* Intentionally not including stdio.h, as it unconditionally defines the
 * swprintf inline, and it can't be renamed with "#define swprintf othername"
 * either, as stdio.h contains "#undef swprintf". */

int __cdecl __ms_vswprintf(wchar_t *ws, size_t n, const wchar_t *format, va_list arg);

int __cdecl swprintf(wchar_t* ws, size_t n, const wchar_t *format, ...);
int __cdecl swprintf(wchar_t* ws, size_t n, const wchar_t *format, ...)
{
  int retval;
  va_list argptr;

  va_start(argptr, format);
  retval = __ms_vswprintf(ws, n, format, argptr);
  va_end(argptr);
  return retval;
}
