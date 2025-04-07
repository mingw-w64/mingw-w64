/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <malloc.h>

static void __cdecl emu__aligned_free(void *memory)
{
    __mingw_aligned_free(memory);
}

#define RETT void
#define FUNC _aligned_free
#define ARGS void *memory
#define CALL memory
#include "msvcrt_or_emu_glue.h"
