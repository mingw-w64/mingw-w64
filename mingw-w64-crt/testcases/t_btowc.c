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

int main (void) {
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
  assert (setlocale (LC_ALL, "English_United States.ACP") != NULL);
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

  /**
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.ACP") != NULL);
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
    if (IsDBCSLeadByteEx (932, (BYTE) c)) {
      assert (btowc (c) == WEOF);
    }
  }

  return 0;
}
