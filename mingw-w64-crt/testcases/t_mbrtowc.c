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
  wchar_t   wc = WEOF;

  /**
   * Test "C" locale
   */
  assert (setlocale (LC_ALL, "C") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All bytes in range [0,255] are valid and must convert to themselves
   */
  for (unsigned char c = 0;; ++c) {
    assert (mbrtowc (&wc, (char *) &c, MB_CUR_MAX, &state) == !!c);
    assert (wc == c);
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
   * This check fails with CRT's mbrtowc.
   */
  state = Ascii[0];
  wc = WEOF;

  assert (mbrtowc (&wc, (char *) &Ascii, MB_CUR_MAX, &state) == (size_t) -1);
  assert (wc == WEOF);
  assert (!mbsinit (&state));
  assert (errno == EINVAL);

  // reset errno
  _set_errno (0);

  /**
   * Set conversion state to initial state
   */
  wc = WEOF;

  assert (mbrtowc (&wc, NULL, 0, &state) == 0);
  assert (wc == WEOF);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Test SBCS code page
   * NOTE: Code page 28951 is ISO-8859-1
   */
  assert (setlocale (LC_ALL, "English_United States.28591") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All bytes must be valid
   *
   * We test ISO-8859-1 so that all bytes must convert to themselves
   */
  for (unsigned char c = 0;; ++c) {
    wc = WEOF;

    assert (mbrtowc (&wc, (char *) &c, MB_CUR_MAX, &state) == !!c);
    assert (wc == c);
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
    wc = WEOF;

    assert (mbrtowc (&wc, &c, 1, &state) == !!c);
    assert (wc == c);
    assert (mbsinit (&state));
    assert (errno == 0);

    if (c == 0x7F) {
      break;
    }
  }

  /**
   * Try convert incomplete multibyte character
   */
  wc = WEOF;

  assert (mbrtowc (&wc, (char *) Multibyte, 1, &state) == (size_t) -2);
  /* This assertion fails with CRT's version */
  assert (wc == WEOF);
  assert (!mbsinit (&state));
  assert (errno == 0);

  /**
   * Complete multibyte character
   *
   * NOTE: return value does not conform to ISO C and POSIX.
   * This behavior is implemented for consistency with CRT.
   */
  wc = WEOF;

  assert (mbrtowc (&wc, (char *) Multibyte + 1, 1, &state) == 2);
  assert (wc != WEOF);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert complete multibyte character
   */
  wc = WEOF;

  assert (mbrtowc (&wc, (char *) Multibyte, MB_CUR_MAX, &state) == 2);
  assert (wc != WEOF);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Try convert invalid multibyte character
   */
  wc = WEOF;

  assert (mbrtowc (&wc, (char *) InvalidMultibyte, MB_CUR_MAX, &state) == (size_t) -1);
  /* This assertion fails with CRT's version */
  assert (wc == WEOF);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  return 0;
}
