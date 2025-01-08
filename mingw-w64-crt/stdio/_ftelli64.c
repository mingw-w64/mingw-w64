/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>
#include <io.h>
#include <errno.h>

__int64 __cdecl _ftelli64(FILE* stream)
{
  fpos_t pos;
  if (fgetpos (stream, &pos))
    return -1LL;
  else
    return (__int64) pos;
}

__int64 __cdecl (*__MINGW_IMP_SYMBOL(_ftelli64))(FILE*) = _ftelli64;
