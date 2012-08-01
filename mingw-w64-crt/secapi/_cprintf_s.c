#include <windows.h>
#include <malloc.h>
#include <errno.h>

HMODULE __mingw_get_msvcrt_handle(void);
int __cdecl _cprintf_s (const char *,...);
int __cdecl _vcprintf_s (const char *,va_list);

int __cdecl (*__MINGW_IMP_SYMBOL(_cprintf_s))(const char *,...) = 
 _cprintf_s;

int __cdecl
_cprintf_s (const char *s, ...)
{
  va_list argp;
  int r;

  va_start (argp, s);
  r = _vcprintf_s (s, argp);
  va_end (argp);
  return r; 
}
