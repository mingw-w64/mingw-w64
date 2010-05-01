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
    FreeLibrary(kernel32handle);
}

void doredirect(const int redir) {
  if (redir) {
    kernel32handle = LoadLibraryA("kernel32.dll");
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
      FreeLibrary(kernel32handle);
      fprintf(stderr, "Wow64DisableWow64FsRedirection failed.\n");
      return;
    } else {
      atexit(undoredirect);
    }
  }
}
#endif
