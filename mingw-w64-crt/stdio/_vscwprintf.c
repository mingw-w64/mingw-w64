/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <errno.h>

/* emulation of _vscwprintf() via _vsnwprintf() */
static int __cdecl emu_vscwprintf(const wchar_t * __restrict__ format, va_list arglist)
{
    wchar_t *buffer, *new_buffer;
    size_t size;
    int ret = -1;

    /* if format is a null pointer, _vscwprintf() returns -1 and sets errno to EINVAL */
    if (!format) {
        errno = EINVAL;
        return -1;
    }

    /* size for _vsnwprintf() must be non-zero and buffer must have place for terminating null character */
    size = (wcslen(format) * 2 + 1) * sizeof(wchar_t);
    buffer = malloc(size);

    if (!buffer) {
        errno = ENOMEM;
        return -1;
    }

    /* if the number of characters to write is greater than size, _vsnwprintf() returns -1 */
    while (size < SIZE_MAX/2 && (ret = _vsnwprintf(buffer, size, format, arglist)) < 0) {
        /* in this case try with larger buffer */
        size *= 2;
        new_buffer = realloc(buffer, size);
        if (!new_buffer)
            break;
        buffer = new_buffer;
    }

    free(buffer);

    if (ret < 0) {
        errno = ENOMEM;
        return -1;
    }

    return ret;
}

#ifndef __LIBMSVCRT_OS__

int __attribute__ ((alias ("emu_vscwprintf"))) __cdecl _vscwprintf(const wchar_t * __restrict__, va_list);
int (__cdecl *__MINGW_IMP_SYMBOL(_vscwprintf))(const wchar_t * __restrict__, va_list) = _vscwprintf;

#else

#include <msvcrt.h>

static int __cdecl init_vscwprintf(const wchar_t * __restrict__ format, va_list arglist);

int (__cdecl *__MINGW_IMP_SYMBOL(_vscwprintf))(const wchar_t * __restrict__, va_list) = init_vscwprintf;

static int __cdecl init_vscwprintf(const wchar_t * __restrict__ format, va_list arglist)
{
    HMODULE msvcrt = __mingw_get_msvcrt_handle();
    int (__cdecl *func)(const wchar_t * __restrict__, va_list) = NULL;

    if (msvcrt)
        func = (int (__cdecl *)(const wchar_t * __restrict__, va_list))GetProcAddress(msvcrt, "_vscwprintf");

    if (!func)
        func = emu_vscwprintf;

    return (__MINGW_IMP_SYMBOL(_vscwprintf) = func)(format, arglist);
}

int __cdecl _vscwprintf(const wchar_t * __restrict__ format, va_list arglist)
{
    return __MINGW_IMP_SYMBOL(_vscwprintf)(format, arglist);
}

#endif
