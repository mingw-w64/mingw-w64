/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CTYPE_DISABLE_MACROS
#include <assert.h>
#include <locale.h>
#include <wctype.h>

/**
 * Verify that `iswctype` is consistent with class-specific wctype.h functions.
 *
 * Example:
 *
 * `iswctype (wc, wctype ("print"))` must be equivalent to `iswprint (wc)`.
 *
 * This requirement applies to all character classes defined by POSIX.
 */

int main (void) {
  if (setlocale (LC_ALL, "English_United States") == NULL) {
    return 77;
  }

  wctype_t alnum  = (wctype_t) 0;
  wctype_t alpha  = (wctype_t) 0;
  wctype_t blank  = (wctype_t) 0;
  wctype_t cntrl  = (wctype_t) 0;
  wctype_t digit  = (wctype_t) 0;
  wctype_t graph  = (wctype_t) 0;
  wctype_t lower  = (wctype_t) 0;
  wctype_t print  = (wctype_t) 0;
  wctype_t punct  = (wctype_t) 0;
  wctype_t space  = (wctype_t) 0;
  wctype_t upper  = (wctype_t) 0;
  wctype_t xdigit = (wctype_t) 0;

  assert ((alnum = wctype ("alnum")) != (wctype_t) 0);
  assert ((alpha = wctype ("alpha")) != (wctype_t) 0);
  assert ((blank = wctype ("blank")) != (wctype_t) 0);
  assert ((cntrl = wctype ("cntrl")) != (wctype_t) 0);
  assert ((digit = wctype ("digit")) != (wctype_t) 0);
  assert ((graph = wctype ("graph")) != (wctype_t) 0);
  assert ((lower = wctype ("lower")) != (wctype_t) 0);
  assert ((print = wctype ("print")) != (wctype_t) 0);
  assert ((punct = wctype ("punct")) != (wctype_t) 0);
  assert ((space = wctype ("space")) != (wctype_t) 0);
  assert ((upper = wctype ("upper")) != (wctype_t) 0);
  assert ((xdigit = wctype ("xdigit")) != (wctype_t) 0);

  for (wchar_t wc = 0;; ++wc) {
    assert (iswalnum (wc) == iswctype (wc, alnum));
    assert (iswalpha (wc) == iswctype (wc, alpha));
    assert (iswblank (wc) == iswctype (wc, blank));
    assert (iswcntrl (wc) == iswctype (wc, cntrl));
    assert (iswdigit (wc) == iswctype (wc, digit));
    assert (iswgraph (wc) == iswctype (wc, graph));
    assert (iswlower (wc) == iswctype (wc, lower));
    assert (iswprint (wc) == iswctype (wc, print));
    assert (iswpunct (wc) == iswctype (wc, punct));
    assert (iswspace (wc) == iswctype (wc, space));
    assert (iswupper (wc) == iswctype (wc, upper));
    assert (iswxdigit (wc) == iswctype (wc, xdigit));

    if (wc == WEOF) {
      break;
    }
  }

  return 0;
}
