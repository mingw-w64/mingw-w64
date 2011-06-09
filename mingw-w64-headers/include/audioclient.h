/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __AUDIOCLIENT_H__
#define __AUDIOCLIENT_H__

#include <objbase.h>

#if (_WIN32_WINNT >= 0x0600)

enum _AUDCLNT_BUFFERFLAGS {
  AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY   = 0x1,
  AUDCLNT_BUFFERFLAGS_SILENT               = 0x2,
  AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR      = 0x4 
};

#ifndef __IAudioClockAdjustment_FWD_DEFINED__
#define __IAudioClockAdjustment_FWD_DEFINED__
typedef struct ISimpleAudioVolume ISimpleAudioVolume;
#endif

#undef  INTERFACE
#define INTERFACE ISimpleAudioVolume
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ISimpleAudioVolume,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ISimpleAudioVolume methods */
    STDMETHOD_(HRESULT,GetMasterVolume)(THIS_ float *pfLevel) PURE;
    STDMETHOD_(HRESULT,GetMute)(THIS_ WINBOOL *pbMute) PURE;
    STDMETHOD_(HRESULT,SetMasterVolume)(THIS_ float fLevel,LPCGUID EventContext) PURE;
    STDMETHOD_(HRESULT,SetMute)(THIS_ WINBOOL bMute,LPCGUID EventContext) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ISimpleAudioVolume_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define ISimpleAudioVolume_AddRef(This) (This)->pVtbl->AddRef(This)
#define ISimpleAudioVolume_Release(This) (This)->pVtbl->Release(This)
#define ISimpleAudioVolume_GetMasterVolume(This,pfLevel) (This)->lpVtbl->GetMasterVolume(This,pfLevel)
#define ISimpleAudioVolume_GetMute(This,pbMute) (This)->lpVtbl->GetMute(This,pbMute)
#define ISimpleAudioVolume_SetMasterVolume(This,fLevel,EventContext) (This)->lpVtbl->SetMasterVolume(This,fLevel,EventContext)
#define ISimpleAudioVolume_SetMute(This,bMute,EventContext) (This)->lpVtbl->SetMute(This,bMute,EventContext)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)

#ifndef __IAudioClock2_FWD_DEFINED__
#define __IAudioClock2_FWD_DEFINED__
typedef struct IAudioClock2 IAudioClock2;
#endif

#ifndef __IAudioClockAdjustment_FWD_DEFINED__
#define __IAudioClockAdjustment_FWD_DEFINED__
typedef struct IAudioClockAdjustment IAudioClockAdjustment;
#endif

#undef  INTERFACE
#define INTERFACE IAudioClock2
DECLARE_INTERFACE_(IAudioClock2,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioClock2 methods */
    STDMETHOD_(HRESULT,GetDevicePosition)(THIS_ UINT64 *DevicePosition,UINT64 *QPCPosition) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioClock2_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioClock2_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioClock2_Release(This) (This)->pVtbl->Release(This)
#define IAudioClock2_GetDevicePosition(This,DevicePosition,QPCPosition) (This)->lpVtbl->GetDevicePosition(This,DevicePosition,QPCPosition)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IAudioClockAdjustment
DECLARE_INTERFACE_(IAudioClockAdjustment,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IAudioClockAdjustment methods */
    STDMETHOD_(HRESULT,SetSampleRate)(THIS_ float flSampleRate) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IAudioClockAdjustment_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IAudioClockAdjustment_AddRef(This) (This)->pVtbl->AddRef(This)
#define IAudioClockAdjustment_Release(This) (This)->pVtbl->Release(This)
#define IAudioClockAdjustment_SetSampleRate(This,flSampleRate) (This)->lpVtbl->SetSampleRate(This,flSampleRate)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /* __AUDIOCLIENT_H__ */
