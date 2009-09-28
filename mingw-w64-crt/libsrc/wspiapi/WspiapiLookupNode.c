#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiLookupNode(const char *pszNodeName,
		  int iSocketType, int iProtocol,
		  WORD wPort, WINBOOL bAI_CANONNAME,
		  struct addrinfo **pptResult)
{
  int iError = 0;
  int iAliasCount = 0;
  char szFQDN1[NI_MAXHOST] = "";
  char szFQDN2[NI_MAXHOST] = "";
  char *pszName = szFQDN1;
  char *pszAlias = szFQDN2;
  char *pszScratch = NULL;
  _WSPIAPI_STRNCPY_S(pszName,NI_MAXHOST,pszNodeName,NI_MAXHOST - 1);
  for(;;) {
    iError = WspiapiQueryDNS(pszNodeName, iSocketType, iProtocol,
			     wPort, pszAlias, pptResult);
    if (iError)
      break;
    if (*pptResult)
      break;
    if ((!strlen(pszAlias)) || (!strcmp(pszName,pszAlias)) ||
	(++iAliasCount == 16)) {
      iError = EAI_FAIL;
      break;
    }
    WspiapiSwap(pszName,pszAlias,pszScratch);
  }
  if (!iError && bAI_CANONNAME) {
    (*pptResult)->ai_canonname = WspiapiStrdup(pszAlias);
    if (!(*pptResult)->ai_canonname)
      iError = EAI_MEMORY;
  }
  return iError;
}
