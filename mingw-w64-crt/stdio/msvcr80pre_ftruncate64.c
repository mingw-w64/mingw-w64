/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <unistd.h>

int __cdecl __mingw_ftruncate64(int fd, _off64_t length);

int __cdecl ftruncate64(int fd, _off64_t length)
{
    return __mingw_ftruncate64(fd, length);
}
