#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>
#include <assert.h>

int main() {
    FILE *file;
    int fd;
    struct _utimbuf times;
    struct __utimbuf32 times32;
    struct __utimbuf64 times64;
    struct stat st;
    struct _stat32 st32;
    struct _stat64 st64;


    /* prepare temporary file */

    file = tmpfile();
    assert(file);
    fd = fileno(file);
    assert(fd >= 0);


    /* set timezone to some very strange value, to ensure that set-get roundtrip is not affected by timezone */

    assert(putenv("TZ=+04:05:06") == 0);
    tzset();


    /* set and get 32-bit mtime via different 32-bit and 64-bit interfaces */

    times.actime = 0x2FFFFFF0;
    times.modtime = 0x4FFFFFF0;
    printf("_futime(    mtime=%I64x)\n", (long long)times.modtime);
    assert(_futime(fd, &times) == 0);

    assert(fstat(fd, &st) == 0);
    printf("fstat():    mtime=%I64x\n", (long long)st.st_mtime);
    assert(st.st_mtime == 0x4FFFFFF0);

    assert(_fstat32(fd, &st32) == 0);
    printf("_fstat32(): mtime=%lx\n", st32.st_mtime);
    assert(st32.st_mtime == 0x4FFFFFF0);

    assert(_fstat64(fd, &st64) == 0);
    printf("_fstat64(): mtime=%I64x\n", st64.st_mtime);
    assert(st64.st_mtime == 0x4FFFFFF0);

    printf("\n");


    times32.actime = 0x2FFFFF00;
    times32.modtime = 0x4FFFFF00;
    printf("_futime32(  mtime=%lx)\n", times32.modtime);
    assert(_futime32(fd, &times32) == 0);

    assert(fstat(fd, &st) == 0);
    printf("fstat():    mtime=%I64x\n", (long long)st.st_mtime);
    assert(st.st_mtime == 0x4FFFFF00);

    assert(_fstat32(fd, &st32) == 0);
    printf("_fstat32(): mtime=%lx\n", st32.st_mtime);
    assert(st32.st_mtime == 0x4FFFFF00);

    assert(_fstat64(fd, &st64) == 0);
    printf("_fstat64(): mtime=%I64x\n", st64.st_mtime);
    assert(st64.st_mtime == 0x4FFFFF00);

    printf("\n");


    times64.actime = 0x2FFFF000;
    times64.modtime = 0x4FFFF000;
    printf("_futime64(  mtime=%I64x)\n", times64.modtime);
    assert(_futime64(fd, &times64) == 0);

    assert(fstat(fd, &st) == 0);
    printf("fstat():    mtime=%I64x\n", (long long)st.st_mtime);
    assert(st.st_mtime == 0x4FFFF000);

    assert(_fstat32(fd, &st32) == 0);
    printf("_fstat32(): mtime=%lx\n", st32.st_mtime);
    assert(st32.st_mtime == 0x4FFFF000);

    assert(_fstat64(fd, &st64) == 0);
    printf("_fstat64(): mtime=%I64x\n", st64.st_mtime);
    assert(st64.st_mtime == 0x4FFFF000);

    printf("\n");


    /* set and get 64-bit mtime via 64-bit interfaces */

    times64.actime = 0x13FFFF000LL;
    times64.modtime = 0x15FFFF000LL;
    printf("_futime64(  mtime=%I64x)\n", times64.modtime);
    assert(_futime64(fd, &times64) == 0);

    assert(_fstat64(fd, &st64) == 0);
    printf("_fstat64(): mtime=%I64x\n", st64.st_mtime);
    assert(st64.st_mtime == 0x15FFFF000LL);


    return 0;
}
