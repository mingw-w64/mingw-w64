#include <assert.h>
#include <io.h>
#include <stdio.h>
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

int main() {
    FILE *file;
    int fd;

    mingw_test_init ();

    /* create temporary file which is automatically deleted when process terminates */
    file = tmpfile();
    assert(file);
    fd = fileno(file);
    assert(fd >= 0);

    /* check if the filesystem supports large files (>= 4GB) */
    BOOL fs_supports_large_files = TRUE;
    HANDLE handle = (HANDLE)_get_osfhandle(fd);
    assert(handle != INVALID_HANDLE_VALUE);
    LARGE_INTEGER li = { .QuadPart = 0x200000000 };
    li.LowPart = SetFilePointer(handle, li.LowPart, &li.HighPart, FILE_BEGIN);
    if (li.LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR) {
        fs_supports_large_files = FALSE;
    }
    SetFilePointer(handle, 0, NULL, FILE_BEGIN);

    /* absolute offset which fits into 32-bit signed type */
    assert(_lseeki64(fd, 0x10, SEEK_SET) == 0x10);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x10);

    /* relative offset which fits into 32-bit signed type, but absolute does not */
    assert(_lseeki64(fd, 0x7FFFFFFF, SEEK_CUR) == 0x7FFFFFFFLL + 0x10);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x7FFFFFFFLL + 0x10);

    /* absolute offset which fits into 32-bit unsigned type but does not into 32-bit signed type */
    assert(_lseeki64(fd, 0x90000000, SEEK_SET) == 0x90000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x90000000);

    if (fs_supports_large_files) {

    /* relative offset which fits into 32-bit unsigned type but absolute does not */
    assert(_lseeki64(fd, 0xFFFFFFFF, SEEK_CUR) == 0xFFFFFFFFLL + 0x90000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0xFFFFFFFFLL + 0x90000000);

    /* absolute offset which does not fit into 32-bit unsigned type */
    assert(_lseeki64(fd, 0x100000000, SEEK_SET) == 0x100000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x100000000);

    /* relative offset which does not fit into 32-bit unsigned type */
    assert(_lseeki64(fd, 0x100000000, SEEK_CUR) == 0x200000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x200000000);

    }

    return 0;
}
