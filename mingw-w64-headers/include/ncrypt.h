/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NCRYPT
#define _INC_NCRYPT
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

#define NCRYPTBUFFER_SSL_CLIENT_RANDOM 20
#define NCRYPTBUFFER_SSL_SERVER_RANDOM 21
#define NCRYPTBUFFER_SSL_HIGHEST_VERSION 22
#define NCRYPTBUFFER_SSL_CLEAR_KEY 23
#define NCRYPTBUFFER_SSL_KEY_ARG_DATA 24
#define NCRYPTBUFFER_PKCS_OID 40
#define NCRYPTBUFFER_PKCS_ALG_OID 41
#define NCRYPTBUFFER_PKCS_ALG_PARAM 42
#define NCRYPTBUFFER_PKCS_ALG_ID 43
#define NCRYPTBUFFER_PKCS_ATTRS 44
#define NCRYPTBUFFER_PKCS_KEY_NAME 45
#define NCRYPTBUFFER_PKCS_SECRET 46
#define NCRYPTBUFFER_CERT_BLOB 47

#ifndef __SECSTATUS_DEFINED__
  typedef LONG SECURITY_STATUS;
#define __SECSTATUS_DEFINED__
#endif

#ifndef __NCRYPT_KEY_HANDLE__
#define __NCRYPT_KEY_HANDLE__
/*in wincrypt.h too*/
typedef ULONG_PTR NCRYPT_KEY_HANDLE;
#endif

typedef ULONG_PTR NCRYPT_PROV_HANDLE;
typedef ULONG_PTR NCRYPT_SECRET_HANDLE;
typedef ULONG_PTR NCRYPT_HANDLE;

#ifndef __HCRYPTKEY__
#define __HCRYPTKEY__
/* In wincrypt.h too */
  typedef ULONG_PTR HCRYPTPROV;
  typedef ULONG_PTR HCRYPTKEY;
#endif

typedef struct _NCryptBuffer {
  ULONG cbBuffer;
  ULONG BufferType;
  PVOID pvBuffer;
} NCryptBuffer, *PNCryptBuffer;

typedef struct _NCryptBufferDesc {
  ULONG         ulVersion;
  ULONG         cBuffers;
  PNCryptBuffer pBuffers;
} NCryptBufferDesc, *PNCryptBufferDesc;

typedef struct __NCRYPT_SUPPORTED_LENGTHS {
  DWORD dwMinLength;
  DWORD dwMaxLength;
  DWORD dwIncrement;
  DWORD dwDefaultLength;
} NCRYPT_SUPPORTED_LENGTHS;

#define NCRYPT_UI_PROTECT_KEY_FLAG 0x00000001
#define NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG 0x00000002

typedef struct __NCRYPT_UI_POLICY {
  DWORD   dwVersion;
  DWORD   dwFlags;
  LPCWSTR pszCreationTitle;
  LPCWSTR pszFriendlyName;
  LPCWSTR pszDescription;
} NCRYPT_UI_POLICY;

typedef struct __NCRYPT_UI_POLICY_BLOB {
  DWORD dwVersion;
  DWORD dwFlags;
  DWORD cbCreationTitle;
  DWORD cbFriendlyName;
  DWORD cbDescription;
} NCRYPT_UI_POLICY_BLOB;

typedef struct NCryptKeyName {
  LPWSTR pszName;
  LPWSTR pszAlgid;
  DWORD  dwLegacyKeySpec;
  DWORD  dwFlags;
} NCryptKeyName;

#define NCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE 0x00000003
#define NCRYPT_SECRET_AGREEMENT_INTERFACE 0x00000004
#define NCRYPT_SIGNATURE_INTERFACE 0x00000005

#define NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION 0x00000004
#define NCRYPT_SECRET_AGREEMENT_OPERATION 0x00000008
#define NCRYPT_SIGNATURE_OPERATION 0x00000010

typedef struct _NCryptAlgorithmName {
  LPWSTR pszName;
  DWORD  dwClass;
  DWORD  dwAlgOperations;
  DWORD  dwFlags;
} NCryptAlgorithmName;

typedef struct NCryptProviderName {
  LPWSTR pszName;
  LPWSTR pszComment;
} NCryptProviderName;

SECURITY_STATUS WINAPI NCryptExportKey(
  NCRYPT_KEY_HANDLE hKey,
  NCRYPT_KEY_HANDLE hExportKey,
  LPCWSTR pszBlobType,
  NCryptBufferDesc *pParameterList,
  PBYTE pbOutput,
  DWORD cbOutput,
  DWORD *pcbResult,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptCreatePersistedKey(
  NCRYPT_PROV_HANDLE hProvider,
  NCRYPT_KEY_HANDLE *phKey,
  LPCWSTR pszAlgId,
  LPCWSTR pszKeyName,
  DWORD dwLegacyKeySpec,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptDecrypt(
  NCRYPT_KEY_HANDLE hKey,
  PBYTE pbInput,
  DWORD cbInput,
  VOID *pPaddingInfo,
  PBYTE pbOutput,
  DWORD cbOutput,
  DWORD *pcbResult,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptDeleteKey(
  NCRYPT_KEY_HANDLE hKey,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptDeriveKey(
  NCRYPT_SECRET_HANDLE hSharedSecret,
  LPCWSTR pwszKDF,
  NCryptBufferDesc *pParameterList,
  PBYTE pbDerivedKey,
  DWORD cbDerivedKey,
  DWORD *pcbResult,
  ULONG dwFlags
);

SECURITY_STATUS WINAPI NCryptEncrypt(
  NCRYPT_KEY_HANDLE hKey,
  PBYTE pbInput,
  DWORD cbInput,
  VOID *pPaddingInfo,
  PBYTE pbOutput,
  DWORD cbOutput,
  DWORD *pcbResult,
  DWORD dwFlags
);

#define NCRYPT_CIPHER_OPERATION 0x00000001
#define NCRYPT_HASH_OPERATION 0x00000002
#define NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION 0x00000004
#define NCRYPT_SECRET_AGREEMENT_OPERATION 0x00000008
#define NCRYPT_SIGNATURE_OPERATION 0x00000010
#define NCRYPT_RNG_OPERATION 0x00000020

SECURITY_STATUS WINAPI NCryptEnumAlgorithms(
  NCRYPT_PROV_HANDLE hProvider,
  DWORD dwAlgOperations,
  DWORD *pdwAlgCount,
  NCryptAlgorithmName **ppAlgList,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptEnumKeys(
  NCRYPT_PROV_HANDLE hProvider,
  LPCWSTR pszScope,
  NCryptKeyName **ppKeyName,
  PVOID *ppEnumState,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptEnumStorageProviders(
  DWORD *pdwProviderCount,
  NCryptProviderName **ppProviderList,
  DWORD dwFlags
);

SECURITY_STATUS NCryptFinalizeKey(
  NCRYPT_KEY_HANDLE hKey,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptFreeBuffer(
  PVOID pvInput
);

SECURITY_STATUS WINAPI NCryptFreeObject(
  NCRYPT_HANDLE hObject
);

SECURITY_STATUS WINAPI NCryptGetProperty(
  NCRYPT_HANDLE hObject,
  LPCWSTR pszProperty,
  PBYTE pbOutput,
  DWORD cbOutput,
  DWORD *pcbResult,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptImportKey(
  NCRYPT_PROV_HANDLE hProvider,
  NCRYPT_KEY_HANDLE hImportKey,
  LPCWSTR pszBlobType,
  NCryptBufferDesc *pParameterList,
  NCRYPT_KEY_HANDLE *phKey,
  PBYTE pbData,
  DWORD cbData,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptIsAlgSupported(
  NCRYPT_PROV_HANDLE hProvider,
  LPCWSTR pszAlgId,
  DWORD dwFlags
);

WINBOOL WINAPI NCryptIsKeyHandle(
  NCRYPT_KEY_HANDLE hKey
);

SECURITY_STATUS WINAPI NCryptNotifyChangeKey(
  NCRYPT_PROV_HANDLE hProvider,
  HANDLE *phEvent,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptOpenKey(
  NCRYPT_PROV_HANDLE hProvider,
  NCRYPT_KEY_HANDLE *phKey,
  LPCWSTR pszKeyName,
  DWORD dwLegacyKeySpec,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptOpenStorageProvider(
  NCRYPT_PROV_HANDLE *phProvider,
  LPCWSTR pszProviderName,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptSecretAgreement(
  NCRYPT_KEY_HANDLE hPrivKey,
  NCRYPT_KEY_HANDLE hPubKey,
  NCRYPT_SECRET_HANDLE *phSecret,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptSetProperty(
  NCRYPT_HANDLE hObject,
  LPCWSTR pszProperty,
  PBYTE pbInput,
  DWORD cbInput,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptSignHash(
  NCRYPT_KEY_HANDLE hKey,
  VOID *pPaddingInfo,
  PBYTE pbHashValue,
  DWORD cbHashValue,
  PBYTE pbSignature,
  DWORD cbSignature,
  DWORD *pcbResult,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptTranslateHandle(
  NCRYPT_PROV_HANDLE *phProvider,
  NCRYPT_KEY_HANDLE *phKey,
  HCRYPTPROV hLegacyProv,
  HCRYPTKEY hLegacyKey,
  DWORD dwLegacyKeySpec,
  DWORD dwFlags
);

SECURITY_STATUS WINAPI NCryptVerifySignature(
  NCRYPT_KEY_HANDLE hKey,
  VOID *pPaddingInfo,
  PBYTE pbHashValue,
  DWORD cbHashValue,
  PBYTE pbSignature,
  DWORD cbSignature,
  DWORD dwFlags
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_NCRYPT*/
