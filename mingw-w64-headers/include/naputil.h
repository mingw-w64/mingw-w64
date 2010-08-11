/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NAPUTIL
#define _INC_NAPUTIL

#include <naptypes.h>
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#define NAPAPI DECLSPEC_IMPORT

  NAPAPI HRESULT WINAPI AllocConnections(Connections **connections,UINT16 connectionsCount);
  NAPAPI VOID WINAPI FreeConnections(Connections *connections);
  NAPAPI HRESULT WINAPI AllocFixupInfo(FixupInfo **fixupInfo,UINT16 countResultCodes);
  NAPAPI VOID WINAPI FreeCountedString(CountedString *countedString);
  NAPAPI VOID WINAPI FreeFixupInfo(FixupInfo *fixupInfo);
  NAPAPI VOID WINAPI FreeIsolationInfo(IsolationInfo *isolationInfo);
  NAPAPI VOID WINAPI FreeIsolationInfoEx(IsolationInfoEx *isolationInfo);
  NAPAPI VOID WINAPI FreeNapComponentRegistrationInfoArray(UINT16 count,NapComponentRegistrationInfo **info);
  NAPAPI VOID WINAPI FreeNetworkSoH(NetworkSoH *networkSoh);
  NAPAPI VOID WINAPI FreePrivateData(PrivateData *privateData);
  NAPAPI VOID WINAPI FreeSoH(SoH *soh);
  NAPAPI VOID WINAPI FreeSoHAttributeValue(SoHAttributeType type,SoHAttributeValue *value);
  NAPAPI VOID WINAPI FreeSystemHealthAgentState(SystemHealthAgentState *state);
  NAPAPI HRESULT WINAPI InitializeNapAgentNotifier(NapNotifyType type,HANDLE hNotifyEvent);
  NAPAPI VOID WINAPI UninitializeNapAgentNotifier(NapNotifyType type);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /* _INC_NAPUTIL */

