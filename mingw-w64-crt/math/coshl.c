/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include "cephes_mconf.h"

#ifndef _SET_ERRNO
#define _SET_ERRNO(x)
#endif

long double coshl(long double x)
{
	long double y;

#ifdef NANS
	if (isnanl(x))
	{
		_SET_ERRNO(EDOM);
		return (x);
  	}
#endif
	if (x < 0)
		x = -x;
	if (x > (MAXLOGL + LOGE2L))
	{
		mtherr( "coshl", OVERFLOW );
		_SET_ERRNO(ERANGE);
#ifdef INFINITIES
		return (INFINITYL);
#else
		return (MAXNUML);
#endif
	}
	if (x >= (MAXLOGL - LOGE2L))
	{
		y = expl(0.5L * x);
		y = (0.5L * y) * y;
		return (y);
	}
	y = expl(x);
	y = 0.5L * (y + 1.0L / y);
	return (y);
}
