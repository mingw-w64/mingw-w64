/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <io.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "_findX.h"

static int __cdecl emu__wfindnext64(intptr_t find_handle, struct _wfinddata64_t *find_data)
{
    WIN32_FIND_DATAW win32_find_data;
    BOOL success;

    success = FindNextFileW((HANDLE)find_handle, &win32_find_data);
    win32_find_data_to_crt_find_data(success, &win32_find_data, find_data);
    return success ? 0 : -1;
}

#define RETT int
#define FUNC _wfindnext64
#define ARGS intptr_t find_handle, struct _wfinddata64_t *find_data
#define CALL find_handle, find_data
#include "msvcrt_or_emu_glue.h"
