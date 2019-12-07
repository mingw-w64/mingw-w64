/*
* ====================================================
* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
*
* Developed at SunPro, a Sun Microsystems, Inc. business.
* Permission to use, copy, modify, and distribute this
* software is freely granted, provided that this notice
* is preserved.
* ====================================================
*/

#include <inttypes.h>
#include <float.h>

typedef unsigned int u_int32_t;

typedef union
{
    double value;
    struct
    {
        u_int32_t lsw;
        u_int32_t msw;
    } parts;
} ieee_double_shape_type;

typedef union {
    float value;
    u_int32_t word;
} ieee_float_shape_type;

/* Get two 32 bit ints from a double.  */

#define EXTRACT_WORDS(ix0,ix1,d)    \
do {                                \
    ieee_double_shape_type ew_u;    \
    ew_u.value = (d);               \
    (ix0) = ew_u.parts.msw;         \
    (ix1) = ew_u.parts.lsw;         \
} while (0)

/* Get the most significant 32 bit int from a double.  */

#define GET_HIGH_WORD(i,d)          \
do {                                \
    ieee_double_shape_type gh_u;    \
    gh_u.value = (d);               \
    (i) = gh_u.parts.msw;           \
} while (0)

/* Get the less significant 32 bit int from a double.  */

#define GET_LOW_WORD(i,d)           \
do {                                \
    ieee_double_shape_type gl_u;    \
    gl_u.value = (d);               \
    (i) = gl_u.parts.lsw;           \
} while (0)

/* Set a double from two 32 bit ints.  */

#define INSERT_WORDS(d,ix0,ix1)     \
do {                                \
    ieee_double_shape_type iw_u;    \
    iw_u.parts.msw = (ix0);         \
    iw_u.parts.lsw = (ix1);         \
    (d) = iw_u.value;               \
} while (0)

/* Set the more significant 32 bits of a double from an int.  */

#define SET_HIGH_WORD(d,v)          \
do {                                \
    ieee_double_shape_type sh_u;    \
    sh_u.value = (d);               \
    sh_u.parts.msw = (v);           \
    (d) = sh_u.value;               \
} while (0)

/* Set the less significant 32 bits of a double from an int.  */

#define SET_LOW_WORD(d,v)           \
do {                                \
    ieee_double_shape_type sl_u;    \
    sl_u.value = (d);               \
    sl_u.parts.lsw = (v);           \
    (d) = sl_u.value;               \
} while (0)

#define GET_FLOAT_WORD(i,d) do \
{ \
    ieee_float_shape_type gf_u; \
    gf_u.value = (d); \
    (i) = gf_u.word; \
} while(0)

#define SET_FLOAT_WORD(d,i) do \
{ \
    ieee_float_shape_type gf_u; \
    gf_u.word = (i); \
    (d) = gf_u.value; \
} while(0)


#ifdef FLT_EVAL_METHOD
/*
 * Attempt to get strict C99 semantics for assignment with non-C99 compilers.
 */
#if FLT_EVAL_METHOD == 0 || __GNUC__ == 0
#define	STRICT_ASSIGN(type, lval, rval)	((lval) = (rval))
#else
#define	STRICT_ASSIGN(type, lval, rval) do {	\
	volatile type __lval;			\
						\
	if (sizeof(type) >= sizeof(long double))	\
		(lval) = (rval);		\
	else {					\
		__lval = (rval);		\
		(lval) = __lval;		\
	}					\
} while (0)
#endif
#endif /* FLT_EVAL_METHOD */
