#include <stdarg.h>
#include <errno.h>
#include <sys/ioctl.h>

#undef ioctl
/* Perform the I/O control operation specified by REQUEST on FD.
   The actual type and use of ARG and the return value depend on REQUEST.  */
int
ioctl (int fd, int request, ...)
{
  void *arg;
  va_list ap;
  int result;

  va_start (ap, request);
  arg = va_arg (ap, void *);

  switch (request)
    {
    default:
	  _set_errno (ENOSYS);
	  result = -1;
      break;
    }
  va_end (ap);
  return result;
}
