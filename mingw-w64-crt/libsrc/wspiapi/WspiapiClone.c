#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiClone (WORD wPort, struct addrinfo *ptResult)
{
  struct addrinfo *ptNext = NULL;
  struct addrinfo *ptNew = NULL;
  for(ptNext = ptResult; ptNext != NULL; ) {
    ptNew = WspiapiNewAddrInfo(SOCK_DGRAM, ptNext->ai_protocol, wPort,
		((struct sockaddr_in *) ptNext->ai_addr)->sin_addr.s_addr);
    if (!ptNew)
      break;
    ptNew->ai_next = ptNext->ai_next;
    ptNext->ai_next = ptNew;
    ptNext = ptNew->ai_next;
  }
  if (ptNext != NULL)
    return EAI_MEMORY;
  return 0;
}
