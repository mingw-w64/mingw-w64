/*
    genstubdll - Generate stub-library acting like an import-library
                 using .def file syntax.
    Copyright (C) 2014-2016  mingw-w64 project

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

#define TK_EQUALEQUAL  256
#define TK_EQUAL '='
#define TK_AT  '@'
#define TK_COLON ','
#define TK_DOT '.'
#define TK_NL '\n'
#define TK_STRING 257
#define TK_DIGIT 258
#define TK_UNKNOWN 259
#define TK_NAME 260
#define TK_LIBRARY 261
#define TK_EXPORTS 262

#define TK_DATA  0x200

typedef struct sSymbol {
  struct sSymbol *next;
  const char *sym;
  const char *libsym;
  const char *alias;
  int is_data;
  struct sSymbol *subs;
} sSymbol;

extern sSymbol *t_sym;
extern const char *cur_libname;

const char *unifyStr (const char *);
const char *unifyCat (const char *, const char *);

void addSymbol (const char *sym, const char *libsym, const char *alias, int is_data);
void sortSymbols (void);
void dumpSymbols (void);
void outputSyms (void);
