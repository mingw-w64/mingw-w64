#include <ctype.h>

#undef isascii
int
isascii (int c)
{
	return __isascii(c);
}
