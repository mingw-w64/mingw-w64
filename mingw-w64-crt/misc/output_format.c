/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <windows.h>

static unsigned int last_value = 0;

static unsigned int emu__get_output_format(void)
{
    return last_value;
}

static unsigned int emu__set_output_format(unsigned int value)
{
    return InterlockedExchange((LONG*)&last_value, value);
}

#define RETT unsigned int
#define FUNC _get_output_format
#define ARGS void
#define CALL
#include "msvcrt_or_emu_glue.h"

#define RETT unsigned int
#define FUNC _set_output_format
#define ARGS unsigned int format
#define CALL format
#include "msvcrt_or_emu_glue.h"
