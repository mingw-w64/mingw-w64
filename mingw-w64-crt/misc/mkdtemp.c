#define _CRT_RAND_S
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

/*
    The mkdtemp() function generates a unique temporary name from template,
    the creates the directory with that name and returns pointer to the modified
    template string.

    The template may be any name with at least six trailing Xs, for example
    /tmp/temp.XXXXXXXX. The trailing Xs are replaced with a unique digit and
    letter combination that makes the file name unique. Since it will be
    modified, template must not be a string constant, but should be declared as
    a character array.
 */
char *__cdecl mkdtemp (char *template_name)
{
    int j, ret, len, index;
    unsigned int i, r;

    /* These are the (62) characters used in temporary filenames. */
    static const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    /* The last six characters of template must be "XXXXXX" */
    if (template_name == NULL || (len = strlen (template_name)) < 6
            || memcmp (template_name + (len - 6), "XXXXXX", 6)) {
        errno = EINVAL;
        return NULL;
    }

    /* User may supply more than six trailing Xs */
    for (index = len - 6; index > 0 && template_name[index - 1] == 'X'; index--);

    /* Like OpenBSD, mkdtemp() will try 2 ** 31 combinations before giving up. */
    for (i = 0; i <= INT_MAX; i++) {
        for(j = index; j < len; j++) {
            if (rand_s(&r))
                r = rand() ^ _time32(NULL);
            template_name[j] = letters[r % 62];
        }
        ret = _mkdir(template_name);
        if (ret == 0) return template_name;
        if (ret != 0 && errno != EEXIST) return NULL;
    }

    return NULL;
}

#if 0
#include <stdio.h>
int main ()
{
    int i;

    for (i = 0; i < 10; i++) {
        char template_name[] = { "temp_XXXXXX" };
        char *name = mkdtemp (template_name);
        if (name) {
            fprintf (stderr, "name=%s\n", name);
            rmdir (name);
        } else {
            fprintf (stderr, "errno=%d\n", errno);
        }
    }

    for (i = 0; i < 10; i++) {
        char template_name[] = { "temp_XXXXXXXX" };
        char *name = mkdtemp (template_name);
        if (name) {
            fprintf (stderr, "name=%s\n", name);
            rmdir (name);
        } else {
            fprintf (stderr, "errno=%d\n", errno);
        }
    }

    return 0;
}
#endif
