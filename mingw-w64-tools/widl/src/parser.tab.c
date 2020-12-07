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
static type_t *find_type_or_error(const char *name, int t);
static type_t *find_type_or_error2(char *name, int t);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);
static void init_lookup_namespace(const char *name);
static void push_lookup_namespace(const char *name);

static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_member_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs);
const char *get_attr_display_name(enum attr_type type);
static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func);
static void check_def(const type_t *t);

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


#line 213 "tools/widl/parser.tab.c"

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
    tALLNODES = 282,               /* tALLNODES  */
    tALLOCATE = 283,               /* tALLOCATE  */
    tANNOTATION = 284,             /* tANNOTATION  */
    tAPICONTRACT = 285,            /* tAPICONTRACT  */
    tAPPOBJECT = 286,              /* tAPPOBJECT  */
    tASYNC = 287,                  /* tASYNC  */
    tASYNCUUID = 288,              /* tASYNCUUID  */
    tAUTOHANDLE = 289,             /* tAUTOHANDLE  */
    tBINDABLE = 290,               /* tBINDABLE  */
    tBOOLEAN = 291,                /* tBOOLEAN  */
    tBROADCAST = 292,              /* tBROADCAST  */
    tBYTE = 293,                   /* tBYTE  */
    tBYTECOUNT = 294,              /* tBYTECOUNT  */
    tCALLAS = 295,                 /* tCALLAS  */
    tCALLBACK = 296,               /* tCALLBACK  */
    tCASE = 297,                   /* tCASE  */
    tCDECL = 298,                  /* tCDECL  */
    tCHAR = 299,                   /* tCHAR  */
    tCOCLASS = 300,                /* tCOCLASS  */
    tCODE = 301,                   /* tCODE  */
    tCOMMSTATUS = 302,             /* tCOMMSTATUS  */
    tCONST = 303,                  /* tCONST  */
    tCONTEXTHANDLE = 304,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 305, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 306, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 307,               /* tCONTRACT  */
    tCONTRACTVERSION = 308,        /* tCONTRACTVERSION  */
    tCONTROL = 309,                /* tCONTROL  */
    tCPPQUOTE = 310,               /* tCPPQUOTE  */
    tCUSTOM = 311,                 /* tCUSTOM  */
    tDECODE = 312,                 /* tDECODE  */
    tDEFAULT = 313,                /* tDEFAULT  */
    tDEFAULTBIND = 314,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 315,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 316,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 317,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 318, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 319,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 320,          /* tDISPINTERFACE  */
    tDLLNAME = 321,                /* tDLLNAME  */
    tDONTFREE = 322,               /* tDONTFREE  */
    tDOUBLE = 323,                 /* tDOUBLE  */
    tDUAL = 324,                   /* tDUAL  */
    tENABLEALLOCATE = 325,         /* tENABLEALLOCATE  */
    tENCODE = 326,                 /* tENCODE  */
    tENDPOINT = 327,               /* tENDPOINT  */
    tENTRY = 328,                  /* tENTRY  */
    tENUM = 329,                   /* tENUM  */
    tERRORSTATUST = 330,           /* tERRORSTATUST  */
    tEXPLICITHANDLE = 331,         /* tEXPLICITHANDLE  */
    tEXTERN = 332,                 /* tEXTERN  */
    tFALSE = 333,                  /* tFALSE  */
    tFASTCALL = 334,               /* tFASTCALL  */
    tFAULTSTATUS = 335,            /* tFAULTSTATUS  */
    tFLOAT = 336,                  /* tFLOAT  */
    tFORCEALLOCATE = 337,          /* tFORCEALLOCATE  */
    tHANDLE = 338,                 /* tHANDLE  */
    tHANDLET = 339,                /* tHANDLET  */
    tHELPCONTEXT = 340,            /* tHELPCONTEXT  */
    tHELPFILE = 341,               /* tHELPFILE  */
    tHELPSTRING = 342,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 343,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 344,          /* tHELPSTRINGDLL  */
    tHIDDEN = 345,                 /* tHIDDEN  */
    tHYPER = 346,                  /* tHYPER  */
    tID = 347,                     /* tID  */
    tIDEMPOTENT = 348,             /* tIDEMPOTENT  */
    tIGNORE = 349,                 /* tIGNORE  */
    tIIDIS = 350,                  /* tIIDIS  */
    tIMMEDIATEBIND = 351,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 352,         /* tIMPLICITHANDLE  */
    tIMPORT = 353,                 /* tIMPORT  */
    tIMPORTLIB = 354,              /* tIMPORTLIB  */
    tIN = 355,                     /* tIN  */
    tIN_LINE = 356,                /* tIN_LINE  */
    tINLINE = 357,                 /* tINLINE  */
    tINPUTSYNC = 358,              /* tINPUTSYNC  */
    tINT = 359,                    /* tINT  */
    tINT32 = 360,                  /* tINT32  */
    tINT3264 = 361,                /* tINT3264  */
    tINT64 = 362,                  /* tINT64  */
    tINTERFACE = 363,              /* tINTERFACE  */
    tLCID = 364,                   /* tLCID  */
    tLENGTHIS = 365,               /* tLENGTHIS  */
    tLIBRARY = 366,                /* tLIBRARY  */
    tLICENSED = 367,               /* tLICENSED  */
    tLOCAL = 368,                  /* tLOCAL  */
    tLONG = 369,                   /* tLONG  */
    tMAYBE = 370,                  /* tMAYBE  */
    tMESSAGE = 371,                /* tMESSAGE  */
    tMETHODS = 372,                /* tMETHODS  */
    tMODULE = 373,                 /* tMODULE  */
    tNAMESPACE = 374,              /* tNAMESPACE  */
    tNOCODE = 375,                 /* tNOCODE  */
    tNONBROWSABLE = 376,           /* tNONBROWSABLE  */
    tNONCREATABLE = 377,           /* tNONCREATABLE  */
    tNONEXTENSIBLE = 378,          /* tNONEXTENSIBLE  */
    tNOTIFY = 379,                 /* tNOTIFY  */
    tNOTIFYFLAG = 380,             /* tNOTIFYFLAG  */
    tNULL = 381,                   /* tNULL  */
    tOBJECT = 382,                 /* tOBJECT  */
    tODL = 383,                    /* tODL  */
    tOLEAUTOMATION = 384,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 385,               /* tOPTIMIZE  */
    tOPTIONAL = 386,               /* tOPTIONAL  */
    tOUT = 387,                    /* tOUT  */
    tPARTIALIGNORE = 388,          /* tPARTIALIGNORE  */
    tPASCAL = 389,                 /* tPASCAL  */
    tPOINTERDEFAULT = 390,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 391,         /* tPRAGMA_WARNING  */
    tPROGID = 392,                 /* tPROGID  */
    tPROPERTIES = 393,             /* tPROPERTIES  */
    tPROPGET = 394,                /* tPROPGET  */
    tPROPPUT = 395,                /* tPROPPUT  */
    tPROPPUTREF = 396,             /* tPROPPUTREF  */
    tPROXY = 397,                  /* tPROXY  */
    tPTR = 398,                    /* tPTR  */
    tPUBLIC = 399,                 /* tPUBLIC  */
    tRANGE = 400,                  /* tRANGE  */
    tREADONLY = 401,               /* tREADONLY  */
    tREF = 402,                    /* tREF  */
    tREGISTER = 403,               /* tREGISTER  */
    tREPRESENTAS = 404,            /* tREPRESENTAS  */
    tREQUESTEDIT = 405,            /* tREQUESTEDIT  */
    tRESTRICTED = 406,             /* tRESTRICTED  */
    tRETVAL = 407,                 /* tRETVAL  */
    tSAFEARRAY = 408,              /* tSAFEARRAY  */
    tSHORT = 409,                  /* tSHORT  */
    tSIGNED = 410,                 /* tSIGNED  */
    tSINGLENODE = 411,             /* tSINGLENODE  */
    tSIZEIS = 412,                 /* tSIZEIS  */
    tSIZEOF = 413,                 /* tSIZEOF  */
    tSMALL = 414,                  /* tSMALL  */
    tSOURCE = 415,                 /* tSOURCE  */
    tSTATIC = 416,                 /* tSTATIC  */
    tSTDCALL = 417,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 418,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 419,                 /* tSTRING  */
    tSTRUCT = 420,                 /* tSTRUCT  */
    tSWITCH = 421,                 /* tSWITCH  */
    tSWITCHIS = 422,               /* tSWITCHIS  */
    tSWITCHTYPE = 423,             /* tSWITCHTYPE  */
    tTHREADING = 424,              /* tTHREADING  */
    tTRANSMITAS = 425,             /* tTRANSMITAS  */
    tTRUE = 426,                   /* tTRUE  */
    tTYPEDEF = 427,                /* tTYPEDEF  */
    tUIDEFAULT = 428,              /* tUIDEFAULT  */
    tUNION = 429,                  /* tUNION  */
    tUNIQUE = 430,                 /* tUNIQUE  */
    tUNSIGNED = 431,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 432,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 433,            /* tUSERMARSHAL  */
    tUUID = 434,                   /* tUUID  */
    tV1ENUM = 435,                 /* tV1ENUM  */
    tVARARG = 436,                 /* tVARARG  */
    tVERSION = 437,                /* tVERSION  */
    tVIPROGID = 438,               /* tVIPROGID  */
    tVOID = 439,                   /* tVOID  */
    tWCHAR = 440,                  /* tWCHAR  */
    tWIREMARSHAL = 441,            /* tWIREMARSHAL  */
    tAPARTMENT = 442,              /* tAPARTMENT  */
    tNEUTRAL = 443,                /* tNEUTRAL  */
    tSINGLE = 444,                 /* tSINGLE  */
    tFREE = 445,                   /* tFREE  */
    tBOTH = 446,                   /* tBOTH  */
    CAST = 447,                    /* CAST  */
    PPTR = 448,                    /* PPTR  */
    POS = 449,                     /* POS  */
    NEG = 450,                     /* NEG  */
    ADDRESSOF = 451                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "tools/widl/parser.y"

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

#line 485 "tools/widl/parser.tab.c"

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
  YYSYMBOL_tALLNODES = 27,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 28,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 29,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 30,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 31,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 32,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 33,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 34,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 35,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 36,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 37,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 38,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 39,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 40,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 41,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 42,                     /* tCASE  */
  YYSYMBOL_tCDECL = 43,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 44,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 45,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 46,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 47,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 48,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 49,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 50, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 51,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 52,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 53,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 54,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 55,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 56,                   /* tCUSTOM  */
  YYSYMBOL_tDECODE = 57,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 58,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 59,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 60,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 61,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 62,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 63,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 64,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 65,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 66,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 67,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 68,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 69,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 70,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 71,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 72,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 73,                    /* tENTRY  */
  YYSYMBOL_tENUM = 74,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 75,             /* tERRORSTATUST  */
  YYSYMBOL_tEXPLICITHANDLE = 76,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 77,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 78,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 79,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 80,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLOAT = 81,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 82,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 83,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 84,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 85,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 86,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 87,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 88,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 89,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 90,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 91,                    /* tHYPER  */
  YYSYMBOL_tID = 92,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 93,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 94,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 95,                    /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 96,            /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 97,           /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 98,                   /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 99,                /* tIMPORTLIB  */
  YYSYMBOL_tIN = 100,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 101,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 102,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 103,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 104,                     /* tINT  */
  YYSYMBOL_tINT32 = 105,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 106,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 107,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 108,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 109,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 110,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 111,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 112,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 113,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 114,                    /* tLONG  */
  YYSYMBOL_tMAYBE = 115,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 116,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 117,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 118,                  /* tMODULE  */
  YYSYMBOL_tNAMESPACE = 119,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 120,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 121,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 122,            /* tNONCREATABLE  */
  YYSYMBOL_tNONEXTENSIBLE = 123,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 124,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 125,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 126,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 127,                  /* tOBJECT  */
  YYSYMBOL_tODL = 128,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 129,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 130,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 131,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 132,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 133,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 134,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 135,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 136,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 137,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 138,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 139,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 140,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 141,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 142,                   /* tPROXY  */
  YYSYMBOL_tPTR = 143,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 144,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 145,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 146,                /* tREADONLY  */
  YYSYMBOL_tREF = 147,                     /* tREF  */
  YYSYMBOL_tREGISTER = 148,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 149,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 150,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 151,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 152,                  /* tRETVAL  */
  YYSYMBOL_tSAFEARRAY = 153,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 154,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 155,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 156,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 157,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 158,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 159,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 160,                  /* tSOURCE  */
  YYSYMBOL_tSTATIC = 161,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 162,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 163,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 164,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 165,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 166,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 167,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 168,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 169,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 170,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 171,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 172,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 173,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 174,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 175,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 176,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 177,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 178,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 179,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 180,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 181,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 182,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 183,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 184,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 185,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 186,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 187,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 188,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 189,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 190,                    /* tFREE  */
  YYSYMBOL_tBOTH = 191,                    /* tBOTH  */
  YYSYMBOL_192_ = 192,                     /* ','  */
  YYSYMBOL_193_ = 193,                     /* '?'  */
  YYSYMBOL_194_ = 194,                     /* ':'  */
  YYSYMBOL_195_ = 195,                     /* '|'  */
  YYSYMBOL_196_ = 196,                     /* '^'  */
  YYSYMBOL_197_ = 197,                     /* '&'  */
  YYSYMBOL_198_ = 198,                     /* '<'  */
  YYSYMBOL_199_ = 199,                     /* '>'  */
  YYSYMBOL_200_ = 200,                     /* '-'  */
  YYSYMBOL_201_ = 201,                     /* '+'  */
  YYSYMBOL_202_ = 202,                     /* '*'  */
  YYSYMBOL_203_ = 203,                     /* '/'  */
  YYSYMBOL_204_ = 204,                     /* '%'  */
  YYSYMBOL_205_ = 205,                     /* '!'  */
  YYSYMBOL_206_ = 206,                     /* '~'  */
  YYSYMBOL_CAST = 207,                     /* CAST  */
  YYSYMBOL_PPTR = 208,                     /* PPTR  */
  YYSYMBOL_POS = 209,                      /* POS  */
  YYSYMBOL_NEG = 210,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 211,                /* ADDRESSOF  */
  YYSYMBOL_212_ = 212,                     /* '.'  */
  YYSYMBOL_213_ = 213,                     /* '['  */
  YYSYMBOL_214_ = 214,                     /* ']'  */
  YYSYMBOL_215_ = 215,                     /* '{'  */
  YYSYMBOL_216_ = 216,                     /* '}'  */
  YYSYMBOL_217_ = 217,                     /* ';'  */
  YYSYMBOL_218_ = 218,                     /* '('  */
  YYSYMBOL_219_ = 219,                     /* ')'  */
  YYSYMBOL_220_ = 220,                     /* '='  */
  YYSYMBOL_YYACCEPT = 221,                 /* $accept  */
  YYSYMBOL_input = 222,                    /* input  */
  YYSYMBOL_m_acf = 223,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 224,           /* gbl_statements  */
  YYSYMBOL_225_1 = 225,                    /* $@1  */
  YYSYMBOL_imp_statements = 226,           /* imp_statements  */
  YYSYMBOL_227_2 = 227,                    /* $@2  */
  YYSYMBOL_int_statements = 228,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 229,            /* semicolon_opt  */
  YYSYMBOL_statement = 230,                /* statement  */
  YYSYMBOL_pragma_warning = 231,           /* pragma_warning  */
  YYSYMBOL_warnings = 232,                 /* warnings  */
  YYSYMBOL_typedecl = 233,                 /* typedecl  */
  YYSYMBOL_cppquote = 234,                 /* cppquote  */
  YYSYMBOL_import_start = 235,             /* import_start  */
  YYSYMBOL_import = 236,                   /* import  */
  YYSYMBOL_importlib = 237,                /* importlib  */
  YYSYMBOL_libraryhdr = 238,               /* libraryhdr  */
  YYSYMBOL_library_start = 239,            /* library_start  */
  YYSYMBOL_librarydef = 240,               /* librarydef  */
  YYSYMBOL_m_args = 241,                   /* m_args  */
  YYSYMBOL_arg_list = 242,                 /* arg_list  */
  YYSYMBOL_args = 243,                     /* args  */
  YYSYMBOL_arg = 244,                      /* arg  */
  YYSYMBOL_array = 245,                    /* array  */
  YYSYMBOL_m_attributes = 246,             /* m_attributes  */
  YYSYMBOL_attributes = 247,               /* attributes  */
  YYSYMBOL_attrib_list = 248,              /* attrib_list  */
  YYSYMBOL_str_list = 249,                 /* str_list  */
  YYSYMBOL_contract_ver = 250,             /* contract_ver  */
  YYSYMBOL_contract_req = 251,             /* contract_req  */
  YYSYMBOL_attribute = 252,                /* attribute  */
  YYSYMBOL_uuid_string = 253,              /* uuid_string  */
  YYSYMBOL_callconv = 254,                 /* callconv  */
  YYSYMBOL_cases = 255,                    /* cases  */
  YYSYMBOL_case = 256,                     /* case  */
  YYSYMBOL_enums = 257,                    /* enums  */
  YYSYMBOL_enum_list = 258,                /* enum_list  */
  YYSYMBOL_enum_member = 259,              /* enum_member  */
  YYSYMBOL_enum = 260,                     /* enum  */
  YYSYMBOL_enumdef = 261,                  /* enumdef  */
  YYSYMBOL_m_exprs = 262,                  /* m_exprs  */
  YYSYMBOL_m_expr = 263,                   /* m_expr  */
  YYSYMBOL_expr = 264,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 265,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 266,           /* expr_int_const  */
  YYSYMBOL_expr_const = 267,               /* expr_const  */
  YYSYMBOL_fields = 268,                   /* fields  */
  YYSYMBOL_field = 269,                    /* field  */
  YYSYMBOL_ne_union_field = 270,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 271,          /* ne_union_fields  */
  YYSYMBOL_union_field = 272,              /* union_field  */
  YYSYMBOL_s_field = 273,                  /* s_field  */
  YYSYMBOL_funcdef = 274,                  /* funcdef  */
  YYSYMBOL_declaration = 275,              /* declaration  */
  YYSYMBOL_m_ident = 276,                  /* m_ident  */
  YYSYMBOL_t_ident = 277,                  /* t_ident  */
  YYSYMBOL_ident = 278,                    /* ident  */
  YYSYMBOL_base_type = 279,                /* base_type  */
  YYSYMBOL_m_int = 280,                    /* m_int  */
  YYSYMBOL_int_std = 281,                  /* int_std  */
  YYSYMBOL_qualified_seq = 282,            /* qualified_seq  */
  YYSYMBOL_283_3 = 283,                    /* $@3  */
  YYSYMBOL_qualified_type = 284,           /* qualified_type  */
  YYSYMBOL_285_4 = 285,                    /* $@4  */
  YYSYMBOL_coclass = 286,                  /* coclass  */
  YYSYMBOL_coclasshdr = 287,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 288,               /* coclassdef  */
  YYSYMBOL_apicontract = 289,              /* apicontract  */
  YYSYMBOL_namespacedef = 290,             /* namespacedef  */
  YYSYMBOL_coclass_ints = 291,             /* coclass_ints  */
  YYSYMBOL_coclass_int = 292,              /* coclass_int  */
  YYSYMBOL_dispinterface = 293,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 294,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 295,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 296,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 297,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 298,                  /* inherit  */
  YYSYMBOL_interface = 299,                /* interface  */
  YYSYMBOL_interfacehdr = 300,             /* interfacehdr  */
  YYSYMBOL_interfacedef = 301,             /* interfacedef  */
  YYSYMBOL_interfacedec = 302,             /* interfacedec  */
  YYSYMBOL_module = 303,                   /* module  */
  YYSYMBOL_modulehdr = 304,                /* modulehdr  */
  YYSYMBOL_moduledef = 305,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 306,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 307,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 308,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 309,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 310,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 311,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 312,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 313,               /* declarator  */
  YYSYMBOL_direct_declarator = 314,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 315,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 316, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 317,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 318, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 319,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 320, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 321,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 322,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 323,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 324,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 325,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 326,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 327,          /* init_declarator  */
  YYSYMBOL_threading_type = 328,           /* threading_type  */
  YYSYMBOL_pointer_type = 329,             /* pointer_type  */
  YYSYMBOL_structdef = 330,                /* structdef  */
  YYSYMBOL_type = 331,                     /* type  */
  YYSYMBOL_typedef = 332,                  /* typedef  */
  YYSYMBOL_uniondef = 333,                 /* uniondef  */
  YYSYMBOL_version = 334,                  /* version  */
  YYSYMBOL_acf_statements = 335,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 336,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 337,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 338,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 339,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 340,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 341,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 342,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 343           /* allocate_option  */
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
#define YYLAST   3046

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  123
/* YYNRULES -- Number of rules.  */
#define YYNRULES  434
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  770

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   451


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
       2,     2,     2,   205,     2,     2,     2,   204,   197,     2,
     218,   219,   202,   201,   192,   200,   212,   203,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   194,   217,
     198,   220,   199,   193,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   213,     2,   214,   196,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   215,   195,   216,   206,     2,     2,     2,
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
     185,   186,   187,   188,   189,   190,   191,   207,   208,   209,
     210,   211
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   331,   331,   345,   345,   347,   348,   348,   350,   351,
     352,   355,   358,   360,   361,   362,   365,   366,   367,   367,
     369,   370,   371,   374,   376,   377,   378,   379,   382,   383,
     386,   387,   391,   392,   393,   394,   395,   396,   397,   400,
     411,   412,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   427,   429,   437,   443,   447,   448,   450,   454,   458,
     459,   462,   463,   466,   467,   471,   476,   483,   487,   488,
     491,   492,   496,   499,   500,   501,   504,   505,   509,   510,
     513,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   628,   629,   634,   635,   636,   637,
     640,   641,   644,   648,   654,   655,   656,   659,   663,   675,
     680,   684,   689,   692,   693,   696,   697,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   739,   741,   742,   745,   746,
     749,   755,   761,   762,   765,   770,   777,   778,   781,   782,
     786,   787,   790,   794,   800,   808,   812,   817,   818,   821,
     822,   823,   826,   828,   831,   832,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   844,   845,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   860,   861,   861,   865,
     866,   866,   869,   870,   878,   884,   888,   895,   896,   899,
     900,   904,   907,   908,   911,   920,   921,   924,   925,   928,
     934,   940,   941,   944,   945,   948,   955,   964,   969,   973,
     974,   977,   978,   981,   986,   993,   994,   995,   999,  1003,
    1006,  1007,  1010,  1011,  1015,  1016,  1020,  1021,  1022,  1026,
    1028,  1029,  1033,  1034,  1035,  1036,  1041,  1043,  1044,  1049,
    1051,  1055,  1056,  1061,  1062,  1063,  1064,  1068,  1076,  1078,
    1079,  1084,  1086,  1090,  1091,  1098,  1099,  1100,  1101,  1102,
    1106,  1113,  1114,  1117,  1118,  1121,  1128,  1129,  1134,  1135,
    1139,  1140,  1141,  1142,  1143,  1147,  1148,  1149,  1152,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1167,
    1174,  1176,  1182,  1183,  1184,  1188,  1189,  1193,  1194,  1198,
    1205,  1214,  1215,  1219,  1220,  1224,  1226,  1227,  1228,  1232,
    1233,  1238,  1239,  1240,  1241
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
  "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT", "tAPPOBJECT",
  "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN",
  "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE",
  "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE",
  "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL",
  "tFAULTSTATUS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT", "tODL",
  "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tPARTIALIGNORE",
  "tPASCAL", "tPOINTERDEFAULT", "tPRAGMA_WARNING", "tPROGID",
  "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF", "tPROXY", "tPTR",
  "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER", "tREPRESENTAS",
  "tREQUESTEDIT", "tRESTRICTED", "tRETVAL", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE",
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
  "contract_ver", "contract_req", "attribute", "uuid_string", "callconv",
  "cases", "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident", "t_ident",
  "ident", "base_type", "m_int", "int_std", "qualified_seq", "$@3",
  "qualified_type", "$@4", "coclass", "coclasshdr", "coclassdef",
  "apicontract", "namespacedef", "coclass_ints", "coclass_int",
  "dispinterface", "dispinterfacehdr", "dispint_props", "dispint_meths",
  "dispinterfacedef", "inherit", "interface", "interfacehdr",
  "interfacedef", "interfacedec", "module", "modulehdr", "moduledef",
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
     445,   446,    44,    63,    58,   124,    94,    38,    60,    62,
      45,    43,    42,    47,    37,    33,   126,   447,   448,   449,
     450,   451,    46,    91,    93,   123,   125,    59,    40,    41,
      61
};
#endif

#define YYPACT_NINF (-598)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-422)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -598,    80,  1572,  -598,  -598,  -598,  -112,   -69,  -598,  -598,
    -598,   175,  -598,   -79,   236,  -598,   244,  -598,  -598,  -598,
    -598,    48,   150,  -598,  -598,  -598,  -598,  -598,   283,    48,
     125,   -44,  -598,    -6,    48,   359,  -598,  -598,   294,   309,
     359,  -598,  -598,  2860,  -598,  -598,  -598,   -23,  -598,  -598,
    -598,  -598,  -598,    44,  2590,     8,     9,  -598,  -598,  -598,
      18,    33,  -598,    46,    56,    55,    83,    62,    66,    97,
    -598,  -598,    86,  -598,   356,   356,   356,    76,  2714,    85,
     356,    94,    99,  -598,    21,  -598,   -69,   211,  -598,  -598,
     310,  -598,  -598,   136,  -598,   137,  -598,  -598,   140,  -598,
    -598,  -598,  -598,  -598,   361,  2714,  -598,  -598,   144,   152,
    -113,   -97,  -598,  -598,   153,  -598,  -598,   154,  -598,  -598,
    -598,   164,   165,  -598,  -598,  -598,  -598,  -598,   169,   173,
    -598,   176,  -598,  -598,  -598,  -598,   184,  -598,  -598,  -598,
     188,  -598,  -598,  -598,   191,   194,  -598,  -598,  -598,  -598,
     195,   209,   210,   221,   224,  -598,   231,  -598,  -598,   233,
    -598,   237,  -598,  -598,   238,   249,  -598,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   251,
    -598,  -598,  -598,   253,   258,  -598,  -598,  -598,  -598,  -598,
    -598,   281,  -598,  -598,   282,  -598,  -598,  -598,   284,  -598,
    -598,  -598,   285,   287,   291,   293,  -598,  -598,  -598,   296,
     297,  -598,  -598,   298,   303,   304,   -66,  -598,  -598,  -598,
    1705,   867,   155,   374,   373,   385,   392,   395,   402,   232,
     245,  -598,  -598,  -598,  -598,    76,   295,   311,  -598,  -598,
    -598,  -598,  -598,  -598,   -45,  -598,  -598,  -598,   181,   286,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,    76,    76,  -598,   234,  -147,  -598,  -598,  -598,
     356,  -598,  -598,  -598,   420,   308,  -598,  -598,  -598,   -55,
    -598,  -598,   522,   312,   -81,  -598,   335,   313,  -598,   315,
    -598,   520,   178,   440,   728,  2625,   527,   178,   728,   525,
     526,   728,   728,   528,   530,   728,   531,   728,   728,  2123,
     728,   728,   533,   -48,   534,   728,  2714,   728,   728,  2714,
     247,  2714,  2714,   178,   159,   535,  2714,  2860,   324,  -598,
     328,  -598,  -598,  -598,   332,  -598,   333,   336,  -598,  -598,
    -598,    62,  2625,  -598,   337,   338,  -598,  -598,  -598,  -598,
     338,   -92,  -598,  -598,    -8,  -598,   360,   -59,   339,   340,
    -598,  -598,  1204,    42,   341,  -598,   728,   103,  2123,  -598,
    -598,   345,  -598,  -598,    27,    21,  -598,   344,  -598,   440,
     346,   369,   347,  -598,   557,  -598,    -7,   155,    24,   349,
    -598,  -598,   350,   351,  -598,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,  -598,   353,  -598,   728,   728,   728,   728,   728,
     728,   643,  2381,  -133,  -598,   357,   386,   376,   370,   399,
    2381,   371,   384,  -598,  -116,   387,   388,   389,   390,   393,
     401,   404,   563,   408,  2625,   208,   409,   -83,  -598,  2381,
     410,   411,   412,   426,   414,   -76,  2156,   415,  -598,  -598,
    -598,  -598,  -598,   416,   417,   418,   419,   427,  -598,   421,
     423,   425,  -598,  2860,   555,  -598,  -598,  -598,  -598,    76,
     405,    62,    -3,  -598,  1115,  -598,   451,  2625,   430,  1448,
     441,   506,  1239,    62,  -598,  2625,  -598,  -598,  -598,  -598,
     663,  -598,  2293,   437,   466,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,   -68,  -598,  -598,   433,  -598,  -598,    68,   728,
    -598,    26,  -598,  2625,  -598,   442,  -598,   443,  -598,   445,
    -598,  -598,  -598,  2625,     2,     2,     2,     2,     2,     2,
    2222,   239,   728,   728,   656,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   660,   728,   728,  -598,  -598,   527,   657,  -598,
     728,  -598,  -598,   658,  -598,  -598,  -598,  -598,  -598,  -598,
    -598,  -598,  -598,  -598,   208,  -598,  1794,  -598,   208,  -598,
    -598,  -598,  -141,  -598,   728,  -598,  -598,  -598,  -598,   728,
    -598,  -598,  -598,  -598,  -598,  -598,  -598,  -598,   662,  -598,
    -598,  -598,  -598,   448,  -598,  -598,   484,  -598,  -598,  -598,
    -598,  -598,    76,   229,  -598,  -598,  2625,   460,  -598,  -598,
    -598,    62,  -598,  -598,  -598,  -598,  2034,   420,    27,  -598,
     465,   464,   433,  -598,  -598,  -598,  -598,   208,   467,   440,
    -598,  -598,   239,  -598,  -598,  1914,  -598,   239,  -598,   463,
     -71,    64,    64,  -598,  1833,  1833,   413,   413,   398,  2247,
    2360,  2411,  1564,  1893,   413,   413,   143,   143,     2,     2,
       2,  -598,  2321,  -598,  -598,  -598,   469,  -598,  -598,    41,
    -598,   471,   208,   475,  -598,  2123,  -598,  -598,   478,  -598,
      62,   991,    76,  -598,  -598,  1328,  -598,  -598,  -598,  -598,
    -598,   680,  -598,  -598,   492,  -598,   -67,  -598,   485,  -598,
     480,   306,  -598,   482,   208,   486,  -598,   728,  2123,  -598,
     728,  -598,  -598,  -598,    41,  -598,  -598,  -598,   487,  -598,
    -598,  -598,  -598,    62,   490,   728,  -598,   208,  -598,  -598,
    -598,  -598,    41,  -598,  -598,  -598,     2,   491,  2381,  -598,
    -598,  -598,  -598,  -598,  -598,    15,  -598,  -598,   728,   509,
    -598,  -598,   515,  -130,  -130,  -598,  -598,   495,  -598,  -598
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    37,   299,     0,   415,   282,   274,
     293,     0,   339,     0,     0,   281,   269,   283,   335,   280,
     284,   285,     0,   338,   287,   294,   295,   292,     0,   285,
       0,     0,   337,     0,   285,     0,   289,   336,   269,   269,
     279,   399,   275,    81,     2,    15,    38,     0,    32,    16,
      35,    16,    14,     0,    71,   402,     0,   401,   276,   400,
       0,     0,    11,     0,     0,     0,     0,    30,     0,   321,
       9,     8,     0,    13,   344,   344,   344,     0,     0,   404,
     344,     0,   406,   300,     0,     4,   415,     0,   302,   303,
       0,   312,   313,   403,   271,     0,   286,   291,     0,   323,
     324,   290,   307,   308,     0,     0,   288,   277,   405,     0,
     407,     0,   278,    82,     0,    84,    85,     0,    86,    87,
      88,     0,     0,    91,    92,    93,    94,    95,     0,     0,
      98,     0,   100,   101,   102,   103,     0,   105,   106,   107,
       0,   109,   110,   111,     0,     0,   114,   115,   116,   117,
       0,     0,     0,     0,     0,   123,     0,   125,   126,     0,
     128,     0,   130,   131,   134,     0,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,     0,
     149,   150,   151,     0,     0,   154,   155,   156,   157,   397,
     158,     0,   160,   395,     0,   162,   163,   164,     0,   166,
     167,   168,     0,     0,     0,     0,   173,   396,   174,     0,
       0,   178,   179,     0,     0,     0,     0,    73,   183,    33,
      70,    70,    70,     0,   269,     0,     0,   269,   269,     0,
     402,   304,   314,   325,   333,     0,   404,   406,    34,    10,
     309,    12,     6,   330,     0,    31,   328,   329,     0,     0,
      28,   348,   345,   347,   346,   272,   273,   186,   187,   188,
     189,   340,     0,     0,   352,   388,   351,   266,   402,   404,
     344,   406,   342,    36,     0,     0,   427,   426,   428,     0,
     423,   416,     0,     0,    70,    52,     0,     0,   252,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    72,    53,
       0,    25,    26,    27,     0,    22,     0,     0,    20,    17,
      24,    30,     0,    71,     0,   403,    55,    56,   331,   332,
     405,   407,    57,   265,    70,     5,     0,    70,     0,     0,
     322,    28,    70,     0,     0,   350,     0,     0,    59,   354,
     343,     0,   296,   301,     0,     0,   422,     0,    51,     0,
       0,   196,   201,   197,     0,   408,    70,    70,    70,     0,
     185,   184,     0,     0,   216,   207,   208,   209,   213,   214,
     215,   210,   211,     0,   212,     0,     0,     0,     0,     0,
       0,     0,   250,     0,   248,     0,     0,    78,     0,     0,
     251,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   373,     0,     0,   203,   206,
       0,     0,     0,     0,     0,     0,     0,     0,   390,   391,
     392,   393,   394,     0,     0,     0,     0,   412,   414,     0,
       0,     0,    74,    81,     0,    21,    23,    18,    58,     0,
       0,    30,     0,   310,    70,   315,     0,     0,     0,     0,
       0,     0,    70,    30,    29,    71,   341,   349,   353,   389,
       0,    69,     0,     0,    63,    60,    61,   297,   433,   431,
     434,   432,     0,   429,   424,   417,   199,   202,    70,     0,
      40,     0,   398,     0,   253,     0,   410,    71,   259,     0,
      83,   177,    89,     0,   240,   239,   238,   241,   236,   237,
       0,   361,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    96,     0,     0,    97,
       0,   104,   108,     0,   112,   113,   118,   119,   120,   121,
     122,   124,   127,   129,   373,   340,    59,   378,   373,   375,
     374,    66,   370,   133,   205,   132,   148,   152,   153,     0,
     161,   165,   169,   170,   172,   171,   175,   176,     0,   180,
     181,   182,    75,     0,    16,   381,   409,   306,   305,   311,
       7,   317,     0,   404,   316,   319,     0,     0,   264,   320,
      28,    30,   334,    68,    67,   355,     0,     0,     0,   425,
     421,     0,   417,   198,   200,    41,    39,     0,   406,   267,
     257,   256,   361,   247,   340,    59,   365,   361,   362,     0,
     358,   229,   230,   242,   223,   224,   227,   228,   218,   219,
       0,   220,   221,   222,   226,   225,   232,   231,   234,   235,
     233,   243,     0,   249,    80,    79,     0,    77,    65,   373,
     340,     0,   373,     0,   369,    59,   377,   204,     0,   413,
      30,    70,     0,   262,   318,    70,   326,    64,    62,   298,
     430,     0,   420,   418,   383,   386,     0,   255,     0,   268,
       0,   361,   340,     0,   373,     0,   357,     0,    59,   364,
       0,   246,    99,   368,   373,   379,   372,   376,     0,   159,
      54,    19,   382,    30,     0,     0,   385,     0,   254,   190,
     245,   356,   373,   366,   360,   363,   244,     0,   217,   371,
     380,   327,   419,   384,   387,     0,   359,   367,     0,     0,
     411,   191,     0,    70,    70,   261,   193,     0,   192,   260
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -598,  -598,  -598,   358,  -598,   -46,  -598,  -350,  -325,     0,
    -598,  -598,  -598,  -598,  -598,   241,  -598,  -598,  -598,    11,
    -516,  -598,  -598,  -282,  -258,  -216,    -2,  -598,  -598,   157,
    -598,  -284,  -201,   -70,  -598,  -598,  -598,  -598,  -598,   207,
      13,   406,   135,  -210,  -598,  -279,  -291,  -598,  -598,  -598,
    -598,   -39,  -224,  -598,   250,  -598,    -4,   -73,  -598,   139,
     142,   101,  -598,   494,  -598,    10,  -598,    17,    19,    20,
    -598,  -598,   672,  -598,  -598,  -598,  -598,  -598,   -37,  -598,
      22,    16,  -598,  -598,    23,  -598,  -598,  -331,  -527,   -53,
     -38,   -24,  -233,  -598,  -598,  -598,  -577,  -598,  -597,  -598,
    -429,  -598,  -598,  -598,    -5,  -598,   498,  -598,   431,     1,
     -64,  -598,     7,  -598,   644,   111,  -598,  -598,   116,  -598,
     377,  -598,   123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    44,     2,   355,   220,   604,   362,   246,   331,
      46,   511,    47,    48,    49,    50,   332,   229,    51,   333,
     493,   494,   495,   496,   577,    53,   343,   216,   424,   418,
     415,   217,   392,   578,   755,   761,   380,   381,   382,   383,
     268,   437,   438,   412,   413,   414,   421,   386,   514,   518,
     388,   766,   767,   617,    56,   708,    95,   579,    57,    97,
      58,   373,   627,    59,   274,   334,    61,   335,   336,   337,
     354,   473,    65,    66,   357,   479,    67,   249,    68,    69,
     338,   339,   234,    72,   340,    74,    75,    76,   363,    77,
     251,    78,   265,   266,   648,   715,   649,   650,   580,   683,
     581,   582,   606,   736,   705,   706,   267,   453,   218,   269,
      80,    81,   271,   459,    85,   631,   632,    86,    87,   279,
     280,   502,   503
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   235,    45,    79,   264,   221,   342,   263,   369,    82,
     425,   482,    60,    52,   270,    55,   468,   233,    71,    62,
     534,    63,    64,   426,    70,    73,   429,   433,   431,   364,
     365,   436,   486,   635,   109,   111,   443,   253,   254,  -421,
     704,   287,   272,   462,   255,   255,   256,   256,   679,   275,
     252,   252,   252,  -270,   498,   236,   252,   758,   476,   554,
     681,   237,    14,    28,   231,   710,   367,   230,   379,   289,
     716,   368,   367,   759,  -270,   489,   563,   685,   276,   255,
       3,   256,   534,    43,   257,   257,   555,   765,   420,    12,
      12,   420,   277,   356,   499,   189,   419,   278,   432,   193,
      83,   439,  -270,   564,   -47,    28,   394,   439,   446,   584,
     395,   396,   397,   398,   399,   400,   584,   711,   290,   257,
     258,   258,   456,  -270,   628,   737,   327,   207,   102,   713,
     487,   103,    43,   478,   741,  -194,   585,   375,   472,    90,
     704,   477,   367,   591,    84,   678,   608,   718,   328,   684,
     738,   629,    96,   724,    43,   258,   420,   492,   622,   376,
      98,   534,   264,   515,   519,   263,   457,   458,   101,   728,
     513,   477,   477,   106,   104,   259,   259,   107,    88,   602,
      89,   401,   112,   500,   359,   742,     5,     6,   390,   264,
     264,   391,   263,   263,   219,   524,   525,   526,   527,   528,
     529,   530,   747,   260,   260,    43,    43,   358,   471,   512,
     259,   255,   105,   256,   552,   553,   222,   501,    54,    54,
     393,    79,    79,   109,   111,   -42,   238,    82,    82,   402,
     634,   760,   370,    55,    55,   239,   605,    43,   260,    91,
     516,    92,   416,   575,   261,   636,   252,    93,   240,    94,
     723,   257,   444,   726,   367,   447,   435,   454,   455,   576,
     262,   403,   461,   241,   547,   548,   549,   550,   551,   676,
     695,   242,   243,   646,   404,   673,   552,   553,   261,   245,
     527,    43,   257,   247,  -195,   744,    99,   258,   100,   469,
     264,   248,   379,   263,   262,   749,   696,   108,   244,    94,
     405,   250,   -44,   406,   407,   490,   506,   434,   409,   410,
     688,   273,   110,   756,    94,   435,   -46,   491,   258,   282,
     283,   411,   651,   652,   686,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   259,   672,   698,   549,   550,   551,   486,   257,
     420,  -270,   284,   -43,    12,   552,   553,   285,   531,  -270,
     485,   -45,   484,    79,   286,   730,   434,   288,    43,    82,
     260,   291,   292,   259,   439,    55,   345,   344,    94,   693,
     486,   574,   293,   294,   646,   258,   517,   295,   346,   646,
     347,   296,   719,   486,   297,   348,   264,   349,   350,   263,
      94,   260,   298,    10,    12,   351,   299,    94,   751,   300,
     575,   486,   301,   302,   532,   533,   534,   535,   536,   537,
     538,   367,   540,   371,   612,   372,   576,   303,   304,   532,
     533,   534,   235,    18,   448,   449,   450,   451,   452,   305,
     259,   644,   306,   255,   753,   256,  -263,   352,  -263,   307,
      21,   308,   367,   646,   366,   309,   310,   645,    23,   732,
     637,   647,   -48,    24,    25,    26,    27,   311,   260,   312,
     642,   313,    54,    29,    45,    79,   314,   616,   613,   762,
     485,    82,   484,    79,    60,    52,   236,    55,   609,    82,
      71,    62,   237,    63,    64,    55,    70,    73,   230,   315,
     316,   361,   317,   318,    32,   319,   682,   746,   644,   320,
     748,   321,   -49,    34,   322,   323,   324,    37,    36,   367,
     638,   325,   326,   435,   645,   420,   374,   377,   -50,   384,
     389,   378,   385,   387,   417,   422,   423,   463,   427,   264,
     428,   430,   263,   440,   442,   460,   464,   477,   477,   465,
     466,   467,   470,  -270,   475,   481,   480,   497,   691,   505,
     488,   508,   507,   235,   510,   603,   709,   509,   520,   521,
     522,   523,   647,   435,   434,   714,   556,   647,   557,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   558,   559,
     561,   560,   435,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   562,    22,   630,   565,   566,   567,   568,
     552,   553,   569,   547,   548,   549,   550,   551,   589,   264,
     570,   607,   263,   571,   434,   552,   553,   573,   583,   586,
     587,   588,   435,   590,   593,   594,   595,   596,   597,   598,
     599,   647,   600,   434,   601,   611,   394,   614,     5,     6,
     395,   396,   397,   398,   399,   400,   625,   619,   626,   653,
     640,   639,   641,   671,   675,   435,   394,   690,   677,   689,
     395,   396,   397,   398,   399,   400,   692,   694,    84,     8,
     702,     9,   717,   434,   707,   734,   735,    10,   722,    54,
     725,    12,    79,   485,   727,   484,    79,   729,    82,   740,
     739,   743,    82,   763,    55,   745,   750,   752,    55,   764,
     757,    15,   769,   474,   674,   633,   434,   224,    17,   687,
      18,   401,   620,   445,    19,   768,   232,    20,   699,   618,
     281,   394,   754,   353,    21,   395,   396,   397,   398,   399,
     400,   401,   360,   703,   441,    23,   701,    24,    25,    26,
      27,   700,   504,     0,     0,     0,   541,    29,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,     0,   402,
       0,     0,     0,     0,     0,   552,   553,     0,     0,     0,
       0,     0,   572,     0,     0,     0,     0,     0,     0,   402,
       0,    32,     0,     0,     0,     0,    33,    34,    35,     0,
       0,   403,    36,     0,    37,     0,   401,     0,   227,     0,
       0,     0,     0,     0,   404,     0,     0,   228,     0,    40,
       0,   403,     0,     0,     0,     0,     0,    41,    42,     0,
       0,     0,     0,     0,   404,     0,     0,     0,     0,     0,
     405,     0,     0,   406,   407,   408,     0,     0,   409,   410,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
     405,   411,     0,   406,   407,   408,     0,     0,   409,   410,
       0,     4,     5,     6,     0,     0,     0,   623,     0,     0,
       0,   411,     0,     0,     0,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
       0,     0,     0,     8,     0,     9,     0,     0,     0,     0,
       0,    10,    11,     0,     0,    12,     0,     0,     0,     0,
       0,     0,    13,     0,     0,   405,     0,     0,   406,   407,
     408,     0,    14,   409,   410,    15,     0,     0,     0,     0,
       0,    16,    17,     0,    18,     0,   411,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,   330,     0,     0,    23,
       0,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,     0,     0,     0,    36,     8,    37,     9,
       0,     0,    38,     0,     0,    10,    11,     0,     0,    12,
       0,    39,     0,    40,     0,     0,    13,     0,     0,     0,
       0,    41,    42,     0,     0,     0,    14,     0,     0,    15,
       0,     0,     0,     0,     0,    16,    17,     0,    18,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,     0,
      43,     0,    21,   341,     0,     0,     0,     0,     0,    22,
     330,     0,     0,    23,     0,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    33,    34,    35,     0,     0,     0,
      36,     8,    37,     9,     0,     0,    38,     0,     0,    10,
      11,     0,     0,    12,     0,    39,     0,    40,     0,     0,
      13,     0,     0,     0,     0,    41,    42,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,     0,    16,
      17,     0,    18,     0,     0,     0,    19,     0,     0,    20,
       0,     0,     0,     0,    43,     0,    21,   731,     4,     5,
       6,     0,     0,    22,     0,     0,     0,    23,     0,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       8,     0,     9,     4,     5,     6,     0,     0,    10,     0,
       0,    31,    12,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,    32,     0,     0,     0,     0,    33,    34,
      35,     0,    15,     0,    36,     8,    37,     9,    16,    17,
      38,    18,     0,    10,     0,    19,     0,    12,    20,    39,
       0,    40,     0,     0,    13,    21,     0,     0,     0,    41,
      42,     0,    22,     0,     0,     0,    23,    15,    24,    25,
      26,    27,     0,    16,    17,     0,    18,     0,    29,     0,
      19,     0,     0,    20,     0,     0,     0,     0,    43,     0,
      21,   610,     4,     5,     6,     0,     0,    22,     0,     0,
      31,    23,     0,    24,    25,    26,    27,     0,     0,     0,
       0,     0,    32,    29,     0,     0,     0,    33,    34,    35,
       0,     0,     0,    36,     8,    37,     9,     0,     0,    38,
       0,     0,    10,     0,     0,    31,    12,     0,    39,     0,
      40,     0,     0,    13,     0,     0,     0,    32,    41,    42,
       0,     0,    33,    34,    35,     0,    15,     0,    36,     0,
      37,     0,    16,    17,    38,    18,     0,     0,     0,    19,
       0,     0,    20,    39,     0,    40,     0,    43,     0,    21,
     483,     0,     0,    41,    42,     0,    22,     0,     0,     0,
      23,     0,    24,    25,    26,    27,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     5,     6,   621,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,    33,    34,    35,     8,     0,     9,    36,     0,    37,
       0,     0,    10,    38,     0,     0,    12,     0,     0,     0,
       0,     0,    39,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,     0,    15,     0,     0,     0,
       0,     0,   224,    17,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,    43,     0,     0,   733,     0,     0,     0,     0,     0,
      23,     0,    24,    25,    26,    27,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
     532,   533,   534,   535,   536,   537,   538,     7,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,    33,    34,    35,     0,     0,     0,    36,     8,    37,
       9,     0,     0,   227,     0,     0,    10,    11,     0,     0,
      12,     0,   228,     0,    40,     0,     0,    13,     0,     0,
       0,     0,    41,    42,     0,     0,     0,    14,     0,     0,
      15,     0,     0,     0,     0,     0,    16,    17,     0,    18,
       0,     0,     0,    19,     0,     0,    20,     0,     0,     0,
       0,    43,     0,    21,   615,     0,     0,     0,     0,     0,
      22,     0,     0,     0,    23,     0,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,   329,
      32,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,    36,     0,    37,     0,     0,     0,    38,     0,     0,
       0,     8,     0,     9,   -70,     0,    39,     0,    40,    10,
      11,     0,     0,    12,     0,     0,    41,    42,     0,     0,
      13,   544,   545,   546,   547,   548,   549,   550,   551,     0,
      14,     0,     0,    15,     0,     0,   552,   553,     0,    16,
      17,     0,    18,     0,     0,    43,    19,     0,     0,    20,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     5,
       6,     0,     0,    22,   330,     0,     0,    23,     0,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       8,     0,     9,     0,     0,     0,     0,   257,    10,     0,
       0,    31,    12,     0,     0,     0,     0,     0,     0,   532,
     533,   534,     0,    32,   537,   538,     0,     0,    33,    34,
      35,     0,    15,     0,    36,     0,    37,     0,   224,    17,
      38,    18,     0,   258,     0,    19,     0,     0,    20,    39,
       0,    40,     0,     0,     0,    21,     0,     0,     0,    41,
      42,     0,     0,     0,     0,     0,    23,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,   532,
     533,   534,   535,   536,   537,   538,     0,     0,    43,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,    33,    34,    35,
       8,     0,     9,    36,     0,    37,   260,   257,    10,   227,
       0,     0,    12,     0,     0,     0,     0,     0,   228,     0,
      40,     0,     0,     0,     0,     0,     0,     0,    41,    42,
       0,     0,    15,     0,     0,     0,     0,     0,   224,    17,
       0,    18,     0,   258,     0,    19,   680,     0,    20,     0,
       0,     0,     0,     0,     0,    21,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,   545,   546,   547,   548,   549,   550,   551,     0,     5,
       6,     0,     0,     0,     0,   552,   553,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   697,
       0,     0,    32,     0,     0,     0,     0,    33,    34,    35,
       8,     0,     9,    36,     0,    37,   260,     0,    10,   227,
       0,     0,    12,     0,     0,     0,     0,     0,   228,     0,
      40,   545,   546,   547,   548,   549,   550,   551,    41,    42,
       0,     0,    15,     0,     0,   552,   553,     0,   224,    17,
       0,    18,     0,     0,     0,    19,   712,     0,    20,     0,
       0,     0,     0,     0,     0,    21,     0,    43,     5,     6,
       0,     0,     0,     0,     0,     0,    23,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,    12,   532,   533,   534,   535,   536,   537,   538,   539,
     540,     0,    32,     0,     0,     0,     0,    33,    34,    35,
       0,    15,     0,    36,     0,    37,     0,   224,    17,   227,
      18,     0,     0,     0,    19,     0,     0,    20,   228,     0,
      40,     0,     0,     0,    21,     0,     0,     0,    41,    42,
       0,     0,     0,     0,     0,    23,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,    29,   532,   533,
     534,   535,   536,   537,   538,   539,   540,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,   533,   534,   535,   536,   537,   538,
       0,    32,     0,     0,     0,     0,    33,    34,    35,     0,
       0,     0,    36,     0,    37,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   228,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    41,    42,   532,
     533,   534,   535,   536,   537,   538,   539,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,   532,   533,   534,
     535,   536,   537,   538,   539,   540,     0,     0,     0,   541,
       0,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,     0,     0,     0,     0,     0,     0,     0,   552,   553,
       0,     0,     0,     0,     0,   592,   532,   533,   534,   535,
     536,   537,   538,   539,   540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,   533,   534,
     535,   536,   537,   538,   539,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   541,     0,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   532,   533,   534,
     535,   536,   537,   538,   552,   553,     0,     0,     0,     0,
       0,   643,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,     0,     0,     0,     0,     0,     0,     0,   552,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541,     0,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,     0,     0,
       0,     0,     0,     0,     0,   552,   553,   624,     0,     0,
       0,     0,     0,     0,   541,     0,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,     0,     0,     0,     0,
       0,     0,     0,   552,   553,   721,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   541,   720,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,     0,     0,     0,     0,     0,
       0,     0,   552,   553,   541,     0,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,     0,     0,     0,     0,
       0,     0,     0,   552,   553,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,   544,   545,
     546,   547,   548,   549,   550,   551,     0,     0,     0,     0,
     223,     0,     0,   552,   553,     0,     8,     0,     9,     0,
       5,     6,     0,     0,    10,    11,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,     0,
       0,     8,     0,     9,   224,    17,     0,    18,     0,    10,
       0,    19,     0,    12,    20,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    15,    24,    25,    26,    27,    28,   224,
      17,   225,    18,     0,    29,     0,    19,     0,   226,    20,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,    23,     0,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    32,    29,
       0,     0,     0,    33,    34,    35,     0,     0,     0,    36,
       8,    37,     9,     0,     0,   227,     0,     0,    10,     0,
       0,     0,     0,     0,   228,     0,    40,     0,     0,     0,
       0,     0,     0,    32,    41,    42,     0,     0,    33,    34,
      35,     0,    15,     0,    36,     0,    37,     0,   224,    17,
     227,     0,     0,     0,     0,    19,     0,     0,    20,   228,
       0,    40,     0,     0,     0,    21,     0,     0,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,    36,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,     0,   113,     0,   228,   114,
      40,   115,   116,   117,   118,   119,     0,   120,    41,    42,
     121,     0,   122,     0,     0,     0,   123,   124,     0,   125,
     126,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   140,     0,     0,   141,
     142,   143,   144,   145,     0,     0,   146,     0,     0,     0,
     147,     0,   148,   149,     0,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,     0,     0,
     162,     0,     0,   163,     0,     0,     0,     0,     0,   164,
     165,     0,   166,   167,     0,   168,   169,     0,     0,     0,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,     0,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,   194,
     195,   196,   197,     0,     0,     0,     0,   198,     0,     0,
     199,     0,     0,   200,   201,     0,     0,   202,   203,   204,
     205,     0,     0,   206,     0,   207,     0,   208,   209,   210,
     211,   212,   213,   214,     0,     0,   215
};

static const yytype_int16 yycheck[] =
{
       2,    54,     2,     2,    77,    51,   222,    77,   266,     2,
     301,   361,     2,     2,    78,     2,   341,    54,     2,     2,
      18,     2,     2,   302,     2,     2,   305,   309,   307,   262,
     263,   310,   363,     7,    38,    39,   315,    75,    76,   108,
     637,   105,    80,   327,     3,     3,     5,     5,   575,    28,
      74,    75,    76,   166,    27,    54,    80,    42,   117,   192,
     576,    54,    65,   108,    54,   642,   213,    54,   284,   166,
     647,   218,   213,    58,   166,   366,   192,   218,    57,     3,
       0,     5,    18,   213,    43,    43,   219,   217,   298,    48,
      48,   301,    71,   138,    67,   143,   297,    76,   308,   147,
     212,   311,   215,   219,   217,   108,     3,   317,   318,   192,
       7,     8,     9,    10,    11,    12,   192,   644,   215,    43,
      79,    79,   323,   215,   192,   192,   192,   175,     3,   645,
     363,     6,   213,   357,   711,   216,   219,   192,   354,   218,
     737,   357,   213,   219,   213,   574,   471,   218,   214,   578,
     217,   219,   104,   680,   213,    79,   366,   367,   483,   214,
      10,    18,   235,   387,   388,   235,     7,     8,    29,   685,
     386,   387,   388,    34,   218,   134,   134,    35,     3,   463,
       5,    78,    40,   156,     3,   712,     5,     6,    10,   262,
     263,    13,   262,   263,   217,   405,   406,   407,   408,   409,
     410,   411,   718,   162,   162,   213,   213,   244,   216,   216,
     134,     3,   218,     5,   212,   213,   172,   190,   220,   221,
     293,   220,   221,   227,   228,   217,   217,   220,   221,   126,
     509,   216,   270,   220,   221,   217,   469,   213,   162,     3,
     216,     5,   295,   202,   202,   219,   270,     3,   215,     5,
     679,    43,   316,   682,   213,   319,   309,   321,   322,   218,
     218,   158,   326,   217,   200,   201,   202,   203,   204,   560,
     620,   215,   217,   531,   171,   554,   212,   213,   202,   217,
     490,   213,    43,   217,   216,   714,     3,    79,     5,   342,
     363,   194,   508,   363,   218,   724,   621,     3,   215,     5,
     197,   215,   217,   200,   201,   202,   379,   309,   205,   206,
     589,   217,     3,   742,     5,   368,   217,   214,    79,   108,
      10,   218,   532,   533,   582,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   134,   553,   626,   202,   203,   204,   679,    43,
     560,   215,   215,   217,    48,   212,   213,   217,   411,   215,
     362,   217,   362,   362,     3,   690,   368,   215,   213,   362,
     162,   218,   218,   134,   584,   362,     3,     3,     5,   612,
     711,   434,   218,   218,   642,    79,   388,   218,     3,   647,
       5,   218,   650,   724,   218,     3,   469,     5,     3,   469,
       5,   162,   218,    44,    48,     3,   218,     5,   733,   218,
     202,   742,   218,   218,    16,    17,    18,    19,    20,    21,
      22,   213,    24,     3,   477,     5,   218,   218,   218,    16,
      17,    18,   485,    77,   187,   188,   189,   190,   191,   218,
     134,   202,   218,     3,   735,     5,   217,   215,   219,   218,
      91,   218,   213,   711,   220,   218,   218,   218,   102,   692,
     513,   531,   217,   104,   105,   106,   107,   218,   162,   218,
     523,   218,   474,   114,   474,   474,   218,   479,   477,   758,
     482,   474,   482,   482,   474,   474,   485,   474,   472,   482,
     474,   474,   485,   474,   474,   482,   474,   474,   485,   218,
     218,   215,   218,   218,   148,   218,   576,   717,   202,   218,
     720,   218,   217,   154,   218,   218,   218,   161,   159,   213,
     513,   218,   218,   576,   218,   735,   218,     5,   217,   194,
      10,   219,   219,   218,     7,    10,    10,   213,    10,   612,
      10,    10,   612,    10,    10,    10,   218,   763,   764,   217,
     217,   215,   215,   215,   194,   215,   217,   212,   604,   215,
     219,   192,   216,   616,     7,    10,   639,   220,   219,   219,
     219,   218,   642,   626,   576,   645,   219,   647,   192,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   212,   219,
     219,   192,   645,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   219,    98,   172,   219,   219,   219,   219,
     212,   213,   219,   200,   201,   202,   203,   204,   192,   692,
     219,   216,   692,   219,   626,   212,   213,   219,   219,   219,
     219,   219,   685,   219,   219,   219,   219,   219,   219,   212,
     219,   711,   219,   645,   219,   194,     3,   217,     5,     6,
       7,     8,     9,    10,    11,    12,   219,   216,   192,     3,
     217,   219,   217,     3,     7,   718,     3,   219,    10,     7,
       7,     8,     9,    10,    11,    12,   192,   217,   213,    36,
     216,    38,   219,   685,   217,     5,   194,    44,   219,   691,
     219,    48,   691,   695,   219,   695,   695,   219,   691,   219,
     215,   219,   695,   194,   691,   219,   219,   217,   695,   194,
     219,    68,   217,   355,   557,   508,   718,    74,    75,   584,
      77,    78,   481,   317,    81,   764,    54,    84,   627,   479,
      86,     3,   737,   235,    91,     7,     8,     9,    10,    11,
      12,    78,   248,   632,   313,   102,   630,   104,   105,   106,
     107,   628,   375,    -1,    -1,    -1,   193,   114,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,   126,
      -1,    -1,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   148,    -1,    -1,    -1,    -1,   153,   154,   155,    -1,
      -1,   158,   159,    -1,   161,    -1,    78,    -1,   165,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,
      -1,   158,    -1,    -1,    -1,    -1,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,
     197,    -1,    -1,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
     197,   218,    -1,   200,   201,   202,    -1,    -1,   205,   206,
      -1,     4,     5,     6,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,    -1,    65,   205,   206,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    77,    -1,   218,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,   102,
      -1,   104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
     153,   154,   155,    -1,    -1,    -1,   159,    36,   161,    38,
      -1,    -1,   165,    -1,    -1,    44,    45,    -1,    -1,    48,
      -1,   174,    -1,   176,    -1,    -1,    55,    -1,    -1,    -1,
      -1,   184,   185,    -1,    -1,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    77,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
     213,    -1,    91,   216,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,   102,    -1,   104,   105,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,   153,   154,   155,    -1,    -1,    -1,
     159,    36,   161,    38,    -1,    -1,   165,    -1,    -1,    44,
      45,    -1,    -1,    48,    -1,   174,    -1,   176,    -1,    -1,
      55,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    77,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,   213,    -1,    91,   216,     4,     5,
       6,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,     4,     5,     6,    -1,    -1,    44,    -1,
      -1,   136,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,   153,   154,
     155,    -1,    68,    -1,   159,    36,   161,    38,    74,    75,
     165,    77,    -1,    44,    -1,    81,    -1,    48,    84,   174,
      -1,   176,    -1,    -1,    55,    91,    -1,    -1,    -1,   184,
     185,    -1,    98,    -1,    -1,    -1,   102,    68,   104,   105,
     106,   107,    -1,    74,    75,    -1,    77,    -1,   114,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,   213,    -1,
      91,   216,     4,     5,     6,    -1,    -1,    98,    -1,    -1,
     136,   102,    -1,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   148,   114,    -1,    -1,    -1,   153,   154,   155,
      -1,    -1,    -1,   159,    36,   161,    38,    -1,    -1,   165,
      -1,    -1,    44,    -1,    -1,   136,    48,    -1,   174,    -1,
     176,    -1,    -1,    55,    -1,    -1,    -1,   148,   184,   185,
      -1,    -1,   153,   154,   155,    -1,    68,    -1,   159,    -1,
     161,    -1,    74,    75,   165,    77,    -1,    -1,    -1,    81,
      -1,    -1,    84,   174,    -1,   176,    -1,   213,    -1,    91,
     216,    -1,    -1,   184,   185,    -1,    98,    -1,    -1,    -1,
     102,    -1,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,     5,     6,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   153,   154,   155,    36,    -1,    38,   159,    -1,   161,
      -1,    -1,    44,   165,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    77,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,   213,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
     102,    -1,   104,   105,   106,   107,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      16,    17,    18,    19,    20,    21,    22,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    36,   161,
      38,    -1,    -1,   165,    -1,    -1,    44,    45,    -1,    -1,
      48,    -1,   174,    -1,   176,    -1,    -1,    55,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    77,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,   213,    -1,    91,   216,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,   102,    -1,   104,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
     148,    -1,    -1,    -1,    -1,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,   161,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    36,    -1,    38,   172,    -1,   174,    -1,   176,    44,
      45,    -1,    -1,    48,    -1,    -1,   184,   185,    -1,    -1,
      55,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      65,    -1,    -1,    68,    -1,    -1,   212,   213,    -1,    74,
      75,    -1,    77,    -1,    -1,   213,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,     5,
       6,    -1,    -1,    98,    99,    -1,    -1,   102,    -1,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,   136,    48,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,   148,    21,    22,    -1,    -1,   153,   154,
     155,    -1,    68,    -1,   159,    -1,   161,    -1,    74,    75,
     165,    77,    -1,    79,    -1,    81,    -1,    -1,    84,   174,
      -1,   176,    -1,    -1,    -1,    91,    -1,    -1,    -1,   184,
     185,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   213,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   153,   154,   155,
      36,    -1,    38,   159,    -1,   161,   162,    43,    44,   165,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    77,    -1,    79,    -1,    81,   202,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,   198,   199,   200,   201,   202,   203,   204,    -1,     5,
       6,    -1,    -1,    -1,    -1,   212,   213,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    -1,   148,    -1,    -1,    -1,    -1,   153,   154,   155,
      36,    -1,    38,   159,    -1,   161,   162,    -1,    44,   165,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   174,    -1,
     176,   198,   199,   200,   201,   202,   203,   204,   184,   185,
      -1,    -1,    68,    -1,    -1,   212,   213,    -1,    74,    75,
      -1,    77,    -1,    -1,    -1,    81,   202,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,   213,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,   148,    -1,    -1,    -1,    -1,   153,   154,   155,
      -1,    68,    -1,   159,    -1,   161,    -1,    74,    75,   165,
      77,    -1,    -1,    -1,    81,    -1,    -1,    84,   174,    -1,
     176,    -1,    -1,    -1,    91,    -1,    -1,    -1,   184,   185,
      -1,    -1,    -1,    -1,    -1,   102,    -1,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      -1,   148,    -1,    -1,    -1,    -1,   153,   154,   155,    -1,
      -1,    -1,   159,    -1,   161,    -1,    -1,    -1,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,   193,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
      -1,    -1,    -1,    -1,    -1,   219,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    16,    17,    18,
      19,    20,    21,    22,   212,   213,    -1,    -1,    -1,    -1,
      -1,   219,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   193,    -1,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   213,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
      30,    -1,    -1,   212,   213,    -1,    36,    -1,    38,    -1,
       5,     6,    -1,    -1,    44,    45,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,
      -1,    36,    -1,    38,    74,    75,    -1,    77,    -1,    44,
      -1,    81,    -1,    48,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    68,   104,   105,   106,   107,   108,    74,
      75,   111,    77,    -1,   114,    -1,    81,    -1,   118,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,   148,   114,
      -1,    -1,    -1,   153,   154,   155,    -1,    -1,    -1,   159,
      36,   161,    38,    -1,    -1,   165,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   184,   185,    -1,    -1,   153,   154,
     155,    -1,    68,    -1,   159,    -1,   161,    -1,    74,    75,
     165,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,   174,
      -1,   176,    -1,    -1,    -1,    91,    -1,    -1,    -1,   184,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,   174,    29,
     176,    31,    32,    33,    34,    35,    -1,    37,   184,   185,
      40,    -1,    42,    -1,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
     100,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,    -1,   112,   113,    -1,   115,   116,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,    -1,   137,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,    -1,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,   163,   164,    -1,    -1,   167,   168,   169,
     170,    -1,    -1,   173,    -1,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,    -1,    -1,   186
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   222,   224,     0,     4,     5,     6,    15,    36,    38,
      44,    45,    48,    55,    65,    68,    74,    75,    77,    81,
      84,    91,    98,   102,   104,   105,   106,   107,   108,   114,
     119,   136,   148,   153,   154,   155,   159,   161,   165,   174,
     176,   184,   185,   213,   223,   230,   231,   233,   234,   235,
     236,   239,   240,   246,   247,   261,   275,   279,   281,   284,
     286,   287,   288,   289,   290,   293,   294,   297,   299,   300,
     301,   302,   304,   305,   306,   307,   308,   310,   312,   330,
     331,   332,   333,   212,   213,   335,   338,   339,     3,     5,
     218,     3,     5,     3,     5,   277,   104,   280,    10,     3,
       5,   280,     3,     6,   218,   218,   280,   281,     3,   277,
       3,   277,   281,    26,    29,    31,    32,    33,    34,    35,
      37,    40,    42,    46,    47,    49,    50,    51,    52,    53,
      54,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    69,    70,    71,    72,    73,    76,    80,    82,    83,
      85,    86,    87,    88,    89,    90,    92,    93,    94,    95,
      96,    97,   100,   103,   109,   110,   112,   113,   115,   116,
     120,   121,   122,   123,   124,   125,   127,   128,   129,   130,
     131,   132,   133,   135,   137,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   149,   150,   151,   152,   157,   160,
     163,   164,   167,   168,   169,   170,   173,   175,   177,   178,
     179,   180,   181,   182,   183,   186,   248,   252,   329,   217,
     226,   226,   172,    30,    74,   111,   118,   165,   174,   238,
     261,   286,   293,   299,   303,   310,   330,   333,   217,   217,
     215,   217,   215,   217,   215,   217,   229,   217,   194,   298,
     215,   311,   312,   311,   311,     3,     5,    43,    79,   134,
     162,   202,   218,   254,   278,   313,   314,   327,   261,   330,
     331,   333,   311,   217,   285,    28,    57,    71,    76,   340,
     341,   335,   108,    10,   215,   217,     3,   331,   215,   166,
     215,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   192,   214,    14,
      99,   230,   237,   240,   286,   288,   289,   290,   301,   302,
     305,   216,   246,   247,     3,     3,     3,     5,     3,     5,
       3,     3,   215,   327,   291,   225,   138,   295,   299,     3,
     284,   215,   228,   309,   313,   313,   220,   213,   218,   245,
     311,     3,     5,   282,   218,   192,   214,     5,   219,   246,
     257,   258,   259,   260,   194,   219,   268,   218,   271,    10,
      10,    13,   253,   278,     3,     7,     8,     9,    10,    11,
      12,    78,   126,   158,   171,   197,   200,   201,   202,   205,
     206,   218,   264,   265,   266,   251,   310,     7,   250,   253,
     264,   267,    10,    10,   249,   267,   266,    10,    10,   266,
      10,   266,   264,   244,   247,   310,   266,   262,   263,   264,
      10,   329,    10,   266,   331,   262,   264,   331,   187,   188,
     189,   190,   191,   328,   331,   331,   253,     7,     8,   334,
      10,   331,   252,   213,   218,   217,   217,   215,   229,   310,
     215,   216,   246,   292,   224,   194,   117,   246,   273,   296,
     217,   215,   228,   216,   230,   247,   308,   313,   219,   267,
     202,   214,   264,   241,   242,   243,   244,   212,    27,    67,
     156,   190,   342,   343,   341,   215,   278,   216,   192,   220,
       7,   232,   216,   246,   269,   273,   216,   247,   270,   273,
     219,   219,   219,   218,   264,   264,   264,   264,   264,   264,
     264,   310,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   193,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   212,   213,   192,   219,   219,   192,   212,   219,
     192,   219,   219,   192,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   310,   202,   218,   245,   254,   278,
     319,   321,   322,   219,   192,   219,   219,   219,   219,   192,
     219,   219,   219,   219,   219,   219,   219,   219,   212,   219,
     219,   219,   252,    10,   227,   313,   323,   216,   229,   302,
     216,   194,   310,   330,   217,   216,   247,   274,   275,   216,
     236,   216,   229,   214,   214,   219,   192,   283,   192,   219,
     172,   336,   337,   260,   266,     7,   219,   310,   333,   219,
     217,   217,   310,   219,   202,   218,   245,   254,   315,   317,
     318,   264,   264,     3,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,     3,   264,   266,   250,     7,   267,    10,   321,   309,
     202,   241,   254,   320,   321,   218,   245,   263,   266,     7,
     219,   226,   192,   313,   217,   228,   229,    25,   244,   282,
     343,   339,   216,   336,   319,   325,   326,   217,   276,   278,
     317,   309,   202,   241,   254,   316,   317,   219,   218,   245,
     194,   214,   219,   321,   309,   219,   321,   219,   241,   219,
     229,   216,   313,   216,     5,   194,   324,   192,   217,   215,
     219,   317,   309,   219,   321,   219,   264,   241,   264,   321,
     219,   229,   217,   267,   325,   255,   321,   219,    42,    58,
     216,   256,   266,   194,   194,   217,   272,   273,   272,   217
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   223,   223,   224,   225,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   226,   226,   227,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   228,   228,
     229,   229,   230,   230,   230,   230,   230,   230,   230,   231,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   234,   235,   236,   237,   238,   238,   239,   240,   241,
     241,   242,   242,   243,   243,   244,   244,   245,   245,   245,
     246,   246,   247,   248,   248,   248,   249,   249,   250,   250,
     251,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   253,   253,   254,   254,   254,   254,
     255,   255,   256,   256,   257,   257,   257,   258,   258,   259,
     260,   260,   261,   262,   262,   263,   263,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   265,   265,
     266,   267,   268,   268,   269,   269,   270,   270,   271,   271,
     272,   272,   273,   273,   274,   275,   275,   276,   276,   277,
     277,   277,   278,   278,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   280,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   283,   282,   284,
     285,   284,   286,   286,   287,   288,   289,   290,   290,   291,
     291,   292,   293,   293,   294,   295,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   301,   301,   301,   302,
     302,   303,   303,   304,   305,   306,   306,   306,   307,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   312,   313,
     313,   313,   314,   314,   314,   314,   315,   315,   315,   316,
     316,   317,   317,   318,   318,   318,   318,   318,   319,   319,
     319,   320,   320,   321,   321,   322,   322,   322,   322,   322,
     322,   323,   323,   324,   324,   325,   326,   326,   327,   327,
     328,   328,   328,   328,   328,   329,   329,   329,   330,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     333,   333,   334,   334,   334,   335,   335,   336,   336,   337,
     338,   339,   339,   340,   340,   341,   341,   341,   341,   342,
     342,   343,   343,   343,   343
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     2,     2,
       3,     2,     3,     2,     2,     2,     0,     2,     0,     6,
       2,     3,     2,     3,     2,     2,     2,     2,     0,     2,
       0,     1,     1,     2,     2,     1,     2,     1,     1,     6,
       1,     2,     1,     2,     1,     2,     1,     2,     2,     2,
       2,     4,     3,     3,     5,     2,     2,     3,     4,     0,
       1,     1,     3,     1,     3,     3,     2,     3,     3,     2,
       0,     1,     3,     1,     3,     4,     1,     3,     1,     3,
       3,     0,     1,     4,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     1,     4,     4,     1,     6,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     1,     4,     1,     1,     4,     1,     4,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     6,
       1,     4,     1,     1,     1,     4,     1,     1,     1,     4,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     4,     3,     0,     2,     1,     1,     3,     2,
       3,     1,     5,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     3,     5,     5,     4,     3,     1,     3,
       1,     1,     0,     2,     4,     3,     2,     2,     0,     2,
       2,     1,     3,     2,     1,     3,     2,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     0,     4,     1,
       0,     4,     2,     2,     2,     5,     5,     2,     2,     0,
       2,     2,     2,     2,     2,     2,     3,     2,     3,     5,
       5,     0,     2,     2,     2,     2,     6,     8,     2,     2,
       2,     2,     2,     2,     5,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     0,     1,     2,     2,     2,     3,
       2,     1,     1,     3,     2,     4,     3,     2,     1,     3,
       2,     0,     1,     3,     2,     1,     3,     4,     3,     2,
       1,     3,     2,     0,     1,     1,     3,     2,     1,     3,
       4,     1,     3,     0,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     4,     5,
       5,    10,     1,     3,     1,     0,     2,     0,     2,     4,
       6,     0,     3,     1,     3,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1
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
#line 331 "tools/widl/parser.y"
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
#line 3164 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 347 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3170 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 348 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3176 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 349 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3182 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interfacedec  */
#line 350 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3188 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements interfacedef  */
#line 351 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3194 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements coclass ';'  */
#line 352 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3202 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclassdef  */
#line 355 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3210 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements apicontract ';'  */
#line 358 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3217 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements moduledef  */
#line 360 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3223 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements librarydef  */
#line 361 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3229 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements statement  */
#line 362 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3235 "tools/widl/parser.tab.c"
    break;

  case 16: /* imp_statements: %empty  */
#line 365 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3241 "tools/widl/parser.tab.c"
    break;

  case 17: /* imp_statements: imp_statements interfacedec  */
#line 366 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3247 "tools/widl/parser.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 367 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3253 "tools/widl/parser.tab.c"
    break;

  case 19: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 368 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3259 "tools/widl/parser.tab.c"
    break;

  case 20: /* imp_statements: imp_statements interfacedef  */
#line 369 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3265 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements coclass ';'  */
#line 370 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3271 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements coclassdef  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3279 "tools/widl/parser.tab.c"
    break;

  case 23: /* imp_statements: imp_statements apicontract ';'  */
#line 374 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3286 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements moduledef  */
#line 376 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3292 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements statement  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3298 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: imp_statements importlib  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3304 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements librarydef  */
#line 379 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3310 "tools/widl/parser.tab.c"
    break;

  case 28: /* int_statements: %empty  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3316 "tools/widl/parser.tab.c"
    break;

  case 29: /* int_statements: int_statements statement  */
#line 383 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3322 "tools/widl/parser.tab.c"
    break;

  case 32: /* statement: cppquote  */
#line 391 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3328 "tools/widl/parser.tab.c"
    break;

  case 33: /* statement: typedecl ';'  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3334 "tools/widl/parser.tab.c"
    break;

  case 34: /* statement: declaration ';'  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3340 "tools/widl/parser.tab.c"
    break;

  case 35: /* statement: import  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3346 "tools/widl/parser.tab.c"
    break;

  case 36: /* statement: typedef ';'  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3352 "tools/widl/parser.tab.c"
    break;

  case 37: /* statement: aPRAGMA  */
#line 396 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3358 "tools/widl/parser.tab.c"
    break;

  case 38: /* statement: pragma_warning  */
#line 397 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3364 "tools/widl/parser.tab.c"
    break;

  case 39: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 401 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3376 "tools/widl/parser.tab.c"
    break;

  case 40: /* warnings: aNUM  */
#line 411 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3382 "tools/widl/parser.tab.c"
    break;

  case 41: /* warnings: warnings aNUM  */
#line 412 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3388 "tools/widl/parser.tab.c"
    break;

  case 43: /* typedecl: tENUM aIDENTIFIER  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3394 "tools/widl/parser.tab.c"
    break;

  case 45: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3400 "tools/widl/parser.tab.c"
    break;

  case 47: /* typedecl: tUNION aIDENTIFIER  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3406 "tools/widl/parser.tab.c"
    break;

  case 48: /* typedecl: attributes enumdef  */
#line 422 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3412 "tools/widl/parser.tab.c"
    break;

  case 49: /* typedecl: attributes structdef  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3418 "tools/widl/parser.tab.c"
    break;

  case 50: /* typedecl: attributes uniondef  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3424 "tools/widl/parser.tab.c"
    break;

  case 51: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3430 "tools/widl/parser.tab.c"
    break;

  case 52: /* import_start: tIMPORT aSTRING ';'  */
#line 429 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3441 "tools/widl/parser.tab.c"
    break;

  case 53: /* import: import_start imp_statements aEOF  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3450 "tools/widl/parser.tab.c"
    break;

  case 54: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3456 "tools/widl/parser.tab.c"
    break;

  case 55: /* libraryhdr: tLIBRARY aIDENTIFIER  */
#line 447 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3462 "tools/widl/parser.tab.c"
    break;

  case 56: /* libraryhdr: tLIBRARY aKNOWNTYPE  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3468 "tools/widl/parser.tab.c"
    break;

  case 57: /* library_start: attributes libraryhdr '{'  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3476 "tools/widl/parser.tab.c"
    break;

  case 58: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 455 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3482 "tools/widl/parser.tab.c"
    break;

  case 59: /* m_args: %empty  */
#line 458 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3488 "tools/widl/parser.tab.c"
    break;

  case 61: /* arg_list: arg  */
#line 462 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3494 "tools/widl/parser.tab.c"
    break;

  case 62: /* arg_list: arg_list ',' arg  */
#line 463 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3500 "tools/widl/parser.tab.c"
    break;

  case 64: /* args: arg_list ',' ELLIPSIS  */
#line 467 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3506 "tools/widl/parser.tab.c"
    break;

  case 65: /* arg: attributes decl_spec m_any_declarator  */
#line 471 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3516 "tools/widl/parser.tab.c"
    break;

  case 66: /* arg: decl_spec m_any_declarator  */
#line 476 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3526 "tools/widl/parser.tab.c"
    break;

  case 67: /* array: '[' expr ']'  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3535 "tools/widl/parser.tab.c"
    break;

  case 68: /* array: '[' '*' ']'  */
#line 487 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3541 "tools/widl/parser.tab.c"
    break;

  case 69: /* array: '[' ']'  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3547 "tools/widl/parser.tab.c"
    break;

  case 70: /* m_attributes: %empty  */
#line 491 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3553 "tools/widl/parser.tab.c"
    break;

  case 72: /* attributes: '[' attrib_list ']'  */
#line 496 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3559 "tools/widl/parser.tab.c"
    break;

  case 73: /* attrib_list: attribute  */
#line 499 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3565 "tools/widl/parser.tab.c"
    break;

  case 74: /* attrib_list: attrib_list ',' attribute  */
#line 500 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3571 "tools/widl/parser.tab.c"
    break;

  case 75: /* attrib_list: attrib_list ']' '[' attribute  */
#line 501 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3577 "tools/widl/parser.tab.c"
    break;

  case 76: /* str_list: aSTRING  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3583 "tools/widl/parser.tab.c"
    break;

  case 77: /* str_list: str_list ',' aSTRING  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3589 "tools/widl/parser.tab.c"
    break;

  case 78: /* contract_ver: aNUM  */
#line 509 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3595 "tools/widl/parser.tab.c"
    break;

  case 79: /* contract_ver: aNUM '.' aNUM  */
#line 510 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3601 "tools/widl/parser.tab.c"
    break;

  case 80: /* contract_req: decl_spec ',' contract_ver  */
#line 513 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3611 "tools/widl/parser.tab.c"
    break;

  case 81: /* attribute: %empty  */
#line 519 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3617 "tools/widl/parser.tab.c"
    break;

  case 82: /* attribute: tAGGREGATABLE  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3623 "tools/widl/parser.tab.c"
    break;

  case 83: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3629 "tools/widl/parser.tab.c"
    break;

  case 84: /* attribute: tAPPOBJECT  */
#line 522 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3635 "tools/widl/parser.tab.c"
    break;

  case 85: /* attribute: tASYNC  */
#line 523 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3641 "tools/widl/parser.tab.c"
    break;

  case 86: /* attribute: tAUTOHANDLE  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3647 "tools/widl/parser.tab.c"
    break;

  case 87: /* attribute: tBINDABLE  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3653 "tools/widl/parser.tab.c"
    break;

  case 88: /* attribute: tBROADCAST  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3659 "tools/widl/parser.tab.c"
    break;

  case 89: /* attribute: tCALLAS '(' ident ')'  */
#line 527 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3665 "tools/widl/parser.tab.c"
    break;

  case 90: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 528 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3671 "tools/widl/parser.tab.c"
    break;

  case 91: /* attribute: tCODE  */
#line 529 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3677 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: tCOMMSTATUS  */
#line 530 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3683 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tCONTEXTHANDLE  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3689 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 532 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3695 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 533 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3701 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 534 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3707 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 535 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tCONTROL  */
#line 536 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3719 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 537 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3725 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tDECODE  */
#line 538 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3731 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tDEFAULT  */
#line 539 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3737 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tDEFAULTBIND  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3743 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tDEFAULTCOLLELEM  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3749 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3755 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tDEFAULTVTABLE  */
#line 543 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3761 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3767 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tDISPLAYBIND  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3773 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3779 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tDUAL  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3785 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tENABLEALLOCATE  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3791 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tENCODE  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3797 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tENDPOINT '(' str_list ')'  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3803 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tENTRY '(' expr_const ')'  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3809 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tEXPLICITHANDLE  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3815 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tFAULTSTATUS  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3821 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tFORCEALLOCATE  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3827 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tHANDLE  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3833 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3839 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3845 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3851 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 559 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3857 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3863 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tHIDDEN  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3869 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tID '(' expr_int_const ')'  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3875 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tIDEMPOTENT  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3881 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tIGNORE  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3887 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tIIDIS '(' expr ')'  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3893 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tIMMEDIATEBIND  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3899 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tIN  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tINPUTSYNC  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3917 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 570 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3923 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tLCID '(' expr_int_const ')'  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3929 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tLCID  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3935 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tLICENSED  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3941 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tLOCAL  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tMAYBE  */
#line 575 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tMESSAGE  */
#line 576 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tNOCODE  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3965 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tNONBROWSABLE  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3971 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tNONCREATABLE  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3977 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tNONEXTENSIBLE  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3983 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tNOTIFY  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3989 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tNOTIFYFLAG  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3995 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tOBJECT  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4001 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tODL  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4007 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tOLEAUTOMATION  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4013 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4019 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tOPTIONAL  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4025 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tOUT  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4031 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tPARTIALIGNORE  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4037 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4043 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tPROGID '(' aSTRING ')'  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4049 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tPROPGET  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4055 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tPROPPUT  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4061 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tPROPPUTREF  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4067 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tPROXY  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4073 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tPUBLIC  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4079 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 598 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4087 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tREADONLY  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4093 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tREPRESENTAS '(' type ')'  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4099 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tREQUESTEDIT  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4105 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tRESTRICTED  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4111 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tRETVAL  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4117 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4123 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tSOURCE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4129 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4135 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tSTRING  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4141 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tSWITCHIS '(' expr ')'  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4147 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4153 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tTRANSMITAS '(' type ')'  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4159 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tTHREADING '(' threading_type ')'  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4165 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tUIDEFAULT  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4171 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tUSESGETLASTERROR  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4177 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4183 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tUUID '(' uuid_string ')'  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4189 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4195 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tV1ENUM  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4201 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tVARARG  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4207 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tVERSION '(' version ')'  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4213 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4219 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4225 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: pointer_type  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4231 "tools/widl/parser.tab.c"
    break;

  case 185: /* uuid_string: aSTRING  */
#line 629 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4239 "tools/widl/parser.tab.c"
    break;

  case 186: /* callconv: tCDECL  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4245 "tools/widl/parser.tab.c"
    break;

  case 187: /* callconv: tFASTCALL  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4251 "tools/widl/parser.tab.c"
    break;

  case 188: /* callconv: tPASCAL  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4257 "tools/widl/parser.tab.c"
    break;

  case 189: /* callconv: tSTDCALL  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4263 "tools/widl/parser.tab.c"
    break;

  case 190: /* cases: %empty  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4269 "tools/widl/parser.tab.c"
    break;

  case 191: /* cases: cases case  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4275 "tools/widl/parser.tab.c"
    break;

  case 192: /* case: tCASE expr_int_const ':' union_field  */
#line 644 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4284 "tools/widl/parser.tab.c"
    break;

  case 193: /* case: tDEFAULT ':' union_field  */
#line 648 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4293 "tools/widl/parser.tab.c"
    break;

  case 194: /* enums: %empty  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4299 "tools/widl/parser.tab.c"
    break;

  case 195: /* enums: enum_list ','  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4305 "tools/widl/parser.tab.c"
    break;

  case 197: /* enum_list: enum  */
#line 659 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4314 "tools/widl/parser.tab.c"
    break;

  case 198: /* enum_list: enum_list ',' enum  */
#line 663 "tools/widl/parser.y"
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
#line 4329 "tools/widl/parser.tab.c"
    break;

  case 199: /* enum_member: m_attributes ident  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4337 "tools/widl/parser.tab.c"
    break;

  case 200: /* enum: enum_member '=' expr_int_const  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4346 "tools/widl/parser.tab.c"
    break;

  case 201: /* enum: enum_member  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4354 "tools/widl/parser.tab.c"
    break;

  case 202: /* enumdef: tENUM t_ident '{' enums '}'  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4360 "tools/widl/parser.tab.c"
    break;

  case 203: /* m_exprs: m_expr  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4366 "tools/widl/parser.tab.c"
    break;

  case 204: /* m_exprs: m_exprs ',' m_expr  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4372 "tools/widl/parser.tab.c"
    break;

  case 205: /* m_expr: %empty  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4378 "tools/widl/parser.tab.c"
    break;

  case 207: /* expr: aNUM  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4384 "tools/widl/parser.tab.c"
    break;

  case 208: /* expr: aHEXNUM  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4390 "tools/widl/parser.tab.c"
    break;

  case 209: /* expr: aDOUBLE  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4396 "tools/widl/parser.tab.c"
    break;

  case 210: /* expr: tFALSE  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4402 "tools/widl/parser.tab.c"
    break;

  case 211: /* expr: tNULL  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4408 "tools/widl/parser.tab.c"
    break;

  case 212: /* expr: tTRUE  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4414 "tools/widl/parser.tab.c"
    break;

  case 213: /* expr: aSTRING  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4420 "tools/widl/parser.tab.c"
    break;

  case 214: /* expr: aWSTRING  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4426 "tools/widl/parser.tab.c"
    break;

  case 215: /* expr: aSQSTRING  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4432 "tools/widl/parser.tab.c"
    break;

  case 216: /* expr: aIDENTIFIER  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4438 "tools/widl/parser.tab.c"
    break;

  case 217: /* expr: expr '?' expr ':' expr  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4444 "tools/widl/parser.tab.c"
    break;

  case 218: /* expr: expr LOGICALOR expr  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4450 "tools/widl/parser.tab.c"
    break;

  case 219: /* expr: expr LOGICALAND expr  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4456 "tools/widl/parser.tab.c"
    break;

  case 220: /* expr: expr '|' expr  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4462 "tools/widl/parser.tab.c"
    break;

  case 221: /* expr: expr '^' expr  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4468 "tools/widl/parser.tab.c"
    break;

  case 222: /* expr: expr '&' expr  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4474 "tools/widl/parser.tab.c"
    break;

  case 223: /* expr: expr EQUALITY expr  */
#line 716 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4480 "tools/widl/parser.tab.c"
    break;

  case 224: /* expr: expr INEQUALITY expr  */
#line 717 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4486 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: expr '>' expr  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4492 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: expr '<' expr  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4498 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: expr GREATEREQUAL expr  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4504 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: expr LESSEQUAL expr  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4510 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: expr SHL expr  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4516 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: expr SHR expr  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4522 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: expr '+' expr  */
#line 724 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4528 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: expr '-' expr  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4534 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: expr '%' expr  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4540 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: expr '*' expr  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4546 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '/' expr  */
#line 728 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4552 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: '!' expr  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4558 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: '~' expr  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4564 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: '+' expr  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4570 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: '-' expr  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4576 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: '&' expr  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4582 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: '*' expr  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4588 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4594 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr '.' aIDENTIFIER  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4600 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4606 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4612 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr '[' expr ']'  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4618 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: '(' expr ')'  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr_list_int_const: expr_int_const  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4630 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 746 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4636 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr_int_const: expr  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4645 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr_const: expr  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4654 "tools/widl/parser.tab.c"
    break;

  case 252: /* fields: %empty  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4660 "tools/widl/parser.tab.c"
    break;

  case 253: /* fields: fields field  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4666 "tools/widl/parser.tab.c"
    break;

  case 254: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 766 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4675 "tools/widl/parser.tab.c"
    break;

  case 255: /* field: m_attributes uniondef ';'  */
#line 770 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4684 "tools/widl/parser.tab.c"
    break;

  case 256: /* ne_union_field: s_field ';'  */
#line 777 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4690 "tools/widl/parser.tab.c"
    break;

  case 257: /* ne_union_field: attributes ';'  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4696 "tools/widl/parser.tab.c"
    break;

  case 258: /* ne_union_fields: %empty  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4702 "tools/widl/parser.tab.c"
    break;

  case 259: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4708 "tools/widl/parser.tab.c"
    break;

  case 260: /* union_field: s_field ';'  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4714 "tools/widl/parser.tab.c"
    break;

  case 261: /* union_field: ';'  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4720 "tools/widl/parser.tab.c"
    break;

  case 262: /* s_field: m_attributes decl_spec declarator  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4729 "tools/widl/parser.tab.c"
    break;

  case 263: /* s_field: m_attributes structdef  */
#line 794 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4738 "tools/widl/parser.tab.c"
    break;

  case 264: /* funcdef: declaration  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4748 "tools/widl/parser.tab.c"
    break;

  case 265: /* declaration: attributes decl_spec init_declarator  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 266: /* declaration: decl_spec init_declarator  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4764 "tools/widl/parser.tab.c"
    break;

  case 267: /* m_ident: %empty  */
#line 817 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4770 "tools/widl/parser.tab.c"
    break;

  case 269: /* t_ident: %empty  */
#line 821 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 4776 "tools/widl/parser.tab.c"
    break;

  case 270: /* t_ident: aIDENTIFIER  */
#line 822 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4782 "tools/widl/parser.tab.c"
    break;

  case 271: /* t_ident: aKNOWNTYPE  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4788 "tools/widl/parser.tab.c"
    break;

  case 272: /* ident: aIDENTIFIER  */
#line 826 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4794 "tools/widl/parser.tab.c"
    break;

  case 273: /* ident: aKNOWNTYPE  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4800 "tools/widl/parser.tab.c"
    break;

  case 274: /* base_type: tBYTE  */
#line 831 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4806 "tools/widl/parser.tab.c"
    break;

  case 275: /* base_type: tWCHAR  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4812 "tools/widl/parser.tab.c"
    break;

  case 277: /* base_type: tSIGNED int_std  */
#line 834 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4818 "tools/widl/parser.tab.c"
    break;

  case 278: /* base_type: tUNSIGNED int_std  */
#line 835 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4824 "tools/widl/parser.tab.c"
    break;

  case 279: /* base_type: tUNSIGNED  */
#line 836 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4830 "tools/widl/parser.tab.c"
    break;

  case 280: /* base_type: tFLOAT  */
#line 837 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4836 "tools/widl/parser.tab.c"
    break;

  case 281: /* base_type: tDOUBLE  */
#line 838 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4842 "tools/widl/parser.tab.c"
    break;

  case 282: /* base_type: tBOOLEAN  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4848 "tools/widl/parser.tab.c"
    break;

  case 283: /* base_type: tERRORSTATUST  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4854 "tools/widl/parser.tab.c"
    break;

  case 284: /* base_type: tHANDLET  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4860 "tools/widl/parser.tab.c"
    break;

  case 287: /* int_std: tINT  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4866 "tools/widl/parser.tab.c"
    break;

  case 288: /* int_std: tSHORT m_int  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4872 "tools/widl/parser.tab.c"
    break;

  case 289: /* int_std: tSMALL  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4878 "tools/widl/parser.tab.c"
    break;

  case 290: /* int_std: tLONG m_int  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4884 "tools/widl/parser.tab.c"
    break;

  case 291: /* int_std: tHYPER m_int  */
#line 852 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4890 "tools/widl/parser.tab.c"
    break;

  case 292: /* int_std: tINT64  */
#line 853 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4896 "tools/widl/parser.tab.c"
    break;

  case 293: /* int_std: tCHAR  */
#line 854 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4902 "tools/widl/parser.tab.c"
    break;

  case 294: /* int_std: tINT32  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4908 "tools/widl/parser.tab.c"
    break;

  case 295: /* int_std: tINT3264  */
#line 856 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4914 "tools/widl/parser.tab.c"
    break;

  case 296: /* qualified_seq: aKNOWNTYPE  */
#line 860 "tools/widl/parser.y"
                      { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4920 "tools/widl/parser.tab.c"
    break;

  case 297: /* $@3: %empty  */
#line 861 "tools/widl/parser.y"
                      { push_lookup_namespace((yyvsp[-1].str)); }
#line 4926 "tools/widl/parser.tab.c"
    break;

  case 298: /* qualified_seq: aIDENTIFIER '.' $@3 qualified_seq  */
#line 861 "tools/widl/parser.y"
                                                                   { (yyval.type) = (yyvsp[0].type); }
#line 4932 "tools/widl/parser.tab.c"
    break;

  case 299: /* qualified_type: aKNOWNTYPE  */
#line 865 "tools/widl/parser.y"
                     { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 300: /* $@4: %empty  */
#line 866 "tools/widl/parser.y"
                     { init_lookup_namespace((yyvsp[-1].str)); }
#line 4944 "tools/widl/parser.tab.c"
    break;

  case 301: /* qualified_type: aNAMESPACE '.' $@4 qualified_seq  */
#line 866 "tools/widl/parser.y"
                                                                  { (yyval.type) = (yyvsp[0].type); }
#line 4950 "tools/widl/parser.tab.c"
    break;

  case 302: /* coclass: tCOCLASS aIDENTIFIER  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4956 "tools/widl/parser.tab.c"
    break;

  case 303: /* coclass: tCOCLASS aKNOWNTYPE  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4967 "tools/widl/parser.tab.c"
    break;

  case 304: /* coclasshdr: attributes coclass  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4976 "tools/widl/parser.tab.c"
    break;

  case 305: /* coclassdef: coclasshdr '{' coclass_ints '}' semicolon_opt  */
#line 885 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4982 "tools/widl/parser.tab.c"
    break;

  case 306: /* apicontract: attributes tAPICONTRACT aIDENTIFIER '{' '}'  */
#line 889 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_APICONTRACT, (yyvsp[-2].str), current_namespace, 0);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_apicontract_attrs((yyval.type)->name, (yyvsp[-4].attr_list));
						}
#line 4991 "tools/widl/parser.tab.c"
    break;

  case 307: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4997 "tools/widl/parser.tab.c"
    break;

  case 308: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 896 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5003 "tools/widl/parser.tab.c"
    break;

  case 309: /* coclass_ints: %empty  */
#line 899 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5009 "tools/widl/parser.tab.c"
    break;

  case 310: /* coclass_ints: coclass_ints coclass_int  */
#line 900 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5015 "tools/widl/parser.tab.c"
    break;

  case 311: /* coclass_int: m_attributes interfacedec  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 5021 "tools/widl/parser.tab.c"
    break;

  case 312: /* dispinterface: tDISPINTERFACE aIDENTIFIER  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5027 "tools/widl/parser.tab.c"
    break;

  case 313: /* dispinterface: tDISPINTERFACE aKNOWNTYPE  */
#line 908 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5033 "tools/widl/parser.tab.c"
    break;

  case 314: /* dispinterfacehdr: attributes dispinterface  */
#line 911 "tools/widl/parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 5045 "tools/widl/parser.tab.c"
    break;

  case 315: /* dispint_props: tPROPERTIES ':'  */
#line 920 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5051 "tools/widl/parser.tab.c"
    break;

  case 316: /* dispint_props: dispint_props s_field ';'  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5057 "tools/widl/parser.tab.c"
    break;

  case 317: /* dispint_meths: tMETHODS ':'  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5063 "tools/widl/parser.tab.c"
    break;

  case 318: /* dispint_meths: dispint_meths funcdef ';'  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5069 "tools/widl/parser.tab.c"
    break;

  case 319: /* dispinterfacedef: dispinterfacehdr '{' dispint_props dispint_meths '}'  */
#line 931 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 5077 "tools/widl/parser.tab.c"
    break;

  case 320: /* dispinterfacedef: dispinterfacehdr '{' interface ';' '}'  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 5085 "tools/widl/parser.tab.c"
    break;

  case 321: /* inherit: %empty  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5091 "tools/widl/parser.tab.c"
    break;

  case 322: /* inherit: ':' qualified_type  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5097 "tools/widl/parser.tab.c"
    break;

  case 323: /* interface: tINTERFACE aIDENTIFIER  */
#line 944 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5103 "tools/widl/parser.tab.c"
    break;

  case 324: /* interface: tINTERFACE aKNOWNTYPE  */
#line 945 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5109 "tools/widl/parser.tab.c"
    break;

  case 325: /* interfacehdr: attributes interface  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 5119 "tools/widl/parser.tab.c"
    break;

  case 326: /* interfacedef: interfacehdr inherit '{' int_statements '}' semicolon_opt  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5130 "tools/widl/parser.tab.c"
    break;

  case 327: /* interfacedef: interfacehdr ':' aIDENTIFIER '{' import int_statements '}' semicolon_opt  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 5138 "tools/widl/parser.tab.c"
    break;

  case 328: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5144 "tools/widl/parser.tab.c"
    break;

  case 329: /* interfacedec: interface ';'  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5150 "tools/widl/parser.tab.c"
    break;

  case 330: /* interfacedec: dispinterface ';'  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5156 "tools/widl/parser.tab.c"
    break;

  case 331: /* module: tMODULE aIDENTIFIER  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5162 "tools/widl/parser.tab.c"
    break;

  case 332: /* module: tMODULE aKNOWNTYPE  */
#line 978 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5168 "tools/widl/parser.tab.c"
    break;

  case 333: /* modulehdr: attributes module  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5176 "tools/widl/parser.tab.c"
    break;

  case 334: /* moduledef: modulehdr '{' int_statements '}' semicolon_opt  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5184 "tools/widl/parser.tab.c"
    break;

  case 335: /* storage_cls_spec: tEXTERN  */
#line 993 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5190 "tools/widl/parser.tab.c"
    break;

  case 336: /* storage_cls_spec: tSTATIC  */
#line 994 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5196 "tools/widl/parser.tab.c"
    break;

  case 337: /* storage_cls_spec: tREGISTER  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5202 "tools/widl/parser.tab.c"
    break;

  case 338: /* function_specifier: tINLINE  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5208 "tools/widl/parser.tab.c"
    break;

  case 339: /* type_qualifier: tCONST  */
#line 1003 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5214 "tools/widl/parser.tab.c"
    break;

  case 340: /* m_type_qual_list: %empty  */
#line 1006 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5220 "tools/widl/parser.tab.c"
    break;

  case 341: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5226 "tools/widl/parser.tab.c"
    break;

  case 342: /* decl_spec: type m_decl_spec_no_type  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5232 "tools/widl/parser.tab.c"
    break;

  case 343: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5238 "tools/widl/parser.tab.c"
    break;

  case 344: /* m_decl_spec_no_type: %empty  */
#line 1015 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5244 "tools/widl/parser.tab.c"
    break;

  case 346: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1020 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5250 "tools/widl/parser.tab.c"
    break;

  case 347: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1021 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5256 "tools/widl/parser.tab.c"
    break;

  case 348: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1022 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5262 "tools/widl/parser.tab.c"
    break;

  case 349: /* declarator: '*' m_type_qual_list declarator  */
#line 1027 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5268 "tools/widl/parser.tab.c"
    break;

  case 350: /* declarator: callconv declarator  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5274 "tools/widl/parser.tab.c"
    break;

  case 352: /* direct_declarator: ident  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5280 "tools/widl/parser.tab.c"
    break;

  case 353: /* direct_declarator: '(' declarator ')'  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5286 "tools/widl/parser.tab.c"
    break;

  case 354: /* direct_declarator: direct_declarator array  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5292 "tools/widl/parser.tab.c"
    break;

  case 355: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5298 "tools/widl/parser.tab.c"
    break;

  case 356: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5304 "tools/widl/parser.tab.c"
    break;

  case 357: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1043 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5310 "tools/widl/parser.tab.c"
    break;

  case 359: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1050 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5316 "tools/widl/parser.tab.c"
    break;

  case 360: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1051 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5322 "tools/widl/parser.tab.c"
    break;

  case 361: /* m_abstract_declarator: %empty  */
#line 1055 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5328 "tools/widl/parser.tab.c"
    break;

  case 363: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5334 "tools/widl/parser.tab.c"
    break;

  case 364: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5340 "tools/widl/parser.tab.c"
    break;

  case 365: /* abstract_direct_declarator: array  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5346 "tools/widl/parser.tab.c"
    break;

  case 366: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1065 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5354 "tools/widl/parser.tab.c"
    break;

  case 367: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1069 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5362 "tools/widl/parser.tab.c"
    break;

  case 368: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1077 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5368 "tools/widl/parser.tab.c"
    break;

  case 369: /* any_declarator: callconv m_any_declarator  */
#line 1078 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5374 "tools/widl/parser.tab.c"
    break;

  case 371: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1085 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5380 "tools/widl/parser.tab.c"
    break;

  case 372: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1086 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5386 "tools/widl/parser.tab.c"
    break;

  case 373: /* m_any_declarator: %empty  */
#line 1090 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5392 "tools/widl/parser.tab.c"
    break;

  case 375: /* any_direct_declarator: ident  */
#line 1098 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5398 "tools/widl/parser.tab.c"
    break;

  case 376: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5404 "tools/widl/parser.tab.c"
    break;

  case 377: /* any_direct_declarator: any_direct_declarator array  */
#line 1100 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5410 "tools/widl/parser.tab.c"
    break;

  case 378: /* any_direct_declarator: array  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5416 "tools/widl/parser.tab.c"
    break;

  case 379: /* any_direct_declarator: '(' m_args ')'  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 380: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1107 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5432 "tools/widl/parser.tab.c"
    break;

  case 381: /* declarator_list: declarator  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5438 "tools/widl/parser.tab.c"
    break;

  case 382: /* declarator_list: declarator_list ',' declarator  */
#line 1114 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5444 "tools/widl/parser.tab.c"
    break;

  case 383: /* m_bitfield: %empty  */
#line 1117 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5450 "tools/widl/parser.tab.c"
    break;

  case 384: /* m_bitfield: ':' expr_const  */
#line 1118 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5456 "tools/widl/parser.tab.c"
    break;

  case 385: /* struct_declarator: any_declarator m_bitfield  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5465 "tools/widl/parser.tab.c"
    break;

  case 386: /* struct_declarator_list: struct_declarator  */
#line 1128 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5471 "tools/widl/parser.tab.c"
    break;

  case 387: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1130 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5477 "tools/widl/parser.tab.c"
    break;

  case 388: /* init_declarator: declarator  */
#line 1134 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5483 "tools/widl/parser.tab.c"
    break;

  case 389: /* init_declarator: declarator '=' expr_const  */
#line 1135 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5489 "tools/widl/parser.tab.c"
    break;

  case 390: /* threading_type: tAPARTMENT  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5495 "tools/widl/parser.tab.c"
    break;

  case 391: /* threading_type: tNEUTRAL  */
#line 1140 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5501 "tools/widl/parser.tab.c"
    break;

  case 392: /* threading_type: tSINGLE  */
#line 1141 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5507 "tools/widl/parser.tab.c"
    break;

  case 393: /* threading_type: tFREE  */
#line 1142 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5513 "tools/widl/parser.tab.c"
    break;

  case 394: /* threading_type: tBOTH  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5519 "tools/widl/parser.tab.c"
    break;

  case 395: /* pointer_type: tREF  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5525 "tools/widl/parser.tab.c"
    break;

  case 396: /* pointer_type: tUNIQUE  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5531 "tools/widl/parser.tab.c"
    break;

  case 397: /* pointer_type: tPTR  */
#line 1149 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5537 "tools/widl/parser.tab.c"
    break;

  case 398: /* structdef: tSTRUCT t_ident '{' fields '}'  */
#line 1152 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5543 "tools/widl/parser.tab.c"
    break;

  case 399: /* type: tVOID  */
#line 1155 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5549 "tools/widl/parser.tab.c"
    break;

  case 400: /* type: qualified_type  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5555 "tools/widl/parser.tab.c"
    break;

  case 401: /* type: base_type  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5561 "tools/widl/parser.tab.c"
    break;

  case 402: /* type: enumdef  */
#line 1158 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5567 "tools/widl/parser.tab.c"
    break;

  case 403: /* type: tENUM aIDENTIFIER  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5573 "tools/widl/parser.tab.c"
    break;

  case 404: /* type: structdef  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5579 "tools/widl/parser.tab.c"
    break;

  case 405: /* type: tSTRUCT aIDENTIFIER  */
#line 1161 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5585 "tools/widl/parser.tab.c"
    break;

  case 406: /* type: uniondef  */
#line 1162 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5591 "tools/widl/parser.tab.c"
    break;

  case 407: /* type: tUNION aIDENTIFIER  */
#line 1163 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5597 "tools/widl/parser.tab.c"
    break;

  case 408: /* type: tSAFEARRAY '(' type ')'  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5603 "tools/widl/parser.tab.c"
    break;

  case 409: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1168 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5612 "tools/widl/parser.tab.c"
    break;

  case 410: /* uniondef: tUNION t_ident '{' ne_union_fields '}'  */
#line 1175 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5618 "tools/widl/parser.tab.c"
    break;

  case 411: /* uniondef: tUNION t_ident tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5624 "tools/widl/parser.tab.c"
    break;

  case 412: /* version: aNUM  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5630 "tools/widl/parser.tab.c"
    break;

  case 413: /* version: aNUM '.' aNUM  */
#line 1183 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5636 "tools/widl/parser.tab.c"
    break;

  case 414: /* version: aHEXNUM  */
#line 1184 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5642 "tools/widl/parser.tab.c"
    break;

  case 419: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1199 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5650 "tools/widl/parser.tab.c"
    break;

  case 420: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1206 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5660 "tools/widl/parser.tab.c"
    break;

  case 421: /* acf_attributes: %empty  */
#line 1214 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5666 "tools/widl/parser.tab.c"
    break;

  case 422: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1215 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5672 "tools/widl/parser.tab.c"
    break;

  case 423: /* acf_attribute_list: acf_attribute  */
#line 1219 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5678 "tools/widl/parser.tab.c"
    break;

  case 424: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5684 "tools/widl/parser.tab.c"
    break;

  case 425: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1225 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5690 "tools/widl/parser.tab.c"
    break;

  case 426: /* acf_attribute: tENCODE  */
#line 1226 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5696 "tools/widl/parser.tab.c"
    break;

  case 427: /* acf_attribute: tDECODE  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5702 "tools/widl/parser.tab.c"
    break;

  case 428: /* acf_attribute: tEXPLICITHANDLE  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5708 "tools/widl/parser.tab.c"
    break;

  case 429: /* allocate_option_list: allocate_option  */
#line 1232 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5714 "tools/widl/parser.tab.c"
    break;

  case 430: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1234 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 5720 "tools/widl/parser.tab.c"
    break;

  case 431: /* allocate_option: tDONTFREE  */
#line 1238 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 5726 "tools/widl/parser.tab.c"
    break;

  case 432: /* allocate_option: tFREE  */
#line 1239 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5732 "tools/widl/parser.tab.c"
    break;

  case 433: /* allocate_option: tALLNODES  */
#line 1240 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 5738 "tools/widl/parser.tab.c"
    break;

  case 434: /* allocate_option: tSINGLENODE  */
#line 1241 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5744 "tools/widl/parser.tab.c"
    break;


#line 5748 "tools/widl/parser.tab.c"

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

#line 1244 "tools/widl/parser.y"


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

static type_t *find_type_or_error(const char *name, int t)
{
    type_t *type;
    if (!(type = find_type(name, current_namespace, t)) &&
        !(type = find_type(name, lookup_namespace, t)))
    {
        error_loc("type '%s' not found\n", name);
        return NULL;
    }
    return type;
}

static type_t *find_type_or_error2(char *name, int t)
{
  type_t *tp = find_type_or_error(name, t);
  free(name);
  return tp;
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
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF M   I Fn ARG T En Enm St Un Fi L  DI M  C AC  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "aggregatable" },
    /* ATTR_ALLOCATE */            { 0, 1, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "allocate" },
    /* ATTR_ANNOTATION */          { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 0,  1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTRACT */            { 0, 0, 0,  1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, "contract" },
    /* ATTR_CONTRACTVERSION */     { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "contractversion" },
    /* ATTR_CONTROL */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, "control" },
    /* ATTR_CUSTOM */              { 0, 0, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, "custom" },
    /* ATTR_DECODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MAYBE */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0,  0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0,  0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0,  0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 0,  1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0,  0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
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

static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs)
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

static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs)
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

static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs)
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

static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs)
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

static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs)
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
        idl_handle->declspec.type = find_type_or_error("handle_t", 0);
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

    async_iface = get_type(TYPE_INTERFACE, strmake("Async%s", iface->name), iface->namespace, 0);
    async_iface->attrs = map_attrs(iface->attrs, async_iface_attrs);

    STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
    {
        var_t *begin_func, *finish_func, *func = stmt->u.var, *arg;
        var_list_t *begin_args = NULL, *finish_args = NULL, *args;

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

    type_interface_define(async_iface, inherit, stmts);
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
        type_t *type = find_type_or_error(var->name, 0);
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

static void check_def(const type_t *t)
{
    if (t->defined)
        error_loc("%s: redefinition error; original definition was at %s:%d\n",
                  t->name, t->loc_info.input_name, t->loc_info.line_number);
}
