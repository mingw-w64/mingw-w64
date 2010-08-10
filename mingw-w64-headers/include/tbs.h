/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_TBS
#define _INC_TBS
#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus
extern "C" {
#endif

typedef UINT32 TBS_RESULT; /* Assumed */

typedef enum _TBS_COMMAND_LOCALITY {
  TBS_COMMAND_LOCALITY_ZERO = 0,
  TBS_COMMAND_LOCALITY_ONE,
  TBS_COMMAND_LOCALITY_TWO,
  TBS_COMMAND_LOCALITY_THREE,
  TBS_COMMAND_LOCALITY_FOUR
} TBS_COMMAND_LOCALITY;

typedef enum _TBS_COMMAND_PRIORITY {
  TBS_COMMAND_PRIORITY_LOW = 100,
  TBS_COMMAND_PRIORITY_NORMAL = 200,
  TBS_COMMAND_PRIORITY_HIGH = 300,
  TBS_COMMAND_PRIORITY_SYSTEM = 400,
  TBS_COMMAND_PRIORITY_MAX = 0x80000000
} TBS_COMMAND_PRIORITY;

typedef struct _TBS_CONTEXT_PARAMS {
  UINT32 version;
} TBS_CONTEXT_PARAMS;

typedef LPVOID TBS_HCONTEXT;

#define TBS_SUCCESS 0
#define TBS_E_BAD_PARAMETER 0x80284002
#define TBS_E_INTERNAL_ERROR 0x80284007
#define TBS_E_INVALID_OUTPUT_POINTER 0x80284003
#define TBS_E_SERVICE_DISABLED 0x80284010
#define TBS_E_SERVICE_NOT_RUNNING 0x80284008
#define TBS_E_SERVICE_START_PENDING 0x8028400B
#define TBS_E_TOO_MANY_TBS_CONTEXTS 0x80284009
#define TBS_E_TPM_NOT_FOUND 0x8028400F
#define TBS_E_DEACTIVATED 0x80284016
#define TBS_E_INVALID_CONTEXT_PARAM 0x80284007
#define TBS_E_IOERROR 0x80284006
#define TBS_E_INSUFFICIENT_BUFFER 0x80284005
#define TBS_E_BUFFER_TOO_LARGE 0x8028400E

TBS_RESULT WINAPI Tbsi_Context_Create(
  const TBS_CONTEXT_PARAMS *pContextParams,
  TBS_HCONTEXT *phContext
);

TBS_RESULT WINAPI Tbsi_Get_TCG_Log(
  TBS_HCONTEXT hContext,
  BYTE *pOutputBuf,
  UINT32 *pOutputBufLen
);

TBS_RESULT WINAPI Tbsi_Physical_Presence_Command(
  TBS_HCONTEXT hContext,
  const BYTE *pInputBuf,
  UINT32 InputBufLen,
  BYTE *pOutputBuf,
  UINT32 *pOutputBufLen
);

TBS_RESULT WINAPI Tbsip_Cancel_Commands(
  TBS_HCONTEXT hContext
);

TBS_RESULT WINAPI Tbsip_Context_Close(
  TBS_HCONTEXT hContext
);

TBS_RESULT WINAPI Tbsip_Submit_Command(
  TBS_HCONTEXT hContext,
  TBS_COMMAND_LOCALITY locality,
  TBS_COMMAND_PRIORITY priority,
  const BYTE *pCommandBuf,
  UINT32 commandBufLen,
  BYTE *pResultBuf,
  UINT32 *pResultBufLen
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_TBH*/
