/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/timeb.h>

int __cdecl ftime64(struct __timeb64 *tb64);
int __cdecl ftime64(struct __timeb64 *tb64)
{
    _ftime64(tb64);
    return 0;
}

/* On 64-bit systems is ftime ABI using 64-bit time_t */
#ifdef _WIN64
int __attribute__ ((alias("ftime64"))) __cdecl ftime(struct timeb *);
#endif
