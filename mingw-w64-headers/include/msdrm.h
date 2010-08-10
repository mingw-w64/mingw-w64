/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NDHELPER
#define _INC_NDHELPER
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef LPVOID DRMHSESSION;

HRESULT WINAPI DRMCreateClientSession(
  DRMCALLBACK pfnCallback,
  UINT uCallbackVersion,
  PWSTR wszGroupIDProviderType,
  PWSTR wszGroupID,
  DRMHSESSION *phClient
);

HRESULT WINAPI DRMAcquireIssuanceLicenseTemplate(
  DRMHSESSION hClient,
  UINT uFlags,
  VOID *pvReserved,
  UINT cReserved,
  PWSTR *pwszReserved,
  PWSTR wszURL,
  VOID *pvContext
);

HRESULT DRMIsWindowProtected(
  HWND hwnd,
  WINBOOL *pfProtected
);

HRESULT DRMRegisterProtectedWindow(
  DRMENVHANDLE hEnv,
  HWND hwnd
);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /*_INC_NDHELPER*/
