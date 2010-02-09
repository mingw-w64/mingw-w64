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

#ifndef __wbemprov_h__
#define __wbemprov_h__

#ifndef __IWbemPropertyProvider_FWD_DEFINED__
#define __IWbemPropertyProvider_FWD_DEFINED__
typedef struct IWbemPropertyProvider IWbemPropertyProvider;
#endif

#ifndef __IWbemUnboundObjectSink_FWD_DEFINED__
#define __IWbemUnboundObjectSink_FWD_DEFINED__
typedef struct IWbemUnboundObjectSink IWbemUnboundObjectSink;
#endif

#ifndef __IWbemEventProvider_FWD_DEFINED__
#define __IWbemEventProvider_FWD_DEFINED__
typedef struct IWbemEventProvider IWbemEventProvider;
#endif

#ifndef __IWbemEventProviderQuerySink_FWD_DEFINED__
#define __IWbemEventProviderQuerySink_FWD_DEFINED__
typedef struct IWbemEventProviderQuerySink IWbemEventProviderQuerySink;
#endif

#ifndef __IWbemEventProviderSecurity_FWD_DEFINED__
#define __IWbemEventProviderSecurity_FWD_DEFINED__
typedef struct IWbemEventProviderSecurity IWbemEventProviderSecurity;
#endif

#ifndef __IWbemEventConsumerProvider_FWD_DEFINED__
#define __IWbemEventConsumerProvider_FWD_DEFINED__
typedef struct IWbemEventConsumerProvider IWbemEventConsumerProvider;
#endif

#ifndef __IWbemProviderInitSink_FWD_DEFINED__
#define __IWbemProviderInitSink_FWD_DEFINED__
typedef struct IWbemProviderInitSink IWbemProviderInitSink;
#endif

#ifndef __IWbemProviderInit_FWD_DEFINED__
#define __IWbemProviderInit_FWD_DEFINED__
typedef struct IWbemProviderInit IWbemProviderInit;
#endif

#ifndef __IWbemHiPerfProvider_FWD_DEFINED__
#define __IWbemHiPerfProvider_FWD_DEFINED__
typedef struct IWbemHiPerfProvider IWbemHiPerfProvider;
#endif

#ifndef __IWbemDecoupledRegistrar_FWD_DEFINED__
#define __IWbemDecoupledRegistrar_FWD_DEFINED__
typedef struct IWbemDecoupledRegistrar IWbemDecoupledRegistrar;
#endif

#ifndef __WbemAdministrativeLocator_FWD_DEFINED__
#define __WbemAdministrativeLocator_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemAdministrativeLocator WbemAdministrativeLocator;
#else
typedef struct WbemAdministrativeLocator WbemAdministrativeLocator;
#endif
#endif

#ifndef __WbemAuthenticatedLocator_FWD_DEFINED__
#define __WbemAuthenticatedLocator_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemAuthenticatedLocator WbemAuthenticatedLocator;
#else
typedef struct WbemAuthenticatedLocator WbemAuthenticatedLocator;
#endif
#endif

#ifndef __WbemUnauthenticatedLocator_FWD_DEFINED__
#define __WbemUnauthenticatedLocator_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemUnauthenticatedLocator WbemUnauthenticatedLocator;
#else
typedef struct WbemUnauthenticatedLocator WbemUnauthenticatedLocator;
#endif
#endif

#ifndef __WbemDecoupledRegistrar_FWD_DEFINED__
#define __WbemDecoupledRegistrar_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemDecoupledRegistrar WbemDecoupledRegistrar;
#else
typedef struct WbemDecoupledRegistrar WbemDecoupledRegistrar;
#endif
#endif

#ifndef __WbemDecoupledBasicEventProvider_FWD_DEFINED__
#define __WbemDecoupledBasicEventProvider_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemDecoupledBasicEventProvider WbemDecoupledBasicEventProvider;
#else
typedef struct WbemDecoupledBasicEventProvider WbemDecoupledBasicEventProvider;
#endif
#endif

#ifndef __IWbemUnboundObjectSink_FWD_DEFINED__
#define __IWbemUnboundObjectSink_FWD_DEFINED__
typedef struct IWbemUnboundObjectSink IWbemUnboundObjectSink;
#endif

#ifndef __IWbemPropertyProvider_FWD_DEFINED__
#define __IWbemPropertyProvider_FWD_DEFINED__
typedef struct IWbemPropertyProvider IWbemPropertyProvider;
#endif

#ifndef __IWbemEventProvider_FWD_DEFINED__
#define __IWbemEventProvider_FWD_DEFINED__
typedef struct IWbemEventProvider IWbemEventProvider;
#endif

#ifndef __IWbemEventProviderQuerySink_FWD_DEFINED__
#define __IWbemEventProviderQuerySink_FWD_DEFINED__
typedef struct IWbemEventProviderQuerySink IWbemEventProviderQuerySink;
#endif

#ifndef __IWbemEventProviderSecurity_FWD_DEFINED__
#define __IWbemEventProviderSecurity_FWD_DEFINED__
typedef struct IWbemEventProviderSecurity IWbemEventProviderSecurity;
#endif

#ifndef __IWbemProviderIdentity_FWD_DEFINED__
#define __IWbemProviderIdentity_FWD_DEFINED__
typedef struct IWbemProviderIdentity IWbemProviderIdentity;
#endif

#ifndef __IWbemEventConsumerProvider_FWD_DEFINED__
#define __IWbemEventConsumerProvider_FWD_DEFINED__
typedef struct IWbemEventConsumerProvider IWbemEventConsumerProvider;
#endif

#ifndef __IWbemProviderInitSink_FWD_DEFINED__
#define __IWbemProviderInitSink_FWD_DEFINED__
typedef struct IWbemProviderInitSink IWbemProviderInitSink;
#endif

#ifndef __IWbemProviderInit_FWD_DEFINED__
#define __IWbemProviderInit_FWD_DEFINED__
typedef struct IWbemProviderInit IWbemProviderInit;
#endif

#ifndef __IWbemHiPerfProvider_FWD_DEFINED__
#define __IWbemHiPerfProvider_FWD_DEFINED__
typedef struct IWbemHiPerfProvider IWbemHiPerfProvider;
#endif

#ifndef __IWbemDecoupledRegistrar_FWD_DEFINED__
#define __IWbemDecoupledRegistrar_FWD_DEFINED__
typedef struct IWbemDecoupledRegistrar IWbemDecoupledRegistrar;
#endif

#ifndef __IWbemDecoupledBasicEventProvider_FWD_DEFINED__
#define __IWbemDecoupledBasicEventProvider_FWD_DEFINED__
typedef struct IWbemDecoupledBasicEventProvider IWbemDecoupledBasicEventProvider;
#endif

#ifndef __IWbemEventSink_FWD_DEFINED__
#define __IWbemEventSink_FWD_DEFINED__
typedef struct IWbemEventSink IWbemEventSink;
#endif

#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "wbemcli.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  typedef VARIANT WBEM_VARIANT;
  typedef WCHAR *WBEM_WSTR;
  typedef const WCHAR *WBEM_CWSTR;

  typedef enum tag_WBEM_PROVIDER_REQUIREMENTS_TYPE {
    WBEM_REQUIREMENTS_START_POSTFILTER = 0,WBEM_REQUIREMENTS_STOP_POSTFILTER = 1,WBEM_REQUIREMENTS_RECHECK_SUBSCRIPTIONS = 2
  } WBEM_PROVIDER_REQUIREMENTS_TYPE;

  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0000_v0_0_s_ifspec;
#ifndef __WbemProviders_v1_LIBRARY_DEFINED__
#define __WbemProviders_v1_LIBRARY_DEFINED__
  EXTERN_C const IID LIBID_WbemProviders_v1;
#ifndef __IWbemPropertyProvider_INTERFACE_DEFINED__
#define __IWbemPropertyProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemPropertyProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemPropertyProvider : public IUnknown {
  public:
    virtual HRESULT WINAPI GetProperty(long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,VARIANT *pvValue) = 0;
    virtual HRESULT WINAPI PutProperty(long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,const VARIANT *pvValue) = 0;
  };
#else
  typedef struct IWbemPropertyProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemPropertyProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemPropertyProvider *This);
      ULONG (WINAPI *Release)(IWbemPropertyProvider *This);
      HRESULT (WINAPI *GetProperty)(IWbemPropertyProvider *This,long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,VARIANT *pvValue);
      HRESULT (WINAPI *PutProperty)(IWbemPropertyProvider *This,long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,const VARIANT *pvValue);
    END_INTERFACE
  } IWbemPropertyProviderVtbl;
  struct IWbemPropertyProvider {
    CONST_VTBL struct IWbemPropertyProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemPropertyProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemPropertyProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemPropertyProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWbemPropertyProvider_GetProperty(This,lFlags,strLocale,strClassMapping,strInstMapping,strPropMapping,pvValue) (This)->lpVtbl->GetProperty(This,lFlags,strLocale,strClassMapping,strInstMapping,strPropMapping,pvValue)
#define IWbemPropertyProvider_PutProperty(This,lFlags,strLocale,strClassMapping,strInstMapping,strPropMapping,pvValue) (This)->lpVtbl->PutProperty(This,lFlags,strLocale,strClassMapping,strInstMapping,strPropMapping,pvValue)
#endif
#endif
  HRESULT WINAPI IWbemPropertyProvider_GetProperty_Proxy(IWbemPropertyProvider *This,long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,VARIANT *pvValue);
  void __RPC_STUB IWbemPropertyProvider_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemPropertyProvider_PutProperty_Proxy(IWbemPropertyProvider *This,long lFlags,const BSTR strLocale,const BSTR strClassMapping,const BSTR strInstMapping,const BSTR strPropMapping,const VARIANT *pvValue);
  void __RPC_STUB IWbemPropertyProvider_PutProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemUnboundObjectSink_INTERFACE_DEFINED__
#define __IWbemUnboundObjectSink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemUnboundObjectSink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemUnboundObjectSink : public IUnknown {
  public:
    virtual HRESULT WINAPI IndicateToConsumer(IWbemClassObject *pLogicalConsumer,long lNumObjects,IWbemClassObject **apObjects) = 0;
  };
#else
  typedef struct IWbemUnboundObjectSinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemUnboundObjectSink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemUnboundObjectSink *This);
      ULONG (WINAPI *Release)(IWbemUnboundObjectSink *This);
      HRESULT (WINAPI *IndicateToConsumer)(IWbemUnboundObjectSink *This,IWbemClassObject *pLogicalConsumer,long lNumObjects,IWbemClassObject **apObjects);
    END_INTERFACE
  } IWbemUnboundObjectSinkVtbl;
  struct IWbemUnboundObjectSink {
    CONST_VTBL struct IWbemUnboundObjectSinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemUnboundObjectSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemUnboundObjectSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemUnboundObjectSink_Release(This) (This)->lpVtbl->Release(This)
#define IWbemUnboundObjectSink_IndicateToConsumer(This,pLogicalConsumer,lNumObjects,apObjects) (This)->lpVtbl->IndicateToConsumer(This,pLogicalConsumer,lNumObjects,apObjects)
#endif
#endif
  HRESULT WINAPI IWbemUnboundObjectSink_IndicateToConsumer_Proxy(IWbemUnboundObjectSink *This,IWbemClassObject *pLogicalConsumer,long lNumObjects,IWbemClassObject **apObjects);
  void __RPC_STUB IWbemUnboundObjectSink_IndicateToConsumer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemEventProvider_INTERFACE_DEFINED__
#define __IWbemEventProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemEventProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemEventProvider : public IUnknown {
  public:
    virtual HRESULT WINAPI ProvideEvents(IWbemObjectSink *pSink,long lFlags) = 0;
  };
#else
  typedef struct IWbemEventProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemEventProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemEventProvider *This);
      ULONG (WINAPI *Release)(IWbemEventProvider *This);
      HRESULT (WINAPI *ProvideEvents)(IWbemEventProvider *This,IWbemObjectSink *pSink,long lFlags);
    END_INTERFACE
  } IWbemEventProviderVtbl;
  struct IWbemEventProvider {
    CONST_VTBL struct IWbemEventProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemEventProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemEventProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemEventProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWbemEventProvider_ProvideEvents(This,pSink,lFlags) (This)->lpVtbl->ProvideEvents(This,pSink,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemEventProvider_ProvideEvents_Proxy(IWbemEventProvider *This,IWbemObjectSink *pSink,long lFlags);
  void __RPC_STUB IWbemEventProvider_ProvideEvents_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemEventProviderQuerySink_INTERFACE_DEFINED__
#define __IWbemEventProviderQuerySink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemEventProviderQuerySink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemEventProviderQuerySink : public IUnknown {
  public:
    virtual HRESULT WINAPI NewQuery(unsigned long dwId,WBEM_WSTR wszQueryLanguage,WBEM_WSTR wszQuery) = 0;
    virtual HRESULT WINAPI CancelQuery(unsigned long dwId) = 0;
  };
#else
  typedef struct IWbemEventProviderQuerySinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemEventProviderQuerySink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemEventProviderQuerySink *This);
      ULONG (WINAPI *Release)(IWbemEventProviderQuerySink *This);
      HRESULT (WINAPI *NewQuery)(IWbemEventProviderQuerySink *This,unsigned long dwId,WBEM_WSTR wszQueryLanguage,WBEM_WSTR wszQuery);
      HRESULT (WINAPI *CancelQuery)(IWbemEventProviderQuerySink *This,unsigned long dwId);
    END_INTERFACE
  } IWbemEventProviderQuerySinkVtbl;
  struct IWbemEventProviderQuerySink {
    CONST_VTBL struct IWbemEventProviderQuerySinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemEventProviderQuerySink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemEventProviderQuerySink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemEventProviderQuerySink_Release(This) (This)->lpVtbl->Release(This)
#define IWbemEventProviderQuerySink_NewQuery(This,dwId,wszQueryLanguage,wszQuery) (This)->lpVtbl->NewQuery(This,dwId,wszQueryLanguage,wszQuery)
#define IWbemEventProviderQuerySink_CancelQuery(This,dwId) (This)->lpVtbl->CancelQuery(This,dwId)
#endif
#endif
  HRESULT WINAPI IWbemEventProviderQuerySink_NewQuery_Proxy(IWbemEventProviderQuerySink *This,unsigned long dwId,WBEM_WSTR wszQueryLanguage,WBEM_WSTR wszQuery);
  void __RPC_STUB IWbemEventProviderQuerySink_NewQuery_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemEventProviderQuerySink_CancelQuery_Proxy(IWbemEventProviderQuerySink *This,unsigned long dwId);
  void __RPC_STUB IWbemEventProviderQuerySink_CancelQuery_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemEventProviderSecurity_INTERFACE_DEFINED__
#define __IWbemEventProviderSecurity_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemEventProviderSecurity;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemEventProviderSecurity : public IUnknown {
  public:
    virtual HRESULT WINAPI AccessCheck(WBEM_CWSTR wszQueryLanguage,WBEM_CWSTR wszQuery,long lSidLength,const BYTE *pSid) = 0;
  };
#else
  typedef struct IWbemEventProviderSecurityVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemEventProviderSecurity *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemEventProviderSecurity *This);
      ULONG (WINAPI *Release)(IWbemEventProviderSecurity *This);
      HRESULT (WINAPI *AccessCheck)(IWbemEventProviderSecurity *This,WBEM_CWSTR wszQueryLanguage,WBEM_CWSTR wszQuery,long lSidLength,const BYTE *pSid);
    END_INTERFACE
  } IWbemEventProviderSecurityVtbl;
  struct IWbemEventProviderSecurity {
    CONST_VTBL struct IWbemEventProviderSecurityVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemEventProviderSecurity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemEventProviderSecurity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemEventProviderSecurity_Release(This) (This)->lpVtbl->Release(This)
#define IWbemEventProviderSecurity_AccessCheck(This,wszQueryLanguage,wszQuery,lSidLength,pSid) (This)->lpVtbl->AccessCheck(This,wszQueryLanguage,wszQuery,lSidLength,pSid)
#endif
#endif
  HRESULT WINAPI IWbemEventProviderSecurity_AccessCheck_Proxy(IWbemEventProviderSecurity *This,WBEM_CWSTR wszQueryLanguage,WBEM_CWSTR wszQuery,long lSidLength,const BYTE *pSid);
  void __RPC_STUB IWbemEventProviderSecurity_AccessCheck_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemEventConsumerProvider_INTERFACE_DEFINED__
#define __IWbemEventConsumerProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemEventConsumerProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemEventConsumerProvider : public IUnknown {
  public:
    virtual HRESULT WINAPI FindConsumer(IWbemClassObject *pLogicalConsumer,IWbemUnboundObjectSink **ppConsumer) = 0;
  };
#else
  typedef struct IWbemEventConsumerProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemEventConsumerProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemEventConsumerProvider *This);
      ULONG (WINAPI *Release)(IWbemEventConsumerProvider *This);
      HRESULT (WINAPI *FindConsumer)(IWbemEventConsumerProvider *This,IWbemClassObject *pLogicalConsumer,IWbemUnboundObjectSink **ppConsumer);
    END_INTERFACE
  } IWbemEventConsumerProviderVtbl;
  struct IWbemEventConsumerProvider {
    CONST_VTBL struct IWbemEventConsumerProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemEventConsumerProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemEventConsumerProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemEventConsumerProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWbemEventConsumerProvider_FindConsumer(This,pLogicalConsumer,ppConsumer) (This)->lpVtbl->FindConsumer(This,pLogicalConsumer,ppConsumer)
#endif
#endif
  HRESULT WINAPI IWbemEventConsumerProvider_FindConsumer_Proxy(IWbemEventConsumerProvider *This,IWbemClassObject *pLogicalConsumer,IWbemUnboundObjectSink **ppConsumer);
  void __RPC_STUB IWbemEventConsumerProvider_FindConsumer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemProviderInitSink_INTERFACE_DEFINED__
#define __IWbemProviderInitSink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemProviderInitSink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemProviderInitSink : public IUnknown {
  public:
    virtual HRESULT WINAPI SetStatus(LONG lStatus,LONG lFlags) = 0;
  };
#else
  typedef struct IWbemProviderInitSinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemProviderInitSink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemProviderInitSink *This);
      ULONG (WINAPI *Release)(IWbemProviderInitSink *This);
      HRESULT (WINAPI *SetStatus)(IWbemProviderInitSink *This,LONG lStatus,LONG lFlags);
    END_INTERFACE
  } IWbemProviderInitSinkVtbl;
  struct IWbemProviderInitSink {
    CONST_VTBL struct IWbemProviderInitSinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemProviderInitSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemProviderInitSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemProviderInitSink_Release(This) (This)->lpVtbl->Release(This)
#define IWbemProviderInitSink_SetStatus(This,lStatus,lFlags) (This)->lpVtbl->SetStatus(This,lStatus,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemProviderInitSink_SetStatus_Proxy(IWbemProviderInitSink *This,LONG lStatus,LONG lFlags);
  void __RPC_STUB IWbemProviderInitSink_SetStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemProviderInit_INTERFACE_DEFINED__
#define __IWbemProviderInit_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemProviderInit;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemProviderInit : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(LPWSTR wszUser,LONG lFlags,LPWSTR wszNamespace,LPWSTR wszLocale,IWbemServices *pNamespace,IWbemContext *pCtx,IWbemProviderInitSink *pInitSink) = 0;
  };
#else
  typedef struct IWbemProviderInitVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemProviderInit *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemProviderInit *This);
      ULONG (WINAPI *Release)(IWbemProviderInit *This);
      HRESULT (WINAPI *Initialize)(IWbemProviderInit *This,LPWSTR wszUser,LONG lFlags,LPWSTR wszNamespace,LPWSTR wszLocale,IWbemServices *pNamespace,IWbemContext *pCtx,IWbemProviderInitSink *pInitSink);
    END_INTERFACE
  } IWbemProviderInitVtbl;
  struct IWbemProviderInit {
    CONST_VTBL struct IWbemProviderInitVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemProviderInit_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemProviderInit_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemProviderInit_Release(This) (This)->lpVtbl->Release(This)
#define IWbemProviderInit_Initialize(This,wszUser,lFlags,wszNamespace,wszLocale,pNamespace,pCtx,pInitSink) (This)->lpVtbl->Initialize(This,wszUser,lFlags,wszNamespace,wszLocale,pNamespace,pCtx,pInitSink)
#endif
#endif
  HRESULT WINAPI IWbemProviderInit_Initialize_Proxy(IWbemProviderInit *This,LPWSTR wszUser,LONG lFlags,LPWSTR wszNamespace,LPWSTR wszLocale,IWbemServices *pNamespace,IWbemContext *pCtx,IWbemProviderInitSink *pInitSink);
  void __RPC_STUB IWbemProviderInit_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemHiPerfProvider_INTERFACE_DEFINED__
#define __IWbemHiPerfProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemHiPerfProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemHiPerfProvider : public IUnknown {
  public:
    virtual HRESULT WINAPI QueryInstances(IWbemServices *pNamespace,WCHAR *wszClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pSink) = 0;
    virtual HRESULT WINAPI CreateRefresher(IWbemServices *pNamespace,long lFlags,IWbemRefresher **ppRefresher) = 0;
    virtual HRESULT WINAPI CreateRefreshableObject(IWbemServices *pNamespace,IWbemObjectAccess *pTemplate,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemObjectAccess **ppRefreshable,long *plId) = 0;
    virtual HRESULT WINAPI StopRefreshing(IWbemRefresher *pRefresher,long lId,long lFlags) = 0;
    virtual HRESULT WINAPI CreateRefreshableEnum(IWbemServices *pNamespace,LPCWSTR wszClass,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum *pHiPerfEnum,long *plId) = 0;
    virtual HRESULT WINAPI GetObjects(IWbemServices *pNamespace,long lNumObjects,IWbemObjectAccess **apObj,long lFlags,IWbemContext *pContext) = 0;
  };
#else
  typedef struct IWbemHiPerfProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemHiPerfProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemHiPerfProvider *This);
      ULONG (WINAPI *Release)(IWbemHiPerfProvider *This);
      HRESULT (WINAPI *QueryInstances)(IWbemHiPerfProvider *This,IWbemServices *pNamespace,WCHAR *wszClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pSink);
      HRESULT (WINAPI *CreateRefresher)(IWbemHiPerfProvider *This,IWbemServices *pNamespace,long lFlags,IWbemRefresher **ppRefresher);
      HRESULT (WINAPI *CreateRefreshableObject)(IWbemHiPerfProvider *This,IWbemServices *pNamespace,IWbemObjectAccess *pTemplate,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemObjectAccess **ppRefreshable,long *plId);
      HRESULT (WINAPI *StopRefreshing)(IWbemHiPerfProvider *This,IWbemRefresher *pRefresher,long lId,long lFlags);
      HRESULT (WINAPI *CreateRefreshableEnum)(IWbemHiPerfProvider *This,IWbemServices *pNamespace,LPCWSTR wszClass,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum *pHiPerfEnum,long *plId);
      HRESULT (WINAPI *GetObjects)(IWbemHiPerfProvider *This,IWbemServices *pNamespace,long lNumObjects,IWbemObjectAccess **apObj,long lFlags,IWbemContext *pContext);
    END_INTERFACE
  } IWbemHiPerfProviderVtbl;
  struct IWbemHiPerfProvider {
    CONST_VTBL struct IWbemHiPerfProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemHiPerfProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemHiPerfProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemHiPerfProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWbemHiPerfProvider_QueryInstances(This,pNamespace,wszClass,lFlags,pCtx,pSink) (This)->lpVtbl->QueryInstances(This,pNamespace,wszClass,lFlags,pCtx,pSink)
#define IWbemHiPerfProvider_CreateRefresher(This,pNamespace,lFlags,ppRefresher) (This)->lpVtbl->CreateRefresher(This,pNamespace,lFlags,ppRefresher)
#define IWbemHiPerfProvider_CreateRefreshableObject(This,pNamespace,pTemplate,pRefresher,lFlags,pContext,ppRefreshable,plId) (This)->lpVtbl->CreateRefreshableObject(This,pNamespace,pTemplate,pRefresher,lFlags,pContext,ppRefreshable,plId)
#define IWbemHiPerfProvider_StopRefreshing(This,pRefresher,lId,lFlags) (This)->lpVtbl->StopRefreshing(This,pRefresher,lId,lFlags)
#define IWbemHiPerfProvider_CreateRefreshableEnum(This,pNamespace,wszClass,pRefresher,lFlags,pContext,pHiPerfEnum,plId) (This)->lpVtbl->CreateRefreshableEnum(This,pNamespace,wszClass,pRefresher,lFlags,pContext,pHiPerfEnum,plId)
#define IWbemHiPerfProvider_GetObjects(This,pNamespace,lNumObjects,apObj,lFlags,pContext) (This)->lpVtbl->GetObjects(This,pNamespace,lNumObjects,apObj,lFlags,pContext)
#endif
#endif
  HRESULT WINAPI IWbemHiPerfProvider_QueryInstances_Proxy(IWbemHiPerfProvider *This,IWbemServices *pNamespace,WCHAR *wszClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pSink);
  void __RPC_STUB IWbemHiPerfProvider_QueryInstances_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfProvider_CreateRefresher_Proxy(IWbemHiPerfProvider *This,IWbemServices *pNamespace,long lFlags,IWbemRefresher **ppRefresher);
  void __RPC_STUB IWbemHiPerfProvider_CreateRefresher_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfProvider_CreateRefreshableObject_Proxy(IWbemHiPerfProvider *This,IWbemServices *pNamespace,IWbemObjectAccess *pTemplate,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemObjectAccess **ppRefreshable,long *plId);
  void __RPC_STUB IWbemHiPerfProvider_CreateRefreshableObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfProvider_StopRefreshing_Proxy(IWbemHiPerfProvider *This,IWbemRefresher *pRefresher,long lId,long lFlags);
  void __RPC_STUB IWbemHiPerfProvider_StopRefreshing_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfProvider_CreateRefreshableEnum_Proxy(IWbemHiPerfProvider *This,IWbemServices *pNamespace,LPCWSTR wszClass,IWbemRefresher *pRefresher,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum *pHiPerfEnum,long *plId);
  void __RPC_STUB IWbemHiPerfProvider_CreateRefreshableEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfProvider_GetObjects_Proxy(IWbemHiPerfProvider *This,IWbemServices *pNamespace,long lNumObjects,IWbemObjectAccess **apObj,long lFlags,IWbemContext *pContext);
  void __RPC_STUB IWbemHiPerfProvider_GetObjects_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemDecoupledRegistrar_INTERFACE_DEFINED__
#define __IWbemDecoupledRegistrar_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemDecoupledRegistrar;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemDecoupledRegistrar : public IUnknown {
  public:
    virtual HRESULT WINAPI Register(long a_Flags,IWbemContext *a_Context,LPCWSTR a_User,LPCWSTR a_Locale,LPCWSTR a_Scope,LPCWSTR a_Registration,IUnknown *a_Unknown) = 0;
    virtual HRESULT WINAPI UnRegister(void) = 0;
  };
#else
  typedef struct IWbemDecoupledRegistrarVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemDecoupledRegistrar *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemDecoupledRegistrar *This);
      ULONG (WINAPI *Release)(IWbemDecoupledRegistrar *This);
      HRESULT (WINAPI *Register)(IWbemDecoupledRegistrar *This,long a_Flags,IWbemContext *a_Context,LPCWSTR a_User,LPCWSTR a_Locale,LPCWSTR a_Scope,LPCWSTR a_Registration,IUnknown *a_Unknown);
      HRESULT (WINAPI *UnRegister)(IWbemDecoupledRegistrar *This);
    END_INTERFACE
  } IWbemDecoupledRegistrarVtbl;
  struct IWbemDecoupledRegistrar {
    CONST_VTBL struct IWbemDecoupledRegistrarVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemDecoupledRegistrar_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemDecoupledRegistrar_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemDecoupledRegistrar_Release(This) (This)->lpVtbl->Release(This)
#define IWbemDecoupledRegistrar_Register(This,a_Flags,a_Context,a_User,a_Locale,a_Scope,a_Registration,a_Unknown) (This)->lpVtbl->Register(This,a_Flags,a_Context,a_User,a_Locale,a_Scope,a_Registration,a_Unknown)
#define IWbemDecoupledRegistrar_UnRegister(This) (This)->lpVtbl->UnRegister(This)
#endif
#endif
  HRESULT WINAPI IWbemDecoupledRegistrar_Register_Proxy(IWbemDecoupledRegistrar *This,long a_Flags,IWbemContext *a_Context,LPCWSTR a_User,LPCWSTR a_Locale,LPCWSTR a_Scope,LPCWSTR a_Registration,IUnknown *a_Unknown);
  void __RPC_STUB IWbemDecoupledRegistrar_Register_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemDecoupledRegistrar_UnRegister_Proxy(IWbemDecoupledRegistrar *This);
  void __RPC_STUB IWbemDecoupledRegistrar_UnRegister_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_WbemAdministrativeLocator;
#ifdef __cplusplus
  class WbemAdministrativeLocator;
#endif
  EXTERN_C const CLSID CLSID_WbemAuthenticatedLocator;
#ifdef __cplusplus
  class WbemAuthenticatedLocator;
#endif
  EXTERN_C const CLSID CLSID_WbemUnauthenticatedLocator;
#ifdef __cplusplus
  class WbemUnauthenticatedLocator;
#endif
  EXTERN_C const CLSID CLSID_WbemDecoupledRegistrar;
#ifdef __cplusplus
  class WbemDecoupledRegistrar;
#endif
  EXTERN_C const CLSID CLSID_WbemDecoupledBasicEventProvider;
#ifdef __cplusplus
  class WbemDecoupledBasicEventProvider;
#endif
#endif

#ifndef __IWbemProviderIdentity_INTERFACE_DEFINED__
#define __IWbemProviderIdentity_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemProviderIdentity;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemProviderIdentity : public IUnknown {
  public:
    virtual HRESULT WINAPI SetRegistrationObject(long lFlags,IWbemClassObject *pProvReg) = 0;
  };
#else
  typedef struct IWbemProviderIdentityVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemProviderIdentity *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemProviderIdentity *This);
      ULONG (WINAPI *Release)(IWbemProviderIdentity *This);
      HRESULT (WINAPI *SetRegistrationObject)(IWbemProviderIdentity *This,long lFlags,IWbemClassObject *pProvReg);
    END_INTERFACE
  } IWbemProviderIdentityVtbl;
  struct IWbemProviderIdentity {
    CONST_VTBL struct IWbemProviderIdentityVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemProviderIdentity_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemProviderIdentity_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemProviderIdentity_Release(This) (This)->lpVtbl->Release(This)
#define IWbemProviderIdentity_SetRegistrationObject(This,lFlags,pProvReg) (This)->lpVtbl->SetRegistrationObject(This,lFlags,pProvReg)
#endif
#endif
  HRESULT WINAPI IWbemProviderIdentity_SetRegistrationObject_Proxy(IWbemProviderIdentity *This,long lFlags,IWbemClassObject *pProvReg);
  void __RPC_STUB IWbemProviderIdentity_SetRegistrationObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum tag_WBEM_EXTRA_RETURN_CODES {
    WBEM_S_INITIALIZED = 0,
    WBEM_S_LIMITED_SERVICE = 0x43001,
    WBEM_S_INDIRECTLY_UPDATED = 0x43002,
    WBEM_S_SUBJECT_TO_SDS = 0x43003,
    WBEM_E_RETRY_LATER = 0x80043001,
    WBEM_E_RESOURCE_CONTENTION = 0x80043002
  } WBEM_EXTRA_RETURN_CODES;

  typedef enum tag_WBEM_PROVIDER_FLAGS {
    WBEM_FLAG_OWNER_UPDATE = 0x10000
  } WBEM_PROVIDER_FLAGS;

  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0169_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0169_v0_0_s_ifspec;
#ifndef __IWbemDecoupledBasicEventProvider_INTERFACE_DEFINED__
#define __IWbemDecoupledBasicEventProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemDecoupledBasicEventProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemDecoupledBasicEventProvider : public IWbemDecoupledRegistrar {
  public:
    virtual HRESULT WINAPI GetSink(long a_Flags,IWbemContext *a_Context,IWbemObjectSink **a_Sink) = 0;
    virtual HRESULT WINAPI GetService(long a_Flags,IWbemContext *a_Context,IWbemServices **a_Service) = 0;
  };
#else
  typedef struct IWbemDecoupledBasicEventProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemDecoupledBasicEventProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemDecoupledBasicEventProvider *This);
      ULONG (WINAPI *Release)(IWbemDecoupledBasicEventProvider *This);
      HRESULT (WINAPI *Register)(IWbemDecoupledBasicEventProvider *This,long a_Flags,IWbemContext *a_Context,LPCWSTR a_User,LPCWSTR a_Locale,LPCWSTR a_Scope,LPCWSTR a_Registration,IUnknown *a_Unknown);
      HRESULT (WINAPI *UnRegister)(IWbemDecoupledBasicEventProvider *This);
      HRESULT (WINAPI *GetSink)(IWbemDecoupledBasicEventProvider *This,long a_Flags,IWbemContext *a_Context,IWbemObjectSink **a_Sink);
      HRESULT (WINAPI *GetService)(IWbemDecoupledBasicEventProvider *This,long a_Flags,IWbemContext *a_Context,IWbemServices **a_Service);
    END_INTERFACE
  } IWbemDecoupledBasicEventProviderVtbl;
  struct IWbemDecoupledBasicEventProvider {
    CONST_VTBL struct IWbemDecoupledBasicEventProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemDecoupledBasicEventProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemDecoupledBasicEventProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemDecoupledBasicEventProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWbemDecoupledBasicEventProvider_Register(This,a_Flags,a_Context,a_User,a_Locale,a_Scope,a_Registration,a_Unknown) (This)->lpVtbl->Register(This,a_Flags,a_Context,a_User,a_Locale,a_Scope,a_Registration,a_Unknown)
#define IWbemDecoupledBasicEventProvider_UnRegister(This) (This)->lpVtbl->UnRegister(This)
#define IWbemDecoupledBasicEventProvider_GetSink(This,a_Flags,a_Context,a_Sink) (This)->lpVtbl->GetSink(This,a_Flags,a_Context,a_Sink)
#define IWbemDecoupledBasicEventProvider_GetService(This,a_Flags,a_Context,a_Service) (This)->lpVtbl->GetService(This,a_Flags,a_Context,a_Service)
#endif
#endif
  HRESULT WINAPI IWbemDecoupledBasicEventProvider_GetSink_Proxy(IWbemDecoupledBasicEventProvider *This,long a_Flags,IWbemContext *a_Context,IWbemObjectSink **a_Sink);
  void __RPC_STUB IWbemDecoupledBasicEventProvider_GetSink_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemDecoupledBasicEventProvider_GetService_Proxy(IWbemDecoupledBasicEventProvider *This,long a_Flags,IWbemContext *a_Context,IWbemServices **a_Service);
  void __RPC_STUB IWbemDecoupledBasicEventProvider_GetService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum tag_WBEM_BATCH_TYPE {
    WBEM_FLAG_BATCH_IF_NEEDED = 0,WBEM_FLAG_MUST_BATCH = 0x1,WBEM_FLAG_MUST_NOT_BATCH = 0x2
  } WBEM_BATCH_TYPE;

  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0174_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemprov_0174_v0_0_s_ifspec;
#ifndef __IWbemEventSink_INTERFACE_DEFINED__
#define __IWbemEventSink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemEventSink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemEventSink : public IWbemObjectSink {
  public:
    virtual HRESULT WINAPI SetSinkSecurity(long lSDLength,BYTE *pSD) = 0;
    virtual HRESULT WINAPI IsActive(void) = 0;
    virtual HRESULT WINAPI GetRestrictedSink(long lNumQueries,const LPCWSTR *awszQueries,IUnknown *pCallback,IWbemEventSink **ppSink) = 0;
    virtual HRESULT WINAPI SetBatchingParameters(LONG lFlags,DWORD dwMaxBufferSize,DWORD dwMaxSendLatency) = 0;
  };
#else
  typedef struct IWbemEventSinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemEventSink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemEventSink *This);
      ULONG (WINAPI *Release)(IWbemEventSink *This);
      HRESULT (WINAPI *Indicate)(IWbemEventSink *This,long lObjectCount,IWbemClassObject **apObjArray);
      HRESULT (WINAPI *SetStatus)(IWbemEventSink *This,long lFlags,HRESULT hResult,BSTR strParam,IWbemClassObject *pObjParam);
      HRESULT (WINAPI *SetSinkSecurity)(IWbemEventSink *This,long lSDLength,BYTE *pSD);
      HRESULT (WINAPI *IsActive)(IWbemEventSink *This);
      HRESULT (WINAPI *GetRestrictedSink)(IWbemEventSink *This,long lNumQueries,const LPCWSTR *awszQueries,IUnknown *pCallback,IWbemEventSink **ppSink);
      HRESULT (WINAPI *SetBatchingParameters)(IWbemEventSink *This,LONG lFlags,DWORD dwMaxBufferSize,DWORD dwMaxSendLatency);
    END_INTERFACE
  } IWbemEventSinkVtbl;
  struct IWbemEventSink {
    CONST_VTBL struct IWbemEventSinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemEventSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemEventSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemEventSink_Release(This) (This)->lpVtbl->Release(This)
#define IWbemEventSink_Indicate(This,lObjectCount,apObjArray) (This)->lpVtbl->Indicate(This,lObjectCount,apObjArray)
#define IWbemEventSink_SetStatus(This,lFlags,hResult,strParam,pObjParam) (This)->lpVtbl->SetStatus(This,lFlags,hResult,strParam,pObjParam)
#define IWbemEventSink_SetSinkSecurity(This,lSDLength,pSD) (This)->lpVtbl->SetSinkSecurity(This,lSDLength,pSD)
#define IWbemEventSink_IsActive(This) (This)->lpVtbl->IsActive(This)
#define IWbemEventSink_GetRestrictedSink(This,lNumQueries,awszQueries,pCallback,ppSink) (This)->lpVtbl->GetRestrictedSink(This,lNumQueries,awszQueries,pCallback,ppSink)
#define IWbemEventSink_SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency) (This)->lpVtbl->SetBatchingParameters(This,lFlags,dwMaxBufferSize,dwMaxSendLatency)
#endif
#endif
  HRESULT WINAPI IWbemEventSink_SetSinkSecurity_Proxy(IWbemEventSink *This,long lSDLength,BYTE *pSD);
  void __RPC_STUB IWbemEventSink_SetSinkSecurity_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemEventSink_IsActive_Proxy(IWbemEventSink *This);
  void __RPC_STUB IWbemEventSink_IsActive_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemEventSink_GetRestrictedSink_Proxy(IWbemEventSink *This,long lNumQueries,const LPCWSTR *awszQueries,IUnknown *pCallback,IWbemEventSink **ppSink);
  void __RPC_STUB IWbemEventSink_GetRestrictedSink_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemEventSink_SetBatchingParameters_Proxy(IWbemEventSink *This,LONG lFlags,DWORD dwMaxBufferSize,DWORD dwMaxSendLatency);
  void __RPC_STUB IWbemEventSink_SetBatchingParameters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);
  unsigned long __RPC_API VARIANT_UserSize(unsigned long *,unsigned long,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(unsigned long *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(unsigned long *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(unsigned long *,VARIANT *);

#ifdef __cplusplus
}
#endif
#endif
