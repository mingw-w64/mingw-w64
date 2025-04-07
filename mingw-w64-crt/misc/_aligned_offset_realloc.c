/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>

static void * __cdecl emu__aligned_offset_realloc(void *memory, size_t size, size_t alignment, size_t offset)
{
    return __mingw_aligned_offset_realloc(memory, size, alignment, offset);
}

#define RETT void *
#define FUNC _aligned_offset_realloc
#define ARGS void *memory, size_t size, size_t alignment, size_t offset
#define CALL memory, size, alignment, offset
#include "msvcrt_or_emu_glue.h"
