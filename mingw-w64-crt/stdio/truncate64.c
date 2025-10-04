#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int truncate64(const char *pathname, _off64_t len){
  int ret, err;
  int fd = _open(pathname,_O_BINARY|_O_RDWR);
  if (fd == -1) return fd;
  ret = ftruncate64(fd,len);
  err = errno;
  _close(fd);
  errno = err;
  return ret;
}
