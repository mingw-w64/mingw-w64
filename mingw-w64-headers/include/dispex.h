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

#ifndef __dispex_h__
#define __dispex_h__

#ifndef __IDispatchEx_FWD_DEFINED__
#define __IDispatchEx_FWD_DEFINED__
typedef struct IDispatchEx IDispatchEx;
#endif

#ifndef __IDispError_FWD_DEFINED__
#define __IDispError_FWD_DEFINED__
typedef struct IDispError IDispError;
#endif

#ifndef __IVariantChangeType_FWD_DEFINED__
#define __IVariantChangeType_FWD_DEFINED__
typedef struct IVariantChangeType IVariantChangeType;
#endif

#ifndef __IObjectIdentity_FWD_DEFINED__
#define __IObjectIdentity_FWD_DEFINED__
typedef struct IObjectIdentity IObjectIdentity;
#endif

#ifndef __IProvideRuntimeContext_FWD_DEFINED__
#define __IProvideRuntimeContext_FWD_DEFINED__
typedef struct IProvideRuntimeContext IProvideRuntimeContext;
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

#ifndef DISPEX_H_
#define DISPEX_H_

#include "servprov.h"

#ifndef _NO_DISPATCHEX_GUIDS
  DEFINE_GUID(IID_IDispatchEx,0xa6ef9860,0xc720,0x11d0,0x93,0x37,0x0,0xa0,0xc9,0xd,0xca,0xa9);
  DEFINE_GUID(IID_IDispError,0xa6ef9861,0xc720,0x11d0,0x93,0x37,0x0,0xa0,0xc9,0xd,0xca,0xa9);
  DEFINE_GUID(IID_IVariantChangeType,0xa6ef9862,0xc720,0x11d0,0x93,0x37,0x0,0xa0,0xc9,0xd,0xca,0xa9);
  DEFINE_GUID(SID_VariantConversion,0x1f101481,0xbccd,0x11d0,0x93,0x36,0x0,0xa0,0xc9,0xd,0xca,0xa9);
  DEFINE_GUID(SID_GetCaller,0x4717cc40,0xbcb9,0x11d0,0x93,0x36,0x0,0xa0,0xc9,0xd,0xca,0xa9);
  DEFINE_GUID(SID_ProvideRuntimeContext,0x74a5040c,0xdd0c,0x48f0,0xac,0x85,0x19,0x4c,0x32,0x59,0x18,0xa);
  DEFINE_GUID(IID_IProvideRuntimeContext,0x10e2414a,0xec59,0x49d2,0xbc,0x51,0x5a,0xdd,0x2c,0x36,0xfe,0xbc);
  DEFINE_GUID(IID_IObjectIdentity,0xca04b7e6,0xd21,0x11d1,0x8c,0xc5,0x0,0xc0,0x4f,0xc2,0xb0,0x85);

#define SID_GetScriptSite IID_IActiveScriptSite
#endif

#ifndef _NO_DISPATCHEX_CONSTS
#define fdexNameCaseSensitive __MSABI_LONG(0x00000001)
#define fdexNameEnsure __MSABI_LONG(0x00000002)
#define fdexNameImplicit __MSABI_LONG(0x00000004)
#define fdexNameCaseInsensitive __MSABI_LONG(0x00000008)
#define fdexNameInternal __MSABI_LONG(0x00000010)
#define fdexNameNoDynamicProperties __MSABI_LONG(0x00000020)

#define fdexPropCanGet __MSABI_LONG(0x00000001)
#define fdexPropCannotGet __MSABI_LONG(0x00000002)
#define fdexPropCanPut __MSABI_LONG(0x00000004)
#define fdexPropCannotPut __MSABI_LONG(0x00000008)
#define fdexPropCanPutRef __MSABI_LONG(0x00000010)
#define fdexPropCannotPutRef __MSABI_LONG(0x00000020)
#define fdexPropNoSideEffects __MSABI_LONG(0x00000040)
#define fdexPropDynamicType __MSABI_LONG(0x00000080)
#define fdexPropCanCall __MSABI_LONG(0x00000100)
#define fdexPropCannotCall __MSABI_LONG(0x00000200)
#define fdexPropCanConstruct __MSABI_LONG(0x00000400)
#define fdexPropCannotConstruct __MSABI_LONG(0x00000800)
#define fdexPropCanSourceEvents __MSABI_LONG(0x00001000)
#define fdexPropCannotSourceEvents __MSABI_LONG(0x00002000)

#define grfdexPropCanAll (fdexPropCanGet | fdexPropCanPut | fdexPropCanPutRef | fdexPropCanCall | fdexPropCanConstruct | fdexPropCanSourceEvents)
#define grfdexPropCannotAll (fdexPropCannotGet | fdexPropCannotPut | fdexPropCannotPutRef | fdexPropCannotCall | fdexPropCannotConstruct | fdexPropCannotSourceEvents)
#define grfdexPropExtraAll (fdexPropNoSideEffects | fdexPropDynamicType)
#define grfdexPropAll (grfdexPropCanAll | grfdexPropCannotAll | grfdexPropExtraAll)

#define fdexEnumDefault __MSABI_LONG(0x00000001)
#define fdexEnumAll __MSABI_LONG(0x00000002)

#define DISPATCH_CONSTRUCT 0x4000

#define DISPID_THIS (-613)
#define DISPID_STARTENUM DISPID_UNKNOWN
#endif

  extern RPC_IF_HANDLE __MIDL_itf_dispex_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_dispex_0000_v0_0_s_ifspec;

#ifndef __IDispatchEx_INTERFACE_DEFINED__
#define __IDispatchEx_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDispatchEx;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDispatchEx : public IDispatch {
  public:
    virtual HRESULT WINAPI GetDispID(BSTR bstrName,DWORD grfdex,DISPID *pid) = 0;
    virtual HRESULT WINAPI InvokeEx(DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller) = 0;
    virtual HRESULT WINAPI DeleteMemberByName(BSTR bstrName,DWORD grfdex) = 0;
    virtual HRESULT WINAPI DeleteMemberByDispID(DISPID id) = 0;
    virtual HRESULT WINAPI GetMemberProperties(DISPID id,DWORD grfdexFetch,DWORD *pgrfdex) = 0;
    virtual HRESULT WINAPI GetMemberName(DISPID id,BSTR *pbstrName) = 0;
    virtual HRESULT WINAPI GetNextDispID(DWORD grfdex,DISPID id,DISPID *pid) = 0;
    virtual HRESULT WINAPI GetNameSpaceParent(IUnknown **ppunk) = 0;
  };
#else
  typedef struct IDispatchExVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDispatchEx *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDispatchEx *This);
      ULONG (WINAPI *Release)(IDispatchEx *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IDispatchEx *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IDispatchEx *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IDispatchEx *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IDispatchEx *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *GetDispID)(IDispatchEx *This,BSTR bstrName,DWORD grfdex,DISPID *pid);
      HRESULT (WINAPI *InvokeEx)(IDispatchEx *This,DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller);
      HRESULT (WINAPI *DeleteMemberByName)(IDispatchEx *This,BSTR bstrName,DWORD grfdex);
      HRESULT (WINAPI *DeleteMemberByDispID)(IDispatchEx *This,DISPID id);
      HRESULT (WINAPI *GetMemberProperties)(IDispatchEx *This,DISPID id,DWORD grfdexFetch,DWORD *pgrfdex);
      HRESULT (WINAPI *GetMemberName)(IDispatchEx *This,DISPID id,BSTR *pbstrName);
      HRESULT (WINAPI *GetNextDispID)(IDispatchEx *This,DWORD grfdex,DISPID id,DISPID *pid);
      HRESULT (WINAPI *GetNameSpaceParent)(IDispatchEx *This,IUnknown **ppunk);
    END_INTERFACE
  } IDispatchExVtbl;
  struct IDispatchEx {
    CONST_VTBL struct IDispatchExVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDispatchEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispatchEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispatchEx_Release(This) (This)->lpVtbl->Release(This)
#define IDispatchEx_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDispatchEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDispatchEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDispatchEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDispatchEx_GetDispID(This,bstrName,grfdex,pid) (This)->lpVtbl->GetDispID(This,bstrName,grfdex,pid)
#define IDispatchEx_InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller) (This)->lpVtbl->InvokeEx(This,id,lcid,wFlags,pdp,pvarRes,pei,pspCaller)
#define IDispatchEx_DeleteMemberByName(This,bstrName,grfdex) (This)->lpVtbl->DeleteMemberByName(This,bstrName,grfdex)
#define IDispatchEx_DeleteMemberByDispID(This,id) (This)->lpVtbl->DeleteMemberByDispID(This,id)
#define IDispatchEx_GetMemberProperties(This,id,grfdexFetch,pgrfdex) (This)->lpVtbl->GetMemberProperties(This,id,grfdexFetch,pgrfdex)
#define IDispatchEx_GetMemberName(This,id,pbstrName) (This)->lpVtbl->GetMemberName(This,id,pbstrName)
#define IDispatchEx_GetNextDispID(This,grfdex,id,pid) (This)->lpVtbl->GetNextDispID(This,grfdex,id,pid)
#define IDispatchEx_GetNameSpaceParent(This,ppunk) (This)->lpVtbl->GetNameSpaceParent(This,ppunk)
#endif
#endif
  HRESULT WINAPI IDispatchEx_GetDispID_Proxy(IDispatchEx *This,BSTR bstrName,DWORD grfdex,DISPID *pid);
  void __RPC_STUB IDispatchEx_GetDispID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_RemoteInvokeEx_Proxy(IDispatchEx *This,DISPID id,LCID lcid,DWORD dwFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller,UINT cvarRefArg,UINT *rgiRefArg,VARIANT *rgvarRefArg);
  void __RPC_STUB IDispatchEx_RemoteInvokeEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_DeleteMemberByName_Proxy(IDispatchEx *This,BSTR bstrName,DWORD grfdex);
  void __RPC_STUB IDispatchEx_DeleteMemberByName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_DeleteMemberByDispID_Proxy(IDispatchEx *This,DISPID id);
  void __RPC_STUB IDispatchEx_DeleteMemberByDispID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_GetMemberProperties_Proxy(IDispatchEx *This,DISPID id,DWORD grfdexFetch,DWORD *pgrfdex);
  void __RPC_STUB IDispatchEx_GetMemberProperties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_GetMemberName_Proxy(IDispatchEx *This,DISPID id,BSTR *pbstrName);
  void __RPC_STUB IDispatchEx_GetMemberName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_GetNextDispID_Proxy(IDispatchEx *This,DWORD grfdex,DISPID id,DISPID *pid);
  void __RPC_STUB IDispatchEx_GetNextDispID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispatchEx_GetNameSpaceParent_Proxy(IDispatchEx *This,IUnknown **ppunk);
  void __RPC_STUB IDispatchEx_GetNameSpaceParent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDispError_INTERFACE_DEFINED__
#define __IDispError_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDispError;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDispError : public IUnknown {
  public:
    virtual HRESULT WINAPI QueryErrorInfo(GUID guidErrorType,IDispError **ppde) = 0;
    virtual HRESULT WINAPI GetNext(IDispError **ppde) = 0;
    virtual HRESULT WINAPI GetHresult(HRESULT *phr) = 0;
    virtual HRESULT WINAPI GetSource(BSTR *pbstrSource) = 0;
    virtual HRESULT WINAPI GetHelpInfo(BSTR *pbstrFileName,DWORD *pdwContext) = 0;
    virtual HRESULT WINAPI GetDescription(BSTR *pbstrDescription) = 0;
  };
#else
  typedef struct IDispErrorVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDispError *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDispError *This);
      ULONG (WINAPI *Release)(IDispError *This);
      HRESULT (WINAPI *QueryErrorInfo)(IDispError *This,GUID guidErrorType,IDispError **ppde);
      HRESULT (WINAPI *GetNext)(IDispError *This,IDispError **ppde);
      HRESULT (WINAPI *GetHresult)(IDispError *This,HRESULT *phr);
      HRESULT (WINAPI *GetSource)(IDispError *This,BSTR *pbstrSource);
      HRESULT (WINAPI *GetHelpInfo)(IDispError *This,BSTR *pbstrFileName,DWORD *pdwContext);
      HRESULT (WINAPI *GetDescription)(IDispError *This,BSTR *pbstrDescription);
    END_INTERFACE
  } IDispErrorVtbl;
  struct IDispError {
    CONST_VTBL struct IDispErrorVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDispError_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDispError_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDispError_Release(This) (This)->lpVtbl->Release(This)
#define IDispError_QueryErrorInfo(This,guidErrorType,ppde) (This)->lpVtbl->QueryErrorInfo(This,guidErrorType,ppde)
#define IDispError_GetNext(This,ppde) (This)->lpVtbl->GetNext(This,ppde)
#define IDispError_GetHresult(This,phr) (This)->lpVtbl->GetHresult(This,phr)
#define IDispError_GetSource(This,pbstrSource) (This)->lpVtbl->GetSource(This,pbstrSource)
#define IDispError_GetHelpInfo(This,pbstrFileName,pdwContext) (This)->lpVtbl->GetHelpInfo(This,pbstrFileName,pdwContext)
#define IDispError_GetDescription(This,pbstrDescription) (This)->lpVtbl->GetDescription(This,pbstrDescription)
#endif
#endif
  HRESULT WINAPI IDispError_QueryErrorInfo_Proxy(IDispError *This,GUID guidErrorType,IDispError **ppde);
  void __RPC_STUB IDispError_QueryErrorInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispError_GetNext_Proxy(IDispError *This,IDispError **ppde);
  void __RPC_STUB IDispError_GetNext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispError_GetHresult_Proxy(IDispError *This,HRESULT *phr);
  void __RPC_STUB IDispError_GetHresult_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispError_GetSource_Proxy(IDispError *This,BSTR *pbstrSource);
  void __RPC_STUB IDispError_GetSource_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispError_GetHelpInfo_Proxy(IDispError *This,BSTR *pbstrFileName,DWORD *pdwContext);
  void __RPC_STUB IDispError_GetHelpInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDispError_GetDescription_Proxy(IDispError *This,BSTR *pbstrDescription);
  void __RPC_STUB IDispError_GetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IVariantChangeType_INTERFACE_DEFINED__
#define __IVariantChangeType_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IVariantChangeType;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IVariantChangeType : public IUnknown {
  public:
    virtual HRESULT WINAPI ChangeType(VARIANT *pvarDst,VARIANT *pvarSrc,LCID lcid,VARTYPE vtNew) = 0;
  };
#else
  typedef struct IVariantChangeTypeVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IVariantChangeType *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IVariantChangeType *This);
      ULONG (WINAPI *Release)(IVariantChangeType *This);
      HRESULT (WINAPI *ChangeType)(IVariantChangeType *This,VARIANT *pvarDst,VARIANT *pvarSrc,LCID lcid,VARTYPE vtNew);
    END_INTERFACE
  } IVariantChangeTypeVtbl;
  struct IVariantChangeType {
    CONST_VTBL struct IVariantChangeTypeVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IVariantChangeType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IVariantChangeType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IVariantChangeType_Release(This) (This)->lpVtbl->Release(This)
#define IVariantChangeType_ChangeType(This,pvarDst,pvarSrc,lcid,vtNew) (This)->lpVtbl->ChangeType(This,pvarDst,pvarSrc,lcid,vtNew)
#endif
#endif
  HRESULT WINAPI IVariantChangeType_ChangeType_Proxy(IVariantChangeType *This,VARIANT *pvarDst,VARIANT *pvarSrc,LCID lcid,VARTYPE vtNew);
  void __RPC_STUB IVariantChangeType_ChangeType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IObjectIdentity_INTERFACE_DEFINED__
#define __IObjectIdentity_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IObjectIdentity;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IObjectIdentity : public IUnknown {
  public:
    virtual HRESULT WINAPI IsEqualObject(IUnknown *punk) = 0;
  };
#else
  typedef struct IObjectIdentityVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IObjectIdentity *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IObjectIdentity *This);
      ULONG (WINAPI *Release)(IObjectIdentity *This);
      HRESULT (WINAPI *IsEqualObject)(IObjectIdentity *This,IUnknown *punk);
    END_INTERFACE
  } IObjectIdentityVtbl;
  struct IObjectIdentity {
    CONST_VTBL struct IObjectIdentityVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IObjectIdentity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IObjectIdentity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IObjectIdentity_Release(This) (This)->lpVtbl->Release(This)
#define IObjectIdentity_IsEqualObject(This,punk) (This)->lpVtbl->IsEqualObject(This,punk)
#endif
#endif
  HRESULT WINAPI IObjectIdentity_IsEqualObject_Proxy(IObjectIdentity *This,IUnknown *punk);
  void __RPC_STUB IObjectIdentity_IsEqualObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IProvideRuntimeContext_INTERFACE_DEFINED__
#define __IProvideRuntimeContext_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IProvideRuntimeContext;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IProvideRuntimeContext : public IUnknown {
  public:
    virtual HRESULT WINAPI GetCurrentSourceContext(DWORD_PTR *pdwContext,VARIANT_BOOL *pfExecutingGlobalCode) = 0;
  };
#else
  typedef struct IProvideRuntimeContextVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IProvideRuntimeContext *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IProvideRuntimeContext *This);
      ULONG (WINAPI *Release)(IProvideRuntimeContext *This);
      HRESULT (WINAPI *GetCurrentSourceContext)(IProvideRuntimeContext *This,DWORD_PTR *pdwContext,VARIANT_BOOL *pfExecutingGlobalCode);
    END_INTERFACE
  } IProvideRuntimeContextVtbl;
  struct IProvideRuntimeContext {
    CONST_VTBL struct IProvideRuntimeContextVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IProvideRuntimeContext_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IProvideRuntimeContext_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IProvideRuntimeContext_Release(This) (This)->lpVtbl->Release(This)
#define IProvideRuntimeContext_GetCurrentSourceContext(This,pdwContext,pfExecutingGlobalCode) (This)->lpVtbl->GetCurrentSourceContext(This,pdwContext,pfExecutingGlobalCode)
#endif
#endif
  HRESULT WINAPI IProvideRuntimeContext_GetCurrentSourceContext_Proxy(IProvideRuntimeContext *This,DWORD_PTR *pdwContext,VARIANT_BOOL *pfExecutingGlobalCode);
  void __RPC_STUB IProvideRuntimeContext_GetCurrentSourceContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_dispex_0268_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_dispex_0268_v0_0_s_ifspec;

  ULONG __RPC_API BSTR_UserSize(ULONG *,ULONG,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(ULONG *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(ULONG *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(ULONG *,BSTR *);
  ULONG __RPC_API VARIANT_UserSize(ULONG *,ULONG,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(ULONG *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(ULONG *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(ULONG *,VARIANT *);

  HRESULT WINAPI IDispatchEx_InvokeEx_Proxy(IDispatchEx *This,DISPID id,LCID lcid,WORD wFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller);
  HRESULT WINAPI IDispatchEx_InvokeEx_Stub(IDispatchEx *This,DISPID id,LCID lcid,DWORD dwFlags,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei,IServiceProvider *pspCaller,UINT cvarRefArg,UINT *rgiRefArg,VARIANT *rgvarRefArg);

#ifdef __cplusplus
}
#endif
#endif
