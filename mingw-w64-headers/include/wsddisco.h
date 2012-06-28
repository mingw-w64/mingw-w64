/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDDISCO
#define _INC_WSDDISCO

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#undef  INTERFACE
#define INTERFACE IWSDScopeMatchingRule
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDScopeMatchingRule,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDScopeMatchingRule methods */
    STDMETHOD_(HRESULT,GetScopeRule)(THIS_ LPCWSTR *ppszScopeMatchingRule) PURE;
    STDMETHOD_(HRESULT,MatchScopes)(THIS_ LPCWSTR pszScope1,LPCWSTR pszScope2,BOOL *pfMatch) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDScopeMatchingRule_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDScopeMatchingRule_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDScopeMatchingRule_Release(This) (This)->lpVtbl->Release(This)
#define IWSDScopeMatchingRule_GetScopeRule(This,ppszScopeMatchingRule) (This)->lpVtbl->GetScopeRule(This,ppszScopeMatchingRule)
#define IWSDScopeMatchingRule_MatchScopes(This,pszScope1,pszScope2,pfMatch) (This)->lpVtbl->MatchScopes(This,pszScope1,pszScope2,pfMatch)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDiscoveryPublisherNotify
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDiscoveryPublisherNotify,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDiscoveryPublisherNotify methods */
    STDMETHOD_(HRESULT,ProbeHandler)(THIS_ const WSD_SOAP_MESSAGE *pSoap,IWSDMessageParameters *pMessageParameters) PURE;
    STDMETHOD_(HRESULT,ResolveHandler)(THIS_ const WSD_SOAP_MESSAGE *pSoap,IWSDMessageParameters *pMessageParameters) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDiscoveryPublisherNotify_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDiscoveryPublisherNotify_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDiscoveryPublisherNotify_Release(This) (This)->lpVtbl->Release(This)
#define IWSDiscoveryPublisherNotify_ProbeHandler(This,pSoap,pMessageParameters) (This)->lpVtbl->ProbeHandler(This,pSoap,pMessageParameters)
#define IWSDiscoveryPublisherNotify_ResolveHandler(This,pSoap,pMessageParameters) (This)->lpVtbl->ResolveHandler(This,pSoap,pMessageParameters)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDiscoveredService
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDiscoveredService,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDiscoveryProviderNotify methods */
    STDMETHOD_(HRESULT *,GetEndpointReference)(THIS_ WSD_ENDPOINT_REFERENCE **ppEndPointReference) PURE;
    STDMETHOD_(HRESULT,GetTypes)(THIS_ WSD_NAME_LIST **ppTypesList) PURE;
    STDMETHOD_(HRESULT,GetScopes)(THIS_ WSD_URI_LIST **ppScopesList) PURE;
    STDMETHOD_(HRESULT,GetXAddrs)(THIS_ WSD_URI_LIST **ppXAddrsList) PURE;
    STDMETHOD_(HRESULT,GetMetadataVersion)(THIS_ ULONGLONG *pullMetadataVersion) PURE;
    STDMETHOD_(HRESULT,GetExtendedDiscoXML)(THIS_ WSDXML_ELEMENT **ppHeaderAny,WSDXML_ELEMENT **ppBodyAny) PURE;
    STDMETHOD_(HRESULT,GetProbeResolveTag)(THIS_ LPCWSTR *ppszTag) PURE;
    STDMETHOD_(HRESULT,GetRemoteTransportAddress)(THIS_ LPCWSTR *ppszRemoteTransportAddress) PURE;
    STDMETHOD_(HRESULT,GetLocalTransportAddress)(THIS_ LPCWSTR *ppszLocalTransportAddress) PURE;
    STDMETHOD_(HRESULT,GetLocalInterfaceGUID)(THIS_ GUID *pGuid) PURE;
    STDMETHOD_(HRESULT *,GetInstanceId)(THIS_ ULONGLONG *pullInstanceId) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDiscoveredService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDiscoveredService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDiscoveredService_Release(This) (This)->lpVtbl->Release(This)
#define IWSDiscoveredService_GetEndpointReference(This,ppEndPointReference) (This)->lpVtbl->GetEndpointReference(This,ppEndPointReference)
#define IWSDiscoveredService_GetTypes(This,ppTypesList) (This)->lpVtbl->GetTypes(This,ppTypesList)
#define IWSDiscoveredService_GetScopes(This,ppScopesList) (This)->lpVtbl->GetScopes(This,ppScopesList)
#define IWSDiscoveredService_GetXAddrs(This,ppXAddrsList) (This)->lpVtbl->GetXAddrs(This,ppXAddrsList)
#define IWSDiscoveredService_GetMetadataVersion(This,pullMetadataVersion) (This)->lpVtbl->GetMetadataVersion(This,pullMetadataVersion)
#define IWSDiscoveredService_GetExtendedDiscoXML(This,ppHeaderAny,ppBodyAny) (This)->lpVtbl->GetExtendedDiscoXML(This,ppHeaderAny,ppBodyAny)
#define IWSDiscoveredService_GetProbeResolveTag(This,ppszTag) (This)->lpVtbl->GetProbeResolveTag(This,ppszTag)
#define IWSDiscoveredService_GetRemoteTransportAddress(This,ppszRemoteTransportAddress) (This)->lpVtbl->GetRemoteTransportAddress(This,ppszRemoteTransportAddress)
#define IWSDiscoveredService_GetLocalTransportAddress(This,ppszLocalTransportAddress) (This)->lpVtbl->GetLocalTransportAddress(This,ppszLocalTransportAddress)
#define IWSDiscoveredService_GetLocalInterfaceGUID(This,pGuid) (This)->lpVtbl->GetLocalInterfaceGUID(This,pGuid)
#define IWSDiscoveredService_GetInstanceId(This,pullInstanceId) (This)->lpVtbl->GetInstanceId(This,pullInstanceId)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDiscoveryProviderNotify
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDiscoveryProviderNotify,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDiscoveryProviderNotify methods */
    STDMETHOD_(HRESULT,Add)(THIS_ IWSDiscoveredService *pService) PURE;
    STDMETHOD_(HRESULT,Remove)(THIS_ IWSDiscoveredService *pService) PURE;
    STDMETHOD_(HRESULT,SearchFailed)(THIS_ HRESULT hr,LPCWSTR pszTag) PURE;
    STDMETHOD_(HRESULT,SearchComplete)(THIS_ LPCWSTR pszTag) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDiscoveryProviderNotify_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDiscoveryProviderNotify_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDiscoveryProviderNotify_Release(This) (This)->lpVtbl->Release(This)
#define IWSDiscoveryProviderNotify_Add(This,pService) (This)->lpVtbl->Add(This,pService)
#define IWSDiscoveryProviderNotify_Remove(This,pService) (This)->lpVtbl->Remove(This,pService)
#define IWSDiscoveryProviderNotify_SearchFailed(This,hr,pszTag) (This)->lpVtbl->SearchFailed(This,hr,pszTag)
#define IWSDiscoveryProviderNotify_SearchComplete(This,pszTag) (This)->lpVtbl->SearchComplete(This,pszTag)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDiscoveryProvider
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDiscoveryProvider,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDiscoveryProvider methods */
    STDMETHOD_(HRESULT,SetAddressFamily)(THIS_ DWORD dwAddressFamily) PURE;
    STDMETHOD_(HRESULT,Attach)(THIS_ IWSDiscoveryProviderNotify *pSink) PURE;
    STDMETHOD_(HRESULT,Detach)(THIS) PURE;
    STDMETHOD_(HRESULT,SearchById)(THIS_ LPCWSTR pszId,LPCWSTR pszTag) PURE;
    STDMETHOD_(HRESULT,SearchByAddress)(THIS_ LPCWSTR pszAddress,LPCWSTR pszTag) PURE;
    STDMETHOD_(HRESULT,SearchByType)(THIS_ LPCWSTR pszTag) PURE;
    STDMETHOD_(HRESULT,GetXMLContext)(THIS_ IWSDXMLContext **ppContext) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDiscoveryProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDiscoveryProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDiscoveryProvider_Release(This) (This)->lpVtbl->Release(This)
#define IWSDiscoveryProvider_SetAddressFamily(This,dwAddressFamily) (This)->lpVtbl->SetAddressFamily(This,dwAddressFamily)
#define IWSDiscoveryProvider_Attach(This,pSink) (This)->lpVtbl->Attach(This,pSink)
#define IWSDiscoveryProvider_Detach() (This)->lpVtbl->Detach(This)
#define IWSDiscoveryProvider_SearchById(This,pszId,pszTag) (This)->lpVtbl->SearchById(This,pszId,pszTag)
#define IWSDiscoveryProvider_SearchByAddress(This,pszAddress,pszTag) (This)->lpVtbl->SearchByAddress(This,pszAddress,pszTag)
#define IWSDiscoveryProvider_SearchByType(This,pszTag) (This)->lpVtbl->SearchByType(This,pszTag)
#define IWSDiscoveryProvider_GetXMLContext(This,ppContext) (This)->lpVtbl->GetXMLContext(This,ppContext)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDiscoveryPublisher
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDiscoveryPublisher,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDiscoveryPublisher methods */
    STDMETHOD_(HRESULT,SetAddressFamily)(THIS_ DWORD dwAddressFamily) PURE;
    STDMETHOD_(HRESULT,RegisterNotificationSink)(THIS_ IWSDiscoveryPublisherNotify *pSink) PURE;
    STDMETHOD_(HRESULT,UnRegisterNotificationSink)(THIS_ IWSDiscoveryPublisherNotify *pSink) PURE;
    STDMETHOD_(HRESULT,Publish)(THIS_ LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSD_URI_LIST *pXAddrsList) PURE;
    STDMETHOD_(HRESULT,UnPublish)(THIS_ LPCWSTR pszDeviceId,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSDXML_ELEMENT *pAny) PURE;
    STDMETHOD_(HRESULT,MatchProbe)(THIS_ const WSD_SOAP_MESSAGE *pProbeMessage,IWSDMessageParameters *pMessageParameters,LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSD_URI_LIST *pXAddrsList) PURE;
    STDMETHOD_(HRESULT,MatchResolve)(THIS_ const WSD_SOAP_MESSAGE *pResolveMessage,IWSDMessageParameters *pMessageParameters,LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSD_URI_LIST *pXAddrsList) PURE;
    STDMETHOD_(HRESULT,PublishEx)(THIS_ LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSDXML_ELEMENT *pAny) PURE;
    STDMETHOD_(HRESULT,MatchProbeEx)(THIS_ const WSD_SOAP_MESSAGE *pProbeMessage,IWSDMessageParameters *pMessageParameters,LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSDXML_ELEMENT *pAny) PURE;
    STDMETHOD_(HRESULT,MatchResolveEx)(THIS_ const WSD_SOAP_MESSAGE *pResolveMessage,IWSDMessageParameters *pMessageParameters,LPCWSTR pszId,ULONGLONG ullMetadataVersion,ULONGLONG ullInstanceId,ULONGLONG ullMessageNumber,const WSDXML_ELEMENT *pAny) PURE;
    STDMETHOD_(HRESULT,RegisterScopeMatchingRule)(THIS_ IWSDScopeMatchingRule *pScopeMatchingRule) PURE;
    STDMETHOD_(HRESULT,UnRegisterScopeMatchingRule)(THIS_ IWSDScopeMatchingRule *pScopeMatchingRule) PURE;
    STDMETHOD_(HRESULT,GetXMLContext)(THIS_ IWSDXMLContext **ppContext) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDiscoveryPublisher_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDiscoveryPublisher_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDiscoveryPublisher_Release(This) (This)->lpVtbl->Release(This)
#define IWSDiscoveryPublisher_SetAddressFamily(This,dwAddressFamily) (This)->lpVtbl->SetAddressFamily(This,dwAddressFamily)
#define IWSDiscoveryPublisher_RegisterNotificationSink(This,pSink) (This)->lpVtbl->RegisterNotificationSink(This,pSink)
#define IWSDiscoveryPublisher_UnRegisterNotificationSink(This,pSink) (This)->lpVtbl->UnRegisterNotificationSink(This,pSink)
#define IWSDiscoveryPublisher_Publish(This,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList) (This)->lpVtbl->Publish(This,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList)
#define IWSDiscoveryPublisher_UnPublish(This,pszDeviceId,ullInstanceId,ullMessageNumber,pAny) (This)->lpVtbl->UnPublish(This,pszDeviceId,ullInstanceId,ullMessageNumber,pAny)
#define IWSDiscoveryPublisher_MatchProbe(This,pProbeMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList) (This)->lpVtbl->MatchProbe(This,pProbeMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList)
#define IWSDiscoveryPublisher_MatchResolve(This,pResolveMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList) (This)->lpVtbl->MatchResolve(This,pResolveMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pXAddrsList)
#define IWSDiscoveryPublisher_PublishEx(This,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny) (This)->lpVtbl->PublishEx(This,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny)
#define IWSDiscoveryPublisher_MatchProbeEx(This,pProbeMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny) (This)->lpVtbl->MatchProbeEx(This,pProbeMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny)
#define IWSDiscoveryPublisher_MatchResolveEx(This,pResolveMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny) (This)->lpVtbl->MatchResolveEx(This,pResolveMessage,pMessageParameters,pszId,ullMetadataVersion,ullInstanceId,ullMessageNumber,pAny)
#define IWSDiscoveryPublisher_RegisterScopeMatchingRule(This,pScopeMatchingRule) (This)->lpVtbl->RegisterScopeMatchingRule(This,pScopeMatchingRule)
#define IWSDiscoveryPublisher_UnRegisterScopeMatchingRule(This,pScopeMatchingRule) (This)->lpVtbl->UnRegisterScopeMatchingRule(This,pScopeMatchingRule)
#define IWSDiscoveryPublisher_GetXMLContext(This,ppContext) (This)->lpVtbl->GetXMLContext(This,ppContext)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI WSDCreateDiscoveryProvider(
  IWSDXMLContext *pContext,
  IWSDiscoveryProvider **ppProvider
);

HRESULT WINAPI WSDCreateDiscoveryPublisher(
  IWSDXMLContext *pContext,
  IWSDiscoveryPublisher **ppPublisher
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDDISCO*/
