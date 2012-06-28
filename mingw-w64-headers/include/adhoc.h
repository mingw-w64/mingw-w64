/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_ADHOC
#define _INC_ADHOC

#if (_WIN32_WINNT >= 0x0600)

typedef enum tagDOT11_ADHOC_AUTH_ALGORITHM {
  DOT11_ADHOC_AUTH_ALGO_INVALID      = -1,
  DOT11_ADHOC_AUTH_ALGO_80211_OPEN   = 1,
  DOT11_ADHOC_AUTH_ALGO_RSNA_PSK     = 7 
} DOT11_ADHOC_AUTH_ALGORITHM;

typedef enum tagDOT11_ADHOC_CIPHER_ALGORITHM {
  DOT11_ADHOC_CIPHER_ALGO_INVALID   = -1,
  DOT11_ADHOC_CIPHER_ALGO_NONE      = 0x00,
  DOT11_ADHOC_CIPHER_ALGO_CCMP      = 0x04,
  DOT11_ADHOC_CIPHER_ALGO_WEP       = 0x101 
} DOT11_ADHOC_CIPHER_ALGORITHM;

typedef enum tagDOT11_ADHOC_CONNECT_FAIL_REASON {
  DOT11_ADHOC_CONNECT_FAIL_DOMAIN_MISMATCH       = 0,
  DOT11_ADHOC_CONNECT_FAIL_PASSPHRASE_MISMATCH   = 1,
  DOT11_ADHOC_CONNECT_FAIL_OTHER                 = 2 
} DOT11_ADHOC_CONNECT_FAIL_REASON;

typedef enum tagDOT11_ADHOC_NETWORK_CONNECTION_STATUS {
  DOT11_ADHOC_NETWORK_CONNECTION_STATUS_INVALID        = 0,
  DOT11_ADHOC_NETWORK_CONNECTION_STATUS_DISCONNECTED   = 11,
  DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTING     = 12,
  DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTED      = 13,
  DOT11_ADHOC_NETWORK_CONNECTION_STATUS_FORMED         = 14 
} DOT11_ADHOC_NETWORK_CONNECTION_STATUS;

typedef struct IDot11AdHocInterfaceNotificationSink IDot11AdHocInterfaceNotificationSink;
typedef struct IDot11AdHocInterface IDot11AdHocInterface;
typedef struct IDot11AdHocManager IDot11AdHocManager;
typedef struct IDot11AdHocManagerNotificationSink IDot11AdHocManagerNotificationSink;
typedef struct IDot11AdHocNetwork IDot11AdHocNetwork;
typedef struct IEnumDot11AdHocSecuritySettings IEnumDot11AdHocSecuritySettings;
typedef struct IEnumDot11AdHocNetworks IEnumDot11AdHocNetworks;
typedef struct IDot11AdHocSecuritySettings IDot11AdHocSecuritySettings;
typedef struct IEnumDot11AdHocNetworks IEnumDot11AdHocNetworks;
typedef struct IEnumDot11AdHocInterfaces IEnumDot11AdHocInterfaces;

#undef  INTERFACE
#define INTERFACE IDot11AdHocInterfaceNotificationSink
DECLARE_INTERFACE_(IDot11AdHocInterfaceNotificationSink,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocInterfaceNotificationSink methods */
    STDMETHOD_(HRESULT,OnConnectionStatusChange)(THIS_ DOT11_ADHOC_NETWORK_CONNECTION_STATUS eStatus) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocInterfaceNotificationSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocInterfaceNotificationSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocInterfaceNotificationSink_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocInterfaceNotificationSink_OnConnectionStatusChange(This,eStatus) (This)->lpVtbl->OnConnectionStatusChange(This,eStatus)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocInterface
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocInterface,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocInterface methods */
    STDMETHOD_(HRESULT,GetDeviceSignature)(THIS_ GUID *pSignature) PURE;
    STDMETHOD_(HRESULT,GetFriendlyName)(THIS_ LPWSTR *ppszName) PURE;
    STDMETHOD_(HRESULT,IsDot11d)(THIS_ BOOLEAN *pf11d) PURE;
    STDMETHOD_(HRESULT,IsAdHocCapable)(THIS_ BOOLEAN *pfAdHocCapable) PURE;
    STDMETHOD_(HRESULT,IsRadioOn)(THIS_ BOOLEAN *pfIsRadioOn) PURE;
    STDMETHOD_(HRESULT,GetActiveNetwork)(THIS_ IDot11AdHocNetwork **ppNetwork) PURE;
    STDMETHOD_(HRESULT,GetIEnumSecuritySettings)(THIS_ IEnumDot11AdHocSecuritySettings **ppEnum) PURE;
    STDMETHOD_(HRESULT,GetIEnumDot11AdHocNetworks)(THIS_ GUID *pFilterGuid,IEnumDot11AdHocNetworks **ppEnum) PURE;
    STDMETHOD_(HRESULT,GetStatus)(THIS_ DOT11_ADHOC_NETWORK_CONNECTION_STATUS *pState) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocInterface_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocInterface_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocInterface_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocInterface_GetDeviceSignature(This,pSignature) (This)->lpVtbl->GetDeviceSignature(This,pSignature)
#define IDot11AdHocInterface_GetFriendlyName(This,ppszName) (This)->lpVtbl->GetFriendlyName(This,ppszName)
#define IDot11AdHocInterface_IsDot11d(This,pf11d) (This)->lpVtbl->IsDot11d(This,pf11d)
#define IDot11AdHocInterface_IsAdHocCapable(This,pfAdHocCapable) (This)->lpVtbl->IsAdHocCapable(This,pfAdHocCapable)
#define IDot11AdHocInterface_IsRadioOn(This,pfIsRadioOn) (This)->lpVtbl->IsRadioOn(This,pfIsRadioOn)
#define IDot11AdHocInterface_GetActiveNetwork(This,ppNetwork) (This)->lpVtbl->GetActiveNetwork(This,ppNetwork)
#define IDot11AdHocInterface_GetIEnumSecuritySettings(This,ppEnum) (This)->lpVtbl->GetIEnumSecuritySettings(This,ppEnum)
#define IDot11AdHocInterface_GetIEnumDot11AdHocNetworks(This,pFilterGuid,ppEnum) (This)->lpVtbl->GetIEnumDot11AdHocNetworks(This,pFilterGuid,ppEnum)
#define IDot11AdHocInterface_GetStatus(This,pState) (This)->lpVtbl->GetStatus(This,pState)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocManager,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocManager methods */
    STDMETHOD_(HRESULT,CreateNetwork)(THIS_ LPCWSTR Name,LPCWSTR Password,LONG GeographicalId,IDot11AdHocInterface *pInterface,IDot11AdHocSecuritySettings *pSecurity,GUID *pContextGuid,IDot11AdHocNetwork **pIAdHoc) PURE;
    STDMETHOD_(HRESULT,CommitCreatedNetwork)(THIS_ IDot11AdHocNetwork *pIAdHoc,BOOLEAN fSaveProfile,BOOLEAN fMakeSavedProfileUserSpecific) PURE;
    STDMETHOD_(HRESULT,GetIEnumDot11AdHocNetworks)(THIS_ GUID *pContextGuid,IEnumDot11AdHocNetworks **ppEnum) PURE;
    STDMETHOD_(HRESULT,GetIEnumDot11AdHocInterfaces)(THIS_ IEnumDot11AdHocInterfaces **ppEnum) PURE;
    STDMETHOD_(HRESULT,GetNetwork)(THIS_ GUID *NetworkSignature,IDot11AdHocNetwork **pNetwork) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocManager_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocManager_CreateNetwork(This,Name,Password,GeographicalId,pInterface,pSecurity,pContextGuid,pIAdHoc) (This)->lpVtbl->CreateNetwork(This,Name,Password,GeographicalId,pInterface,pSecurity,pContextGuid,pIAdHoc)
#define IDot11AdHocManager_CommitCreatedNetwork(This,pIAdHoc,fSaveProfile,fMakeSavedProfileUserSpecific) (This)->lpVtbl->CommitCreatedNetwork(This,pIAdHoc,fSaveProfile,fMakeSavedProfileUserSpecific)
#define IDot11AdHocManager_GetIEnumDot11AdHocNetworks(This,pContextGuid,ppEnum) (This)->lpVtbl->GetIEnumDot11AdHocNetworks(This,pContextGuid,ppEnum)
#define IDot11AdHocManager_GetIEnumDot11AdHocInterfaces(This,ppEnum) (This)->lpVtbl->GetIEnumDot11AdHocInterfaces(This,ppEnum)
#define IDot11AdHocManager_GetNetwork(This,NetworkSignature,pNetwork) (This)->lpVtbl->GetNetwork(This,NetworkSignature,pNetwork)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocManagerNotificationSink
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocManagerNotificationSink,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocManagerNotificationSink methods */
    STDMETHOD_(HRESULT,OnNetworkAdd)(THIS_ IDot11AdHocNetwork *pIAdHocNetwork) PURE;
    STDMETHOD_(HRESULT,OnNetworkRemove)(THIS_ GUID *Signature) PURE;
    STDMETHOD_(HRESULT,OnInterfaceAdd)(THIS_ IDot11AdHocInterface *pIAdHocInterface) PURE;
    STDMETHOD_(HRESULT,OnInterfaceRemove)(THIS_ GUID *Signature) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocManagerNotificationSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocManagerNotificationSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocManagerNotificationSink_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocManagerNotificationSink_OnNetworkAdd(This,pIAdHocNetwork) (This)->lpVtbl->OnNetworkAdd(This,pIAdHocNetwork)
#define IDot11AdHocManagerNotificationSink_OnNetworkRemove(This,Signature) (This)->lpVtbl->OnNetworkRemove(This,Signature)
#define IDot11AdHocManagerNotificationSink_OnInterfaceAdd(This,pIAdHocInterface) (This)->lpVtbl->OnInterfaceAdd(This,pIAdHocInterface)
#define IDot11AdHocManagerNotificationSink_OnInterfaceRemove(This,Signature) (This)->lpVtbl->OnInterfaceRemove(This,Signature)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocNetwork
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocNetwork,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocNetwork methods */
    STDMETHOD_(HRESULT,GetStatus)(THIS_ DOT11_ADHOC_NETWORK_CONNECTION_STATUS *eStatus) PURE;
    STDMETHOD_(HRESULT,GetSSID)(THIS_ LPWSTR *ppszwSSID) PURE;
    STDMETHOD_(HRESULT,HasProfile)(THIS_ BOOLEAN *pf11d) PURE;
    STDMETHOD_(HRESULT,GetProfileName)(THIS_ LPWSTR *ppszwProfileName) PURE;
    STDMETHOD_(HRESULT,DeleteProfile)(THIS) PURE;
    STDMETHOD_(HRESULT,GetSignalQuality)(THIS_ ULONG *puStrengthValue,ULONG *puStrengthMax) PURE;
    STDMETHOD_(HRESULT,GetSecuritySetting)(THIS_ IDot11AdHocSecuritySettings **pAdHocSecuritySetting) PURE;
    STDMETHOD_(HRESULT,GetContextGuid)(THIS_ GUID *pContextGuid) PURE;
    STDMETHOD_(HRESULT,GetSignature)(THIS_ GUID *pSignature) PURE;
    STDMETHOD_(HRESULT,GetInterface)(THIS_ IDot11AdHocInterface **pAdHocInterface) PURE;
    STDMETHOD_(HRESULT,Connect)(THIS_ LPCWSTR Passphrase,LONG GeographicalId,BOOLEAN fSaveProfile,BOOLEAN fMakeSavedProfileUserSpecific) PURE;
    STDMETHOD_(HRESULT,Disconnect)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocNetwork_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocNetwork_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocNetwork_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocNetwork_GetStatus(This,eStatus) (This)->lpVtbl->GetStatus(This,eStatus)
#define IDot11AdHocNetwork_GetSSID(This,ppszwSSID) (This)->lpVtbl->GetSSID(This,ppszwSSID)
#define IDot11AdHocNetwork_HasProfile(This,pf11d) (This)->lpVtbl->HasProfile(This,pf11d)
#define IDot11AdHocNetwork_GetProfileName(This,ppszwProfileName) (This)->lpVtbl->GetProfileName(This,ppszwProfileName)
#define IDot11AdHocNetwork_DeleteProfile() (This)->lpVtbl->DeleteProfile(This)
#define IDot11AdHocNetwork_GetSignalQuality(This,puStrengthValue,puStrengthMax) (This)->lpVtbl->GetSignalQuality(This,puStrengthValue,puStrengthMax)
#define IDot11AdHocNetwork_GetSecuritySetting(This,pAdHocSecuritySetting) (This)->lpVtbl->GetSecuritySetting(This,pAdHocSecuritySetting)
#define IDot11AdHocNetwork_GetContextGuid(This,pContextGuid) (This)->lpVtbl->GetContextGuid(This,pContextGuid)
#define IDot11AdHocNetwork_GetSignature(This,pSignature) (This)->lpVtbl->GetSignature(This,pSignature)
#define IDot11AdHocNetwork_GetInterface(This,pAdHocInterface) (This)->lpVtbl->GetInterface(This,pAdHocInterface)
#define IDot11AdHocNetwork_Connect(This,Passphrase,GeographicalId,fSaveProfile,fMakeSavedProfileUserSpecific) (This)->lpVtbl->Connect(This,Passphrase,GeographicalId,fSaveProfile,fMakeSavedProfileUserSpecific)
#define IDot11AdHocNetwork_Disconnect() (This)->lpVtbl->Disconnect(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocNetworkNotificationSink
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocNetworkNotificationSink,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocNetworkNotificationSink methods */
    STDMETHOD_(HRESULT,OnStatusChange)(THIS_ DOT11_ADHOC_NETWORK_CONNECTION_STATUS eStatus) PURE;
    STDMETHOD_(HRESULT,OnConnectFail)(THIS_ DOT11_ADHOC_CONNECT_FAIL_REASON eFailReason) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocNetworkNotificationSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocNetworkNotificationSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocNetworkNotificationSink_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocNetworkNotificationSink_OnStatusChange(This,eStatus) (This)->lpVtbl->OnStatusChange(This,eStatus)
#define IDot11AdHocNetworkNotificationSink_OnConnectFail(This,eFailReason) (This)->lpVtbl->OnConnectFail(This,eFailReason)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDot11AdHocSecuritySettings
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDot11AdHocSecuritySettings,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDot11AdHocSecuritySettings methods */
    STDMETHOD_(HRESULT,GetDot11AuthAlgorithm)(THIS_ DOT11_ADHOC_AUTH_ALGORITHM *pAuth) PURE;
    STDMETHOD_(HRESULT,GetDot11CipherAlgorithm)(THIS_ DOT11_ADHOC_CIPHER_ALGORITHM *pCipher) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDot11AdHocSecuritySettings_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDot11AdHocSecuritySettings_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDot11AdHocSecuritySettings_Release(This) (This)->lpVtbl->Release(This)
#define IDot11AdHocSecuritySettings_GetDot11AuthAlgorithm(This,pAuth) (This)->lpVtbl->GetDot11AuthAlgorithm(This,pAuth)
#define IDot11AdHocSecuritySettings_GetDot11CipherAlgorithm(This,pCipher) (This)->lpVtbl->GetDot11CipherAlgorithm(This,pCipher)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IEnumDot11AdHocInterfaces
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IEnumDot11AdHocInterfaces,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IEnumDot11AdHocInterfaces methods */
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG cElt,IDot11AdHocInterface **rgElt,ULONG *pcEltFetched) PURE;
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG cElt) PURE;
    STDMETHOD_(HRESULT,Reset)(THIS) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumDot11AdHocInterfaces **ppEnum) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IEnumDot11AdHocInterfaces_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDot11AdHocInterfaces_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDot11AdHocInterfaces_Release(This) (This)->lpVtbl->Release(This)
#define IEnumDot11AdHocInterfaces_Next(This,cElt,rgElt,pcEltFetched) (This)->lpVtbl->Next(This,cElt,rgElt,pcEltFetched)
#define IEnumDot11AdHocInterfaces_Skip(This,cElt) (This)->lpVtbl->Skip(This,cElt)
#define IEnumDot11AdHocInterfaces_Reset() (This)->lpVtbl->Reset(This)
#define IEnumDot11AdHocInterfaces_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IEnumDot11AdHocNetworks
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IEnumDot11AdHocNetworks,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IEnumDot11AdHocNetworks methods */
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG cElt,IDot11AdHocNetwork **rgElt,ULONG *pcEltFetched) PURE;
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG cElt) PURE;
    STDMETHOD_(HRESULT,Reset)(THIS) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumDot11AdHocNetworks **ppEnum) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IEnumDot11AdHocNetworks_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDot11AdHocNetworks_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDot11AdHocNetworks_Release(This) (This)->lpVtbl->Release(This)
#define IEnumDot11AdHocNetworks_Next(This,cElt,rgElt,pcEltFetched) (This)->lpVtbl->Next(This,cElt,rgElt,pcEltFetched)
#define IEnumDot11AdHocNetworks_Skip(This,cElt) (This)->lpVtbl->Skip(This,cElt)
#define IEnumDot11AdHocNetworks_Reset() (This)->lpVtbl->Reset(This)
#define IEnumDot11AdHocNetworks_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IEnumDot11AdHocSecuritySettings
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IEnumDot11AdHocSecuritySettings,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IEnumDot11AdHocSecuritySettings methods */
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG cElt,IDot11AdHocSecuritySettings **rgElt,ULONG *pcEltFetched) PURE;
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG cElt) PURE;
    STDMETHOD_(HRESULT,Reset)(THIS) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumDot11AdHocSecuritySettings **ppEnum) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IEnumDot11AdHocSecuritySettings_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDot11AdHocSecuritySettings_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDot11AdHocSecuritySettings_Release(This) (This)->lpVtbl->Release(This)
#define IEnumDot11AdHocSecuritySettings_Next(This,cElt,rgElt,pcEltFetched) (This)->lpVtbl->Next(This,cElt,rgElt,pcEltFetched)
#define IEnumDot11AdHocSecuritySettings_Skip(This,cElt) (This)->lpVtbl->Skip(This,cElt)
#define IEnumDot11AdHocSecuritySettings_Reset() (This)->lpVtbl->Reset(This)
#define IEnumDot11AdHocSecuritySettings_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_ADHOC*/
