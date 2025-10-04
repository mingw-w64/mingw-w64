/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <errno.h>
#include <io.h>
#include <unistd.h>

int __cdecl ftruncate64(int fd, _off64_t length)
{
    errno_t error;

    /* _chsize_s calls invalid parameter exception handler, so validate input parameters */
    if (fd < 0) {
        errno = EBADF;
        return -1;
    }
    if (length < 0) {
        errno = EINVAL;
        return -1;
    }
    error = _chsize_s(fd, length);
    if (error) {
        errno = error;
        return -1;
    }
    return 0;
}
