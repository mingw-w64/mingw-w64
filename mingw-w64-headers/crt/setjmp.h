/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

#if defined(__i386__)

#define _JBLEN 16
#define _JBTYPE int

  typedef struct __JUMP_BUFFER {
    unsigned long Ebp;
    unsigned long Ebx;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Esp;
    unsigned long Eip;
    unsigned long Registration;
    unsigned long TryLevel;
    /* Following fields are only for new _setjmp3(), the are not for old _setjmp(). */
    unsigned long Cookie; /* 0x56433230 */
    unsigned long UnwindFunc; /* void(__stdcall*)(const _JUMP_BUFFER *) */
    unsigned long UnwindData[6];
  } _JUMP_BUFFER;

#elif defined(__ia64__)

  typedef _CRT_ALIGN(16) struct _SETJMP_FLOAT128 {
    __MINGW_EXTENSION __int64 LowPart;
    __MINGW_EXTENSION __int64 HighPart;
  } SETJMP_FLOAT128;

#define _JBLEN 33
  typedef SETJMP_FLOAT128 _JBTYPE;

  typedef struct __JUMP_BUFFER {

    unsigned long iAReserved[6];

    unsigned long Registration;
    unsigned long TryLevel;
    unsigned long Cookie;
    unsigned long UnwindFunc;

    unsigned long UnwindData[6];

    SETJMP_FLOAT128 FltS0;
    SETJMP_FLOAT128 FltS1;
    SETJMP_FLOAT128 FltS2;
    SETJMP_FLOAT128 FltS3;
    SETJMP_FLOAT128 FltS4;
    SETJMP_FLOAT128 FltS5;
    SETJMP_FLOAT128 FltS6;
    SETJMP_FLOAT128 FltS7;
    SETJMP_FLOAT128 FltS8;
    SETJMP_FLOAT128 FltS9;
    SETJMP_FLOAT128 FltS10;
    SETJMP_FLOAT128 FltS11;
    SETJMP_FLOAT128 FltS12;
    SETJMP_FLOAT128 FltS13;
    SETJMP_FLOAT128 FltS14;
    SETJMP_FLOAT128 FltS15;
    SETJMP_FLOAT128 FltS16;
    SETJMP_FLOAT128 FltS17;
    SETJMP_FLOAT128 FltS18;
    SETJMP_FLOAT128 FltS19;
    __MINGW_EXTENSION __int64 FPSR;
    __MINGW_EXTENSION __int64 StIIP;
    __MINGW_EXTENSION __int64 BrS0;
    __MINGW_EXTENSION __int64 BrS1;
    __MINGW_EXTENSION __int64 BrS2;
    __MINGW_EXTENSION __int64 BrS3;
    __MINGW_EXTENSION __int64 BrS4;
    __MINGW_EXTENSION __int64 IntS0;
    __MINGW_EXTENSION __int64 IntS1;
    __MINGW_EXTENSION __int64 IntS2;
    __MINGW_EXTENSION __int64 IntS3;
    __MINGW_EXTENSION __int64 RsBSP;
    __MINGW_EXTENSION __int64 RsPFS;
    __MINGW_EXTENSION __int64 ApUNAT;
    __MINGW_EXTENSION __int64 ApLC;
    __MINGW_EXTENSION __int64 IntSp;
    __MINGW_EXTENSION __int64 IntNats;
    __MINGW_EXTENSION __int64 Preds;

  } _JUMP_BUFFER;

#elif defined(__x86_64__)

  typedef _CRT_ALIGN(16) struct _SETJMP_FLOAT128 {
    __MINGW_EXTENSION unsigned __int64 Part[2];
  } SETJMP_FLOAT128;

#define _JBLEN 16
  typedef SETJMP_FLOAT128 _JBTYPE;

  typedef struct _JUMP_BUFFER {
    __MINGW_EXTENSION unsigned __int64 Frame;
    __MINGW_EXTENSION unsigned __int64 Rbx;
    __MINGW_EXTENSION unsigned __int64 Rsp;
    __MINGW_EXTENSION unsigned __int64 Rbp;
    __MINGW_EXTENSION unsigned __int64 Rsi;
    __MINGW_EXTENSION unsigned __int64 Rdi;
    __MINGW_EXTENSION unsigned __int64 R12;
    __MINGW_EXTENSION unsigned __int64 R13;
    __MINGW_EXTENSION unsigned __int64 R14;
    __MINGW_EXTENSION unsigned __int64 R15;
    __MINGW_EXTENSION unsigned __int64 Rip;
    unsigned long MxCsr;
    unsigned short FpCsr;
    unsigned short Spare;
    SETJMP_FLOAT128 Xmm6;
    SETJMP_FLOAT128 Xmm7;
    SETJMP_FLOAT128 Xmm8;
    SETJMP_FLOAT128 Xmm9;
    SETJMP_FLOAT128 Xmm10;
    SETJMP_FLOAT128 Xmm11;
    SETJMP_FLOAT128 Xmm12;
    SETJMP_FLOAT128 Xmm13;
    SETJMP_FLOAT128 Xmm14;
    SETJMP_FLOAT128 Xmm15;
  } _JUMP_BUFFER;

#elif defined(_ARM_)

#define _JBLEN 28
#define _JBTYPE int

  typedef struct __JUMP_BUFFER {
    unsigned long Frame;
    unsigned long R4;
    unsigned long R5;
    unsigned long R6;
    unsigned long R7;
    unsigned long R8;
    unsigned long R9;
    unsigned long R10;
    unsigned long R11;
    unsigned long Sp;
    unsigned long Pc;
    unsigned long Fpscr;
    unsigned long long D[8];
  } _JUMP_BUFFER;

#elif defined(_ARM64_)

#define _JBLEN 24
#define _JBTYPE unsigned __int64

  typedef struct __JUMP_BUFFER {
    unsigned __int64 Frame;
    unsigned __int64 Reserved;
    unsigned __int64 X19;
    unsigned __int64 X20;
    unsigned __int64 X21;
    unsigned __int64 X22;
    unsigned __int64 X23;
    unsigned __int64 X24;
    unsigned __int64 X25;
    unsigned __int64 X26;
    unsigned __int64 X27;
    unsigned __int64 X28;
    unsigned __int64 Fp;
    unsigned __int64 Lr;
    unsigned __int64 Sp;
    unsigned long Fpcr;
    unsigned long Fpsr;
    double D[8];
  } _JUMP_BUFFER;

#else

#define _JBLEN 1
#define _JBTYPE int

#endif

#ifndef _JMP_BUF_DEFINED
  typedef _JBTYPE jmp_buf[_JBLEN];
#define _JMP_BUF_DEFINED
#endif

_CRTIMP __MINGW_ATTRIB_NORETURN __attribute__ ((__nothrow__)) void __cdecl longjmp(jmp_buf _Buf, int _Value); /* for setjmp.h and non-i386 setjmpex.h */
#ifdef __i386__
_CRTIMP __MINGW_ATTRIB_NORETURN __attribute__ ((__nothrow__)) void __cdecl _longjmpex(jmp_buf _Buf, int _Value); /* for i386 setjmpex.h */
#endif

#ifdef __i386__
_CRTIMP int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmp(jmp_buf _Buf); /* old i386 crtdll setjmp.h */
_CRTIMP int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmp3(jmp_buf _Buf, int _Count, ... /*void *_UnwindFunc, int _TryLevel, 6xDWORD _UnwindData...*/); /* new i386 msvcrt20+ setjmp.h and setjmpex.h */
#else
#ifndef __aarch64__
_CRTIMP int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmp(jmp_buf _Buf, void *_Frame); /* for non-i386 and non-aarch64 setjmp.h */
#endif
_CRTIMP int __cdecl __attribute__ ((__nothrow__,__returns_twice__)) _setjmpex(jmp_buf _Buf, void *_Frame); /* for non-i386 setjmpex.h and aarch64 setjmp.h */
#endif

#if defined(__i386__) || defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__)
__MINGW_ATTRIB_NORETURN __attribute__ ((__nothrow__)) void __cdecl __mingw_longjmp(jmp_buf _Buf, int _Value);
#endif

void * __cdecl __attribute__ ((__nothrow__)) mingw_getsp (void);

_CRT_END_C_HEADER

#endif /* _INC_SETJMP */

/*
 * Now outside of the _INC_SETJMP block, defines setjmp() and longjmp().
 * It allows '#include <setjmpex.h>' to override the existing setjmp() and longjmp() definitions.
 */

#ifdef setjmp
#  undef setjmp
#endif
#if defined(__i386__) /* i386 _setjmp and _setjmp3 functions always store SEH registration frame for unwind */
#  define setjmp(BUF) _setjmp3((BUF), 2, NULL /*UnwindFunc*/, -1 /*TryLevel*/)
#elif defined(__x86_64__) && !defined(__arm64ec__) /* amd64 requires current stack pointer address */
#  if defined(_INC_SETJMPEX)
#    if (defined(__GNUC__) && __GNUC__ >= 14) || (defined(__clang__) && __clang_major__ >= 22)
#      define setjmp(BUF) _setjmpex((BUF), __builtin_stack_address())
#    else
#      define setjmp(BUF) _setjmpex((BUF), mingw_getsp())
#    endif
#  elif defined(__SEH__) && !defined(__USE_MINGW_SETJMP_NON_SEH)
#    if (defined(__GNUC__) && __GNUC__ >= 14) || (defined(__clang__) && __clang_major__ >= 22)
#      define setjmp(BUF) _setjmp((BUF), __builtin_stack_address())
#    else
#      define setjmp(BUF) _setjmp((BUF), mingw_getsp())
#    endif
#  else
#    define setjmp(BUF) _setjmp((BUF), NULL)
#  endif
#elif defined(__arm__) || defined(__arm64ec__) /* arm32 and arm64ec require stack pointer address from the function entry point */
#  if defined(_INC_SETJMPEX)
#    define setjmp(BUF) _setjmpex((BUF), __builtin_sponentry())
#  elif defined(__SEH__) && !defined(__USE_MINGW_SETJMP_NON_SEH)
#    define setjmp(BUF) _setjmp((BUF), __builtin_sponentry())
#  else
#    define setjmp(BUF) _setjmp((BUF), NULL)
#  endif
#elif defined(__aarch64__) /* arm64 requires stack pointer address from the function entry point and arm64 does not have _setjmp function */
#  if defined(_INC_SETJMPEX) || (defined(__SEH__) && !defined(__USE_MINGW_SETJMP_NON_SEH))
#    define setjmp(BUF) _setjmpex((BUF), __builtin_sponentry())
#  else
#    define setjmp(BUF) _setjmpex((BUF), NULL)
#  endif
#else
#  error Unknown platform
#endif

#ifdef longjmp
#  undef longjmp
#endif
#if defined(__i386__) /* i386 longjmp function always uses SEH registration frame for unwind */
#  if defined(_INC_SETJMPEX)
#    define longjmp _longjmpex
#  elif !defined(__USE_MINGW_SETJMP_NON_SEH)
#    define longjmp longjmp
#  else
#    define longjmp __mingw_longjmp
#  endif
#elif defined(__x86_64__) && !defined(__arm64ec__) /* amd64 longjmp function uses SEH frame for unwind on demand only when is non-NULL */
#  define longjmp longjmp
#elif defined(__arm__) || defined(__aarch64__) || defined(__arm64ec__) /* arm32, arm64 and arm64ec longjmp functions always use SEH frame for unwind */
#  if defined(_INC_SETJMPEX) || (defined(__SEH__) && !defined(__USE_MINGW_SETJMP_NON_SEH))
#    define longjmp longjmp
#  else
#    define longjmp __mingw_longjmp
#  endif
#else
#  error Unknown platform
#endif
