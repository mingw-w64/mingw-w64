#define _UNICODE
#include <assert.h>
#include <fcntl.h>
#include <io.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* mingw-w64 headers */
#include "libtest.h"

/**
 * On some Windows versions, crtdll.dll, msvcrt20.dll and msvcrt40.dll may be
 * redirected to system msvcrt.dll.
 *
 * This may result in `_setmode` succeeding to set `stderr` to Unicode
 * translation mode, while `_wassert` emulation still calls `_assert`.
 *
 * This would result in `assert` macro silently terminating the process without
 * producing any output.
 *
 * CRT function `_wassert` is available since msvcr80.dll, and msvcrt.dll
 * since Windows Vista. Only attempt to set `stderr` to Unicode translation
 * mode with msvcrt.dll, or msvcr80.dll and later.
 */
#if __MSVCRT_VERSION__ == 0x0600 || __MSVCRT_VERSION__ >= 0x0800
#define TEST_UNICODE_MODE
#endif

int main(int argc, char *argv[]) {
    mingw_test_init ();

    if (argc != 2 || strcmp(argv[1], "assert_test") != 0) {
        int exit_code;
        int pipefd[2];
        int back_errfd;
        intptr_t process;
        ssize_t size;
        char buf[512];

        assert(_pipe(pipefd, 0, O_NOINHERIT) == 0);

        /* set stderr fd to write side of pipe, will be used by _spawnl() */
        assert((back_errfd = dup(STDERR_FILENO)) >= 0);
        assert(dup2(pipefd[1], STDERR_FILENO) == 0);
        assert(close(pipefd[1]) == 0);

        process = _spawnl(_P_NOWAIT, _pgmptr, argv[0], "assert_test", NULL);

        /* revert back stderr fd */
        assert(dup2(back_errfd, STDERR_FILENO) == 0);
        assert(close(back_errfd) == 0);

        assert(process != -1);

        size = read(pipefd[0], buf, sizeof(buf));
        assert(size > 0); /* some data were written by child process */
        assert(strnlen(buf, sizeof(buf)) > 0);

        /* wait until child process exits */
        assert(_cwait(&exit_code, process, _WAIT_CHILD) == process);
        assert(exit_code != 0);

        /* read the rest of data in the pipe and write it to stdout */
        if (size < (ssize_t)sizeof(buf)) {
            size += read(pipefd[0], &buf[size], sizeof(buf) - size);
        }
        close(pipefd[0]);
        write(STDOUT_FILENO, buf, size);

        return 0;
    }

#ifdef TEST_UNICODE_MODE
    /* change stderr to translated UNICODE mode */
    _setmode(_fileno(stderr), _O_U8TEXT);
#endif

    /* call assert, it prints to stderr, parent process will check that our stderr is not empty */
    assert(0);

    /* assert(0) does not return, this process pass when returns non-zero */
    return 0;
}
