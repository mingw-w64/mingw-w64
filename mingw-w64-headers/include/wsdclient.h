/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDCLIENT
#define _INC_WSDCLIENT

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#undef  INTERFACE
#define INTERFACE IWSDEventingStatus
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDEventingStatus,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDEventingStatus methods */
    STDMETHOD(SubscriptionRenewed)(THIS_ LPCWSTR pszSubscriptionAction) PURE;
    STDMETHOD(SubscriptionRenewalFailed)(THIS_ LPCWSTR pszSubscriptionAction,HRESULT hr) PURE;
    STDMETHOD(SubscriptionEnded)(THIS_ LPCWSTR pszSubscriptionAction) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDEventingStatus_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDEventingStatus_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDEventingStatus_Release(This) (This)->lpVtbl->Release(This)
#define IWSDEventingStatus_SubscriptionRenewed(This,pszSubscriptionAction) (This)->lpVtbl->SubscriptionRenewed(This,pszSubscriptionAction)
#define IWSDEventingStatus_SubscriptionRenewalFailed(This,pszSubscriptionAction,hr) (This)->lpVtbl->SubscriptionRenewalFailed(This,pszSubscriptionAction,hr)
#define IWSDEventingStatus_SubscriptionEnded(This,pszSubscriptionAction) (This)->lpVtbl->SubscriptionEnded(This,pszSubscriptionAction)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDAsyncCallback
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDAsyncCallback,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDAsyncCallback methods */
    STDMETHOD_(HRESULT,AsyncOperationComplete)(THIS_ IWSDAsyncResult *pAsyncResult,IUnknown *pAsyncState) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDAsyncCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDAsyncCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDAsyncCallback_Release(This) (This)->lpVtbl->Release(This)
#define IWSDAsyncCallback_AsyncOperationComplete(This,pAsyncResult,pAsyncState) (This)->lpVtbl->AsyncOperationComplete(This,pAsyncResult,pAsyncState)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDAsyncResult
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDAsyncResult,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDAsyncResult methods */
    STDMETHOD_(HRESULT,SetCallback)(THIS_ IWSDAsyncCallback *pCallback,IUnknown *pAsyncState) PURE;
    STDMETHOD_(HRESULT,SetWaitHandle)(THIS_ HANDLE hWaitHandle) PURE;
    STDMETHOD_(HRESULT,HasCompleted)(THIS) PURE;
    STDMETHOD_(HRESULT,GetAsyncState)(THIS_ IUnknown **ppAsyncState) PURE;
    STDMETHOD_(HRESULT,Abort)(THIS) PURE;
    STDMETHOD_(HRESULT,GetEvent)(THIS_ WSD_EVENT *pEvent) PURE;
    STDMETHOD_(HRESULT,GetEndpointProxy)(THIS_ IWSDEndpointProxy **ppEndpoint) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDAsyncResult_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDAsyncResult_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDAsyncResult_Release(This) (This)->lpVtbl->Release(This)
#define IWSDAsyncResult_SetCallback(This,pCallback,pAsyncState) (This)->lpVtbl->SetCallback(This,pCallback,pAsyncState)
#define IWSDAsyncResult_SetWaitHandle(This,hWaitHandle) (This)->lpVtbl->SetWaitHandle(This,hWaitHandle)
#define IWSDAsyncResult_HasCompleted() (This)->lpVtbl->HasCompleted(This)
#define IWSDAsyncResult_GetAsyncState(This,ppAsyncState) (This)->lpVtbl->GetAsyncState(This,ppAsyncState)
#define IWSDAsyncResult_Abort() (This)->lpVtbl->Abort(This)
#define IWSDAsyncResult_GetEvent(This,pEvent) (This)->lpVtbl->GetEvent(This,pEvent)
#define IWSDAsyncResult_GetEndpointProxy(This,ppEndpoint) (This)->lpVtbl->GetEndpointProxy(This,ppEndpoint)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDDeviceProxy
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDDeviceProxy,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDDeviceProxy methods */
    STDMETHOD_(HRESULT,Init)(THIS_ LPCWSTR pszDeviceId,IWSDAddress *pDeviceAddress,LPCWSTR pszLocalId,IWSDDeviceProxy *pSponsor) PURE;
    STDMETHOD_(HRESULT,BeginGetMetadata)(THIS_ IWSDAsyncResult **ppResult) PURE;
    STDMETHOD_(HRESULT,EndGetMetadata)(THIS_ IWSDAsyncResult *pResult) PURE;
    STDMETHOD_(HRESULT,GetHostMetadata)(THIS_ WSD_HOST_METADATA **ppHostMetadata) PURE;
    STDMETHOD_(HRESULT,GetThisModelMetadata)(THIS_ WSD_THIS_MODEL_METADATA **ppManufacturerMetadata) PURE;
    STDMETHOD_(HRESULT,GetThisDeviceMetadata)(THIS_ WSD_THIS_DEVICE_METADATA **ppThisDeviceMetadata) PURE;
    STDMETHOD_(HRESULT,GetAllMetadata)(THIS_ WSD_METADATA_SECTION_LIST **ppMetadata) PURE;
    STDMETHOD_(HRESULT,GetServiceProxyById)(THIS_ LPCWSTR pszServiceId,IWSDServiceProxy **ppServiceProxy) PURE;
    STDMETHOD_(HRESULT,GetServiceProxyByType)(THIS_ const WSDXML_NAME *pType,IWSDServiceProxy **ppServiceProxy) PURE;
    STDMETHOD_(HRESULT,GetEndpointProxy)(THIS_ IWSDEndpointProxy **ppProxy) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDDeviceProxy_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDDeviceProxy_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDDeviceProxy_Release(This) (This)->lpVtbl->Release(This)
#define IWSDDeviceProxy_Init(This,pszDeviceId,pDeviceAddress,pszLocalId,pSponsor) (This)->lpVtbl->Init(This,pszDeviceId,pDeviceAddress,pszLocalId,pSponsor)
#define IWSDDeviceProxy_BeginGetMetadata(This,ppResult) (This)->lpVtbl->BeginGetMetadata(This,ppResult)
#define IWSDDeviceProxy_EndGetMetadata(This,pResult) (This)->lpVtbl->EndGetMetadata(This,pResult)
#define IWSDDeviceProxy_GetHostMetadata(This,ppHostMetadata) (This)->lpVtbl->GetHostMetadata(This,ppHostMetadata)
#define IWSDDeviceProxy_GetThisModelMetadata(This,ppManufacturerMetadata) (This)->lpVtbl->GetThisModelMetadata(This,ppManufacturerMetadata)
#define IWSDDeviceProxy_GetThisDeviceMetadata(This,ppThisDeviceMetadata) (This)->lpVtbl->GetThisDeviceMetadata(This,ppThisDeviceMetadata)
#define IWSDDeviceProxy_GetAllMetadata(This,ppMetadata) (This)->lpVtbl->GetAllMetadata(This,ppMetadata)
#define IWSDDeviceProxy_GetServiceProxyById(This,pszServiceId,ppServiceProxy) (This)->lpVtbl->GetServiceProxyById(This,pszServiceId,ppServiceProxy)
#define IWSDDeviceProxy_GetServiceProxyByType(This,pType,ppServiceProxy) (This)->lpVtbl->GetServiceProxyByType(This,pType,ppServiceProxy)
#define IWSDDeviceProxy_GetEndpointProxy(This,ppProxy) (This)->lpVtbl->GetEndpointProxy(This,ppProxy)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDMetadataExchange
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDMetadataExchange,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDMetadataExchange methods */
    STDMETHOD_(HRESULT,GetMetadata)(THIS_ WSD_METADATA_SECTION_LIST **MetadataOut) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDMetadataExchange_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDMetadataExchange_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDMetadataExchange_Release(This) (This)->lpVtbl->Release(This)
#define IWSDMetadataExchange_GetMetadata(This,MetadataOut) (This)->lpVtbl->GetMetadata(This,MetadataOut)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDServiceProxy
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDServiceProxy,IWSDMetadataExchange)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDMetadataExchange methods */
    STDMETHOD_(HRESULT,GetMetadata)(THIS_ WSD_METADATA_SECTION_LIST **MetadataOut) PURE;

    /* IWSDServiceProxy methods */
    STDMETHOD_(HRESULT,BeginGetMetadata)(THIS_ IWSDAsyncResult **ppResult) PURE;
    STDMETHOD_(HRESULT,EndGetMetadata)(THIS_ IWSDAsyncResult *pResult,WSD_METADATA_SECTION_LIST **ppMetadata) PURE;
    STDMETHOD_(HRESULT,GetServiceMetadata)(THIS_ WSD_SERVICE_METADATA **ppServiceMetadata) PURE;
    STDMETHOD_(HRESULT,SubscribeToOperation)(THIS_ const WSD_OPERATION *pOperation,IUnknown *pUnknown,const WSDXML_ELEMENT *pAny,WSDXML_ELEMENT **ppAny) PURE;
    STDMETHOD_(HRESULT,UnsubscribeToOperation)(THIS_ const WSD_OPERATION *pOperation) PURE;
    STDMETHOD_(HRESULT,SetEventingStatusCallback)(THIS_ IWSDEventingStatus *pStatus) PURE;
    STDMETHOD_(HRESULT,GetEndpointProxy)(THIS_ IWSDEndpointProxy **ppProxy) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDServiceProxy_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDServiceProxy_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDServiceProxy_Release(This) (This)->lpVtbl->Release(This)
#define IWSDServiceProxy_BeginGetMetadata(This,ppResult) (This)->lpVtbl->BeginGetMetadata(This,ppResult)
#define IWSDServiceProxy_EndGetMetadata(This,pResult,ppMetadata) (This)->lpVtbl->EndGetMetadata(This,pResult,ppMetadata)
#define IWSDServiceProxy_GetServiceMetadata(This,ppServiceMetadata) (This)->lpVtbl->GetServiceMetadata(This,ppServiceMetadata)
#define IWSDServiceProxy_SubscribeToOperation(This,pOperation,pUnknown,pAny,ppAny) (This)->lpVtbl->SubscribeToOperation(This,pOperation,pUnknown,pAny,ppAny)
#define IWSDServiceProxy_UnsubscribeToOperation(This,pOperation) (This)->lpVtbl->UnsubscribeToOperation(This,pOperation)
#define IWSDServiceProxy_SetEventingStatusCallback(This,pStatus) (This)->lpVtbl->SetEventingStatusCallback(This,pStatus)
#define IWSDServiceProxy_GetEndpointProxy(This,ppProxy) (This)->lpVtbl->GetEndpointProxy(This,ppProxy)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDEndpointProxy
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDEndpointProxy,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDEndpointProxy methods */
    STDMETHOD_(HRESULT,SendOneWayRequest)(THIS_ const void *pBody,const WSD_OPERATION *pOperation) PURE;
    STDMETHOD_(HRESULT,SendTwoWayRequest)(THIS_ const void *pBody,const WSD_OPERATION *pOperation,WSD_SYNCHRONOUS_RESPONSE_CONTEXT *pResponseContext) PURE;
    STDMETHOD_(HRESULT,SendTwoWayRequestAsync)(THIS_ const void *pBody,const WSD_OPERATION *pOperation,IUnknown *pAsyncState,IWSDAsyncCallback *pCallback,IWSDAsyncResult **pResult) PURE;
    STDMETHOD_(HRESULT,AbortAsyncOperation)(THIS_ IWSDAsyncResult *pAsyncResult) PURE;
    STDMETHOD_(HRESULT,ProcessFault)(THIS_ const WSD_SOAP_FAULT *pFault) PURE;
    STDMETHOD_(HRESULT,GetErrorInfo)(THIS_ const LPCWSTR *ppszErrorInfo) PURE;
    STDMETHOD_(HRESULT,GetFaultInfo)(THIS_ WSD_SOAP_FAULT **ppFault) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDEndpointProxy_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDEndpointProxy_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDEndpointProxy_Release(This) (This)->lpVtbl->Release(This)
#define IWSDEndpointProxy_SendOneWayRequest(This,pBody,pOperation) (This)->lpVtbl->SendOneWayRequest(This,pBody,pOperation)
#define IWSDEndpointProxy_SendTwoWayRequest(This,pBody,pOperation,pResponseContext) (This)->lpVtbl->SendTwoWayRequest(This,pBody,pOperation,pResponseContext)
#define IWSDEndpointProxy_SendTwoWayRequestAsync(This,pBody,pOperation,pAsyncState,pCallback,pResult) (This)->lpVtbl->SendTwoWayRequestAsync(This,pBody,pOperation,pAsyncState,pCallback,pResult)
#define IWSDEndpointProxy_AbortAsyncOperation(This,pAsyncResult) (This)->lpVtbl->AbortAsyncOperation(This,pAsyncResult)
#define IWSDEndpointProxy_ProcessFault(This,pFault) (This)->lpVtbl->ProcessFault(This,pFault)
#define IWSDEndpointProxy_GetErrorInfo(This,ppszErrorInfo) (This)->lpVtbl->GetErrorInfo(This,ppszErrorInfo)
#define IWSDEndpointProxy_GetFaultInfo(This,ppFault) (This)->lpVtbl->GetFaultInfo(This,ppFault)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI WSDCreateDeviceProxy(
  const WCHAR *pszDeviceId,
  const WCHAR *pszLocalId,
  IWSDXMLContext *pContext,
  IWSDDeviceProxy **ppDeviceProxy
);

HRESULT WINAPI WSDCreateDeviceProxyAdvanced(
  const WCHAR *pszDeviceId,
  IWSDAddress *pDeviceAddress,
  const WCHAR *pszLocalId,
  IWSDXMLContext *pContext,
  IWSDDeviceProxy **ppDeviceProxy
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDCLIENT*/
