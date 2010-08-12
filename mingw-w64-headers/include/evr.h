/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_EVR
#define _INC_EVR

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#if (_WIN32_WINNT >= 0x0601)
typedef enum _EVRFilterConfig_Prefs {
  EVRFilterConfigPrefs_EnableQoS   = 0x00000001,
  EVRFilterConfigPrefs_Mask        = 0x00000001
} EVRFilterConfigPrefs;
#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef enum MFVideoAspectRatioMode {
  MFVideoARMode_None               = 0x00000000,
  MFVideoARMode_PreservePicture    = 0x00000001,
  MFVideoARMode_PreservePixel      = 0x00000002,
  MFVideoARMode_NonLinearStretch   = 0x00000004,
  MFVideoARMode_Mask               = 0x00000007
} MFVideoAspectRatioMode;

#if (_WIN32_WINNT >= 0x0601)
typedef enum _MFVideoMixPrefs {
  MFVideoMixPrefs_ForceHalfInterlace         = 0x00000001,
  MFVideoMixPrefs_AllowDropToHalfInterlace   = 0x00000002,
  MFVideoMixPrefs_AllowDropToBob             = 0x00000004,
  MFVideoMixPrefs_ForceBob                   = 0x00000008,
  MFVideoMixPrefs_Mask                       = 0x0000000f
} MFVideoMixPrefs;
#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef enum MFVideoRenderPrefs {
  MFVideoRenderPrefs_DoNotRenderBorder       = 0x00000001,
  MFVideoRenderPrefs_DoNotClipToDevice       = 0x00000002,
  MFVideoRenderPrefs_AllowOutputThrottling   = 0x00000004,
  MFVideoRenderPrefs_ForceOutputThrottling   = 0x00000008,
  MFVideoRenderPrefs_ForceBatching           = 0x00000010,
  MFVideoRenderPrefs_AllowBatching           = 0x00000020,
  MFVideoRenderPrefs_ForceScaling            = 0x00000040,
  MFVideoRenderPrefs_AllowScaling            = 0x00000080,
  MFVideoRenderPrefs_DoNotRepaintOnStop      = 0x00000100,
  MFVideoRenderPrefs_Mask                    = 0x000001ff
} MFVideoRenderPrefs;

typedef enum _MFVP_MESSAGE_TYPE {
  MFVP_MESSAGE_FLUSH                 = 0x00000000,
  MFVP_MESSAGE_INVALIDATEMEDIATYPE   = 0x00000001,
  MFVP_MESSAGE_PROCESSINPUTNOTIFY    = 0x00000002,
  MFVP_MESSAGE_BEGINSTREAMING        = 0x00000003,
  MFVP_MESSAGE_ENDSTREAMING          = 0x00000004,
  MFVP_MESSAGE_ENDOFSTREAM           = 0x00000005,
  MFVP_MESSAGE_STEP                  = 0x00000006,
  MFVP_MESSAGE_CANCELSTEP            = 0x00000007
} MFVP_MESSAGE_TYPE;

typedef struct MFVideoNormalizedRect {
  float left;
  float top;
  float right;
  float bottom;
} MFVideoNormalizedRect;

#ifdef __cplusplus
}
#endif

#undef  INTERFACE
#define INTERFACE IMFVideoPresenter
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been unverified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFVideoPresenter,IMFClockStateSink)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFClockStateSink methods */
    STDMETHOD_(HRESULT,OnClockPause)(THIS_ MFTIME hnsSystemTime) PURE;
    STDMETHOD_(HRESULT,OnClockRestart)(THIS_ MFTIME hnsSystemTime) PURE;
    STDMETHOD_(HRESULT,OnClockSetRate)(THIS_ MFTIME hnsSystemTime,float flRate) PURE;
    STDMETHOD_(HRESULT,OnClockStart)(THIS_ MFTIME hnsSystemTime,LONGLONG llClockStartOffset) PURE;
    STDMETHOD_(HRESULT,OnClockStop)(THIS_ MFTIME hnssSystemTime) PURE;

    /* IMFVideoPresenter methods */
    STDMETHOD_(HRESULT,GetCurrentMediaType)(THIS_ IMFVideoMediaType **ppMediaType) PURE;
    STDMETHOD_(HRESULT,ProcessMessage)(THIS_ MFVP_MESSAGE_TYPE eMessage,ULONG_PTR ulParam) PURE;

    END_INTERFACE
};

#ifdef COBJMACROS
#define IMFVideoPresenter_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IMFVideoPresenter_AddRef(This) (This)->pVtbl->AddRef(This)
#define IMFVideoPresenter_Release(This) (This)->pVtbl->Release(This)
#define IMFVideoPresenter_OnClockPause(This,hnsSystemTime) (This)->lpVtbl->OnClockPause(This,hnsSystemTime)
#define IMFVideoPresenter_OnClockRestart(This,hnsSystemTime) (This)->lpVtbl->OnClockRestart(This,hnsSystemTime)
#define IMFVideoPresenter_OnClockSetRate(This,hnsSystemTime,flRate) (This)->lpVtbl->OnClockSetRate(This,hnsSystemTime,flRate)
#define IMFVideoPresenter_OnClockStart(This,hnsSystemTime,llClockStartOffset) (This)->lpVtbl->OnClockStart(This,hnsSystemTime,llClockStartOffset)
#define IMFVideoPresenter_OnClockStop(This,hnssSystemTime) (This)->lpVtbl->OnClockStop(This,hnssSystemTime)
#define IMFVideoPresenter_GetCurrentMediaType(This,ppMediaType) (This)->lpVtbl->GetCurrentMediaType(This,ppMediaType)
#define IMFVideoPresenter_ProcessMessage(This,eMessage,ulParam) (This)->lpVtbl->ProcessMessage(This,eMessage,ulParam)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFDesiredSample
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been unverified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFDesiredSample,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFDesiredSample methods */
    STDMETHOD(Clear)(THIS) PURE;
    STDMETHOD_(HRESULT,GetDesiredSampleTimeAndDuration)(THIS_ LONGLONG *phnsSampleTime,LONGLONG *phnsSampleDuration) PURE;
    STDMETHOD(SetDesiredSampleTimeAndDuration)(THIS_ LONGLONG hnsSampleTime,LONGLONG hnsSampleDuration) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFDesiredSample_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IMFDesiredSample_AddRef(This) (This)->pVtbl->AddRef(This)
#define IMFDesiredSample_Release(This) (This)->pVtbl->Release(This)
#define IMFDesiredSample_Clear() (This)->lpVtbl->Clear(This)
#define IMFDesiredSample_GetDesiredSampleTimeAndDuration(This,phnsSampleTime,phnsSampleDuration) (This)->lpVtbl->GetDesiredSampleTimeAndDuration(This,phnsSampleTime,phnsSampleDuration)
#define IMFDesiredSample_SetDesiredSampleTimeAndDuration(This,hnsSampleTime,hnsSampleDuration) (This)->lpVtbl->SetDesiredSampleTimeAndDuration(This,hnsSampleTime,hnsSampleDuration)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFTrackedSample
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been unverified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTrackedSample,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFTrackedSample methods */
    STDMETHOD_(HRESULT,SetAllocator)(THIS_ IMFAsyncCallback *pSampleAllocator,IUnknown *pUnkState) PURE;

    END_INTERFACE
};

#ifdef COBJMACROS
#define IMFTrackedSample_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTrackedSample_AddRef(This) (This)->pVtbl->AddRef(This)
#define IMFTrackedSample_Release(This) (This)->pVtbl->Release(This)
#define IMFTrackedSample_SetAllocator(This,pSampleAllocator,pUnkState) (This)->lpVtbl->SetAllocator(This,pSampleAllocator,pUnkState)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI MFCreateVideoMixer(IUnknown *pOwner,REFIID riidDevice,REFIID riid,void **ppVideoMixer);
HRESULT WINAPI MFCreateVideoMixerAndPresenter(IUnknown *pMixerOwner,IUnknown *pPresenterOwner,REFIID riidMixer,void **ppvVideoMixer,REFIID riidPresenter,void **ppvVideoPresenter);
HRESULT WINAPI MFCreateVideoPresenter(IUnknown *pOwner,REFIID riidDevice,REFIID riid,void **ppvVideoPresenter);
HRESULT WINAPI MFCreateVideoSampleAllocator(REFIID riid,void** ppSampleAllocator);
HRESULT WINAPI MFCreateVideoSampleFromSurface(IUnknown *pUnkSurface,IMFSample **ppSample);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /*_INC_EVR*/
