/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NLDEF
#define _INC_NLDEF

typedef enum _NL_ADDRESS_TYPE {
  NlatUnspecified,
  NlatUnicast,
  NlatAnycast,
  NlatMulticast,
  NlatBroadcast,
  NlatInvalid
} NL_ADDRESS_TYPE, *PNL_ADDRESS_TYPE;

typedef enum _NL_DAD_STATE {
  NldsInvalid = 0,
  NldsTentative,
  NldsDuplicate,
  NldsDeprecated,
  NldsPreferred,

  IpDadStateInvalid   = 0,
  IpDadStateTentative,
  IpDadStateDuplicate,
  IpDadStateDeprecated,
  IpDadStatePreferred
} NL_DAD_STATE;

typedef enum _NL_LINK_LOCAL_ADDRESS_BEHAVIOR {
  LinkLocalAlwaysOff   = 0,
  LinkLocalDelayed,
  LinkLocalAlwaysOn,
  LinkLocalUnchanged   = -1
} NL_LINK_LOCAL_ADDRESS_BEHAVIOR;

typedef enum _NL_NEIGHBOR_STATE {
  NlnsUnreachable,
  NlnsIncomplete,
  NlnsProbe,
  NlnsDelay,
  NlnsStale,
  NlnsReachable,
  NlnsPermanent,
  NlnsMaximum
} NL_NEIGHBOR_STATE, *PNL_NEIGHBOR_STATE;

typedef enum _tag_NL_PREFIX_ORIGIN {
  IpPrefixOriginOther           = 0,
  IpPrefixOriginManual,
  IpPrefixOriginWellKnown,
  IpPrefixOriginDhcp,
  IpPrefixOriginRouterAdvertisement,
  IpPrefixOriginUnchanged  = 1 << 4
} NL_PREFIX_ORIGIN;

typedef enum _NL_ROUTE_ORIGIN {
  NlroManual,
  NlroWellKnown,
  NlroDHCP,
  NlroRouterAdvertisement,
  Nlro6to4 
} NL_ROUTE_ORIGIN, *PNL_ROUTE_ORIGIN;

typedef enum _NL_ROUTE_PROTOCOL {
  RouteProtocolOther              = 1,
  RouteProtocolLocal,
  RouteProtocolNetMgmt,
  RouteProtocolIcmp,
  RouteProtocolEgp,
  RouteProtocolGgp,
  RouteProtocolHello,
  RouteProtocolRip,
  RouteProtocolIsIs,
  RouteProtocolEsIs,
  RouteProtocolCisco,
  RouteProtocolBbn,
  RouteProtocolOspf,
  RouteProtocolBgp,

  MIB_IPPROTO_OTHER               = 1,
     PROTO_IP_OTHER               = 1,
  MIB_IPPROTO_LOCAL               = 2,
     PROTO_IP_LOCAL               = 2,
  MIB_IPPROTO_NETMGMT             = 3,
     PROTO_IP_NETMGMT             = 3,
  MIB_IPPROTO_ICMP                = 4,
     PROTO_IP_ICMP                = 4,
  MIB_IPPROTO_EGP                 = 5,
     PROTO_IP_EGP                 = 5,
  MIB_IPPROTO_GGP                 = 6,
     PROTO_IP_GGP                 = 6,
  MIB_IPPROTO_HELLO               = 7,
     PROTO_IP_HELLO               = 7,
  MIB_IPPROTO_RIP                 = 8,
     PROTO_IP_RIP                 = 8,
  MIB_IPPROTO_IS_IS               = 9,
     PROTO_IP_IS_IS               = 9,
  MIB_IPPROTO_ES_IS               = 10,
     PROTO_IP_ES_IS               = 10,
  MIB_IPPROTO_CISCO               = 11,
     PROTO_IP_CISCO               = 11,
  MIB_IPPROTO_BBN                 = 12,
     PROTO_IP_BBN                 = 12,
  MIB_IPPROTO_OSPF                = 13,
     PROTO_IP_OSPF                = 13,
  MIB_IPPROTO_BGP                 = 14,
     PROTO_IP_BGP                 = 14,
  MIB_IPPROTO_NT_AUTOSTATIC       = 10002,
     PROTO_IP_NT_AUTOSTATIC       = 10002,
  MIB_IPPROTO_NT_STATIC           = 10006,
     PROTO_IP_NT_STATIC           = 10006,
  MIB_IPPROTO_NT_STATIC_NON_DOD   = 10007,
     PROTO_IP_NT_STATIC_NON_DOD   = 10007
} NL_ROUTE_PROTOCOL, *PNL_ROUTE_PROTOCOL;

typedef enum _NL_ROUTER_DISCOVERY_BEHAVIOR {
  RouterDiscoveryDisabled    = 0,
  RouterDiscoveryEnabled,
  RouterDiscoveryDhcp,
  RouterDiscoveryUnchanged   = -1
} NL_ROUTER_DISCOVERY_BEHAVIOR;

typedef enum _tag_NL_SUFFIX_ORIGIN {
  NlsoOther = 0,
  NlsoManual,
  NlsoWellKnown,
  NlsoDhcp,
  NlsoLinkLayerAddress,
  NlsoRandom,

  IpSuffixOriginOther        = 0,
  IpSuffixOriginManual,
  IpSuffixOriginWellKnown,
  IpSuffixOriginDhcp,
  IpSuffixOriginLinkLayerAddress,
  IpSuffixOriginRandom,
  IpSuffixOriginUnchanged = 1 << 4
} NL_SUFFIX_ORIGIN;

typedef struct _NL_INTERFACE_OFFLOAD_ROD {
  BOOLEAN NlChecksumSupported  :1;
  BOOLEAN NlOptionsSupported  :1;
  BOOLEAN TlDatagramChecksumSupported  :1;
  BOOLEAN TlStreamChecksumSupported  :1;
  BOOLEAN TlStreamOptionsSupported  :1;
  BOOLEAN FastPathCompatible : 1;
  BOOLEAN TlLargeSendOffloadSupported  :1;
  BOOLEAN TlGiantSendOffloadSupported  :1;
} NL_INTERFACE_OFFLOAD_ROD, *PNL_INTERFACE_OFFLOAD_ROD;

#endif /*_INC_NLDEF*/

