#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

WINBOOL WINAPI
WspiapiParseV4Address (const char *pszAddress, PDWORD pdwAddress)
{
  DWORD dwAddress = 0;
  const char *pcNext = NULL;
  int iCount = 0;
  for (pcNext = pszAddress; *pcNext != '\0'; pcNext++) {
    if (*pcNext=='.')
      iCount++;
  }
  if (iCount != 3)
    return FALSE;
  dwAddress = inet_addr(pszAddress);
  if (dwAddress == INADDR_NONE)
    return FALSE;
  *pdwAddress = dwAddress;
  return TRUE;
}
