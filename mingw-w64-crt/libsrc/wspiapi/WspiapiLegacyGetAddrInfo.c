#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiLegacyGetAddrInfo(const char *pszNodeName,
			 const char *pszServiceName,
			 const struct addrinfo *ptHints,
			 struct addrinfo **pptResult)
{
  int iError = 0;
  int iFlags = 0;
  int iFamily = PF_UNSPEC;
  int iSocketType = 0;
  int iProtocol = 0;
  WORD wPort = 0;
  DWORD dwAddress = 0;
  struct servent *ptService = NULL;
  char *pc = NULL;
  WINBOOL bClone = FALSE;
  WORD wTcpPort = 0;
  WORD wUdpPort = 0;
  *pptResult = NULL;
  if ((!pszNodeName) && (!pszServiceName))
    return EAI_NONAME;
  if (ptHints) {
    if ((ptHints->ai_addrlen != 0) || (ptHints->ai_canonname != NULL) ||
        (ptHints->ai_addr != NULL) || (ptHints->ai_next != NULL))
      return EAI_FAIL;
    iFlags = ptHints->ai_flags;
    if ((iFlags & AI_CANONNAME) && !pszNodeName)
      return EAI_BADFLAGS;
    iFamily = ptHints->ai_family;
    if ((iFamily != PF_UNSPEC) && (iFamily != PF_INET))
      return EAI_FAMILY;
    iSocketType = ptHints->ai_socktype;
    if ((iSocketType != 0) && (iSocketType != SOCK_STREAM) &&
        (iSocketType != SOCK_DGRAM) && (iSocketType != SOCK_RAW))
      return EAI_SOCKTYPE;
    iProtocol = ptHints->ai_protocol;
  }
  if (pszServiceName) {
    wPort = (WORD) strtoul(pszServiceName, &pc, 10);
    if (*pc == '\0') {
      wPort = wTcpPort = wUdpPort = htons(wPort);
      if (iSocketType == 0) {
	bClone = TRUE;
	iSocketType = SOCK_STREAM;
      }
    } else {
      if ((iSocketType == 0) || (iSocketType == SOCK_DGRAM)) {
	ptService = getservbyname(pszServiceName, "udp");
	if (ptService)
	  wPort = wUdpPort = ptService->s_port;
      }
      if ((iSocketType == 0) || (iSocketType == SOCK_STREAM)) {
	ptService = getservbyname(pszServiceName, "tcp");
	if (ptService)
	  wPort = wTcpPort = ptService->s_port;
      }
      if (wPort == 0)
        return (iSocketType ? EAI_SERVICE : EAI_NONAME);
      if (iSocketType == 0) {
	iSocketType = (wTcpPort) ? SOCK_STREAM : SOCK_DGRAM;
	bClone = (wTcpPort && wUdpPort);
      }
    }
  }
  if ((!pszNodeName) || (WspiapiParseV4Address(pszNodeName,&dwAddress))) {
    if (!pszNodeName) {
      dwAddress = htonl((iFlags & AI_PASSIVE) ? INADDR_ANY : INADDR_LOOPBACK);
    }
    *pptResult = WspiapiNewAddrInfo(iSocketType, iProtocol, wPort, dwAddress);
    if (!(*pptResult))
      iError = EAI_MEMORY;
    if (!iError && pszNodeName) {
      (*pptResult)->ai_flags |= AI_NUMERICHOST;
      if (iFlags & AI_CANONNAME) {
	(*pptResult)->ai_canonname =
		   WspiapiStrdup(inet_ntoa(*((struct in_addr *) &dwAddress)));
	if (!(*pptResult)->ai_canonname)
	  iError = EAI_MEMORY;
      }
    }
  } else if (iFlags & AI_NUMERICHOST) {
    iError = EAI_NONAME;
  } else {
    iError = WspiapiLookupNode(pszNodeName, iSocketType, iProtocol, wPort,
				(iFlags & AI_CANONNAME), pptResult);
  }
  if (!iError && bClone)
    iError = WspiapiClone(wUdpPort, *pptResult);
  if (iError) {
    WspiapiLegacyFreeAddrInfo(*pptResult);
    *pptResult = NULL;
  }
  return (iError);
}
