/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MFOBJECTS
#define _INC_MFOBJECTS

#if (_WIN32_WINNT >= 0x0600)

typedef struct IMFAsyncCallback IMFAsyncCallback;
typedef struct IMFMediaEvent IMFMediaEvent;
typedef struct IMFPresentationDescriptor IMFPresentationDescriptor;
typedef struct IPropertyStore IPropertyStore;
typedef DWORD MediaEventType;
__MINGW_EXTENSION typedef unsigned __int64 QWORD;

enum MF_ATTRIBUTE_SERIALIZE_OPTIONS {
  MF_ATTRIBUTE_SERIALIZE_UNKNOWN_BYREF   = 0x00000001 
};

typedef enum _MF_ATTRIBUTE_TYPE {
  MF_ATTRIBUTE_UINT32     = VT_UI4,
  MF_ATTRIBUTE_UINT64     = VT_UI8,
  MF_ATTRIBUTE_DOUBLE     = VT_R8,
  MF_ATTRIBUTE_GUID       = VT_CLSID,
  MF_ATTRIBUTE_STRING     = VT_LPWSTR,
  MF_ATTRIBUTE_BLOB       = VT_VECTOR | VT_UI1,
  MF_ATTRIBUTE_IUNKNOWN   = VT_UNKNOWN 
} MF_ATTRIBUTE_TYPE;

typedef enum _MF_ATTRIBUTES_MATCH_TYPE {
  MF_ATTRIBUTES_MATCH_OUR_ITEMS      = 0,
  MF_ATTRIBUTES_MATCH_THEIR_ITEMS    = 1,
  MF_ATTRIBUTES_MATCH_ALL_ITEMS      = 2,
  MF_ATTRIBUTES_MATCH_INTERSECTION   = 3,
  MF_ATTRIBUTES_MATCH_SMALLER        = 4 
} MF_ATTRIBUTES_MATCH_TYPE;

typedef enum _MF_CONNECT_METHOD {
  MF_CONNECT_DIRECT                            = 0x00000000,
  MF_CONNECT_ALLOW_CONVERTER                   = 0x00000001,
  MF_CONNECT_ALLOW_DECODER                     = 0x00000003,
  MF_CONNECT_RESOLVE_INDEPENDENT_OUTPUTTYPES   = 0x00000004,
  MF_CONNECT_AS_OPTIONAL                       = 0x00010000,
  MF_CONNECT_AS_OPTIONAL_BRANCH                = 0x00020000 
} MF_CONNECT_METHOD;

typedef enum MF_FILE_ACCESSMODE {
  MF_ACCESSMODE_READ        = 1,
  MF_ACCESSMODE_WRITE       = 2,
  MF_ACCESSMODE_READWRITE   = 3 
} MF_FILE_ACCESSMODE;

typedef enum  {
  MF_FILEFLAGS_NONE                  = 0x00000000,
  MF_FILEFLAGS_NOBUFFERING           = 0x00000001,
  MF_FILEFLAGS_ALLOW_WRITE_SHARING   = 0x00000002 
} MF_FILE_FLAGS;

typedef enum  {
  MF_OPENMODE_FAIL_IF_NOT_EXIST   = 0,
  MF_OPENMODE_FAIL_IF_EXIST       = 1,
  MF_OPENMODE_RESET_IF_EXIST      = 2,
  MF_OPENMODE_APPEND_IF_EXIST     = 3,
  MF_OPENMODE_DELETE_IF_EXIST     = 4 
} MF_FILE_OPENMODE;

typedef enum _MFVideoTransferFunction {
  MFVideoTransFunc_Unknown      = 0,
  MFVideoTransFunc_10           = 1,
  MFVideoTransFunc_18           = 2,
  MFVideoTransFunc_20           = 3,
  MFVideoTransFunc_22           = 4,
  MFVideoTransFunc_709          = 5,
  MFVideoTransFunc_240M         = 6,
  MFVideoTransFunc_sRGB         = 7,
  MFVideoTransFunc_28           = 8,
  MFVideoTransFunc_Log_100      = 9,
  MFVideoTransFunc_Log_316      = 10,
  MFVideoTransFunc_709_sym      = 11,
  MFVideoTransFunc_Last,
  MFVideoTransFunc_ForceDWORD   = 0x7FFFFFFF 
} MFVideoTransferFunction;

#if (_WIN32_WINNT >= 0x0601)

typedef enum _MF_Plugin_Type {
  MF_Plugin_Type_MFT           = 0,
  MF_Plugin_Type_MediaSource   = 1 
} MF_Plugin_Type;

#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef enum _MFBYTESTREAM_SEEK_ORIGIN {
  msoBegin,
  msoCurrent 
} MFBYTESTREAM_SEEK_ORIGIN;

typedef enum _MFNominalRange {
  MFNominalRange_Unknown   = 0,
  MFNominalRange_Normal    = 1,
  MFNominalRange_Wide      = 2,
  MFNominalRange_0_255     = 1,
  MFNominalRange_16_235    = 2,
  MFNominalRange_48_208    = 3,
  MFNominalRange_64_127    = 4 
} MFNominalRange;

typedef enum _MFStandardVideoFormat {
  MFStdVideoFormat_reserved       = 0,
  MFStdVideoFormat_NTSC,
  MFStdVideoFormat_PAL,
  MFStdVideoFormat_DVD_NTSC,
  MFStdVideoFormat_DVD_PAL,
  MFStdVideoFormat_DV_PAL,
  MFStdVideoFormat_DV_NTSC,
  MFStdVideoFormat_ATSC_SD480i,
  MFStdVideoFormat_ATSC_HD1080i,
  MFStdVideoFormat_ATSC_HD720p 
} MFStandardVideoFormat;

typedef enum _MFVideoChromaSubsampling {
  MFVideoChromaSubsampling_Unknown                          = 0,
  MFVideoChromaSubsampling_ProgressiveChroma                = 0x8,
  MFVideoChromaSubsampling_Horizontally_Cosited             = 0x4,
  MFVideoChromaSubsampling_Vertically_Cosited               = 0x2,
  MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes   = 0x1,
  MFVideoChromaSubsampling_MPEG2                            = 
    MFVideoChromaSubsampling_Horizontally_Cosited | 
    MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes,
  MFVideoChromaSubsampling_MPEG1                            = 
    MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes,
  MFVideoChromaSubsampling_DV_PAL                           = 
    MFVideoChromaSubsampling_Horizontally_Cosited | 
    MFVideoChromaSubsampling_Vertically_Cosited,
  MFVideoChromaSubsampling_Cosited                          = 
    MFVideoChromaSubsampling_Horizontally_Cosited | 
    MFVideoChromaSubsampling_Vertically_Cosited | 
    MFVideoChromaSubsampling_Vertically_AlignedChromaPlanes,
  MFVideoChromaSubsampling_Last                             = MFVideoChromaSubsampling_Cosited + 1,
  MFVideoChromaSubsampling_ForceDWORD                       = 0x7FFFFFFF 
} MFVideoChromaSubsampling;

typedef enum _MFVideoInterlaceMode {
  MFVideoInterlace_Unknown                       = 0,
  MFVideoInterlace_Progressive                   = 2,
  MFVideoInterlace_FieldInterleavedUpperFirst    = 3,
  MFVideoInterlace_FieldInterleavedLowerFirst    = 4,
  MFVideoInterlace_FieldSingleUpper              = 5,
  MFVideoInterlace_FieldSingleLower              = 6,
  MFVideoInterlace_MixedInterlaceOrProgressive   = 7,
  MFVideoInterlace_Last,
  MFVideoInterlace_ForceDWORD                    = 0x7FFFFFFF 
} MFVideoInterlaceMode;

typedef enum _MFVideoLighting {
  MFVideoLighting_Unknown      = 0,
  MFVideoLighting_bright       = 1,
  MFVideoLighting_office       = 2,
  MFVideoLighting_dim          = 3,
  MFVideoLighting_dark         = 4,
  MFVideoLighting_Last,
  MFVideoLighting_ForceDWORD   = 0x7FFFFFFF 
} MFVideoLighting;

typedef enum _MFVideoPrimaries {
  MFVideoPrimaries_Unknown         = 0,
  MFVideoPrimaries_reserved        = 1,
  MFVideoPrimaries_BT709           = 2,
  MFVideoPrimaries_BT470_2_SysM    = 3,
  MFVideoPrimaries_BT470_2_SysBG   = 4,
  MFVideoPrimaries_SMPTE170M       = 5,
  MFVideoPrimaries_SMPTE240M       = 6,
  MFVideoPrimaries_EBU3213         = 7,
  MFVideoPrimaries_SMPTE_C         = 8,
  MFVideoPrimaries_Last,
  MFVideoPrimaries_ForceDWORD      = 0x7FFFFFFF 
} MFVideoPrimaries;

typedef enum _MFVideoTransferMatrix {
  MFVideoTransferMatrix_Unknown      = 0,
  MFVideoTransferMatrix_BT709        = 1,
  MFVideoTransferMatrix_BT601        = 2,
  MFVideoTransferMatrix_SMPTE240M    = 3,
  MFVideoTransferMatrix_Last,
  MFVideoTransferMatrix_ForceDWORD   = 0x7FFFFFFF 
} MFVideoTransferMatrix;

typedef struct _MFRatio {
  DWORD Numerator;
  DWORD Denominator;
} MFRatio;

typedef struct _MFOffset {
  WORD  fract;
  short value;
} MFOffset;

typedef struct _MFVideoArea {
  MFOffset OffsetX;
  MFOffset OffsetY;
  SIZE     Area;
} MFVideoArea;

typedef enum _MFVideoFlags {
  MFVideoFlag_PAD_TO_Mask             = 0x0001 | 0x0002,
  MFVideoFlag_PAD_TO_None             = 0 * 0x0001,
  MFVideoFlag_PAD_TO_4x3              = 1 * 0x0001,
  MFVideoFlag_PAD_TO_16x9             = 2 * 0x0001,
  MFVideoFlag_SrcContentHintMask      = 0x0004 | 0x0008 | 0x0010,
  MFVideoFlag_SrcContentHintNone      = 0 * 0x0004,
  MFVideoFlag_SrcContentHint16x9      = 1 * 0x0004,
  MFVideoFlag_SrcContentHint235_1     = 2 * 0x0004,
  MFVideoFlag_AnalogProtected         = 0x0020,
  MFVideoFlag_DigitallyProtected      = 0x0040,
  MFVideoFlag_ProgressiveContent      = 0x0080,
  MFVideoFlag_FieldRepeatCountMask    = 0x0100 | 0x0200 | 0x0400,
  MFVideoFlag_FieldRepeatCountShift   = 8,
  MFVideoFlag_ProgressiveSeqReset     = 0x0800,
  MFVideoFlag_PanScanEnabled          = 0x20000,
  MFVideoFlag_LowerFieldFirst         = 0x40000,
  MFVideoFlag_BottomUpLinearRep       = 0x80000,
  MFVideoFlags_DXVASurface            = 0x100000,
  MFVideoFlags_RenderTargetSurface    = 0x400000,
  MFVideoFlags_ForceQWORD             = 0x7FFFFFFF 
} MFVideoFlags;

typedef struct _MFVideoCompressedInfo {
  LONGLONG AvgBitrate;
  LONGLONG AvgBitErrorRate;
  DWORD    MaxKeyFrameSpacing;
} MFVideoCompressedInfo;

typedef struct _MFVideoInfo {
  DWORD                    dwWidth;
  DWORD                    dwHeight;
  MFRatio                  PixelAspectRatio;
  MFVideoChromaSubsampling SourceChromaSubsampling;
  MFVideoInterlaceMode     InterlaceMode;
  MFVideoTransferFunction  TransferFunction;
  MFVideoPrimaries         ColorPrimaries;
  MFVideoTransferMatrix    TransferMatrix;
  MFVideoLighting          SourceLighting;
  MFRatio                  FramesPerSecond;
  MFNominalRange           NominalRange;
  MFVideoArea              GeometricAperture;
  MFVideoArea              MinimumDisplayAperture;
  MFVideoArea              PanScanAperture;
  unsigned __int64         VideoFlags;
} MFVideoInfo;

typedef struct _MFARGB {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbAlpha;
} MFARGB;

typedef struct __MFAYUVSample {
  BYTE bCrValue;
  BYTE bCbValue;
  BYTE bYValue;
  BYTE bSampleAlpha8;
} MFAYUVSample;

typedef union _MFPaletteEntry {
  MFARGB       ARGB;
  MFAYUVSample AYCbCr;
} MFPaletteEntry;

typedef struct _MFVideoSurfaceInfo {
  DWORD          Format;
  DWORD          PaletteEntries;
  MFPaletteEntry Palette[];
} MFVideoSurfaceInfo;

typedef struct _MFVIDEOFORMAT {
  DWORD                 dwSize;
  MFVideoInfo           videoInfo;
  GUID                  guidFormat;
  MFVideoCompressedInfo compressedInfo;
  MFVideoSurfaceInfo    surfaceInfo;
} MFVIDEOFORMAT;

#define MF_MEDIATYPE_EQUAL_MAJOR_TYPES          0x00000001
#define MF_MEDIATYPE_EQUAL_FORMAT_TYPES         0x00000002
#define MF_MEDIATYPE_EQUAL_FORMAT_DATA          0x00000004
#define MF_MEDIATYPE_EQUAL_FORMAT_USER_DATA     0x00000008

#define MFBYTESTREAM_IS_READABLE                0x00000001
#define MFBYTESTREAM_IS_WRITABLE                0x00000002
#define MFBYTESTREAM_IS_SEEKABLE                0x00000004
#define MFBYTESTREAM_IS_REMOTE                  0x00000008
#define MFBYTESTREAM_IS_DIRECTORY               0x00000080
#define MFBYTESTREAM_HAS_SLOW_SEEK              0x00000100
#define MFBYTESTREAM_IS_PARTIALLY_DOWNLOADED    0x00000200
#define MFBYTESTREAM_SHARE_WRITE                0x00000400

#undef  INTERFACE
#define INTERFACE IMFRemoteAsyncCallback
DECLARE_INTERFACE_(IMFRemoteAsyncCallback,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFRemoteAsyncCallback methods */
    STDMETHOD(Invoke)(THIS) PURE; /*Not used by applications.*/

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFRemoteAsyncCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFRemoteAsyncCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFRemoteAsyncCallback_Release(This) (This)->lpVtbl->Release(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFAsyncResult
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFAsyncResult,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAsyncResult methods */
    STDMETHOD_(HRESULT,GetObject)(THIS_ IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ IUnknown **ppunkState) PURE;
    STDMETHOD_(IUnknown *,GetStateNoAddRef)(THIS) PURE;
    STDMETHOD_(HRESULT,GetStatus)(THIS) PURE;
    STDMETHOD_(HRESULT,SetStatus)(THIS_ HRESULT hrStatus) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFAsyncResult_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFAsyncResult_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFAsyncResult_Release(This) (This)->lpVtbl->Release(This)
#define IMFAsyncResult_GetObject(This,ppObject) (This)->lpVtbl->GetObject(This,ppObject)
#define IMFAsyncResult_GetState(This,ppunkState) (This)->lpVtbl->GetState(This,ppunkState)
#define IMFAsyncResult_GetStateNoAddRef() (This)->lpVtbl->GetStateNoAddRef(This)
#define IMFAsyncResult_GetStatus() (This)->lpVtbl->GetStatus(This)
#define IMFAsyncResult_SetStatus(This,hrStatus) (This)->lpVtbl->SetStatus(This,hrStatus)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaEventGenerator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaEventGenerator,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFMediaEventGenerator methods */
    /*[call_as(BeginGetEvent)] */
    STDMETHOD_(HRESULT,BeginGetEvent)(THIS_ IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,EndGetEvent)(THIS_ IMFAsyncResult *pResult,IMFMediaEvent **ppEvent) PURE;
    STDMETHOD_(HRESULT,GetEvent)(THIS_ DWORD dwFlags,IMFMediaEvent **ppEvent) PURE;
    STDMETHOD_(HRESULT,QueueEvent)(THIS_ MediaEventType met,REFGUID guidExtendedType,HRESULT hrStatus,const PROPVARIANT *pvValue) PURE;
    STDMETHOD_(HRESULT,RemoteEndGetEvent)(THIS_ IUnknown *pResult,DWORD *pcbEvent,BYTE **ppbEvent) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaEventGenerator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaEventGenerator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaEventGenerator_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaEventGenerator_BeginGetEvent(This,pCallback,punkState) (This)->lpVtbl->BeginGetEvent(This,pCallback,punkState)
#define IMFMediaEventGenerator_EndGetEvent(This,pResult,ppEvent) (This)->lpVtbl->EndGetEvent(This,pResult,ppEvent)
#define IMFMediaEventGenerator_GetEvent(This,dwFlags,ppEvent) (This)->lpVtbl->GetEvent(This,dwFlags,ppEvent)
#define IMFMediaEventGenerator_QueueEvent(This,met,guidExtendedType,hrStatus,pvValue) (This)->lpVtbl->QueueEvent(This,met,guidExtendedType,hrStatus,pvValue)
#define IMFMediaEventGenerator_RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent) (This)->lpVtbl->RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaBuffer
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaBuffer,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFMediaBuffer methods */
    STDMETHOD_(HRESULT,GetCurrentLength)(THIS_ DWORD *pcbCurrentLength) PURE;
    STDMETHOD_(HRESULT,GetMaxLength)(THIS_ DWORD *pcbMaxLength) PURE;
    STDMETHOD_(HRESULT,Lock)(THIS_ BYTE **ppbBuffer,DWORD *pcbMaxLength,DWORD *pcbCurrentLength) PURE;
    STDMETHOD_(HRESULT,SetCurrentLength)(THIS_ DWORD cbCurrentLength) PURE;
    STDMETHOD_(HRESULT,Unlock)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaBuffer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaBuffer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaBuffer_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaBuffer_GetCurrentLength(This,pcbCurrentLength) (This)->lpVtbl->GetCurrentLength(This,pcbCurrentLength)
#define IMFMediaBuffer_GetMaxLength(This,pcbMaxLength) (This)->lpVtbl->GetMaxLength(This,pcbMaxLength)
#define IMFMediaBuffer_Lock(This,ppbBuffer,pcbMaxLength,pcbCurrentLength) (This)->lpVtbl->Lock(This,ppbBuffer,pcbMaxLength,pcbCurrentLength)
#define IMFMediaBuffer_SetCurrentLength(This,cbCurrentLength) (This)->lpVtbl->SetCurrentLength(This,cbCurrentLength)
#define IMFMediaBuffer_Unlock() (This)->lpVtbl->Unlock(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFAttributes
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFAttributes,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFAttributes_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFAttributes_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFAttributes_Release(This) (This)->lpVtbl->Release(This)
#define IMFAttributes_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFAttributes_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFAttributes_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFAttributes_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFAttributes_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFAttributes_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFAttributes_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFAttributes_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFAttributes_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFAttributes_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFAttributes_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFAttributes_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFAttributes_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFAttributes_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFAttributes_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFAttributes_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFAttributes_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFAttributes_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFAttributes_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFAttributes_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFAttributes_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFAttributes_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFAttributes_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFAttributes_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFAttributes_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFAttributes_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFAttributes_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFAttributes_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFAttributes_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFAttributes_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaType
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaType,IMFAttributes)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    /* IMFMediaType methods */
    STDMETHOD_(HRESULT,FreeRepresentation)(THIS_ GUID guidRepresentation,void *pvRepresentation) PURE;
    STDMETHOD_(HRESULT,GetMajorType)(THIS_ GUID *pguidMajorType) PURE;
    STDMETHOD_(HRESULT,GetRepresentation)(THIS_ GUID guidRepresentation,void **ppvRepresentation) PURE;
    STDMETHOD_(HRESULT,IsCompressedFormat)(THIS_ WINBOOL *pfCompressed) PURE;
    STDMETHOD_(HRESULT,IsEqual)(THIS_ IMFMediaType *pIMediaType,DWORD *pdwFlags) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaType_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaType_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFMediaType_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFMediaType_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFMediaType_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFMediaType_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFMediaType_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFMediaType_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFMediaType_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFMediaType_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFMediaType_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFMediaType_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFMediaType_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFMediaType_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFMediaType_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFMediaType_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFMediaType_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFMediaType_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFMediaType_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFMediaType_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFMediaType_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFMediaType_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFMediaType_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFMediaType_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFMediaType_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFMediaType_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFMediaType_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFMediaType_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFMediaType_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFMediaType_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFMediaType_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFMediaType_FreeRepresentation(This,guidRepresentation,pvRepresentation) (This)->lpVtbl->FreeRepresentation(This,guidRepresentation,pvRepresentation)
#define IMFMediaType_GetMajorType(This,pguidMajorType) (This)->lpVtbl->GetMajorType(This,pguidMajorType)
#define IMFMediaType_GetRepresentation(This,guidRepresentation,ppvRepresentation) (This)->lpVtbl->GetRepresentation(This,guidRepresentation,ppvRepresentation)
#define IMFMediaType_IsCompressedFormat(This,pfCompressed) (This)->lpVtbl->IsCompressedFormat(This,pfCompressed)
#define IMFMediaType_IsEqual(This,pIMediaType,pdwFlags) (This)->lpVtbl->IsEqual(This,pIMediaType,pdwFlags)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFAudioMediaType
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFAudioMediaType,IMFAudioMediaType)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    /* IMFMediaType methods */
    STDMETHOD_(HRESULT,FreeRepresentation)(THIS_ GUID guidRepresentation,void *pvRepresentation) PURE;
    STDMETHOD_(HRESULT,GetMajorType)(THIS_ GUID *pguidMajorType) PURE;
    STDMETHOD_(HRESULT,GetRepresentation)(THIS_ GUID guidRepresentation,void **ppvRepresentation) PURE;
    STDMETHOD_(HRESULT,IsCompressedFormat)(THIS_ WINBOOL *pfCompressed) PURE;
    STDMETHOD_(HRESULT,IsEqual)(THIS_ IMFMediaType *pIMediaType,DWORD *pdwFlags) PURE;

    /* IMFAudioMediaType methods */
    STDMETHOD_(const WAVEFORMATEX *,GetAudioFormat)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFAudioMediaType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFAudioMediaType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFAudioMediaType_Release(This) (This)->lpVtbl->Release(This)
#define IMFAudioMediaType_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFAudioMediaType_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFAudioMediaType_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFAudioMediaType_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFAudioMediaType_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFAudioMediaType_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFAudioMediaType_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFAudioMediaType_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFAudioMediaType_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFAudioMediaType_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFAudioMediaType_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFAudioMediaType_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFAudioMediaType_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFAudioMediaType_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFAudioMediaType_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFAudioMediaType_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFAudioMediaType_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFAudioMediaType_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFAudioMediaType_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFAudioMediaType_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFAudioMediaType_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFAudioMediaType_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFAudioMediaType_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFAudioMediaType_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFAudioMediaType_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFAudioMediaType_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFAudioMediaType_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFAudioMediaType_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFAudioMediaType_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFAudioMediaType_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFAudioMediaType_FreeRepresentation(This,guidRepresentation,pvRepresentation) (This)->lpVtbl->FreeRepresentation(This,guidRepresentation,pvRepresentation)
#define IMFAudioMediaType_GetMajorType(This,pguidMajorType) (This)->lpVtbl->GetMajorType(This,pguidMajorType)
#define IMFAudioMediaType_GetRepresentation(This,guidRepresentation,ppvRepresentation) (This)->lpVtbl->GetRepresentation(This,guidRepresentation,ppvRepresentation)
#define IMFAudioMediaType_IsCompressedFormat(This,pfCompressed) (This)->lpVtbl->IsCompressedFormat(This,pfCompressed)
#define IMFAudioMediaType_IsEqual(This,pIMediaType,pdwFlags) (This)->lpVtbl->IsEqual(This,pIMediaType,pdwFlags)
#define IMFAudioMediaType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSample
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSample,IMFAttributes)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    /* IMFMediaType methods */
    STDMETHOD_(HRESULT,FreeRepresentation)(THIS_ GUID guidRepresentation,void *pvRepresentation) PURE;
    STDMETHOD_(HRESULT,GetMajorType)(THIS_ GUID *pguidMajorType) PURE;
    STDMETHOD_(HRESULT,GetRepresentation)(THIS_ GUID guidRepresentation,void **ppvRepresentation) PURE;
    STDMETHOD_(HRESULT,IsCompressedFormat)(THIS_ WINBOOL *pfCompressed) PURE;
    STDMETHOD_(HRESULT,IsEqual)(THIS_ IMFMediaType *pIMediaType,DWORD *pdwFlags) PURE;

    /* IMFSample methods */
    STDMETHOD_(HRESULT,AddBuffer)(THIS_ IMFMediaBuffer *pBuffer) PURE;
    STDMETHOD_(HRESULT,ConvertToContiguousBuffer)(THIS_ IMFMediaBuffer **ppBuffer) PURE;
    STDMETHOD_(HRESULT,CopyToBuffer)(THIS_ IMFMediaBuffer *pBuffer) PURE;
    STDMETHOD_(HRESULT,GetBufferByIndex)(THIS_ DWORD dwIndex,IMFMediaBuffer **ppBuffer) PURE;
    STDMETHOD_(HRESULT,GetBufferCount)(THIS_ DWORD *pdwBufferCount) PURE;
    STDMETHOD_(HRESULT,GetSampleDuration)(THIS_ LONGLONG *phnsSampleDuration) PURE;
    STDMETHOD_(HRESULT,GetSampleFlags)(THIS_ DWORD *pdwSampleFlags) PURE;
    STDMETHOD_(HRESULT,GetSampleTime)(THIS_ LONGLONG *phnsSampleTime) PURE;
    STDMETHOD_(HRESULT,GetTotalLength)(THIS_ DWORD *pcbTotalLength) PURE;
    STDMETHOD_(HRESULT,RemoveAllBuffers)(THIS) PURE;
    STDMETHOD_(HRESULT,RemoveBufferByIndex)(THIS_ DWORD dwIndex) PURE;
    STDMETHOD_(HRESULT,SetSampleDuration)(THIS_ LONGLONG hnsSampleDuration) PURE;
    STDMETHOD_(HRESULT,SetSampleFlags)(THIS_ DWORD dwSampleFlags) PURE;
    STDMETHOD_(HRESULT,SetSampleTime)(THIS_ LONGLONG hnsSampleTime) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSample_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSample_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSample_Release(This) (This)->lpVtbl->Release(This)
#define IMFSample_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFSample_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFSample_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFSample_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFSample_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFSample_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFSample_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFSample_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFSample_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFSample_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFSample_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFSample_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFSample_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFSample_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFSample_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFSample_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFSample_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFSample_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFSample_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFSample_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFSample_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFSample_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFSample_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFSample_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFSample_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFSample_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFSample_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFSample_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFSample_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFSample_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFSample_FreeRepresentation(This,guidRepresentation,pvRepresentation) (This)->lpVtbl->FreeRepresentation(This,guidRepresentation,pvRepresentation)
#define IMFSample_GetMajorType(This,pguidMajorType) (This)->lpVtbl->GetMajorType(This,pguidMajorType)
#define IMFSample_GetRepresentation(This,guidRepresentation,ppvRepresentation) (This)->lpVtbl->GetRepresentation(This,guidRepresentation,ppvRepresentation)
#define IMFSample_IsCompressedFormat(This,pfCompressed) (This)->lpVtbl->IsCompressedFormat(This,pfCompressed)
#define IMFSample_IsEqual(This,pIMediaType,pdwFlags) (This)->lpVtbl->IsEqual(This,pIMediaType,pdwFlags)
#define IMFSample_AddBuffer(This,pBuffer) (This)->lpVtbl->AddBuffer(This,pBuffer)
#define IMFSample_ConvertToContiguousBuffer(This,ppBuffer) (This)->lpVtbl->ConvertToContiguousBuffer(This,ppBuffer)
#define IMFSample_CopyToBuffer(This,pBuffer) (This)->lpVtbl->CopyToBuffer(This,pBuffer)
#define IMFSample_GetBufferByIndex(This,dwIndex,ppBuffer) (This)->lpVtbl->GetBufferByIndex(This,dwIndex,ppBuffer)
#define IMFSample_GetBufferCount(This,pdwBufferCount) (This)->lpVtbl->GetBufferCount(This,pdwBufferCount)
#define IMFSample_GetSampleDuration(This,phnsSampleDuration) (This)->lpVtbl->GetSampleDuration(This,phnsSampleDuration)
#define IMFSample_GetSampleFlags(This,pdwSampleFlags) (This)->lpVtbl->GetSampleFlags(This,pdwSampleFlags)
#define IMFSample_GetSampleTime(This,phnsSampleTime) (This)->lpVtbl->GetSampleTime(This,phnsSampleTime)
#define IMFSample_GetTotalLength(This,pcbTotalLength) (This)->lpVtbl->GetTotalLength(This,pcbTotalLength)
#define IMFSample_RemoveAllBuffers() (This)->lpVtbl->RemoveAllBuffers(This)
#define IMFSample_RemoveBufferByIndex(This,dwIndex) (This)->lpVtbl->RemoveBufferByIndex(This,dwIndex)
#define IMFSample_SetSampleDuration(This,hnsSampleDuration) (This)->lpVtbl->SetSampleDuration(This,hnsSampleDuration)
#define IMFSample_SetSampleFlags(This,dwSampleFlags) (This)->lpVtbl->SetSampleFlags(This,dwSampleFlags)
#define IMFSample_SetSampleTime(This,hnsSampleTime) (This)->lpVtbl->SetSampleTime(This,hnsSampleTime)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMF2DBuffer
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMF2DBuffer,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMF2DBuffer methods */
    STDMETHOD_(HRESULT,ContiguousCopyFrom)(THIS_ const BYTE *pbSrcBuffer,DWORD cbSrcBuffer) PURE;
    STDMETHOD_(HRESULT,ContiguousCopyTo)(THIS_ BYTE *pbDestBuffer,DWORD cbDestBuffer) PURE;
    STDMETHOD_(HRESULT,GetContiguousLength)(THIS_ DWORD *pcbLength) PURE;
    STDMETHOD_(HRESULT,GetScanline0AndPitch)(THIS_ BYTE **pbScanline0,LONG *plPitch) PURE;
    STDMETHOD_(HRESULT,IsContiguousFormat)(THIS_ WINBOOL *pfIsContiguous) PURE;
    STDMETHOD_(HRESULT,Lock2D)(THIS_ BYTE **pbScanline0,LONG *plPitch) PURE;
    STDMETHOD_(HRESULT,Unlock2D)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMF2DBuffer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMF2DBuffer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMF2DBuffer_Release(This) (This)->lpVtbl->Release(This)
#define IMF2DBuffer_ContiguousCopyFrom(This,pbSrcBuffer,cbSrcBuffer) (This)->lpVtbl->ContiguousCopyFrom(This,pbSrcBuffer,cbSrcBuffer)
#define IMF2DBuffer_ContiguousCopyTo(This,pbDestBuffer,cbDestBuffer) (This)->lpVtbl->ContiguousCopyTo(This,pbDestBuffer,cbDestBuffer)
#define IMF2DBuffer_GetContiguousLength(This,pcbLength) (This)->lpVtbl->GetContiguousLength(This,pcbLength)
#define IMF2DBuffer_GetScanline0AndPitch(This,pbScanline0,plPitch) (This)->lpVtbl->GetScanline0AndPitch(This,pbScanline0,plPitch)
#define IMF2DBuffer_IsContiguousFormat(This,pfIsContiguous) (This)->lpVtbl->IsContiguousFormat(This,pfIsContiguous)
#define IMF2DBuffer_Lock2D(This,pbScanline0,plPitch) (This)->lpVtbl->Lock2D(This,pbScanline0,plPitch)
#define IMF2DBuffer_Unlock2D() (This)->lpVtbl->Unlock2D(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFAsyncCallback
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFAsyncCallback,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAsyncCallback methods */
    STDMETHOD_(HRESULT,GetParameters)(THIS_ DWORD *pdwFlags,DWORD *pdwQueue) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ IMFAsyncResult *pAsyncResult) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFAsyncCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFAsyncCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFAsyncCallback_Release(This) (This)->lpVtbl->Release(This)
#define IMFAsyncCallback_GetParameters(This,pdwFlags,pdwQueue) (This)->lpVtbl->GetParameters(This,pdwFlags,pdwQueue)
#define IMFAsyncCallback_Invoke(This,pAsyncResult) (This)->lpVtbl->Invoke(This,pAsyncResult)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFByteStream
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFByteStream,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFByteStream methods */
    STDMETHOD_(HRESULT,GetParameters)(THIS_ DWORD *pdwFlags,DWORD *pdwQueue) PURE;
    STDMETHOD_(HRESULT,MFInvokeCallback)(THIS_ IMFAsyncResult *pAsyncResult) PURE;
    STDMETHOD_(HRESULT,BeginRead)(THIS_ BYTE *pb,ULONG cb,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,BeginWrite)(THIS_ const BYTE *pb,ULONG cb,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,Close)(THIS) PURE;
    STDMETHOD_(HRESULT,EndRead)(THIS_ IMFAsyncResult *pResult,ULONG *pcbRead) PURE;
    STDMETHOD_(HRESULT,EndWrite)(THIS_ IMFAsyncResult *pResult,ULONG *pcbWritten) PURE;
    STDMETHOD_(HRESULT,Flush)(THIS) PURE;
    STDMETHOD_(HRESULT,GetCapabilities)(THIS_ DWORD *pdwCapabilities) PURE;
    STDMETHOD_(HRESULT,GetCurrentPosition)(THIS_ QWORD *pqwPosition) PURE;
    STDMETHOD_(HRESULT,GetLength)(THIS_ QWORD *pqwLength) PURE;
    STDMETHOD_(HRESULT,IsEndOfStream)(THIS_ WINBOOL *pfEndOfStream) PURE;
    STDMETHOD_(HRESULT,Read)(THIS_ BYTE *pb,ULONG cb,ULONG *pcbRead) PURE;
    STDMETHOD_(HRESULT,Seek)(THIS_ MFBYTESTREAM_SEEK_ORIGIN SeekOrigin,LONGLONG qwSeekOffset,DWORD dwSeekFlags,QWORD *pqwCurrentPosition) PURE;
    STDMETHOD_(HRESULT,SetCurrentPosition)(THIS_ QWORD qwPosition) PURE;
    STDMETHOD_(HRESULT,SetLength)(THIS_ QWORD qwLength) PURE;
    STDMETHOD_(HRESULT,Write)(THIS_ const BYTE *pb,ULONG cb,ULONG *pcbWritten) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFByteStream_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFByteStream_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFByteStream_Release(This) (This)->lpVtbl->Release(This)
#define IMFByteStream_GetParameters(This,pdwFlags,pdwQueue) (This)->lpVtbl->GetParameters(This,pdwFlags,pdwQueue)
#define IMFByteStream_MFInvokeCallback(This,pAsyncResult) (This)->lpVtbl->MFInvokeCallback(This,pAsyncResult)
#define IMFByteStream_BeginRead(This,pb,cb,pCallback,punkState) (This)->lpVtbl->BeginRead(This,pb,cb,pCallback,punkState)
#define IMFByteStream_BeginWrite(This,pb,cb,pCallback,punkState) (This)->lpVtbl->BeginWrite(This,pb,cb,pCallback,punkState)
#define IMFByteStream_Close() (This)->lpVtbl->Close(This)
#define IMFByteStream_EndRead(This,pResult,pcbRead) (This)->lpVtbl->EndRead(This,pResult,pcbRead)
#define IMFByteStream_EndWrite(This,pResult,pcbWritten) (This)->lpVtbl->EndWrite(This,pResult,pcbWritten)
#define IMFByteStream_Flush() (This)->lpVtbl->Flush(This)
#define IMFByteStream_GetCapabilities(This,pdwCapabilities) (This)->lpVtbl->GetCapabilities(This,pdwCapabilities)
#define IMFByteStream_GetCurrentPosition(This,pqwPosition) (This)->lpVtbl->GetCurrentPosition(This,pqwPosition)
#define IMFByteStream_GetLength(This,pqwLength) (This)->lpVtbl->GetLength(This,pqwLength)
#define IMFByteStream_IsEndOfStream(This,pfEndOfStream) (This)->lpVtbl->IsEndOfStream(This,pfEndOfStream)
#define IMFByteStream_Read(This,pb,cb,pcbRead) (This)->lpVtbl->Read(This,pb,cb,pcbRead)
#define IMFByteStream_Seek(This,SeekOrigin,qwSeekOffset,dwSeekFlags,pqwCurrentPosition) (This)->lpVtbl->Seek(This,SeekOrigin,qwSeekOffset,dwSeekFlags,pqwCurrentPosition)
#define IMFByteStream_SetCurrentPosition(This,qwPosition) (This)->lpVtbl->SetCurrentPosition(This,qwPosition)
#define IMFByteStream_SetLength(This,qwLength) (This)->lpVtbl->SetLength(This,qwLength)
#define IMFByteStream_Write(This,pb,cb,pcbWritten) (This)->lpVtbl->Write(This,pb,cb,pcbWritten)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaEvent
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaEvent,IMFAttributes)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,BOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,BOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    /* IMFMediaEvent methods */
    STDMETHOD_(HRESULT,GetExtendedType)(THIS_ GUID *pguidExtendedType) PURE;
    STDMETHOD_(HRESULT,GetStatus)(THIS_ HRESULT *phrStatus) PURE;
    STDMETHOD_(HRESULT,GetType)(THIS_ MediaEventType *pmet) PURE;
    STDMETHOD_(HRESULT,GetValue)(THIS_ PROPVARIANT *pvValue) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaEvent_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaEvent_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaEvent_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaEvent_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFMediaEvent_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFMediaEvent_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFMediaEvent_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFMediaEvent_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFMediaEvent_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFMediaEvent_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFMediaEvent_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFMediaEvent_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFMediaEvent_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFMediaEvent_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFMediaEvent_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFMediaEvent_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFMediaEvent_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFMediaEvent_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFMediaEvent_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFMediaEvent_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFMediaEvent_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFMediaEvent_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFMediaEvent_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFMediaEvent_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFMediaEvent_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFMediaEvent_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFMediaEvent_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFMediaEvent_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFMediaEvent_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFMediaEvent_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFMediaEvent_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFMediaEvent_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFMediaEvent_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFMediaEvent_GetExtendedType(This,pguidExtendedType) (This)->lpVtbl->GetExtendedType(This,pguidExtendedType)
#define IMFMediaEvent_GetStatus(This,phrStatus) (This)->lpVtbl->GetStatus(This,phrStatus)
#define IMFMediaEvent_GetType(This,pmet) (This)->lpVtbl->GetType(This,pmet)
#define IMFMediaEvent_GetValue(This,pvValue) (This)->lpVtbl->GetValue(This,pvValue)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFVideoMediaType
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFVideoMediaType,IMFMediaType)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFAttributes methods */
    STDMETHOD_(HRESULT,Compare)(THIS_ IMFAttributes *pTheirs,MF_ATTRIBUTES_MATCH_TYPE MatchType,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CompareItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value,WINBOOL *pbResult) PURE;
    STDMETHOD_(HRESULT,CopyAllItems)(THIS_ IMFAttributes *pDest) PURE;
    STDMETHOD_(HRESULT,DeleteAllItems)(THIS) PURE;
    STDMETHOD_(HRESULT,DeleteItem)(THIS_ REFGUID guidKey) PURE;
    STDMETHOD_(HRESULT,GetAllocatedBlob)(THIS_ REFGUID guidKey,UINT8 **ppBuf,UINT32 *pcbSize) PURE;
    STDMETHOD_(HRESULT,GetAllocatedString)(THIS_ REFGUID guidKey,LPWSTR *ppwszValue,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetBlob)(THIS_ REFGUID guidKey,UINT8 *pBuf,UINT32 cbBufSize,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetBlobSize)(THIS_ REFGUID guidKey,UINT32 *pcbBlobSize) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ UINT32 *pcItems) PURE;
    STDMETHOD_(HRESULT,GetDouble)(THIS_ REFGUID guidKey,double *pfValue) PURE;
    STDMETHOD_(HRESULT,GetGUID)(THIS_ REFGUID guidKey,GUID *pguidValue) PURE;
    STDMETHOD_(HRESULT,GetItem)(THIS_ REFGUID guidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemByIndex)(THIS_ UINT32 unIndex,GUID *pguidKey,PROPVARIANT *pValue) PURE;
    STDMETHOD_(HRESULT,GetItemType)(THIS_ REFGUID guidKey,MF_ATTRIBUTE_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetString)(THIS_ REFGUID guidKey,LPWSTR pwszValue,UINT32 cchBufSize,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetStringLength)(THIS_ REFGUID guidKey,UINT32 *pcchLength) PURE;
    STDMETHOD_(HRESULT,GetUINT32)(THIS_ REFGUID guidKey,UINT32 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUINT64)(THIS_ REFGUID guidKey,UINT64 *punValue) PURE;
    STDMETHOD_(HRESULT,GetUnknown)(THIS_ REFGUID guidKey,REFIID riid,LPVOID *ppv) PURE;
    STDMETHOD_(HRESULT,LockStore)(THIS) PURE;
    STDMETHOD_(HRESULT,SetBlob)(THIS_ REFGUID guidKey,const UINT8 *pBuf,UINT32 cbBufSize) PURE;
    STDMETHOD_(HRESULT,SetDouble)(THIS_ REFGUID guidKey,double fValue) PURE;
    STDMETHOD_(HRESULT,SetGUID)(THIS_ REFGUID guidKey,REFGUID guidValue) PURE;
    STDMETHOD_(HRESULT,SetItem)(THIS_ REFGUID guidKey,REFPROPVARIANT Value) PURE;
    STDMETHOD_(HRESULT,SetString)(THIS_ REFGUID guidKey,LPCWSTR wszValue) PURE;
    STDMETHOD_(HRESULT,SetUINT32)(THIS_ REFGUID guidKey,UINT32 unValue) PURE;
    STDMETHOD_(HRESULT,SetUINT64)(THIS_ REFGUID guidKey,UINT64 unValue) PURE;
    STDMETHOD_(HRESULT,SetUnknown)(THIS_ REFGUID guidKey,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,UnlockStore)(THIS) PURE;

    /* IMFMediaType methods */
    STDMETHOD_(HRESULT,FreeRepresentation)(THIS_ GUID guidRepresentation,void *pvRepresentation) PURE;
    STDMETHOD_(HRESULT,GetMajorType)(THIS_ GUID *pguidMajorType) PURE;
    STDMETHOD_(HRESULT,GetRepresentation)(THIS_ GUID guidRepresentation,void **ppvRepresentation) PURE;
    STDMETHOD_(HRESULT,IsCompressedFormat)(THIS_ WINBOOL *pfCompressed) PURE;
    STDMETHOD_(HRESULT,IsEqual)(THIS_ IMFMediaType *pIMediaType,DWORD *pdwFlags) PURE;

    /* IMFVideoMediaType methods */
    STDMETHOD_(const MFVIDEOFORMAT *,GetVideoFormat)(THIS) PURE;
    STDMETHOD_(HRESULT,GetVideoRepresentation)(THIS_ GUID guidRepresentation,LPVOID *ppvRepresentation,LONG lStride) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFVideoMediaType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFVideoMediaType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFVideoMediaType_Release(This) (This)->lpVtbl->Release(This)
#define IMFVideoMediaType_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFVideoMediaType_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFVideoMediaType_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFVideoMediaType_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFVideoMediaType_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFVideoMediaType_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFVideoMediaType_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFVideoMediaType_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFVideoMediaType_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFVideoMediaType_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFVideoMediaType_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFVideoMediaType_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFVideoMediaType_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFVideoMediaType_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFVideoMediaType_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFVideoMediaType_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFVideoMediaType_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFVideoMediaType_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFVideoMediaType_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFVideoMediaType_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFVideoMediaType_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFVideoMediaType_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFVideoMediaType_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFVideoMediaType_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFVideoMediaType_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFVideoMediaType_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFVideoMediaType_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFVideoMediaType_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFVideoMediaType_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFVideoMediaType_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFVideoMediaType_FreeRepresentation(This,guidRepresentation,pvRepresentation) (This)->lpVtbl->FreeRepresentation(This,guidRepresentation,pvRepresentation)
#define IMFVideoMediaType_GetMajorType(This,pguidMajorType) (This)->lpVtbl->GetMajorType(This,pguidMajorType)
#define IMFVideoMediaType_GetRepresentation(This,guidRepresentation,ppvRepresentation) (This)->lpVtbl->GetRepresentation(This,guidRepresentation,ppvRepresentation)
#define IMFVideoMediaType_IsCompressedFormat(This,pfCompressed) (This)->lpVtbl->IsCompressedFormat(This,pfCompressed)
#define IMFVideoMediaType_IsEqual(This,pIMediaType,pdwFlags) (This)->lpVtbl->IsEqual(This,pIMediaType,pdwFlags)
#define IMFVideoMediaType_GetVideoFormat() (This)->lpVtbl->GetVideoFormat(This)
#define IMFVideoMediaType_GetVideoRepresentation(This,guidRepresentation,ppvRepresentation,lStride) (This)->lpVtbl->GetVideoRepresentation(This,guidRepresentation,ppvRepresentation,lStride)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFCollection
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFCollection,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFCollection methods */
    STDMETHOD_(HRESULT,AddElement)(THIS_ IUnknown *pUnkElement) PURE;
    STDMETHOD_(HRESULT,GetElement)(THIS_ DWORD dwElementIndex,IUnknown **ppUnkElement) PURE;
    STDMETHOD_(HRESULT,GetElementCount)(THIS_ DWORD *pcElements) PURE;
    STDMETHOD_(HRESULT,InsertElementAt)(THIS_ DWORD dwIndex,IUnknown *pUnknown) PURE;
    STDMETHOD_(HRESULT,RemoveAllElements)(THIS) PURE;
    STDMETHOD_(HRESULT,RemoveElement)(THIS_ DWORD dwElementIndex,IUnknown **ppUnkElement) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFCollection_Release(This) (This)->lpVtbl->Release(This)
#define IMFCollection_AddElement(This,pUnkElement) (This)->lpVtbl->AddElement(This,pUnkElement)
#define IMFCollection_GetElement(This,dwElementIndex,ppUnkElement) (This)->lpVtbl->GetElement(This,dwElementIndex,ppUnkElement)
#define IMFCollection_GetElementCount(This,pcElements) (This)->lpVtbl->GetElementCount(This,pcElements)
#define IMFCollection_InsertElementAt(This,dwIndex,pUnknown) (This)->lpVtbl->InsertElementAt(This,dwIndex,pUnknown)
#define IMFCollection_RemoveAllElements() (This)->lpVtbl->RemoveAllElements(This)
#define IMFCollection_RemoveElement(This,dwElementIndex,ppUnkElement) (This)->lpVtbl->RemoveElement(This,dwElementIndex,ppUnkElement)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)

#undef  INTERFACE
#define INTERFACE IMFPluginControl
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFPluginControl,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFPluginControl methods */
    STDMETHOD_(HRESULT,GetDisabledByIndex)(THIS_ DWORD pluginType,DWORD index,CLSID *clsid) PURE;
    STDMETHOD_(HRESULT,GetPreferredClsid)(THIS_ DWORD pluginType,LPCWSTR selector,CLSID *clsid) PURE;
    STDMETHOD_(HRESULT,GetPreferredClsidByIndex)(THIS_ DWORD pluginType,DWORD index,LPWSTR *selector,CLSID *clsid) PURE;
    STDMETHOD_(HRESULT,IsDisabled)(THIS_ DWORD pluginType,REFCLSID clsid) PURE;
    STDMETHOD_(HRESULT,SetDisabled)(THIS_ DWORD pluginType,REFCLSID clsid,WINBOOL disabled) PURE;
    STDMETHOD_(HRESULT,SetPreferredClsid)(THIS_ DWORD pluginType,LPCWSTR selector,const CLSID *clsid) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFPluginControl_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFPluginControl_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFPluginControl_Release(This) (This)->lpVtbl->Release(This)
#define IMFPluginControl_GetDisabledByIndex(This,pluginType,index,clsid) (This)->lpVtbl->GetDisabledByIndex(This,pluginType,index,clsid)
#define IMFPluginControl_GetPreferredClsid(This,pluginType,selector,clsid) (This)->lpVtbl->GetPreferredClsid(This,pluginType,selector,clsid)
#define IMFPluginControl_GetPreferredClsidByIndex(This,pluginType,index,selector,clsid) (This)->lpVtbl->GetPreferredClsidByIndex(This,pluginType,index,selector,clsid)
#define IMFPluginControl_IsDisabled(This,pluginType,clsid) (This)->lpVtbl->IsDisabled(This,pluginType,clsid)
#define IMFPluginControl_SetDisabled(This,pluginType,clsid,disabled) (This)->lpVtbl->SetDisabled(This,pluginType,clsid,disabled)
#define IMFPluginControl_SetPreferredClsid(This,pluginType,selector,clsid) (This)->lpVtbl->SetPreferredClsid(This,pluginType,selector,clsid)
#endif /*COBJMACROS*/
#endif /*(_WIN32_WINNT >= 0x0601)*/

HRESULT WINAPI Invoke(IMFAsyncResult *pAsyncResult);
HRESULT WINAPI MFDeserializeAttributesFromStream(IMFAttributes *pAttr,DWORD dwOptions,IStream *pStm);
HRESULT WINAPI MFDeserializePresentationDescriptor(DWORD cbData,BYTE *pbData,IMFPresentationDescriptor **ppPD);
HRESULT WINAPI MFGetAttribute2UINT32asUINT64(IMFAttributes *pAttributes,REFGUID guidKey,UINT32 *punHigh32,UINT32 *punLow32);
HRESULT WINAPI MFSerializeAttributesToStream(IMFAttributes *pAttr,DWORD dwOptions,IStream *pStm);

typedef enum MF_OBJECT_TYPE MF_OBJECT_TYPE;

/*[call_as(BeginCreateObjectFromByteStream)]*/
HRESULT WINAPI RemoteBeginCreateObjectFromByteStream(
    IMFByteStream* pByteStream,
    LPCWSTR pwszURL,
    IPropertyStore *pProps,
    DWORD dwFlags,
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginCreateObjectFromURL)]*/
HRESULT WINAPI RemoteBeginCreateObjectFromURL(
    LPCWSTR pwszURL,
    DWORD dwFlags,
    IPropertyStore *pProps,
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginEnableContent)]*/
HRESULT WINAPI RemoteBeginEnableContent(
    REFCLSID clsidType,
    BYTE *pbData,
    DWORD cbData,
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginGetEvent)]*/
HRESULT WINAPI RemoteBeginGetEvent(
    IMFRemoteAsyncCallback* pCallback
);

/*[call_as(BeginRegisterPlatformWorkQueueWithMMCSS)]*/
HRESULT WINAPI RemoteBeginRegisterPlatformWorkQueueWithMMCSS(
    DWORD dwPlatformWorkQueue,
    LPCWSTR wszClass,
    DWORD dwTaskId,
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginRegisterTopologyWorkQueuesWithMMCSS)]*/
HRESULT WINAPI RemoteBeginRegisterTopologyWorkQueuesWithMMCSS(
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginUnregisterPlatformWorkQueueWithMMCSS)]*/
HRESULT WINAPI RemoteBeginUnregisterPlatformWorkQueueWithMMCSS(
    DWORD dwPlatformWorkQueue,
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(BeginUnregisterTopologyWorkQueuesWithMMCSS)]*/
HRESULT WINAPI RemoteBeginUnregisterTopologyWorkQueuesWithMMCSS(
    IMFRemoteAsyncCallback *pCallback
);

/*[call_as(CreateObjectByCLSID)]*/
HRESULT WINAPI RemoteCreateObjectByCLSID( 
    REFCLSID clsid,
    BYTE *pbData, 
    DWORD cbData, 
    REFIID riid,
    void **ppv
);

/*[call_as(CreatePresentationDescriptor)]*/
HRESULT WINAPI RemoteCreatePresentationDescriptor(
    DWORD *pcbPD,
    BYTE **pbPD,
    IMFPresentationDescriptor **ppRemotePD
);

/*call_as(EndCreateObjectFromByteStream)]*/
HRESULT WINAPI RemoteEndCreateObjectFromByteStream(
    IUnknown *pResult,
    MF_OBJECT_TYPE *pObjectType,
    IUnknown **ppObject
);

/*[call_as(EndCreateObjectFromURL)]*/
HRESULT WINAPI RemoteEndCreateObjectFromURL(
    IUnknown *pResult,
    MF_OBJECT_TYPE *pObjectType,
    IUnknown **ppObject
);

/*[call_as(EndEnableContent)]*/
HRESULT WINAPI RemoteEndEnableContent(
    IUnknown *pResult
);

/*[call_as(EndGetEvent)]*/
HRESULT WINAPI RemoteEndGetEvent(
    IUnknown *pResult,
    DWORD *pcbEvent,
    BYTE **ppbEvent
);

/*[call_as(EndRegisterPlatformWorkQueueWithMMCSS)]*/
HRESULT WINAPI RemoteEndRegisterPlatformWorkQueueWithMMCSS(
    IUnknown *pResult,
    DWORD *pdwTaskId
);

/*[call_as(EndRegisterTopologyWorkQueuesWithMMCSS)]*/
HRESULT WINAPI RemoteEndRegisterTopologyWorkQueuesWithMMCSS(
    IUnknown *pResult
);

/*[call_as(EndUnregisterPlatformWorkQueueWithMMCSS)]*/
HRESULT WINAPI RemoteEndUnregisterPlatformWorkQueueWithMMCSS(
    IUnknown *pResult
);

/*[call_as(EndUnregisterTopologyWorkQueuesWithMMCSS)]*/
HRESULT WINAPI RemoteEndUnregisterTopologyWorkQueuesWithMMCSS(
    IUnknown *pResult
);

/*[call_as(GetCurrentMediaType)]*/
HRESULT WINAPI RemoteGetCurrentMediaType(
    BYTE **ppbData,
    DWORD *pcbData
);

/*[call_as(GetInputPrefType)]*/
HRESULT WINAPI RemoteGetInputPrefType(
    DWORD dwInputIndex,
    DWORD *pcbData,
    BYTE **ppbData
);

/*call_as(GetOutputPrefType)]*/
HRESULT WINAPI RemoteGetOutputPrefType(
    DWORD dwOutputIndex,
    DWORD *pcbData,
    BYTE **ppbData
);

/*[call_as(RequestSample)]*/
HRESULT WINAPI RemoteRequestSample();

#if (_WIN32_WINNT >= 0x0601)
HRESULT WINAPI MFGetPluginControl(IMFPluginControl **ppPluginControl);
#endif /*(_WIN32_WINNT >= 0x0601)*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /* _INC_MFOBJECTS */
