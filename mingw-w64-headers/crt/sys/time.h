/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#include <time.h>

_CRT_BEGIN_C_HEADER

/* TODO: POSIX.1-2008 marked it as obsolete, and POSIX.1-2024 removed it. */
/* libiberty.h requires the second argument to be void* instead of struct timezone* */
int __cdecl gettimeofday(struct timeval* __restrict__ _Tv, void* __restrict__ _Tz);

_CRT_END_C_HEADER

#endif /* _SYS_TIME_H_ */
