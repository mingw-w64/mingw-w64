/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sys/stat.h>
#include <windows.h>

#include "filetime_to_time64.h"

static int __cdecl emu__wstat64(const wchar_t *path, struct _stat64 *stat)
{
    HANDLE handle;
    WIN32_FIND_DATAW fi;
    struct _stat32 st;
    int ret = _wstat32(path, &st);
    if (ret != 0)
        return ret;
    stat->st_dev = st.st_dev;
    stat->st_ino = st.st_ino;
    stat->st_mode = st.st_mode;
    stat->st_nlink = st.st_nlink;
    stat->st_uid = st.st_uid;
    stat->st_gid = st.st_gid;
    stat->st_rdev = st.st_rdev;
    handle = FindFirstFileW(path, &fi);
    if (handle != INVALID_HANDLE_VALUE) {
        FindClose(handle);
        stat->st_size = ((_off64_t)fi.nFileSizeHigh << 32) | fi.nFileSizeLow;
        stat->st_atime = filetime_to_time64(&fi.ftLastAccessTime);
        stat->st_mtime = filetime_to_time64(&fi.ftLastWriteTime);
        stat->st_ctime = filetime_to_time64(&fi.ftCreationTime);
    } else {
        stat->st_size = st.st_size; /* truncated value */
        stat->st_atime = st.st_atime; /* invalid value -1 */
        stat->st_mtime = st.st_mtime; /* invalid value -1 */
        stat->st_ctime = st.st_ctime; /* invalid value -1 */
    }
    return 0;
}

#define RETT int
#define FUNC _wstat64
#define ARGS const wchar_t *path, struct _stat64 *stat
#define CALL path, stat
#include "msvcrt_or_emu_glue.h"
