/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_BCRYPT
#define _INC_BCRYPT
#if (_WIN32_WINNT >= 0x0600)

#if !defined (_NTDEF_) && !defined (_NTSTATUS_PSDK)
#define _NTSTATUS_PSDK
  typedef LONG NTSTATUS,*PNTSTATUS;
#endif

#define BCRYPT_CIPHER_OPERATION                 0x00000001
#define BCRYPT_HASH_OPERATION                   0x00000002
#define BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION  0x00000004
#define BCRYPT_SECRET_AGREEMENT_OPERATION       0x00000008
#define BCRYPT_SIGNATURE_OPERATION              0x00000010
#define BCRYPT_RNG_OPERATION                    0x00000020

#define BCRYPT_KEY_DATA_BLOB_MAGIC              0x4d42444b
#define BCRYPT_KEY_DATA_BLOB_VERSION1           1

#define BCRYPT_DH_PARAMETERS_MAGIC              0x4d504844

#define BCRYPT_DSA_PUBLIC_MAGIC                 0x42505344
#define BCRYPT_DSA_PRIVATE_MAGIC                0x56505344

#define BCRYPT_DSA_PARAMETERS_MAGIC             0x4d505344

#define BCRYPT_ALGORITHM_NAME                   L"AlgorithmName"
#define BCRYPT_AUTH_TAG_LENGTH                  L"AuthTagLength"
#define BCRYPT_BLOCK_LENGTH                     L"BlockLength"
#define BCRYPT_BLOCK_SIZE_LIST                  L"BlockSizeList"
#define BCRYPT_CHAINING_MODE                    L"ChainingMode"
#define BCRYPT_CHAIN_MODE_CBC                   L"ChainingModeCBC"
#define BCRYPT_CHAIN_MODE_CCM                   L"ChainingModeCCM"
#define BCRYPT_CHAIN_MODE_CFB                   L"ChainingModeCFB"
#define BCRYPT_CHAIN_MODE_ECB                   L"ChainingModeECB"
#define BCRYPT_CHAIN_MODE_GCM                   L"ChainingModeGCM"
#define BCRYPT_CHAIN_MODE_NA                    L"ChainingModeN/A"
#define BCRYPT_DH_PARAMETERS                    L"DHParameters"
#define BCRYPT_DSA_PARAMETERS                   L"DSAParameters"
#define BCRYPT_EFFECTIVE_KEY_LENGTH             L"EffectiveKeyLength"
#define BCRYPT_HASH_BLOCK_LENGTH                L"HashBlockLength"
#define BCRYPT_HASH_LENGTH                      L"HashDigestLength"
#define BCRYPT_HASH_OID_LIST                    L"HashOIDList"
#define BCRYPT_INITIALIZATION_VECTOR            L"IV"
#define BCRYPT_KEY_LENGTH                       L"KeyLength"
#define BCRYPT_KEY_LENGTHS                      L"KeyLengths"
#define BCRYPT_KEY_OBJECT_LENGTH                L"KeyObjectLength"
#define BCRYPT_KEY_STRENGTH                     L"KeyStrength"
#define BCRYPT_OBJECT_LENGTH                    L"ObjectLength"
#define BCRYPT_PADDING_SCHEMES                  L"PaddingSchemes"
#define BCRYPT_SUPPORTED_PAD_ROUTER             0x00000001
#define BCRYPT_SUPPORTED_PAD_PKCS1_ENC          0x00000002
#define BCRYPT_SUPPORTED_PAD_PKCS1_SIG          0x00000004
#define BCRYPT_SUPPORTED_PAD_OAEP               0x00000008
#define BCRYPT_SUPPORTED_PAD_PSS                0x00000010
#define BCRYPT_PROVIDER_HANDLE                  L"ProviderHandle"
#define BCRYPT_SIGNATURE_LENGTH                 L"SignatureLength"

#define KDF_HASH_ALGORITHM                      0
#define KDF_SECRET_PREPEND                      1
#define KDF_SECRET_APPEND                       2
#define KDF_HMAC_KEY                            3
#define KDF_TLS_PRF_LABEL                       4
#define KDF_TLS_PRF_SEED                        5
#define KDF_SECRET_HANDLE                       6

#define BCRYPT_KDF_HASH (L"HASH")
#define BCRYPT_KDF_HASH (L"HASH")
#define BCRYPT_KDF_TLS_PRF (L"TLS_PRF")
#define BCRYPT_KDF_SP80056A_CONCAT (L"SP800_56A_CONCAT")

#define CRYPT_ALL_FUNCTIONS 1
#define CRYPT_ALL_PROVIDERS 2

#ifndef __BCRYPT_KEY_HANDLE_DEFINED__
#define __BCRYPT_KEY_HANDLE_DEFINED__
/*also in cryptxml.h*/
typedef LPVOID BCRYPT_KEY_HANDLE;
#endif /*__BCRYPT_KEY_HANDLE_DEFINED__*/
typedef LPVOID BCRYPT_ALG_HANDLE;
typedef LPVOID BCRYPT_HASH_HANDLE;
typedef LPVOID BCRYPT_SECRET_HANDLE;
typedef LPVOID BCRYPT_HANDLE;

typedef struct _BCRYPT_ALGORITHM_IDENTIFIER {
  LPWSTR pszName;
  ULONG  dwClass;
  ULONG  dwFlags;
} BCRYPT_ALGORITHM_IDENTIFIER;

typedef struct _BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO {
  ULONG     cbSize;
  ULONG     dwInfoVersion;
  PUCHAR    pbNonce;
  ULONG     cbNonce;
  PUCHAR    pbAuthData;
  ULONG     cbAuthData;
  PUCHAR    pbTag;
  ULONG     cbTag;
  PUCHAR    pbMacContext;
  ULONG     cbMacContext;
  ULONG     cbAAD;
  ULONGLONG cbData;
  ULONG     dwFlags;
} BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO, *PBCRYPT_AUTHENTICATED_CIPHER_MODE_INFO;

typedef struct _BCRYPT_DH_KEY_BLOB {
  ULONG dwMagic;
  ULONG cbKey;
} BCRYPT_DH_KEY_BLOB, *PBCRYPT_DH_KEY_BLOB;

typedef struct _BCRYPT_DH_PARAMETER_HEADER {
  ULONG cbLength;
  ULONG dwMagic;
  ULONG cbKeyLength;
} BCRYPT_DH_PARAMETER_HEADER;

typedef struct _BCRYPT_DSA_KEY_BLOB {
  ULONG dwMagic;
  ULONG cbKey;
  UCHAR Count[4];
  UCHAR Seed[20];
  UCHAR q[20];
} BCRYPT_DSA_KEY_BLOB, *PBCRYPT_DSA_KEY_BLOB;

typedef struct _BCRYPT_DSA_PARAMETER_HEADER {
  ULONG cbLength;
  ULONG dwMagic;
  ULONG cbKeyLength;
  UCHAR Count[4];
  UCHAR Seed[20];
  UCHAR q[20];
} BCRYPT_DSA_PARAMETER_HEADER, *PBCRYPT_DSA_PARAMETER_HEADER;

typedef struct _BCRYPT_ECCKEY_BLOB {
  ULONG Magic;
  ULONG cbKey;
} BCRYPT_ECCKEY_BLOB, *PBCRYPT_ECCKEY_BLOB;

typedef struct _BCRYPT_INTERFACE_VERSION {
  USHORT MajorVersion;
  USHORT MinorVersion;
} BCRYPT_INTERFACE_VERSION, *PBCRYPT_INTERFACE_VERSION;

typedef struct _BCRYPT_KEY_BLOB {
  ULONG Magic;
} BCRYPT_KEY_BLOB;

typedef struct _BCRYPT_KEY_DATA_BLOB_HEADER {
  ULONG dwMagic;
  ULONG dwVersion;
  ULONG cbKeyData;
} BCRYPT_KEY_DATA_BLOB_HEADER, *PBCRYPT_KEY_DATA_BLOB_HEADER;

typedef struct __BCRYPT_KEY_LENGTHS_STRUCT {
  ULONG dwMinLength;
  ULONG dwMaxLength;
  ULONG dwIncrement;
} BCRYPT_KEY_LENGTHS_STRUCT, BCRYPT_AUTH_TAG_LENGTHS_STRUCT;

typedef struct _BCRYPT_OAEP_PADDING_INFO {
  LPCWSTR pszAlgId;
  PUCHAR  pbLabel;
  ULONG   cbLabel;
} BCRYPT_OAEP_PADDING_INFO;

typedef struct _BCRYPT_OID {
  ULONG  cbOID;
  PUCHAR pbOID;
} BCRYPT_OID;

typedef struct _BCRYPT_OID_LIST {
  ULONG      dwOIDCount;
  BCRYPT_OID *pOIDs;
} BCRYPT_OID_LIST;

typedef struct _BCRYPT_PKCS1_PADDING_INFO {
  LPCWSTR pszAlgId;
} BCRYPT_PKCS1_PADDING_INFO;

typedef struct _BCRYPT_PROVIDER_NAME {
  LPWSTR pszProviderName;
} BCRYPT_PROVIDER_NAME;

typedef struct _BCRYPT_PSS_PADDING_INFO {
  LPCWSTR pszAlgId;
  ULONG   cbSalt;
} BCRYPT_PSS_PADDING_INFO;

typedef struct _BCRYPT_RSAKEY_BLOB {
  ULONG Magic;
  ULONG BitLength;
  ULONG cbPublicExp;
  ULONG cbModulus;
  ULONG cbPrime1;
  ULONG cbPrime2;
} BCRYPT_RSAKEY_BLOB;

typedef struct _BCryptBuffer {
  ULONG cbBuffer;
  ULONG BufferType;
  PVOID pvBuffer;
} BCryptBuffer, *PBCryptBuffer;

typedef struct _BCryptBufferDesc {
  ULONG         ulVersion;
  ULONG         cBuffers;
  PBCryptBuffer pBuffers;
} BCryptBufferDesc, *PBCryptBufferDesc;

typedef struct _CRYPT_CONTEXTS {
  ULONG cContexts;
  PWSTR rgpszContexts;
} CRYPT_CONTEXTS, *PCRYPT_CONTEXTS;

typedef struct _CRYPT_CONTEXT_CONFIG {
  ULONG dwFlags;
} CRYPT_CONTEXT_CONFIG, *PCRYPT_CONTEXT_CONFIG;

typedef struct _CRYPT_CONTEXT_FUNCTIONS {
  ULONG cFunctions;
  PWSTR rgpszFunctions;
} CRYPT_CONTEXT_FUNCTIONS, *PCRYPT_CONTEXT_FUNCTIONS;

typedef struct _CRYPT_CONTEXT_FUNCTION_CONFIG {
  ULONG dwFlags;
} CRYPT_CONTEXT_FUNCTION_CONFIG, *PCRYPT_CONTEXT_FUNCTION_CONFIG;

typedef struct _CRYPT_CONTEXT_FUNCTION_PROVIDERS {
  ULONG cProviders;
  PWSTR *rgpszProviders;
} CRYPT_CONTEXT_FUNCTION_PROVIDERS, *PCRYPT_CONTEXT_FUNCTION_PROVIDERS;

typedef struct _CRYPT_INTERFACE_REG {
  ULONG dwInterface;
  ULONG dwFlags;
  ULONG cFunctions;
  PWSTR *rgpszFunctions;
} CRYPT_INTERFACE_REG, *PCRYPT_INTERFACE_REG;

typedef struct _CRYPT_IMAGE_REG {
  PWSTR                pszImage;
  ULONG                cInterfaces;
  PCRYPT_INTERFACE_REG *rgpInterfaces;
} CRYPT_IMAGE_REG, *PCRYPT_IMAGE_REG;

typedef struct _CRYPT_IMAGE_REF {
  PWSTR pszImage;
  ULONG dwFlags;
} CRYPT_IMAGE_REF, *PCRYPT_IMAGE_REF;

typedef struct _CRYPT_PROPERTY_REF {
  PWSTR  pszProperty;
  ULONG  cbValue;
  PUCHAR pbValue;
} CRYPT_PROPERTY_REF, *PCRYPT_PROPERTY_REF;

typedef struct _CRYPT_PROVIDERS {
  ULONG cProviders;
  PWSTR *rgpszProviders;
} CRYPT_PROVIDERS, *PCRYPT_PROVIDERS;

typedef struct _CRYPT_PROVIDER_REG {
  ULONG            cAliases;
  PWSTR            *rgpszAliases;
  PCRYPT_IMAGE_REG pUM;
  PCRYPT_IMAGE_REG pKM;
} CRYPT_PROVIDER_REG, *PCRYPT_PROVIDER_REG;

typedef struct _CRYPT_PROVIDER_REF {
  ULONG               dwInterface;
  PWSTR               pszFunction;
  PWSTR               pszProvider;
  ULONG               cProperties;
  PCRYPT_PROPERTY_REF *rgpProperties;
  PCRYPT_IMAGE_REF    pUM;
  PCRYPT_IMAGE_REF    pKM;
} CRYPT_PROVIDER_REF, *PCRYPT_PROVIDER_REF;

typedef struct _CRYPT_PROVIDER_REFS {
  ULONG               cProviders;
  PCRYPT_PROVIDER_REF *rgpProviders;
} CRYPT_PROVIDER_REFS, *PCRYPT_PROVIDER_REFS;

NTSTATUS WINAPI BCryptAddContextFunction(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  ULONG dwPosition
);

NTSTATUS WINAPI BCryptCloseAlgorithmProvider(
  BCRYPT_ALG_HANDLE hAlgorithm,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptConfigureContext(
  ULONG dwTable,
  LPCWSTR pszContext,
  PCRYPT_CONTEXT_CONFIG pConfig
);

NTSTATUS WINAPI BCryptConfigureContextFunction(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig
);

NTSTATUS WINAPI BCryptCreateContext(
  ULONG dwTable,
  LPCWSTR pszContext,
  PCRYPT_CONTEXT_CONFIG pConfig
);

NTSTATUS WINAPI BCryptCreateHash(
  BCRYPT_ALG_HANDLE hAlgorithm,
  BCRYPT_HASH_HANDLE *phHash,
  PUCHAR pbHashObject,
  ULONG cbHashObject,
  PUCHAR pbSecret,
  ULONG cbSecret,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptDecrypt(
  BCRYPT_KEY_HANDLE hKey,
  PUCHAR pbInput,
  ULONG cbInput,
  VOID *pPaddingInfo,
  PUCHAR pbIV,
  ULONG cbIV,
  PUCHAR pbOutput,
  ULONG cbOutput,
  ULONG *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptDeleteContext(
  ULONG dwTable,
  LPCWSTR pszContext
);

NTSTATUS WINAPI BCryptDeriveKey(
  BCRYPT_SECRET_HANDLE hSharedSecret,
  LPCWSTR pwszKDF,
  BCryptBufferDesc *pParameterList,
  PUCHAR pbDerivedKey,
  ULONG cbDerivedKey,
  ULONG *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptDestroyHash(
  BCRYPT_HASH_HANDLE hHash
);

NTSTATUS WINAPI BCryptDestroyKey(
  BCRYPT_KEY_HANDLE hKey
);

NTSTATUS WINAPI BCryptDuplicateHash(
  BCRYPT_HASH_HANDLE hHash,
  BCRYPT_HASH_HANDLE *phNewHash,
  PUCHAR pbHashObject,
  ULONG cbHashObject,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptDuplicateKey(
  BCRYPT_KEY_HANDLE hKey,
  BCRYPT_KEY_HANDLE *phNewKey,
  PUCHAR pbKeyObject,
  ULONG cbKeyObject,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptEnumAlgorithms(
  ULONG dwAlgOperations,
  ULONG *pAlgCount,
  BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptEnumContexts(
  ULONG dwTable,
  ULONG *pcbBuffer,
  PCRYPT_CONTEXTS *ppBuffer
);

NTSTATUS WINAPI BCryptEnumContextFunctions(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  ULONG *pcbBuffer,
  PCRYPT_CONTEXT_FUNCTIONS *ppBuffer
);

NTSTATUS WINAPI BCryptEnumContextFunctionProviders(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  ULONG *pcbBuffer,
  PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer
);

NTSTATUS WINAPI BCryptEnumProviders(
  LPCWSTR pszAlgId,
  ULONG *pImplCount,
  BCRYPT_PROVIDER_NAME **ppImplList,
  ULONG dwFlags
);
NTSTATUS WINAPI BCryptEnumRegisteredProviders(
  ULONG *pcbBuffer,
  PCRYPT_PROVIDERS *ppBuffer
);

NTSTATUS WINAPI BCryptEncrypt(
  BCRYPT_KEY_HANDLE hKey,
  PUCHAR pbInput,
  ULONG cbInput,
  VOID *pPaddingInfo,
  PUCHAR pbIV,
  ULONG cbIV,
  PUCHAR pbOutput,
  ULONG cbOutput,
  ULONG *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptExportKey(
  BCRYPT_KEY_HANDLE hKey,
  BCRYPT_KEY_HANDLE hExportKey,
  LPCWSTR pszBlobType,
  PUCHAR pbOutput,
  ULONG cbOutput,
  ULONG *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptFinishHash(
  BCRYPT_HASH_HANDLE hHash,
  PUCHAR pbOutput,
  ULONG cbOutput,
  ULONG dwFlags
);
VOID WINAPI BCryptFreeBuffer(
  PVOID pvBuffer
);

NTSTATUS WINAPI BCryptGenerateKeyPair(
  BCRYPT_ALG_HANDLE hAlgorithm,
  BCRYPT_KEY_HANDLE *phKey,
  ULONG dwLength,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptGenerateSymmetricKey(
  BCRYPT_ALG_HANDLE hAlgorithm,
  BCRYPT_KEY_HANDLE *phKey,
  PUCHAR pbKeyObject,
  ULONG cbKeyObject,
  PUCHAR pbSecret,
  ULONG cbSecret,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptGenRandom(
  BCRYPT_ALG_HANDLE hAlgorithm,
  PUCHAR pbBuffer,
  ULONG cbBuffer,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptGetFipsAlgorithmMode(
  BOOLEAN *pfEnabled
);

NTSTATUS WINAPI BCryptGetProperty(
  BCRYPT_HANDLE hObject,
  LPCWSTR pszProperty,
  PUCHAR pbOutput,
  ULONG cbOutput,
  ULONG *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptHashData(
  BCRYPT_HASH_HANDLE hHash,
  PUCHAR pbInput,
  ULONG cbInput,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptImportKey(
  BCRYPT_ALG_HANDLE hAlgorithm,
  BCRYPT_KEY_HANDLE hImportKey,
  LPCWSTR pszBlobType,
  BCRYPT_KEY_HANDLE *phKey,
  PUCHAR pbKeyObject,
  ULONG cbKeyObject,
  PUCHAR pbInput,
  ULONG cbInput,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptImportKeyPair(
  BCRYPT_ALG_HANDLE hAlgorithm,
  BCRYPT_KEY_HANDLE hImportKey,
  LPCWSTR pszBlobType,
  BCRYPT_KEY_HANDLE *phKey,
  PUCHAR pbInput,
  ULONG cbInput,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptFinalizeKeyPair(
  BCRYPT_KEY_HANDLE hKey,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptOpenAlgorithmProvider(
  BCRYPT_ALG_HANDLE *phAlgorithm,
  LPCWSTR pszAlgId,
  LPCWSTR pszImplementation,
  DWORD dwFlags
);

NTSTATUS WINAPI BCryptQueryContextConfiguration(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG *pcbBuffer,
  PCRYPT_CONTEXT_CONFIG *ppBuffer
);

NTSTATUS WINAPI BCryptQueryContextFunctionConfiguration(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  ULONG *pcbBuffer,
  PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer
);

NTSTATUS WINAPI BCryptQueryContextFunctionProperty(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  LPCWSTR pszProperty,
  ULONG *pcbValue,
  PUCHAR *ppbValue
);

NTSTATUS WINAPI BCryptQueryProviderRegistration(
  LPCWSTR pszProvider,
  ULONG dwMode,
  ULONG dwInterface,
  ULONG *pcbBuffer,
  PCRYPT_PROVIDER_REG *ppBuffer
);

/* Kernel mode
NTSTATUS WINAPI BCryptRegisterConfigChangeNotify(
  PRKEVENT phEvent
);

NTSTATUS WINAPI BCryptUnregisterConfigChangeNotify(
  PRKEVENT hEvent
);
*/

NTSTATUS WINAPI BCryptRegisterConfigChangeNotify(
  HANDLE *phEvent
);

NTSTATUS WINAPI BCryptUnregisterConfigChangeNotify(
  HANDLE hEvent
);

NTSTATUS WINAPI BCryptRemoveContextFunction(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction
);

NTSTATUS WINAPI BCryptResolveProviders(
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  LPCWSTR pszProvider,
  ULONG dwMode,
  ULONG dwFlags,
  ULONG *pcbBuffer,
  PCRYPT_PROVIDER_REFS *ppBuffer
);

NTSTATUS WINAPI BCryptSecretAgreement(
  BCRYPT_KEY_HANDLE hPrivKey,
  BCRYPT_KEY_HANDLE hPubKey,
  BCRYPT_SECRET_HANDLE *phSecret,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptSetContextFunctionProperty(
  ULONG dwTable,
  LPCWSTR pszContext,
  ULONG dwInterface,
  LPCWSTR pszFunction,
  LPCWSTR pszProperty,
  ULONG cbValue,
  PUCHAR pbValue
);

NTSTATUS WINAPI BCryptSetProperty(
  BCRYPT_HANDLE hObject,
  LPCWSTR pszProperty,
  PUCHAR pbInput,
  ULONG cbInput,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptSignHash(
  BCRYPT_KEY_HANDLE hKey,
  VOID *pPaddingInfo,
  PBYTE pbInput,
  DWORD cbInput,
  PBYTE pbOutput,
  DWORD cbOutput,
  DWORD *pcbResult,
  ULONG dwFlags
);

NTSTATUS WINAPI BCryptVerifySignature(
  BCRYPT_KEY_HANDLE hKey,
  VOID *pPaddingInfo,
  PUCHAR pbHash,
  ULONG cbHash,
  PUCHAR pbSignature,
  ULONG cbSignature,
  ULONG dwFlags
);

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_BCRYPT*/
