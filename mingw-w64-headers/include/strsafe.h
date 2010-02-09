/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _STRSAFE_H_INCLUDED_
#define _STRSAFE_H_INCLUDED_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <specstrings.h>

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
__MINGW_EXTENSION typedef unsigned __int64 size_t;
#else
typedef unsigned int size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
__MINGW_EXTENSION typedef __int64 ssize_t;
#else
typedef int ssize_t;
#endif
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef long HRESULT;
#endif

#ifndef SUCCEEDED
#define SUCCEEDED(hr) ((HRESULT)(hr) >= 0)
#endif

#ifndef FAILED
#define FAILED(hr) ((HRESULT)(hr) < 0)
#endif

#ifndef S_OK
#define S_OK ((HRESULT)0x00000000L)
#endif

#ifndef C_ASSERT
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#endif

#ifdef __cplusplus
#define _STRSAFE_EXTERN_C extern "C"
#else
#define _STRSAFE_EXTERN_C extern
#endif

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#define STRSAFEAPI static __inline HRESULT WINAPI
#define STRSAFE_INLINE_API __CRT_INLINE HRESULT WINAPI

#define STRSAFE_MAX_CCH 2147483647

#ifndef _NTSTRSAFE_H_INCLUDED_
#define STRSAFE_IGNORE_NULLS 0x00000100
#define STRSAFE_FILL_BEHIND_NULL 0x00000200
#define STRSAFE_FILL_ON_FAILURE 0x00000400
#define STRSAFE_NULL_ON_FAILURE 0x00000800
#define STRSAFE_NO_TRUNCATION 0x00001000
#define STRSAFE_IGNORE_NULL_UNICODE_STRINGS 0x00010000
#define STRSAFE_UNICODE_STRING_DEST_NULL_TERMINATED 0x00020000

#define STRSAFE_VALID_FLAGS (0x000000FF | STRSAFE_IGNORE_NULLS | STRSAFE_FILL_BEHIND_NULL | STRSAFE_FILL_ON_FAILURE | STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)
#define STRSAFE_UNICODE_STRING_VALID_FLAGS (STRSAFE_VALID_FLAGS | STRSAFE_IGNORE_NULL_UNICODE_STRINGS | STRSAFE_UNICODE_STRING_DEST_NULL_TERMINATED)

#define STRSAFE_FILL_BYTE(x) ((unsigned long)((x & 0x000000FF) | STRSAFE_FILL_BEHIND_NULL))
#define STRSAFE_FAILURE_BYTE(x) ((unsigned long)((x & 0x000000FF) | STRSAFE_FILL_ON_FAILURE))

#define STRSAFE_GET_FILL_PATTERN(dwFlags) ((int)(dwFlags & 0x000000FF))
#endif

#define STRSAFE_E_INSUFFICIENT_BUFFER ((HRESULT)0x8007007AL)
#define STRSAFE_E_INVALID_PARAMETER ((HRESULT)0x80070057L)
#define STRSAFE_E_END_OF_FILE ((HRESULT)0x80070026L)

typedef char *STRSAFE_LPSTR;
typedef const char *STRSAFE_LPCSTR;
typedef wchar_t *STRSAFE_LPWSTR;
typedef const wchar_t *STRSAFE_LPCWSTR;

STRSAFEAPI StringCopyWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCopyWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc);
STRSAFEAPI StringCopyExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCopyExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCopyNWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy);
STRSAFEAPI StringCopyNWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy);
STRSAFEAPI StringCopyNExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCopyNExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCatWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCatWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc);
STRSAFEAPI StringCatExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCatExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCatNWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend);
STRSAFEAPI StringCatNWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend);
STRSAFEAPI StringCatNExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCatNExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringVPrintfWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringVPrintfWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,va_list argList);
STRSAFEAPI StringVPrintfExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringVPrintfExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList);
STRSAFEAPI StringLengthWorkerA(STRSAFE_LPCSTR psz,size_t cchMax,size_t *pcchLength);
STRSAFEAPI StringLengthWorkerW(STRSAFE_LPCWSTR psz,size_t cchMax,size_t *pcchLength);
STRSAFE_INLINE_API StringGetsExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFE_INLINE_API StringGetsExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);

#ifdef UNICODE
#define StringCchCopy StringCchCopyW
#else
#define StringCchCopy StringCchCopyA
#endif

STRSAFEAPI StringCchCopyA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc);

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCopyA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyWorkerA(pszDest,cchDest,pszSrc);
  return hr;
}

STRSAFEAPI StringCchCopyW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyWorkerW(pszDest,cchDest,pszSrc);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

#ifdef UNICODE
#define StringCbCopy StringCbCopyW
#else
#define StringCbCopy StringCbCopyA
#endif

STRSAFEAPI StringCbCopyA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCbCopyW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc);

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCopyA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyWorkerA(pszDest,cchDest,pszSrc);
  return hr;
}

STRSAFEAPI StringCbCopyW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyWorkerW(pszDest,cchDest,pszSrc);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

#ifdef UNICODE
#define StringCchCopyEx StringCchCopyExW
#else
#define StringCchCopyEx StringCchCopyExA
#endif

STRSAFEAPI StringCchCopyExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCchCopyExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCopyExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringCopyExWorkerA(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}

STRSAFEAPI StringCchCopyExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringCopyExWorkerW(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

#ifdef UNICODE
#define StringCbCopyEx StringCbCopyExW
#else
#define StringCbCopyEx StringCbCopyExA
#endif

STRSAFEAPI StringCbCopyExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
STRSAFEAPI StringCbCopyExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCopyExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyExWorkerA(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbCopyExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyExWorkerW(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCopyNA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy);
STRSAFEAPI StringCchCopyNW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy);
#ifdef UNICODE
#define StringCchCopyN StringCchCopyNW
#else
#define StringCchCopyN StringCchCopyNA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCopyNA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy) {
  HRESULT hr;
  if((cchDest > STRSAFE_MAX_CCH) || (cchToCopy > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNWorkerA(pszDest,cchDest,pszSrc,cchToCopy);
  return hr;
}

STRSAFEAPI StringCchCopyNW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy) {
  HRESULT hr;
  if((cchDest > STRSAFE_MAX_CCH) || (cchToCopy > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNWorkerW(pszDest,cchDest,pszSrc,cchToCopy);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbCopyNA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToCopy);
STRSAFEAPI StringCbCopyNW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToCopy);
#ifdef UNICODE
#define StringCbCopyN StringCbCopyNW
#else
#define StringCbCopyN StringCbCopyNA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCopyNA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToCopy) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToCopy;
  cchDest = cbDest / sizeof(char);
  cchToCopy = cbToCopy / sizeof(char);
  if((cchDest > STRSAFE_MAX_CCH) || (cchToCopy > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNWorkerA(pszDest,cchDest,pszSrc,cchToCopy);
  return hr;
}

STRSAFEAPI StringCbCopyNW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToCopy) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToCopy;
  cchDest = cbDest / sizeof(wchar_t);
  cchToCopy = cbToCopy / sizeof(wchar_t);
  if((cchDest > STRSAFE_MAX_CCH) || (cchToCopy > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNWorkerW(pszDest,cchDest,pszSrc,cchToCopy);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCopyNExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCchCopyNExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCchCopyNEx StringCchCopyNExW
#else
#define StringCchCopyNEx StringCchCopyNExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCopyNExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringCopyNExWorkerA(pszDest,cchDest,cbDest,pszSrc,cchToCopy,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}

STRSAFEAPI StringCchCopyNExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringCopyNExWorkerW(pszDest,cchDest,cbDest,pszSrc,cchToCopy,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbCopyNExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
STRSAFEAPI StringCbCopyNExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCbCopyNEx StringCbCopyNExW
#else
#define StringCbCopyNEx StringCbCopyNExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCopyNExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToCopy;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  cchToCopy = cbToCopy / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNExWorkerA(pszDest,cchDest,cbDest,pszSrc,cchToCopy,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbCopyNExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToCopy;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  cchToCopy = cbToCopy / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCopyNExWorkerW(pszDest,cchDest,cbDest,pszSrc,cchToCopy,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCatA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCchCatW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc);
#ifdef UNICODE
#define StringCchCat StringCchCatW
#else
#define StringCchCat StringCchCatA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCatA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatWorkerA(pszDest,cchDest,pszSrc);
  return hr;
}

STRSAFEAPI StringCchCatW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatWorkerW(pszDest,cchDest,pszSrc);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbCatA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc);
STRSAFEAPI StringCbCatW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc);
#ifdef UNICODE
#define StringCbCat StringCbCatW
#else
#define StringCbCat StringCbCatA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCatA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatWorkerA(pszDest,cchDest,pszSrc);
  return hr;
}

STRSAFEAPI StringCbCatW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatWorkerW(pszDest,cchDest,pszSrc);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCatExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCchCatExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCchCatEx StringCchCatExW
#else
#define StringCchCatEx StringCchCatExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCatExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringCatExWorkerA(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}

STRSAFEAPI StringCchCatExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringCatExWorkerW(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbCatExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
STRSAFEAPI StringCbCatExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCbCatEx StringCbCatExW
#else
#define StringCbCatEx StringCbCatExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCatExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatExWorkerA(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbCatExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatExWorkerW(pszDest,cchDest,cbDest,pszSrc,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCatNA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend);
STRSAFEAPI StringCchCatNW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend);
#ifdef UNICODE
#define StringCchCatN StringCchCatNW
#else
#define StringCchCatN StringCchCatNA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCatNA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNWorkerA(pszDest,cchDest,pszSrc,cchToAppend);
  return hr;
}

STRSAFEAPI StringCchCatNW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNWorkerW(pszDest,cchDest,pszSrc,cchToAppend);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbCatNA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToAppend);
STRSAFEAPI StringCbCatNW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToAppend);
#ifdef UNICODE
#define StringCbCatN StringCbCatNW
#else
#define StringCbCatN StringCbCatNA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCatNA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToAppend) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToAppend;
  cchDest = cbDest / sizeof(char);
  cchToAppend = cbToAppend / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNWorkerA(pszDest,cchDest,pszSrc,cchToAppend);
  return hr;
}

STRSAFEAPI StringCbCatNW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToAppend) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToAppend;
  cchDest = cbDest / sizeof(wchar_t);
  cchToAppend = cbToAppend / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNWorkerW(pszDest,cchDest,pszSrc,cchToAppend);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchCatNExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFEAPI StringCchCatNExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCchCatNEx StringCchCatNExW
#else
#define StringCchCatNEx StringCchCatNExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchCatNExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringCatNExWorkerA(pszDest,cchDest,cbDest,pszSrc,cchToAppend,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}

STRSAFEAPI StringCchCatNExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringCatNExWorkerW(pszDest,cchDest,cbDest,pszSrc,cchToAppend,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}
#endif

STRSAFEAPI StringCbCatNExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
STRSAFEAPI StringCbCatNExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCbCatNEx StringCbCatNExW
#else
#define StringCbCatNEx StringCbCatNExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbCatNExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cbToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToAppend;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  cchToAppend = cbToAppend / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNExWorkerA(pszDest,cchDest,cbDest,pszSrc,cchToAppend,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbCatNExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cbToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchToAppend;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  cchToAppend = cbToAppend / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringCatNExWorkerW(pszDest,cchDest,cbDest,pszSrc,cchToAppend,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchVPrintfA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringCchVPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,va_list argList);
#ifdef UNICODE
#define StringCchVPrintf StringCchVPrintfW
#else
#define StringCchVPrintf StringCchVPrintfA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchVPrintfA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfWorkerA(pszDest,cchDest,pszFormat,argList);
  return hr;
}

STRSAFEAPI StringCchVPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfWorkerW(pszDest,cchDest,pszFormat,argList);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbVPrintfA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringCbVPrintfW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszFormat,va_list argList);
#ifdef UNICODE
#define StringCbVPrintf StringCbVPrintfW
#else
#define StringCbVPrintf StringCbVPrintfA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbVPrintfA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfWorkerA(pszDest,cchDest,pszFormat,argList);
  return hr;
}

STRSAFEAPI StringCbVPrintfW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfWorkerW(pszDest,cchDest,pszFormat,argList);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchPrintfA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,...);
STRSAFEAPI StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...);
#ifdef UNICODE
#define StringCchPrintf StringCchPrintfW
#else
#define StringCchPrintf StringCchPrintfA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchPrintfA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,...) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfWorkerA(pszDest,cchDest,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}

STRSAFEAPI StringCchPrintfW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,...) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfWorkerW(pszDest,cchDest,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbPrintfA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,...);
STRSAFEAPI StringCbPrintfW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszFormat,...);
#ifdef UNICODE
#define StringCbPrintf StringCbPrintfW
#else
#define StringCbPrintf StringCbPrintfA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbPrintfA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,...) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfWorkerA(pszDest,cchDest,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}

STRSAFEAPI StringCbPrintfW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPCWSTR pszFormat,...) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfWorkerW(pszDest,cchDest,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchPrintfExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,...);
STRSAFEAPI StringCchPrintfExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,...);
#ifdef UNICODE
#define StringCchPrintfEx StringCchPrintfExW
#else
#define StringCchPrintfEx StringCchPrintfExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchPrintfExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,...) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    va_list argList;
    cbDest = cchDest*sizeof(char);
    va_start(argList,pszFormat);
    hr = StringVPrintfExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}

STRSAFEAPI StringCchPrintfExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,...) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    va_list argList;
    cbDest = cchDest*sizeof(wchar_t);
    va_start(argList,pszFormat);
    hr = StringVPrintfExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags,pszFormat,argList);
    va_end(argList);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbPrintfExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,...);
STRSAFEAPI StringCbPrintfExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,...);
#ifdef UNICODE
#define StringCbPrintfEx StringCbPrintfExW
#else
#define StringCbPrintfEx StringCbPrintfExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbPrintfExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,...) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags,pszFormat,argList);
    va_end(argList);
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbPrintfExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,...) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    va_list argList;
    va_start(argList,pszFormat);
    hr = StringVPrintfExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags,pszFormat,argList);
    va_end(argList);
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchVPrintfExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringCchVPrintfExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList);
#ifdef UNICODE
#define StringCchVPrintfEx StringCchVPrintfExW
#else
#define StringCchVPrintfEx StringCchVPrintfExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchVPrintfExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringVPrintfExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags,pszFormat,argList);
  }
  return hr;
}

STRSAFEAPI StringCchVPrintfExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringVPrintfExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags,pszFormat,argList);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbVPrintfExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList);
STRSAFEAPI StringCbVPrintfExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList);
#ifdef UNICODE
#define StringCbVPrintfEx StringCbVPrintfExW
#else
#define StringCbVPrintfEx StringCbVPrintfExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbVPrintfExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags,pszFormat,argList);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
    }
  }
  return hr;
}

STRSAFEAPI StringCbVPrintfExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringVPrintfExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags,pszFormat,argList);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(pcbRemaining) {
      *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
    }
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFE_INLINE_API StringCchGetsA(STRSAFE_LPSTR pszDest,size_t cchDest);
STRSAFE_INLINE_API StringCchGetsW(STRSAFE_LPWSTR pszDest,size_t cchDest);
#ifdef UNICODE
#define StringCchGets StringCchGetsW
#else
#define StringCchGets StringCchGetsA
#endif

#ifndef __CRT__NO_INLINE
STRSAFE_INLINE_API StringCchGetsA(STRSAFE_LPSTR pszDest,size_t cchDest) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringGetsExWorkerA(pszDest,cchDest,cbDest,NULL,NULL,0);
  }
  return hr;
}

STRSAFE_INLINE_API StringCchGetsW(STRSAFE_LPWSTR pszDest,size_t cchDest) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringGetsExWorkerW(pszDest,cchDest,cbDest,NULL,NULL,0);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFE_INLINE_API StringCbGetsA(STRSAFE_LPSTR pszDest,size_t cbDest);
STRSAFE_INLINE_API StringCbGetsW(STRSAFE_LPWSTR pszDest,size_t cbDest);
#ifdef UNICODE
#define StringCbGets StringCbGetsW
#else
#define StringCbGets StringCbGetsA
#endif

#ifndef __CRT__NO_INLINE
STRSAFE_INLINE_API StringCbGetsA(STRSAFE_LPSTR pszDest,size_t cbDest) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringGetsExWorkerA(pszDest,cchDest,cbDest,NULL,NULL,0);
  return hr;
}

STRSAFE_INLINE_API StringCbGetsW(STRSAFE_LPWSTR pszDest,size_t cbDest) {
  HRESULT hr;
  size_t cchDest;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringGetsExWorkerW(pszDest,cchDest,cbDest,NULL,NULL,0);
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFE_INLINE_API StringCchGetsExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
STRSAFE_INLINE_API StringCchGetsExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCchGetsEx StringCchGetsExW
#else
#define StringCchGetsEx StringCchGetsExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFE_INLINE_API StringCchGetsExA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(char);
    hr = StringGetsExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}

STRSAFE_INLINE_API StringCchGetsExW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr;
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cbDest;
    cbDest = cchDest*sizeof(wchar_t);
    hr = StringGetsExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,pcchRemaining,dwFlags);
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFE_INLINE_API StringCbGetsExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
STRSAFE_INLINE_API StringCbGetsExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags);
#ifdef UNICODE
#define StringCbGetsEx StringCbGetsExW
#else
#define StringCbGetsEx StringCbGetsExA
#endif

#ifndef __CRT__NO_INLINE
STRSAFE_INLINE_API StringCbGetsExA(STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(char);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringGetsExWorkerA(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER) || (hr==STRSAFE_E_END_OF_FILE)) {
    if(pcbRemaining) *pcbRemaining = (cchRemaining*sizeof(char)) + (cbDest % sizeof(char));
  }
  return hr;
}

STRSAFE_INLINE_API StringCbGetsExW(STRSAFE_LPWSTR pszDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcbRemaining,unsigned long dwFlags) {
  HRESULT hr;
  size_t cchDest;
  size_t cchRemaining = 0;
  cchDest = cbDest / sizeof(wchar_t);
  if(cchDest > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringGetsExWorkerW(pszDest,cchDest,cbDest,ppszDestEnd,&cchRemaining,dwFlags);
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER) || (hr==STRSAFE_E_END_OF_FILE)) {
    if(pcbRemaining) *pcbRemaining = (cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t));
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCchLengthA(STRSAFE_LPCSTR psz,size_t cchMax,size_t *pcchLength);
STRSAFEAPI StringCchLengthW(STRSAFE_LPCWSTR psz,size_t cchMax,size_t *pcchLength);
#ifdef UNICODE
#define StringCchLength StringCchLengthW
#else
#define StringCchLength StringCchLengthA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCchLengthA(STRSAFE_LPCSTR psz,size_t cchMax,size_t *pcchLength) {
  HRESULT hr;
  if(!psz || (cchMax > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringLengthWorkerA(psz,cchMax,pcchLength);
  if(FAILED(hr) && pcchLength) {
    *pcchLength = 0;
  }
  return hr;
}

STRSAFEAPI StringCchLengthW(STRSAFE_LPCWSTR psz,size_t cchMax,size_t *pcchLength) {
  HRESULT hr;
  if(!psz || (cchMax > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringLengthWorkerW(psz,cchMax,pcchLength);
  if(FAILED(hr) && pcchLength) {
    *pcchLength = 0;
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

STRSAFEAPI StringCbLengthA(STRSAFE_LPCSTR psz,size_t cbMax,size_t *pcbLength);
STRSAFEAPI StringCbLengthW(STRSAFE_LPCWSTR psz,size_t cbMax,size_t *pcbLength);
#ifdef UNICODE
#define StringCbLength StringCbLengthW
#else
#define StringCbLength StringCbLengthA
#endif

#ifndef __CRT__NO_INLINE
STRSAFEAPI StringCbLengthA(STRSAFE_LPCSTR psz,size_t cbMax,size_t *pcbLength) {
  HRESULT hr;
  size_t cchMax;
  size_t cchLength = 0;
  cchMax = cbMax / sizeof(char);
  if(!psz || (cchMax > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringLengthWorkerA(psz,cchMax,&cchLength);
  if(pcbLength) {
    if(SUCCEEDED(hr)) {
      *pcbLength = cchLength*sizeof(char);
    } else {
      *pcbLength = 0;
    }
  }
  return hr;
}

STRSAFEAPI StringCbLengthW(STRSAFE_LPCWSTR psz,size_t cbMax,size_t *pcbLength) {
  HRESULT hr;
  size_t cchMax;
  size_t cchLength = 0;
  cchMax = cbMax / sizeof(wchar_t);
  if(!psz || (cchMax > STRSAFE_MAX_CCH)) hr = STRSAFE_E_INVALID_PARAMETER;
  else hr = StringLengthWorkerW(psz,cchMax,&cchLength);
  if(pcbLength) {
    if(SUCCEEDED(hr)) {
      *pcbLength = cchLength*sizeof(wchar_t);
    } else {
      *pcbLength = 0;
    }
  }
  return hr;
}

STRSAFEAPI StringCopyWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    while(cchDest && (*pszSrc!='\0')) {
      *pszDest++ = *pszSrc++;
      cchDest--;
    }
    if(cchDest==0) {
      pszDest--;
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
    *pszDest= '\0';
  }
  return hr;
}

STRSAFEAPI StringCopyWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    while(cchDest && (*pszSrc!=L'\0')) {
      *pszDest++ = *pszSrc++;
      cchDest--;
    }
    if(cchDest==0) {
      pszDest--;
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
    *pszDest= L'\0';
  }
  return hr;
}

STRSAFEAPI StringCopyExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszSrc) pszSrc = "";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if(*pszSrc!='\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining && (*pszSrc!='\0')) {
	  *pszDestEnd++ = *pszSrc++;
	  cchRemaining--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(char)) + (cbDest % sizeof(char)));
	  }
	} else {
	  pszDestEnd--;
	  cchRemaining++;
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
	*pszDestEnd = '\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCopyExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszSrc) pszSrc = L"";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if(*pszSrc!=L'\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining && (*pszSrc!=L'\0')) {
	  *pszDestEnd++ = *pszSrc++;
	  cchRemaining--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)));
	  }
	} else {
	  pszDestEnd--;
	  cchRemaining++;
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
	*pszDestEnd = L'\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCopyNWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchSrc) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    while(cchDest && cchSrc && (*pszSrc!='\0')) {
      *pszDest++ = *pszSrc++;
      cchDest--;
      cchSrc--;
    }
    if(cchDest==0) {
      pszDest--;
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
    *pszDest= '\0';
  }
  return hr;
}

STRSAFEAPI StringCopyNWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    while(cchDest && cchToCopy && (*pszSrc!=L'\0')) {
      *pszDest++ = *pszSrc++;
      cchDest--;
      cchToCopy--;
    }
    if(cchDest==0) {
      pszDest--;
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    }
    *pszDest= L'\0';
  }
  return hr;
}

STRSAFEAPI StringCopyNExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cchToCopy,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else if(cchToCopy > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszSrc) pszSrc = "";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if((cchToCopy!=0) && (*pszSrc!='\0')) {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining && cchToCopy && (*pszSrc!='\0')) {
	  *pszDestEnd++ = *pszSrc++;
	  cchRemaining--;
	  cchToCopy--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(char)) + (cbDest % sizeof(char)));
	  }
	} else {
	  pszDestEnd--;
	  cchRemaining++;
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
	*pszDestEnd = '\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCopyNExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cchToCopy,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else if(cchToCopy > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszSrc) pszSrc = L"";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if((cchToCopy!=0) && (*pszSrc!=L'\0')) {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining && cchToCopy && (*pszSrc!=L'\0')) {
	  *pszDestEnd++ = *pszSrc++;
	  cchRemaining--;
	  cchToCopy--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)));
	  }
	} else {
	  pszDestEnd--;
	  cchRemaining++;
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
	*pszDestEnd = L'\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCatWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc) {
  HRESULT hr;
  size_t cchDestLength;
  hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
  if(SUCCEEDED(hr)) hr = StringCopyWorkerA(pszDest + cchDestLength,cchDest - cchDestLength,pszSrc);
  return hr;
}

STRSAFEAPI StringCatWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc) {
  HRESULT hr;
  size_t cchDestLength;
  hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
  if(SUCCEEDED(hr)) hr = StringCopyWorkerW(pszDest + cchDestLength,cchDest - cchDestLength,pszSrc);
  return hr;
}

STRSAFEAPI StringCatExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cchDestLength;
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest==0) && (cbDest==0)) cchDestLength = 0;
	else hr = STRSAFE_E_INVALID_PARAMETER;
      } else {
	hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
	if(SUCCEEDED(hr)) {
	  pszDestEnd = pszDest + cchDestLength;
	  cchRemaining = cchDest - cchDestLength;
	}
      }
      if(!pszSrc) pszSrc = "";
    } else {
      hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
      if(SUCCEEDED(hr)) {
	pszDestEnd = pszDest + cchDestLength;
	cchRemaining = cchDest - cchDestLength;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	if(*pszSrc!='\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else hr = StringCopyExWorkerA(pszDestEnd,cchRemaining,(cchRemaining*sizeof(char)) + (cbDest % sizeof(char)),pszSrc,&pszDestEnd,&cchRemaining,dwFlags & (~(STRSAFE_FILL_ON_FAILURE | STRSAFE_NULL_ON_FAILURE)));
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & STRSAFE_NULL_ON_FAILURE) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCatExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    size_t cchDestLength;
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest==0) && (cbDest==0)) cchDestLength = 0;
	else hr = STRSAFE_E_INVALID_PARAMETER;
      } else {
	hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
	if(SUCCEEDED(hr)) {
	  pszDestEnd = pszDest + cchDestLength;
	  cchRemaining = cchDest - cchDestLength;
	}
      }
      if(!pszSrc) pszSrc = L"";
    } else {
      hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
      if(SUCCEEDED(hr)) {
	pszDestEnd = pszDest + cchDestLength;
	cchRemaining = cchDest - cchDestLength;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	if(*pszSrc!=L'\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else hr = StringCopyExWorkerW(pszDestEnd,cchRemaining,(cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)),pszSrc,&pszDestEnd,&cchRemaining,dwFlags & (~(STRSAFE_FILL_ON_FAILURE | STRSAFE_NULL_ON_FAILURE)));
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & STRSAFE_NULL_ON_FAILURE) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCatNWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend) {
  HRESULT hr;
  size_t cchDestLength;
  hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
  if(SUCCEEDED(hr)) hr = StringCopyNWorkerA(pszDest + cchDestLength,cchDest - cchDestLength,pszSrc,cchToAppend);
  return hr;
}

STRSAFEAPI StringCatNWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend) {
  HRESULT hr;
  size_t cchDestLength;
  hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
  if(SUCCEEDED(hr)) hr = StringCopyNWorkerW(pszDest + cchDestLength,cchDest - cchDestLength,pszSrc,cchToAppend);
  return hr;
}

STRSAFEAPI StringCatNExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCSTR pszSrc,size_t cchToAppend,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  size_t cchDestLength = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else if(cchToAppend > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest==0) && (cbDest==0)) cchDestLength = 0;
	else hr = STRSAFE_E_INVALID_PARAMETER;
      } else {
	hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
	if(SUCCEEDED(hr)) {
	  pszDestEnd = pszDest + cchDestLength;
	  cchRemaining = cchDest - cchDestLength;
	}
      }
      if(!pszSrc) pszSrc = "";
    } else {
      hr = StringLengthWorkerA(pszDest,cchDest,&cchDestLength);
      if(SUCCEEDED(hr)) {
	pszDestEnd = pszDest + cchDestLength;
	cchRemaining = cchDest - cchDestLength;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	if((cchToAppend!=0) && (*pszSrc!='\0')) {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else hr = StringCopyNExWorkerA(pszDestEnd,cchRemaining,(cchRemaining*sizeof(char)) + (cbDest % sizeof(char)),pszSrc,cchToAppend,&pszDestEnd,&cchRemaining,dwFlags & (~(STRSAFE_FILL_ON_FAILURE | STRSAFE_NULL_ON_FAILURE)));
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringCatNExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPCWSTR pszSrc,size_t cchToAppend,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  size_t cchDestLength = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else if(cchToAppend > STRSAFE_MAX_CCH) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest==0) && (cbDest==0)) cchDestLength = 0;
	else hr = STRSAFE_E_INVALID_PARAMETER;
      } else {
	hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
	if(SUCCEEDED(hr)) {
	  pszDestEnd = pszDest + cchDestLength;
	  cchRemaining = cchDest - cchDestLength;
	}
      }
      if(!pszSrc) pszSrc = L"";
    } else {
      hr = StringLengthWorkerW(pszDest,cchDest,&cchDestLength);
      if(SUCCEEDED(hr)) {
	pszDestEnd = pszDest + cchDestLength;
	cchRemaining = cchDest - cchDestLength;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	if((cchToAppend!=0) && (*pszSrc!=L'\0')) {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else hr = StringCopyNExWorkerW(pszDestEnd,cchRemaining,(cchRemaining*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)),pszSrc,cchToAppend,&pszDestEnd,&cchRemaining,dwFlags & (~(STRSAFE_FILL_ON_FAILURE | STRSAFE_NULL_ON_FAILURE)));
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringVPrintfWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    int iRet;
    size_t cchMax;
    cchMax = cchDest - 1;
    iRet = _vsnprintf(pszDest,cchMax,pszFormat,argList);
    if((iRet < 0) || (((size_t)iRet) > cchMax)) {
      pszDest += cchMax;
      *pszDest = '\0';
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    } else if(((size_t)iRet)==cchMax) {
      pszDest += cchMax;
      *pszDest = '\0';
    }
  }
  return hr;
}

STRSAFEAPI StringVPrintfWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr = S_OK;
  if(cchDest==0) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    int iRet;
    size_t cchMax;
    cchMax = cchDest - 1;
    iRet = _vsnwprintf(pszDest,cchMax,pszFormat,argList);
    if((iRet < 0) || (((size_t)iRet) > cchMax)) {
      pszDest += cchMax;
      *pszDest = L'\0';
      hr = STRSAFE_E_INSUFFICIENT_BUFFER;
    } else if(((size_t)iRet)==cchMax) {
      pszDest += cchMax;
      *pszDest = L'\0';
    }
  }
  return hr;
}

STRSAFEAPI StringVPrintfExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCSTR pszFormat,va_list argList) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszFormat) pszFormat = "";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if(*pszFormat!='\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	int iRet;
	size_t cchMax;
	cchMax = cchDest - 1;
	iRet = _vsnprintf(pszDest,cchMax,pszFormat,argList);
	if((iRet < 0) || (((size_t)iRet) > cchMax)) {
	  pszDestEnd = pszDest + cchMax;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	} else if(((size_t)iRet)==cchMax) {
	  pszDestEnd = pszDest + cchMax;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	} else if(((size_t)iRet) < cchMax) {
	  pszDestEnd = pszDest + iRet;
	  cchRemaining = cchDest - iRet;
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(char)) + (cbDest % sizeof(char)));
	  }
	}
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringVPrintfExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags,STRSAFE_LPCWSTR pszFormat,va_list argList) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
      if(!pszFormat) pszFormat = L"";
    }
    if(SUCCEEDED(hr)) {
      if(cchDest==0) {
	pszDestEnd = pszDest;
	cchRemaining = 0;
	if(*pszFormat!=L'\0') {
	  if(!pszDest) hr = STRSAFE_E_INVALID_PARAMETER;
	  else hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	}
      } else {
	int iRet;
	size_t cchMax;
	cchMax = cchDest - 1;
	iRet = _vsnwprintf(pszDest,cchMax,pszFormat,argList);
	if((iRet < 0) || (((size_t)iRet) > cchMax)) {
	  pszDestEnd = pszDest + cchMax;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	  hr = STRSAFE_E_INSUFFICIENT_BUFFER;
	} else if(((size_t)iRet)==cchMax) {
	  pszDestEnd = pszDest + cchMax;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	} else if(((size_t)iRet) < cchMax) {
	  pszDestEnd = pszDest + iRet;
	  cchRemaining = cchDest - iRet;
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)));
	  }
	}
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFEAPI StringLengthWorkerA(STRSAFE_LPCSTR psz,size_t cchMax,size_t *pcchLength) {
  HRESULT hr = S_OK;
  size_t cchMaxPrev = cchMax;
  while(cchMax && (*psz!='\0')) {
    psz++;
    cchMax--;
  }
  if(cchMax==0) hr = STRSAFE_E_INVALID_PARAMETER;
  if(pcchLength) {
    if(SUCCEEDED(hr)) *pcchLength = cchMaxPrev - cchMax;
    else *pcchLength = 0;
  }
  return hr;
}

STRSAFEAPI StringLengthWorkerW(STRSAFE_LPCWSTR psz,size_t cchMax,size_t *pcchLength) {
  HRESULT hr = S_OK;
  size_t cchMaxPrev = cchMax;
  while(cchMax && (*psz!=L'\0')) {
    psz++;
    cchMax--;
  }
  if(cchMax==0) hr = STRSAFE_E_INVALID_PARAMETER;
  if(pcchLength) {
    if(SUCCEEDED(hr)) *pcchLength = cchMaxPrev - cchMax;
    else *pcchLength = 0;
  }
  return hr;
}

STRSAFE_INLINE_API StringGetsExWorkerA(STRSAFE_LPSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;

  if(dwFlags & (~STRSAFE_VALID_FLAGS)) hr = STRSAFE_E_INVALID_PARAMETER;
  else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest <= 1) {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	if(cchDest==1) *pszDestEnd = '\0';
	hr = STRSAFE_E_INSUFFICIENT_BUFFER;
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining > 1) {
	  char ch;
	  int i = getc(stdin);
	  if(i==EOF) {
	    if(pszDestEnd==pszDest) hr = STRSAFE_E_END_OF_FILE;
	    break;
	  }
	  ch = (char)i;
	  if(ch=='\n') break;
	  *pszDestEnd = ch;
	  pszDestEnd++;
	  cchRemaining--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(char)) + (cbDest % sizeof(char)));
	  }
	}
	*pszDestEnd = '\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = '\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = '\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER) || (hr==STRSAFE_E_END_OF_FILE)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}

STRSAFE_INLINE_API StringGetsExWorkerW(STRSAFE_LPWSTR pszDest,size_t cchDest,size_t cbDest,STRSAFE_LPWSTR *ppszDestEnd,size_t *pcchRemaining,unsigned long dwFlags) {
  HRESULT hr = S_OK;
  STRSAFE_LPWSTR pszDestEnd = pszDest;
  size_t cchRemaining = 0;
  if(dwFlags & (~STRSAFE_VALID_FLAGS)) {
    hr = STRSAFE_E_INVALID_PARAMETER;
  } else {
    if(dwFlags & STRSAFE_IGNORE_NULLS) {
      if(!pszDest) {
	if((cchDest!=0) || (cbDest!=0)) hr = STRSAFE_E_INVALID_PARAMETER;
      }
    }
    if(SUCCEEDED(hr)) {
      if(cchDest <= 1) {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	if(cchDest==1) *pszDestEnd = L'\0';
	hr = STRSAFE_E_INSUFFICIENT_BUFFER;
      } else {
	pszDestEnd = pszDest;
	cchRemaining = cchDest;
	while(cchRemaining > 1) {
	  wchar_t ch = getwc(stdin);
	  if(ch==WEOF) {
	    if(pszDestEnd==pszDest) hr = STRSAFE_E_END_OF_FILE;
	    break;
	  }
	  if(ch==L'\n') break;
	  *pszDestEnd = ch;
	  pszDestEnd++;
	  cchRemaining--;
	}
	if(cchRemaining > 0) {
	  if(dwFlags & STRSAFE_FILL_BEHIND_NULL) {
	    memset(pszDestEnd + 1,STRSAFE_GET_FILL_PATTERN(dwFlags),((cchRemaining - 1)*sizeof(wchar_t)) + (cbDest % sizeof(wchar_t)));
	  }
	}
	*pszDestEnd = L'\0';
      }
    }
  }
  if(FAILED(hr)) {
    if(pszDest) {
      if(dwFlags & STRSAFE_FILL_ON_FAILURE) {
	memset(pszDest,STRSAFE_GET_FILL_PATTERN(dwFlags),cbDest);
	if(STRSAFE_GET_FILL_PATTERN(dwFlags)==0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	} else if(cchDest > 0) {
	  pszDestEnd = pszDest + cchDest - 1;
	  cchRemaining = 1;
	  *pszDestEnd = L'\0';
	}
      }
      if(dwFlags & (STRSAFE_NULL_ON_FAILURE | STRSAFE_NO_TRUNCATION)) {
	if(cchDest > 0) {
	  pszDestEnd = pszDest;
	  cchRemaining = cchDest;
	  *pszDestEnd = L'\0';
	}
      }
    }
  }
  if(SUCCEEDED(hr) || (hr==STRSAFE_E_INSUFFICIENT_BUFFER) || (hr==STRSAFE_E_END_OF_FILE)) {
    if(ppszDestEnd) *ppszDestEnd = pszDestEnd;
    if(pcchRemaining) *pcchRemaining = cchRemaining;
  }
  return hr;
}
#endif /* !__CRT__NO_INLINE */

#define StringCopyWorkerA StringCopyWorkerA_instead_use_StringCchCopyA_or_StringCchCopyExA;
#define StringCopyWorkerW StringCopyWorkerW_instead_use_StringCchCopyW_or_StringCchCopyExW;
#define StringCopyExWorkerA StringCopyExWorkerA_instead_use_StringCchCopyA_or_StringCchCopyExA;
#define StringCopyExWorkerW StringCopyExWorkerW_instead_use_StringCchCopyW_or_StringCchCopyExW;
#define StringCatWorkerA StringCatWorkerA_instead_use_StringCchCatA_or_StringCchCatExA;
#define StringCatWorkerW StringCatWorkerW_instead_use_StringCchCatW_or_StringCchCatExW;
#define StringCatExWorkerA StringCatExWorkerA_instead_use_StringCchCatA_or_StringCchCatExA;
#define StringCatExWorkerW StringCatExWorkerW_instead_use_StringCchCatW_or_StringCchCatExW;
#define StringCatNWorkerA StringCatNWorkerA_instead_use_StringCchCatNA_or_StrincCbCatNA;
#define StringCatNWorkerW StringCatNWorkerW_instead_use_StringCchCatNW_or_StringCbCatNW;
#define StringCatNExWorkerA StringCatNExWorkerA_instead_use_StringCchCatNExA_or_StringCbCatNExA;
#define StringCatNExWorkerW StringCatNExWorkerW_instead_use_StringCchCatNExW_or_StringCbCatNExW;
#define StringVPrintfWorkerA StringVPrintfWorkerA_instead_use_StringCchVPrintfA_or_StringCchVPrintfExA;
#define StringVPrintfWorkerW StringVPrintfWorkerW_instead_use_StringCchVPrintfW_or_StringCchVPrintfExW;
#define StringVPrintfExWorkerA StringVPrintfExWorkerA_instead_use_StringCchVPrintfA_or_StringCchVPrintfExA;
#define StringVPrintfExWorkerW StringVPrintfExWorkerW_instead_use_StringCchVPrintfW_or_StringCchVPrintfExW;
#define StringLengthWorkerA StringLengthWorkerA_instead_use_StringCchLengthA_or_StringCbLengthA;
#define StringLengthWorkerW StringLengthWorkerW_instead_use_StringCchLengthW_or_StringCbLengthW;
#define StringGetsExWorkerA StringGetsExWorkerA_instead_use_StringCchGetsA_or_StringCbGetsA
#define StringGetsExWorkerW StringGetsExWorkerW_instead_use_StringCchGetsW_or_StringCbGetsW

#ifndef STRSAFE_NO_DEPRECATE

#undef strcpy
#define strcpy strcpy_instead_use_StringCbCopyA_or_StringCchCopyA;

#undef wcscpy
#define wcscpy wcscpy_instead_use_StringCbCopyW_or_StringCchCopyW;

#undef strcat
#define strcat strcat_instead_use_StringCbCatA_or_StringCchCatA;

#undef wcscat
#define wcscat wcscat_instead_use_StringCbCatW_or_StringCchCatW;

#undef sprintf
#define sprintf sprintf_instead_use_StringCbPrintfA_or_StringCchPrintfA;

#undef swprintf
#define swprintf swprintf_instead_use_StringCbPrintfW_or_StringCchPrintfW;

#undef vsprintf
#define vsprintf vsprintf_instead_use_StringCbVPrintfA_or_StringCchVPrintfA;

#undef vswprintf
#define vswprintf vswprintf_instead_use_StringCbVPrintfW_or_StringCchVPrintfW;

#undef _snprintf
#define _snprintf _snprintf_instead_use_StringCbPrintfA_or_StringCchPrintfA;

#undef _snwprintf
#define _snwprintf _snwprintf_instead_use_StringCbPrintfW_or_StringCchPrintfW;

#undef _vsnprintf
#define _vsnprintf _vsnprintf_instead_use_StringCbVPrintfA_or_StringCchVPrintfA;

#undef _vsnwprintf
#define _vsnwprintf _vsnwprintf_instead_use_StringCbVPrintfW_or_StringCchVPrintfW;

#undef strcpyA
#define strcpyA strcpyA_instead_use_StringCbCopyA_or_StringCchCopyA;

#undef strcpyW
#define strcpyW strcpyW_instead_use_StringCbCopyW_or_StringCchCopyW;

#undef lstrcpy
#define lstrcpy lstrcpy_instead_use_StringCbCopy_or_StringCchCopy;

#undef lstrcpyA
#define lstrcpyA lstrcpyA_instead_use_StringCbCopyA_or_StringCchCopyA;

#undef lstrcpyW
#define lstrcpyW lstrcpyW_instead_use_StringCbCopyW_or_StringCchCopyW;

#undef StrCpy
#define StrCpy StrCpy_instead_use_StringCbCopy_or_StringCchCopy;

#undef StrCpyA
#define StrCpyA StrCpyA_instead_use_StringCbCopyA_or_StringCchCopyA;

#undef StrCpyW
#define StrCpyW StrCpyW_instead_use_StringCbCopyW_or_StringCchCopyW;

#undef _tcscpy
#define _tcscpy _tcscpy_instead_use_StringCbCopy_or_StringCchCopy;

#undef _ftcscpy
#define _ftcscpy _ftcscpy_instead_use_StringCbCopy_or_StringCchCopy;

#undef lstrcat
#define lstrcat lstrcat_instead_use_StringCbCat_or_StringCchCat;

#undef lstrcatA
#define lstrcatA lstrcatA_instead_use_StringCbCatA_or_StringCchCatA;

#undef lstrcatW
#define lstrcatW lstrcatW_instead_use_StringCbCatW_or_StringCchCatW;

#undef StrCat
#define StrCat StrCat_instead_use_StringCbCat_or_StringCchCat;

#undef StrCatA
#define StrCatA StrCatA_instead_use_StringCbCatA_or_StringCchCatA;

#undef StrCatW
#define StrCatW StrCatW_instead_use_StringCbCatW_or_StringCchCatW;

#undef StrNCat
#define StrNCat StrNCat_instead_use_StringCbCatN_or_StringCchCatN;

#undef StrNCatA
#define StrNCatA StrNCatA_instead_use_StringCbCatNA_or_StringCchCatNA;

#undef StrNCatW
#define StrNCatW StrNCatW_instead_use_StringCbCatNW_or_StringCchCatNW;

#undef StrCatN
#define StrCatN StrCatN_instead_use_StringCbCatN_or_StringCchCatN;

#undef StrCatNA
#define StrCatNA StrCatNA_instead_use_StringCbCatNA_or_StringCchCatNA;

#undef StrCatNW
#define StrCatNW StrCatNW_instead_use_StringCbCatNW_or_StringCchCatNW;

#undef _tcscat
#define _tcscat _tcscat_instead_use_StringCbCat_or_StringCchCat;

#undef _ftcscat
#define _ftcscat _ftcscat_instead_use_StringCbCat_or_StringCchCat;

#undef wsprintf
#define wsprintf wsprintf_instead_use_StringCbPrintf_or_StringCchPrintf;

#undef wsprintfA
#define wsprintfA wsprintfA_instead_use_StringCbPrintfA_or_StringCchPrintfA;

#undef wsprintfW
#define wsprintfW wsprintfW_instead_use_StringCbPrintfW_or_StringCchPrintfW;

#undef wvsprintf
#define wvsprintf wvsprintf_instead_use_StringCbVPrintf_or_StringCchVPrintf;

#undef wvsprintfA
#define wvsprintfA wvsprintfA_instead_use_StringCbVPrintfA_or_StringCchVPrintfA;

#undef wvsprintfW
#define wvsprintfW wvsprintfW_instead_use_StringCbVPrintfW_or_StringCchVPrintfW;

#undef _vstprintf
#define _vstprintf _vstprintf_instead_use_StringCbVPrintf_or_StringCchVPrintf;

#undef _vsntprintf
#define _vsntprintf _vsntprintf_instead_use_StringCbVPrintf_or_StringCchVPrintf;

#undef _stprintf
#define _stprintf _stprintf_instead_use_StringCbPrintf_or_StringCchPrintf;

#undef _sntprintf
#define _sntprintf _sntprintf_instead_use_StringCbPrintf_or_StringCchPrintf;

#undef _getts
#define _getts _getts_instead_use_StringCbGets_or_StringCchGets;

#undef gets
#define gets _gets_instead_use_StringCbGetsA_or_StringCchGetsA;

#undef _getws
#define _getws _getws_instead_use_StringCbGetsW_or_StringCchGetsW;
#endif
#endif
