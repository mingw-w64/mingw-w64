#include <stdio.h>
#include <assert.h>

int main() {
    FILE *file;

    /* create temporary file which is automatically deleted when process terminates */
    file = tmpfile();
    assert(file);

    /* absolute offset which fits into 32-bit signed type */
    assert(_fseeki64(file, 0x10, SEEK_SET) == 0);
    assert(_ftelli64(file) == 0x10);

    /* TODO: _fseeki64(SEEK_CUR) and _ftelli64() do not work when current position does not fit into 32-bit signed type for pre-msvcrt40 */
#if __MSVCRT_VERSION__ < 0x400
    return 77;
#endif

    /* relative offset which fits into 32-bit signed type, but absolute does not */
    assert(_fseeki64(file, 0x7FFFFFFF, SEEK_CUR) == 0);
    assert(_ftelli64(file) == 0x7FFFFFFFLL + 0x10);

    /* absolute offset which fits into 32-bit unsigned type but does not into 32-bit signed type */
    assert(_fseeki64(file, 0x90000000, SEEK_SET) == 0);
    assert(_ftelli64(file) == 0x90000000);

    /* relative offset which fits into 32-bit unsigned type but absolute does not */
    assert(_fseeki64(file, 0xFFFFFFFF, SEEK_CUR) == 0);
    assert(_ftelli64(file) == 0xFFFFFFFFLL + 0x90000000);

    /* absolute offset which does not fit into 32-bit unsigned type */
    assert(_fseeki64(file, 0x100000000, SEEK_SET) == 0);
    assert(_ftelli64(file) == 0x100000000);

    /* relative offset which does not fit into 32-bit unsigned type */
    assert(_fseeki64(file, 0x100000000, SEEK_CUR) == 0);
    assert(_ftelli64(file) == 0x200000000);

    return 0;
}
