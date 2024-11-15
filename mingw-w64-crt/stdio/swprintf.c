/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdarg.h>
#include <stdio.h>

int __cdecl __ms_swprintf(wchar_t *__restrict__ ws, size_t n, const wchar_t *__restrict__ format, ...)
{
    int retval;
    va_list argptr;

    va_start(argptr, format);
    retval = __ms_vswprintf(ws, n, format, argptr);
    va_end(argptr);
    return retval;
}
