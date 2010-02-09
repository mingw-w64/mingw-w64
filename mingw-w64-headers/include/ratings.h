/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _RATINGS_H_
#define _RATINGS_H_

#include <winerror.h>
#include <shlwapi.h>

STDAPI RatingEnable(HWND hwndParent,LPCSTR pszUsername,WINBOOL fEnable);
STDAPI RatingCheckUserAccess(LPCSTR pszUsername,LPCSTR pszURL,LPCSTR pszRatingInfo,LPBYTE pData,DWORD cbData,void **ppRatingDetails);
STDAPI RatingAccessDeniedDialog(HWND hDlg,LPCSTR pszUsername,LPCSTR pszContentDescription,void *pRatingDetails);
STDAPI RatingAccessDeniedDialog2(HWND hDlg,LPCSTR pszUsername,void *pRatingDetails);
STDAPI RatingFreeDetails(void *pRatingDetails);
STDAPI RatingObtainCancel(HANDLE hRatingObtainQuery);
STDAPI RatingObtainQuery(LPCSTR pszTargetUrl,DWORD dwUserData,void (*fCallback)(DWORD dwUserData,HRESULT hr,LPCSTR pszRating,void *lpvRatingDetails),HANDLE *phRatingObtainQuery);
STDAPI RatingSetupUI(HWND hDlg,LPCSTR pszUsername);
#ifdef _INC_COMMCTRL
STDAPI RatingAddPropertyPage(PROPSHEETHEADER *ppsh);
#endif

STDAPI RatingEnabledQuery();
STDAPI RatingInit();
STDAPI_(void) RatingTerm();

static inline WINBOOL IS_RATINGS_ENABLED() {
  TCHAR szSup[200];
  DWORD dwType;
  DWORD cbSize = sizeof(szSup);
  return (SHGetValue(HKEY_LOCAL_MACHINE,TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Ratings"),TEXT("Key"),&dwType,&szSup,&cbSize)==ERROR_SUCCESS);
}

#define S_RATING_ALLOW S_OK
#define S_RATING_DENY S_FALSE
#define S_RATING_FOUND 0x00000002
#define E_RATING_NOT_FOUND 0x80000001

DECLARE_INTERFACE_(IObtainRating,IUnknown) {
  STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppvObj) PURE;
  STDMETHOD_(ULONG,AddRef) (THIS) PURE;
  STDMETHOD_(ULONG,Release) (THIS) PURE;
  STDMETHOD(ObtainRating) (THIS_ LPCSTR pszTargetUrl,HANDLE hAbortEvent,IMalloc *pAllocator,LPSTR *ppRatingOut) PURE;
  STDMETHOD_(ULONG,GetSortOrder) (THIS) PURE;
};

#define RATING_ORDER_REMOTESITE 0x80000000
#define RATING_ORDER_LOCALLIST 0xC0000000
#endif
