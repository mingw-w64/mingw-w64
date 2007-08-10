#include <errno.h>
#include <termios.h>

/* Wait for pending output to be written on FD.  */
int
__libc_tcdrain (int fd)
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }

  _set_errno (ENOSYS);
  return 0;
}
