#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

/* Return the session ID of FD.  */
pid_t
tcgetsid (fd)
     int fd;
{
  pid_t pgrp;
  pid_t sid;
#ifdef TIOCGSID
  static int tiocgsid_does_not_work;

  if (! tiocgsid_does_not_work)
    {
      int serrno = errno;
      int sid;

      if (__ioctl (fd, TIOCGSID, &sid) < 0)
	{
	  if (errno == EINVAL)
	    {
	      tiocgsid_does_not_work = 1;
	      _set_errno (serrno);
	    }
	  else
	    return (pid_t) -1;
	}
      else
	return (pid_t) sid;
    }
#endif

  pgrp = tcgetpgrp (fd);
  if (pgrp == -1)
    return (pid_t) -1;

  sid = getsid (pgrp);
  if (sid == -1 && errno == ESRCH)
    _set_errno (ENOTTY);

  return sid;
}
