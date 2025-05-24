/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>

static errno_t __cdecl emu_getenv_s(size_t *pReturnValue, char *dstBuf, rsize_t dstSize, const char *varName)
{
    const char *value;
    size_t size;

    /* Only below parameter validation sets errno to EINVAL. */

    if (!pReturnValue)
        return errno = EINVAL;

    if ((!dstBuf && dstSize > 0) || (dstBuf && !dstSize)) {
        *pReturnValue = 0;
        return errno = EINVAL;
    }

    if (!varName) {
        *pReturnValue = 0;
        if (dstBuf)
            dstBuf[0] = '\0';
        return errno = EINVAL;
    }

    /* After passing parameter validation, the errno is not changed. */

    value = getenv(varName);
    if (!value) {
        *pReturnValue = 0;
        if (dstBuf)
            dstBuf[0] = '\0';
        return 0;
    }

    size = strlen(value)+1;
    *pReturnValue = size;

    if (dstBuf) {
        if (size > dstSize) {
            dstBuf[0] = '\0';
            return ERANGE;
        }
        memcpy(dstBuf, value, size);
    }

    return 0;
}

#define RETT errno_t
#define FUNC getenv_s
#define ARGS size_t *pReturnValue, char *dstBuf, rsize_t dstSize, const char *varName
#define CALL pReturnValue, dstBuf, dstSize, varName
#include "msvcrt_or_emu_glue.h"
