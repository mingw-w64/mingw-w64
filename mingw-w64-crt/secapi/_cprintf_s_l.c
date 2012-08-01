#include <windows.h>
#include <malloc.h>
#include <errno.h>

HMODULE __mingw_get_msvcrt_handle(void);
int __cdecl _cprintf_s_l (const char *, _locale_t, ...);
int __cdecl _vcprintf_s_l(const char *,_locale_t,va_list);

errno_t __cdecl (*__MINGW_IMP_SYMBOL(_cprintf_s_l))(const char *, _locale_t, ...) = 
 _cprintf_s_l;

int __cdecl
_cprintf_s_l (const char *s, _locale_t loc, ...)
{
  va_list argp;
  int r;

  va_start (argp, s);
  r = _vcprintf_s_l (s, loc, argp);
  va_end (argp);
  return r; 
}
