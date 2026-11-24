#pragma once

#if defined(_X86_) || defined(_AMD64_)

typedef union _MCI_ADDR {
  _ANONYMOUS_STRUCT struct {
    ULONG Address;
    ULONG Reserved;
  } DUMMYSTRUCTNAME;
  ULONGLONG QuadPart;
} MCI_ADDR, *PMCI_ADDR;

typedef enum {
  HAL_MCE_RECORD,
  HAL_MCA_RECORD
} MCA_EXCEPTION_TYPE;

#if defined(_AMD64_)

#if (NTDDI_VERSION <= NTDDI_WINXP)

typedef union _MCI_STATS {
  struct {
    USHORT McaCod;
    USHORT ModelErrorCode;
    ULONG OtherInfo:25;
    ULONG Damage:1;
    ULONG AddressValid:1;
    ULONG MiscValid:1;
    ULONG Enabled:1;
    ULONG Uncorrected:1;
    ULONG OverFlow:1;
    ULONG Valid:1;
  } MciStatus;
  ULONG64 QuadPart;
} MCI_STATS, *PMCI_STATS;

#else

typedef union _MCI_STATS {
  struct {
    USHORT McaErrorCode;
    USHORT ModelErrorCode;
    ULONG OtherInformation:25;
    ULONG ContextCorrupt:1;
    ULONG AddressValid:1;
    ULONG MiscValid:1;
    ULONG ErrorEnabled:1;
    ULONG UncorrectedError:1;
    ULONG StatusOverFlow:1;
    ULONG Valid:1;
  } MciStatus;
  ULONG64 QuadPart;
} MCI_STATS, *PMCI_STATS;

#endif /* (NTDDI_VERSION <= NTDDI_WINXP) */

#endif /* defined(_AMD64_) */

#if defined(_X86_)
typedef union _MCI_STATS {
  struct {
    USHORT McaCod;
    USHORT MsCod;
    ULONG OtherInfo:25;
    ULONG Damage:1;
    ULONG AddressValid:1;
    ULONG MiscValid:1;
    ULONG Enabled:1;
    ULONG UnCorrected:1;
    ULONG OverFlow:1;
    ULONG Valid:1;
  } MciStats;
  ULONGLONG QuadPart;
} MCI_STATS, *PMCI_STATS;
#endif

#define MCA_EXTREG_V2MAX               24

#if defined(_X86_) || defined(_AMD64_)

#if (NTDDI_VERSION >= NTDDI_WINXP)

typedef struct _MCA_EXCEPTION {
  ULONG VersionNumber;
  MCA_EXCEPTION_TYPE ExceptionType;
  LARGE_INTEGER TimeStamp;
  ULONG ProcessorNumber;
  ULONG Reserved1;
  union {
    struct {
      UCHAR BankNumber;
      UCHAR Reserved2[7];
      MCI_STATS Status;
      MCI_ADDR Address;
      ULONGLONG Misc;
    } Mca;
    struct {
      ULONGLONG Address;
      ULONGLONG Type;
    } Mce;
  } u;
  ULONG ExtCnt;
  ULONG Reserved3;
  ULONGLONG ExtReg[MCA_EXTREG_V2MAX];
} MCA_EXCEPTION, *PMCA_EXCEPTION;

#else

typedef struct _MCA_EXCEPTION {
  ULONG VersionNumber;
  MCA_EXCEPTION_TYPE ExceptionType;
  LARGE_INTEGER TimeStamp;
  ULONG ProcessorNumber;
  ULONG Reserved1;
  union {
    struct {
      UCHAR BankNumber;
      UCHAR Reserved2[7];
      MCI_STATS Status;
      MCI_ADDR Address;
      ULONGLONG Misc;
    } Mca;
    struct {
      ULONGLONG Address;
      ULONGLONG Type;
    } Mce;
  } u;
} MCA_EXCEPTION, *PMCA_EXCEPTION;

#endif /* (NTDDI_VERSION >= NTDDI_WINXP) */

typedef MCA_EXCEPTION CMC_EXCEPTION, *PCMC_EXCEPTION;
typedef MCA_EXCEPTION CPE_EXCEPTION, *PCPE_EXCEPTION;

#if (NTDDI_VERSION >= NTDDI_WINXP)
#define MCA_EXCEPTION_V1_SIZE FIELD_OFFSET(MCA_EXCEPTION, ExtCnt)
#define MCA_EXCEPTION_V2_SIZE sizeof(struct _MCA_EXCEPTION)
#endif

#endif /* defined(_X86_) || defined(_AMD64_) */

#if defined(_AMD64_)

typedef UCHAR ERROR_SEVERITY, *PERROR_SEVERITY;

typedef enum _ERROR_SEVERITY_VALUE {
  ErrorRecoverable = 0,
  ErrorFatal = 1,
  ErrorCorrected = 2,
  ErrorOthers = 3,
} ERROR_SEVERITY_VALUE;

#endif

#endif /* defined(_X86_) || defined(_AMD64_) */
