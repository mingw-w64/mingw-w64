/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _INC_CRTDEFS
#define _INC_CRTDEFS

#include "_mingw_mac.h"

#ifdef __cplusplus
extern "C" {
#endif
const char *__mingw_get_crt_info (void);
#ifdef __cplusplus
}
#endif

/* C/C++ specific language defines.  */
#ifdef _WIN64
#ifdef __stdcall
#undef __stdcall
#endif
#define __stdcall
#endif

#ifndef __GNUC__
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT  __declspec(dllimport)
# endif
# ifndef _CRTIMP
#  define _CRTIMP  __declspec(dllimport)
# endif
# define __DECLSPEC_SUPPORTED
# define __attribute__(x) /* nothing */
#else /* __GNUC__ */
# ifdef __declspec
#  ifndef __MINGW_IMPORT
/* Note the extern. This is needed to work around GCC's
limitations in handling dllimport attribute.  */
#   define __MINGW_IMPORT  extern __attribute__ ((__dllimport__))
#  endif
#  ifndef _CRTIMP
#    undef __USE_CRTIMP
#    if !defined (_CRTBLD) && !defined (_SYSCRT)
#      define __USE_CRTIMP 1
#    endif
#    ifdef __USE_CRTIMP
#      define _CRTIMP  __attribute__ ((__dllimport__))
#    else
#      define _CRTIMP
#    endif
#  endif
#  define __DECLSPEC_SUPPORTED
# else /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
#  ifndef _CRTIMP
#   define _CRTIMP
#  endif
# endif /* __declspec */
#endif /* __GNUC__ */

#if defined (__GNUC__) && defined (__GNUC_MINOR__)
#define __MINGW_GNUC_PREREQ(major, minor) \
  (__GNUC__ > (major) \
   || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#else
#define __MINGW_GNUC_PREREQ(major, minor)  0
#endif

#define USE___UUIDOF	0

#ifdef __cplusplus
# define __CRT_INLINE inline
#else
# if ( __MINGW_GNUC_PREREQ(4, 3)  &&  __STDC_VERSION__ >= 199901L)
#  define __CRT_INLINE extern inline __attribute__((__gnu_inline__))
# else
#  define __CRT_INLINE extern __inline__
# endif
#endif

#ifdef __NO_INLINE__
#undef __CRT__NO_INLINE
#define __CRT__NO_INLINE 1
#endif

#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else
# ifdef __GNUC__
#  define __UNUSED_PARAM(x) x __attribute__ ((__unused__))
# else
#  define __UNUSED_PARAM(x) x
# endif
#endif

#ifdef __GNUC__
#define __MINGW_ATTRIB_NORETURN __attribute__ ((__noreturn__))
#define __MINGW_ATTRIB_CONST __attribute__ ((__const__))
#else
#define __MINGW_ATTRIB_NORETURN
#define __MINGW_ATTRIB_CONST
#endif

#if __MINGW_GNUC_PREREQ (3, 0)
#define __MINGW_ATTRIB_MALLOC __attribute__ ((__malloc__))
#define __MINGW_ATTRIB_PURE __attribute__ ((__pure__))
#else
#define __MINGW_ATTRIB_MALLOC
#define __MINGW_ATTRIB_PURE
#endif

/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
#if  __MINGW_GNUC_PREREQ (3, 3)
#define __MINGW_ATTRIB_NONNULL(arg) __attribute__ ((__nonnull__ (arg)))
#else
#define __MINGW_ATTRIB_NONNULL(arg)
#endif /* GNUC >= 3.3 */

#if  __MINGW_GNUC_PREREQ (3, 1)
#define __MINGW_ATTRIB_DEPRECATED __attribute__ ((__deprecated__))
#else
#define __MINGW_ATTRIB_DEPRECATED
#endif /* GNUC >= 3.1 */

#if  __MINGW_GNUC_PREREQ (3, 3)
#define __MINGW_NOTHROW __attribute__ ((__nothrow__))
#else
#define __MINGW_NOTHROW
#endif

#if __MINGW_GNUC_PREREQ (4, 4)
#define __MINGW_ATTRIB_NO_OPTIMIZE __attribute__((__optimize__ ("0")))
#else
#define __MINGW_ATTRIB_NO_OPTIMIZE
#endif

#ifndef __MSVCRT_VERSION__
/*  High byte is the major version, low byte is the minor. */
# define __MSVCRT_VERSION__ 0x0700
#endif


#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x502
#endif

#ifndef _INT128_DEFINED
#define _INT128_DEFINED
#ifdef __GNUC__
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#ifdef _WIN64
typedef int __int128 __attribute__ ((__mode__ (TI)));
#endif
#endif /* __GNUC__ */
#endif /* _INT128_DEFINED */

#ifdef __GNUC__
#define __ptr32
#define __ptr64
#ifndef __unaligned
/* gcc can not handle packed on base types, so
 * this is an empty define. */
#define __unaligned /* __attribute ((packed)) */
#endif
#define __forceinline __inline__ __attribute__((always_inline))
#endif /* __GNUC__ */

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#ifndef __nothrow
#ifdef __cplusplus
#define __nothrow __declspec(nothrow)
#else
#define __nothrow
#endif
#endif /* __nothrow */

#undef _CRT_PACKING
#define _CRT_PACKING 8

#pragma pack(push,_CRT_PACKING)

#include <vadefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRT_STRINGIZE
#define __CRT_STRINGIZE(_Value) #_Value
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif /* _CRT_STRINGIZE */

#ifndef _CRT_WIDE
#define __CRT_WIDE(_String) L ## _String
#define _CRT_WIDE(_String) __CRT_WIDE(_String)
#endif /* _CRT_WIDE */

#ifndef _W64
#define _W64
#endif

#ifndef _CRTIMP_NOIA64
#ifdef __ia64__
#define _CRTIMP_NOIA64
#else
#define _CRTIMP_NOIA64 _CRTIMP
#endif
#endif /* _CRTIMP_NOIA64 */

#ifndef _CRTIMP2
#define _CRTIMP2 _CRTIMP
#endif

#ifndef _CRTIMP_ALTERNATIVE
#define _CRTIMP_ALTERNATIVE _CRTIMP
#define _CRT_ALTERNATIVE_IMPORTED
#endif /* _CRTIMP_ALTERNATIVE */

#ifndef _MRTIMP2
#define _MRTIMP2  _CRTIMP
#endif

/* We have to define _DLL for gcc based mingw version. This define is set
   by VC, when DLL-based runtime is used. So, gcc based runtime just have
   DLL-base runtime, therefore this define has to be set.
   As our headers are possibly used by windows compiler having a static
   C-runtime, we make this definition gnu compiler specific here.  */
#if !defined (_DLL) && defined (__GNUC__)
#define _DLL
#endif

#ifndef _MT
#define _MT
#endif

#ifndef _MCRTIMP
#define _MCRTIMP _CRTIMP
#endif

#ifndef _CRTIMP_PURE
#define _CRTIMP_PURE _CRTIMP
#endif

#ifndef _PGLOBAL
#define _PGLOBAL
#endif

#ifndef _AGLOBAL
#define _AGLOBAL
#endif

#define __STDC_SECURE_LIB__ 200411L
#define __GOT_SECURE_LIB__ __STDC_SECURE_LIB__
#define _SECURECRT_FILL_BUFFER_PATTERN 0xFD
#define _CRT_DEPRECATE_TEXT(_Text) __declspec(deprecated)

#ifndef _CRT_INSECURE_DEPRECATE_MEMORY
#define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement)
#endif

#ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
#define _CRT_INSECURE_DEPRECATE_GLOBALS(_Replacement)
#endif

#ifndef _CRT_MANAGED_HEAP_DEPRECATE
#define _CRT_MANAGED_HEAP_DEPRECATE
#endif

#ifndef _CRT_OBSOLETE
#define _CRT_OBSOLETE(_NewItem)
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef size_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 size_t;
#else
  typedef unsigned int size_t;
#endif /* _WIN64 */
#endif /* _SIZE_T_DEFINED */

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ssize_t;
#else
  typedef int ssize_t;
#endif /* _WIN64 */
#endif /* _SSIZE_T_DEFINED */

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifndef __intptr_t_defined
#define __intptr_t_defined
#undef intptr_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 intptr_t;
#else
  typedef int intptr_t;
#endif /* _WIN64 */
#endif /* __intptr_t_defined */
#endif /* _INTPTR_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifndef __uintptr_t_defined
#define __uintptr_t_defined
#undef uintptr_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef unsigned __int64 uintptr_t;
#else
  typedef unsigned int uintptr_t;
#endif /* _WIN64 */
#endif /* __uintptr_t_defined */
#endif /* _UINTPTR_T_DEFINED */

#ifndef _PTRDIFF_T_DEFINED
#define _PTRDIFF_T_DEFINED
#ifndef _PTRDIFF_T_
#undef ptrdiff_t
#ifdef _WIN64
  __MINGW_EXTENSION typedef __int64 ptrdiff_t;
#else
  typedef int ptrdiff_t;
#endif /* _WIN64 */
#endif /* _PTRDIFF_T_ */
#endif /* _PTRDIFF_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
#ifndef __cplusplus
  typedef unsigned short wchar_t;
#endif
#endif /* _WCHAR_T_DEFINED */

#ifndef _WCTYPE_T_DEFINED
#define _WCTYPE_T_DEFINED
#ifndef __WINT_TYPE__
/* wint_t is unsigned short for compatibility with MS runtime */
#define __WINT_TYPE__ unsigned short
#endif /* __WINT_TYPE__ */
#ifndef _WINT_T
#define _WINT_T
  typedef unsigned short wint_t;
  typedef unsigned short wctype_t;
#endif /* _WINT_T */
#endif /* _WCTYPE_T_DEFINED */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  typedef __gnuc_va_list va_list;
#endif /* _VA_LIST_DEFINED */

#if defined (_WIN32) && !defined (_WIN64) && !defined (__MINGW_USE_VC2005_COMPAT)
#ifndef _USE_32BIT_TIME_T
#define _USE_32BIT_TIME_T
#endif
#endif

#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#error You cannot use 32-bit time_t (_USE_32BIT_TIME_T) with _WIN64
#undef _USE_32BIT_TIME_T
#endif
#endif /* _USE_32BIT_TIME_T */

#ifndef _ERRCODE_DEFINED
#define _ERRCODE_DEFINED
  typedef int errno_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
  __MINGW_EXTENSION typedef __int64 __time64_t;
#endif /* _TIME64_T_DEFINED */

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else
  typedef __time64_t time_t;
#endif
#endif /* _TIME_T_DEFINED */

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#ifndef __CRT_UNALIGNED
#define __CRT_UNALIGNED
#endif

#ifndef UNALIGNED
#if defined(__ia64__) || defined(__x86_64)
#define UNALIGNED __CRT_UNALIGNED
#else
#define UNALIGNED
#endif
#endif /* UNALIGNED */

#ifndef _CRT_ALIGN
#define _CRT_ALIGN(x) __attribute__ ((__aligned__ (x)))
#endif

#ifndef __CRTDECL
#define __CRTDECL __cdecl
#endif

#define _ARGMAX 100

#ifndef _TRUNCATE
#define _TRUNCATE ((size_t)-1)
#endif
  struct threadlocaleinfostruct;
  struct threadmbcinfostruct;
  typedef struct threadlocaleinfostruct *pthreadlocinfo;
  typedef struct threadmbcinfostruct *pthreadmbcinfo;
  struct __lc_time_data;

  typedef struct localeinfo_struct {
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
  } _locale_tstruct,*_locale_t;

#ifndef _TAGLC_ID_DEFINED
#define _TAGLC_ID_DEFINED
  typedef struct tagLC_ID {
    unsigned short wLanguage;
    unsigned short wCountry;
    unsigned short wCodePage;
  } LC_ID,*LPLC_ID;
#endif /* _TAGLC_ID_DEFINED */

#ifndef _THREADLOCALEINFO
#define _THREADLOCALEINFO
  typedef struct threadlocaleinfostruct {
    int refcount;
    unsigned int lc_codepage;
    unsigned int lc_collate_cp;
    unsigned long lc_handle[6];
    LC_ID lc_id[6];
    struct {
      char *locale;
      wchar_t *wlocale;
      int *refcount;
      int *wrefcount;
    } lc_category[6];
    int lc_clike;
    int mb_cur_max;
    int *lconv_intl_refcount;
    int *lconv_num_refcount;
    int *lconv_mon_refcount;
    struct lconv *lconv;
    int *ctype1_refcount;
    unsigned short *ctype1;
    const unsigned short *pctype;
    const unsigned char *pclmap;
    const unsigned char *pcumap;
    struct __lc_time_data *lc_time_curr;
  } threadlocinfo;
#endif /* _THREADLOCALEINFO */

#ifdef __cplusplus
}
#endif

#ifndef _CRT_UNUSED
#define _CRT_UNUSED(x) (void)x
#endif

#pragma pack(pop)

/* _dowildcard is an int that controls the globbing of the command line.
 * The MinGW32 (mingw.org) runtime calls it _CRT_glob, so we are adding
 * a compatibility definition here:  you can use either of _CRT_glob or
 * _dowildcard .
 * If _dowildcard is non-zero, the command line will be globbed:  *.*
 * will be expanded to be all files in the startup directory.
 * In the mingw-w64 library a _dowildcard variable is defined as being
 * 0, therefore command line globbing is DISABLED by default. To turn it
 * on and to leave wildcard command line processing MS's globbing code,
 * include a line in one of your source modules defining _dowildcard and
 * setting it to -1, like so:
 * int _dowildcard = -1;
 */
#undef  _CRT_glob
#define _CRT_glob _dowildcard

#ifndef DUMMYUNIONNAME
# ifdef NONAMELESSUNION
#  define DUMMYUNIONNAME  u
#  define DUMMYUNIONNAME1 u1
#  define DUMMYUNIONNAME2 u2
#  define DUMMYUNIONNAME3 u3
#  define DUMMYUNIONNAME4 u4
#  define DUMMYUNIONNAME5 u5
# else /* NONAMELESSUNION */
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
# endif
#endif	/* DUMMYUNIONNAME */

#ifndef DUMMYSTRUCTNAME
# ifdef NONAMELESSSTRUCT
#  define DUMMYSTRUCTNAME s
# else
#  define DUMMYSTRUCTNAME
# endif
#endif /* DUMMYSTRUCTNAME */

#endif /* _INC_CRTDEFS */

#ifndef MINGW_SDK_INIT
#define MINGW_SDK_INIT

#include "sdks/_mingw_directx.h"

#endif /* MINGW_SDK_INIT */
