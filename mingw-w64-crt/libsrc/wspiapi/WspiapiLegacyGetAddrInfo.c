#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
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
  int err = 0, iFlags = 0, iFamily = PF_UNSPEC, iSocketType = 0, iProtocol = 0;
  DWORD dwAddress = 0;
  struct servent *svc = NULL;
  char *pc = NULL;
  WINBOOL isCloned = FALSE;
  WORD tcpPort = 0, udpPort = 0, port = 0;

  *pptResult = NULL;
  if (!pszNodeName && !pszServiceName)
    return EAI_NONAME;
  if (ptHints)
    {
	if (ptHints->ai_addrlen != 0 || ptHints->ai_canonname != NULL
	    || ptHints->ai_addr!=NULL || ptHints->ai_next != NULL)
	  return EAI_FAIL;
	iFlags = ptHints->ai_flags;
	if ((iFlags & AI_CANONNAME) != 0 && !pszNodeName)
	  return EAI_BADFLAGS;
	iFamily = ptHints->ai_family;
	if (iFamily != PF_UNSPEC && iFamily != PF_INET)
	  return EAI_FAMILY;
	iSocketType = ptHints->ai_socktype;
	if (iSocketType != 0 && iSocketType != SOCK_STREAM && iSocketType != SOCK_DGRAM
	    && iSocketType != SOCK_RAW)
	  return EAI_SOCKTYPE;
	iProtocol = ptHints->ai_protocol;
    }

  if (pszServiceName)
    {
	port = (WORD) strtoul (pszServiceName, &pc, 10);
	if(*pc == 0)
	  {
	    port = tcpPort = udpPort = htons (port);
	    if (iSocketType == 0)
	      {
		isCloned = TRUE;
		iSocketType = SOCK_STREAM;
	      }
	  }
	else
	  {
	    if (iSocketType == 0 || iSocketType == SOCK_DGRAM)
	      {
		svc = getservbyname(pszServiceName, "udp");
		if (svc)
		  port = udpPort = svc->s_port;
	      }
	    if (iSocketType == 0 || iSocketType == SOCK_STREAM)
	      {
		svc = getservbyname(pszServiceName, "tcp");
		if (svc)
		  port = tcpPort = svc->s_port;
	      }
	    if (port == 0)
	      return (iSocketType ? EAI_SERVICE : EAI_NONAME);
	    if (iSocketType==0)
	      {
		iSocketType = (tcpPort) ? SOCK_STREAM : SOCK_DGRAM;
		isCloned = (tcpPort && udpPort);
	      }
	  }
    }
  if (!pszNodeName || WspiapiParseV4Address(pszNodeName,&dwAddress))
    {
	if (!pszNodeName)
	  {
	    dwAddress = htonl ((iFlags & AI_PASSIVE) ? INADDR_ANY : INADDR_LOOPBACK);
	  }
      *pptResult = WspiapiNewAddrInfo(iSocketType, iProtocol, port, dwAddress);
      if (!(*pptResult))
	  err = EAI_MEMORY;
	if (!err && pszNodeName)
	  {
	    (*pptResult)->ai_flags |= AI_NUMERICHOST;
	    if (iFlags & AI_CANONNAME)
	      {
		(*pptResult)->ai_canonname =
		  WspiapiStrdup (inet_ntoa (*((struct in_addr *) &dwAddress)));
		if (!(*pptResult)->ai_canonname)
		  err = EAI_MEMORY;
	      }
	  }
    }
  else if (iFlags & AI_NUMERICHOST)
    err = EAI_NONAME;
  else
    err = WspiapiLookupNode (pszNodeName, iSocketType, iProtocol, port,
			       (iFlags & AI_CANONNAME), pptResult);
  if (!err && isCloned)
    err = WspiapiClone(udpPort, *pptResult);
  if (err)
    {
	WspiapiLegacyFreeAddrInfo (*pptResult);
	*pptResult = NULL;
    }
  return err;
}
