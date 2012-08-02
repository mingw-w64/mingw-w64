/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MFIDL
#define _INC_MFIDL
#include <mfobjects.h>
#include <mfapi.h>
#include <wmcontainer.h>
#include <evr.h>
#include <mftransform.h>
#include <propsys.h>

#if (_WIN32_WINNT >= 0x0600)

#ifndef __MFTIME_DEFINED__
#define __MFTIME_DEFINED__
__MINGW_EXTENSION typedef LONGLONG MFTIME;
#endif

__MINGW_EXTENSION typedef unsigned __int64 TOPOID;
typedef DWORD MFSequencerElementId; /*Unknown type*/

typedef struct _MFT_REGISTER_TYPE_INFO MFT_REGISTER_TYPE_INFO;
typedef struct IMFStreamDescriptor IMFStreamDescriptor;
typedef struct IMFMediaSink IMFMediaSink;
typedef struct IMFMediaTypeHandler IMFMediaTypeHandler;
typedef struct IMFCollection IMFCollection;

typedef enum MFCLOCK_CHARACTERISTICS_FLAGS {
  MFCLOCK_CHARACTERISTICS_FLAG_FREQUENCY_10MHZ   = 0x2,
  MFCLOCK_CHARACTERISTICS_FLAG_ALWAYS_RUNNING    = 0x4,
  MFCLOCK_CHARACTERISTICS_FLAG_IS_SYSTEM_CLOCK   = 0x8 
} MFCLOCK_CHARACTERISTICS_FLAGS;

typedef enum _MF_CLOCK_STATE {
  MFCLOCK_STATE_INVALID,
  MFCLOCK_STATE_RUNNING,
  MFCLOCK_STATE_STOPPED,
  MFCLOCK_STATE_PAUSED 
} MF_CLOCK_STATE, MFCLOCK_STATE;

#if (_WIN32_WINNT >= 0x0601)

typedef enum _MF_QUALITY_ADVISE_FLAGS {
  MF_QUALITY_CANNOT_KEEP_UP   = 0x1 
} MF_QUALITY_ADVISE_FLAGS;

#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef enum _MF_QUALITY_DROP_MODE {
  MF_DROP_MODE_NONE   = 0x0,
  MF_DROP_MODE_1      = 0x1,
  MF_DROP_MODE_2      = 0x2,
  MF_DROP_MODE_3      = 0x3,
  MF_DROP_MODE_4      = 0x4,
  MF_DROP_MODE_5      = 0x5,
  MF_NUM_DROP_MODES   = 0x6 
} MF_QUALITY_DROP_MODE;

typedef enum _MF_QUALITY_LEVEL {
  MF_QUALITY_NORMAL           = 0x0,
  MF_QUALITY_NORMAL_MINUS_1   = 0x1,
  MF_QUALITY_NORMAL_MINUS_2   = 0x2,
  MF_QUALITY_NORMAL_MINUS_3   = 0x3,
  MF_QUALITY_NORMAL_MINUS_4   = 0x4,
  MF_QUALITY_NORMAL_MINUS_5   = 0x5,
  MF_NUM_QUALITY_LEVELS       = 0x6 
} MF_QUALITY_LEVEL;

typedef enum MF_SOURCE_READER_CONTROL_FLAG {
  MF_SOURCE_READER_CONTROLF_DRAIN   = 0x00000001 
} MF_SOURCE_READER_CONTROL_FLAG;

typedef enum _MF_TOPOLOGY_RESOLUTION_STATUS_FLAGS {
  MF_TOPOLOGY_RESOLUTION_SUCCEEDED              = 0x00000000,
  MF_OPTIONAL_NODE_REJECTED_MEDIA_TYPE          = 0x00000001,
  MF_OPTIONAL_NODE_REJECTED_PROTECTED_PROCESS   = 0x00000002 
} MF_TOPOLOGY_RESOLUTION_STATUS_FLAGS;

typedef enum MF_TOPOLOGY_TYPE {
  MF_TOPOLOGY_OUTPUT_NODE,
  MF_TOPOLOGY_SOURCESTREAM_NODE,
  MF_TOPOLOGY_TRANSFORM_NODE,
  MF_TOPOLOGY_TEE_NODE,
  MF_TOPOLOGY_MAX                 = 0xffffffff 
} MF_TOPOLOGY_TYPE;

typedef enum _MF_TOPONODE_DRAIN_MODE {
  MF_TOPONODE_DRAIN_DEFAULT,
  MF_TOPONODE_DRAIN_ALWAYS,
  MF_TOPONODE_DRAIN_NEVER 
} MF_TOPONODE_DRAIN_MODE;

typedef enum _MF_TOPONODE_FLUSH_MODE {
  MF_TOPONODE_FLUSH_ALWAYS,
  MF_TOPONODE_FLUSH_SEEK,
  MF_TOPONODE_FLUSH_NEVER 
} MF_TOPONODE_FLUSH_MODE;

#if (_WIN32_WINNT >= 0x0601)

typedef enum _MF_TRANSCODE_TOPOLOGY_MODE_FLAGS {
  MF_TRANSCODE_TOPOLOGYMODE_SOFTWARE_ONLY      = 0,
  MF_TRANSCODE_TOPOLOGYMODE_HARDWARE_ALLOWED   = 1 
} MF_TRANSCODE_TOPOLOGYMODE_FLAGS;

#endif

typedef enum  {
  MF_LICENSE_URL_UNTRUSTED,
  MF_LICENSE_URL_TRUSTED,
  MF_LICENSE_URL_TAMPERED 
} MF_URL_TRUST_STATUS;

typedef enum MFASF_INDEXERFLAGS {
  MFASF_INDEXER_WRITE_NEW_INDEX            = 0x00000001,
  MFASF_INDEXER_READ_FOR_REVERSEPLAYBACK   = 0x00000004,
  MFASF_INDEXER_WRITE_FOR_LIVEREAD         = 0x00000008 
} MFASF_INDEXERFLAGS;

typedef enum _MFCLOCK_RELATIONAL_FLAGS {
  MFCLOCK_RELATIONAL_FLAG_JITTER_NEVER_AHEAD   = 0x1 
} MFCLOCK_RELATIONAL_FLAGS;

typedef enum _MFMEDIASOURCE_CHARACTERISTICS {
  MFMEDIASOURCE_IS_LIVE                      = 0x1,
  MFMEDIASOURCE_CAN_SEEK                     = 0x2,
  MFMEDIASOURCE_CAN_PAUSE                    = 0x4,
  MFMEDIASOURCE_HAS_SLOW_SEEK                = 0x8,
  MFMEDIASOURCE_HAS_MULTIPLE_PRESENTATIONS   = 0x10,
  MFMEDIASOURCE_CAN_SKIPFORWARD              = 0x20,
  MFMEDIASOURCE_CAN_SKIPBACKWARD             = 0x40 
} MFMEDIASOURCE_CHARACTERISTICS;

typedef enum _MFNET_PROXYSETTINGS {
  MFNET_PROXYSETTING_NONE      = 0,
  MFNET_PROXYSETTING_MANUAL    = 1,
  MFNET_PROXYSETTING_AUTO      = 2,
  MFNET_PROXYSETTING_BROWSER   = 3 
} MFNET_PROXYSETTINGS;

typedef enum _MFNetAuthenticationFlags {
  MFNET_AUTHENTICATION_PROXY            = 0x00000001,
  MFNET_AUTHENTICATION_CLEAR_TEXT       = 0x00000002,
  MFNET_AUTHENTICATION_LOGGED_ON_USER 
} MFNetAuthenticationFlags;

typedef enum _MFNetCredentialOptions {
  MFNET_CREDENTIAL_SAVE               = 0x00000001,
  MFNET_CREDENTIAL_DONT_CACHE         = 0x00000002,
  MFNET_CREDENTIAL_ALLOW_CLEAR_TEXT   = 0x00000004 
} MFNetCredentialOptions;

typedef enum _MFNetCredentialRequirements {
  REQUIRE_PROMPT          = 0x00000001,
  REQUIRE_SAVE_SELECTED   = 0x00000002 
} MFNetCredentialRequirements;

typedef enum _MFNETSOURCE_CACHE_STATE {
  MFNETSOURCE_CACHE_UNAVAILABLE,
  MFNETSOURCE_CACHE_ACTIVE_WRITING,
  MFNETSOURCE_CACHE_ACTIVE_COMPLETE 
} MFNETSOURCE_CACHE_STATE;

typedef enum _MFNETSOURCE_PROTOCOL_TYPE {
  MFNETSOURCE_UNDEFINED   = 0x0,
  MFNETSOURCE_HTTP        = 0x1,
  MFNETSOURCE_RTSP        = 0x2,
  MFNETSOURCE_FILE        = 0x3,
  MFNETSOURCE_MULTICAST   = 0x4 
} MFNETSOURCE_PROTOCOL_TYPE;

typedef enum _MFNETSOURCE_STATISTICS_IDS {
  MFNETSOURCE_RECVPACKETS_ID                = 0,
  MFNETSOURCE_LOSTPACKETS_ID,
  MFNETSOURCE_RESENDSREQUESTED_ID,
  MFNETSOURCE_RESENDSRECEIVED_ID,
  MFNETSOURCE_RECOVEREDBYECCPACKETS_ID,
  MFNETSOURCE_RECOVEREDBYRTXPACKETS_ID,
  MFNETSOURCE_OUTPACKETS_ID,
  MFNETSOURCE_RECVRATE_ID,
  MFNETSOURCE_AVGBANDWIDTHBPS_ID,
  MFNETSOURCE_BYTESRECEIVED_ID,
  MFNETSOURCE_PROTOCOL_ID,
  MFNETSOURCE_TRANSPORT_ID,
  MFNETSOURCE_CACHE_STATE_ID,
  MFNETSOURCE_LINKBANDWIDTH_ID,
  MFNETSOURCE_CONTENTBITRATE_ID,
  MFNETSOURCE_SPEEDFACTOR_ID,
  MFNETSOURCE_BUFFERSIZE_ID,
  MFNETSOURCE_BUFFERPROGRESS_ID,
  MFNETSOURCE_LASTBWSWITCHTS_ID,
  MFNETSOURCE_SEEKRANGESTART_ID,
  MFNETSOURCE_SEEKRANGEEND_ID,
  MFNETSOURCE_BUFFERINGCOUNT_ID,
  MFNETSOURCE_INCORRECTLYSIGNEDPACKETS_ID,
  MFNETSOURCE_SIGNEDSESSION_ID,
  MFNETSOURCE_MAXBITRATE_ID,
  MFNETSOURCE_RECEPTION_QUALITY_ID,
  MFNETSOURCE_RECOVEREDPACKETS_ID,
  MFNETSOURCE_VBR_ID,
  MFNETSOURCE_DOWNLOADPROGRESS_ID 
} MFNETSOURCE_STATISTICS_IDS;

typedef enum _MFNETSOURCE_TRANSPORT_TYPE {
  MFNETSOURCE_UDP,
  MFNETSOURCE_TCP 
} MFNETSOURCE_TRANSPORT_TYPE;

typedef enum MFPMPSESSION_CREATION_FLAGS {
  MFPMPSESSION_UNPROTECTED_PROCESS   = 0x1 
} MFPMPSESSION_CREATION_FLAGS;

typedef enum MF_OBJECT_TYPE {
  MF_OBJECT_MEDIASOURCE,
  MF_OBJECT_BYTESTREAM,
  MF_OBJECT_INVALID 
} MF_OBJECT_TYPE;

typedef enum _MFPOLICYMANAGER_ACTION {
  PEACTION_NO          = 0,
  PEACTION_PLAY        = 1,
  PEACTION_COPY        = 2,
  PEACTION_EXPORT      = 3,
  PEACTION_EXTRACT     = 4,
  PEACTION_RESERVED1   = 5,
  PEACTION_RESERVED2   = 6,
  PEACTION_RESERVED3   = 7,
  PEACTION_LAST        = 7 
} MFPOLICYMANAGER_ACTION;

typedef enum _MFRATE_DIRECTION {
  MFRATE_FORWARD,
  MFRATE_REVERSE 
} MFRATE_DIRECTION;

typedef enum _MFSequencerTopologyFlags {
  SequencerTopologyFlags_Last   = 0x00000001 
} MFSequencerTopologyFlags;

typedef enum MFSESSION_GETFULLTOPOLOGY_FLAGS {
  MFSESSION_GETFULLTOPOLOGY_CURRENT 
} MFSESSION_GETFULLTOPOLOGY_FLAGS;

typedef enum MFSESSION_SETTOPOLOGY_FLAGS {
  MFSESSION_SETTOPOLOGY_IMMEDIATE       = 0x1,
  MFSESSION_SETTOPOLOGY_NORESOLUTION    = 0x2,
  MFSESSION_SETTOPOLOGY_CLEAR_CURRENT   = 0x4 
} MFSESSION_SETTOPOLOGY_FLAGS;

typedef enum _MFSHUTDOWN_STATUS {
  MFSHUTDOWN_INITIATED,
  MFSHUTDOWN_COMPLETED 
} MFSHUTDOWN_STATUS;

typedef enum _MFSINK_WMDRMACTION {
  MFSINK_WMDRMACTION_UNDEFINED    = 0,
  MFSINK_WMDRMACTION_ENCODE       = 1,
  MFSINK_WMDRMACTION_TRANSCODE    = 2,
  MFSINK_WMDRMACTION_TRANSCRYPT   = 3,
  MFSINK_WMDRMACTION_LAST         = 3 
} MFSINK_WMDRMACTION;

typedef enum MFSTREAMSINK_MARKER_TYPE {
  MFSTREAMSINK_MARKER_DEFAULT,
  MFSTREAMSINK_MARKER_ENDOFSEGMENT,
  MFSTREAMSINK_MARKER_TICK,
  MFSTREAMSINK_MARKER_EVENT 
} MFSTREAMSINK_MARKER_TYPE;

typedef enum MFTIMER_FLAGS {
  MFTIMER_RELATIVE   = 0x00000001 
} MFTIMER_FLAGS;

#if (_WIN32_WINNT >= 0x0601)

typedef enum MFTOPLOGY_DXVA_MODE {
  MFTOPOLOGY_DXVA_DEFAULT   = 0,
  MFTOPOLOGY_DXVA_NONE      = 1,
  MFTOPOLOGY_DXVA_FULL      = 2 
} MFTOPOLOGY_DXVA_MODE;

typedef enum MFTOPOLOGY_HARDWARE_MODE {
  MFTOPOLOGY_HWMODE_SOFTWARE_ONLY   = 0,
  MFTOPOLOGY_HWMODE_USE_HARDWARE    = 1 
} MFTOPOLOGY_HARDWARE_MODE;

typedef struct _MFT_REGISTRATION_INFO {
  CLSID                  clsid;
  GUID                   guidCategory;
  UINT32                 uiFlags;
  LPCWSTR                pszName;
  DWORD                  cInTypes;
  MFT_REGISTER_TYPE_INFO *pInTypes;
  DWORD                  cOutTypes;
  MFT_REGISTER_TYPE_INFO *pOutTypes;
} MFT_REGISTRATION_INFO;

#endif /*(_WIN32_WINNT >= 0x0601)*/

typedef struct _ASFFlatPicture {
  BYTE  bPictureType;
  DWORD dwDataLen;
} ASF_FLAT_PICTURE;

typedef struct _ASFFlatSynchronisedLyrics {
  BYTE  bTimeStampFormat;
  BYTE  bContentType;
  DWORD dwLyricsLen;
} ASF_FLAT_SYNCHRONISED_LYRICS;

typedef enum SAMPLE_PROTECTION_VERSION {
  SAMPLE_PROTECTION_VERSION_NO           = 0,
  SAMPLE_PROTECTION_VERSION_BASIC_LOKI   = 1,
  SAMPLE_PROTECTION_VERSION_SCATTER      = 2,
  SAMPLE_PROTECTION_VERSION_RC4          = 3 
} SAMPLE_PROTECTION_VERSION;

typedef struct _MF_LEAKY_BUCKET_PAIR {
  DWORD dwBitrate;
  DWORD msBufferWindow;
} MF_LEAKY_BUCKET_PAIR;

typedef struct _MFBYTESTREAM_BUFFERING_PARAMS {
  QWORD                cbTotalFileSize;
  QWORD                cbPlayableDataSize;
  MF_LEAKY_BUCKET_PAIR *prgBuckets;
  DWORD                cBuckets;
  QWORD                qwNetBufferingTime;
  QWORD                qwExtraBufferingTimeDuringSeek;
  QWORD                qwPlayDuration;
  float                dRate;
} MFBYTESTREAM_BUFFERING_PARAMS;

typedef struct _MFCLOCK_PROPERTIES {
  unsigned __int64 qwCorrelationRate;
  GUID             guidClockId;
  DWORD            dwClockFlags;
  unsigned __int64 qwClockFrequency;
  DWORD            dwClockTolerance;
  DWORD            dwClockJitter;
} MFCLOCK_PROPERTIES;

typedef struct _MFINPUTTRUSTAUTHORITY_ACTION {
  MFPOLICYMANAGER_ACTION Action;
  BYTE                   *pbTicket;
  DWORD                  cbTicket;
} MFINPUTTRUSTAUTHORITY_ACCESS_ACTION;

typedef struct _MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS {
  DWORD                               dwSize;
  DWORD                               dwVer;
  DWORD                               cbSignatureOffset;
  DWORD                               cbSignatureSize;
  DWORD                               cbExtensionOffset;
  DWORD                               cbExtensionSize;
  DWORD                               cActions;
  MFINPUTTRUSTAUTHORITY_ACCESS_ACTION rgOutputActions[1];
} MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS;

typedef struct _MFRR_COMPONENT_HASH_INFO {
  DWORD ulReason;
  WCHAR rgHeaderHash[MAX_HASH_LEN];
  WCHAR rgPublicKeyHash[MAX_HASH_LEN];
  WCHAR wszName[MAX_PATH];
} MFRR_COMPONENT_HASH_INFO, *PMFRR_COMPONENT_HASH_INFO;

typedef struct _MFNetCredentialManagerGetParam {
  HRESULT hrOp;
  WINBOOL    fAllowLoggedOnUser;
  WINBOOL    fClearTextPackage;
  LPCWSTR pszUrl;
  LPCWSTR pszSite;
  LPCWSTR pszRealm;
  LPCWSTR pszPackage;
  LONG    nRetries;
} MFNetCredentialManagerGetParam;

#undef  INTERFACE
#define INTERFACE IMFByteStreamBuffering
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFByteStreamBuffering,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFByteStreamBuffering methods */
    STDMETHOD_(HRESULT,EnableBuffering)(THIS_ WINBOOL fEnable) PURE;
    STDMETHOD_(HRESULT,SetBufferingParams)(THIS_ MFBYTESTREAM_BUFFERING_PARAMS *pParams) PURE;
    STDMETHOD_(HRESULT,StopBuffering)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFByteStreamBuffering_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFByteStreamBuffering_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFByteStreamBuffering_Release(This) (This)->lpVtbl->Release(This)
#define IMFByteStreamBuffering_EnableBuffering(This,fEnable) (This)->lpVtbl->EnableBuffering(This,fEnable)
#define IMFByteStreamBuffering_SetBufferingParams(This,pParams) (This)->lpVtbl->SetBufferingParams(This,pParams)
#define IMFByteStreamBuffering_StopBuffering() (This)->lpVtbl->StopBuffering(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFPresentationDescriptor
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFPresentationDescriptor,IMFAttributes)
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

    /* IMFPresentationDescriptor methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFPresentationDescriptor **ppPresentationDescriptor) PURE;
    STDMETHOD_(HRESULT,DeselectStream)(THIS_ DWORD dwDescriptorIndex) PURE;
    STDMETHOD_(HRESULT,GetStreamDescriptorByIndex)(THIS_ DWORD dwIndex,BOOL *pfSelected,IMFStreamDescriptor **ppDescriptor) PURE;
    STDMETHOD_(HRESULT,GetStreamDescriptorCount)(THIS_ DWORD *pdwDescriptorCount) PURE;
    STDMETHOD_(HRESULT,SelectStream)(THIS_ DWORD dwDescriptorIndex) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFPresentationDescriptor_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFPresentationDescriptor_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFPresentationDescriptor_Release(This) (This)->lpVtbl->Release(This)
#define IMFPresentationDescriptor_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFPresentationDescriptor_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFPresentationDescriptor_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFPresentationDescriptor_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFPresentationDescriptor_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFPresentationDescriptor_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFPresentationDescriptor_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFPresentationDescriptor_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFPresentationDescriptor_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFPresentationDescriptor_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFPresentationDescriptor_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFPresentationDescriptor_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFPresentationDescriptor_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFPresentationDescriptor_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFPresentationDescriptor_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFPresentationDescriptor_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFPresentationDescriptor_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFPresentationDescriptor_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFPresentationDescriptor_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFPresentationDescriptor_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFPresentationDescriptor_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFPresentationDescriptor_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFPresentationDescriptor_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFPresentationDescriptor_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFPresentationDescriptor_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFPresentationDescriptor_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFPresentationDescriptor_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFPresentationDescriptor_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFPresentationDescriptor_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFPresentationDescriptor_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFPresentationDescriptor_Clone(This,ppPresentationDescriptor) (This)->lpVtbl->Clone(This,ppPresentationDescriptor)
#define IMFPresentationDescriptor_DeselectStream(This,dwDescriptorIndex) (This)->lpVtbl->DeselectStream(This,dwDescriptorIndex)
#define IMFPresentationDescriptor_GetStreamDescriptorByIndex(This,dwIndex,pfSelected,ppDescriptor) (This)->lpVtbl->GetStreamDescriptorByIndex(This,dwIndex,pfSelected,ppDescriptor)
#define IMFPresentationDescriptor_GetStreamDescriptorCount(This,pdwDescriptorCount) (This)->lpVtbl->GetStreamDescriptorCount(This,pdwDescriptorCount)
#define IMFPresentationDescriptor_SelectStream(This,dwDescriptorIndex) (This)->lpVtbl->SelectStream(This,dwDescriptorIndex)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)
#undef  INTERFACE
#define INTERFACE IMFByteStreamCacheControl
DECLARE_INTERFACE_(IMFByteStreamCacheControl,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFByteStreamCacheControl methods */
    STDMETHOD_(HRESULT,StopBackgroundTransfer)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFByteStreamCacheControl_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFByteStreamCacheControl_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFByteStreamCacheControl_Release(This) (This)->lpVtbl->Release(This)
#define IMFByteStreamCacheControl_StopBackgroundTransfer() (This)->lpVtbl->StopBackgroundTransfer(This)
#endif /*COBJMACROS*/
#endif /*(_WIN32_WINNT >= 0x0601)*/

#define MF_1_BYTE_ALIGNMENT     0x00000000
#define MF_2_BYTE_ALIGNMENT     0x00000001
#define MF_4_BYTE_ALIGNMENT     0x00000003
#define MF_8_BYTE_ALIGNMENT     0x00000007
#define MF_16_BYTE_ALIGNMENT    0x0000000F
#define MF_32_BYTE_ALIGNMENT    0x0000001F
#define MF_64_BYTE_ALIGNMENT    0x0000003F
#define MF_128_BYTE_ALIGNMENT   0x0000007F
#define MF_256_BYTE_ALIGNMENT   0x000000FF
#define MF_512_BYTE_ALIGNMENT   0x000001FF

#define MEDIASINK_FIXED_STREAMS                 0x00000001
#define MEDIASINK_CANNOT_MATCH_CLOCK            0x00000002
#define MEDIASINK_RATELESS                      0x00000004
#define MEDIASINK_CLOCK_REQUIRED                0x00000008
#define MEDIASINK_CAN_PREROLL                   0x00000010
#define MEDIASINK_REQUIRE_REFERENCE_MEDIATYPE   0x00000020

#define MF_RESOLUTION_MEDIASOURCE                                           0x00000001
#define MF_RESOLUTION_BYTESTREAM                                            0x00000002
#define MF_RESOLUTION_CONTENT_DOES_NOT_HAVE_TO_MATCH_EXTENSION_OR_MIME_TYPE 0x00000010
#define MF_RESOLUTION_KEEP_BYTE_STREAM_ALIVE_ON_FAIL                        0x00000020
#define MF_RESOLUTION_READ                                                  0x00010000
#define MF_RESOLUTION_WRITE                                                 0x00020000

#undef  INTERFACE
#define INTERFACE IMFClockStateSink
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFClockStateSink,IUnknown)
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

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFClockStateSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFClockStateSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFClockStateSink_Release(This) (This)->lpVtbl->Release(This)
#define IMFClockStateSink_OnClockPause(This,hnsSystemTime) (This)->lpVtbl->OnClockPause(This,hnsSystemTime)
#define IMFClockStateSink_OnClockRestart(This,hnsSystemTime) (This)->lpVtbl->OnClockRestart(This,hnsSystemTime)
#define IMFClockStateSink_OnClockSetRate(This,hnsSystemTime,flRate) (This)->lpVtbl->OnClockSetRate(This,hnsSystemTime,flRate)
#define IMFClockStateSink_OnClockStart(This,hnsSystemTime,llClockStartOffset) (This)->lpVtbl->OnClockStart(This,hnsSystemTime,llClockStartOffset)
#define IMFClockStateSink_OnClockStop(This,hnssSystemTime) (This)->lpVtbl->OnClockStop(This,hnssSystemTime)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFClock
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFClock,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFClock methods */
    STDMETHOD_(HRESULT,GetClockCharacteristics)(THIS_ DWORD *pdwCharacteristics) PURE;
    STDMETHOD_(HRESULT,GetContinuityKey)(THIS_ DWORD *pdwContinuityKey) PURE;
    STDMETHOD_(HRESULT,GetCorrelatedTime)(THIS_ DWORD dwReserved,LONGLONG *pllClockTime,MFTIME *phnsSystemTime) PURE;
    STDMETHOD_(HRESULT,GetProperties)(THIS_ MFCLOCK_PROPERTIES *pClockProperties) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ DWORD dwReserved,MFCLOCK_STATE *peClockState) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFClock_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFClock_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFClock_Release(This) (This)->lpVtbl->Release(This)
#define IMFClock_GetClockCharacteristics(This,pdwCharacteristics) (This)->lpVtbl->GetClockCharacteristics(This,pdwCharacteristics)
#define IMFClock_GetContinuityKey(This,pdwContinuityKey) (This)->lpVtbl->GetContinuityKey(This,pdwContinuityKey)
#define IMFClock_GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime) (This)->lpVtbl->GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime)
#define IMFClock_GetProperties(This,pClockProperties) (This)->lpVtbl->GetProperties(This,pClockProperties)
#define IMFClock_GetState(This,dwReserved,peClockState) (This)->lpVtbl->GetState(This,dwReserved,peClockState)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFPresentationTimeSource
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFPresentationTimeSource,IMFClock)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFClock methods */
    STDMETHOD_(HRESULT,GetClockCharacteristics)(THIS_ DWORD *pdwCharacteristics) PURE;
    STDMETHOD_(HRESULT,GetContinuityKey)(THIS_ DWORD *pdwContinuityKey) PURE;
    STDMETHOD_(HRESULT,GetCorrelatedTime)(THIS_ DWORD dwReserved,LONGLONG *pllClockTime,MFTIME *phnsSystemTime) PURE;
    STDMETHOD_(HRESULT,GetProperties)(THIS_ MFCLOCK_PROPERTIES *pClockProperties) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ DWORD dwReserved,MFCLOCK_STATE *peClockState) PURE;

    /* IMFPresentationTimeSource methods */
    STDMETHOD_(HRESULT,GetUnderlyingClock)(THIS_ IMFClock **ppClock) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFPresentationTimeSource_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFPresentationTimeSource_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFPresentationTimeSource_Release(This) (This)->lpVtbl->Release(This)
#define IMFPresentationTimeSource_GetClockCharacteristics(This,pdwCharacteristics) (This)->lpVtbl->GetClockCharacteristics(This,pdwCharacteristics)
#define IMFPresentationTimeSource_GetContinuityKey(This,pdwContinuityKey) (This)->lpVtbl->GetContinuityKey(This,pdwContinuityKey)
#define IMFPresentationTimeSource_GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime) (This)->lpVtbl->GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime)
#define IMFPresentationTimeSource_GetProperties(This,pClockProperties) (This)->lpVtbl->GetProperties(This,pClockProperties)
#define IMFPresentationTimeSource_GetState(This,dwReserved,peClockState) (This)->lpVtbl->GetState(This,dwReserved,peClockState)
#define IMFPresentationTimeSource_GetUnderlyingClock(This,ppClock) (This)->lpVtbl->GetUnderlyingClock(This,ppClock)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFPresentationClock
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFPresentationClock,IMFClock)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFClock methods */
    STDMETHOD_(HRESULT,GetClockCharacteristics)(THIS_ DWORD *pdwCharacteristics) PURE;
    STDMETHOD_(HRESULT,GetContinuityKey)(THIS_ DWORD *pdwContinuityKey) PURE;
    STDMETHOD_(HRESULT,GetCorrelatedTime)(THIS_ DWORD dwReserved,LONGLONG *pllClockTime,MFTIME *phnsSystemTime) PURE;
    STDMETHOD_(HRESULT,GetProperties)(THIS_ MFCLOCK_PROPERTIES *pClockProperties) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ DWORD dwReserved,MFCLOCK_STATE *peClockState) PURE;

    /* IMFPresentationClock methods */
    STDMETHOD_(HRESULT,AddClockStateSink)(THIS_ IMFClockStateSink *pStateSink) PURE;
    STDMETHOD_(HRESULT,GetTime)(THIS_ MFTIME *phnsClockTime) PURE;
    STDMETHOD_(HRESULT,GetTimeSource)(THIS_ IMFPresentationTimeSource **ppTimeSource) PURE;
    STDMETHOD_(HRESULT,Pause)(THIS) PURE;
    STDMETHOD_(HRESULT,RemoveClockStateSink)(THIS_ IMFClockStateSink *pStateSink) PURE;
    STDMETHOD_(HRESULT,SetTimeSource)(THIS_ IMFPresentationTimeSource *pTimeSource) PURE;
    STDMETHOD_(HRESULT,Start)(THIS_ LONGLONG llClockStartOffset) PURE;
    STDMETHOD_(HRESULT,Stop)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFPresentationClock_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFPresentationClock_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFPresentationClock_Release(This) (This)->lpVtbl->Release(This)
#define IMFPresentationClock_GetClockCharacteristics(This,pdwCharacteristics) (This)->lpVtbl->GetClockCharacteristics(This,pdwCharacteristics)
#define IMFPresentationClock_GetContinuityKey(This,pdwContinuityKey) (This)->lpVtbl->GetContinuityKey(This,pdwContinuityKey)
#define IMFPresentationClock_GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime) (This)->lpVtbl->GetCorrelatedTime(This,dwReserved,pllClockTime,phnsSystemTime)
#define IMFPresentationClock_GetProperties(This,pClockProperties) (This)->lpVtbl->GetProperties(This,pClockProperties)
#define IMFPresentationClock_GetState(This,dwReserved,peClockState) (This)->lpVtbl->GetState(This,dwReserved,peClockState)
#define IMFPresentationClock_AddClockStateSink(This,pStateSink) (This)->lpVtbl->AddClockStateSink(This,pStateSink)
#define IMFPresentationClock_GetTime(This,phnsClockTime) (This)->lpVtbl->GetTime(This,phnsClockTime)
#define IMFPresentationClock_GetTimeSource(This,ppTimeSource) (This)->lpVtbl->GetTimeSource(This,ppTimeSource)
#define IMFPresentationClock_Pause() (This)->lpVtbl->Pause(This)
#define IMFPresentationClock_RemoveClockStateSink(This,pStateSink) (This)->lpVtbl->RemoveClockStateSink(This,pStateSink)
#define IMFPresentationClock_SetTimeSource(This,pTimeSource) (This)->lpVtbl->SetTimeSource(This,pTimeSource)
#define IMFPresentationClock_Start(This,llClockStartOffset) (This)->lpVtbl->Start(This,llClockStartOffset)
#define IMFPresentationClock_Stop() (This)->lpVtbl->Stop(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFStreamSink
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFStreamSink,IMFMediaEventGenerator)
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

    /* IMFStreamSink methods */
    STDMETHOD_(HRESULT,Flush)(THIS) PURE;
    STDMETHOD_(HRESULT,GetIdentifier)(THIS_ DWORD *pdwIdentifier) PURE;
    STDMETHOD_(HRESULT,GetMediaSink)(THIS_ IMFMediaSink **ppMediaSink) PURE;
    STDMETHOD_(HRESULT,GetMediaTypeHandler)(THIS_ IMFMediaTypeHandler **ppHandler) PURE;
    STDMETHOD_(HRESULT,PlaceMarker)(THIS_ MFSTREAMSINK_MARKER_TYPE eMarkerType,const PROPVARIANT *pvarMarkerValue,const PROPVARIANT *pvarContextValue) PURE;
    STDMETHOD_(HRESULT,ProcessSample)(THIS_ IMFSample *pSample) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFStreamSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFStreamSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFStreamSink_Release(This) (This)->lpVtbl->Release(This)
#define IMFStreamSink_BeginGetEvent(This,pCallback,punkState) (This)->lpVtbl->BeginGetEvent(This,pCallback,punkState)
#define IMFStreamSink_EndGetEvent(This,pResult,ppEvent) (This)->lpVtbl->EndGetEvent(This,pResult,ppEvent)
#define IMFStreamSink_GetEvent(This,dwFlags,ppEvent) (This)->lpVtbl->GetEvent(This,dwFlags,ppEvent)
#define IMFStreamSink_QueueEvent(This,met,guidExtendedType,hrStatus,pvValue) (This)->lpVtbl->QueueEvent(This,met,guidExtendedType,hrStatus,pvValue)
#define IMFStreamSink_RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent) (This)->lpVtbl->RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent)
#define IMFStreamSink_Flush() (This)->lpVtbl->Flush(This)
#define IMFStreamSink_GetIdentifier(This,pdwIdentifier) (This)->lpVtbl->GetIdentifier(This,pdwIdentifier)
#define IMFStreamSink_GetMediaSink(This,ppMediaSink) (This)->lpVtbl->GetMediaSink(This,ppMediaSink)
#define IMFStreamSink_GetMediaTypeHandler(This,ppHandler) (This)->lpVtbl->GetMediaTypeHandler(This,ppHandler)
#define IMFStreamSink_PlaceMarker(This,eMarkerType,pvarMarkerValue,pvarContextValue) (This)->lpVtbl->PlaceMarker(This,eMarkerType,pvarMarkerValue,pvarContextValue)
#define IMFStreamSink_ProcessSample(This,pSample) (This)->lpVtbl->ProcessSample(This,pSample)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaSink
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaSink,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFMediaSink methods */
    STDMETHOD_(HRESULT,AddStreamSink)(THIS_ DWORD dwStreamSinkIdentifier,IMFMediaType *pMediaType,IMFStreamSink **ppStreamSink) PURE;
    STDMETHOD_(HRESULT,GetCharacteristics)(THIS_ DWORD *pdwCharacteristics) PURE;
    STDMETHOD_(HRESULT,GetPresentationClock)(THIS_ IMFPresentationClock **ppPresentationClock) PURE;
    STDMETHOD_(HRESULT,GetStreamSinkById)(THIS_ DWORD dwStreamSinkIdentifier,IMFStreamSink **ppStreamSink) PURE;
    STDMETHOD_(HRESULT,GetStreamSinkByIndex)(THIS_ DWORD dwIndex,IMFStreamSink **ppStreamSink) PURE;
    STDMETHOD_(HRESULT,GetStreamSinkCount)(THIS_ DWORD *pcStreamSinkCount) PURE;
    STDMETHOD_(HRESULT,RemoveStreamSink)(THIS_ DWORD dwStreamSinkIdentifier) PURE;
    STDMETHOD_(HRESULT,SetPresentationClock)(THIS_ IMFPresentationClock *pPresentationClock) PURE;
    STDMETHOD_(HRESULT,Shutdown)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaSink_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaSink_AddStreamSink(This,dwStreamSinkIdentifier,pMediaType,ppStreamSink) (This)->lpVtbl->AddStreamSink(This,dwStreamSinkIdentifier,pMediaType,ppStreamSink)
#define IMFMediaSink_GetCharacteristics(This,pdwCharacteristics) (This)->lpVtbl->GetCharacteristics(This,pdwCharacteristics)
#define IMFMediaSink_GetPresentationClock(This,ppPresentationClock) (This)->lpVtbl->GetPresentationClock(This,ppPresentationClock)
#define IMFMediaSink_GetStreamSinkById(This,dwStreamSinkIdentifier,ppStreamSink) (This)->lpVtbl->GetStreamSinkById(This,dwStreamSinkIdentifier,ppStreamSink)
#define IMFMediaSink_GetStreamSinkByIndex(This,dwIndex,ppStreamSink) (This)->lpVtbl->GetStreamSinkByIndex(This,dwIndex,ppStreamSink)
#define IMFMediaSink_GetStreamSinkCount(This,pcStreamSinkCount) (This)->lpVtbl->GetStreamSinkCount(This,pcStreamSinkCount)
#define IMFMediaSink_RemoveStreamSink(This,dwStreamSinkIdentifier) (This)->lpVtbl->RemoveStreamSink(This,dwStreamSinkIdentifier)
#define IMFMediaSink_SetPresentationClock(This,pPresentationClock) (This)->lpVtbl->SetPresentationClock(This,pPresentationClock)
#define IMFMediaSink_Shutdown() (This)->lpVtbl->Shutdown(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSchemeHandler
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSchemeHandler,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFSchemeHandler methods */
    STDMETHOD_(HRESULT,BeginCreateObject)(THIS_ LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,IUnknown **ppIUnknownCancelCookie,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,CancelObjectCreation)(THIS_ IUnknown *pIUnknownCancelCookie) PURE;
    STDMETHOD_(HRESULT,EndCreateObject)(THIS_ IMFAsyncResult *pResult,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSchemeHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSchemeHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSchemeHandler_Release(This) (This)->lpVtbl->Release(This)
#define IMFSchemeHandler_BeginCreateObject(This,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState) (This)->lpVtbl->BeginCreateObject(This,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState)
#define IMFSchemeHandler_CancelObjectCreation(This,pIUnknownCancelCookie) (This)->lpVtbl->CancelObjectCreation(This,pIUnknownCancelCookie)
#define IMFSchemeHandler_EndCreateObject(This,pResult,pObjectType,ppObject) (This)->lpVtbl->EndCreateObject(This,pResult,pObjectType,ppObject)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaSource
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaSource,IMFMediaEventGenerator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFMediaSource methods */
    STDMETHOD_(HRESULT,CreatePresentationDescriptor)(THIS_ IMFPresentationDescriptor **ppPresentationDescriptor) PURE;
    STDMETHOD_(HRESULT,GetCharacteristics)(THIS_ DWORD *pdwCharacteristics) PURE;
    STDMETHOD_(HRESULT,Pause)(THIS) PURE;
    STDMETHOD_(HRESULT,RemoteCreatePresentationDescriptor)(THIS_ DWORD *pcbPD,BYTE **pbPD,IMFPresentationDescriptor **ppRemotePD) PURE;
    STDMETHOD_(HRESULT,Shutdown)(THIS) PURE;
    //[call_as(CreatePresentationDescriptor)]
    STDMETHOD_(HRESULT,Start)(THIS_ IMFPresentationDescriptor *pPresentationDescriptor,const GUID *pguidTimeFormat,const PROPVARIANT *pvarStartPosition) PURE;
    STDMETHOD_(HRESULT,Stop)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaSource_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaSource_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaSource_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaSource_CreatePresentationDescriptor(This,ppPresentationDescriptor) (This)->lpVtbl->CreatePresentationDescriptor(This,ppPresentationDescriptor)
#define IMFMediaSource_GetCharacteristics(This,pdwCharacteristics) (This)->lpVtbl->GetCharacteristics(This,pdwCharacteristics)
#define IMFMediaSource_Pause() (This)->lpVtbl->Pause(This)
#define IMFMediaSource_RemoteCreatePresentationDescriptor(This,pcbPD,pbPD,ppRemotePD) (This)->lpVtbl->RemoteCreatePresentationDescriptor(This,pcbPD,pbPD,ppRemotePD)
#define IMFMediaSource_Shutdown() (This)->lpVtbl->Shutdown(This)
#define IMFMediaSource_Start(This,pPresentationDescriptor,pguidTimeFormat,pvarStartPosition) (This)->lpVtbl->Start(This,pPresentationDescriptor,pguidTimeFormat,pvarStartPosition)
#define IMFMediaSource_Stop() (This)->lpVtbl->Stop(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFPMPServer
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFPMPServer,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFPMPServer methods */
    STDMETHOD_(HRESULT,CreateObjectByCLSID)(THIS_ REFCLSID clsid,REFIID riid,void **ppObject) PURE;
    STDMETHOD_(HRESULT,LockProcess)(THIS) PURE;
    STDMETHOD_(HRESULT,UnlockProcess)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFPMPServer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFPMPServer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFPMPServer_Release(This) (This)->lpVtbl->Release(This)
#define IMFPMPServer_CreateObjectByCLSID(This,clsid,riid,ppObject) (This)->lpVtbl->CreateObjectByCLSID(This,clsid,riid,ppObject)
#define IMFPMPServer_LockProcess() (This)->lpVtbl->LockProcess(This)
#define IMFPMPServer_UnlockProcess() (This)->lpVtbl->UnlockProcess(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFTopologyNode
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTopologyNode,IMFAttributes)
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

    /* IMFTopologyNode methods */
    STDMETHOD_(HRESULT,CloneFrom)(THIS_ IMFTopologyNode *pNode) PURE;
    STDMETHOD_(HRESULT,ConnectOutput)(THIS_ DWORD dwOutputIndex,IMFTopologyNode *pDownstreamNode,DWORD dwInputIndexOnDownstreamNode) PURE;
    STDMETHOD_(HRESULT,DisconnectOutput)(THIS_ DWORD dwOutputIndex) PURE;
    STDMETHOD_(HRESULT,GetInput)(THIS_ DWORD dwInputIndex,IMFTopologyNode **ppUpstreamNode,DWORD *pdwOutputIndexOnUpstreamNode) PURE;
    STDMETHOD_(HRESULT,GetInputCount)(THIS_ DWORD *pcInputs) PURE;
    STDMETHOD_(HRESULT,GetInputPrefType)(THIS_ DWORD dwInputIndex,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetNodeType)(THIS_ MF_TOPOLOGY_TYPE *pType) PURE;
    STDMETHOD_(HRESULT,GetObject)(THIS_ IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,GetOutput)(THIS_ DWORD dwOutputIndex,IMFTopologyNode **ppDownstreamNode,DWORD *pdwInputIndexOnDownstreamNode) PURE;
    STDMETHOD_(HRESULT,GetOutputCount)(THIS_ DWORD *pcOutputs) PURE;
    STDMETHOD_(HRESULT,GetOutputPrefType)(THIS_ DWORD dwOutputIndex,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetTopoNodeID)(THIS_ TOPOID *pID) PURE;
    /* [call_as(GetInputPrefType)] */
    STDMETHOD_(HRESULT,RemoteGetInputPrefType)(THIS_ DWORD dwInputIndex,DWORD *pcbData,BYTE **ppbData) PURE;
    /* [call_as(GetOutputPrefType)] */
    STDMETHOD_(HRESULT,RemoteGetOutputPrefType)(THIS_ DWORD dwOutputIndex,DWORD *pcbData,BYTE **ppbData) PURE;
    STDMETHOD_(HRESULT,SetInputPrefType)(THIS_ DWORD dwInputIndex,IMFMediaType *pType) PURE;
    STDMETHOD_(HRESULT,SetObject)(THIS_ IUnknown *pObject) PURE;
    STDMETHOD_(HRESULT,SetOutputPrefType)(THIS_ DWORD dwOutputIndex,IMFMediaType *pType) PURE;
    STDMETHOD_(HRESULT,SetTopoNodeID)(THIS_ TOPOID llTopoID) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFTopologyNode_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTopologyNode_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTopologyNode_Release(This) (This)->lpVtbl->Release(This)
#define IMFTopologyNode_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFTopologyNode_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFTopologyNode_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFTopologyNode_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFTopologyNode_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFTopologyNode_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFTopologyNode_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFTopologyNode_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFTopologyNode_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFTopologyNode_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFTopologyNode_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFTopologyNode_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFTopologyNode_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFTopologyNode_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFTopologyNode_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFTopologyNode_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFTopologyNode_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFTopologyNode_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFTopologyNode_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFTopologyNode_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFTopologyNode_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFTopologyNode_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFTopologyNode_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFTopologyNode_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFTopologyNode_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFTopologyNode_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFTopologyNode_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFTopologyNode_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFTopologyNode_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFTopologyNode_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFTopologyNode_CloneFrom(This,pNode) (This)->lpVtbl->CloneFrom(This,pNode)
#define IMFTopologyNode_ConnectOutput(This,dwOutputIndex,pDownstreamNode,dwInputIndexOnDownstreamNode) (This)->lpVtbl->ConnectOutput(This,dwOutputIndex,pDownstreamNode,dwInputIndexOnDownstreamNode)
#define IMFTopologyNode_DisconnectOutput(This,dwOutputIndex) (This)->lpVtbl->DisconnectOutput(This,dwOutputIndex)
#define IMFTopologyNode_GetInput(This,dwInputIndex,ppUpstreamNode,pdwOutputIndexOnUpstreamNode) (This)->lpVtbl->GetInput(This,dwInputIndex,ppUpstreamNode,pdwOutputIndexOnUpstreamNode)
#define IMFTopologyNode_GetInputCount(This,pcInputs) (This)->lpVtbl->GetInputCount(This,pcInputs)
#define IMFTopologyNode_GetInputPrefType(This,dwInputIndex,ppType) (This)->lpVtbl->GetInputPrefType(This,dwInputIndex,ppType)
#define IMFTopologyNode_GetNodeType(This,pType) (This)->lpVtbl->GetNodeType(This,pType)
#define IMFTopologyNode_GetObject(This,ppObject) (This)->lpVtbl->GetObject(This,ppObject)
#define IMFTopologyNode_GetOutput(This,dwOutputIndex,ppDownstreamNode,pdwInputIndexOnDownstreamNode) (This)->lpVtbl->GetOutput(This,dwOutputIndex,ppDownstreamNode,pdwInputIndexOnDownstreamNode)
#define IMFTopologyNode_GetOutputCount(This,pcOutputs) (This)->lpVtbl->GetOutputCount(This,pcOutputs)
#define IMFTopologyNode_GetOutputPrefType(This,dwOutputIndex,ppType) (This)->lpVtbl->GetOutputPrefType(This,dwOutputIndex,ppType)
#define IMFTopologyNode_GetTopoNodeID(This,pID) (This)->lpVtbl->GetTopoNodeID(This,pID)
#define IMFTopologyNode_RemoteGetInputPrefType(This,dwInputIndex,pcbData,ppbData) (This)->lpVtbl->RemoteGetInputPrefType(This,dwInputIndex,pcbData,ppbData)
#define IMFTopologyNode_RemoteGetOutputPrefType(This,dwOutputIndex,pcbData,ppbData) (This)->lpVtbl->RemoteGetOutputPrefType(This,dwOutputIndex,pcbData,ppbData)
#define IMFTopologyNode_SetInputPrefType(This,dwInputIndex,pType) (This)->lpVtbl->SetInputPrefType(This,dwInputIndex,pType)
#define IMFTopologyNode_SetObject(This,pObject) (This)->lpVtbl->SetObject(This,pObject)
#define IMFTopologyNode_SetOutputPrefType(This,dwOutputIndex,pType) (This)->lpVtbl->SetOutputPrefType(This,dwOutputIndex,pType)
#define IMFTopologyNode_SetTopoNodeID(This,llTopoID) (This)->lpVtbl->SetTopoNodeID(This,llTopoID)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFTopology
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTopology,IMFAttributes)
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

    /* IMFTopology methods */
    STDMETHOD_(HRESULT,ActivateObject)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(HRESULT,DetachObject)(THIS) PURE;
    STDMETHOD_(HRESULT,ShutdownObject)(THIS) PURE;
    STDMETHOD_(HRESULT,AddNode)(THIS_ IMFTopologyNode *pNode) PURE;
    STDMETHOD_(HRESULT,Clear)(THIS) PURE;
    STDMETHOD_(HRESULT,CloneFrom)(THIS_ IMFTopology *pTopology) PURE;
    STDMETHOD_(HRESULT,GetNode)(THIS_ WORD wIndex,IMFTopologyNode **ppNode) PURE;
    STDMETHOD_(HRESULT,GetNodeByID)(THIS_ TOPOID qwTopoNodeID,IMFTopologyNode **ppNode) PURE;
    STDMETHOD_(HRESULT,GetNodeCount)(THIS_ WORD *pwNodes) PURE;
    STDMETHOD_(HRESULT,GetOutputNodeCollection)(THIS_ IMFCollection **ppCollection) PURE;
    STDMETHOD_(HRESULT,GetSourceNodeCollection)(THIS_ IMFCollection **ppCollection) PURE;
    STDMETHOD_(HRESULT,GetTopologyID)(THIS_ TOPOID *pID) PURE;
    STDMETHOD_(HRESULT,RemoveNode)(THIS_ IMFTopologyNode *pNode) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFTopology_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTopology_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTopology_Release(This) (This)->lpVtbl->Release(This)
#define IMFTopology_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFTopology_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFTopology_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFTopology_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFTopology_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFTopology_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFTopology_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFTopology_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFTopology_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFTopology_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFTopology_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFTopology_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFTopology_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFTopology_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFTopology_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFTopology_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFTopology_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFTopology_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFTopology_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFTopology_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFTopology_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFTopology_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFTopology_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFTopology_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFTopology_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFTopology_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFTopology_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFTopology_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFTopology_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFTopology_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFTopology_ActivateObject(This,riid,ppv) (This)->lpVtbl->ActivateObject(This,riid,ppv)
#define IMFTopology_DetachObject() (This)->lpVtbl->DetachObject(This)
#define IMFTopology_ShutdownObject() (This)->lpVtbl->ShutdownObject(This)
#define IMFTopology_AddNode(This,pNode) (This)->lpVtbl->AddNode(This,pNode)
#define IMFTopology_Clear() (This)->lpVtbl->Clear(This)
#define IMFTopology_CloneFrom(This,pTopology) (This)->lpVtbl->CloneFrom(This,pTopology)
#define IMFTopology_GetNode(This,wIndex,ppNode) (This)->lpVtbl->GetNode(This,wIndex,ppNode)
#define IMFTopology_GetNodeByID(This,qwTopoNodeID,ppNode) (This)->lpVtbl->GetNodeByID(This,qwTopoNodeID,ppNode)
#define IMFTopology_GetNodeCount(This,pwNodes) (This)->lpVtbl->GetNodeCount(This,pwNodes)
#define IMFTopology_GetOutputNodeCollection(This,ppCollection) (This)->lpVtbl->GetOutputNodeCollection(This,ppCollection)
#define IMFTopology_GetSourceNodeCollection(This,ppCollection) (This)->lpVtbl->GetSourceNodeCollection(This,ppCollection)
#define IMFTopology_GetTopologyID(This,pID) (This)->lpVtbl->GetTopologyID(This,pID)
#define IMFTopology_RemoveNode(This,pNode) (This)->lpVtbl->RemoveNode(This,pNode)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFTopoLoader
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTopoLoader,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFTopoLoader methods */
    STDMETHOD_(HRESULT,Load)(THIS_ IMFTopology *pInputTopo,IMFTopology **ppOutputTopo,IMFTopology *pCurrentTopo) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFTopoLoader_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTopoLoader_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTopoLoader_Release(This) (This)->lpVtbl->Release(This)
#define IMFTopoLoader_Load(This,pInputTopo,ppOutputTopo,pCurrentTopo) (This)->lpVtbl->Load(This,pInputTopo,ppOutputTopo,pCurrentTopo)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaSession
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaSession,IMFMediaEventGenerator)
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

    /* IMFMediaSession methods */
    STDMETHOD_(HRESULT,ClearTopologies)(THIS) PURE;
    STDMETHOD_(HRESULT,Close)(THIS) PURE;
    STDMETHOD_(HRESULT,GetClock)(THIS_ IMFClock **ppClock) PURE;
    STDMETHOD_(HRESULT,GetFullTopology)(THIS_ DWORD dwGetFullTopologyFlags,TOPOID TopoId,IMFTopology **ppFullTopo) PURE;
    STDMETHOD_(HRESULT,GetSessionCapabilities)(THIS_ DWORD *pdwCaps) PURE;
    STDMETHOD_(HRESULT,Pause)(THIS) PURE;
    STDMETHOD_(HRESULT,SetTopology)(THIS_ DWORD dwSetTopologyFlags,IMFTopology *pTopology) PURE;
    STDMETHOD_(HRESULT,Shutdown)(THIS) PURE;
    STDMETHOD_(HRESULT,Start)(THIS_ const GUID *pguidTimeFormat,const PROPVARIANT *pvarStartPosition) PURE;
    STDMETHOD_(HRESULT,Stop)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaSession_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaSession_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaSession_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaSession_BeginGetEvent(This,pCallback,punkState) (This)->lpVtbl->BeginGetEvent(This,pCallback,punkState)
#define IMFMediaSession_EndGetEvent(This,pResult,ppEvent) (This)->lpVtbl->EndGetEvent(This,pResult,ppEvent)
#define IMFMediaSession_GetEvent(This,dwFlags,ppEvent) (This)->lpVtbl->GetEvent(This,dwFlags,ppEvent)
#define IMFMediaSession_QueueEvent(This,met,guidExtendedType,hrStatus,pvValue) (This)->lpVtbl->QueueEvent(This,met,guidExtendedType,hrStatus,pvValue)
#define IMFMediaSession_RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent) (This)->lpVtbl->RemoteEndGetEvent(This,pResult,pcbEvent,ppbEvent)
#define IMFMediaSession_ClearTopologies() (This)->lpVtbl->ClearTopologies(This)
#define IMFMediaSession_Close() (This)->lpVtbl->Close(This)
#define IMFMediaSession_GetClock(This,ppClock) (This)->lpVtbl->GetClock(This,ppClock)
#define IMFMediaSession_GetFullTopology(This,dwGetFullTopologyFlags,TopoId,ppFullTopo) (This)->lpVtbl->GetFullTopology(This,dwGetFullTopologyFlags,TopoId,ppFullTopo)
#define IMFMediaSession_GetSessionCapabilities(This,pdwCaps) (This)->lpVtbl->GetSessionCapabilities(This,pdwCaps)
#define IMFMediaSession_Pause() (This)->lpVtbl->Pause(This)
#define IMFMediaSession_SetTopology(This,dwSetTopologyFlags,pTopology) (This)->lpVtbl->SetTopology(This,dwSetTopologyFlags,pTopology)
#define IMFMediaSession_Shutdown() (This)->lpVtbl->Shutdown(This)
#define IMFMediaSession_Start(This,pguidTimeFormat,pvarStartPosition) (This)->lpVtbl->Start(This,pguidTimeFormat,pvarStartPosition)
#define IMFMediaSession_Stop() (This)->lpVtbl->Stop(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFActivate
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFActivate,IMFAttributes)
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

    /* IMFActivate methods */
    STDMETHOD_(HRESULT,ActivateObject)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(HRESULT,DetachObject)(THIS) PURE;
    STDMETHOD_(HRESULT,ShutdownObject)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFActivate_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFActivate_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFActivate_Release(This) (This)->lpVtbl->Release(This)
#define IMFActivate_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFActivate_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFActivate_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFActivate_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFActivate_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFActivate_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFActivate_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFActivate_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFActivate_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFActivate_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFActivate_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFActivate_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFActivate_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFActivate_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFActivate_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFActivate_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFActivate_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFActivate_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFActivate_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFActivate_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFActivate_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFActivate_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFActivate_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFActivate_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFActivate_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFActivate_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFActivate_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFActivate_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFActivate_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFActivate_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFActivate_ActivateObject(This,riid,ppv) (This)->lpVtbl->ActivateObject(This,riid,ppv)
#define IMFActivate_DetachObject() (This)->lpVtbl->DetachObject(This)
#define IMFActivate_ShutdownObject() (This)->lpVtbl->ShutdownObject(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFStreamDescriptor
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFStreamDescriptor,IMFAttributes)
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

    /* IMFStreamDescriptor methods */
    STDMETHOD_(HRESULT,GetMediaTypeHandler)(THIS_ IMFMediaTypeHandler **ppMediaTypeHandler) PURE;
    STDMETHOD_(HRESULT,GetStreamIdentifier)(THIS_ DWORD *pdwStreamIdentifier) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFStreamDescriptor_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFStreamDescriptor_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFStreamDescriptor_Release(This) (This)->lpVtbl->Release(This)
#define IMFStreamDescriptor_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFStreamDescriptor_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFStreamDescriptor_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFStreamDescriptor_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFStreamDescriptor_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFStreamDescriptor_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFStreamDescriptor_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFStreamDescriptor_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFStreamDescriptor_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFStreamDescriptor_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFStreamDescriptor_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFStreamDescriptor_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFStreamDescriptor_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFStreamDescriptor_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFStreamDescriptor_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFStreamDescriptor_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFStreamDescriptor_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFStreamDescriptor_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFStreamDescriptor_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFStreamDescriptor_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFStreamDescriptor_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFStreamDescriptor_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFStreamDescriptor_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFStreamDescriptor_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFStreamDescriptor_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFStreamDescriptor_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFStreamDescriptor_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFStreamDescriptor_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFStreamDescriptor_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFStreamDescriptor_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFStreamDescriptor_GetMediaTypeHandler(This,ppMediaTypeHandler) (This)->lpVtbl->GetMediaTypeHandler(This,ppMediaTypeHandler)
#define IMFStreamDescriptor_GetStreamIdentifier(This,pdwStreamIdentifier) (This)->lpVtbl->GetStreamIdentifier(This,pdwStreamIdentifier)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFRemoteDesktopPlugin
DECLARE_INTERFACE_(IMFRemoteDesktopPlugin,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFRemoteDesktopPlugin methods */
    STDMETHOD_(HRESULT,UpdateTopology)(THIS_ IMFTopology *pTopology) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFRemoteDesktopPlugin_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFRemoteDesktopPlugin_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFRemoteDesktopPlugin_Release(This) (This)->lpVtbl->Release(This)
#define IMFRemoteDesktopPlugin_UpdateTopology(This,pTopology) (This)->lpVtbl->UpdateTopology(This,pTopology)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFNetProxyLocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFNetProxyLocator,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFNetProxyLocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFNetProxyLocator **ppProxyLocator) PURE;
    STDMETHOD_(HRESULT,FindFirstProxy)(THIS_ LPCWSTR pszHost,LPCWSTR pszUrl,WINBOOL fReserved) PURE;
    STDMETHOD_(HRESULT,FindNextProxy)(THIS) PURE;
    STDMETHOD_(HRESULT,GetCurrentProxy)(THIS_ LPWSTR pszStr,DWORD *pcchStr) PURE;
    STDMETHOD_(HRESULT,RegisterProxyResult)(THIS_ HRESULT hrOp) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFNetProxyLocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFNetProxyLocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFNetProxyLocator_Release(This) (This)->lpVtbl->Release(This)
#define IMFNetProxyLocator_Clone(This,ppProxyLocator) (This)->lpVtbl->Clone(This,ppProxyLocator)
#define IMFNetProxyLocator_FindFirstProxy(This,pszHost,pszUrl,fReserved) (This)->lpVtbl->FindFirstProxy(This,pszHost,pszUrl,fReserved)
#define IMFNetProxyLocator_FindNextProxy() (This)->lpVtbl->FindNextProxy(This)
#define IMFNetProxyLocator_GetCurrentProxy(This,pszStr,pcchStr) (This)->lpVtbl->GetCurrentProxy(This,pszStr,pcchStr)
#define IMFNetProxyLocator_RegisterProxyResult(This,hrOp) (This)->lpVtbl->RegisterProxyResult(This,hrOp)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFMediaTypeHandler
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFMediaTypeHandler,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFMediaTypeHandler methods */
    STDMETHOD_(HRESULT,GetCurrentMediaType)(THIS_ IMFMediaType **ppMediaType) PURE;
    STDMETHOD_(HRESULT,GetMajorType)(THIS_ GUID *pguidMajorType) PURE;
    STDMETHOD_(HRESULT,GetMediaTypeByIndex)(THIS_ DWORD dwIndex,IMFMediaType **ppType) PURE;
    STDMETHOD_(HRESULT,GetMediaTypeCount)(THIS_ DWORD *pdwTypeCount) PURE;
    STDMETHOD_(HRESULT,IsMediaTypeSupported)(THIS_ IMFMediaType *pMediaType,IMFMediaType **ppMediaType) PURE;
    /* [call_as(GetCurrentMediaType)] */
    STDMETHOD_(HRESULT,RemoteGetCurrentMediaType)(THIS_ BYTE **ppbData,DWORD *pcbData) PURE;
    STDMETHOD_(HRESULT,SetCurrentMediaType)(THIS_ IMFMediaType *pMediaType) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFMediaTypeHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFMediaTypeHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFMediaTypeHandler_Release(This) (This)->lpVtbl->Release(This)
#define IMFMediaTypeHandler_GetCurrentMediaType(This,ppMediaType) (This)->lpVtbl->GetCurrentMediaType(This,ppMediaType)
#define IMFMediaTypeHandler_GetMajorType(This,pguidMajorType) (This)->lpVtbl->GetMajorType(This,pguidMajorType)
#define IMFMediaTypeHandler_GetMediaTypeByIndex(This,dwIndex,ppType) (This)->lpVtbl->GetMediaTypeByIndex(This,dwIndex,ppType)
#define IMFMediaTypeHandler_GetMediaTypeCount(This,pdwTypeCount) (This)->lpVtbl->GetMediaTypeCount(This,pdwTypeCount)
#define IMFMediaTypeHandler_IsMediaTypeSupported(This,pMediaType,ppMediaType) (This)->lpVtbl->IsMediaTypeSupported(This,pMediaType,ppMediaType)
#define IMFMediaTypeHandler_RemoteGetCurrentMediaType(This,ppbData,pcbData) (This)->lpVtbl->RemoteGetCurrentMediaType(This,ppbData,pcbData)
#define IMFMediaTypeHandler_SetCurrentMediaType(This,pMediaType) (This)->lpVtbl->SetCurrentMediaType(This,pMediaType)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSampleGrabberSinkCallback
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSampleGrabberSinkCallback,IMFClockStateSink)
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

    /* IMFSampleGrabberSinkCallback methods */
    STDMETHOD_(HRESULT,OnProcessSample)(THIS_ REFGUID guidMajorMediaType,DWORD dwSampleFlags,LONGLONG llSampleTime,LONGLONG llSampleDuration,const BYTE *pSampleBuffer,DWORD dwSampleSize) PURE;
    STDMETHOD_(HRESULT,OnSetPresentationClock)(THIS_ IMFPresentationClock *pPresentationClock) PURE;
    STDMETHOD_(HRESULT,OnShutdown)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSampleGrabberSinkCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSampleGrabberSinkCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSampleGrabberSinkCallback_Release(This) (This)->lpVtbl->Release(This)
#define IMFSampleGrabberSinkCallback_OnClockPause(This,hnsSystemTime) (This)->lpVtbl->OnClockPause(This,hnsSystemTime)
#define IMFSampleGrabberSinkCallback_OnClockRestart(This,hnsSystemTime) (This)->lpVtbl->OnClockRestart(This,hnsSystemTime)
#define IMFSampleGrabberSinkCallback_OnClockSetRate(This,hnsSystemTime,flRate) (This)->lpVtbl->OnClockSetRate(This,hnsSystemTime,flRate)
#define IMFSampleGrabberSinkCallback_OnClockStart(This,hnsSystemTime,llClockStartOffset) (This)->lpVtbl->OnClockStart(This,hnsSystemTime,llClockStartOffset)
#define IMFSampleGrabberSinkCallback_OnClockStop(This,hnssSystemTime) (This)->lpVtbl->OnClockStop(This,hnssSystemTime)
#define IMFSampleGrabberSinkCallback_OnProcessSample(This,guidMajorMediaType,dwSampleFlags,llSampleTime,llSampleDuration,pSampleBuffer,dwSampleSize) (This)->lpVtbl->OnProcessSample(This,guidMajorMediaType,dwSampleFlags,llSampleTime,llSampleDuration,pSampleBuffer,dwSampleSize)
#define IMFSampleGrabberSinkCallback_OnSetPresentationClock(This,pPresentationClock) (This)->lpVtbl->OnSetPresentationClock(This,pPresentationClock)
#define IMFSampleGrabberSinkCallback_OnShutdown() (This)->lpVtbl->OnShutdown(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSequencerSource
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSequencerSource,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFSequencerSource methods */
    STDMETHOD_(HRESULT,AppendTopology)(THIS_ IMFTopology *pTopology,DWORD dwFlags,MFSequencerElementId *pdwId) PURE;
    STDMETHOD_(HRESULT,DeleteTopology)(THIS_ MFSequencerElementId dwId) PURE;
    STDMETHOD_(HRESULT,GetPresentationContext)(THIS_ IMFPresentationDescriptor *pPD,MFSequencerElementId *pId,IMFTopology **ppTopology) PURE;
    STDMETHOD_(HRESULT,UpdateTopology)(THIS_ MFSequencerElementId dwId,IMFTopology *pTopology) PURE;
    STDMETHOD_(HRESULT,UpdateTopologyFlags)(THIS_ MFSequencerElementId dwId,DWORD dwFlags) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSequencerSource_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSequencerSource_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSequencerSource_Release(This) (This)->lpVtbl->Release(This)
#define IMFSequencerSource_AppendTopology(This,pTopology,dwFlags,pdwId) (This)->lpVtbl->AppendTopology(This,pTopology,dwFlags,pdwId)
#define IMFSequencerSource_DeleteTopology(This,dwId) (This)->lpVtbl->DeleteTopology(This,dwId)
#define IMFSequencerSource_GetPresentationContext(This,pPD,pId,ppTopology) (This)->lpVtbl->GetPresentationContext(This,pPD,pId,ppTopology)
#define IMFSequencerSource_UpdateTopology(This,dwId,pTopology) (This)->lpVtbl->UpdateTopology(This,dwId,pTopology)
#define IMFSequencerSource_UpdateTopologyFlags(This,dwId,dwFlags) (This)->lpVtbl->UpdateTopologyFlags(This,dwId,dwFlags)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFSourceResolver
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFSourceResolver,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFSourceResolver methods */
    STDMETHOD_(HRESULT,BeginCreateObjectFromByteStream)(THIS_ IMFByteStream *pByteStream,LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,IUnknown **ppIUnknownCancelCookie,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,BeginCreateObjectFromURL)(THIS_ LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,IUnknown **ppIUnknownCancelCookie,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,CancelObjectCreation)(THIS_ IUnknown **ppIUnknownCancelCookie) PURE;
    STDMETHOD_(HRESULT,CreateObjectFromByteStream)(THIS_ IMFByteStream *pByteStream,LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,CreateObjectFromURL)(THIS_ LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,EndCreateObjectFromByteStream)(THIS_ IMFAsyncResult *pResult,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,EndCreateObjectFromURL)(THIS_ IMFAsyncResult *pResult,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFSourceResolver_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFSourceResolver_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFSourceResolver_Release(This) (This)->lpVtbl->Release(This)
#define IMFSourceResolver_BeginCreateObjectFromByteStream(This,pByteStream,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState) (This)->lpVtbl->BeginCreateObjectFromByteStream(This,pByteStream,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState)
#define IMFSourceResolver_BeginCreateObjectFromURL(This,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState) (This)->lpVtbl->BeginCreateObjectFromURL(This,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState)
#define IMFSourceResolver_CancelObjectCreation(This,ppIUnknownCancelCookie) (This)->lpVtbl->CancelObjectCreation(This,ppIUnknownCancelCookie)
#define IMFSourceResolver_CreateObjectFromByteStream(This,pByteStream,pwszURL,dwFlags,pProps,pObjectType,ppObject) (This)->lpVtbl->CreateObjectFromByteStream(This,pByteStream,pwszURL,dwFlags,pProps,pObjectType,ppObject)
#define IMFSourceResolver_CreateObjectFromURL(This,pwszURL,dwFlags,pProps,pObjectType,ppObject) (This)->lpVtbl->CreateObjectFromURL(This,pwszURL,dwFlags,pProps,pObjectType,ppObject)
#define IMFSourceResolver_EndCreateObjectFromByteStream(This,pResult,pObjectType,ppObject) (This)->lpVtbl->EndCreateObjectFromByteStream(This,pResult,pObjectType,ppObject)
#define IMFSourceResolver_EndCreateObjectFromURL(This,pResult,pObjectType,ppObject) (This)->lpVtbl->EndCreateObjectFromURL(This,pResult,pObjectType,ppObject)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFQualityManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFQualityManager,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFQualityManager methods */
    STDMETHOD_(HRESULT,NotifyPresentationClock)(THIS_ IMFPresentationClock *pClock) PURE;
    STDMETHOD_(HRESULT,NotifyProcessInput)(THIS_ IMFTopologyNode *pNode,__LONG32 lInputIndex,IMFSample *pSample) PURE;
    STDMETHOD_(HRESULT,NotifyProcessOutput)(THIS_ IMFTopologyNode *pNode,__LONG32 lOutputIndex,IMFSample *pSample) PURE;
    STDMETHOD_(HRESULT,NotifyQualityEvent)(THIS_ IUnknown *pObject,IMFMediaEvent *pEvent) PURE;
    STDMETHOD_(HRESULT,NotifyTopology)(THIS_ IMFTopology *pTopology) PURE;
    STDMETHOD_(HRESULT,Shutdown)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFQualityManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFQualityManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFQualityManager_Release(This) (This)->lpVtbl->Release(This)
#define IMFQualityManager_NotifyPresentationClock(This,pClock) (This)->lpVtbl->NotifyPresentationClock(This,pClock)
#define IMFQualityManager_NotifyProcessInput(This,pNode,lInputIndex,pSample) (This)->lpVtbl->NotifyProcessInput(This,pNode,lInputIndex,pSample)
#define IMFQualityManager_NotifyProcessOutput(This,pNode,lOutputIndex,pSample) (This)->lpVtbl->NotifyProcessOutput(This,pNode,lOutputIndex,pSample)
#define IMFQualityManager_NotifyQualityEvent(This,pObject,pEvent) (This)->lpVtbl->NotifyQualityEvent(This,pObject,pEvent)
#define IMFQualityManager_NotifyTopology(This,pTopology) (This)->lpVtbl->NotifyTopology(This,pTopology)
#define IMFQualityManager_Shutdown() (This)->lpVtbl->Shutdown(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFByteStreamHandler
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFByteStreamHandler,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFByteStreamHandler methods */
    STDMETHOD_(HRESULT,BeginCreateObject)(THIS_ IMFByteStream *pByteStream,LPCWSTR pwszURL,DWORD dwFlags,IPropertyStore *pProps,IUnknown **ppIUnknownCancelCookie,IMFAsyncCallback *pCallback,IUnknown *punkState) PURE;
    STDMETHOD_(HRESULT,CancelObjectCreation)(THIS_ IUnknown *pIUnknownCancelCookie) PURE;
    STDMETHOD_(HRESULT,EndCreateObject)(THIS_ IMFAsyncResult *pResult,MF_OBJECT_TYPE *pObjectType,IUnknown **ppObject) PURE;
    STDMETHOD_(HRESULT,GetMaxNumberOfBytesRequiredForResolution)(THIS_ QWORD *pqwBytes) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFByteStreamHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFByteStreamHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFByteStreamHandler_Release(This) (This)->lpVtbl->Release(This)
#define IMFByteStreamHandler_BeginCreateObject(This,pByteStream,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState) (This)->lpVtbl->BeginCreateObject(This,pByteStream,pwszURL,dwFlags,pProps,ppIUnknownCancelCookie,pCallback,punkState)
#define IMFByteStreamHandler_CancelObjectCreation(This,pIUnknownCancelCookie) (This)->lpVtbl->CancelObjectCreation(This,pIUnknownCancelCookie)
#define IMFByteStreamHandler_EndCreateObject(This,pResult,pObjectType,ppObject) (This)->lpVtbl->EndCreateObject(This,pResult,pObjectType,ppObject)
#define IMFByteStreamHandler_GetMaxNumberOfBytesRequiredForResolution(This,pqwBytes) (This)->lpVtbl->GetMaxNumberOfBytesRequiredForResolution(This,pqwBytes)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)
#undef  INTERFACE
#define INTERFACE IMFTranscodeProfile
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTranscodeProfile,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFTranscodeProfile methods */
    STDMETHOD_(HRESULT,GetAudioAttributes)(THIS_ IMFAttributes **ppAttrs) PURE;
    STDMETHOD_(HRESULT,GetContainerAttributes)(THIS_ IMFAttributes **ppAttrs) PURE;
    STDMETHOD_(HRESULT,GetVideoAttributes)(THIS_ IMFAttributes **ppAttrs) PURE;
    STDMETHOD_(HRESULT,SetAudioAttributes)(THIS_ IMFAttributes *pAttrs) PURE;
    STDMETHOD_(HRESULT,SetContainerAttributes)(THIS_ IMFAttributes *pAttrs) PURE;
    STDMETHOD_(HRESULT,SetVideoAttributes)(THIS_ IMFAttributes *pAttrs) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFTranscodeProfile_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTranscodeProfile_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTranscodeProfile_Release(This) (This)->lpVtbl->Release(This)
#define IMFTranscodeProfile_GetAudioAttributes(This,ppAttrs) (This)->lpVtbl->GetAudioAttributes(This,ppAttrs)
#define IMFTranscodeProfile_GetContainerAttributes(This,ppAttrs) (This)->lpVtbl->GetContainerAttributes(This,ppAttrs)
#define IMFTranscodeProfile_GetVideoAttributes(This,ppAttrs) (This)->lpVtbl->GetVideoAttributes(This,ppAttrs)
#define IMFTranscodeProfile_SetAudioAttributes(This,pAttrs) (This)->lpVtbl->SetAudioAttributes(This,pAttrs)
#define IMFTranscodeProfile_SetContainerAttributes(This,pAttrs) (This)->lpVtbl->SetContainerAttributes(This,pAttrs)
#define IMFTranscodeProfile_SetVideoAttributes(This,pAttrs) (This)->lpVtbl->SetVideoAttributes(This,pAttrs)
#endif /*COBJMACROS*/

typedef struct _MF_TRANSCODE_SINK_INFO {
  DWORD        dwVideoStreamID;
  IMFMediaType *pVideoMediaType;
  DWORD        dwAudioStreamID;
  IMFMediaType *pAudioMediaType;
} MF_TRANSCODE_SINK_INFO;

#undef  INTERFACE
#define INTERFACE IMFTranscodeSinkInfoProvider
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFTranscodeSinkInfoProvider,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFTranscodeSinkInfoProvider methods */
    STDMETHOD_(HRESULT,GetSinkInfo)(THIS_ MF_TRANSCODE_SINK_INFO *pSinkInfo) PURE;
    STDMETHOD_(HRESULT,SetOutputByteStream)(THIS_ IMFActivate *pByteStreamActivate) PURE;
    STDMETHOD_(HRESULT,SetOutputFile)(THIS_ LPCWSTR pwszFileName) PURE;
    STDMETHOD_(HRESULT,SetProfile)(THIS_ IMFTranscodeProfile *pProfile) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFTranscodeSinkInfoProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFTranscodeSinkInfoProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFTranscodeSinkInfoProvider_Release(This) (This)->lpVtbl->Release(This)
#define IMFTranscodeSinkInfoProvider_GetSinkInfo(This,pSinkInfo) (This)->lpVtbl->GetSinkInfo(This,pSinkInfo)
#define IMFTranscodeSinkInfoProvider_SetOutputByteStream(This,pByteStreamActivate) (This)->lpVtbl->SetOutputByteStream(This,pByteStreamActivate)
#define IMFTranscodeSinkInfoProvider_SetOutputFile(This,pwszFileName) (This)->lpVtbl->SetOutputFile(This,pwszFileName)
#define IMFTranscodeSinkInfoProvider_SetProfile(This,pProfile) (This)->lpVtbl->SetProfile(This,pProfile)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
typedef enum _MFVP_MESSAGE_TYPE MFVP_MESSAGE_TYPE;
#undef  INTERFACE
#define INTERFACE IMFVideoSampleAllocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFVideoSampleAllocator,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFVideoSampleAllocator methods */
    STDMETHOD_(HRESULT,GetCurrentMediaType)(THIS_ IMFVideoMediaType **ppMediaType) PURE;
    STDMETHOD_(HRESULT,ProcessMessage)(THIS_ MFVP_MESSAGE_TYPE eMessage,ULONG_PTR ulParam) PURE;
    STDMETHOD_(HRESULT,AllocateSample)(THIS_ IMFSample **ppSample) PURE;
    STDMETHOD_(HRESULT,InitializeSampleAllocator)(THIS_ DWORD cRequestedFrames,IMFMediaType *pMediaType) PURE;
    STDMETHOD_(HRESULT,SetDirectXManager)(THIS_ IUnknown *pManager) PURE;
    STDMETHOD_(HRESULT,UninitializeSampleAllocator)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFVideoSampleAllocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFVideoSampleAllocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFVideoSampleAllocator_Release(This) (This)->lpVtbl->Release(This)
#define IMFVideoSampleAllocator_GetCurrentMediaType(This,ppMediaType) (This)->lpVtbl->GetCurrentMediaType(This,ppMediaType)
#define IMFVideoSampleAllocator_ProcessMessage(This,eMessage,ulParam) (This)->lpVtbl->ProcessMessage(This,eMessage,ulParam)
#define IMFVideoSampleAllocator_AllocateSample(This,ppSample) (This)->lpVtbl->AllocateSample(This,ppSample)
#define IMFVideoSampleAllocator_InitializeSampleAllocator(This,cRequestedFrames,pMediaType) (This)->lpVtbl->InitializeSampleAllocator(This,cRequestedFrames,pMediaType)
#define IMFVideoSampleAllocator_SetDirectXManager(This,pManager) (This)->lpVtbl->SetDirectXManager(This,pManager)
#define IMFVideoSampleAllocator_UninitializeSampleAllocator() (This)->lpVtbl->UninitializeSampleAllocator(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFObjectReferenceStream
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFObjectReferenceStream,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFObjectReferenceStream methods */
    STDMETHOD_(HRESULT,LoadReference)(THIS_ REFIID riid,void **ppv) PURE;
    STDMETHOD_(HRESULT,SaveReference)(THIS_ REFIID riid,IUnknown *pUnk) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFObjectReferenceStream_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFObjectReferenceStream_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFObjectReferenceStream_Release(This) (This)->lpVtbl->Release(This)
#define IMFObjectReferenceStream_LoadReference(This,riid,ppv) (This)->lpVtbl->LoadReference(This,riid,ppv)
#define IMFObjectReferenceStream_SaveReference(This,riid,pUnk) (This)->lpVtbl->SaveReference(This,riid,pUnk)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFWorkQueueServices
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFWorkQueueServices,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFWorkQueueServices methods */
    STDMETHOD_(HRESULT,BeginRegisterPlatformWorkQueueWithMMCSS)(THIS_ DWORD dwPlatformWorkQueue,LPCWSTR wszClass,DWORD dwTaskId,IMFAsyncCallback *pCallback,IUnknown *pState) PURE;
    STDMETHOD_(HRESULT,BeginRegisterTopologyWorkQueuesWithMMCSS)(THIS_ IMFAsyncCallback *pCallback,IUnknown *pState) PURE;
    STDMETHOD_(HRESULT,BeginUnregisterPlatformWorkQueueWithMMCSS)(THIS_ DWORD dwPlatformWorkQueue,IMFAsyncCallback *pCallback,IUnknown *pState) PURE;
    STDMETHOD_(HRESULT,BeginUnregisterTopologyWorkQueuesWithMMCSS)(THIS_ IMFAsyncCallback *pCallback,IUnknown *pState) PURE;
    STDMETHOD_(HRESULT,EndRegisterPlatformWorkQueueWithMMCSS)(THIS_ IMFAsyncResult *pResult,DWORD *pdwTaskId) PURE;
    STDMETHOD_(HRESULT,EndRegisterTopologyWorkQueuesWithMMCSS)(THIS_ IMFAsyncResult *pResult) PURE;
    STDMETHOD_(HRESULT,EndUnregisterPlatformWorkQueueWithMMCSS)(THIS_ IMFAsyncResult *pResult) PURE;
    STDMETHOD_(HRESULT,EndUnregisterTopologyWorkQueuesWithMMCSS)(THIS_ IMFAsyncResult *pResult) PURE;
    STDMETHOD_(HRESULT,GetPlaftormWorkQueueMMCSSClass)(THIS_ DWORD dwPlatformWorkQueueId,LPWSTR pwszClass,DWORD *pcchClass) PURE;
    STDMETHOD_(HRESULT,GetPlatformWorkQueueMMCSSTaskId)(THIS_ DWORD dwPlatformWorkQueueId,DWORD *pdwTaskId) PURE;
    STDMETHOD_(HRESULT,GetTopologyWorkQueueMMCSSClass)(THIS_ DWORD dwTopologyWorkQueueId,LPWSTR pwszClass,DWORD *pcchClass) PURE;
    STDMETHOD_(HRESULT,GetTopologyWorkQueueMMCSSTaskId)(THIS_ DWORD dwTopologyWorkQueueId,DWORD *pdwTaskId) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFWorkQueueServices_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFWorkQueueServices_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFWorkQueueServices_Release(This) (This)->lpVtbl->Release(This)
#define IMFWorkQueueServices_BeginRegisterPlatformWorkQueueWithMMCSS(This,dwPlatformWorkQueue,wszClass,dwTaskId,pCallback,pState) (This)->lpVtbl->BeginRegisterPlatformWorkQueueWithMMCSS(This,dwPlatformWorkQueue,wszClass,dwTaskId,pCallback,pState)
#define IMFWorkQueueServices_BeginRegisterTopologyWorkQueuesWithMMCSS(This,pCallback,pState) (This)->lpVtbl->BeginRegisterTopologyWorkQueuesWithMMCSS(This,pCallback,pState)
#define IMFWorkQueueServices_BeginUnregisterPlatformWorkQueueWithMMCSS(This,dwPlatformWorkQueue,pCallback,pState) (This)->lpVtbl->BeginUnregisterPlatformWorkQueueWithMMCSS(This,dwPlatformWorkQueue,pCallback,pState)
#define IMFWorkQueueServices_BeginUnregisterTopologyWorkQueuesWithMMCSS(This,pCallback,pState) (This)->lpVtbl->BeginUnregisterTopologyWorkQueuesWithMMCSS(This,pCallback,pState)
#define IMFWorkQueueServices_EndRegisterPlatformWorkQueueWithMMCSS(This,pResult,pdwTaskId) (This)->lpVtbl->EndRegisterPlatformWorkQueueWithMMCSS(This,pResult,pdwTaskId)
#define IMFWorkQueueServices_EndRegisterTopologyWorkQueuesWithMMCSS(This,pResult) (This)->lpVtbl->EndRegisterTopologyWorkQueuesWithMMCSS(This,pResult)
#define IMFWorkQueueServices_EndUnregisterPlatformWorkQueueWithMMCSS(This,pResult) (This)->lpVtbl->EndUnregisterPlatformWorkQueueWithMMCSS(This,pResult)
#define IMFWorkQueueServices_EndUnregisterTopologyWorkQueuesWithMMCSS(This,pResult) (This)->lpVtbl->EndUnregisterTopologyWorkQueuesWithMMCSS(This,pResult)
#define IMFWorkQueueServices_GetPlaftormWorkQueueMMCSSClass(This,dwPlatformWorkQueueId,pwszClass,pcchClass) (This)->lpVtbl->GetPlaftormWorkQueueMMCSSClass(This,dwPlatformWorkQueueId,pwszClass,pcchClass)
#define IMFWorkQueueServices_GetPlatformWorkQueueMMCSSTaskId(This,dwPlatformWorkQueueId,pdwTaskId) (This)->lpVtbl->GetPlatformWorkQueueMMCSSTaskId(This,dwPlatformWorkQueueId,pdwTaskId)
#define IMFWorkQueueServices_GetTopologyWorkQueueMMCSSClass(This,dwTopologyWorkQueueId,pwszClass,pcchClass) (This)->lpVtbl->GetTopologyWorkQueueMMCSSClass(This,dwTopologyWorkQueueId,pwszClass,pcchClass)
#define IMFWorkQueueServices_GetTopologyWorkQueueMMCSSTaskId(This,dwTopologyWorkQueueId,pdwTaskId) (This)->lpVtbl->GetTopologyWorkQueueMMCSSTaskId(This,dwTopologyWorkQueueId,pdwTaskId)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)

#undef  INTERFACE
#define INTERFACE IMFVideoSampleAllocatorNotify
DECLARE_INTERFACE_(IMFVideoSampleAllocatorNotify,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFVideoSampleAllocatorNotify methods */
    STDMETHOD_(HRESULT,NotifyRelease)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFVideoSampleAllocatorNotify_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFVideoSampleAllocatorNotify_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFVideoSampleAllocatorNotify_Release(This) (This)->lpVtbl->Release(This)
#define IMFVideoSampleAllocatorNotify_NotifyRelease() (This)->lpVtbl->NotifyRelease(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFVideoSampleAllocatorCallback
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFVideoSampleAllocatorCallback,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFVideoSampleAllocatorCallback methods */
    STDMETHOD_(HRESULT,GetFreeSampleCount)(THIS_ LONG *plSamples) PURE;
    STDMETHOD_(HRESULT,SetCallback)(THIS_ IMFVideoSampleAllocatorNotify *pNotify) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFVideoSampleAllocatorCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFVideoSampleAllocatorCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFVideoSampleAllocatorCallback_Release(This) (This)->lpVtbl->Release(This)
#define IMFVideoSampleAllocatorCallback_GetFreeSampleCount(This,plSamples) (This)->lpVtbl->GetFreeSampleCount(This,plSamples)
#define IMFVideoSampleAllocatorCallback_SetCallback(This,pNotify) (This)->lpVtbl->SetCallback(This,pNotify)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT MFCreate3GPMediaSink(IMFByteStream *pIByteStream,IMFMediaType *pVideoMediaType,IMFMediaType *pAudioMediaType,IMFMediaSink **ppIMediaSink);
HRESULT MFCreateAggregateSource(IMFCollection *pSourceCollection,IMFMediaSource **ppAggSource);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI MFCreateAlignedMemoryBuffer(DWORD cbMaxLength,DWORD fAlignmentFlags,IMFMediaBuffer **ppBuffer);
HRESULT WINAPI MFCreateASFContentInfo(IMFASFContentInfo **ppIContentInfo);
HRESULT WINAPI MFCreateASFIndexer(IMFASFIndexer **ppIIndexer);
HRESULT WINAPI MFCreateASFIndexerByteStream(IMFByteStream *pIContentByteStream,QWORD cbIndexStartOffset,IMFByteStream **pIIndexByteStream);
HRESULT WINAPI MFCreateASFMediaSink(IMFByteStream *pIByteStream,IMFMediaSink **ppIMediaSink);
HRESULT WINAPI MFCreateASFMediaSinkActivate(LPCWSTR pwszFileName,IMFASFContentInfo *pContentInfo,IMFActivate **ppIActivate);
HRESULT WINAPI MFCreateASFMultiplexer(IMFASFMultiplexer **ppIMultiplexer);
HRESULT WINAPI MFCreateASFProfile(IMFASFProfile **ppIProfile);
HRESULT WINAPI MFCreateASFProfileFromPresentationDescriptor(IMFPresentationDescriptor *pIPD,IMFASFProfile **ppIProfile);
HRESULT WINAPI MFCreateASFSplitter(IMFASFSplitter **ppISplitter);
HRESULT WINAPI MFCreateMediaSession(IMFAttributes *pConfiguration,IMFMediaSession **ppMS);
HRESULT WINAPI MFCreateMP3MediaSink(IMFByteStream *pTargetByteStream,IMFMediaSink **ppMediaSink);
HRESULT WINAPI MFCreateMPEG4MediaSink(IMFByteStream *pIByteStream,IMFMediaType *pVideoMediaType,IMFMediaType *pAudioMediaType,IMFMediaSink **ppIMediaSink);
HRESULT WINAPI MFCreateNetSchemePlugin(REFIID riid,LPVOID *ppvHandler);
HRESULT WINAPI MFCreatePMPServer(DWORD dwCreationFlags,IMFPMPServer **ppPMPServer);
HRESULT WINAPI MFCreatePMPMediaSession(DWORD dwCreationFlags,IMFAttributes *pConfiguration,IMFMediaSession **ppMediaSession,IMFActivate **ppEnablerActivate);
HRESULT WINAPI MFCreatePathFromURL(LPCWSTR pwszFileURL,LPWSTR *ppwszFilePath);
HRESULT WINAPI MFCreatePresentationClock(IMFPresentationClock **ppPresentationClock);
HRESULT WINAPI MFCreatePresentationDescriptor(DWORD cStreamDescriptors,IMFStreamDescriptor **apStreamDescriptors,IMFPresentationDescriptor **ppPresentationDescriptor);
HRESULT WINAPI MFCreatePresentationDescriptorFromASFProfile(IMFASFProfile *pIProfile,IMFPresentationDescriptor **ppIPD);
HRESULT WINAPI MFCreateProxyLocator(LPCWSTR pszProtocol,IPropertyStore *pProxyConfig,IMFNetProxyLocator **ppProxyLocator);
HRESULT WINAPI MFCreateRemoteDesktopPlugin(IMFRemoteDesktopPlugin **ppPlugin);
HRESULT WINAPI MFCreateSample(IMFSample **ppIMFSample);
HRESULT WINAPI MFCreateSampleCopierMFT(IMFTransform **ppCopierMFT);
HRESULT WINAPI MFCreateSampleGrabberSinkActivate(IMFMediaType *pIMFMediaType,IMFSampleGrabberSinkCallback *pIMFSampleGrabberSinkCallback,IMFActivate **ppIActivate);
HRESULT WINAPI MFCreateSequencerSource(IUnknown *pReserved,IMFSequencerSource **ppSequencerSource);
HRESULT WINAPI MFCreateSimpleTypeHandler(IMFMediaTypeHandler **ppHandler);
HRESULT WINAPI MFCreateStandardQualityManager(IMFQualityManager **ppQualityManager);
HRESULT WINAPI MFCreateStreamDescriptor(DWORD dwStreamIdentifier,DWORD cMediaTypes,IMFMediaType **apMediaTypes,IMFStreamDescriptor **ppDescriptor);
HRESULT WINAPI MFCreateSourceResolver(IMFSourceResolver **ppISourceResolver);
HRESULT WINAPI MFCreateSystemTimeSource(IMFPresentationTimeSource **ppSystemTimeSource);
HRESULT WINAPI MFCreateTopoLoader(IMFTopoLoader **ppObj);
HRESULT WINAPI MFCreateTopology(IMFTopology **ppTopo);
HRESULT WINAPI MFCreateTopologyNode(MF_TOPOLOGY_TYPE NodeType,IMFTopologyNode **ppNode);
HRESULT WINAPI MFCreateVideoRenderer(REFIID riidRenderer,void **ppVideoRenderer);
HRESULT WINAPI MFCreateVideoRendererActivate(HWND hwndVideo,IMFActivate **ppActivate);
HRESULT WINAPI MFGetService(IUnknown *punkObject,REFGUID guidService,REFIID riid,LPVOID *ppvObject);
HRESULT WINAPI MFGetSupportedMimeTypes(PROPVARIANT *pPropVarMimeTypeArray);
HRESULT WINAPI MFGetSupportedSchemes(PROPVARIANT *pPropVarSchemeArray);
MFTIME WINAPI MFGetSystemTime(void);
HRESULT WINAPI MFShutdownObject(IUnknown *pUnk);
HRESULT WINAPI CreateNamedPropertyStore(INamedPropertyStore **ppStore);
HRESULT WINAPI CreatePropertyStore(IPropertyStore **ppStore);
#ifdef __cplusplus
}
#endif
#if (_WIN32_WINNT >= 0x0601)

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI MFCreateTranscodeProfile(IMFTranscodeProfile **ppTranscodeProfile);
HRESULT WINAPI MFCreateTranscodeSinkActivate(IMFActivate **ppActivate);
HRESULT WINAPI MFCreateTranscodeTopology(IMFMediaSource *pSrc,LPCWSTR pwszOutputFilePath,IMFTranscodeProfile *pProfile,IMFTopology **ppTranscodeTopo);
HRESULT WINAPI MFEnumDeviceSources(IMFAttributes *pAttributes,IMFActivate ***pppSourceActivate,UINT32 *pcSourceActivate);
HRESULT WINAPI MFGetTopoNodeCurrentType(IMFTopologyNode *pNode,DWORD dwStreamIndex,WINBOOL fOutput,IMFMediaType **ppType);
HRESULT WINAPI MFTranscodeGetAudioOutputAvailableTypes(REFGUID guidSubType,DWORD dwMFTFlags,IMFAttributes *pCodecConfig,IMFCollection **ppAvailableTypes);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_MFIDL*/
