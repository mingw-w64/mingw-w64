/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/timeb.h>

int __cdecl ftime32(struct __timeb32 *tb32);
int __cdecl ftime32(struct __timeb32 *tb32)
{
    _ftime32(tb32);
    return 0;
}

/* On 32-bit systems is ftime ABI using 32-bit time_t */
#ifndef _WIN64
int __attribute__ ((alias("ftime32"))) __cdecl ftime(struct timeb *);
#endif
