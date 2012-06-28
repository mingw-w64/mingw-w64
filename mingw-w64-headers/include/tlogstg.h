/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __tlogstg_h__
#define __tlogstg_h__

#ifndef __ITravelLogEntry_FWD_DEFINED__
#define __ITravelLogEntry_FWD_DEFINED__
typedef struct ITravelLogEntry ITravelLogEntry;
#endif

#ifndef __IEnumTravelLogEntry_FWD_DEFINED__
#define __IEnumTravelLogEntry_FWD_DEFINED__
typedef struct IEnumTravelLogEntry IEnumTravelLogEntry;
#endif

#ifndef __ITravelLogStg_FWD_DEFINED__
#define __ITravelLogStg_FWD_DEFINED__
typedef struct ITravelLogStg ITravelLogStg;
#endif

#include "objidl.h"
#include "oleidl.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#define SID_STravelLogCursor IID_ITravelLogStg

  extern RPC_IF_HANDLE __MIDL_itf_tlogstg_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_tlogstg_0000_v0_0_s_ifspec;
#ifndef __ITravelLogEntry_INTERFACE_DEFINED__
#define __ITravelLogEntry_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ITravelLogEntry;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITravelLogEntry : public IUnknown {
  public:
    virtual HRESULT WINAPI GetTitle(LPOLESTR *ppszTitle) = 0;
    virtual HRESULT WINAPI GetURL(LPOLESTR *ppszURL) = 0;
  };
#else
  typedef struct ITravelLogEntryVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITravelLogEntry *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITravelLogEntry *This);
      ULONG (WINAPI *Release)(ITravelLogEntry *This);
      HRESULT (WINAPI *GetTitle)(ITravelLogEntry *This,LPOLESTR *ppszTitle);
      HRESULT (WINAPI *GetURL)(ITravelLogEntry *This,LPOLESTR *ppszURL);
    END_INTERFACE
  } ITravelLogEntryVtbl;
  struct ITravelLogEntry {
    CONST_VTBL struct ITravelLogEntryVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITravelLogEntry_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITravelLogEntry_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITravelLogEntry_Release(This) (This)->lpVtbl->Release(This)
#define ITravelLogEntry_GetTitle(This,ppszTitle) (This)->lpVtbl->GetTitle(This,ppszTitle)
#define ITravelLogEntry_GetURL(This,ppszURL) (This)->lpVtbl->GetURL(This,ppszURL)
#endif
#endif
  HRESULT WINAPI ITravelLogEntry_GetTitle_Proxy(ITravelLogEntry *This,LPOLESTR *ppszTitle);
  void __RPC_STUB ITravelLogEntry_GetTitle_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogEntry_GetURL_Proxy(ITravelLogEntry *This,LPOLESTR *ppszURL);
  void __RPC_STUB ITravelLogEntry_GetURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumTravelLogEntry_INTERFACE_DEFINED__
#define __IEnumTravelLogEntry_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumTravelLogEntry;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumTravelLogEntry : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG cElt,ITravelLogEntry **rgElt,ULONG *pcEltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG cElt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumTravelLogEntry **ppEnum) = 0;
  };
#else
  typedef struct IEnumTravelLogEntryVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumTravelLogEntry *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumTravelLogEntry *This);
      ULONG (WINAPI *Release)(IEnumTravelLogEntry *This);
      HRESULT (WINAPI *Next)(IEnumTravelLogEntry *This,ULONG cElt,ITravelLogEntry **rgElt,ULONG *pcEltFetched);
      HRESULT (WINAPI *Skip)(IEnumTravelLogEntry *This,ULONG cElt);
      HRESULT (WINAPI *Reset)(IEnumTravelLogEntry *This);
      HRESULT (WINAPI *Clone)(IEnumTravelLogEntry *This,IEnumTravelLogEntry **ppEnum);
    END_INTERFACE
  } IEnumTravelLogEntryVtbl;
  struct IEnumTravelLogEntry {
    CONST_VTBL struct IEnumTravelLogEntryVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumTravelLogEntry_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumTravelLogEntry_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumTravelLogEntry_Release(This) (This)->lpVtbl->Release(This)
#define IEnumTravelLogEntry_Next(This,cElt,rgElt,pcEltFetched) (This)->lpVtbl->Next(This,cElt,rgElt,pcEltFetched)
#define IEnumTravelLogEntry_Skip(This,cElt) (This)->lpVtbl->Skip(This,cElt)
#define IEnumTravelLogEntry_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumTravelLogEntry_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif
#endif
  HRESULT WINAPI IEnumTravelLogEntry_Next_Proxy(IEnumTravelLogEntry *This,ULONG cElt,ITravelLogEntry **rgElt,ULONG *pcEltFetched);
  void __RPC_STUB IEnumTravelLogEntry_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumTravelLogEntry_Skip_Proxy(IEnumTravelLogEntry *This,ULONG cElt);
  void __RPC_STUB IEnumTravelLogEntry_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumTravelLogEntry_Reset_Proxy(IEnumTravelLogEntry *This);
  void __RPC_STUB IEnumTravelLogEntry_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumTravelLogEntry_Clone_Proxy(IEnumTravelLogEntry *This,IEnumTravelLogEntry **ppEnum);
  void __RPC_STUB IEnumTravelLogEntry_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ITravelLogStg_INTERFACE_DEFINED__
#define __ITravelLogStg_INTERFACE_DEFINED__
  enum __MIDL_ITravelLogStg_0001 {
    TLEF_RELATIVE_INCLUDE_CURRENT = 0x1,TLEF_RELATIVE_BACK = 0x10,TLEF_RELATIVE_FORE = 0x20,TLEF_INCLUDE_UNINVOKEABLE = 0x40,TLEF_ABSOLUTE = 0x31
  };
  typedef DWORD TLENUMF;

  EXTERN_C const IID IID_ITravelLogStg;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITravelLogStg : public IUnknown {
  public:
    virtual HRESULT WINAPI CreateEntry(LPCOLESTR pszUrl,LPCOLESTR pszTitle,ITravelLogEntry *ptleRelativeTo,WINBOOL fPrepend,ITravelLogEntry **pptle) = 0;
    virtual HRESULT WINAPI TravelTo(ITravelLogEntry *ptle) = 0;
    virtual HRESULT WINAPI EnumEntries(TLENUMF flags,IEnumTravelLogEntry **ppenum) = 0;
    virtual HRESULT WINAPI FindEntries(TLENUMF flags,LPCOLESTR pszUrl,IEnumTravelLogEntry **ppenum) = 0;
    virtual HRESULT WINAPI GetCount(TLENUMF flags,DWORD *pcEntries) = 0;
    virtual HRESULT WINAPI RemoveEntry(ITravelLogEntry *ptle) = 0;
    virtual HRESULT WINAPI GetRelativeEntry(int iOffset,ITravelLogEntry **ptle) = 0;
  };
#else
  typedef struct ITravelLogStgVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITravelLogStg *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITravelLogStg *This);
      ULONG (WINAPI *Release)(ITravelLogStg *This);
      HRESULT (WINAPI *CreateEntry)(ITravelLogStg *This,LPCOLESTR pszUrl,LPCOLESTR pszTitle,ITravelLogEntry *ptleRelativeTo,WINBOOL fPrepend,ITravelLogEntry **pptle);
      HRESULT (WINAPI *TravelTo)(ITravelLogStg *This,ITravelLogEntry *ptle);
      HRESULT (WINAPI *EnumEntries)(ITravelLogStg *This,TLENUMF flags,IEnumTravelLogEntry **ppenum);
      HRESULT (WINAPI *FindEntries)(ITravelLogStg *This,TLENUMF flags,LPCOLESTR pszUrl,IEnumTravelLogEntry **ppenum);
      HRESULT (WINAPI *GetCount)(ITravelLogStg *This,TLENUMF flags,DWORD *pcEntries);
      HRESULT (WINAPI *RemoveEntry)(ITravelLogStg *This,ITravelLogEntry *ptle);
      HRESULT (WINAPI *GetRelativeEntry)(ITravelLogStg *This,int iOffset,ITravelLogEntry **ptle);
    END_INTERFACE
  } ITravelLogStgVtbl;
  struct ITravelLogStg {
    CONST_VTBL struct ITravelLogStgVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITravelLogStg_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITravelLogStg_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITravelLogStg_Release(This) (This)->lpVtbl->Release(This)
#define ITravelLogStg_CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle) (This)->lpVtbl->CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle)
#define ITravelLogStg_TravelTo(This,ptle) (This)->lpVtbl->TravelTo(This,ptle)
#define ITravelLogStg_EnumEntries(This,flags,ppenum) (This)->lpVtbl->EnumEntries(This,flags,ppenum)
#define ITravelLogStg_FindEntries(This,flags,pszUrl,ppenum) (This)->lpVtbl->FindEntries(This,flags,pszUrl,ppenum)
#define ITravelLogStg_GetCount(This,flags,pcEntries) (This)->lpVtbl->GetCount(This,flags,pcEntries)
#define ITravelLogStg_RemoveEntry(This,ptle) (This)->lpVtbl->RemoveEntry(This,ptle)
#define ITravelLogStg_GetRelativeEntry(This,iOffset,ptle) (This)->lpVtbl->GetRelativeEntry(This,iOffset,ptle)
#endif
#endif
  HRESULT WINAPI ITravelLogStg_CreateEntry_Proxy(ITravelLogStg *This,LPCOLESTR pszUrl,LPCOLESTR pszTitle,ITravelLogEntry *ptleRelativeTo,WINBOOL fPrepend,ITravelLogEntry **pptle);
  void __RPC_STUB ITravelLogStg_CreateEntry_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_TravelTo_Proxy(ITravelLogStg *This,ITravelLogEntry *ptle);
  void __RPC_STUB ITravelLogStg_TravelTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_EnumEntries_Proxy(ITravelLogStg *This,TLENUMF flags,IEnumTravelLogEntry **ppenum);
  void __RPC_STUB ITravelLogStg_EnumEntries_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_FindEntries_Proxy(ITravelLogStg *This,TLENUMF flags,LPCOLESTR pszUrl,IEnumTravelLogEntry **ppenum);
  void __RPC_STUB ITravelLogStg_FindEntries_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_GetCount_Proxy(ITravelLogStg *This,TLENUMF flags,DWORD *pcEntries);
  void __RPC_STUB ITravelLogStg_GetCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_RemoveEntry_Proxy(ITravelLogStg *This,ITravelLogEntry *ptle);
  void __RPC_STUB ITravelLogStg_RemoveEntry_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITravelLogStg_GetRelativeEntry_Proxy(ITravelLogStg *This,int iOffset,ITravelLogEntry **ptle);
  void __RPC_STUB ITravelLogStg_GetRelativeEntry_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef __cplusplus
}
#endif
#endif
