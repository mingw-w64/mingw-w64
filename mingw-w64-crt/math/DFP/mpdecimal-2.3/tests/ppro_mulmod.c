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


#ifdef PPRO

#define ANSI

#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "numbertheory.h"
#include "mptypes.h"
#include "mptest.h"
#include "umodarith.h"
#include "malloc_fail.h"

/*
 * These are random tests for the pentium pro modular multiplication functions.
 */

int
main(int argc UNUSED, char **argv)
{
	double dmod;
	uint32_t dinvmod[3];
	mpd_uint_t umod;
	mpd_uint_t a, b, c, d;
	mpd_uint_t a1, a2, b1, b2;
	long i;

	(void)mpd_set_fenv();

	fprintf(stderr, "%s:\n", argv[0]);
	fprintf(stderr, "testing MULMOD ... ");

	srandom((unsigned int)time(NULL));

	SETMODULUS(P1);
	for (i = 0; i < 100000000; i++) {
		a = random()%umod;
		b = random()%umod;
		c = std_mulmod(a, b, umod);
		d = MULMOD(a, b);
		if (c != d) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  ansi: %u "
			                "ppro: %u\n", a, b, c, d);
			exit(1);
		}
	}

	SETMODULUS(P2);
	for (i = 0; i < 100000000; i++) {
		a = random()%umod;
		b = random()%umod;
		c = std_mulmod(a, b, umod);
		d = MULMOD(a, b);
		if (c != d) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  ansi: %u "
			                "ppro: %u\n", a, b, c, d);
			exit(1);
		}
	}

	SETMODULUS(P3);
	for (i = 0; i < 100000000; i++) {
		a = random()%umod;
		b = random()%umod;
		c = std_mulmod(a, b, umod);
		d = MULMOD(a, b);
		if (c != d) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  ansi: %u "
			                "ppro: %u\n", a, b, c, d);
			exit(1);
		}
	}

	fprintf(stderr, "PASS\n");
	fprintf(stderr, "testing MULMOD2C ... ");

	SETMODULUS(P1);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		std_mulmod2c(&a1, &b1, c, umod);
		MULMOD2C(&a2, &b2, c);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, a1, a2, b1, b2);
			exit(1);
		}
	}

	SETMODULUS(P2);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		std_mulmod2c(&a1, &b1, c, umod);
		MULMOD2C(&a2, &b2, c);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, a1, a2, b1, b2);
			exit(1);
		}
	}

	SETMODULUS(P3);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		std_mulmod2c(&a1, &b1, c, umod);
		MULMOD2C(&a2, &b2, c);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, a1, a2, b1, b2);
			exit(1);
		}
	}

	fprintf(stderr, "PASS\n");
	fprintf(stderr, "testing MULMOD2 ... ");

	SETMODULUS(P1);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		d = random()%umod;
		std_mulmod2(&a1, c, &b1, d, umod);
		MULMOD2(&a2, c, &b2, d);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  d: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, d, a1, a2, b1, b2);
			exit(1);
		}
	}

	SETMODULUS(P2);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		d = random()%umod;
		std_mulmod2(&a1, c, &b1, d, umod);
		MULMOD2(&a2, c, &b2, d);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  d: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, d, a1, a2, b1, b2);
			exit(1);
		}
	}

	SETMODULUS(P3);
	for (i = 0; i < 100000000; i++) {
		a1 = a2 = a = random()%umod;
		b1 = b2 = b = random()%umod;
		c = random()%umod;
		d = random()%umod;
		std_mulmod2(&a1, c, &b1, d, umod);
		MULMOD2(&a2, c, &b2, d);
		if (a1 != a2 || b1 != b2) {
			fprintf(stderr, "FAIL:  a: %u  b: %u  c: %u  d: %u  "
                                        "ansi1: %u  ppro1: %u  "
                                        "ansi2: %u  ppro2: %u  ",
			                a, b, c, d, a1, a2, b1, b2);
			exit(1);
		}
	}

	fprintf(stderr, "PASS\n");

	return 0;
}
/* END PPRO_GCC */
#else

int
main(int argc UNUSED, char **argv)
{
	fprintf(stderr, "%s: PASS\n", argv[0]);
	return 0;
}

#endif



