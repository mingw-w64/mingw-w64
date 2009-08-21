#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiQueryDNS(const char *pszNodeName,
		int iSocketType, int iProtocol,
		WORD wPort, char pszAlias[NI_MAXHOST],
		struct addrinfo **pptResult)
{
  struct addrinfo **pptNext = pptResult;
  struct hostent *ptHost = NULL;
  char **ppAddresses;
  *pptNext = NULL;
  pszAlias[0] = '\0';
  ptHost = gethostbyname(pszNodeName);
  if (ptHost) {
    if ((ptHost->h_addrtype == AF_INET) &&
	(ptHost->h_length == sizeof(struct in_addr))) {
	for (ppAddresses = ptHost->h_addr_list; *ppAddresses != NULL;
	     ppAddresses++) {
	  *pptNext = WspiapiNewAddrInfo(iSocketType, iProtocol, wPort,
				((struct in_addr *) *ppAddresses)->s_addr);
	  if (!*pptNext)
	    return EAI_MEMORY;
	  pptNext = &((*pptNext)->ai_next);
	}
    }
    _WSPIAPI_STRNCPY_S(pszAlias,NI_MAXHOST,ptHost->h_name,NI_MAXHOST - 1);
    return 0;
  }
  switch(WSAGetLastError()) {
    case WSAHOST_NOT_FOUND:	return EAI_NONAME;
    case WSATRY_AGAIN:		return EAI_AGAIN;
    case WSANO_RECOVERY:	return EAI_FAIL;
    case WSANO_DATA:		return EAI_NODATA;
    default:			return EAI_NONAME;
  }
}
