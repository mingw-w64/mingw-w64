#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    struct stat64 st64;
    if (0 == stat(argv[0], &st))
        printf("mode = %x\n", st.st_mode);
    if (0 == stat64(argv[0], &st64))
        printf("mode = %x\n", st64.st_mode);
    return 0;
}

