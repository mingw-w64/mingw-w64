/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdarg.h>
#include <stdio.h>
#include <sec_api/stdio_s.h>

int __cdecl vsnprintf_s (char *s, size_t _DstSize, size_t _MaxCount, const char *format, va_list arg)
{
    return _vsnprintf_s(s, _DstSize, _MaxCount, format, arg);
}
