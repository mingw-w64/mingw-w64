/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNICODE
#define RpcCertGeneratePrincipalName RpcCertGeneratePrincipalNameW
#else
#define RpcCertGeneratePrincipalName RpcCertGeneratePrincipalNameA
#endif

  RPCRTAPI RPC_STATUS RPC_ENTRY RpcCertGeneratePrincipalNameW(PCCERT_CONTEXT Context,DWORD Flags,RPC_WSTR *pBuffer);
  RPCRTAPI RPC_STATUS RPC_ENTRY RpcCertGeneratePrincipalNameA(PCCERT_CONTEXT Context,DWORD Flags,RPC_CSTR *pBuffer);

#ifdef __cplusplus
}
#endif
