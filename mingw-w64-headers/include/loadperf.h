/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _LOADPERF_H_
#define _LOADPERF_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#define LOADPERF_FUNCTION __declspec(dllimport) DWORD WINAPI

#define LOADPERF_FLAGS_DELETE_MOF_ON_EXIT ((ULONG_PTR) 1)
#define LOADPERF_FLAGS_LOAD_REGISTRY_ONLY ((ULONG_PTR) 2)
#define LOADPERF_FLAGS_CREATE_MOF_ONLY ((ULONG_PTR) 4)
#define LOADPERF_FLAGS_DISPLAY_USER_MSGS ((ULONG_PTR) 8)

  LOADPERF_FUNCTION InstallPerfDllW(LPCWSTR szComputerName,LPCWSTR lpIniFile,ULONG_PTR dwFlags);
  LOADPERF_FUNCTION InstallPerfDllA(LPCSTR szComputerName,LPCSTR lpIniFile,ULONG_PTR dwFlags);
  LOADPERF_FUNCTION LoadPerfCounterTextStringsA(LPSTR lpCommandLine,WINBOOL bQuietModeArg);
  LOADPERF_FUNCTION LoadPerfCounterTextStringsW(LPWSTR lpCommandLine,WINBOOL bQuietModeArg);
  LOADPERF_FUNCTION UnloadPerfCounterTextStringsW(LPWSTR lpCommandLine,WINBOOL bQuietModeArg);
  LOADPERF_FUNCTION UnloadPerfCounterTextStringsA(LPSTR lpCommandLine,WINBOOL bQuietModeArg);
  LOADPERF_FUNCTION UpdatePerfNameFilesA(LPCSTR szNewCtrFilePath,LPCSTR szNewHlpFilePath,LPSTR szLanguageID,ULONG_PTR dwFlags);
  LOADPERF_FUNCTION UpdatePerfNameFilesW(LPCWSTR szNewCtrFilePath,LPCWSTR szNewHlpFilePath,LPWSTR szLanguageID,ULONG_PTR dwFlags);
  LOADPERF_FUNCTION SetServiceAsTrustedA(LPCSTR szReserved,LPCSTR szServiceName);
  LOADPERF_FUNCTION SetServiceAsTrustedW(LPCWSTR szReserved,LPCWSTR szServiceName);
  DWORD BackupPerfRegistryToFileW(LPCWSTR szFileName,LPCWSTR szCommentString);
  DWORD RestorePerfRegistryFromFileW(LPCWSTR szFileName,LPCWSTR szLangId);

#ifdef UNICODE
#define InstallPerfDll InstallPerfDllW
#define LoadPerfCounterTextStrings LoadPerfCounterTextStringsW
#define UnloadPerfCounterTextStrings UnloadPerfCounterTextStringsW
#define UpdatePerfNameFiles UpdatePerfNameFilesW
#define SetServiceAsTrusted SetServiceAsTrustedW
#else
#define InstallPerfDll InstallPerfDllA
#define LoadPerfCounterTextStrings LoadPerfCounterTextStringsA
#define UnloadPerfCounterTextStrings UnloadPerfCounterTextStringsA
#define UpdatePerfNameFiles UpdatePerfNameFilesA
#define SetServiceAsTrusted SetServiceAsTrustedA
#endif

#ifdef __cplusplus
}
#endif
#endif
