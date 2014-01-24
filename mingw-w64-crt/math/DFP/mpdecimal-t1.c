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

/*
 * Prelim Encoder/Decoder Test
 * Build with -std=gnu99 -Wall -Wextra -Wformat -Wstrict-aliasing -Wshadow -Wpacked \
 * -Winline -Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes \
 * -g -O2 -m32 -std=gnu99 -frounding-math -fsignaling-nans -Wno-inline -DCONFIG_32 \
 * -DPPRO -DASM -Dmpdecimal_header=\"mpdecimal-i686.h\" -fno-strict-aliasing \
 * -Wno-unused-function
*/

#include <stdio.h>
#include <inttypes.h>
#include "dfp_internal.h"
#include mpdecimal_header

static const _Decimal32 dec32 = 0.0DF;
static const _Decimal64 dec64 = 0.0DD;
static const _Decimal128 dec128 = 0.0DL;

static void print_mpd(const mpd_t *in){
  printf("----\n");
  printf("flags: %d\n",in->flags);
  printf("exp: %I64d\n",(uint64_t)in->exp);
  printf("digits: %I64d\n",(uint64_t)in->digits);
  printf("trail: %I64d\n",(uint64_t)mpd_trail_zeros(in));
  printf("len: %I64d\n",(uint64_t)in->len);
  printf("alloc: %I64d\n",(uint64_t)in->alloc);
  printf("data: ");
  for(mpd_ssize_t i = 0; i < in->len; i++){
    printf("[%09I64x]",(uint64_t)in->data[i]);
  }
  printf("\n");
  printf("----\n");
}

static void print_dec32(const _Decimal32 *in){
  ud32 ret;
  ret.d = *in;
  printf("----\n");
  printf("sign %x\n", ret.t0.sign);
  printf("bits %x\n", ret.t0.bits);
  printf("flag %x\n", ret.t0.flag);
  if(ret.t0.bits == 0x3){
    printf("exp %d\n", ret.t2.exponent);
    printf("mantissa %d\n", ret.t2.mantissa);
  } else {
    printf("exp %d\n", ret.t1.exponent);
    printf("mantissa %d\n", ret.t1.mantissa);
  }
  printf("----\n");
}

static void print_dec64(const _Decimal64 *in){
  ud64 ret;
  ret.d = *in;
  printf("----\n");
  printf("sign %x\n", ret.t0.sign);
  printf("bits %x\n", ret.t0.bits);
  printf("flag %x\n", ret.t0.flag);
  if(ret.t0.bits == 0x3){
    printf("exp %d\n", ret.t2.exponent);
    printf("mantissa %I64u\n", (uint64_t)ret.t2.mantissa);
  } else {
    printf("exp %d\n", ret.t1.exponent);
    printf("mantissa %I64u\n", (uint64_t)ret.t1.mantissa);
  }
  printf("----\n");
}

static void print_dec128(const _Decimal128 *in){
  ud128 ret;
  ret.d = *in;
  printf("----\n");
  printf("sign %x\n", ret.t0.sign);
  printf("bits %x\n", ret.t0.bits);
  printf("flag %x\n", ret.t0.flag);
  if(ret.t0.bits == 0x3){
    printf("exp %d\n", ret.t2.exponent);
    printf("mantissaL %I64u\n", (uint64_t)ret.t2.mantissaL);
    printf("mantissaH %I64u\n", (uint64_t)ret.t2.mantissaH);
  } else {
    printf("exp %d\n", ret.t1.exponent);
    printf("mantissaL %I64u\n", (uint64_t)ret.t1.mantissaL);
    printf("mantissaH %I64u\n", (uint64_t)ret.t1.mantissaH);
  }
  printf("----\n");
}


static void dec_to_mpd_conv(mpd_context_t * ctx, mpd_t *result, const int64_t significand_low, const int64_t exponent_part){
  uint32_t status = 0;
  mpd_t *ten, *exp_pow, *exp_partmpd, *significand_partmpd;
  ten = mpd_qnew();
  exp_pow = mpd_qnew();
  exp_partmpd = mpd_qnew();
  significand_partmpd = mpd_qnew();

  mpd_qset_i64(ten,10LL,ctx,&status);
  mpd_qset_i64(significand_partmpd,significand_low,ctx,&status);
  mpd_qset_i64(exp_partmpd,exponent_part,ctx,&status);
  mpd_qpow(exp_pow,ten,exp_partmpd,ctx,&status);
  mpd_qmul(result,significand_partmpd,exp_pow,ctx,&status);

  mpd_del(ten);
  mpd_del(exp_pow);
  mpd_del(exp_partmpd);
  mpd_del(significand_partmpd);
}

static void dec128_to_mpd_conv(mpd_context_t * ctx, mpd_t *result, const uint64_t significand_low, const int64_t significand_high, const int64_t exponent_part){
  uint32_t status = 0;
  mpd_t *ten, *sig1, *sig2, *stemp, *sig, *s64, *exp_pow, *exp_partmpd;
  ten = mpd_qnew();
  s64 = mpd_qnew();
  sig1 = mpd_qnew();
  sig2 = mpd_qnew();
  stemp = mpd_qnew();
  sig = mpd_qnew();
  exp_pow = mpd_qnew();
  exp_partmpd = mpd_qnew();
  mpd_qset_i64(ten,10LL,ctx,&status);
  /* 2^64 */
  mpd_qset_string(s64,"18446744073709551616",ctx,&status);
  mpd_qset_u64(sig1,significand_low,ctx,&status);
  mpd_qset_i64(sig2,significand_high,ctx,&status);
  mpd_qmul(stemp,sig2,s64,ctx,&status);
  mpd_qadd(sig,stemp,sig1,ctx,&status);
  mpd_qset_i64(exp_partmpd,exponent_part,ctx,&status);
  mpd_qpow(exp_pow,ten,exp_partmpd,ctx,&status);
  mpd_qmul(result,sig,exp_pow,ctx,&status);
  mpd_del(ten);
  mpd_del(sig1);
  mpd_del(sig2);
  mpd_del(sig);
  mpd_del(stemp);
  mpd_del(s64);
  mpd_del(exp_pow);
  mpd_del(exp_partmpd);
}

static uint32_t dec128_to_mpd(mpd_context_t * ctx, mpd_t *result, const _Decimal128 deci){
  int64_t significand2, exp_part;
  uint64_t significand1;
  ud128 in = {.d = deci};

  if(in.t0.bits == 0x3){ /*case 11 */
    /* should not enter here */
    exp_part = in.t2.exponent;
    significand1 = in.t2.mantissaL;
    significand2 = (in.t2.mantissaH | (0x1ULL << 49)) * ((in.t2.sign) ? -1 : 1);
  } else {
    exp_part = in.t1.exponent;
    significand1 = in.t1.mantissaL;
    significand2 = in.t1.mantissaH  * ((in.t1.sign) ? -1 : 1);
  }

  printf("%I64d %I64d\n", significand1, significand2);

  exp_part -= 6176; /* exp bias */
  dec128_to_mpd_conv(ctx, result, significand1, significand2, exp_part);
  return 0;
}

static uint32_t dec64_to_mpd(mpd_context_t * ctx, mpd_t *result, const _Decimal64 deci){
  int64_t significand, exp_part;
  ud64 in = {.d = deci};

  if(in.t0.bits == 0x3){ /*case 11 */
    exp_part = in.t2.exponent;
    significand = (in.t2.mantissa | (0x1ULL << 53)) * ((in.t2.sign) ? -1 : 1);
  } else {
    exp_part = in.t1.exponent;
    significand = in.t1.mantissa  * ((in.t1.sign) ? -1 : 1);
  }
  exp_part -= 398; /* exp bias */
  dec_to_mpd_conv(ctx, result, significand, exp_part);
  return 0;
}

static uint32_t dec32_to_mpd(mpd_context_t * ctx, mpd_t *result, const _Decimal32 deci){
  int64_t significand, exp_part;
  ud32 in = {.d = deci};

  if(in.t0.bits == 0x3){ /*case 11 */
    exp_part = in.t2.exponent;
    significand = (in.t2.mantissa | (0x1ULL << 23)) * ((in.t2.sign) ? -1 : 1);
  } else {
    exp_part = in.t1.exponent;
    significand = in.t1.mantissa  * ((in.t1.sign) ? -1 : 1);
  }
  exp_part -= 101; /* exp bias */
  dec_to_mpd_conv(ctx, result, significand, exp_part);
  return 0;
}

static _Decimal32 mpd_to_dec32(mpd_t *in){
  uint32_t exp_part, significand;
  uint32_t status = 0;
  ud32 ret;
  mpd_context_t ctx;
  uint16_t *bases_data;
  size_t bases;

  mpd_ieee_context(&ctx,MPD_DECIMAL32);
  mpd_qfinalize(in, &ctx,&status);

  exp_part = in->exp + (uint32_t)mpd_trail_zeros(in) + 101LL; /* rough guess? */
  in->exp = 0;
  bases = mpd_sizeinbase(in, UINT16_MAX+1);
  bases_data = __mingw_dfp_get_globals()->mpd_callocfunc(bases < 2 ? 2 : bases,sizeof(uint16_t));
  mpd_qexport_u16(bases_data,bases,UINT16_MAX+1,in,&status);
  significand = bases_data[0] | (uint32_t)bases_data[1] << 16 ;
  __mingw_dfp_get_globals()->mpd_free(bases_data);
  ret.t0.sign = mpd_isnegative(in);
  if((significand & (0x7ULL << 21)) == (0x1ULL << 23)) { /* 100 MSB? */
    ret.t2.bits = 0x3;
    ret.t2.mantissa = significand;
    ret.t2.exponent = exp_part;
  } else {
    ret.t1.mantissa = significand;
    ret.t1.exponent = exp_part;
  }
  return ret.d;
}

static _Decimal64 mpd_to_dec64(mpd_t *in){
  uint64_t exp_part, significand;
  uint32_t status = 0;
  size_t bases;
  uint16_t *bases_data;
  ud64 ret;
  mpd_context_t ctx;

  mpd_ieee_context(&ctx,MPD_DECIMAL64);
  mpd_qfinalize(in, &ctx,&status);

  exp_part = in->exp + (uint64_t)mpd_trail_zeros(in) + 398LL; /* rough guess? */
  in->exp = 0;
  bases = mpd_sizeinbase(in, UINT16_MAX+1);
  bases_data = __mingw_dfp_get_globals()->mpd_callocfunc(bases < 4 ? 4 : bases,sizeof(uint16_t));
  mpd_qexport_u16(bases_data,bases,UINT16_MAX+1,in,&status);
  significand = bases_data[0] | (uint64_t)bases_data[1] << 16 | (uint64_t)bases_data[2] << 32 | (uint64_t)bases_data[3] << 48;
  __mingw_dfp_get_globals()->mpd_free(bases_data);
  ret.t0.sign = mpd_isnegative(in);
  if((significand & (0x7ULL << 51)) == (0x1ULL << 53)) { /* 100 MSB? */
    ret.t2.bits = 0x3;
    ret.t2.mantissa = significand;
    ret.t2.exponent = exp_part;
  } else {
    ret.t1.mantissa = significand;
    ret.t1.exponent = exp_part;
  }
  return ret.d;
}

static _Decimal128 mpd_to_dec128(mpd_t *in){
  uint64_t exp_part,significand[2];
  uint16_t *bases_data;
  ud128 ret;
  mpd_context_t ctx;
  size_t bases;
  uint32_t status = 0;

  mpd_ieee_context(&ctx,MPD_DECIMAL128);
  mpd_qfinalize(in, &ctx,&status);
  exp_part = in->exp + (uint64_t)mpd_trail_zeros(in) + 6176LL; /* rough guess? */
  in->exp = 0;
  bases = mpd_sizeinbase(in, UINT16_MAX+1);
  bases_data = __mingw_dfp_get_globals()->mpd_callocfunc(bases < 8 ? 8 : bases,sizeof(uint16_t));
  mpd_qexport_u16(bases_data,bases,UINT16_MAX+1,in,&status);
  significand[0] = bases_data[0] | (uint64_t)bases_data[1] << 16 | (uint64_t)bases_data[2] << 32 | (uint64_t)bases_data[3] << 48;
  significand[1] = bases_data[4] | (uint64_t)bases_data[5] << 16 | (uint64_t)bases_data[6] << 32 | (uint64_t)bases_data[7] << 48;
  __mingw_dfp_get_globals()->mpd_free(bases_data);
  ret.t0.sign = mpd_isnegative(in);
  if((significand[1] & (0x7ULL << 57)) == (0x1ULL << 49)) { /* 100 MSB? */
    ret.t2.bits = 0x3;
    ret.t2.mantissaL = significand[0];
    ret.t2.mantissaH = significand[1];
    ret.t2.exponent = exp_part;
  } else {
    ret.t1.mantissaL = significand[0];
    ret.t1.mantissaH = significand[1];
    ret.t1.exponent = exp_part;
  }
  return ret.d;

}

int main(){
  mpd_context_t ctx;
  mpd_t *result1;
  mpd_t *result2;
  mpd_t *result3;
  mpd_setminalloc(MPD_MINALLOC_MAX);
  mpd_ieee_context(&ctx, 160);
  result1 = mpd_qnew();
  result2 = mpd_qnew();
  result3 = mpd_qnew();
  //mpd_qset_u64(result1,2ULL,&ctx,&status);
  dec32_to_mpd(&ctx,result1,dec32);
  dec64_to_mpd(&ctx,result2,dec64);
  dec128_to_mpd(&ctx,result3,dec128);
  //mpd_qset_u64(result2,4ULL,&ctx,&status);
  //mpd_qpow(result3,result1,result2,&ctx,&status);
  mpd_print(result1);
  mpd_print(result2);
  mpd_print(result3);

  /*print_mpd(result1);
  print_mpd(result2);
  print_mpd(result3);*/

  _Decimal32 ddd = mpd_to_dec32(result1);
  printf ("Compare is %d\n", memcmp(&ddd,&dec32,sizeof(_Decimal32)));
  printf ("0x%x\n0x%x\n", *((uint32_t *)(void *)&ddd), *((uint32_t *)(void *)&dec32));

  _Decimal64 ddd64 = mpd_to_dec64(result2);
  printf ("Compare is %d\n", memcmp(&ddd64,&dec64,sizeof(_Decimal64)));
  printf ("0x%I64x\n0x%I64x\n", *((uint64_t *)(void *)&ddd64), *((uint64_t *)(void *)&dec64));

  _Decimal128 ddd128 = mpd_to_dec128(result3);
  printf ("Compare is %d\n", memcmp(&ddd128,&dec128,sizeof(_Decimal128)));
  printf ("0x%I64d\n0x%I64x\n", *((uint64_t *)(void *)&ddd128), *((uint64_t *)(void *)&dec128));

  mpd_del(result1);
  mpd_del(result2);
  mpd_del(result3);

  print_dec32(&dec32);
  print_dec64(&dec64);
  print_dec128(&dec128);
  return 0;
}
