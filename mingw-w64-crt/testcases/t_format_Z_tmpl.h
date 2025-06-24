#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <ntdef.h>

#define ARRAY_COUNT(a) (sizeof(a)/sizeof(a[0]))
#define DEF_STRING(str) { sizeof(str)-sizeof(str[0]), sizeof(str)-sizeof(str[0]), str }

#define PRINT_NARROW_BUF(buf) \
	for (i = 0; i < ARRAY_COUNT(buf); i++) { \
		if ((buf)[i] == '\n' || ((buf)[i] >= 0x20 && (buf)[i] <= 0x7E && (buf)[i] != '\\')) \
			fputc((buf)[i], stderr); \
		else \
			fprintf(stderr, "\\x%02X", (unsigned int)(unsigned char)(buf)[i]); \
	}

#define PRINT_WIDE_BUF(buf) \
	for (i = 0; i < ARRAY_COUNT(buf); i++) { \
		if ((buf)[i] == L'\n' || ((buf)[i] >= 0x20 && (buf)[i] <= 0x7E && (buf)[i] != L'\\')) \
			fputc((char)(buf)[i], stderr); \
		else \
			fprintf(stderr, "\\x%04X", (unsigned int)(wint_t)(buf)[i]); \
	} \

int main() {
	ANSI_STRING anull = {};
	UNICODE_STRING wnull = {};
	ANSI_STRING as0 = DEF_STRING("TEST\x00XYZA");
	ANSI_STRING as1 = DEF_STRING("TEST");
	UNICODE_STRING ws0 = DEF_STRING(L"TEST\x0000XYZA");
	UNICODE_STRING ws1 = DEF_STRING(L"TEST");
	char abuf[70];
	char abuf2[45];
	wchar_t wbuf[55];
	wchar_t wbuf2[50];
	int ret;
	size_t i;

	(void)ws1; /* avoid "warning: unused variable" on some builds */

	/*
	 * These tests do not work with msvcrt20.dll, msvcrt40.dll and msvcr40d.dll
	 * which do not support %Z format. All older and new CRT libraries support it.
	 *
	 * UCRT does not accept nul characters in ANSI_STRING for wide printf functions
	 * and treats them as errors (signaled by negative return value and stopping
	 * formatting). They are accepted in narrow printf functions. Nul characters
	 * in UNICODE_STRING are accepted by both narrow and wide printf functions.
	 */

#if __MSVCRT_VERSION__ >= 0x200 && __MSVCRT_VERSION__ <= 0x400
	return 0;
#endif

	memset(abuf, 0xff, sizeof(abuf));
#if __USE_MINGW_ANSI_STDIO == 1 || defined(_UCRT)
	ret = snprintf(abuf, ARRAY_COUNT(abuf), "%Z\n%hZ\n%lZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &ws0, &as0, &ws0, &ws0, &anull, NULL, &wnull, NULL);
#else
	ret = snprintf(abuf, ARRAY_COUNT(abuf), "%Z\n%hZ\n%lZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &as0, &as0, &as0, &ws0, &anull, NULL, &wnull, NULL);
#endif
	if (ret != ARRAY_COUNT(abuf)-2 || memcmp(abuf, "TEST\x00XYZA\nTEST\x00XYZA\nTEST\x00XYZA\nTEST\x00XYZA\n(null)\n(null)\n(null)\n(null)\n\x00\xFF", ARRAY_COUNT(abuf)) != 0) {
		fprintf(stderr, "ret: expected=%d got=%d\n", ARRAY_COUNT(abuf)-2, ret);
		fprintf(stderr, "abuf:\n");
		PRINT_NARROW_BUF(abuf);
		fprintf(stderr, "\n");
		return 1;
	}
	printf("OK abuf\n");

	memset(abuf2, 0xff, sizeof(abuf2));
	ret = snprintf(abuf2, ARRAY_COUNT(abuf2), "%hZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &as1, &ws0, &anull, NULL, &wnull, NULL);
	if (ret != ARRAY_COUNT(abuf2)-2 || memcmp(abuf2, "TEST\nTEST\x00XYZA\n(null)\n(null)\n(null)\n(null)\n\x00\xFF", ARRAY_COUNT(abuf2)) != 0) {
		fprintf(stderr, "ret: expected=%d got=%d\n", ARRAY_COUNT(abuf2)-2, ret);
		fprintf(stderr, "abuf2:\n");
		PRINT_NARROW_BUF(abuf2);
		fprintf(stderr, "\n");
		return 1;
	}
	printf("OK abuf2\n");

	memset(wbuf, 0xff, sizeof(wbuf));
#if __USE_MINGW_ANSI_STDIO == 1 || defined(_UCRT)
	ret = swprintf(wbuf, ARRAY_COUNT(wbuf), L"%Z\n%hZ\n%lZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &as1, &as1, &ws1, &ws0, &anull, NULL, &wnull, NULL);
#else
	ret = swprintf(wbuf, ARRAY_COUNT(wbuf), L"%Z\n%hZ\n%lZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &as1, &as1, &as1, &ws0, &anull, NULL, &wnull, NULL);
#endif
	if (ret != ARRAY_COUNT(wbuf)-2 || wmemcmp(wbuf, L"TEST\nTEST\nTEST\nTEST\x00XYZA\n(null)\n(null)\n(null)\n(null)\n\x0000\xFFFF", ARRAY_COUNT(wbuf)) != 0) {
		fprintf(stderr, "ret: expected=%d got=%d\n", ARRAY_COUNT(wbuf)-2, ret);
		fprintf(stderr, "wbuf:\n");
		PRINT_WIDE_BUF(wbuf);
		fprintf(stderr, "\n");
		return 1;
	}
	printf("OK wbuf\n");

	memset(wbuf2, 0xff, sizeof(wbuf2));
	ret = swprintf(wbuf2, ARRAY_COUNT(wbuf2), L"%Z\n%hZ\n%wZ\n%hZ\n%hZ\n%wZ\n%wZ\n", &as1, &as1, &ws0, &anull, NULL, &wnull, NULL);
	if (ret != ARRAY_COUNT(wbuf2)-2 || wmemcmp(wbuf2, L"TEST\nTEST\nTEST\x00XYZA\n(null)\n(null)\n(null)\n(null)\n\x0000\xFFFF", ARRAY_COUNT(wbuf2)) != 0) {
		fprintf(stderr, "ret: expected=%d got=%d\n", ARRAY_COUNT(wbuf2)-2, ret);
		fprintf(stderr, "wbuf2:\n");
		PRINT_WIDE_BUF(wbuf2);
		fprintf(stderr, "\n");
		return 1;
	}
	printf("OK wbuf2\n");

	return 0;
}
