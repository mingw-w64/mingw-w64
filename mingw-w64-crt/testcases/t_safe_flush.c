#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <process.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <versionhelpers.h>

#define STRING "hello world!"

/* child process */

CRITICAL_SECTION cs;

static DWORD WINAPI thread_main(LPVOID user_data) {
    HANDLE handle_event = (HANDLE) user_data;

    /* This thread acquires a critical section and then
     * sleeps indefinitely. This way the critical section
     * will be orphaned during process termination
     */
    EnterCriticalSection(&cs);

    /* Signal the main thread that it can continue */
    SetEvent(handle_event);
    Sleep(INFINITE);

    return 0;
}

static void spawn_thread(void) {
    HANDLE handle_event;

    assert(handle_event = CreateEvent(NULL, TRUE, FALSE, NULL));
    assert(CreateThread(NULL, 0, thread_main, handle_event, 0, NULL) != NULL);
    assert(WaitForSingleObject(handle_event, INFINITE) == WAIT_OBJECT_0);
    assert(CloseHandle(handle_event));
}

typedef void (* callback_t)(void *);

__declspec(dllimport)
void lib_proc_detach_set_callback(callback_t, void*);

static void acquire_critical_section(void *user_data) {
    EnterCriticalSection(&cs);
}

int child_main(void) {
    InitializeCriticalSection(&cs);

    /* Spawn the secondary thread which acquires the critical
     * section (and never releases it)
     */
    spawn_thread();

    /* Make our helper DLL acquire the critical section on
     * DLL_PROCESS_DETACH. This will cause instant termination
     * of the process
     */
    lib_proc_detach_set_callback(acquire_critical_section, NULL);

    /* Set stdout to full-buffering mode (useful in case the test
     * is run directly from a terminal)
     */
    assert(setvbuf(stdout, NULL, _IOFBF, 4096) == 0);

    /* Print a string so that stdout needs flushing at exit */
    fputs(STRING, stdout);
    assert(!ferror(stdout));

    /* The C RunTime library flushes streams from its DllMain
     * handler on DLL_PROCESS_DETACH. However that DllMain
     * won't run because another DLL triggers instant termination.
     * stdout can only be flushed by the safe flush implemented
     * in mingw-w64-crt
     */

    return 0;
}

/* parent process */

int parent_main(const char *argv0) {
    int exit_code;
    int pipefd[2];
    int back_outfd;
    intptr_t process;
    size_t size = 0;
    char buf[512];

    assert(_pipe(pipefd, sizeof(buf), O_NOINHERIT) == 0);

    /* set stdout fd to write side of pipe, will be used by _spawnl() */
    assert((back_outfd = dup(STDOUT_FILENO)) >= 0);
    assert(dup2(pipefd[1], STDOUT_FILENO) == 0);
    assert(close(pipefd[1]) == 0);

    /* spawn child process to read stdout */
    process = _spawnl(_P_NOWAIT, _pgmptr, argv0, "safe_flush_test", NULL);

    /* revert back stdout fd */
    assert(dup2(back_outfd, STDOUT_FILENO) == 0);
    assert(close(back_outfd) == 0);

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

/* common */

int main(int argc, char *argv[]) {
    if (!IsWindowsVistaOrGreater()) {
        /* This test requires at least Windows Vista (where
         * CRITICAL_SECTIONs were made shutdown-aware)
         */
        return 77;  /* skip */
    }

    if (argc != 2 || strcmp(argv[1], "safe_flush_test") != 0) {
        return parent_main(argv[0]);
    }

    return child_main();
}
