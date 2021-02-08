/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs
#define yylval          parser_lval
#define yychar          parser_char

/* First part of user prologue.  */
#line 1 "tools/widl/parser.y"

/*
 * IDL Compiler
 *
 * Copyright 2002 Ove Kaaven
 * Copyright 2006-2008 Robert Shearman
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "widl.h"
#include "utils.h"
#include "parser.h"
#include "header.h"
#include "typelib.h"
#include "typegen.h"
#include "expr.h"
#include "typetree.h"

typedef struct list typelist_t;
struct typenode {
  type_t *type;
  struct list entry;
};

struct _import_t
{
  char *name;
  int import_performed;
};

static str_list_t *append_str(str_list_t *list, char *str);
static attr_list_t *append_attr(attr_list_t *list, attr_t *attr);
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_attrp(enum attr_type type, void *val);
static attr_t *make_custom_attr(UUID *id, expr_t *pval);
static expr_list_t *append_expr(expr_list_t *list, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface);
static ifref_t *make_ifref(type_t *iface);
static var_list_t *append_var_list(var_list_t *list, var_list_t *vars);
static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *p);
static declarator_t *make_declarator(var_t *var);
static type_t *make_safearray(type_t *type);
static typelib_t *make_library(const char *name, const attr_list_t *attrs);
static void append_array(declarator_t *decl, expr_t *expr);
static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual);
static void append_chain_callconv(type_t *chain, char *callconv);
static warning_list_t *append_warning(warning_list_t *, int);

static type_t *reg_typedefs(decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs);
static type_t *find_type_or_error(const char *name);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);
static void init_lookup_namespace(const char *name);
static void push_lookup_namespace(const char *name);

static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_member_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
const char *get_attr_display_name(enum attr_type type);
static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func);

static void check_async_uuid(type_t *iface);

static statement_t *make_statement(enum statement_type type);
static statement_t *make_statement_type_decl(type_t *type);
static statement_t *make_statement_reference(type_t *type);
static statement_t *make_statement_declaration(var_t *var);
static statement_t *make_statement_library(typelib_t *typelib);
static statement_t *make_statement_pragma(const char *str);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names, int declonly);
static statement_t *make_statement_import(const char *str);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *lookup_namespace = &global_namespace;

static typelib_t *current_typelib;


#line 206 "tools/widl/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    aIDENTIFIER = 258,             /* aIDENTIFIER  */
    aPRAGMA = 259,                 /* aPRAGMA  */
    aKNOWNTYPE = 260,              /* aKNOWNTYPE  */
    aNAMESPACE = 261,              /* aNAMESPACE  */
    aNUM = 262,                    /* aNUM  */
    aHEXNUM = 263,                 /* aHEXNUM  */
    aDOUBLE = 264,                 /* aDOUBLE  */
    aSTRING = 265,                 /* aSTRING  */
    aWSTRING = 266,                /* aWSTRING  */
    aSQSTRING = 267,               /* aSQSTRING  */
    aUUID = 268,                   /* aUUID  */
    aEOF = 269,                    /* aEOF  */
    aACF = 270,                    /* aACF  */
    SHL = 271,                     /* SHL  */
    SHR = 272,                     /* SHR  */
    MEMBERPTR = 273,               /* MEMBERPTR  */
    EQUALITY = 274,                /* EQUALITY  */
    INEQUALITY = 275,              /* INEQUALITY  */
    GREATEREQUAL = 276,            /* GREATEREQUAL  */
    LESSEQUAL = 277,               /* LESSEQUAL  */
    LOGICALOR = 278,               /* LOGICALOR  */
    LOGICALAND = 279,              /* LOGICALAND  */
    ELLIPSIS = 280,                /* ELLIPSIS  */
    tAGGREGATABLE = 281,           /* tAGGREGATABLE  */
    tAGILE = 282,                  /* tAGILE  */
    tALLNODES = 283,               /* tALLNODES  */
    tALLOCATE = 284,               /* tALLOCATE  */
    tANNOTATION = 285,             /* tANNOTATION  */
    tAPICONTRACT = 286,            /* tAPICONTRACT  */
    tAPPOBJECT = 287,              /* tAPPOBJECT  */
    tASYNC = 288,                  /* tASYNC  */
    tASYNCUUID = 289,              /* tASYNCUUID  */
    tAUTOHANDLE = 290,             /* tAUTOHANDLE  */
    tBINDABLE = 291,               /* tBINDABLE  */
    tBOOLEAN = 292,                /* tBOOLEAN  */
    tBROADCAST = 293,              /* tBROADCAST  */
    tBYTE = 294,                   /* tBYTE  */
    tBYTECOUNT = 295,              /* tBYTECOUNT  */
    tCALLAS = 296,                 /* tCALLAS  */
    tCALLBACK = 297,               /* tCALLBACK  */
    tCASE = 298,                   /* tCASE  */
    tCDECL = 299,                  /* tCDECL  */
    tCHAR = 300,                   /* tCHAR  */
    tCOCLASS = 301,                /* tCOCLASS  */
    tCODE = 302,                   /* tCODE  */
    tCOMMSTATUS = 303,             /* tCOMMSTATUS  */
    tCONST = 304,                  /* tCONST  */
    tCONTEXTHANDLE = 305,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 306, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 307, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 308,               /* tCONTRACT  */
    tCONTRACTVERSION = 309,        /* tCONTRACTVERSION  */
    tCONTROL = 310,                /* tCONTROL  */
    tCPPQUOTE = 311,               /* tCPPQUOTE  */
    tCUSTOM = 312,                 /* tCUSTOM  */
    tDECODE = 313,                 /* tDECODE  */
    tDEFAULT = 314,                /* tDEFAULT  */
    tDEFAULTBIND = 315,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 316,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 317,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 318,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 319, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 320,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 321,          /* tDISPINTERFACE  */
    tDLLNAME = 322,                /* tDLLNAME  */
    tDONTFREE = 323,               /* tDONTFREE  */
    tDOUBLE = 324,                 /* tDOUBLE  */
    tDUAL = 325,                   /* tDUAL  */
    tENABLEALLOCATE = 326,         /* tENABLEALLOCATE  */
    tENCODE = 327,                 /* tENCODE  */
    tENDPOINT = 328,               /* tENDPOINT  */
    tENTRY = 329,                  /* tENTRY  */
    tENUM = 330,                   /* tENUM  */
    tERRORSTATUST = 331,           /* tERRORSTATUST  */
    tEVENTADD = 332,               /* tEVENTADD  */
    tEVENTREMOVE = 333,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 334,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 335,         /* tEXPLICITHANDLE  */
    tEXTERN = 336,                 /* tEXTERN  */
    tFALSE = 337,                  /* tFALSE  */
    tFASTCALL = 338,               /* tFASTCALL  */
    tFAULTSTATUS = 339,            /* tFAULTSTATUS  */
    tFLAGS = 340,                  /* tFLAGS  */
    tFLOAT = 341,                  /* tFLOAT  */
    tFORCEALLOCATE = 342,          /* tFORCEALLOCATE  */
    tHANDLE = 343,                 /* tHANDLE  */
    tHANDLET = 344,                /* tHANDLET  */
    tHELPCONTEXT = 345,            /* tHELPCONTEXT  */
    tHELPFILE = 346,               /* tHELPFILE  */
    tHELPSTRING = 347,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 348,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 349,          /* tHELPSTRINGDLL  */
    tHIDDEN = 350,                 /* tHIDDEN  */
    tHYPER = 351,                  /* tHYPER  */
    tID = 352,                     /* tID  */
    tIDEMPOTENT = 353,             /* tIDEMPOTENT  */
    tIGNORE = 354,                 /* tIGNORE  */
    tIIDIS = 355,                  /* tIIDIS  */
    tIMMEDIATEBIND = 356,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 357,         /* tIMPLICITHANDLE  */
    tIMPORT = 358,                 /* tIMPORT  */
    tIMPORTLIB = 359,              /* tIMPORTLIB  */
    tIN = 360,                     /* tIN  */
    tIN_LINE = 361,                /* tIN_LINE  */
    tINLINE = 362,                 /* tINLINE  */
    tINPUTSYNC = 363,              /* tINPUTSYNC  */
    tINT = 364,                    /* tINT  */
    tINT32 = 365,                  /* tINT32  */
    tINT3264 = 366,                /* tINT3264  */
    tINT64 = 367,                  /* tINT64  */
    tINTERFACE = 368,              /* tINTERFACE  */
    tLCID = 369,                   /* tLCID  */
    tLENGTHIS = 370,               /* tLENGTHIS  */
    tLIBRARY = 371,                /* tLIBRARY  */
    tLICENSED = 372,               /* tLICENSED  */
    tLOCAL = 373,                  /* tLOCAL  */
    tLONG = 374,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 375,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 376,                  /* tMAYBE  */
    tMESSAGE = 377,                /* tMESSAGE  */
    tMETHODS = 378,                /* tMETHODS  */
    tMODULE = 379,                 /* tMODULE  */
    tMTA = 380,                    /* tMTA  */
    tNAMESPACE = 381,              /* tNAMESPACE  */
    tNOCODE = 382,                 /* tNOCODE  */
    tNONBROWSABLE = 383,           /* tNONBROWSABLE  */
    tNONCREATABLE = 384,           /* tNONCREATABLE  */
    tNONE = 385,                   /* tNONE  */
    tNONEXTENSIBLE = 386,          /* tNONEXTENSIBLE  */
    tNOTIFY = 387,                 /* tNOTIFY  */
    tNOTIFYFLAG = 388,             /* tNOTIFYFLAG  */
    tNULL = 389,                   /* tNULL  */
    tOBJECT = 390,                 /* tOBJECT  */
    tODL = 391,                    /* tODL  */
    tOLEAUTOMATION = 392,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 393,               /* tOPTIMIZE  */
    tOPTIONAL = 394,               /* tOPTIONAL  */
    tOUT = 395,                    /* tOUT  */
    tPARTIALIGNORE = 396,          /* tPARTIALIGNORE  */
    tPASCAL = 397,                 /* tPASCAL  */
    tPOINTERDEFAULT = 398,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 399,         /* tPRAGMA_WARNING  */
    tPROGID = 400,                 /* tPROGID  */
    tPROPERTIES = 401,             /* tPROPERTIES  */
    tPROPGET = 402,                /* tPROPGET  */
    tPROPPUT = 403,                /* tPROPPUT  */
    tPROPPUTREF = 404,             /* tPROPPUTREF  */
    tPROXY = 405,                  /* tPROXY  */
    tPTR = 406,                    /* tPTR  */
    tPUBLIC = 407,                 /* tPUBLIC  */
    tRANGE = 408,                  /* tRANGE  */
    tREADONLY = 409,               /* tREADONLY  */
    tREF = 410,                    /* tREF  */
    tREGISTER = 411,               /* tREGISTER  */
    tREPRESENTAS = 412,            /* tREPRESENTAS  */
    tREQUESTEDIT = 413,            /* tREQUESTEDIT  */
    tRESTRICTED = 414,             /* tRESTRICTED  */
    tRETVAL = 415,                 /* tRETVAL  */
    tRUNTIMECLASS = 416,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 417,              /* tSAFEARRAY  */
    tSHORT = 418,                  /* tSHORT  */
    tSIGNED = 419,                 /* tSIGNED  */
    tSINGLENODE = 420,             /* tSINGLENODE  */
    tSIZEIS = 421,                 /* tSIZEIS  */
    tSIZEOF = 422,                 /* tSIZEOF  */
    tSMALL = 423,                  /* tSMALL  */
    tSOURCE = 424,                 /* tSOURCE  */
    tSTANDARD = 425,               /* tSTANDARD  */
    tSTATIC = 426,                 /* tSTATIC  */
    tSTDCALL = 427,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 428,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 429,                 /* tSTRING  */
    tSTRUCT = 430,                 /* tSTRUCT  */
    tSWITCH = 431,                 /* tSWITCH  */
    tSWITCHIS = 432,               /* tSWITCHIS  */
    tSWITCHTYPE = 433,             /* tSWITCHTYPE  */
    tTHREADING = 434,              /* tTHREADING  */
    tTRANSMITAS = 435,             /* tTRANSMITAS  */
    tTRUE = 436,                   /* tTRUE  */
    tTYPEDEF = 437,                /* tTYPEDEF  */
    tUIDEFAULT = 438,              /* tUIDEFAULT  */
    tUNION = 439,                  /* tUNION  */
    tUNIQUE = 440,                 /* tUNIQUE  */
    tUNSIGNED = 441,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 442,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 443,            /* tUSERMARSHAL  */
    tUUID = 444,                   /* tUUID  */
    tV1ENUM = 445,                 /* tV1ENUM  */
    tVARARG = 446,                 /* tVARARG  */
    tVERSION = 447,                /* tVERSION  */
    tVIPROGID = 448,               /* tVIPROGID  */
    tVOID = 449,                   /* tVOID  */
    tWCHAR = 450,                  /* tWCHAR  */
    tWIREMARSHAL = 451,            /* tWIREMARSHAL  */
    tAPARTMENT = 452,              /* tAPARTMENT  */
    tNEUTRAL = 453,                /* tNEUTRAL  */
    tSINGLE = 454,                 /* tSINGLE  */
    tFREE = 455,                   /* tFREE  */
    tBOTH = 456,                   /* tBOTH  */
    CAST = 457,                    /* CAST  */
    PPTR = 458,                    /* PPTR  */
    POS = 459,                     /* POS  */
    NEG = 460,                     /* NEG  */
    ADDRESSOF = 461                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 128 "tools/widl/parser.y"

	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	type_t *type;
	var_t *var;
	var_list_t *var_list;
	declarator_t *declarator;
	declarator_list_t *declarator_list;
	statement_t *statement;
	statement_list_t *stmt_list;
	warning_t *warning;
	warning_list_t *warning_list;
	ifref_t *ifref;
	ifref_list_t *ifref_list;
	char *str;
	UUID *uuid;
	unsigned int num;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;

#line 488 "tools/widl/parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_aIDENTIFIER = 3,                /* aIDENTIFIER  */
  YYSYMBOL_aPRAGMA = 4,                    /* aPRAGMA  */
  YYSYMBOL_aKNOWNTYPE = 5,                 /* aKNOWNTYPE  */
  YYSYMBOL_aNAMESPACE = 6,                 /* aNAMESPACE  */
  YYSYMBOL_aNUM = 7,                       /* aNUM  */
  YYSYMBOL_aHEXNUM = 8,                    /* aHEXNUM  */
  YYSYMBOL_aDOUBLE = 9,                    /* aDOUBLE  */
  YYSYMBOL_aSTRING = 10,                   /* aSTRING  */
  YYSYMBOL_aWSTRING = 11,                  /* aWSTRING  */
  YYSYMBOL_aSQSTRING = 12,                 /* aSQSTRING  */
  YYSYMBOL_aUUID = 13,                     /* aUUID  */
  YYSYMBOL_aEOF = 14,                      /* aEOF  */
  YYSYMBOL_aACF = 15,                      /* aACF  */
  YYSYMBOL_SHL = 16,                       /* SHL  */
  YYSYMBOL_SHR = 17,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 18,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 19,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 20,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 21,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 22,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 23,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 24,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 25,                  /* ELLIPSIS  */
  YYSYMBOL_tAGGREGATABLE = 26,             /* tAGGREGATABLE  */
  YYSYMBOL_tAGILE = 27,                    /* tAGILE  */
  YYSYMBOL_tALLNODES = 28,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 29,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 30,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 31,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 32,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 33,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 34,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 35,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 36,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 37,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 38,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 39,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 40,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 41,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 42,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 43,                     /* tCASE  */
  YYSYMBOL_tCDECL = 44,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 45,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 46,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 47,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 48,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 49,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 50,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 51, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 52,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 53,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 54,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 55,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 56,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 57,                   /* tCUSTOM  */
  YYSYMBOL_tDECODE = 58,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 59,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 60,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 61,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 62,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 63,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 64,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 65,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 66,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 67,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 68,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 69,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 70,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 71,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 72,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 73,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 74,                    /* tENTRY  */
  YYSYMBOL_tENUM = 75,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 76,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 77,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 78,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 79,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 80,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 81,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 82,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 83,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 84,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 85,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 86,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 87,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 88,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 89,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 90,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 91,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 92,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 93,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 94,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 95,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 96,                    /* tHYPER  */
  YYSYMBOL_tID = 97,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 98,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 99,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 100,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 101,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 102,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 103,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 104,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 105,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 106,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 107,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 108,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 109,                     /* tINT  */
  YYSYMBOL_tINT32 = 110,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 111,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 112,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 113,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 114,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 115,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 116,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 117,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 118,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 119,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 120,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 121,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 122,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 123,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 124,                  /* tMODULE  */
  YYSYMBOL_tMTA = 125,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 126,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 127,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 128,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 129,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 130,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 131,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 132,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 133,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 134,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 135,                  /* tOBJECT  */
  YYSYMBOL_tODL = 136,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 137,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 138,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 139,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 140,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 141,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 142,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 143,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 144,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 145,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 146,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 147,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 148,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 149,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 150,                   /* tPROXY  */
  YYSYMBOL_tPTR = 151,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 152,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 153,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 154,                /* tREADONLY  */
  YYSYMBOL_tREF = 155,                     /* tREF  */
  YYSYMBOL_tREGISTER = 156,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 157,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 158,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 159,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 160,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 161,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 162,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 163,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 164,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 165,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 166,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 167,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 168,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 169,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 170,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 171,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 172,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 173,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 174,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 175,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 176,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 177,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 178,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 179,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 180,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 181,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 182,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 183,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 184,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 185,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 186,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 187,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 188,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 189,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 190,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 191,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 192,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 193,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 194,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 195,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 196,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 197,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 198,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 199,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 200,                    /* tFREE  */
  YYSYMBOL_tBOTH = 201,                    /* tBOTH  */
  YYSYMBOL_202_ = 202,                     /* ','  */
  YYSYMBOL_203_ = 203,                     /* '?'  */
  YYSYMBOL_204_ = 204,                     /* ':'  */
  YYSYMBOL_205_ = 205,                     /* '|'  */
  YYSYMBOL_206_ = 206,                     /* '^'  */
  YYSYMBOL_207_ = 207,                     /* '&'  */
  YYSYMBOL_208_ = 208,                     /* '<'  */
  YYSYMBOL_209_ = 209,                     /* '>'  */
  YYSYMBOL_210_ = 210,                     /* '-'  */
  YYSYMBOL_211_ = 211,                     /* '+'  */
  YYSYMBOL_212_ = 212,                     /* '*'  */
  YYSYMBOL_213_ = 213,                     /* '/'  */
  YYSYMBOL_214_ = 214,                     /* '%'  */
  YYSYMBOL_215_ = 215,                     /* '!'  */
  YYSYMBOL_216_ = 216,                     /* '~'  */
  YYSYMBOL_CAST = 217,                     /* CAST  */
  YYSYMBOL_PPTR = 218,                     /* PPTR  */
  YYSYMBOL_POS = 219,                      /* POS  */
  YYSYMBOL_NEG = 220,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 221,                /* ADDRESSOF  */
  YYSYMBOL_222_ = 222,                     /* '.'  */
  YYSYMBOL_223_ = 223,                     /* '['  */
  YYSYMBOL_224_ = 224,                     /* ']'  */
  YYSYMBOL_225_ = 225,                     /* '{'  */
  YYSYMBOL_226_ = 226,                     /* '}'  */
  YYSYMBOL_227_ = 227,                     /* ';'  */
  YYSYMBOL_228_ = 228,                     /* '('  */
  YYSYMBOL_229_ = 229,                     /* ')'  */
  YYSYMBOL_230_ = 230,                     /* '='  */
  YYSYMBOL_YYACCEPT = 231,                 /* $accept  */
  YYSYMBOL_input = 232,                    /* input  */
  YYSYMBOL_m_acf = 233,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 234,           /* gbl_statements  */
  YYSYMBOL_235_1 = 235,                    /* $@1  */
  YYSYMBOL_imp_statements = 236,           /* imp_statements  */
  YYSYMBOL_237_2 = 237,                    /* $@2  */
  YYSYMBOL_int_statements = 238,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 239,            /* semicolon_opt  */
  YYSYMBOL_statement = 240,                /* statement  */
  YYSYMBOL_pragma_warning = 241,           /* pragma_warning  */
  YYSYMBOL_warnings = 242,                 /* warnings  */
  YYSYMBOL_typedecl = 243,                 /* typedecl  */
  YYSYMBOL_cppquote = 244,                 /* cppquote  */
  YYSYMBOL_import_start = 245,             /* import_start  */
  YYSYMBOL_import = 246,                   /* import  */
  YYSYMBOL_importlib = 247,                /* importlib  */
  YYSYMBOL_libraryhdr = 248,               /* libraryhdr  */
  YYSYMBOL_library_start = 249,            /* library_start  */
  YYSYMBOL_librarydef = 250,               /* librarydef  */
  YYSYMBOL_m_args = 251,                   /* m_args  */
  YYSYMBOL_arg_list = 252,                 /* arg_list  */
  YYSYMBOL_args = 253,                     /* args  */
  YYSYMBOL_arg = 254,                      /* arg  */
  YYSYMBOL_array = 255,                    /* array  */
  YYSYMBOL_m_attributes = 256,             /* m_attributes  */
  YYSYMBOL_attributes = 257,               /* attributes  */
  YYSYMBOL_attrib_list = 258,              /* attrib_list  */
  YYSYMBOL_str_list = 259,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 260,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 261,             /* contract_ver  */
  YYSYMBOL_contract_req = 262,             /* contract_req  */
  YYSYMBOL_attribute = 263,                /* attribute  */
  YYSYMBOL_uuid_string = 264,              /* uuid_string  */
  YYSYMBOL_callconv = 265,                 /* callconv  */
  YYSYMBOL_cases = 266,                    /* cases  */
  YYSYMBOL_case = 267,                     /* case  */
  YYSYMBOL_enums = 268,                    /* enums  */
  YYSYMBOL_enum_list = 269,                /* enum_list  */
  YYSYMBOL_enum_member = 270,              /* enum_member  */
  YYSYMBOL_enum = 271,                     /* enum  */
  YYSYMBOL_enumdef = 272,                  /* enumdef  */
  YYSYMBOL_m_exprs = 273,                  /* m_exprs  */
  YYSYMBOL_m_expr = 274,                   /* m_expr  */
  YYSYMBOL_expr = 275,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 276,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 277,           /* expr_int_const  */
  YYSYMBOL_expr_const = 278,               /* expr_const  */
  YYSYMBOL_fields = 279,                   /* fields  */
  YYSYMBOL_field = 280,                    /* field  */
  YYSYMBOL_ne_union_field = 281,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 282,          /* ne_union_fields  */
  YYSYMBOL_union_field = 283,              /* union_field  */
  YYSYMBOL_s_field = 284,                  /* s_field  */
  YYSYMBOL_funcdef = 285,                  /* funcdef  */
  YYSYMBOL_declaration = 286,              /* declaration  */
  YYSYMBOL_m_ident = 287,                  /* m_ident  */
  YYSYMBOL_m_typename = 288,               /* m_typename  */
  YYSYMBOL_typename = 289,                 /* typename  */
  YYSYMBOL_ident = 290,                    /* ident  */
  YYSYMBOL_base_type = 291,                /* base_type  */
  YYSYMBOL_m_int = 292,                    /* m_int  */
  YYSYMBOL_int_std = 293,                  /* int_std  */
  YYSYMBOL_qualified_seq = 294,            /* qualified_seq  */
  YYSYMBOL_295_3 = 295,                    /* $@3  */
  YYSYMBOL_qualified_type = 296,           /* qualified_type  */
  YYSYMBOL_297_4 = 297,                    /* $@4  */
  YYSYMBOL_coclass = 298,                  /* coclass  */
  YYSYMBOL_coclassdef = 299,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 300,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 301,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 302,              /* apicontract  */
  YYSYMBOL_apicontract_def = 303,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 304,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 305,         /* class_interfaces  */
  YYSYMBOL_class_interface = 306,          /* class_interface  */
  YYSYMBOL_dispinterface = 307,            /* dispinterface  */
  YYSYMBOL_dispattributes = 308,           /* dispattributes  */
  YYSYMBOL_dispint_props = 309,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 310,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 311,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 312,                  /* inherit  */
  YYSYMBOL_interface = 313,                /* interface  */
  YYSYMBOL_interfacedef = 314,             /* interfacedef  */
  YYSYMBOL_interfaceref = 315,             /* interfaceref  */
  YYSYMBOL_module = 316,                   /* module  */
  YYSYMBOL_moduledef = 317,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 318,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 319,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 320,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 321,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 322,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 323,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 324,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 325,               /* declarator  */
  YYSYMBOL_direct_declarator = 326,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 327,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 328, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 329,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 330, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 331,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 332, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 333,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 334,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 335,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 336,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 337,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 338,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 339,          /* init_declarator  */
  YYSYMBOL_threading_type = 340,           /* threading_type  */
  YYSYMBOL_pointer_type = 341,             /* pointer_type  */
  YYSYMBOL_structdef = 342,                /* structdef  */
  YYSYMBOL_type = 343,                     /* type  */
  YYSYMBOL_typedef = 344,                  /* typedef  */
  YYSYMBOL_uniondef = 345,                 /* uniondef  */
  YYSYMBOL_version = 346,                  /* version  */
  YYSYMBOL_acf_statements = 347,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 348,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 349,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 350,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 351,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 352,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 353,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 354,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 355           /* allocate_option  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3585

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  125
/* YYNRULES -- Number of rules.  */
#define YYNRULES  446
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  802

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   461


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   215,     2,     2,     2,   214,   207,     2,
     228,   229,   212,   211,   202,   210,   222,   213,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   204,   227,
     208,   230,   209,   203,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   223,     2,   224,   206,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,   205,   226,   216,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   217,   218,   219,
     220,   221
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   337,   337,   351,   351,   353,   354,   354,   356,   357,
     358,   359,   362,   365,   366,   368,   369,   371,   372,   373,
     376,   377,   378,   379,   379,   381,   382,   383,   386,   387,
     389,   390,   392,   393,   394,   395,   398,   399,   402,   403,
     407,   408,   409,   410,   411,   412,   413,   416,   427,   428,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   443,
     445,   453,   459,   463,   465,   469,   473,   474,   477,   478,
     481,   482,   486,   491,   498,   502,   503,   506,   507,   511,
     514,   515,   516,   519,   520,   524,   525,   526,   530,   531,
     534,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   657,
     658,   663,   664,   665,   666,   669,   670,   673,   677,   683,
     684,   685,   688,   692,   704,   709,   713,   718,   721,   722,
     725,   726,   729,   730,   731,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     768,   770,   771,   774,   775,   778,   784,   790,   791,   794,
     799,   806,   807,   810,   811,   815,   816,   819,   823,   829,
     837,   841,   846,   847,   850,   851,   854,   855,   858,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     874,   875,   878,   879,   880,   881,   882,   883,   884,   885,
     886,   890,   891,   891,   895,   896,   896,   899,   902,   906,
     909,   913,   916,   920,   921,   924,   925,   929,   932,   935,
     938,   939,   942,   943,   947,   949,   953,   954,   957,   960,
     966,   969,   973,   974,   977,   980,   985,   986,   987,   991,
     995,   998,   999,  1002,  1003,  1007,  1008,  1012,  1013,  1014,
    1018,  1020,  1021,  1025,  1026,  1027,  1028,  1033,  1035,  1036,
    1041,  1043,  1047,  1048,  1053,  1054,  1055,  1056,  1060,  1068,
    1070,  1071,  1076,  1078,  1082,  1083,  1090,  1091,  1092,  1093,
    1094,  1098,  1105,  1106,  1109,  1110,  1113,  1120,  1121,  1126,
    1127,  1131,  1132,  1133,  1134,  1135,  1136,  1140,  1141,  1142,
    1145,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1160,  1167,  1169,  1175,  1176,  1177,  1181,  1182,  1186,
    1187,  1191,  1198,  1207,  1208,  1212,  1213,  1217,  1219,  1220,
    1221,  1225,  1226,  1231,  1232,  1233,  1234
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "aIDENTIFIER",
  "aPRAGMA", "aKNOWNTYPE", "aNAMESPACE", "aNUM", "aHEXNUM", "aDOUBLE",
  "aSTRING", "aWSTRING", "aSQSTRING", "aUUID", "aEOF", "aACF", "SHL",
  "SHR", "MEMBERPTR", "EQUALITY", "INEQUALITY", "GREATEREQUAL",
  "LESSEQUAL", "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tAGGREGATABLE",
  "tAGILE", "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT",
  "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE",
  "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK",
  "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE",
  "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEVENTADD", "tEVENTREMOVE", "tEXCLUSIVETO",
  "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL", "tFAULTSTATUS",
  "tFLAGS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE",
  "tMETHODS", "tMODULE", "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE",
  "tNONCREATABLE", "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG",
  "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL",
  "tOUT", "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT",
  "tPRAGMA_WARNING", "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT",
  "tPROPPUTREF", "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY",
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tRESTRICTED",
  "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT", "tSIGNED",
  "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTANDARD",
  "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT",
  "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS",
  "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
  "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG",
  "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT",
  "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'", "'['", "']'",
  "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept", "input", "m_acf",
  "gbl_statements", "$@1", "imp_statements", "$@2", "int_statements",
  "semicolon_opt", "statement", "pragma_warning", "warnings", "typedecl",
  "cppquote", "import_start", "import", "importlib", "libraryhdr",
  "library_start", "librarydef", "m_args", "arg_list", "args", "arg",
  "array", "m_attributes", "attributes", "attrib_list", "str_list",
  "marshaling_behavior", "contract_ver", "contract_req", "attribute",
  "uuid_string", "callconv", "cases", "case", "enums", "enum_list",
  "enum_member", "enum", "enumdef", "m_exprs", "m_expr", "expr",
  "expr_list_int_const", "expr_int_const", "expr_const", "fields", "field",
  "ne_union_field", "ne_union_fields", "union_field", "s_field", "funcdef",
  "declaration", "m_ident", "m_typename", "typename", "ident", "base_type",
  "m_int", "int_std", "qualified_seq", "$@3", "qualified_type", "$@4",
  "coclass", "coclassdef", "runtimeclass", "runtimeclass_def",
  "apicontract", "apicontract_def", "namespacedef", "class_interfaces",
  "class_interface", "dispinterface", "dispattributes", "dispint_props",
  "dispint_meths", "dispinterfacedef", "inherit", "interface",
  "interfacedef", "interfaceref", "module", "moduledef",
  "storage_cls_spec", "function_specifier", "type_qualifier",
  "m_type_qual_list", "decl_spec", "m_decl_spec_no_type",
  "decl_spec_no_type", "declarator", "direct_declarator",
  "abstract_declarator", "abstract_declarator_no_direct",
  "m_abstract_declarator", "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version",
  "acf_statements", "acf_int_statements", "acf_int_statement",
  "acf_interface", "acf_attributes", "acf_attribute_list", "acf_attribute",
  "allocate_option_list", "allocate_option", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,    44,    63,    58,   124,    94,    38,    60,    62,
      45,    43,    42,    47,    37,    33,   126,   457,   458,   459,
     460,   461,    46,    91,    93,   123,   125,    59,    40,    41,
      61
};
#endif

#define YYPACT_NINF (-617)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-434)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -617,    99,  1980,  -617,  -617,  -617,   -29,   -64,    95,  -617,
    -617,  -617,    95,  -617,   -79,    95,  -617,   103,  -617,  -617,
    -617,  -617,    49,   154,  -617,  -617,  -617,  -617,  -617,    95,
      49,   140,   -27,  -617,    95,   -22,    49,   530,  -617,  -617,
     236,   269,   530,  -617,  -617,  3389,  -617,  -617,  -617,   -12,
    -617,  -617,  -617,  -617,  -617,    37,  3001,    -4,    26,  -617,
    -617,  -617,    36,  -617,    46,  -617,    67,  -617,    34,    68,
     218,    73,    96,  -617,  -617,    91,    91,    91,   172,  3234,
     102,    91,   114,   115,  -617,    57,  -617,   -64,   232,  -617,
    -617,  -617,  -617,   336,  -617,    88,   134,  -617,  -617,  -617,
     135,  -617,  -617,  -617,  -617,   366,  -617,  3234,  -617,  -617,
     106,   148,   -93,  -122,  -617,  -617,   146,  -617,  -617,   165,
    -617,  -617,  -617,   166,   171,  -617,  -617,  -617,  -617,  -617,
     173,   174,  -617,   175,  -617,  -617,  -617,  -617,   181,  -617,
    -617,  -617,   183,  -617,  -617,  -617,   184,   187,  -617,  -617,
     190,  -617,  -617,  -617,  -617,  -617,   191,   193,   196,   198,
     201,  -617,   202,  -617,  -617,   204,  -617,   211,  -617,  -617,
     212,   213,  -617,  -617,   214,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,  -617,  -617,   215,  -617,  -617,  -617,
     216,   217,  -617,  -617,  -617,  -617,  -617,  -617,   220,  -617,
    -617,   221,  -617,  -617,  -617,   222,  -617,  -617,  -617,   223,
     225,   226,   227,  -617,  -617,  -617,   228,   229,  -617,  -617,
     230,   231,   234,   -61,  -617,  -617,  -617,  2153,  1077,   159,
     334,    95,    95,   360,   365,   195,   233,   238,   239,   241,
     248,   245,   172,   244,   246,  -617,  -617,  -617,  -617,  -617,
    -617,   250,  -617,  -617,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,   172,   172,  -617,  -617,   247,  -136,
    -617,  -617,  -617,    91,  -617,  -617,  -617,   383,   251,  -617,
    -617,  -617,   -46,  -617,  -617,   475,   254,   -66,  -617,   278,
     255,  -617,   257,  -617,   477,   192,    95,   533,  3122,   479,
     192,   533,   499,   501,   533,  3122,   533,   505,   506,   533,
     507,   533,   533,  2644,   533,   533,    50,   509,   -62,   512,
     533,  3234,   533,   533,  3234,   -73,  3234,  3234,   192,   282,
     513,  3234,  3389,   302,  -617,   299,  -617,  -617,  -617,   301,
    -617,   303,  -617,   304,  -617,   308,   307,   310,  -617,  -617,
      73,  3122,  -617,   313,  -617,  -617,   313,   -92,  -617,  -617,
    -617,   309,   265,   314,  -617,  -617,  -617,   -32,   104,   317,
    -617,   533,   110,  2644,  -617,  -617,   326,  -617,  -617,    48,
      57,  -617,   324,  -617,    95,   327,   352,   328,  -617,   550,
    -617,    -9,   159,    55,   331,  -617,  -617,   332,   333,  -617,
    -617,  -617,  -617,  -617,  -617,  -617,  -617,  -617,   335,  -617,
     533,   533,   533,   533,   533,   533,   890,  2852,   -98,  -617,
     338,   363,   347,   341,   372,  2852,   348,   349,  -617,   -63,
     350,   351,   355,   357,   359,   362,   364,   367,   589,   369,
    3122,   107,   370,   -58,  -617,  2852,  -617,  -617,  -617,   371,
     373,   374,   385,   379,   387,   -48,   735,   388,  -617,  -617,
    -617,  -617,  -617,  -617,   390,   391,   392,   393,   354,  -617,
     395,   405,   406,  -617,  3389,   579,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,   172,    60,    83,    73,   376,  -617,  -617,
    1496,  1363,   434,   -49,   416,  -617,  -617,  -617,  -617,   340,
    -617,  2637,   417,   443,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,   -47,  -617,  -617,   412,  -617,  -617,   101,   533,  -617,
      27,  -617,  3122,  -617,  3122,   418,  -617,   424,  -617,   425,
    -617,  -617,  -617,  3122,    29,    29,    29,    29,    29,    29,
     805,   476,   533,   533,   650,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   651,   533,   533,  -617,  -617,   479,   648,  -617,
     533,  -617,  -617,   646,  -617,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  -617,  -617,  -617,   107,  -617,  2281,  -617,   107,
    -617,  -617,  -617,  -133,  -617,   533,  -617,  -617,  -617,  -617,
    -617,   533,  -617,  -617,  -617,  -617,  -617,  -617,  -617,  -617,
     652,  -617,  -617,  -617,  -617,   429,  -617,  -617,   458,    73,
      25,  -617,    73,  -617,   558,  1617,    73,  -617,  3122,  -617,
    -617,   460,   439,  1859,   444,  -617,  -617,  -617,  2523,   383,
      48,  -617,   446,   445,   412,  -617,  -617,  -617,  -617,   107,
     447,   172,   169,    95,  -617,  -617,   476,  -617,  -617,  2402,
    -617,   476,  -617,   448,  -126,   224,   224,  -617,   167,   167,
     194,   194,  2684,  2804,  2770,  1071,   828,  1899,   194,   194,
     144,   144,    29,    29,    29,  -617,  2748,  -617,  -617,  -617,
     449,  -617,  -617,    52,  -617,   450,   107,   451,  -617,  2644,
    -617,  -617,   452,  -617,    73,  1220,   172,  -617,    95,    95,
     455,  -617,  -617,    73,  -617,  -617,  -617,  -617,  3122,   459,
    -617,  -617,  -617,  -617,  -617,  -617,   667,  -617,  -617,   471,
    -617,    -5,  -617,  -617,   462,  -617,   456,   253,  -617,   461,
     107,   463,  -617,   533,  2644,  -617,   533,  -617,  -617,  -617,
      52,  -617,  -617,  -617,   465,  -617,  -617,  -617,  -617,  -617,
    -617,  -617,  1738,  -617,  -617,   464,   533,  -617,   107,  -617,
    -617,  -617,  -617,    52,  -617,  -617,  -617,    29,   466,  2852,
    -617,  -617,    73,  -617,  -617,  -617,    -8,  -617,  -617,  -617,
     533,   492,  -617,  -617,   497,   -23,   -23,  -617,  -617,   481,
    -617,  -617
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    45,   314,     0,   427,     0,   297,
     289,   308,     0,   350,     0,     0,   296,   284,   298,   346,
     295,   299,   300,     0,   349,   302,   309,   310,   307,     0,
     300,     0,     0,   348,     0,     0,   300,     0,   304,   347,
     284,   284,   294,   411,   290,    91,     2,    19,    46,     0,
      40,    20,    43,    20,    18,     0,    78,   414,     0,   413,
     291,   412,     0,    12,     0,    16,     0,    14,     0,     0,
       0,    38,     0,    10,    17,   355,   355,   355,     0,     0,
     416,   355,     0,   418,   315,     0,     4,   427,     0,   286,
     287,   321,   317,     0,   328,   415,     0,   285,   301,   306,
       0,   338,   305,   323,   324,     0,   319,     0,   303,   292,
     417,     0,   419,     0,   293,    92,     0,    94,    95,     0,
      96,    97,    98,     0,     0,   101,   102,   103,   104,   105,
       0,     0,   108,     0,   110,   111,   112,   113,     0,   115,
     116,   117,     0,   119,   120,   121,     0,     0,   124,   125,
       0,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,   137,     0,   139,   140,     0,   142,     0,   144,   145,
     148,     0,   149,   150,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   164,   165,   166,
       0,     0,   169,   170,   171,   172,   409,   173,     0,   175,
     407,     0,   177,   178,   179,     0,   181,   182,   183,     0,
       0,     0,     0,   188,   408,   189,     0,     0,   193,   194,
       0,     0,     0,     0,    80,   198,    41,    77,    77,    77,
     284,     0,     0,   284,   284,     0,   414,     0,     0,     0,
     336,     0,     0,   416,   418,    42,    11,    15,    13,     6,
       9,     0,    39,   341,     8,   359,   356,   358,   357,   201,
     202,   203,   204,   351,     0,     0,   288,   363,   399,   362,
     281,   414,   416,   355,   418,   353,    44,     0,     0,   439,
     438,   440,     0,   435,   428,     0,     0,    77,    60,     0,
       0,   267,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    79,    61,     0,    33,    34,    35,     0,
      27,     0,    31,     0,    29,     0,     0,     0,    25,    32,
      38,     0,    78,   415,    63,   344,   417,   419,    64,   325,
     325,     0,     0,     0,    36,   280,     5,     0,     0,     0,
     361,     0,     0,    66,   365,   354,     0,   311,   316,     0,
       0,   434,     0,    59,     0,     0,   211,   216,   212,     0,
     420,    77,    77,    77,     0,   200,   199,     0,     0,   231,
     222,   223,   224,   228,   229,   230,   225,   226,     0,   227,
       0,     0,     0,     0,     0,     0,     0,   265,     0,   263,
       0,     0,    88,     0,     0,   266,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,     0,   218,   221,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   406,   401,
     402,   403,   404,   405,     0,     0,     0,     0,   424,   426,
       0,     0,     0,    81,    91,     0,    26,    30,    28,    23,
      22,    21,    65,     0,    77,    77,    38,     0,   337,    36,
      77,    77,     0,    77,     0,   352,   360,   364,   400,     0,
      76,     0,     0,    70,    67,    68,   312,   445,   443,   446,
     444,     0,   441,   436,   429,   214,   217,    77,     0,    48,
       0,   410,     0,   268,     0,     0,   422,    78,   274,     0,
      93,   192,    99,     0,   255,   254,   253,   256,   251,   252,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   106,     0,     0,   107,
       0,   114,   118,     0,   122,   123,   126,   132,   133,   134,
     135,   136,   138,   141,   143,   384,   351,    66,   389,   384,
     386,   385,    73,   381,   147,   220,   146,   151,   163,   167,
     168,     0,   176,   180,   184,   185,   187,   186,   190,   191,
       0,   195,   196,   197,    82,     0,    20,   392,   421,    38,
       0,   326,    38,   322,     0,    77,    38,    37,    78,     7,
     330,     0,     0,     0,     0,    75,    74,   366,     0,     0,
       0,   437,   433,     0,   429,   213,   215,    49,    47,     0,
     418,     0,   416,   282,   272,   271,   372,   262,   351,    66,
     376,   372,   373,     0,   369,   244,   245,   257,   238,   239,
     242,   243,   233,   234,     0,   235,   236,   237,   241,   240,
     247,   246,   249,   250,   248,   258,     0,   264,    90,    89,
       0,    84,    72,   384,   351,     0,   384,     0,   380,    66,
     388,   219,     0,   425,    38,    77,     0,   318,     0,     0,
       0,   320,    36,    38,   345,   332,   331,   334,     0,     0,
     279,   335,    71,    69,   313,   442,     0,   432,   430,   394,
     397,     0,   270,   277,     0,   283,     0,   372,   351,     0,
     384,     0,   368,     0,    66,   375,     0,   261,   109,   379,
     384,   390,   383,   387,     0,   174,    62,    24,   393,   343,
     342,   327,    77,   339,   333,     0,     0,   396,     0,   269,
     205,   260,   367,   384,   377,   371,   374,   259,     0,   232,
     382,   391,    38,   431,   395,   398,     0,   370,   378,   340,
       0,     0,   423,   206,     0,    77,    77,   276,   208,     0,
     207,   275
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -617,  -617,  -617,   344,  -617,   -50,  -617,  -458,  -321,     8,
    -617,  -617,  -617,  -617,  -617,    78,  -617,  -617,  -617,    14,
    -523,  -617,  -617,  -283,  -233,  -224,    -2,  -617,  -617,  -617,
     139,  -617,  -267,  -158,   -69,  -617,  -617,  -617,  -617,  -617,
     199,     2,   396,   118,   361,  -617,  -261,  -266,  -617,  -617,
    -617,  -617,   -81,  -314,  -617,    84,  -617,    32,     3,   -56,
    -617,    58,   108,    80,  -617,   358,  -617,     6,    15,    10,
      17,    11,    19,    21,   368,  -617,    12,  -617,  -617,  -617,
    -617,  -617,     5,    22,  -617,  -617,    23,  -617,  -617,  -340,
    -547,   -55,   -35,    -6,  -238,  -617,  -617,  -617,  -576,  -617,
    -616,  -617,  -386,  -617,  -617,  -617,   -45,  -617,   480,  -617,
     403,     0,   -39,  -617,     4,  -617,   637,    81,  -617,  -617,
      85,  -617,   346,  -617,    89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    46,     2,   366,   227,   616,   490,   253,   336,
      48,   520,    49,    50,    51,    52,   337,   235,    53,   338,
     502,   503,   504,   505,   588,    55,   352,   223,   429,   449,
     423,   420,   224,   397,   589,   786,   793,   385,   386,   387,
     388,   271,   443,   444,   417,   418,   419,   426,   391,   523,
     528,   393,   798,   799,   719,    58,   734,    96,   266,   590,
      59,    99,    60,   378,   639,    61,   277,   339,   340,   341,
     342,   343,   344,   345,   484,   621,   346,    70,   493,   633,
      71,   363,   347,   348,   710,   241,   349,    75,    76,    77,
     368,    78,   255,    79,   268,   269,   662,   741,   663,   664,
     591,   697,   592,   593,   618,   767,   730,   731,   270,   464,
     225,   272,    81,    82,   274,   470,    86,   643,   644,    87,
      88,   282,   283,   511,   512
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   242,    80,   228,    57,   351,    83,    72,    62,   265,
      47,    91,    64,    66,    69,    92,    54,    63,    94,    65,
      97,    67,   267,    68,    73,    74,   369,   370,   495,   482,
     439,   625,   101,   729,   647,   790,   374,   106,   430,   693,
     273,   257,   258,    97,    97,   432,   275,   544,   435,  -433,
     437,   791,   458,   442,   292,    89,   243,    90,   236,   453,
     244,   240,   237,   384,   695,   473,   238,   239,   290,   256,
     256,   256,   111,   113,   631,   256,   507,   446,   525,   529,
     736,    29,   251,  -286,  -286,   742,   278,   372,   102,   196,
     372,   708,   373,   200,   108,   699,   259,   372,    89,     3,
      90,    13,   744,   293,   564,   498,    95,    89,    90,    90,
      89,   737,    90,   399,   492,   279,   508,   400,   401,   402,
     403,   404,   405,   214,   459,   460,   461,   462,   463,   280,
     496,   565,  -286,  -286,   -55,   260,   739,   281,   709,   573,
      13,   332,   424,   103,   595,   109,   104,   750,   259,    93,
     114,   259,   729,    13,   595,   640,   380,    45,    98,    85,
    -209,   772,   544,   333,   100,   623,   574,   522,   524,   524,
     467,   596,    19,   265,    45,    89,   754,    90,   381,   632,
     447,   603,   641,   542,   543,   544,   267,   260,   547,   548,
     260,   773,   406,    84,   261,   265,   265,   768,    24,   692,
      45,   105,   395,   698,   797,   396,   107,   614,   267,   267,
     542,   543,   544,   509,    45,   226,   259,   521,   792,   229,
     448,   778,   769,   -50,   262,    56,    56,    80,    80,    57,
      57,    83,    83,    97,   354,   355,    97,    97,   375,   110,
     398,    90,   544,   421,   407,   617,   261,    33,   510,   261,
     431,   562,   563,   245,   762,   260,   648,   646,   441,   249,
     620,   620,    39,   246,   586,   111,   113,   256,   487,   524,
       5,     6,   112,   247,    90,   372,   262,   408,    45,   262,
     587,   526,   454,    45,    15,   457,   619,   465,   466,   468,
     469,   409,   472,   384,   248,   250,   483,   259,   707,   265,
     252,   711,    13,   687,   690,   714,    45,   749,   660,   622,
     752,   440,   267,  -286,   261,   -51,   263,   410,   441,   586,
     411,   412,   499,   254,    45,   414,   415,  -210,   515,   -52,
     372,  -286,   264,   -53,   500,   587,   260,   353,   416,    90,
     702,   276,   -54,   399,   262,   285,   286,   400,   401,   402,
     403,   404,   405,   495,   775,   723,   559,   560,   561,   287,
     700,   541,   288,   356,   780,    90,   562,   563,   357,   289,
      90,   440,   494,   291,   294,   555,   556,   557,   558,   559,
     560,   561,    45,   756,   263,   585,   376,   787,   377,   562,
     563,   527,   763,   295,   296,   261,  -278,   495,  -278,   297,
     264,   298,   299,   300,   557,   558,   559,   560,   561,   301,
     495,   302,   303,   733,   265,   304,   562,   563,   305,   306,
     358,   307,   406,   660,   308,   262,   309,   267,   660,   310,
     311,   745,   312,   495,   557,   558,   559,   560,   561,   313,
     314,   315,   316,   317,   318,   319,   562,   563,   320,   321,
     322,   323,   362,   324,   325,   326,   327,   328,   329,   330,
     -56,   789,   331,   359,   360,   658,   361,   649,   758,   651,
     364,   -57,   661,   -58,   407,   367,   372,   371,   656,   379,
     382,   659,   389,   383,   390,   392,   422,   394,   628,    56,
      80,    80,    57,    57,    83,    83,    72,    62,   627,    47,
     784,    64,    66,    69,   660,    54,    63,   408,    65,   427,
      67,   428,    68,    73,    74,   433,   434,   436,   696,   450,
     259,   409,   452,   471,   652,   474,   650,   475,   476,   794,
     477,   478,   441,   479,   480,   486,   399,   481,  -286,   489,
     400,   401,   402,   403,   404,   405,   497,   410,   506,   514,
     411,   412,   413,   516,   517,   414,   415,   519,   518,   260,
     530,   531,   532,   533,   635,   567,   705,   566,   416,   568,
     569,   524,   524,   242,   570,    11,   610,   571,   572,   575,
     576,   601,   265,   441,   577,   440,   578,   661,   579,   615,
     740,   580,   661,   581,   642,   267,   582,   735,   584,   594,
     597,   624,   598,   599,   441,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   600,   406,   602,   605,   261,   606,
     607,   608,   609,   628,   611,    80,    22,    57,   243,    83,
     236,   718,   244,   627,   612,   613,   440,   265,   630,    25,
      26,    27,    28,   634,   441,   638,   637,   653,   262,    30,
     267,   654,   655,   667,   685,   689,   691,   440,   704,   703,
     706,    23,   425,   242,   715,   425,   716,   407,   661,    85,
     721,   727,   765,   438,   732,   766,   445,   743,   748,   751,
     753,   755,   761,   445,   456,   771,   764,   770,   658,   441,
     774,   783,   776,    36,   781,   788,   795,   440,    38,   372,
     408,   796,   712,    56,   659,    80,   688,    57,   801,    83,
     491,   759,   760,   701,   409,   800,   645,   720,   455,   724,
     488,   451,   365,   785,   284,   728,   513,   726,   485,   725,
       0,     0,   425,   501,     0,     0,     0,     0,     0,     0,
     410,     0,   440,   411,   412,   413,     0,     0,   414,   415,
       0,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     628,   416,    80,     0,    57,     0,    83,     0,     0,     0,
     627,   534,   535,   536,   537,   538,   539,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   551,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,     0,     0,     0,     0,     0,     0,
       0,   562,   563,     0,     0,     0,     0,     0,   583,     0,
       0,   542,   543,   544,   545,   546,   547,   548,   549,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   542,   543,   544,   545,   546,   547,
     548,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     5,     6,   400,   401,   402,
     403,   404,   405,   665,   666,     0,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,     0,   686,     0,     0,     9,     0,    10,
       0,   425,     0,     0,     0,    11,     0,     0,   551,    13,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
       0,     0,     0,     0,     0,     0,   445,   562,   563,    16,
       0,     0,     0,     0,   604,   230,    18,     0,     0,     0,
       0,    19,   406,     0,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,    25,
      26,    27,    28,     0,     0,     0,     0,     0,   551,    30,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
       0,     0,     0,     0,   407,     0,     0,   562,   563,     0,
       0,     0,     0,     0,   657,   554,   555,   556,   557,   558,
     559,   560,   561,     0,     0,     0,    33,     0,     0,     0,
     562,   563,    35,    36,    37,     0,     0,   408,    38,     0,
       0,    39,     0,     0,     0,   233,     0,     0,     0,     0,
       0,   409,     0,     0,   234,     0,    42,     0,     0,     0,
       0,     4,     5,     6,    43,    44,     0,   542,   543,   544,
     545,   546,   547,   548,     0,     0,     0,   410,     0,     0,
     411,   412,   413,     0,   777,   414,   415,   779,     8,     0,
       0,     0,     0,     0,     9,     0,    10,     0,   416,     0,
       0,     0,    11,    12,     0,     0,    13,   425,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,   335,     0,     0,    24,     0,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     4,     5,     6,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,    34,    35,
      36,    37,     0,     0,     0,    38,     0,     0,    39,     0,
       0,     8,    40,     0,     0,     0,     0,     9,     0,    10,
       0,    41,     0,    42,     0,    11,    12,     0,     0,    13,
       0,    43,    44,     0,     0,     0,    14,   553,   554,   555,
     556,   557,   558,   559,   560,   561,    15,     0,     0,    16,
       0,     0,     0,   562,   563,    17,    18,     0,     0,     0,
      45,    19,     0,   350,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,   335,     0,     0,    24,     0,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     4,     5,     6,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,    39,     0,     0,     8,    40,     0,     0,     0,     0,
       9,     0,    10,     0,    41,     0,    42,     0,    11,    12,
       0,     0,    13,     0,    43,    44,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,     0,    45,    19,     0,   757,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      24,     0,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     9,    39,    10,     0,     0,    40,     0,
       0,    11,     0,     0,     0,    13,     0,    41,     0,    42,
       0,     0,    14,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,     0,     0,    21,    45,     0,     0,   629,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    24,     0,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     9,     0,    10,     0,    35,    36,
      37,     0,    11,     0,    38,     0,    13,    39,     0,     0,
       0,    40,     0,    14,     0,     0,     0,     0,     0,     0,
      41,     0,    42,     0,     0,     0,    16,     0,     0,     0,
      43,    44,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,    45,
      23,     0,   626,     0,    24,     0,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     9,     0,    10,     0,    35,
      36,    37,     0,    11,     0,    38,     0,    13,    39,     0,
       0,     0,    40,     0,    14,     0,     0,     0,     0,     0,
       0,    41,     0,    42,     0,     0,     0,    16,     0,     0,
       0,    43,    44,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
      45,    23,     0,   713,     0,    24,     0,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     9,     0,    10,     0,
      35,    36,    37,     0,    11,     0,    38,     0,    13,    39,
       0,     0,     0,    40,     0,   542,   543,   544,   545,   546,
     547,   548,    41,     0,    42,     0,     0,     0,    16,     0,
       0,     0,    43,    44,   230,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,    45,     0,     0,   782,     0,    24,     0,    25,    26,
      27,    28,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,    33,     0,     9,     0,    10,
       0,    35,    36,    37,     0,    11,    12,    38,     0,    13,
      39,     0,     0,     0,   233,     0,    14,     0,     0,     0,
       0,     0,     0,   234,     0,    42,    15,     0,     0,    16,
       0,     0,     0,    43,    44,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,    45,    23,     0,   717,     0,    24,     0,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,   555,   556,   557,
     558,   559,   560,   561,     0,     0,     0,     0,     0,     0,
       0,   562,   563,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,    39,     0,     0,     0,    40,     0,     4,     5,     6,
       0,     0,   -77,     0,    41,     0,    42,   334,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    11,    12,
       0,     0,    13,    45,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,   335,     0,     0,
      24,     0,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    34,    35,    36,    37,     9,     0,
      10,    38,     0,     0,    39,   259,    11,     0,    40,     0,
      13,     0,     0,     0,     0,     0,     0,    41,     0,    42,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
      16,     0,     0,     0,     0,     0,   230,    18,     0,     0,
       0,     0,    19,     0,   260,     0,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,    45,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     9,
       0,    10,     0,    35,    36,    37,   259,    11,     0,    38,
       0,    13,    39,   262,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    42,     0,     0,
       0,    16,     0,     0,     0,    43,    44,   230,    18,     0,
       0,     0,     0,    19,     0,   260,     0,     0,    20,     0,
       0,    21,     0,   694,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,    24,
       0,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       9,     0,    10,     0,    35,    36,    37,     0,    11,     0,
      38,     0,    13,    39,   262,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   234,     0,    42,     0,
       0,     0,    16,     0,     0,     0,    43,    44,   230,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
       0,     0,    21,     0,   738,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     5,
       6,     0,     0,   542,   543,   544,   545,   546,   547,   548,
     549,   550,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     9,     0,    10,     0,    35,    36,    37,     0,    11,
       0,    38,     0,    13,    39,     0,     0,     0,   233,     0,
     542,   543,   544,   545,   546,   547,   548,   234,   550,    42,
       0,     0,     0,    16,     0,     0,     0,    43,    44,   230,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,    24,     0,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,    30,   542,   543,   544,   545,   546,   547,
     548,   549,   550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,   544,   545,
     546,   547,   548,   549,   550,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,    38,     0,     0,    39,     0,     0,     0,   233,
     542,   543,   544,   545,   546,   547,   548,     0,   234,     0,
      42,     0,     0,     0,     0,     0,     0,     0,    43,    44,
     551,     0,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,     0,     0,     0,     0,     0,     0,     0,   562,
     563,   636,     0,     0,     0,     0,     0,    45,   542,   543,
     544,   545,   546,   547,   548,   549,   550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,     0,
       0,     0,     0,     0,     0,     0,   562,   563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   551,     0,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,     0,     0,     0,     0,     0,     0,     0,
     562,   563,   747,   551,   746,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,     0,     0,     0,     0,     0,
       0,     0,   562,   563,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,     0,
       0,     0,     0,     0,     0,     0,   562,   563,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,   551,     0,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,  -329,     0,     0,
      16,     0,     0,     0,   562,   563,   230,    18,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      25,    26,    27,    28,    29,     0,     0,   231,     0,     0,
      30,     0,     0,     0,     0,   232,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     9,
       0,    10,    34,    35,    36,    37,     0,    11,     0,    38,
       0,    13,    39,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,    42,     0,     0,
       0,    16,     0,     0,     0,    43,    44,   230,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,     0,
       0,    21,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,    25,    26,    27,    28,     0,     0,     0,     0,     5,
       6,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,     0,     0,     0,     0,    33,    11,
       0,     0,     0,     0,    35,    36,    37,     0,     0,     0,
      38,     0,     0,    39,     0,     0,     0,   233,     0,     0,
       0,     0,     0,    16,     0,     0,   234,     0,    42,   230,
      18,     0,     0,     0,     0,     0,    43,    44,     0,     0,
      20,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,   115,     0,     0,   234,   116,
      42,   117,   118,   119,   120,   121,     0,   122,    43,    44,
     123,     0,   124,     0,     0,     0,   125,   126,     0,   127,
     128,   129,   130,   131,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,   142,     0,     0,   143,
     144,   145,   146,   147,     0,     0,   148,   149,   150,   151,
       0,     0,     0,   152,   153,     0,   154,   155,     0,   156,
     157,   158,   159,   160,   161,     0,   162,   163,   164,   165,
     166,   167,     0,     0,   168,     0,     0,   169,     0,     0,
       0,     0,     0,   170,   171,     0,   172,   173,     0,   174,
     175,   176,     0,     0,     0,     0,   177,   178,   179,     0,
     180,   181,   182,     0,   183,   184,   185,   186,   187,   188,
     189,     0,   190,     0,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,   201,   202,   203,   204,
       0,     0,     0,     0,     0,   205,     0,     0,   206,     0,
       0,     0,   207,   208,     0,     0,   209,   210,   211,   212,
       0,     0,   213,     0,   214,     0,   215,   216,   217,   218,
     219,   220,   221,     0,     0,   222
};

static const yytype_int16 yycheck[] =
{
       2,    56,     2,    53,     2,   229,     2,     2,     2,    78,
       2,     8,     2,     2,     2,    12,     2,     2,    15,     2,
      17,     2,    78,     2,     2,     2,   264,   265,   368,   350,
     313,   489,    29,   649,     7,    43,   269,    34,   304,   586,
      79,    76,    77,    40,    41,   306,    81,    18,   309,   113,
     311,    59,   125,   314,   176,     3,    56,     5,    56,   320,
      56,    56,    56,   287,   587,   332,    56,    56,   107,    75,
      76,    77,    40,    41,   123,    81,    28,    27,   392,   393,
     656,   113,    70,   176,   176,   661,    29,   223,    30,   151,
     223,    66,   228,   155,    36,   228,    44,   223,     3,     0,
       5,    49,   228,   225,   202,   371,     3,     3,     5,     5,
       3,   658,     5,     3,   146,    58,    68,     7,     8,     9,
      10,    11,    12,   185,   197,   198,   199,   200,   201,    72,
     368,   229,   225,   225,   227,    83,   659,    80,   113,   202,
      49,   202,   300,     3,   202,    37,     6,   694,    44,   228,
      42,    44,   768,    49,   202,   202,   202,   223,   109,   223,
     226,   737,    18,   224,    10,   486,   229,   391,   392,   393,
     328,   229,    81,   242,   223,     3,   699,     5,   224,   493,
     130,   229,   229,    16,    17,    18,   242,    83,    21,    22,
      83,   738,    82,   222,   142,   264,   265,   202,   107,   585,
     223,   228,    10,   589,   227,    13,   228,   474,   264,   265,
      16,    17,    18,   165,   223,   227,    44,   226,   226,   182,
     170,   744,   227,   227,   172,   227,   228,   227,   228,   227,
     228,   227,   228,   230,   231,   232,   233,   234,   273,     3,
     296,     5,    18,   298,   134,   483,   142,   156,   200,   142,
     305,   222,   223,   227,   712,    83,   229,   518,   313,   225,
     484,   485,   171,   227,   212,   233,   234,   273,     3,   493,
       5,     6,     3,   227,     5,   223,   172,   167,   223,   172,
     228,   226,   321,   223,    66,   324,   226,   326,   327,     7,
       8,   181,   331,   517,   227,   227,   351,    44,   619,   368,
     227,   622,    49,   564,   570,   626,   223,   693,   541,   226,
     696,   313,   368,   225,   142,   227,   212,   207,   373,   212,
     210,   211,   212,   227,   223,   215,   216,   226,   384,   227,
     223,   225,   228,   227,   224,   228,    83,     3,   228,     5,
     601,   227,   227,     3,   172,   113,    10,     7,     8,     9,
      10,    11,    12,   693,   740,   638,   212,   213,   214,   225,
     593,   416,   227,     3,   750,     5,   222,   223,     3,     3,
       5,   373,   367,   225,   228,   208,   209,   210,   211,   212,
     213,   214,   223,   704,   212,   440,     3,   773,     5,   222,
     223,   393,   713,   228,   228,   142,   227,   737,   229,   228,
     228,   228,   228,   228,   210,   211,   212,   213,   214,   228,
     750,   228,   228,   651,   483,   228,   222,   223,   228,   228,
     225,   228,    82,   656,   228,   172,   228,   483,   661,   228,
     228,   664,   228,   773,   210,   211,   212,   213,   214,   228,
     228,   228,   228,   228,   228,   228,   222,   223,   228,   228,
     228,   228,   204,   228,   228,   228,   228,   228,   228,   228,
     227,   782,   228,   225,   225,   212,   225,   522,   706,   524,
     225,   227,   541,   227,   134,   225,   223,   230,   533,   228,
       5,   228,   204,   229,   229,   228,     7,    10,   490,   491,
     490,   491,   490,   491,   490,   491,   491,   491,   490,   491,
     766,   491,   491,   491,   737,   491,   491,   167,   491,    10,
     491,    10,   491,   491,   491,    10,    10,    10,   587,    10,
      44,   181,    10,    10,   524,   223,   522,   228,   227,   790,
     227,   227,   587,   225,   227,   226,     3,   227,   225,   225,
       7,     8,     9,    10,    11,    12,   229,   207,   222,   225,
     210,   211,   212,   226,   202,   215,   216,     7,   230,    83,
     229,   229,   229,   228,   224,   202,   616,   229,   228,   222,
     229,   795,   796,   628,   202,    45,   222,   229,   229,   229,
     229,   202,   651,   638,   229,   587,   229,   656,   229,    10,
     659,   229,   661,   229,   182,   651,   229,   653,   229,   229,
     229,   225,   229,   229,   659,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   229,    82,   229,   229,   142,   229,
     229,   229,   229,   625,   229,   625,    96,   625,   628,   625,
     628,   633,   628,   625,   229,   229,   638,   706,   204,   109,
     110,   111,   112,   227,   699,   202,   229,   229,   172,   119,
     706,   227,   227,     3,     3,     7,    10,   659,   229,     7,
     202,   103,   301,   718,   204,   304,   227,   134,   737,   223,
     226,   226,     5,   312,   227,   204,   315,   229,   229,   229,
     229,   229,   227,   322,   323,   229,   227,   225,   212,   744,
     229,   227,   229,   163,   229,   229,   204,   699,   168,   223,
     167,   204,   624,   705,   228,   705,   567,   705,   227,   705,
     366,   708,   709,   595,   181,   796,   517,   633,   322,   639,
     362,   318,   242,   768,    87,   644,   380,   642,   360,   640,
      -1,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,   744,   210,   211,   212,    -1,    -1,   215,   216,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     762,   228,   762,    -1,   762,    -1,   762,    -1,    -1,    -1,
     762,   410,   411,   412,   413,   414,   415,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,   223,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,   542,   543,    -1,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,    -1,   563,    -1,    -1,    37,    -1,    39,
      -1,   570,    -1,    -1,    -1,    45,    -1,    -1,   203,    49,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,    -1,    -1,    -1,    -1,    -1,   595,   222,   223,    69,
      -1,    -1,    -1,    -1,   229,    75,    76,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,   203,   119,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,    -1,    -1,    -1,   134,    -1,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,   229,   207,   208,   209,   210,   211,
     212,   213,   214,    -1,    -1,    -1,   156,    -1,    -1,    -1,
     222,   223,   162,   163,   164,    -1,    -1,   167,   168,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,    -1,    -1,   184,    -1,   186,    -1,    -1,    -1,
      -1,     4,     5,     6,   194,   195,    -1,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   207,    -1,    -1,
     210,   211,   212,    -1,   743,   215,   216,   746,    31,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    -1,   228,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,   766,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,   104,    -1,    -1,   107,    -1,   109,   110,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,   164,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,    31,   175,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,   184,    -1,   186,    -1,    45,    46,    -1,    -1,    49,
      -1,   194,   195,    -1,    -1,    -1,    56,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    66,    -1,    -1,    69,
      -1,    -1,    -1,   222,   223,    75,    76,    -1,    -1,    -1,
     223,    81,    -1,   226,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,   107,    -1,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,    31,   175,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,   184,    -1,   186,    -1,    45,    46,
      -1,    -1,    49,    -1,   194,   195,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,   223,    81,    -1,   226,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
     107,    -1,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    -1,    -1,
      -1,   168,    -1,    37,   171,    39,    -1,    -1,   175,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,   184,    -1,   186,
      -1,    -1,    56,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,   223,    -1,    -1,   226,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      -1,    -1,    -1,   107,    -1,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    37,    -1,    39,    -1,   162,   163,
     164,    -1,    45,    -1,   168,    -1,    49,   171,    -1,    -1,
      -1,   175,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,    -1,    -1,    -1,    69,    -1,    -1,    -1,
     194,   195,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,   223,
     103,    -1,   226,    -1,   107,    -1,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    37,    -1,    39,    -1,   162,
     163,   164,    -1,    45,    -1,   168,    -1,    49,   171,    -1,
      -1,    -1,   175,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,    -1,    -1,    -1,    69,    -1,    -1,
      -1,   194,   195,    75,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,
     223,   103,    -1,   226,    -1,   107,    -1,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    37,    -1,    39,    -1,
     162,   163,   164,    -1,    45,    -1,   168,    -1,    49,   171,
      -1,    -1,    -1,   175,    -1,    16,    17,    18,    19,    20,
      21,    22,   184,    -1,   186,    -1,    -1,    -1,    69,    -1,
      -1,    -1,   194,   195,    75,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   223,    -1,    -1,   226,    -1,   107,    -1,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,   156,    -1,    37,    -1,    39,
      -1,   162,   163,   164,    -1,    45,    46,   168,    -1,    49,
     171,    -1,    -1,    -1,   175,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,   186,    66,    -1,    -1,    69,
      -1,    -1,    -1,   194,   195,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,   223,   103,    -1,   226,    -1,   107,    -1,   109,
     110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   208,   209,   210,
     211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,   223,    -1,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,     4,     5,     6,
      -1,    -1,   182,    -1,   184,    -1,   186,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    49,   223,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,    -1,    -1,
     107,    -1,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,   164,    37,    -1,
      39,   168,    -1,    -1,   171,    44,    45,    -1,   175,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    83,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,   223,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    37,
      -1,    39,    -1,   162,   163,   164,    44,    45,    -1,   168,
      -1,    49,   171,   172,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,    -1,
      -1,    69,    -1,    -1,    -1,   194,   195,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    83,    -1,    -1,    86,    -1,
      -1,    89,    -1,   212,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,   107,
      -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      37,    -1,    39,    -1,   162,   163,   164,    -1,    45,    -1,
     168,    -1,    49,   171,   172,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
      -1,    -1,    69,    -1,    -1,    -1,   194,   195,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,   212,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
     107,    -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    37,    -1,    39,    -1,   162,   163,   164,    -1,    45,
      -1,   168,    -1,    49,   171,    -1,    -1,    -1,   175,    -1,
      16,    17,    18,    19,    20,    21,    22,   184,    24,   186,
      -1,    -1,    -1,    69,    -1,    -1,    -1,   194,   195,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,   107,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,    -1,   175,
      16,    17,    18,    19,    20,    21,    22,    -1,   184,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
     203,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,
     223,   224,    -1,    -1,    -1,    -1,    -1,   223,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     222,   223,   224,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   222,   223,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,   203,    -1,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,    66,    -1,    -1,
      69,    -1,    -1,    -1,   222,   223,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    37,
      -1,    39,   161,   162,   163,   164,    -1,    45,    -1,   168,
      -1,    49,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,    -1,
      -1,    69,    -1,    -1,    -1,   194,   195,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,     5,
       6,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,   156,    45,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,    -1,   175,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,   184,    -1,   186,    75,
      76,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,    -1,   175,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,   184,    30,
     186,    32,    33,    34,    35,    36,    -1,    38,   194,   195,
      41,    -1,    43,    -1,    -1,    -1,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    -1,    -1,    84,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,   117,   118,    -1,   120,
     121,   122,    -1,    -1,    -1,    -1,   127,   128,   129,    -1,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,   140,
     141,    -1,   143,    -1,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,   166,    -1,    -1,   169,    -1,
      -1,    -1,   173,   174,    -1,    -1,   177,   178,   179,   180,
      -1,    -1,   183,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   232,   234,     0,     4,     5,     6,    15,    31,    37,
      39,    45,    46,    49,    56,    66,    69,    75,    76,    81,
      86,    89,    96,   103,   107,   109,   110,   111,   112,   113,
     119,   126,   144,   156,   161,   162,   163,   164,   168,   171,
     175,   184,   186,   194,   195,   223,   233,   240,   241,   243,
     244,   245,   246,   249,   250,   256,   257,   272,   286,   291,
     293,   296,   298,   299,   300,   301,   302,   303,   304,   307,
     308,   311,   313,   314,   317,   318,   319,   320,   322,   324,
     342,   343,   344,   345,   222,   223,   347,   350,   351,     3,
       5,   289,   289,   228,   289,     3,   288,   289,   109,   292,
      10,   289,   292,     3,     6,   228,   289,   228,   292,   293,
       3,   288,     3,   288,   293,    26,    30,    32,    33,    34,
      35,    36,    38,    41,    43,    47,    48,    50,    51,    52,
      53,    54,    55,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    67,    70,    71,    72,    73,    74,    77,    78,
      79,    80,    84,    85,    87,    88,    90,    91,    92,    93,
      94,    95,    97,    98,    99,   100,   101,   102,   105,   108,
     114,   115,   117,   118,   120,   121,   122,   127,   128,   129,
     131,   132,   133,   135,   136,   137,   138,   139,   140,   141,
     143,   145,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   157,   158,   159,   160,   166,   169,   173,   174,   177,
     178,   179,   180,   183,   185,   187,   188,   189,   190,   191,
     192,   193,   196,   258,   263,   341,   227,   236,   236,   182,
      75,   116,   124,   175,   184,   248,   272,   298,   300,   302,
     313,   316,   322,   342,   345,   227,   227,   227,   227,   225,
     227,   307,   227,   239,   227,   323,   324,   323,   323,    44,
      83,   142,   172,   212,   228,   265,   289,   290,   325,   326,
     339,   272,   342,   343,   345,   323,   227,   297,    29,    58,
      72,    80,   352,   353,   347,   113,    10,   225,   227,     3,
     343,   225,   176,   225,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   202,   224,    14,   104,   240,   247,   250,   298,
     299,   300,   301,   302,   303,   304,   307,   313,   314,   317,
     226,   256,   257,     3,   289,   289,     3,     3,   225,   225,
     225,   225,   204,   312,   225,   339,   235,   225,   321,   325,
     325,   230,   223,   228,   255,   323,     3,     5,   294,   228,
     202,   224,     5,   229,   256,   268,   269,   270,   271,   204,
     229,   279,   228,   282,    10,    10,    13,   264,   290,     3,
       7,     8,     9,    10,    11,    12,    82,   134,   167,   181,
     207,   210,   211,   212,   215,   216,   228,   275,   276,   277,
     262,   322,     7,   261,   264,   275,   278,    10,    10,   259,
     278,   322,   277,    10,    10,   277,    10,   277,   275,   254,
     257,   322,   277,   273,   274,   275,    27,   130,   170,   260,
      10,   341,    10,   277,   343,   273,   275,   343,   125,   197,
     198,   199,   200,   201,   340,   343,   343,   264,     7,     8,
     346,    10,   343,   263,   223,   228,   227,   227,   227,   225,
     227,   227,   239,   322,   305,   305,   226,     3,   296,   225,
     238,   234,   146,   309,   313,   320,   325,   229,   278,   212,
     224,   275,   251,   252,   253,   254,   222,    28,    68,   165,
     200,   354,   355,   353,   225,   290,   226,   202,   230,     7,
     242,   226,   256,   280,   256,   284,   226,   257,   281,   284,
     229,   229,   229,   228,   275,   275,   275,   275,   275,   275,
     275,   322,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   203,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   222,   223,   202,   229,   229,   202,   222,   229,
     202,   229,   229,   202,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   322,   212,   228,   255,   265,
     290,   331,   333,   334,   229,   202,   229,   229,   229,   229,
     229,   202,   229,   229,   229,   229,   229,   229,   229,   229,
     222,   229,   229,   229,   263,    10,   237,   325,   335,   226,
     256,   306,   226,   239,   225,   238,   226,   240,   257,   226,
     204,   123,   284,   310,   227,   224,   224,   229,   202,   295,
     202,   229,   182,   348,   349,   271,   277,     7,   229,   322,
     345,   322,   342,   229,   227,   227,   322,   229,   212,   228,
     255,   265,   327,   329,   330,   275,   275,     3,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,     3,   275,   277,   261,     7,
     278,    10,   333,   321,   212,   251,   265,   332,   333,   228,
     255,   274,   277,     7,   229,   236,   202,   239,    66,   113,
     315,   239,   246,   226,   239,   204,   227,   226,   257,   285,
     286,   226,    25,   254,   294,   355,   351,   226,   348,   331,
     337,   338,   227,   325,   287,   290,   329,   321,   212,   251,
     265,   328,   329,   229,   228,   255,   204,   224,   229,   333,
     321,   229,   333,   229,   251,   229,   239,   226,   325,   289,
     289,   227,   238,   239,   227,     5,   204,   336,   202,   227,
     225,   229,   329,   321,   229,   333,   229,   275,   251,   275,
     333,   229,   226,   227,   278,   337,   266,   333,   229,   239,
      43,    59,   226,   267,   277,   204,   204,   227,   283,   284,
     283,   227
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   231,   232,   233,   233,   234,   235,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     236,   236,   236,   237,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   241,   242,   242,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   251,   252,   252,
     253,   253,   254,   254,   255,   255,   255,   256,   256,   257,
     258,   258,   258,   259,   259,   260,   260,   260,   261,   261,
     262,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   264,
     264,   265,   265,   265,   265,   266,   266,   267,   267,   268,
     268,   268,   269,   269,   270,   271,   271,   272,   273,   273,
     274,   274,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   276,   276,   277,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   285,
     286,   286,   287,   287,   288,   288,   289,   289,   290,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   294,   295,   294,   296,   297,   296,   298,   299,   300,
     301,   302,   303,   304,   304,   305,   305,   306,   307,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   313,   314,
     314,   314,   315,   315,   316,   317,   318,   318,   318,   319,
     320,   321,   321,   322,   322,   323,   323,   324,   324,   324,
     325,   325,   325,   326,   326,   326,   326,   327,   327,   327,
     328,   328,   329,   329,   330,   330,   330,   330,   330,   331,
     331,   331,   332,   332,   333,   333,   334,   334,   334,   334,
     334,   334,   335,   335,   336,   336,   337,   338,   338,   339,
     339,   340,   340,   340,   340,   340,   340,   341,   341,   341,
     342,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   344,   345,   345,   346,   346,   346,   347,   347,   348,
     348,   349,   350,   351,   351,   352,   352,   353,   353,   353,
     353,   354,   354,   355,   355,   355,   355
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     3,     3,
       2,     3,     2,     3,     2,     3,     2,     2,     2,     2,
       0,     3,     3,     0,     6,     2,     3,     2,     3,     2,
       3,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       1,     2,     1,     2,     1,     2,     2,     2,     2,     4,
       3,     3,     5,     2,     3,     4,     0,     1,     1,     3,
       1,     3,     3,     2,     3,     3,     2,     0,     1,     3,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     3,
       3,     0,     1,     4,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     1,     4,     4,     1,     6,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     4,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     1,     4,     1,
       1,     4,     1,     4,     1,     1,     4,     4,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     1,     6,     1,     4,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     4,     3,     0,
       2,     1,     1,     3,     2,     3,     1,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       5,     4,     3,     1,     3,     1,     1,     0,     2,     4,
       3,     2,     2,     0,     2,     2,     1,     3,     2,     1,
       3,     2,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     0,     4,     1,     0,     4,     2,     6,     2,
       6,     2,     5,     2,     2,     0,     2,     3,     2,     1,
       2,     3,     2,     3,     6,     6,     0,     2,     2,     7,
       9,     2,     2,     2,     2,     6,     1,     1,     1,     1,
       1,     0,     2,     2,     3,     0,     1,     2,     2,     2,
       3,     2,     1,     1,     3,     2,     4,     3,     2,     1,
       3,     2,     0,     1,     3,     2,     1,     3,     4,     3,
       2,     1,     3,     2,     0,     1,     1,     3,     2,     1,
       3,     4,     1,     3,     0,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       4,     5,     5,    10,     1,     3,     1,     0,     2,     0,
       2,     4,     6,     0,     3,     1,     3,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: gbl_statements m_acf  */
#line 337 "tools/widl/parser.y"
                                                { check_statements((yyvsp[-1].stmt_list), FALSE);
						  check_all_user_types((yyvsp[-1].stmt_list));
						  write_header((yyvsp[-1].stmt_list));
						  write_id_data((yyvsp[-1].stmt_list));
						  write_proxies((yyvsp[-1].stmt_list));
						  write_client((yyvsp[-1].stmt_list));
						  write_server((yyvsp[-1].stmt_list));
						  write_regscript((yyvsp[-1].stmt_list));
						  write_typelib_regscript((yyvsp[-1].stmt_list));
						  write_dlldata((yyvsp[-1].stmt_list));
						  write_local_stubs((yyvsp[-1].stmt_list));
						}
#line 3307 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 353 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3313 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 354 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3319 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 355 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3325 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interface ';'  */
#line 356 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3331 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 357 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3337 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements interfacedef  */
#line 358 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3343 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclass ';'  */
#line 359 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3351 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements coclassdef  */
#line 362 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3359 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements apicontract ';'  */
#line 365 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3365 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements apicontract_def  */
#line 366 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3372 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 368 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3378 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 369 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3385 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements moduledef  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3391 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements librarydef  */
#line 372 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3397 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements statement  */
#line 373 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3403 "tools/widl/parser.tab.c"
    break;

  case 20: /* imp_statements: %empty  */
#line 376 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3409 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements interface ';'  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3415 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements dispinterface ';'  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3421 "tools/widl/parser.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 379 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3427 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 380 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3433 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements interfacedef  */
#line 381 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3439 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: imp_statements coclass ';'  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3445 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements coclassdef  */
#line 383 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3453 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: imp_statements apicontract ';'  */
#line 386 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3459 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements apicontract_def  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3466 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements runtimeclass ';'  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3472 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements runtimeclass_def  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3479 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements moduledef  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3485 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements statement  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3491 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements importlib  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3497 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements librarydef  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3503 "tools/widl/parser.tab.c"
    break;

  case 36: /* int_statements: %empty  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3509 "tools/widl/parser.tab.c"
    break;

  case 37: /* int_statements: int_statements statement  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3515 "tools/widl/parser.tab.c"
    break;

  case 40: /* statement: cppquote  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3521 "tools/widl/parser.tab.c"
    break;

  case 41: /* statement: typedecl ';'  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3527 "tools/widl/parser.tab.c"
    break;

  case 42: /* statement: declaration ';'  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3533 "tools/widl/parser.tab.c"
    break;

  case 43: /* statement: import  */
#line 410 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3539 "tools/widl/parser.tab.c"
    break;

  case 44: /* statement: typedef ';'  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3545 "tools/widl/parser.tab.c"
    break;

  case 45: /* statement: aPRAGMA  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3551 "tools/widl/parser.tab.c"
    break;

  case 46: /* statement: pragma_warning  */
#line 413 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3557 "tools/widl/parser.tab.c"
    break;

  case 47: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 417 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3569 "tools/widl/parser.tab.c"
    break;

  case 48: /* warnings: aNUM  */
#line 427 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3575 "tools/widl/parser.tab.c"
    break;

  case 49: /* warnings: warnings aNUM  */
#line 428 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3581 "tools/widl/parser.tab.c"
    break;

  case 51: /* typedecl: tENUM aIDENTIFIER  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3587 "tools/widl/parser.tab.c"
    break;

  case 53: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 435 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3593 "tools/widl/parser.tab.c"
    break;

  case 55: /* typedecl: tUNION aIDENTIFIER  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3599 "tools/widl/parser.tab.c"
    break;

  case 56: /* typedecl: attributes enumdef  */
#line 438 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3605 "tools/widl/parser.tab.c"
    break;

  case 57: /* typedecl: attributes structdef  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3611 "tools/widl/parser.tab.c"
    break;

  case 58: /* typedecl: attributes uniondef  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3617 "tools/widl/parser.tab.c"
    break;

  case 59: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 443 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3623 "tools/widl/parser.tab.c"
    break;

  case 60: /* import_start: tIMPORT aSTRING ';'  */
#line 445 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3634 "tools/widl/parser.tab.c"
    break;

  case 61: /* import: import_start imp_statements aEOF  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3643 "tools/widl/parser.tab.c"
    break;

  case 62: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 460 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3649 "tools/widl/parser.tab.c"
    break;

  case 63: /* libraryhdr: tLIBRARY typename  */
#line 463 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3655 "tools/widl/parser.tab.c"
    break;

  case 64: /* library_start: attributes libraryhdr '{'  */
#line 465 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3663 "tools/widl/parser.tab.c"
    break;

  case 65: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 470 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3669 "tools/widl/parser.tab.c"
    break;

  case 66: /* m_args: %empty  */
#line 473 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3675 "tools/widl/parser.tab.c"
    break;

  case 68: /* arg_list: arg  */
#line 477 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3681 "tools/widl/parser.tab.c"
    break;

  case 69: /* arg_list: arg_list ',' arg  */
#line 478 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3687 "tools/widl/parser.tab.c"
    break;

  case 71: /* args: arg_list ',' ELLIPSIS  */
#line 482 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3693 "tools/widl/parser.tab.c"
    break;

  case 72: /* arg: attributes decl_spec m_any_declarator  */
#line 486 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3703 "tools/widl/parser.tab.c"
    break;

  case 73: /* arg: decl_spec m_any_declarator  */
#line 491 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 74: /* array: '[' expr ']'  */
#line 498 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3722 "tools/widl/parser.tab.c"
    break;

  case 75: /* array: '[' '*' ']'  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3728 "tools/widl/parser.tab.c"
    break;

  case 76: /* array: '[' ']'  */
#line 503 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3734 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_attributes: %empty  */
#line 506 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3740 "tools/widl/parser.tab.c"
    break;

  case 79: /* attributes: '[' attrib_list ']'  */
#line 511 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3746 "tools/widl/parser.tab.c"
    break;

  case 80: /* attrib_list: attribute  */
#line 514 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3752 "tools/widl/parser.tab.c"
    break;

  case 81: /* attrib_list: attrib_list ',' attribute  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3758 "tools/widl/parser.tab.c"
    break;

  case 82: /* attrib_list: attrib_list ']' '[' attribute  */
#line 516 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3764 "tools/widl/parser.tab.c"
    break;

  case 83: /* str_list: aSTRING  */
#line 519 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3770 "tools/widl/parser.tab.c"
    break;

  case 84: /* str_list: str_list ',' aSTRING  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3776 "tools/widl/parser.tab.c"
    break;

  case 85: /* marshaling_behavior: tAGILE  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3782 "tools/widl/parser.tab.c"
    break;

  case 86: /* marshaling_behavior: tNONE  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3788 "tools/widl/parser.tab.c"
    break;

  case 87: /* marshaling_behavior: tSTANDARD  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3794 "tools/widl/parser.tab.c"
    break;

  case 88: /* contract_ver: aNUM  */
#line 530 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3800 "tools/widl/parser.tab.c"
    break;

  case 89: /* contract_ver: aNUM '.' aNUM  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3806 "tools/widl/parser.tab.c"
    break;

  case 90: /* contract_req: decl_spec ',' contract_ver  */
#line 534 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3816 "tools/widl/parser.tab.c"
    break;

  case 91: /* attribute: %empty  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3822 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: tAGGREGATABLE  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3828 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3834 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tAPPOBJECT  */
#line 543 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3840 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tASYNC  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3846 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tAUTOHANDLE  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3852 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tBINDABLE  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3858 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tBROADCAST  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3864 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tCALLAS '(' ident ')'  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3870 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3876 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tCODE  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3882 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tCOMMSTATUS  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3888 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tCONTEXTHANDLE  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3894 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3900 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3906 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3912 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3918 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tCONTROL  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3924 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 558 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3930 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tDECODE  */
#line 559 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3936 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tDEFAULT  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3942 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tDEFAULTBIND  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3948 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tDEFAULTCOLLELEM  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3954 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3960 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tDEFAULTVTABLE  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3966 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3972 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tDISPLAYBIND  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3978 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3984 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tDUAL  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3990 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tENABLEALLOCATE  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3996 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tENCODE  */
#line 570 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4002 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tENDPOINT '(' str_list ')'  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4008 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tENTRY '(' expr_const ')'  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4014 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tEVENTADD  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4020 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tEVENTREMOVE  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4026 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 575 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4034 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tEXPLICITHANDLE  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4040 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tFAULTSTATUS  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4046 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tFLAGS  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4052 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tFORCEALLOCATE  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4058 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tHANDLE  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4064 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4070 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4076 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4082 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 586 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4088 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4094 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tHIDDEN  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4100 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tID '(' expr_int_const ')'  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4106 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tIDEMPOTENT  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4112 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tIGNORE  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4118 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tIIDIS '(' expr ')'  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4124 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tIMMEDIATEBIND  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4130 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4136 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tIN  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4142 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tINPUTSYNC  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4148 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4154 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tLCID '(' expr_int_const ')'  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4160 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tLCID  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4166 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tLICENSED  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4172 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tLOCAL  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4178 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4184 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tMAYBE  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4190 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tMESSAGE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4196 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tNOCODE  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4202 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tNONBROWSABLE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4208 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tNONCREATABLE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4214 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tNONEXTENSIBLE  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4220 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tNOTIFY  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4226 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tNOTIFYFLAG  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4232 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tOBJECT  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4238 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tODL  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4244 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tOLEAUTOMATION  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4250 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4256 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tOPTIONAL  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4262 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tOUT  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4268 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tPARTIALIGNORE  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4274 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4280 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tPROGID '(' aSTRING ')'  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4286 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tPROPGET  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4292 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tPROPPUT  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4298 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tPROPPUTREF  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4304 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tPROXY  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4310 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tPUBLIC  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4316 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 627 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4324 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tREADONLY  */
#line 630 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4330 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tREPRESENTAS '(' type ')'  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4336 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tREQUESTEDIT  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4342 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tRESTRICTED  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4348 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tRETVAL  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4354 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4360 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tSOURCE  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4366 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4372 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tSTRING  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4378 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tSWITCHIS '(' expr ')'  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4384 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4390 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tTRANSMITAS '(' type ')'  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4396 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tTHREADING '(' threading_type ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4402 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tUIDEFAULT  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4408 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tUSESGETLASTERROR  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4414 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4420 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tUUID '(' uuid_string ')'  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4426 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4432 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tV1ENUM  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4438 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tVARARG  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4444 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tVERSION '(' version ')'  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4450 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4456 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4462 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: pointer_type  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4468 "tools/widl/parser.tab.c"
    break;

  case 200: /* uuid_string: aSTRING  */
#line 658 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4476 "tools/widl/parser.tab.c"
    break;

  case 201: /* callconv: tCDECL  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4482 "tools/widl/parser.tab.c"
    break;

  case 202: /* callconv: tFASTCALL  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4488 "tools/widl/parser.tab.c"
    break;

  case 203: /* callconv: tPASCAL  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4494 "tools/widl/parser.tab.c"
    break;

  case 204: /* callconv: tSTDCALL  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4500 "tools/widl/parser.tab.c"
    break;

  case 205: /* cases: %empty  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4506 "tools/widl/parser.tab.c"
    break;

  case 206: /* cases: cases case  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4512 "tools/widl/parser.tab.c"
    break;

  case 207: /* case: tCASE expr_int_const ':' union_field  */
#line 673 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4521 "tools/widl/parser.tab.c"
    break;

  case 208: /* case: tDEFAULT ':' union_field  */
#line 677 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4530 "tools/widl/parser.tab.c"
    break;

  case 209: /* enums: %empty  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4536 "tools/widl/parser.tab.c"
    break;

  case 210: /* enums: enum_list ','  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4542 "tools/widl/parser.tab.c"
    break;

  case 212: /* enum_list: enum  */
#line 688 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4551 "tools/widl/parser.tab.c"
    break;

  case 213: /* enum_list: enum_list ',' enum  */
#line 692 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
                                                  {
                                                    var_t *last = LIST_ENTRY( list_tail((yyval.var_list)), var_t, entry );
                                                    enum expr_type type = EXPR_NUM;
                                                    if (last->eval->type == EXPR_HEXNUM) type = EXPR_HEXNUM;
                                                    if (last->eval->cval + 1 < 0) type = EXPR_HEXNUM;
                                                    (yyvsp[0].var)->eval = make_exprl(type, last->eval->cval + 1);
                                                  }
                                                  (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) );
						}
#line 4566 "tools/widl/parser.tab.c"
    break;

  case 214: /* enum_member: m_attributes ident  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4574 "tools/widl/parser.tab.c"
    break;

  case 215: /* enum: enum_member '=' expr_int_const  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4583 "tools/widl/parser.tab.c"
    break;

  case 216: /* enum: enum_member  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4591 "tools/widl/parser.tab.c"
    break;

  case 217: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4597 "tools/widl/parser.tab.c"
    break;

  case 218: /* m_exprs: m_expr  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4603 "tools/widl/parser.tab.c"
    break;

  case 219: /* m_exprs: m_exprs ',' m_expr  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4609 "tools/widl/parser.tab.c"
    break;

  case 220: /* m_expr: %empty  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4615 "tools/widl/parser.tab.c"
    break;

  case 222: /* expr: aNUM  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4621 "tools/widl/parser.tab.c"
    break;

  case 223: /* expr: aHEXNUM  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4627 "tools/widl/parser.tab.c"
    break;

  case 224: /* expr: aDOUBLE  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4633 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: tFALSE  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4639 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: tNULL  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4645 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: tTRUE  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4651 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: aSTRING  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4657 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: aWSTRING  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4663 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: aSQSTRING  */
#line 737 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4669 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: aIDENTIFIER  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4675 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: expr '?' expr ':' expr  */
#line 739 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4681 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: expr LOGICALOR expr  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4687 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: expr LOGICALAND expr  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4693 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '|' expr  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4699 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: expr '^' expr  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4705 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: expr '&' expr  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4711 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: expr EQUALITY expr  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4717 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: expr INEQUALITY expr  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4723 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: expr '>' expr  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4729 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: expr '<' expr  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4735 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr GREATEREQUAL expr  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4741 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr LESSEQUAL expr  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4747 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr SHL expr  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4753 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: expr SHR expr  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4759 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr '+' expr  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4765 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr '-' expr  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4771 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr '%' expr  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4777 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '*' expr  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4783 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr '/' expr  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4789 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: '!' expr  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4795 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: '~' expr  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4801 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: '+' expr  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4807 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: '-' expr  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4813 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: '&' expr  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4819 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: '*' expr  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4825 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4831 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '.' aIDENTIFIER  */
#line 765 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4837 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4843 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 769 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4849 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '[' expr ']'  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4855 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: '(' expr ')'  */
#line 771 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4861 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr_list_int_const: expr_int_const  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4867 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 775 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4873 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr_int_const: expr  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4882 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr_const: expr  */
#line 784 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4891 "tools/widl/parser.tab.c"
    break;

  case 267: /* fields: %empty  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4897 "tools/widl/parser.tab.c"
    break;

  case 268: /* fields: fields field  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4903 "tools/widl/parser.tab.c"
    break;

  case 269: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 795 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4912 "tools/widl/parser.tab.c"
    break;

  case 270: /* field: m_attributes uniondef ';'  */
#line 799 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4921 "tools/widl/parser.tab.c"
    break;

  case 271: /* ne_union_field: s_field ';'  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4927 "tools/widl/parser.tab.c"
    break;

  case 272: /* ne_union_field: attributes ';'  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4933 "tools/widl/parser.tab.c"
    break;

  case 273: /* ne_union_fields: %empty  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4939 "tools/widl/parser.tab.c"
    break;

  case 274: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4945 "tools/widl/parser.tab.c"
    break;

  case 275: /* union_field: s_field ';'  */
#line 815 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4951 "tools/widl/parser.tab.c"
    break;

  case 276: /* union_field: ';'  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4957 "tools/widl/parser.tab.c"
    break;

  case 277: /* s_field: m_attributes decl_spec declarator  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4966 "tools/widl/parser.tab.c"
    break;

  case 278: /* s_field: m_attributes structdef  */
#line 823 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4975 "tools/widl/parser.tab.c"
    break;

  case 279: /* funcdef: declaration  */
#line 829 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4985 "tools/widl/parser.tab.c"
    break;

  case 280: /* declaration: attributes decl_spec init_declarator  */
#line 838 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4993 "tools/widl/parser.tab.c"
    break;

  case 281: /* declaration: decl_spec init_declarator  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5001 "tools/widl/parser.tab.c"
    break;

  case 282: /* m_ident: %empty  */
#line 846 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5007 "tools/widl/parser.tab.c"
    break;

  case 284: /* m_typename: %empty  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5013 "tools/widl/parser.tab.c"
    break;

  case 288: /* ident: typename  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5019 "tools/widl/parser.tab.c"
    break;

  case 289: /* base_type: tBYTE  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5025 "tools/widl/parser.tab.c"
    break;

  case 290: /* base_type: tWCHAR  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5031 "tools/widl/parser.tab.c"
    break;

  case 292: /* base_type: tSIGNED int_std  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5037 "tools/widl/parser.tab.c"
    break;

  case 293: /* base_type: tUNSIGNED int_std  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5043 "tools/widl/parser.tab.c"
    break;

  case 294: /* base_type: tUNSIGNED  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5049 "tools/widl/parser.tab.c"
    break;

  case 295: /* base_type: tFLOAT  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5055 "tools/widl/parser.tab.c"
    break;

  case 296: /* base_type: tDOUBLE  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5061 "tools/widl/parser.tab.c"
    break;

  case 297: /* base_type: tBOOLEAN  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5067 "tools/widl/parser.tab.c"
    break;

  case 298: /* base_type: tERRORSTATUST  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5073 "tools/widl/parser.tab.c"
    break;

  case 299: /* base_type: tHANDLET  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5079 "tools/widl/parser.tab.c"
    break;

  case 302: /* int_std: tINT  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5085 "tools/widl/parser.tab.c"
    break;

  case 303: /* int_std: tSHORT m_int  */
#line 879 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5091 "tools/widl/parser.tab.c"
    break;

  case 304: /* int_std: tSMALL  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5097 "tools/widl/parser.tab.c"
    break;

  case 305: /* int_std: tLONG m_int  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5103 "tools/widl/parser.tab.c"
    break;

  case 306: /* int_std: tHYPER m_int  */
#line 882 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5109 "tools/widl/parser.tab.c"
    break;

  case 307: /* int_std: tINT64  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5115 "tools/widl/parser.tab.c"
    break;

  case 308: /* int_std: tCHAR  */
#line 884 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5121 "tools/widl/parser.tab.c"
    break;

  case 309: /* int_std: tINT32  */
#line 885 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5127 "tools/widl/parser.tab.c"
    break;

  case 310: /* int_std: tINT3264  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5133 "tools/widl/parser.tab.c"
    break;

  case 311: /* qualified_seq: aKNOWNTYPE  */
#line 890 "tools/widl/parser.y"
                      { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5139 "tools/widl/parser.tab.c"
    break;

  case 312: /* $@3: %empty  */
#line 891 "tools/widl/parser.y"
                      { push_lookup_namespace((yyvsp[-1].str)); }
#line 5145 "tools/widl/parser.tab.c"
    break;

  case 313: /* qualified_seq: aIDENTIFIER '.' $@3 qualified_seq  */
#line 891 "tools/widl/parser.y"
                                                                   { (yyval.type) = (yyvsp[0].type); }
#line 5151 "tools/widl/parser.tab.c"
    break;

  case 314: /* qualified_type: aKNOWNTYPE  */
#line 895 "tools/widl/parser.y"
                     { (yyval.type) = find_type_or_error((yyvsp[0].str)); }
#line 5157 "tools/widl/parser.tab.c"
    break;

  case 315: /* $@4: %empty  */
#line 896 "tools/widl/parser.y"
                     { init_lookup_namespace((yyvsp[-1].str)); }
#line 5163 "tools/widl/parser.tab.c"
    break;

  case 316: /* qualified_type: aNAMESPACE '.' $@4 qualified_seq  */
#line 896 "tools/widl/parser.y"
                                                                  { (yyval.type) = (yyvsp[0].type); }
#line 5169 "tools/widl/parser.tab.c"
    break;

  case 317: /* coclass: tCOCLASS typename  */
#line 899 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5175 "tools/widl/parser.tab.c"
    break;

  case 318: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5181 "tools/widl/parser.tab.c"
    break;

  case 319: /* runtimeclass: tRUNTIMECLASS typename  */
#line 906 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5187 "tools/widl/parser.tab.c"
    break;

  case 320: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 910 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5193 "tools/widl/parser.tab.c"
    break;

  case 321: /* apicontract: tAPICONTRACT typename  */
#line 913 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5199 "tools/widl/parser.tab.c"
    break;

  case 322: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 917 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5205 "tools/widl/parser.tab.c"
    break;

  case 323: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 920 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5211 "tools/widl/parser.tab.c"
    break;

  case 324: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5217 "tools/widl/parser.tab.c"
    break;

  case 325: /* class_interfaces: %empty  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5223 "tools/widl/parser.tab.c"
    break;

  case 326: /* class_interfaces: class_interfaces class_interface  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5229 "tools/widl/parser.tab.c"
    break;

  case 327: /* class_interface: m_attributes interfaceref ';'  */
#line 929 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[-1].type)); (yyval.ifref)->attrs = (yyvsp[-2].attr_list); }
#line 5235 "tools/widl/parser.tab.c"
    break;

  case 328: /* dispinterface: tDISPINTERFACE typename  */
#line 932 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5241 "tools/widl/parser.tab.c"
    break;

  case 329: /* dispattributes: attributes  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5247 "tools/widl/parser.tab.c"
    break;

  case 330: /* dispint_props: tPROPERTIES ':'  */
#line 938 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5253 "tools/widl/parser.tab.c"
    break;

  case 331: /* dispint_props: dispint_props s_field ';'  */
#line 939 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5259 "tools/widl/parser.tab.c"
    break;

  case 332: /* dispint_meths: tMETHODS ':'  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5265 "tools/widl/parser.tab.c"
    break;

  case 333: /* dispint_meths: dispint_meths funcdef ';'  */
#line 943 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5271 "tools/widl/parser.tab.c"
    break;

  case 334: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5277 "tools/widl/parser.tab.c"
    break;

  case 335: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5283 "tools/widl/parser.tab.c"
    break;

  case 336: /* inherit: %empty  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5289 "tools/widl/parser.tab.c"
    break;

  case 337: /* inherit: ':' qualified_type  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5295 "tools/widl/parser.tab.c"
    break;

  case 338: /* interface: tINTERFACE typename  */
#line 957 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5301 "tools/widl/parser.tab.c"
    break;

  case 339: /* interfacedef: attributes interface inherit '{' int_statements '}' semicolon_opt  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_define((yyvsp[-5].type), (yyvsp[-6].attr_list), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5309 "tools/widl/parser.tab.c"
    break;

  case 340: /* interfacedef: attributes interface ':' aIDENTIFIER '{' import int_statements '}' semicolon_opt  */
#line 968 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), find_type_or_error((yyvsp[-5].str)), (yyvsp[-2].stmt_list)); }
#line 5315 "tools/widl/parser.tab.c"
    break;

  case 341: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5321 "tools/widl/parser.tab.c"
    break;

  case 342: /* interfaceref: tINTERFACE typename  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5327 "tools/widl/parser.tab.c"
    break;

  case 343: /* interfaceref: tDISPINTERFACE typename  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5333 "tools/widl/parser.tab.c"
    break;

  case 344: /* module: tMODULE typename  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5339 "tools/widl/parser.tab.c"
    break;

  case 345: /* moduledef: attributes module '{' int_statements '}' semicolon_opt  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5345 "tools/widl/parser.tab.c"
    break;

  case 346: /* storage_cls_spec: tEXTERN  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5351 "tools/widl/parser.tab.c"
    break;

  case 347: /* storage_cls_spec: tSTATIC  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5357 "tools/widl/parser.tab.c"
    break;

  case 348: /* storage_cls_spec: tREGISTER  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5363 "tools/widl/parser.tab.c"
    break;

  case 349: /* function_specifier: tINLINE  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5369 "tools/widl/parser.tab.c"
    break;

  case 350: /* type_qualifier: tCONST  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5375 "tools/widl/parser.tab.c"
    break;

  case 351: /* m_type_qual_list: %empty  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5381 "tools/widl/parser.tab.c"
    break;

  case 352: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5387 "tools/widl/parser.tab.c"
    break;

  case 353: /* decl_spec: type m_decl_spec_no_type  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5393 "tools/widl/parser.tab.c"
    break;

  case 354: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1004 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5399 "tools/widl/parser.tab.c"
    break;

  case 355: /* m_decl_spec_no_type: %empty  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5405 "tools/widl/parser.tab.c"
    break;

  case 357: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5411 "tools/widl/parser.tab.c"
    break;

  case 358: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1013 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5417 "tools/widl/parser.tab.c"
    break;

  case 359: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5423 "tools/widl/parser.tab.c"
    break;

  case 360: /* declarator: '*' m_type_qual_list declarator  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5429 "tools/widl/parser.tab.c"
    break;

  case 361: /* declarator: callconv declarator  */
#line 1020 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5435 "tools/widl/parser.tab.c"
    break;

  case 363: /* direct_declarator: ident  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5441 "tools/widl/parser.tab.c"
    break;

  case 364: /* direct_declarator: '(' declarator ')'  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5447 "tools/widl/parser.tab.c"
    break;

  case 365: /* direct_declarator: direct_declarator array  */
#line 1027 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5453 "tools/widl/parser.tab.c"
    break;

  case 366: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5459 "tools/widl/parser.tab.c"
    break;

  case 367: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5465 "tools/widl/parser.tab.c"
    break;

  case 368: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5471 "tools/widl/parser.tab.c"
    break;

  case 370: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5477 "tools/widl/parser.tab.c"
    break;

  case 371: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1043 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5483 "tools/widl/parser.tab.c"
    break;

  case 372: /* m_abstract_declarator: %empty  */
#line 1047 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5489 "tools/widl/parser.tab.c"
    break;

  case 374: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5495 "tools/widl/parser.tab.c"
    break;

  case 375: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1054 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5501 "tools/widl/parser.tab.c"
    break;

  case 376: /* abstract_direct_declarator: array  */
#line 1055 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5507 "tools/widl/parser.tab.c"
    break;

  case 377: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1057 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5515 "tools/widl/parser.tab.c"
    break;

  case 378: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5523 "tools/widl/parser.tab.c"
    break;

  case 379: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1069 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5529 "tools/widl/parser.tab.c"
    break;

  case 380: /* any_declarator: callconv m_any_declarator  */
#line 1070 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5535 "tools/widl/parser.tab.c"
    break;

  case 382: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1077 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5541 "tools/widl/parser.tab.c"
    break;

  case 383: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1078 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5547 "tools/widl/parser.tab.c"
    break;

  case 384: /* m_any_declarator: %empty  */
#line 1082 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5553 "tools/widl/parser.tab.c"
    break;

  case 386: /* any_direct_declarator: ident  */
#line 1090 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5559 "tools/widl/parser.tab.c"
    break;

  case 387: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1091 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5565 "tools/widl/parser.tab.c"
    break;

  case 388: /* any_direct_declarator: any_direct_declarator array  */
#line 1092 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5571 "tools/widl/parser.tab.c"
    break;

  case 389: /* any_direct_declarator: array  */
#line 1093 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5577 "tools/widl/parser.tab.c"
    break;

  case 390: /* any_direct_declarator: '(' m_args ')'  */
#line 1095 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5585 "tools/widl/parser.tab.c"
    break;

  case 391: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5593 "tools/widl/parser.tab.c"
    break;

  case 392: /* declarator_list: declarator  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5599 "tools/widl/parser.tab.c"
    break;

  case 393: /* declarator_list: declarator_list ',' declarator  */
#line 1106 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5605 "tools/widl/parser.tab.c"
    break;

  case 394: /* m_bitfield: %empty  */
#line 1109 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5611 "tools/widl/parser.tab.c"
    break;

  case 395: /* m_bitfield: ':' expr_const  */
#line 1110 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5617 "tools/widl/parser.tab.c"
    break;

  case 396: /* struct_declarator: any_declarator m_bitfield  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5626 "tools/widl/parser.tab.c"
    break;

  case 397: /* struct_declarator_list: struct_declarator  */
#line 1120 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5632 "tools/widl/parser.tab.c"
    break;

  case 398: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1122 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5638 "tools/widl/parser.tab.c"
    break;

  case 399: /* init_declarator: declarator  */
#line 1126 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5644 "tools/widl/parser.tab.c"
    break;

  case 400: /* init_declarator: declarator '=' expr_const  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5650 "tools/widl/parser.tab.c"
    break;

  case 401: /* threading_type: tAPARTMENT  */
#line 1131 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5656 "tools/widl/parser.tab.c"
    break;

  case 402: /* threading_type: tNEUTRAL  */
#line 1132 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5662 "tools/widl/parser.tab.c"
    break;

  case 403: /* threading_type: tSINGLE  */
#line 1133 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5668 "tools/widl/parser.tab.c"
    break;

  case 404: /* threading_type: tFREE  */
#line 1134 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5674 "tools/widl/parser.tab.c"
    break;

  case 405: /* threading_type: tBOTH  */
#line 1135 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5680 "tools/widl/parser.tab.c"
    break;

  case 406: /* threading_type: tMTA  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5686 "tools/widl/parser.tab.c"
    break;

  case 407: /* pointer_type: tREF  */
#line 1140 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5692 "tools/widl/parser.tab.c"
    break;

  case 408: /* pointer_type: tUNIQUE  */
#line 1141 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5698 "tools/widl/parser.tab.c"
    break;

  case 409: /* pointer_type: tPTR  */
#line 1142 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5704 "tools/widl/parser.tab.c"
    break;

  case 410: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5710 "tools/widl/parser.tab.c"
    break;

  case 411: /* type: tVOID  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5716 "tools/widl/parser.tab.c"
    break;

  case 412: /* type: qualified_type  */
#line 1149 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5722 "tools/widl/parser.tab.c"
    break;

  case 413: /* type: base_type  */
#line 1150 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5728 "tools/widl/parser.tab.c"
    break;

  case 414: /* type: enumdef  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5734 "tools/widl/parser.tab.c"
    break;

  case 415: /* type: tENUM aIDENTIFIER  */
#line 1152 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5740 "tools/widl/parser.tab.c"
    break;

  case 416: /* type: structdef  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5746 "tools/widl/parser.tab.c"
    break;

  case 417: /* type: tSTRUCT aIDENTIFIER  */
#line 1154 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5752 "tools/widl/parser.tab.c"
    break;

  case 418: /* type: uniondef  */
#line 1155 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5758 "tools/widl/parser.tab.c"
    break;

  case 419: /* type: tUNION aIDENTIFIER  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5764 "tools/widl/parser.tab.c"
    break;

  case 420: /* type: tSAFEARRAY '(' type ')'  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5770 "tools/widl/parser.tab.c"
    break;

  case 421: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1161 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5779 "tools/widl/parser.tab.c"
    break;

  case 422: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1168 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5785 "tools/widl/parser.tab.c"
    break;

  case 423: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1171 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5791 "tools/widl/parser.tab.c"
    break;

  case 424: /* version: aNUM  */
#line 1175 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5797 "tools/widl/parser.tab.c"
    break;

  case 425: /* version: aNUM '.' aNUM  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5803 "tools/widl/parser.tab.c"
    break;

  case 426: /* version: aHEXNUM  */
#line 1177 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5809 "tools/widl/parser.tab.c"
    break;

  case 431: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1192 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5817 "tools/widl/parser.tab.c"
    break;

  case 432: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1199 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error((yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5827 "tools/widl/parser.tab.c"
    break;

  case 433: /* acf_attributes: %empty  */
#line 1207 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5833 "tools/widl/parser.tab.c"
    break;

  case 434: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1208 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5839 "tools/widl/parser.tab.c"
    break;

  case 435: /* acf_attribute_list: acf_attribute  */
#line 1212 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5845 "tools/widl/parser.tab.c"
    break;

  case 436: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1213 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5851 "tools/widl/parser.tab.c"
    break;

  case 437: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1218 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5857 "tools/widl/parser.tab.c"
    break;

  case 438: /* acf_attribute: tENCODE  */
#line 1219 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5863 "tools/widl/parser.tab.c"
    break;

  case 439: /* acf_attribute: tDECODE  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5869 "tools/widl/parser.tab.c"
    break;

  case 440: /* acf_attribute: tEXPLICITHANDLE  */
#line 1221 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5875 "tools/widl/parser.tab.c"
    break;

  case 441: /* allocate_option_list: allocate_option  */
#line 1225 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5881 "tools/widl/parser.tab.c"
    break;

  case 442: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 5887 "tools/widl/parser.tab.c"
    break;

  case 443: /* allocate_option: tDONTFREE  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 5893 "tools/widl/parser.tab.c"
    break;

  case 444: /* allocate_option: tFREE  */
#line 1232 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5899 "tools/widl/parser.tab.c"
    break;

  case 445: /* allocate_option: tALLNODES  */
#line 1233 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 5905 "tools/widl/parser.tab.c"
    break;

  case 446: /* allocate_option: tSINGLENODE  */
#line 1234 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5911 "tools/widl/parser.tab.c"
    break;


#line 5915 "tools/widl/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1237 "tools/widl/parser.y"


static void decl_builtin_basic(const char *name, enum type_basic_type type)
{
  type_t *t = type_new_basic(type);
  reg_type(t, name, NULL, 0);
}

static void decl_builtin_alias(const char *name, type_t *t)
{
    const decl_spec_t ds = {.type = t};
    reg_type(type_new_alias(&ds, name), name, NULL, 0);
}

void init_types(void)
{
  decl_builtin_basic("byte", TYPE_BASIC_BYTE);
  decl_builtin_basic("wchar_t", TYPE_BASIC_WCHAR);
  decl_builtin_basic("float", TYPE_BASIC_FLOAT);
  decl_builtin_basic("double", TYPE_BASIC_DOUBLE);
  decl_builtin_basic("error_status_t", TYPE_BASIC_ERROR_STATUS_T);
  decl_builtin_basic("handle_t", TYPE_BASIC_HANDLE);
  decl_builtin_alias("boolean", type_new_basic(TYPE_BASIC_CHAR));
}

static str_list_t *append_str(str_list_t *list, char *str)
{
    struct str_list_entry_t *entry;

    if (!str) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->str = str;
    list_add_tail( list, &entry->entry );
    return list;
}

static attr_list_t *move_attr(attr_list_t *dst, attr_list_t *src, enum attr_type type)
{
  attr_t *attr;
  if (!src) return dst;
  LIST_FOR_EACH_ENTRY(attr, src, attr_t, entry)
    if (attr->type == type)
    {
      list_remove(&attr->entry);
      return append_attr(dst, attr);
    }
  return dst;
}

static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list)
{
  struct list *entry;

  if (!old_list) return new_list;

  while ((entry = list_head(old_list)))
  {
    attr_t *attr = LIST_ENTRY(entry, attr_t, entry);
    list_remove(entry);
    new_list = append_attr(new_list, attr);
  }
  return new_list;
}

typedef int (*map_attrs_filter_t)(attr_list_t*,const attr_t*);

static attr_list_t *map_attrs(const attr_list_t *list, map_attrs_filter_t filter)
{
  attr_list_t *new_list;
  const attr_t *attr;
  attr_t *new_attr;

  if (!list) return NULL;

  new_list = xmalloc( sizeof(*list) );
  list_init( new_list );
  LIST_FOR_EACH_ENTRY(attr, list, const attr_t, entry)
  {
    if (filter && !filter(new_list, attr)) continue;
    new_attr = xmalloc(sizeof(*new_attr));
    *new_attr = *attr;
    list_add_tail(new_list, &new_attr->entry);
  }
  return new_list;
}

static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier)
{
  decl_spec_t *declspec = left ? left : right;
  if (!declspec)
  {
    declspec = xmalloc(sizeof(*declspec));
    declspec->type = NULL;
    declspec->stgclass = STG_NONE;
    declspec->qualifier = 0;
    declspec->func_specifier = 0;
  }
  declspec->type = type;
  if (left && declspec != left)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = left->stgclass;
    else if (left->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= left->qualifier;
    declspec->func_specifier |= left->func_specifier;
    assert(!left->type);
    free(left);
  }
  if (right && declspec != right)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = right->stgclass;
    else if (right->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= right->qualifier;
    declspec->func_specifier |= right->func_specifier;
    assert(!right->type);
    free(right);
  }

  if (declspec->stgclass == STG_NONE)
    declspec->stgclass = stgclass;
  else if (stgclass != STG_NONE)
    error_loc("only one storage class can be specified\n");
  declspec->qualifier |= qual;
  declspec->func_specifier |= func_specifier;

  return declspec;
}

static attr_t *make_attr(enum attr_type type)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = 0;
  return a;
}

static attr_t *make_attrv(enum attr_type type, unsigned int val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = val;
  return a;
}

static attr_t *make_attrp(enum attr_type type, void *val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.pval = val;
  return a;
}

static attr_t *make_custom_attr(UUID *id, expr_t *pval)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  attr_custdata_t *cstdata = xmalloc(sizeof(attr_custdata_t));
  a->type = ATTR_CUSTOM;
  cstdata->id = *id;
  cstdata->pval = pval;
  a->u.pval = cstdata;
  return a;
}

static expr_list_t *append_expr(expr_list_t *list, expr_t *expr)
{
    if (!expr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &expr->entry );
    return list;
}

static void append_array(declarator_t *decl, expr_t *expr)
{
    type_t *array;

    if (!expr)
        return;

    /* An array is always a reference pointer unless explicitly marked otherwise
     * (regardless of what the default pointer attribute is). */
    array = type_new_array(NULL, NULL, FALSE, expr->is_const ? expr->cval : 0,
            expr->is_const ? NULL : expr, NULL);

    append_chain_type(decl, array, 0);
}

static struct list type_pool = LIST_INIT(type_pool);
typedef struct
{
  type_t data;
  struct list link;
} type_pool_node_t;

type_t *alloc_type(void)
{
  type_pool_node_t *node = xmalloc(sizeof *node);
  list_add_tail(&type_pool, &node->link);
  return &node->data;
}

void set_all_tfswrite(int val)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.tfswrite = val;
}

void clear_all_offsets(void)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.typestring_offset = node->data.ptrdesc = 0;
}

static void type_function_add_head_arg(type_t *type, var_t *arg)
{
    if (!type->details.function->args)
    {
        type->details.function->args = xmalloc( sizeof(*type->details.function->args) );
        list_init( type->details.function->args );
    }
    list_add_head( type->details.function->args, &arg->entry );
}

static int is_allowed_range_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_INT3264:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_WCHAR:
        case TYPE_BASIC_HYPER:
            return TRUE;
        case TYPE_BASIC_FLOAT:
        case TYPE_BASIC_DOUBLE:
        case TYPE_BASIC_ERROR_STATUS_T:
        case TYPE_BASIC_HANDLE:
            return FALSE;
        }
        return FALSE;
    default:
        return FALSE;
    }
}

static type_t *get_chain_ref(type_t *type)
{
    if (is_ptr(type))
        return type_pointer_get_ref_type(type);
    else if (is_array(type))
        return type_array_get_element_type(type);
    else if (is_func(type))
        return type_function_get_rettype(type);
    return NULL;
}

static type_t *get_chain_end(type_t *type)
{
    type_t *inner;
    while ((inner = get_chain_ref(type)))
        type = inner;
    return type;
}

static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual)
{
    type_t *chain_type;

    if (!decl->type)
    {
        decl->type = type;
        decl->qualifier = qual;
        return;
    }
    chain_type = get_chain_end(decl->type);

    if (is_ptr(chain_type))
    {
        chain_type->details.pointer.ref.type = type;
        chain_type->details.pointer.ref.qualifier = qual;
    }
    else if (is_array(chain_type))
    {
        chain_type->details.array.elem.type = type;
        chain_type->details.array.elem.qualifier = qual;
    }
    else if (is_func(chain_type))
    {
        chain_type->details.function->retval->declspec.type = type;
        chain_type->details.function->retval->declspec.qualifier = qual;
    }
    else
        assert(0);

    if (!is_func(chain_type))
        type->attrs = move_attr(type->attrs, chain_type->attrs, ATTR_CALLCONV);
}

static void append_chain_callconv(type_t *chain, char *callconv)
{
    type_t *chain_end;

    if (chain && (chain_end = get_chain_end(chain)))
        chain_end->attrs = append_attr(chain_end->attrs, make_attrp(ATTR_CALLCONV, callconv));
    else
        error_loc("calling convention applied to non-function type\n");
}

static warning_list_t *append_warning(warning_list_t *list, int num)
{
    warning_t *entry;

    if(!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->num = num;
    list_add_tail( list, &entry->entry );
    return list;
}

static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl,
                       int top)
{
  var_t *v = decl->var;
  expr_list_t *sizes = get_attrp(attrs, ATTR_SIZEIS);
  expr_list_t *lengs = get_attrp(attrs, ATTR_LENGTHIS);
  expr_t *dim;
  type_t **ptype;
  type_t *type = decl_spec->type;

  if (decl_spec->func_specifier & FUNCTION_SPECIFIER_INLINE)
  {
    if (!decl || !is_func(decl->type))
      error_loc("inline attribute applied to non-function type\n");
  }

  /* add type onto the end of the pointers in pident->type */
  append_chain_type(decl, type, decl_spec->qualifier);
  v->declspec = *decl_spec;
  v->declspec.type = decl->type;
  v->declspec.qualifier = decl->qualifier;
  v->attrs = attrs;
  v->declonly = !type->defined;

  if (is_attr(type->attrs, ATTR_CALLCONV) && !is_func(type))
    error_loc("calling convention applied to non-function type\n");

  /* check for pointer attribute being applied to non-pointer, non-array
   * type */
  if (!is_array(v->declspec.type))
  {
    int ptr_attr = get_attrv(v->attrs, ATTR_POINTERTYPE);
    const type_t *ptr = NULL;
    for (ptr = v->declspec.type; ptr && !ptr_attr; )
    {
      ptr_attr = get_attrv(ptr->attrs, ATTR_POINTERTYPE);
      if (!ptr_attr && type_is_alias(ptr))
        ptr = type_alias_get_aliasee_type(ptr);
      else
        break;
    }
    if (is_ptr(ptr))
    {
      if (ptr_attr && ptr_attr != FC_UP &&
          type_get_type(type_pointer_get_ref_type(ptr)) == TYPE_INTERFACE)
          warning_loc_info(&v->loc_info,
                           "%s: pointer attribute applied to interface "
                           "pointer type has no effect\n", v->name);
      if (!ptr_attr && top)
      {
        /* FIXME: this is a horrible hack to cope with the issue that we
         * store an offset to the typeformat string in the type object, but
         * two typeformat strings may be written depending on whether the
         * pointer is a toplevel parameter or not */
        v->declspec.type = duptype(v->declspec.type, 1);
      }
    }
    else if (ptr_attr)
       error_loc("%s: pointer attribute applied to non-pointer type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_STRING))
  {
    type_t *t = type;

    if (!is_ptr(v->declspec.type) && !is_array(v->declspec.type))
      error_loc("'%s': [string] attribute applied to non-pointer, non-array type\n",
                v->name);

    for (;;)
    {
        if (is_ptr(t))
            t = type_pointer_get_ref_type(t);
        else if (is_array(t))
            t = type_array_get_element_type(t);
        else
            break;
    }

    if (type_get_type(t) != TYPE_BASIC &&
        (get_basic_fc(t) != FC_CHAR &&
         get_basic_fc(t) != FC_BYTE &&
         get_basic_fc(t) != FC_WCHAR))
    {
      error_loc("'%s': [string] attribute is only valid on 'char', 'byte', or 'wchar_t' pointers and arrays\n",
                v->name);
    }
  }

  if (is_attr(v->attrs, ATTR_V1ENUM))
  {
    if (type_get_type_detect_alias(v->declspec.type) != TYPE_ENUM)
      error_loc("'%s': [v1_enum] attribute applied to non-enum type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_RANGE) && !is_allowed_range_type(v->declspec.type))
    error_loc("'%s': [range] attribute applied to non-integer type\n",
              v->name);

  ptype = &v->declspec.type;
  if (sizes) LIST_FOR_EACH_ENTRY(dim, sizes, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        if (!type_array_get_conformance(*ptype) ||
            type_array_get_conformance(*ptype)->type != EXPR_VOID)
          error_loc("%s: cannot specify size_is for an already sized array\n", v->name);
        else
          *ptype = type_new_array((*ptype)->name,
                                  type_array_get_element(*ptype), FALSE,
                                  0, dim, NULL);
      }
      else if (is_ptr(*ptype))
        *ptype = type_new_array((*ptype)->name, type_pointer_get_ref(*ptype), TRUE,
                                0, dim, NULL);
      else
        error_loc("%s: size_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in size_is attribute\n", v->name);
  }

  ptype = &v->declspec.type;
  if (lengs) LIST_FOR_EACH_ENTRY(dim, lengs, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        *ptype = type_new_array((*ptype)->name,
                                type_array_get_element(*ptype),
                                type_array_is_decl_as_ptr(*ptype),
                                type_array_get_dim(*ptype),
                                type_array_get_conformance(*ptype), dim);
      }
      else
        error_loc("%s: length_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in length_is attribute\n", v->name);
  }

  if (decl->bits)
    v->declspec.type = type_new_bitfield(v->declspec.type, decl->bits);

  return v;
}

static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls)
{
  declarator_t *decl, *next;
  var_list_t *var_list = NULL;

  LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
  {
    var_t *var = declare_var(attrs, decl_spec, decl, 0);
    var_list = append_var(var_list, var);
    free(decl);
  }
  free(decl_spec);
  return var_list;
}

static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface)
{
    if (!iface) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &iface->entry );
    return list;
}

static ifref_t *make_ifref(type_t *iface)
{
  ifref_t *l = xmalloc(sizeof(ifref_t));
  l->iface = iface;
  l->attrs = NULL;
  return l;
}

var_list_t *append_var(var_list_t *list, var_t *var)
{
    if (!var) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &var->entry );
    return list;
}

static var_list_t *append_var_list(var_list_t *list, var_list_t *vars)
{
    if (!vars) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_move_tail( list, vars );
    return list;
}

var_t *make_var(char *name)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  init_declspec(&v->declspec, NULL);
  v->attrs = NULL;
  v->eval = NULL;
  init_loc_info(&v->loc_info);
  v->declonly = FALSE;
  return v;
}

static var_t *copy_var(var_t *src, char *name, map_attrs_filter_t attr_filter)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  v->declspec = src->declspec;
  v->attrs = map_attrs(src->attrs, attr_filter);
  v->eval = src->eval;
  v->loc_info = src->loc_info;
  return v;
}

static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *d)
{
  if (!d) return list;
  if (!list) {
    list = xmalloc(sizeof(*list));
    list_init(list);
  }
  list_add_tail(list, &d->entry);
  return list;
}

static declarator_t *make_declarator(var_t *var)
{
  declarator_t *d = xmalloc(sizeof(*d));
  d->var = var ? var : make_var(NULL);
  d->type = NULL;
  d->qualifier = 0;
  d->bits = NULL;
  return d;
}

static type_t *make_safearray(type_t *type)
{
    decl_spec_t ds = {.type = type};
    ds.type = type_new_alias(&ds, "SAFEARRAY");
    return type_new_array(NULL, &ds, TRUE, 0, NULL, NULL);
}

static typelib_t *make_library(const char *name, const attr_list_t *attrs)
{
    typelib_t *typelib = xmalloc(sizeof(*typelib));
    memset(typelib, 0, sizeof(*typelib));
    typelib->name = xstrdup(name);
    typelib->attrs = attrs;
    list_init( &typelib->importlibs );
    return typelib;
}

static int hash_ident(const char *name)
{
  const char *p = name;
  int sum = 0;
  /* a simple sum hash is probably good enough */
  while (*p) {
    sum += *p;
    p++;
  }
  return sum & (HASHMAX-1);
}

/***** type repository *****/

static struct namespace *find_sub_namespace(struct namespace *namespace, const char *name)
{
  struct namespace *cur;

  LIST_FOR_EACH_ENTRY(cur, &namespace->children, struct namespace, entry) {
    if(!strcmp(cur->name, name))
      return cur;
  }

  return NULL;
}

static void push_namespace(const char *name)
{
  struct namespace *namespace;

  namespace = find_sub_namespace(current_namespace, name);
  if(!namespace) {
    namespace = xmalloc(sizeof(*namespace));
    namespace->name = xstrdup(name);
    namespace->parent = current_namespace;
    list_add_tail(&current_namespace->children, &namespace->entry);
    list_init(&namespace->children);
    memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
  }

  current_namespace = namespace;
}

static void pop_namespace(const char *name)
{
  assert(!strcmp(current_namespace->name, name) && current_namespace->parent);
  current_namespace = current_namespace->parent;
}

static void init_lookup_namespace(const char *name)
{
    if (!(lookup_namespace = find_sub_namespace(&global_namespace, name)))
        error_loc("namespace '%s' not found\n", name);
}

static void push_lookup_namespace(const char *name)
{
    struct namespace *namespace;
    if (!(namespace = find_sub_namespace(lookup_namespace, name)))
        error_loc("namespace '%s' not found\n", name);
    lookup_namespace = namespace;
}

struct rtype {
  const char *name;
  type_t *type;
  int t;
  struct rtype *next;
};

type_t *reg_type(type_t *type, const char *name, struct namespace *namespace, int t)
{
  struct rtype *nt;
  int hash;
  if (!name) {
    error_loc("registering named type without name\n");
    return type;
  }
  if (!namespace)
    namespace = &global_namespace;
  hash = hash_ident(name);
  nt = xmalloc(sizeof(struct rtype));
  nt->name = name;
  if (is_global_namespace(namespace))
    type->c_name = name;
  else
    type->c_name = format_namespace(namespace, "__x_", "_C", name, use_abi_namespace ? "ABI" : NULL);
  nt->type = type;
  nt->t = t;
  nt->next = namespace->type_hash[hash];
  namespace->type_hash[hash] = nt;
  return type;
}

static type_t *reg_typedefs(decl_spec_t *decl_spec, declarator_list_t *decls, attr_list_t *attrs)
{
  declarator_t *decl;
  type_t *type = decl_spec->type;

  if (is_attr(attrs, ATTR_UUID) && !is_attr(attrs, ATTR_PUBLIC))
    attrs = append_attr( attrs, make_attr(ATTR_PUBLIC) );

  /* We must generate names for tagless enum, struct or union.
     Typedef-ing a tagless enum, struct or union means we want the typedef
     to be included in a library hence the public attribute.  */
  if (type_get_type_detect_alias(type) == TYPE_ENUM ||
      type_get_type_detect_alias(type) == TYPE_STRUCT ||
      type_get_type_detect_alias(type) == TYPE_UNION ||
      type_get_type_detect_alias(type) == TYPE_ENCAPSULATED_UNION)
  {
    if (!type->name)
    {
      type->name = gen_name();
      if (!is_attr(attrs, ATTR_PUBLIC))
        attrs = append_attr(attrs, make_attr(ATTR_PUBLIC));
    }

    /* replace existing attributes when generating a typelib */
    if (do_typelib)
        type->attrs = attrs;
  }

  LIST_FOR_EACH_ENTRY( decl, decls, declarator_t, entry )
  {

    if (decl->var->name) {
      type_t *cur;
      var_t *name;

      cur = find_type(decl->var->name, current_namespace, 0);

      /*
       * MIDL allows shadowing types that are declared in imported files.
       * We don't throw an error in this case and instead add a new type
       * (which is earlier on the list in hash table, so it will be used
       * instead of shadowed type).
       *
       * FIXME: We may consider string separated type tables for each input
       *        for cleaner solution.
       */
      if (cur && input_name == cur->loc_info.input_name)
          error_loc("%s: redefinition error; original definition was at %s:%d\n",
                    cur->name, cur->loc_info.input_name,
                    cur->loc_info.line_number);

      name = declare_var(attrs, decl_spec, decl, 0);
      cur = type_new_alias(&name->declspec, name->name);
      cur->attrs = attrs;

      reg_type(cur, cur->name, current_namespace, 0);
    }
  }
  return type;
}

type_t *find_type(const char *name, struct namespace *namespace, int t)
{
  struct rtype *cur;

  if(namespace && namespace != &global_namespace) {
    for(cur = namespace->type_hash[hash_ident(name)]; cur; cur = cur->next) {
      if(cur->t == t && !strcmp(cur->name, name))
        return cur->type;
    }
  }
  for(cur = global_namespace.type_hash[hash_ident(name)]; cur; cur = cur->next) {
    if(cur->t == t && !strcmp(cur->name, name))
      return cur->type;
  }
  return NULL;
}

static type_t *find_type_or_error(const char *name)
{
    type_t *type;
    if (!(type = find_type(name, current_namespace, 0)) &&
        !(type = find_type(name, lookup_namespace, 0)))
    {
        error_loc("type '%s' not found\n", name);
        return NULL;
    }
    return type;
}

int is_type(const char *name)
{
    return find_type(name, current_namespace, 0) != NULL ||
           find_type(name, lookup_namespace, 0) != NULL;
}

int is_namespace(const char *name)
{
    if (!winrt_mode) return 0;
    return find_sub_namespace(current_namespace, name) != NULL ||
           find_sub_namespace(&global_namespace, name) != NULL;
}

type_t *get_type(enum type_type type, char *name, struct namespace *namespace, int t)
{
  type_t *tp;
  if (!namespace)
    namespace = &global_namespace;
  if (name) {
    tp = find_type(name, namespace, t);
    if (tp) {
      free(name);
      return tp;
    }
  }
  tp = make_type(type);
  tp->name = name;
  tp->namespace = namespace;
  if (!name) return tp;
  return reg_type(tp, name, namespace, t);
}

/***** constant repository *****/

struct rconst {
  char *name;
  var_t *var;
  struct rconst *next;
};

struct rconst *const_hash[HASHMAX];

static var_t *reg_const(var_t *var)
{
  struct rconst *nc;
  int hash;
  if (!var->name) {
    error_loc("registering constant without name\n");
    return var;
  }
  hash = hash_ident(var->name);
  nc = xmalloc(sizeof(struct rconst));
  nc->name = var->name;
  nc->var = var;
  nc->next = const_hash[hash];
  const_hash[hash] = nc;
  return var;
}

var_t *find_const(const char *name, int f)
{
  struct rconst *cur = const_hash[hash_ident(name)];
  while (cur && strcmp(cur->name, name))
    cur = cur->next;
  if (!cur) {
    if (f) error_loc("constant '%s' not found\n", name);
    return NULL;
  }
  return cur->var;
}

char *gen_name(void)
{
  static unsigned long n = 0;
  static const char *file_id;

  if (! file_id)
  {
    char *dst = dup_basename(input_idl_name, ".idl");
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';
  }
  return strmake("__WIDL_%s_generated_name_%08lX", file_id, n++);
}

struct allowed_attr
{
    unsigned int dce_compatible : 1;
    unsigned int acf : 1;
    unsigned int multiple : 1;

    unsigned int on_interface : 1;
    unsigned int on_function : 1;
    unsigned int on_arg : 1;
    unsigned int on_type : 1;
    unsigned int on_enum : 1;
    unsigned int on_enum_member : 1;
    unsigned int on_struct : 2;
    unsigned int on_union : 1;
    unsigned int on_field : 1;
    unsigned int on_library : 1;
    unsigned int on_dispinterface : 1;
    unsigned int on_module : 1;
    unsigned int on_coclass : 1;
    unsigned int on_apicontract : 1;
    unsigned int on_runtimeclass : 1;
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF M   I Fn ARG T En Enm St Un Fi L  DI M  C AC  R  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "aggregatable" },
    /* ATTR_ALLOCATE */            { 0, 1, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "allocate" },
    /* ATTR_ANNOTATION */          { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 0,  1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTRACT */            { 0, 0, 0,  1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, "contract" },
    /* ATTR_CONTRACTVERSION */     { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "contractversion" },
    /* ATTR_CONTROL */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, "control" },
    /* ATTR_CUSTOM */              { 0, 0, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, "custom" },
    /* ATTR_DECODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EVENTADD */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventadd" },
    /* ATTR_EVENTREMOVE */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventremove" },
    /* ATTR_EXCLUSIVETO */         { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "exclusive_to" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FLAGS */               { 0, 0, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "flags" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MARSHALING_BEHAVIOR */ { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "marshaling_behavior" },
    /* ATTR_MAYBE */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0,  0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0,  0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0,  0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 0,  1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0,  0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

static attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
{
    attr_t *attr_existing;
    if (!attr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    if (!allowed_attr[attr->type].multiple)
    {
        LIST_FOR_EACH_ENTRY(attr_existing, list, attr_t, entry)
            if (attr_existing->type == attr->type)
            {
                parser_warning("duplicate attribute %s\n", get_attr_display_name(attr->type));
                /* use the last attribute, like MIDL does */
                list_remove(&attr_existing->entry);
                break;
            }
    }
    list_add_tail( list, &attr->entry );
    return list;
}

const char *get_attr_display_name(enum attr_type type)
{
    return allowed_attr[type].display_name;
}

attr_list_t *check_interface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_interface)
      error_loc("inapplicable attribute %s for interface %s\n",
                allowed_attr[attr->type].display_name, name);
    if (attr->type == ATTR_IMPLICIT_HANDLE)
    {
        const var_t *var = attr->u.pval;
        if (type_get_type( var->declspec.type) == TYPE_BASIC &&
            type_basic_get_type( var->declspec.type ) == TYPE_BASIC_HANDLE)
            continue;
        if (is_aliaschain_attr( var->declspec.type, ATTR_HANDLE ))
            continue;
      error_loc("attribute %s requires a handle type in interface %s\n",
                allowed_attr[attr->type].display_name, name);
    }
  }
  return attrs;
}

static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_function)
      error_loc("inapplicable attribute %s for function %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static void check_arg_attrs(const var_t *arg)
{
  const attr_t *attr;

  if (arg->attrs)
  {
    LIST_FOR_EACH_ENTRY(attr, arg->attrs, const attr_t, entry)
    {
      if (!allowed_attr[attr->type].on_arg)
        error_loc("inapplicable attribute %s for argument %s\n",
                  allowed_attr[attr->type].display_name, arg->name);
    }
  }
}

static attr_list_t *check_typedef_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_type)
      error_loc("inapplicable attribute %s for typedef\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum)
      error_loc("inapplicable attribute %s for enum\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_member_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum_member)
      error_loc("inapplicable attribute %s for enum member\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_struct_attrs(attr_list_t *attrs)
{
  int mask = winrt_mode ? 3 : 1;
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!(allowed_attr[attr->type].on_struct & mask))
      error_loc("inapplicable attribute %s for struct\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_union_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_union)
      error_loc("inapplicable attribute %s for union\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_field)
      error_loc("inapplicable attribute %s for field %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_library)
      error_loc("inapplicable attribute %s for library %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_dispinterface)
      error_loc("inapplicable attribute %s for dispinterface %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_module)
      error_loc("inapplicable attribute %s for module %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_coclass)
      error_loc("inapplicable attribute %s for coclass %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_runtimeclass)
            error_loc("inapplicable attribute %s for runtimeclass %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_apicontract)
            error_loc("inapplicable attribute %s for apicontract %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

static int is_allowed_conf_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_HYPER:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_WCHAR:
            return TRUE;
        default:
            return FALSE;
        }
    case TYPE_ALIAS:
        /* shouldn't get here because of type_get_type call above */
        assert(0);
        /* fall through */
    case TYPE_STRUCT:
    case TYPE_UNION:
    case TYPE_ENCAPSULATED_UNION:
    case TYPE_ARRAY:
    case TYPE_POINTER:
    case TYPE_VOID:
    case TYPE_MODULE:
    case TYPE_COCLASS:
    case TYPE_FUNCTION:
    case TYPE_INTERFACE:
    case TYPE_BITFIELD:
    case TYPE_RUNTIMECLASS:
        return FALSE;
    case TYPE_APICONTRACT:
        /* not supposed to be here */
        assert(0);
        break;
    }
    return FALSE;
}

static int is_ptr_guid_type(const type_t *type)
{
    /* first, make sure it is a pointer to something */
    if (!is_ptr(type)) return FALSE;

    /* second, make sure it is a pointer to something of size sizeof(GUID),
     * i.e. 16 bytes */
    return (type_memsize(type_pointer_get_ref_type(type)) == 16);
}

static void check_conformance_expr_list(const char *attr_name, const var_t *arg, const type_t *container_type, expr_list_t *expr_list)
{
    expr_t *dim;
    struct expr_loc expr_loc;
    expr_loc.v = arg;
    expr_loc.attr = attr_name;
    if (expr_list) LIST_FOR_EACH_ENTRY(dim, expr_list, expr_t, entry)
    {
        if (dim->type != EXPR_VOID)
        {
            const type_t *expr_type = expr_resolve_type(&expr_loc, container_type, dim);
            if (!is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               attr_name);
        }
    }
}

static void check_remoting_fields(const var_t *var, type_t *type);

/* checks that properties common to fields and arguments are consistent */
static void check_field_common(const type_t *container_type,
                               const char *container_name, const var_t *arg)
{
    type_t *type = arg->declspec.type;
    int more_to_do;
    const char *container_type_name;
    const char *var_type;

    switch (type_get_type(container_type))
    {
    case TYPE_STRUCT:
        container_type_name = "struct";
        var_type = "field";
        break;
    case TYPE_UNION:
        container_type_name = "union";
        var_type = "arm";
        break;
    case TYPE_ENCAPSULATED_UNION:
        container_type_name = "encapsulated union";
        var_type = "arm";
        break;
    case TYPE_FUNCTION:
        container_type_name = "function";
        var_type = "parameter";
        break;
    default:
        /* should be no other container types */
        assert(0);
        return;
    }

    if (is_attr(arg->attrs, ATTR_LENGTHIS) &&
        (is_attr(arg->attrs, ATTR_STRING) || is_aliaschain_attr(arg->declspec.type, ATTR_STRING)))
        error_loc_info(&arg->loc_info,
                       "string and length_is specified for argument %s are mutually exclusive attributes\n",
                       arg->name);

    if (is_attr(arg->attrs, ATTR_SIZEIS))
    {
        expr_list_t *size_is_exprs = get_attrp(arg->attrs, ATTR_SIZEIS);
        check_conformance_expr_list("size_is", arg, container_type, size_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_LENGTHIS))
    {
        expr_list_t *length_is_exprs = get_attrp(arg->attrs, ATTR_LENGTHIS);
        check_conformance_expr_list("length_is", arg, container_type, length_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_IIDIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_IIDIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "iid_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_ptr_guid_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to pointer to GUID type for attribute iid_is\n");
        }
    }
    if (is_attr(arg->attrs, ATTR_SWITCHIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_SWITCHIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "switch_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               expr_loc.attr);
        }
    }

    do
    {
        more_to_do = FALSE;

        switch (typegen_detect_type(type, arg->attrs, TDT_IGNORE_STRINGS))
        {
        case TGT_STRUCT:
        case TGT_UNION:
            check_remoting_fields(arg, type);
            break;
        case TGT_INVALID:
        {
            const char *reason = "is invalid";
            switch (type_get_type(type))
            {
            case TYPE_VOID:
                reason = "cannot derive from void *";
                break;
            case TYPE_FUNCTION:
                reason = "cannot be a function pointer";
                break;
            case TYPE_BITFIELD:
                reason = "cannot be a bit-field";
                break;
            case TYPE_COCLASS:
                reason = "cannot be a class";
                break;
            case TYPE_INTERFACE:
                reason = "cannot be a non-pointer to an interface";
                break;
            case TYPE_MODULE:
                reason = "cannot be a module";
                break;
            default:
                break;
            }
            error_loc_info(&arg->loc_info, "%s \'%s\' of %s \'%s\' %s\n",
                           var_type, arg->name, container_type_name, container_name, reason);
            break;
        }
        case TGT_CTXT_HANDLE:
        case TGT_CTXT_HANDLE_POINTER:
            if (type_get_type(container_type) != TYPE_FUNCTION)
                error_loc_info(&arg->loc_info,
                               "%s \'%s\' of %s \'%s\' cannot be a context handle\n",
                               var_type, arg->name, container_type_name,
                               container_name);
            break;
        case TGT_STRING:
        {
            const type_t *t = type;
            while (is_ptr(t))
                t = type_pointer_get_ref_type(t);
            if (is_aliaschain_attr(t, ATTR_RANGE))
                warning_loc_info(&arg->loc_info, "%s: range not verified for a string of ranged types\n", arg->name);
            break;
        }
        case TGT_POINTER:
            type = type_pointer_get_ref_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ARRAY:
            type = type_array_get_element_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ENUM:
            type = type_get_real_type(type);
            if (!type_is_complete(type))
            {
                error_loc_info(&arg->loc_info, "undefined type declaration \"enum %s\"\n", type->name);
            }
        case TGT_USER_TYPE:
        case TGT_IFACE_POINTER:
        case TGT_BASIC:
        case TGT_RANGE:
            /* nothing to do */
            break;
        }
    } while (more_to_do);
}

static void check_remoting_fields(const var_t *var, type_t *type)
{
    const var_t *field;
    const var_list_t *fields = NULL;

    type = type_get_real_type(type);

    if (type->checked)
        return;

    type->checked = TRUE;

    if (type_get_type(type) == TYPE_STRUCT)
    {
        if (type_is_complete(type))
            fields = type_struct_get_fields(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"struct %s\"\n", type->name);
    }
    else if (type_get_type(type) == TYPE_UNION || type_get_type(type) == TYPE_ENCAPSULATED_UNION)
    {
        if (type_is_complete(type))
            fields = type_union_get_cases(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"union %s\"\n", type->name);
    }

    if (fields) LIST_FOR_EACH_ENTRY( field, fields, const var_t, entry )
        if (field->declspec.type) check_field_common(type, type->name, field);
}

/* checks that arguments for a function make sense for marshalling and unmarshalling */
static void check_remoting_args(const var_t *func)
{
    const char *funcname = func->name;
    const var_t *arg;

    if (!type_function_get_args(func->declspec.type))
        return;

    LIST_FOR_EACH_ENTRY( arg, type_function_get_args(func->declspec.type), const var_t, entry )
    {
        const type_t *type = arg->declspec.type;

        /* check that [out] parameters have enough pointer levels */
        if (is_attr(arg->attrs, ATTR_OUT))
        {
            switch (typegen_detect_type(type, arg->attrs, TDT_ALL_TYPES))
            {
            case TGT_BASIC:
            case TGT_ENUM:
            case TGT_RANGE:
            case TGT_STRUCT:
            case TGT_UNION:
            case TGT_CTXT_HANDLE:
            case TGT_USER_TYPE:
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' is not a pointer\n", arg->name, funcname);
                break;
            case TGT_IFACE_POINTER:
                error_loc_info(&arg->loc_info, "out interface pointer \'%s\' of function \'%s\' is not a double pointer\n", arg->name, funcname);
                break;
            case TGT_STRING:
                if (is_array(type))
                {
                    /* needs conformance or fixed dimension */
                    if (type_array_has_conformance(type) &&
                        type_array_get_conformance(type)->type != EXPR_VOID) break;
                    if (!type_array_has_conformance(type) && type_array_get_dim(type)) break;
                }
                if (is_attr( arg->attrs, ATTR_IN )) break;
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' cannot be an unsized string\n", arg->name, funcname);
                break;
            case TGT_INVALID:
                /* already error'd before we get here */
            case TGT_CTXT_HANDLE_POINTER:
            case TGT_POINTER:
            case TGT_ARRAY:
                /* OK */
                break;
            }
        }

        check_field_common(func->declspec.type, funcname, arg);
    }

    if (type_get_type(type_function_get_rettype(func->declspec.type)) != TYPE_VOID)
    {
        var_t var;
        var = *func;
        var.declspec.type = type_function_get_rettype(func->declspec.type);
        var.name = xstrdup("return value");
        check_field_common(func->declspec.type, funcname, &var);
        free(var.name);
    }
}

static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func)
{
    unsigned char explicit_fc, implicit_fc;

    /* check for a defined binding handle */
    if (!get_func_handle_var( iface, func, &explicit_fc, &implicit_fc ) || !explicit_fc)
    {
        /* no explicit handle specified so add
         * "[in] handle_t IDL_handle" as the first parameter to the
         * function */
        var_t *idl_handle = make_var(xstrdup("IDL_handle"));
        idl_handle->attrs = append_attr(NULL, make_attr(ATTR_IN));
        idl_handle->declspec.type = find_type_or_error("handle_t");
        type_function_add_head_arg(func->declspec.type, idl_handle);
    }
}

static void check_functions(const type_t *iface, int is_inside_library)
{
    const statement_t *stmt;
    /* check for duplicates */
    if (is_attr(iface->attrs, ATTR_DISPINTERFACE))
    {
        var_list_t *methods = type_dispiface_get_methods(iface);
        var_t *func, *func_iter;

        if (methods) LIST_FOR_EACH_ENTRY( func, methods, var_t, entry )
        {
            LIST_FOR_EACH_ENTRY( func_iter, methods, var_t, entry )
            {
                if (func == func_iter) break;
                if (strcmp(func->name, func_iter->name)) continue;
                if (is_attr(func->attrs, ATTR_EVENTADD) != is_attr(func_iter->attrs, ATTR_EVENTADD)) continue;
                if (is_attr(func->attrs, ATTR_EVENTREMOVE) != is_attr(func_iter->attrs, ATTR_EVENTREMOVE)) continue;
                if (is_attr(func->attrs, ATTR_PROPGET) != is_attr(func_iter->attrs, ATTR_PROPGET)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUT) != is_attr(func_iter->attrs, ATTR_PROPPUT)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUTREF) != is_attr(func_iter->attrs, ATTR_PROPPUTREF)) continue;
                error_loc_info(&func->loc_info, "duplicated function \'%s\'\n", func->name);
            }
        }
    }
    if (is_attr(iface->attrs, ATTR_EXPLICIT_HANDLE))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            var_t *func = stmt->u.var;
            add_explicit_handle_if_necessary(iface, func);
        }
    }
    if (!is_inside_library && !is_attr(iface->attrs, ATTR_LOCAL))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            const var_t *func = stmt->u.var;
            if (!is_attr(func->attrs, ATTR_LOCAL))
                check_remoting_args(func);
        }
    }
}

static int async_iface_attrs(attr_list_t *attrs, const attr_t *attr)
{
    switch(attr->type)
    {
    case ATTR_UUID:
        return 0;
    case ATTR_ASYNCUUID:
        append_attr(attrs, make_attrp(ATTR_UUID, attr->u.pval));
        return 0;
    default:
        return 1;
    }
}

static int arg_in_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_OUT && attr->type != ATTR_RETVAL;
}

static int arg_out_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_IN;
}

static void check_async_uuid(type_t *iface)
{
    statement_list_t *stmts = NULL;
    statement_t *stmt;
    type_t *async_iface;
    type_t *inherit;

    if (!is_attr(iface->attrs, ATTR_ASYNCUUID)) return;

    inherit = type_iface_get_inherit(iface);
    if (inherit && strcmp(inherit->name, "IUnknown"))
        inherit = type_iface_get_async_iface(inherit);
    if (!inherit)
        error_loc("async_uuid applied to an interface with incompatible parent\n");

    async_iface = type_interface_declare(strmake("Async%s", iface->name), iface->namespace);

    STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
    {
        var_t *begin_func, *finish_func, *func = stmt->u.var, *arg;
        var_list_t *begin_args = NULL, *finish_args = NULL, *args;

        if (is_attr(func->attrs, ATTR_CALLAS)) continue;

        args = type_function_get_args(func->declspec.type);
        if (args) LIST_FOR_EACH_ENTRY(arg, args, var_t, entry)
        {
            if (is_attr(arg->attrs, ATTR_IN) || !is_attr(arg->attrs, ATTR_OUT))
                begin_args = append_var(begin_args, copy_var(arg, strdup(arg->name), arg_in_attrs));
            if (is_attr(arg->attrs, ATTR_OUT))
                finish_args = append_var(finish_args, copy_var(arg, strdup(arg->name), arg_out_attrs));
        }

        begin_func = copy_var(func, strmake("Begin_%s", func->name), NULL);
        begin_func->declspec.type = type_new_function(begin_args);
        begin_func->declspec.type->attrs = func->attrs;
        begin_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(begin_func));

        finish_func = copy_var(func, strmake("Finish_%s", func->name), NULL);
        finish_func->declspec.type = type_new_function(finish_args);
        finish_func->declspec.type->attrs = func->attrs;
        finish_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(finish_func));
    }

    type_interface_define(async_iface, map_attrs(iface->attrs, async_iface_attrs), inherit, stmts);
    iface->details.iface->async_iface = async_iface->details.iface->async_iface = async_iface;
}

static void check_statements(const statement_list_t *stmts, int is_inside_library)
{
    const statement_t *stmt;

    if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
    {
        switch(stmt->type) {
        case STMT_LIBRARY:
            check_statements(stmt->u.lib->stmts, TRUE);
            break;
        case STMT_TYPE:
            switch(type_get_type(stmt->u.type)) {
            case TYPE_INTERFACE:
                check_functions(stmt->u.type, is_inside_library);
                break;
            case TYPE_COCLASS:
                if(winrt_mode)
                    error_loc("coclass is not allowed in Windows Runtime mode\n");
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

static void check_all_user_types(const statement_list_t *stmts)
{
  const statement_t *stmt;
  const var_t *v;

  if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
  {
    if (stmt->type == STMT_LIBRARY)
      check_all_user_types(stmt->u.lib->stmts);
    else if (stmt->type == STMT_TYPE && type_get_type(stmt->u.type) == TYPE_INTERFACE &&
             !is_local(stmt->u.type->attrs))
    {
      const statement_t *stmt_func;
      STATEMENTS_FOR_EACH_FUNC(stmt_func, type_iface_get_stmts(stmt->u.type)) {
        const var_t *func = stmt_func->u.var;
        if (type_function_get_args(func->declspec.type))
          LIST_FOR_EACH_ENTRY( v, type_function_get_args(func->declspec.type), const var_t, entry )
            check_for_additional_prototype_types(v->declspec.type);
        check_for_additional_prototype_types(type_function_get_rettype(func->declspec.type));
      }
    }
  }
}

int is_valid_uuid(const char *s)
{
  int i;

  for (i = 0; i < 36; ++i)
    if (i == 8 || i == 13 || i == 18 || i == 23)
    {
      if (s[i] != '-')
        return FALSE;
    }
    else
      if (!isxdigit(s[i]))
        return FALSE;

  return s[i] == '\0';
}

static statement_t *make_statement(enum statement_type type)
{
    statement_t *stmt = xmalloc(sizeof(*stmt));
    stmt->type = type;
    return stmt;
}

static statement_t *make_statement_type_decl(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type = type;
    stmt->declonly = !type->defined;
    return stmt;
}

static statement_t *make_statement_reference(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPEREF);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_declaration(var_t *var)
{
    statement_t *stmt = make_statement(STMT_DECLARATION);
    stmt->u.var = var;
    if (var->declspec.stgclass == STG_EXTERN && var->eval)
        warning("'%s' initialised and declared extern\n", var->name);
    if (is_const_decl(var))
    {
        if (var->eval)
            reg_const(var);
    }
    else if (type_get_type(var->declspec.type) == TYPE_FUNCTION)
        check_function_attrs(var->name, var->attrs);
    else if (var->declspec.stgclass == STG_NONE || var->declspec.stgclass == STG_REGISTER)
        error_loc("instantiation of data is illegal\n");
    return stmt;
}

static statement_t *make_statement_library(typelib_t *typelib)
{
    statement_t *stmt = make_statement(STMT_LIBRARY);
    stmt->u.lib = typelib;
    return stmt;
}

static statement_t *make_statement_pragma(const char *str)
{
    statement_t *stmt = make_statement(STMT_PRAGMA);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_cppquote(const char *str)
{
    statement_t *stmt = make_statement(STMT_CPPQUOTE);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_importlib(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORTLIB);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_import(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORT);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_module(type_t *type)
{
    statement_t *stmt = make_statement(STMT_MODULE);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_typedef(declarator_list_t *decls, int declonly)
{
    declarator_t *decl, *next;
    statement_t *stmt;
    type_list_t **type_list;

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    type_list = &stmt->u.type_list;
    stmt->declonly = declonly;

    LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
    {
        var_t *var = decl->var;
        type_t *type = find_type_or_error(var->name);
        *type_list = xmalloc(sizeof(type_list_t));
        (*type_list)->type = type;
        (*type_list)->next = NULL;

        type_list = &(*type_list)->next;
        free(decl);
        free(var);
    }

    return stmt;
}

static statement_list_t *append_statements(statement_list_t *l1, statement_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static attr_list_t *append_attribs(attr_list_t *l1, attr_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt)
{
    if (!stmt) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &stmt->entry );
    return list;
}

void init_loc_info(loc_info_t *i)
{
    i->input_name = input_name ? input_name : "stdin";
    i->line_number = line_number;
    i->near_text = parser_text;
}
