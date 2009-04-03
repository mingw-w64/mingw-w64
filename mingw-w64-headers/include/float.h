/* 
 * float.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * Constants related to floating point arithmetic.
 *
 * Also included here are some non-ANSI bits for accessing the floating
 * point controller.
 *
 * NOTE: GCC provides float.h, but it doesn't include the non-standard
 *       stuff for accessing the fp controller. We include_next the
 *       GCC-supplied header and just define the MS-specific extensions
 *       here.     
 *
 */
#ifndef _FLOAT_H___
#define _FLOAT_H___

#undef FLT_RADIX
#undef FLT_MANT_DIG
#undef DBL_MANT_DIG
#undef LDBL_MANT_DIG
#undef FLT_DIG
#undef DBL_DIG
#undef LDBL_DIG
#undef FLT_MIN_EXP
#undef DBL_MIN_EXP
#undef LDBL_MIN_EXP
#undef FLT_MIN_10_EXP
#undef DBL_MIN_10_EXP
#undef LDBL_MIN_10_EXP
#undef FLT_MAX_EXP
#undef DBL_MAX_EXP
#undef LDBL_MAX_EXP
#undef FLT_MAX_10_EXP
#undef DBL_MAX_10_EXP
#undef LDBL_MAX_10_EXP
#undef FLT_MAX
#undef DBL_MAX
#undef LDBL_MAX
#undef FLT_EPSILON
#undef DBL_EPSILON
#undef LDBL_EPSILON
#undef FLT_MIN
#undef DBL_MIN
#undef LDBL_MIN

#undef FLT_ROUNDS

#define FLT_RADIX	__FLT_RADIX__
#define FLT_MANT_DIG	__FLT_MANT_DIG__
#define DBL_MANT_DIG	__DBL_MANT_DIG__
#define LDBL_MANT_DIG	__LDBL_MANT_DIG__
#define FLT_DIG		__FLT_DIG__
#define DBL_DIG		__DBL_DIG__
#define LDBL_DIG	__LDBL_DIG__
#define FLT_MIN_EXP	__FLT_MIN_EXP__
#define DBL_MIN_EXP	__DBL_MIN_EXP__
#define LDBL_MIN_EXP	__LDBL_MIN_EXP__
#define FLT_MIN_10_EXP	__FLT_MIN_10_EXP__
#define DBL_MIN_10_EXP	__DBL_MIN_10_EXP__
#define LDBL_MIN_10_EXP	__LDBL_MIN_10_EXP__
#define FLT_MAX_EXP	__FLT_MAX_EXP__
#define DBL_MAX_EXP	__DBL_MAX_EXP__
#define LDBL_MAX_EXP	__LDBL_MAX_EXP__
#define FLT_MAX_10_EXP	__FLT_MAX_10_EXP__
#define DBL_MAX_10_EXP	__DBL_MAX_10_EXP__
#define LDBL_MAX_10_EXP	__LDBL_MAX_10_EXP__
#define FLT_MAX		__FLT_MAX__
#define DBL_MAX		__DBL_MAX__
#define LDBL_MAX	__LDBL_MAX__
#define FLT_EPSILON	__FLT_EPSILON__
#define DBL_EPSILON	__DBL_EPSILON__
#define LDBL_EPSILON	__LDBL_EPSILON__
#define FLT_MIN		__FLT_MIN__
#define DBL_MIN		__DBL_MIN__
#define LDBL_MIN	__LDBL_MIN__

#define FLT_ROUNDS 1

/* C99 specific defines.  */
#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L

#undef FLT_EVAL_METHOD
#undef DECIMAL_DIG

#define FLT_EVAL_METHOD	__FLT_EVAL_METHOD__
#define DECIMAL_DIG	__DECIMAL_DIG__

#endif

/* TODO: Decimal floating point stuff.  */
#ifdef __STDC_WANT_DEC_FP__

#undef DEC32_MANT_DIG
#undef DEC64_MANT_DIG
#undef DEC128_MANT_DIG
#undef DEC32_MIN_EXP
#undef DEC64_MIN_EXP
#undef DEC128_MIN_EXP
#undef DEC32_MAX_EXP
#undef DEC64_MAX_EXP
#undef DEC128_MAX_EXP
#undef DEC32_MAX
#undef DEC64_MAX
#undef DEC128_MAX
#undef DEC32_EPSILON
#undef DEC64_EPSILON
#undef DEC128_EPSILON
#undef DEC32_MIN
#undef DEC64_MIN
#undef DEC128_MIN
#undef DEC32_SUBNORMAL_MIN
#undef DEC64_SUBNORMAL_MIN
#undef DEC128_SUBNORMAL_MIN
#undef DEC_EVAL_METHOD

#define DEC32_MANT_DIG	__DEC32_MANT_DIG__
#define DEC64_MANT_DIG	__DEC64_MANT_DIG__
#define DEC128_MANT_DIG	__DEC128_MANT_DIG__
#define DEC32_MIN_EXP	__DEC32_MIN_EXP__
#define DEC64_MIN_EXP	__DEC64_MIN_EXP__
#define DEC128_MIN_EXP	__DEC128_MIN_EXP__
#define DEC32_MAX_EXP	__DEC32_MAX_EXP__
#define DEC64_MAX_EXP	__DEC64_MAX_EXP__
#define DEC128_MAX_EXP	__DEC128_MAX_EXP__
#define DEC32_MAX       __DEC32_MAX__
#define DEC64_MAX	__DEC64_MAX__
#define DEC128_MAX	__DEC128_MAX__
#define DEC32_EPSILON	__DEC32_EPSILON__
#define DEC64_EPSILON	__DEC64_EPSILON__
#define DEC128_EPSILON	__DEC128_EPSILON__
#define DEC32_MIN	__DEC32_MIN__
#define DEC64_MIN	__DEC64_MIN__
#define DEC128_MIN	__DEC128_MIN__

#define DEC32_SUBNORMAL_MIN   __DEC32_SUBNORMAL_MIN__
#define DEC64_SUBNORMAL_MIN   __DEC64_SUBNORMAL_MIN__
#define DEC128_SUBNORMAL_MIN  __DEC128_SUBNORMAL_MIN__
#define DEC_EVAL_METHOD	      __DEC_EVAL_METHOD__

#endif

#endif

#ifndef _MINGW_FLOAT_H_
#define _MINGW_FLOAT_H_

/* All the headers include this file. */
#include <_mingw.h>

/*
 * Functions and definitions for controlling the FPU.
 */
#ifndef	__STRICT_ANSI__

/* TODO: These constants are only valid for x86 machines */

/* Control word masks for unMask */
#define	_MCW_DN  	0x03000000  	/* Denormal control */
#define	_MCW_EM		0x0008001F	/* Error masks */
#define	_MCW_IC		0x00040000	/* Infinity */
#define	_MCW_RC		0x00000300	/* Rounding */
#define	_MCW_PC		0x00030000	/* Precision */

/* Control word values for unNew (use with related unMask above) */
#define	_DN_SAVE	0x00000000
#define	_DN_FLUSH	0x01000000
#define	_EM_INVALID	0x00000010
#define	_EM_DENORMAL	0x00080000
#define	_EM_ZERODIVIDE	0x00000008
#define	_EM_OVERFLOW	0x00000004
#define	_EM_UNDERFLOW	0x00000002
#define	_EM_INEXACT	0x00000001
#define	_IC_AFFINE	0x00040000
#define	_IC_PROJECTIVE	0x00000000
#define	_RC_CHOP	0x00000300
#define	_RC_UP		0x00000200
#define	_RC_DOWN	0x00000100
#define	_RC_NEAR	0x00000000
#define	_PC_24		0x00020000
#define	_PC_53		0x00010000
#define	_PC_64		0x00000000

/* These are also defined in Mingw math.h, needed to work around
   GCC build issues.  */
/* Return values for fpclass. */
#ifndef __MINGW_FPCLASS_DEFINED
#define __MINGW_FPCLASS_DEFINED 1
#define	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#define	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#define	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#define	_FPCLASS_NN	0x0008	/* Negative Normal */
#define	_FPCLASS_ND	0x0010	/* Negative Denormal */
#define	_FPCLASS_NZ	0x0020	/* Negative Zero */
#define	_FPCLASS_PZ	0x0040	/* Positive Zero */
#define	_FPCLASS_PD	0x0080	/* Positive Denormal */
#define	_FPCLASS_PN	0x0100	/* Positive Normal */
#define	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#endif /* __MINGW_FPCLASS_DEFINED */

/* invalid subconditions (_SW_INVALID also set) */
#define _SW_UNEMULATED		0x0040  /* unemulated instruction */
#define _SW_SQRTNEG		0x0080  /* square root of a neg number */
#define _SW_STACKOVERFLOW	0x0200  /* FP stack overflow */
#define _SW_STACKUNDERFLOW	0x0400  /* FP stack underflow */

/*  Floating point error signals and return codes */
#define _FPE_INVALID		0x81
#define _FPE_DENORMAL		0x82
#define _FPE_ZERODIVIDE		0x83
#define _FPE_OVERFLOW		0x84
#define _FPE_UNDERFLOW		0x85
#define _FPE_INEXACT		0x86
#define _FPE_UNEMULATED		0x87
#define _FPE_SQRTNEG		0x88
#define _FPE_STACKOVERFLOW	0x8a
#define _FPE_STACKUNDERFLOW	0x8b
#define _FPE_EXPLICITGEN	0x8c    /* raise( SIGFPE ); */

#ifndef RC_INVOKED

#ifdef	__cplusplus
extern "C" {
#endif

/* Set the FPU control word as cw = (cw & ~unMask) | (unNew & unMask),
 * i.e. change the bits in unMask to have the values they have in unNew,
 * leaving other bits unchanged. */
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _controlfp (unsigned int unNew, unsigned int unMask);
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _control87 (unsigned int unNew, unsigned int unMask);


_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _clearfp (void);	/* Clear the FPU status word */
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _statusfp (void);	/* Report the FPU status word */
#define		_clear87	_clearfp
#define		_status87	_statusfp


/*
   MSVCRT.dll _fpreset initializes the control register to 0x27f,
   the status register to zero and the tag word to 0FFFFh.
   This differs from asm instruction finit/fninit which set control
   word to 0x37f (64 bit mantissa precison rather than 53 bit).
   By default, the mingw version of _fpreset sets fp control as
   per fninit. To use the MSVCRT.dll _fpreset, include CRT_fp8.o when
   building your application.	 
*/
void __cdecl __MINGW_NOTHROW _fpreset (void);
void __cdecl __MINGW_NOTHROW fpreset (void);

/* Global 'variable' for the current floating point error code. */
_CRTIMP int * __cdecl __MINGW_NOTHROW __fpecode(void);
#define	_fpecode	(*(__fpecode()))

/*
 * IEEE recommended functions.  MS puts them in float.h
 * but they really belong in math.h.
 */

#ifndef _SIGN_DEFINED
#define _SIGN_DEFINED
  _CRTIMP double __cdecl __MINGW_NOTHROW _chgsign (double _X);
  _CRTIMP double __cdecl __MINGW_NOTHROW _copysign (double _Number,double _Sign);
  _CRTIMP double __cdecl __MINGW_NOTHROW _logb (double);
  _CRTIMP double __cdecl __MINGW_NOTHROW _nextafter (double, double);
  _CRTIMP double __cdecl __MINGW_NOTHROW _scalb (double, long);
 
  _CRTIMP int __cdecl __MINGW_NOTHROW _finite (double);
  _CRTIMP int __cdecl __MINGW_NOTHROW _fpclass (double);
  _CRTIMP int __cdecl __MINGW_NOTHROW _isnan (double);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not __STRICT_ANSI__ */

#endif /* _MINGW_FLOAT_H_ */

 	  	 
