/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include "filetime_to_time64.h"

#define win32_find_data_to_crt_find_data(success, win32_find_data, crt_find_data) do { \
    if (!(success)) { \
        switch (GetLastError()) { \
        case ERROR_FILE_NOT_FOUND: \
        case ERROR_PATH_NOT_FOUND: \
        case ERROR_NO_MORE_FILES: \
            errno = ENOENT; \
            break; \
        case ERROR_NOT_ENOUGH_MEMORY: \
            errno = ENOMEM; \
            break; \
        default: \
            errno = EINVAL; \
            break; \
        } \
    } else { \
        (crt_find_data)->attrib = (win32_find_data)->dwFileAttributes == FILE_ATTRIBUTE_NORMAL ? 0 : (win32_find_data)->dwFileAttributes; \
        (crt_find_data)->time_create = filetime_to_time64(&(win32_find_data)->ftCreationTime); \
        (crt_find_data)->time_access = filetime_to_time64(&(win32_find_data)->ftLastAccessTime); \
        (crt_find_data)->time_write = filetime_to_time64(&(win32_find_data)->ftLastWriteTime); \
        (crt_find_data)->size = ((unsigned long long)(win32_find_data)->nFileSizeHigh << 32) | (win32_find_data)->nFileSizeLow; \
        _Static_assert(sizeof((crt_find_data)->name) == sizeof((win32_find_data)->cFileName), "mismatch size of CRT finddata's name and WIN32_FIND_DATA's cFileName"); \
        memcpy((crt_find_data)->name, (win32_find_data)->cFileName, sizeof((crt_find_data)->name)); \
    } \
} while (0)
