/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_ERRNO
#define _INC_ERRNO

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
_CRTIMP extern int *__cdecl _errno(void);
#define errno (*_errno())

errno_t __cdecl _set_errno(int _Value);
errno_t __cdecl _get_errno(int *_Value);
#endif /* _CRT_ERRNO_DEFINED */

#define EPERM 1
#define ENOENT 2
#define ENOFILE ENOENT
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define EDEADLK 36
#define ENAMETOOLONG 38
#define ENOLCK 39
#define ENOSYS 40
#define ENOTEMPTY 41

#ifndef RC_INVOKED
#if !defined(_SECURECRT_ERRCODE_VALUES_DEFINED)
#define _SECURECRT_ERRCODE_VALUES_DEFINED
#define EINVAL 22
#define ERANGE 34
#define EILSEQ 42
#define STRUNCATE 80
#endif
#endif

#define EDEADLOCK EDEADLK

/* Posix thread extensions.  */

/* Defined with same value as on svr.  */
#ifndef ENOTSUP
#define ENOTSUP         134
#endif

/* Extension defined as WSA or classical WIN error-numbers.  */

#ifndef EAFNOSUPPORT
/* Defined as WSAEAFNOSUPPORT.  */
#define EAFNOSUPPORT 10047
#endif

#ifndef EADDRINUSE
/* Defined as WSAEADDRINUSE.  */
#define EADDRINUSE 10048
#endif

#ifndef EADDRNOTAVAIL
/* Define as WSAEADDRNOTAVAIL.  */
#define EADDRNOTAVAIL 10049
#endif

#ifndef EISCONN
/* Defined as WSAEISCONN.  */
#define EISCONN 10056
#endif

#ifndef ENOBUFS
/* Defined as WSAENOBUFS.  */
#define ENOBUFS 10055
#endif

#ifndef ECONNABORTED
/* Defined as WSAECONNABORTED.  */
#define ECONNABORTED 10053
#endif

#ifndef EALREADY
/* Defined as WSAEALREADY.  */
#define EALREADY 10037
#endif

#ifndef ECONNREFUSED
/* Defined as WSAECONNREFUSED.  */
#define ECONNREFUSED 10061
#endif

#ifndef ECONNRESET
/* Defined as WSAECONNRESET.  */
#define ECONNRESET 10054
#endif

#ifndef EDESTADDRREQ
/* Defined as WSAEDESTADDRREQ.  */
#define EDESTADDRREQ 10039
#endif

#ifndef EHOSTUNREACH
/* Defined as WSAEHOSTUNREACH.  */
#define EHOSTUNREACH 10065
#endif

#ifndef EMSGSIZE
/* Defined as WSAEMSGSIZE.  */
#define EMSGSIZE 10040
#endif

#ifndef ENETDOWN
/* Define as WSAENETDOWN.  */
#define ENETDOWN 10050
#endif

#ifndef ENETRESET
/* Defined as WSAENETRESET.  */
#define ENETRESET 10052
#endif

#ifndef ENETUNREACH
/* Defined as WSAENETUNREACH.  */
#define ENETUNREACH 10051
#endif

#ifndef ENOPROTOOPT
/* Defined as WSAENOPROTOOPT.  */
#define ENOPROTOOPT 10042
#endif

#ifndef ENOTSOCK
/* Defined as WSAENOTSOCK.  */
#define ENOTSOCK 10038
#endif

#ifndef ENOTCONN
/* Defined as WSAENOTCONN.  */
#define ENOTCONN 10057
#endif

#ifndef ECANCELED
/* Defined as WSAEINTR.  */
#define ECANCELED 10004
#endif

#ifndef EINPROGRESS
/* Defined as WSAEINPROGRESS.  */
#define EINPROGRESS 10036
#endif

#ifndef EOPNOTSUPP
/* Defined as WSAEOPNOTSUPP.  */
#define EOPNOTSUPP 10045
#endif

/* Defined as WSAEWOULDBLOCK.  */
#ifndef EWOULDBLOCK
#define EWOULDBLOCK 10035
#endif

#ifndef EOWNERDEAD
/* Defined as ERROR_SEM_OWNER_DIED.  */
#define EOWNERDEAD 105
#endif

#ifndef EPROTO
/* Defined as XACT_E_TIP_PROTOCOL_ERROR.  */
#define EPROTO 0x8004D020
#endif

#ifndef EPROTONOSUPPORT
/* Defined as WSAEPROTONOSUPPORT.  */
#define EPROTONOSUPPORT 10043
#endif

/* Defined as WSAETIMEDOUT.  */
#ifndef ETIMEDOUT
#define ETIMEDOUT 10060
#endif

#ifndef ELOOP
/* Defined as WSAELOOP.  */
#define ELOOP 10062
#endif

#ifndef EPROTOTYPE
/* Defined as WSAEPROTOTYPE.  */
#define EPROTOTYPE 10041
#endif

#ifdef __cplusplus
}
#endif
#endif
