#include "mpdecimal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "mptypes.h"
#include "malloc_fail.h"


/* This file contains coverage tests for rarely exercised code paths. */

#ifndef _MSVC_VER
  #include <inttypes.h>
  #define ASSERT(p) if (!(p)) {abort();}
  mpd_uint_t mpd_qsshiftr(mpd_t *result, const mpd_t *a, mpd_ssize_t n);
#else
  #define ASSERT(p) if (!(p)) {mpd_err_fatal("assertion failed");}
#endif

#define BUFSIZE 500
#if MPD_MAX_FLAG_LIST > BUFSIZE
  #error "insufficient buffer length"
#endif

static void
test_traphandler(mpd_context_t *ctx UNUSED)
{
	;
}

static void mpd_testcontext(mpd_context_t *ctx)
{
	mpd_defaultcontext(ctx);
	ctx->prec = 28;
}

#ifndef LEGACY_COMPILER
uint64_t
randbits(void)
{
	return (uint64_t)rand()<<48 | (uint64_t)rand()<<32 |
	       (uint64_t)rand()<<16 | (uint64_t)rand();
}
#else
uint32_t
randbits(void)
{
	return (uint32_t)rand()<<16 | (uint32_t)rand();
}
#endif


/*****************************************************************************/
/*                      Inttype conversion functions                         */
/*****************************************************************************/

#define TEST_GETSET_INTTYPE(TYPE, FMTSPEC) \
static void                                                \
getset_##TYPE(                                             \
    mpd_t *a, TYPE x, mpd_context_t *ctx,                  \
    TYPE (* getfunc)(const mpd_t *, mpd_context_t *ctx),   \
    void (* setfunc)(mpd_t *, TYPE, mpd_context_t *ctx))   \
{                                                          \
        char buf[BUFSIZE];                                 \
        char *s;                                           \
        TYPE y;                                            \
                                                           \
        setfunc(a, x, ctx);                                \
                                                           \
        if (getfunc != NULL) {                             \
                y = getfunc(a, ctx);                       \
                ASSERT(x == y)                             \
        }                                                  \
                                                           \
        snprintf(buf, BUFSIZE, "%" FMTSPEC, x);            \
        s = mpd_to_sci(a, 0);                              \
        ASSERT(strcmp(s, buf) == 0)                        \
        __mingw_dfp_get_globals()->mpd_free(s);                                       \
}

TEST_GETSET_INTTYPE(mpd_ssize_t, PRI_mpd_ssize_t)
TEST_GETSET_INTTYPE(int32_t, PRIi32)
TEST_GETSET_INTTYPE(mpd_uint_t, PRI_mpd_uint_t)
TEST_GETSET_INTTYPE(uint32_t, PRIu32)
#ifndef LEGACY_COMPILER
TEST_GETSET_INTTYPE(int64_t, PRIi64)
TEST_GETSET_INTTYPE(uint64_t, PRIu64)
#endif

static void
test_int_conversions(void)
{
	uint32_t status;
	mpd_context_t ctx;
	mpd_t *a;
	mpd_uint_t data[MPD_MINALLOC_MAX];
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, data};
	int i;

	mpd_testcontext(&ctx);
	a = mpd_new(&ctx);

#ifdef CONFIG_64
	#define mpd_get_i32 NULL
	#define mpd_get_u32 NULL
#else
	#define mpd_get_i64 NULL
	#define mpd_get_u64 NULL
#endif

	/* mpd_ssize_t */
	getset_mpd_ssize_t(a, MPD_SSIZE_MIN, &ctx, mpd_get_ssize, mpd_set_ssize);
	getset_mpd_ssize_t(a, MPD_SSIZE_MAX, &ctx, mpd_get_ssize, mpd_set_ssize);
	for (i = 0; i < 100000; i++) {
		getset_mpd_ssize_t(a, (mpd_ssize_t)randbits(), &ctx,
		                   mpd_get_ssize, mpd_set_ssize);
	}

	getset_mpd_ssize_t(&b, MPD_SSIZE_MIN, &ctx, mpd_get_ssize, mpd_sset_ssize);
	getset_mpd_ssize_t(&b, MPD_SSIZE_MAX, &ctx, mpd_get_ssize, mpd_sset_ssize);
	for (i = 0; i < 100000; i++) {
		getset_mpd_ssize_t(&b, (mpd_ssize_t)randbits(), &ctx,
		                   mpd_get_ssize, mpd_sset_ssize);
	}

	/* int32_t */
	getset_int32_t(a, INT32_MIN, &ctx, mpd_get_i32, mpd_set_i32);
	getset_int32_t(a, INT32_MAX, &ctx, mpd_get_i32, mpd_set_i32);
	for (i = 0; i < 100000; i++) {
		getset_int32_t(a, (int32_t)randbits(), &ctx,
		               mpd_get_i32, mpd_set_i32);
	}

	getset_int32_t(&b, INT32_MIN, &ctx, mpd_get_i32, mpd_sset_i32);
	getset_int32_t(&b, INT32_MAX, &ctx, mpd_get_i32, mpd_sset_i32);
	for (i = 0; i < 100000; i++) {
		getset_int32_t(&b, (int32_t)randbits(), &ctx,
		               mpd_get_i32, mpd_sset_i32);
	}

#ifndef LEGACY_COMPILER
	/* int64_t */
	getset_int64_t(a, INT64_MIN, &ctx, mpd_get_i64, mpd_set_i64);
	getset_int64_t(a, INT64_MAX, &ctx, mpd_get_i64, mpd_set_i64);
	for (i = 0; i < 100000; i++) {
		getset_int64_t(a, (int64_t)randbits(), &ctx,
		               mpd_get_i64, mpd_set_i64);
	}
#endif

#ifdef CONFIG_64
	getset_int64_t(&b, INT64_MIN, &ctx, mpd_get_i64, mpd_sset_i64);
	getset_int64_t(&b, INT64_MAX, &ctx, mpd_get_i64, mpd_sset_i64);
	for (i = 0; i < 100000; i++) {
		getset_int64_t(&b, (int64_t)randbits(), &ctx,
		               mpd_get_i64, mpd_sset_i64);
	}
#endif

	/* mpd_uint_t */
	getset_mpd_uint_t(a, 0, &ctx, mpd_get_uint, mpd_set_uint);
	getset_mpd_uint_t(a, MPD_UINT_MAX, &ctx, mpd_get_uint, mpd_set_uint);
	for (i = 0; i < 100000; i++) {
		getset_mpd_uint_t(a, (mpd_uint_t)randbits(), &ctx,
		                  mpd_get_uint, mpd_set_uint);
	}

	getset_mpd_uint_t(&b, 0, &ctx, mpd_get_uint, mpd_sset_uint);
	getset_mpd_uint_t(&b, MPD_UINT_MAX, &ctx, mpd_get_uint, mpd_sset_uint);
	for (i = 0; i < 100000; i++) {
		getset_mpd_uint_t(&b, (mpd_uint_t)randbits(), &ctx,
		                  mpd_get_uint, mpd_sset_uint);
	}

	/* uint32_t */
	getset_uint32_t(a, 0, &ctx, mpd_get_u32, mpd_set_u32);
	getset_uint32_t(a, UINT32_MAX, &ctx, mpd_get_u32, mpd_set_u32);
	for (i = 0; i < 100000; i++) {
		getset_uint32_t(a, (uint32_t)randbits(), &ctx,
		                mpd_get_u32, mpd_set_u32);
	}

	getset_uint32_t(&b, 0, &ctx, mpd_get_u32, mpd_sset_u32);
	getset_uint32_t(&b, UINT32_MAX, &ctx, mpd_get_u32, mpd_sset_u32);
	for (i = 0; i < 100000; i++) {
		getset_uint32_t(&b, (uint32_t)randbits(), &ctx,
		                mpd_get_u32, mpd_sset_u32);
	}

#ifndef LEGACY_COMPILER
	/* uint64_t */
	getset_uint64_t(a, 0, &ctx, mpd_get_u64, mpd_set_u64);
	getset_uint64_t(a, UINT64_MAX, &ctx, mpd_get_u64, mpd_set_u64);
	for (i = 0; i < 100000; i++) {
		getset_uint64_t(a, (uint64_t)randbits(), &ctx,
		                mpd_get_u64, mpd_set_u64);
	}
#endif

#ifdef CONFIG_64
	getset_uint64_t(&b, 0, &ctx, mpd_get_u64, mpd_sset_u64);
	getset_uint64_t(&b, UINT64_MAX, &ctx, mpd_get_u64, mpd_sset_u64);
	for (i = 0; i < 100000; i++) {
		getset_uint64_t(&b, (uint64_t)randbits(), &ctx,
		                mpd_get_u64, mpd_sset_u64);
	}
#endif

	/* specials */
	status = 0;
	mpd_set_string(a, "nan", &ctx);
	ASSERT(mpd_qget_uint(a, &status) == MPD_UINT_MAX)
	ASSERT(status&MPD_Invalid_operation)

	/* non-integer */
	status = 0;
	mpd_set_string(a, "2345e-1", &ctx);
	ASSERT(mpd_qget_uint(a, &status) == MPD_UINT_MAX)
	ASSERT(status&MPD_Invalid_operation)

	/* too large */
	status = 0;
	mpd_set_uint(a, 8, &ctx);
	a->exp = MPD_RDIGITS;
	ASSERT(mpd_qget_uint(a, &status) == MPD_UINT_MAX)
	ASSERT(status&MPD_Invalid_operation)

	/* too large */
	status = 0;
	mpd_set_uint(a, ((mpd_uint_t)MPD_SSIZE_MAX)+1, &ctx);
	ASSERT(mpd_qget_ssize(a, &status) == MPD_SSIZE_MAX)
	ASSERT(status&MPD_Invalid_operation)

	mpd_del(a);
}


/*****************************************************************************/
/*                       Mixed arithmetic functions                          */
/*****************************************************************************/

#define TEST_ARITH_INTTYPE(TYPE, FMTSPEC) \
static void                                                                   \
arith_##TYPE(                                                                 \
    mpd_t *tmp, const mpd_t *a, TYPE x, mpd_context_t *ctx,                   \
    void (* func)(mpd_t *, const mpd_t *, TYPE, mpd_context_t *ctx),          \
    void (* ctrl)(mpd_t *, const mpd_t *, const mpd_t *, mpd_context_t *ctx)) \
{                                                                             \
        mpd_context_t maxctx;                                                 \
        char buf[BUFSIZE];                                                    \
        char *s1, *s2;                                                        \
                                                                              \
        func(tmp, a, x, ctx);                                                 \
        s1 = mpd_to_sci(tmp, 0);                                              \
                                                                              \
        snprintf(buf, BUFSIZE, "%" FMTSPEC, x);                               \
        mpd_maxcontext(&maxctx);                                              \
        mpd_set_string(tmp, buf, &maxctx);                                    \
        ctrl(tmp, a, tmp, ctx);                                               \
        s2 = mpd_to_sci(tmp, 0);                                              \
                                                                              \
        ASSERT(strcmp(s1, s2) == 0)                                           \
        __mingw_dfp_get_globals()->mpd_free(s1);                                                         \
        __mingw_dfp_get_globals()->mpd_free(s2);                                                         \
}

TEST_ARITH_INTTYPE(mpd_ssize_t, PRI_mpd_ssize_t)
TEST_ARITH_INTTYPE(int32_t, PRIi32)
TEST_ARITH_INTTYPE(mpd_uint_t, PRI_mpd_uint_t)
TEST_ARITH_INTTYPE(uint32_t, PRIu32)
#ifdef CONFIG_64
TEST_ARITH_INTTYPE(int64_t, PRIi64)
TEST_ARITH_INTTYPE(uint64_t, PRIu64)
#endif

static void (*ssize_funcs[])(mpd_t*, const mpd_t*, mpd_ssize_t, mpd_context_t*) =
  {mpd_add_ssize, mpd_sub_ssize, mpd_mul_ssize, mpd_div_ssize, NULL};

static void (*i32_funcs[])(mpd_t*, const mpd_t*, int32_t, mpd_context_t*) =
  {mpd_add_i32, mpd_sub_i32, mpd_mul_i32, mpd_div_i32, NULL};

static void (*uint_funcs[])(mpd_t*, const mpd_t*, mpd_uint_t, mpd_context_t*) =
  {mpd_add_uint, mpd_sub_uint, mpd_mul_uint, mpd_div_uint, NULL};

static void (*u32_funcs[])(mpd_t*, const mpd_t*, uint32_t, mpd_context_t*) =
  {mpd_add_u32, mpd_sub_u32, mpd_mul_u32, mpd_div_u32, NULL};

#ifdef CONFIG_64
static void (*i64_funcs[])(mpd_t*, const mpd_t*, int64_t, mpd_context_t*) =
  {mpd_add_i64, mpd_sub_i64, mpd_mul_i64, mpd_div_i64, NULL};

static void (*u64_funcs[])(mpd_t*, const mpd_t*, uint64_t, mpd_context_t*) =
  {mpd_add_u64, mpd_sub_u64, mpd_mul_u64, mpd_div_u64, NULL};
#endif

static void (*control_funcs[])(mpd_t*, const mpd_t*, const mpd_t*, mpd_context_t*) =
  {mpd_add, mpd_sub, mpd_mul, mpd_div, NULL};


/* mixed mpd_t and integer operations */
static void
test_mixed_arith(mpd_context_t *ctx)
{
	mpd_t *tmp, *a;
	int i, k;

	tmp = mpd_new(ctx);
	a = mpd_new(ctx);

	ctx->traps &= ~MPD_Division_by_zero;

	for (i = 0; ssize_funcs[i] != NULL; i++) {
		mpd_set_string(a, "123456e2", ctx);
		arith_mpd_ssize_t(tmp, a, MPD_SSIZE_MIN, ctx,
		                  ssize_funcs[i], control_funcs[i]);
		arith_mpd_ssize_t(tmp, a, MPD_SSIZE_MAX, ctx,
		                  ssize_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_mpd_ssize_t(tmp, a, (mpd_ssize_t)randbits(), ctx,
		                          ssize_funcs[i], control_funcs[i]);
		}
	}

	for (i = 0; i32_funcs[i] != NULL; i++) {
		mpd_set_string(a, "-123456e2", ctx);
		arith_int32_t(tmp, a, INT32_MIN, ctx,
		              i32_funcs[i], control_funcs[i]);
		arith_int32_t(tmp, a, INT32_MAX, ctx,
		              i32_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_int32_t(tmp, a, (int32_t)randbits(), ctx,
		                      i32_funcs[i], control_funcs[i]);
		}
	}

	for (i = 0; uint_funcs[i] != NULL; i++) {
		mpd_set_string(a, "456789e2", ctx);
		arith_mpd_uint_t(tmp, a, 0, ctx,
		                 uint_funcs[i], control_funcs[i]);
		arith_mpd_uint_t(tmp, a, MPD_UINT_MAX, ctx,
		                 uint_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_mpd_uint_t(tmp, a, (mpd_uint_t)randbits(), ctx,
		                         uint_funcs[i], control_funcs[i]);
		}
	}

	for (i = 0; u32_funcs[i] != NULL; i++) {
		mpd_set_string(a, "987654e2", ctx);
		arith_uint32_t(tmp, a, 0, ctx,
		               u32_funcs[i], control_funcs[i]);
		arith_uint32_t(tmp, a, UINT32_MAX, ctx,
		               u32_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_uint32_t(tmp, a, (uint32_t)randbits(), ctx,
		                       u32_funcs[i], control_funcs[i]);
		}
	}

#ifdef CONFIG_64
	for (i = 0; i64_funcs[i] != NULL; i++) {
		mpd_set_string(a, "-123456e2", ctx);
		arith_int64_t(tmp, a, INT64_MIN, ctx,
		              i64_funcs[i], control_funcs[i]);
		arith_int64_t(tmp, a, INT64_MAX, ctx,
		              i64_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_int64_t(tmp, a, (int64_t)randbits(), ctx,
		                      i64_funcs[i], control_funcs[i]);
		}
	}

	for (i = 0; u64_funcs[i] != NULL; i++) {
		mpd_set_string(a, "-123456e2", ctx);
		arith_uint64_t(tmp, a, 0, ctx,
		               u64_funcs[i], control_funcs[i]);
		arith_uint64_t(tmp, a, UINT64_MAX, ctx,
		               u64_funcs[i], control_funcs[i]);
		for (k = 0; k < 1000; k++) {
			arith_uint64_t(tmp, a, (uint64_t)randbits(), ctx,
		                       u64_funcs[i], control_funcs[i]);
		}
	}
#endif

	mpd_del(tmp);
	mpd_del(a);
}

static void
test_context(void)
{
	mpd_context_t ctx;
	mpd_ssize_t ssize;
    void (* mpd_dflt_traphandler)(mpd_context_t *);

	/* context.c */
	mpd_dflt_traphandler = __mingw_dfp_get_globals()->mpd_traphandler;
	__mingw_dfp_get_globals()->mpd_traphandler = test_traphandler;
	mpd_init(&ctx, MPD_MAX_PREC+1);
	ASSERT(ctx.status&MPD_Invalid_context)
	ASSERT(ctx.newtrap == MPD_Invalid_context)
	__mingw_dfp_get_globals()->mpd_traphandler = mpd_dflt_traphandler;

	mpd_init(&ctx, 100);
	ASSERT(MPD_MINALLOC_MIN <= __mingw_dfp_get_globals()->MPD_MINALLOC &&
	       __mingw_dfp_get_globals()->MPD_MINALLOC <= MPD_MINALLOC_MAX)

	fprintf(stderr, "  This warning is part of the coverage test: ");
	ssize = __mingw_dfp_get_globals()->MPD_MINALLOC;
	mpd_setminalloc(2000);
	ASSERT(__mingw_dfp_get_globals()->MPD_MINALLOC == ssize)

	/* DON'T do this */
	__mingw_dfp_get_globals()->MPD_MINALLOC = MPD_MINALLOC_MIN;

	mpd_basiccontext(&ctx);
	ASSERT(mpd_getprec(&ctx) == 9)
	ASSERT(mpd_getemax(&ctx) == MPD_MAX_EMAX)
	ASSERT(mpd_getemin(&ctx) == MPD_MIN_EMIN)
	ASSERT(mpd_getround(&ctx) == MPD_ROUND_HALF_UP)
	ASSERT(mpd_gettraps(&ctx) == (MPD_Traps|MPD_Clamped))
	ASSERT(mpd_getstatus(&ctx) == 0)
	ASSERT(mpd_getclamp(&ctx) == 0)
	ASSERT(mpd_getcr(&ctx) == 1)

	ASSERT(mpd_ieee_context(&ctx, MPD_IEEE_CONTEXT_MAX_BITS*2) < 0)

	mpd_ieee_context(&ctx, 128);
	ASSERT(mpd_getprec(&ctx) == 34)
	ASSERT(mpd_getemax(&ctx) == 6144)
	ASSERT(mpd_getemin(&ctx) == -6143)
	ASSERT(mpd_getround(&ctx) == MPD_ROUND_HALF_EVEN)
	ASSERT(mpd_gettraps(&ctx) == 0)
	ASSERT(mpd_getstatus(&ctx) == 0)
	ASSERT(mpd_getclamp(&ctx) == 1)
	ASSERT(mpd_getcr(&ctx) == 1)

	ASSERT(!mpd_qsetprec(&ctx, -1))
	ASSERT(!mpd_qsetprec(&ctx, 0))
	ASSERT(!mpd_qsetprec(&ctx, MPD_MAX_PREC+1))

	ASSERT(!mpd_qsetemax(&ctx, -1))
	ASSERT(!mpd_qsetemax(&ctx, MPD_MAX_EMAX+1))

	ASSERT(!mpd_qsetemin(&ctx, 1))
	ASSERT(!mpd_qsetemin(&ctx, MPD_MIN_EMIN-1))

	ASSERT(!mpd_qsetround(&ctx, -1))
	ASSERT(!mpd_qsetround(&ctx, MPD_ROUND_GUARD))

	ASSERT(!mpd_qsettraps(&ctx, MPD_Max_status+1))
	ASSERT(!mpd_qsetstatus(&ctx, MPD_Max_status+1))

	ASSERT(!mpd_qsetclamp(&ctx, -1))
	ASSERT(!mpd_qsetclamp(&ctx, 2))

	ASSERT(!mpd_qsetcr(&ctx, -1))
	ASSERT(!mpd_qsetcr(&ctx, 2))

	mpd_qsetprec(&ctx, 2*MPD_RDIGITS);
	ASSERT(ctx.prec == 2*MPD_RDIGITS)

	mpd_qsetemax(&ctx, MPD_MAX_EMAX);
	ASSERT(ctx.emax == MPD_MAX_EMAX)

	mpd_qsetemin(&ctx, MPD_MIN_EMIN);
	ASSERT(ctx.emin == MPD_MIN_EMIN)

	mpd_qsetround(&ctx, MPD_ROUND_HALF_UP);
	ASSERT(ctx.round == MPD_ROUND_HALF_UP)

	mpd_qsettraps(&ctx, MPD_Traps);
	ASSERT(ctx.traps == MPD_Traps)

	mpd_qsetstatus(&ctx, 0);
	ASSERT(ctx.status == 0)

	mpd_qsetclamp(&ctx, 0);
	ASSERT(ctx.clamp == 0)

	mpd_qsetcr(&ctx, 1);
	ASSERT(ctx.allcr == 1)
}

/*
 * NOTE: Using setters like in this function is dangerous or meaningless
 * at best. This is only for testing.
 */
static void
test_attributes(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	char *s;

	mpd_testcontext(&ctx);

	/* specials */
	mpd_set_infinity(&a);
	ASSERT(mpd_isinfinite(&a))
	mpd_set_snan(&a);
	ASSERT(mpd_issnan(&a))

	/* data flags */
	mpd_set_dynamic(&a);
	ASSERT(mpd_isdynamic(&a))
	mpd_set_static(&a);
	ASSERT(mpd_isstatic(&a))
	mpd_set_const_data(&a);
	ASSERT(mpd_isconst_data(&a))

	mpd_set_static_data(&a);
	mpd_clear_flags(&a);

	/* switch to dynamic data */
	mpd_set_string(&a, "-2.3854727e+1875", &ctx);
	ASSERT(mpd_isstatic(&a))
	ASSERT(mpd_isstatic_data(&a))
	ASSERT(mpd_resize(&a, 2*MPD_MINALLOC_MAX, &ctx))
	ASSERT(a.alloc == 2*MPD_MINALLOC_MAX)
	ASSERT(mpd_isstatic(&a))
	ASSERT(mpd_isdynamic_data(&a))
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "-2.3854727e+1875") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	/* switch to dynamic data, zero new memory */
	mpd_set_string(&b, "123456789", &ctx);
	ASSERT(mpd_isstatic(&b))
	ASSERT(mpd_isstatic_data(&b))
	ASSERT(mpd_resize_zero(&b, 3*MPD_MINALLOC_MAX, &ctx))
	ASSERT(b.alloc == 3*MPD_MINALLOC_MAX)
	ASSERT(mpd_isstatic(&b))
	ASSERT(mpd_isdynamic_data(&b))
	ASSERT(b.data[0] == 0)


	/* rarely used attributes */
	mpd_set_string(&a, "2.3854727e+1875", &ctx);
	ASSERT(mpd_iscanonical(&a))
	ASSERT(mpd_isfinite(&a))
	ASSERT(!mpd_issigned(&a))
	mpd_set_negative(&a);
	ASSERT(mpd_issigned(&a))

	mpd_set_string(&a, "123000e-3", &ctx);
	ASSERT(mpd_isinteger(&a))
	ASSERT(mpd_isodd(&a))
	ASSERT(!mpd_iseven(&a))

	mpd_set_string(&a, "123000e-2", &ctx);
	ASSERT(mpd_isinteger(&a))
	ASSERT(mpd_iseven(&a))
	ASSERT(!mpd_isodd(&a))

	mpd_del(&a);
	mpd_del(&b);
}

static void
test_shift(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	char *s;

	/* mpd_qsshiftr */
	mpd_testcontext(&ctx);
	ctx.prec = 100;
	ctx.emax = MPD_MAX_EMAX;
	ctx.emin = MPD_MIN_EMIN;

	mpd_set_string(&a, "123456789123456789", &ctx);
	mpd_qsshiftr(&a, &a, 0);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "123456789123456789") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	mpd_set_string(&a, "0", &ctx);
	mpd_qsshiftr(&a, &a, 0);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "0") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	mpd_set_string(&a, "123", &ctx);
	mpd_qsshiftr(&a, &a, 7);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "0") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	mpd_set_string(&a, "123456789123456789", &ctx);
	mpd_qsshiftr(&b, &a, 0);
	s = mpd_to_sci(&b, 0);
	ASSERT(strcmp(s, "123456789123456789") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	mpd_set_string(&a, "0", &ctx);
	mpd_qsshiftr(&b, &a, 0);
	s = mpd_to_sci(&b, 0);
	ASSERT(strcmp(s, "0") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	mpd_set_string(&a, "123", &ctx);
	mpd_qsshiftr(&b, &a, 7);
	s = mpd_to_sci(&b, 0);
	ASSERT(strcmp(s, "0") == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	/* mpd_qrotate */
	ctx.traps = 0;
	ctx.status = 0;
	mpd_set_string(&a, "1234556789", &ctx);
	mpd_set_string(&b, "1e100", &ctx);
	mpd_rotate(&a, &a, &b, &ctx);
	ASSERT(mpd_isnan(&a))
	ASSERT(ctx.status&MPD_Invalid_operation)

	mpd_del(&a);
	mpd_del(&b);
}

static void
test_check_nans(void)
{
	mpd_context_t ctx;
	void (* mpd_dflt_traphandler)(mpd_context_t *);
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};

	mpd_testcontext(&ctx);

	/* check nans */
	ctx.status = 0;
	mpd_set_string(&a, "NaN", &ctx);
	ASSERT(mpd_check_nan(&b, &a, &ctx))
	ASSERT(ctx.status == 0)
	ASSERT(mpd_isqnan(&b))

	ctx.status = 0;
	mpd_set_string(&a, "1", &ctx);
	ASSERT(!mpd_check_nan(&b, &a, &ctx))
	ASSERT(ctx.status == 0)

	mpd_dflt_traphandler = __mingw_dfp_get_globals()->mpd_traphandler;
	__mingw_dfp_get_globals()->mpd_traphandler = test_traphandler;
	ctx.status = 0;
	mpd_set_string(&a, "sNaN", &ctx);
	mpd_set_string(&b, "1", &ctx);
	ASSERT(mpd_check_nans(&b, &a, &b, &ctx))
	ASSERT(ctx.status == MPD_Invalid_operation)
	ASSERT(mpd_isqnan(&b))
	__mingw_dfp_get_globals()->mpd_traphandler = mpd_dflt_traphandler;

	ctx.status = 0;
	mpd_set_string(&a, "2", &ctx);
	mpd_set_string(&b, "1", &ctx);
	ASSERT(!mpd_check_nans(&b, &a, &b, &ctx))
	ASSERT(ctx.status == 0)

	mpd_del(&a);
	mpd_del(&b);
}

static void
test_finalize_round(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	char *s;

	mpd_testcontext(&ctx);

	/* finalize */
	ctx.prec = 5;
	ctx.status = 0;
	mpd_set_string(&a, "8.89871263726722323e201", &ctx);
	mpd_finalize(&a, &ctx);
	s = mpd_to_sci(&a, 1);
	ASSERT(strcmp(s, "8.8987E+201") == 0)
	ASSERT(ctx.status == (MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);

	/* apply_round_excess, apply_round_fit */
	ctx.prec =  MPD_RDIGITS + 1;
	ctx.emax = 99;
	ctx.emin = -99;
	ctx.traps &= ~MPD_Underflow;

#ifdef CONFIG_64
	ctx.status = 0;
	mpd_set_string(&a, "99999999999999999999e-119", &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "1.0000000000000000000e-99") == 0)
	ASSERT(ctx.status == (MPD_Underflow|MPD_Subnormal|MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);

	ctx.status = 0;
	mpd_set_string(&a, "99999999999999999999e79", &ctx);
	mpd_set_string(&b, "1e80", &ctx);
	mpd_quantize(&a, &a, &b, &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "1.0000000000000000000e+99") == 0)
	ASSERT(ctx.status == (MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);
#else
	ctx.status = 0;
	mpd_set_string(&a, "9999999999e-109", &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "1.000000000e-99") == 0)
	ASSERT(ctx.status == (MPD_Underflow|MPD_Subnormal|MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);

	ctx.status = 0;
	mpd_set_string(&a, "9999999999e89", &ctx);
	mpd_set_string(&b, "1e90", &ctx);
	mpd_quantize(&a, &a, &b, &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "1.000000000e+99") == 0)
	ASSERT(ctx.status == (MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);
#endif

	mpd_del(&a);
	mpd_del(&b);
}

static void
test_baseconv(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	uint32_t u32data;
	uint16_t u16data;
	void (* mpd_dflt_traphandler)(mpd_context_t *);

	mpd_testcontext(&ctx);
	mpd_dflt_traphandler = __mingw_dfp_get_globals()->mpd_traphandler;
	__mingw_dfp_get_globals()->mpd_traphandler = test_traphandler;

	/* special or non-integer values */
	mpd_set_string(&a, "inf", &ctx);

	ctx.status = 0;
	ASSERT(mpd_export_u16(&u16data, 1, 1<<15, &a, &ctx) == SIZE_MAX)
	ASSERT(ctx.status & MPD_Invalid_operation)

	ctx.status = 0;
	ASSERT(mpd_export_u32(&u32data, 1, 1<<15, &a, &ctx) == SIZE_MAX)
	ASSERT(ctx.status & MPD_Invalid_operation)

	mpd_set_string(&a, "9.12987391", &ctx);

	ctx.status = 0;
	ASSERT(mpd_export_u16(&u16data, 1, 1<<15, &a, &ctx) == SIZE_MAX)
	ASSERT(ctx.status & MPD_Invalid_operation)

	ctx.status = 0;
	ASSERT(mpd_export_u32(&u32data, 1, 1<<15, &a, &ctx) == SIZE_MAX)
	ASSERT(ctx.status & MPD_Invalid_operation)

	/* exceeding limits */
#if MPD_SIZE_MAX < SIZE_MAX
	mpd_set_string(&a, "123456789", &ctx);
	ctx.status = 0;
	ASSERT(mpd_export_u32(&u32data, (size_t)MPD_SSIZE_MAX+1, 1<<15, &a, &ctx) == SIZE_MAX)
	ASSERT(ctx.status & MPD_Invalid_operation)
#endif

	mpd_set_string(&a, "123456789", &ctx);

	ctx.status = 0;
	mpd_import_u16(&a, &u16data, SIZE_MAX-1, MPD_POS, 1<<15, &ctx);
	ASSERT(ctx.status & MPD_Invalid_operation)

	ctx.status = 0;
	mpd_import_u16(&a, &u16data, MPD_SIZE_MAX/(sizeof (mpd_uint_t))+1, MPD_POS, 2, &ctx);
	ASSERT(ctx.status & MPD_Invalid_operation)

	ctx.status = 0;
	mpd_import_u32(&a, &u32data, SIZE_MAX-1, MPD_POS, 1<<15, &ctx);
	ASSERT(ctx.status & MPD_Invalid_operation)

	ctx.status = 0;
	mpd_import_u32(&a, &u32data, MPD_SIZE_MAX/(sizeof (mpd_uint_t))+1, MPD_POS, 2, &ctx);
	ASSERT(ctx.status & MPD_Invalid_operation)

	__mingw_dfp_get_globals()->mpd_traphandler = mpd_dflt_traphandler;
	mpd_del(&a);
}

static void
test_set_string(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	char buf[BUFSIZE];
	char *s, *t;
	mpd_ssize_t mem;
	int n;

	mpd_testcontext(&ctx);
	ctx.traps = MPD_Malloc_error;

	/* Exponent limits */
	ctx.status = 0;
	ctx.prec = 28;
	snprintf(buf, BUFSIZE, "0.0000000000000000000000001e%" PRI_mpd_ssize_t,
	         (mpd_ssize_t)MPD_MAX_EMAX+20);
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	snprintf(buf, BUFSIZE, "1E+%" PRI_mpd_ssize_t, (mpd_ssize_t)MPD_MAX_EMAX-5);
	ASSERT(strcmp(t, buf) == 0)
	ASSERT(ctx.status == 0)
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	ctx.prec = MPD_MAX_PREC;
	snprintf(buf, BUFSIZE, "0.0000000000000000000000001e%" PRI_mpd_ssize_t,
	         (mpd_ssize_t)MPD_MAX_EMAX+30);
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	ASSERT(strcmp(t, "Infinity") == 0)
	ASSERT(ctx.status == (MPD_Inexact|MPD_Overflow|MPD_Rounded))
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	ctx.prec = MPD_MAX_PREC;
	snprintf(buf, BUFSIZE, "1000000000000000000000000000e%" PRI_mpd_ssize_t, mpd_etiny(&ctx)-27);
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	snprintf(buf, BUFSIZE, "1E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
	ASSERT(strcmp(t, buf) == 0)
	ASSERT(ctx.status == (MPD_Subnormal|MPD_Rounded))
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	ctx.prec = 28;
	snprintf(buf, BUFSIZE, "-0.0000000000000000000000001e%" PRI_mpd_ssize_t, MPD_SSIZE_MAX);
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	ASSERT(strcmp(t, "-Infinity") == 0)
	ASSERT(ctx.status == (MPD_Overflow|MPD_Rounded|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	ctx.prec = 28;
	snprintf(buf, BUFSIZE, "-0.0000000000000000000000001e%" PRI_mpd_ssize_t, MPD_SSIZE_MIN);
	mpd_set_string(&a, buf, &ctx);
	snprintf(buf, BUFSIZE, "-0E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
	t = mpd_to_sci(&a, 1);
	ASSERT(strcmp(t, buf) == 0)
	ASSERT(ctx.status == (MPD_Subnormal|MPD_Inexact|
	                      MPD_Clamped|MPD_Underflow|
	                      MPD_Rounded))
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	n = snprintf(buf, BUFSIZE, "1e%s", "184467440737095516161");
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	ASSERT(strcmp(t, "Infinity") == 0)
	ASSERT(ctx.status == (MPD_Inexact|MPD_Overflow|MPD_Rounded))
	__mingw_dfp_get_globals()->mpd_free(t);

	ctx.status = 0;
	n = snprintf(buf, BUFSIZE, "-1e%s", "-184467440737095516161");
	mpd_set_string(&a, buf, &ctx);
	t = mpd_to_sci(&a, 1);
	snprintf(buf, BUFSIZE, "-0E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
	ASSERT(strcmp(t, buf) == 0)
	ASSERT(ctx.status == (MPD_Subnormal|MPD_Inexact|
	                      MPD_Clamped|MPD_Underflow|
	                      MPD_Rounded))
	__mingw_dfp_get_globals()->mpd_free(t);


	/* Exponent and precision limits: requires large amounts of memory. */
	mem = MPD_MAX_PREC+10+23+1;
	if ((s = malloc(mem)) == NULL) {
		mpd_del(&a);
		mpd_del(&b);
		return;
	}

	ctx.prec = MPD_MAX_PREC;

	/* .000...0001e2147483647 -> Infinity */
	s[0] = '.';
	memset(s+1, '0', MPD_MAX_PREC-1);
	s[MPD_MAX_PREC] = '1';
	s[MPD_MAX_PREC+1] = 'e';
	s[MPD_MAX_PREC+2] = '\0';

	ctx.status = 0;
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%" PRI_mpd_ssize_t, MPD_SSIZE_MAX);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		ASSERT(strcmp(t, "Infinity") == 0)
		ASSERT(ctx.status == (MPD_Inexact|MPD_Overflow|MPD_Rounded))
		__mingw_dfp_get_globals()->mpd_free(t);

	}

	/* .000...0001e184467440737095516161 -> Infinity */
	ctx.status = 0;
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%s", "184467440737095516161");
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		ASSERT(strcmp(t, "Infinity") == 0)
		ASSERT(ctx.status == (MPD_Inexact|MPD_Overflow|MPD_Rounded))
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* .000...0001e425000000 -> 1 */
	ctx.status = 0;
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%" PRI_mpd_ssize_t, (mpd_ssize_t)MPD_MAX_EMAX);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		ASSERT(strcmp(t, "1") == 0)
		ASSERT(ctx.status == 0)
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* .000...0001e850000000 -> 1 */
	ctx.status = 0;
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%" PRI_mpd_ssize_t, 2*(mpd_ssize_t)MPD_MAX_EMAX);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		snprintf(buf, BUFSIZE, "1E+%" PRI_mpd_ssize_t, (mpd_ssize_t)MPD_MAX_EMAX);
		ASSERT(strcmp(t, buf) == 0)
		ASSERT(ctx.status == 0)
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* .000...0005e424999999 -> 0.5 */
	ctx.status = 0;
	s[MPD_MAX_PREC] = '5';
	s[MPD_MAX_PREC+1] = 'e';
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%" PRI_mpd_ssize_t, (mpd_ssize_t)MPD_MAX_EMAX-1);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		ASSERT(strcmp(t, "0.5") == 0)
		ASSERT(ctx.status == 0)
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* .000...0001e-2147483648 -> 0E-849999999 */
	ctx.status = 0;
	s[MPD_MAX_PREC] = '1';
	s[MPD_MAX_PREC+1] = 'e';
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%" PRI_mpd_ssize_t, MPD_SSIZE_MIN);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		snprintf(buf, BUFSIZE, "0E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
		ASSERT(strcmp(t, buf) == 0)
		ASSERT(ctx.status == (MPD_Subnormal|MPD_Inexact|
		                      MPD_Clamped|MPD_Underflow|
		                      MPD_Rounded))
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* .000...0001e-184467440737095516161 -> 0E-849999999 */
	ctx.status = 0;
	s[MPD_MAX_PREC] = '1';
	s[MPD_MAX_PREC+1] = 'e';
	s[MPD_MAX_PREC+2] = '\0';
	n = snprintf(s+MPD_MAX_PREC+2, 23, "%s", "-184467440737095516161");
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		snprintf(buf, BUFSIZE, "0E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
		ASSERT(strcmp(t, buf) == 0)
		ASSERT(ctx.status == (MPD_Subnormal|MPD_Inexact|
		                      MPD_Clamped|MPD_Underflow|
		                      MPD_Rounded))
		__mingw_dfp_get_globals()->mpd_free(t);

	}

	/* 10000...0000e-425000000 -> 0.1 */
	ctx.status = 0;
	s[0] = '1';
	memset(s+1, '0', MPD_MAX_PREC-1);
	s[MPD_MAX_PREC] = 'e';
	s[MPD_MAX_PREC+1] = '\0';
	n = snprintf(s+MPD_MAX_PREC+1, 23, "%" PRI_mpd_ssize_t, (mpd_ssize_t)MPD_MIN_EMIN);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		mpd_set_string(&b, "0.1", &ctx);
		ASSERT(mpd_cmp(&a, &b, &ctx) == 0)
		ASSERT(ctx.status == 0)
	}

	/* 10000...0000e-1275000000 -> 1 */
	ctx.status = 0;
	s[0] = '1';
	memset(s+1, '0', MPD_MAX_PREC-1);
	s[MPD_MAX_PREC] = 'e';
	s[MPD_MAX_PREC+1] = '\0';
	n = snprintf(s+MPD_MAX_PREC+1, 23, "%" PRI_mpd_ssize_t, 3*(mpd_ssize_t)MPD_MIN_EMIN+2);
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		snprintf(buf, BUFSIZE, "1E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
		ASSERT(strcmp(t, buf) == 0)
		ASSERT(ctx.status == (MPD_Subnormal|MPD_Rounded))
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* Too many fraction digits: .000...0001e184467440737095516161 -> NaN */
	s[0] = '.';
	memset(s+1, '0', MPD_MAX_PREC);
	s[MPD_MAX_PREC+1] = '1';
	s[MPD_MAX_PREC+2] = 'e';

	ctx.status = 0;
	s[MPD_MAX_PREC+3] = '\0';
	n = snprintf(s+MPD_MAX_PREC+3, 23, "%s", "184467440737095516161");
	mpd_set_string(&a, s, &ctx);
	if (n > 0 && !(ctx.status&MPD_Malloc_error)) {
		t = mpd_to_sci(&a, 1);
		ASSERT(strcmp(t, "NaN") == 0)
		ASSERT(ctx.status == MPD_Conversion_syntax)
		__mingw_dfp_get_globals()->mpd_free(t);
	}

	/* Exactly MPD_MAX_PREC digits */
	ctx.status = 0;
	ctx.prec = MPD_MAX_PREC;
	memset(s, '9', MPD_MAX_PREC);
	s[MPD_MAX_PREC] = '\0';
	mpd_set_string(&a, s, &ctx);
	if (!(ctx.status&MPD_Malloc_error)) {
		ASSERT(ctx.status == 0)
		t = mpd_to_sci(&a, 0);
		if (t != NULL) {
			ASSERT(strcmp(t, s) == 0)
			__mingw_dfp_get_globals()->mpd_free(t);
		}
	}

	/* Too many digits: 99999...9999 -> NaN */
	ctx.status = 0;
	memset(s, '9', MPD_MAX_PREC+1);
	s[MPD_MAX_PREC+1] = '\0';
	mpd_set_string(&a, s, &ctx);
	if (!(ctx.status&MPD_Malloc_error)) {
		ASSERT(ctx.status == MPD_Conversion_syntax)
	}

	mpd_del(&a);
	mpd_del(&b);
	free(s);
}

static void
test_memory(void)
{
	mpd_context_t ctx;
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	mpd_t *a;

	mpd_testcontext(&ctx);
	ctx.traps = 0;

	/* Allocation failures */
	ctx.status = 0;
	a = mpd_new(&ctx);
	mpd_set_alloc_fail(&ctx);
	mpd_resize(a, 20, &ctx);
	mpd_set_alloc(&ctx);
	ASSERT(ctx.status & MPD_Malloc_error)
	ASSERT(mpd_isnan(a))
	mpd_del(a);

	ctx.status = 0;
	mpd_set_alloc_fail(&ctx);
	mpd_resize_zero(&b, MPD_MINALLOC_MAX+1, &ctx);
	mpd_set_alloc(&ctx);
	ASSERT(ctx.status & MPD_Malloc_error)
	ASSERT(mpd_isnan(&b))

	for (alloc_fail = 1; alloc_fail <= 10; alloc_fail++) {
		ctx.status = 0;

		mpd_set_alloc_fail(&ctx);
		a = mpd_new(&ctx);
		mpd_set_alloc(&ctx);

		if (!(ctx.status & MPD_Malloc_error)) {
			mpd_del(a);
			break;
		}
		ASSERT(a == NULL)
	}
	ASSERT(alloc_fail == 3)

#if MPD_SIZE_MAX < SIZE_MAX
{
	char *s;
	s = mpd_callocfunc_em((size_t)MPD_SIZE_MAX+1, 16);
	ASSERT(s == NULL)
	s = mpd_callocfunc_em(16, (size_t)MPD_SIZE_MAX+1);
	ASSERT(s == NULL)
}
#endif

	mpd_del(&b);
}

static void
test_output(void)
{
	uint32_t status;
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	FILE *fp;
	char buf[BUFSIZE];
	char *s;
	int n;

	mpd_testcontext(&ctx);
	ctx.traps = 0;

	/* printing of flags and signals */
	status = MPD_Max_status;

	s = "Clamped Conversion_syntax Division_by_zero Division_impossible "
	    "Division_undefined Fpu_error Inexact Invalid_context Invalid_operation "
	    "Malloc_error Not_implemented Overflow Rounded Subnormal Underflow";

	n = mpd_snprint_flags(buf, BUFSIZE, status);
	ASSERT(n > 0 && (size_t)n == strlen(s))
	ASSERT(strcmp(buf, s) == 0)

	s = "[Clamped, Conversion_syntax, Division_by_zero, Division_impossible, "
	    "Division_undefined, Fpu_error, Inexact, Invalid_context, Invalid_operation, "
	    "Malloc_error, Not_implemented, Overflow, Rounded, Subnormal, Underflow]";

	n = mpd_lsnprint_flags(buf, BUFSIZE, status, NULL);
	ASSERT(n > 0 && (size_t)n == strlen(s))
	ASSERT(strcmp(buf, s) == 0)

	s = "[Clamped, IEEE_Invalid_operation, Division_by_zero, Inexact, "
	    "Not_implemented, Overflow, Rounded, Subnormal, Underflow]";

	n = mpd_lsnprint_signals(buf, BUFSIZE, status, NULL);
	ASSERT(n > 0 && (size_t)n == strlen(s))
	ASSERT(strcmp(buf, s) == 0)

	/* simple printing to file */
	if ((fp = tmpfile()) != NULL) {
		mpd_set_string(&a, "1.23456789e441", &ctx);
		mpd_fprint(fp, &a);
		rewind(fp);
		if (fgets(buf, BUFSIZE, fp) != NULL) {
			ASSERT(strcmp(buf, "1.23456789e441\n"))
		}
		fclose(fp);
	}

	/* simple printing to stdout */
	mpd_set_string(&a, "1.23456789e441", &ctx);
	printf("  This line is part of the coverage test: ");
	mpd_print(&a);

	/* mpd_qformat_spec */

	/* min_width > MPD_MAX_PREC */
	ctx.status = 0;
	ctx.prec = MPD_MAX_PREC;
	mpd_set_string(&a, "1.23456789e441", &ctx);
	snprintf(buf, BUFSIZE, "%" PRI_mpd_ssize_t ".10", (mpd_ssize_t)MPD_MAX_PREC+1);
	s = mpd_format(&a, buf, &ctx);
	ASSERT(s == NULL && (ctx.status&MPD_Invalid_operation))

	mpd_del(&a);
}

typedef struct {
	uint8_t sign;
	mpd_uint_t value;
} signed_uint_t;
#ifdef CONFIG_64
  #define MPD_MIN_ETINY_ MPD_MIN_ETINY
  #define MPD_MAX_EMAX_ MPD_MAX_EMAX
  #define MPD_MIN_EMIN_ MPD_MIN_EMIN
#else
  #define MPD_MIN_ETINY_ -1999999997
  #define MPD_MAX_EMAX_ 999999999
  #define MPD_MIN_EMIN_ -999999999
#endif

static void
test_scaleb(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	signed_uint_t a_exp, b_exp;
	int i;

	mpd_maxcontext(&ctx);
	ctx.traps = 0;

#ifdef CONFIG_32
	/* generally not safe */
	ctx.prec = 999999999;
	ctx.emax = 999999999;
	ctx.emin = -999999999;

	ctx.status = 0;
	mpd_set_string(&a, "1e999999999", &ctx);
	mpd_set_string(&b, "1147483648", &ctx);
	mpd_scaleb(&a, &a, &b, &ctx);
	ASSERT(ctx.status&MPD_Overflow)
	ASSERT(mpd_ispositive(&a))
	ASSERT(mpd_isinfinite(&a))

	ctx.status = 0;
	mpd_set_string(&a, "1e999999999", &ctx);
	mpd_set_string(&b, "1147483649", &ctx);
	mpd_scaleb(&a, &a, &b, &ctx);
	ASSERT(ctx.status&MPD_Overflow)
	ASSERT(mpd_ispositive(&a))
	ASSERT(mpd_isinfinite(&a))

	ctx.status = 0;
	mpd_set_string(&a, "1e-1999999997", &ctx);
	mpd_set_string(&b, "-147483651", &ctx);
	mpd_scaleb(&a, &a, &b, &ctx);
	ASSERT(ctx.status&(MPD_Underflow|MPD_Clamped))
	ASSERT(mpd_ispositive(&a))
	ASSERT(mpd_iszero(&a))

	ctx.status = 0;
	mpd_set_string(&a, "1e-1999999997", &ctx);
	mpd_set_string(&b, "-147483652", &ctx);
	mpd_scaleb(&a, &a, &b, &ctx);
	ASSERT(ctx.status&(MPD_Underflow|MPD_Clamped))
	ASSERT(mpd_ispositive(&a))
	ASSERT(mpd_iszero(&a))
#endif

	for (i = 0; i < 10000; i++) {
		ctx.status = 0;

		b_exp.value = (mpd_uint_t)randbits();
		b_exp.sign = random()%2;
		mpd_sset_uint(&b, b_exp.value, &ctx);
		mpd_set_sign(&b, b_exp.sign);

		a_exp.sign = random()%2;
		if (a_exp.sign) {
			a_exp.value = random()%(MPD_MAX_EMAX_+1);
		}
		else {
			a_exp.value = random()%(-MPD_MIN_ETINY_+1);
		}
		mpd_set_string(&a, "1", &ctx);
		a.exp = a_exp.value;
		a.exp *= (a_exp.sign?-1:1);

		mpd_scaleb(&a, &a, &b, &ctx);
		if (b_exp.value > 2 * (mpd_uint_t)(ctx.prec + ctx.emax)) {
			ASSERT(ctx.status&MPD_Invalid_operation)
			ASSERT(mpd_isnan(&a))
		}
		else {
		#if !defined(LEGACY_COMPILER) || defined (__GNUC__) || defined(_MSC_VER)
			int64_t x;
			x = (int64_t)a_exp.value * (a_exp.sign?-1:1);
			x += (int64_t)b_exp.value * (b_exp.sign?-1:1);
			if (x < MPD_MIN_ETINY_) {
				ASSERT(ctx.status&MPD_Underflow)
				ASSERT(mpd_iszero(&a))
			}
			else if (MPD_MIN_ETINY_ <= x && x < MPD_MIN_EMIN_) {
				ASSERT(ctx.status&MPD_Subnormal)
				ASSERT(a.exp == x)
			}
			else if (MPD_MIN_EMIN_ <= x && x <= MPD_MAX_EMAX_) {
				ASSERT(ctx.status == 0)
				ASSERT(a.exp == x)
			}
			else {
				ASSERT(ctx.status&MPD_Overflow)
				ASSERT(mpd_isinfinite(&a))
			}
		#endif
			ASSERT(!(ctx.status&MPD_Invalid_operation))
		}
	}

	mpd_del(&a);
	mpd_del(&b);
}

static sig_atomic_t sigfpe_raised = 0;
void
sigfpe_handler(int signum)
{
	(void)signum;
	sigfpe_raised = 1;
}

static void
test_misc(void)
{
	mpd_context_t ctx;
	mpd_uint_t adata[MPD_MINALLOC_MAX];
	mpd_uint_t bdata[MPD_MINALLOC_MAX];
	mpd_t a = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, adata};
	mpd_t b = {MPD_STATIC|MPD_STATIC_DATA, 0, 0, 0, MPD_MINALLOC_MAX, bdata};
	char buf[BUFSIZE];
	char *s, *t;

	mpd_testcontext(&ctx);
	ctx.traps = 0;

	/* signcpy */
	mpd_set_string(&b, "3", &ctx);
	mpd_signcpy(&b, &a);
	s = mpd_to_sci(&b, 0);
	ASSERT(strcmp(s, "-3"))
	__mingw_dfp_get_globals()->mpd_free(s);

	/* maxcoeff */
	ctx.prec = 28;
	ctx.status = 0;
	mpd_set_string(&a, "1e2025", &ctx);
	mpd_maxcoeff(&a, &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "9999999999999999999999999999e2025"))
	ASSERT(ctx.status == 0)
	__mingw_dfp_get_globals()->mpd_free(s);

	/* canonical */
	ctx.status = 0;
	mpd_set_string(&a, "1.182736812e999999", &ctx);
	mpd_canonical(&b, &a, &ctx);
	s = mpd_to_sci(&a, 0);
	t = mpd_to_sci(&b, 0);
	ASSERT(strcmp(s, t) == 0)
	ASSERT(ctx.status == 0)
	__mingw_dfp_get_globals()->mpd_free(s);
	__mingw_dfp_get_globals()->mpd_free(t);

	/* mpd_msword */
	mpd_set_string(&a, "2.3854727e+1875", &ctx);
	ASSERT(mpd_msd(mpd_msword(&a)) == 2)

	/* mpd_radix */
	ASSERT(mpd_radix() == 10)

	/* rescale, greater than emax */
	ctx.status = 0;
	mpd_set_string(&a, "3.3", &ctx);
	mpd_rescale(&a, &a, MPD_MAX_EMAX+1, &ctx);
	s = mpd_to_sci(&a, 1);
	ASSERT(strcmp(s, "NaN") == 0)
	ASSERT(ctx.status == MPD_Invalid_operation)
	__mingw_dfp_get_globals()->mpd_free(s);

	/* CONFIG_64: Over/Underflow in power */
	ctx.status = 0;
	mpd_set_string(&a, "1.000000001", &ctx);
	mpd_set_string(&b, "12345676891234567891123456789", &ctx);
	mpd_pow(&a, &a, &b, &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "Infinity") == 0)
	ASSERT(ctx.status == (MPD_Rounded|MPD_Overflow|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);

	ctx.status = 0;
	mpd_set_string(&a, "1.000000001", &ctx);
	mpd_set_string(&b, "-12345676891234567891123456789", &ctx);
	mpd_pow(&a, &a, &b, &ctx);
	s = mpd_to_sci(&a, 1);
	snprintf(buf, BUFSIZE, "0E%" PRI_mpd_ssize_t, mpd_etiny(&ctx));
	ASSERT(strcmp(s, buf) == 0)
	ASSERT(ctx.status == (MPD_Underflow|MPD_Rounded|MPD_Clamped|MPD_Inexact|MPD_Subnormal))
	__mingw_dfp_get_globals()->mpd_free(s);

	ctx.status = 0;
	mpd_set_string(&a, "2.2122163", &ctx);
	mpd_set_string(&b, "2899999999999999999.891239129", &ctx);
	mpd_pow(&a, &a, &b, &ctx);
	s = mpd_to_sci(&a, 0);
	ASSERT(strcmp(s, "Infinity") == 0)
	ASSERT(ctx.status == (MPD_Rounded|MPD_Overflow|MPD_Inexact))
	__mingw_dfp_get_globals()->mpd_free(s);

#if defined(CONFIG_32) && !defined(LEGACY_COMPILER)
	/* Allocation failure in mpd_set_u64 */
	mpd_resize(&a, MPD_MINALLOC_MAX+1, &ctx);
	mpd_minalloc(&a);

	ctx.status = 0;
	mpd_set_alloc_fail(&ctx);
	mpd_set_u64(&a, UINT64_MAX, &ctx);
	mpd_set_alloc(&ctx);

	ASSERT(ctx.status & MPD_Malloc_error)
	ASSERT(mpd_isnan(&a))
#endif

	/* Default trap handler: SIGFPE */
	signal(SIGFPE, sigfpe_handler);
	ctx.traps = MPD_Rounded;
	mpd_set_string(&a, "1", &ctx);
	ASSERT(sigfpe_raised == 0)
	mpd_div_uint(&a, &a, 7, &ctx);
	ASSERT(sigfpe_raised == 1)

	mpd_del(&a);
	mpd_del(&b);
}


int
main(void)
{
	mpd_context_t ctx;

	srand((unsigned int)time(NULL));
	fprintf(stderr, "Running cov ... \n\n");

	/* context.c */
	test_context(); /* Run this first! */

	/* mpdecimal.c */
	test_check_nans();
	test_finalize_round();
	test_attributes();

	test_int_conversions();
	mpd_testcontext(&ctx);
	test_mixed_arith(&ctx);

	ctx.traps = 0;
	for (ctx.prec = 1; ctx.prec < 23; ctx.prec++) {
		for (ctx.emax = 1; ctx.emax < 23; ctx.emax++) {
			if (ctx.emax < ctx.prec) continue;
			ctx.emin = -ctx.emax;
			test_mixed_arith(&ctx);
		}
	}

	test_shift();
	test_baseconv();
	test_scaleb();
	test_misc();

	/* memory.c */
	test_memory();

	/* io.c */
	test_set_string();
	test_output();

	/* Valgrind */
	mpd_del(&__mingw_dfp_get_globals()->mpd_ln10);

	fprintf(stderr, "\ncov: PASS\n");
	return 0;
}


