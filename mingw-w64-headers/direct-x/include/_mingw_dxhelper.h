/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef DUMMYUNIONNAME
# ifdef NONAMELESSUNION
#  define DUMMYUNIONNAME  u
#  define DUMMYUNIONNAME1 u1
#  define DUMMYUNIONNAME2 u2
#  define DUMMYUNIONNAME3 u3
#  define DUMMYUNIONNAME4 u4
#  define DUMMYUNIONNAME5 u5
#  define DUMMYUNIONNAMEX(X) u##X
# else /* NONAMELESSUNION */
#  define DUMMYUNIONNAME
#  define DUMMYUNIONNAME1
#  define DUMMYUNIONNAME2
#  define DUMMYUNIONNAME3
#  define DUMMYUNIONNAME4
#  define DUMMYUNIONNAME5
#  define DUMMYUNIONNAMEX(X)
# endif
#endif	/* DUMMYUNIONNAME */

#ifndef DUMMYSTRUCTNAME
# ifdef NONAMELESSSTRUCT
#  define DUMMYSTRUCTNAME s
#  define DUMMYSTRUCTNAME1 s1
#  define DUMMYSTRUCTNAME2 s2
#  define DUMMYSTRUCTNAME3 s3
#  define DUMMYSTRUCTNAME4 s4
#  define DUMMYSTRUCTNAME5 s5
#  define DUMMYSTRUCTNAMEX(X) s##X
# else
#  define DUMMYSTRUCTNAME
#  define DUMMYSTRUCTNAME1
#  define DUMMYSTRUCTNAME2
#  define DUMMYSTRUCTNAME3
#  define DUMMYSTRUCTNAME4
#  define DUMMYSTRUCTNAME5
#  define DUMMYSTRUCTNAMEX(X)
# endif
#endif /* DUMMYSTRUCTNAME */

/* These are for compatibility with the Wine source tree */

#ifndef WINELIB_NAME_AW
# ifdef __MINGW_NAME_AW
#   define WINELIB_NAME_AW  __MINGW_NAME_AW
# else
#  ifdef UNICODE
#   define WINELIB_NAME_AW(func) func##W
#  else
#   define WINELIB_NAME_AW(func) func##A
#  endif
# endif
#endif	/* WINELIB_NAME_AW */

#ifndef DECL_WINELIB_TYPE_AW
# ifdef __MINGW_TYPEDEF_AW
#  define DECL_WINELIB_TYPE_AW  __MINGW_TYPEDEF_AW
# else
#  define DECL_WINELIB_TYPE_AW(type)  typedef WINELIB_NAME_AW(type) type;
# endif
#endif	/* DECL_WINELIB_TYPE_AW */

