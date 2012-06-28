/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CYGWIN
#define _INC_CYGWIN

#ifndef __CYGWIN__
#error Only Cygwin target is supported!
#endif

/* This includes the Cygwin gcc definitions for types like wchar_t or size_t. */
#include <stddef.h>

/* Make sure that POSIX types are not defined by _mingw.h if we're building
   for a Cygwin target.  In this case we have to make sure to use the types
   defined by the Cygwin/newlib headers. */
#define _SIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#define _INTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#define _PTRDIFF_T_DEFINED
#define _WCHAR_T_DEFINED
#define _WCTYPE_T_DEFINED
#define _ERRCODE_DEFINED	/* FIXME?  errno_t is no POSIX type. */
#define _TIME_T_DEFINED

#endif /* _INC_CYGWIN */
