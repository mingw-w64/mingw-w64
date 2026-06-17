/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <crtdbg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "libtest.h"

/**
 * Invalid parameter handler.
 */
__attribute__ ((__noreturn__))
static void __cdecl mingw_test_invalid_parameter_handler (
  const wchar_t *expression,
  const wchar_t *function,
  const wchar_t *file,
  unsigned int line,
  uintptr_t pReserved
) {
  fprintf(stderr, "Invalid parameter: %ls", expression);
  /* Additional arguments are non-NULL only for debug CRT DLLs */
  if (function)
    fprintf(stderr, ", function %ls", function);
  if (file)
    fprintf(stderr, ", file %ls", file);
  if (line)
    fprintf(stderr, ", line %d", line);
  fprintf(stderr, "\n");
  (void)pReserved;
  /* Ensure that this handler does not return, as the whole handler replaces calling of Dr. Watson */
  abort ();
}

static int __cdecl mingw_test_fini (void) {
  _CrtCheckMemory ();
  _CrtDumpMemoryLeaks ();

  return EXIT_SUCCESS;
}

void mingw_test_init (void) {
  UINT oldErrorMode = SetErrorMode (0);
  SetErrorMode (oldErrorMode | SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);

  /**
   * msvcr80.dll and later attempt to set multibyte code page to active
   * ANSI code page during initialization.
   *
   * If active ANSI code page is 65001 (UTF-8), _setmbcp will fail
   * and set `errno` to EINVAL.
   *
   * Some tests may assume `errno` to be set to zero when entering main.
   */
  errno = 0;

  /* Set CRT _invalid_parameter() output to CRT stderr and call abort (the default is to just call Dr. Watson) */
  _set_invalid_parameter_handler (mingw_test_invalid_parameter_handler);

  /**
   * Disable buffering.
   * This ensures that all output is written to log files.
   */
  setvbuf (stdout, NULL, _IONBF, 0);
  setvbuf (stderr, NULL, _IONBF, 0);

#if __MSVCRT_VERSION__ >= 0x0800
  /**
   * Make `abort` as silent as possible.
   */
  _set_abort_behavior (0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
#endif

#if __MSVCRT_VERSION__ >= 0x0400
  /**
   * We don't want failed assertions to pop-up a message box.
   */
  assert (_set_error_mode (_OUT_TO_STDERR) != -1);
#endif

  /**
   * Redirect `_CRT_WARN` debug messages to `stderr`.
   */
  assert (_CrtSetReportMode (_CRT_WARN, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_FILE) != -1);
  assert (_CrtSetReportFile (_CRT_WARN, _CRTDBG_FILE_STDERR) != _CRTDBG_HFILE_ERROR);

  /**
   * Redirect `_CRT_ERROR` debug messages to `stderr`.
   */
  assert (_CrtSetReportMode (_CRT_ERROR, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_FILE) != -1);
  assert (_CrtSetReportFile (_CRT_ERROR, _CRTDBG_FILE_STDERR) != _CRTDBG_HFILE_ERROR);

  /**
   * Redirect `_CRT_ASSERT` debug messages to `stderr`.
   */
  assert (_CrtSetReportMode (_CRT_ASSERT, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_FILE) != -1);
  assert (_CrtSetReportFile (_CRT_ASSERT, _CRTDBG_FILE_STDERR) != _CRTDBG_HFILE_ERROR);

  _onexit (mingw_test_fini);
}
