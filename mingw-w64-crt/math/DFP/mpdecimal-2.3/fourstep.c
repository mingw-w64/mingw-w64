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
#include <assert.h>
#include "numbertheory.h"
#include "sixstep.h"
#include "transpose.h"
#include "umodarith.h"
#include "fourstep.h"


/*
 * A variant of the four-step algorithm from:
 *
 * David H. Bailey: FFTs in External or Hierarchical Memory, Journal of
 * Supercomputing, vol. 4, no. 1 (March 1990), p. 23-35.
 *
 * URL: http://crd.lbl.gov/~dhbailey/dhbpapers/
 */


#ifndef PPRO
static inline void
std_size3_ntt(mpd_uint_t *x1, mpd_uint_t *x2, mpd_uint_t *x3,
              mpd_uint_t w3table[3], mpd_uint_t umod)
{
	mpd_uint_t r1, r2;
	mpd_uint_t w;
	mpd_uint_t s, tmp;


	/* k = 0 -> w = 1 */
	s = *x1;
	s = addmod(s, *x2, umod);
	s = addmod(s, *x3, umod);

	r1 = s;

	/* k = 1 */
	s = *x1;

	w = w3table[1];
	tmp = MULMOD(*x2, w);
	s = addmod(s, tmp, umod);

	w = w3table[2];
	tmp = MULMOD(*x3, w);
	s = addmod(s, tmp, umod);

	r2 = s;

	/* k = 2 */
	s = *x1;

	w = w3table[2];
	tmp = MULMOD(*x2, w);
	s = addmod(s, tmp, umod);

	w = w3table[1];
	tmp = MULMOD(*x3, w);
	s = addmod(s, tmp, umod);

	*x3 = s;
	*x2 = r2;
	*x1 = r1;
}
#else /* PPRO */
static inline void
ppro_size3_ntt(mpd_uint_t *x1, mpd_uint_t *x2, mpd_uint_t *x3, mpd_uint_t w3table[3],
               mpd_uint_t umod, double *dmod, uint32_t dinvmod[3])
{
	mpd_uint_t r1, r2;
	mpd_uint_t w;
	mpd_uint_t s, tmp;


	/* k = 0 -> w = 1 */
	s = *x1;
	s = addmod(s, *x2, umod);
	s = addmod(s, *x3, umod);

	r1 = s;

	/* k = 1 */
	s = *x1;

	w = w3table[1];
	tmp = ppro_mulmod(*x2, w, dmod, dinvmod);
	s = addmod(s, tmp, umod);

	w = w3table[2];
	tmp = ppro_mulmod(*x3, w, dmod, dinvmod);
	s = addmod(s, tmp, umod);

	r2 = s;

	/* k = 2 */
	s = *x1;

	w = w3table[2];
	tmp = ppro_mulmod(*x2, w, dmod, dinvmod);
	s = addmod(s, tmp, umod);

	w = w3table[1];
	tmp = ppro_mulmod(*x3, w, dmod, dinvmod);
	s = addmod(s, tmp, umod);

	*x3 = s;
	*x2 = r2;
	*x1 = r1;
}
#endif


/* forward transform, sign = -1; transform length = 3 * 2^n */
int
four_step_fnt(mpd_uint_t *a, mpd_size_t n, int modnum)
{
	mpd_size_t R = 3; /* number of rows */
	mpd_size_t C = n / 3; /* number of columns */
	mpd_uint_t w3table[3];
	mpd_uint_t kernel, w0, w1, wstep;
	mpd_uint_t *s, *p0, *p1, *p2;
	mpd_uint_t umod;
#ifdef PPRO
	double dmod;
	uint32_t dinvmod[3];
#endif
	mpd_size_t i, k;


	assert(n >= 48);
	assert(n <= 3*MPD_MAXTRANSFORM_2N);


	SETMODULUS(modnum);
	_mpd_init_w3table(w3table, -1, modnum);
	/* size three ntt on the columns */
	for (p0=a, p1=p0+C, p2=p0+2*C; p0<a+C; p0++,p1++,p2++) {

		SIZE3_NTT(p0, p1, p2, w3table);
	}


	kernel = _mpd_getkernel(n, -1, modnum);
	for (i = 1; i < R; i++) {
		w0 = 1;
		w1 = POWMOD(kernel, i);
		wstep = MULMOD(w1, w1);
		for (k = 0; k < C-1; k += 2) {
			mpd_uint_t x0 = a[i*C+k];
			mpd_uint_t x1 = a[i*C+k+1];
			MULMOD2(&x0, w0, &x1, w1);
			MULMOD2C(&w0, &w1, wstep);
			a[i*C+k] = x0;
			a[i*C+k+1] = x1;
		}
	}

	/* transform rows */
	for (s = a; s < a+n; s += C) {
		if (!six_step_fnt(s, C, modnum)) {
			return 0;
		}
	}

#if 0
	/* An unordered transform is sufficient for convolution. */
	if (ordered) {
		transpose_3xpow2(a, R, C);
	}
#endif

	return 1;
}

/* backward transform, sign = 1; transform length = 3 * 2^n */
int
inv_four_step_fnt(mpd_uint_t *a, mpd_size_t n, int modnum)
{
	mpd_size_t R = 3; /* number of rows */
	mpd_size_t C = n / 3; /* number of columns */
	mpd_uint_t w3table[3];
	mpd_uint_t kernel, w0, w1, wstep;
	mpd_uint_t *s, *p0, *p1, *p2;
	mpd_uint_t umod;
#ifdef PPRO
	double dmod;
	uint32_t dinvmod[3];
#endif
	mpd_size_t i, k;


	assert(n >= 48);
	assert(n <= 3*MPD_MAXTRANSFORM_2N);


#if 0
	/* An unordered transform is sufficient for convolution. */
	if (ordered) {
		transpose_3xpow2(a, C, R);
	}
#endif

	/* transform rows */
	for (s = a; s < a+n; s += C) {
		if (!inv_six_step_fnt(s, C, modnum)) {
			return 0;
		}
	}


	SETMODULUS(modnum);
	kernel = _mpd_getkernel(n, 1, modnum);
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


	_mpd_init_w3table(w3table, 1, modnum);
	/* size three ntt on the columns */
	for (p0=a, p1=p0+C, p2=p0+2*C; p0<a+C; p0++,p1++,p2++) {

		SIZE3_NTT(p0, p1, p2, w3table);
	}

	return 1;
}


