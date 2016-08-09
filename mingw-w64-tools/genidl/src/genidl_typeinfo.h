/*
    genidl - Generate interface defintion language listing from a
    Portable Executable.
    Copyright (C) 2009-2016  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _GENIDL_TYPEINFO_H
#define _GENIDL_TYPEINFO_H

#define TYPELIB_MSFT_MAGIC 0x5446534d /**< MSFT */
#define TYPELIB_NO_INDEX (-1)

#pragma pack(push,1)

typedef struct sTypeLibMSFT {
  uint32_t magic1;
  uint16_t ver_major;
  uint16_t ver_minor;
  int32_t pos_guid; /* references into guid table.  */
  int32_t lcid;         /* locale id */
  int32_t lcid2;
  uint32_t var_flags; /* syskind, 0x10:if helpfile defined, 0x100:if helpstringdll defined. */
  int32_t version;      /* set with SetVersion() */
  int32_t flags;        /* set with SetFlags() */
  int32_t nr_typeinfos;
  int32_t helpstring; /* position of help string in stringtable.  */
  int32_t helpstringcontext;
  int32_t helpcontext;
  int32_t nametable_count; /* number of names in name table.  */
  uint32_t nametable_size; /* nr of characters in name table */
  int32_t name_offset; /* offset of name in name table.  */
  int32_t helpfile; /* position of helpfile in stringtable */
  int32_t custom_data_offset; /* if -1 no custom data, else it is offset in customer data/guid offset table */
  uint32_t res44;            /* unknown always: 0x20 (guid hash size?) */
  uint32_t res48;            /* unknown always: 0x80 (name hash size?) */
  int32_t dispatchpos;      /* HREFTYPE to IDispatch, or -1 if no IDispatch */
  int32_t nr_impinfos;        /* number of impinfos */
  int32_t dta[1];
} sTypeLibMSFT;
  /* 0x100 set with a helpstringdll defined - in this
  case the offset to the name in the stringtable
  appears right after this struct, before the
  typeinfo offsets */

typedef struct sSegMSFT {
  uint32_t offset;       /* absolute offset in file */
  uint32_t length;       /* length of segment */
  int32_t res08;        /* unknown always -1 */
  int32_t res0c;        /* unknown always 0x0f in the header 0x03 in the typeinfo_data */
} sSegMSFT;

typedef enum eSegMSFT {
    eSegMSFT_TYPEINFO = 0,  /* type information */
    eSegMSFT_IMPORTINFO,    /* import information */
    eSegMSFT_IMPORTFILES,   /* import filenames */
    eSegMSFT_REFERENCES,    /* references (?) */
    eSegMSFT_GUIDHASH,      /* hash table for guids? */
    eSegMSFT_GUID,          /* guid storage */
    eSegMSFT_NAMEHASH,      /* hash table for names */
    eSegMSFT_NAME,          /* name storage */
    eSegMSFT_STRING,        /* string storage */
    eSegMSFT_TYPEDESC,      /* type descriptions */
    eSegMSFT_ARRAYDESC,     /* array descriptions */
    eSegMSFT_CUSTDATA,      /* custom data */
    eSegMSFT_CUSTDATAGUID,  /* custom data guids */
    eSegMSFT_UNKNOWN,       /* ??? */
    eSegMSFT_UNKNOWN2,      /* ??? */
    eSegMSFT_MAX
} eSegMSFT;

typedef struct sMSFT_TypeInfoBase {
  int32_t typekind;             /*  it is the TKIND_xxx */
  /* some byte alignment stuff */
  uint32_t memoffset;          /* points past the file, if no elements */
  int32_t res2;               /* zero if no element, N*0x40 */
  int32_t res3;               /* -1 if no element, (N-1)*0x38 */
  int32_t res4;               /* always? 3 */
  int32_t res5;               /* always? zero */
  int32_t cElement;           /* counts elements, HI=cVars, LO=cFuncs */
  int32_t res7;               /* always? zero */
  int32_t res8;               /* always? zero */
  int32_t res9;               /* always? zero */
  int32_t resA;               /* always? zero */
  int32_t posguid;            /* position in guid table */
  int32_t flags;              /* Typeflags */
  int32_t NameOffset;         /* offset in name table */
  int32_t version;            /* element version */
  int32_t docstringoffs;      /* offset of docstring in string tab */
  int32_t helpstringcontext;  /*  */
  int32_t helpcontext;    /* */
  int32_t oCustData;          /* offset in customer data table */
  int16_t   cImplTypes;     /* nr of implemented interfaces */
  int16_t   cbSizeVft;      /* virtual table size, including inherits */
  int32_t size;           /* size in bytes, at least for structures */
  /* FIXME: name of this field */
  int32_t datatype1;      /* position in type description table */
  /* or in base interfaces */
  /* if coclass: offset in reftable */
  /* if interface: reference to inherited if */
  int32_t datatype2;      /* for interfaces: hiword is num of inherited funcs */
  /* loword is num of inherited interfaces */
  int32_t res18;          /* always? 0 */
  int32_t res19;          /* always? -1 */
} sMSFT_TypeInfoBase;

typedef struct sMSFT_TypeDesc {
  uint16_t kind;
  uint16_t flag;
#ifdef __GNUC__
  __extension__
#endif
  union {
    int32_t oTypeB;
    int32_t oTypeD;
    int32_t oArrayD;
    uint32_t vt;
  };
} sMSFT_TypeDesc;

typedef struct sMSFT_RefTab {
  int32_t oData1;
  int32_t no;
  int32_t data2;
  int32_t oNextRef;
} sMSFT_RefTab;

typedef struct sMSFT_CustomData {
  uint16_t vt;
  unsigned char dta[1];
} sMSFT_CustomData;

typedef struct sMSFT_CDGuid {
    int32_t oGuid;
    int32_t oData;
    int32_t next;     /* next offset in the table, -1 if it's the last */
} sMSFT_CDGuid;

typedef struct sMSFT_FuncParam {
  uint32_t dataType;
  int32_t oName;
  int32_t flags;
} sMSFT_FuncParam;

typedef struct sMSFT_var {
  uint16_t rlen;
  uint16_t id;
  uint32_t datatype;
  uint32_t flags;
  uint16_t varKind;
  uint16_t vardescSize;
  int32_t oValue;
} sMSFT_var;

typedef struct sMSFT_func {
  uint16_t rlen;
  uint16_t id;
  uint32_t datatype;
  uint32_t flags;
  uint16_t vtableOffset;
  uint16_t funcdescSize;
#ifdef __GNUC__
  __extension__
#endif
  union {
    int32_t fkccic;
#ifdef __GNUC__
    __extension__
#endif
    struct {
      uint32_t funcKind : 3;
      uint32_t invokeKind : 4;
      uint32_t hasCustomData : 1;
      uint32_t callconv : 4;
      uint32_t hasParamDefValue : 1;
      uint32_t isOEntryNumeric : 1;
      uint32_t hasRetvalParam : 1;
      uint32_t reserved1 : 1;
      uint32_t nextIndexWithSameID : 16;
    } f;
  };
  uint16_t nrArgs;
  uint16_t nrOptArgs;
  uint32_t data[1];
  /* sMSFT_FuncParam params[1]; */
} sMSFT_func;

typedef struct sMSFT_ImpFiles {
  int32_t res1;
  int32_t res2;
  int32_t res3;
  uint16_t flag;
  unsigned char dta[1];
} sMSFT_ImpFiles;

typedef struct sMSFT_memblob {
  uint32_t size;
#ifdef __GNUC__
  __extension__
#endif
  union {
    unsigned char dta[1];
  };
} sMSFT_memblob;

typedef struct sMSFT_ArrayDesc {
  uint32_t vt;
  uint16_t count;
  uint16_t size;
  uint32_t vt_offset[1];
} sMSFT_ArrayDesc;

typedef struct tagMSFT_ImpInfo {
  uint16_t count;
  unsigned char flags;
  unsigned char tkind;
  int32_t oImpFile;       /* offset in the Import File table */
  int32_t oGuid;          /* offset in Guid table or typeinfo index (see bit 16 of flags) */
} MSFT_ImpInfo;

#pragma pack(pop)

#ifndef IMPLTYPEFLAG_FDEFAULT
#define IMPLTYPEFLAG_FDEFAULT 1
#define IMPLTYPEFLAG_FSOURCE 2
#define IMPLTYPEFLAG_FRESTRICTED 4
#define IMPLTYPEFLAG_FDEFAULTVTABLE 8
#endif

#ifndef LIBFLAG_FRESTRICTED
#define LIBFLAG_FRESTRICTED 1
#define LIBFLAG_FCONTROL 2
#define LIBFLAG_FHIDDEN 4
#define LIBFLAG_FHASDISKIMAGE 0x8
#endif

#define VARKIND_PERINSTANCE 0
#define VARKIND_STATIC	1
#define VARKIND_CONST	2
#define VARKIND_DISPATCH  3

#define SYSKIND_WIN16 0
#define SYSKIND_WIN32 1
#define SYSKIND_MAC 2
#define SYSKIND_WIN64 3

/* Function Kind */
#define FUNCTKIND_VIRTUAL 0
#define FUNCTKIND_PUREVIRTUAL 1
#define FUNCTKIND_NONVIRTUAL 2
#define FUNCTKIND_STATIC 3
#define FUNCTKIND_DISPATCH 4

/* Invoke Kind */
#define INVOKIND_FUNC 1
#define INVOKIND_PROPERTYGET 2
#define INVOKIND_PROPERTYPUT 4
#define INVOKIND_PROPERTYPUTREF 8

/* Calling convention */
#define CALLCONV_FASTCALL 0     /**< fastcall call convention */
#define CALLCONV_CDECL 1        /**< cdecl call convention */
#define CALLCONV_PASCAL 2       /**< pascal call convention */
#define CALLCONV_MACPASCAL 3
#define CALLCONV_STDCALL 4      /**< stdcall call convention */
#define CALLCONV_FPFASTCALL 5
#define CALLCONV_SYSCALL 6
#define CALLCONV_MPWCDECL 7
#define CALLCONV_MPWPASCAL 8
#define CALLCONV_MAX 9

#define DESCKIND_NONE 0
#define DESCKIND_FUNCDESC 1
#define DESCKIND_VARDESC 2
#define DESCKIND_TYPECOMP 3
#define DESCKIND_IMPLICITAPPOBJECT 4
#define DESCKIND_MAX 5

#define TKIND_ENUM  0
#define TKIND_RECORD 1
#define TKIND_MODULE 2
#define TKIND_INTERFACE 3
#define TKIND_DISPATCH 4
#define TKIND_COCLASS 5
#define TKIND_ALIAS 6
#define TKIND_UNION 7
#define TKIND_MAX 8

#define TYPEFLAG_FAPPOBJECT 1
#define TYPEFLAG_FCANCREATE 2
#define TYPEFLAG_FLICENSED 4
#define TYPEFLAG_FPREDECLID 8
#define TYPEFLAG_FHIDDEN 0x10
#define TYPEFLAG_FCONTROL 0x20
#define TYPEFLAG_FDUAL 0x40
#define TYPEFLAG_FNONEXTENSIBLE 0x80
#define TYPEFLAG_FOLEAUTOMATION 0x100
#define TYPEFLAG_FRESTRICTED 0x200
#define TYPEFLAG_FAGGREGATABLE 0x400
#define TYPEFLAG_FREPLACEABLE 0x800
#define TYPEFLAG_FDISPATCHABLE 0x1000
#define TYPEFLAG_FREVERSEBIND 0x2000
#define TYPEFLAG_FPROXY 0x4000


#define TYPE_KIND_STRUCT_EXTERN 0x10a1
#define TYPE_KIND_ENUM 0x2120
#define TYPE_KIND_STRUCT 0x2121
#define TYPE_KIND_TYPEDEF 0x2126
#define TYPE_KIND_FORWARD_STRUCT 0x2225
#define TYPE_KIND_INTERFACE 0x2234
#define TYPE_KIND_UNION 0x4221
#define TYPE_KIND_UNION_INSTRUCT 0x4227

#ifndef PARAMFLAG_FIN
#define PARAMFLAG_FIN 1
#define PARAMFLAG_FOUT 2
#define PARAMFLAG_FLCID 4
#define PARAMFLAG_FRETVAL 8
#define PARAMFLAG_FOPT 0x10
#define PARAMFLAG_FHASDEFAULT 0x20
#define PARAMFLAG_FHASCUSTDATA 0x40
#endif

#define FUNCFLAG_FRESTRICTED 0x1
#define FUNCFLAG_FSOURCE 0x2
#define FUNCFLAG_FBINDABLE 0x4
#define FUNCFLAG_FREQUESTEDIT 0x8
#define FUNCFLAG_FDISPLAYBIND  0x10
#define FUNCFLAG_FDEFAULTBIND 0x20
#define FUNCFLAG_FHIDDEN 0x40
#define FUNCFLAG_FUSESGETLASTERROR 0x80
#define FUNCFLAG_FDEFAULTCOLLELEM 0x100
#define FUNCFLAG_FUIDEFAULT 0x200
#define FUNCFLAG_FNONBROWSABLE 0x400
#define FUNCFLAG_FREPLACEABLE 0x800
#define FUNCFLAG_FIMMEDIATEBIND 0x1000

#define VARFLAG_FREADONLY 0x1
#define VARFLAG_FSOURCE 0x2
#define VARFLAG_FBINDABLE 0x4
#define VARFLAG_FREQUESTEDIT 0x8
#define VARFLAG_FDISPLAYBIND 0x10
#define VARFLAG_FDEFAULTBIND 0x20
#define VARFLAG_FHIDDEN 0x40
#define VARFLAG_FRESTRICTED 0x80
#define VARFLAG_FDEFAULTCOLLELEM 0x100
#define VARFLAG_FUIDEFAULT 0x200
#define VARFLAG_FNONBROWSABLE 0x400
#define VARFLAG_FREPLACEABLE 0x800
#define VARFLAG_FIMMEDIATEBIND 0x1000

/**
 * Dumps typelib info to file
 * @param[in] fp File to print to
 * @param[in] dta raw typelib info
 * @param[in] size size of raw typelib information
 */
void dumpInfo (FILE *fp, unsigned char *dta, size_t size);

#endif
