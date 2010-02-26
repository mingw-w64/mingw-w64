/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009, 2010 by the mingw-w64 project

 Written by Kai Tietz.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _GENIDL_H
#define _GENIDL_H

#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <memory.h>
#include <stdarg.h>
#include <stdint.h>

#if 0
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
#endif

typedef struct sCfgAlias {
  struct sCfgAlias *next;
  char name[1];
} sCfgAlias;

typedef struct sCfgItem {
  struct sCfgItem *next;
  char *type;
  char name[1];
} sCfgItem;

typedef struct sCfgLib {
  struct sCfgLib *next;
  sCfgAlias *alias;
  sCfgItem *item;
  char name[1];
} sCfgLib;

int genidl_read_config (const char *fname);
int genidl_save_config_fp (FILE *fp);
int genidl_save_config (const char *fname);
int genidl_ismodified_config (void);

int genidl_add_lib (const char *lib);
int genidl_add_lib_alias (const char *lib, const char *alias);
int genidl_add_lib_item (const char *lib, const char *name, const char *typ);
int genidl_del_lib_item (const char *lib);
const char *genidl_find_type (const char *lib, const char *name);

char *genidl_strlwr (char *s);

#endif
