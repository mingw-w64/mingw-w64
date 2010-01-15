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

#ifndef __urlhist_h__
#define __urlhist_h__

#ifndef __IEnumSTATURL_FWD_DEFINED__
#define __IEnumSTATURL_FWD_DEFINED__
typedef struct IEnumSTATURL IEnumSTATURL;
#endif

#ifndef __IUrlHistoryStg_FWD_DEFINED__
#define __IUrlHistoryStg_FWD_DEFINED__
typedef struct IUrlHistoryStg IUrlHistoryStg;
#endif

#ifndef __IUrlHistoryStg2_FWD_DEFINED__
#define __IUrlHistoryStg2_FWD_DEFINED__
typedef struct IUrlHistoryStg2 IUrlHistoryStg2;
#endif

#ifndef __IUrlHistoryNotify_FWD_DEFINED__
#define __IUrlHistoryNotify_FWD_DEFINED__
typedef struct IUrlHistoryNotify IUrlHistoryNotify;
#endif

#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "docobj.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#define STATURL_QUERYFLAG_ISCACHED 0x00010000
#define STATURL_QUERYFLAG_NOURL 0x00020000
#define STATURL_QUERYFLAG_NOTITLE 0x00040000
#define STATURL_QUERYFLAG_TOPLEVEL 0x00080000
#define STATURLFLAG_ISCACHED 0x00000001
#define STATURLFLAG_ISTOPLEVEL 0x00000002
  typedef enum _ADDURL_FLAG {
    ADDURL_FIRST = 0,ADDURL_ADDTOHISTORYANDCACHE = 0,ADDURL_ADDTOCACHE = 1,ADDURL_Max = 2147483647L
  } ADDURL_FLAG;

#ifndef _LPENUMSTATURL_DEFINED
#define _LPENUMSTATURL_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0000_v0_0_s_ifspec;
#ifndef __IEnumSTATURL_INTERFACE_DEFINED__
#define __IEnumSTATURL_INTERFACE_DEFINED__
  typedef IEnumSTATURL *LPENUMSTATURL;

  typedef struct _STATURL {
    DWORD cbSize;
    LPWSTR pwcsUrl;
    LPWSTR pwcsTitle;
    FILETIME ftLastVisited;
    FILETIME ftLastUpdated;
    FILETIME ftExpires;
    DWORD dwFlags;
  } STATURL;

  typedef struct _STATURL *LPSTATURL;

  EXTERN_C const IID IID_IEnumSTATURL;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumSTATURL : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,LPSTATURL rgelt,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumSTATURL **ppenum) = 0;
    virtual HRESULT WINAPI SetFilter(LPCOLESTR poszFilter,DWORD dwFlags) = 0;
  };
#else
  typedef struct IEnumSTATURLVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumSTATURL *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumSTATURL *This);
      ULONG (WINAPI *Release)(IEnumSTATURL *This);
      HRESULT (WINAPI *Next)(IEnumSTATURL *This,ULONG celt,LPSTATURL rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumSTATURL *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumSTATURL *This);
      HRESULT (WINAPI *Clone)(IEnumSTATURL *This,IEnumSTATURL **ppenum);
      HRESULT (WINAPI *SetFilter)(IEnumSTATURL *This,LPCOLESTR poszFilter,DWORD dwFlags);
    END_INTERFACE
  } IEnumSTATURLVtbl;
  struct IEnumSTATURL {
    CONST_VTBL struct IEnumSTATURLVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumSTATURL_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumSTATURL_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumSTATURL_Release(This) (This)->lpVtbl->Release(This)
#define IEnumSTATURL_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumSTATURL_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumSTATURL_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumSTATURL_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#define IEnumSTATURL_SetFilter(This,poszFilter,dwFlags) (This)->lpVtbl->SetFilter(This,poszFilter,dwFlags)
#endif
#endif
  HRESULT WINAPI IEnumSTATURL_Next_Proxy(IEnumSTATURL *This,ULONG celt,LPSTATURL rgelt,ULONG *pceltFetched);
  void __RPC_STUB IEnumSTATURL_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumSTATURL_Skip_Proxy(IEnumSTATURL *This,ULONG celt);
  void __RPC_STUB IEnumSTATURL_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumSTATURL_Reset_Proxy(IEnumSTATURL *This);
  void __RPC_STUB IEnumSTATURL_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumSTATURL_Clone_Proxy(IEnumSTATURL *This,IEnumSTATURL **ppenum);
  void __RPC_STUB IEnumSTATURL_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumSTATURL_SetFilter_Proxy(IEnumSTATURL *This,LPCOLESTR poszFilter,DWORD dwFlags);
  void __RPC_STUB IEnumSTATURL_SetFilter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPURLHISTORYSTG_DEFINED
#define _LPURLHISTORYSTG_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0277_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0277_v0_0_s_ifspec;
#ifndef __IUrlHistoryStg_INTERFACE_DEFINED__
#define __IUrlHistoryStg_INTERFACE_DEFINED__
  typedef IUrlHistoryStg *LPURLHISTORYSTG;

  EXTERN_C const IID IID_IUrlHistoryStg;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUrlHistoryStg : public IUnknown {
  public:
    virtual HRESULT WINAPI AddUrl(LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI DeleteUrl(LPCOLESTR pocsUrl,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI QueryUrl(LPCOLESTR pocsUrl,DWORD dwFlags,LPSTATURL lpSTATURL) = 0;
    virtual HRESULT WINAPI BindToObject(LPCOLESTR pocsUrl,REFIID riid,void **ppvOut) = 0;
    virtual HRESULT WINAPI EnumUrls(IEnumSTATURL **ppEnum) = 0;
  };
#else
  typedef struct IUrlHistoryStgVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUrlHistoryStg *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUrlHistoryStg *This);
      ULONG (WINAPI *Release)(IUrlHistoryStg *This);
      HRESULT (WINAPI *AddUrl)(IUrlHistoryStg *This,LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags);
      HRESULT (WINAPI *DeleteUrl)(IUrlHistoryStg *This,LPCOLESTR pocsUrl,DWORD dwFlags);
      HRESULT (WINAPI *QueryUrl)(IUrlHistoryStg *This,LPCOLESTR pocsUrl,DWORD dwFlags,LPSTATURL lpSTATURL);
      HRESULT (WINAPI *BindToObject)(IUrlHistoryStg *This,LPCOLESTR pocsUrl,REFIID riid,void **ppvOut);
      HRESULT (WINAPI *EnumUrls)(IUrlHistoryStg *This,IEnumSTATURL **ppEnum);
    END_INTERFACE
  } IUrlHistoryStgVtbl;
  struct IUrlHistoryStg {
    CONST_VTBL struct IUrlHistoryStgVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUrlHistoryStg_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUrlHistoryStg_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUrlHistoryStg_Release(This) (This)->lpVtbl->Release(This)
#define IUrlHistoryStg_AddUrl(This,pocsUrl,pocsTitle,dwFlags) (This)->lpVtbl->AddUrl(This,pocsUrl,pocsTitle,dwFlags)
#define IUrlHistoryStg_DeleteUrl(This,pocsUrl,dwFlags) (This)->lpVtbl->DeleteUrl(This,pocsUrl,dwFlags)
#define IUrlHistoryStg_QueryUrl(This,pocsUrl,dwFlags,lpSTATURL) (This)->lpVtbl->QueryUrl(This,pocsUrl,dwFlags,lpSTATURL)
#define IUrlHistoryStg_BindToObject(This,pocsUrl,riid,ppvOut) (This)->lpVtbl->BindToObject(This,pocsUrl,riid,ppvOut)
#define IUrlHistoryStg_EnumUrls(This,ppEnum) (This)->lpVtbl->EnumUrls(This,ppEnum)
#endif
#endif
  HRESULT WINAPI IUrlHistoryStg_AddUrl_Proxy(IUrlHistoryStg *This,LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags);
  void __RPC_STUB IUrlHistoryStg_AddUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUrlHistoryStg_DeleteUrl_Proxy(IUrlHistoryStg *This,LPCOLESTR pocsUrl,DWORD dwFlags);
  void __RPC_STUB IUrlHistoryStg_DeleteUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUrlHistoryStg_QueryUrl_Proxy(IUrlHistoryStg *This,LPCOLESTR pocsUrl,DWORD dwFlags,LPSTATURL lpSTATURL);
  void __RPC_STUB IUrlHistoryStg_QueryUrl_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUrlHistoryStg_BindToObject_Proxy(IUrlHistoryStg *This,LPCOLESTR pocsUrl,REFIID riid,void **ppvOut);
  void __RPC_STUB IUrlHistoryStg_BindToObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUrlHistoryStg_EnumUrls_Proxy(IUrlHistoryStg *This,IEnumSTATURL **ppEnum);
  void __RPC_STUB IUrlHistoryStg_EnumUrls_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPURLHISTORYSTG2_DEFINED
#define _LPURLHISTORYSTG2_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0278_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0278_v0_0_s_ifspec;
#ifndef __IUrlHistoryStg2_INTERFACE_DEFINED__
#define __IUrlHistoryStg2_INTERFACE_DEFINED__
  typedef IUrlHistoryStg2 *LPURLHISTORYSTG2;

  EXTERN_C const IID IID_IUrlHistoryStg2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUrlHistoryStg2 : public IUrlHistoryStg {
  public:
    virtual HRESULT WINAPI AddUrlAndNotify(LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags,WINBOOL fWriteHistory,IOleCommandTarget *poctNotify,IUnknown *punkISFolder) = 0;
    virtual HRESULT WINAPI ClearHistory(void) = 0;
  };
#else
  typedef struct IUrlHistoryStg2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUrlHistoryStg2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUrlHistoryStg2 *This);
      ULONG (WINAPI *Release)(IUrlHistoryStg2 *This);
      HRESULT (WINAPI *AddUrl)(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags);
      HRESULT (WINAPI *DeleteUrl)(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,DWORD dwFlags);
      HRESULT (WINAPI *QueryUrl)(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,DWORD dwFlags,LPSTATURL lpSTATURL);
      HRESULT (WINAPI *BindToObject)(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,REFIID riid,void **ppvOut);
      HRESULT (WINAPI *EnumUrls)(IUrlHistoryStg2 *This,IEnumSTATURL **ppEnum);
      HRESULT (WINAPI *AddUrlAndNotify)(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags,WINBOOL fWriteHistory,IOleCommandTarget *poctNotify,IUnknown *punkISFolder);
      HRESULT (WINAPI *ClearHistory)(IUrlHistoryStg2 *This);
    END_INTERFACE
  } IUrlHistoryStg2Vtbl;
  struct IUrlHistoryStg2 {
    CONST_VTBL struct IUrlHistoryStg2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUrlHistoryStg2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUrlHistoryStg2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUrlHistoryStg2_Release(This) (This)->lpVtbl->Release(This)
#define IUrlHistoryStg2_AddUrl(This,pocsUrl,pocsTitle,dwFlags) (This)->lpVtbl->AddUrl(This,pocsUrl,pocsTitle,dwFlags)
#define IUrlHistoryStg2_DeleteUrl(This,pocsUrl,dwFlags) (This)->lpVtbl->DeleteUrl(This,pocsUrl,dwFlags)
#define IUrlHistoryStg2_QueryUrl(This,pocsUrl,dwFlags,lpSTATURL) (This)->lpVtbl->QueryUrl(This,pocsUrl,dwFlags,lpSTATURL)
#define IUrlHistoryStg2_BindToObject(This,pocsUrl,riid,ppvOut) (This)->lpVtbl->BindToObject(This,pocsUrl,riid,ppvOut)
#define IUrlHistoryStg2_EnumUrls(This,ppEnum) (This)->lpVtbl->EnumUrls(This,ppEnum)
#define IUrlHistoryStg2_AddUrlAndNotify(This,pocsUrl,pocsTitle,dwFlags,fWriteHistory,poctNotify,punkISFolder) (This)->lpVtbl->AddUrlAndNotify(This,pocsUrl,pocsTitle,dwFlags,fWriteHistory,poctNotify,punkISFolder)
#define IUrlHistoryStg2_ClearHistory(This) (This)->lpVtbl->ClearHistory(This)
#endif
#endif
  HRESULT WINAPI IUrlHistoryStg2_AddUrlAndNotify_Proxy(IUrlHistoryStg2 *This,LPCOLESTR pocsUrl,LPCOLESTR pocsTitle,DWORD dwFlags,WINBOOL fWriteHistory,IOleCommandTarget *poctNotify,IUnknown *punkISFolder);
  void __RPC_STUB IUrlHistoryStg2_AddUrlAndNotify_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUrlHistoryStg2_ClearHistory_Proxy(IUrlHistoryStg2 *This);
  void __RPC_STUB IUrlHistoryStg2_ClearHistory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPURLHISTORYNOTIFY_DEFINED
#define _LPURLHISTORYNOTIFY_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0279_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0279_v0_0_s_ifspec;
#ifndef __IUrlHistoryNotify_INTERFACE_DEFINED__
#define __IUrlHistoryNotify_INTERFACE_DEFINED__
  typedef IUrlHistoryNotify *LPURLHISTORYNOTIFY;

  EXTERN_C const IID IID_IUrlHistoryNotify;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUrlHistoryNotify : public IOleCommandTarget {
  };
#else
  typedef struct IUrlHistoryNotifyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUrlHistoryNotify *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUrlHistoryNotify *This);
      ULONG (WINAPI *Release)(IUrlHistoryNotify *This);
      HRESULT (WINAPI *QueryStatus)(IUrlHistoryNotify *This,const GUID *pguidCmdGroup,ULONG cCmds,OLECMD prgCmds[],OLECMDTEXT *pCmdText);
      HRESULT (WINAPI *Exec)(IUrlHistoryNotify *This,const GUID *pguidCmdGroup,DWORD nCmdID,DWORD nCmdexecopt,VARIANT *pvaIn,VARIANT *pvaOut);
    END_INTERFACE
  } IUrlHistoryNotifyVtbl;
  struct IUrlHistoryNotify {
    CONST_VTBL struct IUrlHistoryNotifyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUrlHistoryNotify_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUrlHistoryNotify_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUrlHistoryNotify_Release(This) (This)->lpVtbl->Release(This)
#define IUrlHistoryNotify_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText) (This)->lpVtbl->QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)
#define IUrlHistoryNotify_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut) (This)->lpVtbl->Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)
#endif
#endif
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0280_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_urlhist_0280_v0_0_s_ifspec;

#ifdef __cplusplus
}
#endif
#endif
