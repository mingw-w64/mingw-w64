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

#include "softmath_private.h"
#include "../bsd_private_base.h"

static const float
    bp[]   = {1.0, 1.5,},
    dp_h[] = { 0.0, 5.84960938e-01,}, /* 0x3f15c000 */
    dp_l[] = { 0.0, 1.56322085e-06,}, /* 0x35d1cfdc */
    Zero[] = {0.0, -0.0,},
    zero   =  0.0,
    one    =  1.0,
    two    =  2.0,
    two24  =  16777216.0, /* 0x4b800000 */
    huge   =  1.0e30,
    tiny   =  1.0e-30,
    /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
    L1     =  6.0000002384e-01, /* 0x3f19999a */
    L2     =  4.2857143283e-01, /* 0x3edb6db7 */
    L3     =  3.3333334327e-01, /* 0x3eaaaaab */
    L4     =  2.7272811532e-01, /* 0x3e8ba305 */
    L5     =  2.3066075146e-01, /* 0x3e6c3255 */
    L6     =  2.0697501302e-01, /* 0x3e53f142 */
    P1     =  1.6666667163e-01, /* 0x3e2aaaab */
    P2     = -2.7777778450e-03, /* 0xbb360b61 */
    P3     =  6.6137559770e-05, /* 0x388ab355 */
    P4     = -1.6533901999e-06, /* 0xb5ddea0e */
    P5     =  4.1381369442e-08, /* 0x3331bb4c */
    lg2    =  6.9314718246e-01, /* 0x3f317218 */
    lg2_h  =  6.93145752e-01, /* 0x3f317200 */
    lg2_l  =  1.42860654e-06, /* 0x35bfbe8c */
    ovt    =  4.2995665694e-08, /* -(128-log2(ovfl+.5ulp)) */
    cp     =  9.6179670095e-01, /* 0x3f76384f =2/(3ln2) */
    cp_h   =  9.6191406250e-01, /* 0x3f764000 =12b cp */
    cp_l   = -1.1736857402e-04, /* 0xb8f623c6 =tail of cp_h */
    ivln2  =  1.4426950216e+00, /* 0x3fb8aa3b =1/ln2 */
    ivln2_h=  1.4426879883e+00, /* 0x3fb8aa00 =16b 1/ln2*/
    ivln2_l=  7.0526075433e-06; /* 0x36eca570 =1/ln2 tail*/
