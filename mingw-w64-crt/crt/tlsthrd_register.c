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

const int __mingw_TLScallback_caller_provider = 1;
void WINAPI __mingw_TLScallback(HANDLE, DWORD, LPVOID);
static _CRTALLOC(".CRT$XLD") const PIMAGE_TLS_CALLBACK __mingw_TLScallback_ptr = __mingw_TLScallback;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked.  */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }
