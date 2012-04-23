/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MFAPI
#define _INC_MFAPI
#include <dshow.h>
#include <dvdmedia.h>
#include <opmapi.h>
#include <propsys.h>
#include <ksmedia.h>

#if (_WIN32_WINNT >= 0x0600)
/*ksmedia.h needs fixing about "multi-character character constant"*/
typedef struct _MFT_REGISTRATION_INFO MFT_REGISTRATION_INFO;
typedef struct IMFActivate IMFActivate;
typedef enum _EAllocationType { eAllocationTypeIgnore } EAllocationType; /*Unknown type*/

typedef enum  {
  MF_TOPOSTATUS_INVALID           = 0,
  MF_TOPOSTATUS_READY             = 100,
  MF_TOPOSTATUS_STARTED_SOURCE    = 200,
  MF_TOPOSTATUS_DYNAMIC_CHANGED   = 210,
  MF_TOPOSTATUS_SINK_SWITCHED     = 300,
  MF_TOPOSTATUS_ENDED             = 400 
} MF_TOPOSTATUS;

typedef enum _MFVideoDRMFlags {
  MFVideoDRMFlag_None                 = 0,
  MFVideoDRMFlag_AnalogProtected      = 1,
  MFVideoDRMFlag_DigitallyProtected   = 2 
} MFVideoDRMFlags;


#if (_WIN32_WINNT >= 0x0601)

typedef enum  {
  MF_STANDARD_WORKQUEUE   = 0,
  MF_WINDOW_WORKQUEUE     = 1 
} MFASYNC_WORKQUEUE_TYPE;
#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef enum _MFVideoPadFlags {
  MFVideoPadFlag_PAD_TO_None   = 0,
  MFVideoPadFlag_PAD_TO_4x3    = 1,
  MFVideoPadFlag_PAD_TO_16x9   = 2 
} MFVideoPadFlags;

typedef enum _MFVideoSrcContentHintFlags {
  MFVideoSrcContentHintFlag_None    = 0,
  MFVideoSrcContentHintFlag_16x9    = 1,
  MFVideoSrcContentHintFlag_235_1   = 2 
} MFVideoSrcContentHintFlags;

typedef enum _MFWaveFormatExConvertFlags {
  MFWaveFormatExConvertFlag_Normal            = 0,
  MFWaveFormatExConvertFlag_ForceExtensible   = 1 
} MFWaveFormatExConvertFlags;

#if (_WIN32_WINNT >= 0x0601)
#undef  INTERFACE
#define INTERFACE IMFLocalMFTRegistration
DECLARE_INTERFACE_(IMFLocalMFTRegistration,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFLocalMFTRegistration methods */
    STDMETHOD_(HRESULT,RegisterMFTs)(THIS_ MFT_REGISTRATION_INFO *pMFTs,DWORD cMFTs) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFLocalMFTRegistration_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFLocalMFTRegistration_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFLocalMFTRegistration_Release(This) (This)->lpVtbl->Release(This)
#define IMFLocalMFTRegistration_RegisterMFTs(This,pMFTs,cMFTs) (This)->lpVtbl->RegisterMFTs(This,pMFTs,cMFTs)
#endif /*COBJMACROS*/
#endif /*(_WIN32_WINNT >= 0x0601)*/

#ifdef __cplusplus
typedef struct tagMFASYNCRESULT : public IMFAsyncResult {
  OVERLAPPED       overlapped;
  IMFAsyncCallback *pCallback;
  HRESULT          hrStatusResult;
  DWORD            dwBytesTransferred;
  HANDLE           hEvent;
} MFASYNCRESULT;
#endif

typedef struct _MFT_REGISTER_TYPE_INFO {
  GUID guidMajorType;
  GUID guidSubtype;
} MFT_REGISTER_TYPE_INFO;

typedef struct _MFFOLDDOWN_MATRIX {
  UINT32 cbSize;
  UINT32 cSrcChannels;
  UINT32 cDstChannels;
  UINT32 dwChannelMask;
  LONG   Coeff[64];
} MFFOLDDOWN_MATRIX;

typedef struct _MT_CUSTOM_VIDEO_PRIMARIES {
  float fRx;
  float fRy;
  float fGx;
  float fGy;
  float fBx;
  float fBy;
  float fWx;
  float fWy;
} MT_CUSTOM_VIDEO_PRIMARIES;

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*MFPERIODICCALLBACK )(IUnknown *pContext);
typedef ULONGLONG MFWORKITEM_KEY;

HRESULT WINAPI MFAddPeriodicCallback(MFPERIODICCALLBACK Callback,IUnknown *pContext,DWORD *pdwKey);
HRESULT WINAPI MFRemovePeriodicCallback(DWORD dwKey);
HRESULT WINAPI MFAllocateWorkQueue(DWORD *pdwWorkQueue);
HRESULT WINAPI MFAllocateWorkQueueEx(MFASYNC_WORKQUEUE_TYPE WorkQueueType,DWORD *pdwWorkQueue);
HRESULT WINAPI MFAverageTimePerFrameToFrameRate(UINT64 unAverageTimePerFrame,UINT32 *punNumerator,UINT32 *punDenominator);
HRESULT WINAPI MFBeginCreateFile(MF_FILE_ACCESSMODE AccessMode,MF_FILE_OPENMODE OpenMode,MF_FILE_FLAGS fFlags,LPCWSTR pwszFilePath,IMFAsyncCallback *pCallback,IUnknown *pState,IUnknown **ppCancelCookie);
HRESULT WINAPI MFBeginUnregisterWorkQueueWithMMCSS(DWORD dwWorkQueueId,IMFAsyncCallback *pDoneCallback,IUnknown *pDoneState);
HRESULT WINAPI MFBeginRegisterWorkQueueWithMMCSS(DWORD dwWorkQueueId,LPCWSTR wszClass,DWORD dwTaskId,IMFAsyncCallback *pDoneCallback,IUnknown *pDoneState);
HRESULT WINAPI MFBeginCreateFile(MF_FILE_ACCESSMODE AccessMode,MF_FILE_OPENMODE OpenMode,MF_FILE_FLAGS fFlags,LPCWSTR pwszFilePath,IMFAsyncCallback *pCallback,IUnknown *pState,IUnknown **ppCancelCookie);
HRESULT WINAPI MFCalculateBitmapImageSize(const BITMAPINFOHEADER *pBMIH,UINT32 cbBufSize,UINT32 *pcbImageSize,WINBOOL *pbKnown);
HRESULT WINAPI MFCalculateImageSize(REFGUID guidSubtype,UINT32 unWidth,UINT32 unHeight,UINT32 *pcbImageSize);
HRESULT WINAPI MFCancelCreateFile(IUnknown *pCancelCookie);
HRESULT WINAPI MFCancelWorkItem(MFWORKITEM_KEY Key);
WINBOOL WINAPI MFCompareFullToPartialMediaType(IMFMediaType *pMFTypeFull,IMFMediaType *pMFTypePartial);
HRESULT WINAPI MFConvertColorInfoFromDXVA(MFVIDEOFORMAT *pToFormat,DWORD dwFromDXVA);
HRESULT WINAPI MFConvertColorInfoToDXVA(DWORD *pdwToDXVA,const MFVIDEOFORMAT *pFromFormat);
HRESULT WINAPI MFConvertFromFP16Array(float *pDest,const WORD *pSrc,DWORD dwCount);
HRESULT WINAPI MFConvertToFP16Array(WORD *pDest,const float *pSrc,DWORD dwCount);
HRESULT WINAPI MFCopyImage(BYTE *pDest,LONG lDestStride,const BYTE *pSrc,LONG lSrcStride,DWORD dwWidthInBytes,DWORD dwLines);
HRESULT WINAPI MFCreateAudioMediaType(const WAVEFORMATEX *pAudioFormat,IMFAudioMediaType **ppIAudioMediaType);
HRESULT WINAPI MFCreateDXSurfaceBuffer(REFIID riid,IUnknown *punkSurface,BOOL fBottomUpWhenLinear,IMFMediaBuffer **ppBuffer);
HRESULT WINAPI MFCreateMediaType(IMFMediaType **ppMFType);
HRESULT WINAPI MFCreateMediaBufferWrapper(IMFMediaBuffer *pBuffer,DWORD cbOffset,DWORD dwLength,IMFMediaBuffer **ppBuffer);
HRESULT WINAPI MFCreateMediaTypeFromRepresentation(GUID guidRepresentation,LPVOID pvRepresentation,IMFMediaType **ppIMediaType);
HRESULT WINAPI MFCreateMemoryBuffer(DWORD cbMaxLength,IMFMediaBuffer **ppBuffer);
HRESULT WINAPI MFCreateMFVideoFormatFromMFMediaType(IMFMediaType *pMFType,MFVIDEOFORMAT **ppMFVF,UINT32 *pcbSize);
HRESULT WINAPI MFCreateSample(IMFSample **ppIMFSample);
HRESULT WINAPI MFCreateAsyncResult(IUnknown *punkObject,IMFAsyncCallback *pCallback,IUnknown *punkState,IMFAsyncResult **ppAsyncResult);
HRESULT WINAPI MFCreateFile(MF_FILE_ACCESSMODE AccessMode,MF_FILE_OPENMODE OpenMode,MF_FILE_FLAGS fFlags,LPCWSTR pwszFileURL,IMFByteStream **ppIByteStream);
HRESULT WINAPI MFCreateTempFile(MF_FILE_ACCESSMODE AccessMode,MF_FILE_OPENMODE OpenMode,MF_FILE_FLAGS fFlags,IMFByteStream **ppIByteStream);
HRESULT WINAPI MFInitMediaTypeFromWaveFormatEx(IMFMediaType *pMFType,const WAVEFORMATEX *pWaveFormat,UINT32 cbBufSize);
HRESULT WINAPI MFCreateVideoMediaType(const MFVIDEOFORMAT *pVideoFormat,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateVideoMediaTypeFromBitMapInfoHeader(const BITMAPINFOHEADER *pbmihBitMapInfoHeader,DWORD dwPixelAspectRatioX,DWORD dwPixelAspectRatioY,MFVideoInterlaceMode InterlaceMode,QWORD VideoFlags,QWORD qwFramesPerSecondNumerator,QWORD qwFramesPerSecondDenominator,DWORD dwMaxBitRate,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateVideoMediaTypeFromBitMapInfoHeaderEx(const BITMAPINFOHEADER *pbmihBitMapInfoHeader,UINT32 cbBitMapInfoHeader,DWORD dwPixelAspectRatioX,DWORD dwPixelAspectRatioY,MFVideoInterlaceMode InterlaceMode,QWORD VideoFlags,DWORD dwFramesPerSecondNumerator,DWORD dwFramesPerSecondDenominator,DWORD dwMaxBitRate,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateVideoMediaTypeFromSubtype(const GUID *pAMSubtype,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateVideoMediaTypeFromVideoInfoHeader(const KS_VIDEOINFOHEADER *pVideoInfoHeader,DWORD cbVideoInfoHeader,DWORD dwPixelAspectRatioX,DWORD dwPixelAspectRatioY,MFVideoInterlaceMode InterlaceMode,QWORD VideoFlags,const GUID *pSubtype,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateVideoMediaTypeFromVideoInfoHeader2(const KS_VIDEOINFOHEADER2 *pVideoInfoHeader,DWORD cbVideoInfoHeader,QWORD AdditionalVideoFlags,const GUID *pSubtype,IMFVideoMediaType **ppIVideoMediaType);
HRESULT WINAPI MFCreateWMAEncoderActivate(IMFMediaType *pMediaType,IPropertyStore *pEncodingConfigurationProperties,IMFActivate **ppActivate);
HRESULT WINAPI MFEndCreateFile(IMFAsyncResult *pResult,IMFByteStream **ppFile);
HRESULT WINAPI MFEndRegisterWorkQueueWithMMCSS(IMFAsyncResult *pResult,DWORD *pdwTaskId);
HRESULT WINAPI MFEndUnregisterWorkQueueWithMMCSS(IMFAsyncResult *pResult);
HRESULT WINAPI MFFrameRateToAverageTimePerFrame(UINT32 unNumerator,UINT32 unDenominator,UINT64 *punAverageTimePerFrame);
double WINAPI MFGetAttributeDouble(IMFAttributes *pAttributes,REFGUID guidKey,double fDefault);
HRESULT WINAPI MFGetAttributeRatio(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 *pnNumerator,UINT32 *punDenominator);
HRESULT WINAPI MFGetAttributesAsBlob(IMFAttributes *pAttributes,UINT8 *pBuf,UINT cbBufSize);
HRESULT WINAPI MFGetAttributesAsBlobSize(IMFAttributes *pAttributes,UINT32 *pcbBufSize);
HRESULT WINAPI MFGetAttributeSize(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 *punWidth,UINT32 *punHeight);
UINT32 WINAPI MFGetAttributeUINT32(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 unDefault);
UINT64 WINAPI MFGetAttributeUINT64(IMFAttributes *pAttributes,REFGUID guidKey,UINT64 unDefault);
HRESULT WINAPI MFGetPlaneSize(DWORD format,DWORD dwWidth,DWORD dwHeight,DWORD *pdwPlaneSize);
HRESULT WINAPI MFGetStrideForBitmapInfoHeader(DWORD format,DWORD dwWidth,LONG *pStride);
HRESULT WINAPI MFGetTimerPeriodicity(DWORD *Periodicity);
DWORD WINAPI MFGetUncompressedVideoFormat(const MFVIDEOFORMAT *pVideoFormat);
HRESULT WINAPI MFGetWorkQueueMMCSSClass(DWORD dwWorkQueueId,LPWSTR pwszClass,DWORD *pcchClass);
HRESULT WINAPI MFGetWorkQueueMMCSSTaskId(DWORD dwWorkQueueId,LPDWORD pdwTaskId);
void* WINAPI MFHeapAlloc(size_t nSize,ULONG dwFlags,char *pszFile,int line,EAllocationType eat);
void WINAPI MFHeapFree(void *pv);
HRESULT WINAPI MFInitAMMediaTypeFromMFMediaType(IMFMediaType *pMFType,GUID guidFormatBlockType,AM_MEDIA_TYPE *pAMType);
HRESULT WINAPI MFInitAttributesFromBlob(IMFAttributes *pAttributes,const UINT8 *pBuf,UINT cbBufSize);
HRESULT WINAPI MFInitMediaTypeFromAMMediaType(IMFMediaType *pMFType,const AM_MEDIA_TYPE *pAMType);
HRESULT WINAPI MFInitMediaTypeFromMFVideoFormat(IMFMediaType *pMFType,const MFVIDEOFORMAT *pMFVF,UINT32 cbBufSize);
HRESULT WINAPI MFInitVideoFormat(MFVIDEOFORMAT *pVideoFormat,MFStandardVideoFormat type);
HRESULT WINAPI MFInitVideoFormat_RGB(MFVIDEOFORMAT *pVideoFormat,DWORD dwWidth,DWORD dwHeight,DWORD D3Dfmt);
HRESULT WINAPI MFInvokeCallback(IMFAsyncResult *pAsyncResult);
WINBOOL WINAPI MFIsFormatYUV(DWORD Format);
HRESULT WINAPI MFLockPlatform(void);
HRESULT WINAPI MFLockWorkQueue(DWORD dwWorkQueue);
HRESULT WINAPI MFPutWorkItem(DWORD dwQueue,IMFAsyncCallback *pCallback,IUnknown *pState);
HRESULT WINAPI MFPutWorkItemEx(DWORD dwQueue,IMFAsyncResult *pResult);
HRESULT WINAPI MFRemovePeriodicCallback(DWORD dwKey);
HRESULT WINAPI MFRequireProtectedEnvironment(IMFPresentationDescriptor *pPresentationDescriptor);
HRESULT WINAPI MFScheduleWorkItem(IMFAsyncCallback *pCallback,IUnknown *pState,INT64 Timeout,MFWORKITEM_KEY *pKey);
HRESULT WINAPI MFScheduleWorkItemEx(IMFAsyncResult *pResult,INT64 Timeout,MFWORKITEM_KEY *pKey);
HRESULT WINAPI MFSerializePresentationDescriptor(IMFPresentationDescriptor *pPD,DWORD *pcbData,BYTE **ppbData);
HRESULT WINAPI MFSetAttribute2UINT32asUINT64(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 unHigh32,UINT32 unLow32);
HRESULT WINAPI MFSetAttributeRatio(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 unNumerator,UINT32 unDenominator);
HRESULT WINAPI MFSetAttributeSize(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 unWidth,UINT32 unHeight);
HRESULT WINAPI MFShutdown(void);
HRESULT WINAPI MFTEnum(GUID guidCategory,UINT32 Flags,MFT_REGISTER_TYPE_INFO *pInputType,MFT_REGISTER_TYPE_INFO *pOutputType,IMFAttributes *pAttributes,CLSID **ppclsidMFT,UINT32 *pcMFTs);
HRESULT WINAPI MFTGetInfo(CLSID clsidMFT,LPWSTR *pszName,MFT_REGISTER_TYPE_INFO **ppInputTypes,UINT32 *pcInputTypes,MFT_REGISTER_TYPE_INFO **ppOutputTypes,UINT32 *pcOutputTypes,IMFAttributes **ppAttributes);
HRESULT WINAPI MFTRegister(CLSID clsidMFT,GUID guidCategory,LPWSTR pszName,UINT32 Flags,UINT32 cInputTypes,MFT_REGISTER_TYPE_INFO *pInputTypes,UINT32 cOutputTypes,MFT_REGISTER_TYPE_INFO *pOutputTypes,IMFAttributes *pAttributes);
HRESULT WINAPI MFTRegisterLocal(IClassFactory *pClassFactory,REFGUID guidCategory,LPCWSTR pszName,UINT32 Flags,UINT32 cInputTypes,const MFT_REGISTER_TYPE_INFO *pInputTypes,UINT32 cOutputTypes,const MFT_REGISTER_TYPE_INFO *pOutputTypes);
HRESULT WINAPI MFTUnregister(CLSID clsidMFT);
HRESULT WINAPI MFUnlockPlatform(void);
HRESULT WINAPI MFUnlockWorkQueue(DWORD dwWorkQueue);
HRESULT WINAPI MFUnwrapMediaType(IMFMediaType *pWrap,IMFMediaType **ppOrig);
HRESULT WINAPI MFValidateMediaTypeSize(GUID FormatType,UINT8 *pBlock,UINT32 cbSize);
HRESULT WINAPI MFWrapMediaType(IMFMediaType *pOrig,REFGUID MajorType,REFGUID SubType,IMFMediaType **ppWrap);
HRESULT WINAPI OPMGetVideoOutputsFromHMONITOR(HMONITOR hMonitor,OPM_VIDEO_OUTPUT_SEMANTICS vos,ULONG *pulNumVideoOutputs,IOPMVideoOutput ***pppOPMVideoOutputArray);
UINT64 WINAPI Pack2UINT32AsUINT64(UINT32 unHigh,UINT32 unLow);
/*void Unpack2UINT32AsUINT64(UINT64 unPacked,UINT32 *punHigh,UINT32 *punLow);*/
#define Unpack2UINT32AsUINT64(unPacked,punHigh,punLow) \
punHigh=(unPacked&0xffff0000); \
punLow=(unPacked&0x0000ffff);

#ifdef __cplusplus
}
#endif

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
extern "C" {
#endif
HRESULT WINAPI MFCreateMFByteStreamOnStream(IStream *pStream,IMFByteStream **ppByteStream);
HRESULT WINAPI MFGetMFTMerit(IUnknown *pMFT,UINT32 cbVerifier,const BYTE *verifier,DWORD *merit);
HRESULT WINAPI MFGetPluginControl(IMFPluginControl **ppPluginControl);
LONGLONG WINAPI MFllMulDiv(LONGLONG a,LONGLONG b,LONGLONG c,LONGLONG d);
HRESULT WINAPI MFTEnumEx(GUID guidCategory,UINT32 Flags,const MFT_REGISTER_TYPE_INFO *pInputType,const MFT_REGISTER_TYPE_INFO *pOutputType,IMFActivate ***pppMFTActivate,UINT32 *pcMFTActivate);
HRESULT WINAPI MFTRegisterLocalByCLSID(REFCLSID clisdMFT,REFGUID guidCategory,LPCWSTR pszName,UINT32 Flags,UINT32 cInputTypes,const MFT_REGISTER_TYPE_INFO *pInputTypes,UINT32 cOutputTypes,const MFT_REGISTER_TYPE_INFO *pOutputTypes);
HRESULT WINAPI MFTUnregisterLocal(IClassFactory *pClassFactory);
HRESULT WINAPI MFTUnregisterLocalByCLSID(CLSID clsidMFT);
#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/

#ifndef __cplusplus
HRESULT WINAPI MFCreateWaveFormatExFromMFMediaType(IMFMediaType *pMFType,WAVEFORMATEX **ppWF,UINT32 *pcbSize,UINT32 Flags);
HRESULT WINAPI MFInitMediaTypeFromMPEG1VideoInfo(IMFMediaType *pMFType,const MPEG1VIDEOINFO *pMP1VI,UINT32 cbBufSize,const GUID *pSubtype);
HRESULT WINAPI MFInitMediaTypeFromMPEG2VideoInfo(IMFMediaType *pMFType,const MPEG2VIDEOINFO *pMP2VI,UINT32 cbBufSize,const GUID *pSubtype);
HRESULT WINAPI MFInitMediaTypeFromVideoInfoHeader(IMFMediaType *pMFType,const VIDEOINFOHEADER *pVIH,UINT32 cbBufSize,const GUID *pSubtype);
HRESULT WINAPI MFInitMediaTypeFromVideoInfoHeader2(IMFMediaType *pMFType,const VIDEOINFOHEADER2 *pVIH2,UINT32 cbBufSize,const GUID *pSubtype);
HRESULT WINAPI MFStartup(ULONG Version,DWORD dwFlags);
#else
extern "C" HRESULT WINAPI MFCreateWaveFormatExFromMFMediaType(IMFMediaType *pMFType,WAVEFORMATEX **ppWF,UINT32 *pcbSize,UINT32 Flags = MFWaveFormatExConvertFlag_Normal);
extern "C" HRESULT WINAPI MFInitMediaTypeFromMPEG1VideoInfo(IMFMediaType *pMFType,const MPEG1VIDEOINFO *pMP1VI,UINT32 cbBufSize,const GUID *pSubtype = NULL);
extern "C" HRESULT WINAPI MFInitMediaTypeFromMPEG2VideoInfo(IMFMediaType *pMFType,const MPEG2VIDEOINFO *pMP2VI,UINT32 cbBufSize,const GUID *pSubtype = NULL);
extern "C" HRESULT WINAPI MFInitMediaTypeFromVideoInfoHeader(IMFMediaType *pMFType,const VIDEOINFOHEADER *pVIH,UINT32 cbBufSize,const GUID *pSubtype = NULL);
extern "C" HRESULT WINAPI MFInitMediaTypeFromVideoInfoHeader2(IMFMediaType *pMFType,const VIDEOINFOHEADER2 *pVIH2,UINT32 cbBufSize,const GUID *pSubtype = NULL);
extern "C" HRESULT WINAPI MFStartup(ULONG Version,DWORD dwFlags = MFSTARTUP_FULL);
#endif

#endif  /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_MFAPI*/
