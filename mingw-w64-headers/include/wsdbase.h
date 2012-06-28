/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDBASE
#define _INC_WSDBASE

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#warning COM interfaces layout in this header has not been validated.
#warning COM interfaces with incorrect layout may not work at all.

typedef enum _WSDUdpMessageType {
  ONE_WAY   = 0,
  TWO_WAY   = 1 
} WSDUdpMessageType;

typedef struct _WSDUpdRetransmitParams {
  ULONG ulSendDelay;
  ULONG ulRepeat;
  ULONG ulRepeatMinDelay;
  ULONG ulRepeatMaxDelay;
  ULONG ulRepeatUpperDelay;
} WSDUdpRetransmitParams, *PWSDUdpRetransmitParams;

#undef  INTERFACE
#define INTERFACE IWSDTransportAddress
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDTransportAddress,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDTransportAddress methods */
    STDMETHOD_(HRESULT,GetPort)(THIS_ WORD *pwPort) PURE;
    STDMETHOD_(HRESULT,SetPort)(THIS_ WORD wPort) PURE;
    STDMETHOD_(HRESULT,GetTransportAddress)(THIS_ LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,GetTransportAddressEx)(THIS_ WINBOOL fSafe,LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,SetTransportAddress)(THIS_ LPCWSTR pszAddress) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDTransportAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDTransportAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDTransportAddress_Release(This) (This)->lpVtbl->Release(This)
#define IWSDTransportAddress_GetPort(This,pwPort) (This)->lpVtbl->GetPort(This,pwPort)
#define IWSDTransportAddress_SetPort(This,wPort) (This)->lpVtbl->SetPort(This,wPort)
#define IWSDTransportAddress_GetTransportAddress(This,ppszAddress) (This)->lpVtbl->GetTransportAddress(This,ppszAddress)
#define IWSDTransportAddress_GetTransportAddressEx(This,fSafe,ppszAddress) (This)->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress)
#define IWSDTransportAddress_SetTransportAddress(This,pszAddress) (This)->lpVtbl->SetTransportAddress(This,pszAddress)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDHttpAddress
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDHttpAddress,IWSDTransportAddress)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDTransportAddress methods */
    STDMETHOD_(HRESULT,GetPort)(THIS_ WORD *pwPort) PURE;
    STDMETHOD_(HRESULT,SetPort)(THIS_ WORD wPort) PURE;
    STDMETHOD_(HRESULT,GetTransportAddress)(THIS_ LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,GetTransportAddressEx)(THIS_ WINBOOL fSafe,LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,SetTransportAddress)(THIS_ LPCWSTR pszAddress) PURE;

    /* IWSDHttpAddress methods */
    STDMETHOD_(HRESULT,GetSecure)(THIS) PURE;
    STDMETHOD_(HRESULT,SetSecure)(THIS_ WINBOOL fSecure) PURE;
    STDMETHOD_(HRESULT,GetPath)(THIS_ LPCWSTR *ppszPath) PURE;
    STDMETHOD_(HRESULT,SetPath)(THIS_ LPCWSTR pszPath) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDHttpAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDHttpAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDHttpAddress_Release(This) (This)->lpVtbl->Release(This)
#define IWSDHttpAddress_GetPort(This,pwPort) (This)->lpVtbl->GetPort(This,pwPort)
#define IWSDHttpAddress_SetPort(This,wPort) (This)->lpVtbl->SetPort(This,wPort)
#define IWSDHttpAddress_GetTransportAddress(This,ppszAddress) (This)->lpVtbl->GetTransportAddress(This,ppszAddress)
#define IWSDHttpAddress_GetTransportAddressEx(This,fSafe,ppszAddress) (This)->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress)
#define IWSDHttpAddress_SetTransportAddress(This,pszAddress) (This)->lpVtbl->SetTransportAddress(This,pszAddress)
#define IWSDHttpAddress_GetSecure() (This)->lpVtbl->GetSecure(This)
#define IWSDHttpAddress_SetSecure(This,fSecure) (This)->lpVtbl->SetSecure(This,fSecure)
#define IWSDHttpAddress_GetPath(This,ppszPath) (This)->lpVtbl->GetPath(This,ppszPath)
#define IWSDHttpAddress_SetPath(This,pszPath) (This)->lpVtbl->SetPath(This,pszPath)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDUdpAddress
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDUdpAddress,IWSDTransportAddress)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDTransportAddress methods */
    STDMETHOD_(HRESULT,GetPort)(THIS_ WORD *pwPort) PURE;
    STDMETHOD_(HRESULT,SetPort)(THIS_ WORD wPort) PURE;
    STDMETHOD_(HRESULT,GetTransportAddress)(THIS_ LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,GetTransportAddressEx)(THIS_ WINBOOL fSafe,LPCWSTR *ppszAddress) PURE;
    STDMETHOD_(HRESULT,SetTransportAddress)(THIS_ LPCWSTR pszAddress) PURE;

    /* IWSDUdpAddress methods */
    STDMETHOD_(HRESULT,SetSockaddr)(THIS_ const SOCKADDR_STORAGE *pSockAddr) PURE;
    STDMETHOD_(HRESULT *,GetSockaddr)(THIS_ SOCKADDR_STORAGE *pSockAddr) PURE;
    STDMETHOD_(HRESULT,SetExclusive)(THIS_ WINBOOL fExclusive) PURE;
    STDMETHOD_(HRESULT,GetExclusive)(THIS) PURE;
    STDMETHOD_(HRESULT,SetMessageType)(THIS_ WSDUdpMessageType messageType) PURE;
    STDMETHOD_(HRESULT,GetMessageType)(THIS_ WSDUdpMessageType *pMessageType) PURE;
    STDMETHOD_(HRESULT,SetTTL)(THIS_ DWORD dwTTL) PURE;
    STDMETHOD_(HRESULT,GetTTL)(THIS_ DWORD *pdwTTL) PURE;
    STDMETHOD_(HRESULT,SetAlias)(THIS_ const GUID *pAlias) PURE;
    STDMETHOD_(HRESULT,GetAlias)(THIS_ GUID *pAlias) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDUdpAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDUdpAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDUdpAddress_Release(This) (This)->lpVtbl->Release(This)
#define IWSDUdpAddress_GetPort(This,pwPort) (This)->lpVtbl->GetPort(This,pwPort)
#define IWSDUdpAddress_SetPort(This,wPort) (This)->lpVtbl->SetPort(This,wPort)
#define IWSDUdpAddress_GetTransportAddress(This,ppszAddress) (This)->lpVtbl->GetTransportAddress(This,ppszAddress)
#define IWSDUdpAddress_GetTransportAddressEx(This,fSafe,ppszAddress) (This)->lpVtbl->GetTransportAddressEx(This,fSafe,ppszAddress)
#define IWSDUdpAddress_SetTransportAddress(This,pszAddress) (This)->lpVtbl->SetTransportAddress(This,pszAddress)
#define IWSDUdpAddress_SetSockaddr(This,pSockAddr) (This)->lpVtbl->SetSockaddr(This,pSockAddr)
#define IWSDUdpAddress_GetSockaddr(This,pSockAddr) (This)->lpVtbl->GetSockaddr(This,pSockAddr)
#define IWSDUdpAddress_SetExclusive(This,fExclusive) (This)->lpVtbl->SetExclusive(This,fExclusive)
#define IWSDUdpAddress_GetExclusive() (This)->lpVtbl->GetExclusive(This)
#define IWSDUdpAddress_SetMessageType(This,messageType) (This)->lpVtbl->SetMessageType(This,messageType)
#define IWSDUdpAddress_GetMessageType(This,pMessageType) (This)->lpVtbl->GetMessageType(This,pMessageType)
#define IWSDUdpAddress_SetTTL(This,dwTTL) (This)->lpVtbl->SetTTL(This,dwTTL)
#define IWSDUdpAddress_GetTTL(This,pdwTTL) (This)->lpVtbl->GetTTL(This,pdwTTL)
#define IWSDUdpAddress_SetAlias(This,pAlias) (This)->lpVtbl->SetAlias(This,pAlias)
#define IWSDUdpAddress_GetAlias(This,pAlias) (This)->lpVtbl->GetAlias(This,pAlias)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDAddress
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDAddress,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDAddress methods */
    STDMETHOD_(HRESULT,Serialize)(THIS_ LPWSTR pszBuffer,DWORD cchLength,WINBOOL fSafe) PURE;
    STDMETHOD_(HRESULT,Deserialize)(THIS_ LPCWSTR pszBuffer) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDAddress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDAddress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDAddress_Release(This) (This)->lpVtbl->Release(This)
#define IWSDAddress_Serialize(This,pszBuffer,cchLength,fSafe) (This)->lpVtbl->Serialize(This,pszBuffer,cchLength,fSafe)
#define IWSDAddress_Deserialize(This,pszBuffer) (This)->lpVtbl->Deserialize(This,pszBuffer)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDMessageParameters
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDMessageParameters,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDServiceMessaging methods */
    STDMETHOD_(HRESULT,GetLocalAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetLocalAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetRemoteAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetRemoteAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetLowerParameters)(THIS_ IWSDMessageParameters **ppTxParams) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDMessageParameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDMessageParameters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDMessageParameters_Release(This) (This)->lpVtbl->Release(This)
#define IWSDMessageParameters_GetLocalAddress(This,ppAddress) (This)->lpVtbl->GetLocalAddress(This,ppAddress)
#define IWSDMessageParameters_SetLocalAddress(This,pAddress) (This)->lpVtbl->SetLocalAddress(This,pAddress)
#define IWSDMessageParameters_GetRemoteAddress(This,ppAddress) (This)->lpVtbl->GetRemoteAddress(This,ppAddress)
#define IWSDMessageParameters_SetRemoteAddress(This,pAddress) (This)->lpVtbl->SetRemoteAddress(This,pAddress)
#define IWSDMessageParameters_GetLowerParameters(This,ppTxParams) (This)->lpVtbl->GetLowerParameters(This,ppTxParams)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDHttpMessageParameters
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDHttpMessageParameters,IWSDMessageParameters)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDServiceMessaging methods */
    STDMETHOD_(HRESULT,GetLocalAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetLocalAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetRemoteAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetRemoteAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetLowerParameters)(THIS_ IWSDMessageParameters **ppTxParams) PURE;

    /* IWSDHttpMessageParameters methods */
    STDMETHOD_(HRESULT,SetInboundHttpHeaders)(THIS_ LPCWSTR pszHeaders) PURE;
    STDMETHOD_(HRESULT,GetInboundHttpHeaders)(THIS_ LPCWSTR *ppszHeaders) PURE;
    STDMETHOD_(HRESULT,SetOutboundHttpHeaders)(THIS_ LPCWSTR pszHeaders) PURE;
    STDMETHOD_(HRESULT,GetOutboundHttpHeaders)(THIS_ LPCWSTR *ppszHeaders) PURE;
    STDMETHOD_(HRESULT,SetID)(THIS_ LPCWSTR pszId) PURE;
    STDMETHOD_(HRESULT,GetID)(THIS_ LPCWSTR *ppszId) PURE;
    STDMETHOD_(HRESULT,SetContext)(THIS_ IUnknown *pContext) PURE;
    STDMETHOD_(HRESULT,GetContext)(THIS_ IUnknown **ppContext) PURE;
    STDMETHOD_(HRESULT,Clear)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDHttpMessageParameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDHttpMessageParameters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDHttpMessageParameters_Release(This) (This)->lpVtbl->Release(This)
#define IWSDHttpMessageParameters_GetLocalAddress(This,ppAddress) (This)->lpVtbl->GetLocalAddress(This,ppAddress)
#define IWSDHttpMessageParameters_SetLocalAddress(This,pAddress) (This)->lpVtbl->SetLocalAddress(This,pAddress)
#define IWSDHttpMessageParameters_GetRemoteAddress(This,ppAddress) (This)->lpVtbl->GetRemoteAddress(This,ppAddress)
#define IWSDHttpMessageParameters_SetRemoteAddress(This,pAddress) (This)->lpVtbl->SetRemoteAddress(This,pAddress)
#define IWSDHttpMessageParameters_GetLowerParameters(This,ppTxParams) (This)->lpVtbl->GetLowerParameters(This,ppTxParams)
#define IWSDHttpMessageParameters_SetInboundHttpHeaders(This,pszHeaders) (This)->lpVtbl->SetInboundHttpHeaders(This,pszHeaders)
#define IWSDHttpMessageParameters_GetInboundHttpHeaders(This,ppszHeaders) (This)->lpVtbl->GetInboundHttpHeaders(This,ppszHeaders)
#define IWSDHttpMessageParameters_SetOutboundHttpHeaders(This,pszHeaders) (This)->lpVtbl->SetOutboundHttpHeaders(This,pszHeaders)
#define IWSDHttpMessageParameters_GetOutboundHttpHeaders(This,ppszHeaders) (This)->lpVtbl->GetOutboundHttpHeaders(This,ppszHeaders)
#define IWSDHttpMessageParameters_SetID(This,pszId) (This)->lpVtbl->SetID(This,pszId)
#define IWSDHttpMessageParameters_GetID(This,ppszId) (This)->lpVtbl->GetID(This,ppszId)
#define IWSDHttpMessageParameters_SetContext(This,pContext) (This)->lpVtbl->SetContext(This,pContext)
#define IWSDHttpMessageParameters_GetContext(This,ppContext) (This)->lpVtbl->GetContext(This,ppContext)
#define IWSDHttpMessageParameters_Clear() (This)->lpVtbl->Clear(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IWSDUdpMessageParameters
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDUdpMessageParameters,IWSDMessageParameters)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDServiceMessaging methods */
    STDMETHOD_(HRESULT,GetLocalAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetLocalAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetRemoteAddress)(THIS_ IWSDAddress **ppAddress) PURE;
    STDMETHOD_(HRESULT,SetRemoteAddress)(THIS_ IWSDAddress *pAddress) PURE;
    STDMETHOD_(HRESULT,GetLowerParameters)(THIS_ IWSDMessageParameters **ppTxParams) PURE;

    /* IWSDUdpMessageParameters methods */
    STDMETHOD_(HRESULT,SetRetransmitParams)(THIS_ const WSDUdpRetransmitParams *pParams) PURE;
    STDMETHOD_(HRESULT,GetRetransmitParams)(THIS_ WSDUdpRetransmitParams *pParams) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDUdpMessageParameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDUdpMessageParameters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDUdpMessageParameters_Release(This) (This)->lpVtbl->Release(This)
#define IWSDUdpMessageParameters_GetLocalAddress(This,ppAddress) (This)->lpVtbl->GetLocalAddress(This,ppAddress)
#define IWSDUdpMessageParameters_SetLocalAddress(This,pAddress) (This)->lpVtbl->SetLocalAddress(This,pAddress)
#define IWSDUdpMessageParameters_GetRemoteAddress(This,ppAddress) (This)->lpVtbl->GetRemoteAddress(This,ppAddress)
#define IWSDUdpMessageParameters_SetRemoteAddress(This,pAddress) (This)->lpVtbl->SetRemoteAddress(This,pAddress)
#define IWSDUdpMessageParameters_GetLowerParameters(This,ppTxParams) (This)->lpVtbl->GetLowerParameters(This,ppTxParams)
#define IWSDUdpMessageParameters_SetRetransmitParams(This,pParams) (This)->lpVtbl->SetRetransmitParams(This,pParams)
#define IWSDUdpMessageParameters_GetRetransmitParams(This,pParams) (This)->lpVtbl->GetRetransmitParams(This,pParams)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI WSDCreateHttpAddress(
  IWSDHttpAddress **ppAddress
);

HRESULT WINAPI WSDCreateHttpMessageParameters(
  IWSDHttpMessageParameters **ppTxParams
);

HRESULT WINAPI WSDCreateUdpAddress(
  IWSDUdpAddress **ppAddress
);

HRESULT WINAPI WSDCreateUdpMessageParameters(
  IWSDUdpMessageParameters **ppTxParams
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDBASE*/
