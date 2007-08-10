#include <errno.h>

errno_t __cdecl _set_errno (int _Value)
{
  errno = _Value;
}

errno_t __cdecl _get_errno (int *_Value)
{
  if(_Value) *_Value=errno;
  return errno;
}
