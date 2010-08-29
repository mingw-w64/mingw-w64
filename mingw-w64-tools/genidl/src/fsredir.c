/*
   Copyright (c) 2009, 2010 mingw-w64 project

   Contributing authors: Kai Tietz, Jonathan Yong

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/
#include "fsredir.h"

#ifdef REDIRECTOR
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

static PVOID revert; /*revert pointer*/
static HMODULE kernel32handle;
typedef WINBOOL (__stdcall (*redirector))(PVOID *);
typedef WINBOOL (__stdcall (*revertor))(PVOID);
static redirector redirectorfunction; /*Wow64DisableWow64FsRedirection*/
static revertor revertorfunction;     /*Wow64RevertWow64FsRedirection*/

static void undoredirect(void) {
    revertorfunction(revert);
}

void doredirect(const int redir) {
  if (redir) {
    kernel32handle = GetModuleHandleW(L"kernel32.dll");
    if (!kernel32handle) {
      fprintf(stderr, "kernel32.dll failed to load, failed to disable FS redirection.\n");
      return;
    }
    redirectorfunction = (redirector)GetProcAddress(kernel32handle, "Wow64DisableWow64FsRedirection");
    revertorfunction = (revertor)GetProcAddress(kernel32handle, "Wow64RevertWow64FsRedirection");
    if (!redirectorfunction || ! revertorfunction) {
      FreeLibrary(kernel32handle);
      fprintf(stderr, "Wow64DisableWow64FsRedirection or Wow64RevertWow64FsRedirection functions missing.\n");
      return;
    }
    if (!redirectorfunction(&revert)) {
      fprintf(stderr, "Wow64DisableWow64FsRedirection failed.\n");
      return;
    } else {
      atexit(undoredirect);
    }
  }
}
#endif
