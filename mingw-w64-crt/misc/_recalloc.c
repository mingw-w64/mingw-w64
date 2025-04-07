/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>
#include <string.h>

void * __cdecl _recalloc(void *memory, size_t count, size_t size)
{
  void *new_memory;
  size_t previous_size;
  size_t total_size;
  if (__builtin_mul_overflow(count, size, &total_size))
    return NULL;
  previous_size = memory ? _msize(memory) : 0;
  if (previous_size == (size_t)-1)
    return NULL;
  new_memory = realloc(memory, total_size);
  if (new_memory && previous_size < total_size)
    memset(new_memory + previous_size, 0, total_size - previous_size);
  return new_memory;
}
void * (__cdecl *__MINGW_IMP_SYMBOL(_recalloc))(void *, size_t, size_t) = _recalloc;
