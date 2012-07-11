/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_CRTDEFS
#define _INC_CRTDEFS

#include <_mingw.h>

#ifdef __ERRCODE_DEFINED_MS
/* #define __ERRCODE_DEFINED_MS */
typedef int errcode;
#endif

#ifndef _CRTNOALIAS
#define _CRTNOALIAS
#endif

#ifndef _CRTRESTRICT
#define _CRTRESTRICT
#endif

#ifndef _RSIZE_T_DEFINED
typedef size_t rsize_t;
#define _RSIZE_T_DEFINED
#endif

#if defined(__cplusplus) && _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(__ret,__func,__dsttype,__dst) \
  extern "C++" { \
    template <size_t __size> \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size]) { \
        return __func(__dst,__size); \
    } \
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(__ret,__func,__dsttype,__dst,__type1,__arg1) \
  extern "C++" {\
    template <size_t __size> \
    inline __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1) { \
        return __func(__dst,__size,__arg1);  \
    }\
  }

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(__ret,__func,__dsttype,__dst,__type1,__arg1,__type2,__arg2)\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(__dsttype (&__dst)[__size], __type1 __arg1, __type2 __arg2) { \
        return __func(__dst,__size,__arg1,__arg2);  \
    }\
  }

#else

#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_0(__ret,__func,__dsttype,__dst)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_1(__ret,__func,__dsttype,__dst,__type1,__arg1)
#define __DEFINE_CPP_OVERLOAD_SECURE_FUNC_0_2(__ret,__func,__dsttype,__dst,__type1,__arg1,__type2,__arg2)

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

#ifndef __crt_typefix
#define __crt_typefix(ctype)
#endif

#endif /* _INC_CRTDEFS */
