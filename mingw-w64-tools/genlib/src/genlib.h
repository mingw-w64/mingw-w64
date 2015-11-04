/*
    genlib - Generate a COFF lib from a list of exported symbols.
    Copyright (c) 2015 Martell Malone

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
#ifndef _GENLIB_HXX
#define _GENLIB_HXX

#define ENABLE_DEBUG 0

#if ENABLE_DEBUG == 1
#define PRDEBUG(ARG...)  fprintf(stderr,ARG)
#else
#define PRDEBUG(ARG...) do { } while(0)
#endif

typedef struct genlibopts
{
  char *fninput;
  char *fnoutput;
  struct genlibopts *next;
} Genlibopts;

#endif