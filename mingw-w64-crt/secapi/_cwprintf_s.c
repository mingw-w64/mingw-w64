#include <windows.h>
#include <malloc.h>
#include <errno.h>

HMODULE __mingw_get_msvcrt_handle(void);
int __cdecl _cwprintf_s (const wchar_t *,...);
int __cdecl _vcwprintf_s (const wchar_t *,va_list);

int __cdecl (*__MINGW_IMP_SYMBOL(_cwprintf_s))(const wchar_t *,...) = 
 _cwprintf_s;

int __cdecl
_cwprintf_s (const wchar_t *s, ...)
{
  va_list argp;
  int r;

  va_start (argp, s);
  r = _vcwprintf_s (s, argp);
  va_end (argp);
  return r; 
}
