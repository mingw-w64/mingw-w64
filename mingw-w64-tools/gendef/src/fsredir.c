/*
    gendef - Generate list of exported symbols from a Portable Executable.
    Copyright (C) 2009-2016  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
    redirectorfunction = (redirector)(INT_PTR)GetProcAddress(kernel32handle, "Wow64DisableWow64FsRedirection");
    revertorfunction = (revertor)(INT_PTR)GetProcAddress(kernel32handle, "Wow64RevertWow64FsRedirection");
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
