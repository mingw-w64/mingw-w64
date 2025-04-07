/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>

static void * __cdecl emu__aligned_realloc(void *memory, size_t size, size_t alignment)
{
    return __mingw_aligned_realloc(memory, size, alignment);
}

#define RETT void *
#define FUNC _aligned_realloc
#define ARGS void *memory, size_t size, size_t alignment
#define CALL memory, size, alignment
#include "msvcrt_or_emu_glue.h"
