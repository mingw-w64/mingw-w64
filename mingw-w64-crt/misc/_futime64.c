/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <errno.h>
#include <utime.h>
#include <time.h>
#include <io.h>

#include "filetime_to_time64.h"

static int __cdecl emu__futime64(int fd, struct __utimbuf64 *times)
{
    struct __utimbuf64 utimbuf64;
    FILETIME last_access_time;
    FILETIME last_write_time;
    HANDLE handle;

    handle = (HANDLE)_get_osfhandle(fd);
    if (handle == INVALID_HANDLE_VALUE)
        return -1;

    if (!times) {
        utimbuf64.actime = utimbuf64.modtime = _time64(NULL);
        times = &utimbuf64;
    }

    time64_to_filetime(times->actime, &last_access_time);
    time64_to_filetime(times->modtime, &last_write_time);

    if (!SetFileTime(handle, NULL, &last_access_time, &last_write_time)) {
        errno = EINVAL;
        return -1;
    }

    return 0;
}

#define RETT int
#define FUNC _futime64
#define ARGS int fd, struct __utimbuf64 *times
#define CALL fd, times
#include "msvcrt_or_emu_glue.h"
