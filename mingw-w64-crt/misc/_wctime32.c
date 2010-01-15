/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __NO_INLINE__
#define __NO_INLINE__
#endif
#include <time.h>

extern wchar_t * (__cdecl *__MINGW_IMP_SYMBOL(wctime))(const __time32_t *);

wchar_t *__cdecl _wctime32(const __time32_t *_Time)
{
  return (*__MINGW_IMP_SYMBOL(wctime))(_Time);
}

