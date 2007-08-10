#include <errno.h>
#include <termios.h>

/* Flush pending data on FD.  */
int
tcflush (fd, queue_selector)
     int fd;
     int queue_selector;
{
  switch (queue_selector)
    {
    case TCIFLUSH:
    case TCOFLUSH:
    case TCIOFLUSH:
      break;

    default:
      _set_errno (EINVAL);
      return 0;
    }

  _set_errno (ENOSYS);
  return 0;
}
