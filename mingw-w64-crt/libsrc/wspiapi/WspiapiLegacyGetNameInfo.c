#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiLegacyGetNameInfo(const struct sockaddr *ptSocketAddress,
			 socklen_t tSocketLength,
			 char *pszNodeName, size_t tNodeLength,
			 char *pszServiceName, size_t tServiceLength,
			 int iFlags)
{
  struct servent *ptService;
  WORD wPort;
  char szBuffer[] = "65535";
  char *pszService = szBuffer;
  struct hostent *ptHost;
  struct in_addr tAddress;
  char *pszNode = NULL;
  char *pc = NULL;

  if ((!ptSocketAddress) || (tSocketLength < sizeof(struct sockaddr)))
    return EAI_FAIL;
  if (ptSocketAddress->sa_family != (unsigned short)AF_INET)
    return EAI_FAMILY;
  if ((size_t) tSocketLength < sizeof(struct sockaddr_in))
    return EAI_FAIL;
  if (!(pszNodeName && tNodeLength) && !(pszServiceName && tServiceLength))
    return EAI_NONAME;
  if ((iFlags & NI_NUMERICHOST) && (iFlags & NI_NAMEREQD))
    return EAI_BADFLAGS;
  if (pszServiceName && tServiceLength) {
    wPort = ((struct sockaddr_in *) ptSocketAddress)->sin_port;
    if(iFlags & NI_NUMERICSERV) {
      _WSPIAPI_SPRINTF_S_1(szBuffer,_WSPIAPI_COUNTOF(szBuffer),"%u",ntohs(wPort));
    } else {
      ptService = getservbyport(wPort, (iFlags & NI_DGRAM) ? "udp" : NULL);
      if (ptService && ptService->s_name) {
	pszService = ptService->s_name;
      } else {
	_WSPIAPI_SPRINTF_S_1(szBuffer,_WSPIAPI_COUNTOF(szBuffer),"%u",ntohs(wPort));
      }
    }
    if (tServiceLength > strlen(pszService))
      _WSPIAPI_STRCPY_S(pszServiceName,tServiceLength,pszService);
    else
      return EAI_FAIL;
  }
  if (pszNodeName && tNodeLength) {
    tAddress = ((struct sockaddr_in *) ptSocketAddress)->sin_addr;
    if (iFlags & NI_NUMERICHOST) {
      pszNode = inet_ntoa(tAddress);
    } else {
      ptHost = gethostbyaddr((char *) &tAddress, sizeof(struct in_addr), AF_INET);
      if(ptHost && ptHost->h_name) {
	pszNode = ptHost->h_name;
	if ((iFlags & NI_NOFQDN) && ((pc = strchr(pszNode,'.')) != NULL))
	  *pc = '\0';
      } else {
	if (iFlags & NI_NAMEREQD) {
	  switch(WSAGetLastError()) {
	    case WSAHOST_NOT_FOUND:	return EAI_NONAME;
	    case WSATRY_AGAIN:		return EAI_AGAIN;
	    case WSANO_RECOVERY:	return EAI_FAIL;
	    default:			return EAI_NONAME;
	  }
	} else {
	  pszNode = inet_ntoa(tAddress);
	}
      }
    }
    if (tNodeLength > strlen(pszNode))
      _WSPIAPI_STRCPY_S(pszNodeName,tNodeLength,pszNode);
    else
      return EAI_FAIL;
  }
  return 0;
}
