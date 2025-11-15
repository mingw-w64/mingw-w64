/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <assert.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

/* This is import symbol name for "_assert" from CRT DLL library */
__MINGW_ATTRIB_NORETURN
extern void (__cdecl *__MINGW_IMP_SYMBOL(__msvcrt_assert))(const char *message, const char *file, unsigned line);

__MINGW_ATTRIB_NORETURN
void __cdecl _assert(const char *message, const char *file, unsigned line)
{
  /* Turn off _O_WTEXT, _O_U16TEXT or _O_U8TEXT mode on stderr stream
   * by changing mode to _O_TEXT, because fprintf (called by __msvcrt_assert)
   * does not work (and does nothing) on FILE* stream in some of those modes.
   * Only fwprintf works with those modes, but _assert uses fprintf.
   * Before changing the FILE* stream mode, it is required to flush buffers. */
  FILE *stream = stderr; /* stderr expands to function call */
  fflush(stream);
  _setmode(fileno(stream), _O_TEXT);
  __MINGW_IMP_SYMBOL(__msvcrt_assert)(message, file, line);
}
__MINGW_ATTRIB_NORETURN
void (__cdecl *__MINGW_IMP_SYMBOL(_assert))(const char *message, const char *file, unsigned line) = _assert;
