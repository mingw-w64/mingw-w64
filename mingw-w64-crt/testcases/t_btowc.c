#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <errno.h>
#include <limits.h>
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
   * All bytes in range [0,255] are valid and must convert to themselves
   */
  for (int c = 0; c < 0x100; ++c) {
    assert (btowc (c) == c);
  }

  /**
   * Try convert sign-extended input
   */
  for (char c = CHAR_MIN; c < 0; ++c) {
    assert (btowc (c) == (c == EOF ? WEOF : (BYTE) c));
  }

  /**
   * Test SBCS code page
   */
  if (setlocale (LC_ALL, ".1252") == NULL) {
    wprintf (L"Skipping tests for SBCS code page 1252\n");
    goto skip_sbcs;
  }

  assert (MB_CUR_MAX == 1);

  /**
   * All bytes in range [0,127] are valid and must convert to themselves
   */
  for (int c = 0; c < 0x80; ++c) {
    assert (btowc (c) == c);
  }

  /**
   * All bytes in range [0,255] are valid
   */
  for (int c = 0x80; c < 0x100; ++c) {
    assert (btowc (c) != WEOF);
  }

skip_sbcs:
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
  if (setlocale (LC_ALL, ".932") == NULL) {
    wprintf (L"Skipping tests for DBCS code page 932\n");
    goto skip_dbcs;
  }

  assert (MB_CUR_MAX == 2);

  /**
   * All bytes in range [0,127] are valid and must convert to themselves
   */
  for (int c = 0; c < 0x80; ++c) {
    assert (btowc (c) == c);
  }

  /**
   * Try to convert lead bytes
   */
  for (int c = 0x80; c < 0x100; ++c) {
    if (__mingw_isleadbyte_cp ((BYTE) c, 932)) {
      assert (btowc (c) == WEOF);
    }
  }

skip_dbcs:
#endif
#ifdef _UCRT
  /**
   * Test UTF-8
   */
  if (setlocale (LC_ALL, ".UTF-8") != NULL) {
    assert (MB_CUR_MAX == 4);

    /**
     * All bytes in range [0,127] are valid and must convert to themselves
     */
    for (int c = 0; c < 0x80; ++c) {
      assert (btowc (c) == c);
    }

    /**
     * All bytes in range [128,255] are invalid
     */
    for (int c = 0x80; c < 0x100; ++c) {
      assert (btowc (c) == WEOF);
    }
  }
#endif

  return 0;
}
