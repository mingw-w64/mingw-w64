#include <io.h>

_off64_t lseek64(int fd,_off64_t offset, int whence) 
{
  return _lseeki64(fd, (_off64_t) offset, whence);
}

