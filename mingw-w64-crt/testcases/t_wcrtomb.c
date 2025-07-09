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
   * All values in range [0,255] are valid and must convert to themselves
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
    char c = EOF;

    assert (wcrtomb (&c, wc, &state) == 1);
    assert ((unsigned char) c == wc);
    assert (errno == 0);
    assert (mbsinit (&state));
  }

  /**
   * Detect invalid conversion state
   *
   * NOTE: this is optional error condition specified in POSIX.
   * This check fails with CRT's wcrtomb.
   */
  state = 1;

  if (1) {
    char c = EOF;

    assert (wcrtomb (&c, L'\0', &state) == (size_t) -1);
    assert (c == EOF);
    assert (errno == EINVAL);
    assert (!mbsinit (&state));

    // reset errno
    _set_errno (0);
  }

  /**
   * Set conversion state to initial state
   */

  assert (wcrtomb (NULL, WEOF, &state) == 1);
  assert (errno == 0);
  assert (mbsinit (&state));

  /**
   * Try convert character which cannot be repesented by a single byte
   */
  if (1) {
    char buffer = EOF;

    assert (wcrtomb (&buffer, L'語', &state) == (size_t) -1);
    assert (buffer == EOF);
    assert (errno == EILSEQ);
    assert (mbsinit (&state));

    // reset errno
    _set_errno (0);
  }

  /**
   * Try to convert low and high surrogates
   */
  for (wchar_t wc = 0;; ++wc) {
    if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc)) {
      char c = EOF;

      assert (wcrtomb (&c, wc, &state) == (size_t) -1);
      assert (c == EOF);
      assert (errno = EILSEQ);
      assert (mbsinit (&state));

      // reset errno
      _set_errno (0);
    }

    if (wc == WEOF) {
      break;
    }
  }

  /**
   * Test SBCS code page
   * NOTE: Code page 28951 is ISO-8859-1
   */
  assert (setlocale (LC_ALL, "English_United States.28591") != NULL);
  assert (MB_CUR_MAX == 1);

  /**
   * All values in range [0,255] must convert to themselves
   */
  for (wchar_t wc = 0; wc < 0x100; ++wc) {
    char c = EOF;

    assert (wcrtomb (&c, wc, &state) == 1);
    assert ((unsigned char) c == wc);
    assert (errno == 0);
    assert (mbsinit (&state));
  }

  /**
   * Try to convert low and high surrogates
   */
  for (wchar_t wc = 0;; ++wc) {
    if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc)) {
      char c = EOF;

      assert (wcrtomb (&c, wc, &state) == (size_t) -1);
      /* This assertion fails with CRT's version */
      assert (c == EOF);
      assert (errno = EILSEQ);
      assert (mbsinit (&state));

      // reset errno
      _set_errno (0);
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
   * All values in range [0,127] are valid ASCII characters
   */
  for (wchar_t wc = 0; wc < 0x80; ++wc) {
    char c = EOF;

    assert (wcrtomb (&c, wc, &state) == 1);
    assert ((unsigned char) c == wc);
    assert (errno == 0);
    assert (mbsinit (&state));
  }

  /**
   * Try convert multibyte characters
   */
  wchar_t DBCS[] = {L'日', L'本', L'語', L'。'};

  for (size_t i = 0; i < _countof (DBCS); ++i) {
    char buffer[2] = {0};

    assert (wcrtomb (buffer, DBCS[i], &state) == 2);
    assert (buffer[0] != 0 && buffer[1] != 0);
    assert (errno == 0);
    assert (mbsinit (&state));
  }

  /**
   * Try to convert low and high surrogates
   */
  for (wchar_t wc = 0;; ++wc) {
    if (IS_LOW_SURROGATE (wc) || IS_HIGH_SURROGATE (wc)) {
      char c = EOF;

      assert (wcrtomb (&c, wc, &state) == (size_t) -1);
      /* This assertion fails with CRT's version */
      assert (c == EOF);
      assert (errno = EILSEQ);
      assert (mbsinit (&state));

      // reset errno
      _set_errno (0);
    }

    if (wc == WEOF) {
      break;
    }
  }

  return 0;
}
