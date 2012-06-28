/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDHOST
#define _INC_WSDHOST

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#undef  INTERFACE
#define INTERFACE IWSDServiceMessaging
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDServiceMessaging,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDServiceMessaging methods */
    STDMETHOD_(HRESULT,FaultRequest)(THIS_ WSD_SOAP_HEADER *pRequestHeader,IWSDMessageParameters *pMessageParameters,WSD_SOAP_FAULT *pFault) PURE;
    STDMETHOD_(HRESULT,SendResponse)(THIS_ void *pBody,WSD_OPERATION *pOperation,IWSDMessageParameters *pMessageParameters) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDServiceMessaging_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDServiceMessaging_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDServiceMessaging_Release(This) (This)->lpVtbl->Release(This)
#define IWSDServiceMessaging_FaultRequest(This,pRequestHeader,pMessageParameters,pFault) (This)->lpVtbl->FaultRequest(This,pRequestHeader,pMessageParameters,pFault)
#define IWSDServiceMessaging_SendResponse(This,pBody,pOperation,pMessageParameters) (This)->lpVtbl->SendResponse(This,pBody,pOperation,pMessageParameters)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDDeviceHostNotify
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDDeviceHostNotify,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDDeviceHostNotify methods */
    STDMETHOD_(HRESULT,GetService)(THIS_ LPCWSTR pszServiceId,IUnknown **ppService) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDDeviceHostNotify_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDDeviceHostNotify_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDDeviceHostNotify_Release(This) (This)->lpVtbl->Release(This)
#define IWSDDeviceHostNotify_GetService(This,pszServiceId,ppService) (This)->lpVtbl->GetService(This,pszServiceId,ppService)
#endif /*COBJMACROS*/

#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
#warning IWSDDeviceHost is unverified.
#endif

#undef  INTERFACE
#define INTERFACE IWSDDeviceHost
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDDeviceHost,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDDeviceHost methods */
    STDMETHOD_(HRESULT,Init)(THIS_ LPCWSTR pszLocalId,DWORD dwHostAddressCount) PURE;
    STDMETHOD_(HRESULT,Start)(THIS_ ULONGLONG ullInstanceId,const WSD_URI_LIST *pScopeList,IWSDDeviceHostNotify *pNotificationSink) PURE;
    STDMETHOD_(HRESULT,Stop)(THIS) PURE;
    STDMETHOD_(HRESULT,Terminate)(THIS) PURE;
    STDMETHOD_(HRESULT,RegisterPortType)(THIS_ const WSD_PORT_TYPE *pPortType) PURE;
    STDMETHOD_(HRESULT,SetMetadata)(THIS_ const WSD_THIS_MODEL_METADATA *pThisModelMetadata,const WSD_THIS_DEVICE_METADATA *pThisDeviceMetadata,const WSD_METADATA_SECTION_LIST *pCustomMetadata) PURE;
    STDMETHOD_(HRESULT,RegisterService)(THIS_ LPCWSTR pszServiceId,IUnknown *pService) PURE;
    STDMETHOD_(HRESULT,RetireService)(THIS_ LPCWSTR pszServiceId) PURE;
    STDMETHOD_(HRESULT,AddDynamicService)(THIS_ LPCWSTR pszServiceId,IUnknown *pService) PURE;
    STDMETHOD_(HRESULT,RemoveDynamicService)(THIS_ LPCWSTR pszServiceId) PURE;
    STDMETHOD_(HRESULT,SetServiceDiscoverable)(THIS_ const WCHAR *pszServiceId,WINBOOL fDiscoverable) PURE;
    STDMETHOD_(HRESULT,SignalEvent)(THIS_ LPCWSTR pszServiceId,const void *pBody,const WSD_OPERATION *pOperation) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDDeviceHost_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDDeviceHost_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDDeviceHost_Release(This) (This)->lpVtbl->Release(This)
#define IWSDDeviceHost_Init(This,pszLocalId,dwHostAddressCount) (This)->lpVtbl->Init(This,pszLocalId,dwHostAddressCount)
#define IWSDDeviceHost_Start(This,ullInstanceId,pScopeList,pNotificationSink) (This)->lpVtbl->Start(This,ullInstanceId,pScopeList,pNotificationSink)
#define IWSDDeviceHost_Stop() (This)->lpVtbl->Stop(This)
#define IWSDDeviceHost_Terminate() (This)->lpVtbl->Terminate(This)
#define IWSDDeviceHost_RegisterPortType(This,pPortType) (This)->lpVtbl->RegisterPortType(This,pPortType)
#define IWSDDeviceHost_SetMetadata(This,pThisModelMetadata,pThisDeviceMetadata,pCustomMetadata) (This)->lpVtbl->SetMetadata(This,pThisModelMetadata,pThisDeviceMetadata,pCustomMetadata)
#define IWSDDeviceHost_RegisterService(This,pszServiceId,pService) (This)->lpVtbl->RegisterService(This,pszServiceId,pService)
#define IWSDDeviceHost_RetireService(This,pszServiceId) (This)->lpVtbl->RetireService(This,pszServiceId)
#define IWSDDeviceHost_AddDynamicService(This,pszServiceId,pService) (This)->lpVtbl->AddDynamicService(This,pszServiceId,pService)
#define IWSDDeviceHost_RemoveDynamicService(This,pszServiceId) (This)->lpVtbl->RemoveDynamicService(This,pszServiceId)
#define IWSDDeviceHost_SetServiceDiscoverable(This,pszServiceId,fDiscoverable) (This)->lpVtbl->SetServiceDiscoverable(This,pszServiceId,fDiscoverable)
#define IWSDDeviceHost_SignalEvent(This,pszServiceId,pBody,pOperation) (This)->lpVtbl->SignalEvent(This,pszServiceId,pBody,pOperation)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI WSDCreateDeviceHost(
  const WCHAR *pszLocalId,
  IWSDXMLContext *pContext,
  IWSDDeviceHost **ppDeviceHost
);

HRESULT WSDCreateDeviceHostAdvanced(
  const WCHAR *pszLocalId,
  IWSDXMLContext *pContext,
  IWSDAddress **ppHostAddresses,
  DWORD dwHostAddressCount,
  IWSDDeviceHost **ppDeviceHost
);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDHOST*/
