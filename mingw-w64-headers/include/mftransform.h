/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MFTRANSFORM
#define _INC_MFTRANSFORM

#include <mfidl.h>

#if (_WIN32_WINNT >= 0x0600)
/*Not supported.*/
  enum _MFT_DRAIN_TYPE {
    MFT_DRAIN_PRODUCE_TAILS   = 0x00000000,
    MFT_DRAIN_NO_TAILS        = 0x00000001 
  };

#if (_WIN32_WINNT >= 0x0601)
  enum _MFT_ENUM_FLAG {
  MFT_ENUM_FLAG_SYNCMFT          = 0x00000001,
  MFT_ENUM_FLAG_ASYNCMFT         = 0x00000002,
  MFT_ENUM_FLAG_HARDWARE         = 0x00000004,
  MFT_ENUM_FLAG_FIELDOFUSE       = 0x00000008,
  MFT_ENUM_FLAG_LOCALMFT         = 0x00000010,
  MFT_ENUM_FLAG_TRANSCODE_ONLY   = 0x00000020,
  MFT_ENUM_FLAG_SORTANDFILTER    = 0x00000040,
  MFT_ENUM_FLAG_ALL              = 0x0000003F 
};
#endif /*(_WIN32_WINNT >= 0x0601)*/

  enum _MFT_INPUT_STATUS_FLAGS {
    MFT_INPUT_STATUS_ACCEPT_DATA   = 0x00000001 
  };

  enum _MFT_INPUT_DATA_BUFFER_FLAGS {
    MFT_INPUT_DATA_BUFFER_PLACEHOLDER   = 0xFFFFFFFF 
  };

  enum _MFT_OUTPUT_STREAM_INFO_FLAGS {
    MFT_OUTPUT_STREAM_WHOLE_SAMPLES              = 0x00000001,
    MFT_OUTPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER   = 0x00000002,
    MFT_OUTPUT_STREAM_FIXED_SAMPLE_SIZE          = 0x00000004,
    MFT_OUTPUT_STREAM_DISCARDABLE                = 0x00000008,
    MFT_OUTPUT_STREAM_OPTIONAL                   = 0x00000010,
    MFT_OUTPUT_STREAM_PROVIDES_SAMPLES           = 0x00000100,
    MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES        = 0x00000200,
    MFT_OUTPUT_STREAM_LAZY_READ                  = 0x00000400,
    MFT_OUTPUT_STREAM_REMOVABLE                  = 0x00000800 
  };

  enum _MFT_OUTPUT_STATUS_FLAGS {
    MFT_OUTPUT_STATUS_SAMPLE_READY   = 0x00000001 
  };

  enum _MFT_OUTPUT_DATA_BUFFER_FLAGS {
    MFT_OUTPUT_DATA_BUFFER_INCOMPLETE      = 0x01000000,
    MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE   = 0x00000100,
    MFT_OUTPUT_DATA_BUFFER_STREAM_END      = 0x00000200,
    MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE       = 0x00000300 
  };

  enum _MFT_INPUT_STREAM_INFO_FLAGS {
    MFT_INPUT_STREAM_WHOLE_SAMPLES              = 0x00000001,
    MFT_INPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER   = 0x00000002,
    MFT_INPUT_STREAM_FIXED_SAMPLE_SIZE          = 0x00000004,
    MFT_INPUT_STREAM_HOLDS_BUFFERS              = 0x00000008,
    MFT_INPUT_STREAM_DOES_NOT_ADDREF            = 0x00000100,
    MFT_INPUT_STREAM_REMOVABLE                  = 0x00000200,
    MFT_INPUT_STREAM_OPTIONAL                   = 0x00000400,
    MFT_INPUT_STREAM_PROCESSES_IN_PLACE         = 0x00000800 
  };

  typedef enum _VSS_HARDWARE_OPTIONS {
    VSS_BREAKEX_FLAG_MASK_LUNS                      = 0x00000001,
    VSS_BREAKEX_FLAG_MAKE_READ_WRITE                = 0x00000002,
    VSS_BREAKEX_FLAG_REVERT_IDENTITY_ALL            = 0x00000004,
    VSS_BREAKEX_FLAG_REVERT_IDENTITY_NONE           = 0x00000008,
    VSS_ONLUNSTATECHANGE_NOTIFY_READ_WRITE          = 0x00000100,
    VSS_ONLUNSTATECHANGE_NOTIFY_LUN_PRE_RECOVERY    = 0x00000200,
    VSS_ONLUNSTATECHANGE_NOTIFY_LUN_POST_RECOVERY   = 0x00000400,
    VSS_ONLUNSTATECHANGE_DO_MASK_LUNS               = 0x00000800 
  } VSS_HARDWARE_OPTIONS, *PVSS_HARDWARE_OPTIONS;

  enum _MFT_SET_TYPE_FLAGS {
    MFT_SET_TYPE_TEST_ONLY   = 0x00000001 
  };

  enum _MFT_PROCESS_OUTPUT_STATUS {
    MFT_PROCESS_OUTPUT_STATUS_NEW_STREAMS   = 0x00000100 
  };

  enum _MFT_PROCESS_OUTPUT_FLAGS {
    MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER   = 0x00000001 
  };

typedef enum _MFT_MESSAGE_TYPE {
  MFT_MESSAGE_COMMAND_FLUSH            = 0x00000000,
  MFT_MESSAGE_COMMAND_DRAIN            = 0x00000001,
  MFT_MESSAGE_SET_D3D_MANAGER          = 0x00000002,
  MFT_MESSAGE_NOTIFY_BEGIN_STREAMING   = 0x10000000,
  MFT_MESSAGE_NOTIFY_END_STREAMING     = 0x10000001,
  MFT_MESSAGE_NOTIFY_END_OF_STREAM     = 0x10000002,
  MFT_MESSAGE_NOTIFY_START_OF_STREAM   = 0x10000003,
  MFT_MESSAGE_COMMAND_MARKER           = 0x20000000 
} MFT_MESSAGE_TYPE;

typedef struct _MFT_INPUT_STREAM_INFO {
  LONGLONG hnsMaxLatency;
  DWORD    dwFlags;
  DWORD    cbSize;
  DWORD    cbMaxLookahead;
  DWORD    cbAlignment;
} MFT_INPUT_STREAM_INFO;

typedef struct _MFT_OUTPUT_STREAM_INFO {
  DWORD dwFlags;
  DWORD cbSize;
  DWORD cbAlignment;
} MFT_OUTPUT_STREAM_INFO;

typedef struct _MFT_OUTPUT_DATA_BUFFER {
  DWORD         dwStreamID;
  IMFSample     *pSample;
  DWORD         dwStatus;
  IMFCollection *pEvents;
} MFT_OUTPUT_DATA_BUFFER;

#undef  INTERFACE
#define INTERFACE IMFTransform
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTransform,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFTransform methods */
    STDMETHOD_(HRESULT,AddInputStreams)(THIS_ DWORD cStreams,DWORD *adwStreamIDs) PURE;
    STDMETHOD_(HRESULT,DeleteInputStream)(THIS_ DWORD dwStreamID) PURE;
    STDMETHOD_(HRESULT,GetAttributes)(THIS_ IMFAttributes **pAttributes) PURE;
    STDMETHOD_(HRESULT,GetInputAvailableType)(THIS_ DWORD dwInputStreamID,DWORD dwTypeIndex,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetInputCurrentType)(THIS_ DWORD dwInputStreamID,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetInputStatus)(THIS_ DWORD dwInputStreamID,DWORD *pdwFlags) PURE;
    STDMETHOD_(HRESULT,GetInputStreamAttributes)(THIS_ DWORD dwInputStreamID,IMFAttributes **ppAttributes) PURE;
    STDMETHOD_(HRESULT,GetInputStreamInfo)(THIS_ DWORD dwInputStreamID,MFT_INPUT_STREAM_INFO *pStreamInfo) PURE;
    STDMETHOD_(HRESULT,GetOutputAvailableType)(THIS_ DWORD dwOutputStreamID,DWORD dwTypeIndex,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetOutputCurrentType)(THIS_ DWORD dwOutputStreamID,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetOutputStatus)(THIS_ DWORD *pdwFlags) PURE;
    STDMETHOD_(HRESULT,GetOutputStreamAttributes)(THIS_ DWORD dwOutputStreamID,IMFAttributes **ppAttributes) PURE;
    STDMETHOD_(HRESULT,GetOutputStreamInfo)(THIS_ DWORD dwOutputStreamID,MFT_OUTPUT_STREAM_INFO *pStreamInfo) PURE;
    STDMETHOD_(HRESULT,GetStreamCount)(THIS_ DWORD *pcInputStreams,DWORD *pcOutputStreams) PURE;
    STDMETHOD_(HRESULT,GetStreamIDs)(THIS_ DWORD dwInputIDArraySize,DWORD *pdwInputIDs,DWORD dwOutputIDArraySize,DWORD *pdwOutputIDs) PURE;
    STDMETHOD_(HRESULT,GetStreamLimits)(THIS_ DWORD *pdwInputMinimum,DWORD *pdwInputMaximum,DWORD *pdwOutputMinimum,DWORD *pdwOutputMaximum) PURE;
    STDMETHOD_(HRESULT,ProcessEvent)(THIS_ DWORD dwInputStreamID,IMFMediaEvent *pEvent) PURE;
    STDMETHOD_(HRESULT,ProcessInput)(THIS_ DWORD dwInputStreamID,IMFSample *pSample,DWORD dwFlags) PURE;
    STDMETHOD_(HRESULT,ProcessMessage)(THIS_ MFT_MESSAGE_TYPE eMessage,ULONG_PTR ulParam) PURE;
    STDMETHOD_(HRESULT,ProcessOutput)(THIS_ DWORD dwFlags,DWORD cOutputBufferCount,MFT_OUTPUT_DATA_BUFFER *pOutputSamples,DWORD *pdwStatus) PURE;
    STDMETHOD_(HRESULT,SetInputType)(THIS_ DWORD dwInputStreamID,IMFMediaType *pType,DWORD dwFlags) PURE;
    STDMETHOD_(HRESULT,SetOutputBounds)(THIS_ LONGLONG hnsLowerBound,LONGLONG hnsUpperBound) PURE;
    STDMETHOD_(HRESULT,SetOutputType)(THIS_ DWORD dwOutputStreamID,IMFMediaType *pType,DWORD dwFlags) PURE;

    END_INTERFACE
};

#ifdef COBJMACROS
#define IMFTransform_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTransform_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTransform_Release(This) (This)->lpVtbl->Release(This)
#define IMFTransform_AddInputStreams(This,cStreams,adwStreamIDs) (This)->lpVtbl->AddInputStreams(This,cStreams,adwStreamIDs)
#define IMFTransform_DeleteInputStream(This,dwStreamID) (This)->lpVtbl->DeleteInputStream(This,dwStreamID)
#define IMFTransform_GetAttributes(This,pAttributes) (This)->lpVtbl->GetAttributes(This,pAttributes)
#define IMFTransform_GetInputAvailableType(This,dwInputStreamID,dwTypeIndex,ppType) (This)->lpVtbl->GetInputAvailableType(This,dwInputStreamID,dwTypeIndex,ppType)
#define IMFTransform_GetInputCurrentType(This,dwInputStreamID,ppType) (This)->lpVtbl->GetInputCurrentType(This,dwInputStreamID,ppType)
#define IMFTransform_GetInputStatus(This,dwInputStreamID,pdwFlags) (This)->lpVtbl->GetInputStatus(This,dwInputStreamID,pdwFlags)
#define IMFTransform_GetInputStreamAttributes(This,dwInputStreamID,ppAttributes) (This)->lpVtbl->GetInputStreamAttributes(This,dwInputStreamID,ppAttributes)
#define IMFTransform_GetInputStreamInfo(This,dwInputStreamID,pStreamInfo) (This)->lpVtbl->GetInputStreamInfo(This,dwInputStreamID,pStreamInfo)
#define IMFTransform_GetOutputAvailableType(This,dwOutputStreamID,dwTypeIndex,ppType) (This)->lpVtbl->GetOutputAvailableType(This,dwOutputStreamID,dwTypeIndex,ppType)
#define IMFTransform_GetOutputCurrentType(This,dwOutputStreamID,ppType) (This)->lpVtbl->GetOutputCurrentType(This,dwOutputStreamID,ppType)
#define IMFTransform_GetOutputStatus(This,pdwFlags) (This)->lpVtbl->GetOutputStatus(This,pdwFlags)
#define IMFTransform_GetOutputStreamAttributes(This,dwOutputStreamID,ppAttributes) (This)->lpVtbl->GetOutputStreamAttributes(This,dwOutputStreamID,ppAttributes)
#define IMFTransform_GetOutputStreamInfo(This,dwOutputStreamID,pStreamInfo) (This)->lpVtbl->GetOutputStreamInfo(This,dwOutputStreamID,pStreamInfo)
#define IMFTransform_GetStreamCount(This,pcInputStreams,pcOutputStreams) (This)->lpVtbl->GetStreamCount(This,pcInputStreams,pcOutputStreams)
#define IMFTransform_GetStreamIDs(This,dwInputIDArraySize,pdwInputIDs,dwOutputIDArraySize,pdwOutputIDs) (This)->lpVtbl->GetStreamIDs(This,dwInputIDArraySize,pdwInputIDs,dwOutputIDArraySize,pdwOutputIDs)
#define IMFTransform_GetStreamLimits(This,pdwInputMinimum,pdwInputMaximum,pdwOutputMinimum,pdwOutputMaximum) (This)->lpVtbl->GetStreamLimits(This,pdwInputMinimum,pdwInputMaximum,pdwOutputMinimum,pdwOutputMaximum)
#define IMFTransform_ProcessEvent(This,dwInputStreamID,pEvent) (This)->lpVtbl->ProcessEvent(This,dwInputStreamID,pEvent)
#define IMFTransform_ProcessInput(This,dwInputStreamID,pSample,dwFlags) (This)->lpVtbl->ProcessInput(This,dwInputStreamID,pSample,dwFlags)
#define IMFTransform_ProcessMessage(This,eMessage,ulParam) (This)->lpVtbl->ProcessMessage(This,eMessage,ulParam)
#define IMFTransform_ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputSamples,pdwStatus) (This)->lpVtbl->ProcessOutput(This,dwFlags,cOutputBufferCount,pOutputSamples,pdwStatus)
#define IMFTransform_SetInputType(This,dwInputStreamID,pType,dwFlags) (This)->lpVtbl->SetInputType(This,dwInputStreamID,pType,dwFlags)
#define IMFTransform_SetOutputBounds(This,hnsLowerBound,hnsUpperBound) (This)->lpVtbl->SetOutputBounds(This,hnsLowerBound,hnsUpperBound)
#define IMFTransform_SetOutputType(This,dwOutputStreamID,pType,dwFlags) (This)->lpVtbl->SetOutputType(This,dwOutputStreamID,pType,dwFlags)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
extern "C" {
#endif
HRESULT WINAPI MFCreateTransformActivate(IMFActivate **ppActivate);
#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /*_INC_MFTRANSFORM*/
