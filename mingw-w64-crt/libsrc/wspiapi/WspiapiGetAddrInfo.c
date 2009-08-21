#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI WspiapiGetAddrInfo(const char *nodename,
			      const char *servname,
			      const struct addrinfo *hints,
			      struct addrinfo **res)
{
  int iError;
  static WSPIAPI_PGETADDRINFO pfGetAddrInfo = NULL;
  if (!pfGetAddrInfo)
    pfGetAddrInfo = (WSPIAPI_PGETADDRINFO) WspiapiLoad(0);
  iError = (*pfGetAddrInfo)(nodename, servname, hints, res);
  WSASetLastError(iError);
  return iError;
}
