#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
#include <errno.h>

static int handler_called = 0;
static int handler_errno = -1;
static void handler(const wchar_t *expression __attribute__((unused)), const wchar_t *function __attribute__((unused)), const wchar_t *file __attribute__((unused)), unsigned int line __attribute__((unused)), uintptr_t reserved __attribute__((unused))) {
    handler_called = 1;
    handler_errno = errno;
}

int main() {
    const wchar_t input[] = L"ABC CDE FGH";
    wchar_t wcs[sizeof(input)/sizeof(input[0])];
    wchar_t *state;
    wchar_t *token;

    _set_invalid_parameter_handler(handler);

    /* wcstok normal usage without errors */
    handler_called = 0;
    handler_errno = -1;
    errno = -1;
    memcpy(wcs, input, sizeof(input));
    token = wcstok(wcs, L" ", &state);
    assert(wcscmp(token, L"ABC") == 0);
    token = wcstok(NULL, L" ", &state);
    assert(wcscmp(token, L"CDE") == 0);
    token = wcstok(NULL, L" ", &state);
    assert(wcscmp(token, L"FGH") == 0);
    token = wcstok(NULL, L" ", &state);
    assert(!token);
    assert(errno == -1);
    assert(handler_called == 0);
    assert(handler_errno == -1);

    /* msvcrt wcstok for NULL string and state returns NULL and does not set errno and does not call handler */
    /* UCRT wcstok for NULL string expects that the state is non-NULL and dereference it, so do not call this test for UCRT */
#ifndef _UCRT
    handler_called = 0;
    handler_errno = -1;
    errno = -1;
    state = NULL;
    token = wcstok(NULL, L"", &state);
    assert(!token);
    assert(errno == -1);
    assert(handler_called == 0);
    assert(handler_errno == -1);
#endif

    /* wcstok_s normal usage without errors */
    handler_called = 0;
    handler_errno = -1;
    errno = -1;
    memcpy(wcs, input, sizeof(input));
    token = wcstok_s(wcs, L" ", &state);
    assert(wcscmp(token, L"ABC") == 0);
    token = wcstok_s(NULL, L" ", &state);
    assert(wcscmp(token, L"CDE") == 0);
    token = wcstok_s(NULL, L" ", &state);
    assert(wcscmp(token, L"FGH") == 0);
    token = wcstok_s(NULL, L" ", &state);
    assert(!token);
    assert(errno == -1);
    assert(handler_called == 0);
    assert(handler_errno == -1);

    /* wcstok_s for NULL string and state returns NULL and sets errno and calls handler */
    handler_called = 0;
    handler_errno = -1;
    errno = -1;
    state = NULL;
    token = wcstok_s(NULL, L" ", &state);
    assert(!token);
    assert(errno == EINVAL);
    assert(handler_called == 1);
    assert(handler_errno == EINVAL);

    /* wcstok_s validates parameters and on error sets errno and calls handler */
    handler_called = 0;
    handler_errno = -1;
    memcpy(wcs, input, sizeof(input));
    errno = -1;
    token = wcstok_s(wcs, L" ", NULL);
    assert(!token);
    assert(errno == EINVAL);
    assert(handler_called == 1);
    assert(handler_errno == EINVAL);

    handler_called = 0;
    handler_errno = -1;
    memcpy(wcs, input, sizeof(input));
    errno = -1;
    state = NULL;
    token = wcstok_s(wcs, NULL, &state);
    assert(!token);
    assert(errno == EINVAL);
    assert(handler_called == 1);
    assert(handler_errno == EINVAL);

    return 0;
}
