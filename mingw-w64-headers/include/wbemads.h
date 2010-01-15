/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
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

#ifndef __wbemads_h__
#define __wbemads_h__

#ifndef __IWMIExtension_FWD_DEFINED__
#define __IWMIExtension_FWD_DEFINED__
typedef struct IWMIExtension IWMIExtension;
#endif

#ifndef __WMIExtension_FWD_DEFINED__
#define __WMIExtension_FWD_DEFINED__

#ifdef __cplusplus
typedef class WMIExtension WMIExtension;
#else
typedef struct WMIExtension WMIExtension;
#endif
#endif

#ifndef __IWMIExtension_FWD_DEFINED__
#define __IWMIExtension_FWD_DEFINED__
typedef struct IWMIExtension IWMIExtension;
#endif

#include "oaidl.h"
#include "ocidl.h"
#include "wbemdisp.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_wbemads_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemads_0000_v0_0_s_ifspec;
#ifndef __WMIEXTENSIONLib_LIBRARY_DEFINED__
#define __WMIEXTENSIONLib_LIBRARY_DEFINED__
  EXTERN_C const IID LIBID_WMIEXTENSIONLib;
#ifndef __IWMIExtension_INTERFACE_DEFINED__
#define __IWMIExtension_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWMIExtension;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWMIExtension : public IDispatch {
  public:
    virtual HRESULT WINAPI get_WMIObjectPath(BSTR *strWMIObjectPath) = 0;
    virtual HRESULT WINAPI GetWMIObject(ISWbemObject **objWMIObject) = 0;
    virtual HRESULT WINAPI GetWMIServices(ISWbemServices **objWMIServices) = 0;
  };
#else
  typedef struct IWMIExtensionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWMIExtension *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWMIExtension *This);
      ULONG (WINAPI *Release)(IWMIExtension *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IWMIExtension *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IWMIExtension *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IWMIExtension *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IWMIExtension *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_WMIObjectPath)(IWMIExtension *This,BSTR *strWMIObjectPath);
      HRESULT (WINAPI *GetWMIObject)(IWMIExtension *This,ISWbemObject **objWMIObject);
      HRESULT (WINAPI *GetWMIServices)(IWMIExtension *This,ISWbemServices **objWMIServices);
    END_INTERFACE
  } IWMIExtensionVtbl;
  struct IWMIExtension {
    CONST_VTBL struct IWMIExtensionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWMIExtension_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWMIExtension_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWMIExtension_Release(This) (This)->lpVtbl->Release(This)
#define IWMIExtension_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWMIExtension_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWMIExtension_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWMIExtension_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWMIExtension_get_WMIObjectPath(This,strWMIObjectPath) (This)->lpVtbl->get_WMIObjectPath(This,strWMIObjectPath)
#define IWMIExtension_GetWMIObject(This,objWMIObject) (This)->lpVtbl->GetWMIObject(This,objWMIObject)
#define IWMIExtension_GetWMIServices(This,objWMIServices) (This)->lpVtbl->GetWMIServices(This,objWMIServices)
#endif
#endif
  HRESULT WINAPI IWMIExtension_get_WMIObjectPath_Proxy(IWMIExtension *This,BSTR *strWMIObjectPath);
  void __RPC_STUB IWMIExtension_get_WMIObjectPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWMIExtension_GetWMIObject_Proxy(IWMIExtension *This,ISWbemObject **objWMIObject);
  void __RPC_STUB IWMIExtension_GetWMIObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWMIExtension_GetWMIServices_Proxy(IWMIExtension *This,ISWbemServices **objWMIServices);
  void __RPC_STUB IWMIExtension_GetWMIServices_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_WMIExtension;
#ifdef __cplusplus
  class WMIExtension;
#endif
#endif

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);

#ifdef __cplusplus
}
#endif
#endif
