#include <errno.h>
#include <stddef.h>
#include <termios.h>

/* Put the state of FD into *TERMIOS_P.  */
int
__tcgetattr (fd, termios_p)
     int fd;
     struct termios *termios_p;
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }
  if (termios_p == NULL)
    {
      _set_errno (EINVAL);
      return 0;
    }

  _set_errno (ENOSYS);
  return 0;
}
