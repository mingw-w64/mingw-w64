#include <stdio.h>
#include <assert.h>
#include <io.h>

int main() {
    FILE *file;
    int fd;

    /* create temporary file which is automatically deleted when process terminates */
    file = tmpfile();
    assert(file);
    fd = fileno(file);
    assert(fd >= 0);

    /* absolute offset which fits into 32-bit signed type */
    assert(_lseeki64(fd, 0x10, SEEK_SET) == 0x10);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x10);

    /* relative offset which fits into 32-bit signed type, but absolute does not */
    assert(_lseeki64(fd, 0x7FFFFFFF, SEEK_CUR) == 0x7FFFFFFFLL + 0x10);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x7FFFFFFFLL + 0x10);

    /* absolute offset which fits into 32-bit unsigned type but does not into 32-bit signed type */
    assert(_lseeki64(fd, 0x90000000, SEEK_SET) == 0x90000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x90000000);

    /* relative offset which fits into 32-bit unsigned type but absolute does not */
    assert(_lseeki64(fd, 0xFFFFFFFF, SEEK_CUR) == 0xFFFFFFFFLL + 0x90000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0xFFFFFFFFLL + 0x90000000);

    /* absolute offset which does not fit into 32-bit unsigned type */
    assert(_lseeki64(fd, 0x100000000, SEEK_SET) == 0x100000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x100000000);

    /* relative offset which does not fit into 32-bit unsigned type */
    assert(_lseeki64(fd, 0x100000000, SEEK_CUR) == 0x200000000);
    assert(_lseeki64(fd, 0, SEEK_CUR) == 0x200000000);

    return 0;
}
