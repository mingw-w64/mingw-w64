#include <stdlib.h>
#include <uchar.h>

/* mingw-w64 headers */
#include "libtest.h"

int main (void)
{
	mingw_test_init ();

	/* wchar_t should be compatible with char16_t on Windows */
	if (sizeof(wchar_t) != sizeof(char16_t))
		abort ();

	return 0;
}
