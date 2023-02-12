/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void __cdecl __chk_fail(void) __attribute__((__noreturn__));

char *__cdecl __gets_chk(char *dst, size_t bufsize);

char *__cdecl __gets_chk(char *dst, size_t bufsize)
{
  char *buf;
  size_t n;
  if (bufsize >= (size_t) INT_MAX)
    return gets(dst);

  buf = malloc(bufsize + 1);
  if (!buf)
    return gets(dst);

  if (!fgets(buf, (int)(bufsize + 1), stdin)) {
    free(buf);
    return NULL;
  }

  n = strlen(buf);
  if (n > 0 && buf[n - 1] == '\n')
    n--;

  if (n >= bufsize)
    __chk_fail();

  memcpy(dst, buf, n);
  dst[n] = '\0';
  free(buf);
  return dst;
}
