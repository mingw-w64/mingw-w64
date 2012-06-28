/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WMCONTAINER
#define _INC_WMCONTAINER
#include <propsys.h>
#include <mfidl.h>

#if (_WIN32_WINNT >= 0x0600)

#ifdef __IMFASFSplitter_FWD_DEFINED__
#define __IMFASFSplitter_FWD_DEFINED__
typedef struct IMFASFSplitter IMFASFSplitter;
#endif

typedef struct IMFASFContentInfo IMFASFContentInfo;
typedef struct IMFASFProfile IMFASFProfile;
typedef struct IMFActivate IMFActivate;

#ifndef __MFTIME_DEFINED__
#define __MFTIME_DEFINED__
__MINGW_EXTENSION typedef LONGLONG MFTIME;
#endif

typedef enum ASF_SELECTION_STATUS {
  ASF_STATUS_NOTSELECTED       = 0,
  ASF_STATUS_CLEANPOINTSONLY   = 1,
  ASF_STATUS_ALLDATAUNITS      = 2 
} ASF_SELECTION_STATUS;

typedef enum ASF_STATUSFLAGS {
  ASF_STATUSFLAGS_INCOMPLETE       = 0x00000001,
  ASF_STATUSFLAGS_NONFATAL_ERROR   = 0x00000002 
} ASF_STATUSFLAGS;

typedef enum MFASF_MULTIPLEXERFLAGS {
  MFASF_MULTIPLEXER_AUTOADJUST_BITRATE   = 0x00000001 
} MFASF_MULTIPLEXERFLAGS;

typedef enum MFASF_SPLITTERFLAGS {
  MFASF_SPLITTER_REVERSE   = 0x00000001,
  MFASF_SPLITTER_WMDRM     = 0x00000002 
} MFASF_SPLITTERFLAGS;

typedef enum MFASF_STREAMSELECTORFLAGS {
  MFASF_STREAMSELECTOR_DISABLE_THINNING      = 0x00000001,
  MFASF_STREAMSELECTOR_USE_AVERAGE_BITRATE   = 0x00000002 
} MFASF_STREAMSELECTORFLAGS;

typedef struct ASF_MUX_STATISTICS {
  DWORD cFramesWritten;
  DWORD cFramesDropped;
} ASF_MUX_STATISTICS;

typedef struct _ASF_INDEX_IDENTIFIER {
  GUID guidIndexType;
  WORD wStreamNumber;
} ASF_INDEX_IDENTIFIER;

typedef struct _ASF_INDEX_DESCRIPTOR {
  ASF_INDEX_IDENTIFIER Identifier;
  WORD                 cPerEntryBytes;
  WCHAR                szDescription[32];
  DWORD                dwInterval;
} ASF_INDEX_DESCRIPTOR;

#undef  INTERFACE
#define INTERFACE IMFASFMutualExclusion
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFMutualExclusion,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFASFMutualExclusion methods */
    STDMETHOD_(HRESULT,AddRecord)(THIS_ DWORD *pdwRecordNumber) PURE;
    STDMETHOD_(HRESULT,AddStreamForRecord)(THIS_ DWORD dwRecordNumber,WORD wStreamNumber) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFASFMutualExclusion **ppIMutex) PURE;
    STDMETHOD_(HRESULT,GetRecordCount)(THIS_ DWORD *pdwRecordCount) PURE;
    STDMETHOD_(HRESULT,GetStreamsForRecord)(THIS_ DWORD dwRecordNumber,WORD *pwStreamNumArray,DWORD *pcStreams) PURE;
    STDMETHOD_(HRESULT,GetType)(THIS_ GUID *pguidType) PURE;
    STDMETHOD_(HRESULT,RemoveRecord)(THIS_ DWORD dwRecordNumber) PURE;
    STDMETHOD_(HRESULT,RemoveStreamFromRecord)(THIS_ DWORD dwRecordNumber,WORD wStreamNumber) PURE;
    STDMETHOD_(HRESULT,SetType)(THIS_ REFGUID guidType) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFMutualExclusion_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFMutualExclusion_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFMutualExclusion_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFMutualExclusion_AddRecord(This,pdwRecordNumber) (This)->lpVtbl->AddRecord(This,pdwRecordNumber)
#define IMFASFMutualExclusion_AddStreamForRecord(This,dwRecordNumber,wStreamNumber) (This)->lpVtbl->AddStreamForRecord(This,dwRecordNumber,wStreamNumber)
#define IMFASFMutualExclusion_Clone(This,ppIMutex) (This)->lpVtbl->Clone(This,ppIMutex)
#define IMFASFMutualExclusion_GetRecordCount(This,pdwRecordCount) (This)->lpVtbl->GetRecordCount(This,pdwRecordCount)
#define IMFASFMutualExclusion_GetStreamsForRecord(This,dwRecordNumber,pwStreamNumArray,pcStreams) (This)->lpVtbl->GetStreamsForRecord(This,dwRecordNumber,pwStreamNumArray,pcStreams)
#define IMFASFMutualExclusion_GetType(This,pguidType) (This)->lpVtbl->GetType(This,pguidType)
#define IMFASFMutualExclusion_RemoveRecord(This,dwRecordNumber) (This)->lpVtbl->RemoveRecord(This,dwRecordNumber)
#define IMFASFMutualExclusion_RemoveStreamFromRecord(This,dwRecordNumber,wStreamNumber) (This)->lpVtbl->RemoveStreamFromRecord(This,dwRecordNumber,wStreamNumber)
#define IMFASFMutualExclusion_SetType(This,guidType) (This)->lpVtbl->SetType(This,guidType)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFStreamPrioritization
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFStreamPrioritization,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFASFStreamPrioritization methods */
    STDMETHOD_(HRESULT,AddStream)(THIS_ WORD wStreamNumber,WORD wStreamFlags) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFASFStreamPrioritization **ppIStreamPrioritization) PURE;
    STDMETHOD_(HRESULT,GetStream)(THIS_ DWORD dwStreamIndex,WORD *pwStreamNumber,WORD *pwStreamFlags) PURE;
    STDMETHOD_(HRESULT,GetStreamCount)(THIS_ DWORD dwStreamIndex) PURE;
    STDMETHOD_(HRESULT,RemoveStream)(THIS_ DWORD dwStreamIndex) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFStreamPrioritization_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFStreamPrioritization_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFStreamPrioritization_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFStreamPrioritization_AddStream(This,wStreamNumber,wStreamFlags) (This)->lpVtbl->AddStream(This,wStreamNumber,wStreamFlags)
#define IMFASFStreamPrioritization_Clone(This,ppIStreamPrioritization) (This)->lpVtbl->Clone(This,ppIStreamPrioritization)
#define IMFASFStreamPrioritization_GetStream(This,dwStreamIndex,pwStreamNumber,pwStreamFlags) (This)->lpVtbl->GetStream(This,dwStreamIndex,pwStreamNumber,pwStreamFlags)
#define IMFASFStreamPrioritization_GetStreamCount(This,dwStreamIndex) (This)->lpVtbl->GetStreamCount(This,dwStreamIndex)
#define IMFASFStreamPrioritization_RemoveStream(This,dwStreamIndex) (This)->lpVtbl->RemoveStream(This,dwStreamIndex)
#endif /*COBJMACROS*/


#undef  INTERFACE
#define INTERFACE IMFASFSplitter
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFSplitter,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFASFSplitter methods */
    STDMETHOD_(HRESULT,Flush)(THIS) PURE;
    STDMETHOD_(HRESULT,GetFlags)(THIS_ DWORD *pdwFlags) PURE;
    STDMETHOD_(HRESULT,GetLastSendTime)(THIS_ DWORD *pdwLastSendTime) PURE;
    STDMETHOD_(HRESULT,GetNextSample)(THIS_ DWORD *pdwStatusFlags,WORD *pwStreamNumber,IMFSample **ppISample) PURE;
    STDMETHOD_(HRESULT,GetSelectedStreams)(THIS_ WORD *pwStreamNumbers,WORD *pwNumStreams) PURE;
    STDMETHOD_(HRESULT,Initialize)(THIS_ IMFASFContentInfo *pIContentInfo) PURE;
    STDMETHOD_(HRESULT,ParseData)(THIS_ IMFMediaBuffer *pIBuffer,DWORD cbBufferOffset,DWORD cbLength) PURE;
    STDMETHOD_(HRESULT,SelectStreams)(THIS_ WORD *pwStreamNumbers,WORD wNumStreams) PURE;
    STDMETHOD_(HRESULT,SetFlags)(THIS_ DWORD dwFlags) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFSplitter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFSplitter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFSplitter_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFSplitter_Flush() (This)->lpVtbl->Flush(This)
#define IMFASFSplitter_GetFlags(This,pdwFlags) (This)->lpVtbl->GetFlags(This,pdwFlags)
#define IMFASFSplitter_GetLastSendTime(This,pdwLastSendTime) (This)->lpVtbl->GetLastSendTime(This,pdwLastSendTime)
#define IMFASFSplitter_GetNextSample(This,pdwStatusFlags,pwStreamNumber,ppISample) (This)->lpVtbl->GetNextSample(This,pdwStatusFlags,pwStreamNumber,ppISample)
#define IMFASFSplitter_GetSelectedStreams(This,pwStreamNumbers,pwNumStreams) (This)->lpVtbl->GetSelectedStreams(This,pwStreamNumbers,pwNumStreams)
#define IMFASFSplitter_Initialize(This,pIContentInfo) (This)->lpVtbl->Initialize(This,pIContentInfo)
#define IMFASFSplitter_ParseData(This,pIBuffer,cbBufferOffset,cbLength) (This)->lpVtbl->ParseData(This,pIBuffer,cbBufferOffset,cbLength)
#define IMFASFSplitter_SelectStreams(This,pwStreamNumbers,wNumStreams) (This)->lpVtbl->SelectStreams(This,pwStreamNumbers,wNumStreams)
#define IMFASFSplitter_SetFlags(This,dwFlags) (This)->lpVtbl->SetFlags(This,dwFlags)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFContentInfo
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFContentInfo,IMFAttributes)
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

    /* IMFASFContentInfo methods */
    STDMETHOD_(HRESULT,GenerateHeader)(THIS_ IMFMediaBuffer *pIHeader,DWORD *pcbHeader) PURE;
    STDMETHOD_(HRESULT,GeneratePresentationDescriptor)(THIS_ IMFPresentationDescriptor **ppIPresentationDescriptor) PURE;
    STDMETHOD_(HRESULT,GetEncodingConfigurationPropertyStore)(THIS_ WORD wStreamNumber,IPropertyStore **ppIStore) PURE;
    STDMETHOD_(HRESULT,GetHeaderSize)(THIS_ IMFMediaBuffer *pIStartOfContent,QWORD *cbHeaderSize) PURE;
    STDMETHOD_(HRESULT,GetProfile)(THIS_ IMFASFProfile **ppIProfile) PURE;
    STDMETHOD_(HRESULT,ParseHeader)(THIS_ IMFMediaBuffer *pIHeaderBuffer,QWORD cbOffsetWithinHeader) PURE;
    STDMETHOD_(HRESULT,SetProfile)(THIS_ IMFASFProfile *pIProfile) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFContentInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFContentInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFContentInfo_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFContentInfo_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFASFContentInfo_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFASFContentInfo_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFASFContentInfo_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFASFContentInfo_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFASFContentInfo_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFASFContentInfo_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFASFContentInfo_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFASFContentInfo_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFASFContentInfo_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFASFContentInfo_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFASFContentInfo_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFASFContentInfo_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFASFContentInfo_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFASFContentInfo_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFASFContentInfo_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFASFContentInfo_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFASFContentInfo_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFASFContentInfo_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFASFContentInfo_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFASFContentInfo_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFASFContentInfo_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFASFContentInfo_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFASFContentInfo_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFASFContentInfo_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFASFContentInfo_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFASFContentInfo_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFASFContentInfo_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFASFContentInfo_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFASFContentInfo_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFASFContentInfo_GenerateHeader(This,pIHeader,pcbHeader) (This)->lpVtbl->GenerateHeader(This,pIHeader,pcbHeader)
#define IMFASFContentInfo_GeneratePresentationDescriptor(This,ppIPresentationDescriptor) (This)->lpVtbl->GeneratePresentationDescriptor(This,ppIPresentationDescriptor)
#define IMFASFContentInfo_GetEncodingConfigurationPropertyStore(This,wStreamNumber,ppIStore) (This)->lpVtbl->GetEncodingConfigurationPropertyStore(This,wStreamNumber,ppIStore)
#define IMFASFContentInfo_GetHeaderSize(This,pIStartOfContent,cbHeaderSize) (This)->lpVtbl->GetHeaderSize(This,pIStartOfContent,cbHeaderSize)
#define IMFASFContentInfo_GetProfile(This,ppIProfile) (This)->lpVtbl->GetProfile(This,ppIProfile)
#define IMFASFContentInfo_ParseHeader(This,pIHeaderBuffer,cbOffsetWithinHeader) (This)->lpVtbl->ParseHeader(This,pIHeaderBuffer,cbOffsetWithinHeader)
#define IMFASFContentInfo_SetProfile(This,pIProfile) (This)->lpVtbl->SetProfile(This,pIProfile)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFStreamConfig
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFStreamConfig,IMFAttributes)
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

    /* IMFASFStreamConfig methods */
    STDMETHOD_(HRESULT,AddPayloadExtension)(THIS_ GUID guidExtensionSystemID,WORD cbExtensionDataSize,BYTE *pbExtensionSystemInfo,DWORD cbExtensionSystemInfo) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFASFStreamConfig **ppIStreamConfig) PURE;
    STDMETHOD_(HRESULT,GetMediaType)(THIS_ IMFMediaType **ppIMediaType) PURE;
    STDMETHOD_(HRESULT,GetPayloadExtension)(THIS_ WORD wPayloadExtensionNumber,GUID *pguidExtensionSystemID,WORD *pcbExtensionDataSize,BYTE *pbExtensionSystemInfo,DWORD *pcbExtensionSystemInfo) PURE;
    STDMETHOD_(HRESULT,GetPayloadExtensionCount)(THIS_ WORD *pcPayloadExtensions) PURE;
    STDMETHOD_(WORD,GetStreamNumber)(THIS) PURE;
    STDMETHOD_(HRESULT,GetStreamType)(THIS_ GUID *pguidStreamType) PURE;
    STDMETHOD_(HRESULT,RemoveAllPayloadExtensions)(THIS) PURE;
    STDMETHOD_(HRESULT,SetMediaType)(THIS_ IMFMediaType *pIMediaType) PURE;
    STDMETHOD_(HRESULT,SetStreamNumber)(THIS_ WORD wStreamNum) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFStreamConfig_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFStreamConfig_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFStreamConfig_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFStreamConfig_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFASFStreamConfig_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFASFStreamConfig_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFASFStreamConfig_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFASFStreamConfig_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFASFStreamConfig_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFASFStreamConfig_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFASFStreamConfig_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFASFStreamConfig_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFASFStreamConfig_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFASFStreamConfig_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFASFStreamConfig_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFASFStreamConfig_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFASFStreamConfig_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFASFStreamConfig_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFASFStreamConfig_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFASFStreamConfig_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFASFStreamConfig_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFASFStreamConfig_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFASFStreamConfig_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFASFStreamConfig_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFASFStreamConfig_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFASFStreamConfig_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFASFStreamConfig_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFASFStreamConfig_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFASFStreamConfig_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFASFStreamConfig_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFASFStreamConfig_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFASFStreamConfig_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFASFStreamConfig_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFASFStreamConfig_AddPayloadExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo) (This)->lpVtbl->AddPayloadExtension(This,guidExtensionSystemID,cbExtensionDataSize,pbExtensionSystemInfo,cbExtensionSystemInfo)
#define IMFASFStreamConfig_Clone(This,ppIStreamConfig) (This)->lpVtbl->Clone(This,ppIStreamConfig)
#define IMFASFStreamConfig_GetMediaType(This,ppIMediaType) (This)->lpVtbl->GetMediaType(This,ppIMediaType)
#define IMFASFStreamConfig_GetPayloadExtension(This,wPayloadExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo) (This)->lpVtbl->GetPayloadExtension(This,wPayloadExtensionNumber,pguidExtensionSystemID,pcbExtensionDataSize,pbExtensionSystemInfo,pcbExtensionSystemInfo)
#define IMFASFStreamConfig_GetPayloadExtensionCount(This,pcPayloadExtensions) (This)->lpVtbl->GetPayloadExtensionCount(This,pcPayloadExtensions)
#define IMFASFStreamConfig_GetStreamNumber() (This)->lpVtbl->GetStreamNumber(This)
#define IMFASFStreamConfig_GetStreamType(This,pguidStreamType) (This)->lpVtbl->GetStreamType(This,pguidStreamType)
#define IMFASFStreamConfig_RemoveAllPayloadExtensions() (This)->lpVtbl->RemoveAllPayloadExtensions(This)
#define IMFASFStreamConfig_SetMediaType(This,pIMediaType) (This)->lpVtbl->SetMediaType(This,pIMediaType)
#define IMFASFStreamConfig_SetStreamNumber(This,wStreamNum) (This)->lpVtbl->SetStreamNumber(This,wStreamNum)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFProfile
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFProfile,IMFAttributes)
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

    /* IMFASFProfile methods */
    STDMETHOD_(HRESULT,AddMutualExclusion)(THIS_ IMFASFMutualExclusion *pIMutex) PURE;
    STDMETHOD_(HRESULT,AddStreamPrioritization)(THIS_ IMFASFStreamPrioritization *pIStreamPrioritization) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IMFASFProfile **ppIProfile) PURE;
    STDMETHOD_(HRESULT,CreateMutualExclusion)(THIS_ IMFASFMutualExclusion **ppIMutex) PURE;
    STDMETHOD_(HRESULT,CreateStream)(THIS_ IMFMediaType *pIMediaType,IMFASFStreamConfig **ppIStream) PURE;
    STDMETHOD_(HRESULT,CreateStreamPrioritization)(THIS_ IMFASFStreamPrioritization **ppIStreamPrioritization) PURE;
    STDMETHOD_(HRESULT,GetMutualExclusion)(THIS_ DWORD dwMutexIndex,IMFASFMutualExclusion **ppIMutex) PURE;
    STDMETHOD_(HRESULT,GetMutualExclusionCount)(THIS_ DWORD *pcMutexs) PURE;
    STDMETHOD_(HRESULT,GetStream)(THIS_ DWORD dwStreamIndex,WORD *pwStreamNumber,IMFASFStreamConfig **ppIStream) PURE;
    STDMETHOD_(HRESULT,GetStreamByNumber)(THIS_ WORD wStreamNumber,IMFASFStreamConfig **ppIStream) PURE;
    STDMETHOD_(HRESULT,GetStreamCount)(THIS_ DWORD *pcStreams) PURE;
    STDMETHOD_(HRESULT,GetStreamPrioritization)(THIS_ IMFASFStreamPrioritization **ppIStreamPrioritization) PURE;
    STDMETHOD_(HRESULT,RemoveMutualExclusion)(THIS_ DWORD dwMutexIndex) PURE;
    STDMETHOD_(HRESULT,RemoveStream)(THIS_ WORD wStreamNumber) PURE;
    STDMETHOD_(HRESULT,RemoveStreamPrioritization)(THIS) PURE;
    STDMETHOD_(HRESULT,SetStream)(THIS_ IMFASFStreamConfig *pIStream) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFProfile_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFProfile_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFProfile_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFProfile_Compare(This,pTheirs,MatchType,pbResult) (This)->lpVtbl->Compare(This,pTheirs,MatchType,pbResult)
#define IMFASFProfile_CompareItem(This,guidKey,Value,pbResult) (This)->lpVtbl->CompareItem(This,guidKey,Value,pbResult)
#define IMFASFProfile_CopyAllItems(This,pDest) (This)->lpVtbl->CopyAllItems(This,pDest)
#define IMFASFProfile_DeleteAllItems() (This)->lpVtbl->DeleteAllItems(This)
#define IMFASFProfile_DeleteItem(This,guidKey) (This)->lpVtbl->DeleteItem(This,guidKey)
#define IMFASFProfile_GetAllocatedBlob(This,guidKey,ppBuf,pcbSize) (This)->lpVtbl->GetAllocatedBlob(This,guidKey,ppBuf,pcbSize)
#define IMFASFProfile_GetAllocatedString(This,guidKey,ppwszValue,pcchLength) (This)->lpVtbl->GetAllocatedString(This,guidKey,ppwszValue,pcchLength)
#define IMFASFProfile_GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize) (This)->lpVtbl->GetBlob(This,guidKey,pBuf,cbBufSize,pcbBlobSize)
#define IMFASFProfile_GetBlobSize(This,guidKey,pcbBlobSize) (This)->lpVtbl->GetBlobSize(This,guidKey,pcbBlobSize)
#define IMFASFProfile_GetCount(This,pcItems) (This)->lpVtbl->GetCount(This,pcItems)
#define IMFASFProfile_GetDouble(This,guidKey,pfValue) (This)->lpVtbl->GetDouble(This,guidKey,pfValue)
#define IMFASFProfile_GetGUID(This,guidKey,pguidValue) (This)->lpVtbl->GetGUID(This,guidKey,pguidValue)
#define IMFASFProfile_GetItem(This,guidKey,pValue) (This)->lpVtbl->GetItem(This,guidKey,pValue)
#define IMFASFProfile_GetItemByIndex(This,unIndex,pguidKey,pValue) (This)->lpVtbl->GetItemByIndex(This,unIndex,pguidKey,pValue)
#define IMFASFProfile_GetItemType(This,guidKey,pType) (This)->lpVtbl->GetItemType(This,guidKey,pType)
#define IMFASFProfile_GetString(This,guidKey,pwszValue,cchBufSize,pcchLength) (This)->lpVtbl->GetString(This,guidKey,pwszValue,cchBufSize,pcchLength)
#define IMFASFProfile_GetStringLength(This,guidKey,pcchLength) (This)->lpVtbl->GetStringLength(This,guidKey,pcchLength)
#define IMFASFProfile_GetUINT32(This,guidKey,punValue) (This)->lpVtbl->GetUINT32(This,guidKey,punValue)
#define IMFASFProfile_GetUINT64(This,guidKey,punValue) (This)->lpVtbl->GetUINT64(This,guidKey,punValue)
#define IMFASFProfile_GetUnknown(This,guidKey,riid,ppv) (This)->lpVtbl->GetUnknown(This,guidKey,riid,ppv)
#define IMFASFProfile_LockStore() (This)->lpVtbl->LockStore(This)
#define IMFASFProfile_SetBlob(This,guidKey,pBuf,cbBufSize) (This)->lpVtbl->SetBlob(This,guidKey,pBuf,cbBufSize)
#define IMFASFProfile_SetDouble(This,guidKey,fValue) (This)->lpVtbl->SetDouble(This,guidKey,fValue)
#define IMFASFProfile_SetGUID(This,guidKey,guidValue) (This)->lpVtbl->SetGUID(This,guidKey,guidValue)
#define IMFASFProfile_SetItem(This,guidKey,Value) (This)->lpVtbl->SetItem(This,guidKey,Value)
#define IMFASFProfile_SetString(This,guidKey,wszValue) (This)->lpVtbl->SetString(This,guidKey,wszValue)
#define IMFASFProfile_SetUINT32(This,guidKey,unValue) (This)->lpVtbl->SetUINT32(This,guidKey,unValue)
#define IMFASFProfile_SetUINT64(This,guidKey,unValue) (This)->lpVtbl->SetUINT64(This,guidKey,unValue)
#define IMFASFProfile_SetUnknown(This,guidKey,pUnknown) (This)->lpVtbl->SetUnknown(This,guidKey,pUnknown)
#define IMFASFProfile_UnlockStore() (This)->lpVtbl->UnlockStore(This)
#define IMFASFProfile_AddMutualExclusion(This,pIMutex) (This)->lpVtbl->AddMutualExclusion(This,pIMutex)
#define IMFASFProfile_AddStreamPrioritization(This,pIStreamPrioritization) (This)->lpVtbl->AddStreamPrioritization(This,pIStreamPrioritization)
#define IMFASFProfile_Clone(This,ppIProfile) (This)->lpVtbl->Clone(This,ppIProfile)
#define IMFASFProfile_CreateMutualExclusion(This,ppIMutex) (This)->lpVtbl->CreateMutualExclusion(This,ppIMutex)
#define IMFASFProfile_CreateStream(This,pIMediaType,ppIStream) (This)->lpVtbl->CreateStream(This,pIMediaType,ppIStream)
#define IMFASFProfile_CreateStreamPrioritization(This,ppIStreamPrioritization) (This)->lpVtbl->CreateStreamPrioritization(This,ppIStreamPrioritization)
#define IMFASFProfile_GetMutualExclusion(This,dwMutexIndex,ppIMutex) (This)->lpVtbl->GetMutualExclusion(This,dwMutexIndex,ppIMutex)
#define IMFASFProfile_GetMutualExclusionCount(This,pcMutexs) (This)->lpVtbl->GetMutualExclusionCount(This,pcMutexs)
#define IMFASFProfile_GetStream(This,dwStreamIndex,pwStreamNumber,ppIStream) (This)->lpVtbl->GetStream(This,dwStreamIndex,pwStreamNumber,ppIStream)
#define IMFASFProfile_GetStreamByNumber(This,wStreamNumber,ppIStream) (This)->lpVtbl->GetStreamByNumber(This,wStreamNumber,ppIStream)
#define IMFASFProfile_GetStreamCount(This,pcStreams) (This)->lpVtbl->GetStreamCount(This,pcStreams)
#define IMFASFProfile_GetStreamPrioritization(This,ppIStreamPrioritization) (This)->lpVtbl->GetStreamPrioritization(This,ppIStreamPrioritization)
#define IMFASFProfile_RemoveMutualExclusion(This,dwMutexIndex) (This)->lpVtbl->RemoveMutualExclusion(This,dwMutexIndex)
#define IMFASFProfile_RemoveStream(This,wStreamNumber) (This)->lpVtbl->RemoveStream(This,wStreamNumber)
#define IMFASFProfile_RemoveStreamPrioritization() (This)->lpVtbl->RemoveStreamPrioritization(This)
#define IMFASFProfile_SetStream(This,pIStream) (This)->lpVtbl->SetStream(This,pIStream)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFIndexer
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFIndexer,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFASFIndexer methods */
    STDMETHOD_(HRESULT,CommitIndex)(THIS_ IMFASFContentInfo *pIContentInfo) PURE;
    STDMETHOD_(HRESULT,GenerateIndexEntries)(THIS_ IMFSample *pIASFPacketSample) PURE;
    STDMETHOD_(HRESULT,GetCompletedIndex)(THIS_ IMFMediaBuffer *pIIndexBuffer,QWORD cbOffsetWithinIndex) PURE;
    STDMETHOD_(HRESULT,GetFlags)(THIS_ DWORD *pdwFlags) PURE;
    STDMETHOD_(HRESULT,GetIndexByteStreamCount)(THIS_ DWORD *pcByteStreams) PURE;
    STDMETHOD_(HRESULT,GetIndexPosition)(THIS_ IMFASFContentInfo *pIContentInfo,QWORD *pcbIndexOffset) PURE;
    STDMETHOD_(HRESULT,GetIndexStatus)(THIS_ ASF_INDEX_IDENTIFIER *pIndexIdentifier,WINBOOL *pfIsIndexed,BYTE *pbIndexDescriptor,DWORD *pcbIndexDescriptor) PURE;
    STDMETHOD_(HRESULT,GetIndexWriteSpace)(THIS_ QWORD *pcbIndexWriteSpace) PURE;
    STDMETHOD_(HRESULT,GetSeekPositionForValue)(THIS_ const PROPVARIANT *pvarValue,ASF_INDEX_IDENTIFIER *pIndexIdentifier,QWORD *pcbOffsetWithinData,MFTIME *phnsApproxTime,DWORD *pdwPayloadNumberOfStreamWithinPacket) PURE;
    STDMETHOD_(HRESULT,Initialize)(THIS_ IMFASFContentInfo *pIContentInfo) PURE;
    STDMETHOD_(HRESULT,SetFlags)(THIS_ DWORD dwFlags) PURE;
    STDMETHOD_(HRESULT,SetIndexByteStreams)(THIS_ IMFByteStream **ppIByteStreams,DWORD cByteStreams) PURE;
    STDMETHOD_(HRESULT,SetIndexStatus)(THIS_ BYTE *pIndexDescriptor,DWORD cbIndexDescriptor,WINBOOL fGenerateIndex) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFIndexer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFIndexer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFIndexer_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFIndexer_CommitIndex(This,pIContentInfo) (This)->lpVtbl->CommitIndex(This,pIContentInfo)
#define IMFASFIndexer_GenerateIndexEntries(This,pIASFPacketSample) (This)->lpVtbl->GenerateIndexEntries(This,pIASFPacketSample)
#define IMFASFIndexer_GetCompletedIndex(This,pIIndexBuffer,cbOffsetWithinIndex) (This)->lpVtbl->GetCompletedIndex(This,pIIndexBuffer,cbOffsetWithinIndex)
#define IMFASFIndexer_GetFlags(This,pdwFlags) (This)->lpVtbl->GetFlags(This,pdwFlags)
#define IMFASFIndexer_GetIndexByteStreamCount(This,pcByteStreams) (This)->lpVtbl->GetIndexByteStreamCount(This,pcByteStreams)
#define IMFASFIndexer_GetIndexPosition(This,pIContentInfo,pcbIndexOffset) (This)->lpVtbl->GetIndexPosition(This,pIContentInfo,pcbIndexOffset)
#define IMFASFIndexer_GetIndexStatus(This,pIndexIdentifier,pfIsIndexed,pbIndexDescriptor,pcbIndexDescriptor) (This)->lpVtbl->GetIndexStatus(This,pIndexIdentifier,pfIsIndexed,pbIndexDescriptor,pcbIndexDescriptor)
#define IMFASFIndexer_GetIndexWriteSpace(This,pcbIndexWriteSpace) (This)->lpVtbl->GetIndexWriteSpace(This,pcbIndexWriteSpace)
#define IMFASFIndexer_GetSeekPositionForValue(This,pvarValue,pIndexIdentifier,pcbOffsetWithinData,phnsApproxTime,pdwPayloadNumberOfStreamWithinPacket) (This)->lpVtbl->GetSeekPositionForValue(This,pvarValue,pIndexIdentifier,pcbOffsetWithinData,phnsApproxTime,pdwPayloadNumberOfStreamWithinPacket)
#define IMFASFIndexer_Initialize(This,pIContentInfo) (This)->lpVtbl->Initialize(This,pIContentInfo)
#define IMFASFIndexer_SetFlags(This,dwFlags) (This)->lpVtbl->SetFlags(This,dwFlags)
#define IMFASFIndexer_SetIndexByteStreams(This,ppIByteStreams,cByteStreams) (This)->lpVtbl->SetIndexByteStreams(This,ppIByteStreams,cByteStreams)
#define IMFASFIndexer_SetIndexStatus(This,pIndexDescriptor,cbIndexDescriptor,fGenerateIndex) (This)->lpVtbl->SetIndexStatus(This,pIndexDescriptor,cbIndexDescriptor,fGenerateIndex)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMFASFMultiplexer
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMFASFMultiplexer,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IMFASFMultiplexer methods */
    STDMETHOD_(HRESULT,End)(THIS_ IMFASFContentInfo *pIContentInfo) PURE;
    STDMETHOD_(HRESULT,Flush)(THIS) PURE;
    STDMETHOD_(HRESULT,GetFlags)(THIS_ DWORD *pdwFlags) PURE;
    STDMETHOD_(HRESULT,GetNextPacket)(THIS_ DWORD *pdwStatusFlags,IMFSample **ppIPacket) PURE;
    STDMETHOD_(HRESULT,GetStatistics)(THIS_ WORD wStreamNumber,ASF_MUX_STATISTICS *pMuxStats) PURE;
    STDMETHOD_(HRESULT,Initialize)(THIS_ IMFASFContentInfo *pIContentInfo) PURE;
    STDMETHOD_(HRESULT,ProcessSample)(THIS_ WORD wStreamNumber,IMFSample *pISample,LONGLONG hnsTimestampAdjust) PURE;
    STDMETHOD_(HRESULT,SetFlags)(THIS_ DWORD dwFlags) PURE;
    STDMETHOD_(HRESULT,SetSyncTolerance)(THIS_ DWORD msSyncTolerance) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMFASFMultiplexer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMFASFMultiplexer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMFASFMultiplexer_Release(This) (This)->lpVtbl->Release(This)
#define IMFASFMultiplexer_End(This,pIContentInfo) (This)->lpVtbl->End(This,pIContentInfo)
#define IMFASFMultiplexer_Flush() (This)->lpVtbl->Flush(This)
#define IMFASFMultiplexer_GetFlags(This,pdwFlags) (This)->lpVtbl->GetFlags(This,pdwFlags)
#define IMFASFMultiplexer_GetNextPacket(This,pdwStatusFlags,ppIPacket) (This)->lpVtbl->GetNextPacket(This,pdwStatusFlags,ppIPacket)
#define IMFASFMultiplexer_GetStatistics(This,wStreamNumber,pMuxStats) (This)->lpVtbl->GetStatistics(This,wStreamNumber,pMuxStats)
#define IMFASFMultiplexer_Initialize(This,pIContentInfo) (This)->lpVtbl->Initialize(This,pIContentInfo)
#define IMFASFMultiplexer_ProcessSample(This,wStreamNumber,pISample,hnsTimestampAdjust) (This)->lpVtbl->ProcessSample(This,wStreamNumber,pISample,hnsTimestampAdjust)
#define IMFASFMultiplexer_SetFlags(This,dwFlags) (This)->lpVtbl->SetFlags(This,dwFlags)
#define IMFASFMultiplexer_SetSyncTolerance(This,msSyncTolerance) (This)->lpVtbl->SetSyncTolerance(This,msSyncTolerance)
#endif /*COBJMACROS*/

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI MFCreateASFSplitter(IMFASFSplitter **ppISplitter);
HRESULT WINAPI MFCreateAttributes(IMFAttributes **ppMFAttributes,UINT32 cInitialSize);
HRESULT WINAPI MFCreateWMAEncoderActivate(IMFMediaType *pMediaType,IPropertyStore *pEncodingConfigurationProperties,IMFActivate **ppActivate);
HRESULT WINAPI MFCreateWMVEncoderActivate(IMFMediaType *pMediaType,IPropertyStore *pEncodingConfigurationProperties,IMFActivate **ppActivate);

#ifdef __cplusplus
}
#endif

#endif /* (_WIN32_WINNT >= 0x0600) */
#endif /*_INC_WMCONTAINER*/
