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


#include "mpdecimal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include "bits.h"
#include "constants.h"
#include "mptypes.h"
#include "typearith.h"
#include "transpose.h"
#include "malloc_fail.h"



/*
 * All the following is pasted from transpose.c for the sole reason of
 * running the tests with uint8_t arrays, which allow greater sizes.
 */


#define BUFSIZE 4096
#define SIDE 128


static inline void pointerswap_c(uint8_t **a, uint8_t **b)
{
	uint8_t *tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/* Definition of the matrix transpose */
static void
std_trans_c(uint8_t dest[], uint8_t src[], mpd_size_t rows, mpd_size_t cols)
{
	mpd_size_t idest, isrc;
	mpd_size_t r, c;

	for (r = 0; r < rows; r++) {
		isrc = r * cols;
		idest = r;
		for (c = 0; c < cols; c++) {
			dest[idest] = src[isrc];
			isrc += 1;
			idest += rows;
		}
	}
}

/*
 * Swap half-rows of 2^n * (2*2^n) matrix.
 * FORWARD_CYCLE: even/odd permutation of the halfrows.
 * BACKWARD_CYCLE: reverse the even/odd permutation.
 */
static int
swap_halfrows_pow2_c(uint8_t *matrix, mpd_size_t rows, mpd_size_t cols, int dir)
{
	uint8_t buf1[BUFSIZE];
	uint8_t buf2[BUFSIZE];
	uint8_t *readbuf, *writebuf, *hp;
	mpd_size_t *done, dbits;
	mpd_size_t b = BUFSIZE, stride;
	mpd_size_t hn, hmax; /* halfrow number */
	mpd_size_t m, r=0;
	mpd_size_t offset;
	mpd_size_t next;


	assert(cols == mul_size_t(2, rows));

	if (dir == FORWARD_CYCLE) {
		r = rows;
	}
	else if (dir == BACKWARD_CYCLE) {
		r = 2;
	}
	else {
		mpd_err_fatal("swap_halfrows_pow2_c: illegal argument for \"dir\"");
	}

	m = cols - 1;
	hmax = rows; /* cycles start at odd halfrows */
	dbits = 8 * sizeof *done;
	if ((done = mpd_calloc(hmax/(sizeof *done) + 1, sizeof *done)) == NULL) {
		return 0;
	}

	for (hn = 1; hn <= hmax; hn += 2) {

		if (done[hn/dbits] & mpd_bits[hn%dbits]) {
			continue;
		}

		readbuf = buf1; writebuf = buf2;

		for (offset = 0; offset < cols/2; offset += b) {

			stride = (offset + b < cols/2) ? b : cols/2-offset;

			hp = matrix + hn*cols/2;
			memcpy(readbuf, hp+offset, stride*(sizeof *readbuf));
			pointerswap_c(&readbuf, &writebuf);

			next = mulmod_size_t(hn, r, m);
			hp = matrix + next*cols/2;

			while (next != hn) {

				memcpy(readbuf, hp+offset, stride*(sizeof *readbuf));
				memcpy(hp+offset, writebuf, stride*(sizeof *writebuf));
				pointerswap_c(&readbuf, &writebuf);

				done[next/dbits] |= mpd_bits[next%dbits];

				next = mulmod_size_t(next, r, m);
			        hp = matrix + next*cols/2;

			}

			memcpy(hp+offset, writebuf, stride*(sizeof *writebuf));

			done[hn/dbits] |= mpd_bits[hn%dbits];
		}
	}

	__mingw_dfp_get_globals()->mpd_free(done);
	return 1;
}

/* In-place transpose of a square matrix */
static inline void
squaretrans_c(uint8_t *buf, mpd_size_t cols)
{
	uint8_t tmp;
	mpd_size_t idest, isrc;
	mpd_size_t r, c;

	for (r = 0; r < cols; r++) {
		c = r+1;
		isrc = r*cols + c;
		idest = c*cols + r;
		for (c = r+1; c < cols; c++) {
			tmp = buf[isrc];
			buf[isrc] = buf[idest];
			buf[idest] = tmp;
			isrc += 1;
			idest += cols;
		}
	}
}

/*
 * Transpose 2^n * 2^n matrix. For cache efficiency, the matrix is split into
 * square blocks with side length 'SIDE'. First, the blocks are transposed,
 * then a square tranposition is done on each individual block.
 */
static void
squaretrans_pow2_c(uint8_t *matrix, mpd_size_t size)
{
	uint8_t buf1[SIDE*SIDE];
	uint8_t buf2[SIDE*SIDE];
	uint8_t *to, *from;
	mpd_size_t b = size;
	mpd_size_t r, c;
	mpd_size_t i;

	while (b > SIDE) b >>= 1;

	for (r = 0; r < size; r += b) {

		for (c = r; c < size; c += b) {

			from = matrix + r*size + c;
			to = buf1;
			for (i = 0; i < b; i++) {
				memcpy(to, from, b*(sizeof *to));
				from += size;
				to += b;
			}
			squaretrans_c(buf1, b);

			if (r == c) {
				to = matrix + r*size + c;
				from = buf1;
				for (i = 0; i < b; i++) {
					memcpy(to, from, b*(sizeof *to));
					from += b;
					to += size;
				}
				continue;
			}
			else {
				from = matrix + c*size + r;
				to = buf2;
				for (i = 0; i < b; i++) {
					memcpy(to, from, b*(sizeof *to));
					from += size;
					to += b;
				}
				squaretrans_c(buf2, b);

				to = matrix + c*size + r;
				from = buf1;
				for (i = 0; i < b; i++) {
					memcpy(to, from, b*(sizeof *to));
					from += b;
					to += size;
				}

				to = matrix + r*size + c;
				from = buf2;
				for (i = 0; i < b; i++) {
					memcpy(to, from, b*(sizeof *to));
					from += b;
					to += size;
				}
			}
		}
	}

}

/*
 * In-place transposition of a 2^n x 2^n or a 2^n x (2*2^n)
 * or a (2*2^n) x 2^n matrix.
 */
static int
transpose_pow2_c(uint8_t *matrix, mpd_size_t rows, mpd_size_t cols)
{
	mpd_size_t size = mul_size_t(rows, cols);

	assert(ispower2(rows));
	assert(ispower2(cols));

	if (cols == rows) {
		squaretrans_pow2_c(matrix, rows);
	}
	else if (cols == mul_size_t(2, rows)) {
		if (!swap_halfrows_pow2_c(matrix, rows, cols, FORWARD_CYCLE)) {
			return 0;
		}
		squaretrans_pow2_c(matrix, rows);
		squaretrans_pow2_c(matrix+(size/2), rows);
	}
	else if (rows == mul_size_t(2, cols)) {
		squaretrans_pow2_c(matrix, cols);
		squaretrans_pow2_c(matrix+(size/2), cols);
		if (!swap_halfrows_pow2_c(matrix, cols, rows, BACKWARD_CYCLE)) {
			return 0;
		}
	}
	else {
		mpd_err_fatal("transpose_pow2_c: illegal matrix size");
	}

	return 1;
}


#include <time.h>
#define UMOD_ARRAY ((mpd_uint_t)1<<28)
#define UCHAR_ARRAY ((mpd_uint_t)1<<29)

/* The faster in-place functions are tested against std_trans(). */
static int
testit_uint(void (* func)(mpd_uint_t *, mpd_size_t, mpd_size_t), mpd_size_t rows, mpd_size_t cols)
{
	mpd_uint_t *a = NULL, *src = NULL, *dest = NULL;
	clock_t start_fast, end_fast, start_std, end_std;
	mpd_size_t msize;
	mpd_size_t i;
	int ret = 1;

	msize = mul_size_t(rows, cols);
	if ((a = mpd_alloc(msize, sizeof *a)) == NULL) {
		goto error;
	}
	if ((src = mpd_alloc(msize, sizeof *src)) == NULL) {
		goto error;
	}
	if ((dest = mpd_alloc(msize, sizeof *dest)) == NULL) {
		goto error;
	}

	for (i = 0; i < msize; i++) {
		a[i] = src[i] = random();
	}

	start_std= clock();
	std_trans(dest, src, rows, cols);
	end_std= clock();

	start_fast = clock();
	func(a, rows, cols);
	end_fast = clock();

	for (i = 0; i < msize; i++) {
		if (a[i] != dest[i]) {
			fprintf(stderr, "FAIL: a[%"PRI_mpd_size_t"] = %"PRI_mpd_uint_t
                                        "\tdest[%"PRI_mpd_size_t"] = %"PRI_mpd_uint_t"\n",
			        i, a[i], i, dest[i]);
			exit(1);
		}
	}

	fprintf(stderr, "size: %10"PRI_mpd_size_t"\tstd_trans: %6.2f sec\t "
                        "in_place_trans: %6.2f sec\n",
		msize,
		(double)(end_std-start_std)/(double)CLOCKS_PER_SEC,
		(double)(end_fast-start_fast)/(double)CLOCKS_PER_SEC);


out:
	if (a) __mingw_dfp_get_globals()->mpd_free(a);
	if (src) __mingw_dfp_get_globals()->mpd_free(src);
	if (dest) __mingw_dfp_get_globals()->mpd_free(dest);
	return ret;

error:
	ret = 0;
	goto out;
}

/* The faster in-place functions are tested against std_trans(). */
static int
testit_uchar(void (* func)(uint8_t *, mpd_size_t, mpd_size_t), mpd_size_t rows, mpd_size_t cols)
{
	uint8_t *a = NULL, *src = NULL, *dest = NULL;
	clock_t start_fast, end_fast, start_std, end_std;
	mpd_size_t msize;
	mpd_size_t i;
	int ret = 1;

	msize = mul_size_t(rows, cols);
	if ((a = mpd_alloc(msize, sizeof *a)) == NULL) {
		goto error;
	}
	if ((src = mpd_alloc(msize, sizeof *src)) == NULL) {
		goto error;
	}
	if ((dest = mpd_alloc(msize, sizeof *dest)) == NULL) {
		goto error;
	}

	for (i = 0; i < msize; i++) {
		a[i] = src[i] = random();
	}

	start_std= clock();
	std_trans_c(dest, src, rows, cols);
	end_std= clock();

	start_fast = clock();
	func(a, rows, cols);
	end_fast = clock();

	for (i = 0; i < msize; i++) {
		if (a[i] != dest[i]) {
			fprintf(stderr, "FAIL: a[%"PRI_mpd_size_t"] = %d\t"
                                        "dest[%"PRI_mpd_size_t"] = %d\n",
			        i, a[i], i, dest[i]);
			exit(1);
		}
	}

	fprintf(stderr, "size: %10"PRI_mpd_size_t"\tstd_trans: %6.2f sec\t "
                        "in_place_trans: %6.2f sec\n",
		msize,
		(double)(end_std-start_std)/(double)CLOCKS_PER_SEC,
		(double)(end_fast-start_fast)/(double)CLOCKS_PER_SEC);


out:
	if (a) __mingw_dfp_get_globals()->mpd_free(a);
	if (src) __mingw_dfp_get_globals()->mpd_free(src);
	if (dest) __mingw_dfp_get_globals()->mpd_free(dest);
	return ret;

error:
	ret = 0;
	goto out;
}


#define transfunc_uint (void (*)(mpd_uint_t *, mpd_size_t, mpd_size_t))
#define transfunc_uchar (void (*)(uint8_t *, mpd_size_t, mpd_size_t))


int main(void)
{
	mpd_size_t rows, cols;


	fprintf(stderr, "Running test_transpose ... \n");

	fprintf(stderr, "\n2^n * 2^n mpd_uint_t matrices:\n\n");
	for (rows = 1; mul_size_t(rows, rows) <= UMOD_ARRAY; rows *= 2) {
		if (!testit_uint(transfunc_uint transpose_pow2, rows, rows)) {
			break;
		}
	}

	fprintf(stderr, "\n2^n * 2*2^n mpd_uint_t matrices:\n\n");
	for (rows = 8, cols = 16; mul_size_t(rows, cols) <= UMOD_ARRAY; rows *= 2, cols*=2) {
		if (!testit_uint(transfunc_uint transpose_pow2, rows, cols)) {
			break;
		}
	}

	fprintf(stderr, "\n2*2^n * 2^n mpd_uint_t matrices:\n\n");
	for (rows = 16, cols = 8; mul_size_t(rows, cols) <= UMOD_ARRAY; rows *= 2, cols*=2) {
		if (!testit_uint(transfunc_uint transpose_pow2, rows, cols)) {
			break;
		}
	}


	fprintf(stderr, "\n2^n * 2^n uint8_t matrices:\n\n");
	for (rows = 1; mul_size_t(rows, rows) <= UCHAR_ARRAY; rows *= 2) {
		if (!testit_uchar(transfunc_uchar transpose_pow2_c, rows, rows)) {
			break;
		}
	}

	fprintf(stderr, "\n2^n * 2*2^n uint8_t matrices:\n\n");
	for (rows = 8, cols = 16; mul_size_t(rows, cols) <= UCHAR_ARRAY; rows *= 2, cols*=2) {
		if (!testit_uchar(transfunc_uchar transpose_pow2_c, rows, cols)) {
			break;
		}
	}

	fprintf(stderr, "\n2*2^n * 2^n uint8_t matrices:\n\n");
	for (rows = 16, cols = 8; mul_size_t(rows, cols) <= UCHAR_ARRAY; rows *= 2, cols*=2) {
		if (!testit_uchar(transfunc_uchar transpose_pow2_c, rows, cols)) {
			break;
		}
	}

	fprintf(stderr, "\ntest_transpose: PASS\n\n");

	return 0;
}


