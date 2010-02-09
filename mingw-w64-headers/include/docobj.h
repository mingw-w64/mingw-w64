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

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __docobj_h__
#define __docobj_h__

#ifndef __IOleDocument_FWD_DEFINED__
#define __IOleDocument_FWD_DEFINED__
typedef struct IOleDocument IOleDocument;
#endif

#ifndef __IOleDocumentSite_FWD_DEFINED__
#define __IOleDocumentSite_FWD_DEFINED__
typedef struct IOleDocumentSite IOleDocumentSite;
#endif

#ifndef __IOleDocumentView_FWD_DEFINED__
#define __IOleDocumentView_FWD_DEFINED__
typedef struct IOleDocumentView IOleDocumentView;
#endif

#ifndef __IEnumOleDocumentViews_FWD_DEFINED__
#define __IEnumOleDocumentViews_FWD_DEFINED__
typedef struct IEnumOleDocumentViews IEnumOleDocumentViews;
#endif

#ifndef __IContinueCallback_FWD_DEFINED__
#define __IContinueCallback_FWD_DEFINED__
typedef struct IContinueCallback IContinueCallback;
#endif

#ifndef __IPrint_FWD_DEFINED__
#define __IPrint_FWD_DEFINED__
typedef struct IPrint IPrint;
#endif

#ifndef __IOleCommandTarget_FWD_DEFINED__
#define __IOleCommandTarget_FWD_DEFINED__
typedef struct IOleCommandTarget IOleCommandTarget;
#endif

#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef _LPOLEDOCUMENT_DEFINED
#define _LPOLEDOCUMENT_DEFINED

  extern RPC_IF_HANDLE __MIDL_itf_docobj_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0000_v0_0_s_ifspec;

#ifndef __IOleDocument_INTERFACE_DEFINED__
#define __IOleDocument_INTERFACE_DEFINED__
  typedef IOleDocument *LPOLEDOCUMENT;
  typedef enum __MIDL_IOleDocument_0001 {
    DOCMISC_CANCREATEMULTIPLEVIEWS = 1,DOCMISC_SUPPORTCOMPLEXRECTANGLES = 2,DOCMISC_CANTOPENEDIT = 4,DOCMISC_NOFILESUPPORT = 8
  } DOCMISC;

  EXTERN_C const IID IID_IOleDocument;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IOleDocument : public IUnknown {
  public:
    virtual HRESULT WINAPI CreateView(IOleInPlaceSite *pIPSite,IStream *pstm,DWORD dwReserved,IOleDocumentView **ppView) = 0;
    virtual HRESULT WINAPI GetDocMiscStatus(DWORD *pdwStatus) = 0;
    virtual HRESULT WINAPI EnumViews(IEnumOleDocumentViews **ppEnum,IOleDocumentView **ppView) = 0;
  };
#else
  typedef struct IOleDocumentVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IOleDocument *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IOleDocument *This);
      ULONG (WINAPI *Release)(IOleDocument *This);
      HRESULT (WINAPI *CreateView)(IOleDocument *This,IOleInPlaceSite *pIPSite,IStream *pstm,DWORD dwReserved,IOleDocumentView **ppView);
      HRESULT (WINAPI *GetDocMiscStatus)(IOleDocument *This,DWORD *pdwStatus);
      HRESULT (WINAPI *EnumViews)(IOleDocument *This,IEnumOleDocumentViews **ppEnum,IOleDocumentView **ppView);
    END_INTERFACE
  } IOleDocumentVtbl;
  struct IOleDocument {
    CONST_VTBL struct IOleDocumentVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IOleDocument_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IOleDocument_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IOleDocument_Release(This) (This)->lpVtbl->Release(This)
#define IOleDocument_CreateView(This,pIPSite,pstm,dwReserved,ppView) (This)->lpVtbl->CreateView(This,pIPSite,pstm,dwReserved,ppView)
#define IOleDocument_GetDocMiscStatus(This,pdwStatus) (This)->lpVtbl->GetDocMiscStatus(This,pdwStatus)
#define IOleDocument_EnumViews(This,ppEnum,ppView) (This)->lpVtbl->EnumViews(This,ppEnum,ppView)
#endif
#endif
  HRESULT WINAPI IOleDocument_CreateView_Proxy(IOleDocument *This,IOleInPlaceSite *pIPSite,IStream *pstm,DWORD dwReserved,IOleDocumentView **ppView);
  void __RPC_STUB IOleDocument_CreateView_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocument_GetDocMiscStatus_Proxy(IOleDocument *This,DWORD *pdwStatus);
  void __RPC_STUB IOleDocument_GetDocMiscStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocument_EnumViews_Proxy(IOleDocument *This,IEnumOleDocumentViews **ppEnum,IOleDocumentView **ppView);
  void __RPC_STUB IOleDocument_EnumViews_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPOLEDOCUMENTSITE_DEFINED
#define _LPOLEDOCUMENTSITE_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0265_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0265_v0_0_s_ifspec;
#ifndef __IOleDocumentSite_INTERFACE_DEFINED__
#define __IOleDocumentSite_INTERFACE_DEFINED__
  typedef IOleDocumentSite *LPOLEDOCUMENTSITE;
  EXTERN_C const IID IID_IOleDocumentSite;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IOleDocumentSite : public IUnknown {
  public:
    virtual HRESULT WINAPI ActivateMe(IOleDocumentView *pViewToActivate) = 0;
  };
#else
  typedef struct IOleDocumentSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IOleDocumentSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IOleDocumentSite *This);
      ULONG (WINAPI *Release)(IOleDocumentSite *This);
      HRESULT (WINAPI *ActivateMe)(IOleDocumentSite *This,IOleDocumentView *pViewToActivate);
    END_INTERFACE
  } IOleDocumentSiteVtbl;
  struct IOleDocumentSite {
    CONST_VTBL struct IOleDocumentSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IOleDocumentSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IOleDocumentSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IOleDocumentSite_Release(This) (This)->lpVtbl->Release(This)
#define IOleDocumentSite_ActivateMe(This,pViewToActivate) (This)->lpVtbl->ActivateMe(This,pViewToActivate)
#endif
#endif
  HRESULT WINAPI IOleDocumentSite_ActivateMe_Proxy(IOleDocumentSite *This,IOleDocumentView *pViewToActivate);
  void __RPC_STUB IOleDocumentSite_ActivateMe_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPOLEDOCUMENTVIEW_DEFINED
#define _LPOLEDOCUMENTVIEW_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0266_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0266_v0_0_s_ifspec;

#ifndef __IOleDocumentView_INTERFACE_DEFINED__
#define __IOleDocumentView_INTERFACE_DEFINED__
  typedef IOleDocumentView *LPOLEDOCUMENTVIEW;
  EXTERN_C const IID IID_IOleDocumentView;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IOleDocumentView : public IUnknown {
  public:
    virtual HRESULT WINAPI SetInPlaceSite(IOleInPlaceSite *pIPSite) = 0;
    virtual HRESULT WINAPI GetInPlaceSite(IOleInPlaceSite **ppIPSite) = 0;
    virtual HRESULT WINAPI GetDocument(IUnknown **ppunk) = 0;
    virtual HRESULT WINAPI SetRect(LPRECT prcView) = 0;
    virtual HRESULT WINAPI GetRect(LPRECT prcView) = 0;
    virtual HRESULT WINAPI SetRectComplex(LPRECT prcView,LPRECT prcHScroll,LPRECT prcVScroll,LPRECT prcSizeBox) = 0;
    virtual HRESULT WINAPI Show(WINBOOL fShow) = 0;
    virtual HRESULT WINAPI UIActivate(WINBOOL fUIActivate) = 0;
    virtual HRESULT WINAPI Open(void) = 0;
    virtual HRESULT WINAPI CloseView(DWORD dwReserved) = 0;
    virtual HRESULT WINAPI SaveViewState(LPSTREAM pstm) = 0;
    virtual HRESULT WINAPI ApplyViewState(LPSTREAM pstm) = 0;
    virtual HRESULT WINAPI Clone(IOleInPlaceSite *pIPSiteNew,IOleDocumentView **ppViewNew) = 0;
  };
#else
  typedef struct IOleDocumentViewVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IOleDocumentView *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IOleDocumentView *This);
      ULONG (WINAPI *Release)(IOleDocumentView *This);
      HRESULT (WINAPI *SetInPlaceSite)(IOleDocumentView *This,IOleInPlaceSite *pIPSite);
      HRESULT (WINAPI *GetInPlaceSite)(IOleDocumentView *This,IOleInPlaceSite **ppIPSite);
      HRESULT (WINAPI *GetDocument)(IOleDocumentView *This,IUnknown **ppunk);
      HRESULT (WINAPI *SetRect)(IOleDocumentView *This,LPRECT prcView);
      HRESULT (WINAPI *GetRect)(IOleDocumentView *This,LPRECT prcView);
      HRESULT (WINAPI *SetRectComplex)(IOleDocumentView *This,LPRECT prcView,LPRECT prcHScroll,LPRECT prcVScroll,LPRECT prcSizeBox);
      HRESULT (WINAPI *Show)(IOleDocumentView *This,WINBOOL fShow);
      HRESULT (WINAPI *UIActivate)(IOleDocumentView *This,WINBOOL fUIActivate);
      HRESULT (WINAPI *Open)(IOleDocumentView *This);
      HRESULT (WINAPI *CloseView)(IOleDocumentView *This,DWORD dwReserved);
      HRESULT (WINAPI *SaveViewState)(IOleDocumentView *This,LPSTREAM pstm);
      HRESULT (WINAPI *ApplyViewState)(IOleDocumentView *This,LPSTREAM pstm);
      HRESULT (WINAPI *Clone)(IOleDocumentView *This,IOleInPlaceSite *pIPSiteNew,IOleDocumentView **ppViewNew);
    END_INTERFACE
  } IOleDocumentViewVtbl;
  struct IOleDocumentView {
    CONST_VTBL struct IOleDocumentViewVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IOleDocumentView_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IOleDocumentView_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IOleDocumentView_Release(This) (This)->lpVtbl->Release(This)
#define IOleDocumentView_SetInPlaceSite(This,pIPSite) (This)->lpVtbl->SetInPlaceSite(This,pIPSite)
#define IOleDocumentView_GetInPlaceSite(This,ppIPSite) (This)->lpVtbl->GetInPlaceSite(This,ppIPSite)
#define IOleDocumentView_GetDocument(This,ppunk) (This)->lpVtbl->GetDocument(This,ppunk)
#define IOleDocumentView_SetRect(This,prcView) (This)->lpVtbl->SetRect(This,prcView)
#define IOleDocumentView_GetRect(This,prcView) (This)->lpVtbl->GetRect(This,prcView)
#define IOleDocumentView_SetRectComplex(This,prcView,prcHScroll,prcVScroll,prcSizeBox) (This)->lpVtbl->SetRectComplex(This,prcView,prcHScroll,prcVScroll,prcSizeBox)
#define IOleDocumentView_Show(This,fShow) (This)->lpVtbl->Show(This,fShow)
#define IOleDocumentView_UIActivate(This,fUIActivate) (This)->lpVtbl->UIActivate(This,fUIActivate)
#define IOleDocumentView_Open(This) (This)->lpVtbl->Open(This)
#define IOleDocumentView_CloseView(This,dwReserved) (This)->lpVtbl->CloseView(This,dwReserved)
#define IOleDocumentView_SaveViewState(This,pstm) (This)->lpVtbl->SaveViewState(This,pstm)
#define IOleDocumentView_ApplyViewState(This,pstm) (This)->lpVtbl->ApplyViewState(This,pstm)
#define IOleDocumentView_Clone(This,pIPSiteNew,ppViewNew) (This)->lpVtbl->Clone(This,pIPSiteNew,ppViewNew)
#endif
#endif
  HRESULT WINAPI IOleDocumentView_SetInPlaceSite_Proxy(IOleDocumentView *This,IOleInPlaceSite *pIPSite);
  void __RPC_STUB IOleDocumentView_SetInPlaceSite_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_GetInPlaceSite_Proxy(IOleDocumentView *This,IOleInPlaceSite **ppIPSite);
  void __RPC_STUB IOleDocumentView_GetInPlaceSite_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_GetDocument_Proxy(IOleDocumentView *This,IUnknown **ppunk);
  void __RPC_STUB IOleDocumentView_GetDocument_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_SetRect_Proxy(IOleDocumentView *This,LPRECT prcView);
  void __RPC_STUB IOleDocumentView_SetRect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_GetRect_Proxy(IOleDocumentView *This,LPRECT prcView);
  void __RPC_STUB IOleDocumentView_GetRect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_SetRectComplex_Proxy(IOleDocumentView *This,LPRECT prcView,LPRECT prcHScroll,LPRECT prcVScroll,LPRECT prcSizeBox);
  void __RPC_STUB IOleDocumentView_SetRectComplex_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_Show_Proxy(IOleDocumentView *This,WINBOOL fShow);
  void __RPC_STUB IOleDocumentView_Show_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_UIActivate_Proxy(IOleDocumentView *This,WINBOOL fUIActivate);
  void __RPC_STUB IOleDocumentView_UIActivate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_Open_Proxy(IOleDocumentView *This);
  void __RPC_STUB IOleDocumentView_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_CloseView_Proxy(IOleDocumentView *This,DWORD dwReserved);
  void __RPC_STUB IOleDocumentView_CloseView_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_SaveViewState_Proxy(IOleDocumentView *This,LPSTREAM pstm);
  void __RPC_STUB IOleDocumentView_SaveViewState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_ApplyViewState_Proxy(IOleDocumentView *This,LPSTREAM pstm);
  void __RPC_STUB IOleDocumentView_ApplyViewState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleDocumentView_Clone_Proxy(IOleDocumentView *This,IOleInPlaceSite *pIPSiteNew,IOleDocumentView **ppViewNew);
  void __RPC_STUB IOleDocumentView_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPENUMOLEDOCUMENTVIEWS_DEFINED
#define _LPENUMOLEDOCUMENTVIEWS_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0267_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0267_v0_0_s_ifspec;
#ifndef __IEnumOleDocumentViews_INTERFACE_DEFINED__
#define __IEnumOleDocumentViews_INTERFACE_DEFINED__
  typedef IEnumOleDocumentViews *LPENUMOLEDOCUMENTVIEWS;
  EXTERN_C const IID IID_IEnumOleDocumentViews;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumOleDocumentViews : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG cViews,IOleDocumentView **rgpView,ULONG *pcFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG cViews) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumOleDocumentViews **ppEnum) = 0;
  };
#else
  typedef struct IEnumOleDocumentViewsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumOleDocumentViews *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumOleDocumentViews *This);
      ULONG (WINAPI *Release)(IEnumOleDocumentViews *This);
      HRESULT (WINAPI *Next)(IEnumOleDocumentViews *This,ULONG cViews,IOleDocumentView **rgpView,ULONG *pcFetched);
      HRESULT (WINAPI *Skip)(IEnumOleDocumentViews *This,ULONG cViews);
      HRESULT (WINAPI *Reset)(IEnumOleDocumentViews *This);
      HRESULT (WINAPI *Clone)(IEnumOleDocumentViews *This,IEnumOleDocumentViews **ppEnum);
    END_INTERFACE
  } IEnumOleDocumentViewsVtbl;
  struct IEnumOleDocumentViews {
    CONST_VTBL struct IEnumOleDocumentViewsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumOleDocumentViews_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumOleDocumentViews_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumOleDocumentViews_Release(This) (This)->lpVtbl->Release(This)
#define IEnumOleDocumentViews_Next(This,cViews,rgpView,pcFetched) (This)->lpVtbl->Next(This,cViews,rgpView,pcFetched)
#define IEnumOleDocumentViews_Skip(This,cViews) (This)->lpVtbl->Skip(This,cViews)
#define IEnumOleDocumentViews_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumOleDocumentViews_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif
#endif
  HRESULT WINAPI IEnumOleDocumentViews_RemoteNext_Proxy(IEnumOleDocumentViews *This,ULONG cViews,IOleDocumentView **rgpView,ULONG *pcFetched);
  void __RPC_STUB IEnumOleDocumentViews_RemoteNext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumOleDocumentViews_Skip_Proxy(IEnumOleDocumentViews *This,ULONG cViews);
  void __RPC_STUB IEnumOleDocumentViews_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumOleDocumentViews_Reset_Proxy(IEnumOleDocumentViews *This);
  void __RPC_STUB IEnumOleDocumentViews_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumOleDocumentViews_Clone_Proxy(IEnumOleDocumentViews *This,IEnumOleDocumentViews **ppEnum);
  void __RPC_STUB IEnumOleDocumentViews_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPCONTINUECALLBACK_DEFINED
#define _LPCONTINUECALLBACK_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0268_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0268_v0_0_s_ifspec;
#ifndef __IContinueCallback_INTERFACE_DEFINED__
#define __IContinueCallback_INTERFACE_DEFINED__
  typedef IContinueCallback *LPCONTINUECALLBACK;
  EXTERN_C const IID IID_IContinueCallback;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IContinueCallback : public IUnknown {
  public:
    virtual HRESULT WINAPI FContinue(void) = 0;
    virtual HRESULT WINAPI FContinuePrinting(LONG nCntPrinted,LONG nCurPage,wchar_t *pwszPrintStatus) = 0;
  };
#else
  typedef struct IContinueCallbackVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IContinueCallback *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IContinueCallback *This);
      ULONG (WINAPI *Release)(IContinueCallback *This);
      HRESULT (WINAPI *FContinue)(IContinueCallback *This);
      HRESULT (WINAPI *FContinuePrinting)(IContinueCallback *This,LONG nCntPrinted,LONG nCurPage,wchar_t *pwszPrintStatus);
    END_INTERFACE
  } IContinueCallbackVtbl;
  struct IContinueCallback {
    CONST_VTBL struct IContinueCallbackVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IContinueCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IContinueCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IContinueCallback_Release(This) (This)->lpVtbl->Release(This)
#define IContinueCallback_FContinue(This) (This)->lpVtbl->FContinue(This)
#define IContinueCallback_FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus) (This)->lpVtbl->FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus)
#endif
#endif
  HRESULT WINAPI IContinueCallback_FContinue_Proxy(IContinueCallback *This);
  void __RPC_STUB IContinueCallback_FContinue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IContinueCallback_FContinuePrinting_Proxy(IContinueCallback *This,LONG nCntPrinted,LONG nCurPage,wchar_t *pwszPrintStatus);
  void __RPC_STUB IContinueCallback_FContinuePrinting_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPPRINT_DEFINED
#define _LPPRINT_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0269_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0269_v0_0_s_ifspec;
#ifndef __IPrint_INTERFACE_DEFINED__
#define __IPrint_INTERFACE_DEFINED__
  typedef IPrint *LPPRINT;
  typedef enum __MIDL_IPrint_0001 {
    PRINTFLAG_MAYBOTHERUSER = 1,PRINTFLAG_PROMPTUSER = 2,PRINTFLAG_USERMAYCHANGEPRINTER = 4,PRINTFLAG_RECOMPOSETODEVICE = 8,
    PRINTFLAG_DONTACTUALLYPRINT = 16,PRINTFLAG_FORCEPROPERTIES = 32,PRINTFLAG_PRINTTOFILE = 64
  } PRINTFLAG;
  typedef struct tagPAGERANGE {
    LONG nFromPage;
    LONG nToPage;
  } PAGERANGE;

  typedef struct tagPAGESET {
    ULONG cbStruct;
    WINBOOL fOddPages;
    WINBOOL fEvenPages;
    ULONG cPageRange;
    PAGERANGE rgPages[1 ];
  } PAGESET;
#define PAGESET_TOLASTPAGE ((WORD)(-1L))

  EXTERN_C const IID IID_IPrint;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPrint : public IUnknown {
  public:
    virtual HRESULT WINAPI SetInitialPageNum(LONG nFirstPage) = 0;
    virtual HRESULT WINAPI GetPageInfo(LONG *pnFirstPage,LONG *pcPages) = 0;
    virtual HRESULT WINAPI Print(DWORD grfFlags,DVTARGETDEVICE **pptd,PAGESET **ppPageSet,STGMEDIUM *pstgmOptions,IContinueCallback *pcallback,LONG nFirstPage,LONG *pcPagesPrinted,LONG *pnLastPage) = 0;
  };
#else
  typedef struct IPrintVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPrint *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPrint *This);
      ULONG (WINAPI *Release)(IPrint *This);
      HRESULT (WINAPI *SetInitialPageNum)(IPrint *This,LONG nFirstPage);
      HRESULT (WINAPI *GetPageInfo)(IPrint *This,LONG *pnFirstPage,LONG *pcPages);
      HRESULT (WINAPI *Print)(IPrint *This,DWORD grfFlags,DVTARGETDEVICE **pptd,PAGESET **ppPageSet,STGMEDIUM *pstgmOptions,IContinueCallback *pcallback,LONG nFirstPage,LONG *pcPagesPrinted,LONG *pnLastPage);
    END_INTERFACE
  } IPrintVtbl;
  struct IPrint {
    CONST_VTBL struct IPrintVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPrint_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPrint_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPrint_Release(This) (This)->lpVtbl->Release(This)
#define IPrint_SetInitialPageNum(This,nFirstPage) (This)->lpVtbl->SetInitialPageNum(This,nFirstPage)
#define IPrint_GetPageInfo(This,pnFirstPage,pcPages) (This)->lpVtbl->GetPageInfo(This,pnFirstPage,pcPages)
#define IPrint_Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage) (This)->lpVtbl->Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage)
#endif
#endif
  HRESULT WINAPI IPrint_SetInitialPageNum_Proxy(IPrint *This,LONG nFirstPage);
  void __RPC_STUB IPrint_SetInitialPageNum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPrint_GetPageInfo_Proxy(IPrint *This,LONG *pnFirstPage,LONG *pcPages);
  void __RPC_STUB IPrint_GetPageInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPrint_RemotePrint_Proxy(IPrint *This,DWORD grfFlags,DVTARGETDEVICE **pptd,PAGESET **pppageset,RemSTGMEDIUM *pstgmOptions,IContinueCallback *pcallback,LONG nFirstPage,LONG *pcPagesPrinted,LONG *pnLastPage);
  void __RPC_STUB IPrint_RemotePrint_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPOLECOMMANDTARGET_DEFINED
#define _LPOLECOMMANDTARGET_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0270_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0270_v0_0_s_ifspec;
#ifndef __IOleCommandTarget_INTERFACE_DEFINED__
#define __IOleCommandTarget_INTERFACE_DEFINED__
  typedef IOleCommandTarget *LPOLECOMMANDTARGET;
  typedef enum OLECMDF {
    OLECMDF_SUPPORTED = 0x1,OLECMDF_ENABLED = 0x2,OLECMDF_LATCHED = 0x4,OLECMDF_NINCHED = 0x8,OLECMDF_INVISIBLE = 0x10,
    OLECMDF_DEFHIDEONCTXTMENU = 0x20
  } OLECMDF;

  typedef struct _tagOLECMD {
    ULONG cmdID;
    DWORD cmdf;
  } OLECMD;

  typedef struct _tagOLECMDTEXT {
    DWORD cmdtextf;
    ULONG cwActual;
    ULONG cwBuf;
    wchar_t rgwz[1 ];
  } OLECMDTEXT;

  typedef enum OLECMDTEXTF {
    OLECMDTEXTF_NONE = 0,OLECMDTEXTF_NAME = 1,OLECMDTEXTF_STATUS = 2
  } OLECMDTEXTF;

  typedef enum OLECMDEXECOPT {
    OLECMDEXECOPT_DODEFAULT = 0,OLECMDEXECOPT_PROMPTUSER = 1,OLECMDEXECOPT_DONTPROMPTUSER = 2,OLECMDEXECOPT_SHOWHELP = 3
  } OLECMDEXECOPT;

  typedef enum OLECMDID {
    OLECMDID_OPEN = 1,OLECMDID_NEW = 2,OLECMDID_SAVE = 3,OLECMDID_SAVEAS = 4,OLECMDID_SAVECOPYAS = 5,OLECMDID_PRINT = 6,OLECMDID_PRINTPREVIEW = 7,OLECMDID_PAGESETUP = 8,OLECMDID_SPELL = 9,OLECMDID_PROPERTIES = 10,OLECMDID_CUT = 11,OLECMDID_COPY = 12,OLECMDID_PASTE = 13,OLECMDID_PASTESPECIAL = 14,OLECMDID_UNDO = 15,OLECMDID_REDO = 16,OLECMDID_SELECTALL = 17,OLECMDID_CLEARSELECTION = 18,OLECMDID_ZOOM = 19,OLECMDID_GETZOOMRANGE = 20,OLECMDID_UPDATECOMMANDS = 21,OLECMDID_REFRESH = 22,OLECMDID_STOP = 23,OLECMDID_HIDETOOLBARS = 24,OLECMDID_SETPROGRESSMAX = 25,OLECMDID_SETPROGRESSPOS = 26,OLECMDID_SETPROGRESSTEXT = 27,OLECMDID_SETTITLE = 28,OLECMDID_SETDOWNLOADSTATE = 29,OLECMDID_STOPDOWNLOAD = 30,OLECMDID_ONTOOLBARACTIVATED = 31,OLECMDID_FIND = 32,OLECMDID_DELETE = 33,OLECMDID_HTTPEQUIV = 34,OLECMDID_HTTPEQUIV_DONE = 35,OLECMDID_ENABLE_INTERACTION = 36,OLECMDID_ONUNLOAD = 37,OLECMDID_PROPERTYBAG2 = 38,OLECMDID_PREREFRESH = 39,OLECMDID_SHOWSCRIPTERROR = 40,OLECMDID_SHOWMESSAGE = 41,OLECMDID_SHOWFIND = 42,OLECMDID_SHOWPAGESETUP = 43,OLECMDID_SHOWPRINT = 44,OLECMDID_CLOSE = 45,OLECMDID_ALLOWUILESSSAVEAS = 46,OLECMDID_DONTDOWNLOADCSS = 47,OLECMDID_UPDATEPAGESTATUS = 48,OLECMDID_PRINT2 = 49,OLECMDID_PRINTPREVIEW2 = 50,OLECMDID_SETPRINTTEMPLATE = 51,OLECMDID_GETPRINTTEMPLATE = 52,OLECMDID_PAGEACTIONBLOCKED = 55,OLECMDID_PAGEACTIONUIQUERY = 56,OLECMDID_FOCUSVIEWCONTROLS = 57,OLECMDID_FOCUSVIEWCONTROLSQUERY = 58,OLECMDID_SHOWPAGEACTIONMENU = 59
  } OLECMDID;

#define OLECMDERR_E_FIRST (OLE_E_LAST+1)
#define OLECMDERR_E_NOTSUPPORTED (OLECMDERR_E_FIRST)
#define OLECMDERR_E_DISABLED (OLECMDERR_E_FIRST+1)
#define OLECMDERR_E_NOHELP (OLECMDERR_E_FIRST+2)
#define OLECMDERR_E_CANCELED (OLECMDERR_E_FIRST+3)
#define OLECMDERR_E_UNKNOWNGROUP (OLECMDERR_E_FIRST+4)
#define MSOCMDERR_E_FIRST OLECMDERR_E_FIRST
#define MSOCMDERR_E_NOTSUPPORTED OLECMDERR_E_NOTSUPPORTED
#define MSOCMDERR_E_DISABLED OLECMDERR_E_DISABLED
#define MSOCMDERR_E_NOHELP OLECMDERR_E_NOHELP
#define MSOCMDERR_E_CANCELED OLECMDERR_E_CANCELED
#define MSOCMDERR_E_UNKNOWNGROUP OLECMDERR_E_UNKNOWNGROUP
#define OLECMDARGINDEX_SHOWPAGEACTIONMENU_HWND 0
#define OLECMDARGINDEX_SHOWPAGEACTIONMENU_X 1
#define OLECMDARGINDEX_SHOWPAGEACTIONMENU_Y 2
#define OLECMDARGINDEX_ACTIVEXINSTALL_PUBLISHER 0
#define OLECMDARGINDEX_ACTIVEXINSTALL_DISPLAYNAME 1

  typedef enum IGNOREMIME {
    IGNOREMIME_PROMPT = 0x1,IGNOREMIME_TEXT = 0x2
  } IGNOREMIME;

  EXTERN_C const IID IID_IOleCommandTarget;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IOleCommandTarget : public IUnknown {
  public:
    virtual HRESULT WINAPI QueryStatus(const GUID *pguidCmdGroup,ULONG cCmds,OLECMD prgCmds[],OLECMDTEXT *pCmdText) = 0;
    virtual HRESULT WINAPI Exec(const GUID *pguidCmdGroup,DWORD nCmdID,DWORD nCmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut) = 0;
  };
#else
  typedef struct IOleCommandTargetVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IOleCommandTarget *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IOleCommandTarget *This);
      ULONG (WINAPI *Release)(IOleCommandTarget *This);
      HRESULT (WINAPI *QueryStatus)(IOleCommandTarget *This,const GUID *pguidCmdGroup,ULONG cCmds,OLECMD prgCmds[],OLECMDTEXT *pCmdText);
      HRESULT (WINAPI *Exec)(IOleCommandTarget *This,const GUID *pguidCmdGroup,DWORD nCmdID,DWORD nCmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut);
    END_INTERFACE
  } IOleCommandTargetVtbl;
  struct IOleCommandTarget {
    CONST_VTBL struct IOleCommandTargetVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IOleCommandTarget_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IOleCommandTarget_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IOleCommandTarget_Release(This) (This)->lpVtbl->Release(This)
#define IOleCommandTarget_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText) (This)->lpVtbl->QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)
#define IOleCommandTarget_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut) (This)->lpVtbl->Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)
#endif
#endif
  HRESULT WINAPI IOleCommandTarget_QueryStatus_Proxy(IOleCommandTarget *This,const GUID *pguidCmdGroup,ULONG cCmds,OLECMD prgCmds[],OLECMDTEXT *pCmdText);
  void __RPC_STUB IOleCommandTarget_QueryStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IOleCommandTarget_Exec_Proxy(IOleCommandTarget *This,const GUID *pguidCmdGroup,DWORD nCmdID,DWORD nCmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut);
  void __RPC_STUB IOleCommandTarget_Exec_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  typedef enum {
    OLECMDIDF_REFRESH_NORMAL = 0,OLECMDIDF_REFRESH_IFEXPIRED = 1,OLECMDIDF_REFRESH_CONTINUE = 2,OLECMDIDF_REFRESH_COMPLETELY = 3,
    OLECMDIDF_REFRESH_NO_CACHE = 4,OLECMDIDF_REFRESH_RELOAD = 5,OLECMDIDF_REFRESH_LEVELMASK = 0x00FF,OLECMDIDF_REFRESH_CLEARUSERINPUT = 0x1000,
    OLECMDIDF_REFRESH_PROMPTIFOFFLINE = 0x2000,OLECMDIDF_REFRESH_THROUGHSCRIPT = 0x4000,OLECMDIDF_REFRESH_PAGEACTION_ACTIVEXINSTALL = 0x00010000,
    OLECMDIDF_REFRESH_PAGEACTION_FILEDOWNLOAD = 0x00020000,OLECMDIDF_REFRESH_PAGEACTION_LOCALMACHINE = 0x00040000,
    OLECMDIDF_REFRESH_PAGEACTION_POPUPWINDOW = 0x00080000,OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNLOCALMACHINE = 0x00100000,
    OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNTRUSTED = 0x00200000,OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTRANET = 0x00400000,
    OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTERNET = 0x00800000,OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNRESTRICTED = 0x01000000
  } OLECMDID_REFRESHFLAG;

  typedef enum {
    OLECMDIDF_PAGEACTION_FILEDOWNLOAD = 0x00000001,OLECMDIDF_PAGEACTION_ACTIVEXINSTALL = 0x00000002,
    OLECMDIDF_PAGEACTION_ACTIVEXTRUSTFAIL = 0x00000004,OLECMDIDF_PAGEACTION_ACTIVEXUSERDISABLE = 0x00000008,
    OLECMDIDF_PAGEACTION_ACTIVEXDISALLOW = 0x00000010,OLECMDIDF_PAGEACTION_ACTIVEXUNSAFE = 0x00000020,OLECMDIDF_PAGEACTION_POPUPWINDOW = 0x00000040,
    OLECMDIDF_PAGEACTION_LOCALMACHINE = 0x00000080,OLECMDIDF_PAGEACTION_MIMETEXTPLAIN = 0x00000100,OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE = 0x00000200,
    OLECMDIDF_PAGEACTION_PROTLOCKDOWNLOCALMACHINE = 0x00000400,OLECMDIDF_PAGEACTION_PROTLOCKDOWNTRUSTED = 0x00000800,
    OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTRANET = 0x00001000,OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTERNET = 0x00002000,
    OLECMDIDF_PAGEACTION_PROTLOCKDOWNRESTRICTED = 0x00004000,OLECMDIDF_PAGEACTION_PROTLOCKDOWNDENY = 0x00008000,
    OLECMDIDF_PAGEACTION_POPUPALLOWED = 0x00010000,OLECMDIDF_PAGEACTION_RESET = 0x80000000
  } OLECMDID_PAGEACTIONFLAG;

  typedef enum {
    PAGEACTION_UI_DEFAULT = 0,PAGEACTION_UI_MODAL = 1,PAGEACTION_UI_MODELESS = 2,PAGEACTION_UI_SILENT = 3
  } PAGEACTION_UI;

#define IMsoDocument IOleDocument
#define IMsoDocumentSite IOleDocumentSite
#define IMsoView IOleDocumentView
#define IEnumMsoView IEnumOleDocumentViews
#define IMsoCommandTarget IOleCommandTarget
#define LPMSODOCUMENT LPOLEDOCUMENT
#define LPMSODOCUMENTSITE LPOLEDOCUMENTSITE
#define LPMSOVIEW LPOLEDOCUMENTVIEW
#define LPENUMMSOVIEW LPENUMOLEDOCUMENTVIEWS
#define LPMSOCOMMANDTARGET LPOLECOMMANDTARGET
#define MSOCMD OLECMD
#define MSOCMDTEXT OLECMDTEXT
#define IID_IMsoDocument IID_IOleDocument
#define IID_IMsoDocumentSite IID_IOleDocumentSite
#define IID_IMsoView IID_IOleDocumentView
#define IID_IEnumMsoView IID_IEnumOleDocumentViews
#define IID_IMsoCommandTarget IID_IOleCommandTarget
#define MSOCMDF_SUPPORTED OLECMDF_SUPPORTED
#define MSOCMDF_ENABLED OLECMDF_ENABLED
#define MSOCMDF_LATCHED OLECMDF_LATCHED
#define MSOCMDF_NINCHED OLECMDF_NINCHED
#define MSOCMDTEXTF_NONE OLECMDTEXTF_NONE
#define MSOCMDTEXTF_NAME OLECMDTEXTF_NAME
#define MSOCMDTEXTF_STATUS OLECMDTEXTF_STATUS
#define MSOCMDEXECOPT_DODEFAULT OLECMDEXECOPT_DODEFAULT
#define MSOCMDEXECOPT_PROMPTUSER OLECMDEXECOPT_PROMPTUSER
#define MSOCMDEXECOPT_DONTPROMPTUSER OLECMDEXECOPT_DONTPROMPTUSER
#define MSOCMDEXECOPT_SHOWHELP OLECMDEXECOPT_SHOWHELP
#define MSOCMDID_OPEN OLECMDID_OPEN
#define MSOCMDID_NEW OLECMDID_NEW
#define MSOCMDID_SAVE OLECMDID_SAVE
#define MSOCMDID_SAVEAS OLECMDID_SAVEAS
#define MSOCMDID_SAVECOPYAS OLECMDID_SAVECOPYAS
#define MSOCMDID_PRINT OLECMDID_PRINT
#define MSOCMDID_PRINTPREVIEW OLECMDID_PRINTPREVIEW
#define MSOCMDID_PAGESETUP OLECMDID_PAGESETUP
#define MSOCMDID_SPELL OLECMDID_SPELL
#define MSOCMDID_PROPERTIES OLECMDID_PROPERTIES
#define MSOCMDID_CUT OLECMDID_CUT
#define MSOCMDID_COPY OLECMDID_COPY
#define MSOCMDID_PASTE OLECMDID_PASTE
#define MSOCMDID_PASTESPECIAL OLECMDID_PASTESPECIAL
#define MSOCMDID_UNDO OLECMDID_UNDO
#define MSOCMDID_REDO OLECMDID_REDO
#define MSOCMDID_SELECTALL OLECMDID_SELECTALL
#define MSOCMDID_CLEARSELECTION OLECMDID_CLEARSELECTION
#define MSOCMDID_ZOOM OLECMDID_ZOOM
#define MSOCMDID_GETZOOMRANGE OLECMDID_GETZOOMRANGE
  EXTERN_C const GUID SID_SContainerDispatch;

  extern RPC_IF_HANDLE __MIDL_itf_docobj_0271_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_docobj_0271_v0_0_s_ifspec;

  unsigned long __RPC_API VARIANT_UserSize(unsigned long *,unsigned long,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(unsigned long *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(unsigned long *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(unsigned long *,VARIANT *);

  HRESULT WINAPI IEnumOleDocumentViews_Next_Proxy(IEnumOleDocumentViews *This,ULONG cViews,IOleDocumentView **rgpView,ULONG *pcFetched);
  HRESULT WINAPI IEnumOleDocumentViews_Next_Stub(IEnumOleDocumentViews *This,ULONG cViews,IOleDocumentView **rgpView,ULONG *pcFetched);
  HRESULT WINAPI IPrint_Print_Proxy(IPrint *This,DWORD grfFlags,DVTARGETDEVICE **pptd,PAGESET **ppPageSet,STGMEDIUM *pstgmOptions,IContinueCallback *pcallback,LONG nFirstPage,LONG *pcPagesPrinted,LONG *pnLastPage);
  HRESULT WINAPI IPrint_Print_Stub(IPrint *This,DWORD grfFlags,DVTARGETDEVICE **pptd,PAGESET **pppageset,RemSTGMEDIUM *pstgmOptions,IContinueCallback *pcallback,LONG nFirstPage,LONG *pcPagesPrinted,LONG *pnLastPage);

#ifdef __cplusplus
}
#endif
#endif
