/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SHLOBJ_H_
#define _SHLOBJ_H_

#include <_mingw_unicode.h>

#ifndef _WINRESRC_
#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#else
/* FIXME: This really must be 0x0501 !!! */
#if (_WIN32_IE < 0x0500)
#error _WIN32_IE setting conflicts
#endif
#endif
#endif

#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif

#ifndef WINSHELLAPI
#if defined(_SHELL32_)
#define WINSHELLAPI
#else
#define WINSHELLAPI DECLSPEC_IMPORT
#endif
#endif

#ifndef SHSTDAPI
#if defined(_SHELL32_)
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#else
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#endif
#endif

#ifndef SHDOCAPI
#if defined(_SHDOCVW_)
#define SHDOCAPI STDAPI
#define SHDOCAPI_(type) STDAPI_(type)
#else
#define SHDOCAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHDOCAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#endif
#endif

#ifndef SHSTDDOCAPI
#if defined(_SHDOCVW_) || defined(_SHELL32_)
#define SHSTDDOCAPI STDAPI
#define SHSTDDOCAPI_(type) STDAPI_(type)
#else
#define SHSTDDOCAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDDOCAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#endif
#endif

#ifndef BROWSEUIAPI
#if defined(_BROWSEUI_)
#define BROWSEUIAPI STDAPI
#define BROWSEUIAPI_(type) STDAPI_(type)
#else
#define BROWSEUIAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define BROWSEUIAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#endif
#endif

#ifndef SHFOLDERAPI
#if defined(_SHFOLDER_) || defined(_SHELL32_)
#define SHFOLDERAPI STDAPI
#else
#define SHFOLDERAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#endif
#endif

#include <ole2.h>
#include <prsht.h>
#include <commctrl.h>

#ifndef INITGUID
#include <shlguid.h>
#endif

#include <pshpack1.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <shtypes.h>
#include <shobjidl.h>

  SHSTDAPI SHGetMalloc(LPMALLOC *ppMalloc);
  SHSTDAPI_(void *) SHAlloc(SIZE_T cb);
  SHSTDAPI_(void) SHFree(void *pv);

#define CMF_NORMAL 0x00000000
#define CMF_DEFAULTONLY 0x00000001
#define CMF_VERBSONLY 0x00000002
#define CMF_EXPLORE 0x00000004
#define CMF_NOVERBS 0x00000008
#define CMF_CANRENAME 0x00000010
#define CMF_NODEFAULT 0x00000020
#define CMF_INCLUDESTATIC 0x00000040
#define CMF_EXTENDEDVERBS 0x00000100
#define CMF_RESERVED 0xffff0000

#define GCS_VERBA 0x00000000
#define GCS_HELPTEXTA 0x00000001
#define GCS_VALIDATEA 0x00000002
#define GCS_VERBW 0x00000004
#define GCS_HELPTEXTW 0x00000005
#define GCS_VALIDATEW 0x00000006
#define GCS_UNICODE 0x00000004

#define GCS_VERB __MINGW_NAME_AW(GCS_VERB)
#define GCS_HELPTEXT __MINGW_NAME_AW(GCS_HELPTEXT)
#define GCS_VALIDATE __MINGW_NAME_AW(GCS_VALIDATE)

#define CMDSTR_NEWFOLDERA "NewFolder"
#define CMDSTR_VIEWLISTA "ViewList"
#define CMDSTR_VIEWDETAILSA "ViewDetails"
#define CMDSTR_NEWFOLDERW L"NewFolder"
#define CMDSTR_VIEWLISTW L"ViewList"
#define CMDSTR_VIEWDETAILSW L"ViewDetails"

#define CMDSTR_NEWFOLDER __MINGW_NAME_AW(CMDSTR_NEWFOLDER)
#define CMDSTR_VIEWLIST __MINGW_NAME_AW(CMDSTR_VIEWLIST)
#define CMDSTR_VIEWDETAILS __MINGW_NAME_AW(CMDSTR_VIEWDETAILS)

#define CMIC_MASK_HOTKEY SEE_MASK_HOTKEY
#define CMIC_MASK_ICON SEE_MASK_ICON
#define CMIC_MASK_FLAG_NO_UI SEE_MASK_FLAG_NO_UI
#define CMIC_MASK_UNICODE SEE_MASK_UNICODE
#define CMIC_MASK_NO_CONSOLE SEE_MASK_NO_CONSOLE
#define CMIC_MASK_HASLINKNAME SEE_MASK_HASLINKNAME
#define CMIC_MASK_FLAG_SEP_VDM SEE_MASK_FLAG_SEPVDM
#define CMIC_MASK_HASTITLE SEE_MASK_HASTITLE
#define CMIC_MASK_ASYNCOK SEE_MASK_ASYNCOK
#if (_WIN32_IE >= 0x0603)
#define CMIC_MASK_NOZONECHECKS SEE_MASK_NOZONECHECKS
#endif

#define CMIC_MASK_SHIFT_DOWN 0x10000000
#define CMIC_MASK_CONTROL_DOWN 0x40000000
#if (_WIN32_IE >= 0x0560)
#define CMIC_MASK_FLAG_LOG_USAGE SEE_MASK_FLAG_LOG_USAGE
#define CMIC_MASK_NOZONECHECKS SEE_MASK_NOZONECHECKS
#endif
#define CMIC_MASK_PTINVOKE 0x20000000

#include <pshpack8.h>

  typedef struct _CMINVOKECOMMANDINFO {
    DWORD cbSize;
    DWORD fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;

    DWORD dwHotKey;
    HANDLE hIcon;
  } CMINVOKECOMMANDINFO,*LPCMINVOKECOMMANDINFO;

  typedef struct _CMInvokeCommandInfoEx {
    DWORD cbSize;
    DWORD fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    DWORD dwHotKey;
    HANDLE hIcon;
    LPCSTR lpTitle;
    LPCWSTR lpVerbW;
    LPCWSTR lpParametersW;
    LPCWSTR lpDirectoryW;
    LPCWSTR lpTitleW;
    POINT ptInvoke;
  } CMINVOKECOMMANDINFOEX,*LPCMINVOKECOMMANDINFOEX;

#include <poppack.h>

#undef INTERFACE
#define INTERFACE IContextMenu

  DECLARE_INTERFACE_(IContextMenu,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(QueryContextMenu)(THIS_ HMENU hmenu,UINT indexMenu,UINT idCmdFirst,UINT idCmdLast,UINT uFlags) PURE;
    STDMETHOD(InvokeCommand)(THIS_ LPCMINVOKECOMMANDINFO lpici) PURE;
    STDMETHOD(GetCommandString)(THIS_ UINT_PTR idCmd,UINT uType,UINT *pwReserved,LPSTR pszName,UINT cchMax) PURE;
  };

  typedef IContextMenu *LPCONTEXTMENU;

#undef INTERFACE
#define INTERFACE IContextMenu2
  DECLARE_INTERFACE_(IContextMenu2,IContextMenu) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(QueryContextMenu)(THIS_ HMENU hmenu,UINT indexMenu,UINT idCmdFirst,UINT idCmdLast,UINT uFlags) PURE;
    STDMETHOD(InvokeCommand)(THIS_ LPCMINVOKECOMMANDINFO lpici) PURE;
    STDMETHOD(GetCommandString)(THIS_ UINT_PTR idCmd,UINT uType,UINT *pwReserved,LPSTR pszName,UINT cchMax) PURE;
    STDMETHOD(HandleMenuMsg)(THIS_ UINT uMsg,WPARAM wParam,LPARAM lParam) PURE;
  };

  typedef IContextMenu2 *LPCONTEXTMENU2;

#undef INTERFACE
#define INTERFACE IContextMenu3
  DECLARE_INTERFACE_(IContextMenu3,IContextMenu2) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(QueryContextMenu)(THIS_ HMENU hmenu,UINT indexMenu,UINT idCmdFirst,UINT idCmdLast,UINT uFlags) PURE;
    STDMETHOD(InvokeCommand)(THIS_ LPCMINVOKECOMMANDINFO lpici) PURE;
    STDMETHOD(GetCommandString)(THIS_ UINT_PTR idCmd,UINT uType,UINT *pwReserved,LPSTR pszName,UINT cchMax) PURE;
    STDMETHOD(HandleMenuMsg)(THIS_ UINT uMsg,WPARAM wParam,LPARAM lParam) PURE;
    STDMETHOD(HandleMenuMsg2)(THIS_ UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult) PURE;
  };

  typedef IContextMenu3 *LPCONTEXTMENU3;

#undef INTERFACE
#define INTERFACE IPersistFolder3
#define CSIDL_FLAG_PFTI_TRACKTARGET CSIDL_FLAG_DONT_VERIFY

#include <pshpack8.h>

  typedef struct {
    LPITEMIDLIST pidlTargetFolder;
    WCHAR szTargetParsingName[MAX_PATH];
    WCHAR szNetworkProvider[MAX_PATH];
    DWORD dwAttributes;
    int csidl;
  } PERSIST_FOLDER_TARGET_INFO;

#include <poppack.h>

  DECLARE_INTERFACE_(IPersistFolder3,IPersistFolder2) {
    STDMETHOD(QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(GetClassID)(THIS_ LPCLSID lpClassID) PURE;
    STDMETHOD(Initialize)(THIS_ LPCITEMIDLIST pidl) PURE;
    STDMETHOD(GetCurFolder)(THIS_ LPITEMIDLIST *ppidl) PURE;
    STDMETHOD(InitializeEx)(THIS_ IBindCtx *pbc,LPCITEMIDLIST pidlRoot,const PERSIST_FOLDER_TARGET_INFO *ppfti) PURE;
    STDMETHOD(GetFolderTargetInfo)(THIS_ PERSIST_FOLDER_TARGET_INFO *ppfti) PURE;
  };

#define GIL_OPENICON 0x0001
#define GIL_FORSHELL 0x0002
#define GIL_ASYNC 0x0020
#define GIL_DEFAULTICON 0x0040
#define GIL_FORSHORTCUT 0x0080

#define GIL_SIMULATEDOC 0x0001
#define GIL_PERINSTANCE 0x0002
#define GIL_PERCLASS 0x0004
#define GIL_NOTFILENAME 0x0008
#define GIL_DONTCACHE 0x0010

#undef INTERFACE
#define INTERFACE IExtractIconA
  DECLARE_INTERFACE_(IExtractIconA,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetIconLocation)(THIS_ UINT uFlags,LPSTR szIconFile,UINT cchMax,int *piIndex,UINT *pwFlags) PURE;
    STDMETHOD(Extract)(THIS_ LPCSTR pszFile,UINT nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIconSize) PURE;
  };

  typedef IExtractIconA *LPEXTRACTICONA;

#undef INTERFACE
#define INTERFACE IExtractIconW
  DECLARE_INTERFACE_(IExtractIconW,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetIconLocation)(THIS_ UINT uFlags,LPWSTR szIconFile,UINT cchMax,int *piIndex,UINT *pwFlags) PURE;
    STDMETHOD(Extract)(THIS_ LPCWSTR pszFile,UINT nIconIndex,HICON *phiconLarge,HICON *phiconSmall,UINT nIconSize) PURE;
  };

  typedef IExtractIconW *LPEXTRACTICONW;

#define IExtractIcon __MINGW_NAME_AW(IExtractIcon)
#define LPEXTRACTICON __MINGW_NAME_AW(LPEXTRACTICON)

#define IExtractIconVtbl __MINGW_NAME_AW_EXT(IExtractIcon,Vtbl)

#undef INTERFACE
#define INTERFACE IShellIcon
  DECLARE_INTERFACE_(IShellIcon,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetIconOf)(THIS_ LPCITEMIDLIST pidl,UINT flags,LPINT lpIconIndex) PURE;
  };

  typedef IShellIcon *LPSHELLICON;

#undef INTERFACE
#define INTERFACE IShellIconOverlayIdentifier
  DECLARE_INTERFACE_(IShellIconOverlayIdentifier,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (IsMemberOf)(THIS_ LPCWSTR pwszPath,DWORD dwAttrib) PURE;
    STDMETHOD (GetOverlayInfo)(THIS_ LPWSTR pwszIconFile,int cchMax,int *pIndex,DWORD *pdwFlags) PURE;
    STDMETHOD (GetPriority)(THIS_ int *pIPriority) PURE;
  };

#define ISIOI_ICONFILE 0x00000001
#define ISIOI_ICONINDEX 0x00000002
#if (_WIN32_IE >= 0x0601)
#undef INTERFACE
#define INTERFACE IShellIconOverlayManager
  DECLARE_INTERFACE_(IShellIconOverlayManager,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetFileOverlayInfo)(THIS_ LPCWSTR pwszPath,DWORD dwAttrib,int *pIndex,DWORD dwflags) PURE;
    STDMETHOD(GetReservedOverlayInfo)(THIS_ LPCWSTR pwszPath,DWORD dwAttrib,int *pIndex,DWORD dwflags,int iReservedID) PURE;
    STDMETHOD(RefreshOverlayImages)(THIS_ DWORD dwFlags) PURE;
    STDMETHOD(LoadNonloadedOverlayIdentifiers)(THIS) PURE;
    STDMETHOD(OverlayIndexFromImageIndex)(THIS_ int iImage,int *piIndex,WINBOOL fAdd) PURE;
  };
#define SIOM_OVERLAYINDEX 1
#define SIOM_ICONINDEX 2

#define SIOM_RESERVED_SHARED 0
#define SIOM_RESERVED_LINK 1
#define SIOM_RESERVED_SLOWFILE 2
#endif

#undef INTERFACE
#define INTERFACE IShellIconOverlay
  DECLARE_INTERFACE_(IShellIconOverlay,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetOverlayIndex)(THIS_ LPCITEMIDLIST pidl,int *pIndex) PURE;
    STDMETHOD(GetOverlayIconIndex)(THIS_ LPCITEMIDLIST pidl,int *pIconIndex) PURE;
  };

#define OI_ASYNC 0xFFFFEEEE

#define IDO_SHGIOI_SHARE 0x0FFFFFFF
#define IDO_SHGIOI_LINK 0x0FFFFFFE
#define IDO_SHGIOI_SLOWFILE 0x0FFFFFFFD
#define IDO_SHGIOI_DEFAULT 0x0FFFFFFC
  SHSTDAPI_(int) SHGetIconOverlayIndexA(LPCSTR pszIconPath,int iIconIndex);
  SHSTDAPI_(int) SHGetIconOverlayIndexW(LPCWSTR pszIconPath,int iIconIndex);

#define SHGetIconOverlayIndex __MINGW_NAME_AW(SHGetIconOverlayIndex)

  typedef enum {
    SLDF_HAS_ID_LIST = 0x00000001,SLDF_HAS_LINK_INFO = 0x00000002,SLDF_HAS_NAME = 0x00000004,SLDF_HAS_RELPATH = 0x00000008,
    SLDF_HAS_WORKINGDIR = 0x00000010,SLDF_HAS_ARGS = 0x00000020,SLDF_HAS_ICONLOCATION = 0x00000040,SLDF_UNICODE = 0x00000080,
    SLDF_FORCE_NO_LINKINFO = 0x00000100,SLDF_HAS_EXP_SZ = 0x00000200,SLDF_RUN_IN_SEPARATE = 0x00000400,SLDF_HAS_LOGO3ID = 0x00000800,
    SLDF_HAS_DARWINID = 0x00001000,SLDF_RUNAS_USER = 0x00002000,SLDF_HAS_EXP_ICON_SZ = 0x00004000,SLDF_NO_PIDL_ALIAS = 0x00008000,
    SLDF_FORCE_UNCNAME = 0x00010000,SLDF_RUN_WITH_SHIMLAYER = 0x00020000,SLDF_RESERVED = 0x80000000
  } SHELL_LINK_DATA_FLAGS;

  typedef struct tagDATABLOCKHEADER {
    DWORD cbSize;
    DWORD dwSignature;
  } DATABLOCK_HEADER,*LPDATABLOCK_HEADER,*LPDBLIST;

  typedef struct {
#ifdef __cplusplus
    DATABLOCK_HEADER dbh;
#else
/*  DATABLOCK_HEADER; */
    __C89_NAMELESS struct {
      DWORD cbSize;
      DWORD dwSignature;
    };
#endif
    WORD wFillAttribute;
    WORD wPopupFillAttribute;
    COORD dwScreenBufferSize;
    COORD dwWindowSize;
    COORD dwWindowOrigin;
    DWORD nFont;
    DWORD nInputBufferSize;
    COORD dwFontSize;
    UINT uFontFamily;
    UINT uFontWeight;
    WCHAR FaceName[LF_FACESIZE];
    UINT uCursorSize;
    WINBOOL bFullScreen;
    WINBOOL bQuickEdit;
    WINBOOL bInsertMode;
    WINBOOL bAutoPosition;
    UINT uHistoryBufferSize;
    UINT uNumberOfHistoryBuffers;
    WINBOOL bHistoryNoDup;
    COLORREF ColorTable[16 ];
  } NT_CONSOLE_PROPS,*LPNT_CONSOLE_PROPS;
#define NT_CONSOLE_PROPS_SIG 0xA0000002

  typedef struct {
#ifdef __cplusplus
    DATABLOCK_HEADER dbh;
#else
/*  DATABLOCK_HEADER; */
    __C89_NAMELESS struct {
      DWORD cbSize;
      DWORD dwSignature;
    };
#endif
    UINT uCodePage;
  } NT_FE_CONSOLE_PROPS,*LPNT_FE_CONSOLE_PROPS;
#define NT_FE_CONSOLE_PROPS_SIG 0xA0000004

  typedef struct {
#ifdef __cplusplus
    DATABLOCK_HEADER dbh;
#else
/*  DATABLOCK_HEADER; */
    __C89_NAMELESS struct {
      DWORD cbSize;
      DWORD dwSignature;
    };
#endif
    CHAR szDarwinID[MAX_PATH];
    WCHAR szwDarwinID[MAX_PATH];
  } EXP_DARWIN_LINK,*LPEXP_DARWIN_LINK;
#define EXP_DARWIN_ID_SIG 0xA0000006
#define EXP_LOGO3_ID_SIG 0xA0000007

#define EXP_SPECIAL_FOLDER_SIG 0xA0000005

  typedef struct {
    DWORD cbSize;
    DWORD dwSignature;
    DWORD idSpecialFolder;
    DWORD cbOffset;
  } EXP_SPECIAL_FOLDER,*LPEXP_SPECIAL_FOLDER;

  typedef struct {
    DWORD cbSize;
    DWORD dwSignature;
    CHAR szTarget[MAX_PATH ];
    WCHAR swzTarget[MAX_PATH ];
  } EXP_SZ_LINK,*LPEXP_SZ_LINK;
#define EXP_SZ_LINK_SIG 0xA0000001
#define EXP_SZ_ICON_SIG 0xA0000007

#undef INTERFACE
#define INTERFACE IShellLinkDataList
  DECLARE_INTERFACE_(IShellLinkDataList,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(AddDataBlock)(THIS_ void *pDataBlock) PURE;
    STDMETHOD(CopyDataBlock)(THIS_ DWORD dwSig,void **ppDataBlock) PURE;
    STDMETHOD(RemoveDataBlock)(THIS_ DWORD dwSig) PURE;
    STDMETHOD(GetFlags)(THIS_ DWORD *pdwFlags) PURE;
    STDMETHOD(SetFlags)(THIS_ DWORD dwFlags) PURE;
  };

#undef INTERFACE
#define INTERFACE IResolveShellLink
  DECLARE_INTERFACE_(IResolveShellLink,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(ResolveShellLink)(THIS_ IUnknown *punk,HWND hwnd,DWORD fFlags) PURE;
  };

#ifdef _INC_SHELLAPI

#undef INTERFACE
#define INTERFACE IShellExecuteHookA
  DECLARE_INTERFACE_(IShellExecuteHookA,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Execute)(THIS_ LPSHELLEXECUTEINFOA pei) PURE;
  };

#undef INTERFACE
#define INTERFACE IShellExecuteHookW
  DECLARE_INTERFACE_(IShellExecuteHookW,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Execute)(THIS_ LPSHELLEXECUTEINFOW pei) PURE;
  };

#define IShellExecuteHook __MINGW_NAME_AW(IShellExecuteHook)

#define IShellExecuteHookVtbl __MINGW_NAME_AW_EXT(IShellExecuteHook,Vtbl)

#endif

#undef INTERFACE
#define INTERFACE IURLSearchHook
  DECLARE_INTERFACE_(IURLSearchHook,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Translate)(THIS_ LPWSTR lpwszSearchURL,DWORD cchBufferSize) PURE;
  };

#undef INTERFACE
#define INTERFACE ISearchContext
  DECLARE_INTERFACE_(ISearchContext,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetSearchUrl)(THIS_ BSTR *pbstrSearchUrl) PURE;
    STDMETHOD(GetSearchText)(THIS_ BSTR *pbstrSearchText) PURE;
    STDMETHOD(GetSearchStyle)(THIS_ DWORD *pdwSearchStyle) PURE;
  };

#undef INTERFACE
#define INTERFACE IURLSearchHook2
  DECLARE_INTERFACE_(IURLSearchHook2,IURLSearchHook) {
    STDMETHOD(TranslateWithSearchContext)(THIS_ LPWSTR lpwszSearchURL,DWORD cchBufferSize,ISearchContext *pSearchContext) PURE;
  };

#undef INTERFACE
#define INTERFACE INewShortcutHookA

  DECLARE_INTERFACE_(INewShortcutHookA,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(SetReferent)(THIS_ LPCSTR pcszReferent,HWND hwnd) PURE;
    STDMETHOD(GetReferent)(THIS_ LPSTR pszReferent,int cchReferent) PURE;
    STDMETHOD(SetFolder)(THIS_ LPCSTR pcszFolder) PURE;
    STDMETHOD(GetFolder)(THIS_ LPSTR pszFolder,int cchFolder) PURE;
    STDMETHOD(GetName)(THIS_ LPSTR pszName,int cchName) PURE;
    STDMETHOD(GetExtension)(THIS_ LPSTR pszExtension,int cchExtension) PURE;
  };

#undef INTERFACE
#define INTERFACE INewShortcutHookW
  DECLARE_INTERFACE_(INewShortcutHookW,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(SetReferent)(THIS_ LPCWSTR pcszReferent,HWND hwnd) PURE;
    STDMETHOD(GetReferent)(THIS_ LPWSTR pszReferent,int cchReferent) PURE;
    STDMETHOD(SetFolder)(THIS_ LPCWSTR pcszFolder) PURE;
    STDMETHOD(GetFolder)(THIS_ LPWSTR pszFolder,int cchFolder) PURE;
    STDMETHOD(GetName)(THIS_ LPWSTR pszName,int cchName) PURE;
    STDMETHOD(GetExtension)(THIS_ LPWSTR pszExtension,int cchExtension) PURE;
  };

#define INewShortcutHook __MINGW_NAME_AW(INewShortcutHook)

#define INewShortcutHookVtbl __MINGW_NAME_AW_EXT(INewShortcutHook,Vtbl)

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

  typedef UINT PRINTEROP_FLAGS;
#endif

#undef INTERFACE
#define INTERFACE ICopyHookA
  DECLARE_INTERFACE_(ICopyHookA,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD_(UINT,CopyCallback) (THIS_ HWND hwnd,UINT wFunc,UINT wFlags,LPCSTR pszSrcFile,DWORD dwSrcAttribs,LPCSTR pszDestFile,DWORD dwDestAttribs) PURE;
  };

  typedef ICopyHookA *LPCOPYHOOKA;

#undef INTERFACE
#define INTERFACE ICopyHookW
  DECLARE_INTERFACE_(ICopyHookW,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD_(UINT,CopyCallback) (THIS_ HWND hwnd,UINT wFunc,UINT wFlags,LPCWSTR pszSrcFile,DWORD dwSrcAttribs,LPCWSTR pszDestFile,DWORD dwDestAttribs) PURE;
  };

  typedef ICopyHookW *LPCOPYHOOKW;

#define ICopyHook __MINGW_NAME_AW(ICopyHook)
#define LPCOPYHOOK __MINGW_NAME_AW(LPCOPYHOOK)

#define ICopyHookVtbl __MINGW_NAME_AW_EXT(ICopyHook,Vtbl)

#undef INTERFACE
#define INTERFACE IFileViewerSite
  DECLARE_INTERFACE_(IFileViewerSite,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(SetPinnedWindow) (THIS_ HWND hwnd) PURE;
    STDMETHOD(GetPinnedWindow) (THIS_ HWND *phwnd) PURE;
  };

  typedef IFileViewerSite *LPFILEVIEWERSITE;

#include <pshpack8.h>

  typedef struct {
    DWORD cbSize;
    HWND hwndOwner;
    int iShow;
    DWORD dwFlags;
    RECT rect;
    IUnknown *punkRel;
    OLECHAR strNewFile[MAX_PATH];
  } FVSHOWINFO,*LPFVSHOWINFO;

#include <poppack.h>

#define FVSIF_RECT 0x00000001
#define FVSIF_PINNED 0x00000002

#define FVSIF_NEWFAILED 0x08000000

#define FVSIF_NEWFILE 0x80000000
#define FVSIF_CANVIEWIT 0x40000000

#undef INTERFACE
#define INTERFACE IFileViewerA
  DECLARE_INTERFACE(IFileViewerA) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(ShowInitialize) (THIS_ LPFILEVIEWERSITE lpfsi) PURE;
    STDMETHOD(Show) (THIS_ LPFVSHOWINFO pvsi) PURE;
    STDMETHOD(PrintTo) (THIS_ LPSTR pszDriver,WINBOOL fSuppressUI) PURE;
  };

  typedef IFileViewerA *LPFILEVIEWERA;

#undef INTERFACE
#define INTERFACE IFileViewerW
  DECLARE_INTERFACE(IFileViewerW) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(ShowInitialize) (THIS_ LPFILEVIEWERSITE lpfsi) PURE;
    STDMETHOD(Show) (THIS_ LPFVSHOWINFO pvsi) PURE;
    STDMETHOD(PrintTo) (THIS_ LPWSTR pszDriver,WINBOOL fSuppressUI) PURE;
  };

  typedef IFileViewerW *LPFILEVIEWERW;

#define IFileViewer __MINGW_NAME_AW(IFileViewer)
#define LPFILEVIEWER __MINGW_NAME_AW(LPFILEVIEWER)

#define FCIDM_SHVIEWFIRST 0x0000
#define FCIDM_SHVIEWLAST 0x7fff
#define FCIDM_BROWSERFIRST 0xa000
#define FCIDM_BROWSERLAST 0xbf00
#define FCIDM_GLOBALFIRST 0x8000
#define FCIDM_GLOBALLAST 0x9fff

#define FCIDM_MENU_FILE (FCIDM_GLOBALFIRST+0x0000)
#define FCIDM_MENU_EDIT (FCIDM_GLOBALFIRST+0x0040)
#define FCIDM_MENU_VIEW (FCIDM_GLOBALFIRST+0x0080)
#define FCIDM_MENU_VIEW_SEP_OPTIONS (FCIDM_GLOBALFIRST+0x0081)
#define FCIDM_MENU_TOOLS (FCIDM_GLOBALFIRST+0x00c0)
#define FCIDM_MENU_TOOLS_SEP_GOTO (FCIDM_GLOBALFIRST+0x00c1)
#define FCIDM_MENU_HELP (FCIDM_GLOBALFIRST+0x0100)
#define FCIDM_MENU_FIND (FCIDM_GLOBALFIRST+0x0140)
#define FCIDM_MENU_EXPLORE (FCIDM_GLOBALFIRST+0x0150)
#define FCIDM_MENU_FAVORITES (FCIDM_GLOBALFIRST+0x0170)

#define FCIDM_TOOLBAR (FCIDM_BROWSERFIRST + 0)
#define FCIDM_STATUS (FCIDM_BROWSERFIRST + 1)

#define IDC_OFFLINE_HAND 103

#define PANE_NONE -1
#define PANE_ZONE 1
#define PANE_OFFLINE 2
#define PANE_PRINTER 3
#define PANE_SSL 4
#define PANE_NAVIGATION 5
#define PANE_PROGRESS 6
#define PANE_PRIVACY 7

#define CDBOSC_SETFOCUS 0x00000000
#define CDBOSC_KILLFOCUS 0x00000001
#define CDBOSC_SELCHANGE 0x00000002
#define CDBOSC_RENAME 0x00000003
#define CDBOSC_STATECHANGE 0x00000004

#undef INTERFACE
#define INTERFACE ICommDlgBrowser
  DECLARE_INTERFACE_(ICommDlgBrowser,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(OnDefaultCommand) (THIS_ struct IShellView *ppshv) PURE;
    STDMETHOD(OnStateChange) (THIS_ struct IShellView *ppshv,ULONG uChange) PURE;
    STDMETHOD(IncludeObject) (THIS_ struct IShellView *ppshv,LPCITEMIDLIST pidl) PURE;
  };

  typedef ICommDlgBrowser *LPCOMMDLGBROWSER;

#define CDB2N_CONTEXTMENU_DONE 0x00000001
#define CDB2N_CONTEXTMENU_START 0x00000002

#define CDB2GVF_SHOWALLFILES 0x00000001

#undef INTERFACE
#define INTERFACE ICommDlgBrowser2
  DECLARE_INTERFACE_(ICommDlgBrowser2,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(OnDefaultCommand) (THIS_ struct IShellView *ppshv) PURE;
    STDMETHOD(OnStateChange) (THIS_ struct IShellView *ppshv,ULONG uChange) PURE;
    STDMETHOD(IncludeObject) (THIS_ struct IShellView *ppshv,LPCITEMIDLIST pidl) PURE;
    STDMETHOD(Notify) (THIS_ struct IShellView *ppshv,DWORD dwNotifyType) PURE;
    STDMETHOD(GetDefaultMenuText) (THIS_ struct IShellView *ppshv,WCHAR *pszText,INT cchMax) PURE;
    STDMETHOD(GetViewFlags)(THIS_ DWORD *pdwFlags) PURE;
  };

  typedef ICommDlgBrowser2 *LPCOMMDLGBROWSER2;

#define SHGetPathFromIDList __MINGW_NAME_AW(SHGetPathFromIDList)
#define SHCreateDirectoryEx __MINGW_NAME_AW(SHCreateDirectoryEx)

  SHSTDAPI_(WINBOOL) SHGetPathFromIDListA(LPCITEMIDLIST pidl,LPSTR pszPath);
  SHSTDAPI_(WINBOOL) SHGetPathFromIDListW(LPCITEMIDLIST pidl,LPWSTR pszPath);
  SHSTDAPI_(int) SHCreateDirectory(HWND hwnd,LPCWSTR pszPath);
  SHSTDAPI_(int) SHCreateDirectoryExA(HWND hwnd,LPCSTR pszPath,SECURITY_ATTRIBUTES *psa);
  SHSTDAPI_(int) SHCreateDirectoryExW(HWND hwnd,LPCWSTR pszPath,SECURITY_ATTRIBUTES *psa);
  SHSTDAPI SHOpenFolderAndSelectItems(LPCITEMIDLIST pidlFolder,UINT cidl,LPCITEMIDLIST *apidl,DWORD dwFlags);
  SHSTDAPI SHCreateShellItem(LPCITEMIDLIST pidlParent,IShellFolder *psfParent,LPCITEMIDLIST pidl,IShellItem **ppsi);

#define REGSTR_PATH_SPECIAL_FOLDERS REGSTR_PATH_EXPLORER TEXT("\\Shell Folders")

#define CSIDL_DESKTOP 0x0000
#define CSIDL_INTERNET 0x0001
#define CSIDL_PROGRAMS 0x0002
#define CSIDL_CONTROLS 0x0003
#define CSIDL_PRINTERS 0x0004
#define CSIDL_PERSONAL 0x0005
#define CSIDL_FAVORITES 0x0006
#define CSIDL_STARTUP 0x0007
#define CSIDL_RECENT 0x0008
#define CSIDL_SENDTO 0x0009
#define CSIDL_BITBUCKET 0x000a
#define CSIDL_STARTMENU 0x000b
#define CSIDL_MYDOCUMENTS 0x000c
#define CSIDL_MYMUSIC 0x000d
#define CSIDL_MYVIDEO 0x000e
#define CSIDL_DESKTOPDIRECTORY 0x0010
#define CSIDL_DRIVES 0x0011
#define CSIDL_NETWORK 0x0012
#define CSIDL_NETHOOD 0x0013
#define CSIDL_FONTS 0x0014
#define CSIDL_TEMPLATES 0x0015
#define CSIDL_COMMON_STARTMENU 0x0016
#define CSIDL_COMMON_PROGRAMS 0X0017
#define CSIDL_COMMON_STARTUP 0x0018
#define CSIDL_COMMON_DESKTOPDIRECTORY 0x0019
#define CSIDL_APPDATA 0x001a
#define CSIDL_PRINTHOOD 0x001b

#ifndef CSIDL_LOCAL_APPDATA
#define CSIDL_LOCAL_APPDATA 0x001c
#endif

#define CSIDL_ALTSTARTUP 0x001d
#define CSIDL_COMMON_ALTSTARTUP 0x001e
#define CSIDL_COMMON_FAVORITES 0x001f

#ifndef _SHFOLDER_H_
#define CSIDL_INTERNET_CACHE 0x0020
#define CSIDL_COOKIES 0x0021
#define CSIDL_HISTORY 0x0022
#define CSIDL_COMMON_APPDATA 0x0023
#define CSIDL_WINDOWS 0x0024
#define CSIDL_SYSTEM 0x0025
#define CSIDL_PROGRAM_FILES 0x0026
#define CSIDL_MYPICTURES 0x0027
#endif

#define CSIDL_PROFILE 0x0028
#define CSIDL_SYSTEMX86 0x0029
#define CSIDL_PROGRAM_FILESX86 0x002a

#ifndef _SHFOLDER_H_
#define CSIDL_PROGRAM_FILES_COMMON 0x002b
#endif

#define CSIDL_PROGRAM_FILES_COMMONX86 0x002c
#define CSIDL_COMMON_TEMPLATES 0x002d

#ifndef _SHFOLDER_H_
#define CSIDL_COMMON_DOCUMENTS 0x002e
#define CSIDL_COMMON_ADMINTOOLS 0x002f
#define CSIDL_ADMINTOOLS 0x0030
#endif

#define CSIDL_CONNECTIONS 0x0031
#define CSIDL_COMMON_MUSIC 0x0035
#define CSIDL_COMMON_PICTURES 0x0036
#define CSIDL_COMMON_VIDEO 0x0037
#define CSIDL_RESOURCES 0x0038

#ifndef _SHFOLDER_H_
#define CSIDL_RESOURCES_LOCALIZED 0x0039
#endif

#define CSIDL_COMMON_OEM_LINKS 0x003a
#define CSIDL_CDBURN_AREA 0x003b

#define CSIDL_COMPUTERSNEARME 0x003d

#ifndef _SHFOLDER_H_
#define CSIDL_FLAG_CREATE 0x8000
#endif

#define CSIDL_FLAG_DONT_VERIFY 0x4000
#define CSIDL_FLAG_NO_ALIAS 0x1000
#define CSIDL_FLAG_PER_USER_INIT 0x0800
#define CSIDL_FLAG_MASK 0xFF00

#define SHGetSpecialFolderPath __MINGW_NAME_AW(SHGetSpecialFolderPath)
#define SHGetFolderPath __MINGW_NAME_AW(SHGetFolderPath)
#define SHGetFolderPathAndSubDir __MINGW_NAME_AW(SHGetFolderPathAndSubDir)

  SHSTDAPI SHGetSpecialFolderLocation(HWND hwnd,int csidl,LPITEMIDLIST *ppidl);
  SHSTDAPI_(void) SHFlushSFCache(void);
  SHSTDAPI_(LPITEMIDLIST) SHCloneSpecialIDList(HWND hwnd,int csidl,WINBOOL fCreate);
  SHSTDAPI_(WINBOOL) SHGetSpecialFolderPathA(HWND hwnd,LPSTR pszPath,int csidl,WINBOOL fCreate);
  SHSTDAPI_(WINBOOL) SHGetSpecialFolderPathW(HWND hwnd,LPWSTR pszPath,int csidl,WINBOOL fCreate);

  typedef enum {
    SHGFP_TYPE_CURRENT = 0,SHGFP_TYPE_DEFAULT = 1
  } SHGFP_TYPE;

  SHFOLDERAPI SHGetFolderPathA(HWND hwnd,int csidl,HANDLE hToken,DWORD dwFlags,LPSTR pszPath);
  SHFOLDERAPI SHGetFolderPathW(HWND hwnd,int csidl,HANDLE hToken,DWORD dwFlags,LPWSTR pszPath);
  SHSTDAPI SHGetFolderLocation(HWND hwnd,int csidl,HANDLE hToken,DWORD dwFlags,LPITEMIDLIST *ppidl);
  SHFOLDERAPI SHGetFolderPathAndSubDirA(HWND hwnd,int csidl,HANDLE hToken,DWORD dwFlags,LPCSTR pszSubDir,LPSTR pszPath);
  SHFOLDERAPI SHGetFolderPathAndSubDirW(HWND hwnd,int csidl,HANDLE hToken,DWORD dwFlags,LPCWSTR pszSubDir,LPWSTR pszPath);

#define FCS_READ 0x00000001
#define FCS_FORCEWRITE 0x00000002
#define FCS_WRITE (FCS_READ | FCS_FORCEWRITE)
#define FCS_FLAG_DRAGDROP 2

#define FCSM_VIEWID 0x00000001
#define FCSM_WEBVIEWTEMPLATE 0x00000002
#define FCSM_INFOTIP 0x00000004
#define FCSM_CLSID 0x00000008
#define FCSM_ICONFILE 0x00000010
#define FCSM_LOGO 0x00000020
#define FCSM_FLAGS 0x00000040

#include <pshpack8.h>

  typedef struct {
    DWORD dwSize;
    DWORD dwMask;
    SHELLVIEWID *pvid;
    LPSTR pszWebViewTemplate;
    DWORD cchWebViewTemplate;
    LPSTR pszWebViewTemplateVersion;
    LPSTR pszInfoTip;
    DWORD cchInfoTip;
    CLSID *pclsid;
    DWORD dwFlags;
    LPSTR pszIconFile;
    DWORD cchIconFile;
    int iIconIndex;
    LPSTR pszLogo;
    DWORD cchLogo;
  } SHFOLDERCUSTOMSETTINGSA,*LPSHFOLDERCUSTOMSETTINGSA;

  typedef struct {
    DWORD dwSize;
    DWORD dwMask;
    SHELLVIEWID *pvid;
    LPWSTR pszWebViewTemplate;
    DWORD cchWebViewTemplate;
    LPWSTR pszWebViewTemplateVersion;
    LPWSTR pszInfoTip;
    DWORD cchInfoTip;
    CLSID *pclsid;
    DWORD dwFlags;
    LPWSTR pszIconFile;
    DWORD cchIconFile;
    int iIconIndex;
    LPWSTR pszLogo;
    DWORD cchLogo;
  } SHFOLDERCUSTOMSETTINGSW,*LPSHFOLDERCUSTOMSETTINGSW;

#include <poppack.h>

#define SHFOLDERCUSTOMSETTINGS __MINGW_NAME_AW(SHFOLDERCUSTOMSETTINGS)
#define SHGetSetFolderCustomSettings __MINGW_NAME_AW(SHGetSetFolderCustomSettings)
#define LPSHFOLDERCUSTOMSETTINGS __MINGW_NAME_AW(LPSHFOLDERCUSTOMSETTINGS)

  SHSTDAPI SHGetSetFolderCustomSettingsA(LPSHFOLDERCUSTOMSETTINGSA pfcs,LPCSTR pszPath,DWORD dwReadWrite);
  SHSTDAPI SHGetSetFolderCustomSettingsW(LPSHFOLDERCUSTOMSETTINGSW pfcs,LPCWSTR pszPath,DWORD dwReadWrite);

  typedef int (CALLBACK *BFFCALLBACK)(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData);

#include <pshpack8.h>

  typedef struct _browseinfoA {
    HWND hwndOwner;
    LPCITEMIDLIST pidlRoot;
    LPSTR pszDisplayName;
    LPCSTR lpszTitle;
    UINT ulFlags;
    BFFCALLBACK lpfn;
    LPARAM lParam;
    int iImage;
  } BROWSEINFOA,*PBROWSEINFOA,*LPBROWSEINFOA;

  typedef struct _browseinfoW {
    HWND hwndOwner;
    LPCITEMIDLIST pidlRoot;
    LPWSTR pszDisplayName;
    LPCWSTR lpszTitle;
    UINT ulFlags;
    BFFCALLBACK lpfn;
    LPARAM lParam;
    int iImage;
  } BROWSEINFOW,*PBROWSEINFOW,*LPBROWSEINFOW;

#include <poppack.h>

#define BROWSEINFO __MINGW_NAME_AW(BROWSEINFO)
#define PBROWSEINFO __MINGW_NAME_AW(PBROWSEINFO)
#define LPBROWSEINFO __MINGW_NAME_AW(LPBROWSEINFO)

#define BIF_RETURNONLYFSDIRS 0x0001
#define BIF_DONTGOBELOWDOMAIN 0x0002
#define BIF_STATUSTEXT 0x0004

#define BIF_RETURNFSANCESTORS 0x0008
#define BIF_EDITBOX 0x0010
#define BIF_VALIDATE 0x0020

#define BIF_NEWDIALOGSTYLE 0x0040

#define BIF_USENEWUI (BIF_NEWDIALOGSTYLE | BIF_EDITBOX)

#define BIF_BROWSEINCLUDEURLS 0x0080
#define BIF_UAHINT 0x0100
#define BIF_NONEWFOLDERBUTTON 0x0200
#define BIF_NOTRANSLATETARGETS 0x0400

#define BIF_BROWSEFORCOMPUTER 0x1000
#define BIF_BROWSEFORPRINTER 0x2000
#define BIF_BROWSEINCLUDEFILES 0x4000
#define BIF_SHAREABLE 0x8000

#define BFFM_INITIALIZED 1
#define BFFM_SELCHANGED 2
#define BFFM_VALIDATEFAILEDA 3
#define BFFM_VALIDATEFAILEDW 4
#define BFFM_IUNKNOWN 5

#define BFFM_SETSTATUSTEXTA (WM_USER + 100)
#define BFFM_ENABLEOK (WM_USER + 101)
#define BFFM_SETSELECTIONA (WM_USER + 102)
#define BFFM_SETSELECTIONW (WM_USER + 103)
#define BFFM_SETSTATUSTEXTW (WM_USER + 104)
#define BFFM_SETOKTEXT (WM_USER + 105)
#define BFFM_SETEXPANDED (WM_USER + 106)

  SHSTDAPI_(LPITEMIDLIST) SHBrowseForFolderA(LPBROWSEINFOA lpbi);
  SHSTDAPI_(LPITEMIDLIST) SHBrowseForFolderW(LPBROWSEINFOW lpbi);

#define SHBrowseForFolder __MINGW_NAME_AW(SHBrowseForFolder)
#define BFFM_SETSTATUSTEXT __MINGW_NAME_AW(BFFM_SETSTATUSTEXT)
#define BFFM_SETSELECTION __MINGW_NAME_AW(BFFM_SETSELECTION)
#define BFFM_VALIDATEFAILED __MINGW_NAME_AW(BFFM_VALIDATEFAILED)

  SHSTDAPI SHLoadInProc(REFCLSID rclsid);

  SHSTDAPI SHEnableServiceObject(REFCLSID rclsid,WINBOOL fEnable);

  enum {
    ISHCUTCMDID_DOWNLOADICON = 0,ISHCUTCMDID_INTSHORTCUTCREATE = 1
  };
#define CMDID_INTSHORTCUTCREATE ISHCUTCMDID_INTSHORTCUTCREATE

  SHSTDAPI SHGetDesktopFolder(IShellFolder **ppshf);

#define STR_FILE_SYS_BIND_DATA L"File System Bind Data"

#undef INTERFACE
#define INTERFACE IFileSystemBindData
  DECLARE_INTERFACE_(IFileSystemBindData,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(SetFindData)(THIS_ const WIN32_FIND_DATAW *pfd) PURE;
    STDMETHOD(GetFindData)(THIS_ WIN32_FIND_DATAW *pfd) PURE;
  };

#undef INTERFACE
#define INTERFACE IShellDetails
  DECLARE_INTERFACE_(IShellDetails,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetDetailsOf)(THIS_ LPCITEMIDLIST pidl,UINT iColumn,SHELLDETAILS *pDetails) PURE;
    STDMETHOD(ColumnClick)(THIS_ UINT iColumn) PURE;
  };

#undef INTERFACE
#define INTERFACE IObjMgr

  DECLARE_INTERFACE_(IObjMgr,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Append) (THIS_ IUnknown *punk) PURE;
    STDMETHOD(Remove) (THIS_ IUnknown *punk) PURE;
  };

#undef INTERFACE
#define INTERFACE ICurrentWorkingDirectory
  DECLARE_INTERFACE_(ICurrentWorkingDirectory,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetDirectory) (THIS_ LPWSTR pwzPath,DWORD cchSize) PURE;
    STDMETHOD(SetDirectory) (THIS_ LPCWSTR pwzPath) PURE;
  };

#undef INTERFACE
#define INTERFACE IACList
  DECLARE_INTERFACE_(IACList,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Expand) (THIS_ LPCOLESTR pszExpand) PURE;
  };

#undef INTERFACE
#define INTERFACE IACList2
  typedef enum _tagAUTOCOMPLETELISTOPTIONS {
    ACLO_NONE = 0,ACLO_CURRENTDIR = 1,ACLO_MYCOMPUTER = 2,ACLO_DESKTOP = 4,ACLO_FAVORITES = 8,ACLO_FILESYSONLY = 16,ACLO_FILESYSDIRS = 32
  } AUTOCOMPLETELISTOPTIONS;

  DECLARE_INTERFACE_(IACList2,IACList) {
    STDMETHOD(SetOptions)(THIS_ DWORD dwFlag) PURE;
    STDMETHOD(GetOptions)(THIS_ DWORD *pdwFlag) PURE;
  };

#define PROGDLG_NORMAL 0x00000000
#define PROGDLG_MODAL 0x00000001
#define PROGDLG_AUTOTIME 0x00000002
#define PROGDLG_NOTIME 0x00000004
#define PROGDLG_NOMINIMIZE 0x00000008
#define PROGDLG_NOPROGRESSBAR 0x00000010

#define PDTIMER_RESET 0x00000001

#undef INTERFACE
#define INTERFACE IProgressDialog
  DECLARE_INTERFACE_(IProgressDialog,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(StartProgressDialog)(THIS_ HWND hwndParent,IUnknown *punkEnableModless,DWORD dwFlags,LPCVOID pvResevered) PURE;
    STDMETHOD(StopProgressDialog)(THIS) PURE;
    STDMETHOD(SetTitle)(THIS_ LPCWSTR pwzTitle) PURE;
    STDMETHOD(SetAnimation)(THIS_ HINSTANCE hInstAnimation,UINT idAnimation) PURE;
    STDMETHOD_(WINBOOL,HasUserCancelled) (THIS) PURE;
    STDMETHOD(SetProgress)(THIS_ DWORD dwCompleted,DWORD dwTotal) PURE;
    STDMETHOD(SetProgress64)(THIS_ ULONGLONG ullCompleted,ULONGLONG ullTotal) PURE;
    STDMETHOD(SetLine)(THIS_ DWORD dwLineNum,LPCWSTR pwzString,WINBOOL fCompactPath,LPCVOID pvResevered) PURE;
    STDMETHOD(SetCancelMsg)(THIS_ LPCWSTR pwzCancelMsg,LPCVOID pvResevered) PURE;
    STDMETHOD(Timer)(THIS_ DWORD dwTimerAction,LPCVOID pvResevered) PURE;
  };

#undef INTERFACE
#define INTERFACE IInputObjectSite
  DECLARE_INTERFACE_(IInputObjectSite,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(OnFocusChangeIS)(THIS_ IUnknown *punkObj,WINBOOL fSetFocus) PURE;
  };

#undef INTERFACE
#define INTERFACE IInputObject
  DECLARE_INTERFACE_(IInputObject,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(UIActivateIO)(THIS_ WINBOOL fActivate,LPMSG lpMsg) PURE;
    STDMETHOD(HasFocusIO)(THIS) PURE;
    STDMETHOD(TranslateAcceleratorIO)(THIS_ LPMSG lpMsg) PURE;
  };

#undef INTERFACE
#define INTERFACE IDockingWindowSite
  DECLARE_INTERFACE_(IDockingWindowSite,IOleWindow) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetWindow) (THIS_ HWND *lphwnd) PURE;
    STDMETHOD(ContextSensitiveHelp) (THIS_ WINBOOL fEnterMode) PURE;
    STDMETHOD(GetBorderDW) (THIS_ IUnknown *punkObj,LPRECT prcBorder) PURE;
    STDMETHOD(RequestBorderSpaceDW) (THIS_ IUnknown *punkObj,LPCBORDERWIDTHS pbw) PURE;
    STDMETHOD(SetBorderSpaceDW) (THIS_ IUnknown *punkObj,LPCBORDERWIDTHS pbw) PURE;
  };

#define DWFRF_NORMAL 0x0000
#define DWFRF_DELETECONFIGDATA 0x0001

#define DWFAF_HIDDEN 0x0001

#undef INTERFACE
#define INTERFACE IDockingWindowFrame
  DECLARE_INTERFACE_(IDockingWindowFrame,IOleWindow) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetWindow) (THIS_ HWND *lphwnd) PURE;
    STDMETHOD(ContextSensitiveHelp) (THIS_ WINBOOL fEnterMode) PURE;
    STDMETHOD(AddToolbar) (THIS_ IUnknown *punkSrc,LPCWSTR pwszItem,DWORD dwAddFlags) PURE;
    STDMETHOD(RemoveToolbar) (THIS_ IUnknown *punkSrc,DWORD dwRemoveFlags) PURE;
    STDMETHOD(FindToolbar) (THIS_ LPCWSTR pwszItem,REFIID riid,void **ppv) PURE;
  };

#define IRTIR_TASK_NOT_RUNNING 0
#define IRTIR_TASK_RUNNING 1
#define IRTIR_TASK_SUSPENDED 2
#define IRTIR_TASK_PENDING 3
#define IRTIR_TASK_FINISHED 4

#undef INTERFACE
#define INTERFACE IRunnableTask

  DECLARE_INTERFACE_(IRunnableTask,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD (Run)(THIS) PURE;
    STDMETHOD (Kill)(THIS_ WINBOOL fWait) PURE;
    STDMETHOD (Suspend)(THIS) PURE;
    STDMETHOD (Resume)(THIS) PURE;
    STDMETHOD_(ULONG,IsRunning)(THIS) PURE;
  };

  typedef IRunnableTask *LPRUNNABLETASK;

#define TASKOWNERID GUID
#define REFTASKOWNERID REFGUID

#define ITSSFLAG_COMPLETE_ON_DESTROY 0x0000
#define ITSSFLAG_KILL_ON_DESTROY 0x0001
#define ITSSFLAG_SUPPORTS_TERMINATE 0x0002
#define ITSSFLAG_FLAGS_MASK 0x0003
#define ITSSFLAG_THREAD_TERMINATE_TIMEOUT 0x0010
#define ITSSFLAG_THREAD_POOL_TIMEOUT 0x0020
#define ITSS_THREAD_DESTROY_DEFAULT_TIMEOUT (60*1000)
#define ITSS_THREAD_TERMINATE_TIMEOUT (INFINITE)
#define ITSS_THREAD_TIMEOUT_NO_CHANGE (INFINITE - 1)

#define ITSAT_DEFAULT_LPARAM 0xffffffff
#define ITSAT_DEFAULT_PRIORITY 0x10000000
#define ITSAT_MAX_PRIORITY 0x7fffffff
#define ITSAT_MIN_PRIORITY 0x00000000

#define TOID_NULL CLSID_NULL

#undef INTERFACE
#define INTERFACE IShellTaskScheduler
  DECLARE_INTERFACE_(IShellTaskScheduler,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD (AddTask)(THIS_ IRunnableTask *pTask,REFTASKOWNERID rtoid,DWORD_PTR lParam,DWORD dwPriority) PURE;
    STDMETHOD (RemoveTasks)(THIS_ REFTASKOWNERID rtoid,DWORD_PTR lParam,WINBOOL fWaitIfRunning) PURE;
    STDMETHOD_(UINT,CountTasks)(THIS_ REFTASKOWNERID rtoid) PURE;
    STDMETHOD (Status)(THIS_ DWORD dwReleaseStatus,DWORD dwThreadTimeout) PURE;
  };

  typedef IShellTaskScheduler *LPSHELLTASKSCHEDULER;

#define ITSSFLAG_TASK_PLACEINFRONT 0x00000001
#define ITSSFLAG_TASK_PLACEINBACK 0x00000002

#undef INTERFACE
#define INTERFACE IShellTaskScheduler2
  DECLARE_INTERFACE_(IShellTaskScheduler2,IShellTaskScheduler) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD (AddTask)(THIS_ IRunnableTask *pTask,REFTASKOWNERID rtoid,DWORD_PTR lParam,DWORD dwPriority) PURE;
    STDMETHOD (RemoveTasks)(THIS_ REFTASKOWNERID rtoid,DWORD_PTR lParam,WINBOOL fWaitIfRunning) PURE;
    STDMETHOD_(UINT,CountTasks)(THIS_ REFTASKOWNERID rtoid) PURE;
    STDMETHOD (Status)(THIS_ DWORD dwReleaseStatus,DWORD dwThreadTimeout) PURE;
    STDMETHOD (AddTask2)(THIS_ IRunnableTask *pTask,REFTASKOWNERID rtoid,DWORD_PTR lParam,DWORD dwPriority,DWORD grfFlags) PURE;
    STDMETHOD (MoveTask)(THIS_ REFTASKOWNERID rtoid,DWORD_PTR lParam,DWORD dwPriority,DWORD grfFlags) PURE;
  };

#undef INTERFACE
#define INTERFACE IThumbnailCapture
  DECLARE_INTERFACE_ (IThumbnailCapture,IUnknown) {
    STDMETHOD (CaptureThumbnail) (THIS_ const SIZE *pMaxSize,IUnknown *pHTMLDoc2,HBITMAP *phbmThumbnail) PURE;
  };
  typedef IThumbnailCapture *LPTHUMBNAILCAPTURE;

#include <pshpack8.h>
  typedef struct _EnumImageStoreDATAtag {
    WCHAR szPath[MAX_PATH];
    FILETIME ftTimeStamp;
  } ENUMSHELLIMAGESTOREDATA,*PENUMSHELLIMAGESTOREDATA;

#include <poppack.h>

#undef INTERFACE
#define INTERFACE IEnumShellImageStore
  DECLARE_INTERFACE_(IEnumShellImageStore,IUnknown) {
    STDMETHOD (QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (Reset) (THIS) PURE;
    STDMETHOD (Next) (THIS_ ULONG celt,PENUMSHELLIMAGESTOREDATA *prgElt,ULONG *pceltFetched) PURE;
    STDMETHOD (Skip) (THIS_ ULONG celt) PURE;
    STDMETHOD (Clone) (THIS_ IEnumShellImageStore **ppEnum) PURE;
  };

  typedef IEnumShellImageStore *LPENUMSHELLIMAGESTORE;

#define SHIMSTCAPFLAG_LOCKABLE 0x0001
#define SHIMSTCAPFLAG_PURGEABLE 0x0002

#undef INTERFACE
#define INTERFACE IShellImageStore
  DECLARE_INTERFACE_(IShellImageStore,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (Open) (THIS_ DWORD dwMode,DWORD *pdwLock) PURE;
    STDMETHOD (Create) (THIS_ DWORD dwMode,DWORD *pdwLock) PURE;
    STDMETHOD (ReleaseLock) (THIS_ DWORD const *pdwLock) PURE;
    STDMETHOD (Close) (THIS_ DWORD const *pdwLock) PURE;
    STDMETHOD (Commit) (THIS_ DWORD const *pdwLock) PURE;
    STDMETHOD (IsLocked) (THIS) PURE;
    STDMETHOD (GetMode) (THIS_ DWORD *pdwMode) PURE;
    STDMETHOD (GetCapabilities) (THIS_ DWORD *pdwCapMask) PURE;
    STDMETHOD (AddEntry) (THIS_ LPCWSTR pszName,const FILETIME *pftTimeStamp,DWORD dwMode,HBITMAP hImage) PURE;
    STDMETHOD (GetEntry) (THIS_ LPCWSTR pszName,DWORD dwMode,HBITMAP *phImage) PURE;
    STDMETHOD (DeleteEntry) (THIS_ LPCWSTR pszName) PURE;
    STDMETHOD (IsEntryInStore) (THIS_ LPCWSTR pszName,FILETIME *pftTimeStamp) PURE;
    STDMETHOD (Enum) (THIS_ LPENUMSHELLIMAGESTORE *ppEnum) PURE;
  };

  typedef IShellImageStore *LPSHELLIMAGESTORE;

#define ISFB_MASK_STATE 0x00000001
#define ISFB_MASK_BKCOLOR 0x00000002
#define ISFB_MASK_VIEWMODE 0x00000004
#define ISFB_MASK_SHELLFOLDER 0x00000008
#define ISFB_MASK_IDLIST 0x00000010
#define ISFB_MASK_COLORS 0x00000020

#define ISFB_STATE_DEFAULT 0x00000000
#define ISFB_STATE_DEBOSSED 0x00000001
#define ISFB_STATE_ALLOWRENAME 0x00000002
#define ISFB_STATE_NOSHOWTEXT 0x00000004
#define ISFB_STATE_CHANNELBAR 0x00000010
#define ISFB_STATE_QLINKSMODE 0x00000020
#define ISFB_STATE_FULLOPEN 0x00000040
#define ISFB_STATE_NONAMESORT 0x00000080
#define ISFB_STATE_BTNMINSIZE 0x00000100

#define ISFBVIEWMODE_SMALLICONS 0x0001
#define ISFBVIEWMODE_LARGEICONS 0x0002
#define ISFBVIEWMODE_LOGOS 0x0003

#include <pshpack8.h>

  typedef struct {
    DWORD dwMask;
    DWORD dwStateMask;
    DWORD dwState;
    COLORREF crBkgnd;
    COLORREF crBtnLt;
    COLORREF crBtnDk;
    WORD wViewMode;
    WORD wAlign;
    IShellFolder *psf;
    LPITEMIDLIST pidl;
  } BANDINFOSFB,*PBANDINFOSFB;

#include <poppack.h>

#undef INTERFACE
#define INTERFACE IShellFolderBand
  DECLARE_INTERFACE_(IShellFolderBand,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(InitializeSFB)(THIS_ IShellFolder *psf,LPCITEMIDLIST pidl) PURE;
    STDMETHOD(SetBandInfoSFB)(THIS_ PBANDINFOSFB pbi) PURE;
    STDMETHOD(GetBandInfoSFB)(THIS_ PBANDINFOSFB pbi) PURE;
  };

  enum {
    SFBID_PIDLCHANGED,
  };

#undef INTERFACE
#define INTERFACE IDeskBarClient
  DECLARE_INTERFACE_(IDeskBarClient,IOleWindow) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetWindow) (THIS_ HWND *lphwnd) PURE;
    STDMETHOD(ContextSensitiveHelp) (THIS_ WINBOOL fEnterMode) PURE;
    STDMETHOD(SetDeskBarSite) (THIS_ IUnknown *punkSite) PURE;
    STDMETHOD(SetModeDBC) (THIS_ DWORD dwMode) PURE;
    STDMETHOD(UIActivateDBC) (THIS_ DWORD dwState) PURE;
    STDMETHOD(GetSize) (THIS_ DWORD dwWhich,LPRECT prc) PURE;
  };

#define DBC_GS_IDEAL 0
#define DBC_GS_SIZEDOWN 1

#define DBC_HIDE 0
#define DBC_SHOW 1
#define DBC_SHOWOBSCURE 2

  enum {
    DBCID_EMPTY = 0,DBCID_ONDRAG = 1,DBCID_CLSIDOFBAR = 2,DBCID_RESIZE = 3,DBCID_GETBAR = 4
  };

#ifdef _WININET_
  typedef struct _tagWALLPAPEROPT {
    DWORD dwSize;
    DWORD dwStyle;
  } WALLPAPEROPT;

  typedef WALLPAPEROPT *LPWALLPAPEROPT;
  typedef const WALLPAPEROPT *LPCWALLPAPEROPT;

  typedef struct _tagCOMPONENTSOPT {
    DWORD dwSize;
    WINBOOL fEnableComponents;
    WINBOOL fActiveDesktop;
  } COMPONENTSOPT;

  typedef COMPONENTSOPT *LPCOMPONENTSOPT;
  typedef const COMPONENTSOPT *LPCCOMPONENTSOPT;

  typedef struct _tagCOMPPOS {
    DWORD dwSize;
    int iLeft;
    int iTop;
    DWORD dwWidth;
    DWORD dwHeight;
    int izIndex;
    WINBOOL fCanResize;
    WINBOOL fCanResizeX;
    WINBOOL fCanResizeY;
    int iPreferredLeftPercent;
    int iPreferredTopPercent;
  } COMPPOS;

  typedef COMPPOS *LPCOMPPOS;
  typedef const COMPPOS *LPCCOMPPOS;

  typedef struct _tagCOMPSTATEINFO {
    DWORD dwSize;
    int iLeft;
    int iTop;
    DWORD dwWidth;
    DWORD dwHeight;
    DWORD dwItemState;
  } COMPSTATEINFO;

  typedef COMPSTATEINFO *LPCOMPSTATEINFO;
  typedef const COMPSTATEINFO *LPCCOMPSTATEINFO;

#define COMPONENT_TOP (0x3fffffff)

#define COMP_TYPE_HTMLDOC 0
#define COMP_TYPE_PICTURE 1
#define COMP_TYPE_WEBSITE 2
#define COMP_TYPE_CONTROL 3
#define COMP_TYPE_CFHTML 4
#define COMP_TYPE_MAX 4

  typedef struct _tagIE4COMPONENT {
    DWORD dwSize;
    DWORD dwID;
    int iComponentType;
    WINBOOL fChecked;
    WINBOOL fDirty;
    WINBOOL fNoScroll;
    COMPPOS cpPos;
    WCHAR wszFriendlyName[MAX_PATH];
    WCHAR wszSource[INTERNET_MAX_URL_LENGTH];
    WCHAR wszSubscribedURL[INTERNET_MAX_URL_LENGTH];
  } IE4COMPONENT;

  typedef IE4COMPONENT *LPIE4COMPONENT;
  typedef const IE4COMPONENT *LPCIE4COMPONENT;

  typedef struct _tagCOMPONENT {
    DWORD dwSize;
    DWORD dwID;
    int iComponentType;
    WINBOOL fChecked;
    WINBOOL fDirty;
    WINBOOL fNoScroll;
    COMPPOS cpPos;
    WCHAR wszFriendlyName[MAX_PATH];
    WCHAR wszSource[INTERNET_MAX_URL_LENGTH];
    WCHAR wszSubscribedURL[INTERNET_MAX_URL_LENGTH];
    DWORD dwCurItemState;
    COMPSTATEINFO csiOriginal;
    COMPSTATEINFO csiRestored;
  } COMPONENT;

  typedef COMPONENT *LPCOMPONENT;
  typedef const COMPONENT *LPCCOMPONENT;

#define IS_NORMAL 0x00000001
#define IS_FULLSCREEN 0x00000002
#define IS_SPLIT 0x00000004
#define IS_VALIDSIZESTATEBITS (IS_NORMAL | IS_SPLIT | IS_FULLSCREEN)
#define IS_VALIDSTATEBITS (IS_NORMAL | IS_SPLIT | IS_FULLSCREEN | 0x80000000 | 0x40000000)

#define AD_APPLY_SAVE 0x00000001
#define AD_APPLY_HTMLGEN 0x00000002
#define AD_APPLY_REFRESH 0x00000004
#define AD_APPLY_ALL (AD_APPLY_SAVE | AD_APPLY_HTMLGEN | AD_APPLY_REFRESH)
#define AD_APPLY_FORCE 0x00000008
#define AD_APPLY_BUFFERED_REFRESH 0x00000010
#define AD_APPLY_DYNAMICREFRESH 0x00000020

#define WPSTYLE_CENTER 0
#define WPSTYLE_TILE 1
#define WPSTYLE_STRETCH 2
#define WPSTYLE_MAX 3

#define COMP_ELEM_TYPE 0x00000001
#define COMP_ELEM_CHECKED 0x00000002
#define COMP_ELEM_DIRTY 0x00000004
#define COMP_ELEM_NOSCROLL 0x00000008
#define COMP_ELEM_POS_LEFT 0x00000010
#define COMP_ELEM_POS_TOP 0x00000020
#define COMP_ELEM_SIZE_WIDTH 0x00000040
#define COMP_ELEM_SIZE_HEIGHT 0x00000080
#define COMP_ELEM_POS_ZINDEX 0x00000100
#define COMP_ELEM_SOURCE 0x00000200
#define COMP_ELEM_FRIENDLYNAME 0x00000400
#define COMP_ELEM_SUBSCRIBEDURL 0x00000800
#define COMP_ELEM_ORIGINAL_CSI 0x00001000
#define COMP_ELEM_RESTORED_CSI 0x00002000
#define COMP_ELEM_CURITEMSTATE 0x00004000

#define COMP_ELEM_ALL (COMP_ELEM_TYPE | COMP_ELEM_CHECKED | COMP_ELEM_DIRTY | COMP_ELEM_NOSCROLL | COMP_ELEM_POS_LEFT | COMP_ELEM_SIZE_WIDTH | COMP_ELEM_SIZE_HEIGHT | COMP_ELEM_POS_ZINDEX | COMP_ELEM_SOURCE | COMP_ELEM_FRIENDLYNAME | COMP_ELEM_POS_TOP | COMP_ELEM_SUBSCRIBEDURL | COMP_ELEM_ORIGINAL_CSI | COMP_ELEM_RESTORED_CSI | COMP_ELEM_CURITEMSTATE)

  typedef enum tagDTI_ADTIWUI {
    DTI_ADDUI_DEFAULT = 0x00000000,DTI_ADDUI_DISPSUBWIZARD = 0x00000001,DTI_ADDUI_POSITIONITEM = 0x00000002
  };

#define ADDURL_SILENT 0X0001

#define COMPONENT_DEFAULT_LEFT (0xFFFF)
#define COMPONENT_DEFAULT_TOP (0xFFFF)

#undef INTERFACE
#define INTERFACE IActiveDesktop
  DECLARE_INTERFACE_(IActiveDesktop,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (ApplyChanges)(THIS_ DWORD dwFlags) PURE;
    STDMETHOD (GetWallpaper)(THIS_ LPWSTR pwszWallpaper,UINT cchWallpaper,DWORD dwReserved) PURE;
    STDMETHOD (SetWallpaper)(THIS_ LPCWSTR pwszWallpaper,DWORD dwReserved) PURE;
    STDMETHOD (GetWallpaperOptions)(THIS_ LPWALLPAPEROPT pwpo,DWORD dwReserved) PURE;
    STDMETHOD (SetWallpaperOptions)(THIS_ LPCWALLPAPEROPT pwpo,DWORD dwReserved) PURE;
    STDMETHOD (GetPattern)(THIS_ LPWSTR pwszPattern,UINT cchPattern,DWORD dwReserved) PURE;
    STDMETHOD (SetPattern)(THIS_ LPCWSTR pwszPattern,DWORD dwReserved) PURE;
    STDMETHOD (GetDesktopItemOptions)(THIS_ LPCOMPONENTSOPT pco,DWORD dwReserved) PURE;
    STDMETHOD (SetDesktopItemOptions)(THIS_ LPCCOMPONENTSOPT pco,DWORD dwReserved) PURE;
    STDMETHOD (AddDesktopItem)(THIS_ LPCCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (AddDesktopItemWithUI)(THIS_ HWND hwnd,LPCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (ModifyDesktopItem)(THIS_ LPCCOMPONENT pcomp,DWORD dwFlags) PURE;
    STDMETHOD (RemoveDesktopItem)(THIS_ LPCCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (GetDesktopItemCount)(THIS_ LPINT lpiCount,DWORD dwReserved) PURE;
    STDMETHOD (GetDesktopItem)(THIS_ int nComponent,LPCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (GetDesktopItemByID)(THIS_ ULONG_PTR dwID,LPCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (GenerateDesktopItemHtml)(THIS_ LPCWSTR pwszFileName,LPCOMPONENT pcomp,DWORD dwReserved) PURE;
    STDMETHOD (AddUrl)(THIS_ HWND hwnd,LPCWSTR pszSource,LPCOMPONENT pcomp,DWORD dwFlags) PURE;
    STDMETHOD (GetDesktopItemBySource)(THIS_ LPCWSTR pwszSource,LPCOMPONENT pcomp,DWORD dwReserved) PURE;
  };

  typedef IActiveDesktop *LPACTIVEDESKTOP;

#define SSM_CLEAR 0x0000
#define SSM_SET 0x0001
#define SSM_REFRESH 0x0002
#define SSM_UPDATE 0x0004

#define SCHEME_DISPLAY 0x0001
#define SCHEME_EDIT 0x0002
#define SCHEME_LOCAL 0x0004
#define SCHEME_GLOBAL 0x0008
#define SCHEME_REFRESH 0x0010
#define SCHEME_UPDATE 0x0020
#define SCHEME_DONOTUSE 0x0040
#define SCHEME_CREATE 0x0080

#undef INTERFACE
#define INTERFACE IActiveDesktopP

  DECLARE_INTERFACE_(IActiveDesktopP,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (SetSafeMode)(THIS_ DWORD dwFlags) PURE;
    STDMETHOD (EnsureUpdateHTML)(THIS) PURE;
    STDMETHOD (SetScheme)(THIS_ LPCWSTR pwszSchemeName,DWORD dwFlags) PURE;
    STDMETHOD (GetScheme)(THIS_ LPWSTR pwszSchemeName,DWORD *lpdwcchBuffer,DWORD dwFlags) PURE;
  };

  typedef IActiveDesktopP *LPACTIVEDESKTOPP;

#define GADOF_DIRTY 0x00000001

#undef INTERFACE
#define INTERFACE IADesktopP2

  DECLARE_INTERFACE_(IADesktopP2,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (ReReadWallpaper)(THIS) PURE;
    STDMETHOD (GetADObjectFlags)(THIS_ DWORD *lpdwFlags,DWORD dwMask) PURE;
    STDMETHOD (UpdateAllDesktopSubscriptions)(THIS) PURE;
    STDMETHOD (MakeDynamicChanges)(THIS_ IOleObject *pOleObj) PURE;
  };

  typedef IADesktopP2 *LPADESKTOPP2;
#endif

#define MAX_COLUMN_NAME_LEN 80
#define MAX_COLUMN_DESC_LEN 128

#include <pshpack1.h>

  typedef struct {
    SHCOLUMNID scid;
    VARTYPE vt;
    DWORD fmt;
    UINT cChars;
    DWORD csFlags;
    WCHAR wszTitle[MAX_COLUMN_NAME_LEN];
    WCHAR wszDescription[MAX_COLUMN_DESC_LEN];
  } SHCOLUMNINFO,*LPSHCOLUMNINFO;
  typedef const SHCOLUMNINFO *LPCSHCOLUMNINFO;

#include <poppack.h>

#include <pshpack8.h>

  typedef struct {
    ULONG dwFlags;
    ULONG dwReserved;
    WCHAR wszFolder[MAX_PATH];
  } SHCOLUMNINIT,*LPSHCOLUMNINIT;
  typedef const SHCOLUMNINIT *LPCSHCOLUMNINIT;

#define SHCDF_UPDATEITEM 0x00000001

  typedef struct {
    ULONG dwFlags;
    DWORD dwFileAttributes;
    ULONG dwReserved;
    WCHAR *pwszExt;
    WCHAR wszFile[MAX_PATH];
  } SHCOLUMNDATA,*LPSHCOLUMNDATA;
  typedef const SHCOLUMNDATA *LPCSHCOLUMNDATA;

#include <poppack.h>

#undef INTERFACE
#define INTERFACE IColumnProvider

  DECLARE_INTERFACE_(IColumnProvider,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD (Initialize)(THIS_ LPCSHCOLUMNINIT psci) PURE;
    STDMETHOD (GetColumnInfo)(THIS_ DWORD dwIndex,SHCOLUMNINFO *psci) PURE;
    STDMETHOD (GetItemData)(THIS_ LPCSHCOLUMNID pscid,LPCSHCOLUMNDATA pscd,VARIANT *pvarData) PURE;
  };

#include <pshpack8.h>

  typedef struct {
    SIZE sizeDragImage;
    POINT ptOffset;
    HBITMAP hbmpDragImage;
    COLORREF crColorKey;
  } SHDRAGIMAGE,*LPSHDRAGIMAGE;

#include <poppack.h>

#define DI_GETDRAGIMAGE TEXT("ShellGetDragImage")

#undef INTERFACE
#define INTERFACE IDropTargetHelper
  DECLARE_INTERFACE_(IDropTargetHelper,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (DragEnter)(THIS_ HWND hwndTarget,IDataObject *pDataObject,POINT *ppt,DWORD dwEffect) PURE;
    STDMETHOD (DragLeave)(THIS) PURE;
    STDMETHOD (DragOver)(THIS_ POINT *ppt,DWORD dwEffect) PURE;
    STDMETHOD (Drop)(THIS_ IDataObject *pDataObject,POINT *ppt,DWORD dwEffect) PURE;
    STDMETHOD (Show)(THIS_ WINBOOL fShow) PURE;
  };

#undef INTERFACE
#define INTERFACE IDragSourceHelper
  DECLARE_INTERFACE_(IDragSourceHelper,IUnknown) {
    STDMETHOD (QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD (InitializeFromBitmap)(THIS_ LPSHDRAGIMAGE pshdi,IDataObject *pDataObject) PURE;
    STDMETHOD (InitializeFromWindow)(THIS_ HWND hwnd,POINT *ppt,IDataObject *pDataObject) PURE;
  };

#define CFSTR_SHELLIDLIST TEXT("Shell IDList Array")
#define CFSTR_SHELLIDLISTOFFSET TEXT("Shell Object Offsets")
#define CFSTR_NETRESOURCES TEXT("Net Resource")
#define CFSTR_FILEDESCRIPTORA TEXT("FileGroupDescriptor")
#define CFSTR_FILEDESCRIPTORW TEXT("FileGroupDescriptorW")
#define CFSTR_FILECONTENTS TEXT("FileContents")
#define CFSTR_FILENAMEA TEXT("FileName")
#define CFSTR_FILENAMEW TEXT("FileNameW")
#define CFSTR_PRINTERGROUP TEXT("PrinterFriendlyName")
#define CFSTR_FILENAMEMAPA TEXT("FileNameMap")
#define CFSTR_FILENAMEMAPW TEXT("FileNameMapW")
#define CFSTR_SHELLURL TEXT("UniformResourceLocator")
#define CFSTR_INETURLA CFSTR_SHELLURL
#define CFSTR_INETURLW TEXT("UniformResourceLocatorW")
#define CFSTR_PREFERREDDROPEFFECT TEXT("Preferred DropEffect")
#define CFSTR_PERFORMEDDROPEFFECT TEXT("Performed DropEffect")
#define CFSTR_PASTESUCCEEDED TEXT("Paste Succeeded")
#define CFSTR_INDRAGLOOP TEXT("InShellDragLoop")
#define CFSTR_DRAGCONTEXT TEXT("DragContext")
#define CFSTR_MOUNTEDVOLUME TEXT("MountedVolume")
#define CFSTR_PERSISTEDDATAOBJECT TEXT("PersistedDataObject")
#define CFSTR_TARGETCLSID TEXT("TargetCLSID")
#define CFSTR_LOGICALPERFORMEDDROPEFFECT TEXT("Logical Performed DropEffect")
#define CFSTR_AUTOPLAY_SHELLIDLISTS TEXT("Autoplay Enumerated IDList Array")
#define CFSTR_UNTRUSTEDDRAGDROP TEXT("UntrustedDragDrop")

#define CFSTR_FILEDESCRIPTOR __MINGW_NAME_AW(CFSTR_FILEDESCRIPTOR)
#define CFSTR_FILENAME __MINGW_NAME_AW(CFSTR_FILENAME)
#define CFSTR_FILENAMEMAP __MINGW_NAME_AW(CFSTR_FILENAMEMAP)
#define CFSTR_INETURL __MINGW_NAME_AW(CFSTR_INETURL)

#define DVASPECT_SHORTNAME 2
#define DVASPECT_COPY 3
#define DVASPECT_LINK 4

#include <pshpack8.h>

  typedef struct _NRESARRAY {
    UINT cItems;
    NETRESOURCE nr[1];
  } NRESARRAY,*LPNRESARRAY;
#include <poppack.h>

  typedef struct _IDA {
    UINT cidl;
    UINT aoffset[1];
  } CIDA,*LPIDA;

  typedef enum {
    FD_CLSID = 0x0001,FD_SIZEPOINT = 0x0002,FD_ATTRIBUTES = 0x0004,FD_CREATETIME = 0x0008,FD_ACCESSTIME = 0x0010,FD_WRITESTIME = 0x0020,
    FD_FILESIZE = 0x0040,FD_PROGRESSUI = 0x4000,FD_LINKUI = 0x8000
  } FD_FLAGS;

  typedef struct _FILEDESCRIPTORA {
    DWORD dwFlags;

    CLSID clsid;
    SIZEL sizel;
    POINTL pointl;
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    CHAR cFileName[MAX_PATH ];
  } FILEDESCRIPTORA,*LPFILEDESCRIPTORA;

  typedef struct _FILEDESCRIPTORW {
    DWORD dwFlags;
    CLSID clsid;
    SIZEL sizel;
    POINTL pointl;
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    WCHAR cFileName[MAX_PATH ];
  } FILEDESCRIPTORW,*LPFILEDESCRIPTORW;

#define FILEDESCRIPTOR __MINGW_NAME_AW(FILEDESCRIPTOR)
#define LPFILEDESCRIPTOR __MINGW_NAME_AW(LPFILEDESCRIPTOR)

  typedef struct _FILEGROUPDESCRIPTORA {
    UINT cItems;
    FILEDESCRIPTORA fgd[1];
  } FILEGROUPDESCRIPTORA,*LPFILEGROUPDESCRIPTORA;

  typedef struct _FILEGROUPDESCRIPTORW {
    UINT cItems;
    FILEDESCRIPTORW fgd[1];
  } FILEGROUPDESCRIPTORW,*LPFILEGROUPDESCRIPTORW;

#define FILEGROUPDESCRIPTOR __MINGW_NAME_AW(FILEGROUPDESCRIPTOR)
#define LPFILEGROUPDESCRIPTOR __MINGW_NAME_AW(LPFILEGROUPDESCRIPTOR)

  typedef struct _DROPFILES {
    DWORD pFiles;
    POINT pt;
    WINBOOL fNC;
    WINBOOL fWide;
  } DROPFILES,*LPDROPFILES;

  typedef struct _SHChangeNotifyEntry {
    LPCITEMIDLIST pidl;
    WINBOOL fRecursive;
  } SHChangeNotifyEntry;

#define SHCNE_RENAMEITEM 0x00000001L
#define SHCNE_CREATE 0x00000002L
#define SHCNE_DELETE 0x00000004L
#define SHCNE_MKDIR 0x00000008L
#define SHCNE_RMDIR 0x00000010L
#define SHCNE_MEDIAINSERTED 0x00000020L
#define SHCNE_MEDIAREMOVED 0x00000040L
#define SHCNE_DRIVEREMOVED 0x00000080L
#define SHCNE_DRIVEADD 0x00000100L
#define SHCNE_NETSHARE 0x00000200L
#define SHCNE_NETUNSHARE 0x00000400L
#define SHCNE_ATTRIBUTES 0x00000800L
#define SHCNE_UPDATEDIR 0x00001000L
#define SHCNE_UPDATEITEM 0x00002000L
#define SHCNE_SERVERDISCONNECT 0x00004000L
#define SHCNE_UPDATEIMAGE 0x00008000L
#define SHCNE_DRIVEADDGUI 0x00010000L
#define SHCNE_RENAMEFOLDER 0x00020000L
#define SHCNE_FREESPACE 0x00040000L
#define SHCNE_EXTENDED_EVENT 0x04000000L

#define SHCNE_ASSOCCHANGED 0x08000000L

#define SHCNE_DISKEVENTS 0x0002381FL
#define SHCNE_GLOBALEVENTS 0x0C0581E0L
#define SHCNE_ALLEVENTS 0x7FFFFFFFL
#define SHCNE_INTERRUPT 0x80000000L

#define SHCNEE_ORDERCHANGED 2L
#define SHCNEE_MSI_CHANGE 4L
#define SHCNEE_MSI_UNINSTALL 5L

#define SHCNF_IDLIST 0x0000
#define SHCNF_PATHA 0x0001
#define SHCNF_PRINTERA 0x0002
#define SHCNF_DWORD 0x0003
#define SHCNF_PATHW 0x0005
#define SHCNF_PRINTERW 0x0006
#define SHCNF_TYPE 0x00FF
#define SHCNF_FLUSH 0x1000
#define SHCNF_FLUSHNOWAIT 0x2000

#define SHCNF_PATH __MINGW_NAME_AW(SHCNF_PATH)
#define SHCNF_PRINTER __MINGW_NAME_AW(SHCNF_PRINTER)

  SHSTDAPI_(void) SHChangeNotify(LONG wEventId,UINT uFlags,LPCVOID dwItem1,LPCVOID dwItem2);

#undef INTERFACE
#define INTERFACE IShellChangeNotify
  DECLARE_INTERFACE_(IShellChangeNotify,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(OnChange) (THIS_ LONG lEvent,LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2) PURE;
  };

#undef INTERFACE
#define INTERFACE IQueryInfo
  DECLARE_INTERFACE_(IQueryInfo,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetInfoTip)(THIS_ DWORD dwFlags,WCHAR **ppwszTip) PURE;
    STDMETHOD(GetInfoFlags)(THIS_ DWORD *pdwFlags) PURE;
  };

#define QITIPF_DEFAULT 0x00000000
#define QITIPF_USENAME 0x00000001
#define QITIPF_LINKNOTARGET 0x00000002
#define QITIPF_LINKUSETARGET 0x00000004
#define QITIPF_USESLOWTIP 0x00000008

#define QIF_CACHED 0x00000001
#define QIF_DONTEXPANDFOLDER 0x00000002

  typedef enum enum_SHARD{
    SHARD_PIDL = 0x00000001,
    SHARD_PATHA = 0x00000002,
    SHARD_PATHW = 0x00000003,
    SHARD_APPIDINFO = 0x00000004,
    SHARD_APPIDINFOIDLIST = 0x00000005,
    SHARD_LINK = 0x00000006,
    SHARD_APPIDINFOLINK = 0x00000007,
    SHARD_SHELLITEM = 0x00000008
  } SHARD;

#define SHARD_PATH __MINGW_NAME_AW(SHARD_PATH)

  SHSTDAPI_(void) SHAddToRecentDocs(UINT uFlags,LPCVOID pv);

  typedef struct _SHChangeDWORDAsIDList {
    USHORT cb;
    DWORD dwItem1;
    DWORD dwItem2;
    USHORT cbZero;
  } SHChangeDWORDAsIDList,*LPSHChangeDWORDAsIDList;

  typedef struct _SHChangeUpdateImageIDList {
    USHORT cb;
    int iIconIndex;
    int iCurIndex;
    UINT uFlags;
    DWORD dwProcessID;
    WCHAR szName[MAX_PATH];
    USHORT cbZero;
  } SHChangeUpdateImageIDList,*LPSHChangeUpdateImageIDList;

  SHSTDAPI_(int) SHHandleUpdateImage(LPCITEMIDLIST pidlExtra);

  typedef struct _SHChangeProductKeyAsIDList {
    USHORT cb;
    WCHAR wszProductKey[39];
    USHORT cbZero;
  } SHChangeProductKeyAsIDList,*LPSHChangeProductKeyAsIDList;

#define SHUpdateImage __MINGW_NAME_AW(SHUpdateImage)

  SHSTDAPI_(void) SHUpdateImageA(LPCSTR pszHashItem,int iIndex,UINT uFlags,int iImageIndex);
  SHSTDAPI_(void) SHUpdateImageW(LPCWSTR pszHashItem,int iIndex,UINT uFlags,int iImageIndex);
  SHSTDAPI_(ULONG) SHChangeNotifyRegister(HWND hwnd,int fSources,LONG fEvents,UINT wMsg,int cEntries,SHChangeNotifyEntry *pshcne);
  SHSTDAPI_(WINBOOL) SHChangeNotifyDeregister(unsigned long ulID);
  SHSTDAPI_(HANDLE) SHChangeNotification_Lock(HANDLE hChangeNotification,DWORD dwProcessId,LPITEMIDLIST **pppidl,LONG *plEvent);
  SHSTDAPI_(WINBOOL) SHChangeNotification_Unlock(HANDLE hLock);
  SHSTDAPI SHGetRealIDL(IShellFolder *psf,LPCITEMIDLIST pidlSimple,LPITEMIDLIST *ppidlReal);
  SHSTDAPI SHGetInstanceExplorer(IUnknown **ppunk);

#define SHGDFIL_FINDDATA 1
#define SHGDFIL_NETRESOURCE 2
#define SHGDFIL_DESCRIPTIONID 3

#define SHDID_ROOT_REGITEM 1
#define SHDID_FS_FILE 2
#define SHDID_FS_DIRECTORY 3
#define SHDID_FS_OTHER 4
#define SHDID_COMPUTER_DRIVE35 5
#define SHDID_COMPUTER_DRIVE525 6
#define SHDID_COMPUTER_REMOVABLE 7
#define SHDID_COMPUTER_FIXED 8
#define SHDID_COMPUTER_NETDRIVE 9
#define SHDID_COMPUTER_CDROM 10
#define SHDID_COMPUTER_RAMDISK 11
#define SHDID_COMPUTER_OTHER 12
#define SHDID_NET_DOMAIN 13
#define SHDID_NET_SERVER 14
#define SHDID_NET_SHARE 15
#define SHDID_NET_RESTOFNET 16
#define SHDID_NET_OTHER 17
#define SHDID_COMPUTER_IMAGING 18
#define SHDID_COMPUTER_AUDIO 19
#define SHDID_COMPUTER_SHAREDDOCS 20

#include <pshpack8.h>

  typedef struct _SHDESCRIPTIONID {
    DWORD dwDescriptionId;
    CLSID clsid;
  } SHDESCRIPTIONID,*LPSHDESCRIPTIONID;

#include <poppack.h>

#define SHGetDataFromIDList __MINGW_NAME_AW(SHGetDataFromIDList)

  SHSTDAPI SHGetDataFromIDListA(IShellFolder *psf,LPCITEMIDLIST pidl,int nFormat,void *pv,int cb);
  SHSTDAPI SHGetDataFromIDListW(IShellFolder *psf,LPCITEMIDLIST pidl,int nFormat,void *pv,int cb);

#define PRF_VERIFYEXISTS 0x0001
#define PRF_TRYPROGRAMEXTENSIONS (0x0002 | PRF_VERIFYEXISTS)
#define PRF_FIRSTDIRDEF 0x0004
#define PRF_DONTFINDLNK 0x0008
  SHSTDAPI_(int) RestartDialog(HWND hwnd,LPCWSTR lpPrompt,DWORD dwReturn);
  SHSTDAPI_(int) RestartDialogEx(HWND hwnd,LPCWSTR lpPrompt,DWORD dwReturn,DWORD dwReasonCode);
  SHSTDAPI SHCoCreateInstance(LPCWSTR pszCLSID,const CLSID *pclsid,IUnknown *pUnkOuter,REFIID riid,void **ppv);
  DECLARE_HANDLE(FARPROC16);
  SHSTDAPI_(LRESULT) CallCPLEntry16(HINSTANCE hinst,FARPROC16 lpfnEntry,HWND hwndCPL,UINT msg,LPARAM lParam1,LPARAM lParam2);
  SHSTDAPI SHCreateStdEnumFmtEtc(UINT cfmt,const FORMATETC afmt[],IEnumFORMATETC **ppenumFormatEtc);
  SHSTDAPI SHDoDragDrop(HWND hwnd,IDataObject *pdata,IDropSource *pdsrc,DWORD dwEffect,DWORD *pdwEffect);

#define NUM_POINTS 3
  typedef struct {
    int iNextSample;
    DWORD dwLastScroll;
    WINBOOL bFull;
    POINT pts[NUM_POINTS];
    DWORD dwTimes[NUM_POINTS];
  } AUTO_SCROLL_DATA;

  SHSTDAPI_(WINBOOL) DAD_SetDragImage(HIMAGELIST him,POINT *pptOffset);
  SHSTDAPI_(WINBOOL) DAD_DragEnterEx(HWND hwndTarget,const POINT ptStart);
  SHSTDAPI_(WINBOOL) DAD_DragEnterEx2(HWND hwndTarget,const POINT ptStart,IDataObject *pdtObject);
  SHSTDAPI_(WINBOOL) DAD_ShowDragImage(WINBOOL fShow);
  SHSTDAPI_(WINBOOL) DAD_DragMove(POINT pt);
  SHSTDAPI_(WINBOOL) DAD_DragLeave(void);
  SHSTDAPI_(WINBOOL) DAD_AutoScroll(HWND hwnd,AUTO_SCROLL_DATA *pad,const POINT *pptNow);

  typedef struct {
    WORD cLength;
    WORD nVersion;
    WINBOOL fFullPathTitle : 1;
    WINBOOL fSaveLocalView : 1;
    WINBOOL fNotShell : 1;
    WINBOOL fSimpleDefault : 1;
    WINBOOL fDontShowDescBar : 1;
    WINBOOL fNewWindowMode : 1;
    WINBOOL fShowCompColor : 1;
    WINBOOL fDontPrettyNames : 1;
    WINBOOL fAdminsCreateCommonGroups : 1;
    UINT fUnusedFlags : 7;
    UINT fMenuEnumFilter;
  } CABINETSTATE,*LPCABINETSTATE;

#define CABINETSTATE_VERSION 2

#define PathIsSlow __MINGW_NAME_AW(PathIsSlow)

  SHSTDAPI_(WINBOOL) ReadCabinetState(LPCABINETSTATE lpState,int iSize);
  SHSTDAPI_(WINBOOL) WriteCabinetState(LPCABINETSTATE lpState);
  SHSTDAPI_(WINBOOL) PathMakeUniqueName(LPWSTR pszUniqueName,UINT cchMax,LPCWSTR pszTemplate,LPCWSTR pszLongPlate,LPCWSTR pszDir);
  SHSTDAPI_(void) PathQualify(LPWSTR psz);
  SHSTDAPI_(WINBOOL) PathIsExe(LPCWSTR pszPath);
  SHSTDAPI_(WINBOOL) PathIsSlowA(LPCSTR pszFile,DWORD dwAttr);
  SHSTDAPI_(WINBOOL) PathIsSlowW(LPCWSTR pszFile,DWORD dwAttr);

#define PCS_FATAL 0x80000000
#define PCS_REPLACEDCHAR 0x00000001
#define PCS_REMOVEDCHAR 0x00000002
#define PCS_TRUNCATED 0x00000004
#define PCS_PATHTOOLONG 0x00000008

  SHSTDAPI_(int) PathCleanupSpec(LPCWSTR pszDir,LPWSTR pszSpec);
  SHSTDAPI_(int) PathResolve(LPWSTR pszPath,LPCWSTR dirs[],UINT fFlags);
  SHSTDAPI_(WINBOOL) GetFileNameFromBrowse(HWND hwnd,LPWSTR pszFilePath,UINT cbFilePath,LPCWSTR pszWorkingDir,LPCWSTR pszDefExt,LPCWSTR pszFilters,LPCWSTR pszTitle);
  SHSTDAPI_(int) DriveType(int iDrive);
  SHSTDAPI_(int) RealDriveType(int iDrive,WINBOOL fOKToHitNet);
  SHSTDAPI_(int) IsNetDrive(int iDrive);

#define MM_ADDSEPARATOR 0x00000001L
#define MM_SUBMENUSHAVEIDS 0x00000002L
#define MM_DONTREMOVESEPS 0x00000004L

  SHSTDAPI_(UINT) Shell_MergeMenus(HMENU hmDst,HMENU hmSrc,UINT uInsert,UINT uIDAdjust,UINT uIDAdjustMax,ULONG uFlags);
  SHSTDAPI_(WINBOOL) SHObjectProperties(HWND hwnd,DWORD dwType,LPCWSTR lpObject,LPCWSTR lpPage);

#define SHOP_PRINTERNAME 0x00000001
#define SHOP_FILEPATH 0x00000002
#define SHOP_VOLUMEGUID 0x00000004

  SHSTDAPI_(DWORD) SHFormatDrive(HWND hwnd,UINT drive,UINT fmtID,UINT options);

#define SHFMT_ID_DEFAULT 0xFFFF

#define SHFMT_OPT_FULL 0x0001
#define SHFMT_OPT_SYSONLY 0x0002

#define SHFMT_ERROR 0xFFFFFFFFL
#define SHFMT_CANCEL 0xFFFFFFFEL
#define SHFMT_NOFORMAT 0xFFFFFFFDL

#ifndef HPSXA_DEFINED
#define HPSXA_DEFINED
  DECLARE_HANDLE(HPSXA);
#endif
  WINSHELLAPI HPSXA WINAPI SHCreatePropSheetExtArray(HKEY hKey,LPCWSTR pszSubKey,UINT max_iface);
  WINSHELLAPI void WINAPI SHDestroyPropSheetExtArray(HPSXA hpsxa);
  WINSHELLAPI UINT WINAPI SHAddFromPropSheetExtArray(HPSXA hpsxa,LPFNADDPROPSHEETPAGE lpfnAddPage,LPARAM lParam);
  WINSHELLAPI UINT WINAPI SHReplaceFromPropSheetExtArray(HPSXA hpsxa,UINT uPageID,LPFNADDPROPSHEETPAGE lpfnReplaceWith,LPARAM lParam);
  SHSTDAPI_(LPITEMIDLIST) ILClone(LPCITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) ILGetNext(LPCITEMIDLIST pidl);
  SHSTDAPI_(UINT) ILGetSize(LPCITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) ILFindLastID(LPCITEMIDLIST pidl);
  SHSTDAPI_(WINBOOL) ILRemoveLastID(LPITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) ILAppendID(LPITEMIDLIST pidl,LPCSHITEMID pmkid,WINBOOL fAppend);
  SHSTDAPI_(void) ILFree(LPITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) ILCloneFirst(LPCITEMIDLIST pidl);
  SHSTDAPI_(WINBOOL) ILIsEqual(LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
  SHSTDAPI_(WINBOOL) ILIsParent(LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2,WINBOOL fImmediate);
  SHSTDAPI_(LPITEMIDLIST) ILFindChild(LPCITEMIDLIST pidlParent,LPCITEMIDLIST pidlChild);
  SHSTDAPI_(LPITEMIDLIST) ILCombine(LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
  SHSTDAPI ILLoadFromStream(IStream *pstm,LPITEMIDLIST *pidl);
  SHSTDAPI ILSaveToStream(IStream *pstm,LPCITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) ILCreateFromPathA(LPCSTR pszPath);
  SHSTDAPI_(LPITEMIDLIST) ILCreateFromPathW(LPCWSTR pszPath);

#ifdef NO_WRAPPERS_FOR_ILCREATEFROMPATH
  SHSTDAPI_(LPITEMIDLIST) ILCreateFromPath(LPCTSTR pszPath);
#else
#define ILCreateFromPath __MINGW_NAME_AW(ILCreateFromPath)
#endif
  SHSTDAPI SHILCreateFromPath(LPCWSTR szPath,LPITEMIDLIST *ppidl,DWORD *rgfInOut);

#undef INTERFACE
#define INTERFACE IDefViewFrame
  DECLARE_INTERFACE_(IDefViewFrame,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetWindowLV) (THIS_ HWND *phwnd) PURE;
    STDMETHOD(ReleaseWindowLV) (THIS) PURE;
    STDMETHOD(GetShellFolder)(THIS_ IShellFolder **ppsf) PURE;
  };

  typedef enum RESTRICTIONS {
    REST_NONE = 0x00000000,REST_NORUN = 0x00000001,REST_NOCLOSE = 0x00000002,REST_NOSAVESET = 0x00000004,REST_NOFILEMENU = 0x00000008,
    REST_NOSETFOLDERS = 0x00000010,REST_NOSETTASKBAR = 0x00000020,REST_NODESKTOP = 0x00000040,REST_NOFIND = 0x00000080,
    REST_NODRIVES = 0x00000100,REST_NODRIVEAUTORUN = 0x00000200,REST_NODRIVETYPEAUTORUN = 0x00000400,REST_NONETHOOD = 0x00000800,
    REST_STARTBANNER = 0x00001000,REST_RESTRICTRUN = 0x00002000,REST_NOPRINTERTABS = 0x00004000,REST_NOPRINTERDELETE = 0x00008000,
    REST_NOPRINTERADD = 0x00010000,REST_NOSTARTMENUSUBFOLDERS = 0x00020000,REST_MYDOCSONNET = 0x00040000,REST_NOEXITTODOS = 0x00080000,
    REST_ENFORCESHELLEXTSECURITY = 0x00100000,REST_LINKRESOLVEIGNORELINKINFO = 0x00200000,REST_NOCOMMONGROUPS = 0x00400000,
    REST_SEPARATEDESKTOPPROCESS = 0x00800000,REST_NOWEB = 0x01000000,REST_NOTRAYCONTEXTMENU = 0x02000000,REST_NOVIEWCONTEXTMENU = 0x04000000,
    REST_NONETCONNECTDISCONNECT = 0x08000000,REST_STARTMENULOGOFF = 0x10000000,REST_NOSETTINGSASSIST = 0x20000000,REST_NOINTERNETICON = 0x40000001,
    REST_NORECENTDOCSHISTORY = 0x40000002,REST_NORECENTDOCSMENU = 0x40000003,REST_NOACTIVEDESKTOP = 0x40000004,REST_NOACTIVEDESKTOPCHANGES = 0x40000005,
    REST_NOFAVORITESMENU = 0x40000006,REST_CLEARRECENTDOCSONEXIT = 0x40000007,REST_CLASSICSHELL = 0x40000008,REST_NOCUSTOMIZEWEBVIEW = 0x40000009,
    REST_NOHTMLWALLPAPER = 0x40000010,REST_NOCHANGINGWALLPAPER = 0x40000011,REST_NODESKCOMP = 0x40000012,REST_NOADDDESKCOMP = 0x40000013,
    REST_NODELDESKCOMP = 0x40000014,REST_NOCLOSEDESKCOMP = 0x40000015,REST_NOCLOSE_DRAGDROPBAND = 0x40000016,REST_NOMOVINGBAND = 0x40000017,
    REST_NOEDITDESKCOMP = 0x40000018,REST_NORESOLVESEARCH = 0x40000019,REST_NORESOLVETRACK = 0x4000001A,REST_FORCECOPYACLWITHFILE = 0X4000001B,
    REST_NOLOGO3CHANNELNOTIFY = 0x4000001C,REST_NOFORGETSOFTWAREUPDATE = 0x4000001D,REST_NOSETACTIVEDESKTOP = 0x4000001E,
    REST_NOUPDATEWINDOWS = 0x4000001F,REST_NOCHANGESTARMENU = 0x40000020,REST_NOFOLDEROPTIONS = 0x40000021,REST_HASFINDCOMPUTERS = 0x40000022,
    REST_INTELLIMENUS = 0x40000023,REST_RUNDLGMEMCHECKBOX = 0x40000024,REST_ARP_ShowPostSetup = 0x40000025,REST_NOCSC = 0x40000026,
    REST_NOCONTROLPANEL = 0x40000027,REST_ENUMWORKGROUP = 0x40000028,REST_ARP_NOARP = 0x40000029,REST_ARP_NOREMOVEPAGE = 0x4000002A,
    REST_ARP_NOADDPAGE = 0x4000002B,REST_ARP_NOWINSETUPPAGE = 0x4000002C,REST_GREYMSIADS = 0x4000002D,REST_NOCHANGEMAPPEDDRIVELABEL = 0x4000002E,
    REST_NOCHANGEMAPPEDDRIVECOMMENT = 0x4000002F,REST_MaxRecentDocs = 0x40000030,REST_NONETWORKCONNECTIONS = 0x40000031,
    REST_FORCESTARTMENULOGOFF = 0x40000032,REST_NOWEBVIEW = 0x40000033,REST_NOCUSTOMIZETHISFOLDER = 0x40000034,REST_NOENCRYPTION = 0x40000035,
    REST_DONTSHOWSUPERHIDDEN = 0x40000037,REST_NOSHELLSEARCHBUTTON = 0x40000038,REST_NOHARDWARETAB = 0x40000039,REST_NORUNASINSTALLPROMPT = 0x4000003A,
    REST_PROMPTRUNASINSTALLNETPATH = 0x4000003B,REST_NOMANAGEMYCOMPUTERVERB = 0x4000003C,REST_NORECENTDOCSNETHOOD = 0x4000003D,
    REST_DISALLOWRUN = 0x4000003E,REST_NOWELCOMESCREEN = 0x4000003F,REST_RESTRICTCPL = 0x40000040,REST_DISALLOWCPL = 0x40000041,
    REST_NOSMBALLOONTIP = 0x40000042,REST_NOSMHELP = 0x40000043,REST_NOWINKEYS = 0x40000044,REST_NOENCRYPTONMOVE = 0x40000045,
    REST_NOLOCALMACHINERUN = 0x40000046,REST_NOCURRENTUSERRUN = 0x40000047,REST_NOLOCALMACHINERUNONCE = 0x40000048,
    REST_NOCURRENTUSERRUNONCE = 0x40000049,REST_FORCEACTIVEDESKTOPON = 0x4000004A,REST_NOCOMPUTERSNEARME = 0x4000004B,REST_NOVIEWONDRIVE = 0x4000004C,
    REST_NONETCRAWL = 0x4000004D,REST_NOSHAREDDOCUMENTS = 0x4000004E,REST_NOSMMYDOCS = 0x4000004F,REST_NOSMMYPICS = 0x40000050,
    REST_ALLOWBITBUCKDRIVES = 0x40000051,REST_NONLEGACYSHELLMODE = 0x40000052,REST_NOCONTROLPANELBARRICADE = 0x40000053,REST_NOSTARTPAGE = 0x40000054,
    REST_NOAUTOTRAYNOTIFY = 0x40000055,REST_NOTASKGROUPING = 0x40000056,REST_NOCDBURNING = 0x40000057,REST_MYCOMPNOPROP = 0x40000058,
    REST_MYDOCSNOPROP = 0x40000059,REST_NOSTARTPANEL = 0x4000005A,REST_NODISPLAYAPPEARANCEPAGE = 0x4000005B,REST_NOTHEMESTAB = 0x4000005C,
    REST_NOVISUALSTYLECHOICE = 0x4000005D,REST_NOSIZECHOICE = 0x4000005E,REST_NOCOLORCHOICE = 0x4000005F,REST_SETVISUALSTYLE = 0x40000060,
    REST_STARTRUNNOHOMEPATH = 0x40000061,REST_NOUSERNAMEINSTARTPANEL = 0x40000062,REST_NOMYCOMPUTERICON = 0x40000063,REST_NOSMNETWORKPLACES = 0x40000064,
    REST_NOSMPINNEDLIST = 0x40000065,REST_NOSMMYMUSIC = 0x40000066,REST_NOSMEJECTPC = 0x40000067,REST_NOSMMOREPROGRAMS = 0x40000068,
    REST_NOSMMFUPROGRAMS = 0x40000069,REST_NOTRAYITEMSDISPLAY = 0x4000006A,REST_NOTOOLBARSONTASKBAR = 0x4000006B,REST_NOSMCONFIGUREPROGRAMS = 0x4000006F,
    REST_HIDECLOCK = 0x40000070,REST_NOLOWDISKSPACECHECKS = 0x40000071,REST_NOENTIRENETWORK = 0x40000072,REST_NODESKTOPCLEANUP = 0x40000073,
    REST_BITBUCKNUKEONDELETE = 0x40000074,REST_BITBUCKCONFIRMDELETE = 0x40000075,REST_BITBUCKNOPROP = 0x40000076,REST_NODISPBACKGROUND = 0x40000077,
    REST_NODISPSCREENSAVEPG = 0x40000078,REST_NODISPSETTINGSPG = 0x40000079,REST_NODISPSCREENSAVEPREVIEW = 0x4000007A,REST_NODISPLAYCPL = 0x4000007B,
    REST_HIDERUNASVERB = 0x4000007C,REST_NOTHUMBNAILCACHE = 0x4000007D,REST_NOSTRCMPLOGICAL = 0x4000007E,REST_NOPUBLISHWIZARD = 0x4000007F,
    REST_NOONLINEPRINTSWIZARD = 0x40000080,REST_NOWEBSERVICES = 0x40000081,REST_ALLOWUNHASHEDWEBVIEW = 0x40000082,REST_ALLOWLEGACYWEBVIEW = 0x40000083,
    REST_REVERTWEBVIEWSECURITY = 0x40000084,REST_INHERITCONSOLEHANDLES = 0x40000086,REST_SORTMAXITEMCOUNT = 0x40000087,
    REST_NOREMOTERECURSIVEEVENTS = 0x40000089,REST_NOREMOTECHANGENOTIFY = 0x40000091,REST_NOSIMPLENETIDLIST = 0x40000092,
    REST_NOENUMENTIRENETWORK = 0x40000093,REST_NODETAILSTHUMBNAILONNETWORK= 0x40000094,REST_NOINTERNETOPENWITH = 0x40000095,
    REST_ALLOWLEGACYLMZBEHAVIOR = 0x4000009A,REST_DONTRETRYBADNETNAME = 0x4000009B,REST_ALLOWFILECLSIDJUNCTIONS = 0x4000009C,
    REST_NOUPNPINSTALL = 0x4000009D,REST_NODISCONNECT = 0x41000001,REST_NOSECURITY = 0x41000002,REST_NOFILEASSOCIATE = 0x41000003,
    REST_ALLOWCOMMENTTOGGLE = 0x41000004,REST_USEDESKTOPINICACHE = 0x41000005
  } RESTRICTIONS;

  SHSTDAPI_(IStream *) OpenRegStream(HKEY hkey,LPCWSTR pszSubkey,LPCWSTR pszValue,DWORD grfMode);
  SHSTDAPI_(WINBOOL) SHFindFiles(LPCITEMIDLIST pidlFolder,LPCITEMIDLIST pidlSaveFile);
  SHSTDAPI_(void) PathGetShortPath(LPWSTR pszLongPath);
  SHSTDAPI_(WINBOOL) PathYetAnotherMakeUniqueName(LPWSTR pszUniqueName,LPCWSTR pszPath,LPCWSTR pszShort,LPCWSTR pszFileSpec);
  SHSTDAPI_(WINBOOL) Win32DeleteFile(LPCWSTR pszPath);

#define PPCF_ADDQUOTES 0x00000001
#define PPCF_ADDARGUMENTS 0x00000003
#define PPCF_NODIRECTORIES 0x00000010
#define PPCF_FORCEQUALIFY 0x00000040
#define PPCF_LONGESTPOSSIBLE 0x00000080

#define SHStartNetConnectionDialog __MINGW_NAME_AW(SHStartNetConnectionDialog)
#define SHDefExtractIcon __MINGW_NAME_AW(SHDefExtractIcon)

  SHSTDAPI_(LONG) PathProcessCommand(LPCWSTR lpSrc,LPWSTR lpDest,int iMax,DWORD dwFlags);
  SHSTDAPI_(DWORD) SHRestricted(RESTRICTIONS rest);
  SHSTDAPI_(WINBOOL) SignalFileOpen(LPCITEMIDLIST pidl);
  SHSTDAPI_(LPITEMIDLIST) SHSimpleIDListFromPath(LPCWSTR pszPath);
  SHSTDAPI SHLoadOLE(LPARAM lParam);
  SHSTDAPI SHStartNetConnectionDialogA(HWND hwnd,LPCSTR pszRemoteName,DWORD dwType);
  SHSTDAPI SHStartNetConnectionDialogW(HWND hwnd,LPCWSTR pszRemoteName,DWORD dwType);
  SHSTDAPI SHDefExtractIconA(LPCSTR pszIconFile,int iIndex,UINT uFlags,HICON *phiconLarge,HICON *phiconSmall,UINT nIconSize);
  SHSTDAPI SHDefExtractIconW(LPCWSTR pszIconFile,int iIndex,UINT uFlags,HICON *phiconLarge,HICON *phiconSmall,UINT nIconSize);
  SHSTDAPI_(WINBOOL) Shell_GetImageLists(HIMAGELIST *phiml,HIMAGELIST *phimlSmall);
  SHSTDAPI_(int) Shell_GetCachedImageIndex(LPCWSTR pszIconPath,int iIconIndex,UINT uIconFlags);

#undef INTERFACE
#define INTERFACE IDocViewSite
  DECLARE_INTERFACE_(IDocViewSite,IUnknown) {
    STDMETHOD(QueryInterface)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    STDMETHOD(OnSetTitle) (THIS_ VARIANTARG *pvTitle) PURE;
  };
#define VALIDATEUNC_NOUI 0x0002
#define VALIDATEUNC_CONNECT 0x0001
#define VALIDATEUNC_PRINT 0x0004
#define VALIDATEUNC_VALID 0x0007

  SHSTDAPI_(WINBOOL) SHValidateUNC(HWND hwndOwner,LPWSTR pszFile,UINT fConnect);
#define OPENPROPS_NONE 0x0000
#define OPENPROPS_INHIBITPIF 0x8000
#define GETPROPS_NONE 0x0000
#define SETPROPS_NONE 0x0000
#define CLOSEPROPS_NONE 0x0000
#define CLOSEPROPS_DISCARD 0x0001

#define PIFNAMESIZE 30
#define PIFSTARTLOCSIZE 63
#define PIFDEFPATHSIZE 64
#define PIFPARAMSSIZE 64
#define PIFSHPROGSIZE 64
#define PIFSHDATASIZE 64
#define PIFDEFFILESIZE 80
#define PIFMAXFILEPATH 260

  typedef struct PROPPRG {
    WORD flPrg;
    WORD flPrgInit;
    CHAR achTitle[PIFNAMESIZE];
    CHAR achCmdLine[PIFSTARTLOCSIZE+PIFPARAMSSIZE+1];
    CHAR achWorkDir[PIFDEFPATHSIZE];
    WORD wHotKey;
    CHAR achIconFile[PIFDEFFILESIZE];
    WORD wIconIndex;
    DWORD dwEnhModeFlags;
    DWORD dwRealModeFlags;
    CHAR achOtherFile[PIFDEFFILESIZE];
    CHAR achPIFFile[PIFMAXFILEPATH];
  } PROPPRG;
  typedef UNALIGNED PROPPRG *PPROPPRG;
  typedef UNALIGNED PROPPRG *LPPROPPRG;
  typedef const UNALIGNED PROPPRG *LPCPROPPRG;

  SHSTDAPI_(HANDLE) PifMgr_OpenProperties(LPCWSTR pszApp,LPCWSTR pszPIF,UINT hInf,UINT flOpt);
  SHSTDAPI_(int) PifMgr_GetProperties(HANDLE hProps,LPCSTR pszGroup,void *lpProps,int cbProps,UINT flOpt);
  SHSTDAPI_(int) PifMgr_SetProperties(HANDLE hProps,LPCSTR pszGroup,const VOID *lpProps,int cbProps,UINT flOpt);
  SHSTDAPI_(HANDLE) PifMgr_CloseProperties(HANDLE hProps,UINT flOpt);
  SHSTDAPI_(void) SHSetInstanceExplorer(IUnknown *punk);
  SHSTDAPI_(WINBOOL) IsUserAnAdmin(void);

#undef INTERFACE
#define INTERFACE IInitializeObject
  DECLARE_INTERFACE_(IInitializeObject,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(Initialize)(THIS) PURE;
  };

  enum {
    BMICON_LARGE = 0,BMICON_SMALL
  };

#undef INTERFACE
#define INTERFACE IBanneredBar
  DECLARE_INTERFACE_(IBanneredBar,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(SetIconSize)(THIS_ DWORD iIcon) PURE;
    STDMETHOD(GetIconSize)(THIS_ DWORD *piIcon) PURE;
    STDMETHOD(SetBitmap)(THIS_ HBITMAP hBitmap) PURE;
    STDMETHOD(GetBitmap)(THIS_ HBITMAP *phBitmap) PURE;
  };

  SHSTDAPI_(LRESULT) SHShellFolderView_Message(HWND hwndMain,UINT uMsg,LPARAM lParam);

#undef INTERFACE
#define INTERFACE IShellFolderViewCB
  DECLARE_INTERFACE_(IShellFolderViewCB,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(MessageSFVCB)(THIS_ UINT uMsg,WPARAM wParam,LPARAM lParam) PURE;
  };

#include <pshpack8.h>

#undef UNSIZED_ARRAY2
#undef EMPTY_SIZE2
#define UNSIZED_ARRAY2
#define EMPTY_SIZE2 UNSIZED_ARRAY2

#define QCMINFO_PLACE_BEFORE 0
#define QCMINFO_PLACE_AFTER 1
  typedef struct _QCMINFO_IDMAP_PLACEMENT {
    UINT id;
    UINT fFlags;
  } QCMINFO_IDMAP_PLACEMENT;

  typedef struct _QCMINFO_IDMAP {
    UINT nMaxIds;
    QCMINFO_IDMAP_PLACEMENT pIdList[1];
  } QCMINFO_IDMAP;

  typedef struct _QCMINFO {
    HMENU hmenu;
    UINT indexMenu;
    UINT idCmdFirst;
    UINT idCmdLast;
    QCMINFO_IDMAP const *pIdMap;
  } QCMINFO;

  typedef QCMINFO *LPQCMINFO;

#define TBIF_APPEND 0
#define TBIF_PREPEND 1
#define TBIF_REPLACE 2
#define TBIF_DEFAULT 0x00000000
#define TBIF_INTERNETBAR 0x00010000
#define TBIF_STANDARDTOOLBAR 0x00020000
#define TBIF_NOTOOLBAR 0x00030000

  typedef struct _TBINFO {
    UINT cbuttons;
    UINT uFlags;
  } TBINFO;

  typedef struct _DETAILSINFO {
    LPCITEMIDLIST pidl;
    int fmt;
    int cxChar;
    STRRET str;
    int iImage;
  } DETAILSINFO;

  typedef struct _SFVM_PROPPAGE_DATA {
    DWORD dwReserved;
    LPFNADDPROPSHEETPAGE pfn;
    LPARAM lParam;
  } SFVM_PROPPAGE_DATA;

  typedef struct _SFVM_HELPTOPIC_DATA {
    WCHAR wszHelpFile[MAX_PATH];
    WCHAR wszHelpTopic[MAX_PATH];
  } SFVM_HELPTOPIC_DATA;

#define SFVM_MERGEMENU 1
#define SFVM_INVOKECOMMAND 2
#define SFVM_GETHELPTEXT 3
#define SFVM_GETTOOLTIPTEXT 4
#define SFVM_GETBUTTONINFO 5
#define SFVM_GETBUTTONS 6
#define SFVM_INITMENUPOPUP 7
#define SFVM_FSNOTIFY 14
#define SFVM_WINDOWCREATED 15
#define SFVM_GETDETAILSOF 23
#define SFVM_COLUMNCLICK 24
#define SFVM_QUERYFSNOTIFY 25
#define SFVM_DEFITEMCOUNT 26
#define SFVM_DEFVIEWMODE 27
#define SFVM_UNMERGEMENU 28
#define SFVM_UPDATESTATUSBAR 31
#define SFVM_BACKGROUNDENUM 32
#define SFVM_DIDDRAGDROP 36
#define SFVM_SETISFV 39
#define SFVM_THISIDLIST 41
#define SFVM_ADDPROPERTYPAGES 47
#define SFVM_BACKGROUNDENUMDONE 48
#define SFVM_GETNOTIFY 49
#define SFVM_GETSORTDEFAULTS 53
#define SFVM_SIZE 57
#define SFVM_GETZONE 58
#define SFVM_GETPANE 59
#define SFVM_GETHELPTOPIC 63
#define SFVM_GETANIMATION 68

  typedef struct _SFV_CREATE {
    UINT cbSize;
    IShellFolder *pshf;
    IShellView *psvOuter;
    IShellFolderViewCB *psfvcb;
  } SFV_CREATE;

  SHSTDAPI SHCreateShellFolderView(const SFV_CREATE *pcsfv,IShellView **ppsv);

  typedef HRESULT (CALLBACK *LPFNDFMCALLBACK)(IShellFolder *psf,HWND hwnd,IDataObject *pdtobj,UINT uMsg,WPARAM wParam,LPARAM lParam);

#define SHOpenPropSheet __MINGW_NAME_AW(SHOpenPropSheet)

  SHSTDAPI CDefFolderMenu_Create2(LPCITEMIDLIST pidlFolder,HWND hwnd,UINT cidl,LPCITEMIDLIST *apidl,IShellFolder *psf,LPFNDFMCALLBACK lpfn,UINT nKeys,const HKEY *ahkeyClsKeys,IContextMenu **ppcm);
  SHSTDAPI_(WINBOOL) SHOpenPropSheetA(LPCSTR pszCaption,HKEY ahkeys[],UINT cikeys,const CLSID *pclsidDefault,IDataObject *pdtobj,IShellBrowser *psb,LPCSTR pStartPage);
  SHSTDAPI_(WINBOOL) SHOpenPropSheetW(LPCWSTR pszCaption,HKEY ahkeys[],UINT cikeys,const CLSID *pclsidDefault,IDataObject *pdtobj,IShellBrowser *psb,LPCWSTR pStartPage);

#define DFM_MERGECONTEXTMENU 1
#define DFM_INVOKECOMMAND 2
#define DFM_GETDEFSTATICID 14

#define DFM_CMD_PROPERTIES ((UINT)-5)
  typedef TBINFO *LPTBINFO;
  typedef DETAILSINFO *PDETAILSINFO;
  typedef HRESULT (CALLBACK *LPFNVIEWCALLBACK)(IShellView *psvOuter,IShellFolder *psf,HWND hwndMain,UINT uMsg,WPARAM wParam,LPARAM lParam);

  typedef struct _CSFV {
    UINT cbSize;
    IShellFolder *pshf;
    IShellView *psvOuter;
    LPCITEMIDLIST pidl;
    LONG lEvents;
    LPFNVIEWCALLBACK pfnCallback;
    FOLDERVIEWMODE fvm;
  } CSFV,*LPCSFV;

#define SFVM_REARRANGE 0x00000001
#define ShellFolderView_ReArrange(_hwnd,_lparam) (WINBOOL)SHShellFolderView_Message(_hwnd,SFVM_REARRANGE,_lparam)

#define SFVM_ADDOBJECT 0x00000003
#define ShellFolderView_AddObject(_hwnd,_pidl) (LPARAM)SHShellFolderView_Message(_hwnd,SFVM_ADDOBJECT,(LPARAM)_pidl)

#define SFVM_REMOVEOBJECT 0x00000006
#define ShellFolderView_RemoveObject(_hwnd,_pidl) (LPARAM)SHShellFolderView_Message(_hwnd,SFVM_REMOVEOBJECT,(LPARAM)_pidl)

#define SFVM_UPDATEOBJECT 0x00000007
#define ShellFolderView_UpdateObject(_hwnd,_ppidl) (LPARAM)SHShellFolderView_Message(_hwnd,SFVM_UPDATEOBJECT,(LPARAM)_ppidl)

#define SFVM_GETSELECTEDOBJECTS 0x00000009
#define ShellFolderView_GetSelectedObjects(_hwnd,ppidl) (LPARAM)SHShellFolderView_Message(_hwnd,SFVM_GETSELECTEDOBJECTS,(LPARAM)ppidl)
  typedef struct _SFV_SETITEMPOS {
    LPCITEMIDLIST pidl;
    POINT pt;
  } SFV_SETITEMPOS,*LPSFV_SETITEMPOS;

#define SFVM_SETITEMPOS 0x0000000e
#define ShellFolderView_SetItemPos(_hwnd,_pidl,_x,_y) { SFV_SETITEMPOS _sip = {_pidl,{_x,_y}}; SHShellFolderView_Message(_hwnd,SFVM_SETITEMPOS,(LPARAM)(LPSFV_SETITEMPOS)&_sip);}

#define SFVM_SETCLIPBOARD 0x00000010
#define ShellFolderView_SetClipboard(_hwnd,_dwEffect) (void)SHShellFolderView_Message(_hwnd,SFVM_SETCLIPBOARD,(LPARAM)(DWORD)(_dwEffect))
#define SFVM_SETPOINTS 0x00000017
#define ShellFolderView_SetPoints(_hwnd,_pdtobj) (void)SHShellFolderView_Message(_hwnd,SFVM_SETPOINTS,(LPARAM)_pdtobj)
#include <poppack.h>
  SHSTDAPI_(IContextMenu *) SHFind_InitMenuPopup(HMENU hmenu,HWND hwndOwner,UINT idCmdFirst,UINT idCmdLast);
  SHSTDAPI SHCreateShellFolderViewEx(LPCSFV pcsfv,IShellView **ppsv);

#define PID_IS_URL 2
#define PID_IS_NAME 4
#define PID_IS_WORKINGDIR 5
#define PID_IS_HOTKEY 6
#define PID_IS_SHOWCMD 7
#define PID_IS_ICONINDEX 8
#define PID_IS_ICONFILE 9
#define PID_IS_WHATSNEW 10
#define PID_IS_AUTHOR 11
#define PID_IS_DESCRIPTION 12
#define PID_IS_COMMENT 13

#define PID_INTSITE_WHATSNEW 2
#define PID_INTSITE_AUTHOR 3
#define PID_INTSITE_LASTVISIT 4
#define PID_INTSITE_LASTMOD 5
#define PID_INTSITE_VISITCOUNT 6
#define PID_INTSITE_DESCRIPTION 7
#define PID_INTSITE_COMMENT 8
#define PID_INTSITE_FLAGS 9
#define PID_INTSITE_CONTENTLEN 10
#define PID_INTSITE_CONTENTCODE 11
#define PID_INTSITE_RECURSE 12
#define PID_INTSITE_WATCH 13
#define PID_INTSITE_SUBSCRIPTION 14
#define PID_INTSITE_URL 15
#define PID_INTSITE_TITLE 16
#define PID_INTSITE_CODEPAGE 18
#define PID_INTSITE_TRACKING 19
#define PID_INTSITE_ICONINDEX 20
#define PID_INTSITE_ICONFILE 21

#define PIDISF_RECENTLYCHANGED 0x00000001
#define PIDISF_CACHEDSTICKY 0x00000002
#define PIDISF_CACHEIMAGES 0x00000010
#define PIDISF_FOLLOWALLLINKS 0x00000020

#define PIDISM_GLOBAL 0
#define PIDISM_WATCH 1
#define PIDISM_DONTWATCH 2

  typedef struct {
    WINBOOL fShowAllObjects : 1;
    WINBOOL fShowExtensions : 1;
    WINBOOL fNoConfirmRecycle : 1;
    WINBOOL fShowSysFiles : 1;
    WINBOOL fShowCompColor : 1;
    WINBOOL fDoubleClickInWebView : 1;
    WINBOOL fDesktopHTML : 1;
    WINBOOL fWin95Classic : 1;
    WINBOOL fDontPrettyPath : 1;
    WINBOOL fShowAttribCol : 1;
    WINBOOL fMapNetDrvBtn : 1;
    WINBOOL fShowInfoTip : 1;
    WINBOOL fHideIcons : 1;
    WINBOOL fWebView : 1;
    WINBOOL fFilter : 1;
    WINBOOL fShowSuperHidden : 1;
    WINBOOL fNoNetCrawling : 1;
    DWORD dwWin95Unused;
    UINT uWin95Unused;
    LONG lParamSort;
    int iSortDirection;
    UINT version;
    UINT uNotUsed;
    WINBOOL fSepProcess: 1;
    WINBOOL fStartPanelOn: 1;
    WINBOOL fShowStartPage: 1;
    UINT fSpareFlags : 13;
  } SHELLSTATEA,*LPSHELLSTATEA;

  typedef struct {
    WINBOOL fShowAllObjects : 1;
    WINBOOL fShowExtensions : 1;
    WINBOOL fNoConfirmRecycle : 1;
    WINBOOL fShowSysFiles : 1;
    WINBOOL fShowCompColor : 1;
    WINBOOL fDoubleClickInWebView : 1;
    WINBOOL fDesktopHTML : 1;
    WINBOOL fWin95Classic : 1;
    WINBOOL fDontPrettyPath : 1;
    WINBOOL fShowAttribCol : 1;
    WINBOOL fMapNetDrvBtn : 1;
    WINBOOL fShowInfoTip : 1;
    WINBOOL fHideIcons : 1;
    WINBOOL fWebView : 1;
    WINBOOL fFilter : 1;
    WINBOOL fShowSuperHidden : 1;
    WINBOOL fNoNetCrawling : 1;
    DWORD dwWin95Unused;
    UINT uWin95Unused;
    LONG lParamSort;
    int iSortDirection;
    UINT version;
    UINT uNotUsed;
    WINBOOL fSepProcess: 1;
    WINBOOL fStartPanelOn: 1;
    WINBOOL fShowStartPage: 1;
    UINT fSpareFlags : 13;
  } SHELLSTATEW,*LPSHELLSTATEW;

#define SHELLSTATEVERSION_IE4 9
#define SHELLSTATEVERSION_WIN2K 10

#define SHELLSTATE __MINGW_NAME_AW(SHELLSTATE)
#define LPSHELLSTATE __MINGW_NAME_AW(LPSHELLSTATE)

#define SHELLSTATE_SIZE_WIN95 FIELD_OFFSET(SHELLSTATE,lParamSort)
#define SHELLSTATE_SIZE_NT4 FIELD_OFFSET(SHELLSTATE,version)
#define SHELLSTATE_SIZE_IE4 FIELD_OFFSET(SHELLSTATE,uNotUsed)
#define SHELLSTATE_SIZE_WIN2K sizeof(SHELLSTATE)

  SHSTDAPI_(void) SHGetSetSettings(LPSHELLSTATE lpss,DWORD dwMask,WINBOOL bSet);

  typedef struct {
    WINBOOL fShowAllObjects : 1;
    WINBOOL fShowExtensions : 1;
    WINBOOL fNoConfirmRecycle : 1;
    WINBOOL fShowSysFiles : 1;
    WINBOOL fShowCompColor : 1;
    WINBOOL fDoubleClickInWebView : 1;
    WINBOOL fDesktopHTML : 1;
    WINBOOL fWin95Classic : 1;
    WINBOOL fDontPrettyPath : 1;
    WINBOOL fShowAttribCol : 1;
    WINBOOL fMapNetDrvBtn : 1;
    WINBOOL fShowInfoTip : 1;
    WINBOOL fHideIcons : 1;
    UINT fRestFlags : 3;
  } SHELLFLAGSTATE,*LPSHELLFLAGSTATE;

#define SSF_SHOWALLOBJECTS 0x00000001
#define SSF_SHOWEXTENSIONS 0x00000002
#define SSF_HIDDENFILEEXTS 0x00000004
#define SSF_SERVERADMINUI 0x00000004
#define SSF_SHOWCOMPCOLOR 0x00000008
#define SSF_SORTCOLUMNS 0x00000010
#define SSF_SHOWSYSFILES 0x00000020
#define SSF_DOUBLECLICKINWEBVIEW 0x00000080
#define SSF_SHOWATTRIBCOL 0x00000100
#define SSF_DESKTOPHTML 0x00000200
#define SSF_WIN95CLASSIC 0x00000400
#define SSF_DONTPRETTYPATH 0x00000800
#define SSF_SHOWINFOTIP 0x00002000
#define SSF_MAPNETDRVBUTTON 0x00001000
#define SSF_NOCONFIRMRECYCLE 0x00008000
#define SSF_HIDEICONS 0x00004000
#define SSF_FILTER 0x00010000
#define SSF_WEBVIEW 0x00020000
#define SSF_SHOWSUPERHIDDEN 0x00040000
#define SSF_SEPPROCESS 0x00080000
#define SSF_NONETCRAWLING 0x00100000
#define SSF_STARTPANELON 0x00200000
#define SSF_SHOWSTARTPAGE 0x00400000

  SHSTDAPI_(void) SHGetSettings(LPSHELLFLAGSTATE lpsfs,DWORD dwMask);
  SHSTDAPI SHBindToParent(LPCITEMIDLIST pidl,REFIID riid,void **ppv,LPCITEMIDLIST *ppidlLast);
  SHSTDAPI SHParseDisplayName(LPCWSTR pszName,IBindCtx *pbc,LPITEMIDLIST *ppidl,SFGAOF sfgaoIn,SFGAOF *psfgaoOut);

#define SHPPFW_NONE 0x00000000
#define SHPPFW_DEFAULT SHPPFW_DIRCREATE
#define SHPPFW_DIRCREATE 0x00000001
#define SHPPFW_ASKDIRCREATE 0x00000002
#define SHPPFW_IGNOREFILENAME 0x00000004
#define SHPPFW_NOWRITECHECK 0x00000008
#define SHPPFW_MEDIACHECKONLY 0x00000010

#define SHPathPrepareForWrite __MINGW_NAME_AW(SHPathPrepareForWrite)

  SHSTDAPI SHPathPrepareForWriteA(HWND hwnd,IUnknown *punkEnableModless,LPCSTR pszPath,DWORD dwFlags);
  SHSTDAPI SHPathPrepareForWriteW(HWND hwnd,IUnknown *punkEnableModless,LPCWSTR pszPath,DWORD dwFlags);


#undef INTERFACE
#define INTERFACE INamedPropertyBag
  DECLARE_INTERFACE_(INamedPropertyBag,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(ReadPropertyNPB) (THIS_ LPCOLESTR pszBagname,LPCOLESTR pszPropName,PROPVARIANT *pVar) PURE;
    STDMETHOD(WritePropertyNPB)(THIS_ LPCOLESTR pszBagname,LPCOLESTR pszPropName,PROPVARIANT *pVar) PURE;
    STDMETHOD(RemovePropertyNPB)(THIS_ LPCOLESTR pszBagname,LPCOLESTR pszPropName) PURE;
  };

#ifdef __urlmon_h__
  SHDOCAPI_(DWORD) SoftwareUpdateMessageBox(HWND hWnd,LPCWSTR szDistUnit,DWORD dwFlags,LPSOFTDISTINFO psdi);
#endif

#define SHCreateFileExtractIcon __MINGW_NAME_AW(SHCreateFileExtractIcon)

  SHSTDAPI SHPropStgCreate(IPropertySetStorage *psstg,REFFMTID fmtid,CLSID *pclsid,DWORD grfFlags,DWORD grfMode,DWORD dwDisposition,IPropertyStorage**ppstg,UINT *puCodePage);
  SHSTDAPI SHPropStgReadMultiple(IPropertyStorage *pps,UINT uCodePage,ULONG cpspec,PROPSPEC const rgpspec[],PROPVARIANT rgvar[]);
  SHSTDAPI SHPropStgWriteMultiple(IPropertyStorage *pps,UINT *puCodePage,ULONG cpspec,PROPSPEC const rgpspec[],PROPVARIANT rgvar[],PROPID propidNameFirst);
  SHSTDAPI SHCreateFileExtractIconA(LPCSTR pszFile,DWORD dwFileAttributes,REFIID riid,void **ppv);
  SHSTDAPI SHCreateFileExtractIconW(LPCWSTR pszFile,DWORD dwFileAttributes,REFIID riid,void **ppv);

#include <pshpack8.h>
  SHSTDAPI SHLimitInputEdit(HWND hwndEdit,IShellFolder *psf);
  SHSTDAPI SHMultiFileProperties(IDataObject *pdtobj,DWORD dwFlags);

#if (_WIN32_IE >= 0x0600)
  typedef void (CALLBACK *PFNASYNCICONTASKBALLBACK)(LPCITEMIDLIST pidl,LPVOID pvData,LPVOID pvHint,INT iIconIndex,INT iOpenIconIndex);
  SHSTDAPI SHMapIDListToImageListIndexAsync(IShellTaskScheduler *pts,IShellFolder *psf,LPCITEMIDLIST pidl,UINT flags,PFNASYNCICONTASKBALLBACK pfn,LPVOID pvData,LPVOID pvHint,int *piIndex,int *piIndexSel);
#endif

  SHSTDAPI_(int) SHMapPIDLToSystemImageListIndex(IShellFolder *pshf,LPCITEMIDLIST pidl,int *piIndexSel);
  STDAPI SHCLSIDFromString(PCWSTR lpsz,CLSID *pclsid);
  STDAPI SHFlushClipboard(void);
  STDAPI SHCreateQueryCancelAutoPlayMoniker(IMoniker**ppmoniker);
  HINSTANCE WINAPI SHGetShellStyleHInstance(void);
  STDAPI_(void) PerUserInit(void);
  WINSHELLAPI WINBOOL WINAPI SHRunControlPanel(LPCWSTR lpcszCmdLine,HWND hwndMsgParent);
  WINSHELLAPI int WINAPI PickIconDlg(HWND hwnd,LPWSTR pszIconPath,UINT cbIconPath,int *piIconIndex);

  typedef struct tagAAMENUFILENAME {
    SHORT cbTotal;
    BYTE rgbReserved[12];
    WCHAR szFileName[1];
  } AASHELLMENUFILENAME,*LPAASHELLMENUFILENAME;

  typedef struct tagAASHELLMENUITEM {
    void *lpReserved1;
    int iReserved;
    UINT uiReserved;
    LPAASHELLMENUFILENAME lpName;
    LPWSTR psz;
  } AASHELLMENUITEM,*LPAASHELLMENUITEM;

  STDAPI SHGetAttributesFromDataObject(IDataObject *pdo,DWORD dwAttributeMask,DWORD *pdwAttributes,UINT *pcItems);

#include <poppack.h>

#ifdef __cplusplus
}
#endif

#include <poppack.h>

SHDOCAPI_(WINBOOL) ImportPrivacySettings(LPCWSTR szFilename,WINBOOL *pfParsePrivacyPreferences,WINBOOL *pfParsePerSiteRules);
#ifndef IEnumPrivacyRecords
typedef struct IEnumPrivacyRecords IEnumPrivacyRecords;
#endif
SHDOCAPI DoPrivacyDlg(HWND hwndParent,LPOLESTR pszUrl,IEnumPrivacyRecords *pPrivacyEnum,WINBOOL fReportAllSites);
#endif
