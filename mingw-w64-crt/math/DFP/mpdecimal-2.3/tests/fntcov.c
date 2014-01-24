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
#include "malloc_fail.h"


/*
 * Code coverage for _mpd_fntmul, _mpd_kmul, and _mpd_kmul_fnt. Since
 * _mpd_kmul_fnt is only triggered for a result length that exceeds
 * 3*MPD_MAXTRANSFORM_2N, the final tests require substantial amounts
 * of RAM.
 *
 * For CONFIG_32, 4-8GB are required, This means that the tests will
 * run comfortably on a 64-bit 8GB machine if the compile option
 * MACHINE=full_coverage is chosen.
 *
 * For CONFIG_64, about 1TB of memory would be needed.
 */


#ifndef _MSC_VER
  #define ASSERT(p) if (!(p)) {abort();}
#else
  #define ASSERT(p) if (!(p)) {mpd_err_fatal("assertion failed");}
#endif

#define MAXWORDS 10000


int
main(void)
{
    uint32_t status = 0;
    mpd_context_t ctx;
    mpd_uint_t *a, *b;
    mpd_uint_t *fntresult, *kresult, *kfntresult;
    mpd_size_t rsize;
    mpd_t *x, *y, *z;
    mpd_ssize_t xl[5] = {MPD_MAXTRANSFORM_2N, 2*MPD_MAXTRANSFORM_2N,
                         4*MPD_MAXTRANSFORM_2N, 4*MPD_MAXTRANSFORM_2N-1,
                         4*MPD_MAXTRANSFORM_2N-1};
    mpd_ssize_t yl[5] = {MPD_MAXTRANSFORM_2N/2, MPD_MAXTRANSFORM_2N,
                         2*MPD_MAXTRANSFORM_2N, 2*MPD_MAXTRANSFORM_2N,
                         32};
    mpd_ssize_t k, alen, blen;
    mpd_ssize_t xlen, ylen;
    time_t seed;
    int i;


    mpd_maxcontext(&ctx);

    a = malloc(MAXWORDS * (sizeof *a));
    b = malloc(MAXWORDS * (sizeof *b));

    for (k = 0; k < MAXWORDS; k++) {
        a[k] = MPD_RADIX-1;
    }
    for (k = 0; k < MAXWORDS; k++) {
        b[k] = MPD_RADIX-1;
    }

    fprintf(stderr, "Running fntcov ... \n\n");
    fprintf(stderr, "  Testing Karatsuba multiplication and number "
                    "theoretic transform ... ");

    /* bignum: all digits 9 */
    for (alen = 1200; alen < MAXWORDS; alen += 1000) {

        fntresult = _mpd_fntmul(a, a, alen, alen, &rsize);
        kresult = _mpd_kmul(a, a, alen, alen, &rsize);
        kfntresult = _mpd_kmul_fnt(a, a, alen, alen, &rsize);

        for (k = 0; k < 2*alen; k++) {
            if (kresult[k] != fntresult[k] || kfntresult[k] != fntresult[k]) {
                fprintf(stderr, " FAIL\n");
                exit(1);
            }
        }

        __mingw_dfp_get_globals()->mpd_free(fntresult);
        __mingw_dfp_get_globals()->mpd_free(kresult);
        __mingw_dfp_get_globals()->mpd_free(kfntresult);

        for (blen = 1200; blen <= alen; blen += 1000) {

            fntresult = _mpd_fntmul(a, b, alen, blen, &rsize);
            kresult = _mpd_kmul(a, b, alen, blen, &rsize);
            kfntresult = _mpd_kmul_fnt(a, b, alen, blen, &rsize);

            for (k = 0; k < alen+blen; k++) {
                if (kresult[k] != fntresult[k] || kfntresult[k] != fntresult[k]) {
                    fprintf(stderr, " FAIL\n");
                    exit(1);
                }
            }

            __mingw_dfp_get_globals()->mpd_free(fntresult);
            __mingw_dfp_get_globals()->mpd_free(kresult);
            __mingw_dfp_get_globals()->mpd_free(kfntresult);
        }
    }

    /* Bignum: random test */
    seed = time(NULL);
    srandom((unsigned int)seed);

    for (alen = 1200; alen < MAXWORDS; alen += 1000) {

        for (k = 0; k < alen; k++) {
            a[k] = random()%MPD_RADIX;
        }

        fntresult = _mpd_fntmul(a, a, alen, alen, &rsize);
        kresult = _mpd_kmul(a, a, alen, alen, &rsize);
        kfntresult = _mpd_kmul_fnt(a, a, alen, alen, &rsize);

        for (k = 0; k < 2*alen; k++) {
            if (kresult[k] != fntresult[k] || kfntresult[k] != fntresult[k]) {
                fprintf(stderr, " FAIL: seed = %"PRI_time_t"\n", seed);
                exit(1);
            }
        }

        __mingw_dfp_get_globals()->mpd_free(fntresult);
        __mingw_dfp_get_globals()->mpd_free(kresult);
        __mingw_dfp_get_globals()->mpd_free(kfntresult);

        for (blen = 1200; blen <= alen; blen += 1000) {

            for (k = 0; k < blen; k++) {
                b[k] = random()%MPD_RADIX;
            }

            fntresult = _mpd_fntmul(a, b, alen, blen, &rsize);
            kresult = _mpd_kmul(a, b, alen, blen, &rsize);
            kfntresult = _mpd_kmul_fnt(a, b, alen, blen, &rsize);

            for (k = 0; k < alen+blen; k++) {
                if (kresult[k] != fntresult[k] || kfntresult[k] != fntresult[k]) {
                    fprintf(stderr, " FAIL: seed = %"PRI_time_t"\n", seed);
                    exit(1);
                }
            }

            __mingw_dfp_get_globals()->mpd_free(fntresult);
            __mingw_dfp_get_globals()->mpd_free(kresult);
            __mingw_dfp_get_globals()->mpd_free(kfntresult);
        }
    }

    /* Excessive lengths */
    fntresult = _mpd_fntmul(a, a, 2*MPD_MAXTRANSFORM_2N, 2*MPD_MAXTRANSFORM_2N,
                            &rsize);
    ASSERT(fntresult == NULL)

    /* Allocation failures */
    for (alen=500, blen = 500; alen <= 4000; alen+=3500, blen+=1500) {

        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            fntresult = _mpd_fntmul(a, a, alen, alen, &rsize);
            mpd_set_alloc(&ctx);

            if (fntresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(fntresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            fntresult = _mpd_fntmul(a, b, alen, blen, &rsize);
            mpd_set_alloc(&ctx);

            if (fntresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(fntresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            kresult = _mpd_kmul(a, a, alen, alen, &rsize);
            mpd_set_alloc(&ctx);

            if (kresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(kresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            kresult = _mpd_kmul(a, b, alen, blen, &rsize);
            mpd_set_alloc(&ctx);

            if (kresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(kresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            kfntresult = _mpd_kmul_fnt(a, a, alen, alen, &rsize);
            mpd_set_alloc(&ctx);

            if (kfntresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(kfntresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {

            mpd_set_alloc_fail(&ctx);
            kfntresult = _mpd_kmul_fnt(a, b, alen, blen, &rsize);
            mpd_set_alloc(&ctx);

            if (kfntresult != NULL) {
                __mingw_dfp_get_globals()->mpd_free(kfntresult);
                if (alloc_idx < alloc_fail) {
                    break;
                }
            }
        }
    }

    __mingw_dfp_get_globals()->mpd_free(a);
    __mingw_dfp_get_globals()->mpd_free(b);


    /* Huge numbers */
    fprintf(stderr, "\n\n  Long test, requires more than 4GB of memory ... \n\n");

    x = mpd_new(&ctx);
    y = mpd_new(&ctx);
    z = mpd_new(&ctx);

    ctx.traps = 0;
    /* NOT safe, but works for this test. */
    ctx.emax = MPD_SSIZE_MAX;
    ctx.prec = MPD_SSIZE_MAX;
    for (i = 0; i < 5; i++) {

        xlen = xl[i];
        ylen = yl[i];
        fprintf(stderr, "    op1: %11"PRI_mpd_ssize_t" words    op2: "
                        "%11"PRI_mpd_ssize_t" words\n", xlen, ylen);

        if (!mpd_qresize(x, xlen, &status)) {
            goto malloc_error;
        }
        for (k = 0; k < xlen; k++) {
            x->data[k] = MPD_RADIX-1;
        }
        x->len = xlen;
        x->exp = 0;
        mpd_setdigits(x);

        if (!mpd_qresize(y, ylen, &status)) {
            goto malloc_error;
        }
        for (k = 0; k < ylen; k++) {
            y->data[k] = MPD_RADIX-1;
        }
        y->len = ylen;
        y->exp = 0;
        mpd_setdigits(y);

        ctx.status = 0;
        mpd_mul(z, x, y, &ctx);
        if (mpd_isnan(z)) {
            ASSERT(ctx.status&MPD_Malloc_error);
            goto malloc_error;
        }

        ASSERT(z->data[0] == 1)
        for (k = 1; k < ylen; k++) {
            ASSERT(z->data[k] == 0)
        }
        for (; k < xlen; k++) {
            ASSERT(z->data[k] == MPD_RADIX-1);
        }
        ASSERT(z->data[k] == MPD_RADIX-2)
        k++;
        for (; k < xlen+ylen; k++) {
            ASSERT(z->data[k] == MPD_RADIX-1);
        }

#if 0
        /* Allocation failures: Only reasonable to test with an
         * artificially small MPD_MAXTRANSFORM_2N. For example,
         * with MPD_MAXTRANSFORM_2N=4096 coverage of _mpd_kmul_fnt
         * is 100%, i.e. also lines tagged with GCOV_UNLIKELY are
         * reached.
         */
        for (alloc_fail = 1; alloc_fail < INT_MAX; alloc_fail++) {
            ctx.status = 0;

            mpd_set_alloc_fail(&ctx);
            mpd_mul(z, x, y, &ctx);
            mpd_set_alloc(&ctx);

            if (!(ctx.status&MPD_Malloc_error)) {
                if (alloc_idx < alloc_fail) {
                    printf("alloc_idx: %d\n", alloc_idx);
                    break;
                }
            }
            else {
                ASSERT(mpd_isnan(z));
            }
        }
#endif
    }

    fprintf(stderr, "\nfntcov: PASS\n\n");

out:
    mpd_del(x);
    mpd_del(y);
    mpd_del(z);
    return 0;


malloc_error:
    fprintf(stderr, "\nfntcov: out of memory: this test requires large "
                    "amounts of memory\n\n");
    goto out;
}


