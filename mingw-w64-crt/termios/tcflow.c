#include <errno.h>
#include <termios.h>

/* Suspend or restart transmission on FD.  */
int
tcflow (fd, action)
     int fd;
     int action;
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }

  switch (action)
    {
    case TCOOFF:
    case TCOON:
    case TCIOFF:
    case TCION:
      break;

    default:
      _set_errno (EINVAL);
      return 0;
    }

  _set_errno (ENOSYS);
  return 0;
}
