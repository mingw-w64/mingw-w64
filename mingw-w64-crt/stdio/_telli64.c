/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <io.h>
#include <unistd.h>

__int64 __cdecl _telli64(int fd) { return _lseeki64(fd, 0, SEEK_CUR); }
__int64 (__cdecl *__MINGW_IMP_SYMBOL(_telli64))(int) = _telli64;
