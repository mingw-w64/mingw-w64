/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <io.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <windows.h>

#include "_findX.h"

static intptr_t __cdecl emu__wfindfirst64(const wchar_t *path, struct _wfinddata64_t *find_data)
{
    WIN32_FIND_DATAW win32_find_data;
    HANDLE handle;

    handle = FindFirstFileW(path, &win32_find_data);
    win32_find_data_to_crt_find_data(handle != NULL && handle != INVALID_HANDLE_VALUE, &win32_find_data, find_data);
    return (intptr_t)handle;
}

#define RETT intptr_t
#define FUNC _wfindfirst64
#define ARGS const wchar_t *path, struct _wfinddata64_t *find_data
#define CALL path, find_data
#include "msvcrt_or_emu_glue.h"
