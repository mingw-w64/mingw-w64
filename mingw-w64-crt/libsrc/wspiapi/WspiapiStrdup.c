#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

char *WINAPI WspiapiStrdup (const char *pszString)
{
  char *pszMemory;
  size_t cchMemory;
  if (!pszString)
    return(NULL);
  cchMemory = strlen(pszString) + 1;
  pszMemory = (char *) WspiapiMalloc(cchMemory);
  if (!pszMemory)
    return(NULL);
  _WSPIAPI_STRCPY_S(pszMemory,cchMemory,pszString);
  return pszMemory;
}
