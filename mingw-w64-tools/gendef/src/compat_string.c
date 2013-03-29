/*
    gendef - Generate list of exported symbols from a Portable Executable.
    Copyright (C) 2009, 2010, 2011, 2012, 2013  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
