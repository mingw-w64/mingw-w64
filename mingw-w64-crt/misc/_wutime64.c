/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <utime.h>
#include <fcntl.h>
#include <io.h>

static int __cdecl emu__wutime64(const wchar_t *filename, struct __utimbuf64 *times)
{
    int fd;
    int ret;

    fd = _wopen(filename, O_RDWR | O_BINARY);
    if (fd < 0)
        return -1;

    ret = _futime64(fd, times);
    close(fd);
    return ret;
}

#define RETT int
#define FUNC _wutime64
#define ARGS const wchar_t *filename, struct __utimbuf64 *times
#define CALL filename, times
#include "msvcrt_or_emu_glue.h"
