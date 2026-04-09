/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <string.h>

char *__cdecl strndup(const char *src, size_t size);

char *__cdecl strndup(const char *src, size_t size)
{
  size_t len = strnlen(src, size);
  char *copy;

  copy = malloc(len + 1);
  if (!copy)
    return NULL;

  if (len != 0)
    memcpy(copy, src, len);
  copy[len] = '\0';
  return copy;
}
