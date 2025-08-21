#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/* ASCII text */
char          AsciiText[] = "Simple English string.";
/* SBCS text (code page 1252) */
unsigned char SBCSText[] = {'a', 'A', 0xC0, 0xE0, 'e', 'E', 0xC8, 0xE8, 0xCB, 0xEB, 0x0};
/* DBCS text (code page 932) */
unsigned char DBCSText[] = {0x93, 0xFA, 0x96, 0x7B, 0x8C, 0xEA, 0x83, 0x65, 0x83, 0x4E, 0x83, 0x58, 0x83, 0x67, 0x0};
/* Mix of single-byte and double-byte characters */
unsigned char MixedText[] = {0x93, 0xFA, 'n', 'i', 0x96, 0x7B, 'h', 'o', 'n', 0x8C, 0xEA, 'g', 'o', 0x0};
/* DBCS text with truncated multibyte character */
unsigned char BadText[] = {0x93, 0xFA, 0x96, 0x7B, 0x8C, 0x0};

int main (void) {
#ifdef _UCRT
  return 77;
#endif
  mbstate_t state = {0};
  wchar_t   buffer[BUFSIZ];

  const char *original_text = NULL;
  const char *text = NULL;
  size_t      text_length = 0;

  /**
   * Test "C" locale
   */
  assert (setlocale (LC_ALL, "C") != NULL);
  assert (MB_CUR_MAX == 1);

  /* Test ASCII input */

  original_text = AsciiText;
  text_length = sizeof AsciiText - 1;

  /**
   * Get length of converted AsciiString
   *
   * - return value must be `text_length`
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must not change
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert AsciiString
   *
   * - return value must be `text_length`
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == L'\0');

  /**
   * Convert 10 characters of AsciiString
   *
   * - return value must be 10
   * - value of `text` must be `original_text + 10`
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must not be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, 10, &state) == 10);
  assert (text == original_text + 10);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == WEOF);

  /* Test SBCS input */

  original_text = (char *) SBCSText;
  text_length = sizeof SBCSText - 1;

  /**
   * Get length of converted SBCSText
   *
   * - return value must be `text_length`
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must not change
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert SBCSText
   *
   * - return value must be `text_length`
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == L'\0');

  /**
   * Test SBCS code page
   */
  assert (setlocale (LC_ALL, "English_United States.ACP") != NULL);
  assert (MB_CUR_MAX == 1);

  /* Test SBCS input */

  original_text = (char *) SBCSText;
  text_length = sizeof SBCSText - 1;

  /**
   * Get length of converted SBCSText
   *
   * - return value must be length of `text_length`
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must not change
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == text_length);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert SBCSText
   *
   * - return value must be `text_length`
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == L'\0');

  /**
   * Convert 8 characters in SBCSText
   *
   * - return value must be 8
   * - value of `text` must be `original_text + 8`
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must not be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, 8, &state) == 8);
  assert (text == original_text + 8);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[8] == WEOF);

  /**
   * Test DBCS code page
   */
  assert (setlocale (LC_ALL, "Japanese_Japan.ACP") != NULL);
  assert (MB_CUR_MAX == 2);

  /* Test ASCII input */

  original_text = AsciiText;
  text_length = sizeof AsciiText - 1;

  /**
   * Convert AsciiString
   *
   * - return value must be `text_length`
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == text_length);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[text_length] == L'\0');

  /* Test DBCS input */

  original_text = (char *) DBCSText;
  text_length = sizeof DBCSText - 1;

  /**
   * Get length of converted DBCSText
   *
   * - return value must be 7
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must not change
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == 7);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Convert 3 multibyte characters in DBCSText
   *
   * - return value must be 3
   * - value of `text` must point to `original_text + 6`
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must not be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, 3, &state) == 3);
  assert (text == original_text + 6);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[0] != WEOF && buffer[1] != WEOF && buffer[2] != WEOF && buffer[3] == WEOF);

  /**
   * Convert DBCSText
   *
   * - return value must be 7
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == 7);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[7] == L'\0');

  /* Test mixed input */

  original_text = (char *) MixedText;

  /**
   * Get length of converted MixedText
   *
   * - return value must be 10
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must not change
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == 10);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == 0);

  /**
   * Converted MixedText
   *
   * - return value must be 10
   * - value of `text` must be NULL
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == 10);
  assert (text == NULL);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[10] == L'\0');

  /**
   * Converted 7 multibyte characters in MixedText
   *
   * - return value must be 7
   * - value of `text` must be `original_text + 9`
   * - `state` must be in the initial state
   * - value of `errno` must not change
   * - converted string must not be terminated with '\0'
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, 7, &state) == 7);
  assert (text == original_text + 9);
  assert (mbsinit (&state));
  assert (errno == 0);
  assert (buffer[7] == WEOF);

  /* Test bad DBCS input */

  original_text = (char *) BadText;

  /**
   * Try get length of converted BadText
   *
   * - return value must be (size_t)-1
   * - value of `text` must not change
   * - `state` must be in the initial state
   * - value of `errno` must be EILSEQ
   */
  text = original_text;

  assert (mbsrtowcs (NULL, &text, 0, &state) == (size_t) -1);
  assert (text == original_text);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);

  // reset errno
  _set_errno (0);

  /**
   * Try convert BadText
   *
   * - return value must be (size_t)-1
   * - value of `text` must be `original_text + 4`
   * - `state` must be in the initial state
   * - value of `errno` must be EILSEQ
   */
  wmemset (buffer, WEOF, BUFSIZ);
  text = original_text;

  assert (mbsrtowcs (buffer, &text, BUFSIZ, &state) == (size_t) -1);
  assert (text == original_text + 4);
  assert (mbsinit (&state));
  assert (errno == EILSEQ);
  /* This assertion fails with CRT's version */
  assert (buffer[0] != WEOF && buffer[1] != WEOF && buffer[2] == WEOF);

  return 0;
}
