/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _DHCPSAPI_
#define _DHCPSAPI_

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#define DHCP_API_FUNCTION WINAPI

#ifdef __cplusplus
#define DHCP_CONST const
extern "C" {
#else
#define DHCP_CONST
#endif

typedef DWORD DHCP_IP_ADDRESS,*PDHCP_IP_ADDRESS,*LPDHCP_IP_ADDRESS;
typedef DWORD DHCP_IP_MASK;
typedef DWORD DHCP_RESUME_HANDLE;
typedef DWORD DHCP_OPTION_ID;

typedef struct _DATE_TIME {
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} DATE_TIME,*LPDATE_TIME;

typedef struct _DWORD_DWORD {
  DWORD DWord1;
  DWORD DWord2;
} DWORD_DWORD,*LPDWORD_DWORD;

typedef struct _DHCP_BINARY_DATA {
  DWORD DataLength;
  BYTE *Data;
} DHCP_BINARY_DATA,*LPDHCP_BINARY_DATA;

typedef DHCP_BINARY_DATA DHCP_CLIENT_UID;

#define DHCP_ENDPOINT_FLAG_CANT_MODIFY 0x01

typedef struct _DHCP_BIND_ELEMENT {
  ULONG Flags;
  WINBOOL fBoundToDHCPServer;
  DHCP_IP_ADDRESS AdapterPrimaryAddress;
  DHCP_IP_ADDRESS AdapterSubnetAddress;
  LPWSTR IfDescription;
  ULONG IfIdSize;
  LPBYTE IfId;
} DHCP_BIND_ELEMENT,*LPDHCP_BIND_ELEMENT;

typedef struct _DHCP_BIND_ELEMENT_ARRAY {
  DWORD NumElements;
  LPDHCP_BIND_ELEMENT Elements;
} DHCP_BIND_ELEMENT_ARRAY,*LPDHCP_BIND_ELEMENT_ARRAY;

typedef enum _DHCP_CLIENT_SEARCH_TYPE {
  DhcpClientIpAddress,DhcpClientHardwareAddress,DhcpClientName
} DHCP_SEARCH_INFO_TYPE,*LPDHCP_SEARCH_INFO_TYPE;

typedef struct _DHCP_CLIENT_SEARCH_INFO {
  DHCP_SEARCH_INFO_TYPE SearchType;
  union _DHCP_CLIENT_SEARCH_UNION {
    DHCP_IP_ADDRESS ClientIpAddress;
    DHCP_CLIENT_UID ClientHardwareAddress;
    LPWSTR ClientName;
  } SearchInfo;
} DHCP_SEARCH_INFO,*LPDHCP_SEARCH_INFO;

typedef enum _DHCP_OPTION_SCOPE_TYPE {
  DhcpDefaultOptions,DhcpGlobalOptions,DhcpSubnetOptions,DhcpReservedOptions,DhcpMScopeOptions
} DHCP_OPTION_SCOPE_TYPE,*LPDHCP_OPTION_SCOPE_TYPE;

typedef struct _DHCP_RESERVED_SCOPE {
  DHCP_IP_ADDRESS ReservedIpAddress;
  DHCP_IP_ADDRESS ReservedIpSubnetAddress;
} DHCP_RESERVED_SCOPE,*LPDHCP_RESERVED_SCOPE;

typedef struct _DHCP_OPTION_SCOPE_INFO {
  DHCP_OPTION_SCOPE_TYPE ScopeType;
  union _DHCP_OPTION_SCOPE_UNION {
    PVOID DefaultScopeInfo;
    PVOID GlobalScopeInfo;
    DHCP_IP_ADDRESS SubnetScopeInfo;
    DHCP_RESERVED_SCOPE ReservedScopeInfo;
    LPWSTR MScopeInfo;
  } ScopeInfo;
} DHCP_OPTION_SCOPE_INFO,*LPDHCP_OPTION_SCOPE_INFO;

typedef struct _DHCP_HOST_INFO {
  DHCP_IP_ADDRESS IpAddress;
  LPWSTR NetBiosName;
  LPWSTR HostName;
} DHCP_HOST_INFO,*LPDHCP_HOST_INFO;

typedef struct _DHCP_CLIENT_INFO {
  DHCP_IP_ADDRESS ClientIpAddress;
  DHCP_IP_MASK SubnetMask;
  DHCP_CLIENT_UID ClientHardwareAddress;
  LPWSTR ClientName;
  LPWSTR ClientComment;
  DATE_TIME ClientLeaseExpires;
  DHCP_HOST_INFO OwnerHost;
} DHCP_CLIENT_INFO,*LPDHCP_CLIENT_INFO;

typedef struct _DHCP_CLIENT_INFO_ARRAY {
  DWORD NumElements;
  LPDHCP_CLIENT_INFO *Clients;
} DHCP_CLIENT_INFO_ARRAY,*LPDHCP_CLIENT_INFO_ARRAY;

typedef struct _DHCP_IP_ARRAY {
  DWORD NumElements;
  LPDHCP_IP_ADDRESS Elements;
} DHCP_IP_ARRAY,*LPDHCP_IP_ARRAY;

typedef enum _DHCP_SUBNET_STATE {
  DhcpSubnetEnabled = 0,DhcpSubnetDisabled,DhcpSubnetEnabledSwitched,DhcpSubnetDisabledSwitched,DhcpSubnetInvalidState
} DHCP_SUBNET_STATE,*LPDHCP_SUBNET_STATE;

typedef struct _DHCP_SUBNET_INFO {
  DHCP_IP_ADDRESS SubnetAddress;
  DHCP_IP_MASK SubnetMask;
  LPWSTR SubnetName;
  LPWSTR SubnetComment;
  DHCP_HOST_INFO PrimaryHost;
  DHCP_SUBNET_STATE SubnetState;
} DHCP_SUBNET_INFO,*LPDHCP_SUBNET_INFO;

typedef enum _DHCP_OPTION_DATA_TYPE {
  DhcpByteOption,DhcpWordOption,DhcpDWordOption,DhcpDWordDWordOption,DhcpIpAddressOption,DhcpStringDataOption,DhcpBinaryDataOption,DhcpEncapsulatedDataOption
} DHCP_OPTION_DATA_TYPE,*LPDHCP_OPTION_DATA_TYPE;

typedef struct _DHCP_OPTION_DATA_ELEMENT {
  DHCP_OPTION_DATA_TYPE OptionType;
  union _DHCP_OPTION_ELEMENT_UNION {
    BYTE ByteOption;
    WORD WordOption;
    DWORD DWordOption;
    DWORD_DWORD DWordDWordOption;
    DHCP_IP_ADDRESS IpAddressOption;
    LPWSTR StringDataOption;
    DHCP_BINARY_DATA BinaryDataOption;
    DHCP_BINARY_DATA EncapsulatedDataOption;

  } Element;
} DHCP_OPTION_DATA_ELEMENT,*LPDHCP_OPTION_DATA_ELEMENT;

typedef struct _DHCP_OPTION_DATA {
  DWORD NumElements;
  LPDHCP_OPTION_DATA_ELEMENT Elements;
} DHCP_OPTION_DATA,*LPDHCP_OPTION_DATA;

typedef struct _DHCP_OPTION_VALUE {
  DHCP_OPTION_ID OptionID;
  DHCP_OPTION_DATA Value;
} DHCP_OPTION_VALUE,*LPDHCP_OPTION_VALUE;

DWORD WINAPI DhcpGetVersion(LPWSTR ServerIpAddress,LPDWORD MajorVersion,LPDWORD MinorVersion);
DWORD WINAPI DhcpSetServerBindingInfo(DHCP_CONST WCHAR *ServerIpAddress,ULONG Flags,LPDHCP_BIND_ELEMENT_ARRAY BindElementInfo);
DWORD WINAPI DhcpGetServerBindingInfo(DHCP_CONST WCHAR *ServerIpAddress,ULONG Flags,LPDHCP_BIND_ELEMENT_ARRAY *BindElementsInfo);
DWORD WINAPI DhcpCreateClientInfo(DHCP_CONST WCHAR *ServerIpAddress,DHCP_CONST DHCP_CLIENT_INFO *ClientInfo);
DWORD WINAPI DhcpSetClientInfo(DHCP_CONST WCHAR *ServerIpAddress,DHCP_CONST DHCP_CLIENT_INFO *ClientInfo);
DWORD WINAPI DhcpGetClientInfo(DHCP_CONST WCHAR *ServerIpAddress,DHCP_CONST DHCP_SEARCH_INFO *SearchInfo,LPDHCP_CLIENT_INFO *ClientInfo);
DWORD WINAPI DhcpDeleteClientInfo(DHCP_CONST WCHAR *ServerIpAddress,DHCP_CONST DHCP_SEARCH_INFO *ClientInfo);
DWORD WINAPI DhcpEnumSubnetClients(DHCP_CONST WCHAR *ServerIpAddress,DHCP_IP_ADDRESS SubnetAddress,DHCP_RESUME_HANDLE *ResumeHandle,DWORD PreferredMaximum,LPDHCP_CLIENT_INFO_ARRAY *ClientInfo,DWORD *ClientsRead,DWORD *ClientsTotal);
DWORD WINAPI DhcpEnumSubnets(DHCP_CONST WCHAR *ServerIpAddress,DHCP_RESUME_HANDLE *ResumeHandle,DWORD PreferredMaximum,LPDHCP_IP_ARRAY *EnumInfo,DWORD *ElementsRead,DWORD *ElementsTotal);
DWORD WINAPI DhcpGetSubnetInfo(DHCP_CONST WCHAR *ServerIpAddress,DHCP_IP_ADDRESS SubnetAddress,LPDHCP_SUBNET_INFO *SubnetInfo);
DWORD WINAPI DhcpGetOptionValue(DHCP_CONST WCHAR *ServerIpAddress,DHCP_OPTION_ID OptionID,DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo,LPDHCP_OPTION_VALUE *OptionValue);
VOID WINAPI DhcpRpcFreeMemory(PVOID BufferPointer);

#ifdef __cplusplus
}
#endif
#endif
