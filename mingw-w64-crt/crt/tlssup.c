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
ULONG _tls_index = -1; /* -1 as uninitialized value */

/* TLS raw template data start and end.
   We use here pointer-types for start/end so that tls-data remains
   aligned on pointer-size-width.  This seems to be required for
   pe-loader. */
_CRTALLOC(".tls") char *_tls_start = NULL;
_CRTALLOC(".tls$ZZZ") char *_tls_end = NULL;

_CRTALLOC(".CRT$XLA") PIMAGE_TLS_CALLBACK __xl_a = 0;
_CRTALLOC(".CRT$XLZ") PIMAGE_TLS_CALLBACK __xl_z = 0;

/* This is placed next to `__xl_z` so it will not be garbage-collected by the
   linker. The linker should have retained `_tls_used` but it's only fixed in
   Binutils 2.48.  */
_CRTALLOC(".CRT$XLZZ") const IMAGE_TLS_DIRECTORY _tls_used = {
  (ULONG_PTR) &_tls_start, (ULONG_PTR) &_tls_end,
  (ULONG_PTR) &_tls_index, (ULONG_PTR) (&__xl_a+1),
  (ULONG) 0, (ULONG) 0
};
