/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <errno.h>
#include <time.h>
#include <string.h>

/* Both the 32-bit and 64-bit versions of gmtime, mktime, mkgmtime,
 * and localtime all use one common tm structure per thread for the
 * conversion. Each call to one of these functions destroys the
 * result of any previous call.
 */
struct tm *__cdecl localtime_r(const time_t *_Time, struct tm *_Tm)
{
    struct tm *tmp;

    if (_Time == NULL || _Tm == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    tmp = localtime(_Time);
    if (tmp != NULL)
        memcpy(_Tm, tmp, sizeof(struct tm);
    return tmp;
}

struct tm *__cdecl gmtime_r(const time_t *_Time, struct tm *_Tm)
{
	struct tm *tmp;

    if (_Time == NULL || _Tm == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

	tmp = gmtime(_Time);
	if (tmp != NULL)
		memcpy(_Tm, tmp, sizeof(struct tm);
	return tmp;
}

char *__cdecl ctime_r(const time_t *_Time, char * _Str)
{
	char *tmp;

    if (_Tm == NULL || _Str == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

	tmp = ctime(_Time);
	if (tmp != NULL)
		tmp = strcpy(_Str,tmp);
	return tmp;
}

 /* TODO: thread safe implementation */
char *__cdecl asctime_r(const struct tm *_Tm, char * _Str)
{
    char *tmp;

    if (_Tm == NULL || _Str == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    tmp = asctime(_Tm);
    if (tmp != NULL)
        tmp = strcpy(_Str,tmp);

    return tmp;
}
