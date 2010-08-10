/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_DSSEC
#define _INC_DSSEC
#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus
extern "C" {
#endif

typedef HRESULT (WINAPI *PFNREADOBJECTSECURITY)(
    LPCWSTR,               // Active Directory path of object
    SECURITY_INFORMATION,  // the security information to read
    PSECURITY_DESCRIPTOR*, // the returned security descriptor 
    LPARAM                 // context parameter
);

typedef HRESULT (WINAPI *PFNWRITEOBJECTSECURITY)(
    LPCWSTR,              // Active Directory path of object
    SECURITY_INFORMATION, // the security information to write
    PSECURITY_DESCRIPTOR, // the security descriptor to write
    LPARAM                // context parameter
);

HRESULT WINAPI DSCreateISecurityInfoObject(
  LPCWSTR pwszObjectPath,
  LPCWSTR pwszObjectClass,
  DWORD dwFlags,
  LPSECURITYINFO *ppSI,
  PFNREADOBJECTSECURITY pfnReadSD,
  PFNWRITEOBJECTSECURITY pfnWriteSD,
  LPARAM lpContext
);

HRESULT WINAPI DSCreateISecurityInfoObjectEx(
  LPCWSTR pwszObjectPath,
  LPCWSTR pwszObjectClass,
  LPCWSTR pwszServer,
  LPCWSTR pwszUserName,
  LPCWSTR pwszPassword,
  DWORD dwFlags,
  LPSECURITYINFO *ppSI,
  PFNREADOBJECTSECURITY pfnReadSD,
  PFNWRITEOBJECTSECURITY pfnWriteSD,
  LPARAM lpContext
);

HRESULT WINAPI DSEditSecurity(
  HWND hwndOwner,
  LPCWSTR pwszObjectPath,
  LPCWSTR pwszObjectClass,
  DWORD dwFlags,
  LPCWSTR *pwszCaption,
  PFNREADOBJECTSECURITY pfnReadSD,
  PFNWRITEOBJECTSECURITY pfnWriteSD,
  LPARAM lpContext
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_DSSEC*/
