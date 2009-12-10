#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

char * WINAPI
WspiapiStrdup (const char *pszString)
{
  char *rstr;
  size_t szlen;

  if(!pszString)
    return NULL;
  szlen = strlen(pszString) + 1;
  rstr = (char *) WspiapiMalloc (szlen);
  if (!rstr)
    return NULL;
  strcpy (rstr, pszString);
  return rstr;
}
