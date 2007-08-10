#include <errno.h>
#include <termios.h>

/* Send zero bits on FD.  */
int
tcsendbreak (fd, duration)
     int fd;
     int duration;
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }

  _set_errno (ENOSYS);
  return 0;
}
