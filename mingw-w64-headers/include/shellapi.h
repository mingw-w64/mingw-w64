/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SHELLAPI
#define _INC_SHELLAPI

#ifndef WINSHELLAPI
#if !defined(_SHELL32_)
#define WINSHELLAPI DECLSPEC_IMPORT
#else
#define WINSHELLAPI
#endif
#endif

#ifndef SHSTDAPI
#if !defined(_SHELL32_)
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#else
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#endif
#endif

#ifndef SHDOCAPI
#if !defined(_SHDOCVW_)
#define SHDOCAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHDOCAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#else
#define SHDOCAPI STDAPI
#define SHDOCAPI_(type) STDAPI_(type)
#endif
#endif

#if !defined(_WIN64)
#include <pshpack1.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

  DECLARE_HANDLE(HDROP);

#ifdef UNICODE
#define DragQueryFile DragQueryFileW
#define ShellExecute ShellExecuteW
#define FindExecutable FindExecutableW
#define ShellAbout ShellAboutW
#define ExtractAssociatedIcon ExtractAssociatedIconW
#define ExtractAssociatedIconEx ExtractAssociatedIconExW
#define ExtractIcon ExtractIconW
#else
#define DragQueryFile DragQueryFileA
#define ShellExecute ShellExecuteA
#define FindExecutable FindExecutableA
#define ShellAbout ShellAboutA
#define ExtractAssociatedIcon ExtractAssociatedIconA
#define ExtractAssociatedIconEx ExtractAssociatedIconExA
#define ExtractIcon ExtractIconA
#endif

  SHSTDAPI_(UINT) DragQueryFileA(HDROP,UINT,LPSTR,UINT);
  SHSTDAPI_(UINT) DragQueryFileW(HDROP,UINT,LPWSTR,UINT);
  SHSTDAPI_(WINBOOL) DragQueryPoint(HDROP,LPPOINT);
  SHSTDAPI_(void) DragFinish(HDROP);
  SHSTDAPI_(void) DragAcceptFiles(HWND,WINBOOL);
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lpResult);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lpResult);
  SHSTDAPI_(LPWSTR *) CommandLineToArgvW(LPCWSTR lpCmdLine,int*pNumArgs);
  SHSTDAPI_(INT) ShellAboutA(HWND hWnd,LPCSTR szApp,LPCSTR szOtherStuff,HICON hIcon);
  SHSTDAPI_(INT) ShellAboutW(HWND hWnd,LPCWSTR szApp,LPCWSTR szOtherStuff,HICON hIcon);
  SHSTDAPI_(HICON) DuplicateIcon(HINSTANCE hInst,HICON hIcon);
  SHSTDAPI_(HICON) ExtractAssociatedIconA(HINSTANCE hInst,LPSTR lpIconPath,LPWORD lpiIcon);
  SHSTDAPI_(HICON) ExtractAssociatedIconW(HINSTANCE hInst,LPWSTR lpIconPath,LPWORD lpiIcon);
#if (_WIN32_IE >= 0x0601)
  SHSTDAPI_(HICON) ExtractAssociatedIconExA(HINSTANCE hInst,LPSTR lpIconPath,LPWORD lpiIconIndex,LPWORD lpiIconId);
  SHSTDAPI_(HICON) ExtractAssociatedIconExW(HINSTANCE hInst,LPWSTR lpIconPath,LPWORD lpiIconIndex,LPWORD lpiIconId);
#endif
  SHSTDAPI_(HICON) ExtractIconA(HINSTANCE hInst,LPCSTR lpszExeFileName,UINT nIconIndex);
  SHSTDAPI_(HICON) ExtractIconW(HINSTANCE hInst,LPCWSTR lpszExeFileName,UINT nIconIndex);

  typedef struct _DRAGINFOA {
    UINT uSize;
    POINT pt;
    WINBOOL fNC;
    LPSTR lpFileList;
    DWORD grfKeyState;
  } DRAGINFOA,*LPDRAGINFOA;

  typedef struct _DRAGINFOW {
    UINT uSize;
    POINT pt;
    WINBOOL fNC;
    LPWSTR lpFileList;
    DWORD grfKeyState;
  } DRAGINFOW,*LPDRAGINFOW;
#ifdef UNICODE
  typedef DRAGINFOW DRAGINFO;
  typedef LPDRAGINFOW LPDRAGINFO;
#else
  typedef DRAGINFOA DRAGINFO;
  typedef LPDRAGINFOA LPDRAGINFO;
#endif

#define ABM_NEW 0x00000000
#define ABM_REMOVE 0x00000001
#define ABM_QUERYPOS 0x00000002
#define ABM_SETPOS 0x00000003
#define ABM_GETSTATE 0x00000004
#define ABM_GETTASKBARPOS 0x00000005
#define ABM_ACTIVATE 0x00000006
#define ABM_GETAUTOHIDEBAR 0x00000007
#define ABM_SETAUTOHIDEBAR 0x00000008

#define ABM_WINDOWPOSCHANGED 0x0000009
#define ABM_SETSTATE 0x0000000a

#define ABN_STATECHANGE 0x0000000
#define ABN_POSCHANGED 0x0000001
#define ABN_FULLSCREENAPP 0x0000002
#define ABN_WINDOWARRANGE 0x0000003

#define ABS_AUTOHIDE 0x0000001
#define ABS_ALWAYSONTOP 0x0000002

#define ABE_LEFT 0
#define ABE_TOP 1
#define ABE_RIGHT 2
#define ABE_BOTTOM 3

  typedef struct _AppBarData {
    DWORD cbSize;
    HWND hWnd;
    UINT uCallbackMessage;
    UINT uEdge;
    RECT rc;
    LPARAM lParam;
  } APPBARDATA,*PAPPBARDATA;

#define EIRESID(x) (-1 *(int)(x))

#ifdef UNICODE
#define DoEnvironmentSubst DoEnvironmentSubstW
#define ExtractIconEx ExtractIconExW
#else
#define DoEnvironmentSubst DoEnvironmentSubstA
#define ExtractIconEx ExtractIconExA
#endif

  SHSTDAPI_(UINT_PTR) SHAppBarMessage(DWORD dwMessage,PAPPBARDATA pData);
  SHSTDAPI_(DWORD) DoEnvironmentSubstA(LPSTR szString,UINT cchString);
  SHSTDAPI_(DWORD) DoEnvironmentSubstW(LPWSTR szString,UINT cchString);
  SHSTDAPI_(UINT) ExtractIconExA(LPCSTR lpszFile,int nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIcons);
  SHSTDAPI_(UINT) ExtractIconExW(LPCWSTR lpszFile,int nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIcons);

#ifndef FO_MOVE

#define FO_MOVE 0x0001
#define FO_COPY 0x0002
#define FO_DELETE 0x0003
#define FO_RENAME 0x0004

#define FOF_MULTIDESTFILES 0x0001
#define FOF_CONFIRMMOUSE 0x0002
#define FOF_SILENT 0x0004
#define FOF_RENAMEONCOLLISION 0x0008
#define FOF_NOCONFIRMATION 0x0010
#define FOF_WANTMAPPINGHANDLE 0x0020

#define FOF_ALLOWUNDO 0x0040
#define FOF_FILESONLY 0x0080
#define FOF_SIMPLEPROGRESS 0x0100
#define FOF_NOCONFIRMMKDIR 0x0200
#define FOF_NOERRORUI 0x0400
#define FOF_NOCOPYSECURITYATTRIBS 0x0800
#define FOF_NORECURSION 0x1000
#define FOF_NO_CONNECTED_ELEMENTS 0x2000
#define FOF_WANTNUKEWARNING 0x4000
#define FOF_NORECURSEREPARSE 0x8000

  typedef WORD FILEOP_FLAGS;

#define PO_DELETE 0x0013
#define PO_RENAME 0x0014
#define PO_PORTCHANGE 0x0020

#define PO_REN_PORT 0x0034

  typedef WORD PRINTEROP_FLAGS;
#endif

  typedef struct _SHFILEOPSTRUCTA {
    HWND hwnd;
    UINT wFunc;
    LPCSTR pFrom;
    LPCSTR pTo;
    FILEOP_FLAGS fFlags;
    WINBOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCSTR lpszProgressTitle;
  } SHFILEOPSTRUCTA,*LPSHFILEOPSTRUCTA;

  typedef struct _SHFILEOPSTRUCTW {
    HWND hwnd;
    UINT wFunc;
    LPCWSTR pFrom;
    LPCWSTR pTo;
    FILEOP_FLAGS fFlags;
    WINBOOL fAnyOperationsAborted;
    LPVOID hNameMappings;
    LPCWSTR lpszProgressTitle;
  } SHFILEOPSTRUCTW,*LPSHFILEOPSTRUCTW;
#ifdef UNICODE
  typedef SHFILEOPSTRUCTW SHFILEOPSTRUCT;
  typedef LPSHFILEOPSTRUCTW LPSHFILEOPSTRUCT;
#else
  typedef SHFILEOPSTRUCTA SHFILEOPSTRUCT;
  typedef LPSHFILEOPSTRUCTA LPSHFILEOPSTRUCT;
#endif

#ifdef UNICODE
#define SHFileOperation SHFileOperationW
#else
#define SHFileOperation SHFileOperationA
#endif

  SHSTDAPI_(int) SHFileOperationA(LPSHFILEOPSTRUCTA lpFileOp);
  SHSTDAPI_(int) SHFileOperationW(LPSHFILEOPSTRUCTW lpFileOp);
  SHSTDAPI_(void) SHFreeNameMappings(HANDLE hNameMappings);

  typedef struct _SHNAMEMAPPINGA {
    LPSTR pszOldPath;
    LPSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
  } SHNAMEMAPPINGA,*LPSHNAMEMAPPINGA;

  typedef struct _SHNAMEMAPPINGW {
    LPWSTR pszOldPath;
    LPWSTR pszNewPath;
    int cchOldPath;
    int cchNewPath;
  } SHNAMEMAPPINGW,*LPSHNAMEMAPPINGW;
#ifdef UNICODE
  typedef SHNAMEMAPPINGW SHNAMEMAPPING;
  typedef LPSHNAMEMAPPINGW LPSHNAMEMAPPING;
#else
  typedef SHNAMEMAPPINGA SHNAMEMAPPING;
  typedef LPSHNAMEMAPPINGA LPSHNAMEMAPPING;
#endif

#define SE_ERR_FNF 2
#define SE_ERR_PNF 3
#define SE_ERR_ACCESSDENIED 5
#define SE_ERR_OOM 8
#define SE_ERR_DLLNOTFOUND 32

#define SE_ERR_SHARE 26
#define SE_ERR_ASSOCINCOMPLETE 27
#define SE_ERR_DDETIMEOUT 28
#define SE_ERR_DDEFAIL 29
#define SE_ERR_DDEBUSY 30
#define SE_ERR_NOASSOC 31

#define SEE_MASK_CLASSNAME 0x00000001
#define SEE_MASK_CLASSKEY 0x00000003

#define SEE_MASK_IDLIST 0x00000004
#define SEE_MASK_INVOKEIDLIST 0x0000000c
#define SEE_MASK_ICON 0x00000010
#define SEE_MASK_HOTKEY 0x00000020
#define SEE_MASK_NOCLOSEPROCESS 0x00000040
#define SEE_MASK_CONNECTNETDRV 0x00000080
#define SEE_MASK_FLAG_DDEWAIT 0x00000100
#define SEE_MASK_DOENVSUBST 0x00000200
#define SEE_MASK_FLAG_NO_UI 0x00000400
#define SEE_MASK_UNICODE 0x00004000
#define SEE_MASK_NO_CONSOLE 0x00008000
#define SEE_MASK_ASYNCOK 0x00100000
#define SEE_MASK_HMONITOR 0x00200000
#if (_WIN32_IE >= 0x0560)
#define SEE_MASK_NOZONECHECKS 0x00800000
#endif
#define SEE_MASK_NOQUERYCLASSSTORE 0x01000000
#define SEE_MASK_WAITFORINPUTIDLE 0x02000000
#if (_WIN32_IE >= 0x0560)
#define SEE_MASK_FLAG_LOG_USAGE 0x04000000
#endif

  typedef struct _SHELLEXECUTEINFOA {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpFile;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    __MINGW_EXTENSION union {
      HANDLE hIcon;
      HANDLE hMonitor;
    } DUMMYUNIONNAME;
    HANDLE hProcess;
  } SHELLEXECUTEINFOA,*LPSHELLEXECUTEINFOA;

  typedef struct _SHELLEXECUTEINFOW {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCWSTR lpVerb;
    LPCWSTR lpFile;
    LPCWSTR lpParameters;
    LPCWSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCWSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    __MINGW_EXTENSION union {
      HANDLE hIcon;
      HANDLE hMonitor;
    } DUMMYUNIONNAME;
    HANDLE hProcess;
  } SHELLEXECUTEINFOW,*LPSHELLEXECUTEINFOW;
#ifdef UNICODE
  typedef SHELLEXECUTEINFOW SHELLEXECUTEINFO;
  typedef LPSHELLEXECUTEINFOW LPSHELLEXECUTEINFO;
#else
  typedef SHELLEXECUTEINFOA SHELLEXECUTEINFO;
  typedef LPSHELLEXECUTEINFOA LPSHELLEXECUTEINFO;
#endif

#ifdef UNICODE
#define ShellExecuteEx ShellExecuteExW
#define WinExecError WinExecErrorW
#else
#define ShellExecuteEx ShellExecuteExA
#define WinExecError WinExecErrorA
#endif

  SHSTDAPI_(WINBOOL) ShellExecuteExA(LPSHELLEXECUTEINFOA lpExecInfo);
  SHSTDAPI_(WINBOOL) ShellExecuteExW(LPSHELLEXECUTEINFOW lpExecInfo);
  SHSTDAPI_(void) WinExecErrorA(HWND hwnd,int error,LPCSTR lpstrFileName,LPCSTR lpstrTitle);
  SHSTDAPI_(void) WinExecErrorW(HWND hwnd,int error,LPCWSTR lpstrFileName,LPCWSTR lpstrTitle);

  typedef struct _SHCREATEPROCESSINFOW {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCWSTR pszFile;
    LPCWSTR pszParameters;
    LPCWSTR pszCurrentDirectory;
    HANDLE hUserToken;
    LPSECURITY_ATTRIBUTES lpProcessAttributes;
    LPSECURITY_ATTRIBUTES lpThreadAttributes;
    WINBOOL bInheritHandles;
    DWORD dwCreationFlags;
    LPSTARTUPINFOW lpStartupInfo;
    LPPROCESS_INFORMATION lpProcessInformation;
  } SHCREATEPROCESSINFOW,*PSHCREATEPROCESSINFOW;

  SHSTDAPI_(WINBOOL) SHCreateProcessAsUserW(PSHCREATEPROCESSINFOW pscpi);

  typedef struct _SHQUERYRBINFO {
    DWORD cbSize;
    __MINGW_EXTENSION __int64 i64Size;
    __MINGW_EXTENSION __int64 i64NumItems;
  } SHQUERYRBINFO,*LPSHQUERYRBINFO;

#define SHERB_NOCONFIRMATION 0x00000001
#define SHERB_NOPROGRESSUI 0x00000002
#define SHERB_NOSOUND 0x00000004

#ifdef UNICODE
#define SHQueryRecycleBin SHQueryRecycleBinW
#define SHEmptyRecycleBin SHEmptyRecycleBinW
#else
#define SHQueryRecycleBin SHQueryRecycleBinA
#define SHEmptyRecycleBin SHEmptyRecycleBinA
#endif

  SHSTDAPI SHQueryRecycleBinA(LPCSTR pszRootPath,LPSHQUERYRBINFO pSHQueryRBInfo);
  SHSTDAPI SHQueryRecycleBinW(LPCWSTR pszRootPath,LPSHQUERYRBINFO pSHQueryRBInfo);
  SHSTDAPI SHEmptyRecycleBinA(HWND hwnd,LPCSTR pszRootPath,DWORD dwFlags);
  SHSTDAPI SHEmptyRecycleBinW(HWND hwnd,LPCWSTR pszRootPath,DWORD dwFlags);

  typedef struct _NOTIFYICONDATAA {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
    CHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    CHAR szInfo[256];
    __MINGW_EXTENSION union {
      UINT uTimeout;
      UINT uVersion;
    } DUMMYUNIONNAME;
    CHAR szInfoTitle[64];
    DWORD dwInfoFlags;
#if (_WIN32_IE >= 0x600)
    GUID guidItem;
#endif
  } NOTIFYICONDATAA,*PNOTIFYICONDATAA;

  typedef struct _NOTIFYICONDATAW {
    DWORD cbSize;
    HWND hWnd;
    UINT uID;
    UINT uFlags;
    UINT uCallbackMessage;
    HICON hIcon;
    WCHAR szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    WCHAR szInfo[256];
    __MINGW_EXTENSION union {
      UINT uTimeout;
      UINT uVersion;
    } DUMMYUNIONNAME;
    WCHAR szInfoTitle[64];
    DWORD dwInfoFlags;
#if (_WIN32_IE >= 0x600)
    GUID guidItem;
#endif
  } NOTIFYICONDATAW,*PNOTIFYICONDATAW;
#ifdef UNICODE
  typedef NOTIFYICONDATAW NOTIFYICONDATA;
  typedef PNOTIFYICONDATAW PNOTIFYICONDATA;
#else
  typedef NOTIFYICONDATAA NOTIFYICONDATA;
  typedef PNOTIFYICONDATAA PNOTIFYICONDATA;
#endif

#define NOTIFYICONDATAA_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAA,szTip[64])
#define NOTIFYICONDATAW_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAW,szTip[64])
#ifdef UNICODE
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAW_V1_SIZE
#else
#define NOTIFYICONDATA_V1_SIZE NOTIFYICONDATAA_V1_SIZE
#endif

#define NOTIFYICONDATAA_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAA,guidItem)
#define NOTIFYICONDATAW_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAW,guidItem)
#ifdef UNICODE
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAW_V2_SIZE
#else
#define NOTIFYICONDATA_V2_SIZE NOTIFYICONDATAA_V2_SIZE
#endif

#define NIN_SELECT (WM_USER + 0)
#define NINF_KEY 0x1
#define NIN_KEYSELECT (NIN_SELECT | NINF_KEY)
#define NIN_BALLOONSHOW (WM_USER + 2)
#define NIN_BALLOONHIDE (WM_USER + 3)
#define NIN_BALLOONTIMEOUT (WM_USER + 4)
#define NIN_BALLOONUSERCLICK (WM_USER + 5)
#define NIM_ADD 0x00000000
#define NIM_MODIFY 0x00000001
#define NIM_DELETE 0x00000002
#define NIM_SETFOCUS 0x00000003
#define NIM_SETVERSION 0x00000004
#define NOTIFYICON_VERSION 3

#define NIF_MESSAGE 0x00000001
#define NIF_ICON 0x00000002
#define NIF_TIP 0x00000004
#define NIF_STATE 0x00000008
#define NIF_INFO 0x00000010
#if (_WIN32_IE >= 0x600)
#define NIF_GUID 0x00000020
#endif

#define NIS_HIDDEN 0x00000001
#define NIS_SHAREDICON 0x00000002

#define NIIF_NONE 0x00000000
#define NIIF_INFO 0x00000001
#define NIIF_WARNING 0x00000002
#define NIIF_ERROR 0x00000003
#if (_WIN32_IE >= 0x0600)
#define NIIF_USER 0x00000004
#endif
#define NIIF_ICON_MASK 0x0000000F
#define NIIF_NOSOUND 0x00000010

#ifdef UNICODE
#define Shell_NotifyIcon Shell_NotifyIconW
#else
#define Shell_NotifyIcon Shell_NotifyIconA
#endif

  SHSTDAPI_(WINBOOL) Shell_NotifyIconA(DWORD dwMessage,PNOTIFYICONDATAA lpData);
  SHSTDAPI_(WINBOOL) Shell_NotifyIconW(DWORD dwMessage,PNOTIFYICONDATAW lpData);

#ifndef SHFILEINFO_DEFINED
#define SHFILEINFO_DEFINED
  typedef struct _SHFILEINFOA {
    HICON hIcon;
    int iIcon;
    DWORD dwAttributes;
    CHAR szDisplayName[MAX_PATH];
    CHAR szTypeName[80];
  } SHFILEINFOA;

  typedef struct _SHFILEINFOW {
    HICON hIcon;
    int iIcon;
    DWORD dwAttributes;
    WCHAR szDisplayName[MAX_PATH];
    WCHAR szTypeName[80];
  } SHFILEINFOW;
#ifdef UNICODE
  typedef SHFILEINFOW SHFILEINFO;
#else
  typedef SHFILEINFOA SHFILEINFO;
#endif
#endif

#define SHGFI_ICON 0x000000100
#define SHGFI_DISPLAYNAME 0x000000200
#define SHGFI_TYPENAME 0x000000400
#define SHGFI_ATTRIBUTES 0x000000800
#define SHGFI_ICONLOCATION 0x000001000
#define SHGFI_EXETYPE 0x000002000
#define SHGFI_SYSICONINDEX 0x000004000
#define SHGFI_LINKOVERLAY 0x000008000
#define SHGFI_SELECTED 0x000010000
#define SHGFI_ATTR_SPECIFIED 0x000020000
#define SHGFI_LARGEICON 0x000000000
#define SHGFI_SMALLICON 0x000000001
#define SHGFI_OPENICON 0x000000002
#define SHGFI_SHELLICONSIZE 0x000000004
#define SHGFI_PIDL 0x000000008
#define SHGFI_USEFILEATTRIBUTES 0x000000010
#define SHGFI_ADDOVERLAYS 0x000000020
#define SHGFI_OVERLAYINDEX 0x000000040

#ifdef UNICODE
#define SHGetFileInfo SHGetFileInfoW
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
#define SHGetNewLinkInfo SHGetNewLinkInfoW
#else
#define SHGetFileInfo SHGetFileInfoA
#define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
#define SHGetNewLinkInfo SHGetNewLinkInfoA
#endif

  SHSTDAPI_(DWORD_PTR) SHGetFileInfoA(LPCSTR pszPath,DWORD dwFileAttributes,SHFILEINFOA *psfi,UINT cbFileInfo,UINT uFlags);
  SHSTDAPI_(DWORD_PTR) SHGetFileInfoW(LPCWSTR pszPath,DWORD dwFileAttributes,SHFILEINFOW *psfi,UINT cbFileInfo,UINT uFlags);
#define SHGetDiskFreeSpace SHGetDiskFreeSpaceEx
  SHSTDAPI_(WINBOOL) SHGetDiskFreeSpaceExA(LPCSTR pszDirectoryName,ULARGE_INTEGER *pulFreeBytesAvailableToCaller,ULARGE_INTEGER *pulTotalNumberOfBytes,ULARGE_INTEGER *pulTotalNumberOfFreeBytes);
  SHSTDAPI_(WINBOOL) SHGetDiskFreeSpaceExW(LPCWSTR pszDirectoryName,ULARGE_INTEGER *pulFreeBytesAvailableToCaller,ULARGE_INTEGER *pulTotalNumberOfBytes,ULARGE_INTEGER *pulTotalNumberOfFreeBytes);
  SHSTDAPI_(WINBOOL) SHGetNewLinkInfoA(LPCSTR pszLinkTo,LPCSTR pszDir,LPSTR pszName,WINBOOL *pfMustCopy,UINT uFlags);
  SHSTDAPI_(WINBOOL) SHGetNewLinkInfoW(LPCWSTR pszLinkTo,LPCWSTR pszDir,LPWSTR pszName,WINBOOL *pfMustCopy,UINT uFlags);

#define SHGNLI_PIDL 0x000000001
#define SHGNLI_PREFIXNAME 0x000000002
#define SHGNLI_NOUNIQUE 0x000000004
#define SHGNLI_NOLNK 0x000000008

#define PRINTACTION_OPEN 0
#define PRINTACTION_PROPERTIES 1
#define PRINTACTION_NETINSTALL 2
#define PRINTACTION_NETINSTALLLINK 3
#define PRINTACTION_TESTPAGE 4
#define PRINTACTION_OPENNETPRN 5
#ifdef WINNT
#define PRINTACTION_DOCUMENTDEFAULTS 6
#define PRINTACTION_SERVERPROPERTIES 7
#endif

#ifdef UNICODE
#define SHInvokePrinterCommand SHInvokePrinterCommandW
#else
#define SHInvokePrinterCommand SHInvokePrinterCommandA
#endif

  SHSTDAPI_(WINBOOL) SHInvokePrinterCommandA(HWND hwnd,UINT uAction,LPCSTR lpBuf1,LPCSTR lpBuf2,WINBOOL fModal);
  SHSTDAPI_(WINBOOL) SHInvokePrinterCommandW(HWND hwnd,UINT uAction,LPCWSTR lpBuf1,LPCWSTR lpBuf2,WINBOOL fModal);
  SHSTDAPI SHLoadNonloadedIconOverlayIdentifiers(void);
  SHSTDAPI SHIsFileAvailableOffline(LPCWSTR pwszPath,LPDWORD pdwStatus);

#define OFFLINE_STATUS_LOCAL 0x0001
#define OFFLINE_STATUS_REMOTE 0x0002
#define OFFLINE_STATUS_INCOMPLETE 0x0004

  SHSTDAPI SHSetLocalizedName(LPWSTR pszPath,LPCWSTR pszResModule,int idsRes);

#if (_WIN32_IE >= 0x0601)

#ifdef UNICODE
#define ShellMessageBox ShellMessageBoxW
#else
#define ShellMessageBox ShellMessageBoxA
#endif

  int __cdecl ShellMessageBoxA(HINSTANCE hAppInst,HWND hWnd,LPCSTR lpcText,LPCSTR lpcTitle,UINT fuStyle,...);
  int __cdecl ShellMessageBoxW(HINSTANCE hAppInst,HWND hWnd,LPCWSTR lpcText,LPCWSTR lpcTitle,UINT fuStyle,...);
#endif

#if (_WIN32_IE >= 0x0601)
#ifdef UNICODE
#define IsLFNDrive IsLFNDriveW
#else
#define IsLFNDrive IsLFNDriveA
#endif

  SHSTDAPI_(WINBOOL) IsLFNDriveA(LPCSTR pszPath);
  SHSTDAPI_(WINBOOL) IsLFNDriveW(LPCWSTR pszPath);
#endif

#if _WIN32_IE >= 0x0600
#ifdef UNICODE
#define SHEnumerateUnreadMailAccounts SHEnumerateUnreadMailAccountsW
#define SHGetUnreadMailCount SHGetUnreadMailCountW
#define SHSetUnreadMailCount SHSetUnreadMailCountW
#else
#define SHEnumerateUnreadMailAccounts SHEnumerateUnreadMailAccountsA
#define SHGetUnreadMailCount SHGetUnreadMailCountA
#define SHSetUnreadMailCount SHSetUnreadMailCountA
#endif

  STDAPI SHEnumerateUnreadMailAccountsA(HKEY hKeyUser,DWORD dwIndex,LPSTR pszMailAddress,int cchMailAddress);
  STDAPI SHEnumerateUnreadMailAccountsW(HKEY hKeyUser,DWORD dwIndex,LPWSTR pszMailAddress,int cchMailAddress);
  STDAPI SHGetUnreadMailCountA(HKEY hKeyUser,LPCSTR pszMailAddress,DWORD *pdwCount,FILETIME *pFileTime,LPSTR pszShellExecuteCommand,int cchShellExecuteCommand);
  STDAPI SHGetUnreadMailCountW(HKEY hKeyUser,LPCWSTR pszMailAddress,DWORD *pdwCount,FILETIME *pFileTime,LPWSTR pszShellExecuteCommand,int cchShellExecuteCommand);
  STDAPI SHSetUnreadMailCountA(LPCSTR pszMailAddress,DWORD dwCount,LPCSTR pszShellExecuteCommand);
  STDAPI SHSetUnreadMailCountW(LPCWSTR pszMailAddress,DWORD dwCount,LPCWSTR pszShellExecuteCommand);
#endif

#if (_WIN32_IE >= 0x0601)
  STDAPI_(WINBOOL) SHTestTokenMembership(HANDLE hToken,ULONG ulRID);
#endif

#if _WIN32_IE >= 0x0600

  STDAPI SHGetImageList(int iImageList,REFIID riid,void **ppvObj);

#define SHIL_LARGE 0
#define SHIL_SMALL 1
#define SHIL_EXTRALARGE 2
#define SHIL_SYSSMALL 3

#define SHIL_LAST SHIL_SYSSMALL

  typedef HRESULT (WINAPI *PFNCANSHAREFOLDERW)(LPCWSTR pszPath);
  typedef HRESULT (WINAPI *PFNSHOWSHAREFOLDERUIW)(HWND hwndParent,LPCWSTR pszPath);
#endif

#ifdef __cplusplus
}
#endif

#if !defined(_WIN64)
#include <poppack.h>
#endif
#endif
