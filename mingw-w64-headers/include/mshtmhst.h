/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __mshtmhst_h__
#define __mshtmhst_h__

#ifndef __IHostDialogHelper_FWD_DEFINED__
#define __IHostDialogHelper_FWD_DEFINED__
typedef struct IHostDialogHelper IHostDialogHelper;
#endif

#ifndef __HostDialogHelper_FWD_DEFINED__
#define __HostDialogHelper_FWD_DEFINED__
#ifdef __cplusplus
typedef class HostDialogHelper HostDialogHelper;
#else
typedef struct HostDialogHelper HostDialogHelper;
#endif
#endif

#ifndef __IDocHostUIHandler_FWD_DEFINED__
#define __IDocHostUIHandler_FWD_DEFINED__
typedef struct IDocHostUIHandler IDocHostUIHandler;
#endif

#ifndef __IDocHostUIHandler2_FWD_DEFINED__
#define __IDocHostUIHandler2_FWD_DEFINED__
typedef struct IDocHostUIHandler2 IDocHostUIHandler2;
#endif

#ifndef __ICustomDoc_FWD_DEFINED__
#define __ICustomDoc_FWD_DEFINED__
typedef struct ICustomDoc ICustomDoc;
#endif

#ifndef __IDocHostShowUI_FWD_DEFINED__
#define __IDocHostShowUI_FWD_DEFINED__
typedef struct IDocHostShowUI IDocHostShowUI;
#endif

#ifndef __IClassFactoryEx_FWD_DEFINED__
#define __IClassFactoryEx_FWD_DEFINED__
typedef struct IClassFactoryEx IClassFactoryEx;
#endif

#ifndef __IHTMLOMWindowServices_FWD_DEFINED__
#define __IHTMLOMWindowServices_FWD_DEFINED__
typedef struct IHTMLOMWindowServices IHTMLOMWindowServices;
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

#ifndef MSHTMHST_H
#define MSHTMHST_H
#define CONTEXT_MENU_DEFAULT 0
#define CONTEXT_MENU_IMAGE 1
#define CONTEXT_MENU_CONTROL 2
#define CONTEXT_MENU_TABLE 3

#define CONTEXT_MENU_TEXTSELECT 4
#define CONTEXT_MENU_ANCHOR 5
#define CONTEXT_MENU_UNKNOWN 6

#define CONTEXT_MENU_IMGDYNSRC 7
#define CONTEXT_MENU_IMGART 8
#define CONTEXT_MENU_DEBUG 9

#define CONTEXT_MENU_VSCROLL 10
#define CONTEXT_MENU_HSCROLL 11
#define MENUEXT_SHOWDIALOG 0x1
#define DOCHOSTUIFLAG_BROWSER DOCHOSTUIFLAG_DISABLE_HELP_MENU | DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE
#define HTMLDLG_NOUI 0x10
#define HTMLDLG_MODAL 0x20
#define HTMLDLG_MODELESS 0x40
#define HTMLDLG_PRINT_TEMPLATE 0x80
#define HTMLDLG_VERIFY 0x100
#define HTMLDLG_LMZLUNLOCK 0x200
#define HTMLDLG_ALLOWNEXTWINDOW 0x400
#define PRINT_DONTBOTHERUSER 0x01
#define PRINT_WAITFORCOMPLETION 0x02
  EXTERN_C const GUID CGID_MSHTML;
#define CMDSETID_Forms3 CGID_MSHTML
#define SZ_HTML_CLIENTSITE_OBJECTPARAM L"{d4db6850-5385-11d0-89e9-00a0c90a90ac}"
#ifndef __IHTMLWindow2_FWD_DEFINED__
#define __IHTMLWindow2_FWD_DEFINED__
  typedef struct IHTMLWindow2 IHTMLWindow2;
#endif
  typedef HRESULT WINAPI SHOWHTMLDIALOGFN (HWND hwndParent,IMoniker *pmk,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvArgOut);
  typedef HRESULT WINAPI SHOWHTMLDIALOGEXFN (HWND hwndParent,IMoniker *pmk,DWORD dwDialogFlags,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvArgOut);
  typedef HRESULT WINAPI SHOWMODELESSHTMLDIALOGFN (HWND hwndParent,IMoniker *pmk,VARIANT *pvarArgIn,VARIANT *pvarOptions,IHTMLWindow2 **ppWindow);

  STDAPI ShowHTMLDialog(HWND hwndParent,IMoniker *pMk,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvarArgOut);
  STDAPI ShowHTMLDialogEx(HWND hwndParent,IMoniker *pMk,DWORD dwDialogFlags,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvarArgOut);
  STDAPI ShowModelessHTMLDialog(HWND hwndParent,IMoniker *pMk,VARIANT *pvarArgIn,VARIANT *pvarOptions,IHTMLWindow2 **ppWindow);
  STDAPI RunHTMLApplication(HINSTANCE hinst,HINSTANCE hPrevInst,LPSTR szCmdLine,int nCmdShow);
  STDAPI CreateHTMLPropertyPage(IMoniker *pmk,IPropertyPage **ppPP);

  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0000_v0_0_s_ifspec;

#ifndef __IHostDialogHelper_INTERFACE_DEFINED__
#define __IHostDialogHelper_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IHostDialogHelper;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IHostDialogHelper : public IUnknown {
  public:
    virtual HRESULT WINAPI ShowHTMLDialog(HWND hwndParent,IMoniker *pMk,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvarArgOut,IUnknown *punkHost) = 0;
  };
#else
  typedef struct IHostDialogHelperVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IHostDialogHelper *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IHostDialogHelper *This);
      ULONG (WINAPI *Release)(IHostDialogHelper *This);
      HRESULT (WINAPI *ShowHTMLDialog)(IHostDialogHelper *This,HWND hwndParent,IMoniker *pMk,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvarArgOut,IUnknown *punkHost);
    END_INTERFACE
  } IHostDialogHelperVtbl;
  struct IHostDialogHelper {
    CONST_VTBL struct IHostDialogHelperVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IHostDialogHelper_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IHostDialogHelper_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IHostDialogHelper_Release(This) (This)->lpVtbl->Release(This)
#define IHostDialogHelper_ShowHTMLDialog(This,hwndParent,pMk,pvarArgIn,pchOptions,pvarArgOut,punkHost) (This)->lpVtbl->ShowHTMLDialog(This,hwndParent,pMk,pvarArgIn,pchOptions,pvarArgOut,punkHost)
#endif
#endif
  HRESULT WINAPI IHostDialogHelper_ShowHTMLDialog_Proxy(IHostDialogHelper *This,HWND hwndParent,IMoniker *pMk,VARIANT *pvarArgIn,WCHAR *pchOptions,VARIANT *pvarArgOut,IUnknown *punkHost);
  void __RPC_STUB IHostDialogHelper_ShowHTMLDialog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const GUID CLSID_HostDialogHelper;
  typedef enum tagDOCHOSTUITYPE {
    DOCHOSTUITYPE_BROWSE = 0,DOCHOSTUITYPE_AUTHOR = 1
  } DOCHOSTUITYPE;

  typedef enum tagDOCHOSTUIDBLCLK {
    DOCHOSTUIDBLCLK_DEFAULT = 0,DOCHOSTUIDBLCLK_SHOWPROPERTIES = 1,DOCHOSTUIDBLCLK_SHOWCODE = 2
  } DOCHOSTUIDBLCLK;

  typedef enum tagDOCHOSTUIFLAG {
    DOCHOSTUIFLAG_DIALOG = 0x1,DOCHOSTUIFLAG_DISABLE_HELP_MENU = 0x2,DOCHOSTUIFLAG_NO3DBORDER = 0x4,DOCHOSTUIFLAG_SCROLL_NO = 0x8,
    DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE = 0x10,DOCHOSTUIFLAG_OPENNEWWIN = 0x20,DOCHOSTUIFLAG_DISABLE_OFFSCREEN = 0x40,
    DOCHOSTUIFLAG_FLAT_SCROLLBAR = 0x80,DOCHOSTUIFLAG_DIV_BLOCKDEFAULT = 0x100,DOCHOSTUIFLAG_ACTIVATE_CLIENTHIT_ONLY = 0x200,
    DOCHOSTUIFLAG_OVERRIDEBEHAVIORFACTORY = 0x400,DOCHOSTUIFLAG_CODEPAGELINKEDFONTS = 0x800,DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8 = 0x1000,
    DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8 = 0x2000,DOCHOSTUIFLAG_ENABLE_FORMS_AUTOCOMPLETE = 0x4000,DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION = 0x10000,
    DOCHOSTUIFLAG_IME_ENABLE_RECONVERSION = 0x20000,DOCHOSTUIFLAG_THEME = 0x40000,DOCHOSTUIFLAG_NOTHEME = 0x80000,DOCHOSTUIFLAG_NOPICS = 0x100000,
    DOCHOSTUIFLAG_NO3DOUTERBORDER = 0x200000,DOCHOSTUIFLAG_DISABLE_EDIT_NS_FIXUP = 0x400000,DOCHOSTUIFLAG_LOCAL_MACHINE_ACCESS_CHECK = 0x800000,
    DOCHOSTUIFLAG_DISABLE_UNTRUSTEDPROTOCOL = 0x1000000
  } DOCHOSTUIFLAG;

#define DOCHOSTUIATOM_ENABLE_HIRES _T("TridentEnableHiRes")

  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0277_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0277_v0_0_s_ifspec;

#ifndef __IDocHostUIHandler_INTERFACE_DEFINED__
#define __IDocHostUIHandler_INTERFACE_DEFINED__

  typedef struct _DOCHOSTUIINFO {
    ULONG cbSize;
    DWORD dwFlags;
    DWORD dwDoubleClick;
    OLECHAR *pchHostCss;
    OLECHAR *pchHostNS;
  } DOCHOSTUIINFO;

  EXTERN_C const IID IID_IDocHostUIHandler;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDocHostUIHandler : public IUnknown {
  public:
    virtual HRESULT WINAPI ShowContextMenu(DWORD dwID,POINT *ppt,IUnknown *pcmdtReserved,IDispatch *pdispReserved) = 0;
    virtual HRESULT WINAPI GetHostInfo(DOCHOSTUIINFO *pInfo) = 0;
    virtual HRESULT WINAPI ShowUI(DWORD dwID,IOleInPlaceActiveObject *pActiveObject,IOleCommandTarget *pCommandTarget,IOleInPlaceFrame *pFrame,IOleInPlaceUIWindow *pDoc) = 0;
    virtual HRESULT WINAPI HideUI(void) = 0;
    virtual HRESULT WINAPI UpdateUI(void) = 0;
    virtual HRESULT WINAPI EnableModeless(WINBOOL fEnable) = 0;
    virtual HRESULT WINAPI OnDocWindowActivate(WINBOOL fActivate) = 0;
    virtual HRESULT WINAPI OnFrameWindowActivate(WINBOOL fActivate) = 0;
    virtual HRESULT WINAPI ResizeBorder(LPCRECT prcBorder,IOleInPlaceUIWindow *pUIWindow,WINBOOL fRameWindow) = 0;
    virtual HRESULT WINAPI TranslateAccelerator(LPMSG lpMsg,const GUID *pguidCmdGroup,DWORD nCmdID) = 0;
    virtual HRESULT WINAPI GetOptionKeyPath(LPOLESTR *pchKey,DWORD dw) = 0;
    virtual HRESULT WINAPI GetDropTarget(IDropTarget *pDropTarget,IDropTarget **ppDropTarget) = 0;
    virtual HRESULT WINAPI GetExternal(IDispatch **ppDispatch) = 0;
    virtual HRESULT WINAPI TranslateUrl(DWORD dwTranslate,OLECHAR *pchURLIn,OLECHAR **ppchURLOut) = 0;
    virtual HRESULT WINAPI FilterDataObject(IDataObject *pDO,IDataObject **ppDORet) = 0;
  };
#else
  typedef struct IDocHostUIHandlerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDocHostUIHandler *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDocHostUIHandler *This);
      ULONG (WINAPI *Release)(IDocHostUIHandler *This);
      HRESULT (WINAPI *ShowContextMenu)(IDocHostUIHandler *This,DWORD dwID,POINT *ppt,IUnknown *pcmdtReserved,IDispatch *pdispReserved);
      HRESULT (WINAPI *GetHostInfo)(IDocHostUIHandler *This,DOCHOSTUIINFO *pInfo);
      HRESULT (WINAPI *ShowUI)(IDocHostUIHandler *This,DWORD dwID,IOleInPlaceActiveObject *pActiveObject,IOleCommandTarget *pCommandTarget,IOleInPlaceFrame *pFrame,IOleInPlaceUIWindow *pDoc);
      HRESULT (WINAPI *HideUI)(IDocHostUIHandler *This);
      HRESULT (WINAPI *UpdateUI)(IDocHostUIHandler *This);
      HRESULT (WINAPI *EnableModeless)(IDocHostUIHandler *This,WINBOOL fEnable);
      HRESULT (WINAPI *OnDocWindowActivate)(IDocHostUIHandler *This,WINBOOL fActivate);
      HRESULT (WINAPI *OnFrameWindowActivate)(IDocHostUIHandler *This,WINBOOL fActivate);
      HRESULT (WINAPI *ResizeBorder)(IDocHostUIHandler *This,LPCRECT prcBorder,IOleInPlaceUIWindow *pUIWindow,WINBOOL fRameWindow);
      HRESULT (WINAPI *TranslateAccelerator)(IDocHostUIHandler *This,LPMSG lpMsg,const GUID *pguidCmdGroup,DWORD nCmdID);
      HRESULT (WINAPI *GetOptionKeyPath)(IDocHostUIHandler *This,LPOLESTR *pchKey,DWORD dw);
      HRESULT (WINAPI *GetDropTarget)(IDocHostUIHandler *This,IDropTarget *pDropTarget,IDropTarget **ppDropTarget);
      HRESULT (WINAPI *GetExternal)(IDocHostUIHandler *This,IDispatch **ppDispatch);
      HRESULT (WINAPI *TranslateUrl)(IDocHostUIHandler *This,DWORD dwTranslate,OLECHAR *pchURLIn,OLECHAR **ppchURLOut);
      HRESULT (WINAPI *FilterDataObject)(IDocHostUIHandler *This,IDataObject *pDO,IDataObject **ppDORet);
    END_INTERFACE
  } IDocHostUIHandlerVtbl;
  struct IDocHostUIHandler {
    CONST_VTBL struct IDocHostUIHandlerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDocHostUIHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDocHostUIHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDocHostUIHandler_Release(This) (This)->lpVtbl->Release(This)
#define IDocHostUIHandler_ShowContextMenu(This,dwID,ppt,pcmdtReserved,pdispReserved) (This)->lpVtbl->ShowContextMenu(This,dwID,ppt,pcmdtReserved,pdispReserved)
#define IDocHostUIHandler_GetHostInfo(This,pInfo) (This)->lpVtbl->GetHostInfo(This,pInfo)
#define IDocHostUIHandler_ShowUI(This,dwID,pActiveObject,pCommandTarget,pFrame,pDoc) (This)->lpVtbl->ShowUI(This,dwID,pActiveObject,pCommandTarget,pFrame,pDoc)
#define IDocHostUIHandler_HideUI(This) (This)->lpVtbl->HideUI(This)
#define IDocHostUIHandler_UpdateUI(This) (This)->lpVtbl->UpdateUI(This)
#define IDocHostUIHandler_EnableModeless(This,fEnable) (This)->lpVtbl->EnableModeless(This,fEnable)
#define IDocHostUIHandler_OnDocWindowActivate(This,fActivate) (This)->lpVtbl->OnDocWindowActivate(This,fActivate)
#define IDocHostUIHandler_OnFrameWindowActivate(This,fActivate) (This)->lpVtbl->OnFrameWindowActivate(This,fActivate)
#define IDocHostUIHandler_ResizeBorder(This,prcBorder,pUIWindow,fRameWindow) (This)->lpVtbl->ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)
#define IDocHostUIHandler_TranslateAccelerator(This,lpMsg,pguidCmdGroup,nCmdID) (This)->lpVtbl->TranslateAccelerator(This,lpMsg,pguidCmdGroup,nCmdID)
#define IDocHostUIHandler_GetOptionKeyPath(This,pchKey,dw) (This)->lpVtbl->GetOptionKeyPath(This,pchKey,dw)
#define IDocHostUIHandler_GetDropTarget(This,pDropTarget,ppDropTarget) (This)->lpVtbl->GetDropTarget(This,pDropTarget,ppDropTarget)
#define IDocHostUIHandler_GetExternal(This,ppDispatch) (This)->lpVtbl->GetExternal(This,ppDispatch)
#define IDocHostUIHandler_TranslateUrl(This,dwTranslate,pchURLIn,ppchURLOut) (This)->lpVtbl->TranslateUrl(This,dwTranslate,pchURLIn,ppchURLOut)
#define IDocHostUIHandler_FilterDataObject(This,pDO,ppDORet) (This)->lpVtbl->FilterDataObject(This,pDO,ppDORet)
#endif
#endif
  HRESULT WINAPI IDocHostUIHandler_ShowContextMenu_Proxy(IDocHostUIHandler *This,DWORD dwID,POINT *ppt,IUnknown *pcmdtReserved,IDispatch *pdispReserved);
  void __RPC_STUB IDocHostUIHandler_ShowContextMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_GetHostInfo_Proxy(IDocHostUIHandler *This,DOCHOSTUIINFO *pInfo);
  void __RPC_STUB IDocHostUIHandler_GetHostInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_ShowUI_Proxy(IDocHostUIHandler *This,DWORD dwID,IOleInPlaceActiveObject *pActiveObject,IOleCommandTarget *pCommandTarget,IOleInPlaceFrame *pFrame,IOleInPlaceUIWindow *pDoc);
  void __RPC_STUB IDocHostUIHandler_ShowUI_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_HideUI_Proxy(IDocHostUIHandler *This);
  void __RPC_STUB IDocHostUIHandler_HideUI_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_UpdateUI_Proxy(IDocHostUIHandler *This);
  void __RPC_STUB IDocHostUIHandler_UpdateUI_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_EnableModeless_Proxy(IDocHostUIHandler *This,WINBOOL fEnable);
  void __RPC_STUB IDocHostUIHandler_EnableModeless_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_OnDocWindowActivate_Proxy(IDocHostUIHandler *This,WINBOOL fActivate);
  void __RPC_STUB IDocHostUIHandler_OnDocWindowActivate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_OnFrameWindowActivate_Proxy(IDocHostUIHandler *This,WINBOOL fActivate);
  void __RPC_STUB IDocHostUIHandler_OnFrameWindowActivate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_ResizeBorder_Proxy(IDocHostUIHandler *This,LPCRECT prcBorder,IOleInPlaceUIWindow *pUIWindow,WINBOOL fRameWindow);
  void __RPC_STUB IDocHostUIHandler_ResizeBorder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_TranslateAccelerator_Proxy(IDocHostUIHandler *This,LPMSG lpMsg,const GUID *pguidCmdGroup,DWORD nCmdID);
  void __RPC_STUB IDocHostUIHandler_TranslateAccelerator_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_GetOptionKeyPath_Proxy(IDocHostUIHandler *This,LPOLESTR *pchKey,DWORD dw);
  void __RPC_STUB IDocHostUIHandler_GetOptionKeyPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_GetDropTarget_Proxy(IDocHostUIHandler *This,IDropTarget *pDropTarget,IDropTarget **ppDropTarget);
  void __RPC_STUB IDocHostUIHandler_GetDropTarget_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_GetExternal_Proxy(IDocHostUIHandler *This,IDispatch **ppDispatch);
  void __RPC_STUB IDocHostUIHandler_GetExternal_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_TranslateUrl_Proxy(IDocHostUIHandler *This,DWORD dwTranslate,OLECHAR *pchURLIn,OLECHAR **ppchURLOut);
  void __RPC_STUB IDocHostUIHandler_TranslateUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostUIHandler_FilterDataObject_Proxy(IDocHostUIHandler *This,IDataObject *pDO,IDataObject **ppDORet);
  void __RPC_STUB IDocHostUIHandler_FilterDataObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDocHostUIHandler2_INTERFACE_DEFINED__
#define __IDocHostUIHandler2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDocHostUIHandler2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDocHostUIHandler2 : public IDocHostUIHandler {
  public:
    virtual HRESULT WINAPI GetOverrideKeyPath(LPOLESTR *pchKey,DWORD dw) = 0;
  };
#else
  typedef struct IDocHostUIHandler2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDocHostUIHandler2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDocHostUIHandler2 *This);
      ULONG (WINAPI *Release)(IDocHostUIHandler2 *This);
      HRESULT (WINAPI *ShowContextMenu)(IDocHostUIHandler2 *This,DWORD dwID,POINT *ppt,IUnknown *pcmdtReserved,IDispatch *pdispReserved);
      HRESULT (WINAPI *GetHostInfo)(IDocHostUIHandler2 *This,DOCHOSTUIINFO *pInfo);
      HRESULT (WINAPI *ShowUI)(IDocHostUIHandler2 *This,DWORD dwID,IOleInPlaceActiveObject *pActiveObject,IOleCommandTarget *pCommandTarget,IOleInPlaceFrame *pFrame,IOleInPlaceUIWindow *pDoc);
      HRESULT (WINAPI *HideUI)(IDocHostUIHandler2 *This);
      HRESULT (WINAPI *UpdateUI)(IDocHostUIHandler2 *This);
      HRESULT (WINAPI *EnableModeless)(IDocHostUIHandler2 *This,WINBOOL fEnable);
      HRESULT (WINAPI *OnDocWindowActivate)(IDocHostUIHandler2 *This,WINBOOL fActivate);
      HRESULT (WINAPI *OnFrameWindowActivate)(IDocHostUIHandler2 *This,WINBOOL fActivate);
      HRESULT (WINAPI *ResizeBorder)(IDocHostUIHandler2 *This,LPCRECT prcBorder,IOleInPlaceUIWindow *pUIWindow,WINBOOL fRameWindow);
      HRESULT (WINAPI *TranslateAccelerator)(IDocHostUIHandler2 *This,LPMSG lpMsg,const GUID *pguidCmdGroup,DWORD nCmdID);
      HRESULT (WINAPI *GetOptionKeyPath)(IDocHostUIHandler2 *This,LPOLESTR *pchKey,DWORD dw);
      HRESULT (WINAPI *GetDropTarget)(IDocHostUIHandler2 *This,IDropTarget *pDropTarget,IDropTarget **ppDropTarget);
      HRESULT (WINAPI *GetExternal)(IDocHostUIHandler2 *This,IDispatch **ppDispatch);
      HRESULT (WINAPI *TranslateUrl)(IDocHostUIHandler2 *This,DWORD dwTranslate,OLECHAR *pchURLIn,OLECHAR **ppchURLOut);
      HRESULT (WINAPI *FilterDataObject)(IDocHostUIHandler2 *This,IDataObject *pDO,IDataObject **ppDORet);
      HRESULT (WINAPI *GetOverrideKeyPath)(IDocHostUIHandler2 *This,LPOLESTR *pchKey,DWORD dw);
    END_INTERFACE
  } IDocHostUIHandler2Vtbl;
  struct IDocHostUIHandler2 {
    CONST_VTBL struct IDocHostUIHandler2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDocHostUIHandler2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDocHostUIHandler2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDocHostUIHandler2_Release(This) (This)->lpVtbl->Release(This)
#define IDocHostUIHandler2_ShowContextMenu(This,dwID,ppt,pcmdtReserved,pdispReserved) (This)->lpVtbl->ShowContextMenu(This,dwID,ppt,pcmdtReserved,pdispReserved)
#define IDocHostUIHandler2_GetHostInfo(This,pInfo) (This)->lpVtbl->GetHostInfo(This,pInfo)
#define IDocHostUIHandler2_ShowUI(This,dwID,pActiveObject,pCommandTarget,pFrame,pDoc) (This)->lpVtbl->ShowUI(This,dwID,pActiveObject,pCommandTarget,pFrame,pDoc)
#define IDocHostUIHandler2_HideUI(This) (This)->lpVtbl->HideUI(This)
#define IDocHostUIHandler2_UpdateUI(This) (This)->lpVtbl->UpdateUI(This)
#define IDocHostUIHandler2_EnableModeless(This,fEnable) (This)->lpVtbl->EnableModeless(This,fEnable)
#define IDocHostUIHandler2_OnDocWindowActivate(This,fActivate) (This)->lpVtbl->OnDocWindowActivate(This,fActivate)
#define IDocHostUIHandler2_OnFrameWindowActivate(This,fActivate) (This)->lpVtbl->OnFrameWindowActivate(This,fActivate)
#define IDocHostUIHandler2_ResizeBorder(This,prcBorder,pUIWindow,fRameWindow) (This)->lpVtbl->ResizeBorder(This,prcBorder,pUIWindow,fRameWindow)
#define IDocHostUIHandler2_TranslateAccelerator(This,lpMsg,pguidCmdGroup,nCmdID) (This)->lpVtbl->TranslateAccelerator(This,lpMsg,pguidCmdGroup,nCmdID)
#define IDocHostUIHandler2_GetOptionKeyPath(This,pchKey,dw) (This)->lpVtbl->GetOptionKeyPath(This,pchKey,dw)
#define IDocHostUIHandler2_GetDropTarget(This,pDropTarget,ppDropTarget) (This)->lpVtbl->GetDropTarget(This,pDropTarget,ppDropTarget)
#define IDocHostUIHandler2_GetExternal(This,ppDispatch) (This)->lpVtbl->GetExternal(This,ppDispatch)
#define IDocHostUIHandler2_TranslateUrl(This,dwTranslate,pchURLIn,ppchURLOut) (This)->lpVtbl->TranslateUrl(This,dwTranslate,pchURLIn,ppchURLOut)
#define IDocHostUIHandler2_FilterDataObject(This,pDO,ppDORet) (This)->lpVtbl->FilterDataObject(This,pDO,ppDORet)
#define IDocHostUIHandler2_GetOverrideKeyPath(This,pchKey,dw) (This)->lpVtbl->GetOverrideKeyPath(This,pchKey,dw)
#endif
#endif
  HRESULT WINAPI IDocHostUIHandler2_GetOverrideKeyPath_Proxy(IDocHostUIHandler2 *This,LPOLESTR *pchKey,DWORD dw);
  void __RPC_STUB IDocHostUIHandler2_GetOverrideKeyPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  DEFINE_GUID(CGID_DocHostCommandHandler,0xf38bc242,0xb950,0x11d1,0x89,0x18,0x00,0xc0,0x4f,0xc2,0xc8,0x36);
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0279_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0279_v0_0_s_ifspec;

#ifndef __ICustomDoc_INTERFACE_DEFINED__
#define __ICustomDoc_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ICustomDoc;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICustomDoc : public IUnknown {
  public:
    virtual HRESULT WINAPI SetUIHandler(IDocHostUIHandler *pUIHandler) = 0;
  };
#else
  typedef struct ICustomDocVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICustomDoc *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICustomDoc *This);
      ULONG (WINAPI *Release)(ICustomDoc *This);
      HRESULT (WINAPI *SetUIHandler)(ICustomDoc *This,IDocHostUIHandler *pUIHandler);
    END_INTERFACE
  } ICustomDocVtbl;
  struct ICustomDoc {
    CONST_VTBL struct ICustomDocVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICustomDoc_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICustomDoc_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICustomDoc_Release(This) (This)->lpVtbl->Release(This)
#define ICustomDoc_SetUIHandler(This,pUIHandler) (This)->lpVtbl->SetUIHandler(This,pUIHandler)
#endif
#endif
  HRESULT WINAPI ICustomDoc_SetUIHandler_Proxy(ICustomDoc *This,IDocHostUIHandler *pUIHandler);
  void __RPC_STUB ICustomDoc_SetUIHandler_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDocHostShowUI_INTERFACE_DEFINED__
#define __IDocHostShowUI_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDocHostShowUI;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDocHostShowUI : public IUnknown {
  public:
    virtual HRESULT WINAPI ShowMessage(HWND hwnd,LPOLESTR lpstrText,LPOLESTR lpstrCaption,DWORD dwType,LPOLESTR lpstrHelpFile,DWORD dwHelpContext,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI ShowHelp(HWND hwnd,LPOLESTR pszHelpFile,UINT uCommand,DWORD dwData,POINT ptMouse,IDispatch *pDispatchObjectHit) = 0;
  };
#else
  typedef struct IDocHostShowUIVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDocHostShowUI *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDocHostShowUI *This);
      ULONG (WINAPI *Release)(IDocHostShowUI *This);
      HRESULT (WINAPI *ShowMessage)(IDocHostShowUI *This,HWND hwnd,LPOLESTR lpstrText,LPOLESTR lpstrCaption,DWORD dwType,LPOLESTR lpstrHelpFile,DWORD dwHelpContext,LRESULT *plResult);
      HRESULT (WINAPI *ShowHelp)(IDocHostShowUI *This,HWND hwnd,LPOLESTR pszHelpFile,UINT uCommand,DWORD dwData,POINT ptMouse,IDispatch *pDispatchObjectHit);
    END_INTERFACE
  } IDocHostShowUIVtbl;
  struct IDocHostShowUI {
    CONST_VTBL struct IDocHostShowUIVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDocHostShowUI_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDocHostShowUI_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDocHostShowUI_Release(This) (This)->lpVtbl->Release(This)
#define IDocHostShowUI_ShowMessage(This,hwnd,lpstrText,lpstrCaption,dwType,lpstrHelpFile,dwHelpContext,plResult) (This)->lpVtbl->ShowMessage(This,hwnd,lpstrText,lpstrCaption,dwType,lpstrHelpFile,dwHelpContext,plResult)
#define IDocHostShowUI_ShowHelp(This,hwnd,pszHelpFile,uCommand,dwData,ptMouse,pDispatchObjectHit) (This)->lpVtbl->ShowHelp(This,hwnd,pszHelpFile,uCommand,dwData,ptMouse,pDispatchObjectHit)
#endif
#endif
  HRESULT WINAPI IDocHostShowUI_ShowMessage_Proxy(IDocHostShowUI *This,HWND hwnd,LPOLESTR lpstrText,LPOLESTR lpstrCaption,DWORD dwType,LPOLESTR lpstrHelpFile,DWORD dwHelpContext,LRESULT *plResult);
  void __RPC_STUB IDocHostShowUI_ShowMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDocHostShowUI_ShowHelp_Proxy(IDocHostShowUI *This,HWND hwnd,LPOLESTR pszHelpFile,UINT uCommand,DWORD dwData,POINT ptMouse,IDispatch *pDispatchObjectHit);
  void __RPC_STUB IDocHostShowUI_ShowHelp_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define IClassFactory3 IClassFactoryEx
#define IID_IClassFactory3 IID_IClassFactoryEx

  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0281_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0281_v0_0_s_ifspec;

#ifndef __IClassFactoryEx_INTERFACE_DEFINED__
#define __IClassFactoryEx_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IClassFactoryEx;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IClassFactoryEx : public IClassFactory {
  public:
    virtual HRESULT WINAPI CreateInstanceWithContext(IUnknown *punkContext,IUnknown *punkOuter,REFIID riid,void **ppv) = 0;
  };
#else
  typedef struct IClassFactoryExVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IClassFactoryEx *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IClassFactoryEx *This);
      ULONG (WINAPI *Release)(IClassFactoryEx *This);
      HRESULT (WINAPI *CreateInstance)(IClassFactoryEx *This,IUnknown *pUnkOuter,REFIID riid,void **ppvObject);
      HRESULT (WINAPI *LockServer)(IClassFactoryEx *This,WINBOOL fLock);
      HRESULT (WINAPI *CreateInstanceWithContext)(IClassFactoryEx *This,IUnknown *punkContext,IUnknown *punkOuter,REFIID riid,void **ppv);
    END_INTERFACE
  } IClassFactoryExVtbl;
  struct IClassFactoryEx {
    CONST_VTBL struct IClassFactoryExVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IClassFactoryEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IClassFactoryEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IClassFactoryEx_Release(This) (This)->lpVtbl->Release(This)
#define IClassFactoryEx_CreateInstance(This,pUnkOuter,riid,ppvObject) (This)->lpVtbl->CreateInstance(This,pUnkOuter,riid,ppvObject)
#define IClassFactoryEx_LockServer(This,fLock) (This)->lpVtbl->LockServer(This,fLock)
#define IClassFactoryEx_CreateInstanceWithContext(This,punkContext,punkOuter,riid,ppv) (This)->lpVtbl->CreateInstanceWithContext(This,punkContext,punkOuter,riid,ppv)
#endif
#endif
  HRESULT WINAPI IClassFactoryEx_CreateInstanceWithContext_Proxy(IClassFactoryEx *This,IUnknown *punkContext,IUnknown *punkOuter,REFIID riid,void **ppv);
  void __RPC_STUB IClassFactoryEx_CreateInstanceWithContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IHTMLOMWindowServices_INTERFACE_DEFINED__
#define __IHTMLOMWindowServices_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IHTMLOMWindowServices;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IHTMLOMWindowServices : public IUnknown {
  public:
    virtual HRESULT WINAPI moveTo(LONG x,LONG y) = 0;
    virtual HRESULT WINAPI moveBy(LONG x,LONG y) = 0;
    virtual HRESULT WINAPI resizeTo(LONG x,LONG y) = 0;
    virtual HRESULT WINAPI resizeBy(LONG x,LONG y) = 0;
  };
#else
  typedef struct IHTMLOMWindowServicesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IHTMLOMWindowServices *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IHTMLOMWindowServices *This);
      ULONG (WINAPI *Release)(IHTMLOMWindowServices *This);
      HRESULT (WINAPI *moveTo)(IHTMLOMWindowServices *This,LONG x,LONG y);
      HRESULT (WINAPI *moveBy)(IHTMLOMWindowServices *This,LONG x,LONG y);
      HRESULT (WINAPI *resizeTo)(IHTMLOMWindowServices *This,LONG x,LONG y);
      HRESULT (WINAPI *resizeBy)(IHTMLOMWindowServices *This,LONG x,LONG y);
    END_INTERFACE
  } IHTMLOMWindowServicesVtbl;
  struct IHTMLOMWindowServices {
    CONST_VTBL struct IHTMLOMWindowServicesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IHTMLOMWindowServices_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IHTMLOMWindowServices_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IHTMLOMWindowServices_Release(This) (This)->lpVtbl->Release(This)
#define IHTMLOMWindowServices_moveTo(This,x,y) (This)->lpVtbl->moveTo(This,x,y)
#define IHTMLOMWindowServices_moveBy(This,x,y) (This)->lpVtbl->moveBy(This,x,y)
#define IHTMLOMWindowServices_resizeTo(This,x,y) (This)->lpVtbl->resizeTo(This,x,y)
#define IHTMLOMWindowServices_resizeBy(This,x,y) (This)->lpVtbl->resizeBy(This,x,y)
#endif
#endif
  HRESULT WINAPI IHTMLOMWindowServices_moveTo_Proxy(IHTMLOMWindowServices *This,LONG x,LONG y);
  void __RPC_STUB IHTMLOMWindowServices_moveTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IHTMLOMWindowServices_moveBy_Proxy(IHTMLOMWindowServices *This,LONG x,LONG y);
  void __RPC_STUB IHTMLOMWindowServices_moveBy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IHTMLOMWindowServices_resizeTo_Proxy(IHTMLOMWindowServices *This,LONG x,LONG y);
  void __RPC_STUB IHTMLOMWindowServices_resizeTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IHTMLOMWindowServices_resizeBy_Proxy(IHTMLOMWindowServices *This,LONG x,LONG y);
  void __RPC_STUB IHTMLOMWindowServices_resizeBy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SID_SHTMLOMWindowServices IID_IHTMLOMWindowServices
#endif

  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0283_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_mshtmhst_0283_v0_0_s_ifspec;

#ifdef __cplusplus
}
#endif
#endif
