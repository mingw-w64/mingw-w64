#ifdef CONFIG_H
#include <config.h>
#endif

#ifndef HAVE_STRLWER

#include <ctype.h>
#include "compat_string.h"

char *strlwr(char *s) {
	while(*s != '\x0') {
		*s = tolower(*s);
		s++;
	}

	return s;
}

#endif /* HAVE_STRLWER */
