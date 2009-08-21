#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

void WINAPI WspiapiLegacyFreeAddrInfo (struct addrinfo *ptHead)
{
  struct addrinfo *ptNext;
  for (ptNext = ptHead; ptNext != NULL; ptNext = ptHead) {
    if (ptNext->ai_canonname)
      WspiapiFree(ptNext->ai_canonname);
    if (ptNext->ai_addr)
      WspiapiFree(ptNext->ai_addr);
    ptHead = ptNext->ai_next;
    WspiapiFree(ptNext);
  }
}
