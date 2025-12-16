#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <process.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#define STRING "hello world!\n"

int main(int argc, char *argv[]) {
    if (argc != 2 || strcmp(argv[1], "stderr_buffering_test") != 0) {
        int exit_code;
        int pipefd[2];
        int back_errfd;
        intptr_t process;
        size_t size = 0;
        char buf[512];

        assert(_pipe(pipefd, sizeof(buf), _O_NOINHERIT) == 0);

        /* set stderr fd to write side of pipe, will be used by _spawnl() */
        assert((back_errfd = dup(STDERR_FILENO)) >= 0);
        assert(dup2(pipefd[1], STDERR_FILENO) == 0);
        assert(close(pipefd[1]) == 0);

        process = _spawnl(_P_NOWAIT, _pgmptr, argv[0], "stderr_buffering_test", NULL);

        /* revert back stderr fd */
        assert(dup2(back_errfd, STDERR_FILENO) == 0);
        assert(close(back_errfd) == 0);

        assert(process != -1);

        /* read data as required */
        while (size < strlen (STRING)) {
            int delta = read(pipefd[0], buf + size, sizeof(buf) - size);
            assert(delta > 0);
            size += delta;
        }

        /* no more data is available */
        assert(read(pipefd[0], buf + size, sizeof(buf) - size) == 0);
        close(pipefd[0]);

        /* wait until child process exits */
        assert(_cwait(&exit_code, process, _WAIT_CHILD) == process);
        assert(exit_code == 0);

        assert(size == strlen (STRING));
        assert(memcmp(buf, STRING, strlen (STRING)) == 0);

        return 0;
    }

    /* stderr must not be fully-buffered on startup */
    fputs(STRING, stderr);
    assert(!ferror (stderr));

    /* could also use _Exit here... */
    TerminateProcess(GetCurrentProcess(), 0);

    /* unreachable */
    assert(0);
}
