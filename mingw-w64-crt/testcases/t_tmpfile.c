#include <stdio.h>
#include <direct.h>
#include <assert.h>

int main() {
    FILE *file;

    /* ensure that tmpfile() works also when cwd is in C:\Windows or C:\ but do not fail if caller has no access to C:\ */
    if (chdir("C:\\Windows\\") != 0)
        chdir("C:\\");

    file = tmpfile();
    assert(file);

    assert(fputs("test", file) >= 0);
    assert(fflush(file) == 0);

    /* ensure that _rmtmp() works also for emulated mingw-w64 tmpfile() implementation */
    assert(_rmtmp() == 1);

    return 0;
}
