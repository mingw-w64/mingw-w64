#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

int main (void) {
  mingw_test_init ();

  /**
   * Test "C" locale
   */
  assert (setlocale (LC_ALL, "C") != NULL);

  /**
   * All values in range [0,255] are valid and must convert to themselves
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
    assert (wctob (wc) == wc);
  }

  /**
   * All values in range [256,WEOF] are invalid
   */
  for (wchar_t wc = 0x100;; ++wc) {
    assert (wctob (wc) == EOF);
    if (wc == WEOF) {
      break;
    }
  }

  /**
   * Test SBCS code page
   */
  assert (setlocale (LC_ALL, "English_United States.1252") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All values in range [0,127] are valid ASCII characters
   */
  for (wchar_t wc = 0; wc < 0x80; ++wc) {
    assert (wctob (wc) == wc);
  }

  /**
   * All values in range [128,159] are valid characters
   */
  for (wchar_t wc = 0x80; wc < 0xA0; ++wc) {
    int c = wctob (wc);

    if (wc == 0x81 || wc == 0x8D || wc == 0x8F || wc == 0x90 || wc == 0x9D) {
      assert ((unsigned char) c == wc);
    } else {
      assert (c == EOF || (unsigned char) c != wc);
    }
  }

  /**
   * All values in range [160,255] are valid and must convert to themselves
   */
  for (wchar_t wc = 0xA0; wc < 0x100; ++wc) {
    assert (wctob (wc) == wc);
  }

  /**
   * Try convert low and high surrogates
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
    if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc) || wc == WEOF) {
      assert (wctob (wc) == EOF);
    }

    if (wc == WEOF) {
      break;
    }
  }

  /**
   * Disable tests for DBCS code pages with msvcrt10.dll since it does not
   * support multibyte characters.
   *
   * Calling setlocale with locale string which requests DBCS code page
   * result in runtime error.
   */
#if __MSVCRT_VERSION__ != 0x0100
  /**
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.932") != NULL);
  assert (MB_CUR_MAX == 2);

  /**
   * All values in range [0,127] are valid and must convert to themselves
   */
  for (wchar_t wc = 0; wc < 0x80; ++wc) {
    assert (wctob (wc) == wc);
  }

  /**
   * Try convert multibyte characters
   */
  wchar_t DBCS[] = {L'日', L'本', L'語', L'。'};

  for (size_t i = 0; i < _countof (DBCS); ++i) {
    assert (wctob (DBCS[i]) == EOF);
  }

  /**
   * Try convert low and high surrogates
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
    if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc) || wc == WEOF) {
      assert (wctob (wc) == EOF);
    }

    if (wc == WEOF) {
      break;
    }
  }
#endif
#ifdef _UCRT
  /**
   * Test UTF-8
   */
  if (setlocale (LC_ALL, ".UTF-8") != NULL) {
    assert (MB_CUR_MAX == 4);

    /**
     * All values in range [0,127] are valid and must convert to themselves
     */
    for (wchar_t wc = 0; wc < 0x80; ++wc) {
      assert (wctob (wc) == wc);
    }

    /**
     * All values in range [128,WEOF] are invalid
     */
    for (int wc = 0x80;; ++wc) {
      assert (wctob (wc) == EOF);
      if (wc == WEOF) {
        break;
      }
    }
  }
#endif

  return 0;
}
