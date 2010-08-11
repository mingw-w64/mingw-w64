/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NAPTYPES
#define _INC_NAPTYPES

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#define maxSoHAttributeCount          0x64
#define maxSoHAttributeSize           0xFA0
#define minNetworkSoHSize             0xC
#define maxNetworkSoHSize             0xFA0
#define maxDwordCountPerSoHAttribute  (maxSoHAttributeSize / sizeof(DWORD))
#define maxIpv4CountPerSoHAttribute   (maxSoHAttributeSize / 0x4)
#define maxIpv6CountPerSoHAttribute   (maxSoHAttributeSize / 0x10)
#define maxStringLength               0x400
#define maxStringLengthInBytes        ((maxStringLength + 1) * sizeof(WCHAR))
#define maxSystemHealthEntityCount    0x14
#define SystemHealthEntityCount       0x14 /*[range(0, maxSystemHealthEntityCount)]*/
#define maxEnforcerCount              0x14
#define EnforcementEntityCount        0x14 /*[range(0, maxEnforcerCount)]*/
#define maxPrivateDataSize            0xC8
#define maxConnectionCountPerEnforcer 0x14
#define maxCachedSoHCount             (maxSystemHealthEntityCount * maxEnforcerCount * maxConnectionCountPerEnforcer)
#define freshSoHRequest               0x1
#define shaFixup                      0x1
#define failureCategoryCount          0x5
#define ComponentTypeEnforcementClientSoH 0x1
#define ComponentTypeEnforcementClientRp  0x2

#ifndef NAPTypes
#define NAPTypes
  typedef FILETIME ProbationTime;
  typedef UINT32 ProtocolMaxSize;
  typedef UINT32 NapComponentId;
  typedef NapComponentId SystemHealthEntityId;
  typedef NapComponentId EnforcementEntityId;
  typedef UINT16 SystemHealthEntityCount;
  typedef UINT16 EnforcementEntityCount;
  typedef CountedString StringCorrelationId;
  typedef GUID ConnectionId;
  typedef UINT8 Percentage;
  typedef UINT32 MessageId;
#endif /* NAPTypes */

  typedef enum tagFixupState {
    fixupStateSuccess          = 0,
    fixupStateInProgress       = 1,
    fixupStateCouldNotUpdate   = 2
  } FixupState;

typedef enum tagFailureCategory {
  failureCategoryNone                  = 0,
  failureCategoryOther                 = 1,
  failureCategoryClientComponent       = 2,
  failureCategoryClientCommunication   = 3,
  failureCategoryServerComponent       = 4,
  failureCategoryServerCommunication   = 5
} FailureCategory;

  typedef enum tagIsolationState {
    isolationStateNotRestricted      = 1,
    isolationStateInProbation        = 2,
    isolationStateRestrictedAccess   = 3
  } IsolationState;

  typedef enum tagExtendedIsolationState {
    extendedIsolationStateNoData       = 0,
    extendedIsolationStateTransition   = 1,
    extendedIsolationStateInfected     = 2,
    extendedIsolationStateUnknown      = 3
  } ExtendedIsolationState;

  typedef enum tagRemoteConfigurationType {
    remoteConfigTypeMachine      = 1,
    remoteConfigTypeConfigBlob   = 2
  } RemoteConfigurationType;

  typedef enum tagNapNotifyType {
    napNotifyTypeUnknown        = 0,
    napNotifyTypeServiceState   = 1,
    napNotifyTypeQuarState      = 2
  } NapNotifyType;
  
  typedef enum _NAPI_PROVIDER_LEVEL {
    ProviderLevel_None        = 0,
    ProviderLevel_Secondary,
    ProviderLevel_Primary
  } NAPI_PROVIDER_LEVEL;

  typedef enum _NAPI_PROVIDER_TYPE {
    ProviderType_Application   = 1,
    ProviderType_Service
  } NAPI_PROVIDER_TYPE;

  typedef struct tagResultCodes {
    UINT16  count;
    HRESULT *results;
  } ResultCodes;

  typedef struct tagCorrelationId {
    GUID     connId;
    FILETIME timeStamp;
  } CorrelationId;

  typedef struct tagSoHAttribute {
    UINT16 type;
    UINT16 size;
    BYTE * value;
  } SoHAttribute;

  typedef struct tagCountedString {
    UINT16 length;
    WCHAR *string;
  } CountedString;

  typedef struct tagIpv4Address {
    BYTE addr[4];
  } Ipv4Address;

  typedef struct tagIpv6Address {
    BYTE addr[16];
  } Ipv6Address;

  typedef struct tagSoH {
    UINT16       count;
    SoHAttribute *attributes;
  } SoH, SoHRequest, SoHResponse;

  typedef struct tagFixupInfo {
    FixupState  state;
    Percentage  percentage;
    ResultCodes resultCodes;
    MessageId   fixupMsgId;
  } FixupInfo;

#define failureCategoryCount 5

  typedef struct tagFailureCategoryMapping {
    WINBOOL mappingCompliance[failureCategoryCount];
  } FailureCategoryMapping;

  typedef struct tagIsolationInfo {
    IsolationState isolationState;
    ProbationTime  probEndTime;
    CountedString  failureUrl;
  } IsolationInfo;

  typedef struct tagIsolationInfoEx {
    IsolationState         isolationState;
    ExtendedIsolationState extendedIsolationState;
    ProbationTime          probEndTime;
    CountedString          failureUrl;
  } IsolationInfoEx;

  typedef struct tagNapComponentRegistrationInfo {
    NapComponentId id;
    CountedString  friendlyName;
    CountedString  description;
    CountedString  version;
    CountedString  vendorName;
    CLSID          infoClsid;
    CLSID          configClsid;
    FILETIME       registrationDate;
    UINT32         componentType;
  } NapComponentRegistrationInfo;

  typedef struct tagPrivateData {
    UINT16 size;
    BYTE * data;
  } PrivateData;

  typedef struct tagNetworkSoH {
    UINT16 size;
    BYTE * data;
  } NetworkSoH, NetworkSoHRequest, NetworkSoHResponse;

  typedef struct tagSystemHealthAgentState {
    SystemHealthEntityId id;
    ResultCodes          shaResultCodes;
    FailureCategory      failureCategory;
    FixupInfo            fixupInfo;
  } SystemHealthAgentState;
  
typedef struct _NAPI_DOMAIN_DESCRIPTION_BLOB {
  DWORD AuthLevel;
  DWORD cchDomainName;
  DWORD OffsetNextDomainDescription;
  DWORD OffsetThisDomainName;
} NAPI_DOMAIN_DESCRIPTION_BLOB, *PNAPI_DOMAIN_DESCRIPTION_BLOB;

typedef struct _NAPI_PROVIDER_INSTALLATION_BLOB {
  DWORD dwVersion;
  DWORD dwProviderType;
  DWORD fSupportsWildCard;
  DWORD cDomains;
  DWORD OffsetFirstDomain;
} NAPI_PROVIDER_INSTALLATION_BLOB, *PNAPI_PROVIDER_INSTALLATION_BLOB;

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /* _INC_NAPTYPES */

