#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int fd;
    FILE *file;
    fpos_t pos;
    ftello64(stdin);
    _ftelli64(stdin);
    fgetpos64(stdin, &pos);
    fseeko64(stdin, 0, SEEK_CUR);
    _fseeki64(stdin, 0, SEEK_CUR);
    pos = 0;
    fsetpos64(stdin, &pos);
    lseek64(STDIN_FILENO, 0, SEEK_CUR);
    _lseeki64(STDIN_FILENO, 0, SEEK_CUR);
    file = fopen64(argc >= 2 ? argv[1] : argv[0], "r");
    if (file) {
        freopen64(argc >= 2 ? argv[1] : argv[0], "r", file);
        fclose(file);
    }
    file = tmpfile64();
    if (file) fclose(file);
    fd = open64(argc >= 2 ? argv[1] : argv[0], O_RDONLY);
    if (fd >= 0) close(fd);
    return 0;
}
