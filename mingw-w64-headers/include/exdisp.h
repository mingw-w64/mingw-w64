/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __exdisp_h__
#define __exdisp_h__

#ifndef __IWebBrowser_FWD_DEFINED__
#define __IWebBrowser_FWD_DEFINED__
typedef struct IWebBrowser IWebBrowser;
#endif

#ifndef __DWebBrowserEvents_FWD_DEFINED__
#define __DWebBrowserEvents_FWD_DEFINED__
typedef struct DWebBrowserEvents DWebBrowserEvents;
#endif

#ifndef __IWebBrowserApp_FWD_DEFINED__
#define __IWebBrowserApp_FWD_DEFINED__
typedef struct IWebBrowserApp IWebBrowserApp;
#endif

#ifndef __IWebBrowser2_FWD_DEFINED__
#define __IWebBrowser2_FWD_DEFINED__
typedef struct IWebBrowser2 IWebBrowser2;
#endif

#ifndef __DWebBrowserEvents2_FWD_DEFINED__
#define __DWebBrowserEvents2_FWD_DEFINED__
typedef struct DWebBrowserEvents2 DWebBrowserEvents2;
#endif

#ifndef __WebBrowser_V1_FWD_DEFINED__
#define __WebBrowser_V1_FWD_DEFINED__

#ifdef __cplusplus
typedef class WebBrowser_V1 WebBrowser_V1;
#else
typedef struct WebBrowser_V1 WebBrowser_V1;
#endif
#endif

#ifndef __WebBrowser_FWD_DEFINED__
#define __WebBrowser_FWD_DEFINED__

#ifdef __cplusplus
typedef class WebBrowser WebBrowser;
#else
typedef struct WebBrowser WebBrowser;
#endif
#endif

#ifndef __InternetExplorer_FWD_DEFINED__
#define __InternetExplorer_FWD_DEFINED__

#ifdef __cplusplus
typedef class InternetExplorer InternetExplorer;
#else
typedef struct InternetExplorer InternetExplorer;
#endif
#endif

#ifndef __ShellBrowserWindow_FWD_DEFINED__
#define __ShellBrowserWindow_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellBrowserWindow ShellBrowserWindow;
#else
typedef struct ShellBrowserWindow ShellBrowserWindow;
#endif
#endif

#ifndef __DShellWindowsEvents_FWD_DEFINED__
#define __DShellWindowsEvents_FWD_DEFINED__
typedef struct DShellWindowsEvents DShellWindowsEvents;
#endif

#ifndef __IShellWindows_FWD_DEFINED__
#define __IShellWindows_FWD_DEFINED__
typedef struct IShellWindows IShellWindows;
#endif

#ifndef __ShellWindows_FWD_DEFINED__
#define __ShellWindows_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellWindows ShellWindows;
#else
typedef struct ShellWindows ShellWindows;
#endif
#endif

#ifndef __IShellUIHelper_FWD_DEFINED__
#define __IShellUIHelper_FWD_DEFINED__
typedef struct IShellUIHelper IShellUIHelper;
#endif

#ifndef __ShellUIHelper_FWD_DEFINED__
#define __ShellUIHelper_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellUIHelper ShellUIHelper;
#else
typedef struct ShellUIHelper ShellUIHelper;
#endif
#endif

#ifndef __DShellNameSpaceEvents_FWD_DEFINED__
#define __DShellNameSpaceEvents_FWD_DEFINED__
typedef struct DShellNameSpaceEvents DShellNameSpaceEvents;
#endif

#ifndef __IShellFavoritesNameSpace_FWD_DEFINED__
#define __IShellFavoritesNameSpace_FWD_DEFINED__
typedef struct IShellFavoritesNameSpace IShellFavoritesNameSpace;
#endif

#ifndef __IShellNameSpace_FWD_DEFINED__
#define __IShellNameSpace_FWD_DEFINED__
typedef struct IShellNameSpace IShellNameSpace;
#endif

#ifndef __ShellNameSpace_FWD_DEFINED__
#define __ShellNameSpace_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellNameSpace ShellNameSpace;
#else
typedef struct ShellNameSpace ShellNameSpace;
#endif
#endif

#ifndef __IScriptErrorList_FWD_DEFINED__
#define __IScriptErrorList_FWD_DEFINED__
typedef struct IScriptErrorList IScriptErrorList;
#endif

#ifndef __CScriptErrorList_FWD_DEFINED__
#define __CScriptErrorList_FWD_DEFINED__
#ifdef __cplusplus
typedef class CScriptErrorList CScriptErrorList;
#else
typedef struct CScriptErrorList CScriptErrorList;
#endif
#endif

#ifndef __ISearch_FWD_DEFINED__
#define __ISearch_FWD_DEFINED__
typedef struct ISearch ISearch;
#endif

#ifndef __ISearches_FWD_DEFINED__
#define __ISearches_FWD_DEFINED__
typedef struct ISearches ISearches;
#endif

#ifndef __ISearchAssistantOC_FWD_DEFINED__
#define __ISearchAssistantOC_FWD_DEFINED__
typedef struct ISearchAssistantOC ISearchAssistantOC;
#endif

#ifndef __ISearchAssistantOC2_FWD_DEFINED__
#define __ISearchAssistantOC2_FWD_DEFINED__
typedef struct ISearchAssistantOC2 ISearchAssistantOC2;
#endif

#ifndef __ISearchAssistantOC3_FWD_DEFINED__
#define __ISearchAssistantOC3_FWD_DEFINED__
typedef struct ISearchAssistantOC3 ISearchAssistantOC3;
#endif

#ifndef ___SearchAssistantEvents_FWD_DEFINED__
#define ___SearchAssistantEvents_FWD_DEFINED__
typedef struct _SearchAssistantEvents _SearchAssistantEvents;
#endif

#ifndef __SearchAssistantOC_FWD_DEFINED__
#define __SearchAssistantOC_FWD_DEFINED__
#ifdef __cplusplus
typedef class SearchAssistantOC SearchAssistantOC;
#else
typedef struct SearchAssistantOC SearchAssistantOC;
#endif
#endif

#include "ocidl.h"
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef __SHDocVw_LIBRARY_DEFINED__
#define __SHDocVw_LIBRARY_DEFINED__

  typedef enum CommandStateChangeConstants {
    CSC_UPDATECOMMANDS = 0xffffffff,CSC_NAVIGATEFORWARD = 0x1,CSC_NAVIGATEBACK = 0x2
  } CommandStateChangeConstants;

  typedef enum SecureLockIconConstants {
    secureLockIconUnsecure = 0,secureLockIconMixed = 0x1,secureLockIconSecureUnknownBits = 0x2,secureLockIconSecure40Bit = 0x3,
    secureLockIconSecure56Bit = 0x4,secureLockIconSecureFortezza = 0x5,secureLockIconSecure128Bit = 0x6
  } SecureLockIconConstants;

  typedef enum ShellWindowTypeConstants {
    SWC_EXPLORER = 0,SWC_BROWSER = 0x1,SWC_3RDPARTY = 0x2,SWC_CALLBACK = 0x4
  } ShellWindowTypeConstants;

  typedef enum ShellWindowFindWindowOptions {
    SWFO_NEEDDISPATCH = 0x1,SWFO_INCLUDEPENDING = 0x2,SWFO_COOKIEPASSED = 0x4
  } ShellWindowFindWindowOptions;

  EXTERN_C const IID LIBID_SHDocVw;

#ifndef __IWebBrowser_INTERFACE_DEFINED__
#define __IWebBrowser_INTERFACE_DEFINED__
  typedef enum BrowserNavConstants {
    navOpenInNewWindow = 0x1,navNoHistory = 0x2,navNoReadFromCache = 0x4,navNoWriteToCache = 0x8,navAllowAutosearch = 0x10,
    navBrowserBar = 0x20,navHyperlink = 0x40,navEnforceRestricted = 0x80,navNewWindowsManaged = 0x100,navUntrustedForDownload = 0x200,
    navTrustedForActiveX = 0x400
  } BrowserNavConstants;

  typedef enum RefreshConstants {
    REFRESH_NORMAL = 0,REFRESH_IFEXPIRED = 1,REFRESH_COMPLETELY = 3
  } RefreshConstants;

  EXTERN_C const IID IID_IWebBrowser;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWebBrowser : public IDispatch {
  public:
    virtual HRESULT WINAPI GoBack(void) = 0;
    virtual HRESULT WINAPI GoForward(void) = 0;
    virtual HRESULT WINAPI GoHome(void) = 0;
    virtual HRESULT WINAPI GoSearch(void) = 0;
    virtual HRESULT WINAPI Navigate(BSTR URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers) = 0;
    virtual HRESULT WINAPI Refresh(void) = 0;
    virtual HRESULT WINAPI Refresh2(VARIANT *Level) = 0;
    virtual HRESULT WINAPI Stop(void) = 0;
    virtual HRESULT WINAPI get_Application(IDispatch **ppDisp) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppDisp) = 0;
    virtual HRESULT WINAPI get_Container(IDispatch **ppDisp) = 0;
    virtual HRESULT WINAPI get_Document(IDispatch **ppDisp) = 0;
    virtual HRESULT WINAPI get_TopLevelContainer(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI get_Type(BSTR *Type) = 0;
    virtual HRESULT WINAPI get_Left(long *pl) = 0;
    virtual HRESULT WINAPI put_Left(long Left) = 0;
    virtual HRESULT WINAPI get_Top(long *pl) = 0;
    virtual HRESULT WINAPI put_Top(long Top) = 0;
    virtual HRESULT WINAPI get_Width(long *pl) = 0;
    virtual HRESULT WINAPI put_Width(long Width) = 0;
    virtual HRESULT WINAPI get_Height(long *pl) = 0;
    virtual HRESULT WINAPI put_Height(long Height) = 0;
    virtual HRESULT WINAPI get_LocationName(BSTR *LocationName) = 0;
    virtual HRESULT WINAPI get_LocationURL(BSTR *LocationURL) = 0;
    virtual HRESULT WINAPI get_Busy(VARIANT_BOOL *pBool) = 0;
  };
#else
  typedef struct IWebBrowserVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWebBrowser *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWebBrowser *This);
      ULONG (WINAPI *Release)(IWebBrowser *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IWebBrowser *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IWebBrowser *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IWebBrowser *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IWebBrowser *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *GoBack)(IWebBrowser *This);
      HRESULT (WINAPI *GoForward)(IWebBrowser *This);
      HRESULT (WINAPI *GoHome)(IWebBrowser *This);
      HRESULT (WINAPI *GoSearch)(IWebBrowser *This);
      HRESULT (WINAPI *Navigate)(IWebBrowser *This,BSTR URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
      HRESULT (WINAPI *Refresh)(IWebBrowser *This);
      HRESULT (WINAPI *Refresh2)(IWebBrowser *This,VARIANT *Level);
      HRESULT (WINAPI *Stop)(IWebBrowser *This);
      HRESULT (WINAPI *get_Application)(IWebBrowser *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Parent)(IWebBrowser *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Container)(IWebBrowser *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Document)(IWebBrowser *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_TopLevelContainer)(IWebBrowser *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *get_Type)(IWebBrowser *This,BSTR *Type);
      HRESULT (WINAPI *get_Left)(IWebBrowser *This,long *pl);
      HRESULT (WINAPI *put_Left)(IWebBrowser *This,long Left);
      HRESULT (WINAPI *get_Top)(IWebBrowser *This,long *pl);
      HRESULT (WINAPI *put_Top)(IWebBrowser *This,long Top);
      HRESULT (WINAPI *get_Width)(IWebBrowser *This,long *pl);
      HRESULT (WINAPI *put_Width)(IWebBrowser *This,long Width);
      HRESULT (WINAPI *get_Height)(IWebBrowser *This,long *pl);
      HRESULT (WINAPI *put_Height)(IWebBrowser *This,long Height);
      HRESULT (WINAPI *get_LocationName)(IWebBrowser *This,BSTR *LocationName);
      HRESULT (WINAPI *get_LocationURL)(IWebBrowser *This,BSTR *LocationURL);
      HRESULT (WINAPI *get_Busy)(IWebBrowser *This,VARIANT_BOOL *pBool);
    END_INTERFACE
  } IWebBrowserVtbl;
  struct IWebBrowser {
    CONST_VTBL struct IWebBrowserVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWebBrowser_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWebBrowser_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWebBrowser_Release(This) (This)->lpVtbl->Release(This)
#define IWebBrowser_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWebBrowser_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWebBrowser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWebBrowser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWebBrowser_GoBack(This) (This)->lpVtbl->GoBack(This)
#define IWebBrowser_GoForward(This) (This)->lpVtbl->GoForward(This)
#define IWebBrowser_GoHome(This) (This)->lpVtbl->GoHome(This)
#define IWebBrowser_GoSearch(This) (This)->lpVtbl->GoSearch(This)
#define IWebBrowser_Navigate(This,URL,Flags,TargetFrameName,PostData,Headers) (This)->lpVtbl->Navigate(This,URL,Flags,TargetFrameName,PostData,Headers)
#define IWebBrowser_Refresh(This) (This)->lpVtbl->Refresh(This)
#define IWebBrowser_Refresh2(This,Level) (This)->lpVtbl->Refresh2(This,Level)
#define IWebBrowser_Stop(This) (This)->lpVtbl->Stop(This)
#define IWebBrowser_get_Application(This,ppDisp) (This)->lpVtbl->get_Application(This,ppDisp)
#define IWebBrowser_get_Parent(This,ppDisp) (This)->lpVtbl->get_Parent(This,ppDisp)
#define IWebBrowser_get_Container(This,ppDisp) (This)->lpVtbl->get_Container(This,ppDisp)
#define IWebBrowser_get_Document(This,ppDisp) (This)->lpVtbl->get_Document(This,ppDisp)
#define IWebBrowser_get_TopLevelContainer(This,pBool) (This)->lpVtbl->get_TopLevelContainer(This,pBool)
#define IWebBrowser_get_Type(This,Type) (This)->lpVtbl->get_Type(This,Type)
#define IWebBrowser_get_Left(This,pl) (This)->lpVtbl->get_Left(This,pl)
#define IWebBrowser_put_Left(This,Left) (This)->lpVtbl->put_Left(This,Left)
#define IWebBrowser_get_Top(This,pl) (This)->lpVtbl->get_Top(This,pl)
#define IWebBrowser_put_Top(This,Top) (This)->lpVtbl->put_Top(This,Top)
#define IWebBrowser_get_Width(This,pl) (This)->lpVtbl->get_Width(This,pl)
#define IWebBrowser_put_Width(This,Width) (This)->lpVtbl->put_Width(This,Width)
#define IWebBrowser_get_Height(This,pl) (This)->lpVtbl->get_Height(This,pl)
#define IWebBrowser_put_Height(This,Height) (This)->lpVtbl->put_Height(This,Height)
#define IWebBrowser_get_LocationName(This,LocationName) (This)->lpVtbl->get_LocationName(This,LocationName)
#define IWebBrowser_get_LocationURL(This,LocationURL) (This)->lpVtbl->get_LocationURL(This,LocationURL)
#define IWebBrowser_get_Busy(This,pBool) (This)->lpVtbl->get_Busy(This,pBool)
#endif
#endif
  HRESULT WINAPI IWebBrowser_GoBack_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_GoBack_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_GoForward_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_GoForward_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_GoHome_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_GoHome_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_GoSearch_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_GoSearch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_Navigate_Proxy(IWebBrowser *This,BSTR URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
  void __RPC_STUB IWebBrowser_Navigate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_Refresh_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_Refresh2_Proxy(IWebBrowser *This,VARIANT *Level);
  void __RPC_STUB IWebBrowser_Refresh2_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_Stop_Proxy(IWebBrowser *This);
  void __RPC_STUB IWebBrowser_Stop_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Application_Proxy(IWebBrowser *This,IDispatch **ppDisp);
  void __RPC_STUB IWebBrowser_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Parent_Proxy(IWebBrowser *This,IDispatch **ppDisp);
  void __RPC_STUB IWebBrowser_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Container_Proxy(IWebBrowser *This,IDispatch **ppDisp);
  void __RPC_STUB IWebBrowser_get_Container_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Document_Proxy(IWebBrowser *This,IDispatch **ppDisp);
  void __RPC_STUB IWebBrowser_get_Document_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_TopLevelContainer_Proxy(IWebBrowser *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IWebBrowser_get_TopLevelContainer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Type_Proxy(IWebBrowser *This,BSTR *Type);
  void __RPC_STUB IWebBrowser_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Left_Proxy(IWebBrowser *This,long *pl);
  void __RPC_STUB IWebBrowser_get_Left_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_put_Left_Proxy(IWebBrowser *This,long Left);
  void __RPC_STUB IWebBrowser_put_Left_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Top_Proxy(IWebBrowser *This,long *pl);
  void __RPC_STUB IWebBrowser_get_Top_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_put_Top_Proxy(IWebBrowser *This,long Top);
  void __RPC_STUB IWebBrowser_put_Top_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Width_Proxy(IWebBrowser *This,long *pl);
  void __RPC_STUB IWebBrowser_get_Width_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_put_Width_Proxy(IWebBrowser *This,long Width);
  void __RPC_STUB IWebBrowser_put_Width_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Height_Proxy(IWebBrowser *This,long *pl);
  void __RPC_STUB IWebBrowser_get_Height_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_put_Height_Proxy(IWebBrowser *This,long Height);
  void __RPC_STUB IWebBrowser_put_Height_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_LocationName_Proxy(IWebBrowser *This,BSTR *LocationName);
  void __RPC_STUB IWebBrowser_get_LocationName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_LocationURL_Proxy(IWebBrowser *This,BSTR *LocationURL);
  void __RPC_STUB IWebBrowser_get_LocationURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser_get_Busy_Proxy(IWebBrowser *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IWebBrowser_get_Busy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __DWebBrowserEvents_DISPINTERFACE_DEFINED__
#define __DWebBrowserEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DWebBrowserEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DWebBrowserEvents : public IDispatch {
  };
#else
  typedef struct DWebBrowserEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DWebBrowserEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DWebBrowserEvents *This);
      ULONG (WINAPI *Release)(DWebBrowserEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DWebBrowserEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DWebBrowserEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DWebBrowserEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DWebBrowserEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DWebBrowserEventsVtbl;
  struct DWebBrowserEvents {
    CONST_VTBL struct DWebBrowserEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DWebBrowserEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DWebBrowserEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DWebBrowserEvents_Release(This) (This)->lpVtbl->Release(This)
#define DWebBrowserEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DWebBrowserEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DWebBrowserEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DWebBrowserEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

#ifndef __IWebBrowserApp_INTERFACE_DEFINED__
#define __IWebBrowserApp_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWebBrowserApp;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWebBrowserApp : public IWebBrowser {
  public:
    virtual HRESULT WINAPI Quit(void) = 0;
    virtual HRESULT WINAPI ClientToWindow(int *pcx,int *pcy) = 0;
    virtual HRESULT WINAPI PutProperty(BSTR Property,VARIANT vtValue) = 0;
    virtual HRESULT WINAPI GetProperty(BSTR Property,VARIANT *pvtValue) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *Name) = 0;
    virtual HRESULT WINAPI get_HWND(SHANDLE_PTR *pHWND) = 0;
    virtual HRESULT WINAPI get_FullName(BSTR *FullName) = 0;
    virtual HRESULT WINAPI get_Path(BSTR *Path) = 0;
    virtual HRESULT WINAPI get_Visible(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI put_Visible(VARIANT_BOOL Value) = 0;
    virtual HRESULT WINAPI get_StatusBar(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI put_StatusBar(VARIANT_BOOL Value) = 0;
    virtual HRESULT WINAPI get_StatusText(BSTR *StatusText) = 0;
    virtual HRESULT WINAPI put_StatusText(BSTR StatusText) = 0;
    virtual HRESULT WINAPI get_ToolBar(int *Value) = 0;
    virtual HRESULT WINAPI put_ToolBar(int Value) = 0;
    virtual HRESULT WINAPI get_MenuBar(VARIANT_BOOL *Value) = 0;
    virtual HRESULT WINAPI put_MenuBar(VARIANT_BOOL Value) = 0;
    virtual HRESULT WINAPI get_FullScreen(VARIANT_BOOL *pbFullScreen) = 0;
    virtual HRESULT WINAPI put_FullScreen(VARIANT_BOOL bFullScreen) = 0;
  };
#else
  typedef struct IWebBrowserAppVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWebBrowserApp *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWebBrowserApp *This);
      ULONG (WINAPI *Release)(IWebBrowserApp *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IWebBrowserApp *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IWebBrowserApp *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IWebBrowserApp *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IWebBrowserApp *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *GoBack)(IWebBrowserApp *This);
      HRESULT (WINAPI *GoForward)(IWebBrowserApp *This);
      HRESULT (WINAPI *GoHome)(IWebBrowserApp *This);
      HRESULT (WINAPI *GoSearch)(IWebBrowserApp *This);
      HRESULT (WINAPI *Navigate)(IWebBrowserApp *This,BSTR URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
      HRESULT (WINAPI *Refresh)(IWebBrowserApp *This);
      HRESULT (WINAPI *Refresh2)(IWebBrowserApp *This,VARIANT *Level);
      HRESULT (WINAPI *Stop)(IWebBrowserApp *This);
      HRESULT (WINAPI *get_Application)(IWebBrowserApp *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Parent)(IWebBrowserApp *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Container)(IWebBrowserApp *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Document)(IWebBrowserApp *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_TopLevelContainer)(IWebBrowserApp *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *get_Type)(IWebBrowserApp *This,BSTR *Type);
      HRESULT (WINAPI *get_Left)(IWebBrowserApp *This,long *pl);
      HRESULT (WINAPI *put_Left)(IWebBrowserApp *This,long Left);
      HRESULT (WINAPI *get_Top)(IWebBrowserApp *This,long *pl);
      HRESULT (WINAPI *put_Top)(IWebBrowserApp *This,long Top);
      HRESULT (WINAPI *get_Width)(IWebBrowserApp *This,long *pl);
      HRESULT (WINAPI *put_Width)(IWebBrowserApp *This,long Width);
      HRESULT (WINAPI *get_Height)(IWebBrowserApp *This,long *pl);
      HRESULT (WINAPI *put_Height)(IWebBrowserApp *This,long Height);
      HRESULT (WINAPI *get_LocationName)(IWebBrowserApp *This,BSTR *LocationName);
      HRESULT (WINAPI *get_LocationURL)(IWebBrowserApp *This,BSTR *LocationURL);
      HRESULT (WINAPI *get_Busy)(IWebBrowserApp *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *Quit)(IWebBrowserApp *This);
      HRESULT (WINAPI *ClientToWindow)(IWebBrowserApp *This,int *pcx,int *pcy);
      HRESULT (WINAPI *PutProperty)(IWebBrowserApp *This,BSTR Property,VARIANT vtValue);
      HRESULT (WINAPI *GetProperty)(IWebBrowserApp *This,BSTR Property,VARIANT *pvtValue);
      HRESULT (WINAPI *get_Name)(IWebBrowserApp *This,BSTR *Name);
      HRESULT (WINAPI *get_HWND)(IWebBrowserApp *This,SHANDLE_PTR *pHWND);
      HRESULT (WINAPI *get_FullName)(IWebBrowserApp *This,BSTR *FullName);
      HRESULT (WINAPI *get_Path)(IWebBrowserApp *This,BSTR *Path);
      HRESULT (WINAPI *get_Visible)(IWebBrowserApp *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *put_Visible)(IWebBrowserApp *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_StatusBar)(IWebBrowserApp *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *put_StatusBar)(IWebBrowserApp *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_StatusText)(IWebBrowserApp *This,BSTR *StatusText);
      HRESULT (WINAPI *put_StatusText)(IWebBrowserApp *This,BSTR StatusText);
      HRESULT (WINAPI *get_ToolBar)(IWebBrowserApp *This,int *Value);
      HRESULT (WINAPI *put_ToolBar)(IWebBrowserApp *This,int Value);
      HRESULT (WINAPI *get_MenuBar)(IWebBrowserApp *This,VARIANT_BOOL *Value);
      HRESULT (WINAPI *put_MenuBar)(IWebBrowserApp *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_FullScreen)(IWebBrowserApp *This,VARIANT_BOOL *pbFullScreen);
      HRESULT (WINAPI *put_FullScreen)(IWebBrowserApp *This,VARIANT_BOOL bFullScreen);
    END_INTERFACE
  } IWebBrowserAppVtbl;
  struct IWebBrowserApp {
    CONST_VTBL struct IWebBrowserAppVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWebBrowserApp_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWebBrowserApp_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWebBrowserApp_Release(This) (This)->lpVtbl->Release(This)
#define IWebBrowserApp_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWebBrowserApp_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWebBrowserApp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWebBrowserApp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWebBrowserApp_GoBack(This) (This)->lpVtbl->GoBack(This)
#define IWebBrowserApp_GoForward(This) (This)->lpVtbl->GoForward(This)
#define IWebBrowserApp_GoHome(This) (This)->lpVtbl->GoHome(This)
#define IWebBrowserApp_GoSearch(This) (This)->lpVtbl->GoSearch(This)
#define IWebBrowserApp_Navigate(This,URL,Flags,TargetFrameName,PostData,Headers) (This)->lpVtbl->Navigate(This,URL,Flags,TargetFrameName,PostData,Headers)
#define IWebBrowserApp_Refresh(This) (This)->lpVtbl->Refresh(This)
#define IWebBrowserApp_Refresh2(This,Level) (This)->lpVtbl->Refresh2(This,Level)
#define IWebBrowserApp_Stop(This) (This)->lpVtbl->Stop(This)
#define IWebBrowserApp_get_Application(This,ppDisp) (This)->lpVtbl->get_Application(This,ppDisp)
#define IWebBrowserApp_get_Parent(This,ppDisp) (This)->lpVtbl->get_Parent(This,ppDisp)
#define IWebBrowserApp_get_Container(This,ppDisp) (This)->lpVtbl->get_Container(This,ppDisp)
#define IWebBrowserApp_get_Document(This,ppDisp) (This)->lpVtbl->get_Document(This,ppDisp)
#define IWebBrowserApp_get_TopLevelContainer(This,pBool) (This)->lpVtbl->get_TopLevelContainer(This,pBool)
#define IWebBrowserApp_get_Type(This,Type) (This)->lpVtbl->get_Type(This,Type)
#define IWebBrowserApp_get_Left(This,pl) (This)->lpVtbl->get_Left(This,pl)
#define IWebBrowserApp_put_Left(This,Left) (This)->lpVtbl->put_Left(This,Left)
#define IWebBrowserApp_get_Top(This,pl) (This)->lpVtbl->get_Top(This,pl)
#define IWebBrowserApp_put_Top(This,Top) (This)->lpVtbl->put_Top(This,Top)
#define IWebBrowserApp_get_Width(This,pl) (This)->lpVtbl->get_Width(This,pl)
#define IWebBrowserApp_put_Width(This,Width) (This)->lpVtbl->put_Width(This,Width)
#define IWebBrowserApp_get_Height(This,pl) (This)->lpVtbl->get_Height(This,pl)
#define IWebBrowserApp_put_Height(This,Height) (This)->lpVtbl->put_Height(This,Height)
#define IWebBrowserApp_get_LocationName(This,LocationName) (This)->lpVtbl->get_LocationName(This,LocationName)
#define IWebBrowserApp_get_LocationURL(This,LocationURL) (This)->lpVtbl->get_LocationURL(This,LocationURL)
#define IWebBrowserApp_get_Busy(This,pBool) (This)->lpVtbl->get_Busy(This,pBool)
#define IWebBrowserApp_Quit(This) (This)->lpVtbl->Quit(This)
#define IWebBrowserApp_ClientToWindow(This,pcx,pcy) (This)->lpVtbl->ClientToWindow(This,pcx,pcy)
#define IWebBrowserApp_PutProperty(This,Property,vtValue) (This)->lpVtbl->PutProperty(This,Property,vtValue)
#define IWebBrowserApp_GetProperty(This,Property,pvtValue) (This)->lpVtbl->GetProperty(This,Property,pvtValue)
#define IWebBrowserApp_get_Name(This,Name) (This)->lpVtbl->get_Name(This,Name)
#define IWebBrowserApp_get_HWND(This,pHWND) (This)->lpVtbl->get_HWND(This,pHWND)
#define IWebBrowserApp_get_FullName(This,FullName) (This)->lpVtbl->get_FullName(This,FullName)
#define IWebBrowserApp_get_Path(This,Path) (This)->lpVtbl->get_Path(This,Path)
#define IWebBrowserApp_get_Visible(This,pBool) (This)->lpVtbl->get_Visible(This,pBool)
#define IWebBrowserApp_put_Visible(This,Value) (This)->lpVtbl->put_Visible(This,Value)
#define IWebBrowserApp_get_StatusBar(This,pBool) (This)->lpVtbl->get_StatusBar(This,pBool)
#define IWebBrowserApp_put_StatusBar(This,Value) (This)->lpVtbl->put_StatusBar(This,Value)
#define IWebBrowserApp_get_StatusText(This,StatusText) (This)->lpVtbl->get_StatusText(This,StatusText)
#define IWebBrowserApp_put_StatusText(This,StatusText) (This)->lpVtbl->put_StatusText(This,StatusText)
#define IWebBrowserApp_get_ToolBar(This,Value) (This)->lpVtbl->get_ToolBar(This,Value)
#define IWebBrowserApp_put_ToolBar(This,Value) (This)->lpVtbl->put_ToolBar(This,Value)
#define IWebBrowserApp_get_MenuBar(This,Value) (This)->lpVtbl->get_MenuBar(This,Value)
#define IWebBrowserApp_put_MenuBar(This,Value) (This)->lpVtbl->put_MenuBar(This,Value)
#define IWebBrowserApp_get_FullScreen(This,pbFullScreen) (This)->lpVtbl->get_FullScreen(This,pbFullScreen)
#define IWebBrowserApp_put_FullScreen(This,bFullScreen) (This)->lpVtbl->put_FullScreen(This,bFullScreen)
#endif
#endif
  HRESULT WINAPI IWebBrowserApp_Quit_Proxy(IWebBrowserApp *This);
  void __RPC_STUB IWebBrowserApp_Quit_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_ClientToWindow_Proxy(IWebBrowserApp *This,int *pcx,int *pcy);
  void __RPC_STUB IWebBrowserApp_ClientToWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_PutProperty_Proxy(IWebBrowserApp *This,BSTR Property,VARIANT vtValue);
  void __RPC_STUB IWebBrowserApp_PutProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_GetProperty_Proxy(IWebBrowserApp *This,BSTR Property,VARIANT *pvtValue);
  void __RPC_STUB IWebBrowserApp_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_Name_Proxy(IWebBrowserApp *This,BSTR *Name);
  void __RPC_STUB IWebBrowserApp_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_HWND_Proxy(IWebBrowserApp *This,SHANDLE_PTR *pHWND);
  void __RPC_STUB IWebBrowserApp_get_HWND_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_FullName_Proxy(IWebBrowserApp *This,BSTR *FullName);
  void __RPC_STUB IWebBrowserApp_get_FullName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_Path_Proxy(IWebBrowserApp *This,BSTR *Path);
  void __RPC_STUB IWebBrowserApp_get_Path_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_Visible_Proxy(IWebBrowserApp *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IWebBrowserApp_get_Visible_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_Visible_Proxy(IWebBrowserApp *This,VARIANT_BOOL Value);
  void __RPC_STUB IWebBrowserApp_put_Visible_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_StatusBar_Proxy(IWebBrowserApp *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IWebBrowserApp_get_StatusBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_StatusBar_Proxy(IWebBrowserApp *This,VARIANT_BOOL Value);
  void __RPC_STUB IWebBrowserApp_put_StatusBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_StatusText_Proxy(IWebBrowserApp *This,BSTR *StatusText);
  void __RPC_STUB IWebBrowserApp_get_StatusText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_StatusText_Proxy(IWebBrowserApp *This,BSTR StatusText);
  void __RPC_STUB IWebBrowserApp_put_StatusText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_ToolBar_Proxy(IWebBrowserApp *This,int *Value);
  void __RPC_STUB IWebBrowserApp_get_ToolBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_ToolBar_Proxy(IWebBrowserApp *This,int Value);
  void __RPC_STUB IWebBrowserApp_put_ToolBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_MenuBar_Proxy(IWebBrowserApp *This,VARIANT_BOOL *Value);
  void __RPC_STUB IWebBrowserApp_get_MenuBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_MenuBar_Proxy(IWebBrowserApp *This,VARIANT_BOOL Value);
  void __RPC_STUB IWebBrowserApp_put_MenuBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_get_FullScreen_Proxy(IWebBrowserApp *This,VARIANT_BOOL *pbFullScreen);
  void __RPC_STUB IWebBrowserApp_get_FullScreen_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowserApp_put_FullScreen_Proxy(IWebBrowserApp *This,VARIANT_BOOL bFullScreen);
  void __RPC_STUB IWebBrowserApp_put_FullScreen_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWebBrowser2_INTERFACE_DEFINED__
#define __IWebBrowser2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWebBrowser2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWebBrowser2 : public IWebBrowserApp {
  public:
    virtual HRESULT WINAPI Navigate2(VARIANT *URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers) = 0;
    virtual HRESULT WINAPI QueryStatusWB(OLECMDID cmdID,OLECMDF *pcmdf) = 0;
    virtual HRESULT WINAPI ExecWB(OLECMDID cmdID,OLECMDEXECOPT cmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut) = 0;
    virtual HRESULT WINAPI ShowBrowserBar(VARIANT *pvaClsid,VARIANT *pvarShow,VARIANT *pvarSize) = 0;
    virtual HRESULT WINAPI get_ReadyState(READYSTATE *plReadyState) = 0;
    virtual HRESULT WINAPI get_Offline(VARIANT_BOOL *pbOffline) = 0;
    virtual HRESULT WINAPI put_Offline(VARIANT_BOOL bOffline) = 0;
    virtual HRESULT WINAPI get_Silent(VARIANT_BOOL *pbSilent) = 0;
    virtual HRESULT WINAPI put_Silent(VARIANT_BOOL bSilent) = 0;
    virtual HRESULT WINAPI get_RegisterAsBrowser(VARIANT_BOOL *pbRegister) = 0;
    virtual HRESULT WINAPI put_RegisterAsBrowser(VARIANT_BOOL bRegister) = 0;
    virtual HRESULT WINAPI get_RegisterAsDropTarget(VARIANT_BOOL *pbRegister) = 0;
    virtual HRESULT WINAPI put_RegisterAsDropTarget(VARIANT_BOOL bRegister) = 0;
    virtual HRESULT WINAPI get_TheaterMode(VARIANT_BOOL *pbRegister) = 0;
    virtual HRESULT WINAPI put_TheaterMode(VARIANT_BOOL bRegister) = 0;
    virtual HRESULT WINAPI get_AddressBar(VARIANT_BOOL *Value) = 0;
    virtual HRESULT WINAPI put_AddressBar(VARIANT_BOOL Value) = 0;
    virtual HRESULT WINAPI get_Resizable(VARIANT_BOOL *Value) = 0;
    virtual HRESULT WINAPI put_Resizable(VARIANT_BOOL Value) = 0;
  };
#else
  typedef struct IWebBrowser2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWebBrowser2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWebBrowser2 *This);
      ULONG (WINAPI *Release)(IWebBrowser2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IWebBrowser2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IWebBrowser2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IWebBrowser2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IWebBrowser2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *GoBack)(IWebBrowser2 *This);
      HRESULT (WINAPI *GoForward)(IWebBrowser2 *This);
      HRESULT (WINAPI *GoHome)(IWebBrowser2 *This);
      HRESULT (WINAPI *GoSearch)(IWebBrowser2 *This);
      HRESULT (WINAPI *Navigate)(IWebBrowser2 *This,BSTR URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
      HRESULT (WINAPI *Refresh)(IWebBrowser2 *This);
      HRESULT (WINAPI *Refresh2)(IWebBrowser2 *This,VARIANT *Level);
      HRESULT (WINAPI *Stop)(IWebBrowser2 *This);
      HRESULT (WINAPI *get_Application)(IWebBrowser2 *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Parent)(IWebBrowser2 *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Container)(IWebBrowser2 *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_Document)(IWebBrowser2 *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_TopLevelContainer)(IWebBrowser2 *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *get_Type)(IWebBrowser2 *This,BSTR *Type);
      HRESULT (WINAPI *get_Left)(IWebBrowser2 *This,long *pl);
      HRESULT (WINAPI *put_Left)(IWebBrowser2 *This,long Left);
      HRESULT (WINAPI *get_Top)(IWebBrowser2 *This,long *pl);
      HRESULT (WINAPI *put_Top)(IWebBrowser2 *This,long Top);
      HRESULT (WINAPI *get_Width)(IWebBrowser2 *This,long *pl);
      HRESULT (WINAPI *put_Width)(IWebBrowser2 *This,long Width);
      HRESULT (WINAPI *get_Height)(IWebBrowser2 *This,long *pl);
      HRESULT (WINAPI *put_Height)(IWebBrowser2 *This,long Height);
      HRESULT (WINAPI *get_LocationName)(IWebBrowser2 *This,BSTR *LocationName);
      HRESULT (WINAPI *get_LocationURL)(IWebBrowser2 *This,BSTR *LocationURL);
      HRESULT (WINAPI *get_Busy)(IWebBrowser2 *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *Quit)(IWebBrowser2 *This);
      HRESULT (WINAPI *ClientToWindow)(IWebBrowser2 *This,int *pcx,int *pcy);
      HRESULT (WINAPI *PutProperty)(IWebBrowser2 *This,BSTR Property,VARIANT vtValue);
      HRESULT (WINAPI *GetProperty)(IWebBrowser2 *This,BSTR Property,VARIANT *pvtValue);
      HRESULT (WINAPI *get_Name)(IWebBrowser2 *This,BSTR *Name);
      HRESULT (WINAPI *get_HWND)(IWebBrowser2 *This,SHANDLE_PTR *pHWND);
      HRESULT (WINAPI *get_FullName)(IWebBrowser2 *This,BSTR *FullName);
      HRESULT (WINAPI *get_Path)(IWebBrowser2 *This,BSTR *Path);
      HRESULT (WINAPI *get_Visible)(IWebBrowser2 *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *put_Visible)(IWebBrowser2 *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_StatusBar)(IWebBrowser2 *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *put_StatusBar)(IWebBrowser2 *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_StatusText)(IWebBrowser2 *This,BSTR *StatusText);
      HRESULT (WINAPI *put_StatusText)(IWebBrowser2 *This,BSTR StatusText);
      HRESULT (WINAPI *get_ToolBar)(IWebBrowser2 *This,int *Value);
      HRESULT (WINAPI *put_ToolBar)(IWebBrowser2 *This,int Value);
      HRESULT (WINAPI *get_MenuBar)(IWebBrowser2 *This,VARIANT_BOOL *Value);
      HRESULT (WINAPI *put_MenuBar)(IWebBrowser2 *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_FullScreen)(IWebBrowser2 *This,VARIANT_BOOL *pbFullScreen);
      HRESULT (WINAPI *put_FullScreen)(IWebBrowser2 *This,VARIANT_BOOL bFullScreen);
      HRESULT (WINAPI *Navigate2)(IWebBrowser2 *This,VARIANT *URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
      HRESULT (WINAPI *QueryStatusWB)(IWebBrowser2 *This,OLECMDID cmdID,OLECMDF *pcmdf);
      HRESULT (WINAPI *ExecWB)(IWebBrowser2 *This,OLECMDID cmdID,OLECMDEXECOPT cmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut);
      HRESULT (WINAPI *ShowBrowserBar)(IWebBrowser2 *This,VARIANT *pvaClsid,VARIANT *pvarShow,VARIANT *pvarSize);
      HRESULT (WINAPI *get_ReadyState)(IWebBrowser2 *This,READYSTATE *plReadyState);
      HRESULT (WINAPI *get_Offline)(IWebBrowser2 *This,VARIANT_BOOL *pbOffline);
      HRESULT (WINAPI *put_Offline)(IWebBrowser2 *This,VARIANT_BOOL bOffline);
      HRESULT (WINAPI *get_Silent)(IWebBrowser2 *This,VARIANT_BOOL *pbSilent);
      HRESULT (WINAPI *put_Silent)(IWebBrowser2 *This,VARIANT_BOOL bSilent);
      HRESULT (WINAPI *get_RegisterAsBrowser)(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
      HRESULT (WINAPI *put_RegisterAsBrowser)(IWebBrowser2 *This,VARIANT_BOOL bRegister);
      HRESULT (WINAPI *get_RegisterAsDropTarget)(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
      HRESULT (WINAPI *put_RegisterAsDropTarget)(IWebBrowser2 *This,VARIANT_BOOL bRegister);
      HRESULT (WINAPI *get_TheaterMode)(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
      HRESULT (WINAPI *put_TheaterMode)(IWebBrowser2 *This,VARIANT_BOOL bRegister);
      HRESULT (WINAPI *get_AddressBar)(IWebBrowser2 *This,VARIANT_BOOL *Value);
      HRESULT (WINAPI *put_AddressBar)(IWebBrowser2 *This,VARIANT_BOOL Value);
      HRESULT (WINAPI *get_Resizable)(IWebBrowser2 *This,VARIANT_BOOL *Value);
      HRESULT (WINAPI *put_Resizable)(IWebBrowser2 *This,VARIANT_BOOL Value);
    END_INTERFACE
  } IWebBrowser2Vtbl;
  struct IWebBrowser2 {
    CONST_VTBL struct IWebBrowser2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWebBrowser2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWebBrowser2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWebBrowser2_Release(This) (This)->lpVtbl->Release(This)
#define IWebBrowser2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWebBrowser2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWebBrowser2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWebBrowser2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWebBrowser2_GoBack(This) (This)->lpVtbl->GoBack(This)
#define IWebBrowser2_GoForward(This) (This)->lpVtbl->GoForward(This)
#define IWebBrowser2_GoHome(This) (This)->lpVtbl->GoHome(This)
#define IWebBrowser2_GoSearch(This) (This)->lpVtbl->GoSearch(This)
#define IWebBrowser2_Navigate(This,URL,Flags,TargetFrameName,PostData,Headers) (This)->lpVtbl->Navigate(This,URL,Flags,TargetFrameName,PostData,Headers)
#define IWebBrowser2_Refresh(This) (This)->lpVtbl->Refresh(This)
#define IWebBrowser2_Refresh2(This,Level) (This)->lpVtbl->Refresh2(This,Level)
#define IWebBrowser2_Stop(This) (This)->lpVtbl->Stop(This)
#define IWebBrowser2_get_Application(This,ppDisp) (This)->lpVtbl->get_Application(This,ppDisp)
#define IWebBrowser2_get_Parent(This,ppDisp) (This)->lpVtbl->get_Parent(This,ppDisp)
#define IWebBrowser2_get_Container(This,ppDisp) (This)->lpVtbl->get_Container(This,ppDisp)
#define IWebBrowser2_get_Document(This,ppDisp) (This)->lpVtbl->get_Document(This,ppDisp)
#define IWebBrowser2_get_TopLevelContainer(This,pBool) (This)->lpVtbl->get_TopLevelContainer(This,pBool)
#define IWebBrowser2_get_Type(This,Type) (This)->lpVtbl->get_Type(This,Type)
#define IWebBrowser2_get_Left(This,pl) (This)->lpVtbl->get_Left(This,pl)
#define IWebBrowser2_put_Left(This,Left) (This)->lpVtbl->put_Left(This,Left)
#define IWebBrowser2_get_Top(This,pl) (This)->lpVtbl->get_Top(This,pl)
#define IWebBrowser2_put_Top(This,Top) (This)->lpVtbl->put_Top(This,Top)
#define IWebBrowser2_get_Width(This,pl) (This)->lpVtbl->get_Width(This,pl)
#define IWebBrowser2_put_Width(This,Width) (This)->lpVtbl->put_Width(This,Width)
#define IWebBrowser2_get_Height(This,pl) (This)->lpVtbl->get_Height(This,pl)
#define IWebBrowser2_put_Height(This,Height) (This)->lpVtbl->put_Height(This,Height)
#define IWebBrowser2_get_LocationName(This,LocationName) (This)->lpVtbl->get_LocationName(This,LocationName)
#define IWebBrowser2_get_LocationURL(This,LocationURL) (This)->lpVtbl->get_LocationURL(This,LocationURL)
#define IWebBrowser2_get_Busy(This,pBool) (This)->lpVtbl->get_Busy(This,pBool)
#define IWebBrowser2_Quit(This) (This)->lpVtbl->Quit(This)
#define IWebBrowser2_ClientToWindow(This,pcx,pcy) (This)->lpVtbl->ClientToWindow(This,pcx,pcy)
#define IWebBrowser2_PutProperty(This,Property,vtValue) (This)->lpVtbl->PutProperty(This,Property,vtValue)
#define IWebBrowser2_GetProperty(This,Property,pvtValue) (This)->lpVtbl->GetProperty(This,Property,pvtValue)
#define IWebBrowser2_get_Name(This,Name) (This)->lpVtbl->get_Name(This,Name)
#define IWebBrowser2_get_HWND(This,pHWND) (This)->lpVtbl->get_HWND(This,pHWND)
#define IWebBrowser2_get_FullName(This,FullName) (This)->lpVtbl->get_FullName(This,FullName)
#define IWebBrowser2_get_Path(This,Path) (This)->lpVtbl->get_Path(This,Path)
#define IWebBrowser2_get_Visible(This,pBool) (This)->lpVtbl->get_Visible(This,pBool)
#define IWebBrowser2_put_Visible(This,Value) (This)->lpVtbl->put_Visible(This,Value)
#define IWebBrowser2_get_StatusBar(This,pBool) (This)->lpVtbl->get_StatusBar(This,pBool)
#define IWebBrowser2_put_StatusBar(This,Value) (This)->lpVtbl->put_StatusBar(This,Value)
#define IWebBrowser2_get_StatusText(This,StatusText) (This)->lpVtbl->get_StatusText(This,StatusText)
#define IWebBrowser2_put_StatusText(This,StatusText) (This)->lpVtbl->put_StatusText(This,StatusText)
#define IWebBrowser2_get_ToolBar(This,Value) (This)->lpVtbl->get_ToolBar(This,Value)
#define IWebBrowser2_put_ToolBar(This,Value) (This)->lpVtbl->put_ToolBar(This,Value)
#define IWebBrowser2_get_MenuBar(This,Value) (This)->lpVtbl->get_MenuBar(This,Value)
#define IWebBrowser2_put_MenuBar(This,Value) (This)->lpVtbl->put_MenuBar(This,Value)
#define IWebBrowser2_get_FullScreen(This,pbFullScreen) (This)->lpVtbl->get_FullScreen(This,pbFullScreen)
#define IWebBrowser2_put_FullScreen(This,bFullScreen) (This)->lpVtbl->put_FullScreen(This,bFullScreen)
#define IWebBrowser2_Navigate2(This,URL,Flags,TargetFrameName,PostData,Headers) (This)->lpVtbl->Navigate2(This,URL,Flags,TargetFrameName,PostData,Headers)
#define IWebBrowser2_QueryStatusWB(This,cmdID,pcmdf) (This)->lpVtbl->QueryStatusWB(This,cmdID,pcmdf)
#define IWebBrowser2_ExecWB(This,cmdID,cmdexecopt,pvaIn,pvaOut) (This)->lpVtbl->ExecWB(This,cmdID,cmdexecopt,pvaIn,pvaOut)
#define IWebBrowser2_ShowBrowserBar(This,pvaClsid,pvarShow,pvarSize) (This)->lpVtbl->ShowBrowserBar(This,pvaClsid,pvarShow,pvarSize)
#define IWebBrowser2_get_ReadyState(This,plReadyState) (This)->lpVtbl->get_ReadyState(This,plReadyState)
#define IWebBrowser2_get_Offline(This,pbOffline) (This)->lpVtbl->get_Offline(This,pbOffline)
#define IWebBrowser2_put_Offline(This,bOffline) (This)->lpVtbl->put_Offline(This,bOffline)
#define IWebBrowser2_get_Silent(This,pbSilent) (This)->lpVtbl->get_Silent(This,pbSilent)
#define IWebBrowser2_put_Silent(This,bSilent) (This)->lpVtbl->put_Silent(This,bSilent)
#define IWebBrowser2_get_RegisterAsBrowser(This,pbRegister) (This)->lpVtbl->get_RegisterAsBrowser(This,pbRegister)
#define IWebBrowser2_put_RegisterAsBrowser(This,bRegister) (This)->lpVtbl->put_RegisterAsBrowser(This,bRegister)
#define IWebBrowser2_get_RegisterAsDropTarget(This,pbRegister) (This)->lpVtbl->get_RegisterAsDropTarget(This,pbRegister)
#define IWebBrowser2_put_RegisterAsDropTarget(This,bRegister) (This)->lpVtbl->put_RegisterAsDropTarget(This,bRegister)
#define IWebBrowser2_get_TheaterMode(This,pbRegister) (This)->lpVtbl->get_TheaterMode(This,pbRegister)
#define IWebBrowser2_put_TheaterMode(This,bRegister) (This)->lpVtbl->put_TheaterMode(This,bRegister)
#define IWebBrowser2_get_AddressBar(This,Value) (This)->lpVtbl->get_AddressBar(This,Value)
#define IWebBrowser2_put_AddressBar(This,Value) (This)->lpVtbl->put_AddressBar(This,Value)
#define IWebBrowser2_get_Resizable(This,Value) (This)->lpVtbl->get_Resizable(This,Value)
#define IWebBrowser2_put_Resizable(This,Value) (This)->lpVtbl->put_Resizable(This,Value)
#endif
#endif
  HRESULT WINAPI IWebBrowser2_Navigate2_Proxy(IWebBrowser2 *This,VARIANT *URL,VARIANT *Flags,VARIANT *TargetFrameName,VARIANT *PostData,VARIANT *Headers);
  void __RPC_STUB IWebBrowser2_Navigate2_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_QueryStatusWB_Proxy(IWebBrowser2 *This,OLECMDID cmdID,OLECMDF *pcmdf);
  void __RPC_STUB IWebBrowser2_QueryStatusWB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_ExecWB_Proxy(IWebBrowser2 *This,OLECMDID cmdID,OLECMDEXECOPT cmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut);
  void __RPC_STUB IWebBrowser2_ExecWB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_ShowBrowserBar_Proxy(IWebBrowser2 *This,VARIANT *pvaClsid,VARIANT *pvarShow,VARIANT *pvarSize);
  void __RPC_STUB IWebBrowser2_ShowBrowserBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_ReadyState_Proxy(IWebBrowser2 *This,READYSTATE *plReadyState);
  void __RPC_STUB IWebBrowser2_get_ReadyState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_Offline_Proxy(IWebBrowser2 *This,VARIANT_BOOL *pbOffline);
  void __RPC_STUB IWebBrowser2_get_Offline_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_Offline_Proxy(IWebBrowser2 *This,VARIANT_BOOL bOffline);
  void __RPC_STUB IWebBrowser2_put_Offline_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_Silent_Proxy(IWebBrowser2 *This,VARIANT_BOOL *pbSilent);
  void __RPC_STUB IWebBrowser2_get_Silent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_Silent_Proxy(IWebBrowser2 *This,VARIANT_BOOL bSilent);
  void __RPC_STUB IWebBrowser2_put_Silent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_RegisterAsBrowser_Proxy(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
  void __RPC_STUB IWebBrowser2_get_RegisterAsBrowser_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_RegisterAsBrowser_Proxy(IWebBrowser2 *This,VARIANT_BOOL bRegister);
  void __RPC_STUB IWebBrowser2_put_RegisterAsBrowser_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_RegisterAsDropTarget_Proxy(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
  void __RPC_STUB IWebBrowser2_get_RegisterAsDropTarget_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_RegisterAsDropTarget_Proxy(IWebBrowser2 *This,VARIANT_BOOL bRegister);
  void __RPC_STUB IWebBrowser2_put_RegisterAsDropTarget_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_TheaterMode_Proxy(IWebBrowser2 *This,VARIANT_BOOL *pbRegister);
  void __RPC_STUB IWebBrowser2_get_TheaterMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_TheaterMode_Proxy(IWebBrowser2 *This,VARIANT_BOOL bRegister);
  void __RPC_STUB IWebBrowser2_put_TheaterMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_AddressBar_Proxy(IWebBrowser2 *This,VARIANT_BOOL *Value);
  void __RPC_STUB IWebBrowser2_get_AddressBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_AddressBar_Proxy(IWebBrowser2 *This,VARIANT_BOOL Value);
  void __RPC_STUB IWebBrowser2_put_AddressBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_get_Resizable_Proxy(IWebBrowser2 *This,VARIANT_BOOL *Value);
  void __RPC_STUB IWebBrowser2_get_Resizable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebBrowser2_put_Resizable_Proxy(IWebBrowser2 *This,VARIANT_BOOL Value);
  void __RPC_STUB IWebBrowser2_put_Resizable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __DWebBrowserEvents2_DISPINTERFACE_DEFINED__
#define __DWebBrowserEvents2_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DWebBrowserEvents2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DWebBrowserEvents2 : public IDispatch {
  };
#else
  typedef struct DWebBrowserEvents2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DWebBrowserEvents2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DWebBrowserEvents2 *This);
      ULONG (WINAPI *Release)(DWebBrowserEvents2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DWebBrowserEvents2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DWebBrowserEvents2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DWebBrowserEvents2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DWebBrowserEvents2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DWebBrowserEvents2Vtbl;
  struct DWebBrowserEvents2 {
    CONST_VTBL struct DWebBrowserEvents2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DWebBrowserEvents2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DWebBrowserEvents2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DWebBrowserEvents2_Release(This) (This)->lpVtbl->Release(This)
#define DWebBrowserEvents2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DWebBrowserEvents2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DWebBrowserEvents2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DWebBrowserEvents2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

  EXTERN_C const CLSID CLSID_WebBrowser_V1;
#ifdef __cplusplus
  class WebBrowser_V1;
#endif
  EXTERN_C const CLSID CLSID_WebBrowser;
#ifdef __cplusplus
  class WebBrowser;
#endif
  EXTERN_C const CLSID CLSID_InternetExplorer;
#ifdef __cplusplus
  class InternetExplorer;
#endif
  EXTERN_C const CLSID CLSID_ShellBrowserWindow;
#ifdef __cplusplus
  class ShellBrowserWindow;
#endif

#ifndef __DShellWindowsEvents_DISPINTERFACE_DEFINED__
#define __DShellWindowsEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DShellWindowsEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DShellWindowsEvents : public IDispatch {
  };
#else
  typedef struct DShellWindowsEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DShellWindowsEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DShellWindowsEvents *This);
      ULONG (WINAPI *Release)(DShellWindowsEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DShellWindowsEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DShellWindowsEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DShellWindowsEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DShellWindowsEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DShellWindowsEventsVtbl;
  struct DShellWindowsEvents {
    CONST_VTBL struct DShellWindowsEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DShellWindowsEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DShellWindowsEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DShellWindowsEvents_Release(This) (This)->lpVtbl->Release(This)
#define DShellWindowsEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DShellWindowsEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DShellWindowsEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DShellWindowsEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

#ifndef __IShellWindows_INTERFACE_DEFINED__
#define __IShellWindows_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellWindows;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellWindows : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(long *Count) = 0;
    virtual HRESULT WINAPI Item(VARIANT index,IDispatch **Folder) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppunk) = 0;
    virtual HRESULT WINAPI Register(IDispatch *pid,long hwnd,int swClass,long *plCookie) = 0;
    virtual HRESULT WINAPI RegisterPending(long lThreadId,VARIANT *pvarloc,VARIANT *pvarlocRoot,int swClass,long *plCookie) = 0;
    virtual HRESULT WINAPI Revoke(long lCookie) = 0;
    virtual HRESULT WINAPI OnNavigate(long lCookie,VARIANT *pvarLoc) = 0;
    virtual HRESULT WINAPI OnActivated(long lCookie,VARIANT_BOOL fActive) = 0;
    virtual HRESULT WINAPI FindWindowSW(VARIANT *pvarLoc,VARIANT *pvarLocRoot,int swClass,long *phwnd,int swfwOptions,IDispatch **ppdispOut) = 0;
    virtual HRESULT WINAPI OnCreated(long lCookie,IUnknown *punk) = 0;
    virtual HRESULT WINAPI ProcessAttachDetach(VARIANT_BOOL fAttach) = 0;
  };
#else
  typedef struct IShellWindowsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellWindows *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellWindows *This);
      ULONG (WINAPI *Release)(IShellWindows *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellWindows *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellWindows *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellWindows *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellWindows *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(IShellWindows *This,long *Count);
      HRESULT (WINAPI *Item)(IShellWindows *This,VARIANT index,IDispatch **Folder);
      HRESULT (WINAPI *_NewEnum)(IShellWindows *This,IUnknown **ppunk);
      HRESULT (WINAPI *Register)(IShellWindows *This,IDispatch *pid,long hwnd,int swClass,long *plCookie);
      HRESULT (WINAPI *RegisterPending)(IShellWindows *This,long lThreadId,VARIANT *pvarloc,VARIANT *pvarlocRoot,int swClass,long *plCookie);
      HRESULT (WINAPI *Revoke)(IShellWindows *This,long lCookie);
      HRESULT (WINAPI *OnNavigate)(IShellWindows *This,long lCookie,VARIANT *pvarLoc);
      HRESULT (WINAPI *OnActivated)(IShellWindows *This,long lCookie,VARIANT_BOOL fActive);
      HRESULT (WINAPI *FindWindowSW)(IShellWindows *This,VARIANT *pvarLoc,VARIANT *pvarLocRoot,int swClass,long *phwnd,int swfwOptions,IDispatch **ppdispOut);
      HRESULT (WINAPI *OnCreated)(IShellWindows *This,long lCookie,IUnknown *punk);
      HRESULT (WINAPI *ProcessAttachDetach)(IShellWindows *This,VARIANT_BOOL fAttach);
    END_INTERFACE
  } IShellWindowsVtbl;
  struct IShellWindows {
    CONST_VTBL struct IShellWindowsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellWindows_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellWindows_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellWindows_Release(This) (This)->lpVtbl->Release(This)
#define IShellWindows_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellWindows_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellWindows_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellWindows_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellWindows_get_Count(This,Count) (This)->lpVtbl->get_Count(This,Count)
#define IShellWindows_Item(This,index,Folder) (This)->lpVtbl->Item(This,index,Folder)
#define IShellWindows__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#define IShellWindows_Register(This,pid,hwnd,swClass,plCookie) (This)->lpVtbl->Register(This,pid,hwnd,swClass,plCookie)
#define IShellWindows_RegisterPending(This,lThreadId,pvarloc,pvarlocRoot,swClass,plCookie) (This)->lpVtbl->RegisterPending(This,lThreadId,pvarloc,pvarlocRoot,swClass,plCookie)
#define IShellWindows_Revoke(This,lCookie) (This)->lpVtbl->Revoke(This,lCookie)
#define IShellWindows_OnNavigate(This,lCookie,pvarLoc) (This)->lpVtbl->OnNavigate(This,lCookie,pvarLoc)
#define IShellWindows_OnActivated(This,lCookie,fActive) (This)->lpVtbl->OnActivated(This,lCookie,fActive)
#define IShellWindows_FindWindowSW(This,pvarLoc,pvarLocRoot,swClass,phwnd,swfwOptions,ppdispOut) (This)->lpVtbl->FindWindowSW(This,pvarLoc,pvarLocRoot,swClass,phwnd,swfwOptions,ppdispOut)
#define IShellWindows_OnCreated(This,lCookie,punk) (This)->lpVtbl->OnCreated(This,lCookie,punk)
#define IShellWindows_ProcessAttachDetach(This,fAttach) (This)->lpVtbl->ProcessAttachDetach(This,fAttach)
#endif
#endif
  HRESULT WINAPI IShellWindows_get_Count_Proxy(IShellWindows *This,long *Count);
  void __RPC_STUB IShellWindows_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_Item_Proxy(IShellWindows *This,VARIANT index,IDispatch **Folder);
  void __RPC_STUB IShellWindows_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows__NewEnum_Proxy(IShellWindows *This,IUnknown **ppunk);
  void __RPC_STUB IShellWindows__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_Register_Proxy(IShellWindows *This,IDispatch *pid,long hwnd,int swClass,long *plCookie);
  void __RPC_STUB IShellWindows_Register_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_RegisterPending_Proxy(IShellWindows *This,long lThreadId,VARIANT *pvarloc,VARIANT *pvarlocRoot,int swClass,long *plCookie);
  void __RPC_STUB IShellWindows_RegisterPending_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_Revoke_Proxy(IShellWindows *This,long lCookie);
  void __RPC_STUB IShellWindows_Revoke_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_OnNavigate_Proxy(IShellWindows *This,long lCookie,VARIANT *pvarLoc);
  void __RPC_STUB IShellWindows_OnNavigate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_OnActivated_Proxy(IShellWindows *This,long lCookie,VARIANT_BOOL fActive);
  void __RPC_STUB IShellWindows_OnActivated_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_FindWindowSW_Proxy(IShellWindows *This,VARIANT *pvarLoc,VARIANT *pvarLocRoot,int swClass,long *phwnd,int swfwOptions,IDispatch **ppdispOut);
  void __RPC_STUB IShellWindows_FindWindowSW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_OnCreated_Proxy(IShellWindows *This,long lCookie,IUnknown *punk);
  void __RPC_STUB IShellWindows_OnCreated_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellWindows_ProcessAttachDetach_Proxy(IShellWindows *This,VARIANT_BOOL fAttach);
  void __RPC_STUB IShellWindows_ProcessAttachDetach_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellWindows;
#ifdef __cplusplus
  class ShellWindows;
#endif

#ifndef __IShellUIHelper_INTERFACE_DEFINED__
#define __IShellUIHelper_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellUIHelper;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellUIHelper : public IDispatch {
  public:
    virtual HRESULT WINAPI ResetFirstBootMode(void) = 0;
    virtual HRESULT WINAPI ResetSafeMode(void) = 0;
    virtual HRESULT WINAPI RefreshOfflineDesktop(void) = 0;
    virtual HRESULT WINAPI AddFavorite(BSTR URL,VARIANT *Title) = 0;
    virtual HRESULT WINAPI AddChannel(BSTR URL) = 0;
    virtual HRESULT WINAPI AddDesktopComponent(BSTR URL,BSTR Type,VARIANT *Left,VARIANT *Top,VARIANT *Width,VARIANT *Height) = 0;
    virtual HRESULT WINAPI IsSubscribed(BSTR URL,VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI NavigateAndFind(BSTR URL,BSTR strQuery,VARIANT *varTargetFrame) = 0;
    virtual HRESULT WINAPI ImportExportFavorites(VARIANT_BOOL fImport,BSTR strImpExpPath) = 0;
    virtual HRESULT WINAPI AutoCompleteSaveForm(VARIANT *Form) = 0;
    virtual HRESULT WINAPI AutoScan(BSTR strSearch,BSTR strFailureUrl,VARIANT *pvarTargetFrame) = 0;
    virtual HRESULT WINAPI AutoCompleteAttach(VARIANT *Reserved) = 0;
    virtual HRESULT WINAPI ShowBrowserUI(BSTR bstrName,VARIANT *pvarIn,VARIANT *pvarOut) = 0;
  };
#else
  typedef struct IShellUIHelperVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellUIHelper *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellUIHelper *This);
      ULONG (WINAPI *Release)(IShellUIHelper *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellUIHelper *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellUIHelper *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellUIHelper *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellUIHelper *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *ResetFirstBootMode)(IShellUIHelper *This);
      HRESULT (WINAPI *ResetSafeMode)(IShellUIHelper *This);
      HRESULT (WINAPI *RefreshOfflineDesktop)(IShellUIHelper *This);
      HRESULT (WINAPI *AddFavorite)(IShellUIHelper *This,BSTR URL,VARIANT *Title);
      HRESULT (WINAPI *AddChannel)(IShellUIHelper *This,BSTR URL);
      HRESULT (WINAPI *AddDesktopComponent)(IShellUIHelper *This,BSTR URL,BSTR Type,VARIANT *Left,VARIANT *Top,VARIANT *Width,VARIANT *Height);
      HRESULT (WINAPI *IsSubscribed)(IShellUIHelper *This,BSTR URL,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *NavigateAndFind)(IShellUIHelper *This,BSTR URL,BSTR strQuery,VARIANT *varTargetFrame);
      HRESULT (WINAPI *ImportExportFavorites)(IShellUIHelper *This,VARIANT_BOOL fImport,BSTR strImpExpPath);
      HRESULT (WINAPI *AutoCompleteSaveForm)(IShellUIHelper *This,VARIANT *Form);
      HRESULT (WINAPI *AutoScan)(IShellUIHelper *This,BSTR strSearch,BSTR strFailureUrl,VARIANT *pvarTargetFrame);
      HRESULT (WINAPI *AutoCompleteAttach)(IShellUIHelper *This,VARIANT *Reserved);
      HRESULT (WINAPI *ShowBrowserUI)(IShellUIHelper *This,BSTR bstrName,VARIANT *pvarIn,VARIANT *pvarOut);
    END_INTERFACE
  } IShellUIHelperVtbl;
  struct IShellUIHelper {
    CONST_VTBL struct IShellUIHelperVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellUIHelper_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellUIHelper_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellUIHelper_Release(This) (This)->lpVtbl->Release(This)
#define IShellUIHelper_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellUIHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellUIHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellUIHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellUIHelper_ResetFirstBootMode(This) (This)->lpVtbl->ResetFirstBootMode(This)
#define IShellUIHelper_ResetSafeMode(This) (This)->lpVtbl->ResetSafeMode(This)
#define IShellUIHelper_RefreshOfflineDesktop(This) (This)->lpVtbl->RefreshOfflineDesktop(This)
#define IShellUIHelper_AddFavorite(This,URL,Title) (This)->lpVtbl->AddFavorite(This,URL,Title)
#define IShellUIHelper_AddChannel(This,URL) (This)->lpVtbl->AddChannel(This,URL)
#define IShellUIHelper_AddDesktopComponent(This,URL,Type,Left,Top,Width,Height) (This)->lpVtbl->AddDesktopComponent(This,URL,Type,Left,Top,Width,Height)
#define IShellUIHelper_IsSubscribed(This,URL,pBool) (This)->lpVtbl->IsSubscribed(This,URL,pBool)
#define IShellUIHelper_NavigateAndFind(This,URL,strQuery,varTargetFrame) (This)->lpVtbl->NavigateAndFind(This,URL,strQuery,varTargetFrame)
#define IShellUIHelper_ImportExportFavorites(This,fImport,strImpExpPath) (This)->lpVtbl->ImportExportFavorites(This,fImport,strImpExpPath)
#define IShellUIHelper_AutoCompleteSaveForm(This,Form) (This)->lpVtbl->AutoCompleteSaveForm(This,Form)
#define IShellUIHelper_AutoScan(This,strSearch,strFailureUrl,pvarTargetFrame) (This)->lpVtbl->AutoScan(This,strSearch,strFailureUrl,pvarTargetFrame)
#define IShellUIHelper_AutoCompleteAttach(This,Reserved) (This)->lpVtbl->AutoCompleteAttach(This,Reserved)
#define IShellUIHelper_ShowBrowserUI(This,bstrName,pvarIn,pvarOut) (This)->lpVtbl->ShowBrowserUI(This,bstrName,pvarIn,pvarOut)
#endif
#endif
  HRESULT WINAPI IShellUIHelper_ResetFirstBootMode_Proxy(IShellUIHelper *This);
  void __RPC_STUB IShellUIHelper_ResetFirstBootMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_ResetSafeMode_Proxy(IShellUIHelper *This);
  void __RPC_STUB IShellUIHelper_ResetSafeMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_RefreshOfflineDesktop_Proxy(IShellUIHelper *This);
  void __RPC_STUB IShellUIHelper_RefreshOfflineDesktop_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AddFavorite_Proxy(IShellUIHelper *This,BSTR URL,VARIANT *Title);
  void __RPC_STUB IShellUIHelper_AddFavorite_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AddChannel_Proxy(IShellUIHelper *This,BSTR URL);
  void __RPC_STUB IShellUIHelper_AddChannel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AddDesktopComponent_Proxy(IShellUIHelper *This,BSTR URL,BSTR Type,VARIANT *Left,VARIANT *Top,VARIANT *Width,VARIANT *Height);
  void __RPC_STUB IShellUIHelper_AddDesktopComponent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_IsSubscribed_Proxy(IShellUIHelper *This,BSTR URL,VARIANT_BOOL *pBool);
  void __RPC_STUB IShellUIHelper_IsSubscribed_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_NavigateAndFind_Proxy(IShellUIHelper *This,BSTR URL,BSTR strQuery,VARIANT *varTargetFrame);
  void __RPC_STUB IShellUIHelper_NavigateAndFind_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_ImportExportFavorites_Proxy(IShellUIHelper *This,VARIANT_BOOL fImport,BSTR strImpExpPath);
  void __RPC_STUB IShellUIHelper_ImportExportFavorites_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AutoCompleteSaveForm_Proxy(IShellUIHelper *This,VARIANT *Form);
  void __RPC_STUB IShellUIHelper_AutoCompleteSaveForm_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AutoScan_Proxy(IShellUIHelper *This,BSTR strSearch,BSTR strFailureUrl,VARIANT *pvarTargetFrame);
  void __RPC_STUB IShellUIHelper_AutoScan_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_AutoCompleteAttach_Proxy(IShellUIHelper *This,VARIANT *Reserved);
  void __RPC_STUB IShellUIHelper_AutoCompleteAttach_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellUIHelper_ShowBrowserUI_Proxy(IShellUIHelper *This,BSTR bstrName,VARIANT *pvarIn,VARIANT *pvarOut);
  void __RPC_STUB IShellUIHelper_ShowBrowserUI_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellUIHelper;
#ifdef __cplusplus
  class ShellUIHelper;
#endif

#ifndef __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__
#define __DShellNameSpaceEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DShellNameSpaceEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DShellNameSpaceEvents : public IDispatch {
  };
#else
  typedef struct DShellNameSpaceEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DShellNameSpaceEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DShellNameSpaceEvents *This);
      ULONG (WINAPI *Release)(DShellNameSpaceEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DShellNameSpaceEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DShellNameSpaceEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DShellNameSpaceEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DShellNameSpaceEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DShellNameSpaceEventsVtbl;
  struct DShellNameSpaceEvents {
    CONST_VTBL struct DShellNameSpaceEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DShellNameSpaceEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DShellNameSpaceEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DShellNameSpaceEvents_Release(This) (This)->lpVtbl->Release(This)
#define DShellNameSpaceEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DShellNameSpaceEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DShellNameSpaceEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DShellNameSpaceEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

#ifndef __IShellFavoritesNameSpace_INTERFACE_DEFINED__
#define __IShellFavoritesNameSpace_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellFavoritesNameSpace;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellFavoritesNameSpace : public IDispatch {
  public:
    virtual HRESULT WINAPI MoveSelectionUp(void) = 0;
    virtual HRESULT WINAPI MoveSelectionDown(void) = 0;
    virtual HRESULT WINAPI ResetSort(void) = 0;
    virtual HRESULT WINAPI NewFolder(void) = 0;
    virtual HRESULT WINAPI Synchronize(void) = 0;
    virtual HRESULT WINAPI Import(void) = 0;
    virtual HRESULT WINAPI Export(void) = 0;
    virtual HRESULT WINAPI InvokeContextMenuCommand(BSTR strCommand) = 0;
    virtual HRESULT WINAPI MoveSelectionTo(void) = 0;
    virtual HRESULT WINAPI get_SubscriptionsEnabled(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI CreateSubscriptionForSelection(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI DeleteSubscriptionForSelection(VARIANT_BOOL *pBool) = 0;
    virtual HRESULT WINAPI SetRoot(BSTR bstrFullPath) = 0;
  };
#else
  typedef struct IShellFavoritesNameSpaceVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellFavoritesNameSpace *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellFavoritesNameSpace *This);
      ULONG (WINAPI *Release)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellFavoritesNameSpace *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellFavoritesNameSpace *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellFavoritesNameSpace *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellFavoritesNameSpace *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *MoveSelectionUp)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *MoveSelectionDown)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *ResetSort)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *NewFolder)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *Synchronize)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *Import)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *Export)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *InvokeContextMenuCommand)(IShellFavoritesNameSpace *This,BSTR strCommand);
      HRESULT (WINAPI *MoveSelectionTo)(IShellFavoritesNameSpace *This);
      HRESULT (WINAPI *get_SubscriptionsEnabled)(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *CreateSubscriptionForSelection)(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *DeleteSubscriptionForSelection)(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *SetRoot)(IShellFavoritesNameSpace *This,BSTR bstrFullPath);
    END_INTERFACE
  } IShellFavoritesNameSpaceVtbl;
  struct IShellFavoritesNameSpace {
    CONST_VTBL struct IShellFavoritesNameSpaceVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellFavoritesNameSpace_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellFavoritesNameSpace_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellFavoritesNameSpace_Release(This) (This)->lpVtbl->Release(This)
#define IShellFavoritesNameSpace_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellFavoritesNameSpace_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellFavoritesNameSpace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellFavoritesNameSpace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellFavoritesNameSpace_MoveSelectionUp(This) (This)->lpVtbl->MoveSelectionUp(This)
#define IShellFavoritesNameSpace_MoveSelectionDown(This) (This)->lpVtbl->MoveSelectionDown(This)
#define IShellFavoritesNameSpace_ResetSort(This) (This)->lpVtbl->ResetSort(This)
#define IShellFavoritesNameSpace_NewFolder(This) (This)->lpVtbl->NewFolder(This)
#define IShellFavoritesNameSpace_Synchronize(This) (This)->lpVtbl->Synchronize(This)
#define IShellFavoritesNameSpace_Import(This) (This)->lpVtbl->Import(This)
#define IShellFavoritesNameSpace_Export(This) (This)->lpVtbl->Export(This)
#define IShellFavoritesNameSpace_InvokeContextMenuCommand(This,strCommand) (This)->lpVtbl->InvokeContextMenuCommand(This,strCommand)
#define IShellFavoritesNameSpace_MoveSelectionTo(This) (This)->lpVtbl->MoveSelectionTo(This)
#define IShellFavoritesNameSpace_get_SubscriptionsEnabled(This,pBool) (This)->lpVtbl->get_SubscriptionsEnabled(This,pBool)
#define IShellFavoritesNameSpace_CreateSubscriptionForSelection(This,pBool) (This)->lpVtbl->CreateSubscriptionForSelection(This,pBool)
#define IShellFavoritesNameSpace_DeleteSubscriptionForSelection(This,pBool) (This)->lpVtbl->DeleteSubscriptionForSelection(This,pBool)
#define IShellFavoritesNameSpace_SetRoot(This,bstrFullPath) (This)->lpVtbl->SetRoot(This,bstrFullPath)
#endif
#endif
  HRESULT WINAPI IShellFavoritesNameSpace_MoveSelectionUp_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_MoveSelectionUp_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_MoveSelectionDown_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_MoveSelectionDown_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_ResetSort_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_ResetSort_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_NewFolder_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_NewFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_Synchronize_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_Synchronize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_Import_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_Import_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_Export_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_Export_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_InvokeContextMenuCommand_Proxy(IShellFavoritesNameSpace *This,BSTR strCommand);
  void __RPC_STUB IShellFavoritesNameSpace_InvokeContextMenuCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_MoveSelectionTo_Proxy(IShellFavoritesNameSpace *This);
  void __RPC_STUB IShellFavoritesNameSpace_MoveSelectionTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_get_SubscriptionsEnabled_Proxy(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IShellFavoritesNameSpace_get_SubscriptionsEnabled_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_CreateSubscriptionForSelection_Proxy(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IShellFavoritesNameSpace_CreateSubscriptionForSelection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_DeleteSubscriptionForSelection_Proxy(IShellFavoritesNameSpace *This,VARIANT_BOOL *pBool);
  void __RPC_STUB IShellFavoritesNameSpace_DeleteSubscriptionForSelection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFavoritesNameSpace_SetRoot_Proxy(IShellFavoritesNameSpace *This,BSTR bstrFullPath);
  void __RPC_STUB IShellFavoritesNameSpace_SetRoot_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellNameSpace_INTERFACE_DEFINED__
#define __IShellNameSpace_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellNameSpace;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellNameSpace : public IShellFavoritesNameSpace {
  public:
    virtual HRESULT WINAPI get_EnumOptions(LONG *pgrfEnumFlags) = 0;
    virtual HRESULT WINAPI put_EnumOptions(LONG lVal) = 0;
    virtual HRESULT WINAPI get_SelectedItem(IDispatch **pItem) = 0;
    virtual HRESULT WINAPI put_SelectedItem(IDispatch *pItem) = 0;
    virtual HRESULT WINAPI get_Root(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Root(VARIANT var) = 0;
    virtual HRESULT WINAPI get_Depth(int *piDepth) = 0;
    virtual HRESULT WINAPI put_Depth(int iDepth) = 0;
    virtual HRESULT WINAPI get_Mode(UINT *puMode) = 0;
    virtual HRESULT WINAPI put_Mode(UINT uMode) = 0;
    virtual HRESULT WINAPI get_Flags(DWORD *pdwFlags) = 0;
    virtual HRESULT WINAPI put_Flags(DWORD dwFlags) = 0;
    virtual HRESULT WINAPI put_TVFlags(DWORD dwFlags) = 0;
    virtual HRESULT WINAPI get_TVFlags(DWORD *dwFlags) = 0;
    virtual HRESULT WINAPI get_Columns(BSTR *bstrColumns) = 0;
    virtual HRESULT WINAPI put_Columns(BSTR bstrColumns) = 0;
    virtual HRESULT WINAPI get_CountViewTypes(int *piTypes) = 0;
    virtual HRESULT WINAPI SetViewType(int iType) = 0;
    virtual HRESULT WINAPI SelectedItems(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI Expand(VARIANT var,int iDepth) = 0;
    virtual HRESULT WINAPI UnselectAll(void) = 0;
  };
#else
  typedef struct IShellNameSpaceVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellNameSpace *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellNameSpace *This);
      ULONG (WINAPI *Release)(IShellNameSpace *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellNameSpace *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellNameSpace *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellNameSpace *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellNameSpace *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *MoveSelectionUp)(IShellNameSpace *This);
      HRESULT (WINAPI *MoveSelectionDown)(IShellNameSpace *This);
      HRESULT (WINAPI *ResetSort)(IShellNameSpace *This);
      HRESULT (WINAPI *NewFolder)(IShellNameSpace *This);
      HRESULT (WINAPI *Synchronize)(IShellNameSpace *This);
      HRESULT (WINAPI *Import)(IShellNameSpace *This);
      HRESULT (WINAPI *Export)(IShellNameSpace *This);
      HRESULT (WINAPI *InvokeContextMenuCommand)(IShellNameSpace *This,BSTR strCommand);
      HRESULT (WINAPI *MoveSelectionTo)(IShellNameSpace *This);
      HRESULT (WINAPI *get_SubscriptionsEnabled)(IShellNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *CreateSubscriptionForSelection)(IShellNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *DeleteSubscriptionForSelection)(IShellNameSpace *This,VARIANT_BOOL *pBool);
      HRESULT (WINAPI *SetRoot)(IShellNameSpace *This,BSTR bstrFullPath);
      HRESULT (WINAPI *get_EnumOptions)(IShellNameSpace *This,LONG *pgrfEnumFlags);
      HRESULT (WINAPI *put_EnumOptions)(IShellNameSpace *This,LONG lVal);
      HRESULT (WINAPI *get_SelectedItem)(IShellNameSpace *This,IDispatch **pItem);
      HRESULT (WINAPI *put_SelectedItem)(IShellNameSpace *This,IDispatch *pItem);
      HRESULT (WINAPI *get_Root)(IShellNameSpace *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Root)(IShellNameSpace *This,VARIANT var);
      HRESULT (WINAPI *get_Depth)(IShellNameSpace *This,int *piDepth);
      HRESULT (WINAPI *put_Depth)(IShellNameSpace *This,int iDepth);
      HRESULT (WINAPI *get_Mode)(IShellNameSpace *This,UINT *puMode);
      HRESULT (WINAPI *put_Mode)(IShellNameSpace *This,UINT uMode);
      HRESULT (WINAPI *get_Flags)(IShellNameSpace *This,DWORD *pdwFlags);
      HRESULT (WINAPI *put_Flags)(IShellNameSpace *This,DWORD dwFlags);
      HRESULT (WINAPI *put_TVFlags)(IShellNameSpace *This,DWORD dwFlags);
      HRESULT (WINAPI *get_TVFlags)(IShellNameSpace *This,DWORD *dwFlags);
      HRESULT (WINAPI *get_Columns)(IShellNameSpace *This,BSTR *bstrColumns);
      HRESULT (WINAPI *put_Columns)(IShellNameSpace *This,BSTR bstrColumns);
      HRESULT (WINAPI *get_CountViewTypes)(IShellNameSpace *This,int *piTypes);
      HRESULT (WINAPI *SetViewType)(IShellNameSpace *This,int iType);
      HRESULT (WINAPI *SelectedItems)(IShellNameSpace *This,IDispatch **ppid);
      HRESULT (WINAPI *Expand)(IShellNameSpace *This,VARIANT var,int iDepth);
      HRESULT (WINAPI *UnselectAll)(IShellNameSpace *This);
    END_INTERFACE
  } IShellNameSpaceVtbl;
  struct IShellNameSpace {
    CONST_VTBL struct IShellNameSpaceVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellNameSpace_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellNameSpace_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellNameSpace_Release(This) (This)->lpVtbl->Release(This)
#define IShellNameSpace_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellNameSpace_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellNameSpace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellNameSpace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellNameSpace_MoveSelectionUp(This) (This)->lpVtbl->MoveSelectionUp(This)
#define IShellNameSpace_MoveSelectionDown(This) (This)->lpVtbl->MoveSelectionDown(This)
#define IShellNameSpace_ResetSort(This) (This)->lpVtbl->ResetSort(This)
#define IShellNameSpace_NewFolder(This) (This)->lpVtbl->NewFolder(This)
#define IShellNameSpace_Synchronize(This) (This)->lpVtbl->Synchronize(This)
#define IShellNameSpace_Import(This) (This)->lpVtbl->Import(This)
#define IShellNameSpace_Export(This) (This)->lpVtbl->Export(This)
#define IShellNameSpace_InvokeContextMenuCommand(This,strCommand) (This)->lpVtbl->InvokeContextMenuCommand(This,strCommand)
#define IShellNameSpace_MoveSelectionTo(This) (This)->lpVtbl->MoveSelectionTo(This)
#define IShellNameSpace_get_SubscriptionsEnabled(This,pBool) (This)->lpVtbl->get_SubscriptionsEnabled(This,pBool)
#define IShellNameSpace_CreateSubscriptionForSelection(This,pBool) (This)->lpVtbl->CreateSubscriptionForSelection(This,pBool)
#define IShellNameSpace_DeleteSubscriptionForSelection(This,pBool) (This)->lpVtbl->DeleteSubscriptionForSelection(This,pBool)
#define IShellNameSpace_SetRoot(This,bstrFullPath) (This)->lpVtbl->SetRoot(This,bstrFullPath)
#define IShellNameSpace_get_EnumOptions(This,pgrfEnumFlags) (This)->lpVtbl->get_EnumOptions(This,pgrfEnumFlags)
#define IShellNameSpace_put_EnumOptions(This,lVal) (This)->lpVtbl->put_EnumOptions(This,lVal)
#define IShellNameSpace_get_SelectedItem(This,pItem) (This)->lpVtbl->get_SelectedItem(This,pItem)
#define IShellNameSpace_put_SelectedItem(This,pItem) (This)->lpVtbl->put_SelectedItem(This,pItem)
#define IShellNameSpace_get_Root(This,pvar) (This)->lpVtbl->get_Root(This,pvar)
#define IShellNameSpace_put_Root(This,var) (This)->lpVtbl->put_Root(This,var)
#define IShellNameSpace_get_Depth(This,piDepth) (This)->lpVtbl->get_Depth(This,piDepth)
#define IShellNameSpace_put_Depth(This,iDepth) (This)->lpVtbl->put_Depth(This,iDepth)
#define IShellNameSpace_get_Mode(This,puMode) (This)->lpVtbl->get_Mode(This,puMode)
#define IShellNameSpace_put_Mode(This,uMode) (This)->lpVtbl->put_Mode(This,uMode)
#define IShellNameSpace_get_Flags(This,pdwFlags) (This)->lpVtbl->get_Flags(This,pdwFlags)
#define IShellNameSpace_put_Flags(This,dwFlags) (This)->lpVtbl->put_Flags(This,dwFlags)
#define IShellNameSpace_put_TVFlags(This,dwFlags) (This)->lpVtbl->put_TVFlags(This,dwFlags)
#define IShellNameSpace_get_TVFlags(This,dwFlags) (This)->lpVtbl->get_TVFlags(This,dwFlags)
#define IShellNameSpace_get_Columns(This,bstrColumns) (This)->lpVtbl->get_Columns(This,bstrColumns)
#define IShellNameSpace_put_Columns(This,bstrColumns) (This)->lpVtbl->put_Columns(This,bstrColumns)
#define IShellNameSpace_get_CountViewTypes(This,piTypes) (This)->lpVtbl->get_CountViewTypes(This,piTypes)
#define IShellNameSpace_SetViewType(This,iType) (This)->lpVtbl->SetViewType(This,iType)
#define IShellNameSpace_SelectedItems(This,ppid) (This)->lpVtbl->SelectedItems(This,ppid)
#define IShellNameSpace_Expand(This,var,iDepth) (This)->lpVtbl->Expand(This,var,iDepth)
#define IShellNameSpace_UnselectAll(This) (This)->lpVtbl->UnselectAll(This)
#endif
#endif
  HRESULT WINAPI IShellNameSpace_get_EnumOptions_Proxy(IShellNameSpace *This,LONG *pgrfEnumFlags);
  void __RPC_STUB IShellNameSpace_get_EnumOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_EnumOptions_Proxy(IShellNameSpace *This,LONG lVal);
  void __RPC_STUB IShellNameSpace_put_EnumOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_SelectedItem_Proxy(IShellNameSpace *This,IDispatch **pItem);
  void __RPC_STUB IShellNameSpace_get_SelectedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_SelectedItem_Proxy(IShellNameSpace *This,IDispatch *pItem);
  void __RPC_STUB IShellNameSpace_put_SelectedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_Root_Proxy(IShellNameSpace *This,VARIANT *pvar);
  void __RPC_STUB IShellNameSpace_get_Root_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_Root_Proxy(IShellNameSpace *This,VARIANT var);
  void __RPC_STUB IShellNameSpace_put_Root_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_Depth_Proxy(IShellNameSpace *This,int *piDepth);
  void __RPC_STUB IShellNameSpace_get_Depth_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_Depth_Proxy(IShellNameSpace *This,int iDepth);
  void __RPC_STUB IShellNameSpace_put_Depth_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_Mode_Proxy(IShellNameSpace *This,UINT *puMode);
  void __RPC_STUB IShellNameSpace_get_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_Mode_Proxy(IShellNameSpace *This,UINT uMode);
  void __RPC_STUB IShellNameSpace_put_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_Flags_Proxy(IShellNameSpace *This,DWORD *pdwFlags);
  void __RPC_STUB IShellNameSpace_get_Flags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_Flags_Proxy(IShellNameSpace *This,DWORD dwFlags);
  void __RPC_STUB IShellNameSpace_put_Flags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_TVFlags_Proxy(IShellNameSpace *This,DWORD dwFlags);
  void __RPC_STUB IShellNameSpace_put_TVFlags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_TVFlags_Proxy(IShellNameSpace *This,DWORD *dwFlags);
  void __RPC_STUB IShellNameSpace_get_TVFlags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_Columns_Proxy(IShellNameSpace *This,BSTR *bstrColumns);
  void __RPC_STUB IShellNameSpace_get_Columns_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_put_Columns_Proxy(IShellNameSpace *This,BSTR bstrColumns);
  void __RPC_STUB IShellNameSpace_put_Columns_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_get_CountViewTypes_Proxy(IShellNameSpace *This,int *piTypes);
  void __RPC_STUB IShellNameSpace_get_CountViewTypes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_SetViewType_Proxy(IShellNameSpace *This,int iType);
  void __RPC_STUB IShellNameSpace_SetViewType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_SelectedItems_Proxy(IShellNameSpace *This,IDispatch **ppid);
  void __RPC_STUB IShellNameSpace_SelectedItems_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_Expand_Proxy(IShellNameSpace *This,VARIANT var,int iDepth);
  void __RPC_STUB IShellNameSpace_Expand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellNameSpace_UnselectAll_Proxy(IShellNameSpace *This);
  void __RPC_STUB IShellNameSpace_UnselectAll_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellNameSpace;
#ifdef __cplusplus
  class ShellNameSpace;
#endif

#ifndef __IScriptErrorList_INTERFACE_DEFINED__
#define __IScriptErrorList_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IScriptErrorList;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IScriptErrorList : public IDispatch {
  public:
    virtual HRESULT WINAPI advanceError(void) = 0;
    virtual HRESULT WINAPI retreatError(void) = 0;
    virtual HRESULT WINAPI canAdvanceError(WINBOOL *pfCanAdvance) = 0;
    virtual HRESULT WINAPI canRetreatError(WINBOOL *pfCanRetreat) = 0;
    virtual HRESULT WINAPI getErrorLine(LONG *plLine) = 0;
    virtual HRESULT WINAPI getErrorChar(LONG *plChar) = 0;
    virtual HRESULT WINAPI getErrorCode(LONG *plCode) = 0;
    virtual HRESULT WINAPI getErrorMsg(BSTR *pstr) = 0;
    virtual HRESULT WINAPI getErrorUrl(BSTR *pstr) = 0;
    virtual HRESULT WINAPI getAlwaysShowLockState(WINBOOL *pfAlwaysShowLocked) = 0;
    virtual HRESULT WINAPI getDetailsPaneOpen(WINBOOL *pfDetailsPaneOpen) = 0;
    virtual HRESULT WINAPI setDetailsPaneOpen(WINBOOL fDetailsPaneOpen) = 0;
    virtual HRESULT WINAPI getPerErrorDisplay(WINBOOL *pfPerErrorDisplay) = 0;
    virtual HRESULT WINAPI setPerErrorDisplay(WINBOOL fPerErrorDisplay) = 0;
  };
#else
  typedef struct IScriptErrorListVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IScriptErrorList *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IScriptErrorList *This);
      ULONG (WINAPI *Release)(IScriptErrorList *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IScriptErrorList *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IScriptErrorList *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IScriptErrorList *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IScriptErrorList *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *advanceError)(IScriptErrorList *This);
      HRESULT (WINAPI *retreatError)(IScriptErrorList *This);
      HRESULT (WINAPI *canAdvanceError)(IScriptErrorList *This,WINBOOL *pfCanAdvance);
      HRESULT (WINAPI *canRetreatError)(IScriptErrorList *This,WINBOOL *pfCanRetreat);
      HRESULT (WINAPI *getErrorLine)(IScriptErrorList *This,LONG *plLine);
      HRESULT (WINAPI *getErrorChar)(IScriptErrorList *This,LONG *plChar);
      HRESULT (WINAPI *getErrorCode)(IScriptErrorList *This,LONG *plCode);
      HRESULT (WINAPI *getErrorMsg)(IScriptErrorList *This,BSTR *pstr);
      HRESULT (WINAPI *getErrorUrl)(IScriptErrorList *This,BSTR *pstr);
      HRESULT (WINAPI *getAlwaysShowLockState)(IScriptErrorList *This,WINBOOL *pfAlwaysShowLocked);
      HRESULT (WINAPI *getDetailsPaneOpen)(IScriptErrorList *This,WINBOOL *pfDetailsPaneOpen);
      HRESULT (WINAPI *setDetailsPaneOpen)(IScriptErrorList *This,WINBOOL fDetailsPaneOpen);
      HRESULT (WINAPI *getPerErrorDisplay)(IScriptErrorList *This,WINBOOL *pfPerErrorDisplay);
      HRESULT (WINAPI *setPerErrorDisplay)(IScriptErrorList *This,WINBOOL fPerErrorDisplay);
    END_INTERFACE
  } IScriptErrorListVtbl;
  struct IScriptErrorList {
    CONST_VTBL struct IScriptErrorListVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IScriptErrorList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IScriptErrorList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IScriptErrorList_Release(This) (This)->lpVtbl->Release(This)
#define IScriptErrorList_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IScriptErrorList_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IScriptErrorList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IScriptErrorList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IScriptErrorList_advanceError(This) (This)->lpVtbl->advanceError(This)
#define IScriptErrorList_retreatError(This) (This)->lpVtbl->retreatError(This)
#define IScriptErrorList_canAdvanceError(This,pfCanAdvance) (This)->lpVtbl->canAdvanceError(This,pfCanAdvance)
#define IScriptErrorList_canRetreatError(This,pfCanRetreat) (This)->lpVtbl->canRetreatError(This,pfCanRetreat)
#define IScriptErrorList_getErrorLine(This,plLine) (This)->lpVtbl->getErrorLine(This,plLine)
#define IScriptErrorList_getErrorChar(This,plChar) (This)->lpVtbl->getErrorChar(This,plChar)
#define IScriptErrorList_getErrorCode(This,plCode) (This)->lpVtbl->getErrorCode(This,plCode)
#define IScriptErrorList_getErrorMsg(This,pstr) (This)->lpVtbl->getErrorMsg(This,pstr)
#define IScriptErrorList_getErrorUrl(This,pstr) (This)->lpVtbl->getErrorUrl(This,pstr)
#define IScriptErrorList_getAlwaysShowLockState(This,pfAlwaysShowLocked) (This)->lpVtbl->getAlwaysShowLockState(This,pfAlwaysShowLocked)
#define IScriptErrorList_getDetailsPaneOpen(This,pfDetailsPaneOpen) (This)->lpVtbl->getDetailsPaneOpen(This,pfDetailsPaneOpen)
#define IScriptErrorList_setDetailsPaneOpen(This,fDetailsPaneOpen) (This)->lpVtbl->setDetailsPaneOpen(This,fDetailsPaneOpen)
#define IScriptErrorList_getPerErrorDisplay(This,pfPerErrorDisplay) (This)->lpVtbl->getPerErrorDisplay(This,pfPerErrorDisplay)
#define IScriptErrorList_setPerErrorDisplay(This,fPerErrorDisplay) (This)->lpVtbl->setPerErrorDisplay(This,fPerErrorDisplay)
#endif
#endif
  HRESULT WINAPI IScriptErrorList_advanceError_Proxy(IScriptErrorList *This);
  void __RPC_STUB IScriptErrorList_advanceError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_retreatError_Proxy(IScriptErrorList *This);
  void __RPC_STUB IScriptErrorList_retreatError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_canAdvanceError_Proxy(IScriptErrorList *This,WINBOOL *pfCanAdvance);
  void __RPC_STUB IScriptErrorList_canAdvanceError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_canRetreatError_Proxy(IScriptErrorList *This,WINBOOL *pfCanRetreat);
  void __RPC_STUB IScriptErrorList_canRetreatError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getErrorLine_Proxy(IScriptErrorList *This,LONG *plLine);
  void __RPC_STUB IScriptErrorList_getErrorLine_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getErrorChar_Proxy(IScriptErrorList *This,LONG *plChar);
  void __RPC_STUB IScriptErrorList_getErrorChar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getErrorCode_Proxy(IScriptErrorList *This,LONG *plCode);
  void __RPC_STUB IScriptErrorList_getErrorCode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getErrorMsg_Proxy(IScriptErrorList *This,BSTR *pstr);
  void __RPC_STUB IScriptErrorList_getErrorMsg_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getErrorUrl_Proxy(IScriptErrorList *This,BSTR *pstr);
  void __RPC_STUB IScriptErrorList_getErrorUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getAlwaysShowLockState_Proxy(IScriptErrorList *This,WINBOOL *pfAlwaysShowLocked);
  void __RPC_STUB IScriptErrorList_getAlwaysShowLockState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getDetailsPaneOpen_Proxy(IScriptErrorList *This,WINBOOL *pfDetailsPaneOpen);
  void __RPC_STUB IScriptErrorList_getDetailsPaneOpen_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_setDetailsPaneOpen_Proxy(IScriptErrorList *This,WINBOOL fDetailsPaneOpen);
  void __RPC_STUB IScriptErrorList_setDetailsPaneOpen_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_getPerErrorDisplay_Proxy(IScriptErrorList *This,WINBOOL *pfPerErrorDisplay);
  void __RPC_STUB IScriptErrorList_getPerErrorDisplay_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IScriptErrorList_setPerErrorDisplay_Proxy(IScriptErrorList *This,WINBOOL fPerErrorDisplay);
  void __RPC_STUB IScriptErrorList_setPerErrorDisplay_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_CScriptErrorList;
#ifdef __cplusplus
  class CScriptErrorList;
#endif

#ifndef __ISearch_INTERFACE_DEFINED__
#define __ISearch_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ISearch;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearch : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Title(BSTR *pbstrTitle) = 0;
    virtual HRESULT WINAPI get_Id(BSTR *pbstrId) = 0;
    virtual HRESULT WINAPI get_Url(BSTR *pbstrUrl) = 0;
  };
#else
  typedef struct ISearchVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearch *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearch *This);
      ULONG (WINAPI *Release)(ISearch *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearch *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearch *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearch *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearch *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Title)(ISearch *This,BSTR *pbstrTitle);
      HRESULT (WINAPI *get_Id)(ISearch *This,BSTR *pbstrId);
      HRESULT (WINAPI *get_Url)(ISearch *This,BSTR *pbstrUrl);
    END_INTERFACE
  } ISearchVtbl;
  struct ISearch {
    CONST_VTBL struct ISearchVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearch_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearch_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearch_Release(This) (This)->lpVtbl->Release(This)
#define ISearch_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearch_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearch_get_Title(This,pbstrTitle) (This)->lpVtbl->get_Title(This,pbstrTitle)
#define ISearch_get_Id(This,pbstrId) (This)->lpVtbl->get_Id(This,pbstrId)
#define ISearch_get_Url(This,pbstrUrl) (This)->lpVtbl->get_Url(This,pbstrUrl)
#endif
#endif
  HRESULT WINAPI ISearch_get_Title_Proxy(ISearch *This,BSTR *pbstrTitle);
  void __RPC_STUB ISearch_get_Title_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearch_get_Id_Proxy(ISearch *This,BSTR *pbstrId);
  void __RPC_STUB ISearch_get_Id_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearch_get_Url_Proxy(ISearch *This,BSTR *pbstrUrl);
  void __RPC_STUB ISearch_get_Url_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ISearches_INTERFACE_DEFINED__
#define __ISearches_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ISearches;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearches : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(long *plCount) = 0;
    virtual HRESULT WINAPI get_Default(BSTR *pbstrDefault) = 0;
    virtual HRESULT WINAPI Item(VARIANT index,ISearch **ppid) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppunk) = 0;
  };
#else
  typedef struct ISearchesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearches *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearches *This);
      ULONG (WINAPI *Release)(ISearches *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearches *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearches *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearches *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearches *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ISearches *This,long *plCount);
      HRESULT (WINAPI *get_Default)(ISearches *This,BSTR *pbstrDefault);
      HRESULT (WINAPI *Item)(ISearches *This,VARIANT index,ISearch **ppid);
      HRESULT (WINAPI *_NewEnum)(ISearches *This,IUnknown **ppunk);
    END_INTERFACE
  } ISearchesVtbl;
  struct ISearches {
    CONST_VTBL struct ISearchesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearches_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearches_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearches_Release(This) (This)->lpVtbl->Release(This)
#define ISearches_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearches_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearches_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearches_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearches_get_Count(This,plCount) (This)->lpVtbl->get_Count(This,plCount)
#define ISearches_get_Default(This,pbstrDefault) (This)->lpVtbl->get_Default(This,pbstrDefault)
#define ISearches_Item(This,index,ppid) (This)->lpVtbl->Item(This,index,ppid)
#define ISearches__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#endif
#endif
  HRESULT WINAPI ISearches_get_Count_Proxy(ISearches *This,long *plCount);
  void __RPC_STUB ISearches_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearches_get_Default_Proxy(ISearches *This,BSTR *pbstrDefault);
  void __RPC_STUB ISearches_get_Default_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearches_Item_Proxy(ISearches *This,VARIANT index,ISearch **ppid);
  void __RPC_STUB ISearches_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearches__NewEnum_Proxy(ISearches *This,IUnknown **ppunk);
  void __RPC_STUB ISearches__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ISearchAssistantOC_INTERFACE_DEFINED__
#define __ISearchAssistantOC_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ISearchAssistantOC;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearchAssistantOC : public IDispatch {
  public:
    virtual HRESULT WINAPI AddNextMenuItem(BSTR bstrText,long idItem) = 0;
    virtual HRESULT WINAPI SetDefaultSearchUrl(BSTR bstrUrl) = 0;
    virtual HRESULT WINAPI NavigateToDefaultSearch(void) = 0;
    virtual HRESULT WINAPI IsRestricted(BSTR bstrGuid,VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI get_ShellFeaturesEnabled(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI get_SearchAssistantDefault(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI get_Searches(ISearches **ppid) = 0;
    virtual HRESULT WINAPI get_InWebFolder(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI PutProperty(VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR bstrValue) = 0;
    virtual HRESULT WINAPI GetProperty(VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR *pbstrValue) = 0;
    virtual HRESULT WINAPI put_EventHandled(VARIANT_BOOL bHandled) = 0;
    virtual HRESULT WINAPI ResetNextMenu(void) = 0;
    virtual HRESULT WINAPI FindOnWeb(void) = 0;
    virtual HRESULT WINAPI FindFilesOrFolders(void) = 0;
    virtual HRESULT WINAPI FindComputer(void) = 0;
    virtual HRESULT WINAPI FindPrinter(void) = 0;
    virtual HRESULT WINAPI FindPeople(void) = 0;
    virtual HRESULT WINAPI GetSearchAssistantURL(VARIANT_BOOL bSubstitute,VARIANT_BOOL bCustomize,BSTR *pbstrValue) = 0;
    virtual HRESULT WINAPI NotifySearchSettingsChanged(void) = 0;
    virtual HRESULT WINAPI put_ASProvider(BSTR Provider) = 0;
    virtual HRESULT WINAPI get_ASProvider(BSTR *pProvider) = 0;
    virtual HRESULT WINAPI put_ASSetting(int Setting) = 0;
    virtual HRESULT WINAPI get_ASSetting(int *pSetting) = 0;
    virtual HRESULT WINAPI NETDetectNextNavigate(void) = 0;
    virtual HRESULT WINAPI PutFindText(BSTR FindText) = 0;
    virtual HRESULT WINAPI get_Version(int *pVersion) = 0;
    virtual HRESULT WINAPI EncodeString(BSTR bstrValue,BSTR bstrCharSet,VARIANT_BOOL bUseUTF8,BSTR *pbstrResult) = 0;
  };
#else
  typedef struct ISearchAssistantOCVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearchAssistantOC *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearchAssistantOC *This);
      ULONG (WINAPI *Release)(ISearchAssistantOC *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearchAssistantOC *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearchAssistantOC *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearchAssistantOC *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearchAssistantOC *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *AddNextMenuItem)(ISearchAssistantOC *This,BSTR bstrText,long idItem);
      HRESULT (WINAPI *SetDefaultSearchUrl)(ISearchAssistantOC *This,BSTR bstrUrl);
      HRESULT (WINAPI *NavigateToDefaultSearch)(ISearchAssistantOC *This);
      HRESULT (WINAPI *IsRestricted)(ISearchAssistantOC *This,BSTR bstrGuid,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_ShellFeaturesEnabled)(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_SearchAssistantDefault)(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_Searches)(ISearchAssistantOC *This,ISearches **ppid);
      HRESULT (WINAPI *get_InWebFolder)(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *PutProperty)(ISearchAssistantOC *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR bstrValue);
      HRESULT (WINAPI *GetProperty)(ISearchAssistantOC *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR *pbstrValue);
      HRESULT (WINAPI *put_EventHandled)(ISearchAssistantOC *This,VARIANT_BOOL bHandled);
      HRESULT (WINAPI *ResetNextMenu)(ISearchAssistantOC *This);
      HRESULT (WINAPI *FindOnWeb)(ISearchAssistantOC *This);
      HRESULT (WINAPI *FindFilesOrFolders)(ISearchAssistantOC *This);
      HRESULT (WINAPI *FindComputer)(ISearchAssistantOC *This);
      HRESULT (WINAPI *FindPrinter)(ISearchAssistantOC *This);
      HRESULT (WINAPI *FindPeople)(ISearchAssistantOC *This);
      HRESULT (WINAPI *GetSearchAssistantURL)(ISearchAssistantOC *This,VARIANT_BOOL bSubstitute,VARIANT_BOOL bCustomize,BSTR *pbstrValue);
      HRESULT (WINAPI *NotifySearchSettingsChanged)(ISearchAssistantOC *This);
      HRESULT (WINAPI *put_ASProvider)(ISearchAssistantOC *This,BSTR Provider);
      HRESULT (WINAPI *get_ASProvider)(ISearchAssistantOC *This,BSTR *pProvider);
      HRESULT (WINAPI *put_ASSetting)(ISearchAssistantOC *This,int Setting);
      HRESULT (WINAPI *get_ASSetting)(ISearchAssistantOC *This,int *pSetting);
      HRESULT (WINAPI *NETDetectNextNavigate)(ISearchAssistantOC *This);
      HRESULT (WINAPI *PutFindText)(ISearchAssistantOC *This,BSTR FindText);
      HRESULT (WINAPI *get_Version)(ISearchAssistantOC *This,int *pVersion);
      HRESULT (WINAPI *EncodeString)(ISearchAssistantOC *This,BSTR bstrValue,BSTR bstrCharSet,VARIANT_BOOL bUseUTF8,BSTR *pbstrResult);
    END_INTERFACE
  } ISearchAssistantOCVtbl;
  struct ISearchAssistantOC {
    CONST_VTBL struct ISearchAssistantOCVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearchAssistantOC_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearchAssistantOC_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearchAssistantOC_Release(This) (This)->lpVtbl->Release(This)
#define ISearchAssistantOC_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearchAssistantOC_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearchAssistantOC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearchAssistantOC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearchAssistantOC_AddNextMenuItem(This,bstrText,idItem) (This)->lpVtbl->AddNextMenuItem(This,bstrText,idItem)
#define ISearchAssistantOC_SetDefaultSearchUrl(This,bstrUrl) (This)->lpVtbl->SetDefaultSearchUrl(This,bstrUrl)
#define ISearchAssistantOC_NavigateToDefaultSearch(This) (This)->lpVtbl->NavigateToDefaultSearch(This)
#define ISearchAssistantOC_IsRestricted(This,bstrGuid,pVal) (This)->lpVtbl->IsRestricted(This,bstrGuid,pVal)
#define ISearchAssistantOC_get_ShellFeaturesEnabled(This,pVal) (This)->lpVtbl->get_ShellFeaturesEnabled(This,pVal)
#define ISearchAssistantOC_get_SearchAssistantDefault(This,pVal) (This)->lpVtbl->get_SearchAssistantDefault(This,pVal)
#define ISearchAssistantOC_get_Searches(This,ppid) (This)->lpVtbl->get_Searches(This,ppid)
#define ISearchAssistantOC_get_InWebFolder(This,pVal) (This)->lpVtbl->get_InWebFolder(This,pVal)
#define ISearchAssistantOC_PutProperty(This,bPerLocale,bstrName,bstrValue) (This)->lpVtbl->PutProperty(This,bPerLocale,bstrName,bstrValue)
#define ISearchAssistantOC_GetProperty(This,bPerLocale,bstrName,pbstrValue) (This)->lpVtbl->GetProperty(This,bPerLocale,bstrName,pbstrValue)
#define ISearchAssistantOC_put_EventHandled(This,bHandled) (This)->lpVtbl->put_EventHandled(This,bHandled)
#define ISearchAssistantOC_ResetNextMenu(This) (This)->lpVtbl->ResetNextMenu(This)
#define ISearchAssistantOC_FindOnWeb(This) (This)->lpVtbl->FindOnWeb(This)
#define ISearchAssistantOC_FindFilesOrFolders(This) (This)->lpVtbl->FindFilesOrFolders(This)
#define ISearchAssistantOC_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define ISearchAssistantOC_FindPrinter(This) (This)->lpVtbl->FindPrinter(This)
#define ISearchAssistantOC_FindPeople(This) (This)->lpVtbl->FindPeople(This)
#define ISearchAssistantOC_GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue) (This)->lpVtbl->GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue)
#define ISearchAssistantOC_NotifySearchSettingsChanged(This) (This)->lpVtbl->NotifySearchSettingsChanged(This)
#define ISearchAssistantOC_put_ASProvider(This,Provider) (This)->lpVtbl->put_ASProvider(This,Provider)
#define ISearchAssistantOC_get_ASProvider(This,pProvider) (This)->lpVtbl->get_ASProvider(This,pProvider)
#define ISearchAssistantOC_put_ASSetting(This,Setting) (This)->lpVtbl->put_ASSetting(This,Setting)
#define ISearchAssistantOC_get_ASSetting(This,pSetting) (This)->lpVtbl->get_ASSetting(This,pSetting)
#define ISearchAssistantOC_NETDetectNextNavigate(This) (This)->lpVtbl->NETDetectNextNavigate(This)
#define ISearchAssistantOC_PutFindText(This,FindText) (This)->lpVtbl->PutFindText(This,FindText)
#define ISearchAssistantOC_get_Version(This,pVersion) (This)->lpVtbl->get_Version(This,pVersion)
#define ISearchAssistantOC_EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult) (This)->lpVtbl->EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult)
#endif
#endif
  HRESULT WINAPI ISearchAssistantOC_AddNextMenuItem_Proxy(ISearchAssistantOC *This,BSTR bstrText,long idItem);
  void __RPC_STUB ISearchAssistantOC_AddNextMenuItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_SetDefaultSearchUrl_Proxy(ISearchAssistantOC *This,BSTR bstrUrl);
  void __RPC_STUB ISearchAssistantOC_SetDefaultSearchUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_NavigateToDefaultSearch_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_NavigateToDefaultSearch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_IsRestricted_Proxy(ISearchAssistantOC *This,BSTR bstrGuid,VARIANT_BOOL *pVal);
  void __RPC_STUB ISearchAssistantOC_IsRestricted_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_ShellFeaturesEnabled_Proxy(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
  void __RPC_STUB ISearchAssistantOC_get_ShellFeaturesEnabled_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_SearchAssistantDefault_Proxy(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
  void __RPC_STUB ISearchAssistantOC_get_SearchAssistantDefault_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_Searches_Proxy(ISearchAssistantOC *This,ISearches **ppid);
  void __RPC_STUB ISearchAssistantOC_get_Searches_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_InWebFolder_Proxy(ISearchAssistantOC *This,VARIANT_BOOL *pVal);
  void __RPC_STUB ISearchAssistantOC_get_InWebFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_PutProperty_Proxy(ISearchAssistantOC *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR bstrValue);
  void __RPC_STUB ISearchAssistantOC_PutProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_GetProperty_Proxy(ISearchAssistantOC *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR *pbstrValue);
  void __RPC_STUB ISearchAssistantOC_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_put_EventHandled_Proxy(ISearchAssistantOC *This,VARIANT_BOOL bHandled);
  void __RPC_STUB ISearchAssistantOC_put_EventHandled_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_ResetNextMenu_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_ResetNextMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_FindOnWeb_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_FindOnWeb_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_FindFilesOrFolders_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_FindFilesOrFolders_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_FindComputer_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_FindComputer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_FindPrinter_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_FindPrinter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_FindPeople_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_FindPeople_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_GetSearchAssistantURL_Proxy(ISearchAssistantOC *This,VARIANT_BOOL bSubstitute,VARIANT_BOOL bCustomize,BSTR *pbstrValue);
  void __RPC_STUB ISearchAssistantOC_GetSearchAssistantURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_NotifySearchSettingsChanged_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_NotifySearchSettingsChanged_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_put_ASProvider_Proxy(ISearchAssistantOC *This,BSTR Provider);
  void __RPC_STUB ISearchAssistantOC_put_ASProvider_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_ASProvider_Proxy(ISearchAssistantOC *This,BSTR *pProvider);
  void __RPC_STUB ISearchAssistantOC_get_ASProvider_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_put_ASSetting_Proxy(ISearchAssistantOC *This,int Setting);
  void __RPC_STUB ISearchAssistantOC_put_ASSetting_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_ASSetting_Proxy(ISearchAssistantOC *This,int *pSetting);
  void __RPC_STUB ISearchAssistantOC_get_ASSetting_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_NETDetectNextNavigate_Proxy(ISearchAssistantOC *This);
  void __RPC_STUB ISearchAssistantOC_NETDetectNextNavigate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_PutFindText_Proxy(ISearchAssistantOC *This,BSTR FindText);
  void __RPC_STUB ISearchAssistantOC_PutFindText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_get_Version_Proxy(ISearchAssistantOC *This,int *pVersion);
  void __RPC_STUB ISearchAssistantOC_get_Version_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC_EncodeString_Proxy(ISearchAssistantOC *This,BSTR bstrValue,BSTR bstrCharSet,VARIANT_BOOL bUseUTF8,BSTR *pbstrResult);
  void __RPC_STUB ISearchAssistantOC_EncodeString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ISearchAssistantOC2_INTERFACE_DEFINED__
#define __ISearchAssistantOC2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ISearchAssistantOC2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearchAssistantOC2 : public ISearchAssistantOC {
  public:
    virtual HRESULT WINAPI get_ShowFindPrinter(VARIANT_BOOL *pbShowFindPrinter) = 0;
  };
#else
  typedef struct ISearchAssistantOC2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearchAssistantOC2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearchAssistantOC2 *This);
      ULONG (WINAPI *Release)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearchAssistantOC2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearchAssistantOC2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearchAssistantOC2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearchAssistantOC2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *AddNextMenuItem)(ISearchAssistantOC2 *This,BSTR bstrText,long idItem);
      HRESULT (WINAPI *SetDefaultSearchUrl)(ISearchAssistantOC2 *This,BSTR bstrUrl);
      HRESULT (WINAPI *NavigateToDefaultSearch)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *IsRestricted)(ISearchAssistantOC2 *This,BSTR bstrGuid,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_ShellFeaturesEnabled)(ISearchAssistantOC2 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_SearchAssistantDefault)(ISearchAssistantOC2 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_Searches)(ISearchAssistantOC2 *This,ISearches **ppid);
      HRESULT (WINAPI *get_InWebFolder)(ISearchAssistantOC2 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *PutProperty)(ISearchAssistantOC2 *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR bstrValue);
      HRESULT (WINAPI *GetProperty)(ISearchAssistantOC2 *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR *pbstrValue);
      HRESULT (WINAPI *put_EventHandled)(ISearchAssistantOC2 *This,VARIANT_BOOL bHandled);
      HRESULT (WINAPI *ResetNextMenu)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *FindOnWeb)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *FindFilesOrFolders)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *FindComputer)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *FindPrinter)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *FindPeople)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *GetSearchAssistantURL)(ISearchAssistantOC2 *This,VARIANT_BOOL bSubstitute,VARIANT_BOOL bCustomize,BSTR *pbstrValue);
      HRESULT (WINAPI *NotifySearchSettingsChanged)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *put_ASProvider)(ISearchAssistantOC2 *This,BSTR Provider);
      HRESULT (WINAPI *get_ASProvider)(ISearchAssistantOC2 *This,BSTR *pProvider);
      HRESULT (WINAPI *put_ASSetting)(ISearchAssistantOC2 *This,int Setting);
      HRESULT (WINAPI *get_ASSetting)(ISearchAssistantOC2 *This,int *pSetting);
      HRESULT (WINAPI *NETDetectNextNavigate)(ISearchAssistantOC2 *This);
      HRESULT (WINAPI *PutFindText)(ISearchAssistantOC2 *This,BSTR FindText);
      HRESULT (WINAPI *get_Version)(ISearchAssistantOC2 *This,int *pVersion);
      HRESULT (WINAPI *EncodeString)(ISearchAssistantOC2 *This,BSTR bstrValue,BSTR bstrCharSet,VARIANT_BOOL bUseUTF8,BSTR *pbstrResult);
      HRESULT (WINAPI *get_ShowFindPrinter)(ISearchAssistantOC2 *This,VARIANT_BOOL *pbShowFindPrinter);
    END_INTERFACE
  } ISearchAssistantOC2Vtbl;
  struct ISearchAssistantOC2 {
    CONST_VTBL struct ISearchAssistantOC2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearchAssistantOC2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearchAssistantOC2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearchAssistantOC2_Release(This) (This)->lpVtbl->Release(This)
#define ISearchAssistantOC2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearchAssistantOC2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearchAssistantOC2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearchAssistantOC2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearchAssistantOC2_AddNextMenuItem(This,bstrText,idItem) (This)->lpVtbl->AddNextMenuItem(This,bstrText,idItem)
#define ISearchAssistantOC2_SetDefaultSearchUrl(This,bstrUrl) (This)->lpVtbl->SetDefaultSearchUrl(This,bstrUrl)
#define ISearchAssistantOC2_NavigateToDefaultSearch(This) (This)->lpVtbl->NavigateToDefaultSearch(This)
#define ISearchAssistantOC2_IsRestricted(This,bstrGuid,pVal) (This)->lpVtbl->IsRestricted(This,bstrGuid,pVal)
#define ISearchAssistantOC2_get_ShellFeaturesEnabled(This,pVal) (This)->lpVtbl->get_ShellFeaturesEnabled(This,pVal)
#define ISearchAssistantOC2_get_SearchAssistantDefault(This,pVal) (This)->lpVtbl->get_SearchAssistantDefault(This,pVal)
#define ISearchAssistantOC2_get_Searches(This,ppid) (This)->lpVtbl->get_Searches(This,ppid)
#define ISearchAssistantOC2_get_InWebFolder(This,pVal) (This)->lpVtbl->get_InWebFolder(This,pVal)
#define ISearchAssistantOC2_PutProperty(This,bPerLocale,bstrName,bstrValue) (This)->lpVtbl->PutProperty(This,bPerLocale,bstrName,bstrValue)
#define ISearchAssistantOC2_GetProperty(This,bPerLocale,bstrName,pbstrValue) (This)->lpVtbl->GetProperty(This,bPerLocale,bstrName,pbstrValue)
#define ISearchAssistantOC2_put_EventHandled(This,bHandled) (This)->lpVtbl->put_EventHandled(This,bHandled)
#define ISearchAssistantOC2_ResetNextMenu(This) (This)->lpVtbl->ResetNextMenu(This)
#define ISearchAssistantOC2_FindOnWeb(This) (This)->lpVtbl->FindOnWeb(This)
#define ISearchAssistantOC2_FindFilesOrFolders(This) (This)->lpVtbl->FindFilesOrFolders(This)
#define ISearchAssistantOC2_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define ISearchAssistantOC2_FindPrinter(This) (This)->lpVtbl->FindPrinter(This)
#define ISearchAssistantOC2_FindPeople(This) (This)->lpVtbl->FindPeople(This)
#define ISearchAssistantOC2_GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue) (This)->lpVtbl->GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue)
#define ISearchAssistantOC2_NotifySearchSettingsChanged(This) (This)->lpVtbl->NotifySearchSettingsChanged(This)
#define ISearchAssistantOC2_put_ASProvider(This,Provider) (This)->lpVtbl->put_ASProvider(This,Provider)
#define ISearchAssistantOC2_get_ASProvider(This,pProvider) (This)->lpVtbl->get_ASProvider(This,pProvider)
#define ISearchAssistantOC2_put_ASSetting(This,Setting) (This)->lpVtbl->put_ASSetting(This,Setting)
#define ISearchAssistantOC2_get_ASSetting(This,pSetting) (This)->lpVtbl->get_ASSetting(This,pSetting)
#define ISearchAssistantOC2_NETDetectNextNavigate(This) (This)->lpVtbl->NETDetectNextNavigate(This)
#define ISearchAssistantOC2_PutFindText(This,FindText) (This)->lpVtbl->PutFindText(This,FindText)
#define ISearchAssistantOC2_get_Version(This,pVersion) (This)->lpVtbl->get_Version(This,pVersion)
#define ISearchAssistantOC2_EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult) (This)->lpVtbl->EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult)
#define ISearchAssistantOC2_get_ShowFindPrinter(This,pbShowFindPrinter) (This)->lpVtbl->get_ShowFindPrinter(This,pbShowFindPrinter)
#endif
#endif
  HRESULT WINAPI ISearchAssistantOC2_get_ShowFindPrinter_Proxy(ISearchAssistantOC2 *This,VARIANT_BOOL *pbShowFindPrinter);
  void __RPC_STUB ISearchAssistantOC2_get_ShowFindPrinter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ISearchAssistantOC3_INTERFACE_DEFINED__
#define __ISearchAssistantOC3_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ISearchAssistantOC3;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearchAssistantOC3 : public ISearchAssistantOC2 {
  public:
    virtual HRESULT WINAPI get_SearchCompanionAvailable(VARIANT_BOOL *pbAvailable) = 0;
    virtual HRESULT WINAPI put_UseSearchCompanion(VARIANT_BOOL bUseSC) = 0;
    virtual HRESULT WINAPI get_UseSearchCompanion(VARIANT_BOOL *pbUseSC) = 0;
  };
#else
  typedef struct ISearchAssistantOC3Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearchAssistantOC3 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearchAssistantOC3 *This);
      ULONG (WINAPI *Release)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearchAssistantOC3 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearchAssistantOC3 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearchAssistantOC3 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearchAssistantOC3 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *AddNextMenuItem)(ISearchAssistantOC3 *This,BSTR bstrText,long idItem);
      HRESULT (WINAPI *SetDefaultSearchUrl)(ISearchAssistantOC3 *This,BSTR bstrUrl);
      HRESULT (WINAPI *NavigateToDefaultSearch)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *IsRestricted)(ISearchAssistantOC3 *This,BSTR bstrGuid,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_ShellFeaturesEnabled)(ISearchAssistantOC3 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_SearchAssistantDefault)(ISearchAssistantOC3 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *get_Searches)(ISearchAssistantOC3 *This,ISearches **ppid);
      HRESULT (WINAPI *get_InWebFolder)(ISearchAssistantOC3 *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *PutProperty)(ISearchAssistantOC3 *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR bstrValue);
      HRESULT (WINAPI *GetProperty)(ISearchAssistantOC3 *This,VARIANT_BOOL bPerLocale,BSTR bstrName,BSTR *pbstrValue);
      HRESULT (WINAPI *put_EventHandled)(ISearchAssistantOC3 *This,VARIANT_BOOL bHandled);
      HRESULT (WINAPI *ResetNextMenu)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *FindOnWeb)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *FindFilesOrFolders)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *FindComputer)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *FindPrinter)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *FindPeople)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *GetSearchAssistantURL)(ISearchAssistantOC3 *This,VARIANT_BOOL bSubstitute,VARIANT_BOOL bCustomize,BSTR *pbstrValue);
      HRESULT (WINAPI *NotifySearchSettingsChanged)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *put_ASProvider)(ISearchAssistantOC3 *This,BSTR Provider);
      HRESULT (WINAPI *get_ASProvider)(ISearchAssistantOC3 *This,BSTR *pProvider);
      HRESULT (WINAPI *put_ASSetting)(ISearchAssistantOC3 *This,int Setting);
      HRESULT (WINAPI *get_ASSetting)(ISearchAssistantOC3 *This,int *pSetting);
      HRESULT (WINAPI *NETDetectNextNavigate)(ISearchAssistantOC3 *This);
      HRESULT (WINAPI *PutFindText)(ISearchAssistantOC3 *This,BSTR FindText);
      HRESULT (WINAPI *get_Version)(ISearchAssistantOC3 *This,int *pVersion);
      HRESULT (WINAPI *EncodeString)(ISearchAssistantOC3 *This,BSTR bstrValue,BSTR bstrCharSet,VARIANT_BOOL bUseUTF8,BSTR *pbstrResult);
      HRESULT (WINAPI *get_ShowFindPrinter)(ISearchAssistantOC3 *This,VARIANT_BOOL *pbShowFindPrinter);
      HRESULT (WINAPI *get_SearchCompanionAvailable)(ISearchAssistantOC3 *This,VARIANT_BOOL *pbAvailable);
      HRESULT (WINAPI *put_UseSearchCompanion)(ISearchAssistantOC3 *This,VARIANT_BOOL bUseSC);
      HRESULT (WINAPI *get_UseSearchCompanion)(ISearchAssistantOC3 *This,VARIANT_BOOL *pbUseSC);
    END_INTERFACE
  } ISearchAssistantOC3Vtbl;
  struct ISearchAssistantOC3 {
    CONST_VTBL struct ISearchAssistantOC3Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearchAssistantOC3_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearchAssistantOC3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearchAssistantOC3_Release(This) (This)->lpVtbl->Release(This)
#define ISearchAssistantOC3_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearchAssistantOC3_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearchAssistantOC3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearchAssistantOC3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearchAssistantOC3_AddNextMenuItem(This,bstrText,idItem) (This)->lpVtbl->AddNextMenuItem(This,bstrText,idItem)
#define ISearchAssistantOC3_SetDefaultSearchUrl(This,bstrUrl) (This)->lpVtbl->SetDefaultSearchUrl(This,bstrUrl)
#define ISearchAssistantOC3_NavigateToDefaultSearch(This) (This)->lpVtbl->NavigateToDefaultSearch(This)
#define ISearchAssistantOC3_IsRestricted(This,bstrGuid,pVal) (This)->lpVtbl->IsRestricted(This,bstrGuid,pVal)
#define ISearchAssistantOC3_get_ShellFeaturesEnabled(This,pVal) (This)->lpVtbl->get_ShellFeaturesEnabled(This,pVal)
#define ISearchAssistantOC3_get_SearchAssistantDefault(This,pVal) (This)->lpVtbl->get_SearchAssistantDefault(This,pVal)
#define ISearchAssistantOC3_get_Searches(This,ppid) (This)->lpVtbl->get_Searches(This,ppid)
#define ISearchAssistantOC3_get_InWebFolder(This,pVal) (This)->lpVtbl->get_InWebFolder(This,pVal)
#define ISearchAssistantOC3_PutProperty(This,bPerLocale,bstrName,bstrValue) (This)->lpVtbl->PutProperty(This,bPerLocale,bstrName,bstrValue)
#define ISearchAssistantOC3_GetProperty(This,bPerLocale,bstrName,pbstrValue) (This)->lpVtbl->GetProperty(This,bPerLocale,bstrName,pbstrValue)
#define ISearchAssistantOC3_put_EventHandled(This,bHandled) (This)->lpVtbl->put_EventHandled(This,bHandled)
#define ISearchAssistantOC3_ResetNextMenu(This) (This)->lpVtbl->ResetNextMenu(This)
#define ISearchAssistantOC3_FindOnWeb(This) (This)->lpVtbl->FindOnWeb(This)
#define ISearchAssistantOC3_FindFilesOrFolders(This) (This)->lpVtbl->FindFilesOrFolders(This)
#define ISearchAssistantOC3_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define ISearchAssistantOC3_FindPrinter(This) (This)->lpVtbl->FindPrinter(This)
#define ISearchAssistantOC3_FindPeople(This) (This)->lpVtbl->FindPeople(This)
#define ISearchAssistantOC3_GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue) (This)->lpVtbl->GetSearchAssistantURL(This,bSubstitute,bCustomize,pbstrValue)
#define ISearchAssistantOC3_NotifySearchSettingsChanged(This) (This)->lpVtbl->NotifySearchSettingsChanged(This)
#define ISearchAssistantOC3_put_ASProvider(This,Provider) (This)->lpVtbl->put_ASProvider(This,Provider)
#define ISearchAssistantOC3_get_ASProvider(This,pProvider) (This)->lpVtbl->get_ASProvider(This,pProvider)
#define ISearchAssistantOC3_put_ASSetting(This,Setting) (This)->lpVtbl->put_ASSetting(This,Setting)
#define ISearchAssistantOC3_get_ASSetting(This,pSetting) (This)->lpVtbl->get_ASSetting(This,pSetting)
#define ISearchAssistantOC3_NETDetectNextNavigate(This) (This)->lpVtbl->NETDetectNextNavigate(This)
#define ISearchAssistantOC3_PutFindText(This,FindText) (This)->lpVtbl->PutFindText(This,FindText)
#define ISearchAssistantOC3_get_Version(This,pVersion) (This)->lpVtbl->get_Version(This,pVersion)
#define ISearchAssistantOC3_EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult) (This)->lpVtbl->EncodeString(This,bstrValue,bstrCharSet,bUseUTF8,pbstrResult)
#define ISearchAssistantOC3_get_ShowFindPrinter(This,pbShowFindPrinter) (This)->lpVtbl->get_ShowFindPrinter(This,pbShowFindPrinter)
#define ISearchAssistantOC3_get_SearchCompanionAvailable(This,pbAvailable) (This)->lpVtbl->get_SearchCompanionAvailable(This,pbAvailable)
#define ISearchAssistantOC3_put_UseSearchCompanion(This,bUseSC) (This)->lpVtbl->put_UseSearchCompanion(This,bUseSC)
#define ISearchAssistantOC3_get_UseSearchCompanion(This,pbUseSC) (This)->lpVtbl->get_UseSearchCompanion(This,pbUseSC)
#endif
#endif
  HRESULT WINAPI ISearchAssistantOC3_get_SearchCompanionAvailable_Proxy(ISearchAssistantOC3 *This,VARIANT_BOOL *pbAvailable);
  void __RPC_STUB ISearchAssistantOC3_get_SearchCompanionAvailable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC3_put_UseSearchCompanion_Proxy(ISearchAssistantOC3 *This,VARIANT_BOOL bUseSC);
  void __RPC_STUB ISearchAssistantOC3_put_UseSearchCompanion_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchAssistantOC3_get_UseSearchCompanion_Proxy(ISearchAssistantOC3 *This,VARIANT_BOOL *pbUseSC);
  void __RPC_STUB ISearchAssistantOC3_get_UseSearchCompanion_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___SearchAssistantEvents_DISPINTERFACE_DEFINED__
#define ___SearchAssistantEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID__SearchAssistantEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _SearchAssistantEvents : public IDispatch {
  };
#else
  typedef struct _SearchAssistantEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_SearchAssistantEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_SearchAssistantEvents *This);
      ULONG (WINAPI *Release)(_SearchAssistantEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_SearchAssistantEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_SearchAssistantEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_SearchAssistantEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_SearchAssistantEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } _SearchAssistantEventsVtbl;
  struct _SearchAssistantEvents {
    CONST_VTBL struct _SearchAssistantEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _SearchAssistantEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _SearchAssistantEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _SearchAssistantEvents_Release(This) (This)->lpVtbl->Release(This)
#define _SearchAssistantEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _SearchAssistantEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _SearchAssistantEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _SearchAssistantEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

  EXTERN_C const CLSID CLSID_SearchAssistantOC;
#ifdef __cplusplus
  class SearchAssistantOC;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
