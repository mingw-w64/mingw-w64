/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <signal.h>

extern int mingw_app_type;

void __cdecl _wassert (const wchar_t *, const wchar_t *,unsigned);
void __cdecl _assert (const char *, const char *, unsigned);

void __cdecl
_assert (const char *_Message, const char *_File, unsigned _Line)
{
  wchar_t *m, *f;
  int i;
  m = (wchar_t *) malloc ((strlen (_Message) + 1) * sizeof (wchar_t));
  f = (wchar_t *) malloc ((strlen (_File) + 1) * sizeof (wchar_t));
  for (i = 0; _Message[i] != 0; i++)
    m[i] = ((wchar_t) _Message[i]) & 0xff;
  m[i] = 0;
  for (i = 0; _File[i] != 0; i++)
    f[i] = ((wchar_t) _File[i]) & 0xff;
  f[i] = 0;
  _wassert (m, f, _Line);
  free (m);
  free (f);
}

void __cdecl
_wassert (const wchar_t *_Message, const wchar_t *_File, unsigned _Line)
{
  wchar_t *msgbuf = (wchar_t *) malloc (8192*sizeof(wchar_t));
  wchar_t fn[MAX_PATH + 1];
  DWORD nCode;

  if (!_File || _File[0] == 0)
    _File = L"<unknown>";
  if (!_Message || _Message[0] == 0)
    _Message = L"?";
  if (! GetModuleFileNameW (NULL, fn, MAX_PATH))
    wcscpy (fn, L"<unknown>");
  _snwprintf (msgbuf, 8191, L"Assertion failed!\n\nProgram: %ws\n"
		  "File: %ws, Line %u\n\nExpression: %ws",
		  fn, _File,_Line, _Message);
  if (mingw_app_type == 0)
    {
      fwprintf (stderr, L"%ws\n", msgbuf);
      abort ();
    }
  nCode = MessageBoxW (NULL, msgbuf, L"MinGW Runtime Assertion", MB_ABORTRETRYIGNORE|
    MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  if (nCode == IDABORT)
    {
      raise (SIGABRT);
      _exit (3);
      abort ();
    }
  if (nCode == IDIGNORE)
    return;
  abort ();
}
