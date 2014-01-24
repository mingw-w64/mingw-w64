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
#include <stdlib.h>
#include "typearith.h"
#include "memory.h"

/* emulate calloc if it is not available */
void *
mpd_callocfunc_em(size_t nmemb, size_t size)
{
	void *ptr;
	size_t req;

#if MPD_SIZE_MAX < SIZE_MAX
	if (nmemb > MPD_SIZE_MAX || size > MPD_SIZE_MAX) {
		return NULL;
	}
#endif
	req = mul_size_t((mpd_size_t)nmemb, (mpd_size_t)size);
	if ((ptr = __mingw_dfp_get_globals()->mpd_mallocfunc(req)) == NULL) {
		return NULL;
	}
	/* used on uint32_t or uint64_t */
	memset(ptr, 0, req);

	return ptr;
}


/* malloc with overflow checking */
void *
mpd_alloc(mpd_size_t nmemb, mpd_size_t size)
{
	void *ptr;
	mpd_size_t req;

	req = mul_size_t(nmemb, size);
	if ((ptr = __mingw_dfp_get_globals()->mpd_mallocfunc(req)) == NULL) {
		return NULL;
	}

	return ptr;
}

/* calloc with overflow checking */
void *
mpd_calloc(mpd_size_t nmemb, mpd_size_t size)
{
	void *ptr;

	if ((ptr = __mingw_dfp_get_globals()->mpd_callocfunc(nmemb, size)) == NULL) {
		return NULL;
	}

	return ptr;
}

/* realloc with overflow checking */
void *
mpd_realloc(void *ptr, mpd_size_t nmemb, mpd_size_t size, uint8_t *err)
{
	void *new;
	mpd_size_t req;

	req = mul_size_t(nmemb, size);
	if ((new = __mingw_dfp_get_globals()->mpd_reallocfunc(ptr, req)) == NULL) {
		*err = 1;
		return ptr;
	}

	return new;
}

/* struct hack malloc with overflow checking */
void *
mpd_sh_alloc(mpd_size_t struct_size, mpd_size_t nmemb, mpd_size_t size)
{
	void *ptr;
	mpd_size_t req;

	req = mul_size_t(nmemb, size);
	req = add_size_t(req, struct_size);
	if ((ptr = __mingw_dfp_get_globals()->mpd_mallocfunc(req)) == NULL) {
		return NULL;
	}

	return ptr;
}


/* Allocate a new decimal with data-size 'size'.
 * In case of an error the return value is NULL.
 */
mpd_t *
mpd_qnew_size(mpd_ssize_t size)
{
	mpd_t *result;

	size = (size < __mingw_dfp_get_globals()->MPD_MINALLOC) ? __mingw_dfp_get_globals()->MPD_MINALLOC : size;

	if ((result = mpd_alloc(1, sizeof *result)) == NULL) {
		return NULL;
	}
	if ((result->data = mpd_alloc(size, sizeof *result->data)) == NULL) {
		__mingw_dfp_get_globals()->mpd_free(result);
		return NULL;
	}

	result->flags = 0;
	result->exp = 0;
	result->digits = 0;
	result->len = 0;
	result->alloc = size;

	return result;
}

/* Allocate a new decimal with data-size MPD_MINALLOC.
 * In case of an error the return value is NULL.
 */
mpd_t *
mpd_qnew(void)
{
	return mpd_qnew_size(__mingw_dfp_get_globals()->MPD_MINALLOC);
}

/* Allocate new decimal. Caller can check for NULL or MPD_Malloc_error.
 * Raises on error.
 */
mpd_t *
mpd_new(mpd_context_t *ctx)
{
	mpd_t *result;

	if ((result = mpd_qnew()) == NULL) {
		mpd_addstatus_raise(ctx, MPD_Malloc_error);
	}
	return result;
}

int
mpd_switch_to_dyn(mpd_t *result, mpd_ssize_t size, uint32_t *status)
{
	mpd_uint_t *p = result->data;

	if ((result->data = mpd_alloc(size, sizeof *result->data)) == NULL) {
		result->data = p;
		mpd_set_qnan(result);
		mpd_set_positive(result);
		result->exp = result->digits = result->len = 0;
		*status |= MPD_Malloc_error;
		return 0;
	}

	memcpy(result->data, p, result->len * (sizeof *result->data));
	result->alloc = size;
	mpd_set_dynamic_data(result);
	return 1;
}

int
mpd_switch_to_dyn_zero(mpd_t *result, mpd_ssize_t size, uint32_t *status)
{
	mpd_uint_t *p = result->data;

	if ((result->data = mpd_calloc(size, sizeof *result->data)) == NULL) {
		result->data = p;
		mpd_set_qnan(result);
		mpd_set_positive(result);
		result->exp = result->digits = result->len = 0;
		*status |= MPD_Malloc_error;
		return 0;
	}

	result->alloc = size;
	mpd_set_dynamic_data(result);

	return 1;
}

int
mpd_realloc_dyn(mpd_t *result, mpd_ssize_t size, uint32_t *status)
{
	uint8_t err = 0;

	result->data = mpd_realloc(result->data, size, sizeof *result->data, &err);
	if (!err) {
		result->alloc = size;
	}
	else if (size > result->alloc) {
		mpd_set_qnan(result);
		mpd_set_positive(result);
		result->exp = result->digits = result->len = 0;
		*status |= MPD_Malloc_error;
		return 0;
	}

	return 1;
}


