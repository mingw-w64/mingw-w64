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
static type_t *find_type_or_error(struct namespace *parent, const char *name);
static struct namespace *find_namespace_or_error(struct namespace *namespace, const char *name);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);
static void push_parameters_namespace(const char *name);
static void pop_parameters_namespace(const char *name);

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts);
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
static statement_t *make_statement_parameterized_type(type_t *type, typeref_list_t *params);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *parameters_namespace = NULL;
static statement_list_t *parameterized_type_stmts = NULL;

static typelib_t *current_typelib;


#line 202 "tools/widl/parser.tab.c"

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
    aNUM = 261,                    /* aNUM  */
    aHEXNUM = 262,                 /* aHEXNUM  */
    aDOUBLE = 263,                 /* aDOUBLE  */
    aSTRING = 264,                 /* aSTRING  */
    aWSTRING = 265,                /* aWSTRING  */
    aSQSTRING = 266,               /* aSQSTRING  */
    aUUID = 267,                   /* aUUID  */
    aEOF = 268,                    /* aEOF  */
    aACF = 269,                    /* aACF  */
    SHL = 270,                     /* SHL  */
    SHR = 271,                     /* SHR  */
    MEMBERPTR = 272,               /* MEMBERPTR  */
    EQUALITY = 273,                /* EQUALITY  */
    INEQUALITY = 274,              /* INEQUALITY  */
    GREATEREQUAL = 275,            /* GREATEREQUAL  */
    LESSEQUAL = 276,               /* LESSEQUAL  */
    LOGICALOR = 277,               /* LOGICALOR  */
    LOGICALAND = 278,              /* LOGICALAND  */
    ELLIPSIS = 279,                /* ELLIPSIS  */
    tACTIVATABLE = 280,            /* tACTIVATABLE  */
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
    tDECLARE = 313,                /* tDECLARE  */
    tDECODE = 314,                 /* tDECODE  */
    tDEFAULT = 315,                /* tDEFAULT  */
    tDEFAULTBIND = 316,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 317,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 318,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 319,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 320, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 321,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 322,          /* tDISPINTERFACE  */
    tDLLNAME = 323,                /* tDLLNAME  */
    tDONTFREE = 324,               /* tDONTFREE  */
    tDOUBLE = 325,                 /* tDOUBLE  */
    tDUAL = 326,                   /* tDUAL  */
    tENABLEALLOCATE = 327,         /* tENABLEALLOCATE  */
    tENCODE = 328,                 /* tENCODE  */
    tENDPOINT = 329,               /* tENDPOINT  */
    tENTRY = 330,                  /* tENTRY  */
    tENUM = 331,                   /* tENUM  */
    tERRORSTATUST = 332,           /* tERRORSTATUST  */
    tEVENTADD = 333,               /* tEVENTADD  */
    tEVENTREMOVE = 334,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 335,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 336,         /* tEXPLICITHANDLE  */
    tEXTERN = 337,                 /* tEXTERN  */
    tFALSE = 338,                  /* tFALSE  */
    tFASTCALL = 339,               /* tFASTCALL  */
    tFAULTSTATUS = 340,            /* tFAULTSTATUS  */
    tFLAGS = 341,                  /* tFLAGS  */
    tFLOAT = 342,                  /* tFLOAT  */
    tFORCEALLOCATE = 343,          /* tFORCEALLOCATE  */
    tHANDLE = 344,                 /* tHANDLE  */
    tHANDLET = 345,                /* tHANDLET  */
    tHELPCONTEXT = 346,            /* tHELPCONTEXT  */
    tHELPFILE = 347,               /* tHELPFILE  */
    tHELPSTRING = 348,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 349,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 350,          /* tHELPSTRINGDLL  */
    tHIDDEN = 351,                 /* tHIDDEN  */
    tHYPER = 352,                  /* tHYPER  */
    tID = 353,                     /* tID  */
    tIDEMPOTENT = 354,             /* tIDEMPOTENT  */
    tIGNORE = 355,                 /* tIGNORE  */
    tIIDIS = 356,                  /* tIIDIS  */
    tIMMEDIATEBIND = 357,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 358,         /* tIMPLICITHANDLE  */
    tIMPORT = 359,                 /* tIMPORT  */
    tIMPORTLIB = 360,              /* tIMPORTLIB  */
    tIN = 361,                     /* tIN  */
    tIN_LINE = 362,                /* tIN_LINE  */
    tINLINE = 363,                 /* tINLINE  */
    tINPUTSYNC = 364,              /* tINPUTSYNC  */
    tINT = 365,                    /* tINT  */
    tINT32 = 366,                  /* tINT32  */
    tINT3264 = 367,                /* tINT3264  */
    tINT64 = 368,                  /* tINT64  */
    tINTERFACE = 369,              /* tINTERFACE  */
    tLCID = 370,                   /* tLCID  */
    tLENGTHIS = 371,               /* tLENGTHIS  */
    tLIBRARY = 372,                /* tLIBRARY  */
    tLICENSED = 373,               /* tLICENSED  */
    tLOCAL = 374,                  /* tLOCAL  */
    tLONG = 375,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 376,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 377,                  /* tMAYBE  */
    tMESSAGE = 378,                /* tMESSAGE  */
    tMETHODS = 379,                /* tMETHODS  */
    tMODULE = 380,                 /* tMODULE  */
    tMTA = 381,                    /* tMTA  */
    tNAMESPACE = 382,              /* tNAMESPACE  */
    tNOCODE = 383,                 /* tNOCODE  */
    tNONBROWSABLE = 384,           /* tNONBROWSABLE  */
    tNONCREATABLE = 385,           /* tNONCREATABLE  */
    tNONE = 386,                   /* tNONE  */
    tNONEXTENSIBLE = 387,          /* tNONEXTENSIBLE  */
    tNOTIFY = 388,                 /* tNOTIFY  */
    tNOTIFYFLAG = 389,             /* tNOTIFYFLAG  */
    tNULL = 390,                   /* tNULL  */
    tOBJECT = 391,                 /* tOBJECT  */
    tODL = 392,                    /* tODL  */
    tOLEAUTOMATION = 393,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 394,               /* tOPTIMIZE  */
    tOPTIONAL = 395,               /* tOPTIONAL  */
    tOUT = 396,                    /* tOUT  */
    tPARTIALIGNORE = 397,          /* tPARTIALIGNORE  */
    tPASCAL = 398,                 /* tPASCAL  */
    tPOINTERDEFAULT = 399,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 400,         /* tPRAGMA_WARNING  */
    tPROGID = 401,                 /* tPROGID  */
    tPROPERTIES = 402,             /* tPROPERTIES  */
    tPROPGET = 403,                /* tPROPGET  */
    tPROPPUT = 404,                /* tPROPPUT  */
    tPROPPUTREF = 405,             /* tPROPPUTREF  */
    tPROXY = 406,                  /* tPROXY  */
    tPTR = 407,                    /* tPTR  */
    tPUBLIC = 408,                 /* tPUBLIC  */
    tRANGE = 409,                  /* tRANGE  */
    tREADONLY = 410,               /* tREADONLY  */
    tREF = 411,                    /* tREF  */
    tREGISTER = 412,               /* tREGISTER  */
    tREPRESENTAS = 413,            /* tREPRESENTAS  */
    tREQUESTEDIT = 414,            /* tREQUESTEDIT  */
    tREQUIRES = 415,               /* tREQUIRES  */
    tRESTRICTED = 416,             /* tRESTRICTED  */
    tRETVAL = 417,                 /* tRETVAL  */
    tRUNTIMECLASS = 418,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 419,              /* tSAFEARRAY  */
    tSHORT = 420,                  /* tSHORT  */
    tSIGNED = 421,                 /* tSIGNED  */
    tSINGLENODE = 422,             /* tSINGLENODE  */
    tSIZEIS = 423,                 /* tSIZEIS  */
    tSIZEOF = 424,                 /* tSIZEOF  */
    tSMALL = 425,                  /* tSMALL  */
    tSOURCE = 426,                 /* tSOURCE  */
    tSTANDARD = 427,               /* tSTANDARD  */
    tSTATIC = 428,                 /* tSTATIC  */
    tSTDCALL = 429,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 430,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 431,                 /* tSTRING  */
    tSTRUCT = 432,                 /* tSTRUCT  */
    tSWITCH = 433,                 /* tSWITCH  */
    tSWITCHIS = 434,               /* tSWITCHIS  */
    tSWITCHTYPE = 435,             /* tSWITCHTYPE  */
    tTHREADING = 436,              /* tTHREADING  */
    tTRANSMITAS = 437,             /* tTRANSMITAS  */
    tTRUE = 438,                   /* tTRUE  */
    tTYPEDEF = 439,                /* tTYPEDEF  */
    tUIDEFAULT = 440,              /* tUIDEFAULT  */
    tUNION = 441,                  /* tUNION  */
    tUNIQUE = 442,                 /* tUNIQUE  */
    tUNSIGNED = 443,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 444,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 445,            /* tUSERMARSHAL  */
    tUUID = 446,                   /* tUUID  */
    tV1ENUM = 447,                 /* tV1ENUM  */
    tVARARG = 448,                 /* tVARARG  */
    tVERSION = 449,                /* tVERSION  */
    tVIPROGID = 450,               /* tVIPROGID  */
    tVOID = 451,                   /* tVOID  */
    tWCHAR = 452,                  /* tWCHAR  */
    tWIREMARSHAL = 453,            /* tWIREMARSHAL  */
    tAPARTMENT = 454,              /* tAPARTMENT  */
    tNEUTRAL = 455,                /* tNEUTRAL  */
    tSINGLE = 456,                 /* tSINGLE  */
    tFREE = 457,                   /* tFREE  */
    tBOTH = 458,                   /* tBOTH  */
    CAST = 459,                    /* CAST  */
    PPTR = 460,                    /* PPTR  */
    POS = 461,                     /* POS  */
    NEG = 462,                     /* NEG  */
    ADDRESSOF = 463                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "tools/widl/parser.y"

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
	typeref_t *typeref;
	typeref_list_t *typeref_list;
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
	struct namespace *namespace;

#line 487 "tools/widl/parser.tab.c"

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
  YYSYMBOL_aNUM = 6,                       /* aNUM  */
  YYSYMBOL_aHEXNUM = 7,                    /* aHEXNUM  */
  YYSYMBOL_aDOUBLE = 8,                    /* aDOUBLE  */
  YYSYMBOL_aSTRING = 9,                    /* aSTRING  */
  YYSYMBOL_aWSTRING = 10,                  /* aWSTRING  */
  YYSYMBOL_aSQSTRING = 11,                 /* aSQSTRING  */
  YYSYMBOL_aUUID = 12,                     /* aUUID  */
  YYSYMBOL_aEOF = 13,                      /* aEOF  */
  YYSYMBOL_aACF = 14,                      /* aACF  */
  YYSYMBOL_SHL = 15,                       /* SHL  */
  YYSYMBOL_SHR = 16,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 17,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 18,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 19,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 20,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 21,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 22,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 23,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 24,                  /* ELLIPSIS  */
  YYSYMBOL_tACTIVATABLE = 25,              /* tACTIVATABLE  */
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
  YYSYMBOL_tDECLARE = 58,                  /* tDECLARE  */
  YYSYMBOL_tDECODE = 59,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 60,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 61,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 62,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 63,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 64,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 65,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 66,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 67,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 68,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 69,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 70,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 71,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 72,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 73,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 74,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 75,                    /* tENTRY  */
  YYSYMBOL_tENUM = 76,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 77,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 78,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 79,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 80,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 81,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 82,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 83,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 84,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 85,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 86,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 87,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 88,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 89,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 90,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 91,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 92,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 93,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 94,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 95,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 96,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 97,                    /* tHYPER  */
  YYSYMBOL_tID = 98,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 99,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 100,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 101,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 102,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 103,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 104,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 105,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 106,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 107,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 108,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 109,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 110,                     /* tINT  */
  YYSYMBOL_tINT32 = 111,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 112,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 113,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 114,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 115,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 116,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 117,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 118,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 119,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 120,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 121,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 122,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 123,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 124,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 125,                  /* tMODULE  */
  YYSYMBOL_tMTA = 126,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 127,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 128,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 129,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 130,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 131,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 132,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 133,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 134,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 135,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 136,                  /* tOBJECT  */
  YYSYMBOL_tODL = 137,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 138,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 139,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 140,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 141,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 142,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 143,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 144,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 145,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 146,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 147,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 148,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 149,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 150,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 151,                   /* tPROXY  */
  YYSYMBOL_tPTR = 152,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 153,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 154,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 155,                /* tREADONLY  */
  YYSYMBOL_tREF = 156,                     /* tREF  */
  YYSYMBOL_tREGISTER = 157,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 158,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 159,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 160,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 161,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 162,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 163,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 164,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 165,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 166,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 167,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 168,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 169,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 170,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 171,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 172,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 173,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 174,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 175,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 176,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 177,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 178,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 179,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 180,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 181,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 182,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 183,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 184,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 185,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 186,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 187,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 188,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 189,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 190,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 191,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 192,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 193,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 194,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 195,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 196,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 197,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 198,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 199,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 200,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 201,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 202,                    /* tFREE  */
  YYSYMBOL_tBOTH = 203,                    /* tBOTH  */
  YYSYMBOL_204_ = 204,                     /* ','  */
  YYSYMBOL_205_ = 205,                     /* '?'  */
  YYSYMBOL_206_ = 206,                     /* ':'  */
  YYSYMBOL_207_ = 207,                     /* '|'  */
  YYSYMBOL_208_ = 208,                     /* '^'  */
  YYSYMBOL_209_ = 209,                     /* '&'  */
  YYSYMBOL_210_ = 210,                     /* '<'  */
  YYSYMBOL_211_ = 211,                     /* '>'  */
  YYSYMBOL_212_ = 212,                     /* '-'  */
  YYSYMBOL_213_ = 213,                     /* '+'  */
  YYSYMBOL_214_ = 214,                     /* '*'  */
  YYSYMBOL_215_ = 215,                     /* '/'  */
  YYSYMBOL_216_ = 216,                     /* '%'  */
  YYSYMBOL_217_ = 217,                     /* '!'  */
  YYSYMBOL_218_ = 218,                     /* '~'  */
  YYSYMBOL_CAST = 219,                     /* CAST  */
  YYSYMBOL_PPTR = 220,                     /* PPTR  */
  YYSYMBOL_POS = 221,                      /* POS  */
  YYSYMBOL_NEG = 222,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 223,                /* ADDRESSOF  */
  YYSYMBOL_224_ = 224,                     /* '.'  */
  YYSYMBOL_225_ = 225,                     /* '['  */
  YYSYMBOL_226_ = 226,                     /* ']'  */
  YYSYMBOL_227_ = 227,                     /* ';'  */
  YYSYMBOL_228_ = 228,                     /* '{'  */
  YYSYMBOL_229_ = 229,                     /* '}'  */
  YYSYMBOL_230_ = 230,                     /* '('  */
  YYSYMBOL_231_ = 231,                     /* ')'  */
  YYSYMBOL_232_ = 232,                     /* '='  */
  YYSYMBOL_YYACCEPT = 233,                 /* $accept  */
  YYSYMBOL_input = 234,                    /* input  */
  YYSYMBOL_m_acf = 235,                    /* m_acf  */
  YYSYMBOL_decl_statements = 236,          /* decl_statements  */
  YYSYMBOL_decl_block = 237,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 238,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 239,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 240,           /* gbl_statements  */
  YYSYMBOL_241_1 = 241,                    /* $@1  */
  YYSYMBOL_imp_statements = 242,           /* imp_statements  */
  YYSYMBOL_243_2 = 243,                    /* $@2  */
  YYSYMBOL_int_statements = 244,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 245,            /* semicolon_opt  */
  YYSYMBOL_statement = 246,                /* statement  */
  YYSYMBOL_pragma_warning = 247,           /* pragma_warning  */
  YYSYMBOL_warnings = 248,                 /* warnings  */
  YYSYMBOL_typedecl = 249,                 /* typedecl  */
  YYSYMBOL_cppquote = 250,                 /* cppquote  */
  YYSYMBOL_import_start = 251,             /* import_start  */
  YYSYMBOL_import = 252,                   /* import  */
  YYSYMBOL_importlib = 253,                /* importlib  */
  YYSYMBOL_libraryhdr = 254,               /* libraryhdr  */
  YYSYMBOL_library_start = 255,            /* library_start  */
  YYSYMBOL_librarydef = 256,               /* librarydef  */
  YYSYMBOL_m_args = 257,                   /* m_args  */
  YYSYMBOL_arg_list = 258,                 /* arg_list  */
  YYSYMBOL_args = 259,                     /* args  */
  YYSYMBOL_arg = 260,                      /* arg  */
  YYSYMBOL_array = 261,                    /* array  */
  YYSYMBOL_m_attributes = 262,             /* m_attributes  */
  YYSYMBOL_attributes = 263,               /* attributes  */
  YYSYMBOL_attrib_list = 264,              /* attrib_list  */
  YYSYMBOL_str_list = 265,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 266,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 267,             /* contract_ver  */
  YYSYMBOL_contract_req = 268,             /* contract_req  */
  YYSYMBOL_static_attr = 269,              /* static_attr  */
  YYSYMBOL_attribute = 270,                /* attribute  */
  YYSYMBOL_uuid_string = 271,              /* uuid_string  */
  YYSYMBOL_callconv = 272,                 /* callconv  */
  YYSYMBOL_cases = 273,                    /* cases  */
  YYSYMBOL_case = 274,                     /* case  */
  YYSYMBOL_enums = 275,                    /* enums  */
  YYSYMBOL_enum_list = 276,                /* enum_list  */
  YYSYMBOL_enum_member = 277,              /* enum_member  */
  YYSYMBOL_enum = 278,                     /* enum  */
  YYSYMBOL_enumdef = 279,                  /* enumdef  */
  YYSYMBOL_m_exprs = 280,                  /* m_exprs  */
  YYSYMBOL_m_expr = 281,                   /* m_expr  */
  YYSYMBOL_expr = 282,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 283,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 284,           /* expr_int_const  */
  YYSYMBOL_expr_const = 285,               /* expr_const  */
  YYSYMBOL_fields = 286,                   /* fields  */
  YYSYMBOL_field = 287,                    /* field  */
  YYSYMBOL_ne_union_field = 288,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 289,          /* ne_union_fields  */
  YYSYMBOL_union_field = 290,              /* union_field  */
  YYSYMBOL_s_field = 291,                  /* s_field  */
  YYSYMBOL_funcdef = 292,                  /* funcdef  */
  YYSYMBOL_declaration = 293,              /* declaration  */
  YYSYMBOL_m_ident = 294,                  /* m_ident  */
  YYSYMBOL_m_typename = 295,               /* m_typename  */
  YYSYMBOL_typename = 296,                 /* typename  */
  YYSYMBOL_ident = 297,                    /* ident  */
  YYSYMBOL_base_type = 298,                /* base_type  */
  YYSYMBOL_m_int = 299,                    /* m_int  */
  YYSYMBOL_int_std = 300,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 301,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 302,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 303,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 304,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 305,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 306,                  /* coclass  */
  YYSYMBOL_coclassdef = 307,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 308,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 309,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 310,              /* apicontract  */
  YYSYMBOL_apicontract_def = 311,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 312,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 313,         /* class_interfaces  */
  YYSYMBOL_class_interface = 314,          /* class_interface  */
  YYSYMBOL_dispinterface = 315,            /* dispinterface  */
  YYSYMBOL_dispattributes = 316,           /* dispattributes  */
  YYSYMBOL_dispint_props = 317,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 318,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 319,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 320,                  /* inherit  */
  YYSYMBOL_type_parameter = 321,           /* type_parameter  */
  YYSYMBOL_type_parameters = 322,          /* type_parameters  */
  YYSYMBOL_interface = 323,                /* interface  */
  YYSYMBOL_324_3 = 324,                    /* $@3  */
  YYSYMBOL_325_4 = 325,                    /* $@4  */
  YYSYMBOL_required_types = 326,           /* required_types  */
  YYSYMBOL_requires = 327,                 /* requires  */
  YYSYMBOL_interfacedef = 328,             /* interfacedef  */
  YYSYMBOL_329_5 = 329,                    /* $@5  */
  YYSYMBOL_interfaceref = 330,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 331,         /* dispinterfaceref  */
  YYSYMBOL_module = 332,                   /* module  */
  YYSYMBOL_moduledef = 333,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 334,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 335,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 336,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 337,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 338,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 339,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 340,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 341,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 342,               /* declarator  */
  YYSYMBOL_direct_declarator = 343,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 344,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 345, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 346,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 347, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 348,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 349, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 350,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 351,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 352,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 353,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 354,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 355,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 356,          /* init_declarator  */
  YYSYMBOL_threading_type = 357,           /* threading_type  */
  YYSYMBOL_pointer_type = 358,             /* pointer_type  */
  YYSYMBOL_structdef = 359,                /* structdef  */
  YYSYMBOL_unqualified_type = 360,         /* unqualified_type  */
  YYSYMBOL_type = 361,                     /* type  */
  YYSYMBOL_typedef = 362,                  /* typedef  */
  YYSYMBOL_uniondef = 363,                 /* uniondef  */
  YYSYMBOL_version = 364,                  /* version  */
  YYSYMBOL_acf_statements = 365,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 366,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 367,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 368,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 369,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 370,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 371,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 372,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 373           /* allocate_option  */
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
#define YYLAST   3580

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  483
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  874

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   463


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
       2,     2,     2,   217,     2,     2,     2,   216,   209,     2,
     230,   231,   214,   213,   204,   212,   224,   215,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   206,   227,
     210,   232,   211,   205,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   225,     2,   226,   208,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   228,   207,   229,   218,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   219,
     220,   221,   222,   223
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   348,   348,   363,   363,   365,   366,   372,   374,   375,
     379,   381,   382,   382,   384,   385,   386,   387,   390,   393,
     394,   396,   397,   399,   400,   401,   402,   405,   406,   407,
     408,   408,   410,   411,   412,   415,   416,   418,   419,   421,
     422,   423,   424,   425,   428,   429,   432,   433,   437,   438,
     439,   440,   441,   442,   443,   446,   454,   462,   463,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   478,   480,
     488,   494,   498,   500,   504,   508,   509,   512,   513,   516,
     517,   521,   526,   533,   537,   538,   541,   542,   546,   549,
     550,   551,   554,   555,   559,   560,   561,   565,   566,   569,
     575,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   645,   646,   647,   648,   649,   650,   651,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   699,   700,   705,   706,   707,   708,   711,   712,   715,
     719,   725,   726,   727,   730,   734,   746,   751,   755,   760,
     763,   764,   767,   768,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   810,   812,   813,   816,   817,   820,   826,   832,
     833,   836,   841,   848,   849,   852,   853,   857,   858,   861,
     865,   871,   879,   883,   888,   889,   892,   893,   896,   897,
     900,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   916,   917,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   932,   933,   937,   938,   941,   946,   947,
     948,   949,   950,   954,   955,   959,   962,   966,   969,   973,
     976,   980,   983,   984,   988,   989,   992,   995,   998,   999,
    1002,  1003,  1007,  1009,  1013,  1014,  1015,  1018,  1022,  1023,
    1027,  1028,  1028,  1028,  1033,  1034,  1035,  1036,  1038,  1039,
    1042,  1042,  1055,  1059,  1060,  1064,  1067,  1070,  1075,  1076,
    1077,  1081,  1085,  1088,  1089,  1092,  1093,  1097,  1099,  1103,
    1104,  1108,  1109,  1110,  1114,  1116,  1117,  1121,  1122,  1123,
    1124,  1129,  1131,  1132,  1137,  1139,  1143,  1144,  1149,  1150,
    1151,  1152,  1156,  1164,  1166,  1167,  1172,  1174,  1178,  1179,
    1186,  1187,  1188,  1189,  1190,  1194,  1201,  1202,  1205,  1206,
    1209,  1216,  1217,  1222,  1223,  1227,  1228,  1229,  1230,  1231,
    1232,  1236,  1237,  1238,  1241,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1258,  1259,  1260,  1263,  1270,
    1272,  1278,  1279,  1280,  1284,  1285,  1289,  1290,  1294,  1301,
    1310,  1311,  1315,  1316,  1320,  1322,  1323,  1324,  1328,  1329,
    1334,  1335,  1336,  1337
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
  "aPRAGMA", "aKNOWNTYPE", "aNUM", "aHEXNUM", "aDOUBLE", "aSTRING",
  "aWSTRING", "aSQSTRING", "aUUID", "aEOF", "aACF", "SHL", "SHR",
  "MEMBERPTR", "EQUALITY", "INEQUALITY", "GREATEREQUAL", "LESSEQUAL",
  "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tACTIVATABLE", "tAGGREGATABLE",
  "tAGILE", "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT",
  "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE",
  "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK",
  "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECLARE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
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
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES",
  "tRESTRICTED", "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE",
  "tSTANDARD", "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING",
  "tSTRUCT", "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING",
  "tTRANSMITAS", "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE",
  "tUNSIGNED", "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM",
  "tVARARG", "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL",
  "tAPARTMENT", "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'",
  "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'",
  "'['", "']'", "';'", "'{'", "'}'", "'('", "')'", "'='", "$accept",
  "input", "m_acf", "decl_statements", "decl_block", "imp_decl_statements",
  "imp_decl_block", "gbl_statements", "$@1", "imp_statements", "$@2",
  "int_statements", "semicolon_opt", "statement", "pragma_warning",
  "warnings", "typedecl", "cppquote", "import_start", "import",
  "importlib", "libraryhdr", "library_start", "librarydef", "m_args",
  "arg_list", "args", "arg", "array", "m_attributes", "attributes",
  "attrib_list", "str_list", "marshaling_behavior", "contract_ver",
  "contract_req", "static_attr", "attribute", "uuid_string", "callconv",
  "cases", "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident",
  "m_typename", "typename", "ident", "base_type", "m_int", "int_std",
  "namespace_pfx", "qualified_type", "parameterized_type",
  "parameterized_type_arg", "parameterized_type_args", "coclass",
  "coclassdef", "runtimeclass", "runtimeclass_def", "apicontract",
  "apicontract_def", "namespacedef", "class_interfaces", "class_interface",
  "dispinterface", "dispattributes", "dispint_props", "dispint_meths",
  "dispinterfacedef", "inherit", "type_parameter", "type_parameters",
  "interface", "$@3", "$@4", "required_types", "requires", "interfacedef",
  "$@5", "interfaceref", "dispinterfaceref", "module", "moduledef",
  "storage_cls_spec", "function_specifier", "type_qualifier",
  "m_type_qual_list", "decl_spec", "unqualified_decl_spec",
  "m_decl_spec_no_type", "decl_spec_no_type", "declarator",
  "direct_declarator", "abstract_declarator",
  "abstract_declarator_no_direct", "m_abstract_declarator",
  "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "unqualified_type", "type", "typedef",
  "uniondef", "version", "acf_statements", "acf_int_statements",
  "acf_int_statement", "acf_interface", "acf_attributes",
  "acf_attribute_list", "acf_attribute", "allocate_option_list",
  "allocate_option", YY_NULLPTR
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
     455,   456,   457,   458,    44,    63,    58,   124,    94,    38,
      60,    62,    45,    43,    42,    47,    37,    33,   126,   459,
     460,   461,   462,   463,    46,    91,    93,    59,   123,   125,
      40,    41,    61
};
#endif

#define YYPACT_NINF (-651)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-471)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -651,   128,  1830,  -651,  -110,  -651,   -49,   -25,   352,  -651,
    -651,  -651,   352,  -651,   -36,   -60,   352,  -651,   358,  -651,
    -651,  -651,  -651,   103,   171,  -651,  -651,  -651,  -651,  -651,
     352,   103,   240,    33,  -651,   352,    40,   103,   550,  -651,
    -651,   370,   374,   550,  -651,  -651,  3382,  -651,  -651,  -651,
    -651,    25,  -651,  -651,  -651,  -651,  -651,   107,  2891,    69,
      82,  -651,  -651,  -651,   399,    87,  -651,   101,  -651,   115,
    -651,   119,  -651,   105,   120,   269,   123,   127,  -651,  -651,
      52,    52,    52,   130,  3021,   138,  -651,    52,   139,   147,
    -651,    78,  -651,   -25,   200,  -651,  -651,  -651,  -651,   384,
    -651,  -651,   -83,   169,  -651,  -651,  -651,   188,   208,  -651,
    -651,    93,  -651,  3021,  -651,  -651,    10,   196,   -86,   -73,
    -651,   192,  -651,   195,  -651,  -651,   197,  -651,  -651,  -651,
     198,   199,  -651,  -651,  -651,  -651,  -651,   201,   202,  -651,
     203,  -651,  -651,  -651,  -651,   204,  -651,  -651,  -651,   205,
    -651,  -651,  -651,   207,   209,  -651,  -651,   214,  -651,  -651,
    -651,  -651,  -651,   216,   217,   218,   219,   220,  -651,   221,
    -651,  -651,   222,  -651,   232,  -651,  -651,   233,   236,  -651,
    -651,   237,  -651,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,   238,  -651,  -651,  -651,   239,   242,  -651,
    -651,  -651,  -651,  -651,  -651,   248,  -651,  -651,   250,  -651,
    -651,  -651,   251,  -651,   252,  -651,  -651,   253,   255,   256,
     258,  -651,  -651,  -651,   259,   260,  -651,  -651,   261,   262,
     263,  -102,  -651,  -651,  -651,  1986,  1092,   213,   404,   352,
     352,   405,   408,   267,   243,   268,   271,   272,  -651,   273,
     130,   275,   277,  -651,   282,   287,  1189,  -651,  -651,  -651,
    -651,  -651,   283,  -651,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,   130,   130,  -651,  -651,   281,
    -115,  -651,  -651,  -651,    52,  -651,  -651,  -651,   278,  -651,
    -651,  -651,   -50,  -651,  -651,   421,   284,   -54,   -14,  -651,
    -651,   306,   308,   288,  -651,   294,  -651,  2993,   516,   276,
     352,   810,  2993,   522,   276,   810,   530,   532,   810,  2993,
     810,   534,   535,   810,   537,   810,   810,  2456,   810,   810,
      55,   539,   -44,   541,   810,  3021,   810,  2993,   810,  3021,
     -53,  3021,  3021,   276,   270,   545,  3021,  3382,   330,  -651,
     333,   332,  -651,  -651,  -651,  -651,   336,  -651,   338,  -651,
     343,  -651,   344,   346,   347,  -651,  -651,   123,  2993,  -651,
     349,  -651,  -651,   349,   -72,  -651,  -651,  -651,   342,   369,
    -651,  -651,  -651,  -651,   399,    65,   366,  -651,   -93,  -651,
     -15,    73,   361,  -651,   810,   247,  2456,  -651,  -651,    57,
      78,  -651,   368,  -651,   409,  -651,   352,   365,   397,   371,
    -651,   352,   598,   598,  -651,    81,   213,    86,   375,   401,
     377,  -651,  -651,   379,   381,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,   383,  -651,   810,   810,   810,   810,
     810,   810,   872,  2677,  -106,  -651,   387,   390,   388,   411,
    2677,   389,   391,  -651,  -104,   392,   393,   394,   395,   410,
     412,   414,   415,   789,   417,  2993,   126,   418,  -101,  -651,
    2677,  -651,  -651,  -651,   419,   423,   425,   426,   424,   433,
     -68,   434,   435,  2347,   436,  -651,  -651,  -651,  -651,  -651,
    -651,   438,   440,   441,   442,   428,  -651,   443,   444,   445,
    -651,  3382,  -651,   633,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,   130,    96,   106,   123,   409,   506,  1482,  -651,  -651,
    -651,  1189,  -651,  1380,   472,   -56,   454,  -651,  -651,  -651,
    -651,   895,  -651,  2565,   452,   483,  -651,  -651,  -651,  -651,
    -651,  -651,   -40,  -651,  -651,   504,   485,  -651,  -651,   109,
     810,  -651,  -651,   489,  -651,    51,    53,  -651,  2993,  -651,
    2993,   465,  -651,   470,  -651,   471,  -651,   522,  -651,  -651,
    -651,  3123,    70,    70,    70,    70,    70,    70,  -651,  2460,
     494,  3225,    52,   810,   810,   696,   810,   810,   810,   810,
     810,   810,   810,   810,   810,   810,   810,   810,   810,   810,
     810,   810,   810,   704,   810,   810,  -651,  -651,   705,  -651,
     810,  -651,  -651,   701,  -651,  -651,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,  -651,  -651,   126,  -651,  2109,  -651,   126,
    -651,  -651,  -651,   -13,  -651,   810,  -651,  -651,  -651,  -651,
    -651,   810,  -651,  -651,  -651,  2993,  -651,  -651,  -651,  -651,
    -651,  -651,   706,  -651,  -651,  -651,  -651,   -31,   482,  -651,
    -651,   510,   123,     5,  -651,   123,  -651,    87,  -651,   409,
     488,   123,  -651,  2993,  -651,  -651,  -651,   511,   491,  1686,
     493,  -651,  -651,  -651,  2354,    57,  -651,   498,   497,   504,
    1189,  -651,  -651,   352,   517,  -651,  -651,  -651,   126,   500,
     130,   114,   352,  -651,  -651,  -651,   494,  -651,  -651,  2232,
    -651,   494,  -651,   507,    -4,    52,  -651,   175,   175,  -651,
    1155,  1155,   156,   156,   568,  2031,  2639,   714,  2694,  2701,
     156,   156,   170,   170,    70,    70,    70,  -651,  2587,  -651,
    -651,   509,  -651,  -651,   118,  -651,   512,   126,   513,  -651,
    2456,  -651,  -651,   514,  -651,  -651,   409,  -651,   123,  1236,
     130,  -651,   352,   409,   515,   520,  -651,    87,  -651,   533,
    -651,  -651,  -651,  -651,  -651,  2993,   521,  -651,  -651,  -651,
    -651,  -651,   736,  -651,  -651,   -91,  -651,  -651,   543,  -651,
     -88,  -651,  -651,   523,  -651,   525,   280,  -651,   526,   126,
     527,  -651,   810,  2456,  -651,  -651,   810,  -651,  -651,  -651,
     118,  -651,  -651,  -651,   529,  -651,   551,  -651,  -651,  -651,
    -651,  -651,   399,  -651,  -651,   409,  1584,  -651,   538,   540,
     810,  -651,   126,  -651,  -651,  -651,  -651,   118,  -651,  -651,
    -651,    70,   531,  2677,  -651,  -651,  1189,  -651,    87,  -651,
     123,  -651,  -651,  -651,  -651,    31,  -651,  -651,   -46,  -651,
     810,   547,  -651,  -651,   542,   558,   194,  -651,   194,  -651,
    -651,   544,  -651,  -651
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,     3,     1,   298,    53,   454,   464,     0,   309,
     301,   320,     0,   382,     0,     0,     0,   308,   296,   310,
     378,   307,   311,   312,     0,   381,   314,   321,   322,   319,
       0,   312,     0,     0,   380,     0,     0,   312,     0,   316,
     379,   296,   296,   306,   445,   302,   101,     2,    26,    25,
      54,     0,    48,    27,    51,    27,    24,     0,    87,   447,
       0,   325,   446,   303,     0,     0,   457,     0,    18,     0,
      22,     0,    20,     0,     0,     0,    46,     0,    16,    23,
     389,   389,   389,     0,     0,   449,   455,   389,     0,   451,
     323,     0,     4,   464,     0,   298,   299,   339,   335,     0,
       5,   346,   448,     0,   297,   313,   318,     0,   360,   317,
     341,     0,   337,     0,   315,   304,   450,     0,   452,     0,
     305,     0,   103,     0,   105,   106,     0,   107,   108,   109,
       0,     0,   112,   113,   114,   115,   116,     0,     0,   119,
       0,   121,   122,   123,   124,     0,   126,   127,   128,     0,
     130,   131,   132,     0,     0,   135,   136,     0,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,   148,     0,
     150,   151,     0,   153,     0,   155,   156,   159,     0,   160,
     161,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   175,   176,   177,     0,     0,   180,
     181,   182,   183,   443,   184,     0,   186,   441,     0,   188,
     189,   190,     0,   192,     0,   194,   195,     0,     0,     0,
       0,   200,   442,   201,     0,     0,   205,   206,     0,     0,
       0,     0,    89,   210,    49,    86,    86,    86,   296,     0,
       0,   296,   296,     0,   447,     0,     0,     0,   370,     0,
       0,   449,   451,    50,   298,   456,     0,    17,    21,    19,
      12,    15,     0,    47,   372,    14,   393,   390,   392,   391,
     213,   214,   215,   216,   383,     0,     0,   300,   397,   433,
     396,   293,   447,   449,   389,   451,   385,    52,     0,   476,
     475,   477,     0,   472,   465,     0,     0,     0,    86,    69,
     361,     0,     0,     0,   279,     0,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,    88,    70,
       0,     0,    43,    40,    41,    42,     0,    34,     0,    38,
       0,    36,     0,     0,     0,    32,    39,    46,     0,    87,
     448,    72,   376,   450,   452,    73,   342,   342,     0,   354,
      44,   292,   324,   328,     0,   329,   331,   333,     0,    11,
       0,     0,     0,   395,     0,     0,    75,   399,   386,     0,
       0,   471,     0,    68,     0,     7,     0,     0,   223,   228,
     224,     0,     0,     0,   453,    86,    86,    86,     0,     0,
       0,   212,   211,     0,     0,   243,   234,   235,   236,   240,
     241,   242,   237,   238,     0,   239,     0,     0,     0,     0,
       0,     0,     0,   277,     0,   275,     0,    97,     0,     0,
     278,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   418,     0,     0,   230,
     233,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   440,   435,   436,   437,   438,
     439,     0,     0,     0,     0,   461,   463,     0,     0,     0,
      90,   101,     8,     0,    33,    37,    35,    30,    29,    28,
      74,     0,    86,    86,    46,     0,   368,    86,   326,   330,
     332,     0,   327,    86,     0,    86,     0,   384,   394,   398,
     434,     0,    85,     0,     0,    79,    76,    77,   482,   480,
     483,   481,     0,   478,   473,   466,     0,   226,   229,    86,
       0,   357,   358,   362,    57,     0,     0,   444,     0,   280,
       0,     0,   459,    87,   286,     0,   102,     0,   104,   204,
     110,     0,   267,   266,   265,   268,   263,   264,   454,     0,
     406,     0,   389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   117,     0,   118,
       0,   125,   129,     0,   133,   134,   137,   143,   144,   145,
     146,   147,   149,   152,   154,   418,   383,    75,   423,   418,
     420,   419,    82,   415,   158,   232,   157,   162,   174,   178,
     179,     0,   187,   191,   193,     0,   196,   197,   199,   198,
     202,   203,     0,   207,   208,   209,    91,     0,     0,    27,
     426,   458,    46,     0,   343,    46,   340,   355,   356,     0,
       0,    46,    45,    87,   334,    13,   348,     0,     0,     0,
       0,    84,    83,   400,     0,     0,   474,   470,     0,   466,
       0,   225,   227,     0,     0,    58,    55,    56,     0,   451,
       0,   449,   294,   284,   283,    99,   406,   274,   383,    75,
     410,   406,   407,     0,   403,   389,   387,   256,   257,   269,
     250,   251,   254,   255,   245,   246,     0,   247,   248,   249,
     253,   252,   259,   258,   261,   262,   260,   270,     0,   276,
      98,     0,    93,    81,   418,   383,     0,   418,     0,   414,
      75,   422,   231,     0,   100,   462,     0,    10,    46,    86,
       0,   336,     0,     0,     0,     0,   338,   364,   365,   369,
      44,   377,   350,   349,   352,     0,     0,   291,   353,    80,
      78,   479,     0,   469,   467,     0,   359,   363,   428,   431,
       0,   282,   289,     0,   295,     0,   406,   383,     0,   418,
       0,   402,     0,    75,   409,   388,     0,   273,   120,   413,
     418,   424,   417,   421,     0,   185,     0,    71,    31,   427,
     375,   373,     0,   344,   345,     0,    86,   351,     0,     0,
       0,   430,     0,   281,   217,   272,   401,   418,   411,   405,
     408,   271,     0,   244,   416,   425,     0,   374,   366,   367,
      46,   468,     6,   429,   432,     0,   404,   412,     0,   371,
       0,     0,   460,   218,     0,     0,    86,     9,    86,   288,
     220,     0,   219,   287
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -651,  -651,  -651,  -651,  -651,  -651,  -651,   396,  -651,   -52,
    -651,     3,  -313,    -1,  -651,   353,  -651,  -651,  -651,  -651,
    -651,  -651,  -651,    30,  -557,  -651,  -651,  -292,  -227,  -232,
       0,  -651,  -651,  -651,   223,  -286,  -651,  -304,  -205,   -71,
    -651,  -651,  -651,  -651,  -651,   245,    13,   450,   135,   264,
    -651,  -279,  -297,  -651,  -651,  -651,  -651,   -81,  -322,  -651,
     110,  -651,    23,    -8,   -69,  -247,   158,   185,  -216,  -214,
    -249,   279,  -627,    22,    34,    26,    35,    28,    36,    37,
     420,  -651,    29,  -651,  -651,  -651,  -651,  -651,    95,  -651,
      11,  -651,  -651,  -651,  -651,    43,  -651,  -651,  -651,  -651,
      45,  -651,  -651,  -339,  -568,   -29,   225,   -62,   -64,  -225,
    -651,  -651,  -651,  -618,  -651,  -650,  -651,  -548,  -651,  -651,
    -651,   -34,  -651,   549,  -651,   469,     4,  -363,   -23,  -651,
       9,  -651,   722,   133,  -651,  -651,   136,  -651,   427,  -651,
     143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    47,   297,    48,   657,   352,     2,   389,   235,
     659,   517,   264,   353,    50,   555,    51,    52,    53,    54,
     354,   243,    55,   355,   534,   535,   536,   537,   628,    57,
     369,   231,   454,   474,   448,   418,   481,   232,   423,   629,
     855,   863,   407,   408,   409,   410,   282,   468,   469,   443,
     444,   445,   451,   415,   559,   564,   417,   870,   871,   776,
      60,   793,   103,    61,   630,    62,   106,    63,    64,    65,
      66,   387,   388,   356,   357,   358,   359,   360,   361,   362,
     512,   664,   363,    75,   525,   679,    76,   516,   552,   553,
     364,   411,   694,   769,   670,   365,   379,   764,   765,   249,
     366,    80,    81,    82,   391,    83,   580,   266,    84,   279,
     280,   712,   800,   713,   714,   631,   748,   632,   633,   661,
     831,   789,   790,   281,   491,   233,   283,    86,    87,    88,
     285,   497,    92,   688,   689,    93,    94,   292,   293,   542,
     543
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,    49,    58,   236,    98,   368,    85,   386,   101,   383,
     104,    89,   276,    77,   278,    59,   267,   267,   267,   268,
     269,   455,   108,   267,    67,   286,   446,   112,    69,   250,
      71,    74,    56,   104,   104,   464,    68,    70,    72,    73,
     384,   457,   385,   500,   460,    78,   462,    79,   788,   467,
     392,   393,   527,   397,   510,   478,   255,   695,   744,   695,
     404,   284,   251,   785,   117,   119,   406,   252,   677,   248,
     746,   244,   762,   485,   860,   277,    95,   743,    96,   582,
     245,   749,   471,   756,   246,   538,   247,   585,   795,  -470,
     303,   861,  -298,   801,   561,   565,   301,   530,   605,    30,
     613,    13,   347,   635,   262,   305,  -298,   288,   203,   449,
     395,   521,   207,   521,    90,   396,   832,   270,   522,   763,
     829,    95,    13,    96,   348,   606,   539,   614,     3,    95,
     636,    96,   524,    95,    20,    96,   635,   289,   494,   833,
     796,   -64,  -298,   222,   -60,  -298,   486,   487,   488,   489,
     490,   290,   798,   302,   400,   306,  -298,   271,   521,   291,
      25,  -299,   270,   643,   685,   864,   528,    13,   100,    46,
     270,   583,   584,   585,   270,   405,   401,   810,   836,   276,
     107,   278,   788,   558,   560,   560,   472,   585,   384,   109,
     546,   686,   585,   814,    99,   114,   809,   656,   757,   812,
      91,   666,   271,   678,   276,   276,   278,   278,   582,    34,
     271,    46,   395,   105,   271,  -221,   272,   750,   715,   858,
     267,   395,   398,   115,   540,    40,   803,   473,   120,   837,
     104,   371,   372,   104,   104,    58,    58,   -62,  -298,    85,
      85,   424,   277,   110,    89,    89,   842,   273,    59,    59,
     425,   839,   234,   426,   427,   428,   429,   430,   431,   541,
     862,   272,   844,   111,   117,   119,   668,   277,   277,   272,
     113,   692,   386,   272,   383,   256,   495,   496,   419,   519,
     663,   663,   696,   419,   697,   421,   660,   274,   422,   856,
     456,   237,   273,   560,   603,   604,   -59,   256,   466,   384,
     273,   667,   277,   275,   273,   384,    46,   385,   482,   253,
     557,    46,   479,   741,   295,   562,   484,   406,   492,   493,
     276,    46,   278,   499,   270,   662,   739,   465,   257,    13,
     432,    46,   626,   260,    46,   665,    16,   547,  -222,   511,
     626,  -290,   258,   395,   274,  -290,   259,   261,   627,   761,
     263,   395,   766,   710,   265,    95,   627,    96,   771,   754,
     275,   102,   753,    96,   271,   -61,   287,   466,   598,   599,
     600,   601,   602,   116,   -63,    96,   518,   118,   581,    96,
     603,   604,   433,   277,   600,   601,   602,   598,   599,   600,
     601,   602,   780,   296,   603,   604,   465,   298,   277,   603,
     604,   526,   254,   551,    96,   527,   751,   370,   373,    96,
      96,   374,     4,    96,    96,   299,   434,   563,   300,    46,
     768,   869,   307,   272,   304,   308,   402,   309,   310,   311,
     435,   312,   313,   314,   315,   316,   625,   317,    46,   318,
     276,   386,   278,   383,   319,   817,   320,   321,   322,   323,
     324,   325,   326,   384,   273,   767,   436,   527,   277,   437,
     438,   531,   327,   328,   440,   441,   329,   330,   331,   332,
     -65,   527,   333,   532,   384,   792,   385,   442,   334,   710,
     335,   336,   337,   338,   710,   339,   340,   804,   341,   342,
     343,   344,   345,   346,   708,   375,   376,  -326,   527,   377,
     378,   380,   -66,   277,   -67,   395,   382,   581,   399,   711,
     709,   390,   412,   394,   413,   403,   672,   673,   267,   414,
     716,    85,    49,    58,   416,   420,    89,    85,   447,   698,
      59,   700,    89,   853,    77,   819,    59,   859,   270,   452,
     384,   453,   816,   458,   459,    67,   461,   822,   475,    69,
     477,    71,    74,    56,   498,   501,   747,    68,    70,    72,
      73,   502,   503,   504,   701,   505,    78,   699,    79,   710,
     506,   514,   507,   508,   509,   515,   849,  -298,   271,   450,
     520,   865,   450,   583,   584,   585,   586,   587,   588,   589,
     463,   591,   529,   470,   548,    11,   545,   386,   466,   383,
     470,   549,   483,   550,   554,   567,   566,   759,   568,   384,
     569,   848,   570,   571,   608,   610,   419,   277,   607,   609,
     611,   277,   612,   615,   616,   617,   618,   465,   641,   276,
     384,   278,   385,   794,   560,   711,   560,   272,   799,   645,
     711,   619,   658,   620,   250,   621,   622,    23,   624,   634,
     637,   267,   652,   805,   638,   466,   639,   640,   450,   533,
      26,    27,    28,    29,   642,   644,   669,   647,   273,   648,
      31,   649,   650,   651,   653,   654,   655,   251,   676,   775,
     466,   680,   252,   683,   465,   551,   244,   684,   687,   276,
     277,   278,   277,   693,   277,   690,   702,   703,   704,   719,
     572,   573,   574,   575,   576,   577,   579,   737,   708,   465,
     742,   740,   755,   758,   760,    37,   770,   772,   773,   395,
      39,   466,   778,    91,   709,   711,   783,   791,   787,   583,
     584,   585,   586,   587,   588,   589,   277,   825,   802,   277,
     808,   828,   823,   811,   813,   815,   250,   824,   827,   830,
     465,   834,   277,   866,   820,   821,   835,   838,   840,    58,
     845,   846,   857,    85,   868,   851,   556,   852,    89,   867,
     752,   873,    59,   826,   466,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   523,   480,   872,   786,   777,
     705,   277,   603,   604,   691,   575,   706,   513,   854,   381,
     674,   476,   277,   465,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   425,   847,   294,   426,   427,   428,   429,
     430,   431,   784,   782,   277,   672,   673,   544,   781,   277,
      85,     0,     0,     0,     0,    89,     0,     0,     0,    59,
       0,     0,     0,     0,     0,     0,     0,   717,   718,     0,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   734,   735,   736,     0,   738,     0,
       0,     0,     0,     0,   450,   425,     0,   578,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,     0,     0,     0,     0,   425,   470,
       0,   426,   427,   428,   429,   430,   431,     0,     0,     9,
       0,    10,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    13,   594,   595,   596,   597,   598,   599,   600,   601,
     602,     0,     0,     0,     0,     0,     0,     0,   603,   604,
       0,     0,    17,     0,     0,   433,     0,     0,   238,    19,
       0,     0,     0,     0,    20,   432,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,   432,   434,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,   435,   592,     0,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,     0,   433,     0,     0,
       0,     0,     0,   603,   604,     0,     0,     0,     0,   436,
     623,     0,   437,   438,   439,     0,     0,   440,   441,    34,
     433,     0,     0,     0,     0,     0,    36,    37,    38,     0,
     442,   434,    39,     0,     0,    40,     0,     0,     0,   241,
       0,     0,     0,     0,     0,   435,     0,     0,   242,     0,
      43,     0,     0,     0,   434,     0,   841,     0,    44,    45,
     843,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,   436,     0,     0,   437,   438,   439,     0,     0,   440,
     441,     0,     0,     0,   450,     4,     5,     6,     0,     0,
       0,     0,   442,     0,   436,     0,     0,   437,   438,   439,
       0,     0,   440,   441,     0,     0,     0,     0,     0,     0,
       0,   681,     0,     8,     0,   442,     0,     0,     0,     9,
       0,    10,     0,     0,     0,     0,     0,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    14,     0,
     350,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,    17,     0,     0,     0,     0,     0,    18,    19,
     583,   584,   585,     0,    20,   588,   589,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     4,     0,    96,     0,    24,   351,     0,     0,
      25,     0,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     9,     0,    10,     0,
       0,     0,     0,     0,    11,     0,     0,    33,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,    35,    36,    37,    38,    17,
       0,     0,    39,     0,     0,    40,    19,     8,     0,    41,
       0,     0,     0,     9,     0,    10,    21,     0,    42,    22,
      43,    11,    12,     0,     0,    13,    23,     0,    44,    45,
       0,     0,    14,     0,   350,     0,     0,     0,     0,    26,
      27,    28,    29,    16,     0,     0,    17,     0,     0,    31,
       0,     0,    18,    19,     0,     0,     0,    46,    20,     0,
       0,   367,     0,    21,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,   351,     0,     0,    25,     0,    26,    27,    28,    29,
      30,     0,     0,     0,    37,    38,    31,     0,     0,    39,
       0,     0,     0,    32,     0,   596,   597,   598,   599,   600,
     601,   602,     0,     0,     0,     0,     0,    43,     0,   603,
     604,    33,     0,     4,     5,     6,    45,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     8,     0,    41,     0,     0,     0,     9,     0,    10,
       0,     0,    42,     0,    43,    11,    12,     0,     0,    13,
       0,     0,    44,    45,     0,     0,    14,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,    46,    20,     0,     0,   818,     0,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    24,     4,     5,     6,    25,     0,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,    10,     0,     0,     0,    33,     0,    11,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    34,    14,     0,
       0,     0,     0,    35,    36,    37,    38,     0,     0,     0,
      39,     0,    17,    40,     0,     0,     0,    41,    18,    19,
       0,     0,     0,     0,    20,     0,    42,     0,    43,    21,
       0,     0,    22,     0,     0,     0,    44,    45,     0,    23,
       0,     0,     0,     0,     0,     0,    24,     4,     5,     6,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,    46,     0,     0,     0,   675,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,     0,     0,     0,    33,     0,    11,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    34,
      14,     0,     0,     0,     0,     0,    36,    37,    38,     0,
       0,     0,    39,     0,    17,    40,     0,     0,     0,    41,
      18,    19,     0,     0,     0,     0,    20,     0,    42,     0,
      43,    21,     0,     0,    22,     0,     0,     0,    44,    45,
       0,    23,     0,     0,     0,     0,     0,     0,    24,     4,
       0,     6,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,     0,    46,     0,     0,
       0,   671,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,    33,
       0,    11,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,    17,    40,     0,     0,
       0,    41,   238,    19,     0,     0,     0,     0,    20,     0,
      42,     0,    43,    21,     0,     0,    22,     0,     0,     0,
      44,    45,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,     0,    46,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,    34,     7,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     8,     0,   241,     0,     0,     0,     9,     0,    10,
       0,     0,   242,     0,    43,    11,    12,     0,     0,    13,
       0,     0,    44,    45,     0,     0,    14,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,    46,    20,     0,     0,   774,     0,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,    25,     0,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     4,
       5,     6,     0,    35,    36,    37,    38,     0,     0,   349,
      39,     0,     0,    40,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   -86,     0,    42,     8,    43,     0,
       0,     0,     0,     9,     0,    10,    44,    45,     0,     0,
       0,    11,    12,     0,     0,    13,     0,     0,     0,     0,
       0,     0,    14,     0,   350,     0,   583,   584,   585,   586,
     587,   588,   589,    16,     0,    46,    17,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    21,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,   351,     0,     0,    25,     0,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     4,    32,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     9,     0,    10,    35,
      36,    37,    38,   270,    11,     0,    39,     0,    13,    40,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,    43,     0,     0,     0,     0,    17,
       0,     0,    44,    45,     0,   238,    19,     0,     0,     0,
       0,    20,     0,   271,     0,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     4,     0,     6,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,     0,     0,
       0,     0,   272,     0,     0,   603,   604,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     9,
       0,    10,     0,    36,    37,    38,   270,    11,     0,    39,
       0,    13,    40,   273,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,   242,     0,    43,     0,     0,
       0,     0,    17,     0,     0,    44,    45,     0,   238,    19,
       0,     0,     0,     0,    20,     0,   271,     0,     0,    21,
       0,     0,    22,   745,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     4,     0,     6,
       0,     0,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,     0,     0,     0,   272,     0,     0,   779,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     9,     0,    10,     0,     0,    36,    37,    38,    11,
       0,     0,    39,    13,     0,    40,   273,     0,     0,   241,
       0,     0,     0,     0,     0,     0,     0,     0,   242,     0,
      43,     0,     0,     0,    17,     0,     0,     0,    44,    45,
     238,    19,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    21,     0,     0,    22,     0,   797,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    46,     0,     4,
       0,     6,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,   583,   584,   585,   586,   587,
     588,   589,   590,   591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,     0,
       0,    11,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,    17,    40,     0,     0,
       0,   241,   238,    19,     0,     0,     0,     0,    20,     0,
     242,     0,    43,    21,     0,     0,    22,     0,     0,     0,
      44,    45,   592,    23,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,    25,     0,    26,    27,    28,    29,
       0,   603,   604,     0,     0,     0,    31,     0,   646,    46,
     583,   584,   585,   586,   587,   588,   589,   590,   591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,   242,     0,    43,     0,     0,     0,     0,     0,
       0,     0,    44,    45,   583,   584,   585,   586,   587,   588,
     589,   590,   591,     0,     0,   592,     0,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,     0,     0,     0,
       0,    46,     0,     0,   603,   604,     0,     0,     0,     0,
       0,   707,   583,   584,   585,   586,   587,   588,   589,   590,
     591,     0,     0,     0,     0,     0,     0,     0,     0,   583,
     584,   585,   586,   587,   588,   589,   583,   584,   585,   586,
     587,   588,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,     0,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,     0,     0,     0,     0,     0,     0,     0,   603,
     604,   682,   592,     0,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,     0,     0,     0,     0,     0,     0,
       0,   603,   604,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   592,   806,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,     0,     0,     0,     0,
       0,     0,     0,   603,   604,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,     0,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,     4,     0,     6,     0,     0,     0,
       0,   603,   604,   595,   596,   597,   598,   599,   600,   601,
     602,   596,   597,   598,   599,   600,   601,   602,   603,   604,
       0,     0,     8,     0,     0,   603,   604,     0,     9,     0,
      10,     0,     0,     0,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -347,     0,
       0,    17,     0,     0,     0,     0,     0,   238,    19,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     6,    25,
       0,    26,    27,    28,    29,    30,     0,     0,   239,     0,
       0,    31,     0,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     6,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    11,     0,
       0,     0,    13,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,    35,    36,    37,    38,     9,     0,
      10,    39,     0,    17,    40,     0,    11,     0,   241,   238,
      19,     0,     0,     0,     0,    20,     0,   242,     0,    43,
      21,     0,     0,    22,     0,     0,     0,    44,    45,     0,
      23,    17,     0,     0,     0,     0,     0,   238,    19,     0,
       0,    25,     0,    26,    27,    28,    29,     0,    21,     0,
       0,    22,     0,    31,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   578,     0,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       9,     0,    10,    39,     0,     0,    40,     0,    11,     0,
     241,     0,    13,     0,     0,     0,     0,     0,     0,   242,
       0,    43,     0,     0,     0,    36,    37,    38,     0,    44,
      45,    39,     0,    17,     0,     0,     0,     0,   241,   238,
      19,     0,     0,     0,     0,    20,     0,   242,     0,    43,
      21,     0,     0,    22,     0,     0,     0,    44,    45,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     578,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,    39,     0,    17,    40,     0,     0,     0,
     241,   238,    19,     0,     0,     0,     0,     0,     0,   242,
       0,    43,    21,     0,     0,    22,     0,     0,     0,    44,
      45,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,   241,     0,     0,     0,     0,   121,   122,     0,
       0,   242,   123,    43,   124,   125,   126,   127,   128,     0,
     129,    44,    45,   130,     0,   131,     0,     0,     0,   132,
     133,     0,   134,   135,   136,   137,   138,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,     0,
     149,     0,     0,   150,   151,   152,   153,   154,     0,     0,
     155,   156,   157,   158,     0,     0,     0,   159,   160,     0,
     161,   162,     0,   163,   164,   165,   166,   167,   168,     0,
     169,   170,   171,   172,   173,   174,     0,     0,   175,     0,
       0,   176,     0,     0,     0,     0,     0,   177,   178,     0,
     179,   180,     0,   181,   182,   183,     0,     0,     0,     0,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,     0,   197,     0,   198,     0,
     199,   200,   201,   202,   203,   204,   205,   206,   207,     0,
     208,   209,     0,   210,   211,     0,     0,     0,     0,     0,
     212,     0,     0,   213,     0,   214,     0,   215,   216,     0,
       0,   217,   218,   219,   220,     0,     0,   221,     0,   222,
       0,   223,   224,   225,   226,   227,   228,   229,     0,     0,
     230
};

static const yytype_int16 yycheck[] =
{
       8,     2,     2,    55,    12,   237,     2,   256,    16,   256,
      18,     2,    83,     2,    83,     2,    80,    81,    82,    81,
      82,   318,    30,    87,     2,    87,   312,    35,     2,    58,
       2,     2,     2,    41,    42,   327,     2,     2,     2,     2,
     256,   320,   256,   347,   323,     2,   325,     2,   698,   328,
     275,   276,   391,   280,   367,   334,    64,     6,   626,     6,
     114,    84,    58,   690,    41,    42,   298,    58,   124,    58,
     627,    58,    67,   126,    43,    83,     3,   625,     5,   442,
      58,   629,    27,   114,    58,    28,    58,    17,   706,   114,
     113,    60,   178,   711,   416,   417,     3,   394,   204,   114,
     204,    49,   204,   204,    75,   178,   178,    29,   152,   314,
     225,   204,   156,   204,   224,   230,   204,    44,   211,   114,
     211,     3,    49,     5,   226,   231,    69,   231,     0,     3,
     231,     5,   147,     3,    82,     5,   204,    59,   343,   227,
     708,   227,   228,   187,   227,   228,   199,   200,   201,   202,
     203,    73,   709,    60,   204,   228,   228,    84,   204,    81,
     108,   210,    44,   231,   204,   211,   391,    49,   228,   225,
      44,    15,    16,    17,    44,   229,   226,   745,   796,   250,
       9,   250,   832,   415,   416,   417,   131,    17,   404,    31,
     404,   231,    17,   750,   230,    37,   744,   501,   229,   747,
     225,   514,    84,   525,   275,   276,   275,   276,   571,   157,
      84,   225,   225,   110,    84,   229,   143,   230,   581,   846,
     284,   225,   284,    38,   167,   173,   230,   172,    43,   797,
     238,   239,   240,   241,   242,   235,   236,   227,   228,   235,
     236,   310,   250,     3,   235,   236,   803,   174,   235,   236,
       3,   799,   227,     6,     7,     8,     9,    10,    11,   202,
     229,   143,   810,   230,   241,   242,   515,   275,   276,   143,
     230,   550,   521,   143,   521,   210,     6,     7,   307,   214,
     512,   513,   231,   312,   231,     9,   511,   214,    12,   837,
     319,   184,   174,   525,   224,   225,   227,   210,   327,   515,
     174,   515,   310,   230,   174,   521,   225,   521,   337,   227,
     229,   225,   335,   610,   114,   229,   339,   549,   341,   342,
     391,   225,   391,   346,    44,   229,   605,   327,   227,    49,
      83,   225,   214,   228,   225,   229,    67,   406,   229,   368,
     214,   227,   227,   225,   214,   231,   227,   227,   230,   662,
     227,   225,   665,   580,   227,     3,   230,     5,   671,   645,
     230,     3,   641,     5,    84,   227,   227,   396,   212,   213,
     214,   215,   216,     3,   227,     5,   384,     3,   442,     5,
     224,   225,   135,   391,   214,   215,   216,   212,   213,   214,
     215,   216,   684,     9,   224,   225,   396,   228,   406,   224,
     225,   390,     3,   411,     5,   744,   633,     3,     3,     5,
       5,     3,     3,     5,     5,   227,   169,   417,   210,   225,
     669,   227,   230,   143,   228,   230,     5,   230,   230,   230,
     183,   230,   230,   230,   230,   230,   465,   230,   225,   230,
     511,   690,   511,   690,   230,   758,   230,   230,   230,   230,
     230,   230,   230,   669,   174,   669,   209,   796,   466,   212,
     213,   214,   230,   230,   217,   218,   230,   230,   230,   230,
     227,   810,   230,   226,   690,   700,   690,   230,   230,   706,
     230,   230,   230,   230,   711,   230,   230,   714,   230,   230,
     230,   230,   230,   230,   214,   228,   228,   210,   837,   228,
     228,   228,   227,   511,   227,   225,   224,   571,   230,   580,
     230,   228,   206,   232,   206,   231,   517,   517,   582,   231,
     582,   517,   523,   523,   230,     9,   517,   523,     6,   558,
     517,   560,   523,   830,   523,   760,   523,   850,    44,     9,
     756,     9,   756,     9,     9,   523,     9,   763,     9,   523,
       9,   523,   523,   523,     9,   225,   627,   523,   523,   523,
     523,   228,   230,   227,   560,   227,   523,   558,   523,   796,
     227,   229,   228,   227,   227,   206,   825,   228,    84,   315,
     214,   860,   318,    15,    16,    17,    18,    19,    20,    21,
     326,    23,   231,   329,   229,    45,   228,   846,   627,   846,
     336,   204,   338,   232,     6,   204,   231,   659,   231,   825,
     231,   825,   231,   230,   224,   204,   645,   625,   231,   231,
     231,   629,   231,   231,   231,   231,   231,   627,   204,   700,
     846,   700,   846,   702,   866,   706,   868,   143,   709,   204,
     711,   231,     9,   231,   673,   231,   231,    97,   231,   231,
     231,   715,   224,   715,   231,   684,   231,   231,   394,   395,
     110,   111,   112,   113,   231,   231,   160,   231,   174,   231,
     120,   231,   231,   231,   231,   231,   231,   673,   206,   679,
     709,   227,   673,   231,   684,   693,   673,   204,   184,   760,
     698,   760,   700,   204,   702,   210,   231,   227,   227,     3,
     436,   437,   438,   439,   440,   441,   442,     3,   214,   709,
       9,     6,     6,   231,   204,   165,   228,   206,   227,   225,
     170,   750,   229,   225,   230,   796,   229,   227,   211,    15,
      16,    17,    18,    19,    20,    21,   744,   204,   231,   747,
     231,     5,   227,   231,   231,   231,   775,   227,   227,   206,
     750,   228,   760,   206,   762,   763,   231,   231,   231,   759,
     231,   210,   231,   759,   206,   227,   413,   227,   759,   227,
     635,   227,   759,   770,   803,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   389,   336,   868,   693,   679,
     567,   799,   224,   225,   549,   531,   571,   377,   832,   250,
     521,   332,   810,   803,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     3,   822,    93,     6,     7,     8,     9,
      10,    11,   689,   687,   832,   826,   826,   400,   685,   837,
     826,    -1,    -1,    -1,    -1,   826,    -1,    -1,    -1,   826,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,   584,    -1,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,    -1,   604,    -1,
      -1,    -1,    -1,    -1,   610,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,     3,   635,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,
      -1,    -1,    70,    -1,    -1,   135,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,   169,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   183,   205,    -1,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   135,    -1,    -1,
      -1,    -1,    -1,   224,   225,    -1,    -1,    -1,    -1,   209,
     231,    -1,   212,   213,   214,    -1,    -1,   217,   218,   157,
     135,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,
     230,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,   186,    -1,
     188,    -1,    -1,    -1,   169,    -1,   802,    -1,   196,   197,
     806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
      -1,   209,    -1,    -1,   212,   213,   214,    -1,    -1,   217,
     218,    -1,    -1,    -1,   830,     3,     4,     5,    -1,    -1,
      -1,    -1,   230,    -1,   209,    -1,    -1,   212,   213,   214,
      -1,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,    -1,    31,    -1,   230,    -1,    -1,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      15,    16,    17,    -1,    82,    20,    21,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,     3,    -1,     5,    -1,   104,   105,    -1,    -1,
     108,    -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,   145,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,   163,   164,   165,   166,    70,
      -1,    -1,   170,    -1,    -1,   173,    77,    31,    -1,   177,
      -1,    -1,    -1,    37,    -1,    39,    87,    -1,   186,    90,
     188,    45,    46,    -1,    -1,    49,    97,    -1,   196,   197,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,    67,    -1,    -1,    70,    -1,    -1,   120,
      -1,    -1,    76,    77,    -1,    -1,    -1,   225,    82,    -1,
      -1,   229,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,    -1,    -1,   108,    -1,   110,   111,   112,   113,
     114,    -1,    -1,    -1,   165,   166,   120,    -1,    -1,   170,
      -1,    -1,    -1,   127,    -1,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,   188,    -1,   224,
     225,   145,    -1,     3,     4,     5,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    31,    -1,   177,    -1,    -1,    -1,    37,    -1,    39,
      -1,    -1,   186,    -1,   188,    45,    46,    -1,    -1,    49,
      -1,    -1,   196,   197,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,   225,    82,    -1,    -1,   229,    -1,    87,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,     3,     4,     5,   108,    -1,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,    -1,    -1,   145,    -1,    45,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,   157,    56,    -1,
      -1,    -1,    -1,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    70,   173,    -1,    -1,    -1,   177,    76,    77,
      -1,    -1,    -1,    -1,    82,    -1,   186,    -1,   188,    87,
      -1,    -1,    90,    -1,    -1,    -1,   196,   197,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,     3,     4,     5,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,   225,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,    -1,   145,    -1,    45,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,   157,
      56,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    70,   173,    -1,    -1,    -1,   177,
      76,    77,    -1,    -1,    -1,    -1,    82,    -1,   186,    -1,
     188,    87,    -1,    -1,    90,    -1,    -1,    -1,   196,   197,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,     3,
      -1,     5,   108,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,   225,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,   145,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    70,   173,    -1,    -1,
      -1,   177,    76,    77,    -1,    -1,    -1,    -1,    82,    -1,
     186,    -1,   188,    87,    -1,    -1,    90,    -1,    -1,    -1,
     196,   197,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,   225,
      -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    14,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    31,    -1,   177,    -1,    -1,    -1,    37,    -1,    39,
      -1,    -1,   186,    -1,   188,    45,    46,    -1,    -1,    49,
      -1,    -1,   196,   197,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,   225,    82,    -1,    -1,   229,    -1,    87,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,     3,
       4,     5,    -1,   163,   164,   165,   166,    -1,    -1,    13,
     170,    -1,    -1,   173,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,    31,   188,    -1,
      -1,    -1,    -1,    37,    -1,    39,   196,   197,    -1,    -1,
      -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    -1,    15,    16,    17,    18,
      19,    20,    21,    67,    -1,   225,    70,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,    -1,    -1,   108,    -1,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,     3,   127,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    37,    -1,    39,   163,
     164,   165,   166,    44,    45,    -1,   170,    -1,    49,   173,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,   188,    -1,    -1,    -1,    -1,    70,
      -1,    -1,   196,   197,    -1,    76,    77,    -1,    -1,    -1,
      -1,    82,    -1,    84,    -1,    -1,    87,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   143,    -1,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    37,
      -1,    39,    -1,   164,   165,   166,    44,    45,    -1,   170,
      -1,    49,   173,   174,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,    -1,    -1,
      -1,    -1,    70,    -1,    -1,   196,   197,    -1,    76,    77,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    87,
      -1,    -1,    90,   214,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,   143,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    37,    -1,    39,    -1,    -1,   164,   165,   166,    45,
      -1,    -1,   170,    49,    -1,   173,   174,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,
     188,    -1,    -1,    -1,    70,    -1,    -1,    -1,   196,   197,
      76,    77,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    90,    -1,   214,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,   225,    -1,     3,
      -1,     5,   108,    -1,   110,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    70,   173,    -1,    -1,
      -1,   177,    76,    77,    -1,    -1,    -1,    -1,    82,    -1,
     186,    -1,   188,    87,    -1,    -1,    90,    -1,    -1,    -1,
     196,   197,   205,    97,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   108,    -1,   110,   111,   112,   113,
      -1,   224,   225,    -1,    -1,    -1,   120,    -1,   231,   225,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,   205,    -1,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,   225,    -1,    -1,   224,   225,    -1,    -1,    -1,    -1,
      -1,   231,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,    -1,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,     3,    -1,     5,    -1,    -1,    -1,
      -1,   224,   225,   209,   210,   211,   212,   213,   214,   215,
     216,   210,   211,   212,   213,   214,   215,   216,   224,   225,
      -1,    -1,    31,    -1,    -1,   224,   225,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,   108,
      -1,   110,   111,   112,   113,   114,    -1,    -1,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,    37,    -1,
      39,   170,    -1,    70,   173,    -1,    45,    -1,   177,    76,
      77,    -1,    -1,    -1,    -1,    82,    -1,   186,    -1,   188,
      87,    -1,    -1,    90,    -1,    -1,    -1,   196,   197,    -1,
      97,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,   108,    -1,   110,   111,   112,   113,    -1,    87,    -1,
      -1,    90,    -1,   120,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
      37,    -1,    39,   170,    -1,    -1,   173,    -1,    45,    -1,
     177,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,    -1,    -1,    -1,   164,   165,   166,    -1,   196,
     197,   170,    -1,    70,    -1,    -1,    -1,    -1,   177,    76,
      77,    -1,    -1,    -1,    -1,    82,    -1,   186,    -1,   188,
      87,    -1,    -1,    90,    -1,    -1,    -1,   196,   197,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,   108,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,
      -1,    -1,    -1,   170,    -1,    70,   173,    -1,    -1,    -1,
     177,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,    87,    -1,    -1,    90,    -1,    -1,    -1,   196,
     197,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,   186,    30,   188,    32,    33,    34,    35,    36,    -1,
      38,   196,   197,    41,    -1,    43,    -1,    -1,    -1,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      78,    79,    80,    81,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    -1,    91,    92,    93,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
     118,   119,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,
     128,   129,   130,    -1,   132,   133,   134,    -1,   136,   137,
     138,   139,   140,   141,   142,    -1,   144,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,   173,    -1,   175,   176,    -1,
      -1,   179,   180,   181,   182,    -1,    -1,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
     198
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   234,   240,     0,     3,     4,     5,    14,    31,    37,
      39,    45,    46,    49,    56,    58,    67,    70,    76,    77,
      82,    87,    90,    97,   104,   108,   110,   111,   112,   113,
     114,   120,   127,   145,   157,   163,   164,   165,   166,   170,
     173,   177,   186,   188,   196,   197,   225,   235,   237,   246,
     247,   249,   250,   251,   252,   255,   256,   262,   263,   279,
     293,   296,   298,   300,   301,   302,   303,   306,   307,   308,
     309,   310,   311,   312,   315,   316,   319,   323,   328,   333,
     334,   335,   336,   338,   341,   359,   360,   361,   362,   363,
     224,   225,   365,   368,   369,     3,     5,   296,   296,   230,
     228,   296,     3,   295,   296,   110,   299,     9,   296,   299,
       3,   230,   296,   230,   299,   300,     3,   295,     3,   295,
     300,    25,    26,    30,    32,    33,    34,    35,    36,    38,
      41,    43,    47,    48,    50,    51,    52,    53,    54,    55,
      57,    59,    60,    61,    62,    63,    64,    65,    66,    68,
      71,    72,    73,    74,    75,    78,    79,    80,    81,    85,
      86,    88,    89,    91,    92,    93,    94,    95,    96,    98,
      99,   100,   101,   102,   103,   106,   109,   115,   116,   118,
     119,   121,   122,   123,   128,   129,   130,   132,   133,   134,
     136,   137,   138,   139,   140,   141,   142,   144,   146,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   158,   159,
     161,   162,   168,   171,   173,   175,   176,   179,   180,   181,
     182,   185,   187,   189,   190,   191,   192,   193,   194,   195,
     198,   264,   270,   358,   227,   242,   242,   184,    76,   117,
     125,   177,   186,   254,   279,   306,   308,   310,   323,   332,
     338,   359,   363,   227,     3,   296,   210,   227,   227,   227,
     228,   227,   315,   227,   245,   227,   340,   341,   340,   340,
      44,    84,   143,   174,   214,   230,   272,   296,   297,   342,
     343,   356,   279,   359,   361,   363,   340,   227,    29,    59,
      73,    81,   370,   371,   365,   114,     9,   236,   228,   227,
     210,     3,    60,   361,   228,   178,   228,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   204,   226,    13,
      58,   105,   239,   246,   253,   256,   306,   307,   308,   309,
     310,   311,   312,   315,   323,   328,   333,   229,   262,   263,
       3,   296,   296,     3,     3,   228,   228,   228,   228,   329,
     228,   356,   224,   298,   301,   302,   303,   304,   305,   241,
     228,   337,   342,   342,   232,   225,   230,   261,   340,   230,
     204,   226,     5,   231,   114,   229,   262,   275,   276,   277,
     278,   324,   206,   206,   231,   286,   230,   289,   268,   338,
       9,     9,    12,   271,   297,     3,     6,     7,     8,     9,
      10,    11,    83,   135,   169,   183,   209,   212,   213,   214,
     217,   218,   230,   282,   283,   284,   268,     6,   267,   271,
     282,   285,     9,     9,   265,   285,   338,   284,     9,     9,
     284,     9,   284,   282,   260,   263,   338,   284,   280,   281,
     282,    27,   131,   172,   266,     9,   358,     9,   284,   361,
     280,   269,   338,   282,   361,   126,   199,   200,   201,   202,
     203,   357,   361,   361,   271,     6,     7,   364,     9,   361,
     270,   225,   228,   230,   227,   227,   227,   228,   227,   227,
     245,   338,   313,   313,   229,   206,   320,   244,   296,   214,
     214,   204,   211,   240,   147,   317,   323,   336,   342,   231,
     285,   214,   226,   282,   257,   258,   259,   260,    28,    69,
     167,   202,   372,   373,   371,   228,   302,   297,   229,   204,
     232,   296,   321,   322,     6,   248,   248,   229,   262,   287,
     262,   291,   229,   263,   288,   291,   231,   204,   231,   231,
     231,   230,   282,   282,   282,   282,   282,   282,     5,   282,
     339,   341,   360,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   205,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   224,   225,   204,   231,   231,   224,   231,
     204,   231,   231,   204,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   338,   214,   230,   261,   272,
     297,   348,   350,   351,   231,   204,   231,   231,   231,   231,
     231,   204,   231,   231,   231,   204,   231,   231,   231,   231,
     231,   231,   224,   231,   231,   231,   270,   238,     9,   243,
     342,   352,   229,   262,   314,   229,   245,   302,   303,   160,
     327,   229,   246,   263,   304,   229,   206,   124,   291,   318,
     227,   226,   226,   231,   204,   204,   231,   184,   366,   367,
     210,   278,   284,   204,   325,     6,   231,   231,   338,   363,
     338,   359,   231,   227,   227,   267,   339,   231,   214,   230,
     261,   272,   344,   346,   347,   360,   340,   282,   282,     3,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,     3,   282,   284,
       6,   285,     9,   350,   337,   214,   257,   272,   349,   350,
     230,   261,   281,   284,   268,     6,   114,   229,   231,   242,
     204,   245,    67,   114,   330,   331,   245,   302,   303,   326,
     228,   245,   206,   227,   229,   263,   292,   293,   229,    24,
     260,   373,   369,   229,   366,   305,   321,   211,   348,   354,
     355,   227,   342,   294,   297,   346,   337,   214,   257,   272,
     345,   346,   231,   230,   261,   340,   206,   226,   231,   350,
     337,   231,   350,   231,   257,   231,   302,   245,   229,   342,
     296,   296,   301,   227,   227,   204,   244,   227,     5,   211,
     206,   353,   204,   227,   228,   231,   346,   337,   231,   350,
     231,   282,   257,   282,   350,   231,   210,   296,   302,   303,
     229,   227,   227,   285,   354,   273,   350,   231,   305,   245,
      43,    60,   229,   274,   211,   284,   206,   227,   206,   227,
     290,   291,   290,   227
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   233,   234,   235,   235,   236,   236,   237,   238,   238,
     239,   240,   241,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   242,   242,   242,
     243,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   244,   244,   245,   245,   246,   246,
     246,   246,   246,   246,   246,   247,   247,   248,   248,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   261,   262,   262,   263,   264,
     264,   264,   265,   265,   266,   266,   266,   267,   267,   268,
     269,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   272,   272,   272,   272,   273,   273,   274,
     274,   275,   275,   275,   276,   276,   277,   278,   278,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   283,   283,   284,   285,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   293,   293,   294,   294,   295,   295,   296,   296,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   299,   299,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   301,   301,   302,   302,   303,   304,   304,
     304,   304,   304,   305,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   313,   314,   314,   315,   316,   317,   317,
     318,   318,   319,   319,   320,   320,   320,   321,   322,   322,
     323,   324,   325,   323,   326,   326,   326,   326,   327,   327,
     329,   328,   328,   330,   330,   331,   332,   333,   334,   334,
     334,   335,   336,   337,   337,   338,   338,   339,   339,   340,
     340,   341,   341,   341,   342,   342,   342,   343,   343,   343,
     343,   344,   344,   344,   345,   345,   346,   346,   347,   347,
     347,   347,   347,   348,   348,   348,   349,   349,   350,   350,
     351,   351,   351,   351,   351,   351,   352,   352,   353,   353,
     354,   355,   355,   356,   356,   357,   357,   357,   357,   357,
     357,   358,   358,   358,   359,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   361,   361,   361,   362,   363,
     363,   364,   364,   364,   365,   365,   366,   366,   367,   368,
     369,   369,   370,   370,   371,   371,   371,   371,   372,   372,
     373,   373,   373,   373
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     7,     4,     0,     7,
       4,     0,     0,     6,     3,     3,     2,     3,     2,     3,
       2,     3,     2,     2,     2,     2,     2,     0,     3,     3,
       0,     6,     2,     3,     2,     3,     2,     3,     2,     2,
       2,     2,     2,     2,     0,     2,     0,     1,     1,     2,
       2,     1,     2,     1,     1,     6,     6,     1,     2,     1,
       2,     1,     2,     1,     2,     2,     2,     2,     4,     3,
       3,     5,     2,     3,     4,     0,     1,     1,     3,     1,
       3,     3,     2,     3,     3,     2,     0,     1,     3,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     0,     4,     1,     4,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     1,     4,     4,     1,
       6,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       1,     1,     1,     4,     4,     1,     1,     4,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     1,     4,
       1,     1,     4,     1,     4,     1,     1,     4,     4,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     4,
       1,     1,     1,     1,     1,     6,     1,     4,     1,     1,
       1,     4,     1,     4,     1,     1,     4,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     4,
       3,     0,     2,     1,     1,     3,     2,     3,     1,     5,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     3,
       3,     5,     5,     4,     3,     1,     3,     1,     1,     0,
       2,     4,     3,     2,     2,     0,     2,     2,     1,     3,
       2,     1,     3,     2,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     2,     3,     1,     2,     4,     1,     1,
       2,     1,     2,     1,     3,     2,     6,     2,     6,     2,
       5,     2,     0,     2,     3,     3,     2,     1,     2,     3,
       2,     3,     6,     6,     0,     2,     2,     1,     1,     3,
       2,     0,     0,     7,     1,     1,     3,     3,     0,     2,
       0,     9,     2,     2,     3,     2,     2,     6,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     2,     3,     0,
       1,     2,     2,     2,     3,     2,     1,     1,     3,     2,
       4,     3,     2,     1,     3,     2,     0,     1,     3,     2,
       1,     3,     4,     3,     2,     1,     3,     2,     0,     1,
       1,     3,     2,     1,     3,     4,     1,     3,     0,     2,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     1,     2,     1,
       2,     1,     2,     4,     1,     1,     2,     1,     5,     5,
      10,     1,     3,     1,     0,     2,     0,     2,     4,     6,
       0,     3,     1,     3,     4,     1,     1,     1,     1,     3,
       1,     1,     1,     1
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
#line 348 "tools/widl/parser.y"
                                                { (yyvsp[-1].stmt_list) = append_parameterized_type_stmts((yyvsp[-1].stmt_list));
						  check_statements((yyvsp[-1].stmt_list), FALSE);
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
#line 3368 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 365 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3374 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 367 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3382 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 372 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3388 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 374 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3394 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 376 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3400 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 379 "tools/widl/parser.y"
                                                     { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3406 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 381 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3412 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 382 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3418 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 383 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3424 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 384 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3430 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 385 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3436 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 386 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3442 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements coclass ';'  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3450 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclassdef  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3458 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements apicontract ';'  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3464 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract_def  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3471 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 396 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3477 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 397 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3484 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements moduledef  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3490 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements librarydef  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3496 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements statement  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3502 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements decl_block  */
#line 402 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3508 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: %empty  */
#line 405 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3514 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: imp_statements interface ';'  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3520 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements dispinterface ';'  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3526 "tools/widl/parser.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 408 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3532 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 409 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3538 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements interfacedef  */
#line 410 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3544 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements coclass ';'  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3550 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements coclassdef  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3558 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements apicontract ';'  */
#line 415 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3564 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements apicontract_def  */
#line 416 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3571 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements runtimeclass ';'  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3577 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements runtimeclass_def  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3584 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements moduledef  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3590 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements statement  */
#line 422 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3596 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements importlib  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3602 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements librarydef  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3608 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements imp_decl_block  */
#line 425 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3614 "tools/widl/parser.tab.c"
    break;

  case 44: /* int_statements: %empty  */
#line 428 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3620 "tools/widl/parser.tab.c"
    break;

  case 45: /* int_statements: int_statements statement  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3626 "tools/widl/parser.tab.c"
    break;

  case 48: /* statement: cppquote  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3632 "tools/widl/parser.tab.c"
    break;

  case 49: /* statement: typedecl ';'  */
#line 438 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3638 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: declaration ';'  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3644 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: import  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3650 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: typedef ';'  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3656 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: aPRAGMA  */
#line 442 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3662 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: pragma_warning  */
#line 443 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3668 "tools/widl/parser.tab.c"
    break;

  case 55: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 447 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3680 "tools/widl/parser.tab.c"
    break;

  case 56: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 455 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3689 "tools/widl/parser.tab.c"
    break;

  case 57: /* warnings: aNUM  */
#line 462 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3695 "tools/widl/parser.tab.c"
    break;

  case 58: /* warnings: warnings aNUM  */
#line 463 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3701 "tools/widl/parser.tab.c"
    break;

  case 60: /* typedecl: tENUM aIDENTIFIER  */
#line 468 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3707 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 470 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tUNION aIDENTIFIER  */
#line 472 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3719 "tools/widl/parser.tab.c"
    break;

  case 65: /* typedecl: attributes enumdef  */
#line 473 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3725 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: attributes structdef  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3731 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes uniondef  */
#line 475 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3737 "tools/widl/parser.tab.c"
    break;

  case 68: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3743 "tools/widl/parser.tab.c"
    break;

  case 69: /* import_start: tIMPORT aSTRING ';'  */
#line 480 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3754 "tools/widl/parser.tab.c"
    break;

  case 70: /* import: import_start imp_statements aEOF  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3763 "tools/widl/parser.tab.c"
    break;

  case 71: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 495 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3769 "tools/widl/parser.tab.c"
    break;

  case 72: /* libraryhdr: tLIBRARY typename  */
#line 498 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3775 "tools/widl/parser.tab.c"
    break;

  case 73: /* library_start: attributes libraryhdr '{'  */
#line 500 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3783 "tools/widl/parser.tab.c"
    break;

  case 74: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3789 "tools/widl/parser.tab.c"
    break;

  case 75: /* m_args: %empty  */
#line 508 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3795 "tools/widl/parser.tab.c"
    break;

  case 77: /* arg_list: arg  */
#line 512 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3801 "tools/widl/parser.tab.c"
    break;

  case 78: /* arg_list: arg_list ',' arg  */
#line 513 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3807 "tools/widl/parser.tab.c"
    break;

  case 80: /* args: arg_list ',' ELLIPSIS  */
#line 517 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3813 "tools/widl/parser.tab.c"
    break;

  case 81: /* arg: attributes decl_spec m_any_declarator  */
#line 521 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3823 "tools/widl/parser.tab.c"
    break;

  case 82: /* arg: decl_spec m_any_declarator  */
#line 526 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3833 "tools/widl/parser.tab.c"
    break;

  case 83: /* array: '[' expr ']'  */
#line 533 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3842 "tools/widl/parser.tab.c"
    break;

  case 84: /* array: '[' '*' ']'  */
#line 537 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3848 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' ']'  */
#line 538 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3854 "tools/widl/parser.tab.c"
    break;

  case 86: /* m_attributes: %empty  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3860 "tools/widl/parser.tab.c"
    break;

  case 88: /* attributes: '[' attrib_list ']'  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3866 "tools/widl/parser.tab.c"
    break;

  case 89: /* attrib_list: attribute  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3872 "tools/widl/parser.tab.c"
    break;

  case 90: /* attrib_list: attrib_list ',' attribute  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3878 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attrib_list ']' '[' attribute  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3884 "tools/widl/parser.tab.c"
    break;

  case 92: /* str_list: aSTRING  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3890 "tools/widl/parser.tab.c"
    break;

  case 93: /* str_list: str_list ',' aSTRING  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3896 "tools/widl/parser.tab.c"
    break;

  case 94: /* marshaling_behavior: tAGILE  */
#line 559 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3902 "tools/widl/parser.tab.c"
    break;

  case 95: /* marshaling_behavior: tNONE  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3908 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tSTANDARD  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3914 "tools/widl/parser.tab.c"
    break;

  case 97: /* contract_ver: aNUM  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3920 "tools/widl/parser.tab.c"
    break;

  case 98: /* contract_ver: aNUM '.' aNUM  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3926 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_req: decl_spec ',' contract_ver  */
#line 569 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3936 "tools/widl/parser.tab.c"
    break;

  case 100: /* static_attr: decl_spec ',' contract_req  */
#line 575 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 3945 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: %empty  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3951 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tACTIVATABLE '(' contract_req ')'  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 3957 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tAGGREGATABLE  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3963 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3969 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tAPPOBJECT  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3975 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tASYNC  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3981 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tAUTOHANDLE  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3987 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tBINDABLE  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3993 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tBROADCAST  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3999 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tCALLAS '(' ident ')'  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 4005 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 4011 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tCODE  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 4017 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tCOMMSTATUS  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 4023 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tCONTEXTHANDLE  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 4029 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4035 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4041 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 4047 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 4053 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCONTROL  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 4059 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 599 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 4065 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tDECODE  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 4071 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tDEFAULT  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 4077 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tDEFAULTBIND  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 4083 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tDEFAULTCOLLELEM  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 4089 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 4095 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tDEFAULTVTABLE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 4101 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 4107 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tDISPLAYBIND  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 4113 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 4119 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDUAL  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 4125 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tENABLEALLOCATE  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 4131 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tENCODE  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4137 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tENDPOINT '(' str_list ')'  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4143 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tENTRY '(' expr_const ')'  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4149 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tEVENTADD  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4155 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tEVENTREMOVE  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4161 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 616 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4169 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tEXPLICITHANDLE  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4175 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tFAULTSTATUS  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4181 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tFLAGS  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4187 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tFORCEALLOCATE  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4193 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tHANDLE  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4199 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4205 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4211 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4217 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 627 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4223 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4229 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tHIDDEN  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4235 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tID '(' expr_int_const ')'  */
#line 630 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4241 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tIDEMPOTENT  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4247 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tIGNORE  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4253 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tIIDIS '(' expr ')'  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4259 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tIMMEDIATEBIND  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4265 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4271 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tIN  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4277 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tINPUTSYNC  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4283 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4289 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tLCID '(' expr_int_const ')'  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4295 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tLCID  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4301 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tLICENSED  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4307 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tLOCAL  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4313 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4319 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tMAYBE  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4325 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tMESSAGE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4331 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tNOCODE  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4337 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tNONBROWSABLE  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4343 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tNONCREATABLE  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4349 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tNONEXTENSIBLE  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4355 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tNOTIFY  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4361 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tNOTIFYFLAG  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4367 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tOBJECT  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4373 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tODL  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4379 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tOLEAUTOMATION  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4385 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4391 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tOPTIONAL  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4397 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tOUT  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4403 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tPARTIALIGNORE  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4409 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4415 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tPROGID '(' aSTRING ')'  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4421 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tPROPGET  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4427 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tPROPPUT  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4433 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tPROPPUTREF  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4439 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tPROXY  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4445 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tPUBLIC  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4451 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 668 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4459 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tREADONLY  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4465 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tREPRESENTAS '(' type ')'  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4471 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tREQUESTEDIT  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4477 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tRESTRICTED  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4483 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tRETVAL  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4489 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4495 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tSOURCE  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4501 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tSTATIC '(' static_attr ')'  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4507 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4513 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tSTRING  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4519 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tSWITCHIS '(' expr ')'  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4525 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4531 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tTRANSMITAS '(' type ')'  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4537 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tTHREADING '(' threading_type ')'  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4543 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tUIDEFAULT  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4549 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tUSESGETLASTERROR  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4555 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4561 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tUUID '(' uuid_string ')'  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4567 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4573 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tV1ENUM  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4579 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tVARARG  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4585 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tVERSION '(' version ')'  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4591 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4597 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4603 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: pointer_type  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4609 "tools/widl/parser.tab.c"
    break;

  case 212: /* uuid_string: aSTRING  */
#line 700 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4617 "tools/widl/parser.tab.c"
    break;

  case 213: /* callconv: tCDECL  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4623 "tools/widl/parser.tab.c"
    break;

  case 214: /* callconv: tFASTCALL  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4629 "tools/widl/parser.tab.c"
    break;

  case 215: /* callconv: tPASCAL  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4635 "tools/widl/parser.tab.c"
    break;

  case 216: /* callconv: tSTDCALL  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4641 "tools/widl/parser.tab.c"
    break;

  case 217: /* cases: %empty  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4647 "tools/widl/parser.tab.c"
    break;

  case 218: /* cases: cases case  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4653 "tools/widl/parser.tab.c"
    break;

  case 219: /* case: tCASE expr_int_const ':' union_field  */
#line 715 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4662 "tools/widl/parser.tab.c"
    break;

  case 220: /* case: tDEFAULT ':' union_field  */
#line 719 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4671 "tools/widl/parser.tab.c"
    break;

  case 221: /* enums: %empty  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4677 "tools/widl/parser.tab.c"
    break;

  case 222: /* enums: enum_list ','  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4683 "tools/widl/parser.tab.c"
    break;

  case 224: /* enum_list: enum  */
#line 730 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4692 "tools/widl/parser.tab.c"
    break;

  case 225: /* enum_list: enum_list ',' enum  */
#line 734 "tools/widl/parser.y"
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
#line 4707 "tools/widl/parser.tab.c"
    break;

  case 226: /* enum_member: m_attributes ident  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4715 "tools/widl/parser.tab.c"
    break;

  case 227: /* enum: enum_member '=' expr_int_const  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4724 "tools/widl/parser.tab.c"
    break;

  case 228: /* enum: enum_member  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4732 "tools/widl/parser.tab.c"
    break;

  case 229: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4738 "tools/widl/parser.tab.c"
    break;

  case 230: /* m_exprs: m_expr  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4744 "tools/widl/parser.tab.c"
    break;

  case 231: /* m_exprs: m_exprs ',' m_expr  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4750 "tools/widl/parser.tab.c"
    break;

  case 232: /* m_expr: %empty  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: aNUM  */
#line 771 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4762 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: aHEXNUM  */
#line 772 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4768 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: aDOUBLE  */
#line 773 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4774 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: tFALSE  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4780 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: tNULL  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4786 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: tTRUE  */
#line 776 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4792 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: aSTRING  */
#line 777 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4798 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: aWSTRING  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4804 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: aSQSTRING  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4810 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: aIDENTIFIER  */
#line 780 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4816 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr '?' expr ':' expr  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4822 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: expr LOGICALOR expr  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4828 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr LOGICALAND expr  */
#line 783 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4834 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr '|' expr  */
#line 784 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4840 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr '^' expr  */
#line 785 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4846 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '&' expr  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4852 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr EQUALITY expr  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4858 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr INEQUALITY expr  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4864 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '>' expr  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4870 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr '<' expr  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4876 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr GREATEREQUAL expr  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4882 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr LESSEQUAL expr  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4888 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr SHL expr  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4894 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr SHR expr  */
#line 794 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4900 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '+' expr  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4906 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr '-' expr  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4912 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr '%' expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4918 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '*' expr  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4924 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr '/' expr  */
#line 799 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4930 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: '!' expr  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4936 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: '~' expr  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4942 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: '+' expr  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4948 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: '-' expr  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4954 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: '&' expr  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4960 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: '*' expr  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4966 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4972 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: expr '.' aIDENTIFIER  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4978 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4984 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4990 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: expr '[' expr ']'  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4996 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: '(' expr ')'  */
#line 813 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5002 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr_list_int_const: expr_int_const  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5008 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 817 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5014 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr_int_const: expr  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5023 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr_const: expr  */
#line 826 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5032 "tools/widl/parser.tab.c"
    break;

  case 279: /* fields: %empty  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5038 "tools/widl/parser.tab.c"
    break;

  case 280: /* fields: fields field  */
#line 833 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5044 "tools/widl/parser.tab.c"
    break;

  case 281: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 837 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5053 "tools/widl/parser.tab.c"
    break;

  case 282: /* field: m_attributes uniondef ';'  */
#line 841 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5062 "tools/widl/parser.tab.c"
    break;

  case 283: /* ne_union_field: s_field ';'  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5068 "tools/widl/parser.tab.c"
    break;

  case 284: /* ne_union_field: attributes ';'  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5074 "tools/widl/parser.tab.c"
    break;

  case 285: /* ne_union_fields: %empty  */
#line 852 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5080 "tools/widl/parser.tab.c"
    break;

  case 286: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 853 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5086 "tools/widl/parser.tab.c"
    break;

  case 287: /* union_field: s_field ';'  */
#line 857 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5092 "tools/widl/parser.tab.c"
    break;

  case 288: /* union_field: ';'  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5098 "tools/widl/parser.tab.c"
    break;

  case 289: /* s_field: m_attributes decl_spec declarator  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5107 "tools/widl/parser.tab.c"
    break;

  case 290: /* s_field: m_attributes structdef  */
#line 865 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5116 "tools/widl/parser.tab.c"
    break;

  case 291: /* funcdef: declaration  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5126 "tools/widl/parser.tab.c"
    break;

  case 292: /* declaration: attributes decl_spec init_declarator  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5134 "tools/widl/parser.tab.c"
    break;

  case 293: /* declaration: decl_spec init_declarator  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5142 "tools/widl/parser.tab.c"
    break;

  case 294: /* m_ident: %empty  */
#line 888 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5148 "tools/widl/parser.tab.c"
    break;

  case 296: /* m_typename: %empty  */
#line 892 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5154 "tools/widl/parser.tab.c"
    break;

  case 300: /* ident: typename  */
#line 900 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5160 "tools/widl/parser.tab.c"
    break;

  case 301: /* base_type: tBYTE  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5166 "tools/widl/parser.tab.c"
    break;

  case 302: /* base_type: tWCHAR  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5172 "tools/widl/parser.tab.c"
    break;

  case 304: /* base_type: tSIGNED int_std  */
#line 906 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5178 "tools/widl/parser.tab.c"
    break;

  case 305: /* base_type: tUNSIGNED int_std  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5184 "tools/widl/parser.tab.c"
    break;

  case 306: /* base_type: tUNSIGNED  */
#line 908 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5190 "tools/widl/parser.tab.c"
    break;

  case 307: /* base_type: tFLOAT  */
#line 909 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5196 "tools/widl/parser.tab.c"
    break;

  case 308: /* base_type: tDOUBLE  */
#line 910 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5202 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tBOOLEAN  */
#line 911 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5208 "tools/widl/parser.tab.c"
    break;

  case 310: /* base_type: tERRORSTATUST  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5214 "tools/widl/parser.tab.c"
    break;

  case 311: /* base_type: tHANDLET  */
#line 913 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5220 "tools/widl/parser.tab.c"
    break;

  case 314: /* int_std: tINT  */
#line 920 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5226 "tools/widl/parser.tab.c"
    break;

  case 315: /* int_std: tSHORT m_int  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5232 "tools/widl/parser.tab.c"
    break;

  case 316: /* int_std: tSMALL  */
#line 922 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5238 "tools/widl/parser.tab.c"
    break;

  case 317: /* int_std: tLONG m_int  */
#line 923 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5244 "tools/widl/parser.tab.c"
    break;

  case 318: /* int_std: tHYPER m_int  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5250 "tools/widl/parser.tab.c"
    break;

  case 319: /* int_std: tINT64  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5256 "tools/widl/parser.tab.c"
    break;

  case 320: /* int_std: tCHAR  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5262 "tools/widl/parser.tab.c"
    break;

  case 321: /* int_std: tINT32  */
#line 927 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5268 "tools/widl/parser.tab.c"
    break;

  case 322: /* int_std: tINT3264  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5274 "tools/widl/parser.tab.c"
    break;

  case 323: /* namespace_pfx: aIDENTIFIER '.'  */
#line 932 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5280 "tools/widl/parser.tab.c"
    break;

  case 324: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 933 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5286 "tools/widl/parser.tab.c"
    break;

  case 325: /* qualified_type: typename  */
#line 937 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5292 "tools/widl/parser.tab.c"
    break;

  case 326: /* qualified_type: namespace_pfx typename  */
#line 938 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5298 "tools/widl/parser.tab.c"
    break;

  case 327: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5304 "tools/widl/parser.tab.c"
    break;

  case 328: /* parameterized_type_arg: base_type  */
#line 946 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5310 "tools/widl/parser.tab.c"
    break;

  case 329: /* parameterized_type_arg: qualified_type  */
#line 947 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5316 "tools/widl/parser.tab.c"
    break;

  case 330: /* parameterized_type_arg: qualified_type '*'  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5322 "tools/widl/parser.tab.c"
    break;

  case 331: /* parameterized_type_arg: parameterized_type  */
#line 949 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5328 "tools/widl/parser.tab.c"
    break;

  case 332: /* parameterized_type_arg: parameterized_type '*'  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5334 "tools/widl/parser.tab.c"
    break;

  case 333: /* parameterized_type_args: parameterized_type_arg  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5340 "tools/widl/parser.tab.c"
    break;

  case 334: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5346 "tools/widl/parser.tab.c"
    break;

  case 335: /* coclass: tCOCLASS typename  */
#line 959 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5352 "tools/widl/parser.tab.c"
    break;

  case 336: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 963 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5358 "tools/widl/parser.tab.c"
    break;

  case 337: /* runtimeclass: tRUNTIMECLASS typename  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5364 "tools/widl/parser.tab.c"
    break;

  case 338: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5370 "tools/widl/parser.tab.c"
    break;

  case 339: /* apicontract: tAPICONTRACT typename  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5376 "tools/widl/parser.tab.c"
    break;

  case 340: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5382 "tools/widl/parser.tab.c"
    break;

  case 341: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 980 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5388 "tools/widl/parser.tab.c"
    break;

  case 342: /* class_interfaces: %empty  */
#line 983 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5394 "tools/widl/parser.tab.c"
    break;

  case 343: /* class_interfaces: class_interfaces class_interface  */
#line 984 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5400 "tools/widl/parser.tab.c"
    break;

  case 344: /* class_interface: m_attributes interfaceref ';'  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5406 "tools/widl/parser.tab.c"
    break;

  case 345: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 989 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5412 "tools/widl/parser.tab.c"
    break;

  case 346: /* dispinterface: tDISPINTERFACE typename  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5418 "tools/widl/parser.tab.c"
    break;

  case 347: /* dispattributes: attributes  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 348: /* dispint_props: tPROPERTIES ':'  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5430 "tools/widl/parser.tab.c"
    break;

  case 349: /* dispint_props: dispint_props s_field ';'  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5436 "tools/widl/parser.tab.c"
    break;

  case 350: /* dispint_meths: tMETHODS ':'  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5442 "tools/widl/parser.tab.c"
    break;

  case 351: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1003 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5448 "tools/widl/parser.tab.c"
    break;

  case 352: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5454 "tools/widl/parser.tab.c"
    break;

  case 353: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5460 "tools/widl/parser.tab.c"
    break;

  case 354: /* inherit: %empty  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5466 "tools/widl/parser.tab.c"
    break;

  case 355: /* inherit: ':' qualified_type  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5472 "tools/widl/parser.tab.c"
    break;

  case 356: /* inherit: ':' parameterized_type  */
#line 1015 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5478 "tools/widl/parser.tab.c"
    break;

  case 357: /* type_parameter: typename  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5484 "tools/widl/parser.tab.c"
    break;

  case 358: /* type_parameters: type_parameter  */
#line 1022 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5490 "tools/widl/parser.tab.c"
    break;

  case 359: /* type_parameters: type_parameters ',' type_parameter  */
#line 1023 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5496 "tools/widl/parser.tab.c"
    break;

  case 360: /* interface: tINTERFACE typename  */
#line 1027 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5502 "tools/widl/parser.tab.c"
    break;

  case 361: /* $@3: %empty  */
#line 1028 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5508 "tools/widl/parser.tab.c"
    break;

  case 362: /* $@4: %empty  */
#line 1028 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5514 "tools/widl/parser.tab.c"
    break;

  case 363: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1029 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5520 "tools/widl/parser.tab.c"
    break;

  case 364: /* required_types: qualified_type  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5526 "tools/widl/parser.tab.c"
    break;

  case 365: /* required_types: parameterized_type  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5532 "tools/widl/parser.tab.c"
    break;

  case 366: /* required_types: required_types ',' qualified_type  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5538 "tools/widl/parser.tab.c"
    break;

  case 367: /* required_types: required_types ',' parameterized_type  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5544 "tools/widl/parser.tab.c"
    break;

  case 368: /* requires: %empty  */
#line 1038 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5550 "tools/widl/parser.tab.c"
    break;

  case 369: /* requires: tREQUIRES required_types  */
#line 1039 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5556 "tools/widl/parser.tab.c"
    break;

  case 370: /* $@5: %empty  */
#line 1042 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5562 "tools/widl/parser.tab.c"
    break;

  case 371: /* interfacedef: attributes interface $@5 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1044 "tools/widl/parser.y"
                                                { if ((yyvsp[-7].type)->type_type == TYPE_PARAMETERIZED_TYPE)
						  {
						      (yyval.type) = type_parameterized_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list));
						      pop_parameters_namespace((yyvsp[-7].type)->name);
						  }
						  else
						  {
						      (yyval.type) = type_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list));
						      check_async_uuid((yyval.type));
						  }
						}
#line 5578 "tools/widl/parser.tab.c"
    break;

  case 372: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1055 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5584 "tools/widl/parser.tab.c"
    break;

  case 373: /* interfaceref: tINTERFACE typename  */
#line 1059 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5590 "tools/widl/parser.tab.c"
    break;

  case 374: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5596 "tools/widl/parser.tab.c"
    break;

  case 375: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1064 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5602 "tools/widl/parser.tab.c"
    break;

  case 376: /* module: tMODULE typename  */
#line 1067 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5608 "tools/widl/parser.tab.c"
    break;

  case 377: /* moduledef: attributes module '{' int_statements '}' semicolon_opt  */
#line 1071 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5614 "tools/widl/parser.tab.c"
    break;

  case 378: /* storage_cls_spec: tEXTERN  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5620 "tools/widl/parser.tab.c"
    break;

  case 379: /* storage_cls_spec: tSTATIC  */
#line 1076 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5626 "tools/widl/parser.tab.c"
    break;

  case 380: /* storage_cls_spec: tREGISTER  */
#line 1077 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5632 "tools/widl/parser.tab.c"
    break;

  case 381: /* function_specifier: tINLINE  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5638 "tools/widl/parser.tab.c"
    break;

  case 382: /* type_qualifier: tCONST  */
#line 1085 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5644 "tools/widl/parser.tab.c"
    break;

  case 383: /* m_type_qual_list: %empty  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5650 "tools/widl/parser.tab.c"
    break;

  case 384: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1089 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5656 "tools/widl/parser.tab.c"
    break;

  case 385: /* decl_spec: type m_decl_spec_no_type  */
#line 1092 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5662 "tools/widl/parser.tab.c"
    break;

  case 386: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1094 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5668 "tools/widl/parser.tab.c"
    break;

  case 387: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1098 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5674 "tools/widl/parser.tab.c"
    break;

  case 388: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1100 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5680 "tools/widl/parser.tab.c"
    break;

  case 389: /* m_decl_spec_no_type: %empty  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5686 "tools/widl/parser.tab.c"
    break;

  case 391: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1108 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5692 "tools/widl/parser.tab.c"
    break;

  case 392: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1109 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5698 "tools/widl/parser.tab.c"
    break;

  case 393: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1110 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5704 "tools/widl/parser.tab.c"
    break;

  case 394: /* declarator: '*' m_type_qual_list declarator  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5710 "tools/widl/parser.tab.c"
    break;

  case 395: /* declarator: callconv declarator  */
#line 1116 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5716 "tools/widl/parser.tab.c"
    break;

  case 397: /* direct_declarator: ident  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5722 "tools/widl/parser.tab.c"
    break;

  case 398: /* direct_declarator: '(' declarator ')'  */
#line 1122 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5728 "tools/widl/parser.tab.c"
    break;

  case 399: /* direct_declarator: direct_declarator array  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5734 "tools/widl/parser.tab.c"
    break;

  case 400: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1124 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5740 "tools/widl/parser.tab.c"
    break;

  case 401: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1130 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5746 "tools/widl/parser.tab.c"
    break;

  case 402: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1131 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5752 "tools/widl/parser.tab.c"
    break;

  case 404: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5758 "tools/widl/parser.tab.c"
    break;

  case 405: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5764 "tools/widl/parser.tab.c"
    break;

  case 406: /* m_abstract_declarator: %empty  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5770 "tools/widl/parser.tab.c"
    break;

  case 408: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1149 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5776 "tools/widl/parser.tab.c"
    break;

  case 409: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1150 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5782 "tools/widl/parser.tab.c"
    break;

  case 410: /* abstract_direct_declarator: array  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5788 "tools/widl/parser.tab.c"
    break;

  case 411: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5796 "tools/widl/parser.tab.c"
    break;

  case 412: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5804 "tools/widl/parser.tab.c"
    break;

  case 413: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1165 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5810 "tools/widl/parser.tab.c"
    break;

  case 414: /* any_declarator: callconv m_any_declarator  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5816 "tools/widl/parser.tab.c"
    break;

  case 416: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1173 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5822 "tools/widl/parser.tab.c"
    break;

  case 417: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1174 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5828 "tools/widl/parser.tab.c"
    break;

  case 418: /* m_any_declarator: %empty  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5834 "tools/widl/parser.tab.c"
    break;

  case 420: /* any_direct_declarator: ident  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5840 "tools/widl/parser.tab.c"
    break;

  case 421: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1187 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5846 "tools/widl/parser.tab.c"
    break;

  case 422: /* any_direct_declarator: any_direct_declarator array  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5852 "tools/widl/parser.tab.c"
    break;

  case 423: /* any_direct_declarator: array  */
#line 1189 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5858 "tools/widl/parser.tab.c"
    break;

  case 424: /* any_direct_declarator: '(' m_args ')'  */
#line 1191 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5866 "tools/widl/parser.tab.c"
    break;

  case 425: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1195 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5874 "tools/widl/parser.tab.c"
    break;

  case 426: /* declarator_list: declarator  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5880 "tools/widl/parser.tab.c"
    break;

  case 427: /* declarator_list: declarator_list ',' declarator  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5886 "tools/widl/parser.tab.c"
    break;

  case 428: /* m_bitfield: %empty  */
#line 1205 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5892 "tools/widl/parser.tab.c"
    break;

  case 429: /* m_bitfield: ':' expr_const  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5898 "tools/widl/parser.tab.c"
    break;

  case 430: /* struct_declarator: any_declarator m_bitfield  */
#line 1209 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5907 "tools/widl/parser.tab.c"
    break;

  case 431: /* struct_declarator_list: struct_declarator  */
#line 1216 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5913 "tools/widl/parser.tab.c"
    break;

  case 432: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1218 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5919 "tools/widl/parser.tab.c"
    break;

  case 433: /* init_declarator: declarator  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5925 "tools/widl/parser.tab.c"
    break;

  case 434: /* init_declarator: declarator '=' expr_const  */
#line 1223 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5931 "tools/widl/parser.tab.c"
    break;

  case 435: /* threading_type: tAPARTMENT  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5937 "tools/widl/parser.tab.c"
    break;

  case 436: /* threading_type: tNEUTRAL  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5943 "tools/widl/parser.tab.c"
    break;

  case 437: /* threading_type: tSINGLE  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5949 "tools/widl/parser.tab.c"
    break;

  case 438: /* threading_type: tFREE  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5955 "tools/widl/parser.tab.c"
    break;

  case 439: /* threading_type: tBOTH  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5961 "tools/widl/parser.tab.c"
    break;

  case 440: /* threading_type: tMTA  */
#line 1232 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5967 "tools/widl/parser.tab.c"
    break;

  case 441: /* pointer_type: tREF  */
#line 1236 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5973 "tools/widl/parser.tab.c"
    break;

  case 442: /* pointer_type: tUNIQUE  */
#line 1237 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5979 "tools/widl/parser.tab.c"
    break;

  case 443: /* pointer_type: tPTR  */
#line 1238 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5985 "tools/widl/parser.tab.c"
    break;

  case 444: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1241 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5991 "tools/widl/parser.tab.c"
    break;

  case 445: /* unqualified_type: tVOID  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5997 "tools/widl/parser.tab.c"
    break;

  case 446: /* unqualified_type: base_type  */
#line 1246 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6003 "tools/widl/parser.tab.c"
    break;

  case 447: /* unqualified_type: enumdef  */
#line 1247 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6009 "tools/widl/parser.tab.c"
    break;

  case 448: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1248 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6015 "tools/widl/parser.tab.c"
    break;

  case 449: /* unqualified_type: structdef  */
#line 1249 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6021 "tools/widl/parser.tab.c"
    break;

  case 450: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1250 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6027 "tools/widl/parser.tab.c"
    break;

  case 451: /* unqualified_type: uniondef  */
#line 1251 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6033 "tools/widl/parser.tab.c"
    break;

  case 452: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1252 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 6039 "tools/widl/parser.tab.c"
    break;

  case 453: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1253 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6045 "tools/widl/parser.tab.c"
    break;

  case 454: /* unqualified_type: aKNOWNTYPE  */
#line 1254 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6051 "tools/widl/parser.tab.c"
    break;

  case 456: /* type: namespace_pfx typename  */
#line 1259 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6057 "tools/widl/parser.tab.c"
    break;

  case 457: /* type: parameterized_type  */
#line 1260 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6063 "tools/widl/parser.tab.c"
    break;

  case 458: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1264 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6072 "tools/widl/parser.tab.c"
    break;

  case 459: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1271 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 6078 "tools/widl/parser.tab.c"
    break;

  case 460: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6084 "tools/widl/parser.tab.c"
    break;

  case 461: /* version: aNUM  */
#line 1278 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6090 "tools/widl/parser.tab.c"
    break;

  case 462: /* version: aNUM '.' aNUM  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6096 "tools/widl/parser.tab.c"
    break;

  case 463: /* version: aHEXNUM  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6102 "tools/widl/parser.tab.c"
    break;

  case 468: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1295 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6110 "tools/widl/parser.tab.c"
    break;

  case 469: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1302 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6120 "tools/widl/parser.tab.c"
    break;

  case 470: /* acf_attributes: %empty  */
#line 1310 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6126 "tools/widl/parser.tab.c"
    break;

  case 471: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1311 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6132 "tools/widl/parser.tab.c"
    break;

  case 472: /* acf_attribute_list: acf_attribute  */
#line 1315 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6138 "tools/widl/parser.tab.c"
    break;

  case 473: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1316 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6144 "tools/widl/parser.tab.c"
    break;

  case 474: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1321 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 6150 "tools/widl/parser.tab.c"
    break;

  case 475: /* acf_attribute: tENCODE  */
#line 1322 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 6156 "tools/widl/parser.tab.c"
    break;

  case 476: /* acf_attribute: tDECODE  */
#line 1323 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 6162 "tools/widl/parser.tab.c"
    break;

  case 477: /* acf_attribute: tEXPLICITHANDLE  */
#line 1324 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 6168 "tools/widl/parser.tab.c"
    break;

  case 478: /* allocate_option_list: allocate_option  */
#line 1328 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6174 "tools/widl/parser.tab.c"
    break;

  case 479: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1330 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6180 "tools/widl/parser.tab.c"
    break;

  case 480: /* allocate_option: tDONTFREE  */
#line 1334 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6186 "tools/widl/parser.tab.c"
    break;

  case 481: /* allocate_option: tFREE  */
#line 1335 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6192 "tools/widl/parser.tab.c"
    break;

  case 482: /* allocate_option: tALLNODES  */
#line 1336 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6198 "tools/widl/parser.tab.c"
    break;

  case 483: /* allocate_option: tSINGLENODE  */
#line 1337 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6204 "tools/widl/parser.tab.c"
    break;


#line 6208 "tools/widl/parser.tab.c"

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

#line 1340 "tools/widl/parser.y"


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

typeref_list_t *append_typeref(typeref_list_t *list, typeref_t *ref)
{
    if (!ref) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &ref->entry );
    return list;
}

typeref_t *make_typeref(type_t *type)
{
    typeref_t *ref = xmalloc(sizeof(typeref_t));
    ref->type = type;
    ref->attrs = NULL;
    return ref;
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

static void push_parameters_namespace(const char *name)
{
    struct namespace *namespace;

    if (!(namespace = find_sub_namespace(current_namespace, name)))
    {
        namespace = xmalloc(sizeof(*namespace));
        namespace->name = xstrdup(name);
        namespace->parent = current_namespace;
        list_add_tail(&current_namespace->children, &namespace->entry);
        list_init(&namespace->children);
        memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
    }

    parameters_namespace = namespace;
}

static void pop_parameters_namespace(const char *name)
{
    assert(!strcmp(parameters_namespace->name, name) && parameters_namespace->parent);
    parameters_namespace = NULL;
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

static type_t *find_type_or_error(struct namespace *namespace, const char *name)
{
    type_t *type;
    if (!(type = find_type(name, namespace, 0)) &&
        !(type = find_type(name, parameters_namespace, 0)))
    {
        error_loc("type '%s' not found in %s namespace\n", name, namespace && namespace->name ? namespace->name : "global");
        return NULL;
    }
    return type;
}

static struct namespace *find_namespace_or_error(struct namespace *parent, const char *name)
{
    struct namespace *namespace = NULL;

    if (!winrt_mode)
        error_loc("namespaces are only supported in winrt mode.\n");
    else if (!(namespace = find_sub_namespace(parent, name)))
        error_loc("namespace '%s' not found in '%s'\n", name, parent->name);

    return namespace;
}

int is_type(const char *name)
{
    return find_type(name, current_namespace, 0) != NULL ||
           find_type(name, parameters_namespace, 0);
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
    /* ATTR_ACTIVATABLE */         { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "activatable" },
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
    /* ATTR_STATIC */              { 0, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "static" },
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
    case TYPE_PARAMETERIZED_TYPE:
    case TYPE_PARAMETER:
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
        idl_handle->declspec.type = find_type_or_error(NULL, "handle_t");
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

    type_interface_define(async_iface, map_attrs(iface->attrs, async_iface_attrs), inherit, stmts, NULL);
    iface->details.iface->async_iface = async_iface->details.iface->async_iface = async_iface;
}

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts)
{
    statement_t *stmt, *next;

    if (stmts && parameterized_type_stmts) LIST_FOR_EACH_ENTRY_SAFE(stmt, next, parameterized_type_stmts, statement_t, entry)
    {
        switch(stmt->type)
        {
        case STMT_TYPE:
            stmt->u.type = type_parameterized_type_specialize_define(stmt->u.type);
            stmt->declonly = FALSE;
            list_remove(&stmt->entry);
            stmts = append_statement(stmts, stmt);
            break;
        default:
            assert(0); /* should not be there */
            break;
        }
    }

    return stmts;
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

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    stmt->declonly = declonly;

    LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
    {
        var_t *var = decl->var;
        type_t *type = find_type_or_error(current_namespace, var->name);
        stmt->u.type_list = append_typeref(stmt->u.type_list, make_typeref(type));
        free(decl);
        free(var);
    }

    return stmt;
}

static statement_t *make_statement_parameterized_type(type_t *type, typeref_list_t *params)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type = type_parameterized_type_specialize_partial(type, params);
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

type_t *find_parameterized_type(type_t *type, typeref_list_t *params)
{
    char *name = format_parameterized_type_name(type, params);

    if (parameters_namespace)
    {
        assert(type->type_type == TYPE_PARAMETERIZED_TYPE);
        type = type_parameterized_type_specialize_partial(type, params);
    }
    else if ((type = find_type(name, type->namespace, 0)))
        assert(type->type_type != TYPE_PARAMETERIZED_TYPE);
    else
        error_loc("parameterized type '%s' not declared\n", name);

    free(name);
    return type;
}
