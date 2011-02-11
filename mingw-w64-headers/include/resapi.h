/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _RESAPI_DEFINES_
#define _RESAPI_DEFINES_

#include <windows.h>
#include <winsvc.h>
#include <clusapi.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NO_W32_PSEUDO_MODIFIERS
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef OPTIONAL
#define OPTIONAL
#endif
#endif

#define STARTUP_ROUTINE "Startup"

#define CLRES_V1_FUNCTION_SIZE sizeof(CLRES_V1_FUNCTIONS)
#define CLRES_VERSION_V1_00 0x100

#define CLRES_V1_FUNCTION_TABLE(_Name,_Version,_Prefix,_Arbitrate,_Release,_ResControl,_ResTypeControl) CLRES_FUNCTION_TABLE _Name = { CLRES_V1_FUNCTION_SIZE,_Version,_Prefix##Open,_Prefix##Close,_Prefix##Online,_Prefix##Offline,_Prefix##Terminate,_Prefix##LooksAlive,_Prefix##IsAlive,_Arbitrate,_Release,_ResControl,_ResTypeControl }
#endif

#ifndef _RESAPI_
#define _RESAPI_

  typedef PVOID RESID;
  typedef HANDLE RESOURCE_HANDLE;

  typedef struct RESOURCE_STATUS {
    CLUSTER_RESOURCE_STATE ResourceState;
    DWORD CheckPoint;
    DWORD WaitHint;
    HANDLE EventHandle;
  } RESOURCE_STATUS,*PRESOURCE_STATUS;

#define ResUtilInitializeResourceStatus(_resource_status_) ZeroMemory(_resource_status_,sizeof(RESOURCE_STATUS))

  typedef DWORD (_stdcall *PSET_RESOURCE_STATUS_ROUTINE)(RESOURCE_HANDLE ResourceHandle,PRESOURCE_STATUS ResourceStatus);
  typedef VOID (_stdcall *PQUORUM_RESOURCE_LOST)(RESOURCE_HANDLE Resource);

  typedef enum LOG_LEVEL {
    LOG_INFORMATION = 0,LOG_WARNING,LOG_ERROR,LOG_SEVERE
  } LOG_LEVEL,*PLOG_LEVEL;

  typedef VOID (_stdcall *PLOG_EVENT_ROUTINE)(RESOURCE_HANDLE ResourceHandle,LOG_LEVEL LogLevel,LPCWSTR FormatString,...);
  typedef RESID (_stdcall *POPEN_ROUTINE)(LPCWSTR ResourceName,HKEY ResourceKey,RESOURCE_HANDLE ResourceHandle);
  typedef VOID (_stdcall *PCLOSE_ROUTINE)(RESID Resource);
  typedef DWORD (_stdcall *PONLINE_ROUTINE)(RESID Resource,LPHANDLE EventHandle);
  typedef DWORD (_stdcall *POFFLINE_ROUTINE)(RESID Resource);
  typedef VOID (_stdcall *PTERMINATE_ROUTINE)(RESID Resource);
  typedef WINBOOL (_stdcall *PIS_ALIVE_ROUTINE)(RESID Resource);
  typedef WINBOOL (_stdcall *PLOOKS_ALIVE_ROUTINE)(RESID Resource);
  typedef DWORD (_stdcall *PARBITRATE_ROUTINE)(RESID Resource,PQUORUM_RESOURCE_LOST LostQuorumResource);
  typedef DWORD (_stdcall *PRELEASE_ROUTINE)(RESID Resource);
  typedef DWORD (_stdcall *PRESOURCE_CONTROL_ROUTINE)(RESID Resource,DWORD ControlCode,PVOID InBuffer,DWORD InBufferSize,PVOID OutBuffer,DWORD OutBufferSize,LPDWORD BytesReturned);
  typedef DWORD (_stdcall *PRESOURCE_TYPE_CONTROL_ROUTINE)(LPCWSTR ResourceTypeName,DWORD ControlCode,PVOID InBuffer,DWORD InBufferSize,PVOID OutBuffer,DWORD OutBufferSize,LPDWORD BytesReturned);

  typedef enum _RESOURCE_EXIT_STATE {
    ResourceExitStateContinue = 0,ResourceExitStateTerminate,ResourceExitStateMax
  } RESOURCE_EXIT_STATE;

  typedef struct CLRES_V1_FUNCTIONS {
    POPEN_ROUTINE Open;
    PCLOSE_ROUTINE Close;
    PONLINE_ROUTINE Online;
    POFFLINE_ROUTINE Offline;
    PTERMINATE_ROUTINE Terminate;
    PLOOKS_ALIVE_ROUTINE LooksAlive;
    PIS_ALIVE_ROUTINE IsAlive;
    PARBITRATE_ROUTINE Arbitrate;
    PRELEASE_ROUTINE Release;
    PRESOURCE_CONTROL_ROUTINE ResourceControl;
    PRESOURCE_TYPE_CONTROL_ROUTINE ResourceTypeControl;
  } CLRES_V1_FUNCTIONS,*PCLRES_V1_FUNCTIONS;

  typedef struct CLRES_FUNCTION_TABLE {
    DWORD TableSize;
    DWORD Version;
    __C89_NAMELESS union {
      CLRES_V1_FUNCTIONS V1Functions;
    };
  } CLRES_FUNCTION_TABLE,*PCLRES_FUNCTION_TABLE;

#ifndef FIELD_OFFSET
#define FIELD_OFFSET(type,field) ((LONG)&(((type *)0)->field))
#endif

  typedef struct RESUTIL_LARGEINT_DATA {
    LARGE_INTEGER Default;
    LARGE_INTEGER Minimum;
    LARGE_INTEGER Maximum;
  } RESUTIL_LARGEINT_DATA,*PRESUTIL_LARGEINT_DATA;

  typedef struct RESUTIL_ULARGEINT_DATA {
    ULARGE_INTEGER Default;
    ULARGE_INTEGER Minimum;
    ULARGE_INTEGER Maximum;
  } RESUTIL_ULARGEINT_DATA,*PRESUTIL_ULARGEINT_DATA;

#define RESUTIL_PROPITEM_READ_ONLY 0x00000001
#define RESUTIL_PROPITEM_REQUIRED 0x00000002
#define RESUTIL_PROPITEM_SIGNED 0x00000004

  typedef struct RESUTIL_PROPERTY_ITEM {
    LPWSTR Name;
    LPWSTR KeyName;
    DWORD Format;
    __C89_NAMELESS union {
      DWORD_PTR DefaultPtr;
      DWORD Default;
      LPVOID lpDefault;
      PRESUTIL_LARGEINT_DATA LargeIntData;
      PRESUTIL_ULARGEINT_DATA ULargeIntData;
    };
    DWORD Minimum;
    DWORD Maximum;
    DWORD Flags;
    DWORD Offset;
  } RESUTIL_PROPERTY_ITEM,*PRESUTIL_PROPERTY_ITEM;

  typedef DWORD (_stdcall *PSTARTUP_ROUTINE)(LPCWSTR ResourceType,DWORD MinVersionSupported,DWORD MaxVersionSupported,PSET_RESOURCE_STATUS_ROUTINE SetResourceStatus,PLOG_EVENT_ROUTINE LogEvent,PCLRES_FUNCTION_TABLE *FunctionTable);

  typedef enum RESOURCE_MONITOR_STATE {
    RmonInitializing,RmonIdle,RmonStartingResource,RmonInitializingResource,RmonOnlineResource,RmonOfflineResource,RmonShutdownResource,
    RmonDeletingResource,RmonIsAlivePoll,RmonLooksAlivePoll,RmonArbitrateResource,RmonReleaseResource,RmonResourceControl,
    RmonResourceTypeControl,RmonTerminateResource,RmonDeadlocked
  } RESOURCE_MONITOR_STATE;

  typedef struct MONITOR_STATE {
    LARGE_INTEGER LastUpdate;
    RESOURCE_MONITOR_STATE State;
    HANDLE ActiveResource;
    WINBOOL ResmonStop;
  } MONITOR_STATE,*PMONITOR_STATE;

  DWORD WINAPI ResUtilStartResourceService(LPCWSTR pszServiceName,LPSC_HANDLE phServiceHandle);
  DWORD WINAPI ResUtilVerifyResourceService(LPCWSTR pszServiceName);
  DWORD WINAPI ResUtilStopResourceService(LPCWSTR pszServiceName);
  DWORD WINAPI ResUtilVerifyService(SC_HANDLE hServiceHandle);
  DWORD WINAPI ResUtilStopService(SC_HANDLE hServiceHandle);
  DWORD WINAPI ResUtilCreateDirectoryTree(LPCWSTR pszPath);
  WINBOOL WINAPI ResUtilIsPathValid(LPCWSTR pszPath);
  DWORD WINAPI ResUtilEnumProperties(const PRESUTIL_PROPERTY_ITEM pPropertyTable,LPWSTR pszOutProperties,DWORD cbOutPropertiesSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilEnumPrivateProperties(HKEY hkeyClusterKey,LPWSTR pszOutProperties,DWORD cbOutPropertiesSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilGetProperties(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID pOutPropertyList,DWORD cbOutPropertyListSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilGetAllProperties(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID pOutPropertyList,DWORD cbOutPropertyListSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilGetPrivateProperties(HKEY hkeyClusterKey,PVOID pOutPropertyList,DWORD cbOutPropertyListSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilGetPropertySize(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTableItem,LPDWORD pcbOutPropertyListSize,LPDWORD pnPropertyCount);
  DWORD WINAPI ResUtilGetProperty(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTableItem,PVOID *pOutPropertyItem,LPDWORD pcbOutPropertyItemSize);
  DWORD WINAPI ResUtilVerifyPropertyTable(const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID Reserved,WINBOOL bAllowUnknownProperties,const PVOID pInPropertyList,DWORD cbInPropertyListSize,LPBYTE pOutParams);
  DWORD WINAPI ResUtilSetPropertyTable(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID Reserved,WINBOOL bAllowUnknownProperties,const PVOID pInPropertyList,DWORD cbInPropertyListSize,LPBYTE pOutParams);
  DWORD WINAPI ResUtilSetPropertyTableEx(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID Reserved,WINBOOL bAllowUnknownProperties,const PVOID pInPropertyList,DWORD cbInPropertyListSize,WINBOOL bForceWrite,LPBYTE pOutParams);
  DWORD WINAPI ResUtilSetPropertyParameterBlock(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID Reserved,const LPBYTE pInParams,const PVOID pInPropertyList,DWORD cbInPropertyListSize,LPBYTE pOutParams);
  DWORD WINAPI ResUtilSetPropertyParameterBlockEx(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID Reserved,const LPBYTE pInParams,const PVOID pInPropertyList,DWORD cbInPropertyListSize,WINBOOL bForceWrite,LPBYTE pOutParams);
  DWORD WINAPI ResUtilSetUnknownProperties(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,const PVOID pInPropertyList,DWORD cbInPropertyListSize);
  DWORD WINAPI ResUtilGetPropertiesToParameterBlock(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,LPBYTE pOutParams,WINBOOL bCheckForRequiredProperties,LPWSTR *pszNameOfPropInError);
  DWORD WINAPI ResUtilPropertyListFromParameterBlock(const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID pOutPropertyList,LPDWORD pcbOutPropertyListSize,const LPBYTE pInParams,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilDupParameterBlock(LPBYTE pOutParams,const LPBYTE pInParams,const PRESUTIL_PROPERTY_ITEM pPropertyTable);
  void WINAPI ResUtilFreeParameterBlock(LPBYTE pOutParams,const LPBYTE pInParams,const PRESUTIL_PROPERTY_ITEM pPropertyTable);
  DWORD WINAPI ResUtilAddUnknownProperties(HKEY hkeyClusterKey,const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID pOutPropertyList,DWORD pcbOutPropertyListSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilSetPrivatePropertyList(HKEY hkeyClusterKey,const PVOID pInPropertyList,DWORD cbInPropertyListSize);
  DWORD WINAPI ResUtilVerifyPrivatePropertyList(const PVOID pInPropertyList,DWORD cbInPropertyListSize);
  PWSTR WINAPI ResUtilDupString(LPCWSTR pszInString);
  DWORD WINAPI ResUtilGetBinaryValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPBYTE *ppbOutValue,LPDWORD pcbOutValueSize);
  LPWSTR WINAPI ResUtilGetSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName);
  LPWSTR WINAPI ResUtilGetExpandSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,WINBOOL bExpand);
#ifndef __CRT__NO_INLINE
  __CRT_INLINE DWORD WINAPI ResUtilGetMultiSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPWSTR *ppszOutValue,LPDWORD pcbOutValueSize)
  {
   return ResUtilGetBinaryValue(hkeyClusterKey,pszValueName,(LPBYTE *)ppszOutValue,pcbOutValueSize);
  }
#endif /* !__CRT__NO_INLINE */
  DWORD WINAPI ResUtilGetDwordValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPDWORD pdwOutValue,DWORD dwDefaultValue);
  DWORD WINAPI ResUtilSetBinaryValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,const LPBYTE pbNewValue,DWORD cbNewValueSize,LPBYTE *ppbOutValue,LPDWORD pcbOutValueSize);
  DWORD WINAPI ResUtilSetSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPCWSTR pszNewValue,LPWSTR *ppszOutString);
  DWORD WINAPI ResUtilSetExpandSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPCWSTR pszNewValue,LPWSTR *ppszOutString);
  DWORD WINAPI ResUtilSetMultiSzValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,LPCWSTR pszNewValue,DWORD cbNewValueSize,LPWSTR *ppszOutValue,LPDWORD pcbOutValueSize);
  DWORD WINAPI ResUtilSetDwordValue(HKEY hkeyClusterKey,LPCWSTR pszValueName,DWORD dwNewValue,LPDWORD pdwOutValue);
  DWORD WINAPI ResUtilGetBinaryProperty(LPBYTE *ppbOutValue,LPDWORD pcbOutValueSize,const PCLUSPROP_BINARY pValueStruct,const LPBYTE pbOldValue,DWORD cbOldValueSize,LPBYTE *ppPropertyList,LPDWORD pcbPropertyListSize);
  DWORD WINAPI ResUtilGetSzProperty(LPWSTR *ppszOutValue,const PCLUSPROP_SZ pValueStruct,LPCWSTR pszOldValue,LPBYTE *ppPropertyList,LPDWORD pcbPropertyListSize);
  DWORD WINAPI ResUtilGetMultiSzProperty(LPWSTR *ppszOutValue,LPDWORD pcbOutValueSize,const PCLUSPROP_SZ pValueStruct,LPCWSTR pszOldValue,DWORD cbOldValueSize,LPBYTE *ppPropertyList,LPDWORD pcbPropertyListSize);
  DWORD WINAPI ResUtilGetDwordProperty(LPDWORD pdwOutValue,const PCLUSPROP_DWORD pValueStruct,DWORD dwOldValue,DWORD dwMinimum,DWORD dwMaximum,LPBYTE *ppPropertyList,LPDWORD pcbPropertyListSize);
  LPVOID WINAPI ResUtilGetEnvironmentWithNetName(HRESOURCE hResource);
  DWORD WINAPI ResUtilFreeEnvironment(LPVOID lpEnvironment);
  LPWSTR WINAPI ResUtilExpandEnvironmentStrings(LPCWSTR pszSrc);
  DWORD WINAPI ResUtilSetResourceServiceEnvironment(LPCWSTR pszServiceName,HRESOURCE hResource,PLOG_EVENT_ROUTINE pfnLogEvent,RESOURCE_HANDLE hResourceHandle);
  DWORD WINAPI ResUtilRemoveResourceServiceEnvironment(LPCWSTR pszServiceName,PLOG_EVENT_ROUTINE pfnLogEvent,RESOURCE_HANDLE hResourceHandle);
  DWORD WINAPI ResUtilSetResourceServiceStartParameters(LPCWSTR pszServiceName,SC_HANDLE schSCMHandle,LPSC_HANDLE phService,PLOG_EVENT_ROUTINE pfnLogEvent,RESOURCE_HANDLE hResourceHandle);
  DWORD WINAPI ResUtilFindSzProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPWSTR *pszPropertyValue);
  DWORD WINAPI ResUtilFindExpandSzProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPWSTR *pszPropertyValue);
  DWORD WINAPI ResUtilFindExpandedSzProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPWSTR *pszPropertyValue);
  DWORD WINAPI ResUtilFindDwordProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPDWORD pdwPropertyValue);
  DWORD WINAPI ResUtilFindBinaryProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPBYTE *pbPropertyValue,LPDWORD pcbPropertyValueSize);
  DWORD WINAPI ResUtilFindMultiSzProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPWSTR *pszPropertyValue,LPDWORD pcbPropertyValueSize);
  DWORD WINAPI ResUtilFindLongProperty(const PVOID pPropertyList,DWORD cbPropertyListSize,LPCWSTR pszPropertyName,LPLONG plPropertyValueSize);

  typedef struct CLUS_WORKER {
    HANDLE hThread;
    WINBOOL Terminate;
  } CLUS_WORKER,*PCLUS_WORKER;

  typedef DWORD (WINAPI *PWORKER_START_ROUTINE)(PCLUS_WORKER pWorker,LPVOID lpThreadParameter);
  typedef DWORD (*LPRESOURCE_CALLBACK)(HRESOURCE,HRESOURCE,PVOID);
  typedef DWORD (*LPRESOURCE_CALLBACK_EX)(HCLUSTER,HRESOURCE,HRESOURCE,PVOID);

  DWORD WINAPI ClusWorkerCreate(PCLUS_WORKER lpWorker,PWORKER_START_ROUTINE lpStartAddress,PVOID lpParameter);
  WINBOOL WINAPI ClusWorkerCheckTerminate(PCLUS_WORKER lpWorker);
  VOID WINAPI ClusWorkerTerminate(PCLUS_WORKER lpWorker);
  WINBOOL WINAPI ResUtilResourcesEqual(HRESOURCE hSelf,HRESOURCE hResource);
  WINBOOL WINAPI ResUtilResourceTypesEqual(LPCWSTR lpszResourceTypeName,HRESOURCE hResource);
  WINBOOL WINAPI ResUtilIsResourceClassEqual(PCLUS_RESOURCE_CLASS_INFO prci,HRESOURCE hResource);
  DWORD WINAPI ResUtilEnumResources(HRESOURCE hSelf,LPCWSTR lpszResTypeName,LPRESOURCE_CALLBACK pResCallBack,PVOID pParameter);
  DWORD WINAPI ResUtilEnumResourcesEx(HCLUSTER hCluster,HRESOURCE hSelf,LPCWSTR lpszResTypeName,LPRESOURCE_CALLBACK_EX pResCallBack,PVOID pParameter);
  HRESOURCE WINAPI ResUtilGetResourceDependency(HANDLE hSelf,LPCWSTR lpszResourceType);
  HRESOURCE WINAPI ResUtilGetResourceDependencyByName(HCLUSTER hCluster,HANDLE hSelf,LPCWSTR lpszResourceType,WINBOOL bRecurse);
  HRESOURCE WINAPI ResUtilGetResourceDependencyByClass(HCLUSTER hCluster,HANDLE hSelf,PCLUS_RESOURCE_CLASS_INFO prci,WINBOOL bRecurse);
  HRESOURCE WINAPI ResUtilGetResourceNameDependency(LPCWSTR lpszResourceName,LPCWSTR lpszResourceType);
  DWORD WINAPI ResUtilGetResourceDependentIPAddressProps(HRESOURCE hResource,LPWSTR pszAddress,DWORD *pcchAddress,LPWSTR pszSubnetMask,DWORD *pcchSubnetMask,LPWSTR pszNetwork,DWORD *pcchNetwork);
  DWORD WINAPI ResUtilFindDependentDiskResourceDriveLetter(HCLUSTER hCluster,HRESOURCE hResource,LPWSTR pszDriveLetter,DWORD *pcchDriveLetter);
  DWORD WINAPI ResUtilTerminateServiceProcessFromResDll(DWORD dwServicePid,WINBOOL bOffline,PDWORD pdwResourceState,PLOG_EVENT_ROUTINE pfnLogEvent,RESOURCE_HANDLE hResourceHandle);
  DWORD WINAPI ResUtilGetPropertyFormats(const PRESUTIL_PROPERTY_ITEM pPropertyTable,PVOID pOutPropertyFormatList,DWORD cbPropertyFormatListSize,LPDWORD pcbBytesReturned,LPDWORD pcbRequired);
  DWORD WINAPI ResUtilGetCoreClusterResources(HCLUSTER hCluster,HRESOURCE *phClusterNameResource,HRESOURCE *phClusterIPAddressResource,HRESOURCE *phClusterQuorumResource);
  DWORD WINAPI ResUtilGetResourceName(HRESOURCE hResource,PWSTR pszResourceName,DWORD *pcchResourceNameInOut);

#if (_WIN32_WINNT >= 0x0600)
typedef enum _CLUSTER_ROLE {
  ClusterRoleDHCP                          = 0,
  ClusterRoleDTC                           = 1,
  ClusterRoleFileServer                    = 2,
  ClusterRoleGenericApplication            = 3,
  ClusterRoleGenericScript                 = 4,
  ClusterRoleGenericService                = 5,
  ClusterRoleISCSINameServer               = 6,
  ClusterRoleMSMQ                          = 7,
  ClusterRoleNFS                           = 8,
  ClusterRolePrintServer                   = 9,
  ClusterRoleStandAloneNamespaceServer     = 10,
  ClusterRoleVolumeShadowCopyServiceTask   = 11,
  ClusterRoleWINS                          = 12 
} CLUSTER_ROLE;

typedef enum _CLUSTER_ROLE_STATE {
  ClusterRoleUnknown       = -1,
  ClusterRoleClustered     = 0,
  ClusterRoleUnclustered   = 1 
} CLUSTER_ROLE_STATE;

typedef enum RESOURCE_MONITOR_STATE {
  RmonInitializing,
  RmonIdle,
  RmonStartingResource,
  RmonInitializingResource,
  RmonOnlineResource,
  RmonOfflineResource,
  RmonShutdownResource,
  RmonDeletingResource,
  RmonIsAlivePoll,
  RmonLooksAlivePoll,
  RmonArbitrateResource,
  RmonReleaseResource,
  RmonResourceControl,
  RmonResourceTypeControl,
  RmonTerminateResource,
  RmonDeadlocked 
} RESOURCE_MONITOR_STATE;

typedef DWORD (CALLBACK *LPRESOURCE_CALLBACK)( 
  HRESOURCE hSelf,
  HRESOURCE hResource,
  PVOID pParameter
);

typedef DWORD (CALLBACK *LPRESOURCE_CALLBACK_EX)( 
  HCLUSTER hCluster,
  HRESOURCE hSelf,
  HRESOURCE hResource,
  PVOID pParameter
);

typedef struct RESUTIL_FILETIME_DATA {
  FILETIME Default;
  FILETIME Minimum;
  FILETIME Maximum;
} RESUTIL_FILETIME_DATA, *PRESUTIL_FILETIME_DATA;

DWORD ResUtilFindFileTimeProperty(
  const PVOID pPropertyList,
  DWORD cbPropertyListSize,
  LPCWSTR pszPropertyName,
  LPFILETIME pftPropertyValue
);

CLUSTER_ROLE_STATE WINAPI ResUtilGetClusterRoleState(
  HCLUSTER hCluster,
  CLUSTER_ROLE eClusterRole
);

DWORD WINAPI ResUtilGetFileTimeProperty(
  LPFILETIME pftOutValue,
  const PCLUSPROP_FILETIME pValueStruct,
  FILETIME ftOldValue,
  FILETIME ftMinimum,
  FILETIME ftMaximum,
  LPBYTE *ppPropertyList,
  LPDWORD pcbPropertyListSize
);

DWORD WINAPI ResUtilGetLongProperty(
  LPLONG plOutValue,
  const PCLUSPROP_LONG pValueStruct,
  LONG lOldValue,
  LONG lMinimum,
  LONG lMaximum,
  LPBYTE *ppPropertyList,
  LPDWORD pcbPropertyListSize
);

DWORD WINAPI ResUtilGetQwordValue(
  HKEY hkeyClusterKey,
  LPCWSTR pszValueName,
  PULONGLONG pqwOutValue,
  ULONGLONG qwDefaultValue
);

DWORD WINAPI ResUtilSetQwordValue(
  HKEY hkeyClusterKey,
  LPCWSTR pszValueName,
  ULONGLONG qwNewValue,
  PULONGLONG pqwOutValue
);

typedef DWORD (WINAPI *PWORKER_START_ROUTINE)( 
  PCLUS_WORKER pWorker,
  LPVOID lpThreadParameter
);

#endif /* (_WIN32_WINNT >= 0x0600) */

#if (_WIN32_WINNT >= 0x0600)
DWORD WINAPI ClusterClearBackupStateForSharedVolume(
  LPCWSTR lpszVolumePathName
);

WINBOOL WINAPI ClusterGetVolumeNameForVolumeMountPoint(
  LPCWSTR lpszVolumeMountPoint,
  LPWSTR lpszVolumeName,
  DWORD cchBufferLength
);

WINBOOL WINAPI ClusterGetVolumePathName(
  LPCWSTR lpszFileName,
  LPWSTR lpszVolumePathName,
  DWORD cchBufferLength
);

WINBOOL WINAPI ClusterIsPathOnSharedVolume(
  LPCWSTR lpszPathName
);

DWORD WINAPI ClusterPrepareSharedVolumeForBackup(
  LPCWSTR lpszFileName,
  LPWSTR lpszVolumePathName,
  LPDWORD lpcchVolumePathName,
  LPWSTR lpszVolumeName,
  LPDWORD lpcchVolumeName
);

#endif /* (_WIN32_WINNT >= 0x0600) */

#ifdef __cplusplus
}
#endif
#endif
