/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <excpt.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <signal.h>
#include <stdio.h>

EXCEPTION_DISPOSITION __cdecl __mingw_SEH_error_handler(struct _EXCEPTION_RECORD *, void *, struct _CONTEXT *, void *);

#if defined(__x86_64__) && !defined(_MSC_VER) && !defined(__SEH__)

#pragma pack(push,1)
typedef struct _UNWIND_INFO {
  BYTE Version:3;
  BYTE Flags:5;
  BYTE PrologSize;
  BYTE CountOfUnwindCodes;
  BYTE FrameRegisterAndOffset;
  ULONG AddressOfExceptionHandler;
} UNWIND_INFO,*PUNWIND_INFO;
#pragma pack(pop)

PIMAGE_SECTION_HEADER _FindPESectionByName (const char *);
PIMAGE_SECTION_HEADER _FindPESectionExec (size_t);
PBYTE _GetPEImageBase (void);

#define MAX_PDATA_ENTRIES 32
static RUNTIME_FUNCTION emu_pdata[MAX_PDATA_ENTRIES];
static UNWIND_INFO emu_xdata[MAX_PDATA_ENTRIES];

int __mingw_init_ehandler (void);
int
__mingw_init_ehandler (void)
{
  static int was_here = 0;
  size_t e = 0;
  PIMAGE_SECTION_HEADER pSec;
  PBYTE _ImageBase = _GetPEImageBase ();
  
  if (was_here || !_ImageBase)
    return was_here;
  was_here = 1;
  if (_FindPESectionByName (".pdata") != NULL)
    return 1;

  e = 0;
  /* Fill tables and entries.  */
  while (e < MAX_PDATA_ENTRIES && (pSec = _FindPESectionExec (e)) != NULL)
    {
      emu_xdata[e].Version = 1;
      emu_xdata[e].Flags = UNW_FLAG_EHANDLER;
      emu_xdata[e].AddressOfExceptionHandler =
	(DWORD)(size_t) ((LPBYTE)__mingw_SEH_error_handler - _ImageBase);
      emu_pdata[e].BeginAddress = pSec->VirtualAddress;
      emu_pdata[e].EndAddress = pSec->VirtualAddress + pSec->Misc.VirtualSize;
      emu_pdata[e].UnwindData =
	(DWORD)(size_t)((LPBYTE)&emu_xdata[e] - _ImageBase);
      ++e;
    }
#ifdef _DEBUG_CRT
  if (!e || e > MAX_PDATA_ENTRIES)
    abort ();
#endif
  /* RtlAddFunctionTable.  */
  if (e != 0)
    RtlAddFunctionTable (emu_pdata, e, (DWORD64)_ImageBase);
  return 1;
}

#endif

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
EXCEPTION_DISPOSITION __cdecl
__mingw_SEH_error_handler (struct _EXCEPTION_RECORD* ExceptionRecord,
			   void *EstablisherFrame  __attribute__ ((unused)),
			   struct _CONTEXT* ContextRecord,
			   void *DispatcherContext __attribute__ ((unused)))
{
  long action;

  if (ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING)
    return ExceptionContinueSearch;

  /* Despite that the CRT _XcptFilter() function is SEH __except filter function,
   * it directly executes the handler registered by CRT signal() function. Normally
   * the SEH __except handler is called based on the SEH __except filter result.
   *
   * If the CRT signal handler function (called by _XcptFilter() function) returns
   * then the CRT _XcptFilter() returns back to us and the action is set to:
   * EXCEPTION_CONTINUE_EXECUTION - execution of the process should continue
   * EXCEPTION_EXECUTE_HANDLER - execution of the process should be aborted
   * EXCEPTION_CONTINUE_SEARCH - parent SEH handler should be called
   */
  action = _XcptFilter(ExceptionRecord->ExceptionCode, &(EXCEPTION_POINTERS){.ExceptionRecord = ExceptionRecord, .ContextRecord = ContextRecord});
  switch (action)
    {
    case EXCEPTION_CONTINUE_SEARCH:
      return ExceptionContinueSearch;

    case EXCEPTION_CONTINUE_EXECUTION:
      return ExceptionContinueExecution;

    case EXCEPTION_EXECUTE_HANDLER:
    default:
      /* msvc CRT EXE exception handler just exit process with exception code */
      _exit(ExceptionRecord->ExceptionCode);
    }
}
