#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

/* Set the foreground process group ID of FD set PGRP_ID.  */
int
tcsetpgrp (fd, pgrp_id)
     int fd;
     pid_t pgrp_id;
{
  if (fd < 0)
    {
      _set_errno (EBADF);
      return -1;
    }

  _set_errno (ENOSYS);
  return 0;
}
