/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <assert.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>

/* This is import symbol name for "_assert" from CRT DLL library */
extern void (__cdecl *__MINGW_IMP_SYMBOL(__msvcrt_assert))(const char *message, const char *file, unsigned line);

/* Turn off _O_WTEXT, _O_U16TEXT or _O_U8TEXT mode on stderr stream
 * by changing mode to _O_TEXT, because fprintf (called by __msvcrt_assert)
 * does not work (and does nothing) on FILE* stream in some of those modes.
 * Only fwprintf works with those modes, but _assert uses fprintf.
 * Before changing the FILE* stream mode, it is required to flush buffers. */
void __cdecl _assert(const char *message, const char *file, unsigned line)
{
  /* stderr expands to function call */
  FILE *stream = stderr;
  /* Cache fd used by `stderr` */
  int fd = _fileno (stream);
  /* We need to restore previous mode in case `_assert` returns; it can happen
   * if program has called _set_error_mode(_OUT_TO_MSGBOX) and user pressed
   * "Ignore" button in popped up message box. */
  int oldmode;

  /* Change `stderr` mode to `_O_TEXT` */
  fflush(stream);
  oldmode = _setmode(fd, _O_TEXT);

  /* Call CRT `_assert` */
  __MINGW_IMP_SYMBOL(__msvcrt_assert)(message, file, line);

  /* Restore `stderr` mode to `oldmode` */
  fflush (stream);
  if (_setmode (fd, oldmode) != _O_TEXT) {
    abort ();
  }
}

void (__cdecl *__MINGW_IMP_SYMBOL(_assert))(const char *message, const char *file, unsigned line) = _assert;
