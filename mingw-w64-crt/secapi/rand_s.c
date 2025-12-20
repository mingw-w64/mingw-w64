#define _CRT_RAND_S
#include <stdlib.h>
#include <windows.h>
#include <ntsecapi.h>
#include <errno.h>

#ifdef __LIBMSVCRT_OS__
#include <msvcrt.h>
#endif

static BOOLEAN (WINAPI *pRtlGenRandom)(void*,ULONG);

static errno_t mingw_rand_s(unsigned int *pval)
{
    return !pval || !pRtlGenRandom || !pRtlGenRandom(pval, sizeof(*pval)) ? EINVAL : 0;
}

static errno_t __cdecl init_rand_s(unsigned int*);

errno_t (__cdecl *__MINGW_IMP_SYMBOL(rand_s))(unsigned int*) = init_rand_s;

errno_t __cdecl
rand_s(unsigned int *val)
{
    return __MINGW_IMP_SYMBOL(rand_s)(val);
}

static errno_t __cdecl init_rand_s(unsigned int *val)
{
    int (__cdecl *func)(unsigned int*) = NULL;

#ifdef __LIBMSVCRT_OS__
    func = (void*)GetProcAddress(__mingw_get_msvcrt_handle(), "rand_s");
#endif

    if(!func) {
        func = mingw_rand_s;
        /* Function RtlGenRandom() is located in library advapi32.dll under
         * symbol "SystemFunction036" and is available since Windows XP. */
        pRtlGenRandom = (void*)GetProcAddress(LoadLibraryW(L"advapi32.dll"), "SystemFunction036");
    }

    return (__MINGW_IMP_SYMBOL(rand_s) = func)(val);
}
