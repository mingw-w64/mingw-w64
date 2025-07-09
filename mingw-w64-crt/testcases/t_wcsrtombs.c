#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

wchar_t AsciiText[] = L"Simple English text.";
wchar_t SBCSText[] = L"Sömè fÛnnÿ têxt";
wchar_t DBCSText[] = L"日本語テクスト";
wchar_t MixedText[] = L"日NI本HON語GO";
wchar_t BadText[] = {L'テ', L'く', WEOF, L'ト'};

int main (void) {
#if __MSVCRT_VERSION__ >= 0x0800
  return 77;
#endif
  const wchar_t *original_text = NULL;
  const wchar_t *text = NULL;
  size_t         text_length = 0;

  char      buffer[BUFSIZ];
  mbstate_t state = {0};

  /**
   * Test "C" locale
   */
  assert (setlocale (LC_ALL, "C") != NULL);
  assert (MB_CUR_MAX == 1);

  /* Test ASCII input */

  original_text = AsciiText;
  text_length = _countof (AsciiText) - 1;

  /**
   * Get length of converted AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == '\0');

  /**
   * Convert 10 wide characters in AsciiText
   *
   * - return value must be 10
   * - value of `test` must be `original_text + 10`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test SBCS input */

  original_text = SBCSText;
  text_length = _countof (SBCSText) - 1;

  /**
   * Get length of converted SBCSText
   *
   * - return value must be 15
   * - value of `text` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert SBCSText
   *
   * - return value must be 15
   * - value of `text` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == '\0');

  /**
   * Convert 10 wide characters in SBCSText
   *
   * - return value must be 10
   * - value of `text` must be `original_text + 10`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test DBCS input */

  original_text = DBCSText;
  text_length = _countof (DBCSText) - 1;

  /**
   * Try get length of converted DBCSText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);
  assert (buffer[0] == EOF);

  // reset errno
  _set_errno (0);

  /**
   * Try convert DBCSText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  // reset errno
  _set_errno (0);

  /**
   * Test SBCS code page
   */
  assert (setlocale (LC_ALL, "English_United States.ACP") != NULL);
  assert (MB_CUR_MAX == 1);

  /* Test ASCII input */

  original_text = AsciiText;
  text_length = _countof (AsciiText) - 1;

  /**
   * Get length of converted AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == '\0');

  /**
   * Convert 10 wide characters in AsciiText
   *
   * - return value must be 10
   * - value of `test` must be `original_text + 10`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test SBCS input */

  original_text = SBCSText;
  text_length = _countof (SBCSText) - 1;

  /**
   * Get length of converted SBCSText
   *
   * - return value must be 15
   * - value of `text` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert SBCSText
   *
   * - return value must be 15
   * - value of `text` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == '\0');

  /**
   * Convert 10 wide characters in SBCSText
   *
   * - return value must be 10
   * - value of `text` must be `original_text + 10`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test DBCS input */

  original_text = DBCSText;
  text_length = _countof (DBCSText) - 1;

  /**
   * Try get length of converted DBCSText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  // reset errno
  _set_errno (0);

  /**
   * Try convert DBCSText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   * - nothing must be written to `buffer`
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);
  /* This assertion fails with CRT's version */
  assert (buffer[0] == EOF);

  // reset errno
  _set_errno (0);

  /**
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.ACP") != NULL);
  assert (MB_CUR_MAX == 2);

  /* Test ASCII input */

  original_text = AsciiText;
  text_length = _countof (AsciiText) - 1;

  /**
   * Get length of converted AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert AsciiText
   *
   * - return value must be `text_length`
   * - value of `test` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == '\0');

  /**
   * Convert 10 wide characters in AsciiText
   *
   * - return value must be 10
   * - value of `test` must be `original_text + 10`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test DBCS input */

  original_text = DBCSText;
  text_length = _countof (DBCSText) - 1;

  /**
   * Get length of converted DBCSText
   *
   * - return value must be 14
   * - value of `text` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == 14);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert DBCSText
   *
   * - return value must be 14
   * - value of `text` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == 14);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[14] == '\0');

  /**
   * Convert 5 wide characters in DBCSText
   *
   * - return value must be 10
   * - value of `text` must be `original_text + 5`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be terminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 11, &state) == 10);
  assert (text == original_text + 5);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == EOF);

  /* Test mixed input */

  original_text = MixedText;
  text_length = _countof (MixedText) - 1;

  /**
   * Get length of converted MixedText
   *
   * - return value must be 13
   * - value of `test` must not change
   * - value of `errno` must not change
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == 13);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert MixedText
   *
   * - return value must be 13
   * - value of `test` must be NULL
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must be teminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == 13);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[13] == '\0');

  /**
   * Convert 7 wide characters in MixedText
   *
   * - return value must be 9
   * - value of `test` must be `original_text + 7`
   * - value of `errno` must not change
   * - `state` must be in initial state
   * - converted string must not be teminated with '\0'
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, 10, &state) == 9);
  assert (text == original_text + 7);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[9] == EOF);

  /* Test bad input */

  original_text = BadText;
  text_length = _countof (BadText) - 1;

  /**
   * Try get length of converted BadText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   */
  text = original_text;

  assert (wcsrtombs (NULL, &text, 0, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  /**
   * Try convert BadText
   *
   * - return value must be (size_t)-1
   * - value of `text` must be `original_text + 2`
   * - value of `errno` must be EILSEQ
   * - `state` must be in initial state
   */
  memset (buffer, EOF, BUFSIZ);
  text = original_text;

  assert (wcsrtombs (buffer, &text, BUFSIZ, &state) == (size_t) -1);
  assert (text == original_text + 2);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);
  /* This assertion fails with CRT's version */
  assert (buffer[3] != EOF && buffer[4] == EOF);

  // reset errno
  _set_errno (0);

  return 0;
}
