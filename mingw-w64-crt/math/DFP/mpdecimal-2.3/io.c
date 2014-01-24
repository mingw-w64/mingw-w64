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
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <locale.h>
#include "bits.h"
#include "constants.h"
#include "memory.h"
#include "typearith.h"
#include "io.h"


/*
 * Work around the behavior of tolower() and strcasecmp() in certain
 * locales. For example, in tr_TR.utf8:
 *
 * tolower((unsigned char)'I') == 'I'
 *
 * u is the exact uppercase version of l; n is strlen(l) or strlen(l)+1
 */
static inline int
_mpd_strneq(const char *s, const char *l, const char *u, size_t n)
{
	while (--n != SIZE_MAX) {
		if (*s != *l && *s != *u) {
			return 0;
		}
		s++; u++; l++;
	}

	return 1;
}

static mpd_ssize_t
strtoexp(const char *s)
{
	char *end;
	mpd_ssize_t retval;

	errno = 0;
	retval = mpd_strtossize(s, &end, 10);
	if (errno == 0 && !(*s != '\0' && *end == '\0'))
		errno = EINVAL;

	return retval;
}

/*
 * Scan 'len' words. The most significant word contains 'r' digits,
 * the remaining words are full words. Skip dpoint. The string 's' must
 * consist of digits and an optional single decimal point at 'dpoint'.
 */
static void
string_to_coeff(mpd_uint_t *data, const char *s, const char *dpoint, int r,
                size_t len)
{
	int j;

	if (r > 0) {
		data[--len] = 0;
		for (j = 0; j < r; j++, s++) {
			if (s == dpoint) s++;
			data[len] = 10 * data[len] + (*s - '0');
		}
	}

	while (--len != SIZE_MAX) {
		data[len] = 0;
		for (j = 0; j < MPD_RDIGITS; j++, s++) {
			if (s == dpoint) s++;
			data[len] = 10 * data[len] + (*s - '0');
		}
	}
}

/*
 * Scan for at most one decimal point and at most one indicator.
 * Remove unneeded zeros before and after the decimal point.
 * The first relevant digit will be the start of the coefficient.
 * A decimal point may occur before an indicator.
 * Plus or minus may occur directly after the indicator.
 * The rest of the characters must be decimal digits.
 *
 * Return start of the coefficient or NULL or error. The end of
 * the string is stored in 'end'.
 */
static const char *
scan_dpoint_exp(const char *s, const char **dpoint, const char **exp,
                const char **end)
{
	const char *coeff = NULL;

	*dpoint = NULL;
	*exp = NULL;
	for (; *s != '\0'; s++) {
		switch (*s) {
		case '.':
			if (*dpoint != NULL || *exp != NULL)
				return NULL;
			*dpoint = s;
			break;
		case 'E': case 'e':
			if (*exp != NULL)
				return NULL;
			*exp = s;
			if (*(s+1) == '+' || *(s+1) == '-')
				s++;
			break;
		default:
			if (!isdigit((uchar)*s))
				return NULL;
			if (coeff == NULL && *exp == NULL) {
				if (*s == '0') {
					if (!isdigit((uchar)*(s+1)))
						if (!(*(s+1) == '.' &&
						      isdigit((uchar)*(s+2))))
							coeff = s;
				}
				else {
					coeff = s;
				}
			}
			break;

		}
	}

	*end = s;
	return coeff;
}

/* scan the payload of a NaN */
static const char *
scan_payload(const char *s, const char **end)
{
	const char *coeff;

	while (*s == '0')
		s++;
	coeff = s;

	while (isdigit((uchar)*s))
		s++;
	*end = s;

	return (*s == '\0') ? coeff : NULL;
}

/* convert a character string to a decimal */
void
mpd_qset_string(mpd_t *dec, const char *s, const mpd_context_t *ctx,
                uint32_t *status)
{
	mpd_ssize_t q, r, len;
	const char *coeff, *end;
	const char *dpoint = NULL, *exp = NULL;
	size_t digits;
	uint8_t sign = MPD_POS;

	mpd_set_flags(dec, 0);
	dec->len = 0;
	dec->exp = 0;

	/* [flags] */
	if (*s == '+') {
		s++;
	}
	else if (*s == '-') {
		mpd_set_negative(dec);
		sign = MPD_NEG;
		s++;
	}

	if (_mpd_strneq(s, "nan", "NAN", 3)) { /* NaN */
		s += 3;
		mpd_setspecial(dec, sign, MPD_NAN);
		if (*s == '\0')
			return;
		/* only digits for the diagnostic code */
		if ((coeff = scan_payload(s, &end)) == NULL)
			goto conversion_error;
		/* payload consists entirely of zeros */
		if (*coeff == '\0')
			return;
		digits = end - coeff;
		/* prec >= 1, clamp is 0 or 1 */
		if (digits > (size_t)(ctx->prec-ctx->clamp))
			goto conversion_error;
	} /* sNaN */
	else if (_mpd_strneq(s, "snan", "SNAN", 4)) {
		s += 4;
		mpd_setspecial(dec, sign, MPD_SNAN);
		if (*s == '\0')
			return;
		/* only digits for the diagnostic code */
		if ((coeff = scan_payload(s, &end)) == NULL)
			goto conversion_error;
		/* payload consists entirely of zeros */
		if (*coeff == '\0')
			return;
		digits = end - coeff;
		if (digits > (size_t)(ctx->prec-ctx->clamp))
			goto conversion_error;
	}
	else if (_mpd_strneq(s, "inf", "INF", 3)) {
		s += 3;
		if (*s == '\0' || _mpd_strneq(s, "inity", "INITY", 6)) {
			/* numeric-value: infinity */
			mpd_setspecial(dec, sign, MPD_INF);
			return;
		}
		goto conversion_error;
	}
	else {
		/* scan for start of coefficient, decimal point, indicator, end */
		if ((coeff = scan_dpoint_exp(s, &dpoint, &exp, &end)) == NULL)
			goto conversion_error;

		/* numeric-value: [exponent-part] */
		if (exp) {
			/* exponent-part */
			end = exp; exp++;
			dec->exp = strtoexp(exp);
			if (errno) {
				if (!(errno == ERANGE &&
				     (dec->exp == MPD_SSIZE_MAX ||
				      dec->exp == MPD_SSIZE_MIN)))
					goto conversion_error;
			}
		}

	        digits = end - coeff;
		if (dpoint) {
			size_t fracdigits = end-dpoint-1;
			if (dpoint > coeff) digits--;

			if (fracdigits > MPD_MAX_PREC) {
				goto conversion_error;
			}
			if (dec->exp < (MPD_SSIZE_MIN+1)+(mpd_ssize_t)fracdigits) {
				dec->exp = MPD_SSIZE_MIN+1;
			}
			else {
				dec->exp -= (mpd_ssize_t)fracdigits;
			}
		}
		if (digits > MPD_MAX_PREC) {
			goto conversion_error;
		}
		if (dec->exp > MPD_EXP_INF) {
			dec->exp = MPD_EXP_INF;
		}
	}

	_mpd_idiv_word(&q, &r, (mpd_ssize_t)digits, MPD_RDIGITS);

	len = (r == 0) ? q : q+1;
	if (len == 0) {
		goto conversion_error; /* GCOV_NOT_REACHED */
	}
	if (!mpd_qresize(dec, len, status)) {
		mpd_seterror(dec, MPD_Malloc_error, status);
		return;
	}
	dec->len = len;

	string_to_coeff(dec->data, coeff, dpoint, (int)r, len);

	mpd_setdigits(dec);
	mpd_qfinalize(dec, ctx, status);
	return;

conversion_error:
	/* standard wants a positive NaN */
	mpd_seterror(dec, MPD_Conversion_syntax, status);
}

/* print the exponent to a string */
static inline char *
exp_to_string(char *s, mpd_ssize_t x)
{
	mpd_ssize_t q, d;
	char sign = '+';
	int j;

	if (x < 0) {
		sign = '-';
		x = -x;
	}
	*s++ = sign;

	j = mpd_exp_digits(x) - 1;

	for (; j != 0; --j) {
		d = mpd_pow10[j];
		q = x / d;
		x -= d * q;
		*s++ = '0' + (char)q;
	}
	*s++ = '0' + (char)x;

	return s;
}

/* print coefficient to string, len(dec) > 0 */
static inline char *
coeff_to_string(char *s, const mpd_t *dec)
{
	mpd_uint_t x, q, d;
	mpd_ssize_t i;
	int j;

	/* most significant word */
	x = mpd_msword(dec);
	j = mpd_word_digits(x) - 1;

	for (; j != 0; --j) {
		d = mpd_pow10[j];
		q = x / d;
		x -= d * q;
		*s++ = '0' + (char)q;
	}
	*s++ = '0' + (char)x;

	/* remaining full words */
	for (i=dec->len-2; i >= 0; --i) {
		x = dec->data[i];
		for (j=MPD_RDIGITS-1; j != 0; --j) {
			d = mpd_pow10[j];
			q = x / d;
			x -= d * q;
			*s++ = '0' + (char)q;
		}
		*s++ = '0' + (char)x;
	}

	return s;
}

/* print coefficient to string, len(dec) > 0 */
static inline char *
coeff_to_string_dot(char *s, char *dot, const mpd_t *dec)
{
	mpd_uint_t x, q, d;
	mpd_ssize_t i;
	int j;

	/* most significant word */
	x = mpd_msword(dec);
	j = mpd_word_digits(x) - 1;

	for (; j >= 0; --j) {
		if (s == dot)
			*s++ = '.';
		d = mpd_pow10[j];
		q = x / d;
		x -= d * q;
		*s++ = '0' + (char)q;
	}

	/* remaining full words */
	for (i=dec->len-2; i >= 0; --i) {
		x = dec->data[i];
		for (j=MPD_RDIGITS-1; j >= 0; --j) {
			if (s == dot)
				*s++ = '.';
			d = mpd_pow10[j];
			q = x / d;
			x -= d * q;
			*s++ = '0' + (char)q;
		}
	}

	return s;
}

/* Format type */
#define MPD_FMT_LOWER      0x00000000
#define MPD_FMT_UPPER      0x00000001
#define MPD_FMT_TOSCI      0x00000002
#define MPD_FMT_TOENG      0x00000004
#define MPD_FMT_EXP        0x00000008
#define MPD_FMT_FIXED      0x00000010
#define MPD_FMT_PERCENT    0x00000020
#define MPD_FMT_SIGN_SPACE 0x00000040
#define MPD_FMT_SIGN_PLUS  0x00000080

/*
 * Return the string representation of a decimal. Formatting is done according
 * to 'flags'. A return value of NULL indicates MPD_Malloc_error.
 *
 * To allow formatting like [0e15, '.6e' -> 0.000000e-9], 'zeroexp' is used
 * in combination with MPD_FMT_FIXED (see mpd_qformat for details).
 */
static char *
_mpd_to_string(const mpd_t *dec, int flags, mpd_ssize_t zeroexp)
{
	char *decstring = NULL, *cp = NULL;
	mpd_ssize_t ldigits, dplace;
	mpd_ssize_t mem = 0, k;

	if (mpd_isspecial(dec)) {

		mem = sizeof "-Infinity";
		if (mpd_isnan(dec) && dec->len > 0) {
			/* diagnostic code */
			mem += dec->digits;
		}
		cp = decstring = mpd_alloc(mem, sizeof *decstring);
		if (cp == NULL) {
			return NULL;
		}

		if (mpd_isnegative(dec)) {
			*cp++ = '-';
		}
		else if (flags&MPD_FMT_SIGN_SPACE) {
			*cp++ = ' ';
		}
		else if (flags&MPD_FMT_SIGN_PLUS) {
			*cp++ = '+';
		}

		if (mpd_isnan(dec)) {
			if (mpd_isqnan(dec)) {
				strcpy(cp, "NaN");
				cp += 3;
			}
			else {
				strcpy(cp, "sNaN");
				cp += 4;
			}
			if (dec->len > 0) { /* diagnostic code */
				cp = coeff_to_string(cp, dec);
			}
		}
		else if (mpd_isinfinite(dec)) {
			strcpy(cp, "Infinity");
			cp += 8;
		}
		else { /* debug */
			abort(); /* GCOV_NOT_REACHED */
		}
	}
	else {
		assert(dec->len > 0);

		/*
		 * ldigits: Digits to the left of the decimal point, as if the
		 *          number was written without exponent notation.
		 *
		 * dplace: Position of the decimal point relative to the first
		 *         member of the coefficient.
		 *
		 * 0.00000_.____._____000000.
		 *  ^      ^    ^           ^
		 *  |      |    |           |
		 *  |      |    |           `- dplace in the last position
		 *  |      |    `- dplace in the middle of the coefficient
		 *  |      ` dplace = 1 (after the first coefficient digit)
		 *  `- dplace is negative
		 */

		ldigits = dec->digits + dec->exp;
		dplace = 1; /* default for MPD_FMT_TOSCI, MPD_FMT_EXP */

		if (flags&MPD_FMT_EXP) {
			;
		}
		else if (flags&MPD_FMT_FIXED || (dec->exp <= 0 && ldigits > -6)) {
			/* MPD_FMT_FIXED: always use fixed point notation.
			 * MPD_FMT_TOSCI, MPD_FMT_TOENG: for a certain range,
			 * override exponent notation. */
			dplace = ldigits;
		}
		else if (flags&MPD_FMT_TOENG) {
			if (mpd_iszero(dec)) {
				/* If the exponent is divisible by three,
				 * dplace = 1. Otherwise, move dplace one
				 * or two places to the left. */
				dplace = -1 + mod_mpd_ssize_t(dec->exp+2, 3);
			}
			else { /* ldigits-1 is the adjusted exponent, which
				* should be divisible by three. If not, move
				* dplace one or two places to the right. */
				dplace += mod_mpd_ssize_t(ldigits-1, 3);
			}
		}

		/*
		 * Basic space requirements:
		 *
		 * [-][.][coeffdigits][E][-][expdigits+1][%]['\0']
		 *
		 * If the decimal point lies outside of the coefficient digits,
		 * space is adjusted accordingly.
		 */
		if (dplace <= 0) {
			mem = -dplace + dec->digits + 2;
		}
		else if (dplace >= dec->digits) {
			mem = dplace;
		}
		else {
			mem = dec->digits;
		}
		mem += (MPD_EXPDIGITS+1+6);

		cp = decstring = mpd_alloc(mem, sizeof *decstring);
		if (cp == NULL) {
			return NULL;
		}


		if (mpd_isnegative(dec)) {
			*cp++ = '-';
		}
		else if (flags&MPD_FMT_SIGN_SPACE) {
			*cp++ = ' ';
		}
		else if (flags&MPD_FMT_SIGN_PLUS) {
			*cp++ = '+';
		}

		if (dplace <= 0) {
			/* space: -dplace+dec->digits+2 */
			*cp++ = '0';
			*cp++ = '.';
			for (k = 0; k < -dplace; k++) {
				*cp++ = '0';
			}
			cp = coeff_to_string(cp, dec);
		}
		else if (dplace >= dec->digits) {
			/* space: dplace */
			cp = coeff_to_string(cp, dec);
			for (k = 0; k < dplace-dec->digits; k++) {
				*cp++ = '0';
			}
		}
		else {
			/* space: dec->digits+1 */
			cp = coeff_to_string_dot(cp, cp+dplace, dec);
		}

		/*
		 * Conditions for printing an exponent:
		 *
		 *   MPD_FMT_TOSCI, MPD_FMT_TOENG: only if ldigits != dplace
		 *   MPD_FMT_FIXED:                never (ldigits == dplace)
		 *   MPD_FMT_EXP:                  always
		 *   MPD_FMT_FIXED with zeroexp:   always
		 */
		if (ldigits != dplace || flags&MPD_FMT_EXP || zeroexp != MPD_SSIZE_MAX) {
			/* space: expdigits+2 */
			mpd_ssize_t x = (zeroexp != MPD_SSIZE_MAX) ? zeroexp : ldigits-dplace;
			*cp++ = (flags&MPD_FMT_UPPER) ? 'E' : 'e';
			cp = exp_to_string(cp, x);
		}

		if (flags&MPD_FMT_PERCENT) {
			*cp++ = '%';
		}
	}

	assert(cp < decstring+mem);
	*cp = '\0';
	return decstring;
}

char *
mpd_to_sci(const mpd_t *dec, int fmt)
{
	int flags = MPD_FMT_TOSCI;

	flags |= fmt ? MPD_FMT_UPPER : MPD_FMT_LOWER;
	return _mpd_to_string(dec, flags, MPD_SSIZE_MAX);
}

char *
mpd_to_eng(const mpd_t *dec, int fmt)
{
	int flags = MPD_FMT_TOENG;

	flags |= fmt ? MPD_FMT_UPPER : MPD_FMT_LOWER;
	return _mpd_to_string(dec, flags, MPD_SSIZE_MAX);
}

/* Copy a single UTF-8 char to dest. */
static int
_mpd_copy_utf8(char dest[5], const char *s)
{
	const uchar *cp = (const uchar *)s;
	uchar lb, ub;
	int count, i;


	if (*cp == 0) {
		/* empty string */
		dest[0] = '\0';
		return 0;
	}
	else if (*cp <= 0x7f) {
		/* ascii */
		dest[0] = *cp;
		dest[1] = '\0';
		return 1;
	}
	else if (0xc2 <= *cp && *cp <= 0xdf) {
		lb = 0x80; ub = 0xbf;
		count = 2;
	}
	else if (*cp == 0xe0) {
		lb = 0xa0; ub = 0xbf;
		count = 3;
	}
	else if (*cp <= 0xec) {
		lb = 0x80; ub = 0xbf;
		count = 3;
	}
	else if (*cp == 0xed) {
		lb = 0x80; ub = 0x9f;
		count = 3;
	}
	else if (*cp <= 0xef) {
		lb = 0x80; ub = 0xbf;
		count = 3;
	}
	else if (*cp == 0xf0) {
		lb = 0x90; ub = 0xbf;
		count = 4;
	}
	else if (*cp <= 0xf3) {
		lb = 0x80; ub = 0xbf;
		count = 4;
	}
	else if (*cp == 0xf4) {
		lb = 0x80; ub = 0x8f;
		count = 4;
	}
	else {
		/* invalid */
		goto error;
	}

	dest[0] = *cp++;
	if (*cp < lb || ub < *cp) {
		goto error;
	}
	dest[1] = *cp++;
	for (i = 2; i < count; i++) {
		if (*cp < 0x80 || 0xbf < *cp) {
			goto error;
		}
		dest[i] = *cp++;
	}
	dest[i] = '\0';

	return count;

error:
	dest[0] = '\0';
	return -1;
}

int
mpd_parse_fmt_str(mpd_spec_t *spec, const char *fmt, int caps)
{
	char *cp = (char *)fmt;
	int have_align = 0, n;

	/* defaults */
	spec->min_width = 0;
	spec->prec = -1;
	spec->type = caps ? 'G' : 'g';
	spec->align = '>';
	spec->sign = '-';
	spec->dot = "";
	spec->sep = "";
	spec->grouping = "";


	/* presume that the first character is a UTF-8 fill character */
	if ((n = _mpd_copy_utf8(spec->fill, cp)) < 0) {
		return 0;
	}

	/* alignment directive, prefixed by a fill character */
	if (*cp && (*(cp+n) == '<' || *(cp+n) == '>' ||
	            *(cp+n) == '=' || *(cp+n) == '^')) {
		cp += n;
		spec->align = *cp++;
		have_align = 1;
	} /* alignment directive */
	else {
		/* default fill character */
		spec->fill[0] = ' ';
		spec->fill[1] = '\0';
		if (*cp == '<' || *cp == '>' ||
		    *cp == '=' || *cp == '^') {
			spec->align = *cp++;
			have_align = 1;
		}
	}

	/* sign formatting */
	if (*cp == '+' || *cp == '-' || *cp == ' ') {
		spec->sign = *cp++;
	}

	/* zero padding */
	if (*cp == '0') {
		/* zero padding implies alignment, which should not be
		 * specified twice. */
		if (have_align) {
			return 0;
		}
		spec->align = 'z';
		spec->fill[0] = *cp++;
		spec->fill[1] = '\0';
	}

	/* minimum width */
	if (isdigit((uchar)*cp)) {
		if (*cp == '0') {
			return 0;
		}
		errno = 0;
		spec->min_width = mpd_strtossize(cp, &cp, 10);
		if (errno == ERANGE || errno == EINVAL) {
			return 0;
		}
	}

	/* thousands separator */
	if (*cp == ',') {
		spec->dot = ".";
		spec->sep = ",";
		spec->grouping = "\003\003";
		cp++;
	}

	/* fraction digits or significant digits */
	if (*cp == '.') {
		cp++;
		if (!isdigit((uchar)*cp)) {
			return 0;
		}
		errno = 0;
		spec->prec = mpd_strtossize(cp, &cp, 10);
		if (errno == ERANGE || errno == EINVAL) {
			return 0;
		}
	}

	/* type */
	if (*cp == 'E' || *cp == 'e' || *cp == 'F' || *cp == 'f' ||
	    *cp == 'G' || *cp == 'g' || *cp == '%') {
		spec->type = *cp++;
	}
	else if (*cp == 'N' || *cp == 'n') {
		/* locale specific conversion */
		struct lconv *lc;
		spec->type = *cp++;
		/* separator has already been specified */
		if (*spec->sep) return 0;
		spec->type = (spec->type == 'N') ? 'G' : 'g';
		lc = localeconv();
		spec->dot = lc->decimal_point;
		spec->sep = lc->thousands_sep;
		spec->grouping = lc->grouping;
	}

	/* check correctness */
	if (*cp != '\0') {
		return 0;
	}

	return 1;
}

/*
 * The following functions assume that spec->min_width <= MPD_MAX_PREC, which
 * is made sure in mpd_qformat_spec. Then, even with a spec that inserts a
 * four-byte separator after each digit, nbytes in the following struct
 * cannot overflow.
 */

/* Multibyte string */
typedef struct {
	mpd_ssize_t nbytes; /* length in bytes */
	mpd_ssize_t nchars; /* length in chars */
	mpd_ssize_t cur;    /* current write index */
	char *data;
} mpd_mbstr_t;

static inline void
_mpd_bcopy(char *dest, const char *src, mpd_ssize_t n)
{
	while (--n >= 0) {
		dest[n] = src[n];
	}
}

static inline void
_mbstr_copy_char(mpd_mbstr_t *dest, const char *src, mpd_ssize_t n)
{
	dest->nbytes += n;
	dest->nchars += 1;
	dest->cur -= n;

	if (dest->data != NULL) {
		_mpd_bcopy(dest->data+dest->cur, src, n);
	}
}

static inline void
_mbstr_copy_ascii(mpd_mbstr_t *dest, const char *src, mpd_ssize_t n)
{
	dest->nbytes += n;
	dest->nchars += n;
	dest->cur -= n;

	if (dest->data != NULL) {
		_mpd_bcopy(dest->data+dest->cur, src, n);
	}
}

static inline void
_mbstr_copy_pad(mpd_mbstr_t *dest, mpd_ssize_t n)
{
	dest->nbytes += n;
	dest->nchars += n;
	dest->cur -= n;

	if (dest->data != NULL) {
		char*cp = dest->data + dest->cur;
		while (--n >= 0) {
			cp[n] = '0';
		}
	}
}

/*
 * Copy the decimal to dest, adding separators according to
 * spec->grouping. If leading zero padding is enabled and the
 * result is smaller than spec->min_width, continue adding zeros
 * and separators until min_width is reached.
 */
static void
_mpd_add_sep_dot(mpd_mbstr_t *dest,
                 const char *src, mpd_ssize_t n_src, /* integer part and length */
                 const char *sign, const char *dot, const char *rest,
                 mpd_spec_t *spec)
{
	mpd_ssize_t n_sep, n_sign, consume;
	const char *g;
	int pad = 0;

	n_sign = sign ? 1 : 0;
	n_sep = (mpd_ssize_t)strlen(spec->sep);
	g = spec->grouping;
	dest->cur = dest->nbytes;
	dest->nbytes = dest->nchars = 0;

	/* rest <= MPD_MAX_PREC */
	_mbstr_copy_ascii(dest, rest, (mpd_ssize_t)strlen(rest));

	if (dot) {
		_mbstr_copy_char(dest, dot, (mpd_ssize_t)strlen(dot));
	}

	consume = *g;
	while (1) {
		if (*g == 0 || *g == CHAR_MAX || consume > n_src) {
			consume = n_src;
		}
		n_src -= consume;
		if (pad) {
			_mbstr_copy_pad(dest, consume);
		}
		else {
			_mbstr_copy_ascii(dest, src+n_src, consume);
		}

		if (n_src == 0) {
			if (spec->align == 'z' &&
			    dest->nchars + n_sign < spec->min_width) {
				n_src = spec->min_width - (dest->nchars + n_sign);
				consume = *g - consume;
				pad = 1;
				continue;
			}
			break;
		}

		if (n_sep > 0) {
			if (pad && n_src > 1) n_src -= 1;
			_mbstr_copy_char(dest, spec->sep, n_sep);
		}

		if (*g && *(g+1)) g++;
		consume = *g;
	}

	if (sign) {
		_mbstr_copy_ascii(dest, sign, 1);
	}

	if (dest->data) {
		dest->data[dest->nbytes] = '\0';
	}
}

/* Change decstring to locale-specific appearance. */
static void
_mpd_apply_lconv(mpd_mbstr_t *result, char *decstring, mpd_spec_t *spec,
                 uint32_t *status)
{
	const char *sign = NULL, *intpart = NULL;
	const char *dot = NULL, *rest = NULL;
	const char *dp;
	mpd_ssize_t n_int;

	assert(result->data == NULL);

	dp = decstring;
	n_int = 0;

	if (!isdigit((uchar)*dp)) {
		sign = dp++;
	}
	if (isdigit((uchar)*dp)) {
		intpart = dp++;
		while (isdigit((uchar)*dp)) {
			dp++;
		}
		n_int = (mpd_ssize_t)(dp-intpart);
	}
	if (*dp == '.') {
		if (*spec->dot == '\0') {
		        /* decimal point must be present */
			*status |= MPD_Invalid_operation; /* GCOV_NOT_REACHED */
			__mingw_dfp_get_globals()->mpd_free(decstring); /* GCOV_NOT_REACHED */
			return; /* GCOV_NOT_REACHED */
		}
		dp++; dot = spec->dot;
	}
	rest = dp;


	if (!dot && !(intpart && *spec->sep && *spec->grouping)) {
		result->data = decstring;
		result->nbytes = result->nchars = (mpd_ssize_t)strlen(decstring);
		return;
	}

	/* Get the size of the new decimal string after inserting dot and
	 * separators. */
	_mpd_add_sep_dot(result, intpart, n_int, sign, dot, rest, spec);

	if ((result->data = mpd_alloc(result->nbytes+1, 1)) == NULL) {
		*status |= MPD_Malloc_error;
		__mingw_dfp_get_globals()->mpd_free(decstring);
		return;
	}

	/* Perform actual writes. */
	_mpd_add_sep_dot(result, intpart, n_int, sign, dot, rest, spec);

	__mingw_dfp_get_globals()->mpd_free(decstring);
}

/* Add padding to the formatted string if necessary. */
static void
_mpd_add_pad(mpd_mbstr_t *result, mpd_spec_t *spec, uint32_t *status)
{
	if (result->nchars < spec->min_width) {
		mpd_ssize_t add_chars, add_bytes;
		size_t lpad = 0, rpad = 0;
		size_t n_fill, len, i, j;
		uint8_t err = 0;
		char *cp;

		n_fill = strlen(spec->fill);
		add_chars = (spec->min_width - result->nchars);
		/* max value: MPD_MAX_PREC * 4 */
		add_bytes = add_chars * (mpd_ssize_t)n_fill;

		cp = result->data = mpd_realloc(result->data,
		                                result->nbytes+add_bytes+1,
		                                sizeof *result->data, &err);
		if (err) {
			*status |= MPD_Malloc_error;
			__mingw_dfp_get_globals()->mpd_free(result->data);
			result->data = NULL;
			return;
		}

		if (spec->align == 'z') {
			spec->align = '=';
		}

		if (spec->align == '<') {
			rpad = add_chars;
		}
		else if (spec->align == '>' || spec->align == '=') {
			lpad = add_chars;
		}
		else { /* align == '^' */
			lpad = add_chars/2;
			rpad = add_chars-lpad;
		}

		len = result->nbytes;
		if (spec->align == '=' && (*cp == '-' || *cp == '+' ||
		                           *cp == ' ')) {
			/* leave sign in the leading position */
			cp++; len--;
		}

		memmove(cp+n_fill*lpad, cp, len);
		for (i = 0; i < lpad; i++) {
			for (j = 0; j < n_fill; j++) {
				cp[i*n_fill+j] = spec->fill[j];
			}
		}
		cp += (n_fill*lpad + len);
		for (i = 0; i < rpad; i++) {
			for (j = 0; j < n_fill; j++) {
				cp[i*n_fill+j] = spec->fill[j];
			}
		}

		result->nbytes += add_bytes;
		result->nchars += add_chars;
		result->data[result->nbytes] = '\0';
	}
}

/*
 * Return the string representation of an mpd_t, formatted according to 'spec'.
 * 'spec' is modified. The format specification is assumed to be valid. Memory
 * errors are indicated as usual. This function is quiet.
 */
char *
mpd_qformat_spec(const mpd_t *dec, mpd_spec_t *spec, const mpd_context_t *ctx,
                 uint32_t *status)
{
	mpd_context_t workctx;
	mpd_uint_t dt[MPD_MINALLOC_MAX];
	mpd_t tmp = {MPD_STATIC|MPD_STATIC_DATA,0,0,0,MPD_MINALLOC_MAX,dt};
	mpd_ssize_t prec, fracdigits, exp;
	mpd_ssize_t zeroexp = MPD_SSIZE_MAX;
	mpd_mbstr_t result;
	char *decstring;
	int flags = 0;


	if (spec->min_width > MPD_MAX_PREC) {
		*status |= MPD_Invalid_operation;
		return NULL;
	}

	if (!mpd_qcopy(&tmp, dec, status)) {
		return NULL;
	}

	if (spec->type == '%') {
		tmp.exp += 2;
		spec->type = 'f';
		flags |= MPD_FMT_PERCENT;
	}

	if (isupper((uchar)spec->type)) {
		spec->type = tolower((uchar)spec->type);
		flags |= MPD_FMT_UPPER;
	}
	if (spec->sign == ' ') {
		flags |= MPD_FMT_SIGN_SPACE;
	}
	else if (spec->sign == '+') {
		flags |= MPD_FMT_SIGN_PLUS;
	}

	mpd_maxcontext_plus(&workctx, ctx);
	workctx.round = ctx->round;
	if (mpd_isspecial(&tmp)) {
		/* no percent formatting */
		flags |= MPD_FMT_TOSCI;
		if (spec->align == 'z') {
			spec->fill[0] = ' ';
			spec->fill[1] = '\0';
			spec->align = '>';
		}
	}
	else if (spec->type == 'g') {
		/* spec->prec: significant digits */
		prec = (spec->prec < 0) ? dec->digits : spec->prec;
		workctx.prec = (prec == 0) ? 1 : prec;
		flags |= MPD_FMT_TOSCI;
		mpd_qfinalize(&tmp, &workctx, &workctx.status);
	}
	else {
		/* spec->prec: fraction digits */
		if (spec->type == 'e') {
			fracdigits = (spec->prec < 0) ? tmp.digits-1 : spec->prec;
			if (mpd_iszero(&tmp)) {
				zeroexp = tmp.exp+fracdigits;
				exp = -fracdigits;
				flags |= MPD_FMT_FIXED;
			}
			else {
				exp = tmp.exp + tmp.digits-(fracdigits+1);
				flags |= MPD_FMT_EXP;
			}
		}
		else { /* 'f' */
			fracdigits = spec->prec;
			if (fracdigits < 0) {
				fracdigits = (tmp.exp < 0) ? -tmp.exp : 0;
			}
			exp = -fracdigits;
			fracdigits += (tmp.exp+tmp.digits);
			fracdigits = (fracdigits < 0) ? 0 : fracdigits;
			flags |= MPD_FMT_FIXED;
		}
		workctx.prec = fracdigits+1;
		mpd_qrescale(&tmp, &tmp, exp, &workctx, &workctx.status);
		if (tmp.digits > workctx.prec) {
			mpd_qfinalize(&tmp, &workctx, &workctx.status);
		}
	}

	if ((decstring = _mpd_to_string(&tmp, flags, zeroexp)) == NULL) {
		*status |= MPD_Malloc_error;
		mpd_del(&tmp);
		return NULL;
	}

	result.data = decstring;
	result.nbytes = result.nchars = 0;
	if (!mpd_isspecial(&tmp) && *spec->dot != '\0') {
		result.data = NULL;
		_mpd_apply_lconv(&result, decstring, spec, status);
		if (result.data == NULL) {
			goto finish;
		}
	}

	if (spec->min_width) {
		if (result.nbytes == 0) {
			result.nbytes = result.nchars =
			        (mpd_ssize_t)strlen(result.data);
		}
		_mpd_add_pad(&result, spec, status);
	}


finish:
	mpd_del(&tmp);
	return result.data;
}

char *
mpd_qformat(const mpd_t *dec, const char *fmt, const mpd_context_t *ctx,
            uint32_t *status)
{
	mpd_spec_t spec;

	if (!mpd_parse_fmt_str(&spec, fmt, 1)) {
		*status |= MPD_Invalid_operation;
		return NULL;
	}

	return mpd_qformat_spec(dec, &spec, ctx, status);
}

/*
 * The specification has a *condition* called Invalid_operation and an
 * IEEE *signal* called Invalid_operation. The former corresponds to
 * MPD_Invalid_operation, the latter to MPD_IEEE_Invalid_operation.
 * MPD_IEEE_Invalid_operation comprises the following conditions:
 *
 * [MPD_Conversion_syntax, MPD_Division_impossible, MPD_Division_undefined,
 *  MPD_Fpu_error, MPD_Invalid_context, MPD_Invalid_operation,
 *  MPD_Malloc_error]
 *
 * In the following functions, 'flag' denotes the condition, 'signal'
 * denotes the IEEE signal.
 */

static const char *mpd_flag_string[MPD_NUM_FLAGS] = {
	"Clamped",
	"Conversion_syntax",
	"Division_by_zero",
	"Division_impossible",
	"Division_undefined",
	"Fpu_error",
	"Inexact",
	"Invalid_context",
	"Invalid_operation",
	"Malloc_error",
	"Not_implemented",
	"Overflow",
	"Rounded",
	"Subnormal",
	"Underflow",
};

static const char *mpd_signal_string[MPD_NUM_FLAGS] = {
	"Clamped",
	"IEEE_Invalid_operation",
	"Division_by_zero",
	"IEEE_Invalid_operation",
	"IEEE_Invalid_operation",
	"IEEE_Invalid_operation",
	"Inexact",
	"IEEE_Invalid_operation",
	"IEEE_Invalid_operation",
	"IEEE_Invalid_operation",
	"Not_implemented",
	"Overflow",
	"Rounded",
	"Subnormal",
	"Underflow",
};

/* print conditions to buffer, separated by spaces */
int
mpd_snprint_flags(char *dest, int nmemb, uint32_t flags)
{
	char *cp;
	int n, j;

	assert(nmemb >= MPD_MAX_FLAG_STRING);

	*dest = '\0'; cp = dest;
	for (j = 0; j < MPD_NUM_FLAGS; j++) {
		if (flags & (1U<<j)) {
			n = snprintf(cp, nmemb, "%s ", mpd_flag_string[j]);
			if (n < 0 || n >= nmemb) return -1;
			cp += n; nmemb -= n;
		}
	}

	if (cp != dest) {
		*(--cp) = '\0';
	}

	return (int)(cp-dest);
}

/* print conditions to buffer, in list form */
int
mpd_lsnprint_flags(char *dest, int nmemb, uint32_t flags, const char *flag_string[])
{
	char *cp;
	int n, j;

	assert(nmemb >= MPD_MAX_FLAG_LIST);
	if (flag_string == NULL) {
		flag_string = mpd_flag_string;
	}

	*dest = '[';
	*(dest+1) = '\0';
	cp = dest+1;
	--nmemb;

	for (j = 0; j < MPD_NUM_FLAGS; j++) {
		if (flags & (1U<<j)) {
			n = snprintf(cp, nmemb, "%s, ", flag_string[j]);
			if (n < 0 || n >= nmemb) return -1;
			cp += n; nmemb -= n;
		}
	}

	/* erase the last ", " */
	if (cp != dest+1) {
		cp -= 2;
	}

	*cp++ = ']';
	*cp = '\0';

	return (int)(cp-dest); /* strlen, without NUL terminator */
}

/* print signals to buffer, in list form */
int
mpd_lsnprint_signals(char *dest, int nmemb, uint32_t flags, const char *signal_string[])
{
	char *cp;
	int n, j;
	int ieee_invalid_done = 0;

	assert(nmemb >= MPD_MAX_SIGNAL_LIST);
	if (signal_string == NULL) {
		signal_string = mpd_signal_string;
	}

	*dest = '[';
	*(dest+1) = '\0';
	cp = dest+1;
	--nmemb;

	for (j = 0; j < MPD_NUM_FLAGS; j++) {
		uint32_t f = flags & (1U<<j);
		if (f) {
			if (f&MPD_IEEE_Invalid_operation) {
				if (ieee_invalid_done) {
					continue;
				}
				ieee_invalid_done = 1;
			}
			n = snprintf(cp, nmemb, "%s, ", signal_string[j]);
			if (n < 0 || n >= nmemb) return -1;
			cp += n; nmemb -= n;
		}
	}

	/* erase the last ", " */
	if (cp != dest+1) {
		cp -= 2;
	}

	*cp++ = ']';
	*cp = '\0';

	return (int)(cp-dest); /* strlen, without NUL terminator */
}

/* The following two functions are mainly intended for debugging. */
void
mpd_fprint(FILE *file, const mpd_t *dec)
{
	char *decstring;

	decstring = mpd_to_sci(dec, 1);
	if (decstring != NULL) {
		fprintf(file, "%s\n", decstring);
		__mingw_dfp_get_globals()->mpd_free(decstring);
	}
	else {
		fputs("mpd_fprint: output error\n", file); /* GCOV_NOT_REACHED */
	}
}

void
mpd_print(const mpd_t *dec)
{
	char *decstring;

	decstring = mpd_to_sci(dec, 1);
	if (decstring != NULL) {
		printf("%s\n", decstring);
		__mingw_dfp_get_globals()->mpd_free(decstring);
	}
	else {
		fputs("mpd_fprint: output error\n", stderr); /* GCOV_NOT_REACHED */
	}
}


