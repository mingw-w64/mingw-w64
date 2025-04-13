/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

static inline __time64_t filetime_to_time64(FILETIME *filetime)
{
    unsigned long long value = ((unsigned long long)filetime->dwHighDateTime << 32) | filetime->dwLowDateTime;
    if (value == 0) return 0; /* 0 has special meaning - not set */
    /* conversion from unsigned 64-bit FILETIME (1601-01-01 in 100-nanoseconds) to signed 64-bit UNIX timestamp (1970-01-01 in seconds) */
    return (value - 116444736000000000LL) / 10000000;
}
