/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <locale.h>
#include <string.h>
#include <stdlib.h>

static inline
unsigned int get_cp_from_locale (void)
{
  char* cp_string;
  /*
    locale :: "lang[_country[.code_page]]" 
               | ".code_page"

  */

  if ((cp_string = strchr(setlocale(LC_CTYPE, NULL), '.')))
    return  ((unsigned) atoi (cp_string + 1));
  return 0;
}
