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

int main (void) {
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
   * NOTE: code page 28591 is ISO-8859-1
   */
  assert (setlocale (LC_ALL, "English_United States.28591") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All values in range [0,255] are valid and must convert to themselves
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
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
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.ACP") != NULL);
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
