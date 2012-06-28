/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_WDSTPTMGMT
#define _INC_WDSTPTMGMT
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _WDSTRANSPORT_DIAGNOSTICS_COMPONENT_FLAGS {
  WdsTptDiagnosticsComponentPxe           = 1,
  WdsTptDiagnosticsComponentTftp          = 2,
  WdsTptDiagnosticsComponentImageServer   = 4,
  WdsTptDiagnosticsComponentMulticast     = 8 
} WDSTRANSPORT_DIAGNOSTICS_COMPONENT_FLAGS;

typedef enum _WDSTRANSPORT_DISCONNECT_TYPE {
  WdsTptDisconnectUnknown    = 0,
  WdsTptDisconnectFallback   = 1,
  WdsTptDisconnectAbort      = 2 
} WDSTRANSPORT_DISCONNECT_TYPE;

typedef enum _WDSTRANSPORT_FEATURE_FLAGS {
  WdsTptFeatureAdminPack          = 1,
  WdsTptFeatureTransportServer    = 2,
  WdsTptFeatureDeploymentServer   = 4 
} WDSTRANSPORT_FEATURE_FLAGS;

typedef enum _WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE {
  WdsTptIpAddressSourceUnknown   = 0,
  WdsTptIpAddressSourceDhcp      = 1,
  WdsTptIpAddressSourceRange     = 2 
} WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE;

typedef enum _WDSTRANSPORT_IP_ADDRESS_TYPE {
  WdsTptIpAddressUnknown   = 0,
  WdsTptIpAddressIpv4      = 1,
  WdsTptIpAddressIpv6      = 2 
} WDSTRANSPORT_IP_ADDRESS_TYPE;

typedef enum _WDSTRANSPORT_NAMESPACE_TYPE {
  WdsTptNamespaceTypeUnknown                    = 0,
  WdsTptNamespaceTypeAutoCast                   = 1,
  WdsTptNamespaceTypeScheduledCastManualStart   = 2,
  WdsTptNamespaceTypeScheduledCastAutoStart     = 3 
} WDSTRANSPORT_NAMESPACE_TYPE;

typedef enum _WDSTRANSPORT_NETWORK_PROFILE_TYPE {
  WdsTptNetworkProfileUnknown   = 0,
  WdsTptNetworkProfileCustom    = 1,
  WdsTptNetworkProfile10Mbps    = 2,
  WdsTptNetworkProfile100Mbps   = 3,
  WdsTptNetworkProfile1Gbps     = 4 
} WDSTRANSPORT_NETWORK_PROFILE_TYPE;

typedef enum _WDSTRANSPORT_PROTOCOL_FLAGS {
  WdsTptProtocolUnicast     = 1,
  WdsTptProtocolMulticast   = 2 
} WDSTRANSPORT_PROTOCOL_FLAGS;

typedef enum _WDSTRANSPORT_SERVICE_NOTIFICATION {
  WdsTptServiceNotifyUnknown        = 0,
  WdsTptServiceNotifyReadSettings   = 1 
} WDSTRANSPORT_SERVICE_NOTIFICATION;

#ifdef __cplusplus
}
#endi
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WDSTPTMGMT*/
