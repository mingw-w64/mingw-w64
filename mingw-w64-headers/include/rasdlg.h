/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _RASDLG_H_
#define _RASDLG_H_

#include <_mingw_unicode.h>
#include <pshpack4.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <ras.h>

  typedef VOID (WINAPI *RASPBDLGFUNCW)(ULONG_PTR,DWORD,LPWSTR,LPVOID);
  typedef VOID (WINAPI *RASPBDLGFUNCA)(ULONG_PTR,DWORD,LPSTR,LPVOID);

#define RASPBDEVENT_AddEntry 1
#define RASPBDEVENT_EditEntry 2
#define RASPBDEVENT_RemoveEntry 3
#define RASPBDEVENT_DialEntry 4
#define RASPBDEVENT_EditGlobals 5
#define RASPBDEVENT_NoUser 6
#define RASPBDEVENT_NoUserEdit 7

#define RASNOUSER_SmartCard 0x00000001

#define RASNOUSERW struct tagRASNOUSERW
  RASNOUSERW {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwTimeoutMs;
    WCHAR szUserName[UNLEN + 1];
    WCHAR szPassword[PWLEN + 1];
    WCHAR szDomain[DNLEN + 1];
  };

#define RASNOUSERA struct tagRASNOUSERA
  RASNOUSERA {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwTimeoutMs;
    CHAR szUserName[UNLEN + 1];
    CHAR szPassword[PWLEN + 1];
    CHAR szDomain[DNLEN + 1];
  };

#define RASNOUSER __MINGW_NAME_AW(RASNOUSER)

#define LPRASNOUSERW RASNOUSERW*
#define LPRASNOUSERA RASNOUSERA*
#define LPRASNOUSER RASNOUSER*

#define RASPBDFLAG_PositionDlg 0x00000001
#define RASPBDFLAG_ForceCloseOnDial 0x00000002
#define RASPBDFLAG_NoUser 0x00000010
#define RASPBDFLAG_UpdateDefaults 0x80000000

#define RASPBDLGW struct tagRASPBDLGW
  RASPBDLGW {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
    ULONG_PTR dwCallbackId;
    RASPBDLGFUNCW pCallback;
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
  };

#define RASPBDLGA struct tagRASPBDLGA
  RASPBDLGA {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
    ULONG_PTR dwCallbackId;
    RASPBDLGFUNCA pCallback;
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
  };

#define RASPBDLG __MINGW_NAME_AW(RASPBDLG)
#define RASPBDLGFUNC __MINGW_NAME_AW(RASPBDLGFUNC)

#define LPRASPBDLGW RASPBDLGW*
#define LPRASPBDLGA RASPBDLGA*
#define LPRASPBDLG RASPBDLG*

#define RASEDFLAG_PositionDlg 0x00000001
#define RASEDFLAG_NewEntry 0x00000002
#define RASEDFLAG_CloneEntry 0x00000004
#define RASEDFLAG_NoRename 0x00000008
#define RASEDFLAG_ShellOwned 0x40000000
#define RASEDFLAG_NewPhoneEntry 0x00000010
#define RASEDFLAG_NewTunnelEntry 0x00000020
#define RASEDFLAG_NewDirectEntry 0x00000040
#define RASEDFLAG_NewBroadbandEntry 0x00000080
#define RASEDFLAG_InternetEntry 0x00000100
#define RASEDFLAG_NAT 0x00000200

#define RASENTRYDLGW struct tagRASENTRYDLGW
  RASENTRYDLGW {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
    WCHAR szEntry[RAS_MaxEntryName + 1];
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
  };

#define RASENTRYDLGA struct tagRASENTRYDLGA
  RASENTRYDLGA {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
    CHAR szEntry[RAS_MaxEntryName + 1];
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
  };

#define RASENTRYDLG __MINGW_NAME_AW(RASENTRYDLG)

#define LPRASENTRYDLGW RASENTRYDLGW*
#define LPRASENTRYDLGA RASENTRYDLGA*
#define LPRASENTRYDLG RASENTRYDLG*

#define RASDDFLAG_PositionDlg 0x00000001
#define RASDDFLAG_NoPrompt 0x00000002
#define RASDDFLAG_LinkFailure 0x80000000

#define RASDIALDLG struct tagRASDIALDLG
  RASDIALDLG {
    DWORD dwSize;
    HWND hwndOwner;
    DWORD dwFlags;
    LONG xDlg;
    LONG yDlg;
    DWORD dwSubEntry;
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
  };

#define LPRASDIALDLG RASDIALDLG*

  typedef WINBOOL (WINAPI *RasCustomDialDlgFn)(HINSTANCE hInstDll,DWORD dwFlags,LPWSTR lpszPhonebook,LPWSTR lpszEntry,LPWSTR lpszPhoneNumber,LPRASDIALDLG lpInfo,PVOID pvInfo);
  typedef WINBOOL (WINAPI *RasCustomEntryDlgFn)(HINSTANCE hInstDll,LPWSTR lpszPhonebook,LPWSTR lpszEntry,LPRASENTRYDLG lpInfo,DWORD dwFlags);

  WINBOOL WINAPI RasPhonebookDlgA(LPSTR lpszPhonebook,LPSTR lpszEntry,LPRASPBDLGA lpInfo);
  WINBOOL WINAPI RasPhonebookDlgW(LPWSTR lpszPhonebook,LPWSTR lpszEntry,LPRASPBDLGW lpInfo);
  WINBOOL WINAPI RasEntryDlgA(LPSTR lpszPhonebook,LPSTR lpszEntry,LPRASENTRYDLGA lpInfo);
  WINBOOL WINAPI RasEntryDlgW(LPWSTR lpszPhonebook,LPWSTR lpszEntry,LPRASENTRYDLGW lpInfo);
  WINBOOL WINAPI RasDialDlgA(LPSTR lpszPhonebook,LPSTR lpszEntry,LPSTR lpszPhoneNumber,LPRASDIALDLG lpInfo);
  WINBOOL WINAPI RasDialDlgW(LPWSTR lpszPhonebook,LPWSTR lpszEntry,LPWSTR lpszPhoneNumber,LPRASDIALDLG lpInfo);

#define RasPhonebookDlg __MINGW_NAME_AW(RasPhonebookDlg)
#define RasEntryDlg __MINGW_NAME_AW(RasEntryDlg)
#define RasDialDlg __MINGW_NAME_AW(RasDialDlg)

#ifdef __cplusplus
}
#endif

#include <poppack.h>
#endif
