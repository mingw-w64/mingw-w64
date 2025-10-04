/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <errno.h>
#include <io.h>
#include <unistd.h>

#if defined(__i386__) || defined(__x86_64__)
#include <windows.h>
#include <msvcrt.h>
#endif

int __cdecl ftruncate64(int fd, _off64_t length)
{
    errno_t error;

    /* Function symbol _chsize_s is available since Windows Vista, so load it dynamically on x86 systems */
#if defined(__i386__) || defined(__x86_64__)
    extern int __cdecl __mingw_ftruncate64(int fd, _off64_t length);

    static errno_t (__cdecl *volatile chsize_s_ptr)(int, __int64);
    static volatile long init = 0;

    if (!init) {
        HMODULE msvcrt = __mingw_get_msvcrt_handle();
        FARPROC func = msvcrt ? GetProcAddress(msvcrt, "_chsize_s") : NULL;
        (void)InterlockedExchangePointer((PVOID volatile *)&chsize_s_ptr, func);
        (void)InterlockedExchange(&init, 1);
    }

    if (!chsize_s_ptr)
        return __mingw_ftruncate64(fd, length);

    #define _chsize_s chsize_s_ptr
#endif

    /* msvcrt.dll's _chsize_s does not call invalid parameter exception handler, so it is not needed to validate input parameters */
    error = _chsize_s(fd, length);
    if (error) {
        errno = error;
        return -1;
    }
    return 0;
}
