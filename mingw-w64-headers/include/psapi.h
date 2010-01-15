/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _PSAPI_H_
#define _PSAPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNICODE
#define GetModuleBaseName GetModuleBaseNameW
#define GetModuleFileNameEx GetModuleFileNameExW
#define GetMappedFileName GetMappedFileNameW
#define GetDeviceDriverBaseName GetDeviceDriverBaseNameW
#define GetDeviceDriverFileName GetDeviceDriverFileNameW
#define PENUM_PAGE_FILE_CALLBACK PENUM_PAGE_FILE_CALLBACKW
#define EnumPageFiles EnumPageFilesW
#define GetProcessImageFileName GetProcessImageFileNameW
#else
#define GetModuleBaseName GetModuleBaseNameA
#define GetModuleFileNameEx GetModuleFileNameExA
#define GetMappedFileName GetMappedFileNameA
#define GetDeviceDriverBaseName GetDeviceDriverBaseNameA
#define GetDeviceDriverFileName GetDeviceDriverFileNameA
#define PENUM_PAGE_FILE_CALLBACK PENUM_PAGE_FILE_CALLBACKA
#define EnumPageFiles EnumPageFilesA
#define GetProcessImageFileName GetProcessImageFileNameA
#endif

  WINBOOL WINAPI EnumProcesses(DWORD *lpidProcess,DWORD cb,DWORD *cbNeeded);
  WINBOOL WINAPI EnumProcessModules(HANDLE hProcess,HMODULE *lphModule,DWORD cb,LPDWORD lpcbNeeded);
  DWORD WINAPI GetModuleBaseNameA(HANDLE hProcess,HMODULE hModule,LPSTR lpBaseName,DWORD nSize);
  DWORD WINAPI GetModuleBaseNameW(HANDLE hProcess,HMODULE hModule,LPWSTR lpBaseName,DWORD nSize);
  DWORD WINAPI GetModuleFileNameExA(HANDLE hProcess,HMODULE hModule,LPSTR lpFilename,DWORD nSize);
  DWORD WINAPI GetModuleFileNameExW(HANDLE hProcess,HMODULE hModule,LPWSTR lpFilename,DWORD nSize);

  typedef struct _MODULEINFO {
    LPVOID lpBaseOfDll;
    DWORD SizeOfImage;
    LPVOID EntryPoint;
  } MODULEINFO,*LPMODULEINFO;

  WINBOOL WINAPI GetModuleInformation(HANDLE hProcess,HMODULE hModule,LPMODULEINFO lpmodinfo,DWORD cb);
  WINBOOL WINAPI EmptyWorkingSet(HANDLE hProcess);
  WINBOOL WINAPI QueryWorkingSet(HANDLE hProcess,PVOID pv,DWORD cb);
  WINBOOL WINAPI QueryWorkingSetEx(HANDLE hProcess,PVOID pv,DWORD cb);
  WINBOOL WINAPI InitializeProcessForWsWatch(HANDLE hProcess);

  typedef struct _PSAPI_WS_WATCH_INFORMATION {
    LPVOID FaultingPc;
    LPVOID FaultingVa;
  } PSAPI_WS_WATCH_INFORMATION,*PPSAPI_WS_WATCH_INFORMATION;

  WINBOOL WINAPI GetWsChanges(HANDLE hProcess,PPSAPI_WS_WATCH_INFORMATION lpWatchInfo,DWORD cb);
  DWORD WINAPI GetMappedFileNameW(HANDLE hProcess,LPVOID lpv,LPWSTR lpFilename,DWORD nSize);
  DWORD WINAPI GetMappedFileNameA(HANDLE hProcess,LPVOID lpv,LPSTR lpFilename,DWORD nSize);
  WINBOOL WINAPI EnumDeviceDrivers(LPVOID *lpImageBase,DWORD cb,LPDWORD lpcbNeeded);
  DWORD WINAPI GetDeviceDriverBaseNameA(LPVOID ImageBase,LPSTR lpBaseName,DWORD nSize);
  DWORD WINAPI GetDeviceDriverBaseNameW(LPVOID ImageBase,LPWSTR lpBaseName,DWORD nSize);
  DWORD WINAPI GetDeviceDriverFileNameA(LPVOID ImageBase,LPSTR lpFilename,DWORD nSize);
  DWORD WINAPI GetDeviceDriverFileNameW(LPVOID ImageBase,LPWSTR lpFilename,DWORD nSize);

  typedef struct _PROCESS_MEMORY_COUNTERS {
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
  } PROCESS_MEMORY_COUNTERS;
  typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS;

  typedef struct _PROCESS_MEMORY_COUNTERS_EX {
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivateUsage;
  } PROCESS_MEMORY_COUNTERS_EX;
  typedef PROCESS_MEMORY_COUNTERS_EX *PPROCESS_MEMORY_COUNTERS_EX;

  WINBOOL WINAPI GetProcessMemoryInfo(HANDLE Process,PPROCESS_MEMORY_COUNTERS ppsmemCounters,DWORD cb);

  typedef struct _PERFORMANCE_INFORMATION {
    DWORD cb;
    SIZE_T CommitTotal;
    SIZE_T CommitLimit;
    SIZE_T CommitPeak;
    SIZE_T PhysicalTotal;
    SIZE_T PhysicalAvailable;
    SIZE_T SystemCache;
    SIZE_T KernelTotal;
    SIZE_T KernelPaged;
    SIZE_T KernelNonpaged;
    SIZE_T PageSize;
    DWORD HandleCount;
    DWORD ProcessCount;
    DWORD ThreadCount;
  } PERFORMANCE_INFORMATION,*PPERFORMANCE_INFORMATION,PERFORMACE_INFORMATION,*PPERFORMACE_INFORMATION;

  WINBOOL WINAPI GetPerformanceInfo (PPERFORMACE_INFORMATION pPerformanceInformation,DWORD cb);

  typedef struct _ENUM_PAGE_FILE_INFORMATION {
    DWORD cb;
    DWORD Reserved;
    SIZE_T TotalSize;
    SIZE_T TotalInUse;
    SIZE_T PeakUsage;
  } ENUM_PAGE_FILE_INFORMATION,*PENUM_PAGE_FILE_INFORMATION;

  typedef WINBOOL (*PENUM_PAGE_FILE_CALLBACKW) (LPVOID pContext,PENUM_PAGE_FILE_INFORMATION pPageFileInfo,LPCWSTR lpFilename);
  typedef WINBOOL (*PENUM_PAGE_FILE_CALLBACKA) (LPVOID pContext,PENUM_PAGE_FILE_INFORMATION pPageFileInfo,LPCSTR lpFilename);

  WINBOOL WINAPI EnumPageFilesW (PENUM_PAGE_FILE_CALLBACKW pCallBackRoutine,LPVOID pContext);
  WINBOOL WINAPI EnumPageFilesA (PENUM_PAGE_FILE_CALLBACKA pCallBackRoutine,LPVOID pContext);
  DWORD WINAPI GetProcessImageFileNameA(HANDLE hProcess,LPSTR lpImageFileName,DWORD nSize);
  DWORD WINAPI GetProcessImageFileNameW(HANDLE hProcess,LPWSTR lpImageFileName,DWORD nSize);

#ifdef __cplusplus
}
#endif
#endif
