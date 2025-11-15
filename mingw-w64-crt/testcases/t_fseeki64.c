#include <stdio.h>
#include <assert.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

static void assert_winapi_seek(HANDLE handle, LONGLONG offset, DWORD method) {
    LARGE_INTEGER li = { .QuadPart = offset };
    li.LowPart = SetFilePointer(handle, li.LowPart, &li.HighPart, method);
    assert(li.LowPart != INVALID_SET_FILE_POINTER || GetLastError() == NO_ERROR);
}

int main() {
    FILE *file;
    HANDLE handle;
    char buf[5];
    DWORD len;

    /* create temporary file which is automatically deleted when process terminates */
    file = tmpfile();
    assert(file);

    /* use text mode which translates \n to \r\n */
    assert(_setmode(fileno(file), _O_TEXT) != -1);

    /* absolute offset which fits into 32-bit signed type */
    assert(_fseeki64(file, 0x10, SEEK_SET) == 0);
    assert(fputs("A\n", file) >= 0);
    assert(fputs("A", file) >= 0);

    /* relative offset which fits into 32-bit signed type, but absolute does not */
    assert(_fseeki64(file, 0x7FFFFFFF, SEEK_CUR) == 0);
    assert(fputs("B\n", file) >= 0);
    assert(fputs("B", file) >= 0);

    /* absolute offset which fits into 32-bit unsigned type but does not into 32-bit signed type */
    assert(_fseeki64(file, 0x90000000, SEEK_SET) == 0);
    assert(fputs("C\n", file) >= 0);
    assert(fputs("C", file) >= 0);

    /* TODO: SEEK_CUR does not work when current position does not fit into 32-bit signed type for pre-msvcrt40 */
#if __MSVCRT_VERSION__ >= 0x400
    /* relative offset which fits into 32-bit unsigned type but absolute does not */
    assert(_fseeki64(file, 0xFFFFFFFF, SEEK_CUR) == 0);
    assert(fputs("D\n", file) >= 0);
    assert(fputs("D", file) >= 0);
#else
    assert(_fseeki64(file, 0xFFFFFFFF, SEEK_CUR) == -1);
    assert(errno == EOVERFLOW);
#endif

    /* absolute offset which does not fit into 32-bit unsigned type */
    assert(_fseeki64(file, 0x100000000, SEEK_SET) == 0);
    assert(fputs("E\n", file) >= 0);
    assert(fputs("E", file) >= 0);

    /* TODO: SEEK_CUR does not work when current position does not fit into 32-bit signed type for pre-msvcrt40 */
#if __MSVCRT_VERSION__ >= 0x400
    /* relative offset which does not fit into 32-bit unsigned type */
    assert(_fseeki64(file, 0x100000000, SEEK_CUR) == 0);
    assert(fputs("F\n", file) >= 0);
    assert(fputs("F", file) >= 0);
#else
    assert(_fseeki64(file, 0x100000000, SEEK_CUR) == -1);
    assert(errno == EOVERFLOW);
#endif

    /* last absolute write, without the nul byte */
    assert(_fseeki64(file, 0x300000000, SEEK_SET) == 0);
    assert(fputs("_\n", file) >= 0);
    assert(fputs("_", file) >= 0);

    /* flush all data, so they can be accessed via WinAPI */
    assert(fflush(file) == 0);

    /* now read all data via WinAPI and check that they were written at correct offsets */

    handle = (HANDLE)_get_osfhandle(fileno(file));
    assert(handle != INVALID_HANDLE_VALUE);

    assert_winapi_seek(handle, 0, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "\0\0\0\0", 5) == 0);

    assert_winapi_seek(handle, 0x10, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "A\r\nA", 5) == 0);

    assert_winapi_seek(handle, 0x7FFFFFFFLL + 0x10 + 4, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "B\r\nB", 5) == 0);

    assert_winapi_seek(handle, 0x90000000, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "C\r\nC", 5) == 0);

    /* TODO: SEEK_CUR does not work when current position does not fit into 32-bit signed type for pre-msvcrt40 */
#if __MSVCRT_VERSION__ >= 0x400
    assert_winapi_seek(handle, 0xFFFFFFFFLL + 0x90000000 + 4, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "D\r\nD", 5) == 0);
#endif

    assert_winapi_seek(handle, 0x100000000, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "E\r\nE", 5) == 0);

    /* TODO: SEEK_CUR does not work when current position does not fit into 32-bit signed type for pre-msvcrt40 */
#if __MSVCRT_VERSION__ >= 0x400
    assert_winapi_seek(handle, 0x200000000 + 4, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == sizeof(buf));
    assert(memcmp(buf, "F\r\nF", 5) == 0);
#endif

    assert_winapi_seek(handle, 0x300000000, FILE_BEGIN);
    assert(ReadFile(handle, buf, sizeof(buf), &len, NULL) == TRUE);
    assert(len == 4); /* sizeof(buf)-1 -> no nul byte */
    assert(memcmp(buf, "_\r\n_", 4) == 0);

    return 0;
}
