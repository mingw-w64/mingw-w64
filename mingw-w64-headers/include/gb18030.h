/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __GB18030_H
#define __GB18030_H

#define NLS_CP_CPINFO 0x10000000
#define NLS_CP_MBTOWC 0x40000000
#define NLS_CP_WCTOMB 0x80000000

STDAPI_(DWORD) NlsDllCodePageTranslation(DWORD CodePage,DWORD dwFlags,LPSTR lpMultiByteStr,int cchMultiByte,LPWSTR lpWideCharStr,int cchWideChar,LPCPINFO lpCPInfo);
STDAPI_(DWORD) BytesToUnicode(BYTE *lpMultiByteStr,UINT cchMultiByte,UINT *pcchLeftOverBytes,LPWSTR lpWideCharStr,UINT cchWideChar);
ÜSTDAPI_(DWORD) UnicodeToBytes(LPWSTR lpWideCharStr,UINT cchWideChar,LPSTR lpMultiByteStr,UINT cchMultiByte);

#endif
