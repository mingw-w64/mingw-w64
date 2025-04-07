/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>

static void * __cdecl emu__aligned_malloc(size_t size, size_t alignment)
{
    return __mingw_aligned_malloc(size, alignment);
}

#define RETT void *
#define FUNC _aligned_malloc
#define ARGS size_t size, size_t alignment
#define CALL size, alignment
#include "msvcrt_or_emu_glue.h"
