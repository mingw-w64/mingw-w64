#include <stddef.h>
#include <errno.h>
#include <termios.h>

#undef cfgetospeed
/* Return the output baud rate stored in *TERMIOS_P.  */
speed_t
cfgetospeed (termios_p)
     const struct termios *termios_p;
{
  return termios_p->c_ospeed;
}

#undef cfgetispeed
/* Return the input baud rate stored in *TERMIOS_P.  */
speed_t
cfgetispeed (termios_p)
     const struct termios *termios_p;
{
  return termios_p->c_ispeed;
}

#undef cfsetospeed
/* Set the output baud rate stored in *TERMIOS_P to SPEED.  */
int
cfsetospeed (termios_p, speed)
     struct termios *termios_p;
     speed_t speed;
{
  if (termios_p == NULL)
    {
      _set_errno (EINVAL);
      return -1;
    }

  termios_p->c_ospeed = speed;
  return 0;
}

#undef cfsetispeed
/* Set the input baud rate stored in *TERMIOS_P to SPEED.  */
int
cfsetispeed (termios_p, speed)
     struct termios *termios_p;
     speed_t speed;
{
  if (termios_p == NULL)
    {
      _set_errno (EINVAL);
      return -1;
    }

  termios_p->c_ispeed = speed;
  return 0;
}
