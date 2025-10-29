/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

FILE *__cdecl tmpfile(void)
{
    /* GetTempPathA() requires buffer of size MAX_PATH+1
     * and tmpnam() requires buffer of size L_tmpnam.
     */
    char path[MAX_PATH+1+L_tmpnam];
    DWORD len;
    int fd;
    FILE *file;

    len = GetTempPathA(MAX_PATH, path);
    if (len == 0 || len > MAX_PATH) {
        errno = EINVAL;
        return NULL;
    }

    /* Function tmpnam() generates path name starting with backslash,
     * so ensure that the temp directory path does not contain it.
     */
    if (path[len-1] == '\\')
        len--;

    /* Generate temporary file path and exclusively create+open it in binary mode.
     * If the generated temporary file path already exist then generate new one again.
     * Note that we cannot use fopen() because msvcrt does not support exclusive 'x' mode.
     * Use open() with O_CREAT | O_EXCL flags followed by the fdopen() to get FILE* stream.
     */
    do {
        if (tmpnam(path+len) != path+len)
            return NULL;
        fd = open(path, O_RDWR | O_CREAT | O_EXCL | O_BINARY | O_TEMPORARY, S_IREAD | S_IWRITE);
        if (fd < 0 && errno != EEXIST)
            return NULL;
    } while (fd < 0);

    file = fdopen(fd, "r+b");
    if (!file) {
        int saved_errno = errno;
        close(fd);
        errno = saved_errno;
        return NULL;
    }

    /* Mark the associated FILE* stream as temporary, so the _rmtmp() can remove it. */
    file->_tmpfname = strdup(path);
    if (!file->_tmpfname) {
        fclose(file);
        errno = ENOMEM;
        return NULL;
    }

    return file;
}
FILE * (__cdecl *__MINGW_IMP_SYMBOL(tmpfile))(void) = tmpfile;

FILE * __attribute__((alias("tmpfile"))) __cdecl tmpfile64(void);
extern FILE * (__cdecl *__attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(tmpfile))))) __MINGW_IMP_SYMBOL(tmpfile64))(void);
