/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef HCN_CLIENT_H
#define HCN_CLIENT_H

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum HCN_NOTIFICATIONS {
  HcnNotificationInvalid = 0x00000000,
  HcnNotificationNetworkPreCreate = 0x00000001,
  HcnNotificationNetworkCreate = 0x00000002,
  HcnNotificationNetworkPreDelete = 0x00000003,
  HcnNotificationNetworkDelete = 0x00000004,
  HcnNotificationNamespaceCreate = 0x00000005,
  HcnNotificationNamespaceDelete = 0x00000006,
  HcnNotificationServiceDisconnect = 0x01000000,
  HcnNotificationFlagsReserved = 0xF0000000
} HCN_NOTIFICATIONS;

typedef void* HCN_CALLBACK;

typedef void (CALLBACK *HCN_NOTIFICATION_CALLBACK)(DWORD NotificationType, void *Context, HRESULT NotificationStatus, PCWSTR NotificationData);

typedef void* HCN_NETWORK;
typedef HCN_NETWORK* PHCN_NETWORK;

HRESULT WINAPI HcnEnumerateNetworks (PCWSTR Query, PWSTR *Networks, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCreateNetwork (REFGUID Id, PCWSTR Settings, PHCN_NETWORK Network, PWSTR *ErrorRecord);
HRESULT WINAPI HcnOpenNetwork (REFGUID Id, PHCN_NETWORK Network, PWSTR *ErrorRecord);
HRESULT WINAPI HcnModifyNetwork (HCN_NETWORK Network, PCWSTR Settings, PWSTR *ErrorRecord);
HRESULT WINAPI HcnQueryNetworkProperties (HCN_NETWORK Network, PCWSTR Query, PWSTR *Properties, PWSTR *ErrorRecord);
HRESULT WINAPI HcnDeleteNetwork (REFGUID Id, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCloseNetwork (HCN_NETWORK Network);

typedef void* HCN_NAMESPACE;
typedef HCN_NAMESPACE* PHCN_NAMESPACE;

HRESULT WINAPI HcnEnumerateNamespaces (PCWSTR Query, PWSTR *Namespaces, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCreateNamespace (REFGUID Id, PCWSTR Settings, PHCN_NAMESPACE Namespace, PWSTR *ErrorRecord);
HRESULT WINAPI HcnOpenNamespace (REFGUID Id, PHCN_NAMESPACE Namespace, PWSTR *ErrorRecord);
HRESULT WINAPI HcnModifyNamespace (HCN_NAMESPACE Namespace, PCWSTR Settings, PWSTR *ErrorRecord);
HRESULT WINAPI HcnQueryNamespaceProperties (HCN_NAMESPACE Namespace, PCWSTR Query, PWSTR *Properties, PWSTR *ErrorRecord);
HRESULT WINAPI HcnDeleteNamespace (REFGUID Id, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCloseNamespace (HCN_NAMESPACE Namespace);

typedef void* HCN_ENDPOINT;
typedef HCN_ENDPOINT* PHCN_ENDPOINT;

HRESULT WINAPI HcnEnumerateEndpoints (PCWSTR Query, PWSTR *Endpoints, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCreateEndpoint (HCN_NETWORK Network, REFGUID Id, PCWSTR Settings, PHCN_ENDPOINT Endpoint, PWSTR *ErrorRecord);
HRESULT WINAPI HcnOpenEndpoint (REFGUID Id, PHCN_ENDPOINT Endpoint, PWSTR *ErrorRecord);
HRESULT WINAPI HcnModifyEndpoint (HCN_ENDPOINT Endpoint, PCWSTR Settings, PWSTR *ErrorRecord);
HRESULT WINAPI HcnQueryEndpointProperties (HCN_ENDPOINT Endpoint, PCWSTR Query, PWSTR *Properties, PWSTR *ErrorRecord);
HRESULT WINAPI HcnDeleteEndpoint (REFGUID Id, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCloseEndpoint (HCN_ENDPOINT Endpoint);

typedef void* HCN_LOADBALANCER;
typedef HCN_LOADBALANCER* PHCN_LOADBALANCER;

HRESULT WINAPI HcnEnumerateLoadBalancers (PCWSTR Query, PWSTR *LoadBalancer, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCreateLoadBalancer (REFGUID Id, PCWSTR Settings, PHCN_LOADBALANCER LoadBalancer, PWSTR *ErrorRecord);
HRESULT WINAPI HcnOpenLoadBalancer (REFGUID Id, PHCN_LOADBALANCER LoadBalancer, PWSTR *ErrorRecord);
HRESULT WINAPI HcnModifyLoadBalancer (HCN_LOADBALANCER LoadBalancer, PCWSTR Settings, PWSTR *ErrorRecord);
HRESULT WINAPI HcnQueryLoadBalancerProperties (HCN_LOADBALANCER LoadBalancer, PCWSTR Query, PWSTR *Properties, PWSTR *ErrorRecord);
HRESULT WINAPI HcnDeleteLoadBalancer (REFGUID Id, PWSTR *ErrorRecord);
HRESULT WINAPI HcnCloseLoadBalancer (HCN_LOADBALANCER LoadBalancer);

typedef void* HCN_SERVICE;
typedef HCN_SERVICE* PHCN_SERVICE;

HRESULT WINAPI HcnRegisterServiceCallback (HCN_NOTIFICATION_CALLBACK Callback, void *Context, HCN_CALLBACK *CallbackHandle);
HRESULT WINAPI HcnUnregisterServiceCallback (HCN_CALLBACK CallbackHandle);

#ifdef __cplusplus
}
#endif

#endif /* WINAPI_PARTITION_DESKTOP */

#endif /* HCN_CLIENT_H */
