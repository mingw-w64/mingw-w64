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


#ifdef _MSC_VER
  #define llabs _abs64
#else
  #define _XOPEN_SOURCE 600
  #include <inttypes.h>
#endif

#include "mpdecimal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "io.h"
#include "memory.h"
#include "mptest.h"
#include "mptypes.h"
#include "malloc_fail.h"

#define DECCHECK 1
#define  DECNUMDIGITS 10000
#include "decNumber.h"


#define MAXOP DECNUMDIGITS
/* string operands */
static char cop1[MAXOP];
static char cop2[MAXOP];
static char cop3[MAXOP];

/* libmpdec contexts and operands */
static mpd_context_t mctx;
static mpd_context_t m_maxctx;
static mpd_t *mop1, *mop2, *mop3;
static mpd_t *mresult;
static mpd_t *mtmp;

/* decNumber contexts and operands */
static decContext dctx;
static decContext d_maxctx;
static decNumber dop1, dop2, dop3;
static decNumber dresult;

/* decNumber result strings */
static char dsci[DECNUMDIGITS+14];
static char deng[DECNUMDIGITS+14];

static mpd_ssize_t rt_pow10[] = {
  1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};

/* return value */
static int retval = 0;
static int exit_on_error = 0;

/* command line options */
static int verbose = 0;
static int short_tests = 0;

/* rudimentary statistics */
static uint64_t counter = 0;
static uint64_t nans = 0;
static uint64_t infinities = 0;
static uint64_t subnormals = 0;
static uint64_t zeros = 0;
static uint64_t skipped = 0;
static uint64_t skipped_flags = 0;


/* ========================================================================== */
/*                                Function IDs                                */
/* ========================================================================== */

enum {
  /* Standard unary functions */
  ABS, EXP, LN, LOG10, LOGB, MINUS, NEXTMINUS, NEXTPLUS, PLUS, REDUCE,
  SQRT, TOINT, TOINTX,
  /* Logical unary functions */
  INVERT,
  /* Char unary functions */
  TOSCI, TOENG,
  /* Const char unary functions */
  CLASS,
  /* Copy unary functions */
  COPY, COPYABS, COPYNEG,
  /* Standard binary functions */
  ADD, DIV, NDIV, DIVINT, MAX, MAXMAG, MIN, MINMAG, MULTIPLY,
  NEXTTWRD, POWER, QUANTIZE, REM, NREM, REMNEAR,
  ROTATE, SCALEB, SHIFT, SUBTRACT,
  /* Logical binary functions */
  AND, OR, XOR,
  /* Copy binary functions */
  COPYSIGN,
  /* Compare binary functions taking a context */
  CMP, CMPSIG,
  /* Compare binary functions */
  CMPT, CMPTMAG,
  /* Int binary functions */
  SAMEQUANT,
  /* Standard ternary functions */
  FMA,
  /* GUARD */
  MAXID
};

enum {UN, BN, TN};
struct ts;
typedef struct ts {
  const int id;
  const char *name;
  const int restricted;
  const int type;
  void (* testfunc)(const struct ts *);
  const void *mfunc;
  const void *dfunc;
} testset;


/* ========================================================================== */
/*                                   Contexts                                 */
/* ========================================================================== */

/* Restricted emax/emin (999999/-999999) for decNumber */
enum {NOT_RE, RE};
/* Min/Max Exponents */
#define IEEE_MAX 3
static mpd_ssize_t ieee_prec[] = {  7,   16,    34};
static mpd_ssize_t ieee_emax[] = { 96,  384,  6144};
static mpd_ssize_t ieee_emin[] = {-95, -383, -6143};
/* Rounding modes */
static int mround[] = {
  MPD_ROUND_UP, MPD_ROUND_DOWN, MPD_ROUND_CEILING, MPD_ROUND_FLOOR,
  MPD_ROUND_HALF_UP, MPD_ROUND_HALF_DOWN, MPD_ROUND_HALF_EVEN, MPD_ROUND_05UP
};
static int dround[] = {
  DEC_ROUND_UP, DEC_ROUND_DOWN, DEC_ROUND_CEILING, DEC_ROUND_FLOOR,
  DEC_ROUND_HALF_UP, DEC_ROUND_HALF_DOWN, DEC_ROUND_HALF_EVEN, DEC_ROUND_05UP
};

static void
mpd_readcontext(mpd_context_t *mctx, decContext *dctx)
{
	mctx->prec=DECNUMDIGITS;
	mctx->emax=999999999;
	mctx->emin=-999999999;
	mctx->round=MPD_ROUND_HALF_UP;
	mctx->traps=MPD_Traps;
	mctx->traps=0;
	mctx->status=0;
	mctx->newtrap=0;
	mctx->clamp=0;
	mctx->allcr=0;

	dctx->digits=DECNUMDIGITS;
	dctx->emax=999999999;
	dctx->emin=-999999999;
	dctx->round=DEC_ROUND_HALF_UP;
	dctx->traps=DEC_NaNs;
	dctx->traps=0;
	dctx->status=0;
	dctx->clamp=0;
}

static void
mpd_testcontext(mpd_context_t *mctx, decContext *dctx)
{
	mctx->prec=DECNUMDIGITS;
	mctx->emax=999999999;
	mctx->emin=-999999999;
	mctx->round=MPD_ROUND_HALF_UP;
	mctx->traps=0;
	mctx->status=0;
	mctx->newtrap=0;
	mctx->clamp=0;
	mctx->allcr=0;

	dctx->digits=DECNUMDIGITS;
	dctx->emax=999999999;
	dctx->emin=-999999999;
	dctx->round=DEC_ROUND_HALF_UP;
	dctx->traps=0;
	dctx->status=0;
	dctx->clamp=0;
}

static void
mpd_restrcontext(mpd_context_t *mctx, decContext *dctx)
{
	mctx->emax=999999;
	mctx->emin=-999999;

	dctx->emax=999999;
	dctx->emin=-999999;
}
 

/* ========================================================================== */
/*                               Print Errors                                 */
/* ========================================================================== */

/* decNumber flags as a list */
void
decflags_as_list(char dest[], uint32_t status)
{
	size_t len;
	dest[0] = '[';
	dest[1] = '\0';
	if (status&DEC_Clamped)              strcat(dest, "Clamped, ");
	if (status&DEC_Conversion_syntax)    strcat(dest, "Conversion_syntax, ");
	if (status&DEC_Division_by_zero)     strcat(dest, "Division_by_zero, ");
	if (status&DEC_Division_impossible)  strcat(dest, "Division_impossible, ");
	if (status&DEC_Division_undefined)   strcat(dest, "Division_undefined, ");
	if (status&DEC_Insufficient_storage) strcat(dest, "Insufficient_storage, ");
	if (status&DEC_Inexact)              strcat(dest, "Inexact, ");
	if (status&DEC_Invalid_context)      strcat(dest, "Invalid_context, ");
	if (status&DEC_Invalid_operation)    strcat(dest, "Invalid_operation, ");
	if (status&DEC_Overflow)             strcat(dest, "Overflow, ");
	if (status&DEC_Rounded)              strcat(dest, "Rounded, ");
	if (status&DEC_Subnormal)            strcat(dest, "Subnormal, ");
	if (status&DEC_Underflow)            strcat(dest, "Underflow, ");
	len = strlen(dest) - 1;
	while(dest[len] == ' ' || dest[len] == ',')
		len--;
	dest[len+1] = ']';
	dest[len+2] = '\0';
}

/* translate decNumber rounding constants to strings */
static const char *dec_round_string[] = {
  "ROUND_CEILING",
  "ROUND_UP",
  "ROUND_HALF_UP",
  "ROUND_HALF_EVEN",
  "ROUND_HALF_DOWN",
  "ROUND_DOWN",
  "ROUND_FLOOR",
  "ROUND_05UP",
  "ROUND_MAX"
};

static void
print_contexts(void)
{
	char m_traps_list[MPD_MAX_FLAG_LIST];
	char m_status_list[MPD_MAX_FLAG_LIST];
	char d_traps_list[MPD_MAX_FLAG_LIST];
	char d_status_list[MPD_MAX_FLAG_LIST];

	mpd_lsnprint_flags(m_traps_list, MPD_MAX_FLAG_LIST, mctx.traps, NULL);
	mpd_lsnprint_flags(m_status_list, MPD_MAX_FLAG_LIST, mctx.status, NULL);
	decflags_as_list(d_traps_list, dctx.traps);
	decflags_as_list(d_status_list, dctx.status);

	printf("mctx(prec=%"PRI_mpd_ssize_t", emax=%"PRI_mpd_ssize_t""
	       ", emin=%"PRI_mpd_ssize_t", traps=%s, status=%s, "
 	       "round=%s, clamp=%d)\n",
 	       mctx.prec, mctx.emax, mctx.emin,
	       m_traps_list, m_status_list,
	       mpd_round_string[mctx.round],
	       mctx.clamp);

	printf("dctx(prec=%d, emax=%d, emin=%d, traps=%s, status=%s, "
 	       "round=%s, clamp=%d)\n\n",
 	       dctx.digits, dctx.emax, dctx.emin,
	       d_traps_list, d_status_list,
	       dec_round_string[dctx.round],
	       dctx.clamp);
	fflush(stdout);
}

static void
print_err(const testset *t, const char *msci, const char *dsci,
          const char *meng, const char *deng)
{
	switch (t->type) {
	case UN:
		printf("%s   %s\n", t->name, cop1);
		break;
	case BN:
		printf("%s   %s   %s\n", t->name, cop1, cop2);
		break;
	case TN:
		printf("%s   %s   %s   %s\n", t->name, cop1, cop2, cop3);
		break;
	default:
		abort();
	}

	if (meng) {
		printf("msci: %s   meng: %s\n", msci, meng);
		printf("dsci: %s   deng: %s\n\n", dsci, deng);
	}
	else {
		printf("msci: %s\n", msci);
		printf("dsci: %s\n\n", dsci);
	}
	fflush(stdout);
	print_contexts();
}


/* ========================================================================== */
/*                              Compare Results                               */
/* ========================================================================== */

static int
compare_contexts(void)
{
	if (!!(mctx.status&MPD_Clamped)             != !!(dctx.status&DEC_Clamped) ||
	    !!(mctx.status&MPD_Conversion_syntax)   != !!(dctx.status&DEC_Conversion_syntax) ||
	    !!(mctx.status&MPD_Division_by_zero)    != !!(dctx.status&DEC_Division_by_zero) ||
	    !!(mctx.status&MPD_Division_impossible) != !!(dctx.status&DEC_Division_impossible) ||
	    !!(mctx.status&MPD_Division_undefined)  != !!(dctx.status&DEC_Division_undefined) ||
	    !!(mctx.status&MPD_Inexact)             != !!(dctx.status&DEC_Inexact) ||
	    !!(mctx.status&MPD_Invalid_context)     != !!(dctx.status&DEC_Invalid_context) ||
	    !!(mctx.status&MPD_Invalid_operation)   != !!(dctx.status&DEC_Invalid_operation) ||
	    !!(mctx.status&MPD_Malloc_error)        != !!(dctx.status&DEC_Insufficient_storage) ||
	    !!(mctx.status&MPD_Overflow)            != !!(dctx.status&DEC_Overflow) ||
	    !!(mctx.status&MPD_Rounded)             != !!(dctx.status&DEC_Rounded) ||
	    !!(mctx.status&MPD_Subnormal)           != !!(dctx.status&DEC_Subnormal) ||
	    !!(mctx.status&MPD_Underflow)           != !!(dctx.status&DEC_Underflow)) {
		return 0;
	}

	return 1;
}

static void
harrison_ulp(mpd_t *ulp, mpd_t *dec)
{
	mpd_context_t ctx;
	mpd_t *a, *b;

	ctx = mctx;
	a = mpd_qnew();
	b = mpd_qnew();
	mpd_next_plus(a, dec, &ctx);
	mpd_next_minus(b, dec, &ctx);
	mpd_sub(ulp, a, b, &ctx);
	mpd_abs(ulp, ulp, &ctx);
	mpd_del(a);
	mpd_del(b);
}

static void
standard_ulp(mpd_t *ulp, mpd_t *dec, mpd_ssize_t prec)
{
	mpd_context_t ctx;

	ctx = mctx;
	mpd_set_uint(ulp, 1, &ctx);
	ulp->exp = dec->exp + dec->digits - prec;
}

enum {LIBMPDEC, LIBDECNUMBER};
static int
check_ulpdiff(int lib, mpd_t *exact, mpd_t *rounded)
{
	mpd_context_t maxcontext, ctx;
	mpd_t *x, *y;
	mpd_t *t, *ulp, *err;
	const char *maxerr = "1.1";
	int ret;

	ctx = mctx;
	mpd_maxcontext(&maxcontext);
	maxcontext.traps = 0;
	maxcontext.emax = 1000000000;
	maxcontext.emin = -1000000000;


	/* Convert infinities to the largest representable number + 1ULP. */
	x = exact;
	if (!mpd_iszero(exact) && mpd_adjexp(exact) > ctx.emax) {
		/* If the exact result is in infinity territory, decNumber is
		 * sometimes off by several ulps from the exact result, but
		 * within one ulp from round(exact) = Infinity. */
		x = mpd_qnew();
		mpd_set_string(x, "10", &maxcontext);
		x->exp = ctx.emax;
		mpd_signcpy(x, exact);
	}
	y = rounded;
	if (mpd_isinfinite(rounded)) {
		y = mpd_qnew();
		mpd_set_string(y, "10", &maxcontext);
		y->exp = ctx.emax;
		mpd_signcpy(y, exact);
	}

	t = mpd_qnew();
	ulp = mpd_qnew();
	err = mpd_qnew();

	/* err = (rounded - exact) / ulp(rounded) */
	maxcontext.prec = ctx.prec <= 5 ? 10 : 2*ctx.prec;
	mpd_sub(t, y, x, &maxcontext);
	if ((lib == LIBMPDEC &&
	      (mctx.status&MPD_Clamped ||
	       mctx.status&MPD_Underflow)) ||
	    (lib == LIBDECNUMBER &&
	      (dctx.status&DEC_Clamped ||
	       dctx.status&DEC_Underflow))) {
		harrison_ulp(ulp, y);
	}
	else {
		standard_ulp(ulp, y, ctx.prec);
	}
	mpd_div(err, t, ulp, &maxcontext);
	mpd_abs(err, err, &maxcontext);

	mpd_set_string(t, maxerr, &maxcontext);
	ret = (mpd_cmp(err, t, &maxcontext) < 0) ? 1 : 0;

	if (x != exact) mpd_del(x);
	if (y != rounded) mpd_del(y);
	mpd_del(t);
	mpd_del(ulp);
	mpd_del(err);

	return ret;
}

static int
resolve_ulp(const testset *t, const char *dsci)
{
	mpd_context_t maxcontext, ctx;
	mpd_t *exact, *rounded;
	int ret = 1;

	ctx = mctx;
	mpd_maxcontext(&maxcontext);
	maxcontext.prec = ctx.prec <= 5 ? 10 : 2*ctx.prec;
	maxcontext.traps = 0;

	exact = mpd_qnew();
	switch (t->id) {
	case EXP:
		mpd_exp(exact, mop1, &maxcontext);
		break;
	case LN:
		mpd_ln(exact, mop1, &maxcontext);
		break;
	case LOG10:
		mpd_log10(exact, mop1, &maxcontext);
		break;
	case POWER:
		mpd_pow(exact, mop1, mop2, &maxcontext);
		break;
	/* decNumber: Issue 1: incorrect rounding in add/subtract/fma */
	case ADD:
		mpd_add(exact, mop1, mop2, &maxcontext);
		break;
	case SUBTRACT:
		mpd_sub(exact, mop1, mop2, &maxcontext);
		break;
	case FMA:
		mpd_fma(exact, mop1, mop2, mop3, &maxcontext);
		break;
	/* End Issue 1 */
	default:
		mpd_del(exact);
		return 0;
	}

	/* test mpd_t result */
	rounded = mresult;
	if (!check_ulpdiff(LIBMPDEC, exact, rounded)) {
		ret = 0;
	}

	/* test decNumber result */
	rounded = mpd_qnew();
	mpd_set_string(rounded, dsci, &maxcontext);
	if (!check_ulpdiff(LIBDECNUMBER, exact, rounded)) {
		ret = 0;
	}

	mpd_del(exact);
	mpd_del(rounded);
	return ret;
}

static void
compare_results(const testset *t)
{
	char *msci;
	char *meng;
	int have_dot;
	int skip_contexts = 0;
	char *mp;
	char *dp;

	msci = mpd_to_sci(mresult, 1);
	meng = mpd_to_eng(mresult, 1);
	decNumberToString(&dresult, dsci);
	decNumberToEngString(&dresult, deng);

	/*  NaN payload differences: skip for all functions */
	if (mpd_isnan(mresult) && decNumberIsNaN(&dresult)) {
		/* In IEEE 754 interchange formats a NaN payload has one
		   digit fewer. libmpdec applies this rule whenever 'clamp'
		   is set. */
		if (mctx.clamp)
			goto skip;
		/* decNumber allows the first digit of the payload to be zero. */
		if (strstr(dsci, "NaN0"))
			goto skip;
		/* decNumber: Issue 19: If the second operand is sNaN and the
		   third operand is outside the allowed range, decNumber generates
		   a NaN from the third operand, i.e. it does not use the payload
		   from the second operand. */
		if (t->id == FMA) {
			goto skip;
		}
	}

	/* decNumber restrictions */
	if (t->restricted && !(mctx.status&MPD_Invalid_operation) &&
	    dctx.status&DEC_Invalid_operation)
		goto skip;

	/* Function specific skips */
	switch (t->id) {
	case ADD: case FMA: case SUBTRACT:
		/* decNumber: Issue 2: Overflow status in add/subtract */
		/* decNumber: Issue 3: Clamped status in add/subtract */
		if (mctx.round == MPD_ROUND_05UP ||
		    mctx.round == MPD_ROUND_DOWN ||
		    mctx.round == MPD_ROUND_CEILING ||
		    mctx.round == MPD_ROUND_FLOOR) {
			if ((!!(mctx.status&MPD_Overflow) != !!(dctx.status&DEC_Overflow)) ||
			    ((mctx.status&MPD_Clamped) && !(dctx.status&DEC_Clamped))) {
				skip_contexts = 1;
			}
		
		}
		/* decNumber: Issue 4: Subnormal/Underflow status in add/subtract */
		if (!!(dctx.status&DEC_Subnormal) != !!(mctx.status&MPD_Subnormal) &&
		    !!(dctx.status&DEC_Underflow) != !!(mctx.status&MPD_Underflow)) {
			skip_contexts = 1;
		}
		/* decNumber: Issue 5: Inexact status in add/subtract */
		if (dctx.status == (DEC_Rounded|DEC_Inexact) &&
		    mctx.status == MPD_Rounded) {
			skip_contexts = 1;
		}
		break;
	case AND: case OR: case XOR:
		/* decNumber: Issue 6: Logical functions with invalid excess digits */
		if (mop1->digits > mctx.prec || mop2->digits > mctx.prec) {
			if (mctx.status==MPD_Invalid_operation &&
			    dctx.status==0)
				goto skip;
		}
		break;
	case EXP:
		/* decNumber: Flag-issue 1: Subnormal status in exp */
		if (mctx.status==(MPD_Rounded|MPD_Inexact) &&
		    dctx.status==(DEC_Rounded|DEC_Inexact|DEC_Subnormal)) {
			skip_contexts = 1;
		}
		break;
	case INVERT:
		/* decNumber: Issue 6: Logical functions with invalid excess digits */
		if (mop1->digits > mctx.prec) {
			if (mctx.status==MPD_Invalid_operation &&
			    dctx.status==0)
				goto skip;
		}
		break;
	case LN:
		/* decNumber: Overflow not set in ln. This is a side effect
		              of the patch for Issue 20. */
		if (((mctx.status&MPD_Overflow) && !(dctx.status&DEC_Overflow)) ||
		    ((mctx.status&MPD_Subnormal) && !(dctx.status&DEC_Subnormal))) {
			skip_contexts = 1;
		}
		break;
	case LOG10:
		/* decNumber: Issue 7: NaN payload exceeding precision */
		if (mpd_isnan(mresult) && decNumberIsNaN(&dresult)) {
			if (strlen(msci) != strlen(dsci))
				goto skip;
		}
		/* decNumber: Overflow not set in ln. This is a side effect
		              of the patch for Issue 20. */
		if (((mctx.status&MPD_Overflow) && !(dctx.status&DEC_Overflow)) ||
		    ((mctx.status&MPD_Subnormal) && !(dctx.status&DEC_Subnormal))) {
			skip_contexts = 1;
		}
		/* decNumber: Issue 18: no Overflow to -Infinity */
		if (mpd_isnegative(mresult) && mpd_isinfinite(mresult) &&
		    !decNumberIsInfinite(&dresult)) {
			goto skip;
		}
		break;
	case NEXTMINUS: case NEXTPLUS:
		/* decNumber: Issue 8: incorrect results in next_minus and next_plus */
		if (mresult->exp == mpd_etiny(&mctx)) goto skip;
		if (llabs(mop1->exp) > 999999999L) goto skip;
		break;
	case NEXTTWRD:
		/* "In the first two cases, flags are set as though the operation had
		    been computed by adding (in the first case) or subtracting
		    (in the second) an infinitesimally small positive value to or from
		    the first operand with the rounding mode set to be round-ceiling or
		    round-floor respectively." */
		if (mpd_iszero(mresult))
			/* status??? */
			goto skip;
		if ((mctx.status&MPD_Inexact))
			/* status??? */
			goto skip;
		/* decNumber: similar to issue 8 */
		if (mresult->exp == mpd_etiny(&mctx)) goto skip;
		if (llabs(mop1->exp) > 999999999L) goto skip;
		break;
	case POWER:
		/* decNumber: Issue 9: incorrect power result */
		if (mctx.status==(MPD_Inexact|MPD_Overflow|MPD_Rounded) &&
		    (strcmp("1", dsci) == 0 || strcmp("-1", dsci) == 0))
			goto skip;
		/* decNumber: Issue 10: rounding to infinity */
		if ((mctx.round == MPD_ROUND_FLOOR || mctx.round == MPD_ROUND_DOWN ||
		     mctx.round == MPD_ROUND_05UP || mctx.round == MPD_ROUND_CEILING) &&
		     mpd_isfinite(mresult) && decNumberIsInfinite(&dresult))
			goto skip;
		/* decNumber: Integer exponents must be in the range
		              -1999999997 through +999999999. */
		if (!mpd_isnan(mresult) && decNumberIsNaN(&dresult))
			goto skip;
		/* decNumber: Flag-issue 2: Clamped status in power */
		if (!(mctx.status&MPD_Clamped) && (dctx.status&DEC_Clamped)) {
			skip_contexts = 1;
		}
		/* decNumber: Flag-issue 3: Rounded status in power */
		if (!!(mctx.status&MPD_Rounded) != !!(dctx.status&DEC_Rounded)) {
			skip_contexts = 1;
		}
		/* Always having the same values for Subnormal/Underflow is hard */
		if (!!(mctx.status&MPD_Underflow) != !!(dctx.status&DEC_Underflow)) {
			skip_contexts = 1;
		}
		/* Always having the same values for Overflow is hard */
		if (!!(mctx.status&MPD_Overflow) != !!(dctx.status&DEC_Overflow)) {
			skip_contexts = 1;
		}
		break;
	case QUANTIZE:
		/* decNumber: Issue 11: Infinity result with normal operand */
		if (mpd_isnan(mresult) && decNumberIsInfinite(&dresult))
			goto skip;
		/* decNumber: Issue 12: Inexact/Rounded with NaN result */
		if (mpd_isnan(mresult) && decNumberIsNaN(&dresult)) {
			if ((mctx.status&MPD_Invalid_operation) &&
			    (dctx.status&DEC_Invalid_operation) &&
			    ((dctx.status|DEC_Inexact) || (dctx.status|DEC_Rounded)))
				goto skip;
		}
		break;
	case REM: case NREM: case REMNEAR:
		/* decNumber: Issue 13: ideal exponent and status for
		              remainder(0, x), rem_near(0, x) */
		if (mpd_iszero(mresult) && decNumberIsZero(&dresult) &&
		    (mctx.status&MPD_Clamped))
			goto skip;
		break;
	case ROTATE:
		/* decNumber: Issue 14: rotate with excess input digits */
		if (mop1->digits > mctx.prec) goto skip;
		break;
	case SCALEB:
		/* decNumber: Issue 15: scaleb with excess input digits */
		if (mop1->digits > mctx.prec) goto skip;
		/* decNumber limits the maximum exponent difference. */
		if ((dctx.status&DEC_Invalid_operation) &&
		    !(mctx.status&MPD_Invalid_operation))
			goto skip;
		break;
	case SHIFT:
		/* decNumber: Issue 16: shift with excess input digits */
		if (mop1->digits > mctx.prec) goto skip;
		break;
	case SQRT:
		/* decNumber: Issue 17: squareroot zero padding */
		have_dot = 0;
		mp = msci;
		dp = dsci;
		while (*dp && *mp == *dp) {
			if (*dp == '.') have_dot = 1;
			dp++; mp++;
		}
		if (have_dot && (*dp == '\0' || *dp == 'E') && *mp == '0') {
			/* skip zeros */
			while (*mp == '0') mp++;
		}
		if (strcmp(dp, mp) == 0) {
			/* decNumber: Issue 20: square root status */
			if ((mctx.status&MPD_Rounded) &&
			    (mctx.status&MPD_Inexact) &&
			    !(dctx.status&DEC_Rounded) &&
			    !(dctx.status&DEC_Inexact)) {
				goto skip;
			}
			goto cmp_contexts;
		}
		break;
	case TOINT: case TOINTX:
		/* Might be respecified. */
		if (mop1->digits > mctx.prec) {
			if (mctx.clamp) goto skip;
			if (mctx.status==MPD_Invalid_operation &&
			    (dctx.status&DEC_Invalid_operation))
				/* decNumber sets Rounded and/or Inexact */
				goto skip;
			/* quantize */
			if (!!(mctx.status&MPD_Invalid_operation) !=
			    !!(dctx.status&DEC_Invalid_operation))
				goto skip;
			/* quantize infinity in decNumber */
			if (decNumberIsInfinite(&dresult))
				goto skip;
		}
		break;
	default:
		break;
	}

	if (strcmp(msci, dsci) || strcmp(meng, deng)) {
		/* resolve_ulp() is undefined for NaNs. */
		if (!!mpd_isnan(mresult) != !!decNumberIsNaN(&dresult)) {
			print_err(t, msci, dsci, meng, deng);
			retval = EXIT_FAILURE;
			if (exit_on_error) {
				exit(retval);
			}
		}
		else if (!resolve_ulp(t, dsci)) {
			print_err(t, msci, dsci, meng, deng);
			retval = EXIT_FAILURE;
			if (exit_on_error) {
				exit(retval);
			}
		}
		/* Contexts are likely different even if ulpdiff is fine. */
		goto out;
	}

cmp_contexts:
	if (!skip_contexts) {
		if (!compare_contexts()) {
			print_err(t, msci, dsci, meng, deng);
			retval = EXIT_FAILURE;
			if (exit_on_error) {
				exit(retval);
			}
		}
	}
	else {
		skipped_flags++;
	}

out:
	mpd_free(msci);
	mpd_free(meng);
	return;

skip:
	skipped++;
	goto out;
}


/* ========================================================================== */
/*                              Function Types                                */
/* ========================================================================== */

#ifndef PRINT_ONLY
#define unary_mfunc void (*)(mpd_t *, const mpd_t *, mpd_context_t *)
#define unary_dfunc decNumber * (*)(decNumber *, const decNumber *, decContext *)
static void
un(const testset *t)
{
#ifdef DEBUG
	printf("%s %s\n", t->name, cop1); fflush(stdout);
#endif
	mpd_set_string(mop1, cop1, &m_maxctx);
	decNumberFromString(&dop1, cop1, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	((unary_mfunc)t->mfunc)(mresult, mop1, &mctx);
	((unary_dfunc)t->dfunc)(&dresult, &dop1, &dctx);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}

static void
unlog(const testset *t)
{
	un(t);
}

#define unarychar_mfunc char * (*)(const mpd_t *, int)
#define unarychar_dfunc char * (*)(const decNumber *, char *)
static void
unchar(const testset *t)
{
	char *mcalc;
	char *dcalc = dsci;

#ifdef DEBUG
	printf("%s %s\n", t->name, cop1);
	fflush(stdout);
#endif
	/* status should be set in conversion */
	mctx.status = 0;
	dctx.status = 0;
	mpd_set_string(mop1, cop1, &mctx);
	decNumberFromString(&dop1, cop1, &dctx);

	mcalc = ((unarychar_mfunc)t->mfunc)(mop1, 1);
	((unarychar_dfunc)t->dfunc)(&dop1, dcalc);

	if (strcmp(mcalc, dcalc) || !compare_contexts()) {
		print_err(t, mcalc, dcalc, NULL, NULL);
	}

	mpd_free(mcalc);
}

#define unarycchar_mfunc const char * (*)(const mpd_t *, mpd_context_t *)
#define unarycchar_dfunc const char * (*)(const decNumber *, decContext *)
static void
uncchar(const testset *t)
{
	const char *mcalc;
	const char *dcalc;

#ifdef DEBUG
	printf("%s %s\n", t->name, cop1);
	fflush(stdout);
#endif
	mpd_set_string(mop1, cop1, &m_maxctx);
	decNumberFromString(&dop1, cop1, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	mcalc = ((unarycchar_mfunc)t->mfunc)(mop1, &mctx);
	dcalc = ((unarycchar_dfunc)t->dfunc)(&dop1, &dctx);

	if (strcmp(mcalc, dcalc) || !compare_contexts()) {
		print_err(t, mcalc, dcalc, NULL, NULL);
	}
}

#define unarycopy_mfunc void (*)(mpd_t *, const mpd_t *, mpd_context_t *)
#define unarycopy_dfunc decNumber * (*)(decNumber *, const decNumber *)
static void
uncpy(const testset *t)
{
#ifdef DEBUG
	printf("%s %s\n", t->name, cop1);
	fflush(stdout);
#endif
	mpd_set_string(mop1, cop1, &m_maxctx);
	decNumberFromString(&dop1, cop1, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	((unarycopy_mfunc)t->mfunc)(mresult, mop1, &mctx);
	((unarycopy_dfunc)t->dfunc)(&dresult, &dop1);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}

#define binary_mfunc void (*)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *)
#define binary_dfunc decNumber * (*)(decNumber *, const decNumber *, const decNumber *, decContext *)
static void
bn(const testset *t)
{
#ifdef DEBUG
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	((binary_mfunc)t->mfunc)(mresult, mop1, mop2, &mctx);
	((binary_dfunc)t->dfunc)(&dresult, &dop1, &dop2, &dctx);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}

static void
bnlog(const testset *t)
{
	bn(t);
}

#define binarycpy_mfunc void (*)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *)
#define binarycpy_dfunc decNumber *(*)(decNumber *, const decNumber *, const decNumber *)
static void
bncpy(const testset *t)
{
#ifdef DEBUG
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	((binarycpy_mfunc)t->mfunc)(mresult, mop1, mop2, &mctx);
	((binarycpy_dfunc)t->dfunc)(&dresult, &dop1, &dop2);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}

#define binarycmpctx_mfunc int (*)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *)
#define binarycmpctx_dfunc decNumber *(*)(decNumber *, const decNumber *, const decNumber *, decContext *)
static void
bncmpctx(const testset *t)
{
#ifdef DEBUG
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	(void)((binarycmpctx_mfunc)t->mfunc)(mresult, mop1, mop2, &mctx);
	((binarycmpctx_dfunc)t->dfunc)(&dresult, &dop1, &dop2, &dctx);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}

#define binarycmp_mfunc int (*)(mpd_t *, const mpd_t *, const mpd_t *)
#define binarycmp_dfunc decNumber *(*)(decNumber *, const decNumber *, const decNumber *, decContext *)
static void
bncmp(const testset *t)
{
#ifdef DEBUG
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	(void)((binarycmp_mfunc)t->mfunc)(mresult, mop1, mop2);
	((binarycmp_dfunc)t->dfunc)(&dresult, &dop1, &dop2, &dctx);

	compare_results(t);
}

#define binarysq_mfunc int (*)(const mpd_t *, const mpd_t *)
#define binarysq_dfunc int (*)(const decNumber *, const decNumber *)
static void
bnsameq(const testset *t)
{
	int mres, dres;

#ifdef DEBUG
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	mres = ((binarysq_mfunc)t->mfunc)(mop1, mop2);
	dres = ((binarysq_dfunc)t->dfunc)(&dop1, &dop2);

	if (mres != dres || !compare_contexts()) {
		printf("%s\n", "XXX");
		fflush(stdout);
	}
}

#define ternary_mfunc void (*)(mpd_t *, const mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *)
#define ternary_dfunc decNumber *(*)(decNumber *, const decNumber *, const decNumber *, const decNumber *, decContext *)
static void
tn(const testset *t)
{
#ifdef DEBUG
	printf("%s  %s  %s  %s\n", t->name, cop1, cop2, cop3);
	fflush(stdout);
#endif
        mpd_set_string(mop1, cop1, &m_maxctx);
        decNumberFromString(&dop1, cop1, &d_maxctx);

        mpd_set_string(mop2, cop2, &m_maxctx);
        decNumberFromString(&dop2, cop2, &d_maxctx);

        mpd_set_string(mop3, cop3, &m_maxctx);
        decNumberFromString(&dop3, cop3, &d_maxctx);

	mctx.status = 0;
	dctx.status = 0;
	((ternary_mfunc)t->mfunc)(mresult, mop1, mop2, mop3, &mctx);
	((ternary_dfunc)t->dfunc)(&dresult, &dop1, &dop2, &dop3, &dctx);

	counter++;
	nans += !!mpd_isnan(mresult);
	infinities += !!mpd_isinfinite(mresult);
	subnormals += !!mpd_issubnormal(mresult, &mctx);
	zeros += !!mpd_iszero(mresult);

	compare_results(t);
}
#else
/* PRINT_ONLY */
static void
un(const testset *t)
{
	printf("%s %s\n", t->name, cop1);
	fflush(stdout);
        mpd_set_string(mop1, cop1, &m_maxctx);
	if (m_maxctx.status&MPD_Conversion_syntax) {
		abort();
	}
	counter++;
}
static void unlog(const testset *t) { un(t); }
static void unchar(const testset *t) { un(t); }
static void uncchar(const testset *t) { un(t); }
static void uncpy(const testset *t) { un(t); }

static void
bn(const testset *t)
{
	printf("%s  %s  %s\n", t->name, cop1, cop2);
	fflush(stdout);
        mpd_set_string(mop1, cop1, &m_maxctx);
        mpd_set_string(mop2, cop2, &m_maxctx);
	if (m_maxctx.status&MPD_Conversion_syntax) {
		abort();
	}
	counter++;
}
static void bnlog(const testset *t) { bn(t); }
static void bncmp(const testset *t) { bn(t); }
static void bncpy(const testset *t) { bn(t); }
static void bncmpctx(const testset *t) { bn(t); }
static void bnsameq(const testset *t) { bn(t); }

static void
tn(const testset *t)
{
	printf("%s  %s  %s  %s\n", t->name, cop1, cop2, cop3);
	fflush(stdout);
        mpd_set_string(mop1, cop1, &m_maxctx);
        mpd_set_string(mop2, cop2, &m_maxctx);
        mpd_set_string(mop3, cop3, &m_maxctx);
	if (m_maxctx.status&MPD_Conversion_syntax) {
		abort();
	}
	counter++;
}
#endif /* PRINT_ONLY */


/* ========================================================================== */
/*                       Adapt problematic functions                          */
/* ========================================================================== */

static const char *
dn_class(decNumber *x, decContext *ctx)
{
	return decNumberClassToString(decNumberClass(x, ctx));
}

static int
dn_samequantum(decNumber *x, decNumber *y)
{
        decNumberSameQuantum(&dresult, x, y);
        return decNumberToInt32(&dresult, &dctx);
}


/* ========================================================================== */
/*                               Unary functions                              */
/* ========================================================================== */

#define cvp const void *
static const testset testsets[] = {
  /* unary functions */
  {ABS,       "abs",             0,  UN, un,        (cvp)mpd_abs,               (cvp)decNumberAbs},
  {EXP,       "exp",             RE, UN, un,        (cvp)mpd_exp,               (cvp)decNumberExp},
  {LN,        "ln",              RE, UN, un,        (cvp)mpd_ln,                (cvp)decNumberLn},
  {LOG10,     "log10",           RE, UN, un,        (cvp)mpd_log10,             (cvp)decNumberLog10},
  {LOGB,      "logb",            0,  UN, un,        (cvp)mpd_logb,              (cvp)decNumberLogB},
  {MINUS,     "minus",           0,  UN, un,        (cvp)mpd_minus,             (cvp)decNumberMinus},
  {NEXTMINUS, "nextminus",       0,  UN, un,        (cvp)mpd_next_minus,        (cvp)decNumberNextMinus},
  {NEXTPLUS,  "nextplus",        0,  UN, un,        (cvp)mpd_next_plus,         (cvp)decNumberNextPlus},
  {PLUS,      "plus",            0,  UN, un,        (cvp)mpd_plus,              (cvp)decNumberPlus},
  {REDUCE,    "reduce",          0,  UN, un,        (cvp)mpd_reduce,            (cvp)decNumberReduce},
  {SQRT,      "squareroot",      0,  UN, un,        (cvp)mpd_sqrt,              (cvp)decNumberSquareRoot},
  {TOINT,     "tointegral",      0,  UN, un,        (cvp)mpd_round_to_int,      (cvp)decNumberToIntegralValue},
  {TOINTX,    "tointegralx",     0,  UN, un,        (cvp)mpd_round_to_intx,     (cvp)decNumberToIntegralExact},
  /* char unary functions */
  {TOSCI,     "tosci",           0,  UN, unchar,    (cvp)mpd_to_sci,            (cvp)decNumberToString},
  {TOENG,     "toeng",           0,  UN, unchar,    (cvp)mpd_to_eng,            (cvp)decNumberToEngString},
  /* const char unary functions */
  {CLASS,     "class",           0,  UN, uncchar,   (cvp)mpd_class,             (cvp)dn_class},
  /* copy */
  {COPY,      "copy",            0,  UN, uncpy,     (cvp)mpd_copy,              (cvp)decNumberCopy},
  {COPYABS,   "copyabs",         0,  UN, uncpy,     (cvp)mpd_copy_abs,          (cvp)decNumberCopyAbs},
  {COPYNEG,   "copynegate",      0,  UN, uncpy,     (cvp)mpd_copy_negate,       (cvp)decNumberCopyNegate},
  /* logical unary functions */
  {INVERT,    "invert",          0,  UN, unlog,     (cvp)mpd_invert,            (cvp)decNumberInvert},
  /* binary functions */
  {ADD,       "add",             0,  BN, bn,        (cvp)mpd_add,               (cvp)decNumberAdd},
  {DIV,       "divide",          0,  BN, bn,        (cvp)mpd_div,               (cvp)decNumberDivide},
  {NDIV,      "ndivide",         0,  BN, bn,        (cvp)mpd_test_newtondiv,    (cvp)decNumberDivide},
  {DIVINT,    "divideint",       0,  BN, bn,        (cvp)mpd_divint,            (cvp)decNumberDivideInteger},
  {MAX,       "max",             0,  BN, bn,        (cvp)mpd_max,               (cvp)decNumberMax},
  {MAXMAG,    "maxmag",          0,  BN, bn,        (cvp)mpd_max_mag,           (cvp)decNumberMaxMag},
  {MIN,       "min",             0,  BN, bn,        (cvp)mpd_min,               (cvp)decNumberMin},
  {MINMAG,    "minmag",          0,  BN, bn,        (cvp)mpd_min_mag,           (cvp)decNumberMinMag},
  {MULTIPLY,  "multiply",        0,  BN, bn,        (cvp)mpd_mul,               (cvp)decNumberMultiply},
  {NEXTTWRD,  "nexttoward",      0,  BN, bn,        (cvp)mpd_next_toward,       (cvp)decNumberNextToward},
  {POWER,     "power",           RE, BN, bn,        (cvp)mpd_pow,               (cvp)decNumberPower},
  {QUANTIZE,  "quantize",        0,  BN, bn,        (cvp)mpd_quantize,          (cvp)decNumberQuantize},
  {REM,       "remainder",       0,  BN, bn,        (cvp)mpd_rem,               (cvp)decNumberRemainder},
  {NREM,      "nremainder",      0,  BN, bn,        (cvp)mpd_test_newtonrem,    (cvp)decNumberRemainder},
  {REMNEAR,   "remaindernear",   0,  BN, bn,        (cvp)mpd_rem_near,          (cvp)decNumberRemainderNear},
  {ROTATE,    "rotate",          0,  BN, bn,        (cvp)mpd_rotate,            (cvp)decNumberRotate},
  {SCALEB,    "scaleb",          0,  BN, bn,        (cvp)mpd_scaleb,            (cvp)decNumberScaleB},
  {SHIFT,     "shift",           0,  BN, bn,        (cvp)mpd_shift,             (cvp)decNumberShift},
  {SUBTRACT,  "subtract",        0,  BN, bn,        (cvp)mpd_sub,               (cvp)decNumberSubtract},
  /* logical binary functions */
  {AND,       "and",             0,  BN, bnlog,     (cvp)mpd_and,               (cvp)decNumberAnd},
  {OR,        "or",              0,  BN, bnlog,     (cvp)mpd_or,                (cvp)decNumberOr},
  {XOR,       "xor",             0,  BN, bnlog,     (cvp)mpd_xor,               (cvp)decNumberXor},
  /* copy binary functions */
  {COPYSIGN,  "copysign",        0,  BN, bncpy,     (cvp)mpd_copy_sign,         (cvp)decNumberCopySign},
  /* compare binary functions taking a context */
  {CMP,       "compare",         0,  BN, bncmpctx,  (cvp)mpd_compare,           (cvp)decNumberCompare},
  {CMPSIG,    "comparesig",      0,  BN, bncmpctx,  (cvp)mpd_compare_signal,    (cvp)decNumberCompareSignal},
  /* compare binary functions */
  {CMPT,      "comparetotal",    0,  BN, bncmp,     (cvp)mpd_compare_total,     (cvp)decNumberCompareTotal},
  {CMPTMAG,   "comparetotalmag", 0,  BN, bncmp,     (cvp)mpd_compare_total_mag, (cvp)decNumberCompareTotalMag},
  /* int binary functions */
  {SAMEQUANT, "samequantum",     0,  BN, bnsameq,   (cvp)mpd_same_quantum,      (cvp)dn_samequantum},
  /* ternary functions */
  {FMA,       "fma",             RE, TN, tn,        (cvp)mpd_fma,               (cvp)decNumberFMA},
  {MAXID,     NULL,              -1, -1, NULL,      NULL,                       NULL}
};


/* ========================================================================== */
/*                               Test functions                               */
/* ========================================================================== */

static inline char *
indicator(char *s)
{
	*s++ = random()%2 ? 'e' : 'E';
	*s = '\0';
	return s;
}

static inline char *
digits(char *s, mpd_ssize_t len)
{
	mpd_ssize_t n;

	for (n = 0; n < len; n++) {
		*s++ = random()%10 + '0';
	}
	*s = '\0';
	return s;
}

static inline char *
decimal_part(char *s, mpd_ssize_t len)
{
	long x = random()%100;
	mpd_ssize_t intlen, fraclen;

	if (x > 80) {
		s = digits(s, len);
	}
	else if (x > 20) {
		intlen = random()%(len+1);
		fraclen = len - intlen;
		s = digits(s, intlen);
		*s++ = '.';
		s = digits(s, fraclen);
	}
	else {
		intlen = random()%(len+1)+1;
		*s++ = '.';
		s = digits(s, intlen);
	}
	return s;
}

static inline char *
expdigits(char *s)
{
	mpd_ssize_t x, q, d;
	int j;

	x = (random()%2) ? mctx.emax : 200;

	if (random()%2) {
		*s++ = '-';
		 x = random() % (2*x+1);
	}
	else {
		if (random()%2)
			*s++ = '+';
		x = random() % (x+1);
	}

	j = mpd_exp_digits(x) - 1;

	for (; j != 0; --j) {
		d = rt_pow10[j];
		q = x / d;
		x -= d * q;
		*s++ = '0' + (char)q;
	}
	*s++ = '0' + (char)x;
	*s = '\0';

	return s;
}

static inline char *
exponentpart(char *s)
{
	s = indicator(s);
	s = expdigits(s);
	return s;
}

static inline char *
infinity(char *s)
{
	*s++ = 'i';
	*s++ = 'n';
	*s++ = 'f';
	if (random()%2) {
		*s++ = 'i';
		*s++ = 'n';
		*s++ = 'i';
		*s++ = 't';
		*s++ = 'y';
	}
	*s = '\0';
	return s;
}

static inline char *
dcnan(char *s, mpd_ssize_t len)
{
	if (random()%2) {
		*s++ = 's';
	}
	*s++ = 'N';
	*s++ = 'a';
	*s++ = 'N';
	*s = '\0';
	if (random()%2) {
		s = digits(s, len);
	}
	return s;
}

static inline char *
numeric_value(char *s, mpd_ssize_t maxprec)
{
	long x = random()%100;
	if (x > 95) {
		return infinity(s);
	}
	s = decimal_part(s, maxprec);
	if (x > 20) {
		s = exponentpart(s);
	}
	return s;
}

static inline char *
numeric_string(char *s, mpd_ssize_t maxprec)
{
	long x = random()%100;
	if (x > 98) {
		return dcnan(s, maxprec);
	}
	return numeric_value(s, maxprec);
}

static inline char *
randdec(char *s, mpd_ssize_t maxprec)
{
	return numeric_string(s, maxprec);
}

static inline char *
leading_zero_pattern(char *s, mpd_ssize_t maxzeros)
{
	long nzeros = random()%(maxzeros+1);
	long ndigits = random()%10;
	long n;

	*s++ = '.';
	memset(s, '0', nzeros);
	s += nzeros;

	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	*s = '\0';
	return s;
}

static inline char *
double_zero_pattern(char *s, mpd_ssize_t maxzeros)
{
	long nzeros = random()%(maxzeros+1);
	long ndigits = random()%10;
	long n;

	*s++ = '.';
	memset(s, '0', nzeros);
	s += nzeros;
	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	nzeros = random()%(maxzeros+1);
	ndigits = random()%10;
	memset(s, '0', nzeros);
	s += nzeros;
	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	*s = '\0';
	return s;
}

static inline char *
leading_nine_pattern(char *s, mpd_ssize_t maxnines)
{
	long nines = random()%(maxnines+1);
	long ndigits = random()%10;
	long n = 0;

	*s++ = '.';
	memset(s, '9', nines);
	s += nines;

	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	*s = '\0';
	return s;
}

static inline char *
small_integer(char *s)
{
	long ndigits = random()%3+1;
	long n = 0;

	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	*s = '\0';
	return s;
}

static inline char *
small_neg_integer(char *s)
{
	long ndigits = random()%3+1;
	long n = 0;

	*s++ = '-';
	for (n = 0; n < ndigits; n++) {
		*s++ = random()%10 + '0';
	}

	*s = '\0';
	return s;
}

/* close to minus infinity */
static void
close_to_minus_inf_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '-';
	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emax+1);
}

static void
close_to_minus_inf_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '-';
	*s++ = '9';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emax);
}

/* close to minus one */
static void
close_to_minus_one_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '-';
	*s++ = '1';
	*s++ = '.';
	memset(s, '0', zeros);
	s += zeros;
	digits(s, prec);
}

static void
close_to_minus_one_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '-';
	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	digits(s, prec);
}

/* close to minus emin */
static void
close_to_minus_emin_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '-';
	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emin);
}

static void
close_to_minus_emin_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '-';
	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emin);
}

/* close to minus etiny */
static void
close_to_minus_etiny_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '-';
	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mpd_etiny(&mctx));
}

static void
close_to_minus_etiny_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '-';
	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mpd_etiny(&mctx));
}

/* close to zero */
static void
close_to_zero_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '-';
	*s++ = '0';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	digits(s, prec);
}

static void
close_to_zero_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '0';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	digits(s, prec);
}

/* close to etiny */
static void
close_to_etiny_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mpd_etiny(&mctx));
}

static void
close_to_etiny_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mpd_etiny(&mctx));
}

/* close to emin */
static void
close_to_emin_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emin);
}

static void
close_to_emin_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emin);
}

/* close to one */
static void
close_to_one_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '0';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	digits(s, prec);
}

static void
close_to_one_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '1';
	*s++ = '.';
	memset(s, '0', zeros);
	s += zeros;
	digits(s, prec);
}

/* close to infinity */
static void
close_to_inf_less(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t nines = random()%(prec+30);

	*s++ = '9';
	*s++ = '.';
	*s++ = '9';
	memset(s, '9', nines);
	s += nines;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emax);
}

static void
close_to_inf_greater(char *s, mpd_ssize_t prec)
{
	mpd_ssize_t zeros = random()%(prec+30);

	*s++ = '1';
	*s++ = '.';
	*s++ = '0';
	memset(s, '0', zeros);
	s += zeros;
	s = digits(s, prec);
	snprintf(s, MAXOP-prec-30, "e%"PRI_mpd_ssize_t"", mctx.emax+1);
}

static void (*close_funcs[])(char *, mpd_ssize_t) = {
  close_to_minus_inf_less, close_to_minus_inf_greater, close_to_minus_one_less,
  close_to_minus_one_greater, close_to_minus_emin_less, close_to_minus_emin_greater,
  close_to_minus_etiny_less, close_to_minus_etiny_greater, close_to_zero_less,
  close_to_zero_greater, close_to_etiny_less, close_to_etiny_greater,
  close_to_emin_less, close_to_emin_greater, close_to_one_less,
  close_to_one_greater, close_to_inf_less, close_to_inf_greater
};

static void
un_close_to_pow10(const testset *t, mpd_ssize_t prec)
{
	mpd_ssize_t n;

	/* integer nines */
	n = prec+30;
	memset(cop1, '9', n);
	for (n = prec+30; n >= 1; n--) {
		cop1[n] = '\0';
		t->testfunc(t);
		leading_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		double_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		leading_nine_pattern(cop1+n, 50);
		t->testfunc(t);
	}

	/* negative integer nines */
	n = prec+30;
	cop1[0] = '-';
	memset(cop1+1, '9', n);
	for (n = 1+prec+30; n >= 2; n--) {
		cop1[n] = '\0';
		t->testfunc(t);
		leading_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		double_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		leading_nine_pattern(cop1+n, 50);
		t->testfunc(t);
	}

	/* integer powers of 10 */
	cop1[0] = '1';
	n = prec+30;
	memset(cop1+1, '0', n);
	for (n = 1+prec+30; n >= 1; n--) {
		cop1[n] = '\0';
		t->testfunc(t);
		leading_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		double_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		leading_nine_pattern(cop1+n, 50);
		t->testfunc(t);
	}

	/* negative integer powers of 10 */
	cop1[0] = '-';
	cop1[1] = '1';
	n = prec+30;
	memset(cop1+2, '0', n);
	for (n = 2+prec+30; n >= 2; n--) {
		cop1[n] = '\0';
		t->testfunc(t);
		leading_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		double_zero_pattern(cop1+n, 50);
		t->testfunc(t);
		leading_nine_pattern(cop1+n, 50);
		t->testfunc(t);
	}
}

static void
bn_close_to_pow10(const testset *t, mpd_ssize_t prec)
{
	mpd_ssize_t n;

	/* 9999999..., small int */
	n = prec+30;
	memset(cop1, '9', n);
	for (n = prec+30; n >= 1; n--) {
		cop1[n] = '\0';
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		double_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_nine_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);
	}

	/* -999999...., small int */
	n = prec+30;
	cop1[0] = '-';
	memset(cop1+1, '9', n);
	for (n = 1+prec+30; n >= 2; n--) {
		cop1[n] = '\0';
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		double_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_nine_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);
	}

	/* 1000000..., small int */
	cop1[0] = '1';
	n = prec+30;
	memset(cop1+1, '0', n);
	for (n = 1+prec+30; n >= 1; n--) {
		cop1[n] = '\0';
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		double_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_nine_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);
	}

	/* -1000000, small int */
	cop1[0] = '-';
	cop1[1] = '1';
	n = prec+30;
	memset(cop1+2, '0', n);
	for (n = 2+prec+30; n >= 2; n--) {
		cop1[n] = '\0';
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		double_zero_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);

		leading_nine_pattern(cop1+n, 50);
		small_integer(cop2);
		t->testfunc(t);
		small_neg_integer(cop2);
		t->testfunc(t);
	}
}

static void
un_incr_digits(const testset *t, mpd_ssize_t prec)
{
	char *s;
	mpd_ssize_t n;


	for (n = 1; n < prec+30; n++) {
		digits(cop1, n);
		t->testfunc(t);
	}

	cop1[0] = '-';
	for (n = 1; n < prec+30; n++) {
		digits(cop1+1, n);
		t->testfunc(t);
	}

	s = cop1;
	for (n = 1; n < prec+30; n++) {
		s = digits(cop1, n);
		exponentpart(s);
		t->testfunc(t);
	}

	cop1[0] = '-';
	for (n = 1; n < prec+30; n++) {
		s = digits(cop1+1, n);
		exponentpart(s);
		t->testfunc(t);
	}
}

static void
bn_incr_digits(const testset *t, mpd_ssize_t prec)
{
	char *s, *r;
	mpd_ssize_t n, m;


	for (n = 1; n < prec+30; n++) {
		digits(cop1, n);
		for (m = 1; m < prec+30; m++) {
			digits(cop2, n);
			t->testfunc(t);
		}
	}

	cop1[0] = '-';
	for (n = 1; n < prec+30; n++) {
		digits(cop1+1, n);
		for (m = 1; m < prec+30; m++) {
			digits(cop2, n);
			t->testfunc(t);
		}
	}

	s = cop1;
	for (n = 1; n < prec+30; n++) {
		s = digits(cop1, n);
		exponentpart(s);
		for (m = 1; m < prec+30; m++) {
			r = digits(cop2, n);
			exponentpart(r);
			t->testfunc(t);
		}
	}

	cop1[0] = '-';
	for (n = 1; n < prec+30; n++) {
		s = digits(cop1+1, n);
		exponentpart(s);
		for (m = 1; m < prec+30; m++) {
			r = digits(cop2, n);
			exponentpart(r);
			t->testfunc(t);
		}
	}
}

static void
un_close_funcs(const testset *t, mpd_ssize_t prec)
{
	mpd_ssize_t i, n_func;

	n_func = sizeof(close_funcs)/sizeof(*close_funcs);

	for (i = 0; i < n_func; i++) {
		if (t->restricted) {
			if (close_funcs[i] == close_to_minus_inf_less ||
			    close_funcs[i] == close_to_inf_greater) {
				continue;
			}
		}
		close_funcs[i](cop1, prec);
		t->testfunc(t);
	}
}

static void
bn_close_funcs(const testset *t, mpd_ssize_t prec)
{
	mpd_ssize_t i, j, n_func;

	n_func = sizeof(close_funcs)/sizeof(*close_funcs);

	for (i = 0; i < n_func; i++) {
		if (t->restricted) {
			if (close_funcs[i] == close_to_minus_inf_less ||
			    close_funcs[i] == close_to_inf_greater) {
				continue;
			}
		}
		for (j = 0; j < n_func; j++) {
			if (t->restricted) {
				if (close_funcs[i] == close_to_minus_inf_less ||
				    close_funcs[i] == close_to_inf_greater) {
					continue;
				}
			}
			close_funcs[i](cop1, prec);
			close_funcs[j](cop2, prec);
			t->testfunc(t);
		}
	}
}

static void
un_randdec(const testset *t, mpd_ssize_t prec)
{
	long x;
	int i;

	for (i = 0; i < 1000; i++) {
		x = random()%(2*prec)+1;
		randdec(cop1, x);
		t->testfunc(t);
	}
}

static void
bn_randdec(const testset *t, mpd_ssize_t prec)
{
	long x, y;
	int i;

	for (i = 0; i < 10000; i++) {
		x = random()%(2*prec)+1;
		y = random()%(2*prec)+1;
		randdec(cop1, x);
		randdec(cop2, y);
		t->testfunc(t);
	}
}

static void
tn_randdec(const testset *t, mpd_ssize_t prec)
{
	long x, y, z;
	int i;

	for (i = 0; i < 10000; i++) {
		x = random()%(2*prec)+1;
		y = random()%(2*prec)+1;
		z = random()%(2*prec)+1;
		randdec(cop1, x);
		randdec(cop2, y);
		randdec(cop3, z);
		t->testfunc(t);
	}
}

static void
test_unary(const testset *t, mpd_ssize_t prec)
{
	un_close_to_pow10(t, prec);
	un_close_funcs(t, prec);
	un_incr_digits(t, prec);
	un_randdec(t, prec);
}

static void
test_binary(const testset *t, mpd_ssize_t prec)
{
	bn_close_to_pow10(t, prec);
	bn_close_funcs(t,  prec);
	bn_incr_digits(t, prec);
	bn_randdec(t, prec);
}

static void
test_ternary(const testset *t, mpd_ssize_t prec)
{
	tn_randdec(t, prec);
}

static void
test_all(const testset *t)
{
	int i, j, n_round;

	printf("testing %s ...\n", t->name);
	fflush(stdout);
	n_round = sizeof(mround) / sizeof(*mround);

	/* Small precisions */
	for (mctx.prec = 1; mctx.prec <= 5; mctx.prec++) {
		dctx.digits = (int32_t)mctx.prec;
		for (mctx.emax = 1; mctx.emax <= 5; mctx.emax++) {
			if (mctx.prec > mctx.emax) continue;
			dctx.emax = (int32_t)mctx.emax;
			mctx.emin = -mctx.emax;
			dctx.emin = (int32_t)mctx.emin;
			if (verbose) {
				printf("    prec: %"PRI_mpd_ssize_t"  emin: %"PRI_mpd_ssize_t""
				       "  emax: %"PRI_mpd_ssize_t"\n",
				       mctx.prec, mctx.emin, mctx.emax);
				fflush(stdout);
			}
			for (i = 0; i < n_round; i++) {
				mctx.round = mround[i];
				dctx.round = dround[i];
				for (mctx.clamp = 0; mctx.clamp <= 1; mctx.clamp++) {
					dctx.clamp = mctx.clamp;
					switch (t->type) {
					case UN:
						test_unary(t, mctx.prec);
						break;
					case BN:
						test_binary(t, mctx.prec);
						break;
					case TN:
						test_ternary(t, mctx.prec);
						break;
					default:
						abort();
						break;
					}
				}
			}
		}
	}

	/* IEEE contexts */
	for (i = 0; i < IEEE_MAX; i++) {
		mctx.prec = ieee_prec[i];
		mctx.emax = ieee_emax[i];
		mctx.emin = ieee_emin[i];
		dctx.digits = (int32_t)mctx.prec;
		dctx.emax = (int32_t)mctx.emax;
		dctx.emin = (int32_t)mctx.emin;
		if (verbose) {
			printf("    prec: %"PRI_mpd_ssize_t"  emin: %"PRI_mpd_ssize_t""
			       "  emax: %"PRI_mpd_ssize_t"\n",
			       mctx.prec, mctx.emin, mctx.emax);
			fflush(stdout);
		}
		for (j = 0; j < n_round; j++) {
			mctx.round = mround[j];
			dctx.round = dround[j];
			for (mctx.clamp = 0; mctx.clamp <= 1; mctx.clamp++) {
				dctx.clamp = mctx.clamp;
				switch (t->type) {
				case UN:
					test_unary(t, mctx.prec);
					break;
				case BN:
					test_binary(t, mctx.prec);
					break;
				case TN:
					test_ternary(t, mctx.prec);
					break;
				default:
					abort();
					break;
				}
			}
		}
	}

#ifdef CONFIG_64
	mctx.emax = 999999999;
	mctx.emin = -999999999;
	dctx.emax = (int32_t)mctx.emax;
	dctx.emin = (int32_t)mctx.emin;
#else
	mctx.emax = 425000000;
	mctx.emin = -425000000;
	dctx.emax = (int32_t)mctx.emax;
	dctx.emin = (int32_t)mctx.emin;
#endif
	if (t->restricted)
		mpd_restrcontext(&mctx, &dctx);
	/* Precisions from 1-100 */
	for (mctx.prec = 1; mctx.prec <= 100; mctx.prec++) {
		dctx.digits = (int32_t)mctx.prec;
		if (verbose) {
			printf("    prec: %"PRI_mpd_ssize_t"  emin: %"PRI_mpd_ssize_t""
			       "  emax: %"PRI_mpd_ssize_t"\n",
			       mctx.prec, mctx.emin, mctx.emax);
			fflush(stdout);
		}
		for (i = 0; i < n_round; i++) {
			mctx.round = mround[i];
			dctx.round = dround[i];
			for (mctx.clamp = 0; mctx.clamp <= 1; mctx.clamp++) {
				dctx.clamp = mctx.clamp;
				switch (t->type) {
				case UN:
					test_unary(t, mctx.prec);
					break;
				case BN:
					test_binary(t, mctx.prec);
					break;
				case TN:
					test_ternary(t, mctx.prec);
					break;
				default:
					abort();
					break;
				}
			}
		}
	}
}

static void
test_random(const testset *t)
{
	int i, n_round;
	mpd_ssize_t max_emax;

#ifdef CONFIG_64
	max_emax = 999999999;
#else
	max_emax = 425000000;
#endif
	if (t->restricted) {
		max_emax = 999999;
	}

	printf("testing %s ...\n", t->name);
	fflush(stdout);
	n_round = sizeof(mround) / sizeof(*mround);

	mctx.prec = random()%100 + 1;
	mctx.emax = random()%(max_emax-mctx.prec);
	mctx.emin = -mctx.emax;

	dctx.digits = (int32_t)mctx.prec;
	dctx.emax = (int32_t)mctx.emax;
	dctx.emin = (int32_t)mctx.emin;

	if (verbose) {
		printf("    prec: %"PRI_mpd_ssize_t"  emin: %"PRI_mpd_ssize_t""
		       "  emax: %"PRI_mpd_ssize_t"\n",
		       mctx.prec, mctx.emin, mctx.emax);
		fflush(stdout);
	}
	for (i = 0; i < n_round; i++) {
		mctx.round = mround[i];
		dctx.round = dround[i];
		for (mctx.clamp = 0; mctx.clamp <= 1; mctx.clamp++) {
			dctx.clamp = mctx.clamp;
			switch (t->type) {
			case UN:
				test_unary(t, mctx.prec);
				break;
			case BN:
				test_binary(t, mctx.prec);
				break;
			case TN:
				test_ternary(t, mctx.prec);
				break;
			default:
				abort();
				break;
			}
		}
	}
}

static void
doit(void)
{
	testset *t;

	mpd_testcontext(&mctx, &dctx);
	mpd_readcontext(&m_maxctx, &d_maxctx);

	for (t = (testset *)testsets; t->id != MAXID; t++) {
		if (short_tests) {
			test_random(t);
		}
		else {
			test_all(t);
		}
	}
}


const char *usage = "\
runtest: usage: deccheck [-v] [--short] [--minalloc] [--exit]\n";

const char *minalloc_fmt = "\n\
# ======================================================================\n\
#                              minalloc: %" PRI_mpd_ssize_t "\n\
# ======================================================================\n\
\n";


int main(int argc, char **argv)
{
	mpd_ssize_t ma;
	mpd_ssize_t limit = MPD_MINALLOC_MIN;
	int i;

	if (argc > 1) {
		for (i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-v") == 0) {
				verbose = 1;
			}
			else if (strcmp(argv[i], "--short") == 0) {
				short_tests = 1;
			}
			else if (strcmp(argv[i], "--minalloc") == 0) {
				limit = MPD_MINALLOC_MAX;
			}
			else if (strcmp(argv[i], "--exit") == 0) {
				exit_on_error = 1;
			}
			else {
				fputs(usage, stderr);
				exit(EXIT_FAILURE);
			}
		}
	}

	srandom((unsigned int)time(NULL));

	for (ma = MPD_MINALLOC_MIN; ma <= limit; ma++) {

		/* DON'T do this in a real program. You have to be sure that
		 * no previously allocated decimals will ever be used again. */
		MPD_MINALLOC = ma;
		if (limit == MPD_MINALLOC_MAX) {
			printf(minalloc_fmt, MPD_MINALLOC);
			fflush(stdout);
		}

		mop1 = mpd_qnew();
		mop2 = mpd_qnew();
		mop3 = mpd_qnew();
		mresult = mpd_qnew();
		mtmp = mpd_qnew();

		doit();

		mpd_del(mop1);
		mpd_del(mop2);
		mpd_del(mop3);
		mpd_del(mresult);
		mpd_del(mtmp);
	}

	/* Valgrind */
	mpd_del(&mpd_ln10);

	fprintf(stderr, "\n");
	fprintf(stderr, "counter:       %20" PRIu64 "\n", counter);
	fprintf(stderr, "nans:          %20" PRIu64 "\n", nans);
	fprintf(stderr, "infinities:    %20" PRIu64 "\n", infinities);
	fprintf(stderr, "subnormals:    %20" PRIu64 "\n", subnormals);
	fprintf(stderr, "zeros:         %20" PRIu64 "\n", zeros);
	fprintf(stderr, "skipped:       %20" PRIu64 "\n", skipped);
	fprintf(stderr, "skipped_flags: %20" PRIu64 "\n", skipped_flags);
	fprintf(stderr, "\n");


	return retval;
}



