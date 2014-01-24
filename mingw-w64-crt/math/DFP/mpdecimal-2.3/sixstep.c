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
#include <assert.h>
#include "bits.h"
#include "difradix2.h"
#include "mptypes.h"
#include "numbertheory.h"
#include "transpose.h"
#include "umodarith.h"
#include "sixstep.h"


/*
 * A variant of the six-step algorithm from:
 *
 * David H. Bailey: FFTs in External or Hierarchical Memory, Journal of
 * Supercomputing, vol. 4, no. 1 (March 1990), p. 23-35.
 *
 * URL: http://crd.lbl.gov/~dhbailey/dhbpapers/
 */


/* forward transform with sign = -1 */
int
six_step_fnt(mpd_uint_t *a, mpd_size_t n, int modnum)
{
	struct fnt_params *tparams;
	mpd_size_t log2n, C, R;
	mpd_uint_t kernel;
	mpd_uint_t umod;
#ifdef PPRO
	double dmod;
	uint32_t dinvmod[3];
#endif
	mpd_uint_t *x, w0, w1, wstep;
	mpd_size_t i, k;


	assert(ispower2(n));
	assert(n >= 16);
	assert(n <= MPD_MAXTRANSFORM_2N);

	log2n = mpd_bsr(n);
	C = (ONE_UM << (log2n / 2));  /* number of columns */
	R = (ONE_UM << (log2n - (log2n / 2))); /* number of rows */


	/* view 'a' as an RxC matrix, transpose */
	if (!transpose_pow2(a, R, C)) {
		return 0;
	}

	if ((tparams = _mpd_init_fnt_params(R, -1, modnum)) == NULL) {
		return 0;
	}
	for (x = a; x < a+n; x += R) {
		fnt_dif2(x, R, tparams);
	}

	if (!transpose_pow2(a, C, R)) {
		__mingw_dfp_get_globals()->mpd_free(tparams);
		return 0;
	}


	SETMODULUS(modnum);
	kernel = _mpd_getkernel(n, -1, modnum);
	for (i = 1; i < R; i++) {
		w0 = 1;
		w1 = POWMOD(kernel, i);
		wstep = MULMOD(w1, w1);
		for (k = 0; k < C; k += 2) {
			mpd_uint_t x0 = a[i*C+k];
			mpd_uint_t x1 = a[i*C+k+1];
			MULMOD2(&x0, w0, &x1, w1);
			MULMOD2C(&w0, &w1, wstep);
			a[i*C+k] = x0;
			a[i*C+k+1] = x1;
		}
	}


	if (C != R) {
		__mingw_dfp_get_globals()->mpd_free(tparams);
		if ((tparams = _mpd_init_fnt_params(C, -1, modnum)) == NULL) {
			return 0;
		}
	}
	for (x = a; x < a+n; x += C) {
		fnt_dif2(x, C, tparams);
	}
	__mingw_dfp_get_globals()->mpd_free(tparams);


#if 0
	/* An unordered transform is sufficient for convolution. */
	if (ordered) {
		if (!transpose_pow2(a, R, C)) {
			return 0;
		}
	}
#endif

	return 1;
}


/* reverse transform, sign = 1 */
int
inv_six_step_fnt(mpd_uint_t *a, mpd_size_t n, int modnum)
{
	struct fnt_params *tparams;
	mpd_size_t log2n, C, R;
	mpd_uint_t kernel;
	mpd_uint_t umod;
#ifdef PPRO
	double dmod;
	uint32_t dinvmod[3];
#endif
	mpd_uint_t *x, w0, w1, wstep;
	mpd_size_t i, k;


	assert(ispower2(n));
	assert(n >= 16);
	assert(n <= MPD_MAXTRANSFORM_2N);

	log2n = mpd_bsr(n);
	C = (ONE_UM << (log2n / 2)); /* number of columns */
	R = (ONE_UM << (log2n - (log2n / 2))); /* number of rows */


#if 0
	/* An unordered transform is sufficient for convolution. */
	if (ordered) {
		if (!transpose_pow2(a, C, R)) {
			return 0;
		}
	}
#endif

	if ((tparams = _mpd_init_fnt_params(C, 1, modnum)) == NULL) {
		return 0;
	}
	for (x = a; x < a+n; x += C) {
		fnt_dif2(x, C, tparams);
	}

	if (!transpose_pow2(a, R, C)) {
		__mingw_dfp_get_globals()->mpd_free(tparams);
		return 0;
	}


	SETMODULUS(modnum);
	kernel = _mpd_getkernel(n, 1, modnum);
	for (i = 1; i < C; i++) {
		w0 = 1;
		w1 = POWMOD(kernel, i);
		wstep = MULMOD(w1, w1);
		for (k = 0; k < R; k += 2) {
			mpd_uint_t x0 = a[i*R+k];
			mpd_uint_t x1 = a[i*R+k+1];
			MULMOD2(&x0, w0, &x1, w1);
			MULMOD2C(&w0, &w1, wstep);
			a[i*R+k] = x0;
			a[i*R+k+1] = x1;
		}
	}


	if (R != C) {
		__mingw_dfp_get_globals()->mpd_free(tparams);
		if ((tparams = _mpd_init_fnt_params(R, 1, modnum)) == NULL) {
			return 0;
		}
	}
	for (x = a; x < a+n; x += R) {
		fnt_dif2(x, R, tparams);
	}
	__mingw_dfp_get_globals()->mpd_free(tparams);

	if (!transpose_pow2(a, C, R)) {
		return 0;
	}

	return 1;
}


