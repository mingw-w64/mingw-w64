/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <_mingw.h>
#include <stdarg.h>
#include <stddef.h>

/* Intentionally not including stdio.h, as it unconditionally defines the
 * vsnprintf inline, and it can't be renamed with "#define vsnprintf othername"
 * either, as stdio.h contains "#undef vsnprintf". */

_CRTIMP int __cdecl _vscprintf(const char * __restrict__ _Format,va_list _ArgList);
_CRTIMP int __cdecl _vsnprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,va_list _Args);

int __cdecl __ms_vsnprintf (char *s,size_t n,const char *format,va_list arg);

int __cdecl __ms_vsnprintf (char *s,size_t n,const char *format,va_list arg)
{
    int retval;

    /* _vsnprintf() does not work with zero length buffer
     * so count number of character by _vscprintf() call */
    if (n == 0 || !s)
        return _vscprintf(format, arg);

    retval = _vsnprintf(s, n, format, arg);

    /* _vsnprintf() returns negative number if buffer is too small
     * so count number of character by _vscprintf() call */
    if (retval < 0)
        retval = _vscprintf(format, arg);

    /* _vsnprintf() does not fill trailing null byte if there is not place for it */
    if ((size_t)retval >= n)
        s[n-1] = '\0';

    return retval;
}

int __attribute__ ((alias ("__ms_vsnprintf"))) __cdecl vsnprintf(char*, size_t, const char *, va_list);
