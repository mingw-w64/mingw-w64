/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>

void __cdecl __chk_fail(void) __attribute__((__noreturn__));

char *__cdecl __strcpy_chk(char *dst, const char *src, size_t bufsize);

char *__cdecl __strcpy_chk(char *dst, const char *src, size_t bufsize)
{
  size_t n = strlen(src);
  if (n >= bufsize)
    __chk_fail();
  return memcpy(dst, src, n + 1);
}
