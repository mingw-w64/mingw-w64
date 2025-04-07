/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>

size_t __cdecl _aligned_msize(void *memory, size_t alignment, size_t offset)
{
  return __mingw_aligned_msize(memory, alignment, offset);
}
size_t (__cdecl *__MINGW_IMP_SYMBOL(_aligned_msize))(void *, size_t, size_t) = _aligned_msize;
