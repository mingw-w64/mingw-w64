/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009 - 2013 by the mingw-w64 project

 See the AUTHORS file for the list of contributors to the mingw-w64 project.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __STDC_WANT_DEC_FP__
#define __STDC_WANT_DEC_FP__ 1
#endif
#include <math.h>
#include <fenv.h>
#include <errno.h>
#include <inttypes.h>

#ifndef _MSC_VER
#ifndef __DECIMAL_BID_FORMAT__
#error Only BID DFP supported!
#endif

#if (__BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__) || (__FLOAT_WORD_ORDER__ != __ORDER_LITTLE_ENDIAN__)
#error Only little endian supported!
#endif
#endif /* _MSC_VER */

/* We need to check the BID encoding format

_Decimal32:
MSB-----------------------------------------------------------------LSB
s         | 00eeeeee                      |(0)TTTtttttttttttttttttttt |
[sign bit]|[ proble bits must not be "11"]|[Implicit "0" MSB]         |
          |[ 8-bit exponent, "00" probed ]|[23-bit True Siginifcant  ]|

If probed bits form "11" exponent is 10-bits instead of 8-bits.
s         | 11 00eeeeee       |(100) Ttttttttttttttttttttt |
[sign bit]|["11" proble bits ]|                            |
          |[ 10-bit exponent ]|[Implicit "100" as MSB]     |
          |                   |[21-bit True Significant   ]|

DFP = -1^s x tttt x [ 10 ^ (eeee - (101(base10))]

Use type0d32 to probe the 2 bits, if not 11, use type1d32, else use type2d32.
The 11 bits are ignored when computing exponents.

Examples:

s 00eeeeee (0)TTTtttttttttttttttttttt
s 01eeeeee (0)TTTtttttttttttttttttttt
s 10eeeeee (0)TTTtttttttttttttttttttt
s 11 01eeeeee (100)Ttttttttttttttttttttt
s 11 10eeeeee (100)Ttttttttttttttttttttt

NAN types:

s 11110 xxxxxxxxxxxxxxxxxxxxxxxxxx   +-Infinity
s 111110 xxxxxxxxxxxxxxxxxxxxxxxxx   quiet NaN
s 111111 xxxxxxxxxxxxxxxxxxxxxxxxx   signaling NaN

_Decimal64:

s 00eeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt
s 01eeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt
s 10eeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt
s 11 00eeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt
s 11 01eeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt
s 11 10eeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt

DFP = -1^s x tttt x [ 10 ^ (eeee - (398(base10))]

_Decimal128:

s 00eeeeeeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt
s 01eeeeeeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt
s 10eeeeeeeeeeee TTTtttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt
s 11 00eeeeeeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt
s 11 01eeeeeeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt
s 11 10eeeeeeeeeeee (100)Ttttttttttttttttttttt tttttttttttttttttttttttttttttt tttttttttttttttttttttttttttttttttttttttttttttttttttttttt

DFP = -1^s x tttt x [ 10 ^ (eeee - (6176(base10))]

*/

#include <pshpack1.h>
#ifdef __GNUC__
#define structpack __attribute__((gcc_struct))
#else
#define structpack
#endif

typedef struct structpack type0d32 {
  uint64_t blob:25;
  uint32_t flag:4;
  uint32_t bits:2;
  uint32_t sign:1;
} type0d32;

/* case not 11 */
typedef struct structpack type1d32 {
  uint64_t mantissa:23;
  uint32_t exponent:8;
  uint32_t sign:1;
} type1d32;

/* case 11 */
typedef struct structpack type2d32 {
  /* implicit (100) MSB for mantissa */
  uint64_t mantissa:21;
  uint32_t exponent:8;
  uint32_t bits:2;
  uint32_t sign:1;
} type2d32;

typedef struct structpack type0d64 {
  uint64_t blob:57;
  uint32_t flag:4;
  uint32_t bits:2;
  uint32_t sign:1;
} type0d64;

/* case not 11 */
typedef struct structpack type1d64 {;
  uint64_t mantissa:53;
  uint32_t exponent:10;
  uint32_t sign:1;
} type1d64;

/* case 11 */
typedef struct structpack type2d64 {
  /* implicit (100) MSB for mantissa */
  uint64_t mantissa:51;
  uint32_t exponent:10;
  uint32_t bits:2;
  uint32_t sign:1;
} type2d64;

typedef struct structpack type0d128 {
  uint64_t blobL:64;
  uint64_t blobH:57;
  uint32_t flag:4;
  uint32_t bits:2;
  uint32_t sign:1;
} type0d128;

/* case not 11 */
typedef struct structpack type1d128 {
  uint64_t mantissaL:64;
  uint64_t mantissaH:49;
  uint32_t exponent:14;
  uint32_t sign:1;
} type1d128;

/* case 11 */
typedef struct structpack type2d128 {
  uint64_t mantissaL:64;
  /* implicit (100) MSB for mantissa */
  uint64_t mantissaH:47;
  uint32_t exponent:14;
  uint32_t bits:2;
  uint32_t sign:1;
} type2d128;

#ifdef _MSC_VER
typedef type0d32 _Decimal32;
typedef type0d64 _Decimal64;
typedef type0d128 _Decimal128;
#endif /* _MSC_VER */

#include <poppack.h>

typedef union ud32 {
  _Decimal32 d;
  type0d32 t0;
  type1d32 t1;
  type2d32 t2;
  unsigned char b[sizeof(_Decimal32)];
} ud32;

typedef union ud64 {
  _Decimal64 d;
  type0d64 t0;
  type1d64 t1;
  type2d64 t2;
  unsigned char b[sizeof(_Decimal64)];
} ud64;

typedef union ud128 {
  _Decimal128 d;
  type0d128 t0;
  type1d128 t1;
  type2d128 t2;
  unsigned char b[sizeof(_Decimal128)];
} ud128;
