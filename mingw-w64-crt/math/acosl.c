/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
long double acosl (long double x)
{
  long double res;

  /* acosl = atanl (sqrtl(1 - x^2) / x) */
  asm (	"fld	%%st\n\t"
	"fmul	%%st(0)\n\t"		/* x^2 */
	"fld1\n\t"
	"fsubp\n\t"			/* 1 - x^2 */
	"fsqrt\n\t"			/* sqrtl (1 - x^2) */
	"fxch	%%st(1)\n\t"
	"fpatan"
	: "=t" (res) : "0" (x) : "st(1)");
  return res;
}
