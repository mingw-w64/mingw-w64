#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h>

#define _WIN32_WINNT_NT35 MAKEWORD(50, 3) /* really decimal, not hex */

#define type(mode) (S_ISDIR(mode) ? "DIR" : S_ISFIFO(mode) ? "FIFO" : S_ISCHR(mode) ? "CHR" : S_ISBLK(mode) ? "BLK" : S_ISREG(mode) ? "REG" : "UNKN")

int main(int argc, char *argv[])
{
    char windows_dir_path[MAX_PATH + 1];
    char buffer[sizeof(windows_dir_path) + 128];
    struct stat st;
    struct stat64 st64;
    DWORD raw_ver;
    unsigned ver;
    unsigned type;

    if (0 == stat(argv[0], &st))
        printf("mode = %x\n", st.st_mode);
    if (0 == stat64(argv[0], &st64))
        printf("mode = %x\n", st64.st_mode);

    assert(stat("nul", &st) == 0);
    printf("nul: %s\n", type(st.st_mode));
    assert(S_ISCHR(st.st_mode));

    assert(stat("NUL", &st) == 0);
    printf("NUL: %s\n", type(st.st_mode));
    assert(S_ISCHR(st.st_mode));

    if (!GetWindowsDirectoryA(windows_dir_path, MAX_PATH))
        return 77;

    raw_ver = GetVersion();
    ver = ((raw_ver & 0xff) << 8) | ((raw_ver & 0xff00) >> 8);
    type = (raw_ver >> 30) ^ 2;

    if (type != VER_PLATFORM_WIN32_NT)
        return 77;

    snprintf(buffer, sizeof(buffer), "\\\\.\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    /* WinAPI namespace \\?\ is supported since Windows NT 3.5 */
    if (ver < _WIN32_WINNT_NT35)
        return 77;

    snprintf(buffer, sizeof(buffer), "\\\\?\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    /* NT \??\Global and NT \??\GLOBALROOT is available since Windows 2000 */
    if (ver < _WIN32_WINNT_WIN2K)
        return 0;

    snprintf(buffer, sizeof(buffer), "\\\\.\\Global\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\?\\Global\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\.\\GLOBALROOT\\??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\?\\GLOBALROOT\\??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\.\\GLOBALROOT\\DosDevices\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\?\\GLOBALROOT\\DosDevices\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    /* NT \GLOBAL?? is available since Windows XP */
    if (ver < _WIN32_WINNT_WINXP)
        return 0;

    snprintf(buffer, sizeof(buffer), "\\\\.\\GLOBALROOT\\GLOBAL??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\?\\GLOBALROOT\\GLOBAL??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\.\\GLOBALROOT\\GLOBAL??\\GLOBALROOT\\??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    snprintf(buffer, sizeof(buffer), "\\\\?\\GLOBALROOT\\GLOBAL??\\GLOBALROOT\\??\\%s", windows_dir_path);
    assert(stat(buffer, &st) == 0);
    printf("%s: %s\n", buffer, type(st.st_mode));
    assert(S_ISDIR(st.st_mode));

    return 0;
}

