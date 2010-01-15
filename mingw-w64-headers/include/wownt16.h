/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WOWNT16_
#define _WOWNT16_

#ifdef __cplusplus
extern "C" {
#endif

  DWORD WINAPI GetVDMPointer32W(LPVOID vp,UINT fMode);
  DWORD WINAPI LoadLibraryEx32W(LPCSTR lpszLibFile,DWORD hFile,DWORD dwFlags);
  DWORD WINAPI GetProcAddress32W(DWORD hModule,LPCSTR lpszProc);
  DWORD WINAPI FreeLibrary32W(DWORD hLibModule);
  DWORD CDECL CallProcEx32W(DWORD,DWORD,DWORD,...);

#define CPEX_DEST_STDCALL 0x00000000L
#define CPEX_DEST_CDECL 0x80000000L

#ifdef __cplusplus
}
#endif
#endif
