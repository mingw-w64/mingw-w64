/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _UNISTD_H
#define _UNISTD_H
#define __UNISTD_H_SOURCED__ 1

#include <io.h>
#include <process.h>
#include <getopt.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined __NO_ISOCEXT
#include <sys/types.h> /* For useconds_t. */

int __cdecl __MINGW_NOTHROW usleep(useconds_t useconds);
#endif  /* Not __NO_ISOCEXT */

#ifndef FTRUNCATE_DEFINED
#define FTRUNCATE_DEFINED
/* This is defined as a real library function to allow autoconf
   to verify its existence. */
#if !defined(NO_OLDNAMES) || defined(_POSIX)
int ftruncate(int, off_t);
#ifndef __CRT__NO_INLINE
__CRT_INLINE int ftruncate(int __fd, off_t __length)
{
  return _chsize (__fd, __length);
}
#endif /* !__CRT__NO_INLINE */
#else
int ftruncate(int, _off_t);
#ifndef __CRT__NO_INLINE
__CRT_INLINE int ftruncate(int __fd, _off_t __length)
{
  return _chsize (__fd, __length);
}
#endif /* !__CRT__NO_INLINE */
#endif
#endif /* FTRUNCATE_DEFINED */

#ifdef __cplusplus
}
#endif

#undef __UNISTD_H_SOURCED__
#endif /* _UNISTD_H */

