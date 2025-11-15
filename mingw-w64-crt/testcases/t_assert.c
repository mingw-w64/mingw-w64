#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <process.h>
#include <io.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2 || strcmp(argv[1], "assert_test") != 0) {
        int exit_code;
        int pipefd[2];
        int back_errfd;
        intptr_t process;
        ssize_t size;
        char buf[512];

        assert(_pipe(pipefd, sizeof(buf), O_NOINHERIT) == 0);

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
        close(pipefd[0]);
        assert(size > 0); /* some data were written by child process */
        assert(strnlen(buf, sizeof(buf)) > 0);

        /* wait until child process exits */
        assert(_cwait(&exit_code, process, _WAIT_CHILD) == process);
        assert(exit_code != 0);

        return 0;
    }

    /* change stderr to translated UNICODE mode */
    _setmode(fileno(stderr), _O_U8TEXT);

    /* call assert, it prints to stderr, parent process will check that our stderr is not empty */
#if __MSVCRT_VERSION__ > 0x800
    _set_abort_behavior(0, _CALL_REPORTFAULT); /* assert() will not call Dr. Watson */
#endif
    assert(0);

    /* assert(0) does not return, this process pass when returns non-zero */
    return 0;
}
