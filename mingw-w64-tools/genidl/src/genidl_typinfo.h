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

#ifndef GETIDL_TYPINFO_HXX
#define GETIDL_TYPINFO_HXX

#define TITYP_NONE -1
#define TITYP_NAME  0
#define TITYP_STR   1
#define TITYP_GUIDS 2
#define TITYP_TYPINFO_NAMES 3
#define TITYP_DEREF 4
#define TITYP_ARRAY 5
#define TITYP_REF   6
#define TITYP_IMP   7
#define TITYP_UNKNOWN 8
#define TITYP_CUSTOMDATA 9
#define TITYP_CUSTOMGUID 10
#define TITYP_IMPREF	 11

#define TITYP_MAX 12

typedef struct sTITyp {
  uint32_t memid;       /**< TYPINFO offset ID */
  int32_t kind;         /**< TYPINFO kind */
  int32_t refkind;
  uint32_t refmem;      /**< Offset reference */
  char *refstr;         /**< Helper member to form TYPINFO string */
  char *poststr;        /**< Helper member to form TYPINFO string */
  char name[1];         /**< TYPINFO name */
} sTITyp;

typedef struct sTITypsHash
{
  size_t count;
  size_t max;
  sTITyp **arr; /**< Directory of TYPEINFO data found */
} sTITypsHash;

typedef struct sTITyps {
  sTITypsHash buc[TITYP_MAX];
} sTITyps;

/**
 * Initializes sTITyps struct
 * @param[in] ptyp Address of struct to zero
 * @return always 0
 */
int32_t TI_init_typs (sTITyps *ptyp);

/**
 * Walks over and frees sTITypsHash entries found in sTITyps structure
 * @param[in] ptyp sTITyps structure containing sTITypsHash entries to destroy
 * @return always 0
 */
int32_t TI_dest_typs (sTITyps *ptyp);

/**
 * Inserts a sTITypsHash entry into a sTITyps
 * @param[in] ptyp Structure to insert entry into
 * @param[in] memid
 * @param[in] kind
 * @param[in] refkind
 * @param[in] refmem
 * @param[in[ refstr
 * @param[in] name typinfo associated name
 * @param[in] poststr
 * @return always 0
 */
int32_t TI_add_typ (sTITyps *ptyp, uint32_t memid, int32_t kind, int32_t refkind, uint32_t refmem,
		const char *refstr, const char *name, const char *poststr);

/**
 * Searches ptyp for element matching memid and kind.
 * @param[in] ptyp typelib data to search
 * @param[in] memid TTYPINFO offset to match
 * @param[in] kind TYPINFO kind to match
 * @return pointer to matching matching typinfo section
 */
sTITyp *TI_get_typ (sTITyps *ptyp, uint32_t memid, int32_t kind);

/**
 * Returns a string to name the TYPINFO sections
 * @param[in] memid TTYPINFO offset to match
 * @param[in] kind TYPINFO kind to match
 * @param[in] varname
 * @return string to name of TYPINFO section
 */
char *TI_get_typ_name (sTITyps *ptyp, uint32_t memid, int32_t kind, const char *varName);

/**
 * Decodes name from raw data to insert into new entry in sTITyps
 * @return always 0
 */
int32_t TI2_import_name (sTITyps *nptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_guid (sTITyps *gptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_typinfo_names (sTITyps *tptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_string (sTITyps *sptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_typedesc (sTITyps *dptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_customdata (sTITyps *dptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_customdataguid (sTITyps *gptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_importlibs (sTITyps *iptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_ref (sTITyps *gptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_array (sTITyps *gptr, unsigned char *dta, uint32_t len);
int32_t TI2_import_importref (sTITyps *gptr, unsigned char *dta, uint32_t len);

const char *decode_VT_name_tmp (unsigned short vt);
size_t getVT_data (sTITyps *dptr, uint32_t vt, unsigned char *dta, char **ret);
char *TI_getVTorDref (sTITyps *ptyp,uint32_t vt, const char *varName, int beBase);
size_t getVT_size (uint32_t vt, unsigned char *dta, size_t *basesz);

typedef struct sTI2TypeBaseMemItem {
  int beFunc;
#ifdef __GNUC__
  __extension__
#endif
  union {
    unsigned char *mem;
    sMSFT_func *func;
    sMSFT_var *var;
  };
  uint32_t *customData;
  sMSFT_FuncParam *funcParam;
  uint32_t *extData;
  size_t max;
} sTI2TypeBaseMemItem;

typedef struct sTI2TypeBaseMem
{
  size_t count;
  sTI2TypeBaseMemItem *items;
} sTI2TypeBaseMem;

typedef struct sTI2TypeBase {
  uint32_t kind;
  uint32_t kflags;
  int32_t cVars;
  int32_t cFuncs;
  int32_t flags;
  char *name;
  char *guid;
  char *docstr;
  char *custData;
  uint32_t version;
  char *dataType;
  sMSFT_TypeInfoBase *tib;
  sTI2TypeBaseMem mem;
} sTI2TypeBase;

typedef struct sTI2TypLib {
  int16_t ver_major;
  int16_t ver_minor;
  int32_t version;
  char *guid;
  uint32_t lcid1;
  uint32_t lcid2;
  uint32_t flags;
  uint32_t setFlags;
  char *helpstring;
  char *helpfile;
  int32_t helpstringctx;
  int32_t helpctx;
  char *name;
  int32_t dispatch;
  size_t nr_typinfos;
  size_t nr_impinfos;
  uint32_t *typinfos_hash;
  sTITyps ti2_typs;
  sTI2TypeBase *typb;
} sTI2TypLib;

sTI2TypLib *TI2_typlib_init (unsigned char *dta, size_t len);
void TI2_typlib_dest (sTI2TypLib *tl);
void TI2_typlib_hdr (FILE *fp, sTI2TypLib *tl, const char *orgfname);
void TI2_typlib_idl (FILE *fp, sTI2TypLib *tl, const char *orgname);

/**
 * Returns text string of calling convention type
 * @param[in] cc calling convention type
 * @return pointer to convention type string
 */
const char *getCallConvName (int32_t cc);

/**
 * Returns text string of calling convention type
 * @param[in] fp file to print to
 * @param[in] typs
 */
void printValue(FILE *fp, sTITyps *typs, uint32_t val);
char *getTypeBOrImpRef (sTITyps *dptr, uint32_t off, const char *var);

#endif
