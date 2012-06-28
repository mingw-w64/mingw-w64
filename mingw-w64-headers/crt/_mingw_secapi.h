/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
 
#ifndef _INC_MINGW_SECAPI
#define _INC_MINGW_SECAPI

/* http://msdn.microsoft.com/en-us/library/ms175759%28v=VS.100%29.aspx */
#if defined(__cplusplus) && (MINGW_HAS_SECURE_API == 1)
#ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1         /* default to 1 */
#endif /*_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES*/
#ifndef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY 0  /* default to 0 */
#endif /*_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY*/
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 0       /* default to 0 */
#endif /* _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES */
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 0 /* default to 0 */
#endif /* _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT */
#ifndef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0 /* default to 0 */
#endif /* _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY */
#else
/* Templates won't work in C, will break if secure API is not enabled, disabled */
#undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES
#undef _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT
#undef _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 0
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY 0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 0
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY 0
#endif /*defined(__cplusplus) && (MINGW_HAS_SECURE_API == 1)*/

#define __MINGW_CRT_NAME_CONCAT1(sym) ::sym
#define __MINGW_CRT_NAME_CONCAT2(sym) ::sym##_s
#define __MINGW_CRT_NAME_INSECURE(sym) ::__insecure__##sym
#define __MINGW_CRT_NAME_INSECURE_DEF(sym) __insecure__##sym

#ifdef __cplusplus
extern "C++" {
template <bool __test, typename __dsttype>
  struct __if_array;
template <typename __dsttype>
  struct __if_array <true, __dsttype> {
    typedef __dsttype __type;
};
}
#endif /*__cplusplus*/

#if (_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES == 1)
#define __CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_0_2_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  extern "C" { _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3); }\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(\
    __type1 (&__arg1)[__size],\
    __type3 __attrib3 (__arg3)) {\
      return __MINGW_CRT_NAME_CONCAT1(__func)(__arg1,__size,__arg3);\
    }\
  }
#else
#define __CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_0_2_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3);
#endif /*_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES*/

#if (_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY == 1)
#define __CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3,__type4,__attrib4,__arg4)\
  extern "C" { _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3, __type4 __attrib4 __arg4); }\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(\
    __type1 (&__arg1)[__size],\
    __type3 __attrib3 (__arg3),\
    __type4 __attrib4 (__arg4)) {\
      return __MINGW_CRT_NAME_CONCAT1(__func)(__arg1,__size,__arg3,__arg4);\
    }\
  }
#else
#define __CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3,__type4,__attrib4,__arg4)\
  _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3, __type4 __attrib4 __arg4);
#endif /*_CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES_MEMORY*/

#if (_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES == 1)
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_0_2_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2)\
  extern "C" {\
    inline __ret __cdecl __MINGW_CRT_NAME_INSECURE_DEF(__func)(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2){\
      _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2);\
      return __func(__arg1,__arg2);\
    }\
  }\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(\
    __type1 (&__arg1)[__size],\
    __type2 (__arg2)) {\
      return __MINGW_CRT_NAME_CONCAT2(__func) (__arg1,__size,__arg2) == 0 ? __arg1 : NULL;\
    }\
    template <typename __t1> inline \
    __t1 __cdecl __func(\
    __t1 __attrib1 (__arg1),\
    __type2 __attrib2 (__arg2)) {\
      return __MINGW_CRT_NAME_INSECURE(__func)(__arg1,__arg2);\
    }\
  }
#else
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_0_2_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2)\
  _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif /*_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES*/

/*
  The macro _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT requires that _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES
  is also defined as 1. If _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT is defined as 1 and
  _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES is defined as 0, the application will not perform any template overloads.
*/
/* Fallback on insecure mode if not possible to know destination size at compile time, NULL is appended for strncpy */
#if (_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT == 1) && (_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES == 1)
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  extern "C" {\
    inline __ret __cdecl __MINGW_CRT_NAME_INSECURE_DEF(__func)(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3){\
      _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3);\
      return __func(__arg1,__arg2,__arg3);\
    }\
  }\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(\
    __type1 (&__arg1)[__size],\
    __type2 __attrib2 (__arg2),\
    __type3 __attrib3 (__arg3)) {\
      return __MINGW_CRT_NAME_CONCAT2(__func) (__arg1,__size,__arg2,__arg3) == 0 ? __arg1 : NULL;\
    }\
    template <typename __t1> inline \
    __ret __cdecl __func(\
    __t1 (__arg1),\
    __type2 __attrib2 (__arg2),\
    __type3 __attrib3 (__arg3)) {\
      return __MINGW_CRT_NAME_INSECURE(__func) (__arg1,__arg2,__arg3);\
    }\
  }

/* For *_l locale types */
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT_1_4_(__ret,__imp_attrib,__func,__real_func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3,__type4,__attrib4,__arg4)\
  extern "C" {\
    inline __ret __cdecl __MINGW_CRT_NAME_INSECURE_DEF(__func)(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3, __type4 __attrib4 __arg4){\
      __imp_attrib __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3, __type4 __attrib4 __arg4);\
      return __func(__arg1,__arg2,__arg3,__arg4);\
    }\
  }\
  extern "C++" {\
    template <size_t __size> inline\
    __ret __cdecl __func(\
    __type1 (&__arg1)[__size],\
    __type2 __attrib2 (__arg2),\
    __type3 __attrib3 (__arg3),\
    __type4 __attrib4 (__arg4)) {\
      return __MINGW_CRT_NAME_CONCAT1(__real_func) (__arg1,__size,__arg2,__arg3,__arg4) == 0 ? __arg1 : NULL;\
    }\
    template <typename __t1> inline \
    __ret __cdecl __func(\
    __t1 (__arg1),\
    __type2 __attrib2 (__arg2),\
    __type3 __attrib3 (__arg3),\
    __type4 __attrib4 (__arg4)) {\
      return __MINGW_CRT_NAME_INSECURE(__func) (__arg1,__arg2,__arg3,__arg4);\
    }\
  }

#else
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT_1_4_(__ret,__imp_attrib,__func,__real_func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3,__type4,__attrib4,__arg4)\
  __imp_attrib __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3, __type4 __attrib4 __arg4) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

/* https://blogs.msdn.com/b/sdl/archive/2010/02/16/vc-2010-and-memcpy.aspx?Redirected=true */
/* fallback on default implementation if we can't know the size of the destination */
#if (_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY == 1)
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  extern "C" {_CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;}\
  extern "C++" {\
    template <size_t __size, typename __dsttype> inline\
    typename __if_array < (__size > 1), void * >::__type __cdecl __func(\
    __dsttype (&__arg1)[__size],\
    __type2 __attrib2 (__arg2),\
    __type3 __attrib3 (__arg3)) {\
      return __MINGW_CRT_NAME_CONCAT2(__func) (__arg1,__size * sizeof(__dsttype),__arg2,__arg3) == 0 ? __arg1 : NULL;\
    }\
  }
#else
#define __CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_MEMORY_0_3_(__ret,__func,__type1,__attrib1,__arg1,__type2,__attrib2,__arg2,__type3,__attrib3,__arg3)\
  _CRTIMP __ret __cdecl __func(__type1 * __attrib1 __arg1, __type2 __attrib2 __arg2, __type3 __attrib3 __arg3) __MINGW_ATTRIB_DEPRECATED_SEC_WARN;
#endif

#endif /*_INC_MINGW_SECAPI*/
