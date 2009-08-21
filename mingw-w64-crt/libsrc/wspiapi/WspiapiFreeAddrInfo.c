#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

void WINAPI
WspiapiFreeAddrInfo (struct addrinfo *ai)
{
  static WSPIAPI_PFREEADDRINFO pfFreeAddrInfo = NULL;
  if (!pfFreeAddrInfo)
    pfFreeAddrInfo = (WSPIAPI_PFREEADDRINFO) WspiapiLoad(2);
  (*pfFreeAddrInfo)(ai);
}
