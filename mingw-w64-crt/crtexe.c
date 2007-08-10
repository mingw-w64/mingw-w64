#undef CRTDLL
#define _DLL

#define SPECIAL_CRTEXE

#include <oscalls.h>
#include <internal.h>
#include <process.h>
#include <math.h>
#include <stdlib.h>
#include <tchar.h>
#include <sect_attribs.h>
#include <locale.h>

#ifndef __winitenv
extern wchar_t ***_imp____winitenv;
#define __winitenv (*_imp____winitenv)
#endif

#ifndef __initenv
extern char ***_imp____initenv;
#define __initenv (*_imp____initenv)
#endif

/* This symbol is defined by ld.  */
extern IMAGE_DOS_HEADER _ImageBase;

#define SPACECHAR _T(' ')
#define DQUOTECHAR _T('\"')

_CRTIMP void __setusermatherr(int (__cdecl *)(struct _exception *));

extern int *_imp___fmode;
extern int *_imp___commode;

extern int _fmode;
extern int *_imp___commode;
#define _commode (*_imp___commode)
extern int _dowildcard;

extern int __defaultmatherr;
extern _CRTIMP void __cdecl _initterm(_PVFV *, _PVFV *);

static int __cdecl check_managed_app (void);

extern _CRTALLOC(".CRT$XIA") _PIFV __xi_a[];
extern _CRTALLOC(".CRT$XIZ") _PIFV __xi_z[];
extern _CRTALLOC(".CRT$XCA") _PVFV __xc_a[];
extern _CRTALLOC(".CRT$XCZ") _PVFV __xc_z[];

extern const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;

extern _PVFV *__onexitbegin;
extern _PVFV *__onexitend;

extern int mingw_app_type;

static int argc;
#ifdef WPRFLAG
static wchar_t **argv;
static wchar_t **envp;
#else
static char **argv;
static char **envp;
#endif

static int argret;
static int mainret=0;
static int managedapp;
static int has_cctor = 0;
static _startupinfo startinfo;

static int __cdecl pre_c_init (void);
static void __cdecl pre_cpp_init (void);

_CRTALLOC(".CRT$XIAA") _PIFV mingw_pcinit = pre_c_init;
_CRTALLOC(".CRT$XCAA") _PVFV mingw_pcppinit = pre_cpp_init;

static int __cdecl
pre_c_init (void)
{
  managedapp = check_managed_app ();
  if (mingw_app_type)
    __set_app_type(_GUI_APP);
  else
    __set_app_type (_CONSOLE_APP);
  __onexitbegin = __onexitend = (_PVFV *) _encode_pointer ((_PVFV *)(-1));

  *_imp___fmode = _fmode;
  *_imp___commode = _commode;

#ifdef WPRFLAG
  _wsetargv();
#else
  _setargv();
#endif

  if (! __defaultmatherr)
    __setusermatherr (_matherr);

  if (__globallocalestatus == -1)
    {
    }
  return 0;
}

static void __cdecl
pre_cpp_init (void)
{
  startinfo.newmode = _newmode;

#ifdef WPRFLAG
  argret = __wgetmainargs(&argc,&argv,&envp,_dowildcard,&startinfo);
#else
  argret = __getmainargs(&argc,&argv,&envp,_dowildcard,&startinfo);
#endif
}

static int __tmainCRTStartup (void);

#ifdef WPRFLAG
int wWinMainCRTStartup (void)
#else
int WinMainCRTStartup (void)
#endif
{
  mingw_app_type = 1;
  __security_init_cookie ();
  return __tmainCRTStartup ();
}

#ifdef WPRFLAG
int wmainCRTStartup (void)
#else
int mainCRTStartup (void)
#endif
{
  mingw_app_type = 0;
  __security_init_cookie ();
  return __tmainCRTStartup ();
}


__declspec(noinline) int
__tmainCRTStartup (void)
{
  _TUCHAR *lpszCommandLine = NULL;
  STARTUPINFO StartupInfo;
  BOOL inDoubleQuote = FALSE;
  memset (&StartupInfo, 0, sizeof (STARTUPINFO));
  
  if (mingw_app_type)
    GetStartupInfo (&StartupInfo);
  {
    void *lock_free = NULL;
    void *fiberid = ((PNT_TIB)NtCurrentTeb())->StackBase;
    int nested = FALSE;
    while((lock_free = InterlockedCompareExchangePointer ((volatile PVOID *) &__native_startup_lock,
							  fiberid, 0)) != 0)
      {
	if (lock_free == fiberid)
	  {
	    nested = TRUE;
	    break;
	  }
	Sleep(1000);
      }
    if (__native_startup_state == __initializing)
      {
	_amsg_exit (31);
      }
    else if (__native_startup_state == __uninitialized)
      {
	__native_startup_state = __initializing;
	_initterm ((_PVFV *)(void *)__xi_a, (_PVFV *)(void *) __xi_z);
      }
    else
      has_cctor = 1;

    if (__native_startup_state == __initializing)
      {
	_initterm (__xc_a, __xc_z);
	__native_startup_state = __initialized;
      }
    _ASSERTE(__native_startup_state == __initialized);
    if (! nested)
      InterlockedExchangePointer ((volatile PVOID *) &__native_startup_lock, 0);
    
    if (__dyn_tls_init_callback != NULL && _IsNonwritableInCurrentImage ((PBYTE) &__dyn_tls_init_callback))
      __dyn_tls_init_callback (NULL, DLL_THREAD_ATTACH, NULL);
    
    _CrtSetCheckCount (FALSE);

    if (mingw_app_type)
      {
#ifdef WPRFLAG
    if (_wcmdln == NULL)
      return 255;
    lpszCommandLine = (wchar_t *) _wcmdln;
#else
    lpszCommandLine = (unsigned char *) _acmdln;
#endif
    while (*lpszCommandLine > SPACECHAR || (*lpszCommandLine&&inDoubleQuote))
      {
	if (*lpszCommandLine == DQUOTECHAR)
	  inDoubleQuote = !inDoubleQuote;
#ifdef _MBCS
	if (_ismbblead (*lpszCommandLine))
	  {
	    if (lpszCommandLine)
	      lpszCommandLine++;
	  }
#endif
	++lpszCommandLine;
      }
    while (*lpszCommandLine && (*lpszCommandLine <= SPACECHAR))
      lpszCommandLine++;

#ifdef WPRFLAG
    mainret = wmain (
    	(int) (StartupInfo.dwFlags & STARTF_USESHOWWINDOW ? StartupInfo.wShowWindow : SW_SHOWDEFAULT),
    	(wchar_t **) lpszCommandLine, (wchar_t **) (HINSTANCE) &_ImageBase);
#else
    mainret = main (
    	(int) (StartupInfo.dwFlags & STARTF_USESHOWWINDOW ? StartupInfo.wShowWindow : SW_SHOWDEFAULT),
    	(char **) lpszCommandLine, (char **) (HINSTANCE) &_ImageBase);
#endif
    }
  else
    {
#ifdef WPRFLAG
    __winitenv = envp;
    mainret = wmain (argc, argv, envp);
#else
    __initenv = envp;
    mainret = main (argc, argv, envp);
#endif
    }
    if (!managedapp)
      exit (mainret);

    if (has_cctor == 0)
      _cexit ();
  }
  return mainret;
}

extern int mingw_initltsdrot_force;
extern int mingw_initltsdyn_force;
extern int mingw_initltssuo_force;
extern int mingw_initcharmax;

static int __cdecl
check_managed_app (void)
{
  PIMAGE_DOS_HEADER pDOSHeader;
  PIMAGE_NT_HEADERS pPEHeader;
  PIMAGE_OPTIONAL_HEADER32 pNTHeader32;
  PIMAGE_OPTIONAL_HEADER64 pNTHeader64;

  /* Force to be linked.  */
  mingw_initltsdrot_force=1;
  mingw_initltsdyn_force=1;
  mingw_initltssuo_force=1;
  mingw_initcharmax=1;

  pDOSHeader = (PIMAGE_DOS_HEADER) &_ImageBase;
  if (pDOSHeader->e_magic != IMAGE_DOS_SIGNATURE)
    return 0;

  pPEHeader = (PIMAGE_NT_HEADERS)((char *)pDOSHeader + pDOSHeader->e_lfanew);
  if (pPEHeader->Signature != IMAGE_NT_SIGNATURE)
    return 0;

  pNTHeader32 = (PIMAGE_OPTIONAL_HEADER32) &pPEHeader->OptionalHeader;
  switch (pNTHeader32->Magic)
    {
    case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
      if (pNTHeader32->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader32->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
      pNTHeader64 = (PIMAGE_OPTIONAL_HEADER64)pNTHeader32;
      if (pNTHeader64->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader64->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    }
  return 0;
}

int __defaultmatherr;
