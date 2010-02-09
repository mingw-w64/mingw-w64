/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __WPTYPES_H__
#define __WPTYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct tagWPSITEINFOA {
    DWORD dwSize;
    DWORD dwFlags;
    LPSTR lpszSiteName;
    LPSTR lpszSiteURL;
  } WPSITEINFOA,*LPWPSITEINFOA;

  typedef struct tagWPSITEINFOW {
    DWORD dwSize;
    DWORD dwFlags;
    LPWSTR lpszSiteName;
    LPWSTR lpszSiteURL;
  } WPSITEINFOW,*LPWPSITEINFOW;

  typedef struct tagWPPROVINFOA {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwPriority;
    LPSTR lpszProviderName;
    LPSTR lpszProviderCLSID;
    LPSTR lpszDllPath;
  } WPPROVINFOA,*LPWPPROVINFOA;

  typedef struct tagWPPROVINFOW {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwPriority;
    LPWSTR lpszProviderName;
    LPWSTR lpszProviderCLSID;
    LPWSTR lpszDllPath;
  } WPPROVINFOW,*LPWPPROVINFOW;

#ifdef UNICODE
#define WPSITEINFO WPSITEINFOW
#define LPWPSITEINFO LPWPSITEINFOW
#define WPPROVINFO WPPROVINFOW
#define LPWPPROVINFO LPWPPROVINFOW
#else
#define WPSITEINFO WPSITEINFOA
#define LPWPSITEINFO LPWPSITEINFOA
#define WPPROVINFO WPPROVINFOA
#define LPWPPROVINFO LPWPPROVINFOA
#endif

#ifdef __cplusplus
}
#endif
#endif
