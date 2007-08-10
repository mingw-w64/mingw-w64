/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef IP_TYPES_INCLUDED
#define IP_TYPES_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

#define MAX_ADAPTER_DESCRIPTION_LENGTH 128
#define MAX_ADAPTER_NAME_LENGTH 256
#define MAX_ADAPTER_ADDRESS_LENGTH 8
#define DEFAULT_MINIMUM_ENTITIES 32
#define MAX_HOSTNAME_LEN 128
#define MAX_DOMAIN_NAME_LEN 128
#define MAX_SCOPE_ID_LEN 256

#define BROADCAST_NODETYPE 1
#define PEER_TO_PEER_NODETYPE 2
#define MIXED_NODETYPE 4
#define HYBRID_NODETYPE 8

  typedef struct {
    char String[4*4];
  } IP_ADDRESS_STRING,*PIP_ADDRESS_STRING,IP_MASK_STRING,*PIP_MASK_STRING;

  typedef struct _IP_ADDR_STRING {
    struct _IP_ADDR_STRING *Next;
    IP_ADDRESS_STRING IpAddress;
    IP_MASK_STRING IpMask;
    DWORD Context;
  } IP_ADDR_STRING,*PIP_ADDR_STRING;

  typedef struct _IP_ADAPTER_INFO {
    struct _IP_ADAPTER_INFO *Next;
    DWORD ComboIndex;
    char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
    char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
    UINT AddressLength;
    BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
    DWORD Index;
    UINT Type;
    UINT DhcpEnabled;
    PIP_ADDR_STRING CurrentIpAddress;
    IP_ADDR_STRING IpAddressList;
    IP_ADDR_STRING GatewayList;
    IP_ADDR_STRING DhcpServer;
    WINBOOL HaveWins;
    IP_ADDR_STRING PrimaryWinsServer;
    IP_ADDR_STRING SecondaryWinsServer;
    time_t LeaseObtained;
    time_t LeaseExpires;
  } IP_ADAPTER_INFO,*PIP_ADAPTER_INFO;

#ifdef _WINSOCK2API_

  typedef enum {
    IpPrefixOriginOther = 0,IpPrefixOriginManual,IpPrefixOriginWellKnown,IpPrefixOriginDhcp,IpPrefixOriginRouterAdvertisement
  } IP_PREFIX_ORIGIN;

  typedef enum {
    IpSuffixOriginOther = 0,IpSuffixOriginManual,IpSuffixOriginWellKnown,IpSuffixOriginDhcp,IpSuffixOriginLinkLayerAddress,IpSuffixOriginRandom
  } IP_SUFFIX_ORIGIN;

  typedef enum {
    IpDadStateInvalid = 0,IpDadStateTentative,IpDadStateDuplicate,IpDadStateDeprecated,IpDadStatePreferred
  } IP_DAD_STATE;

  typedef struct _IP_ADAPTER_UNICAST_ADDRESS {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD Flags;
      };
    };
    struct _IP_ADAPTER_UNICAST_ADDRESS *Next;
    SOCKET_ADDRESS Address;
    IP_PREFIX_ORIGIN PrefixOrigin;
    IP_SUFFIX_ORIGIN SuffixOrigin;
    IP_DAD_STATE DadState;
    ULONG ValidLifetime;
    ULONG PreferredLifetime;
    ULONG LeaseLifetime;
  } IP_ADAPTER_UNICAST_ADDRESS,*PIP_ADAPTER_UNICAST_ADDRESS;

  typedef struct _IP_ADAPTER_ANYCAST_ADDRESS {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD Flags;
      };
    };
    struct _IP_ADAPTER_ANYCAST_ADDRESS *Next;
    SOCKET_ADDRESS Address;
  } IP_ADAPTER_ANYCAST_ADDRESS,*PIP_ADAPTER_ANYCAST_ADDRESS;

  typedef struct _IP_ADAPTER_MULTICAST_ADDRESS {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD Flags;
      };
    };
    struct _IP_ADAPTER_MULTICAST_ADDRESS *Next;
    SOCKET_ADDRESS Address;
  } IP_ADAPTER_MULTICAST_ADDRESS,*PIP_ADAPTER_MULTICAST_ADDRESS;

#define IP_ADAPTER_ADDRESS_DNS_ELIGIBLE 0x01
#define IP_ADAPTER_ADDRESS_TRANSIENT 0x02
#define IP_ADAPTER_ADDRESS_PRIMARY 0x04

  typedef struct _IP_ADAPTER_DNS_SERVER_ADDRESS {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD Reserved;
      };
    };
    struct _IP_ADAPTER_DNS_SERVER_ADDRESS *Next;
    SOCKET_ADDRESS Address;
  } IP_ADAPTER_DNS_SERVER_ADDRESS,*PIP_ADAPTER_DNS_SERVER_ADDRESS;

  typedef struct _IP_ADAPTER_PREFIX {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD Flags;
      };
    };
    struct _IP_ADAPTER_PREFIX *Next;
    SOCKET_ADDRESS Address;
    ULONG PrefixLength;
  } IP_ADAPTER_PREFIX,*PIP_ADAPTER_PREFIX;

#define IP_ADAPTER_DDNS_ENABLED 0x01
#define IP_ADAPTER_REGISTER_ADAPTER_SUFFIX 0x02
#define IP_ADAPTER_DHCP_ENABLED 0x04
#define IP_ADAPTER_RECEIVE_ONLY 0x08
#define IP_ADAPTER_NO_MULTICAST 0x10
#define IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG 0x20

  typedef enum {
    IfOperStatusUp = 1,IfOperStatusDown,IfOperStatusTesting,IfOperStatusUnknown,IfOperStatusDormant,IfOperStatusNotPresent,IfOperStatusLowerLayerDown
  } IF_OPER_STATUS;

  typedef enum {
    ScopeLevelInterface = 1,ScopeLevelLink = 2,ScopeLevelSubnet = 3,ScopeLevelAdmin = 4,ScopeLevelSite = 5,ScopeLevelOrganization = 8,
    ScopeLevelGlobal = 14
  } SCOPE_LEVEL;

  typedef struct _IP_ADAPTER_ADDRESSES {
    union {
      ULONGLONG Alignment;
      struct {
	ULONG Length;
	DWORD IfIndex;
      };
    };
    struct _IP_ADAPTER_ADDRESSES *Next;
    PCHAR AdapterName;
    PIP_ADAPTER_UNICAST_ADDRESS FirstUnicastAddress;
    PIP_ADAPTER_ANYCAST_ADDRESS FirstAnycastAddress;
    PIP_ADAPTER_MULTICAST_ADDRESS FirstMulticastAddress;
    PIP_ADAPTER_DNS_SERVER_ADDRESS FirstDnsServerAddress;
    PWCHAR DnsSuffix;
    PWCHAR Description;
    PWCHAR FriendlyName;
    BYTE PhysicalAddress[MAX_ADAPTER_ADDRESS_LENGTH];
    DWORD PhysicalAddressLength;
    DWORD Flags;
    DWORD Mtu;
    DWORD IfType;
    IF_OPER_STATUS OperStatus;
    DWORD Ipv6IfIndex;
    DWORD ZoneIndices[16];
    PIP_ADAPTER_PREFIX FirstPrefix;
  } IP_ADAPTER_ADDRESSES,*PIP_ADAPTER_ADDRESSES;

#define GAA_FLAG_SKIP_UNICAST 0x0001
#define GAA_FLAG_SKIP_ANYCAST 0x0002
#define GAA_FLAG_SKIP_MULTICAST 0x0004
#define GAA_FLAG_SKIP_DNS_SERVER 0x0008
#define GAA_FLAG_INCLUDE_PREFIX 0x0010
#define GAA_FLAG_SKIP_FRIENDLY_NAME 0x0020
#endif

  typedef struct _IP_PER_ADAPTER_INFO {
    UINT AutoconfigEnabled;
    UINT AutoconfigActive;
    PIP_ADDR_STRING CurrentDnsServer;
    IP_ADDR_STRING DnsServerList;
  } IP_PER_ADAPTER_INFO,*PIP_PER_ADAPTER_INFO;

  typedef struct {
    char HostName[MAX_HOSTNAME_LEN + 4];
    char DomainName[MAX_DOMAIN_NAME_LEN + 4];
    PIP_ADDR_STRING CurrentDnsServer;
    IP_ADDR_STRING DnsServerList;
    UINT NodeType;
    char ScopeId[MAX_SCOPE_ID_LEN + 4];
    UINT EnableRouting;
    UINT EnableProxy;
    UINT EnableDns;
  } FIXED_INFO,*PFIXED_INFO;

#ifndef IP_INTERFACE_NAME_INFO_DEFINED
#define IP_INTERFACE_NAME_INFO_DEFINED

  typedef struct ip_interface_name_info {
    ULONG Index;
    ULONG MediaType;
    UCHAR ConnectionType;
    UCHAR AccessType;
    GUID DeviceGuid;
    GUID InterfaceGuid;
  } IP_INTERFACE_NAME_INFO,*PIP_INTERFACE_NAME_INFO;
#endif

#ifdef __cplusplus
}
#endif
#endif
