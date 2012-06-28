/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MFREADWRITE
#define _INC_MFREADWRITE

#if (_WIN32_WINNT >= 0x0601)

typedef enum MF_SOURCE_READER_FLAG {
  MF_SOURCE_READERF_ERROR                     = 0x00000001,
  MF_SOURCE_READERF_ENDOFSTREAM               = 0x00000002,
  MF_SOURCE_READERF_NEWSTREAM                 = 0x00000004,
  MF_SOURCE_READERF_NATIVEMEDIATYPECHANGED    = 0x00000010,
  MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED   = 0x00000020,
  MF_SOURCE_READERF_STREAMTICK                = 0x00000100 
} MF_SOURCE_READER_FLAG;

typedef struct _MF_SINK_WRITER_STATISTICS {
  DWORD    cb;
  LONGLONG llLastTimestampReceived;
  LONGLONG llLastTimestampEncoded;
  LONGLONG llLastTimestampProcessed;
  LONGLONG llLastStreamTickReceived;
  LONGLONG llLastSinkSampleRequest;
  QWORD    qwNumSamplesReceived;
  QWORD    qwNumSamplesEncoded;
  QWORD    qwNumSamplesProcessed;
  QWORD    qwNumStreamTicksReceived;
  DWORD    dwByteCountQueued;
  QWORD    qwByteCountProcessed;
  DWORD    dwNumOutstandingSinkSampleRequests;
  DWORD    dwAverageSampleRateReceived;
  DWORD    dwAverageSampleRateEncoded;
  DWORD    dwAverageSampleRateProcessed;
} MF_SINK_WRITER_STATISTICS;

#undef  INTERFACE
#define INTERFACE IMFSinkWriter
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSinkWriter,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFSinkWriter methods */
    STDMETHOD_(HRESULT,AddStream)(THIS_ IMFMediaType *pTargetMediaType,DWORD *pdwStreamIndex) PURE;
    STDMETHOD_(HRESULT,BeginWriting)(THIS) PURE;
    STDMETHOD_(HRESULT,Finalize)(THIS) PURE;
    STDMETHOD_(HRESULT,Flush)(THIS_ DWORD dwStreamIndex) PURE;
    STDMETHOD_(HRESULT,GetServiceForStream)(THIS_ DWORD dwStreamIndex,REFGUID guidService,REFIID riid,LPVOID *ppvObject) PURE;
    STDMETHOD_(HRESULT,GetStatistics)(THIS_ DWORD dwStreamIndex,MF_SINK_WRITER_STATISTICS *pStats) PURE;
    STDMETHOD_(HRESULT,NotifyEndOfSegment)(THIS_ DWORD dwStreamIndex) PURE;
    STDMETHOD_(HRESULT,PlaceMarker)(THIS_ DWORD dwStreamIndex,LPVOID pvContext) PURE;
    STDMETHOD_(HRESULT,SendStreamTick)(THIS_ DWORD dwStreamIndex,LONGLONG llTimestamp) PURE;
    STDMETHOD_(HRESULT,SetInputMediaType)(THIS_ DWORD dwStreamIndex,IMFMediaType *pInputMediaType,IMFAttributes *pEncodingParameters) PURE;
    STDMETHOD_(HRESULT,WriteSample)(THIS_ DWORD dwStreamIndex,IMFSample *pSample) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSinkWriter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSinkWriter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSinkWriter_Release(This) (This)->lpVtbl->Release(This)
#define IMFSinkWriter_AddStream(This,pTargetMediaType,pdwStreamIndex) (This)->lpVtbl->AddStream(This,pTargetMediaType,pdwStreamIndex)
#define IMFSinkWriter_BeginWriting() (This)->lpVtbl->BeginWriting(This)
#define IMFSinkWriter_Finalize() (This)->lpVtbl->Finalize(This)
#define IMFSinkWriter_Flush(This,dwStreamIndex) (This)->lpVtbl->Flush(This,dwStreamIndex)
#define IMFSinkWriter_GetServiceForStream(This,dwStreamIndex,guidService,riid,ppvObject) (This)->lpVtbl->GetServiceForStream(This,dwStreamIndex,guidService,riid,ppvObject)
#define IMFSinkWriter_GetStatistics(This,dwStreamIndex,pStats) (This)->lpVtbl->GetStatistics(This,dwStreamIndex,pStats)
#define IMFSinkWriter_NotifyEndOfSegment(This,dwStreamIndex) (This)->lpVtbl->NotifyEndOfSegment(This,dwStreamIndex)
#define IMFSinkWriter_PlaceMarker(This,dwStreamIndex,pvContext) (This)->lpVtbl->PlaceMarker(This,dwStreamIndex,pvContext)
#define IMFSinkWriter_SendStreamTick(This,dwStreamIndex,llTimestamp) (This)->lpVtbl->SendStreamTick(This,dwStreamIndex,llTimestamp)
#define IMFSinkWriter_SetInputMediaType(This,dwStreamIndex,pInputMediaType,pEncodingParameters) (This)->lpVtbl->SetInputMediaType(This,dwStreamIndex,pInputMediaType,pEncodingParameters)
#define IMFSinkWriter_WriteSample(This,dwStreamIndex,pSample) (This)->lpVtbl->WriteSample(This,dwStreamIndex,pSample)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSourceReader
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSourceReader,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFSourceReader methods */
    STDMETHOD_(HRESULT,Flush)(THIS_ DWORD dwStreamIndex) PURE;
    STDMETHOD_(HRESULT,GetCurrentMediaType)(THIS_ DWORD dwStreamIndex,IMFMediaType **ppMediaType) PURE;
    STDMETHOD_(HRESULT,GetNativeMediaType)(THIS_ DWORD dwStreamIndex,DWORD dwMediaTypeIndex,IMFMediaType **ppMediaType) PURE;
    STDMETHOD_(HRESULT,GetPresentationAttribute)(THIS_ DWORD dwStreamIndex,REFGUID guidAttribute,PROPVARIANT *pvarAttribute) PURE;
    STDMETHOD_(HRESULT,GetServiceForStream)(THIS_ DWORD dwStreamIndex,REFGUID guidService,REFIID riid,LPVOID *ppvObject) PURE;
    STDMETHOD_(HRESULT,GetStreamSelection)(THIS_ DWORD dwStreamIndex,BOOL *pfSelected) PURE;
    STDMETHOD_(HRESULT,ReadSample)(THIS_ DWORD dwStreamIndex,DWORD dwControlFlags,DWORD *pdwActualStreamIndex,DWORD *pdwStreamFlags,LONGLONG *pllTimestamp,IMFSample **ppSample) PURE;
    STDMETHOD_(HRESULT,SetCurrentMediaType)(THIS_ DWORD dwStreamIndex,DWORD *pdwReserved,IMFMediaType *pMediaType) PURE;
    STDMETHOD_(HRESULT,SetCurrentPosition)(THIS_ REFGUID guidTimeFormat,REFPROPVARIANT varPosition) PURE;
    STDMETHOD_(HRESULT,SetStreamSelection)(THIS_ DWORD dwStreamIndex,BOOL fSelected) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSourceReader_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSourceReader_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSourceReader_Release(This) (This)->lpVtbl->Release(This)
#define IMFSourceReader_Flush(This,dwStreamIndex) (This)->lpVtbl->Flush(This,dwStreamIndex)
#define IMFSourceReader_GetCurrentMediaType(This,dwStreamIndex,ppMediaType) (This)->lpVtbl->GetCurrentMediaType(This,dwStreamIndex,ppMediaType)
#define IMFSourceReader_GetNativeMediaType(This,dwStreamIndex,dwMediaTypeIndex,ppMediaType) (This)->lpVtbl->GetNativeMediaType(This,dwStreamIndex,dwMediaTypeIndex,ppMediaType)
#define IMFSourceReader_GetPresentationAttribute(This,dwStreamIndex,guidAttribute,pvarAttribute) (This)->lpVtbl->GetPresentationAttribute(This,dwStreamIndex,guidAttribute,pvarAttribute)
#define IMFSourceReader_GetServiceForStream(This,dwStreamIndex,guidService,riid,ppvObject) (This)->lpVtbl->GetServiceForStream(This,dwStreamIndex,guidService,riid,ppvObject)
#define IMFSourceReader_GetStreamSelection(This,dwStreamIndex,pfSelected) (This)->lpVtbl->GetStreamSelection(This,dwStreamIndex,pfSelected)
#define IMFSourceReader_ReadSample(This,dwStreamIndex,dwControlFlags,pdwActualStreamIndex,pdwStreamFlags,pllTimestamp,ppSample) (This)->lpVtbl->ReadSample(This,dwStreamIndex,dwControlFlags,pdwActualStreamIndex,pdwStreamFlags,pllTimestamp,ppSample)
#define IMFSourceReader_SetCurrentMediaType(This,dwStreamIndex,pdwReserved,pMediaType) (This)->lpVtbl->SetCurrentMediaType(This,dwStreamIndex,pdwReserved,pMediaType)
#define IMFSourceReader_SetCurrentPosition(This,guidTimeFormat,varPosition) (This)->lpVtbl->SetCurrentPosition(This,guidTimeFormat,varPosition)
#define IMFSourceReader_SetStreamSelection(This,dwStreamIndex,fSelected) (This)->lpVtbl->SetStreamSelection(This,dwStreamIndex,fSelected)
#endif /*COBJMACROS*/

#define MF_SOURCE_READER_FIRST_VIDEO_STREAM 0xFFFFFFFC
#define MF_SOURCE_READER_FIRST_AUDIO_STREAM 0xFFFFFFFD
#define MF_SOURCE_READER_ALL_STREAMS        0xFFFFFFFE
#define MF_SOURCE_READER_MEDIASOURCE        0xFFFFFFFF

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI MFCreateSinkWriterFromMediaSink(IMFMediaSink *pMediaSink,IMFAttributes *pAttributes,IMFSinkWriter **ppSinkWriter);
HRESULT WINAPI MFCreateSinkWriterFromURL(LPCWSTR pwszOutputURL,IMFByteStream *pByteStream,IMFAttributes *pAttributes,IMFSinkWriter **ppSinkWriter);
HRESULT WINAPI MFCreateSourceReaderFromByteStream(IMFByteStream *pByteStream,IMFAttributes *pAttributes,IMFSourceReader **ppSourceReader);
HRESULT WINAPI MFCreateSourceReaderFromMediaSource(IMFMediaSource *pMediaSource,IMFAttributes *pAttributes,IMFSourceReader **ppSourceReader);
HRESULT WINAPI MFCreateSourceReaderFromURL(LPCWSTR pwszURL,IMFAttributes *pAttributes,IMFSourceReader **ppSourceReader);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*_INC_MFREADWRITE*/
