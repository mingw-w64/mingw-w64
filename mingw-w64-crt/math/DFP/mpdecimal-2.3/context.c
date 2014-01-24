/*
 * Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#include mpdecimal_header
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <windows.h>

static DWORD __mingw_dfp_globals = TLS_OUT_OF_INDEXES;
int __mingwthr_key_dtor (DWORD key, void (*dtor)(void *));

static void * default_mpd_malloc (size_t size){
  return HeapAlloc(GetProcessHeap(),0,size);
}

static void * default_mpd_realloc (void *ptr, size_t size){
  if(size == 0) {
    HeapFree(GetProcessHeap(),0,ptr);
    return NULL;
  }
  return HeapReAlloc(GetProcessHeap(),0,ptr,size);
}

static void * default_mpd_calloc (size_t nmemb, size_t size){
  return HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,nmemb * size);
}

static void default_mpd_free (void *ptr){
  if(ptr)
    HeapFree(GetProcessHeap(),0,ptr);
}

static void
mpd_dflt_traphandler(mpd_context_t *ctx UNUSED)
{
	raise(SIGFPE);
}

static void
clean_tls(void *blob){
  DWORD idx = ((__mingw_dfp_gvars *)blob)->idx;
  default_mpd_free(blob);
  TlsFree(idx);
}

__mingw_dfp_gvars *__mingw_dfp_get_globals(void){
  __mingw_dfp_gvars *ret = NULL;
  DWORD tls_get;
  if(TLS_OUT_OF_INDEXES == __atomic_load_n(&__mingw_dfp_globals, __ATOMIC_ACQUIRE)){
    DWORD tmpalloc = TlsAlloc();
    DWORD __no_alloc = TLS_OUT_OF_INDEXES;
    if(!__atomic_compare_exchange_n(&__mingw_dfp_globals,&__no_alloc,tmpalloc,
        0, __ATOMIC_RELEASE, __ATOMIC_CONSUME)){
      TlsFree(tmpalloc);
    }
  }

  tls_get = __atomic_load_n(&__mingw_dfp_globals, __ATOMIC_CONSUME);
  ret = TlsGetValue(tls_get);

  if((GetLastError() == ERROR_SUCCESS) && ret == NULL){
    ret = default_mpd_calloc(1,sizeof(__mingw_dfp_gvars));
    TlsSetValue(tls_get,ret);
    __mingwthr_key_dtor(tls_get,clean_tls);
    ret->idx = tls_get;
    ret->MPD_MINALLOC = MPD_MINALLOC_MAX;
    ret->mpd_mallocfunc = default_mpd_malloc;
    ret->mpd_reallocfunc = default_mpd_realloc;
    ret->mpd_callocfunc = default_mpd_calloc;
    ret->mpd_free = default_mpd_free;
    ret->mpd_traphandler = mpd_dflt_traphandler;
    ret->minalloc_is_set = 0;
    ret->mpd_ln10.flags = MPD_STATIC|MPD_STATIC_DATA;
    ret->mpd_ln10.exp = -(2*MPD_RDIGITS-1);
    ret->mpd_ln10.digits = 2*MPD_RDIGITS;
    ret->mpd_ln10.len = 2;
    ret->mpd_ln10.alloc = MPD_MINALLOC_MAX;
    ret->mpd_ln10.data = ret->mpd_ln10_data_blob;
/* Two word initial approximations for ln(10) */
#ifdef CONFIG_64
    mpd_uint_t mpd_ln10_init[2] = {179914546843642076, 2302585092994045684},
    mpd_ln10_data[MPD_MINALLOC_MAX] = {179914546843642076, 2302585092994045684};
#else
    mpd_uint_t mpd_ln10_init[2] = {299404568, 230258509},
    mpd_ln10_data[MPD_MINALLOC_MAX] = {299404568, 230258509};
#endif
    memcpy(ret->mpd_ln10.data, mpd_ln10_data, sizeof(mpd_uint_t[MPD_MINALLOC_MAX]));
    memcpy(ret->mpd_ln10_data, mpd_ln10_data, sizeof(mpd_uint_t[MPD_MINALLOC_MAX]));
    memcpy(ret->mpd_ln10_init, mpd_ln10_init, sizeof(mpd_uint_t[2]));
  }
  return ret;
}

void
mpd_setminalloc(mpd_ssize_t n){

	if (__mingw_dfp_get_globals()->minalloc_is_set) {
		mpd_err_warn("mpd_setminalloc: ignoring request to set "
		             "MPD_MINALLOC a second time\n");
		return;
	}
	if (n < MPD_MINALLOC_MIN || n > MPD_MINALLOC_MAX) {
		mpd_err_fatal("illegal value for MPD_MINALLOC"); /* GCOV_NOT_REACHED */
	}
	__mingw_dfp_get_globals()->MPD_MINALLOC = n;
	__mingw_dfp_get_globals()->minalloc_is_set = 1;
}

void
mpd_init(mpd_context_t *ctx, mpd_ssize_t prec)
{
	mpd_ssize_t ideal_minalloc;

	mpd_defaultcontext(ctx);

	if (!mpd_qsetprec(ctx, prec)) {
		mpd_addstatus_raise(ctx, MPD_Invalid_context);
		return;
	}

	ideal_minalloc = 2 * ((prec+MPD_RDIGITS-1) / MPD_RDIGITS);
	if (ideal_minalloc < MPD_MINALLOC_MIN) ideal_minalloc = MPD_MINALLOC_MIN;
	if (ideal_minalloc > MPD_MINALLOC_MAX) ideal_minalloc = MPD_MINALLOC_MAX;

	mpd_setminalloc(ideal_minalloc);
}

void
mpd_maxcontext(mpd_context_t *ctx)
{
	ctx->prec=MPD_MAX_PREC;
	ctx->emax=MPD_MAX_EMAX;
	ctx->emin=MPD_MIN_EMIN;
	ctx->round=MPD_ROUND_HALF_EVEN;
	ctx->traps=MPD_Traps;
	ctx->status=0;
	ctx->newtrap=0;
	ctx->clamp=0;
	ctx->allcr=1;
}

void
mpd_maxcontext_plus(mpd_context_t *workctx, const mpd_context_t *ctx)
{
	workctx->prec = ctx->prec > MPD_MAX_PREC ? ctx->prec : MPD_MAX_PREC;
	workctx->emax = ctx->emax > MPD_MAX_EMAX ? ctx->emax : MPD_MAX_EMAX;
	workctx->emin = ctx->emin < MPD_MIN_EMIN ? ctx->emin : MPD_MIN_EMIN;
	workctx->round=MPD_ROUND_HALF_EVEN;
	workctx->traps=MPD_Traps;
	workctx->status=0;
	workctx->newtrap=0;
	workctx->clamp=0;
	workctx->allcr=1;
}

void
mpd_defaultcontext(mpd_context_t *ctx)
{
	ctx->prec=2*MPD_RDIGITS;
	ctx->emax=MPD_MAX_EMAX;
	ctx->emin=MPD_MIN_EMIN;
	ctx->round=MPD_ROUND_HALF_UP;
	ctx->traps=MPD_Traps;
	ctx->status=0;
	ctx->newtrap=0;
	ctx->clamp=0;
	ctx->allcr=1;
}

void
mpd_basiccontext(mpd_context_t *ctx)
{
	ctx->prec=9;
	ctx->emax=MPD_MAX_EMAX;
	ctx->emin=MPD_MIN_EMIN;
	ctx->round=MPD_ROUND_HALF_UP;
	ctx->traps=MPD_Traps|MPD_Clamped;
	ctx->status=0;
	ctx->newtrap=0;
	ctx->clamp=0;
	ctx->allcr=1;
}

int
mpd_ieee_context(mpd_context_t *ctx, int bits)
{
	if (bits <= 0 || bits > MPD_IEEE_CONTEXT_MAX_BITS || bits % 32) {
		return -1;
	}

	ctx->prec = 9 * (bits/32) - 2;
	ctx->emax = 3 * ((mpd_ssize_t)1<<(bits/16+3));
	ctx->emin = 1 - ctx->emax;
	ctx->round=MPD_ROUND_HALF_EVEN;
	ctx->traps=0;
	ctx->status=0;
	ctx->newtrap=0;
	ctx->clamp=1;
	ctx->allcr=1;

	return 0;
}

mpd_ssize_t
mpd_getprec(const mpd_context_t *ctx)
{
	return ctx->prec;
}

mpd_ssize_t
mpd_getemax(const mpd_context_t *ctx)
{
	return ctx->emax;
}

mpd_ssize_t
mpd_getemin(const mpd_context_t *ctx)
{
	return ctx->emin;
}

int
mpd_getround(const mpd_context_t *ctx)
{
	return ctx->round;
}

uint32_t
mpd_gettraps(const mpd_context_t *ctx)
{
	return ctx->traps;
}

uint32_t
mpd_getstatus(const mpd_context_t *ctx)
{
	return ctx->status;
}

int
mpd_getclamp(const mpd_context_t *ctx)
{
	return ctx->clamp;
}

int
mpd_getcr(const mpd_context_t *ctx)
{
	return ctx->allcr;
}


int
mpd_qsetprec(mpd_context_t *ctx, mpd_ssize_t prec)
{
	if (prec <= 0 || prec > MPD_MAX_PREC) {
		return 0;
	}
	ctx->prec = prec;
	return 1;
}

int
mpd_qsetemax(mpd_context_t *ctx, mpd_ssize_t emax)
{
	if (emax < 0 || emax > MPD_MAX_EMAX) {
		return 0;
	}
	ctx->emax = emax;
	return 1;
}

int
mpd_qsetemin(mpd_context_t *ctx, mpd_ssize_t emin)
{
	if (emin > 0 || emin < MPD_MIN_EMIN) {
		return 0;
	}
	ctx->emin = emin;
	return 1;
}

int
mpd_qsetround(mpd_context_t *ctx, int round)
{
	int i;

	for (i = 0; i < MPD_ROUND_GUARD; i++) {
		if (i == round) {
			ctx->round = round;
			return 1;
		}
	}
	return 0;
}

int
mpd_qsettraps(mpd_context_t *ctx, uint32_t traps)
{
	if (traps > MPD_Max_status) {
		return 0;
	}
	ctx->traps = traps;
	return 1;
}

int
mpd_qsetstatus(mpd_context_t *ctx, uint32_t flags)
{
	if (flags > MPD_Max_status) {
		return 0;
	}
	ctx->status = flags;
	return 1;
}

int
mpd_qsetclamp(mpd_context_t *ctx, int c)
{
	if (c != 0 && c != 1) {
		return 0;
	}
	ctx->clamp = c;
	return 1;
}

int
mpd_qsetcr(mpd_context_t *ctx, int c)
{
	if (c != 0 && c != 1) {
		return 0;
	}
	ctx->allcr = c;
	return 1;
}


void
mpd_addstatus_raise(mpd_context_t *ctx, uint32_t flags)
{
	ctx->status |= flags;
	if (flags&ctx->traps) {
		ctx->newtrap = (flags&ctx->traps);
		__mingw_dfp_get_globals()->mpd_traphandler(ctx);
	}
}


