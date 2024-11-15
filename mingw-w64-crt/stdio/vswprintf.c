/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <stdarg.h>
#include <stdio.h>

int __cdecl __ms_vswprintf(wchar_t *__restrict__ ws, size_t n, const wchar_t *__restrict__ format, va_list arg)
{
    int retval;

    /* ISO C95+ vswprintf() returns negative value if buffer has zero size */
    if (n == 0)
        return -1;

    /*
     * _vsnwprintf() returns number of filled wide chars up to the N or -1 otherwise.
     * ISO C95+ vswprintf() returns number of filled wide chars excluding the
     * trailing nul (therefore up to the N-1) or -1 otherwise.
     * So call _vsnwprintf() with n-1 to have correct return value (-1) when more
     * wide chars (inc nul) were requested to write into the output buffer than N.
     */
    retval = _vsnwprintf(ws, n-1, format, arg);

    /* _vsnwprintf() does not fill trailing nul wide char if there is not place for it */
    if (retval < 0 || (size_t)retval == n-1)
        ws[n-1] = L'\0';

    return retval;
}
