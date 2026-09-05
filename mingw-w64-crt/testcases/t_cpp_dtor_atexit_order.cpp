#include <cstdio>
#include <cstdlib>

/* mingw-w64 headers */
#ifdef __MINGW64_VERSION_MAJOR
#include "libtest.h"
#endif

template <void (*callback)()> struct dtor_callback { ~dtor_callback() { callback(); } };

bool main_success = false;

void cpp_tls_dtor_func() {
    std::puts("C++ tls dtor func called");
    if (!main_success) {
        std::_Exit(1);
    }
    std::puts("TEST PASSED");
    std::_Exit(0);
}
template struct dtor_callback<&cpp_tls_dtor_func>;
thread_local dtor_callback<&cpp_tls_dtor_func> register_tls_dtor_callback;

void atexit_func() {
    std::puts("atexit func called");
    std::puts("TEST FAILED");
    main_success = false;
    std::_Exit(1);
}

int main() {
#ifdef __MINGW64_VERSION_MAJOR
    mingw_test_init();
#endif

    /* For some unknown reasons, this test is passing under mingw-w64 clang and under linux gcc but is failing under mingw-w64 gcc */
#if defined(__MINGW64_VERSION_MAJOR) && !defined(__clang__)
    return 77;
#endif

    std::puts("registering atexit func");
    std::atexit(atexit_func);

    std::puts("referencing C++ TLS obj");
    (void)register_tls_dtor_callback;

    std::puts("registering atexit func");
    std::atexit(atexit_func);

    std::puts("returning from main");
    main_success = true;
    return 1;
}
