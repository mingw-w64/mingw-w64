#include <windows.h>
#include <stdio.h>

HANDLE __mingw_get_msvcrt_handle(void);

static unsigned int last_value = 0;
typedef unsigned int (*f_get_output_format)(void);
typedef unsigned int (*f_set_output_format)(unsigned int);

static int call_set_output_format(unsigned int _Format)
{
  f_set_output_format sof;
  sof = (f_set_output_format) GetProcAddress (__mingw_get_msvcrt_handle(), "_set_output_format");
  if (sof)
    {
      last_value = (*sof)(_Format);
    }
  if (!sof) return 0;
  return 1;
}

static int call_get_output_format(void)
{
  f_get_output_format sof;
  sof = (f_get_output_format) GetProcAddress (__mingw_get_msvcrt_handle(), "_get_output_format");
  if (sof)
    {
      last_value = (*sof)();
    }
  if (!sof) return 0;
  return 1;
}  

unsigned int __cdecl __mingw_set_output_format(unsigned int _Format)
{
  static int probe = 1;
  unsigned int l = last_value;
  if (probe)
    probe = call_set_output_format (_Format);
  if (!probe)
    {
      last_value = _Format;
    }
  return l;
}

unsigned int __cdecl __mingw_get_output_format(void)
{
  static int probe = 1;
  if (probe)
    probe = call_get_output_format ();
  return last_value;
}

