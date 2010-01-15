/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __SENSAPI_H__
#define __SENSAPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#define NETWORK_ALIVE_LAN 0x00000001
#define NETWORK_ALIVE_WAN 0x00000002
#define NETWORK_ALIVE_AOL 0x00000004

  typedef struct tagQOCINFO {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwInSpeed;
    DWORD dwOutSpeed;
  } QOCINFO,*LPQOCINFO;

#ifdef UNICODE
#define IsDestinationReachable IsDestinationReachableW
#else
#define IsDestinationReachable IsDestinationReachableA
#endif

  WINBOOL WINAPI IsDestinationReachableA(LPCSTR lpszDestination,LPQOCINFO lpQOCInfo);
  WINBOOL WINAPI IsDestinationReachableW(LPCWSTR lpszDestination,LPQOCINFO lpQOCInfo);
  WINBOOL WINAPI IsNetworkAlive(LPDWORD lpdwFlags);

#ifdef __cplusplus
}
#endif
#endif
