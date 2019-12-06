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

static const double
    bp[]   = {1.0, 1.5,},
    dp_h[] = { 0.0, 5.84962487220764160156e-01,}, /* 0x3FE2B803, 0x40000000 */
    dp_l[] = { 0.0, 1.35003920212974897128e-08,}, /* 0x3E4CFDEB, 0x43CFD006 */
    Zero[] = {0.0, -0.0,},
    zero   =  0.0,
    one	   =  1.0,
    two	   =  2.0,
    two53  =  9007199254740992.0, /* 0x43400000, 0x00000000 */
    huge   =  1.0e300,
    tiny   =  1.0e-300,
    /* poly coefs for (3/2)*(log(x)-2s-2/3*s**3 */
    L1     =  5.99999999999994648725e-01, /* 0x3FE33333, 0x33333303 */
    L2     =  4.28571428578550184252e-01, /* 0x3FDB6DB6, 0xDB6FABFF */
    L3     =  3.33333329818377432918e-01, /* 0x3FD55555, 0x518F264D */
    L4     =  2.72728123808534006489e-01, /* 0x3FD17460, 0xA91D4101 */
    L5     =  2.30660745775561754067e-01, /* 0x3FCD864A, 0x93C9DB65 */
    L6     =  2.06975017800338417784e-01, /* 0x3FCA7E28, 0x4A454EEF */
    P1     =  1.66666666666666019037e-01, /* 0x3FC55555, 0x5555553E */
    P2     = -2.77777777770155933842e-03, /* 0xBF66C16C, 0x16BEBD93 */
    P3     =  6.61375632143793436117e-05, /* 0x3F11566A, 0xAF25DE2C */
    P4     = -1.65339022054652515390e-06, /* 0xBEBBBD41, 0xC5D26BF1 */
    P5     =  4.13813679705723846039e-08, /* 0x3E663769, 0x72BEA4D0 */
    lg2    =  6.93147180559945286227e-01, /* 0x3FE62E42, 0xFEFA39EF */
    lg2_h  =  6.93147182464599609375e-01, /* 0x3FE62E43, 0x00000000 */
    lg2_l  = -1.90465429995776804525e-09, /* 0xBE205C61, 0x0CA86C39 */
    ovt    =  8.0085662595372944372e-0017, /* -(1024-log2(ovfl+.5ulp)) */
    cp     =  9.61796693925975554329e-01, /* 0x3FEEC709, 0xDC3A03FD =2/(3ln2) */
    cp_h   =  9.61796700954437255859e-01, /* 0x3FEEC709, 0xE0000000 =(float)cp */
    cp_l   = -7.02846165095275826516e-09, /* 0xBE3E2FE0, 0x145B01F5 =tail of cp_h*/
    ivln2  =  1.44269504088896338700e+00, /* 0x3FF71547, 0x652B82FE =1/ln2 */
    ivln2_h=  1.44269502162933349609e+00, /* 0x3FF71547, 0x60000000 =24b 1/ln2*/
    ivln2_l=  1.92596299112661746887e-08; /* 0x3E54AE0B, 0xF85DDF44 =1/ln2 tail*/
