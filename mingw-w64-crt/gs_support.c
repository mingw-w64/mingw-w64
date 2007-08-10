#include <windows.h>
#include <intrin.h>

#ifdef _WIN64
#define DEFAULT_SECURITY_COOKIE 0x00002B992DDFA232ll
#else
#define DEFAULT_SECURITY_COOKIE 0xBB40E64E
#endif

/* Externals.  */
PRUNTIME_FUNCTION RtlLookupFunctionEntry (ULONG64, PULONG64, PVOID);
PVOID RtlVirtualUnwind (ULONG HandlerType, ULONG64, ULONG64, PRUNTIME_FUNCTION,
			PCONTEXT, PVOID *, PULONG64, PVOID);

typedef LONG NTSTATUS;

#define UNW_FLAG_NHANDLER 0x00
#define STATUS_STACK_BUFFER_OVERRUN ((NTSTATUS)0xC0000409L)

typedef union
{
  unsigned __int64 ft_scalar;
  FILETIME ft_struct;
} FT;

static EXCEPTION_RECORD GS_ExceptionRecord;
static CONTEXT GS_ContextRecord;

static const EXCEPTION_POINTERS GS_ExceptionPointers = {
  &GS_ExceptionRecord,&GS_ContextRecord
};

DECLSPEC_SELECTANY UINT_PTR __security_cookie = DEFAULT_SECURITY_COOKIE;
DECLSPEC_SELECTANY UINT_PTR __security_cookie_complement = ~(DEFAULT_SECURITY_COOKIE);

void __cdecl
__security_init_cookie (void)
{
  UINT_PTR cookie;
  FT systime = { 0, };
  LARGE_INTEGER perfctr;
#ifdef CHECK_FOR_LATE_COOKIE_INIT
  PEXCEPTION_REGISTRATION_RECORD ehrec;
#endif

  if (__security_cookie != DEFAULT_SECURITY_COOKIE)
    {
      __security_cookie_complement = ~__security_cookie;
      return;
    }

#ifdef CHECK_FOR_LATE_COOKIE_INIT
  for (ehrec = (PEXCEPTION_REGISTRATION_RECORD) (UINT_PTR) __readfsdword(FIELD_OFFSET(NT_TIB,ExceptionList));
       ehrec != EXCEPTION_CHAIN_END; ehrec = ehrec->Next)
    {
      if (ehrec->Handler == &_except_handler4)
	FatalAppExit (0, _RT_COOKIE_INIT_TXT);

      if (ehrec >= ehrec->Next)
	break;
    }
#endif
  GetSystemTimeAsFileTime (&systime.ft_struct);
#ifdef _WIN64
  cookie = systime.ft_scalar;
#else
  cookie = systime.ft_struct.dwLowDateTime;
  cookie ^= systime.ft_struct.dwHighDateTime;
#endif

  cookie ^= GetCurrentProcessId ();
  cookie ^= GetCurrentThreadId ();
  cookie ^= GetTickCount ();

  QueryPerformanceCounter (&perfctr);
#ifdef _WIN64
  cookie ^= perfctr.QuadPart;
#else
  cookie ^= perfctr.LowPart;
  cookie ^= perfctr.HighPart;
#endif

#ifdef _WIN64
  cookie &= 0x0000ffffffffffffll;
#endif

  if (cookie == DEFAULT_SECURITY_COOKIE)
    cookie = DEFAULT_SECURITY_COOKIE + 1;
  __security_cookie = cookie;
  __security_cookie_complement = ~cookie;
}

__declspec(noreturn) void __cdecl
__report_gsfailure (ULONGLONG StackCookie)
{
  volatile UINT_PTR cookie[2];
  ULONG64 controlPC, imgBase, establisherFrame;
  PRUNTIME_FUNCTION fctEntry;
  PVOID hndData;

  RtlCaptureContext (&GS_ContextRecord);
  controlPC = GS_ContextRecord.Rip;
  fctEntry = RtlLookupFunctionEntry (controlPC, &imgBase, NULL);
  if (fctEntry != NULL)
    {
      RtlVirtualUnwind (UNW_FLAG_NHANDLER, imgBase, controlPC, fctEntry,
			&GS_ContextRecord, &hndData, &establisherFrame, NULL);
    }
  else
    {
      GS_ContextRecord.Rip = (ULONGLONG) __builtin_return_address (0);
      GS_ContextRecord.Rsp = (ULONGLONG) __builtin_frame_address (0) + 8;
    }

  GS_ExceptionRecord.ExceptionAddress = (PVOID) GS_ContextRecord.Rip;
  GS_ContextRecord.Rcx = StackCookie;
  GS_ExceptionRecord.ExceptionCode = STATUS_STACK_BUFFER_OVERRUN;
  GS_ExceptionRecord.ExceptionFlags = EXCEPTION_NONCONTINUABLE;
  cookie[0] = __security_cookie;
  cookie[1] = __security_cookie_complement;
  SetUnhandledExceptionFilter (NULL);
  UnhandledExceptionFilter ((EXCEPTION_POINTERS *) &GS_ExceptionPointers);
  TerminateProcess (GetCurrentProcess (), STATUS_STACK_BUFFER_OVERRUN);
  abort();
}
