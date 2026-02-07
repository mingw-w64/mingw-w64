/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <assert.h>
#include <locale.h>
#include <wctype.h>

/**
 * Test Summary:
 *
 * Verify that `towctrans` is consistent with mapping-specific wctype.h
 * functions.
 *
 * `towctrans (wc, wctrans ("tolower"))` must be equivalent to `towlower (wc)`.
 * `towctrans (wc, wctrans ("toupper"))` must be equivalent to `towupper (wc)`.
 *
 * POSIX requires that if second argument to `towctrans` is `(wctrans_t)0`,
 * then `wc` is returned unchanged.
 */

int main (void) {
  if (setlocale (LC_ALL, "English_United States") == NULL) {
    return 77;
  }

  wctrans_t lower = 0;
  wctrans_t upper = 0;

  assert ((lower = wctrans ("tolower")) != (wctrans_t) 0);
  assert ((upper = wctrans ("toupper")) != (wctrans_t) 0);

  for (wint_t wc = 0;; ++wc) {
    assert (towctrans (wc, (wctrans_t) 0) == wc);
    assert (towlower (wc) == towctrans (wc, lower));
    assert (towupper (wc) == towctrans (wc, upper));

    if (wc == WEOF) {
      break;
    }
  }

  return 0;
}
