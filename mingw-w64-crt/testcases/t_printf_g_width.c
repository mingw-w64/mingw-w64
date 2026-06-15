#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>

/* mingw-w64 headers */
#include "libtest.h"

int main(void) {
    char buffer[64];

    mingw_test_init ();

    // Test the %g width specifier
    // This should output "(    100000)" with 4 leading spaces
    snprintf(buffer, sizeof(buffer), "(%10g)", 100000.0f);

    if (strcmp(buffer, "(    100000)") != 0) {
        fprintf(stderr, "FAIL: Expected '(    100000)', got '%s'\n", buffer);
        return 1;
    }

    return 0;
}
