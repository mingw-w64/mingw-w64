#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

/* Return the foreground process group ID of FD.  */
pid_t
tcgetpgrp (fd)
     int fd;
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return (pid_t) -1;
    }

  _set_errno (ENOSYS);
  return (pid_t) 0;
}
