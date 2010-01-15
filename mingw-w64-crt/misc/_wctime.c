/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

#ifndef _USE_32BIT_TIME_T
wchar_t *__cdecl _wctime(const time_t *_Time)
{
  return _wctime64 (_Time);
}
#else
wchar_t *__cdecl _wctime(const time_t *_Time)
{
  return _wctime32 (_Time);
}
#endif /* _USE_32BIT_TIME_T */

