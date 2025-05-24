/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>
#include <errno.h>
#include <windows.h>

errno_t __cdecl getenv_s(size_t *pReturnValue, char *dstBuf, rsize_t dstSize, const char *varName)
{
    DWORD ret;

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

    /*
     * Function GetEnvironmentVariableA() is documented on:
     * https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getenvironmentvariablea
     */
    ret = GetEnvironmentVariableA(varName, dstBuf, dstSize);
    if (ret == 0) {
        /* If the function fails, the return value is zero (e.g. specified
         * environment variable was not found).
         * Zero value is returned also when function passes, environment
         * variable exists but has zero length value.
         */
        ret = GetLastError();
        *pReturnValue = ret == ERROR_SUCCESS ? 1 : 0;
        if (dstBuf)
            dstBuf[0] = '\0';
        if (ret == ERROR_SUCCESS || ret == ERROR_ENVVAR_NOT_FOUND)
            return 0;
        else if (ret == ERROR_NOT_ENOUGH_MEMORY)
            return ENOMEM;
        else
            return EINVAL;
    } else if (dstSize > 0 && ret > dstSize) {
        /* If buffer is not large enough to hold the data, the return value is
         * the buffer size, in characters, required to hold the string and its
         * terminating null character and the contents of buffer are undefined.
         */
        *pReturnValue = ret;
        if (dstBuf)
            dstBuf[0] = '\0';
        return ERANGE;
    } else {
        /* If the GetEnvironmentVariable succeeds, the return value is the
         * number of characters stored in the buffer, not including the
         * terminating null character.
         */
        *pReturnValue = ret+1;
        return 0;
    }
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(getenv_s))(size_t *, char *, rsize_t, const char *) = getenv_s;
