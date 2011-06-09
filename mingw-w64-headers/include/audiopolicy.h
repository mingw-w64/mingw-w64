/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_AUDIOPOLICY__
#define __INC_AUDIOPOLICY__

#include <objbase.h>
#include <audiosessiontypes.h>

#if (_WIN32_WINNT >= 0x0600)

/* Fixme: AudioSessionDisconnectReason is guessed from
    https://msdn.microsoft.com/en-us/library/dd370941%28v=VS.85%29.aspx
*/
typedef enum _AudioSessionDisconnectReason {
  DisconnectReasonDeviceRemoval = 0,
  DisconnectReasonServerShutdown,
  DisconnectReasonFormatChanged,
  DisconnectReasonSessionLogoff,
  DisconnectReasonSessionDisconnected,
  DisconnectReasonExclusiveModeOverride
} AudioSessionDisconnectReason;

#ifndef __IAudioClockAdjustment_FWD_DEFINED__
#define __IAudioClockAdjustment_FWD_DEFINED__
typedef struct ISimpleAudioVolume ISimpleAudioVolume;
#endif

#ifndef __IAudioSessionControl_FWD_DEFINED__
#define __IAudioSessionControl_FWD_DEFINED__
typedef struct IAudioSessionControl IAudioSessionControl;
#endif

#ifndef __IAudioSessionEvents_FWD_DEFINED__
#define __IAudioSessionEvents_FWD_DEFINED__
typedef struct IAudioSessionEvents IAudioSessionEvents;
#endif

#ifndef __IAudioSessionManager_FWD_DEFINED__
#define __IAudioSessionManager_FWD_DEFINED__
typedef struct IAudioSessionManager IAudioSessionManager;
#endif

#undef  INTERFACE
#define INTERFACE IAudioSessionControl
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionControl,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionControl methods */
    STDMETHOD_(HRESULT,GetDisplayName)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetGroupingParam)(THIS_ GUID *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetIconPath)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetLastActivation)(THIS_ DATE *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetLastInactivation)(THIS_ DATE *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ AudioSessionState *pRetVal) PURE;
    STDMETHOD_(HRESULT,RegisterAudioSessionNotification)(THIS_ IAudioSessionEvents *NewNotifications) PURE;
    STDMETHOD_(HRESULT,SetDisplayName)(THIS_ LPCWSTR Value,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,SetGroupingParam)(THIS_ LPCGUID Grouping,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,SetIconPath)(THIS_ LPCWSTR Value,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,UnregisterAudioSessionNotification)(THIS_ IAudioSessionEvents *NewNotifications) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionControl_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionControl_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionControl_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionControl_GetDisplayName(This,pRetVal) (This)->lpVtbl->GetDisplayName(This,pRetVal)
#define IAudioSessionControl_GetGroupingParam(This,pRetVal) (This)->lpVtbl->GetGroupingParam(This,pRetVal)
#define IAudioSessionControl_GetIconPath(This,pRetVal) (This)->lpVtbl->GetIconPath(This,pRetVal)
#define IAudioSessionControl_GetLastActivation(This,pRetVal) (This)->lpVtbl->GetLastActivation(This,pRetVal)
#define IAudioSessionControl_GetLastInactivation(This,pRetVal) (This)->lpVtbl->GetLastInactivation(This,pRetVal)
#define IAudioSessionControl_GetState(This,pRetVal) (This)->lpVtbl->GetState(This,pRetVal)
#define IAudioSessionControl_RegisterAudioSessionNotification(This,NewNotifications) (This)->lpVtbl->RegisterAudioSessionNotification(This,NewNotifications)
#define IAudioSessionControl_SetDisplayName(This,Value,EventContext) (This)->lpVtbl->SetDisplayName(This,Value,EventContext)
#define IAudioSessionControl_SetGroupingParam(This,Grouping,EventContext) (This)->lpVtbl->SetGroupingParam(This,Grouping,EventContext)
#define IAudioSessionControl_SetIconPath(This,Value,EventContext) (This)->lpVtbl->SetIconPath(This,Value,EventContext)
#define IAudioSessionControl_UnregisterAudioSessionNotification(This,NewNotifications) (This)->lpVtbl->UnregisterAudioSessionNotification(This,NewNotifications)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioSessionEvents
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionEvents,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionEvents methods */
    STDMETHOD_(HRESULT,OnChannelVolumeChanged)(THIS_ DWORD ChannelCount,float NewChannelVolumeArray[],DWORD ChangedChannel,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,OnDisplayNameChanged)(THIS_ LPCWSTR NewDisplayName,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,OnGroupingParamChanged)(THIS_ LPCGUID NewGroupingParam,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,OnIconPathChanged)(THIS_ PWCHAR NewIconPath,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,OnSessionDisconnected)(THIS_ AudioSessionDisconnectReason DisconnectReason) PURE;
    STDMETHOD_(HRESULT,OnSimpleVolumeChanged)(THIS_ float NewVolume,WINBOOL NewMute,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,OnStateChanged)(THIS_ AudioSessionState NewState) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionEvents_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionEvents_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionEvents_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionEvents_OnChannelVolumeChanged(This,ChannelCount,NewChannelVolumeArray,ChangedChannel,EventContext) (This)->lpVtbl->OnChannelVolumeChanged(This,ChannelCount,NewChannelVolumeArray,ChangedChannel,EventContext)
#define IAudioSessionEvents_OnDisplayNameChanged(This,NewDisplayName,EventContext) (This)->lpVtbl->OnDisplayNameChanged(This,NewDisplayName,EventContext)
#define IAudioSessionEvents_OnGroupingParamChanged(This,NewGroupingParam,EventContext) (This)->lpVtbl->OnGroupingParamChanged(This,NewGroupingParam,EventContext)
#define IAudioSessionEvents_OnIconPathChanged(This,NewIconPath,EventContext) (This)->lpVtbl->OnIconPathChanged(This,NewIconPath,EventContext)
#define IAudioSessionEvents_OnSessionDisconnected(This,DisconnectReason) (This)->lpVtbl->OnSessionDisconnected(This,DisconnectReason)
#define IAudioSessionEvents_OnSimpleVolumeChanged(This,NewVolume,NewMute,EventContext) (This)->lpVtbl->OnSimpleVolumeChanged(This,NewVolume,NewMute,EventContext)
#define IAudioSessionEvents_OnStateChanged(This,NewState) (This)->lpVtbl->OnStateChanged(This,NewState)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioSessionManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionManager,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionManager methods */
    STDMETHOD_(HRESULT,GetAudioSessionControl)(THIS_ LPCGUID AudioSessionGuid,WINBOOL CrossProcessSession,IAudioSessionControl **SessionControl) PURE;
    STDMETHOD_(HRESULT,GetSimpleAudioVolume)(THIS_ LPCGUID AudioSessionGuid,DWORD CrossProcessSession,ISimpleAudioVolume **AudioVolume) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionManager_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionManager_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionManager_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionManager_GetAudioSessionControl(This,AudioSessionGuid,CrossProcessSession,SessionControl) (This)->lpVtbl->GetAudioSessionControl(This,AudioSessionGuid,CrossProcessSession,SessionControl)
#define IAudioSessionManager_GetSimpleAudioVolume(This,AudioSessionGuid,CrossProcessSession,AudioVolume) (This)->lpVtbl->GetSimpleAudioVolume(This,AudioSessionGuid,CrossProcessSession,AudioVolume)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)

#ifndef __IAudioSessionControl2_FWD_DEFINED__
#define __IAudioSessionControl2_FWD_DEFINED__
typedef struct IAudioSessionControl2 IAudioSessionControl2;
#endif

#ifndef __IAudioSessionEnumerator_FWD_DEFINED__
#define __IAudioSessionEnumerator_FWD_DEFINED__
typedef struct IAudioSessionEnumerator IAudioSessionEnumerator;
#endif

#ifndef __IAudioSessionManager2_FWD_DEFINED__
#define __IAudioSessionManager2_FWD_DEFINED__
typedef struct IAudioSessionManager2 IAudioSessionManager2;
#endif

#ifndef __IAudioSessionNotification_FWD_DEFINED__
#define __IAudioSessionNotification_FWD_DEFINED__
typedef struct IAudioSessionNotification IAudioSessionNotification;
#endif

#ifndef __IAudioVolumeDuckNotification_FWD_DEFINED__
#define __IAudioVolumeDuckNotification_FWD_DEFINED__
typedef struct IAudioVolumeDuckNotification IAudioVolumeDuckNotification;
#endif

#undef  INTERFACE
#define INTERFACE IAudioSessionControl2
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionControl2,IAudioSessionControl)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionControl methods */
    STDMETHOD_(HRESULT,GetDisplayName)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetGroupingParam)(THIS_ GUID *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetIconPath)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetLastActivation)(THIS_ DATE *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetLastInactivation)(THIS_ DATE *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ AudioSessionState *pRetVal) PURE;
    STDMETHOD_(HRESULT,RegisterAudioSessionNotification)(THIS_ IAudioSessionEvents *NewNotifications) PURE;
    STDMETHOD_(HRESULT,SetDisplayName)(THIS_ LPCWSTR Value,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,SetGroupingParam)(THIS_ LPCGUID Grouping,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,SetIconPath)(THIS_ LPCWSTR Value,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,UnregisterAudioSessionNotification)(THIS_ IAudioSessionEvents *NewNotifications) PURE;

    /* IAudioSessionControl2 methods */
    STDMETHOD_(HRESULT,GetProcessId)(THIS_ DWORD *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetSessionIdentifier)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,GetSessionInstanceIdentifier)(THIS_ LPWSTR *pRetVal) PURE;
    STDMETHOD_(HRESULT,IsSystemSoundsSession)(THIS) PURE;
    STDMETHOD_(HRESULT,SetDuckingPreference)(THIS_ WINBOOL optOut) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionControl2_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionControl2_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionControl2_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionControl2_GetDisplayName(This,pRetVal) (This)->lpVtbl->GetDisplayName(This,pRetVal)
#define IAudioSessionControl2_GetGroupingParam(This,pRetVal) (This)->lpVtbl->GetGroupingParam(This,pRetVal)
#define IAudioSessionControl2_GetIconPath(This,pRetVal) (This)->lpVtbl->GetIconPath(This,pRetVal)
#define IAudioSessionControl2_GetLastActivation(This,pRetVal) (This)->lpVtbl->GetLastActivation(This,pRetVal)
#define IAudioSessionControl2_GetLastInactivation(This,pRetVal) (This)->lpVtbl->GetLastInactivation(This,pRetVal)
#define IAudioSessionControl2_GetState(This,pRetVal) (This)->lpVtbl->GetState(This,pRetVal)
#define IAudioSessionControl2_RegisterAudioSessionNotification(This,NewNotifications) (This)->lpVtbl->RegisterAudioSessionNotification(This,NewNotifications)
#define IAudioSessionControl2_SetDisplayName(This,Value,EventContext) (This)->lpVtbl->SetDisplayName(This,Value,EventContext)
#define IAudioSessionControl2_SetGroupingParam(This,Grouping,EventContext) (This)->lpVtbl->SetGroupingParam(This,Grouping,EventContext)
#define IAudioSessionControl2_SetIconPath(This,Value,EventContext) (This)->lpVtbl->SetIconPath(This,Value,EventContext)
#define IAudioSessionControl2_UnregisterAudioSessionNotification(This,NewNotifications) (This)->lpVtbl->UnregisterAudioSessionNotification(This,NewNotifications)
#define IAudioSessionControl2_GetProcessId(This,pRetVal) (This)->lpVtbl->GetProcessId(This,pRetVal)
#define IAudioSessionControl2_GetSessionIdentifier(This,pRetVal) (This)->lpVtbl->GetSessionIdentifier(This,pRetVal)
#define IAudioSessionControl2_GetSessionInstanceIdentifier(This,pRetVal) (This)->lpVtbl->GetSessionInstanceIdentifier(This,pRetVal)
#define IAudioSessionControl2_IsSystemSoundsSession() (This)->lpVtbl->IsSystemSoundsSession(This)
#define IAudioSessionControl2_SetDuckingPreference(This,optOut) (This)->lpVtbl->SetDuckingPreference(This,optOut)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioSessionEnumerator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionEnumerator,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionEnumerator methods */
    STDMETHOD_(HRESULT,GetCount)(THIS_ int *SessionCount) PURE;
    STDMETHOD_(HRESULT,GetSession)(THIS_ int SessionCount,IAudioSessionControl **Session) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionEnumerator_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionEnumerator_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionEnumerator_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionEnumerator_GetCount(This,SessionCount) (This)->lpVtbl->GetCount(This,SessionCount)
#define IAudioSessionEnumerator_GetSession(This,SessionCount,Session) (This)->lpVtbl->GetSession(This,SessionCount,Session)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioSessionManager2
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioSessionManager2,IAudioSessionManager)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionManager methods */
    STDMETHOD_(HRESULT,GetAudioSessionControl)(THIS_ LPCGUID AudioSessionGuid,WINBOOL CrossProcessSession,IAudioSessionControl **SessionControl) PURE;
    STDMETHOD_(HRESULT,GetSimpleAudioVolume)(THIS_ LPCGUID AudioSessionGuid,DWORD CrossProcessSession,ISimpleAudioVolume **AudioVolume) PURE;

    /* IAudioSessionManager2 methods */
    STDMETHOD_(HRESULT,GetSessionEnumerator)(THIS_ IAudioSessionEnumerator **SessionList) PURE;
    STDMETHOD_(HRESULT,RegisterDuckNotification)(THIS_ LPCWSTR SessionID,IAudioVolumeDuckNotification *duckNotification) PURE;
    STDMETHOD_(HRESULT,RegisterSessionNotification)(THIS_ IAudioSessionNotification *SessionNotification) PURE;
    STDMETHOD_(HRESULT,UnregisterDuckNotification)(THIS_ IAudioVolumeDuckNotification *duckNotification) PURE;
    STDMETHOD_(HRESULT,UnregisterSessionNotification)(THIS_ IAudioSessionNotification *SessionNotification) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionManager2_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionManager2_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionManager2_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionManager2_GetSessionEnumerator(This,SessionList) (This)->lpVtbl->GetSessionEnumerator(This,SessionList)
#define IAudioSessionManager2_RegisterDuckNotification(This,SessionID,duckNotification) (This)->lpVtbl->RegisterDuckNotification(This,SessionID,duckNotification)
#define IAudioSessionManager2_RegisterSessionNotification(This,SessionNotification) (This)->lpVtbl->RegisterSessionNotification(This,SessionNotification)
#define IAudioSessionManager2_UnregisterDuckNotification(This,duckNotification) (This)->lpVtbl->UnregisterDuckNotification(This,duckNotification)
#define IAudioSessionManager2_UnregisterSessionNotification(This,SessionNotification) (This)->lpVtbl->UnregisterSessionNotification(This,SessionNotification)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioSessionNotification
DECLARE_INTERFACE_(IAudioSessionNotification,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioSessionNotification methods */
    STDMETHOD_(HRESULT,OnSessionCreated)(THIS_ IAudioSessionControl *NewSession) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioSessionNotification_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioSessionNotification_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioSessionNotification_Release(This) (This)->pVtbl->Release(This)
#define IAudioSessionNotification_OnSessionCreated(This,NewSession) (This)->lpVtbl->OnSessionCreated(This,NewSession)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioVolumeDuckNotification
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IAudioVolumeDuckNotification,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioVolumeDuckNotification methods */
    STDMETHOD_(HRESULT,OnVolumeDuckNotification)(THIS_ LPCWSTR sessionID,UINT32 countCommunicationsSessions) PURE;
    STDMETHOD_(HRESULT,OnVolumeUnduckNotification)(THIS_ LPCWSTR sessionID,UINT32 countCommunicationsSessions) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioVolumeDuckNotification_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioVolumeDuckNotification_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioVolumeDuckNotification_Release(This) (This)->pVtbl->Release(This)
#define IAudioVolumeDuckNotification_OnVolumeDuckNotification(This,sessionID,countCommunicationsSessions) (This)->lpVtbl->OnVolumeDuckNotification(This,sessionID,countCommunicationsSessions)
#define IAudioVolumeDuckNotification_OnVolumeUnduckNotification(This,sessionID,countCommunicationsSessions) (This)->lpVtbl->OnVolumeUnduckNotification(This,sessionID,countCommunicationsSessions)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/

#endif /*__INC_AUDIOPOLICY__*/
