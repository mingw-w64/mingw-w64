#include <errno.h>
#include <stddef.h>
#include <termios.h>

static int bad_speed (speed_t speed);

/* Set the state of FD to *TERMIOS_P.  */
int
tcsetattr (int fd, int optional_actions, const struct termios *termios_p)
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }
  if (termios_p == NULL)
    {
      _set_errno (EINVAL);
      return -1;
    }
  switch (optional_actions)
    {
    case TCSANOW:
    case TCSADRAIN:
    case TCSAFLUSH:
      break;
    default:
      _set_errno (EINVAL);
      return 0;
    }

  if (bad_speed(termios_p->c_ospeed) ||
      bad_speed(termios_p->c_ispeed == 0 ?
		termios_p->c_ospeed : termios_p->c_ispeed))
    {
      _set_errno (EINVAL);
      return -1;
    }

  _set_errno (ENOSYS);
  return 0;
}


/* Strychnine checking.  */
static int
bad_speed (speed_t speed)
{
#if 0
  switch (speed)
    {
    case B0:
    case B50:
    case B75:
    case B110:
    case B134:
    case B150:
    case B200:
    case B300:
    case B600:
    case B1200:
    case B1800:
    case B2400:
    case B4800:
    case B9600:
    case B19200:
    case B38400:
    case B57600:
    case B115200:
    case B230400:
    case B460800:
    case B500000:
    case B576000:
    case B921600:
    case B1000000:
    case B1152000:
    case B1500000:
    case B2000000:
    case B2500000:
    case B3000000:
    case B3500000:
    case B4000000:
      return 0;
    default:
      return 1;
    }
#else
  return 0;
#endif
}
