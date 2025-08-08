/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <sect_attribs.h>

const int __mingw_atexit_tls_callback_caller_provider = 1;
extern void (WINAPI *const __mingw_atexit_tls_callback_ptr)(HANDLE,DWORD,LPVOID);
static void WINAPI callback(HANDLE handle, DWORD reason, LPVOID reserved) {
  __mingw_atexit_tls_callback_ptr(handle, reason, reserved);
}
static _CRTALLOC(".CRT$XLB") PIMAGE_TLS_CALLBACK callback_ptr = callback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked.  */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((used)) const IMAGE_TLS_DIRECTORY *const _include_tls_used = &_tls_used;
