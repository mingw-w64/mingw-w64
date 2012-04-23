/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_BDAIFACE__
#define __INC_BDAIFACE__

#include <objbase.h>
#include <bdatypes.h>
#include <dshow.h>

#if (_WIN32_WINNT >= 0x0601)

typedef enum ApplicationTypeType {
  SCTE28_ConditionalAccess              = 0,
  SCTE28_POD_Host_Binding_Information,
  SCTE28_IPService,
  SCTE28_NetworkInterface_SCTE55_2,
  SCTE28_NetworkInterface_SCTE55_1,
  SCTE28_CopyProtection,
  SCTE28_Diagnostic,
  SCTE28_Undesignated,
  SCTE28_Reserved 
} ApplicationTypeType;

typedef enum BDA_DrmPairingError {
  BDA_DrmPairing_Succeeded            = 0,
  BDA_DrmPairing_HardwareFailure,
  BDA_DrmPairing_NeedRevocationData,
  BDA_DrmPairing_NeedIndiv,
  BDA_DrmPairing_Other,
  BDA_DrmPairing_DrmInitFailed,
  BDA_DrmPairing_DrmNotPaired,
  BDA_DrmPairing_DrmRePairSoon 
} BDA_DrmPairingError;

typedef enum SmartCardAssociationType {
  NotAssociated        = 0,
  Associated,
  AssociationUnknown 
} SmartCardAssociationType;

enum SmartCardStatusType {
  CardInserted          = 0,
  CardRemoved,
  CardError,
  CardDataChanged,
  CardFirmwareUpgrade 
};

enum UICloseReasonType {
  NotReady       = 0,
  UserClosed,
  SystemClosed,
  DeviceClosed,
  ErrorClosed 
};

/* Guessed from: https://acidframework.googlecode.com/svn-history/r215/trunk/Acid/Multimedia/DirectShow/BDA/BDAIface.cs */
typedef enum _LocationCodeSchemeType {
  SCTE_18 = 0
} LocationCodeSchemeType;

typedef struct _EALocationCodeType {
  LocationCodeSchemeType LocationCodeScheme;
  BYTE                   state_code;
  BYTE                   county_subdivision;
  WORD                   county_code;
} EALocationCodeType;

typedef struct _SmartCardApplication {
  ApplicationTypeType ApplicationType;
  USHORT              ApplicationVersion;
  BSTR                pbstrApplicationName;
  BSTR                pbstrApplicationURL;
} SmartCardApplication;

typedef struct _TransportSampleStatistics {
  DWORD          dwWindowSize;
  DWORD          dwNoOfRunningPackets;
  DWORD          dwNoOfScrambledPackets;
  DWORD          dwNoOfDiscontinuity;
  DWORD          dwNoOfDroppedPackets;
  REFERENCE_TIME rtCurrentStreamTime;
  REFERENCE_TIME rtFirstPacketStreamTime;
  REFERENCE_TIME rtLastPacketStreamTime;
  REFERENCE_TIME rtLastDemuxInputSampleTime;
} TRANSPORT_SAMPLE_STATISTICS;

#define PBDA_Encoder_Video_MPEG2PartII 0x00000000
#define PBDA_Encoder_Video_MPEG4Part10 0x00000001
#define PBDA_Encoder_Video_MPEG4Part10 0x00000001
#define PBDA_Encoder_Video_H264 0x00000001

#define PBDA_Encoder_BitrateMode_Constant 0x00000001
#define PBDA_Encoder_BitrateMode_Variable 0x00000002
#define PBDA_Encoder_BitrateMode_Average 0x00000003

#ifndef __IBDA_ConditionalAccessEx_FWD_DEFINED__
#define __IBDA_ConditionalAccessEx_FWD_DEFINED__
typedef struct IBDA_ConditionalAccessEx IBDA_ConditionalAccessEx;
#endif

#ifndef __IBDA_DRIDRMService_FWD_DEFINED__
#define __IBDA_DRIDRMService_FWD_DEFINED__
typedef struct IBDA_DRIDRMService IBDA_DRIDRMService;
#endif

#ifndef __IBDA_Encoder_FWD_DEFINED__
#define __IBDA_Encoder_FWD_DEFINED__
typedef struct IBDA_Encoder IBDA_Encoder;
#endif

#ifndef __IBDA_EventingService_FWD_DEFINED__
#define __IBDA_EventingService_FWD_DEFINED__
typedef struct IBDA_EventingService IBDA_EventingService;
#endif

#ifndef __IBDA_FDC_FWD_DEFINED__
#define __IBDA_FDC_FWD_DEFINED__
typedef struct IBDA_FDC IBDA_FDC;
#endif

#ifndef __IBDA_GuideDataDeliveryService_FWD_DEFINED__
#define __IBDA_GuideDataDeliveryService_FWD_DEFINED__
typedef struct IBDA_GuideDataDeliveryService IBDA_GuideDataDeliveryService;
#endif

#ifndef __IBDA_ISDBConditionalAccess_FWD_DEFINED__
#define __IBDA_ISDBConditionalAccess_FWD_DEFINED__
typedef struct IBDA_ISDBConditionalAccess IBDA_ISDBConditionalAccess;
#endif

#ifndef __IBDA_MUX_FWD_DEFINED__
#define __IBDA_MUX_FWD_DEFINED__
typedef struct IBDA_MUX IBDA_MUX;
#endif

#ifndef __IBDA_UserActivityService_FWD_DEFINED__
#define __IBDA_UserActivityService_FWD_DEFINED__
typedef struct IBDA_UserActivityService IBDA_UserActivityService;
#endif

#ifndef __IBDA_ISDBConditionalAccess_FWD_DEFINED__
#define __IBDA_ISDBConditionalAccess_FWD_DEFINED__
typedef struct IBDA_ISDBConditionalAccess IBDA_ISDBConditionalAccess;
#endif

#undef  INTERFACE
#define INTERFACE IBDA_ConditionalAccessEx
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_ConditionalAccessEx,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_ConditionalAccessEx methods */
    STDMETHOD_(HRESULT,CheckEntitlementToken)(THIS_ ULONG ulDialogRequest,BSTR bstrLanguage,BDA_CONDITIONALACCESS_REQUESTTYPE RequestType,ULONG ulcbEntitlementTokenLen,BYTE *pbEntitlementToken,ULONG *pulDescrambleStatus) PURE;
    STDMETHOD_(HRESULT,CloseMmiDialog)(THIS_ ULONG ulDialogRequest,BSTR bstrLanguage,ULONG ulDialogNumber,BDA_CONDITIONALACCESS_MMICLOSEREASON ReasonCode,ULONG *pulSessionResult) PURE;
    STDMETHOD_(HRESULT,CreateDialogRequestNumber)(THIS_ ULONG *pulDialogRequestNumber) PURE;
    STDMETHOD_(HRESULT,OpenBroadcastMmi)(THIS_ ULONG ulDialogRequest,BSTR bstrLanguage,ULONG EventId) PURE;
    STDMETHOD_(HRESULT,SetCaptureToken)(THIS_ ULONG ulcbCaptureTokenLen,BYTE *pbCaptureToken) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_ConditionalAccessEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_ConditionalAccessEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_ConditionalAccessEx_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_ConditionalAccessEx_CheckEntitlementToken(This,ulDialogRequest,bstrLanguage,RequestType,ulcbEntitlementTokenLen,pbEntitlementToken,pulDescrambleStatus) (This)->lpVtbl->CheckEntitlementToken(This,ulDialogRequest,bstrLanguage,RequestType,ulcbEntitlementTokenLen,pbEntitlementToken,pulDescrambleStatus)
#define IBDA_ConditionalAccessEx_CloseMmiDialog(This,ulDialogRequest,bstrLanguage,ulDialogNumber,ReasonCode,pulSessionResult) (This)->lpVtbl->CloseMmiDialog(This,ulDialogRequest,bstrLanguage,ulDialogNumber,ReasonCode,pulSessionResult)
#define IBDA_ConditionalAccessEx_CreateDialogRequestNumber(This,pulDialogRequestNumber) (This)->lpVtbl->CreateDialogRequestNumber(This,pulDialogRequestNumber)
#define IBDA_ConditionalAccessEx_OpenBroadcastMmi(This,ulDialogRequest,bstrLanguage,EventId) (This)->lpVtbl->OpenBroadcastMmi(This,ulDialogRequest,bstrLanguage,EventId)
#define IBDA_ConditionalAccessEx_SetCaptureToken(This,ulcbCaptureTokenLen,pbCaptureToken) (This)->lpVtbl->SetCaptureToken(This,ulcbCaptureTokenLen,pbCaptureToken)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_DRIDRMService
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_DRIDRMService,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_DRIDRMService methods */
    STDMETHOD_(HRESULT,GetDRMStatus)(THIS_ BSTR *pbstrDrmUuidList,GUID *DrmUuid) PURE;
    STDMETHOD_(HRESULT,GetPairingStatus)(THIS_ BDA_DrmPairingError *penumPairingStatus) PURE;
    STDMETHOD_(HRESULT,SetDRM)(THIS_ GUID *puuidNewDrm) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_DRIDRMService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_DRIDRMService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_DRIDRMService_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_DRIDRMService_GetDRMStatus(This,pbstrDrmUuidList,DrmUuid) (This)->lpVtbl->GetDRMStatus(This,pbstrDrmUuidList,DrmUuid)
#define IBDA_DRIDRMService_GetPairingStatus(This,penumPairingStatus) (This)->lpVtbl->GetPairingStatus(This,penumPairingStatus)
#define IBDA_DRIDRMService_SetDRM(This,puuidNewDrm) (This)->lpVtbl->SetDRM(This,puuidNewDrm)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_Encoder
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_Encoder,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_Encoder methods */
    STDMETHOD_(HRESULT,EnumAudioCapability)(THIS_ DWORD FmtIndex,DWORD *MethodID,DWORD *AlgorithmType,DWORD *SamplingRate,DWORD *BitDepth,DWORD *NumChannels) PURE;
    STDMETHOD_(HRESULT,EnumVideoCapability)(THIS_ DWORD FmtIndex,DWORD *MethodID,DWORD *AlgorithmType,DWORD *VerticalSize,DWORD *HorizontalSize,DWORD *AspectRatio,DWORD *FrameRateCode,DWORD *ProgressiveSequence) PURE;
    STDMETHOD_(HRESULT,GetState)(THIS_ DWORD *AudioBitrateMax,DWORD *AudioBitrateMin,DWORD *AudioBitrateMode,DWORD *AudioBitrateStepping,DWORD *AudioBitrate,DWORD *AudioMethodID,DWORD *AvailableAudioPrograms,DWORD *AudioProgram,DWORD *VideoBitrateMax,DWORD *VideoBitrateMin,DWORD *VideoBitrateMode,DWORD *VideoBitrate,DWORD *VideoBitrateStepping,DWORD *VideoMethodID,DWORD *SignalSourceID,ULONGLONG *SignalFormat,WINBOOL *SignalLock,LONG *SignalLevel,DWORD *SignalToNoiseRatio) PURE;
    STDMETHOD_(HRESULT,QueryCapabilities)(THIS_ DWORD *NumAudioFmts,DWORD *NumVideoFmts) PURE;
    STDMETHOD_(HRESULT,SetParameters)(THIS_ DWORD AudioBitrateMode,DWORD AudioBitrate,DWORD AudioMethodID,DWORD AudioProgram,DWORD VideoBitrateMode,DWORD VideoBitrate,DWORD VideoMethodID) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_Encoder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_Encoder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_Encoder_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_Encoder_EnumAudioCapability(This,FmtIndex,MethodID,AlgorithmType,SamplingRate,BitDepth,NumChannels) (This)->lpVtbl->EnumAudioCapability(This,FmtIndex,MethodID,AlgorithmType,SamplingRate,BitDepth,NumChannels)
#define IBDA_Encoder_EnumVideoCapability(This,FmtIndex,MethodID,AlgorithmType,VerticalSize,HorizontalSize,AspectRatio,FrameRateCode,ProgressiveSequence) (This)->lpVtbl->EnumVideoCapability(This,FmtIndex,MethodID,AlgorithmType,VerticalSize,HorizontalSize,AspectRatio,FrameRateCode,ProgressiveSequence)
#define IBDA_Encoder_GetState(This,AudioBitrateMax,AudioBitrateMin,AudioBitrateMode,AudioBitrateStepping,AudioBitrate,AudioMethodID,AvailableAudioPrograms,AudioProgram,VideoBitrateMax,VideoBitrateMin,VideoBitrateMode,VideoBitrate,VideoBitrateStepping,VideoMethodID,SignalSourceID,SignalFormat,SignalLock,SignalLevel,SignalToNoiseRatio) (This)->lpVtbl->GetState(This,AudioBitrateMax,AudioBitrateMin,AudioBitrateMode,AudioBitrateStepping,AudioBitrate,AudioMethodID,AvailableAudioPrograms,AudioProgram,VideoBitrateMax,VideoBitrateMin,VideoBitrateMode,VideoBitrate,VideoBitrateStepping,VideoMethodID,SignalSourceID,SignalFormat,SignalLock,SignalLevel,SignalToNoiseRatio)
#define IBDA_Encoder_QueryCapabilities(This,NumAudioFmts,NumVideoFmts) (This)->lpVtbl->QueryCapabilities(This,NumAudioFmts,NumVideoFmts)
#define IBDA_Encoder_SetParameters(This,AudioBitrateMode,AudioBitrate,AudioMethodID,AudioProgram,VideoBitrateMode,VideoBitrate,VideoMethodID) (This)->lpVtbl->SetParameters(This,AudioBitrateMode,AudioBitrate,AudioMethodID,AudioProgram,VideoBitrateMode,VideoBitrate,VideoMethodID)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_EventingService
DECLARE_INTERFACE_(IBDA_EventingService,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_EventingService methods */
    STDMETHOD_(HRESULT,CompleteEvent)(THIS_ ULONG ulEventID,ULONG ulEventResult) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_EventingService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_EventingService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_EventingService_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_EventingService_CompleteEvent(This,ulEventID,ulEventResult) (This)->lpVtbl->CompleteEvent(This,ulEventID,ulEventResult)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_FDC
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_FDC,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_FDC methods */
    STDMETHOD_(HRESULT,AddPid)(THIS_ BSTR PidsToAdd,DWORD *RemainingFilterEntries) PURE;
    STDMETHOD_(HRESULT,AddTid)(THIS_ BSTR TidsToAdd,BSTR *CurrentTidList) PURE;
    STDMETHOD_(HRESULT,GetStatus)(THIS_ DWORD *CurrentBitrate,WINBOOL *CarrierLock,DWORD *CurrentFrequency,WINBOOL *CurrentSpectrumInversion,BSTR *CurrentPIDList,BSTR *CurrentTIDList,WINBOOL *Overflow) PURE;
    STDMETHOD_(HRESULT,GetTableSection)(THIS_ DWORD *Pid,DWORD MaxBufferSize,DWORD *ActualSize,BYTE *SecBuffer) PURE;
    STDMETHOD_(HRESULT,RemovePid)(THIS_ BSTR PidsToRemove) PURE;
    STDMETHOD_(HRESULT,RemoveTid)(THIS_ BSTR TidsToRemove) PURE;
    STDMETHOD_(HRESULT,RequestTables)(THIS_ BSTR TableIDs) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_FDC_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_FDC_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_FDC_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_FDC_AddPid(This,PidsToAdd,RemainingFilterEntries) (This)->lpVtbl->AddPid(This,PidsToAdd,RemainingFilterEntries)
#define IBDA_FDC_AddTid(This,TidsToAdd,CurrentTidList) (This)->lpVtbl->AddTid(This,TidsToAdd,CurrentTidList)
#define IBDA_FDC_GetStatus(This,CurrentBitrate,CarrierLock,CurrentFrequency,CurrentSpectrumInversion,CurrentPIDList,CurrentTIDList,Overflow) (This)->lpVtbl->GetStatus(This,CurrentBitrate,CarrierLock,CurrentFrequency,CurrentSpectrumInversion,CurrentPIDList,CurrentTIDList,Overflow)
#define IBDA_FDC_GetTableSection(This,Pid,MaxBufferSize,ActualSize,SecBuffer) (This)->lpVtbl->GetTableSection(This,Pid,MaxBufferSize,ActualSize,SecBuffer)
#define IBDA_FDC_RemovePid(This,PidsToRemove) (This)->lpVtbl->RemovePid(This,PidsToRemove)
#define IBDA_FDC_RemoveTid(This,TidsToRemove) (This)->lpVtbl->RemoveTid(This,TidsToRemove)
#define IBDA_FDC_RequestTables(This,TableIDs) (This)->lpVtbl->RequestTables(This,TableIDs)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_GuideDataDeliveryService
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_GuideDataDeliveryService,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_GuideDataDeliveryService methods */
    STDMETHOD(GetGuideData)(THIS_ ULONG *pulcbBufferLen,BYTE *pbBuffer,ULONG *pulGuideDataPercentageProgress) PURE;
    STDMETHOD_(HRESULT,GetGuideDataType)(THIS_ GUID *pguidDataType) PURE;
    STDMETHOD_(HRESULT,GetServiceInfoFromTuneXml)(THIS_ BSTR bstrTuneXml,BSTR *pbstrServiceDescription) PURE;
    STDMETHOD_(HRESULT,GetServices)(THIS_ ULONG *pulcbBufferLen,BYTE *pbBuffer) PURE;
    STDMETHOD_(HRESULT,GetTuneXmlFromServiceIdx)(THIS_ ULONG64 ul64ServiceIdx,BSTR *pbstrTuneXml) PURE;
    STDMETHOD_(HRESULT,RequestGuideDataUpdate)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_GuideDataDeliveryService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_GuideDataDeliveryService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_GuideDataDeliveryService_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_GuideDataDeliveryService_GetGuideData(This,pulcbBufferLen,pbBuffer,pulGuideDataPercentageProgress) (This)->lpVtbl->GetGuideData(This,pulcbBufferLen,pbBuffer,pulGuideDataPercentageProgress)
#define IBDA_GuideDataDeliveryService_GetGuideDataType(This,pguidDataType) (This)->lpVtbl->GetGuideDataType(This,pguidDataType)
#define IBDA_GuideDataDeliveryService_GetServiceInfoFromTuneXml(This,bstrTuneXml,pbstrServiceDescription) (This)->lpVtbl->GetServiceInfoFromTuneXml(This,bstrTuneXml,pbstrServiceDescription)
#define IBDA_GuideDataDeliveryService_GetServices(This,pulcbBufferLen,pbBuffer) (This)->lpVtbl->GetServices(This,pulcbBufferLen,pbBuffer)
#define IBDA_GuideDataDeliveryService_GetTuneXmlFromServiceIdx(This,ul64ServiceIdx,pbstrTuneXml) (This)->lpVtbl->GetTuneXmlFromServiceIdx(This,ul64ServiceIdx,pbstrTuneXml)
#define IBDA_GuideDataDeliveryService_RequestGuideDataUpdate() (This)->lpVtbl->RequestGuideDataUpdate(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_ISDBConditionalAccess
DECLARE_INTERFACE_(IBDA_ISDBConditionalAccess,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_ISDBConditionalAccess methods */
    STDMETHOD_(HRESULT,SetIsdbCasRequest)(THIS_ ULONG ulRequestId,ULONG ulcbRequestBufferLen,BYTE *pbRequestBuffer) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_ISDBConditionalAccess_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_ISDBConditionalAccess_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_ISDBConditionalAccess_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_ISDBConditionalAccess_SetIsdbCasRequest(This,ulRequestId,ulcbRequestBufferLen,pbRequestBuffer) (This)->lpVtbl->SetIsdbCasRequest(This,ulRequestId,ulcbRequestBufferLen,pbRequestBuffer)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_MUX
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_MUX,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_MUX methods */
    STDMETHOD_(HRESULT,GetPidList)(THIS_ BDA_MUX_PIDLISTITEM *pbPidListBuffer) PURE;
    STDMETHOD_(HRESULT,SetPidList)(THIS_ ULONG ulPidListCount,BDA_MUX_PIDLISTITEM *pbPidListBuffer) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_MUX_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_MUX_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_MUX_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_MUX_GetPidList(This,pbPidListBuffer) (This)->lpVtbl->GetPidList(This,pbPidListBuffer)
#define IBDA_MUX_SetPidList(This,ulPidListCount,pbPidListBuffer) (This)->lpVtbl->SetPidList(This,ulPidListCount,pbPidListBuffer)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IBDA_UserActivityService
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IBDA_UserActivityService,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDA_UserActivityService methods */
    STDMETHOD_(HRESULT,GetUserActivityInterval)(THIS_ DWORD *pdwActivityInterval) PURE;
    STDMETHOD_(HRESULT,SetCurrentTunerUseReason)(THIS_ DWORD dwUseReason) PURE;
    STDMETHOD_(HRESULT,UserActivityDetected)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDA_UserActivityService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDA_UserActivityService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDA_UserActivityService_Release(This) (This)->lpVtbl->Release(This)
#define IBDA_UserActivityService_GetUserActivityInterval(This,pdwActivityInterval) (This)->lpVtbl->GetUserActivityInterval(This,pdwActivityInterval)
#define IBDA_UserActivityService_SetCurrentTunerUseReason(This,dwUseReason) (This)->lpVtbl->SetCurrentTunerUseReason(This,dwUseReason)
#define IBDA_UserActivityService_UserActivityDetected() (This)->lpVtbl->UserActivityDetected(This)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*__INC_BDAIFACE__*/
