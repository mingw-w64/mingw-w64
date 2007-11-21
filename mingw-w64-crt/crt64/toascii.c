#include <ctype.h>

#undef toascii
int
toascii (int c)
{
	return __toascii(c);
}
