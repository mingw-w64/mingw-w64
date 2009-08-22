#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

struct addrinfo * WINAPI
WspiapiNewAddrInfo (int iSocketType, int iProtocol, WORD wPort, DWORD dwAddress)
{
  struct addrinfo *ptNew;
  struct sockaddr_in *ptAddress;
  ptNew = (struct addrinfo *) WspiapiMalloc(sizeof(struct addrinfo));
  if (!ptNew)
    return NULL;
  ptAddress = (struct sockaddr_in *) WspiapiMalloc(sizeof(struct sockaddr_in));
  if(!ptAddress) {
    WspiapiFree(ptNew);
    return NULL;
  }
  ptAddress->sin_family = AF_INET;
  ptAddress->sin_port = wPort;
  ptAddress->sin_addr.s_addr = dwAddress;
  ptNew->ai_family = PF_INET;
  ptNew->ai_socktype = iSocketType;
  ptNew->ai_protocol = iProtocol;
  ptNew->ai_addrlen = sizeof(struct sockaddr_in);
  ptNew->ai_addr = (struct sockaddr *) ptAddress;
  return ptNew;
}
