#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

static int check_tls_section(HMODULE module)
{
  IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *)module; /* This cast does not work on Win32s, HMODULE is not IMAGE_DOS_HEADER* */
  assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

  IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *)((BYTE *)dos_header + dos_header->e_lfanew);
  assert(nt_headers->Signature == IMAGE_NT_SIGNATURE);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory));
  assert(nt_headers->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR_MAGIC);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory[nt_headers->OptionalHeader.NumberOfRvaAndSizes]));

  return
    nt_headers->OptionalHeader.NumberOfRvaAndSizes > IMAGE_DIRECTORY_ENTRY_TLS &&
    nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size != 0 &&
    nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress != 0;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI thread_main(LPVOID user_data)
{
  int (*register_func)(void);
  int ret = 0;

  register_func = (typeof(register_func))user_data;
  if (register_func) {
    printf("Registering for DLL_THREAD_DETACH\n");
    if (register_func() != 0) {
      printf("Error: Registration function for DLL_THREAD_DETACH failed\n");
      ret = 1;
    }
  }

  return ret;
}

int main(void)
{
  mingw_test_init();


  int ret = 0;
  HMODULE lib;
  int (*get_func)(void);
  void (*set_var_func)(int *var);
  int (*register_func)(void);
  int var;
  HANDLE thread;
  int skip_thread;


  /* Test for native PE TLS callback */
  printf("libtls01.dll - BEGIN - Native PE TLS callback\n");
  if (_osplatform != VER_PLATFORM_WIN32s && _winver < _WIN32_WINNT_VISTA) {
    printf("libtls01.dll - Skipped because Win9x and WinNT pre-Vista systems do not call native PE TLS callbacks on LoadLibrary()\n");
  } else {
    lib = LoadLibraryA("libtls01.dll");
    if (!lib) {
      printf("Error: Cannot load library libtls01.dll: %lu\n", GetLastError());
      ret = 1;
    } else {
      if (_osplatform != VER_PLATFORM_WIN32s) {
        if (!check_tls_section(lib)) {
          printf("Error: Library libtls01.dll does not have TLS section\n");
          ret = 1;
        } else {
          printf("libtls01.dll - TLS section is present\n");
        }
      }

      get_func = (typeof(get_func))(void(*)(void))GetProcAddress(lib, "get_process_attach");
      if (!get_func) {
        printf("Error: Cannot resolve get_process_attach symbol from library libtls01.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        if (get_func() != 1) {
          printf("Error: TLS callback in libtls01.dll was called %d times for DLL_PROCESS_ATTACH\n", get_func());
          ret = 1;
        } else {
          printf("libtls01.dll - TLS callback for DLL_PROCESS_ATTACH was called\n");
        }
      }

      get_func = (typeof(get_func))(void(*)(void))GetProcAddress(lib, "get_thread_attach");
      if (!get_func) {
        printf("Error: Cannot resolve get_thread_attach symbol from library libtls01.dll: %lu\n", GetLastError());
        ret = 1;
      }
      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_thread_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_thread_detach_var symbol from library libtls01.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }
      var = 0;
      skip_thread = 0;
      thread = CreateThread(NULL, 0, thread_main, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
      if (!thread) {
        if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
          printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
          ret = 1;
        } else {
          printf("Skipped thread subcase\n");
          skip_thread = 1;
        }
      } else {
        DWORD tret;
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &tret);
        CloseHandle(thread);
        if (tret) {
          printf("Error: Thread failed\n");
          ret = 1;
        }
      }
      if (!skip_thread) {
        if (get_func) {
          if (get_func() != 1) {
            printf("Error: TLS callback in libtls01.dll was called %d times for DLL_THREAD_ATTACH\n", get_func());
            ret = 1;
          } else {
            printf("libtls01.dll - TLS callback for DLL_THREAD_ATTACH was called\n");
          }
        }
        if (set_var_func) {
          if (var != 1) {
            printf("Error: TLS callback in libtls01.dll was called %d times for DLL_THREAD_DETACH\n", var);
            ret = 1;
          } else {
            printf("libtls01.dll - TLS callback for DLL_THREAD_DETACH was called\n");
          }
        }
      }

      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_process_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_process_detach_var symbol from library libtls01.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }

      var = 0;
      FreeLibrary(lib);

      if (set_var_func) {
        if (var != 1) {
          printf("Error: TLS callback in libtls01.dll was called %d times for DLL_PROCESS_DETACH\n", var);
          ret = 1;
        } else {
          printf("libtls01.dll - TLS callback for DLL_PROCESS_DETACH was called\n");
        }
      }
    }
  }
  printf("libtls01.dll - END\n\n");


  /* Test for CRT dyn TLS callback which uses PE TLS callback __dyn_tls_init */
  printf("libtls02.dll - BEGIN - __dyn_tls_init\n");
  if (_osplatform != VER_PLATFORM_WIN32s && _winver < _WIN32_WINNT_VISTA) {
    printf("libtls02.dll - Skipped because Win9x and WinNT pre-Vista systems do not call native PE TLS callbacks on LoadLibrary()\n");
  } else {
    lib = LoadLibraryA("libtls02.dll");
    if (!lib) {
      printf("Error: Cannot load library libtls02.dll: %lu\n", GetLastError());
      ret = 1;
    } else {
      if (_osplatform != VER_PLATFORM_WIN32s) {
        if (!check_tls_section(lib)) {
          printf("Error: Library libtls02.dll does not have TLS section\n");
          ret = 1;
        } else {
          printf("libtls02.dll - TLS section is present\n");
        }
      }

      get_func = (typeof(get_func))(void(*)(void))GetProcAddress(lib, "get_process_or_thread_attach");
      if (!get_func) {
        printf("Error: Cannot resolve get_process_attach symbol from library libtls02.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        if (get_func() != 1) {
          printf("Error: TLS callback in libtls02.dll was called %d times for DLL_PROCESS_ATTACH\n", get_func());
          ret = 1;
        } else {
          printf("libtls02.dll - TLS callback for DLL_PROCESS_ATTACH was called\n");
        }

        skip_thread = 0;
        thread = CreateThread(NULL, 0, thread_main, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
        if (!thread) {
          if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
            printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
            ret = 1;
          } else {
            printf("Skipped thread subcase\n");
            skip_thread = 1;
          }
        } else {
          DWORD tret;
          WaitForSingleObject(thread, INFINITE);
          GetExitCodeThread(thread, &tret);
          CloseHandle(thread);
          if (tret) {
            printf("Error: Thread failed\n");
            ret = 1;
          }
        }

        if (!skip_thread) {
          if (get_func() != 2) {
            printf("Error: TLS callback in libtls02.dll was called %d times for DLL_THREAD_ATTACH\n", get_func()-1);
            ret = 1;
          } else {
            printf("libtls02.dll - TLS callback for DLL_THREAD_ATTACH was called\n");
          }
        }
      }

      FreeLibrary(lib);
    }
  }
  printf("libtls02.dll - END\n\n");


  /* Test for CRT dtor TLS callback via __tlregdtor which uses PE TLS callback __dyn_tls_dtor and PE TLS variables */
  printf("libtls03.dll - BEGIN - __tlregdtor\n");
  if (_winver < _WIN32_WINNT_VISTA) {
    printf("libtls03.dll - Skipped because pre-Vista systems do not support native PE TLS variables for LoadLibrary()\n");
  } else {
    lib = LoadLibraryA("libtls03.dll");
    if (!lib) {
      printf("Error: Cannot load library libtls03.dll: %lu\n", GetLastError());
      ret = 1;
    } else {
      if (_osplatform != VER_PLATFORM_WIN32s) {
        if (!check_tls_section(lib)) {
          printf("Error: Library libtls03.dll does not have TLS section\n");
          ret = 1;
        } else {
          printf("libtls03.dll - TLS section is present\n");
        }
      }

      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_process_or_thread_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_process_or_thread_detach_var symbol from library libtls03.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }

      register_func = (typeof(register_func))(void(*)(void))GetProcAddress(lib, "register_thread_detach_for_current_thread");
      if (!register_func) {
        printf("Error: Cannot resolve register_thread_detach_for_current_thread symbol from library libtls03.dll: %lu\n", GetLastError());
        ret = 1;
      } else {
        printf("Registering for DLL_PROCESS_DETACH\n");
        if (register_func() != 0) {
          printf("Error: Registration function for DLL_PROCESS_DETACH failed\n");
          ret = 1;
        }
      }

      var = 0;
      skip_thread = 0;
      thread = CreateThread(NULL, 0, thread_main, (void *)register_func, 0, &(DWORD){0} /*out: ThreadId*/);
      if (!thread) {
        if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
          printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
          ret = 1;
        } else {
          printf("Skipped thread subcase\n");
          skip_thread = 1;
        }
      } else {
        DWORD tret;
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &tret);
        CloseHandle(thread);
        if (tret) {
          printf("Error: Thread failed\n");
          ret = 1;
        }
      }

      if (!skip_thread) {
        if (set_var_func) {
          if (var != 1) {
            printf("Error: TLS callback in libtls03.dll was called %d times for DLL_THREAD_DETACH\n", var);
            ret = 1;
          } else {
            printf("libtls03.dll - TLS callback for DLL_THREAD_DETACH was called\n");
          }
        }
      }

      var = 0;
      FreeLibrary(lib);

      if (set_var_func) {
        if (var != 1) {
          printf("Error: TLS callback in libtls03.dll was called %d times for DLL_PROCESS_DETACH\n", var);
          ret = 1;
        } else {
          printf("libtls03.dll - TLS callback for DLL_PROCESS_DETACH was called\n");
        }
      }
    }
  }
  printf("libtls03.dll - END\n\n");


  /* Tests for _onexit, atexit, __cxa_atexit, __mingw_cxa_atexit (they do not have to use native PE TLS callbacks) */
  static const char *const libnames1[] = { "libtls04.dll", "libtls05.dll", "libtls06.dll", "libtls07.dll" };
  static const char *const descrs1[] = { "_onexit", "atexit", "__cxa_atexit", "__mingw_cxa_atexit" };
  for (size_t i = 0; i < sizeof(libnames1)/sizeof(libnames1[0]); i++) {
    const char *const libname = libnames1[i];
    const char *const descr = descrs1[i];
    printf("%s - BEGIN - %s\n", libname, descr);
    lib = LoadLibraryA(libname);
    if (!lib) {
      printf("Error: Cannot load library %s: %lu\n", libname, GetLastError());
      ret = 1;
    } else {
      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_process_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_process_detach_var symbol from library %s: %lu\n", libname, GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }

      /* Run new thread just to verify that it will not call our process detach callback */
      var = 0;
      skip_thread = 0;
      thread = CreateThread(NULL, 0, thread_main, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
      if (!thread) {
        if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
          printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
          ret = 1;
        } else {
          printf("Skipped thread subcase\n");
          skip_thread = 1;
        }
      } else {
        DWORD tret;
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &tret);
        CloseHandle(thread);
        if (tret) {
          printf("Error: Thread failed\n");
          ret = 1;
        }
      }

      if (!skip_thread) {
        if (set_var_func) {
          if (var != 0) {
            printf("Error: TLS callback in %s was called %d times for DLL_THREAD_DETACH\n", libname, var);
            ret = 1;
          } else {
            printf("%s - TLS callback for DLL_THREAD_DETACH was NOT called\n", libname);
          }
        }
      }

      var = 0;
      FreeLibrary(lib);

      if (set_var_func) {
        if (var != 1) {
          printf("Error: TLS callback in %s was called %d times for DLL_PROCESS_DETACH\n", libname, var);
          ret = 1;
        } else {
          printf("%s - TLS callback for DLL_PROCESS_DETACH was called\n", libname);
        }
      }
    }
    printf("%s - END\n\n", libname);
  }


  /* Tests for __cxa_thread_atexit, __mingw_cxa_thread_atexit (they do not have to use native PE TLS callbacks) */
  static const char *const libnames2[] = { "libtls08.dll", "libtls09.dll" };
  static const char *const descrs2[] = { "__cxa_thread_atexit", "__mingw_cxa_thread_atexit" };
  for (size_t i = 0; i < sizeof(libnames2)/sizeof(libnames2[0]); i++) {
    const char *const libname = libnames2[i];
    const char *const descr = descrs2[i];
    printf("%s - BEGIN - %s\n", libname, descr);
    lib = LoadLibraryA(libname);
    if (!lib) {
      printf("Error: Cannot load library %s: %lu\n", libname, GetLastError());
      ret = 1;
    } else {
      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_process_or_thread_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_process_detach_var symbol from library %s: %lu\n", libname, GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }

      register_func = (typeof(register_func))(void(*)(void))GetProcAddress(lib, "register_thread_detach_for_current_thread");
      if (!register_func) {
        printf("Error: Cannot resolve register_thread_detach_for_current_thread symbol from library %s: %lu\n", libname, GetLastError());
        ret = 1;
      } else {
        printf("Registering for DLL_PROCESS_DETACH\n");
        if (register_func() != 0) {
          printf("Error: Registration function for DLL_PROCESS_DETACH failed\n");
          ret = 1;
        }
      }

      var = 0;
      skip_thread = 0;
      thread = CreateThread(NULL, 0, thread_main, (void *)register_func, 0, &(DWORD){0} /*out: ThreadId*/);
      if (!thread) {
        if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
          printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
          ret = 1;
        } else {
          printf("Skipped thread subcase\n");
          skip_thread = 1;
        }
      } else {
        DWORD tret;
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &tret);
        CloseHandle(thread);
        if (tret) {
          printf("Error: Thread failed\n");
          ret = 1;
        }
      }

      if (!skip_thread) {
        if (set_var_func) {
          if (var != 1) {
            printf("Error: TLS callback in %s was called %d times for DLL_THREAD_DETACH\n", libname, var);
            ret = 1;
          } else {
            printf("%s - TLS callback for DLL_THREAD_DETACH was called\n", libname);
          }
        }
      }

      var = 0;
      FreeLibrary(lib);

      if (set_var_func) {
        if (var != 1) {
          printf("Error: TLS callback in %s was called %d times for DLL_PROCESS_DETACH\n", libname, var);
          ret = 1;
        } else {
          printf("%s - TLS callback for DLL_PROCESS_DETACH was called\n", libname);
        }
      }
    }
    printf("%s - END\n\n", libname);
  }


  /* Tests for __mingwthr_key_dtor, ___w64_mingwthr_add_key_dtor (they do not have to use native PE TLS callbacks) */
  static const char *const libnames3[] = { "libtls10.dll", "libtls11.dll" };
  static const char *const descrs3[] = { "__mingwthr_key_dtor", "___w64_mingwthr_add_key_dtor" };
  for (size_t i = 0; i < sizeof(libnames3)/sizeof(libnames3[0]); i++) {
    const char *const libname = libnames3[i];
    const char *const descr = descrs3[i];
    printf("%s - BEGIN - %s\n", libname, descr);
    lib = LoadLibraryA(libname);
    if (!lib) {
      printf("Error: Cannot load library %s: %lu\n", libname, GetLastError());
      ret = 1;
    } else {
      set_var_func = (typeof(set_var_func))(void(*)(void))GetProcAddress(lib, "set_thread_detach_var");
      if (!set_var_func) {
        printf("Error: Cannot resolve set_process_detach_var symbol from library %s: %lu\n", libname, GetLastError());
        ret = 1;
      } else {
        set_var_func(&var);
      }

      var = 0;
      skip_thread = 0;
      thread = CreateThread(NULL, 0, thread_main, NULL, 0, &(DWORD){0} /*out: ThreadId*/);
      if (!thread) {
        if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED) {
          printf("Error: Cannot spawn new thread: %lu\n", GetLastError());
          ret = 1;
        } else {
          printf("Skipped thread subcase\n");
          skip_thread = 1;
        }
      } else {
        DWORD tret;
        WaitForSingleObject(thread, INFINITE);
        GetExitCodeThread(thread, &tret);
        CloseHandle(thread);
        if (tret) {
          printf("Error: Thread failed\n");
          ret = 1;
        }
      }

      if (!skip_thread) {
        if (set_var_func) {
          if (var != 1) {
            printf("Error: TLS callback in %s was called %d times for DLL_THREAD_DETACH\n", libname, var);
            ret = 1;
          } else {
            printf("%s - TLS callback for DLL_THREAD_DETACH was called\n", libname);
          }
        }
      }

      var = 0;
      FreeLibrary(lib);

      if (set_var_func) {
        if (var != 0) {
          printf("Error: TLS callback in %s was called %d times for DLL_PROCESS_DETACH\n", libname, var);
          ret = 1;
        } else {
          printf("%s - TLS callback for DLL_PROCESS_DETACH was NOT called\n", libname);
        }
      }
    }
    printf("%s - END\n\n", libname);
  }


  if (ret == 0) printf("ALL OK\n"); else printf("FAILED\n");
  return ret;
}
