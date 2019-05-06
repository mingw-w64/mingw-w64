/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

char *__cdecl gets(char *buf) {
  char *ret = fgets(buf, INT_MAX, stdin);
  if (ret) {
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
      buf[len - 1] = '\0';
  }
  return ret;
}
