/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>

void __cdecl __chk_fail(void) __attribute__((__noreturn__));

void *__cdecl __memset_chk(void *dst, int c, size_t n, size_t bufsize);

void *__cdecl __memset_chk(void *dst, int c, size_t n, size_t bufsize)
{
  if (n > bufsize)
    __chk_fail();
  return memset(dst, c, n);
}
