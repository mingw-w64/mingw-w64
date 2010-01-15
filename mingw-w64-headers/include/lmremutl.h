/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _LMREMUTL_
#define _LMREMUTL_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DESC_CHAR_UNICODE
  typedef CHAR DESC_CHAR;
#else
  typedef WCHAR DESC_CHAR;
#endif

  typedef DESC_CHAR *LPDESC;

  NET_API_STATUS WINAPI NetRemoteTOD(LPCWSTR UncServerName,LPBYTE *BufferPtr);
  NET_API_STATUS WINAPI NetRemoteComputerSupports(LPCWSTR UncServerName,DWORD OptionsWanted,LPDWORD OptionsSupported);
  NET_API_STATUS __cdecl RxRemoteApi(DWORD ApiNumber,LPCWSTR UncServerName,LPDESC ParmDescString,LPDESC DataDesc16,LPDESC DataDesc32,LPDESC DataDescSmb,LPDESC AuxDesc16,LPDESC AuxDesc32,LPDESC AuxDescSmb,DWORD Flags,...);

  typedef struct _TIME_OF_DAY_INFO {
    DWORD tod_elapsedt;
    DWORD tod_msecs;
    DWORD tod_hours;
    DWORD tod_mins;
    DWORD tod_secs;
    DWORD tod_hunds;
    LONG tod_timezone;
    DWORD tod_tinterval;
    DWORD tod_day;
    DWORD tod_month;
    DWORD tod_year;
    DWORD tod_weekday;
  } TIME_OF_DAY_INFO,*PTIME_OF_DAY_INFO,*LPTIME_OF_DAY_INFO;

#define SUPPORTS_REMOTE_ADMIN_PROTOCOL 0x00000002L
#define SUPPORTS_RPC 0x00000004L
#define SUPPORTS_SAM_PROTOCOL 0x00000008L
#define SUPPORTS_UNICODE 0x00000010L
#define SUPPORTS_LOCAL 0x00000020L
#define SUPPORTS_ANY 0xFFFFFFFFL

#define NO_PERMISSION_REQUIRED 0x00000001
#define ALLOCATE_RESPONSE 0x00000002
#define USE_SPECIFIC_TRANSPORT 0x80000000

#ifdef __cplusplus
}
#endif
#endif
