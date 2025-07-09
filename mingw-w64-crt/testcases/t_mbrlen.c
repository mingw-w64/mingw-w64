#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

char Ascii[] = {'a'};
char NonAscii[] = {(char) 0x80};
char Multibyte[] = {(char) 0x81, (char) 0x81};
char InvalidMultibyte[] = {(char) 0x81, 0};

int main (void) {
#if __MSVCRT_VERSION__ >= 0x0800
  return 77;
#endif
  mbstate_t state = {0};

  /**
   * Test "C" locale
   */
  assert (setlocale (LC_ALL, "C") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All bytes in range [0,255] are valid
   */
  for (unsigned char c = 0;; ++c) {
    assert (mbrlen ((char *) &c, MB_CUR_MAX, &state) == !!c);
    assert (mbsinit (&state));
    assert (errno == 0);

    if (c == 0xFF) {
      break;
    }
  }

  /**
   * Detect invalid conversion state
   *
   * NOTE: this is optional error condition specified in POSIX.
   * This check fails with CRT's mbrlen.
   */
  state = Ascii[0];

  assert (mbrlen ((char *) &Ascii, MB_CUR_MAX, &state) == (size_t) -1);
  assert (!mbsinit (&state));
  assert (errno == EINVAL);

  // reset errno
  _set_errno (0);

  /**
   * Set conversion state to initial state
   */

  assert (mbrlen (NULL, 0, &state) == 0);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Test SBCS code page
   */
  assert (setlocale (LC_ALL, "English_United States.ACP") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All bytes must be valid
   */
  for (unsigned char c = 0;; ++c) {
    assert (mbrlen ((char *) &c, MB_CUR_MAX, &state) == !!c);
    assert (mbsinit (&state));
    assert (errno == 0);

    if (c == 0xFF) {
      break;
    }
  }

  /**
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.ACP") != NULL);
  assert (MB_CUR_MAX == 2);

  /**
   * Make sure ASCII characters are handled correctly
   */
  for (char c = 0;; ++c) {
    assert (mbrlen (&c, 1, &state) == !!c);
    assert (mbsinit (&state));
    assert (errno == 0);

    if (c == 0x7F) {
      break;
    }
  }

  /**
   * Try convert incomplete multibyte character
   */

  assert (mbrlen ((char *) Multibyte, 1, &state) == (size_t) -2);
  assert (!mbsinit (&state));
  assert (errno == 0);

  /**
   * Complete multibyte character
   *
   * NOTE: return value does not conform to ISO C and POSIX.
   * This behavior is implemented for consistency with CRT.
   */

  assert (mbrlen ((char *) Multibyte + 1, 1, &state) == 2);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert multibyte character
   */

  assert (mbrlen ((char *) Multibyte, MB_CUR_MAX, &state) == 2);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Invalid multibyte character
   */

  assert (mbrlen ((char *) InvalidMultibyte, MB_CUR_MAX, &state) == (size_t) -1);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  return 0;
}
