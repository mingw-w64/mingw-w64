/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WERAPI
#define _INC_WERAPI
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

/* Guessed from http://msdn.microsoft.com/en-us/library/bb513623%28v=VS.85%29.aspx */
typedef enum _WER_REGISTER_FILE_TYPE {
  WerFileTypeHeapdump,
  WerFileTypeMicrodump,
  WerFileTypeMinidump,
  WerRegFileTypeOther,
  WerRegFileTypeUserDocument
} WER_REGISTER_FILE_TYPE;

/* Guessed from http://msdn.microsoft.com/en-us/library/bb513622%28VS.85%29.aspx */
typedef enum _WER_DUMP_TYPE {
  WerDumpTypeHeapDump,
  WerDumpTypeMicroDump,
  WerDumpTypeMiniDump,
} WER_DUMP_TYPE;

/* Guessed from http://msdn.microsoft.com/en-us/library/bb513627%28v=VS.85%29.aspx */
typedef enum _WER_REPORT_UI {
  WerUIAdditionalDataDlgHeader,
  WerUICloseDlgBody,
  WerUICloseDlgButtonText,
  WerUICloseDlgHeader,
  WerUICloseText,
  WerUIConsentDlgBody,
  WerUIConsentDlgHeader,
  WerUIIconFilePath,
  WerUIOfflineSolutionCheckText,
  WerUIOnlineSolutionCheckText
} WER_REPORT_UI;

/* Guessed from http://msdn.microsoft.com/en-us/library/bb513628%28v=VS.85%29.aspx */
typedef enum _WER_CONSENT {
  WerConsentApproved,
  WerConsentDenied,
  WerConsentNotAsked
} WER_CONSENT;

/* Guessed from http://msdn.microsoft.com/en-us/library/bb513628%28v=VS.85%29.aspx */
typedef enum _WER_SUBMIT_RESULT {
  WerDisabled,
  WerDisabledQueue,
  WerReportAsync,
  WerReportCancelled,
  WerReportDebug,
  WerReportFailed,
  WerReportQueued,
  WerReportUploaded
} WER_SUBMIT_RESULT;

typedef struct _WER_DUMP_CUSTOM_OPTIONS {
  DWORD dwSize;
  DWORD dwMask;
  DWORD dwDumpFlags;
  WINBOOL bOnlyThisThread;
  DWORD dwExceptionThreadFlags;
  DWORD dwOtherThreadFlags;
  DWORD dwExceptionThreadExFlags;
  DWORD dwOtherThreadExFlags;
  DWORD dwPreferredModuleFlags;
  DWORD dwOtherModuleFlags;
  WCHAR wzPreferredModuleList[WER_MAX_PREFERRED_MODULES_BUFFER];
} WER_DUMP_CUSTOM_OPTIONS, *PWER_DUMP_CUSTOM_OPTIONS;

typedef struct _WER_EXCEPTION_INFORMATION {
  PEXCEPTION_POINTERS pExceptionPointers;
  WINBOOL             bClientPointers;
} WER_EXCEPTION_INFORMATION, *PWER_EXCEPTION_INFORMATION;

typedef struct _WER_REPORT_INFORMATION {
  DWORD  dwSize;
  HANDLE hProcess;
  WCHAR  wzConsentKey[64];
  WCHAR  wzFriendlyEventName[128];
  WCHAR  wzApplicationName[128];
  WCHAR  wzApplicationPath[MAX_PATH];
  WCHAR  wzDescription[512];
  HWND   hwndParent;
} WER_REPORT_INFORMATION, *PWER_REPORT_INFORMATION;

HRESULT WINAPI WerAddExcludedApplication(
  PCWSTR pwzExeName,
  WINBOOL bAllUsers
);

HRESULT WINAPI WerGetFlags(
  HANDLE hProcess,
  PDWORD pdwFlags
);

HRESULT WINAPI WerRegisterFile(
  PCWSTR pwzFile,
  WER_REGISTER_FILE_TYPE regFileType,
  DWORD dwFlags
);

HRESULT WINAPI WerRegisterMemoryBlock(
  PVOID pvAddress,
  DWORD dwSize
);

HRESULT WINAPI WerRemoveExcludedApplication(
  PCWSTR pwzExeName,
  WINBOOL bAllUsers
);

HRESULT WINAPI WerReportAddDump(
  HREPORT hReportHandle,
  HANDLE hProcess,
  HANDLE hThread,
  WER_DUMP_TYPE dumpType,
  PWER_EXCEPTION_INFORMATION pExceptionParam,
  PWER_DUMP_CUSTOM_OPTIONS pDumpCustomOptions,
  DWORD dwFlags
);

HRESULT WINAPI WerReportAddFile(
  HREPORT hReportHandle,
  PCWSTR pwzPath,
  WER_FILE_TYPE repFileType,
  DWORD dwFileFlags
);

HRESULT WINAPI WerReportCloseHandle(
  HREPORT hReportHandle
);

HRESULT WINAPI WerReportCreate(
  PCWSTR pwzEventType,
  WER_REPORT_TYPE repType,
  PWER_REPORT_INFORMATION pReportInformation,
  HREPORT *phReportHandle
);

HRESULT WINAPI WerReportHang(
  HWND hwndHungWindow,
  PCWSTR wszHungApplicationName
);

HRESULT WINAPI WerReportSetParameter(
  HREPORT hReportHandle,
  DWORD dwparamID,
  PCWSTR pwzName,
  PCWSTR pwzValue
);

HRESULT WINAPI WerReportSetUIOption(
  HREPORT hReportHandle,
  WER_REPORT_UI repUITypeID,
  PCWSTR pwzValue
);

HRESULT WINAPI WerReportSubmit(
  HREPORT hReportHandle,
  WER_CONSENT consent,
  DWORD dwFlags,
  PWER_SUBMIT_RESULT pSubmitResult
);

HRESULT WINAPI WerSetFlags(
  DWORD dwFlags
);

HRESULT WINAPI WerUnregisterFile(
  PCWSTR pwzFilePath
);

HRESULT WINAPI WerUnregisterMemoryBlock(
  PVOID pvAddress
);

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WERAPI*/
