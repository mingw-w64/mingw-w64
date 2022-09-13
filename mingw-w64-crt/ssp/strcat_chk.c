/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>

void __cdecl __chk_fail(void) __attribute__((__noreturn__));

char *__cdecl __strcat_chk(char *dst, const char *src, size_t bufsize);

char *__cdecl __strcat_chk(char *dst, const char *src, size_t bufsize)
{
  size_t cur_len = strlen(dst);
  char *orig_dst = dst;

  if (cur_len > bufsize)
    __chk_fail();

  dst += cur_len;
  bufsize -= cur_len;

  while (*src) {
    if (bufsize == 0)
      __chk_fail();
    *dst++ = *src++;
    bufsize--;
  }

  if (bufsize == 0)
    __chk_fail();
  *dst++ = '\0';

  return orig_dst;
}
