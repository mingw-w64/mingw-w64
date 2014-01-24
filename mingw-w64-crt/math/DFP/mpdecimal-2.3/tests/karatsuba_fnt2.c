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
#include <time.h>
#include "mptypes.h"
#include "mptest.h"


/*
 * Test Karatsuba multiplication with FNT basecase against
 * FNT multiplication.
 */


#define WORDS 1200


int
main(int argc, char **argv)
{
	mpd_uint_t *a, *b;
	mpd_uint_t *fntresult, *kresult;
	mpd_size_t alen, blen, k;
	double total = (WORDS-1)*(WORDS)-12;
	double counter = 0;
	mpd_size_t rsize;
	time_t seed;
	int verbose;

	verbose = !(argc > 1 && strcmp(argv[1], "-q") == 0);

	a = malloc(WORDS * (sizeof *a));
	b = malloc(WORDS * (sizeof *b));

	for (k = 0; k < WORDS; k++) {
		a[k] = MPD_RADIX-1;
	}
	for (k = 0; k < WORDS; k++) {
		b[k] = MPD_RADIX-1;
	}

	if (!verbose) {
		fprintf(stderr, "%s ... ", argv[0]);
	}

	/* test with all digits 9 */
	for (alen = 4; alen < WORDS; alen++) {

		if (verbose) {
			fprintf(stderr, "\r%s: progress: %2.4f%%", argv[0],
			        (counter/total*100));
		}

		for (blen = 1; blen <= alen; blen++) {

			counter++;

			fntresult = _mpd_fntmul(a, b, alen, blen, &rsize);
			kresult = _mpd_kmul_fnt(a, b, alen, blen, &rsize);

			for (k = 0; k < alen+blen; k++) {
				if (kresult[k] != fntresult[k]) {
					fprintf(stderr, " FAIL\n");
					exit(1);
				}
			}

			mpd_free(fntresult);
			mpd_free(kresult);
		}
	}

	/* random test */
	seed = time(NULL);
	srandom((unsigned int)seed);

	for (alen = 4; alen < WORDS; alen++) {

		if (verbose) {
			fprintf(stderr, "\r%s: progress: %2.4f%%", argv[0],
			        (counter/total*100));
		}

		for (k = 0; k < alen; k++) {
			a[k] = random()%MPD_RADIX;
		}

		for (blen = 1; blen <= alen; blen++) {

			counter++;

			for (k = 0; k < blen; k++) {
				b[k] = random()%MPD_RADIX;
			}

			fntresult = _mpd_fntmul(a, b, alen, blen, &rsize);
			kresult = _mpd_kmul_fnt(a, b, alen, blen, &rsize);

			for (k = 0; k < alen+blen; k++) {
				if (kresult[k] != fntresult[k]) {
					fprintf(stderr, " FAIL: seed = %"PRI_time_t"\n", seed);
					exit(1);
				}
			}

			mpd_free(fntresult);
			mpd_free(kresult);
		}
	}

	if (verbose) {
		fprintf(stderr, "\r%s: progress: %2.4f%%", argv[0], 100.0);
	}
	fprintf(stderr, " PASS\n");

	mpd_free(a);
	mpd_free(b);

	return 0;
}


