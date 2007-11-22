/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ERRORREP_H__
#define __ERRORREP_H__

typedef enum tagEFaultRepRetVal {
  frrvOk = 0,frrvOkManifest,frrvOkQueued,frrvErr,frrvErrNoDW,frrvErrTimeout,frrvLaunchDebugger,frrvOkHeadless
} EFaultRepRetVal;

EFaultRepRetVal WINAPI ReportFault(LPEXCEPTION_POINTERS pep,DWORD dwOpt);
WINBOOL WINAPI AddERExcludedApplicationA(LPCSTR szApplication);
WINBOOL WINAPI AddERExcludedApplicationW(LPCWSTR wszApplication);

typedef EFaultRepRetVal (WINAPI *pfn_REPORTFAULT)(LPEXCEPTION_POINTERS,DWORD);
typedef EFaultRepRetVal (WINAPI *pfn_ADDEREXCLUDEDAPPLICATIONA)(LPCSTR);
typedef EFaultRepRetVal (WINAPI *pfn_ADDEREXCLUDEDAPPLICATIONW)(LPCWSTR);

#ifdef UNICODE
#define AddERExcludedApplication AddERExcludedApplicationW
#define pfn_ADDEREXCLUDEDAPPLICATION pfn_ADDEREXCLUDEDAPPLICATIONW
#else
#define AddERExcludedApplication AddERExcludedApplicationA
#define pfn_ADDEREXCLUDEDAPPLICATION pfn_ADDEREXCLUDEDAPPLICATIONA
#endif
#endif
