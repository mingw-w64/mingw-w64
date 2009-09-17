/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#define __CRT__NO_INLINE
#include <time.h>

wchar_t *__cdecl _wctime(const time_t *_Time)
{
#ifndef _USE_32BIT_TIME_T
  return _wctime64 (_Time);
#else
  return _wctime32 (_Time);
#endif
}

