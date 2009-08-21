#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef  __CRT__NO_INLINE
#define __CRT__NO_INLINE
#include <wspiapi.h>

int WINAPI
WspiapiGetNameInfo (const struct sockaddr *sa, socklen_t salen,
		    char *host, size_t hostlen,
		    char *serv, size_t servlen, int flags)
{
  int iError;
  static WSPIAPI_PGETNAMEINFO pfGetNameInfo = NULL;
  if (!pfGetNameInfo)
    pfGetNameInfo = (WSPIAPI_PGETNAMEINFO) WspiapiLoad(1);
  iError = (*pfGetNameInfo)(sa, salen, host, hostlen, serv, servlen, flags);
  WSASetLastError(iError);
  return iError;
}
