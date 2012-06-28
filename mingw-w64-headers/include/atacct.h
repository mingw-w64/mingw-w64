/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_ATACCT
#define _INC_ATACCT

HRESULT GetNetScheduleAccountInformation(
  LPCWSTR pwszServerName,
  DWORD ccAccount,
  WCHAR wszAccount[]
);

HRESULT SetNetScheduleAccountInformation(
  LPCWSTR pwszServerName,
  LPCWSTR pwszAccount,
  LPCWSTR pwszPassword
);

#endif /*_INC_ATACCT*/
