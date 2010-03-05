/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __IPHLPAPI_H__
#define __IPHLPAPI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <iprtrmib.h>
#include <ipexport.h>
#include <iptypes.h>

  DWORD WINAPI GetNumberOfInterfaces(PDWORD pdwNumIf);
  DWORD WINAPI GetIfEntry(PMIB_IFROW pIfRow);
  DWORD WINAPI GetIfTable(PMIB_IFTABLE pIfTable,PULONG pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetIpAddrTable(PMIB_IPADDRTABLE pIpAddrTable,PULONG pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetIpNetTable(PMIB_IPNETTABLE pIpNetTable,PULONG pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetIpForwardTable(PMIB_IPFORWARDTABLE pIpForwardTable,PULONG pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetTcpTable(PMIB_TCPTABLE pTcpTable,PDWORD pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetUdpTable(PMIB_UDPTABLE pUdpTable,PDWORD pdwSize,WINBOOL bOrder);
  DWORD WINAPI GetIpStatistics(PMIB_IPSTATS pStats);
  DWORD WINAPI GetIpStatisticsEx(PMIB_IPSTATS pStats,DWORD dwFamily);
  DWORD WINAPI GetIcmpStatistics(PMIB_ICMP pStats);
  DWORD WINAPI GetIcmpStatisticsEx(PMIB_ICMP_EX pStats,DWORD dwFamily);
  DWORD WINAPI GetTcpStatistics(PMIB_TCPSTATS pStats);
  DWORD WINAPI GetTcpStatisticsEx(PMIB_TCPSTATS pStats,DWORD dwFamily);
  DWORD WINAPI GetUdpStatistics(PMIB_UDPSTATS pStats);
  DWORD WINAPI GetUdpStatisticsEx(PMIB_UDPSTATS pStats,DWORD dwFamily);
  DWORD WINAPI SetIfEntry(PMIB_IFROW pIfRow);
  DWORD WINAPI CreateIpForwardEntry(PMIB_IPFORWARDROW pRoute);
  DWORD WINAPI SetIpForwardEntry(PMIB_IPFORWARDROW pRoute);
  DWORD WINAPI DeleteIpForwardEntry(PMIB_IPFORWARDROW pRoute);
  DWORD WINAPI SetIpStatistics(PMIB_IPSTATS pIpStats);
  DWORD WINAPI SetIpTTL(UINT nTTL);
  DWORD WINAPI CreateIpNetEntry(PMIB_IPNETROW pArpEntry);
  DWORD WINAPI SetIpNetEntry(PMIB_IPNETROW pArpEntry);
  DWORD WINAPI DeleteIpNetEntry(PMIB_IPNETROW pArpEntry);
  DWORD WINAPI FlushIpNetTable(DWORD dwIfIndex);
  DWORD WINAPI CreateProxyArpEntry(DWORD dwAddress,DWORD dwMask,DWORD dwIfIndex);
  DWORD WINAPI DeleteProxyArpEntry(DWORD dwAddress,DWORD dwMask,DWORD dwIfIndex);
  DWORD WINAPI SetTcpEntry(PMIB_TCPROW pTcpRow);
  DWORD WINAPI GetInterfaceInfo(PIP_INTERFACE_INFO pIfTable,PULONG dwOutBufLen);
  DWORD WINAPI GetUniDirectionalAdapterInfo(PIP_UNIDIRECTIONAL_ADAPTER_ADDRESS pIPIfInfo,PULONG dwOutBufLen);

#ifndef NhpAllocateAndGetInterfaceInfoFromStack_DEFINED
#define NhpAllocateAndGetInterfaceInfoFromStack_DEFINED
  DWORD WINAPI NhpAllocateAndGetInterfaceInfoFromStack(IP_INTERFACE_NAME_INFO **ppTable,PDWORD pdwCount,WINBOOL bOrder,HANDLE hHeap,DWORD dwFlags);
#endif

  DWORD WINAPI GetBestInterface(IPAddr dwDestAddr,PDWORD pdwBestIfIndex);
  DWORD WINAPI GetBestInterfaceEx(struct sockaddr *pDestAddr,PDWORD pdwBestIfIndex);
  DWORD WINAPI GetBestRoute(DWORD dwDestAddr,DWORD dwSourceAddr,PMIB_IPFORWARDROW pBestRoute);
  DWORD WINAPI GetExtendedTcpTable (PVOID pTcpTable,PDWORD pdwSize,BOOL bOrder,ULONG ulAf,TCP_TABLE_CLASS TableClass,ULONG Reserved);
  DWORD WINAPI NotifyAddrChange(PHANDLE Handle,LPOVERLAPPED overlapped);
  DWORD WINAPI NotifyRouteChange(PHANDLE Handle,LPOVERLAPPED overlapped);
  WINBOOL WINAPI CancelIPChangeNotify(LPOVERLAPPED notifyOverlapped);
  DWORD WINAPI GetAdapterIndex(LPWSTR AdapterName,PULONG IfIndex);
  DWORD WINAPI AddIPAddress(IPAddr Address,IPMask IpMask,DWORD IfIndex,PULONG NTEContext,PULONG NTEInstance);
  DWORD WINAPI DeleteIPAddress(ULONG NTEContext);
  DWORD WINAPI GetNetworkParams(PFIXED_INFO pFixedInfo,PULONG pOutBufLen);
  DWORD WINAPI GetAdaptersInfo(PIP_ADAPTER_INFO pAdapterInfo,PULONG pOutBufLen);
  PIP_ADAPTER_ORDER_MAP WINAPI GetAdapterOrderMap(VOID);

#ifdef _WINSOCK2API_
  DWORD WINAPI GetAdaptersAddresses(ULONG Family,DWORD Flags,PVOID Reserved,PIP_ADAPTER_ADDRESSES pAdapterAddresses,PULONG pOutBufLen);
#endif

  DWORD WINAPI GetPerAdapterInfo(ULONG IfIndex,PIP_PER_ADAPTER_INFO pPerAdapterInfo,PULONG pOutBufLen);
  DWORD WINAPI IpReleaseAddress(PIP_ADAPTER_INDEX_MAP AdapterInfo);
  DWORD WINAPI IpRenewAddress(PIP_ADAPTER_INDEX_MAP AdapterInfo);
  DWORD WINAPI SendARP(IPAddr DestIP,IPAddr SrcIP,PULONG pMacAddr,PULONG PhyAddrLen);
  WINBOOL WINAPI GetRTTAndHopCount(IPAddr DestIpAddress,PULONG HopCount,ULONG MaxHops,PULONG RTT);
  DWORD WINAPI GetFriendlyIfIndex(DWORD IfIndex);
  DWORD WINAPI EnableRouter(HANDLE *pHandle,OVERLAPPED *pOverlapped);
  DWORD WINAPI UnenableRouter(OVERLAPPED *pOverlapped,LPDWORD lpdwEnableCount);
  DWORD WINAPI DisableMediaSense(HANDLE *pHandle,OVERLAPPED *pOverLapped);
  DWORD WINAPI RestoreMediaSense(OVERLAPPED *pOverlapped,LPDWORD lpdwEnableCount);
  DWORD WINAPI GetIpErrorString(IP_STATUS ErrorCode,PWCHAR Buffer,PDWORD Size);

#ifdef __cplusplus
}
#endif
#endif
