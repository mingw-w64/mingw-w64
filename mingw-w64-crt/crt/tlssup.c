/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 * Written by Kai Tietz  <kai.tietz@onevision.com>
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <sect_attribs.h>

__attribute__((used))
ULONG _tls_index = 0;

/* TLS raw template data start and end. 
   We use here pointer-types for start/end so that tls-data remains
   aligned on pointer-size-width.  This seems to be required for
   pe-loader. */
_CRTALLOC(".tls") char *_tls_start = NULL;
_CRTALLOC(".tls$ZZZ") char *_tls_end = NULL;

_CRTALLOC(".CRT$XLA") PIMAGE_TLS_CALLBACK __xl_a = 0;
_CRTALLOC(".CRT$XLZ") PIMAGE_TLS_CALLBACK __xl_z = 0;

__attribute__((used))
const IMAGE_TLS_DIRECTORY _tls_used = {
  (ULONG_PTR) &_tls_start, (ULONG_PTR) &_tls_end,
  (ULONG_PTR) &_tls_index, (ULONG_PTR) (&__xl_a+1),
  (ULONG) 0, (ULONG) 0
};
