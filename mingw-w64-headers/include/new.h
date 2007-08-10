/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_NEW
#define _INC_NEW

#ifdef __cplusplus

#include <new>

#include <_mingw.h>

#pragma push_macro("new")
#undef new

#ifndef __NOTHROW_T_DEFINED
#define __NOTHROW_T_DEFINED
namespace std {

  struct nothrow_t {};

  extern const nothrow_t nothrow;
};

void *__cdecl operator new(size_t _Size,const std::nothrow_t&) throw();
void *__cdecl operator new[](size_t _Size,const std::nothrow_t&) throw();
void __cdecl operator delete(void *,const std::nothrow_t&) throw();
void __cdecl operator delete[](void *,const std::nothrow_t&) throw();
#endif

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
inline void *__cdecl operator new(size_t,void *_Where) { return (_Where); }
inline void __cdecl operator delete(void *,void *) { return; }
#endif

_CRTIMP int __cdecl _query_new_mode(void);
_CRTIMP int __cdecl _set_new_mode(int _NewMode);

#ifndef _PNH_DEFINED
typedef int (__cdecl *_PNH)(size_t);
#define _PNH_DEFINED
#endif

_CRTIMP _PNH __cdecl _query_new_handler(void);
_CRTIMP _PNH __cdecl _set_new_handler(_PNH _NewHandler);

#ifndef _NO_ANSI_NH_DEFINED
#define _NO_ANSI_NEW_HANDLER ((new_handler)-1)
#define _NO_ANSI_NEW_HANDLER_M ((_new_handler_m)-1)
#define _NO_ANSI_NH_DEFINED
#endif

#pragma pop_macro("new")
#endif
#endif
