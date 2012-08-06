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

#ifndef __wbemtran_h__
#define __wbemtran_h__

#ifndef __IWbemTransport_FWD_DEFINED__
#define __IWbemTransport_FWD_DEFINED__
typedef struct IWbemTransport IWbemTransport;
#endif

#ifndef __IWbemLevel1Login_FWD_DEFINED__
#define __IWbemLevel1Login_FWD_DEFINED__
typedef struct IWbemLevel1Login IWbemLevel1Login;
#endif

#ifndef __IWbemConnectorLogin_FWD_DEFINED__
#define __IWbemConnectorLogin_FWD_DEFINED__
typedef struct IWbemConnectorLogin IWbemConnectorLogin;
#endif

#ifndef __IWbemAddressResolution_FWD_DEFINED__
#define __IWbemAddressResolution_FWD_DEFINED__
typedef struct IWbemAddressResolution IWbemAddressResolution;
#endif

#ifndef __WbemLevel1Login_FWD_DEFINED__
#define __WbemLevel1Login_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemLevel1Login WbemLevel1Login;
#else
typedef struct WbemLevel1Login WbemLevel1Login;
#endif
#endif

#ifndef __WbemLocalAddrRes_FWD_DEFINED__
#define __WbemLocalAddrRes_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemLocalAddrRes WbemLocalAddrRes;
#else
typedef struct WbemLocalAddrRes WbemLocalAddrRes;
#endif
#endif

#ifndef __WbemUninitializedClassObject_FWD_DEFINED__
#define __WbemUninitializedClassObject_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemUninitializedClassObject WbemUninitializedClassObject;
#else
typedef struct WbemUninitializedClassObject WbemUninitializedClassObject;
#endif
#endif

#ifndef __IWbemClientTransport_FWD_DEFINED__
#define __IWbemClientTransport_FWD_DEFINED__
typedef struct IWbemClientTransport IWbemClientTransport;
#endif

#ifndef __IWbemClientConnectionTransport_FWD_DEFINED__
#define __IWbemClientConnectionTransport_FWD_DEFINED__
typedef struct IWbemClientConnectionTransport IWbemClientConnectionTransport;
#endif

#ifndef __WbemDCOMTransport_FWD_DEFINED__
#define __WbemDCOMTransport_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemDCOMTransport WbemDCOMTransport;
#else
typedef struct WbemDCOMTransport WbemDCOMTransport;
#endif
#endif

#ifndef __IWbemLevel1Login_FWD_DEFINED__
#define __IWbemLevel1Login_FWD_DEFINED__
typedef struct IWbemLevel1Login IWbemLevel1Login;
#endif

#ifndef __IWbemConnectorLogin_FWD_DEFINED__
#define __IWbemConnectorLogin_FWD_DEFINED__
typedef struct IWbemConnectorLogin IWbemConnectorLogin;
#endif

#ifndef __IWbemAddressResolution_FWD_DEFINED__
#define __IWbemAddressResolution_FWD_DEFINED__
typedef struct IWbemAddressResolution IWbemAddressResolution;
#endif

#ifndef __IWbemTransport_FWD_DEFINED__
#define __IWbemTransport_FWD_DEFINED__
typedef struct IWbemTransport IWbemTransport;
#endif

#ifndef __IWbemConstructClassObject_FWD_DEFINED__
#define __IWbemConstructClassObject_FWD_DEFINED__
typedef struct IWbemConstructClassObject IWbemConstructClassObject;
#endif

#ifndef __IWbemClientTransport_FWD_DEFINED__
#define __IWbemClientTransport_FWD_DEFINED__
typedef struct IWbemClientTransport IWbemClientTransport;
#endif

#ifndef __IWbemClientConnectionTransport_FWD_DEFINED__
#define __IWbemClientConnectionTransport_FWD_DEFINED__
typedef struct IWbemClientConnectionTransport IWbemClientConnectionTransport;
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

  extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemtran_0000_v0_0_s_ifspec;

#ifndef __WbemTransports_v1_LIBRARY_DEFINED__
#define __WbemTransports_v1_LIBRARY_DEFINED__
  typedef enum tag_WBEM_LOGIN_TYPE {
    WBEM_FLAG_INPROC_LOGIN = 0,WBEM_FLAG_LOCAL_LOGIN = 1,WBEM_FLAG_REMOTE_LOGIN = 2,WBEM_AUTHENTICATION_METHOD_MASK = 0xf,
    WBEM_FLAG_USE_MULTIPLE_CHALLENGES = 0x10
  } WBEM_LOGIN_TYPE;

  typedef BYTE *WBEM_128BITS;

  EXTERN_C const IID LIBID_WbemTransports_v1;
#ifndef __IWbemTransport_INTERFACE_DEFINED__
#define __IWbemTransport_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemTransport;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemTransport : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(void) = 0;
  };
#else
  typedef struct IWbemTransportVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemTransport *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemTransport *This);
      ULONG (WINAPI *Release)(IWbemTransport *This);
      HRESULT (WINAPI *Initialize)(IWbemTransport *This);
    END_INTERFACE
  } IWbemTransportVtbl;
  struct IWbemTransport {
    CONST_VTBL struct IWbemTransportVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemTransport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemTransport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemTransport_Release(This) (This)->lpVtbl->Release(This)
#define IWbemTransport_Initialize(This) (This)->lpVtbl->Initialize(This)
#endif
#endif
  HRESULT WINAPI IWbemTransport_Initialize_Proxy(IWbemTransport *This);
  void __RPC_STUB IWbemTransport_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemLevel1Login_INTERFACE_DEFINED__
#define __IWbemLevel1Login_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemLevel1Login;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemLevel1Login : public IUnknown {
  public:
    virtual HRESULT WINAPI EstablishPosition(LPWSTR wszClientMachineName,DWORD dwProcessId,DWORD *phAuthEventHandle) = 0;
    virtual HRESULT WINAPI RequestChallenge(LPWSTR wszNetworkResource,LPWSTR wszUser,WBEM_128BITS Nonce) = 0;
    virtual HRESULT WINAPI WBEMLogin(LPWSTR wszPreferredLocale,WBEM_128BITS AccessToken,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace) = 0;
    virtual HRESULT WINAPI NTLMLogin(LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace) = 0;
  };
#else
  typedef struct IWbemLevel1LoginVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemLevel1Login *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemLevel1Login *This);
      ULONG (WINAPI *Release)(IWbemLevel1Login *This);
      HRESULT (WINAPI *EstablishPosition)(IWbemLevel1Login *This,LPWSTR wszClientMachineName,DWORD dwProcessId,DWORD *phAuthEventHandle);
      HRESULT (WINAPI *RequestChallenge)(IWbemLevel1Login *This,LPWSTR wszNetworkResource,LPWSTR wszUser,WBEM_128BITS Nonce);
      HRESULT (WINAPI *WBEMLogin)(IWbemLevel1Login *This,LPWSTR wszPreferredLocale,WBEM_128BITS AccessToken,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace);
      HRESULT (WINAPI *NTLMLogin)(IWbemLevel1Login *This,LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace);
    END_INTERFACE
  } IWbemLevel1LoginVtbl;
  struct IWbemLevel1Login {
    CONST_VTBL struct IWbemLevel1LoginVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemLevel1Login_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemLevel1Login_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemLevel1Login_Release(This) (This)->lpVtbl->Release(This)
#define IWbemLevel1Login_EstablishPosition(This,wszClientMachineName,dwProcessId,phAuthEventHandle) (This)->lpVtbl->EstablishPosition(This,wszClientMachineName,dwProcessId,phAuthEventHandle)
#define IWbemLevel1Login_RequestChallenge(This,wszNetworkResource,wszUser,Nonce) (This)->lpVtbl->RequestChallenge(This,wszNetworkResource,wszUser,Nonce)
#define IWbemLevel1Login_WBEMLogin(This,wszPreferredLocale,AccessToken,lFlags,pCtx,ppNamespace) (This)->lpVtbl->WBEMLogin(This,wszPreferredLocale,AccessToken,lFlags,pCtx,ppNamespace)
#define IWbemLevel1Login_NTLMLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,ppNamespace) (This)->lpVtbl->NTLMLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,ppNamespace)
#endif
#endif
  HRESULT WINAPI IWbemLevel1Login_EstablishPosition_Proxy(IWbemLevel1Login *This,LPWSTR wszClientMachineName,DWORD dwProcessId,DWORD *phAuthEventHandle);
  void __RPC_STUB IWbemLevel1Login_EstablishPosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemLevel1Login_RequestChallenge_Proxy(IWbemLevel1Login *This,LPWSTR wszNetworkResource,LPWSTR wszUser,WBEM_128BITS Nonce);
  void __RPC_STUB IWbemLevel1Login_RequestChallenge_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemLevel1Login_WBEMLogin_Proxy(IWbemLevel1Login *This,LPWSTR wszPreferredLocale,WBEM_128BITS AccessToken,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace);
  void __RPC_STUB IWbemLevel1Login_WBEMLogin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemLevel1Login_NTLMLogin_Proxy(IWbemLevel1Login *This,LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,IWbemServices **ppNamespace);
  void __RPC_STUB IWbemLevel1Login_NTLMLogin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemConnectorLogin_INTERFACE_DEFINED__
#define __IWbemConnectorLogin_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemConnectorLogin;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemConnectorLogin : public IUnknown {
  public:
    virtual HRESULT WINAPI ConnectorLogin(LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface) = 0;
  };
#else
  typedef struct IWbemConnectorLoginVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemConnectorLogin *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemConnectorLogin *This);
      ULONG (WINAPI *Release)(IWbemConnectorLogin *This);
      HRESULT (WINAPI *ConnectorLogin)(IWbemConnectorLogin *This,LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface);
    END_INTERFACE
  } IWbemConnectorLoginVtbl;
  struct IWbemConnectorLogin {
    CONST_VTBL struct IWbemConnectorLoginVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemConnectorLogin_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemConnectorLogin_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemConnectorLogin_Release(This) (This)->lpVtbl->Release(This)
#define IWbemConnectorLogin_ConnectorLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,riid,pInterface) (This)->lpVtbl->ConnectorLogin(This,wszNetworkResource,wszPreferredLocale,lFlags,pCtx,riid,pInterface)
#endif
#endif
  HRESULT WINAPI IWbemConnectorLogin_ConnectorLogin_Proxy(IWbemConnectorLogin *This,LPWSTR wszNetworkResource,LPWSTR wszPreferredLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface);
  void __RPC_STUB IWbemConnectorLogin_ConnectorLogin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemAddressResolution_INTERFACE_DEFINED__
#define __IWbemAddressResolution_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemAddressResolution;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemAddressResolution : public IUnknown {
  public:
    virtual HRESULT WINAPI Resolve(LPWSTR wszNamespacePath,LPWSTR wszAddressType,DWORD *pdwAddressLength,BYTE **pabBinaryAddress) = 0;
  };
#else
  typedef struct IWbemAddressResolutionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemAddressResolution *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemAddressResolution *This);
      ULONG (WINAPI *Release)(IWbemAddressResolution *This);
      HRESULT (WINAPI *Resolve)(IWbemAddressResolution *This,LPWSTR wszNamespacePath,LPWSTR wszAddressType,DWORD *pdwAddressLength,BYTE **pabBinaryAddress);
    END_INTERFACE
  } IWbemAddressResolutionVtbl;
  struct IWbemAddressResolution {
    CONST_VTBL struct IWbemAddressResolutionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemAddressResolution_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemAddressResolution_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemAddressResolution_Release(This) (This)->lpVtbl->Release(This)
#define IWbemAddressResolution_Resolve(This,wszNamespacePath,wszAddressType,pdwAddressLength,pabBinaryAddress) (This)->lpVtbl->Resolve(This,wszNamespacePath,wszAddressType,pdwAddressLength,pabBinaryAddress)
#endif
#endif
  HRESULT WINAPI IWbemAddressResolution_Resolve_Proxy(IWbemAddressResolution *This,LPWSTR wszNamespacePath,LPWSTR wszAddressType,DWORD *pdwAddressLength,BYTE **pabBinaryAddress);
  void __RPC_STUB IWbemAddressResolution_Resolve_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_WbemLevel1Login;
#ifdef __cplusplus
  class WbemLevel1Login;
#endif
  EXTERN_C const CLSID CLSID_WbemLocalAddrRes;
#ifdef __cplusplus
  class WbemLocalAddrRes;
#endif
  EXTERN_C const CLSID CLSID_WbemUninitializedClassObject;
#ifdef __cplusplus
  class WbemUninitializedClassObject;
#endif

#ifndef __IWbemClientTransport_INTERFACE_DEFINED__
#define __IWbemClientTransport_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemClientTransport;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemClientTransport : public IUnknown {
  public:
    virtual HRESULT WINAPI ConnectServer(BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,BSTR strNetworkResource,BSTR strUser,BSTR strPassword,BSTR strLocale,__LONG32 lSecurityFlags,BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace) = 0;
  };
#else
  typedef struct IWbemClientTransportVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemClientTransport *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemClientTransport *This);
      ULONG (WINAPI *Release)(IWbemClientTransport *This);
      HRESULT (WINAPI *ConnectServer)(IWbemClientTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,BSTR strNetworkResource,BSTR strUser,BSTR strPassword,BSTR strLocale,__LONG32 lSecurityFlags,BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace);
    END_INTERFACE
  } IWbemClientTransportVtbl;
  struct IWbemClientTransport {
    CONST_VTBL struct IWbemClientTransportVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemClientTransport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemClientTransport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemClientTransport_Release(This) (This)->lpVtbl->Release(This)
#define IWbemClientTransport_ConnectServer(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace) (This)->lpVtbl->ConnectServer(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace)
#endif
#endif
  HRESULT WINAPI IWbemClientTransport_ConnectServer_Proxy(IWbemClientTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,BSTR strNetworkResource,BSTR strUser,BSTR strPassword,BSTR strLocale,__LONG32 lSecurityFlags,BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace);
  void __RPC_STUB IWbemClientTransport_ConnectServer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemClientConnectionTransport_INTERFACE_DEFINED__
#define __IWbemClientConnectionTransport_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemClientConnectionTransport;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemClientConnectionTransport : public IUnknown {
  public:
    virtual HRESULT WINAPI Open(BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface,IWbemCallResult **pCallRes) = 0;
    virtual HRESULT WINAPI OpenAsync(BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI Cancel(__LONG32 lFlags,IWbemObjectSink *pHandler) = 0;
  };
#else
  typedef struct IWbemClientConnectionTransportVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemClientConnectionTransport *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemClientConnectionTransport *This);
      ULONG (WINAPI *Release)(IWbemClientConnectionTransport *This);
      HRESULT (WINAPI *Open)(IWbemClientConnectionTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface,IWbemCallResult **pCallRes);
      HRESULT (WINAPI *OpenAsync)(IWbemClientConnectionTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *Cancel)(IWbemClientConnectionTransport *This,__LONG32 lFlags,IWbemObjectSink *pHandler);
    END_INTERFACE
  } IWbemClientConnectionTransportVtbl;
  struct IWbemClientConnectionTransport {
    CONST_VTBL struct IWbemClientConnectionTransportVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemClientConnectionTransport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemClientConnectionTransport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemClientConnectionTransport_Release(This) (This)->lpVtbl->Release(This)
#define IWbemClientConnectionTransport_Open(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pInterface,pCallRes) (This)->lpVtbl->Open(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pInterface,pCallRes)
#define IWbemClientConnectionTransport_OpenAsync(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pResponseHandler) (This)->lpVtbl->OpenAsync(This,strAddressType,dwBinaryAddressLength,abBinaryAddress,strObject,strUser,strPassword,strLocale,lFlags,pCtx,riid,pResponseHandler)
#define IWbemClientConnectionTransport_Cancel(This,lFlags,pHandler) (This)->lpVtbl->Cancel(This,lFlags,pHandler)
#endif
#endif
  HRESULT WINAPI IWbemClientConnectionTransport_Open_Proxy(IWbemClientConnectionTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,void **pInterface,IWbemCallResult **pCallRes);
  void __RPC_STUB IWbemClientConnectionTransport_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClientConnectionTransport_OpenAsync_Proxy(IWbemClientConnectionTransport *This,BSTR strAddressType,DWORD dwBinaryAddressLength,BYTE *abBinaryAddress,const BSTR strObject,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,__LONG32 lFlags,IWbemContext *pCtx,REFIID riid,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemClientConnectionTransport_OpenAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClientConnectionTransport_Cancel_Proxy(IWbemClientConnectionTransport *This,__LONG32 lFlags,IWbemObjectSink *pHandler);
  void __RPC_STUB IWbemClientConnectionTransport_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_WbemDCOMTransport;
#ifdef __cplusplus
  class WbemDCOMTransport;
#endif
#endif

#ifndef __IWbemConstructClassObject_INTERFACE_DEFINED__
#define __IWbemConstructClassObject_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemConstructClassObject;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemConstructClassObject : public IUnknown {
  public:
    virtual HRESULT WINAPI SetInheritanceChain(__LONG32 lNumAntecedents,LPWSTR *awszAntecedents) = 0;
    virtual HRESULT WINAPI SetPropertyOrigin(LPCWSTR wszPropertyName,__LONG32 lOriginIndex) = 0;
    virtual HRESULT WINAPI SetMethodOrigin(LPCWSTR wszMethodName,__LONG32 lOriginIndex) = 0;
    virtual HRESULT WINAPI SetServerNamespace(LPCWSTR wszServer,LPCWSTR wszNamespace) = 0;
  };
#else
  typedef struct IWbemConstructClassObjectVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemConstructClassObject *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemConstructClassObject *This);
      ULONG (WINAPI *Release)(IWbemConstructClassObject *This);
      HRESULT (WINAPI *SetInheritanceChain)(IWbemConstructClassObject *This,__LONG32 lNumAntecedents,LPWSTR *awszAntecedents);
      HRESULT (WINAPI *SetPropertyOrigin)(IWbemConstructClassObject *This,LPCWSTR wszPropertyName,__LONG32 lOriginIndex);
      HRESULT (WINAPI *SetMethodOrigin)(IWbemConstructClassObject *This,LPCWSTR wszMethodName,__LONG32 lOriginIndex);
      HRESULT (WINAPI *SetServerNamespace)(IWbemConstructClassObject *This,LPCWSTR wszServer,LPCWSTR wszNamespace);
    END_INTERFACE
  } IWbemConstructClassObjectVtbl;
  struct IWbemConstructClassObject {
    CONST_VTBL struct IWbemConstructClassObjectVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemConstructClassObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemConstructClassObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemConstructClassObject_Release(This) (This)->lpVtbl->Release(This)
#define IWbemConstructClassObject_SetInheritanceChain(This,lNumAntecedents,awszAntecedents) (This)->lpVtbl->SetInheritanceChain(This,lNumAntecedents,awszAntecedents)
#define IWbemConstructClassObject_SetPropertyOrigin(This,wszPropertyName,lOriginIndex) (This)->lpVtbl->SetPropertyOrigin(This,wszPropertyName,lOriginIndex)
#define IWbemConstructClassObject_SetMethodOrigin(This,wszMethodName,lOriginIndex) (This)->lpVtbl->SetMethodOrigin(This,wszMethodName,lOriginIndex)
#define IWbemConstructClassObject_SetServerNamespace(This,wszServer,wszNamespace) (This)->lpVtbl->SetServerNamespace(This,wszServer,wszNamespace)
#endif
#endif
  HRESULT WINAPI IWbemConstructClassObject_SetInheritanceChain_Proxy(IWbemConstructClassObject *This,__LONG32 lNumAntecedents,LPWSTR *awszAntecedents);
  void __RPC_STUB IWbemConstructClassObject_SetInheritanceChain_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConstructClassObject_SetPropertyOrigin_Proxy(IWbemConstructClassObject *This,LPCWSTR wszPropertyName,__LONG32 lOriginIndex);
  void __RPC_STUB IWbemConstructClassObject_SetPropertyOrigin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConstructClassObject_SetMethodOrigin_Proxy(IWbemConstructClassObject *This,LPCWSTR wszMethodName,__LONG32 lOriginIndex);
  void __RPC_STUB IWbemConstructClassObject_SetMethodOrigin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConstructClassObject_SetServerNamespace_Proxy(IWbemConstructClassObject *This,LPCWSTR wszServer,LPCWSTR wszNamespace);
  void __RPC_STUB IWbemConstructClassObject_SetServerNamespace_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef __cplusplus
}
#endif
#endif
