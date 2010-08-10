/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_MUILOAD
#define _INC_MUILOAD

/*Fixme: These are static functions as opposed to dllimported*/

WINBOOL WINAPI FreeMUILibrary(
  HMODULE hResModule
);

HINSTANCE WINAPI LoadMUILibrary(
  LPCTSTR pszFullModuleName,
  DWORD dwLangConvention,
  LANGID LangID
);

WINBOOL WINAPI GetUILanguageFallbackList(
  PWSTR pFallbackList,
  ULONG cchFallbackList,
  PULONG pcchFallbackListOut
);
#endif /*_INC_MUILOAD*/
