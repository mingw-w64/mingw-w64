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
#include <time.h>
#include <gmp.h>
#include "mptypes.h"


/*
 * Test mpd_add against mpz_add, for all possible lengths
 * (in decimal digits) from 1x1 upto (WORDS*MPD_RDIGITS)x(WORDS*MPD_RDIGITS).
 */


#define WORDS 80


int
main(int argc, char **argv)
{
    mpd_context_t ctx;
    mpd_t *a, *b, *c;
    mpz_t x, y, z;
    mpd_ssize_t ma;
    char *mpdresult, *mpzresult;
    char *s;
    size_t alen, blen, k;
    double total = (WORDS*MPD_RDIGITS)*(WORDS*MPD_RDIGITS)*63;
    double counter = 0;
    time_t seed;
    int verbose;

    verbose = !(argc > 1 && strcmp(argv[1], "-q") == 0);

    mpd_maxcontext(&ctx);
    s = malloc(WORDS*MPD_RDIGITS+1);
    seed = time(NULL);
    srandom((unsigned int)seed);

    if (!verbose) {
        fprintf(stderr, "%s ... ", argv[0]);
    }

    for (ma = MPD_MINALLOC_MIN; ma <= MPD_MINALLOC_MAX; ma++) {

        /* DON'T do this in a real program. You have to be sure
         * that no previously allocated decimals will ever be used. */
        MPD_MINALLOC = ma;

        a = mpd_new(&ctx);
        b = mpd_new(&ctx);
        c = mpd_new(&ctx);
        mpz_init(x);
        mpz_init(y);
        mpz_init(z);

        for (alen = 1; alen <= WORDS*MPD_RDIGITS; alen++) {

            if (verbose) {
                fprintf(stderr, "\r%s: progress: %2.4f%%", argv[0],
                        (counter/total*100));
            }

            for (k = 0; k < alen; k++) {
                s[k] = '0' + random()%10;
            }
            s[k] = '\0';
            mpd_set_string(a, s, &ctx);
            mpz_set_str(x, s, 10);

            for (blen = 1; blen <= WORDS*MPD_RDIGITS; blen++) {

                counter++;

                for (k = 0; k < blen; k++) {
                    s[k] = '0' + random()%10;
                }
                s[k] = '\0';

                mpd_set_string(b, s, &ctx);
                mpz_set_str(y, s, 10);

                mpd_add(c, a, b, &ctx);
                mpdresult = mpd_to_sci(c, 1);

                mpz_add(z, x, y);
                mpzresult = mpz_get_str(NULL, 10, z);

                if (strcmp(mpzresult, mpdresult) != 0) {
                    fprintf(stderr, " FAIL: seed = %"PRI_time_t"\n", seed);
                    exit(1);
                }

                mpd_free(mpdresult);
                mpd_free(mpzresult);
            }
        }

        mpd_del(a);
        mpd_del(b);
        mpd_del(c);
        mpz_clear(x);
        mpz_clear(y);
        mpz_clear(z);
    }

    free(s);
    if (verbose) {
        fprintf(stderr, "\r%s: progress: %2.4f%%", argv[0], 100.0);
    }
    fprintf(stderr, " PASS\n");

    return 0;
}


