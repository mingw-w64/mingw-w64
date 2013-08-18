/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINBASE_
#define _WINBASE_

#include <_mingw_unicode.h>

#include <apisetcconv.h>
#include <winapifamily.h>

#include <minwinbase.h>
#include <bemapiset.h>
#include <debugapi.h>
#include <errhandlingapi.h>
#include <fibersapi.h>
#include <fileapi.h>
#include <handleapi.h>
#include <heapapi.h>
#include <ioapiset.h>
#include <jobapi.h>
#include <interlockedapi.h>
#include <libloaderapi.h>
#include <memoryapi.h>
#include <namedpipeapi.h>
#include <namespaceapi.h>
#include <processenv.h>
#include <processthreadsapi.h>
#include <processtopologyapi.h>
#include <profileapi.h>
#include <realtimeapiset.h>
#include <securitybaseapi.h>
#include <securityappcontainer.h>
#include <synchapi.h>
#include <sysinfoapi.h>
#include <systemtopologyapi.h>
#include <threadpoolapiset.h>
#include <threadpoollegacyapiset.h>
#include <utilapiset.h>
#include <wow64apiset.h>

#define __INTRINSIC_GROUP_WINBASE /* only define the intrinsics in this file */
#include <psdk_inc/intrin-impl.h>

#ifdef __cplusplus
extern "C" {
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
#define DefineHandleTable(w) ( { (VOID)(w); TRUE; } )
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w) (w)
#define LockSegment(w) GlobalFix((HANDLE)(w))
#define UnlockSegment(w) GlobalUnfix((HANDLE)(w))

#define Yield()

#define FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2

#define TIME_ZONE_ID_INVALID ((DWORD)0xffffffff)

#define WAIT_FAILED ((DWORD)0xffffffff)
#define WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)
#define WAIT_ABANDONED ((STATUS_ABANDONED_WAIT_0) + 0)
#define WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0) + 0)
#define WAIT_IO_COMPLETION STATUS_USER_APC

#define SecureZeroMemory RtlSecureZeroMemory
#define CaptureStackBackTrace RtlCaptureStackBackTrace

#define FILE_FLAG_WRITE_THROUGH 0x80000000
#define FILE_FLAG_OVERLAPPED 0x40000000
#define FILE_FLAG_NO_BUFFERING 0x20000000
#define FILE_FLAG_RANDOM_ACCESS 0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN 0x8000000
#define FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#define FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#define FILE_FLAG_POSIX_SEMANTICS 0x1000000
#define FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#define FILE_FLAG_OPEN_NO_RECALL 0x100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000
#if _WIN32_WINNT >= 0x602
#define FILE_FLAG_OPEN_REQUIRING_OPLOCK 0x40000
#endif

#define PROGRESS_CONTINUE 0
#define PROGRESS_CANCEL 1
#define PROGRESS_STOP 2
#define PROGRESS_QUIET 3

#define CALLBACK_CHUNK_FINISHED 0x0
#define CALLBACK_STREAM_SWITCH 0x1

#define COPY_FILE_FAIL_IF_EXISTS 0x1
#define COPY_FILE_RESTARTABLE 0x2
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x4
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8
#if _WIN32_WINNT >= 0x0600
#define COPY_FILE_COPY_SYMLINK 0x0800
#define COPY_FILE_NO_BUFFERING 0x1000
#endif

#define REPLACEFILE_WRITE_THROUGH 0x1
#define REPLACEFILE_IGNORE_MERGE_ERRORS 0x2
#if _WIN32_WINNT >= 0x0600
#define REPLACEFILE_IGNORE_ACL_ERRORS 0x4
#endif

#define PIPE_ACCESS_INBOUND 0x1
#define PIPE_ACCESS_OUTBOUND 0x2
#define PIPE_ACCESS_DUPLEX 0x3

#define PIPE_CLIENT_END 0x0
#define PIPE_SERVER_END 0x1

#define PIPE_WAIT 0x0
#define PIPE_NOWAIT 0x1
#define PIPE_READMODE_BYTE 0x0
#define PIPE_READMODE_MESSAGE 0x2
#define PIPE_TYPE_BYTE 0x0
#define PIPE_TYPE_MESSAGE 0x4
#define PIPE_ACCEPT_REMOTE_CLIENTS 0x0
#define PIPE_REJECT_REMOTE_CLIENTS 0x8

#define PIPE_UNLIMITED_INSTANCES 255

#define SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#define SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#define SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#define SECURITY_DELEGATION (SecurityDelegation << 16)

#define SECURITY_CONTEXT_TRACKING 0x40000
#define SECURITY_EFFECTIVE_ONLY 0x80000

#define SECURITY_SQOS_PRESENT 0x100000
#define SECURITY_VALID_SQOS_FLAGS 0x1f0000

#if (_WIN32_WINNT >= 0x0600)
/* available in Vista SP1 and higher */ 
#define PROCESS_DEP_ENABLE 0x1
#define PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION 0x2
#endif

  typedef VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
  typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

#ifdef _X86_
  typedef PLDT_ENTRY LPLDT_ENTRY;
#else
  typedef LPVOID LPLDT_ENTRY;
#endif

#define FAIL_FAST_GENERATE_EXCEPTION_ADDRESS 0x1
#define FAIL_FAST_NO_HARD_ERROR_DLG 0x2

#define CRITICAL_SECTION_NO_DEBUG_INFO RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO

#define SP_SERIALCOMM ((DWORD)0x1)

#define PST_UNSPECIFIED ((DWORD)0x0)
#define PST_RS232 ((DWORD)0x1)
#define PST_PARALLELPORT ((DWORD)0x2)
#define PST_RS422 ((DWORD)0x3)
#define PST_RS423 ((DWORD)0x4)
#define PST_RS449 ((DWORD)0x5)
#define PST_MODEM ((DWORD)0x6)
#define PST_FAX ((DWORD)0x21)
#define PST_SCANNER ((DWORD)0x22)
#define PST_NETWORK_BRIDGE ((DWORD)0x100)
#define PST_LAT ((DWORD)0x101)
#define PST_TCPIP_TELNET ((DWORD)0x102)
#define PST_X25 ((DWORD)0x103)

#define PCF_DTRDSR ((DWORD)0x1)
#define PCF_RTSCTS ((DWORD)0x2)
#define PCF_RLSD ((DWORD)0x4)
#define PCF_PARITY_CHECK ((DWORD)0x8)
#define PCF_XONXOFF ((DWORD)0x10)
#define PCF_SETXCHAR ((DWORD)0x20)
#define PCF_TOTALTIMEOUTS ((DWORD)0x40)
#define PCF_INTTIMEOUTS ((DWORD)0x80)
#define PCF_SPECIALCHARS ((DWORD)0x100)
#define PCF_16BITMODE ((DWORD)0x200)

#define SP_PARITY ((DWORD)0x1)
#define SP_BAUD ((DWORD)0x2)
#define SP_DATABITS ((DWORD)0x4)
#define SP_STOPBITS ((DWORD)0x8)
#define SP_HANDSHAKING ((DWORD)0x10)
#define SP_PARITY_CHECK ((DWORD)0x20)
#define SP_RLSD ((DWORD)0x40)

#define BAUD_075 ((DWORD)0x1)
#define BAUD_110 ((DWORD)0x2)
#define BAUD_134_5 ((DWORD)0x4)
#define BAUD_150 ((DWORD)0x8)
#define BAUD_300 ((DWORD)0x10)
#define BAUD_600 ((DWORD)0x20)
#define BAUD_1200 ((DWORD)0x40)
#define BAUD_1800 ((DWORD)0x80)
#define BAUD_2400 ((DWORD)0x100)
#define BAUD_4800 ((DWORD)0x200)
#define BAUD_7200 ((DWORD)0x400)
#define BAUD_9600 ((DWORD)0x800)
#define BAUD_14400 ((DWORD)0x1000)
#define BAUD_19200 ((DWORD)0x2000)
#define BAUD_38400 ((DWORD)0x4000)
#define BAUD_56K ((DWORD)0x8000)
#define BAUD_128K ((DWORD)0x10000)
#define BAUD_115200 ((DWORD)0x20000)
#define BAUD_57600 ((DWORD)0x40000)
#define BAUD_USER ((DWORD)0x10000000)

#define DATABITS_5 ((WORD)0x1)
#define DATABITS_6 ((WORD)0x2)
#define DATABITS_7 ((WORD)0x4)
#define DATABITS_8 ((WORD)0x8)
#define DATABITS_16 ((WORD)0x10)
#define DATABITS_16X ((WORD)0x20)

#define STOPBITS_10 ((WORD)0x1)
#define STOPBITS_15 ((WORD)0x2)
#define STOPBITS_20 ((WORD)0x4)
#define PARITY_NONE ((WORD)0x100)
#define PARITY_ODD ((WORD)0x200)
#define PARITY_EVEN ((WORD)0x400)
#define PARITY_MARK ((WORD)0x800)
#define PARITY_SPACE ((WORD)0x1000)

  typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#define COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  typedef struct _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
  } COMSTAT,*LPCOMSTAT;

#define DTR_CONTROL_DISABLE 0x0
#define DTR_CONTROL_ENABLE 0x1
#define DTR_CONTROL_HANDSHAKE 0x2

#define RTS_CONTROL_DISABLE 0x0
#define RTS_CONTROL_ENABLE 0x1
#define RTS_CONTROL_HANDSHAKE 0x2
#define RTS_CONTROL_TOGGLE 0x3

  typedef struct _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD fOutX: 1;
    DWORD fInX: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    char XonChar;
    char XoffChar;
    char ErrorChar;
    char EofChar;
    char EvtChar;
    WORD wReserved1;
  } DCB,*LPDCB;

  typedef struct _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  typedef struct _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
  } COMMCONFIG,*LPCOMMCONFIG;

#define FreeModule(hLibModule) FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance) (lpProc)
#define FreeProcInstance(lpProc) (lpProc)

#define GMEM_FIXED 0x0
#define GMEM_MOVEABLE 0x2
#define GMEM_NOCOMPACT 0x10
#define GMEM_NODISCARD 0x20
#define GMEM_ZEROINIT 0x40
#define GMEM_MODIFY 0x80
#define GMEM_DISCARDABLE 0x100
#define GMEM_NOT_BANKED 0x1000
#define GMEM_SHARE 0x2000
#define GMEM_DDESHARE 0x2000
#define GMEM_NOTIFY 0x4000
#define GMEM_LOWER GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS 0x7F72
#define GMEM_INVALID_HANDLE 0x8000

#define GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#define GlobalLRUNewest(h) ((HANDLE)(h))
#define GlobalLRUOldest(h) ((HANDLE)(h))
#define GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#define GMEM_DISCARDED 0x4000
#define GMEM_LOCKCOUNT 0xff

  typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#define NUMA_NO_PREFERRED_NODE ((DWORD) -1)

#define DEBUG_PROCESS 0x1
#define DEBUG_ONLY_THIS_PROCESS 0x2
#define CREATE_SUSPENDED 0x4
#define DETACHED_PROCESS 0x8
#define CREATE_NEW_CONSOLE 0x10
#define NORMAL_PRIORITY_CLASS 0x20
#define IDLE_PRIORITY_CLASS 0x40
#define HIGH_PRIORITY_CLASS 0x80
#define REALTIME_PRIORITY_CLASS 0x100
#define CREATE_NEW_PROCESS_GROUP 0x200
#define CREATE_UNICODE_ENVIRONMENT 0x400
#define CREATE_SEPARATE_WOW_VDM 0x800
#define CREATE_SHARED_WOW_VDM 0x1000
#define CREATE_FORCEDOS 0x2000
#define BELOW_NORMAL_PRIORITY_CLASS 0x4000
#define ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#define INHERIT_PARENT_AFFINITY 0x10000
#define INHERIT_CALLER_PRIORITY 0x20000
#define CREATE_PROTECTED_PROCESS 0x40000
#define EXTENDED_STARTUPINFO_PRESENT 0x00080000
#define PROCESS_MODE_BACKGROUND_BEGIN 0x100000
#define PROCESS_MODE_BACKGROUND_END 0x200000
#define CREATE_BREAKAWAY_FROM_JOB 0x1000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL 0x2000000
#define CREATE_DEFAULT_ERROR_MODE 0x4000000
#define CREATE_NO_WINDOW 0x8000000
#define PROFILE_USER 0x10000000
#define PROFILE_KERNEL 0x20000000
#define PROFILE_SERVER 0x40000000
#define CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x10000

#define THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL 0
#define THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN (MAXLONG)

#define THREAD_MODE_BACKGROUND_BEGIN 0x00010000
#define THREAD_MODE_BACKGROUND_END 0x00020000

#define THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE

#define VOLUME_NAME_DOS 0x0
#define VOLUME_NAME_GUID 0x1
#define VOLUME_NAME_NT 0x2
#define VOLUME_NAME_NONE 0x4

#define FILE_NAME_NORMALIZED 0x0
#define FILE_NAME_OPENED 0x8
#endif /* $$$$ */

  typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
  typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#define DRIVE_UNKNOWN 0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE 2
#define DRIVE_FIXED 3
#define DRIVE_REMOTE 4
#define DRIVE_CDROM 5
#define DRIVE_RAMDISK 6

#define GetFreeSpace(w) (__MSABI_LONG(0x100000))
#define FILE_TYPE_UNKNOWN 0x0
#define FILE_TYPE_DISK 0x1
#define FILE_TYPE_CHAR 0x2
#define FILE_TYPE_PIPE 0x3
#define FILE_TYPE_REMOTE 0x8000

#define STD_INPUT_HANDLE ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define STD_ERROR_HANDLE ((DWORD)-12)

#define NOPARITY 0
#define ODDPARITY 1
#define EVENPARITY 2
#define MARKPARITY 3
#define SPACEPARITY 4

#define ONESTOPBIT 0
#define ONE5STOPBITS 1
#define TWOSTOPBITS 2

#define IGNORE 0
#define INFINITE 0xffffffff

#define CBR_110 110
#define CBR_300 300
#define CBR_600 600
#define CBR_1200 1200
#define CBR_2400 2400
#define CBR_4800 4800
#define CBR_9600 9600
#define CBR_14400 14400
#define CBR_19200 19200
#define CBR_38400 38400
#define CBR_56000 56000
#define CBR_57600 57600
#define CBR_115200 115200
#define CBR_128000 128000
#define CBR_256000 256000

#define CE_RXOVER 0x1
#define CE_OVERRUN 0x2
#define CE_RXPARITY 0x4
#define CE_FRAME 0x8
#define CE_BREAK 0x10
#define CE_TXFULL 0x100
#define CE_PTO 0x200
#define CE_IOE 0x400
#define CE_DNS 0x800
#define CE_OOP 0x1000
#define CE_MODE 0x8000

#define IE_BADID (-1)
#define IE_OPEN (-2)
#define IE_NOPEN (-3)
#define IE_MEMORY (-4)
#define IE_DEFAULT (-5)
#define IE_HARDWARE (-10)
#define IE_BYTESIZE (-11)
#define IE_BAUDRATE (-12)

#define EV_RXCHAR 0x1
#define EV_RXFLAG 0x2
#define EV_TXEMPTY 0x4
#define EV_CTS 0x8
#define EV_DSR 0x10
#define EV_RLSD 0x20
#define EV_BREAK 0x40
#define EV_ERR 0x80
#define EV_RING 0x100
#define EV_PERR 0x200
#define EV_RX80FULL 0x400
#define EV_EVENT1 0x800
#define EV_EVENT2 0x1000

#define SETXOFF 1
#define SETXON 2
#define SETRTS 3
#define CLRRTS 4
#define SETDTR 5
#define CLRDTR 6
#define RESETDEV 7
#define SETBREAK 8
#define CLRBREAK 9

#define PURGE_TXABORT 0x1
#define PURGE_RXABORT 0x2
#define PURGE_TXCLEAR 0x4
#define PURGE_RXCLEAR 0x8

#define LPTx 0x80

#define MS_CTS_ON ((DWORD)0x10)
#define MS_DSR_ON ((DWORD)0x20)
#define MS_RING_ON ((DWORD)0x40)
#define MS_RLSD_ON ((DWORD)0x80)

#define S_QUEUEEMPTY 0
#define S_THRESHOLD 1
#define S_ALLTHRESHOLD 2

#define S_NORMAL 0
#define S_LEGATO 1
#define S_STACCATO 2

#define S_PERIOD512 0
#define S_PERIOD1024 1
#define S_PERIOD2048 2
#define S_PERIODVOICE 3
#define S_WHITE512 4
#define S_WHITE1024 5
#define S_WHITE2048 6
#define S_WHITEVOICE 7

#define S_SERDVNA (-1)
#define S_SEROFM (-2)
#define S_SERMACT (-3)
#define S_SERQFUL (-4)
#define S_SERBDNT (-5)
#define S_SERDLN (-6)
#define S_SERDCC (-7)
#define S_SERDTP (-8)
#define S_SERDVL (-9)
#define S_SERDMD (-10)
#define S_SERDSH (-11)
#define S_SERDPT (-12)
#define S_SERDFQ (-13)
#define S_SERDDR (-14)
#define S_SERDSR (-15)
#define S_SERDST (-16)

#define NMPWAIT_WAIT_FOREVER 0xffffffff
#define NMPWAIT_NOWAIT 0x1
#define NMPWAIT_USE_DEFAULT_WAIT 0x0

#define FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#define FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#define OF_READ 0x0
#define OF_WRITE 0x1
#define OF_READWRITE 0x2
#define OF_SHARE_COMPAT 0x0
#define OF_SHARE_EXCLUSIVE 0x10
#define OF_SHARE_DENY_WRITE 0x20
#define OF_SHARE_DENY_READ 0x30
#define OF_SHARE_DENY_NONE 0x40
#define OF_PARSE 0x100
#define OF_DELETE 0x200
#define OF_VERIFY 0x400
#define OF_CANCEL 0x800
#define OF_CREATE 0x1000
#define OF_PROMPT 0x2000
#define OF_EXIST 0x4000
#define OF_REOPEN 0x8000

#define OFS_MAXPATHNAME 128
  typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#ifndef NOWINBASEINTERLOCK

#ifndef _NTOS_

#if defined(__ia64__) && !defined(RC_INVOKED)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire _InterlockedIncrement_acq
#define InterlockedIncrementRelease _InterlockedIncrement_rel
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire _InterlockedDecrement_acq
#define InterlockedDecrementRelease _InterlockedDecrement_rel
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#define InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#define InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG volatile *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG volatile *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG volatile *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG volatile *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG volatile *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG volatile *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG volatile *Target,LONGLONG Value);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG volatile *Target,LONGLONG Value);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG volatile *Addend,LONGLONG Value);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG volatile *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG volatile *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG volatile *lpAddend);
  LONG __cdecl InterlockedExchange(LONG volatile *Target,LONG Value);
  LONG __cdecl InterlockedExchangeAdd(LONG volatile *Addend,LONG Value);
  LONG __cdecl InterlockedCompareExchange(LONG volatile *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG volatile *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG volatile *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl InterlockedExchangePointer(PVOID volatile *Target,PVOID Value);
  PVOID __cdecl InterlockedCompareExchangePointer(PVOID volatile *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerAcquire(PVOID volatile *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerRelease(PVOID volatile *Destination,PVOID Exchange,PVOID Comperand);

#ifndef __CRT__NO_INLINE
#ifndef InterlockedAnd
#define InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG volatile *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    do {
      i = j;
      j = InterlockedCompareExchange(Target,i & Set,i);
    } while(i!=j);
    return j;
  }
#endif

#ifndef InterlockedOr
#define InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG volatile *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    do {
      i = j;
      j = InterlockedCompareExchange(Target,i | Set,i);
    } while(i!=j);
    return j;
  }
#endif

#ifndef InterlockedXor
#define InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG volatile *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    do {
      i = j;
      j = InterlockedCompareExchange(Target,i ^ Set,i);
    } while(i!=j);
    return j;
  }
#endif

#ifndef !defined (InterlockedAnd64)
#define InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    return Old;
  }
#endif

#ifndef InterlockedOr64
#define InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    return Old;
  }
#endif

#ifndef InterlockedXor64
#define InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);
    return Old;
  }
#endif

#ifndef InterlockedBitTestAndSet
#define InterlockedBitTestAndSet InterlockedBitTestAndSet_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndSet_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    return (BOOLEAN)((InterlockedOr(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit)!=0);
  }
#endif

#ifndef InterlockedBitTestAndReset
#define InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    return (BOOLEAN)((InterlockedAnd(&Base[Bit/(sizeof(*Base)*8)],~tBit)&tBit)!=0);
  }
#endif

#ifndef InterlockedBitTestAndComplement
#define InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    return (BOOLEAN)((InterlockedXor(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit)!=0);
  }
#endif
#endif /* !__CRT__NO_INLINE */

#elif defined(__x86_64) && !defined(RC_INVOKED)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedExchangePointer _InterlockedExchangePointer
#define InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#define InterlockedAnd64 _InterlockedAnd64
#define InterlockedOr64 _InterlockedOr64
#define InterlockedXor64 _InterlockedXor64
#define InterlockedIncrement64 _InterlockedIncrement64
#define InterlockedDecrement64 _InterlockedDecrement64
#define InterlockedExchange64 _InterlockedExchange64
#define InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#define InterlockedCompareExchange64 _InterlockedCompareExchange64
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  /* LONG  __cdecl _InterlockedIncrement(LONG volatile *Addend); moved to psdk_inc/intrin-impl.h */
  /* LONG  __cdecl _InterlockedDecrement(LONG volatile *Addend); moved to psdk_inc/intrin-impl.h */
  /* LONG  __cdecl _InterlockedExchange(LONG volatile *Target,LONG Value); moved to psdk_inc/intrin-impl.h */
  /* LONG  __cdecl _InterlockedExchangeAdd(LONG volatile *Addend,LONG Value); moved to psdk_inc/intrin-impl.h */
  /* LONG  __cdecl _InterlockedCompareExchange(LONG volatile *Destination,LONG ExChange,LONG Comperand); moved to psdk_inc/intrin-impl.h */
  /* PVOID  __cdecl _InterlockedCompareExchangePointer(PVOID volatile *Destination,PVOID Exchange,PVOID Comperand); moved to psdk_inc/intrin-impl.h */
  /* PVOID  __cdecl _InterlockedExchangePointer(PVOID volatile *Target,PVOID Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedAnd64(LONG64 volatile *Destination,LONG64 Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedOr64(LONG64 volatile *Destination,LONG64 Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedXor64(LONG64 volatile *Destination,LONG64 Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedIncrement64(LONG64 volatile *Addend); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedDecrement64(LONG64 volatile *Addend); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedExchange64(LONG64 volatile *Target,LONG64 Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedExchangeAdd64(LONG64 volatile *Addend,LONG64 Value); moved to psdk_inc/intrin-impl.h */
  /* LONG64  __cdecl _InterlockedCompareExchange64(LONG64 volatile *Destination,LONG64 ExChange,LONG64 Comperand); moved to psdk_inc/intrin-impl.h */

#else /* not ia64, nor x64.  */

#if defined(__MINGW_INTRIN_INLINE) && (defined(__GNUC__) && (__MINGW_GNUC_PREREQ(4, 9) || (__MINGW_GNUC_PREREQ(4, 8) && __GNUC_PATCHLEVEL__ >= 2)))

  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedIncrement(LONG volatile *lpAddend) {
      return _InterlockedIncrement(lpAddend);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedDecrement(LONG volatile *lpAddend) {
      return _InterlockedDecrement(lpAddend);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedExchange(LONG volatile *Target, LONG Value) {
      return _InterlockedExchange(Target, Value);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedExchangeAdd(LONG volatile *Addend, LONG Value) {
      return _InterlockedExchangeAdd(Addend, Value);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedCompareExchange(LONG volatile *Destination, LONG Exchange, LONG Comperand) {
      return _InterlockedCompareExchange(Destination, Exchange, Comperand);
  }
  __MINGW_INTRIN_INLINE LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG volatile *Destination, LONGLONG Exchange, LONGLONG Comperand) {
      return _InterlockedCompareExchange64(Destination, Exchange, Comperand);
  }

#endif

  LONGLONG __cdecl InterlockedAnd64 (LONGLONG volatile *Destination,LONGLONG Value);
  LONGLONG __cdecl InterlockedOr64 (LONGLONG volatile *Destination,LONGLONG Value);
  LONGLONG __cdecl InterlockedXor64 (LONGLONG volatile *Destination,LONGLONG Value);
  LONGLONG __cdecl InterlockedIncrement64(LONGLONG volatile *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG volatile *Addend);
  LONGLONG __cdecl InterlockedExchange64(LONGLONG volatile *Target,LONGLONG Value);
  LONGLONG __cdecl InterlockedExchangeAdd64(LONGLONG volatile *Addend,LONGLONG Value);

  FORCEINLINE LONGLONG InterlockedAnd64 (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    return Old;
  }

  FORCEINLINE LONGLONG InterlockedOr64 (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    return Old;
  }

  FORCEINLINE LONGLONG InterlockedXor64 (LONGLONG volatile *Destination,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Destination;
    } while(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);

    return Old;
  }

  FORCEINLINE LONGLONG InterlockedIncrement64(LONGLONG volatile *Addend) {
    LONGLONG Old;
    do {
      Old = *Addend;
    } while(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    return Old + 1;
  }

  FORCEINLINE LONGLONG InterlockedDecrement64(LONGLONG volatile *Addend) {
    LONGLONG Old;
    do {
      Old = *Addend;
    } while(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    return Old - 1;
  }

  FORCEINLINE LONGLONG InterlockedExchange64(LONGLONG volatile *Target,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Target;
    } while(InterlockedCompareExchange64(Target,Value,Old)!=Old);
    return Old;
  }

  FORCEINLINE LONGLONG InterlockedExchangeAdd64(LONGLONG volatile *Addend,LONGLONG Value) {
    LONGLONG Old;
    do {
      Old = *Addend;
    } while(InterlockedCompareExchange64(Addend,Old + Value,Old)!=Old);
    return Old;
  }

#if defined(__cplusplus)
  FORCEINLINE PVOID __cdecl
  __InlineInterlockedCompareExchangePointer(PVOID volatile *Destination,PVOID ExChange,PVOID Comperand) {
    return ((PVOID)(LONG_PTR)
	    InterlockedCompareExchange((LONG volatile *)(LONG_PTR)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#define InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#else
#define InterlockedCompareExchangePointer(Destination,ExChange,Comperand)	\
	   (PVOID)(LONG_PTR)							\
	    InterlockedCompareExchange((LONG volatile *)(LONG_PTR)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#endif /* __cplusplus */

#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedDecrementAcquire InterlockedDecrement
#define InterlockedDecrementRelease InterlockedDecrement
#define InterlockedIncrementAcquire InterlockedIncrement
#define InterlockedIncrementRelease InterlockedIncrement
#define InterlockedCompareExchangeAcquire InterlockedCompareExchange
#define InterlockedCompareExchangeRelease InterlockedCompareExchange
#define InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#define InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#define InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#define InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#endif /* end of _X86_ interlocked api */

#endif /* ! _NTOS_ */
#endif /* ! NOWINBASEINTERLOCK */

#define UnlockResource(hResData) ( { (VOID)(hResData); 0; } )
#define MAXINTATOM 0xC000
#define MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#define INVALID_ATOM ((ATOM)0)

  int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd);
  int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd);
/* Unicode entry point is wWinMain, WinMain is just the ANSI version.  */

  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,SIZE_T dwBytes);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,SIZE_T dwBytes,UINT uFlags);
  WINBASEAPI SIZE_T WINAPI GlobalSize(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,SIZE_T uBytes);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,SIZE_T uBytes,UINT uFlags);
  WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalSize(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL hMem,UINT cbNewSize);
  WINBASEAPI SIZE_T WINAPI LocalCompact(UINT uMinFree);

#define SCS_32BIT_BINARY 0
#define SCS_DOS_BINARY 1
#define SCS_WOW_BINARY 2
#define SCS_PIF_BINARY 3
#define SCS_POSIX_BINARY 4
#define SCS_OS216_BINARY 5
#define SCS_64BIT_BINARY 6

#define GetBinaryType __MINGW_NAME_AW(GetBinaryType)

#ifdef _WIN64
#define SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#else
#define SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#endif

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  WINBASEAPI WINBOOL WINAPI GetBinaryTypeA(LPCSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI WINBOOL WINAPI GetBinaryTypeW(LPCWSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath,LPSTR lpszShortPath,DWORD cchBuffer);
#ifndef UNICODE
#define GetShortPathName GetShortPathNameA
#endif
  WINBASEAPI WINBOOL WINAPI GetProcessAffinityMask(HANDLE hProcess,PDWORD_PTR lpProcessAffinityMask,PDWORD_PTR lpSystemAffinityMask);
  WINBASEAPI WINBOOL WINAPI SetProcessAffinityMask(HANDLE hProcess,DWORD_PTR dwProcessAffinityMask);
#endif

  /* available in XP SP3, Vista SP1 and higher */ 
  WINBASEAPI WINBOOL WINAPI GetProcessDEPPolicy (HANDLE hProcess,LPDWORD lpFlags,PBOOL lpPermanent);
  WINBASEAPI WINBOOL WINAPI SetProcessDEPPolicy (DWORD dwFlags);

  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize);
  WINBASEAPI VOID WINAPI FatalExit(int ExitCode);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsA (LPCH NewEnvironment);
#ifndef UNICODE
#define SetEnvironmentStrings SetEnvironmentStringsA
#endif

#define FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T dwStackSize,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T dwStackCommitSize,SIZE_T dwStackReserveSize,DWORD dwFlags,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ConvertFiberToThread(VOID);
  WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID lpFiber);
  WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE hThread,DWORD_PTR dwThreadAffinityMask);
  WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess,PBOOL pDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI WINBOOL WINAPI GetThreadSelectorEntry(HANDLE hThread,DWORD dwSelector,LPLDT_ENTRY lpSelectorEntry);
  WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE esFlags);

#define HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal)!=STATUS_PENDING)

#define SEM_FAILCRITICALERRORS 0x1
#define SEM_NOGPFAULTERRORBOX 0x2
#define SEM_NOALIGNMENTFAULTEXCEPT 0x4
#define SEM_NOOPENFILEERRORBOX 0x8000

  typedef VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI WINBOOL WINAPI DebugSetProcessKillOnExit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD nCount,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI InitAtomTable(DWORD nSize);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI SetHandleCount(UINT uNumber);
  WINBASEAPI WINBOOL WINAPI LockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh);

#define SetFileShortName __MINGW_NAME_AW(SetFileShortName)

  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI SetMessageWaitingIndicator(HANDLE hMsgIndicator,ULONG ulMsgCount);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameA(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameW(HANDLE hFile,LPCWSTR lpShortName);

#define HANDLE_FLAG_INHERIT 0x1
#define HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#define HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI LoadModule(LPCSTR lpModuleName,LPVOID lpParameterBlock);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lpCmdLine,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetCommMask(HANDLE hFile,LPDWORD lpEvtMask);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI GetCommModemStatus(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI SetCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI SetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
  WINBASEAPI WINBOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,char cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE hDevice,DWORD dwPositionMethod,DWORD dwPartition,DWORD dwOffsetLow,DWORD dwOffsetHigh,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdwOffsetLow,LPDWORD lpdwOffsetHigh);
  WINBASEAPI DWORD WINAPI PrepareTape(HANDLE hDevice,DWORD dwOperation,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI EraseTape(HANDLE hDevice,DWORD dwEraseType,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE hDevice,DWORD dwPartitionMethod,DWORD dwCount,DWORD dwSize);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dwTapemarkCount,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdwSize,LPVOID lpTapeInformation);

#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPVOID lpTapeInformation);

#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI int WINAPI MulDiv(int nNumber,int nNumerator,int nDenominator);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdwQuotaUsed);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);

  typedef struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#define FormatMessage __MINGW_NAME_AW(FormatMessage)

  WINBASEAPI WINBOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
  WINBASEAPI WINBOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
  WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
  WINBASEAPI WINBOOL WINAPI DosDateTimeToFileTime(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment,WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI DWORD WINAPI FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPSTR lpBuffer,DWORD nSize,va_list *Arguments);
  WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,DWORD nSize,va_list *Arguments);

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
#ifndef __cplusplus
#define GetCurrentTime() GetTickCount()
#else
  DWORD FORCEINLINE GetCurrentTime(void) {
    return GetTickCount();
  }
#endif
#endif

#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x100
#define FORMAT_MESSAGE_IGNORE_INSERTS 0x200
#define FORMAT_MESSAGE_FROM_STRING 0x400
#define FORMAT_MESSAGE_FROM_HMODULE 0x800
#define FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK 0xff

#define CreateMailslot __MINGW_NAME_AW(CreateMailslot)
#define EncryptFile __MINGW_NAME_AW(EncryptFile)
#define DecryptFile __MINGW_NAME_AW(DecryptFile)
#define FileEncryptionStatus __MINGW_NAME_AW(FileEncryptionStatus)

  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lpOutBufferSize,LPDWORD lpInBufferSize,LPDWORD lpMaxInstances);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lpMaxMessageSize,LPDWORD lpNextSize,LPDWORD lpMessageCount,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI SetMailslotInfo(HANDLE hMailslot,DWORD lReadTimeout);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#define FILE_ENCRYPTABLE 0
#define FILE_IS_ENCRYPTED 1
#define FILE_SYSTEM_ATTR 2
#define FILE_ROOT_DIR 3
#define FILE_SYSTEM_DIR 4
#define FILE_UNKNOWN 5
#define FILE_SYSTEM_NOT_SUPPORT 6
#define FILE_USER_DISALLOWED 7
#define FILE_READ_ONLY 8
#define FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI FileEncryptionStatusA(LPCSTR lpFileName,LPDWORD lpStatus);
  WINADVAPI WINBOOL WINAPI FileEncryptionStatusW(LPCWSTR lpFileName,LPDWORD lpStatus);

#define EFS_USE_RECOVERY_KEYS (0x1)

  typedef DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,ULONG ulLength);
  typedef DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,PULONG ulLength);

#define CREATE_FOR_IMPORT (1)
#define CREATE_FOR_DIR (2)
#define OVERWRITE_HIDDEN (4)

#define OpenEncryptedFileRaw __MINGW_NAME_AW(OpenEncryptedFileRaw)
#define lstrcmp __MINGW_NAME_AW(lstrcmp)
#define lstrcmpi __MINGW_NAME_AW(lstrcmpi)
#define lstrcpyn __MINGW_NAME_AW(lstrcpyn)
#define lstrcpy __MINGW_NAME_AW(lstrcpy)
#define lstrcat __MINGW_NAME_AW(lstrcat)
#define lstrlen __MINGW_NAME_AW(lstrlen)

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI int WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI int WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI int WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI int WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,int iMaxLength);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,int iMaxLength);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI int WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI int WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lpPathName,int iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lpPathName,int iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lpBuffer,UINT uBytes);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lpBuffer,UINT uBytes);
  WINBASEAPI __LONG32 WINAPI _hread(HFILE hFile,LPVOID lpBuffer,__LONG32 lBytes);
  WINBASEAPI __LONG32 WINAPI _hwrite(HFILE hFile,LPCCH lpBuffer,__LONG32 lBytes);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG lOffset,int iOrigin);
  WINADVAPI WINBOOL WINAPI IsTextUnicode(CONST VOID *lpv,int iSize,LPINT lpiResult);

  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dwLowBytesToSeek,DWORD dwHighBytesToSeek,LPDWORD lpdwLowByteSeeked,LPDWORD lpdwHighByteSeeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  typedef struct _WIN32_STREAM_ID {
    DWORD dwStreamId;
    DWORD dwStreamAttributes;
    LARGE_INTEGER Size;
    DWORD dwStreamNameSize;
    WCHAR cStreamName[ANYSIZE_ARRAY];
  } WIN32_STREAM_ID,*LPWIN32_STREAM_ID;

#define BACKUP_INVALID 0x0
#define BACKUP_DATA 0x1
#define BACKUP_EA_DATA 0x2
#define BACKUP_SECURITY_DATA 0x3
#define BACKUP_ALTERNATE_DATA 0x4
#define BACKUP_LINK 0x5
#define BACKUP_PROPERTY_DATA 0x6
#define BACKUP_OBJECT_ID 0x7
#define BACKUP_REPARSE_DATA 0x8
#define BACKUP_SPARSE_BLOCK 0x9

#define STREAM_NORMAL_ATTRIBUTE 0x0
#define STREAM_MODIFIED_WHEN_READ 0x1
#define STREAM_CONTAINS_SECURITY 0x2
#define STREAM_CONTAINS_PROPERTIES 0x4
#define STREAM_SPARSE_ATTRIBUTE 0x8

#define STARTF_USESHOWWINDOW 0x1
#define STARTF_USESIZE 0x2
#define STARTF_USEPOSITION 0x4
#define STARTF_USECOUNTCHARS 0x8
#define STARTF_USEFILLATTRIBUTE 0x10
#define STARTF_RUNFULLSCREEN 0x20
#define STARTF_FORCEONFEEDBACK 0x40
#define STARTF_FORCEOFFFEEDBACK 0x80
#define STARTF_USESTDHANDLES 0x100

#define STARTF_USEHOTKEY 0x200

#define SHUTDOWN_NORETRY 0x1

#define OpenEvent __MINGW_NAME_AW(OpenEvent)
#define CreateSemaphore __MINGW_NAME_AW(CreateSemaphore)

  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
#ifndef UNICODE
#define OpenMutex OpenMutexA
#endif
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
#ifndef UNICODE
#define OpenSemaphore OpenSemaphoreA
#endif

#define CreateWaitableTimer __MINGW_NAME_AW(CreateWaitableTimer)
#define LoadLibrary __MINGW_NAME_AW(LoadLibrary)

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
#define GetModuleHandle __MINGW_NAME_AW(GetModuleHandle)
#endif


  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
#ifndef UNICODE
#define OpenWaitableTimer OpenWaitableTimerA
#endif
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCSTR lpName);
#ifndef UNICODE
#define CreateFileMapping CreateFileMappingA
#endif

  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
#ifndef UNICODE
#define OpenFileMapping OpenFileMappingA
#endif

  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD nBufferLength,LPSTR lpBuffer);
#ifndef UNICODE
#define GetLogicalDriveStrings GetLogicalDriveStringsA
#endif

  WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#define FatalAppExit __MINGW_NAME_AW(FatalAppExit)
#define ExpandEnvironmentStrings __MINGW_NAME_AW(ExpandEnvironmentStrings)
#define GetFirmwareEnvironmentVariable __MINGW_NAME_AW(GetFirmwareEnvironmentVariable)
#define SetFirmwareEnvironmentVariable __MINGW_NAME_AW(SetFirmwareEnvironmentVariable)
#define FindResource __MINGW_NAME_AW(FindResource)

  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameA(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameW(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lpMessageText);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lpMessageText);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
#ifndef UNICODE
#define GetStartupInfo GetStartupInfoA
#endif
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
#ifndef UNICODE
#define FindResourceEx FindResourceExA
#endif

  /* available in XP SP3, Vista SP1 and higher */ 
  typedef enum _DEP_SYSTEM_POLICY_TYPE {
    AlwaysOff = 0,
    AlwaysOn = 1,
    OptIn = 2,
    OptOut = 3
  } DEP_SYSTEM_POLICY_TYPE;
  WINBASEAPI DEP_SYSTEM_POLICY_TYPE WINAPI GetSystemDEPPolicy (void);

#define EnumResourceTypes __MINGW_NAME_AW(EnumResourceTypes)
#define EnumResourceNames __MINGW_NAME_AW(EnumResourceNames)
#define BeginUpdateResource __MINGW_NAME_AW(BeginUpdateResource)
#define UpdateResource __MINGW_NAME_AW(UpdateResource)
#define EndUpdateResource __MINGW_NAME_AW(EndUpdateResource)
#define GlobalAddAtom __MINGW_NAME_AW(GlobalAddAtom)
#define GlobalFindAtom __MINGW_NAME_AW(GlobalFindAtom)
#define GlobalGetAtomName __MINGW_NAME_AW(GlobalGetAtomName)
#define AddAtom __MINGW_NAME_AW(AddAtom)
#define FindAtom __MINGW_NAME_AW(FindAtom)
#define GetAtomName __MINGW_NAME_AW(GetAtomName)
#define GetProfileInt __MINGW_NAME_AW(GetProfileInt)
#define GetProfileString __MINGW_NAME_AW(GetProfileString)
#define WriteProfileString __MINGW_NAME_AW(WriteProfileString)
#define GetProfileSection __MINGW_NAME_AW(GetProfileSection)
#define WriteProfileSection __MINGW_NAME_AW(WriteProfileSection)
#define GetPrivateProfileInt __MINGW_NAME_AW(GetPrivateProfileInt)
#define GetPrivateProfileString __MINGW_NAME_AW(GetPrivateProfileString)
#define WritePrivateProfileString __MINGW_NAME_AW(WritePrivateProfileString)
#define GetPrivateProfileSection __MINGW_NAME_AW(GetPrivateProfileSection)
#define WritePrivateProfileSection __MINGW_NAME_AW(WritePrivateProfileSection)
#define GetPrivateProfileSectionNames __MINGW_NAME_AW(GetPrivateProfileSectionNames)
#define GetPrivateProfileStruct __MINGW_NAME_AW(GetPrivateProfileStruct)
#define WritePrivateProfileStruct __MINGW_NAME_AW(WritePrivateProfileStruct)
#define AddLocalAlternateComputerName __MINGW_NAME_AW(AddLocalAlternateComputerName)

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesA(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesW(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceA(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceW(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lpBuffer,int nSize);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,int nSize);
  WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lpBuffer,int nSize);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,int nSize);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI DWORD WINAPI GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lpTempFileName);
#ifndef UNICODE
#define GetTempPath GetTempPathA
#define GetTempFileName GetTempFileNameA
#endif

#ifndef RC_INVOKED
#define GetSystemWow64Directory __MINGW_NAME_AW(GetSystemWow64Directory)

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);

  typedef UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lpBuffer,UINT uSize);
  typedef UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lpBuffer,UINT uSize);

#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A __MINGW_NAME_UAW_EXT(GET_SYSTEM_WOW64_DIRECTORY_NAME,A)
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W __MINGW_NAME_UAW_EXT(GET_SYSTEM_WOW64_DIRECTORY_NAME,W)
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T __MINGW_NAME_UAW_EXT(GET_SYSTEM_WOW64_DIRECTORY_NAME,T)

#endif

#define GetCurrentDirectory __MINGW_NAME_AW(GetCurrentDirectory)
#define SetDllDirectory __MINGW_NAME_AW(SetDllDirectory)
#define GetDllDirectory __MINGW_NAME_AW(GetDllDirectory)
#define CreateDirectoryEx __MINGW_NAME_AW(CreateDirectoryEx)
#define CreateFile __MINGW_NAME_AW(CreateFile)

  WINBASEAPI WINBOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);

#define BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE  0x00000001
#define BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE 0x00010000
#define BASE_SEARCH_PATH_PERMANENT               0x00008000
  WINBASEAPI WINBOOL WINAPI SetSearchPathMode(DWORD dwFlags);

#define DDD_RAW_TARGET_PATH 0x1
#define DDD_REMOVE_DEFINITION 0x2
#define DDD_EXACT_MATCH_ON_REMOVE 0x4
#define DDD_NO_BROADCAST_SYSTEM 0x8
#define DDD_LUID_BROADCAST_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lpTargetPath);
#ifndef UNICODE
#define DefineDosDevice DefineDosDeviceA
#endif
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lpTargetPath,DWORD ucchMax);
#ifndef UNICODE
#define QueryDosDevice QueryDosDeviceA
#endif

#define EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dwShareMode,DWORD dwFlagsAndAttributes);

#define GetCompressedFileSize __MINGW_NAME_AW(GetCompressedFileSize)
#define CheckNameLegalDOS8Dot3 __MINGW_NAME_AW(CheckNameLegalDOS8Dot3)

  WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);

#define CopyFile __MINGW_NAME_AW(CopyFile)
#define CopyFileEx __MINGW_NAME_AW(CopyFileEx)
#define MoveFile __MINGW_NAME_AW(MoveFile)
#define MoveFileEx __MINGW_NAME_AW(MoveFileEx)
#define MoveFileWithProgress __MINGW_NAME_AW(MoveFileWithProgress)
#define ReplaceFile __MINGW_NAME_AW(ReplaceFile)
#define CreateHardLink __MINGW_NAME_AW(CreateHardLink)
#define GetNamedPipeHandleState __MINGW_NAME_AW(GetNamedPipeHandleState)
#define CallNamedPipe __MINGW_NAME_AW(CallNamedPipe)
#define SetVolumeLabel __MINGW_NAME_AW(SetVolumeLabel)
#define ClearEventLog __MINGW_NAME_AW(ClearEventLog)
#define BackupEventLog __MINGW_NAME_AW(BackupEventLog)
#define OpenEventLog __MINGW_NAME_AW(OpenEventLog)
#define RegisterEventSource __MINGW_NAME_AW(RegisterEventSource)
#define OpenBackupEventLog __MINGW_NAME_AW(OpenBackupEventLog)
#define ReadEventLog __MINGW_NAME_AW(ReadEventLog)
#define ReportEvent __MINGW_NAME_AW(ReportEvent)
#define IsBadStringPtr __MINGW_NAME_AW(IsBadStringPtr)
#define LookupAccountSid __MINGW_NAME_AW(LookupAccountSid)
#define LookupAccountName __MINGW_NAME_AW(LookupAccountName)
#define LookupPrivilegeValue __MINGW_NAME_AW(LookupPrivilegeValue)
#define LookupPrivilegeName __MINGW_NAME_AW(LookupPrivilegeName)
#define LookupPrivilegeDisplayName __MINGW_NAME_AW(LookupPrivilegeDisplayName)
#define BuildCommDCB __MINGW_NAME_AW(BuildCommDCB)
#define BuildCommDCBAndTimeouts __MINGW_NAME_AW(BuildCommDCBAndTimeouts)
#define CommConfigDialog __MINGW_NAME_AW(CommConfigDialog)
#define GetDefaultCommConfig __MINGW_NAME_AW(GetDefaultCommConfig)
#define SetDefaultCommConfig __MINGW_NAME_AW(SetDefaultCommConfig)
#define GetComputerName __MINGW_NAME_AW(GetComputerName)
#define SetComputerName __MINGW_NAME_AW(SetComputerName)
#define DnsHostnameToComputerName __MINGW_NAME_AW(DnsHostnameToComputerName)
#define GetUserName __MINGW_NAME_AW(GetUserName)

  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  typedef DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER TotalFileSize,LARGE_INTEGER TotalBytesTransferred,LARGE_INTEGER StreamSize,LARGE_INTEGER StreamBytesTransferred,DWORD dwStreamNumber,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,LPVOID lpData);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);

#define MOVEFILE_REPLACE_EXISTING 0x1
#define MOVEFILE_COPY_ALLOWED 0x2
#define MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#define MOVEFILE_WRITE_THROUGH 0x8
#define MOVEFILE_CREATE_HARDLINK 0x10
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);

  typedef enum _STREAM_INFO_LEVELS {
    FindStreamInfoStandard,FindStreamInfoMaxInfoLevel
  } STREAM_INFO_LEVELS;

  typedef struct _WIN32_FIND_STREAM_DATA {
    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[MAX_PATH + 36];
  } WIN32_FIND_STREAM_DATA,*PWIN32_FIND_STREAM_DATA;

  HANDLE WINAPI FindFirstStreamW(LPCWSTR lpFileName,STREAM_INFO_LEVELS InfoLevel,LPVOID lpFindStreamData,DWORD dwFlags);
  WINBOOL WINAPI FindNextStreamW(HANDLE hFindStream,LPVOID lpFindStreamData);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
#ifndef UNICODE
#define CreateNamedPipe CreateNamedPipeA
#endif
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPWSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD nTimeOut);
#ifndef UNICODE
#define WaitNamedPipe WaitNamedPipeA
#endif
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelA(LPCSTR lpRootPathName,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelW(LPCWSTR lpRootPathName,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID);
  WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName,LPSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
#ifndef UNICODE
#define GetVolumeInformation GetVolumeInformationA
#endif
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI DeregisterEventSource(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI GetNumberOfEventLogRecords(HANDLE hEventLog,PDWORD NumberOfRecords);
  WINADVAPI WINBOOL WINAPI GetOldestEventLogRecord(HANDLE hEventLog,PDWORD OldestRecord);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCSTR *lpStrings,LPVOID lpRawData);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCWSTR *lpStrings,LPVOID lpRawData);

#define EVENTLOG_FULL_INFO 0

  typedef struct _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
  } EVENTLOG_FULL_INFORMATION,*LPEVENTLOG_FULL_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lpBuffer,DWORD cbBufSize,LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
#ifndef UNICODE
#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
#ifndef UNICODE
#define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
#ifndef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
#endif
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
#ifndef UNICODE
#define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
#endif

  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
#ifndef UNICODE
#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
#ifndef UNICODE
#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
#ifndef UNICODE
#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
#ifndef UNICODE
#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#endif

  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
#ifndef UNICODE
#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#endif

  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferSize);
  WINADVAPI WINBOOL WINAPI SetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
#ifndef UNICODE
#define SetFileSecurity SetFileSecurityA
#endif

  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
#ifndef UNICODE
#define GetFileSecurity GetFileSecurityA
#endif

  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lpBuffer,DWORD nBufferLength,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadCodePtr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueW(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameA(LPCSTR lpSystemName,PLUID lpLuid,LPSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameW(LPCWSTR lpSystemName,PLUID lpLuid,LPWSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR lpSystemName,LPCSTR lpName,LPSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName,LPCWSTR lpName,LPWSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBA(LPCSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBW(LPCWSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogA(LPCSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogW(LPCWSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);

#define MAX_COMPUTERNAME_LENGTH 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetComputerNameA(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI SetComputerNameW(LPCWSTR lpComputerName);

  WINBASEAPI WINBOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPCSTR lpBuffer);
#ifndef UNICODE
#define SetComputerNameEx SetComputerNameExA
#endif

  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameA(LPCSTR Hostname,LPSTR ComputerName,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD nSize);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lpBuffer,LPDWORD pcbBuffer);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lpBuffer,LPDWORD pcbBuffer);

#define LOGON32_LOGON_INTERACTIVE 2
#define LOGON32_LOGON_NETWORK 3
#define LOGON32_LOGON_BATCH 4
#define LOGON32_LOGON_SERVICE 5
#define LOGON32_LOGON_UNLOCK 7
#define LOGON32_LOGON_NETWORK_CLEARTEXT 8
#define LOGON32_LOGON_NEW_CREDENTIALS 9

#define LOGON32_PROVIDER_DEFAULT 0
#define LOGON32_PROVIDER_WINNT35 1
#define LOGON32_PROVIDER_WINNT40 2
#define LOGON32_PROVIDER_WINNT50 3

#define LogonUser __MINGW_NAME_AW(LogonUser)
#define LogonUserEx __MINGW_NAME_AW(LogonUserEx)

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
#ifndef UNICODE
#define CreateProcessAsUser CreateProcessAsUserA
#endif

#define LOGON_WITH_PROFILE 0x00000001
#define LOGON_NETCREDENTIALS_ONLY 0x00000002
#define LOGON_ZERO_PASSWORD_BUFFER 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);

  typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI RegisterWaitForSingleObject(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);

#define HW_PROFILE_GUIDLEN 39
#define MAX_PROFILE_LEN 80

#define DOCKINFO_UNDOCKED (0x1)
#define DOCKINFO_DOCKED (0x2)
#define DOCKINFO_USER_SUPPLIED (0x4)
#define DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  typedef struct tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  typedef struct tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

  __MINGW_TYPEDEF_AW(HW_PROFILE_INFO)
  __MINGW_TYPEDEF_AW(LPHW_PROFILE_INFO)

#define GetCurrentHwProfile __MINGW_NAME_AW(GetCurrentHwProfile)
#define VerifyVersionInfo __MINGW_NAME_AW(VerifyVersionInfo)

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);

#include <winerror.h>

#define TC_NORMAL 0
#define TC_HARDERR 1
#define TC_GP_TRAP 2
#define TC_SIGNAL 3

#define AC_LINE_OFFLINE 0x0
#define AC_LINE_ONLINE 0x1
#define AC_LINE_BACKUP_POWER 0x2
#define AC_LINE_UNKNOWN 0xff

#define BATTERY_FLAG_HIGH 0x1
#define BATTERY_FLAG_LOW 0x2
#define BATTERY_FLAG_CRITICAL 0x4
#define BATTERY_FLAG_CHARGING 0x8
#define BATTERY_FLAG_NO_BATTERY 0x80
#define BATTERY_FLAG_UNKNOWN 0xff

#define BATTERY_PERCENTAGE_UNKNOWN 0xff

#define BATTERY_LIFE_UNKNOWN 0xffffffff

  typedef struct _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
  } SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;

#define CreateJobObject __MINGW_NAME_AW(CreateJobObject)
#define OpenJobObject __MINGW_NAME_AW(OpenJobObject)
#define FindFirstVolumeMountPoint __MINGW_NAME_AW(FindFirstVolumeMountPoint)
#define FindNextVolumeMountPoint __MINGW_NAME_AW(FindNextVolumeMountPoint)
#define SetVolumeMountPoint __MINGW_NAME_AW(SetVolumeMountPoint)

  WINBOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus);
  WINBOOL WINAPI SetSystemPowerState(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI AssignProcessToJobObject(HANDLE hJob,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength,LPDWORD lpReturnLength);
  WINBASEAPI WINBOOL WINAPI SetInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength);
  WINBASEAPI WINBOOL WINAPI CreateJobSet(ULONG NumJob,PJOB_SET_ARRAY UserJobSet,ULONG Flags);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cchBufferLength);
#ifndef UNICODE
#define FindFirstVolume FindFirstVolumeA
#endif
  WINBASEAPI WINBOOL WINAPI FindNextVolumeA(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cchBufferLength);
#ifndef UNICODE
#define FindNextVolume FindNextVolumeA
#endif
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpszRootPathName,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpszRootPathName,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointA(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointW(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
#ifndef UNICODE
#define DeleteVolumeMountPoint DeleteVolumeMountPointA
#endif
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameA(LPCSTR lpszFileName,LPSTR lpszVolumePathName,DWORD cchBufferLength);
#ifndef UNICODE
#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#define GetVolumePathName GetVolumePathNameA
#define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#endif
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,LPCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);

#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#define ACTCTX_FLAG_LANGID_VALID 0x2
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#define ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT 0x10
#define ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#define ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 0x40
#define ACTCTX_FLAG_HMODULE_VALID 0x80

  typedef struct tagACTCTXA {
    ULONG cbSize;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  typedef struct tagACTCTXW {
    ULONG cbSize;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  typedef const ACTCTXA *PCACTCTXA;
  typedef const ACTCTXW *PCACTCTXW;

  __MINGW_TYPEDEF_AW(ACTCTX)
  __MINGW_TYPEDEF_AW(PACTCTX)
  __MINGW_TYPEDEF_AW(PCACTCTX)

#define CreateActCtx __MINGW_NAME_AW(CreateActCtx)

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
  } ACTCTX_SECTION_KEYED_DATA_2600,*PACTCTX_SECTION_KEYED_DATA_2600;

  typedef const ACTCTX_SECTION_KEYED_DATA_2600 *PCACTCTX_SECTION_KEYED_DATA_2600;

  typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
  } ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  typedef struct tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_DATA,*PACTCTX_SECTION_KEYED_DATA;

  typedef const ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;

#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX 0x1
#define FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS 0x2
#define FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA 0x4

#define FindActCtxSectionString __MINGW_NAME_AW(FindActCtxSectionString)

  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,const GUID *lpExtensionGuid,ULONG ulSectionId,const GUID *lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);

#ifndef RC_INVOKED
#ifndef ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  typedef const struct _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#define ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#endif
#endif

#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 0x4
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 0x10
#define QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  typedef WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId();
  WINBASEAPI WINBOOL WINAPI GetNumaProcessorNode(UCHAR Processor,PUCHAR NodeNumber);
  WINBASEAPI WINBOOL WINAPI GetNumaNodeProcessorMask(UCHAR Node,PULONGLONG ProcessorMask);
  WINBASEAPI WINBOOL WINAPI GetNumaAvailableMemoryNode(UCHAR Node,PULONGLONG AvailableBytes);

  /* New Windows Vista API.  */
#if (_WIN32_WINNT >= 0x0600)
#define SYMBOLIC_LINK_FLAG_FILE		0x0
#define SYMBOLIC_LINK_FLAG_DIRECTORY	0x1

#define CreateSymbolicLink __MINGW_NAME_AW(CreateSymbolicLink)
#define OpenPrivateNamespace __MINGW_NAME_AW(OpenPrivateNamespace)
#define CopyFileTransacted __MINGW_NAME_AW(CopyFileTransacted)
#define CreateDirectoryTransacted __MINGW_NAME_AW(CreateDirectoryTransacted)
#define CreateEventEx __MINGW_NAME_AW(CreateEventEx)
#define CreateFileTransacted __MINGW_NAME_AW(CreateFileTransacted)
#define CreateHardLinkTransacted __MINGW_NAME_AW(CreateHardLinkTransacted)
#define DeleteFileTransacted __MINGW_NAME_AW(DeleteFileTransacted)
#define CreateSymbolicLinkTransacted __MINGW_NAME_AW(CreateSymbolicLinkTransacted)
#define FindFirstFileTransacted __MINGW_NAME_AW(FindFirstFileTransacted)

WINBASEAPI BOOLEAN WINAPI CreateSymbolicLinkA (LPSTR lpSymLinkFileName, LPSTR lpTargetFileName, DWORD dwFlags);
WINBASEAPI BOOLEAN WINAPI CreateSymbolicLinkW (LPWSTR lpSymLinkFileName, LPWSTR lpTargetFileName, DWORD dwFlags);

WINBASEAPI HANDLE WINAPI CreateBoundaryDescriptorA(LPCSTR Name,ULONG Flags);
#ifndef UNICODE
#define CreateBoundaryDescriptor CreateBoundaryDescriptorA
#endif

WINBASEAPI HANDLE WINAPI OpenPrivateNamespaceA(LPVOID lpBoundaryDescriptor,LPCSTR lpAliasPrefix);
WINBASEAPI HANDLE WINAPI OpenPrivateNamespaceW(LPVOID lpBoundaryDescriptor,LPCWSTR lpAliasPrefix);
WINBASEAPI HANDLE WINAPI CreatePrivateNamespaceA(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,LPVOID lpBoundaryDescriptor,LPCSTR lpAliasPrefix);
#ifndef UNICODE
#define CreatePrivateNamespace CreatePrivateNamespaceA
#endif

typedef BOOLEAN CALLBACK (*PSECURE_MEMORY_CACHE_CALLBACK) (PVOID Addr,SIZE_T Range);

WINBASEAPI WINBOOL WINAPI AddSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack);
WINBASEAPI WINBOOL WINAPI RemoveSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack);

WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPagesNuma(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray,DWORD nndPreferred);

typedef DWORD (WINAPI *APPLICATION_RECOVERY_CALLBACK)(PVOID pvParameter);
WINBASEAPI HRESULT WINAPI RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK pRecoveryCallback,PVOID pvParameter,DWORD dwPingInterval,DWORD dwFlags);
WINBASEAPI VOID WINAPI ApplicationRecoveryFinished(WINBOOL bSuccess);
WINBASEAPI HRESULT WINAPI ApplicationRecoveryInProgress(PBOOL pbCanceled);

/* THREAD POOL stuff : */
/* FIXME: These thread pool callback data types and
 * func. pointer types actually belong in winnt.h !!!!
 * Not all data types need to be opaque, either !!! */
typedef struct _TP_IO *PTP_IO;
typedef struct _TP_CALLBACK_INSTANCE *PTP_CALLBACK_INSTANCE;
typedef struct _TP_CLEANUP_GROUP *PTP_CLEANUP_GROUP;
typedef struct _TP_TIMER *PTP_TIMER;
typedef struct _TP_WAIT *PTP_WAIT;
typedef struct _TP_WORK *PTP_WORK;
typedef struct _TP_POOL *PTP_POOL;

typedef DWORD TP_WAIT_RESULT;

typedef VOID (CALLBACK *PTP_WAIT_CALLBACK)(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WAIT Wait, TP_WAIT_RESULT WaitResult);
typedef VOID (CALLBACK *PTP_WORK_CALLBACK)(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_WORK Work);
typedef VOID (CALLBACK *PTP_TIMER_CALLBACK)(PTP_CALLBACK_INSTANCE Instance, PVOID Context, PTP_TIMER Timer);
typedef VOID (CALLBACK *PTP_SIMPLE_CALLBACK)(PTP_CALLBACK_INSTANCE Instance, PVOID Context);

WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter, DWORD dwFlags);

/* FIXME: These must be inlines and must call something
 *	  proper from winnt.h !!!!   See above for more
 *	  thread pool fixme notes.  */

/* INLINE - http://msdn.microsoft.com/en-us/library/ms686255%28v=VS.85%29.aspx */
VOID SetThreadpoolCallbackCleanupGroup(PTP_CALLBACK_ENVIRON pcbe, PTP_CLEANUP_GROUP ptpcg, PTP_CLEANUP_GROUP_CANCEL_CALLBACK pfng);
/* INLINE - http://msdn.microsoft.com/en-us/library/ms686258%28v=VS.85%29.aspx */
VOID SetThreadpoolCallbackLibrary(PTP_CALLBACK_ENVIRON pcbe, PVOID mod);
/* INLINE -  http://msdn.microsoft.com/en-us/library/ms686261%28v=VS.85%29.aspx */
VOID SetThreadpoolCallbackPool(PTP_CALLBACK_ENVIRON pcbe, PTP_POOL ptpp);
/* INLINE - http://msdn.microsoft.com/en-us/library/ms686263%28v=VS.85%29.aspx */
VOID SetThreadpoolCallbackRunsLong(PTP_CALLBACK_ENVIRON pcbe);

WINBASEAPI WINBOOL WINAPI SetThreadpoolThreadMinimum(PTP_POOL ptpp, DWORD cthrdMic);

/* End of THREAD POOL stuff */


WINBASEAPI WINBOOL WINAPI CopyFileTransactedA(
  LPCSTR lpExistingFileName,
  LPCSTR lpNewFileName,
  LPPROGRESS_ROUTINE lpProgressRoutine,
  LPVOID lpData,
  LPBOOL pbCancel,
  DWORD dwCopyFlags,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI CopyFileTransactedW(
  LPCWSTR lpExistingFileName,
  LPCWSTR lpNewFileName,
  LPPROGRESS_ROUTINE lpProgressRoutine,
  LPVOID lpData,
  LPBOOL pbCancel,
  DWORD dwCopyFlags,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI CreateDirectoryTransactedA(
  LPCSTR lpTemplateDirectory,
  LPCSTR lpNewDirectory,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI CreateDirectoryTransactedW(
  LPCWSTR lpTemplateDirectory,
  LPCWSTR lpNewDirectory,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI CreateFileMappingNumaA(
  HANDLE hFile,
  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  DWORD flProtect,
  DWORD dwMaximumSizeHigh,
  DWORD dwMaximumSizeLow,
  LPCSTR lpName,
  DWORD nndPreferred
);
#ifndef UNICODE
#define CreateFileMappingNuma CreateFileMappingNumaA
#endif

#define TXFS_MINIVERSION_COMMITTED_VIEW 0x0000
#define TXFS_MINIVERSION_DIRTY_VIEW 0xFFFE
#define TXFS_MINIVERSION_DEFAULT_VIEW 0xFFFF

WINBASEAPI HANDLE WINAPI CreateFileTransactedA(
  LPCSTR lpFileName,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwCreationDisposition,
  DWORD dwFlagsAndAttributes,
  HANDLE hTemplateFile,
  HANDLE hTransaction,
  PUSHORT pusMiniVersion,
  PVOID pExtendedParameter
);

WINBASEAPI HANDLE WINAPI CreateFileTransactedW(
  LPCWSTR lpFileName,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwCreationDisposition,
  DWORD dwFlagsAndAttributes,
  HANDLE hTemplateFile,
  HANDLE hTransaction,
  PUSHORT pusMiniVersion,
  PVOID pExtendedParameter
);

WINBASEAPI WINBOOL WINAPI CreateHardLinkTransactedA(
  LPCSTR lpFileName,
  LPCSTR lpExistingFileName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI CreateHardLinkTransactedW(
  LPCWSTR lpFileName,
  LPCWSTR lpExistingFileName,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI CreateTransaction(
  LPSECURITY_ATTRIBUTES lpTransactionAttributes,
  LPGUID UOW,
  DWORD CreateOptions,
  DWORD IsolationLevel,
  DWORD IsolationFlags,
  DWORD Timeout,
  LPWSTR Description
);

WINBASEAPI WINBOOL WINAPI DeleteFileTransactedA(
  LPCSTR lpFileName,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI DeleteFileTransactedW(
  LPCWSTR lpFileName,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI CreateSemaphoreExA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCSTR lpName, DWORD dwFlags, DWORD dwDesiredAccess);
#ifndef UNICODE
#define CreateSemaphoreEx CreateSemaphoreExA
#endif

WINBASEAPI BOOLEAN WINAPI CreateSymbolicLinkTransactedW(LPWSTR lpSymlinkFileName, LPWSTR lpTargetFileName, DWORD dwFlags, HANDLE hTransaction);
WINBASEAPI BOOLEAN WINAPI CreateSymbolicLinkTransactedA(LPSTR lpSymlinkFileName, LPSTR lpTargetFileName, DWORD dwFlags, HANDLE hTransaction);

WINBASEAPI HANDLE WINAPI CreateWaitableTimerExA(LPSECURITY_ATTRIBUTES lpTimerAttributes, LPCSTR lpTimerName, DWORD dwFlags, DWORD dwDesiredAccess);
#ifndef UNICODE
#define CreateWaitableTimerEx CreateWaitableTimerExA
#endif

#define DeleteFileTransacted __MINGW_NAME_AW(DeleteFileTransacted)

WINBASEAPI WINBOOL WINAPI DeleteFileTransactedW(LPCWSTR lpFileName, HANDLE hTransaction);
WINBASEAPI WINBOOL WINAPI DeleteFileTransactedA(LPCSTR lpFileName, HANDLE hTransaction);

WINBASEAPI VOID WINAPI DestroyThreadpoolEnvironment(PTP_CALLBACK_ENVIRON pcbe);

typedef enum _FILE_ID_TYPE {
  FileIdType,
  ObjectIdType,
  MaximumFileIdType 
} FILE_ID_TYPE, *PFILE_ID_TYPE;

typedef struct _TIME_DYNAMIC_ZONE_INFORMATION {
  LONG       Bias;
  WCHAR      StandardName[32];
  SYSTEMTIME StandardDate;
  LONG       StandardBias;
  WCHAR      DaylightName[32];
  SYSTEMTIME DaylightDate;
  LONG       DaylightBias;
  WCHAR      TimeZoneKeyName[128];
  BOOLEAN    DynamicDaylightTimeDisabled;
} DYNAMIC_TIME_ZONE_INFORMATION, *PDYNAMIC_TIME_ZONE_INFORMATION;

typedef struct _FILE_ALLOCATION_INFO {
  LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFO, *PFILE_ALLOCATION_INFO;

typedef struct _FILE_ATTRIBUTE_TAG_INFO {
  DWORD FileAttributes;
  DWORD ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO, *PFILE_ATTRIBUTE_TAG_INFO;

typedef struct _FILE_BASIC_INFO {
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  DWORD         FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

typedef struct _FILE_COMPRESSION_INFO {
  LARGE_INTEGER CompressedFileSize;
  WORD          CompressionFormat;
  UCHAR         CompressionUnitShift;
  UCHAR         ChunkShift;
  UCHAR         ClusterShift;
  UCHAR         Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;

typedef struct _FILE_DISPOSITION_INFO {
  WINBOOL DeleteFile;
} FILE_DISPOSITION_INFO, *PFILE_DISPOSITION_INFO;

typedef struct _FILE_END_OF_FILE_INFO {
  LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFO, *PFILE_END_OF_FILE_INFO;

typedef struct _FILE_ID_BOTH_DIR_INFO {
  DWORD         NextEntryOffset;
  DWORD         FileIndex;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER EndOfFile;
  LARGE_INTEGER AllocationSize;
  DWORD         FileAttributes;
  DWORD         FileNameLength;
  DWORD         EaSize;
  CCHAR         ShortNameLength;
  WCHAR         ShortName[12];
  LARGE_INTEGER FileId;
  WCHAR         FileName[1];
} FILE_ID_BOTH_DIR_INFO, *PFILE_ID_BOTH_DIR_INFO;

typedef struct _FILE_ID_DESCRIPTOR{
  DWORD        dwSize;
  FILE_ID_TYPE Type;
  __C89_NAMELESS union {
    LARGE_INTEGER FileId;
    GUID          ObjectId;
  };
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;

typedef enum _PRIORITY_HINT {
  IoPriorityHintVeryLow       = 0,
  IoPriorityHintLow,
  IoPriorityHintNormal,
  MaximumIoPriorityHintType 
} PRIORITY_HINT;

typedef struct _FILE_IO_PRIORITY_HINT_INFO {
  PRIORITY_HINT PriorityHint;
} FILE_IO_PRIORITY_HINT_INFO, *PFILE_IO_PRIORITY_HINT_INFO;

typedef struct _FILE_NAME_INFO {
  DWORD FileNameLength;
  WCHAR FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;

typedef struct _FILE_RENAME_INFO {
  BOOL   ReplaceIfExists;
  HANDLE RootDirectory;
  DWORD  FileNameLength;
  WCHAR  FileName[1];
} FILE_RENAME_INFO, *PFILE_RENAME_INFO;

typedef struct _FILE_STANDARD_INFO {
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  DWORD          NumberOfLinks;
  WINBOOL        DeletePending;
  WINBOOL        Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_STREAM_INFO {
  DWORD         NextEntryOffset;
  DWORD         StreamNameLength;
  LARGE_INTEGER StreamSize;
  LARGE_INTEGER StreamAllocationSize;
  WCHAR         StreamName[1];
} FILE_STREAM_INFO, *PFILE_STREAM_INFO;

WINBASEAPI HANDLE WINAPI FindFirstFileNameTransactedW(
  LPCWSTR lpFileName,
  DWORD dwFlags,
  LPDWORD StringLength,
  PWCHAR LinkName,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI FindFirstFileNameW(
  LPCWSTR lpFileName,
  DWORD dwFlags,
  LPDWORD StringLength,
  PWCHAR LinkName
);

WINBASEAPI HANDLE WINAPI FindFirstFileTransactedA(
  LPCSTR lpFileName,
  FINDEX_INFO_LEVELS fInfoLevelId,
  LPVOID lpFindFileData,
  FINDEX_SEARCH_OPS fSearchOp,
  LPVOID lpSearchFilter,
  DWORD dwAdditionalFlags,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI FindFirstFileTransactedW(
  LPCWSTR lpFileName,
  FINDEX_INFO_LEVELS fInfoLevelId,
  LPVOID lpFindFileData,
  FINDEX_SEARCH_OPS fSearchOp,
  LPVOID lpSearchFilter,
  DWORD dwAdditionalFlags,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI FindFirstStreamTransactedW(
  LPCWSTR lpFileName,
  STREAM_INFO_LEVELS InfoLevel,
  LPVOID lpFindStreamData,
  DWORD dwFlags,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI FindFirstStreamW(
  LPCWSTR lpFileName,
  STREAM_INFO_LEVELS InfoLevel,
  LPVOID lpFindStreamData,
  DWORD dwFlags
);

WINBASEAPI WINBOOL WINAPI FindNextFileNameW(
  HANDLE hFindStream,
  LPDWORD StringLength,
  PWCHAR LinkName
);

WINBASEAPI WINBOOL WINAPI FindNextStreamW(
  HANDLE hFindStream,
  LPVOID lpFindStreamData
);

WINBASEAPI DWORD WINAPI FlsAlloc(
  PFLS_CALLBACK_FUNCTION lpCallback
);

WINBASEAPI WINBOOL WINAPI FlsFree(
  DWORD dwFlsIndex
);

WINBASEAPI PVOID WINAPI FlsGetValue(
  DWORD dwFlsIndex
);

WINBASEAPI WINBOOL WINAPI FlsSetValue(
  DWORD dwFlsIndex,
  PVOID lpFlsData
);

WINBASEAPI HRESULT WINAPI GetApplicationRecoveryCallback(
  HANDLE hProcess,
  APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback,
  PVOID *ppvParameter,
  DWORD dwPingInterval,
  DWORD dwFlags
);

WINBASEAPI HRESULT WINAPI GetApplicationRestartSettings(
  HANDLE hProcess,
  PWSTR pwzCommandline,
  PDWORD pcchSize,
  PDWORD pdwFlags
);

#define RESTART_NO_CRASH 1
#define RESTART_NO_HANG 2
#define RESTART_NO_PATCH 4
#define RESTART_NO_REBOOT 8

#define RESTART_MAX_CMD_LINE 1024

WINBASEAPI HRESULT WINAPI RegisterApplicationRestart(
  PCWSTR pwzCommandline,
  DWORD dwFlags
);

#define GetCompressedFileSizeTransacted __MINGW_NAME_AW(GetCompressedFileSizeTransacted)

WINBASEAPI DWORD WINAPI GetCompressedFileSizeTransactedA(
  LPCTSTR lpFileName,
  LPDWORD lpFileSizeHigh,
  HANDLE hTransaction
);

WINBASEAPI DWORD WINAPI GetCompressedFileSizeTransactedW(
  LPCWSTR lpFileName,
  LPDWORD lpFileSizeHigh,
  HANDLE hTransaction
);

WINBASEAPI DWORD WINAPI GetDynamicTimeZoneInformation(
  PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation
);


#define GetFileAttributesTransacted __MINGW_NAME_AW(GetFileAttributesTransacted)

WINBASEAPI WINBOOL WINAPI GetFileAttributesTransactedA(
  LPCSTR lpFileName,
  GET_FILEEX_INFO_LEVELS fInfoLevelId,
  LPVOID lpFileInformation,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI GetFileAttributesTransactedW(
  LPCWSTR lpFileName,
  GET_FILEEX_INFO_LEVELS fInfoLevelId,
  LPVOID lpFileInformation,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI GetFileBandwidthReservation(
  HANDLE hFile,
  LPDWORD lpPeriodMilliseconds,
  LPDWORD lpBytesPerPeriod,
  LPBOOL pDiscardable,
  LPDWORD lpTransferSize,
  LPDWORD lpNumOutstandingRequests
);

WINBASEAPI WINBOOL WINAPI GetFileInformationByHandleEx(
  HANDLE hFile,
  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
  LPVOID lpFileInformation,
  DWORD dwBufferSize
);

#define GetFullPathNameTransacted __MINGW_NAME_AW(GetFullPathNameTransacted)

WINBASEAPI DWORD WINAPI GetFullPathNameTransactedA(
  LPCSTR lpFileName,
  DWORD nBufferLength,
  LPSTR lpBuffer,
  LPSTR *lpFilePart,
  HANDLE hTransaction
);

WINBASEAPI DWORD WINAPI GetFullPathNameTransactedW(
  LPCWSTR lpFileName,
  DWORD nBufferLength,
  LPWSTR lpBuffer,
  LPWSTR *lpFilePart,
  HANDLE hTransaction
);

#define GetLongPathNameTransacted __MINGW_NAME_AW(GetLongPathNameTransacted)

WINBASEAPI DWORD WINAPI GetLongPathNameTransactedA(
  LPCSTR lpszShortPath,
  LPSTR  lpszLongPath,
  DWORD  cchBuffer,
  HANDLE hTransaction
);

WINBASEAPI DWORD WINAPI GetLongPathNameTransactedW(
  LPCWSTR lpszShortPath,
  LPWSTR   lpszLongPath,
  DWORD    cchBuffer,
  HANDLE   hTransaction
);

WINBASEAPI WINBOOL WINAPI GetNamedPipeClientComputerNameA(
  HANDLE Pipe,
  LPSTR ClientComputerName,
  ULONG ClientComputerNameLength
);

#ifndef UNICODE
#define GetNamedPipeClientComputerName GetNamedPipeClientComputerNameA
#endif

WINBASEAPI WINBOOL WINAPI GetNamedPipeClientProcessId(
  HANDLE Pipe,
  PULONG ClientProcessId
);

WINBASEAPI WINBOOL WINAPI GetNamedPipeClientSessionId(
  HANDLE Pipe,
  PULONG ClientSessionId
);

WINBASEAPI WINBOOL WINAPI GetNamedPipeServerProcessId(
  HANDLE Pipe,
  PULONG ServerProcessId
);

WINBASEAPI WINBOOL WINAPI GetNamedPipeServerSessionId(
  HANDLE Pipe,
  PULONG ServerSessionId
);

WINBASEAPI WINBOOL WINAPI GetNumaProximityNode(
  ULONG ProximityId,
  PUCHAR NodeNumber
);

WINBOOL WINAPI GetPhysicallyInstalledSystemMemory(
  PULONGLONG TotalMemoryInKilobytes
);

#define PROC_THREAD_ATTRIBUTE_NUMBER    0x0000ffff
#define PROC_THREAD_ATTRIBUTE_THREAD    0x00010000
#define PROC_THREAD_ATTRIBUTE_INPUT     0x00020000
#define PROC_THREAD_ATTRIBUTE_ADDITIVE  0x00040000

typedef enum _PROC_THREAD_ATTRIBUTE_NUM {
    ProcThreadAttributeParentProcess = 0,
    ProcThreadAttributeExtendedFlags,
    ProcThreadAttributeHandleList,
    ProcThreadAttributeGroupAffinity,
    ProcThreadAttributePreferredNode,
    ProcThreadAttributeIdealProcessor,
    ProcThreadAttributeUmsThread,
    ProcThreadAttributeMitigationPolicy,
    ProcThreadAttributeMax
} PROC_THREAD_ATTRIBUTE_NUM;

#define ProcThreadAttributeValue(number, thread, input, additive) \
    (((number)   & PROC_THREAD_ATTRIBUTE_NUMBER) \
    |((thread)   ? PROC_THREAD_ATTRIBUTE_THREAD : 0) \
    |((input)    ? PROC_THREAD_ATTRIBUTE_INPUT : 0) \
    |((additive) ? PROC_THREAD_ATTRIBUTE_ADDITIVE : 0))

#define PROC_THREAD_ATTRIBUTE_PARENT_PROCESS    ProcThreadAttributeValue(ProcThreadAttributeParentProcess,FALSE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_EXTENDED_FLAGS    ProcThreadAttributeValue(ProcThreadAttributeExtendedFlags,FALSE,TRUE,TRUE)
#define PROC_THREAD_ATTRIBUTE_HANDLE_LIST       ProcThreadAttributeValue(ProcThreadAttributeHandleList,FALSE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY    ProcThreadAttributeValue(ProcThreadAttributeGroupAffinity,TRUE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_PREFERRED_NODE    ProcThreadAttributeValue(ProcThreadAttributePreferredNode,FALSE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR   ProcThreadAttributeValue(ProcThreadAttributeIdealProcessor,TRUE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_UMS_THREAD        ProcThreadAttributeValue(ProcThreadAttributeUmsThread,TRUE,TRUE,FALSE)
#define PROC_THREAD_ATTRIBUTE_MITIGATION_POLICY ProcThreadAttributeValue(ProcThreadAttributeMitigationPolicy,FALSE,TRUE,FALSE)

#define PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE           0x0001
#define PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE 0x0002
#define PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE         0x0004

WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(
  PDWORD pdwQuotaAllowed,
  PDWORD pdwQuotaUsed
);

WINBASEAPI WINBOOL WINAPI GetSystemTimes(
  LPFILETIME lpIdleTime,
  LPFILETIME lpKernelTime,
  LPFILETIME lpUserTime
);

WINBASEAPI WINBOOL WINAPI GetTimeZoneInformationForYear(
  USHORT wYear,
  PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,
  LPTIME_ZONE_INFORMATION ptzi
);

WINBASEAPI LPVOID WINAPI MapViewOfFileExNuma(
  HANDLE hFileMappingObject,
  DWORD dwDesiredAccess,
  DWORD dwFileOffsetHigh,
  DWORD dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap,
  LPVOID lpBaseAddress,
  DWORD nndPreferred
);

#define MoveFileTransacted __MINGW_NAME_AW(MoveFileTransacted)

WINBASEAPI WINBOOL WINAPI MoveFileTransactedA(
  LPCSTR lpExistingFileName,
  LPCSTR lpNewFileName,
  LPPROGRESS_ROUTINE lpProgressRoutine,
  LPVOID lpData,
  DWORD dwFlags,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI MoveFileTransactedW(
  LPCWSTR lpExistingFileName,
  LPCWSTR lpNewFileName,
  LPPROGRESS_ROUTINE lpProgressRoutine,
  LPVOID lpData,
  DWORD dwFlags,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI OpenFileById(
  HANDLE hFile,
  LPFILE_ID_DESCRIPTOR lpFileID,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwFlags
);

WINBASEAPI WINBOOL WINAPI QueryActCtxSettingsW(
  DWORD dwFlags,
  HANDLE hActCtx,
  PCWSTR settingsNameSpace,
  PCWSTR settingName,
  PWSTR pvBuffer,
  SIZE_T dwBuffer,
  SIZE_T *pdwWrittenOrRequired
);

WINBASEAPI WINBOOL WINAPI QueryFullProcessImageNameA(
  HANDLE hProcess,
  DWORD dwFlags,
  LPSTR lpExeName,
  PDWORD lpdwSize
);

WINBASEAPI WINBOOL WINAPI QueryFullProcessImageNameW(
  HANDLE hProcess,
  DWORD dwFlags,
  LPWSTR lpExeName,
  PDWORD lpdwSize
);
#define QueryFullProcessImageName __MINGW_NAME_AW(QueryFullProcessImageName)

#define RemoveDirectoryTransacted __MINGW_NAME_AW(RemoveDirectoryTransacted)

WINBASEAPI WINBOOL WINAPI RemoveDirectoryTransactedA(
  LPCSTR lpPathName,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI RemoveDirectoryTransactedW(
  LPCWSTR lpPathName,
  HANDLE hTransaction
);

WINBASEAPI HANDLE WINAPI ReOpenFile(
  HANDLE hOriginalFile,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  DWORD dwFlags
);

WINBASEAPI WINBOOL WINAPI SetDynamicTimeZoneInformation(
  const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation
);

WINBASEAPI WINBOOL WINAPI SetFileAttributesTransactedA(
  LPCSTR lpFileName,
  DWORD dwFileAttributes,
  HANDLE hTransaction
);

WINBASEAPI WINBOOL WINAPI SetFileAttributesTransactedW(
  LPCWSTR lpFileName,
  DWORD dwFileAttributes,
  HANDLE hTransaction
);

#define SetFileAttributesTransacted __MINGW_NAME_AW(SetFileAttributesTransacted)

WINBASEAPI WINBOOL WINAPI SetFileBandwidthReservation(
  HANDLE hFile,
  DWORD nPeriodMilliseconds,
  DWORD nBytesPerPeriod,
  WINBOOL bDiscardable,
  LPDWORD lpTransferSize,
  LPDWORD lpNumOutstandingRequests
);

WINBASEAPI WINBOOL WINAPI SetFileCompletionNotificationModes(
  HANDLE FileHandle,
  UCHAR Flags
);

WINBASEAPI WINBOOL WINAPI SetFileIoOverlappedRange(
  HANDLE FileHandle,
  PUCHAR OverlappedRangeStart,
  ULONG Length
);

WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSizeEx(
  HANDLE hProcess,
  SIZE_T dwMinimumWorkingSetSize,
  SIZE_T dwMaximumWorkingSetSize,
  DWORD Flags
);

typedef struct _STARTUPINFOEXA {
  STARTUPINFOA                 StartupInfo;
  PPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXA, *LPSTARTUPINFOEXA;

typedef struct _STARTUPINFOEXAW {
  STARTUPINFOW                 StartupInfo;
  PPROC_THREAD_ATTRIBUTE_LIST lpAttributeList;
} STARTUPINFOEXW, *LPSTARTUPINFOEXW;

__MINGW_TYPEDEF_AW(STARTUPINFOEX)
__MINGW_TYPEDEF_AW(LPSTARTUPINFOEX)

WINBASEAPI HRESULT WINAPI UnregisterApplicationRestart(void);

WINBASEAPI HRESULT WINAPI UnregisterApplicationRecoveryCallback(void);

WINBASEAPI LPVOID WINAPI VirtualAllocExNuma(
  HANDLE hProcess,
  LPVOID lpAddress,
  SIZE_T dwSize,
  DWORD flAllocationType,
  DWORD flProtect,
  DWORD nndPreferred
);

WINBASEAPI WINBOOL WINAPI Wow64GetThreadContext(
  HANDLE hThread,
  PWOW64_CONTEXT lpContext
);

WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(
  PVOID OldValue
);

WINBASEAPI WINBOOL WINAPI Wow64SetThreadContext(
  HANDLE hThread,
  const WOW64_CONTEXT *lpContext
);

WINBASEAPI DWORD WINAPI Wow64SuspendThread(
  HANDLE hThread
);

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)
WINBASEAPI WINBOOL WINAPI GetNumaAvailableMemoryNodeEx(
  USHORT Node,
  PULONGLONG AvailableBytes
);

WINBASEAPI WINBOOL WINAPI GetNumaNodeNumberFromHandle(
  HANDLE hFile,
  PUSHORT NodeNumber
);

WINBASEAPI WINBOOL WINAPI GetNumaProcessorNodeEx(
  PPROCESSOR_NUMBER Processor,
  PUSHORT NodeNumber
);

WINBASEAPI WINBOOL WINAPI GetNumaProximityNodeEx(
  ULONG ProximityId,
  PUSHORT NodeNumber
);

WINBASEAPI WINBOOL WINAPI GetProcessorSystemCycleTime(
  USHORT Group,
  PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer,
  PDWORD ReturnedLength
);

WINBASEAPI DWORD WINAPI GetThreadErrorMode(void);

WINBASEAPI WINBOOL WINAPI AddConditionalAce(
  PACL pAcl,
  DWORD dwAceRevision,
  DWORD AceFlags,
  UCHAR AceType,
  DWORD AccessMask,
  PSID pSid,
  PWCHAR ConditionStr,
  DWORD *ReturnLength
);

WINBASEAPI DWORD WINAPI GetActiveProcessorCount(
  WORD GroupNumber
);

WINBASEAPI WORD WINAPI GetActiveProcessorGroupCount(void);

WINBASEAPI VOID WINAPI GetCurrentProcessorNumberEx(
  PPROCESSOR_NUMBER ProcNumber
);

WINBASEAPI DWORD WINAPI GetMaximumProcessorCount(
  WORD GroupNumber
);

WINBASEAPI WORD WINAPI GetMaximumProcessorGroupCount(void);

#ifdef _WIN64
typedef struct _UMS_COMPLETION_LIST *PUMS_COMPLETION_LIST;
typedef struct _UMS_CONTEXT *PUMS_CONTEXT;

typedef enum _UMS_SCHEDULER_REASON {
  UmsSchedulerStartup = 0,
  UmsSchedulerThreadBlocked = 1,
  UmsSchedulerThreadYield = 2
} UMS_SCHEDULER_REASON;

typedef VOID (*PUMS_SCHEDULER_ENTRY_POINT)(
  UMS_SCHEDULER_REASON Reason,
  ULONG_PTR ActivationPayload,
  PVOID SchedulerParam
);

typedef enum _UMS_THREAD_INFO_CLASS {
  UmsThreadInvalidInfoClass   = 0,
  UmsThreadUserContext        = 1,
  UmsThreadPriority           = 2,
  UmsThreadAffinity           = 3,
  UmsThreadTeb                = 4,
  UmsThreadIsSuspended        = 5,
  UmsThreadIsTerminated       = 6,
  UmsThreadMaxInfoClass       = 7 
} UMS_THREAD_INFO_CLASS, *PUMS_THREAD_INFO_CLASS;

typedef struct _UMS_SCHEDULER_STARTUP_INFO {
  ULONG                      UmsVersion;
  PUMS_COMPLETION_LIST       CompletionList;
  PUMS_SCHEDULER_ENTRY_POINT SchedulerProc;
  PVOID                      SchedulerParam;
} UMS_SCHEDULER_STARTUP_INFO, *PUMS_SCHEDULER_STARTUP_INFO;

WINBASEAPI WINBOOL CreateUmsCompletionList(
  PUMS_COMPLETION_LIST *UmsCompletionList
);

WINBASEAPI WINBOOL CreateUmsThreadContext(
  PUMS_CONTEXT *lpUmsThread
);

WINBASEAPI WINBOOL EnterUmsSchedulingMode(
  PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo
);

WINBASEAPI WINBOOL DequeueUmsCompletionListItems(
  PUMS_COMPLETION_LIST UmsCompletionList,
  DWORD WaitTimeOut,
  PUMS_CONTEXT *UmsThreadList
);

WINBASEAPI WINBOOL GetUmsCompletionListEvent(
  PUMS_COMPLETION_LIST UmsCompletionList,
  PHANDLE UmsCompletionEvent
);

WINBASEAPI WINBOOL DeleteUmsCompletionList(
  PUMS_COMPLETION_LIST UmsCompletionList
);

WINBASEAPI WINBOOL DeleteUmsThreadContext(
  PUMS_CONTEXT UmsThread
);

WINBASEAPI WINBOOL QueryUmsThreadInformation(
  PUMS_CONTEXT UmsThread,
  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,
  PVOID UmsThreadInformation,
  ULONG UmsThreadInformationLength,
  PULONG ReturnLength
);

WINBASEAPI WINBOOL SetUmsThreadInformation(
  PUMS_CONTEXT UmsThread,
  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,
  PVOID UmsThreadInformation,
  ULONG UmsThreadInformationLength
);

WINBASEAPI WINBOOL ExecuteUmsThread(
  PUMS_CONTEXT UmsThread
);

WINBASEAPI WINBOOL UmsThreadYield(
  PVOID SchedulerParam
);

WINBASEAPI PUMS_CONTEXT GetNextUmsListItem(
  PUMS_CONTEXT UmsContext
);

WINBASEAPI PUMS_CONTEXT GetCurrentUmsThread(void);


#endif /* _WIN64 */
#endif /*(_WIN32_WINNT >= 0x0601)*/

#if (_WIN32_WINNT >= 0x0602)
HMODULE WINAPI LoadPackagedLibrary(LPCWSTR lpwLibFileName, DWORD Reserved);

#endif /*(_WIN32_WINNT >= 0x0602)*/

#ifdef __cplusplus
}
#endif

#endif /* _WINBASE_ */

#if !defined(NOWINBASEINTERLOCK) && !defined(MICROSOFT_WINDOWS_WINBASE_INTERLOCKED_CPLUSPLUS_H_INCLUDED)
#define MICROSOFT_WINDOWS_WINBASE_INTERLOCKED_CPLUSPLUS_H_INCLUDED

#ifdef __cplusplus

extern "C++" {
    FORCEINLINE unsigned InterlockedIncrement(unsigned volatile *Addend) {
        return (unsigned)InterlockedIncrement((volatile LONG*)Addend);
    }

    FORCEINLINE unsigned long InterlockedIncrement(unsigned long volatile *Addend) {
        return (unsigned long)InterlockedIncrement((volatile LONG*)Addend);
    }

    FORCEINLINE unsigned __int64 InterlockedIncrement(unsigned __int64 volatile *Addend) {
        return (unsigned __int64)InterlockedIncrement64((volatile LONGLONG*)Addend);
    }

    FORCEINLINE unsigned InterlockedDecrement(unsigned volatile *Addend) {
        return (unsigned long)InterlockedDecrement((volatile LONG*)Addend);
    }

    FORCEINLINE unsigned long InterlockedDecrement(unsigned long volatile *Addend) {
        return (unsigned long)InterlockedDecrement((volatile LONG*)Addend);
    }

    FORCEINLINE unsigned __int64 InterlockedDecrement(unsigned __int64 volatile *Addend) {
        return (unsigned __int64)InterlockedDecrement64((volatile LONGLONG*)Addend);
    }

    FORCEINLINE unsigned InterlockedExchange(unsigned volatile *Target, unsigned Value) {
        return (unsigned)InterlockedExchange((volatile LONG*) Target, (LONG)Value);
    }

    FORCEINLINE unsigned long InterlockedExchange(unsigned long volatile *Target, unsigned long Value) {
        return (unsigned long)InterlockedExchange((volatile LONG*)Target, (LONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedExchange(unsigned __int64 volatile *Target, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedExchange64((volatile LONGLONG*)Target, (LONGLONG)Value);
    }

    FORCEINLINE unsigned InterlockedExchangeAdd(unsigned volatile *Addend, unsigned Value) {
        return (unsigned)InterlockedExchangeAdd((volatile LONG*)Addend, (LONG)Value);
    }

    FORCEINLINE unsigned InterlockedExchangeSubtract(unsigned volatile *Addend, unsigned Value) {
        return (unsigned)InterlockedExchangeAdd((volatile LONG*)Addend, -(LONG)Value);
    }

    FORCEINLINE unsigned long InterlockedExchangeAdd(unsigned long volatile *Addend, unsigned long Value) {
        return (unsigned long)InterlockedExchangeAdd((volatile LONG*)Addend, (LONG)Value);
    }

    FORCEINLINE unsigned long InterlockedExchangeSubtract(unsigned long volatile *Addend, unsigned long Value) {
        return (unsigned long)InterlockedExchangeAdd((volatile LONG*)Addend, -(LONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedExchangeAdd(unsigned __int64 volatile *Addend, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedExchangeAdd64((volatile LONGLONG*)Addend,  (LONGLONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedExchangeSubtract(unsigned __int64 volatile *Addend, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedExchangeAdd64((volatile LONGLONG*)Addend, -(LONGLONG)Value);
    }

    FORCEINLINE unsigned InterlockedCompareExchange(unsigned volatile *Destination, unsigned Exchange, unsigned Comperand) {
        return (unsigned)InterlockedCompareExchange((volatile LONG*)Destination, (LONG)Exchange, (LONG)Comperand);
    }

    FORCEINLINE unsigned long InterlockedCompareExchange(unsigned long volatile *Destination, unsigned long Exchange,
                                                         unsigned long Comperand) {
        return (unsigned long)InterlockedCompareExchange((volatile LONG*)Destination, (LONG)Exchange, (LONG)Comperand);
    }

    FORCEINLINE unsigned __int64 InterlockedAnd(unsigned __int64 volatile *Destination, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedAnd64((volatile LONGLONG*)Destination, (LONGLONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedOr(unsigned __int64 volatile *Destination, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedOr64((volatile LONGLONG*)Destination, (LONGLONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedXor(unsigned __int64 volatile *Destination, unsigned __int64 Value) {
        return (unsigned __int64)InterlockedXor64((volatile LONGLONG*)Destination, (LONGLONG)Value);
    }

    FORCEINLINE unsigned __int64 InterlockedCompareExchange(unsigned __int64 volatile *Destination, unsigned __int64 Exchange,
                                                            unsigned __int64 Comperand) {
        return (unsigned __int64)InterlockedCompareExchange64((volatile LONGLONG*)Destination, (LONGLONG)Exchange,
                                                              (LONGLONG)Comperand);
    }
}

#endif /* __cplusplus */

#endif /* !defined(NOWINBASEINTERLOCK) && !defined(MICROSOFT_WINDOWS_WINBASE_INTERLOCKED_CPLUSPLUS_H_INCLUDED) */
