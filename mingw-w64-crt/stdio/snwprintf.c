/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <stdarg.h>
#include <wchar.h>

int  snwprintf(wchar_t* buffer, size_t n, const wchar_t* format, ...)
{
    int retval;
    va_list argptr;
          
    va_start( argptr, format );
    retval = _vsnwprintf( buffer, n, format, argptr );
    va_end( argptr );
    return retval;
}
