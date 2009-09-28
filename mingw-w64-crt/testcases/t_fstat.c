#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    if (0 == fstat(0, &st))
        printf("mode = %x\n", st.st_mode);
    return 0;
}

