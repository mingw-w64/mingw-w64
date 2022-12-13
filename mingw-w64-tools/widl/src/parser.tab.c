/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PARSER_STYPE
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
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_custom_attr(struct uuid *id, expr_t *pval);
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

static void push_namespaces(str_list_t *names);
static void pop_namespaces(str_list_t *names);
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
static statement_t *make_statement_delegate(type_t *ret, var_list_t *args);
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
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    PARSER_EMPTY = -2,
    PARSER_EOF = 0,                /* "end of file"  */
    PARSER_error = 256,            /* error  */
    PARSER_UNDEF = 257,            /* "invalid token"  */
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
    tDELEGATE = 317,               /* tDELEGATE  */
    tDEFAULTCOLLELEM = 318,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 319,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 320,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 321, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 322,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 323,          /* tDISPINTERFACE  */
    tDLLNAME = 324,                /* tDLLNAME  */
    tDONTFREE = 325,               /* tDONTFREE  */
    tDOUBLE = 326,                 /* tDOUBLE  */
    tDUAL = 327,                   /* tDUAL  */
    tENABLEALLOCATE = 328,         /* tENABLEALLOCATE  */
    tENCODE = 329,                 /* tENCODE  */
    tENDPOINT = 330,               /* tENDPOINT  */
    tENTRY = 331,                  /* tENTRY  */
    tENUM = 332,                   /* tENUM  */
    tERRORSTATUST = 333,           /* tERRORSTATUST  */
    tEVENTADD = 334,               /* tEVENTADD  */
    tEVENTREMOVE = 335,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 336,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 337,         /* tEXPLICITHANDLE  */
    tEXTERN = 338,                 /* tEXTERN  */
    tFALSE = 339,                  /* tFALSE  */
    tFASTCALL = 340,               /* tFASTCALL  */
    tFAULTSTATUS = 341,            /* tFAULTSTATUS  */
    tFLAGS = 342,                  /* tFLAGS  */
    tFLOAT = 343,                  /* tFLOAT  */
    tFORCEALLOCATE = 344,          /* tFORCEALLOCATE  */
    tHANDLE = 345,                 /* tHANDLE  */
    tHANDLET = 346,                /* tHANDLET  */
    tHELPCONTEXT = 347,            /* tHELPCONTEXT  */
    tHELPFILE = 348,               /* tHELPFILE  */
    tHELPSTRING = 349,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 350,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 351,          /* tHELPSTRINGDLL  */
    tHIDDEN = 352,                 /* tHIDDEN  */
    tHYPER = 353,                  /* tHYPER  */
    tID = 354,                     /* tID  */
    tIDEMPOTENT = 355,             /* tIDEMPOTENT  */
    tIGNORE = 356,                 /* tIGNORE  */
    tIIDIS = 357,                  /* tIIDIS  */
    tIMMEDIATEBIND = 358,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 359,         /* tIMPLICITHANDLE  */
    tIMPORT = 360,                 /* tIMPORT  */
    tIMPORTLIB = 361,              /* tIMPORTLIB  */
    tIN = 362,                     /* tIN  */
    tIN_LINE = 363,                /* tIN_LINE  */
    tINLINE = 364,                 /* tINLINE  */
    tINPUTSYNC = 365,              /* tINPUTSYNC  */
    tINT = 366,                    /* tINT  */
    tINT32 = 367,                  /* tINT32  */
    tINT3264 = 368,                /* tINT3264  */
    tINT64 = 369,                  /* tINT64  */
    tINTERFACE = 370,              /* tINTERFACE  */
    tLCID = 371,                   /* tLCID  */
    tLENGTHIS = 372,               /* tLENGTHIS  */
    tLIBRARY = 373,                /* tLIBRARY  */
    tLICENSED = 374,               /* tLICENSED  */
    tLOCAL = 375,                  /* tLOCAL  */
    tLONG = 376,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 377,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 378,                  /* tMAYBE  */
    tMESSAGE = 379,                /* tMESSAGE  */
    tMETHODS = 380,                /* tMETHODS  */
    tMODULE = 381,                 /* tMODULE  */
    tMTA = 382,                    /* tMTA  */
    tNAMESPACE = 383,              /* tNAMESPACE  */
    tNOCODE = 384,                 /* tNOCODE  */
    tNONBROWSABLE = 385,           /* tNONBROWSABLE  */
    tNONCREATABLE = 386,           /* tNONCREATABLE  */
    tNONE = 387,                   /* tNONE  */
    tNONEXTENSIBLE = 388,          /* tNONEXTENSIBLE  */
    tNOTIFY = 389,                 /* tNOTIFY  */
    tNOTIFYFLAG = 390,             /* tNOTIFYFLAG  */
    tNULL = 391,                   /* tNULL  */
    tOBJECT = 392,                 /* tOBJECT  */
    tODL = 393,                    /* tODL  */
    tOLEAUTOMATION = 394,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 395,               /* tOPTIMIZE  */
    tOPTIONAL = 396,               /* tOPTIONAL  */
    tOUT = 397,                    /* tOUT  */
    tOVERLOAD = 398,               /* tOVERLOAD  */
    tPARTIALIGNORE = 399,          /* tPARTIALIGNORE  */
    tPASCAL = 400,                 /* tPASCAL  */
    tPOINTERDEFAULT = 401,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 402,         /* tPRAGMA_WARNING  */
    tPROGID = 403,                 /* tPROGID  */
    tPROPERTIES = 404,             /* tPROPERTIES  */
    tPROPGET = 405,                /* tPROPGET  */
    tPROPPUT = 406,                /* tPROPPUT  */
    tPROPPUTREF = 407,             /* tPROPPUTREF  */
    tPROXY = 408,                  /* tPROXY  */
    tPTR = 409,                    /* tPTR  */
    tPUBLIC = 410,                 /* tPUBLIC  */
    tRANGE = 411,                  /* tRANGE  */
    tREADONLY = 412,               /* tREADONLY  */
    tREF = 413,                    /* tREF  */
    tREGISTER = 414,               /* tREGISTER  */
    tREPRESENTAS = 415,            /* tREPRESENTAS  */
    tREQUESTEDIT = 416,            /* tREQUESTEDIT  */
    tREQUIRES = 417,               /* tREQUIRES  */
    tRESTRICTED = 418,             /* tRESTRICTED  */
    tRETVAL = 419,                 /* tRETVAL  */
    tRUNTIMECLASS = 420,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 421,              /* tSAFEARRAY  */
    tSHORT = 422,                  /* tSHORT  */
    tSIGNED = 423,                 /* tSIGNED  */
    tSINGLENODE = 424,             /* tSINGLENODE  */
    tSIZEIS = 425,                 /* tSIZEIS  */
    tSIZEOF = 426,                 /* tSIZEOF  */
    tSMALL = 427,                  /* tSMALL  */
    tSOURCE = 428,                 /* tSOURCE  */
    tSTANDARD = 429,               /* tSTANDARD  */
    tSTATIC = 430,                 /* tSTATIC  */
    tSTDCALL = 431,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 432,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 433,                 /* tSTRING  */
    tSTRUCT = 434,                 /* tSTRUCT  */
    tSWITCH = 435,                 /* tSWITCH  */
    tSWITCHIS = 436,               /* tSWITCHIS  */
    tSWITCHTYPE = 437,             /* tSWITCHTYPE  */
    tTHREADING = 438,              /* tTHREADING  */
    tTRANSMITAS = 439,             /* tTRANSMITAS  */
    tTRUE = 440,                   /* tTRUE  */
    tTYPEDEF = 441,                /* tTYPEDEF  */
    tUIDEFAULT = 442,              /* tUIDEFAULT  */
    tUNION = 443,                  /* tUNION  */
    tUNIQUE = 444,                 /* tUNIQUE  */
    tUNSIGNED = 445,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 446,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 447,            /* tUSERMARSHAL  */
    tUUID = 448,                   /* tUUID  */
    tV1ENUM = 449,                 /* tV1ENUM  */
    tVARARG = 450,                 /* tVARARG  */
    tVERSION = 451,                /* tVERSION  */
    tVIPROGID = 452,               /* tVIPROGID  */
    tVOID = 453,                   /* tVOID  */
    tWCHAR = 454,                  /* tWCHAR  */
    tWIREMARSHAL = 455,            /* tWIREMARSHAL  */
    tAPARTMENT = 456,              /* tAPARTMENT  */
    tNEUTRAL = 457,                /* tNEUTRAL  */
    tSINGLE = 458,                 /* tSINGLE  */
    tFREE = 459,                   /* tFREE  */
    tBOTH = 460,                   /* tBOTH  */
    CAST = 461,                    /* CAST  */
    PPTR = 462,                    /* PPTR  */
    POS = 463,                     /* POS  */
    NEG = 464,                     /* NEG  */
    ADDRESSOF = 465                /* ADDRESSOF  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 126 "tools/widl/parser.y"

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
	struct uuid *uuid;
	unsigned int num;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;
	struct namespace *namespace;

#line 497 "tools/widl/parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif


extern PARSER_STYPE parser_lval;


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
  YYSYMBOL_tDELEGATE = 62,                 /* tDELEGATE  */
  YYSYMBOL_tDEFAULTCOLLELEM = 63,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 64,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 65,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 66,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 67,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 68,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 69,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 70,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 71,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 72,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 73,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 74,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 75,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 76,                    /* tENTRY  */
  YYSYMBOL_tENUM = 77,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 78,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 79,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 80,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 81,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 82,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 83,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 84,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 85,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 86,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 87,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 88,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 89,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 90,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 91,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 92,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 93,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 94,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 95,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 96,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 97,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 98,                    /* tHYPER  */
  YYSYMBOL_tID = 99,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 100,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 101,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 102,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 103,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 104,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 105,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 106,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 107,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 108,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 109,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 110,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 111,                     /* tINT  */
  YYSYMBOL_tINT32 = 112,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 113,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 114,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 115,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 116,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 117,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 118,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 119,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 120,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 121,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 122,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 123,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 124,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 125,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 126,                  /* tMODULE  */
  YYSYMBOL_tMTA = 127,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 128,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 129,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 130,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 131,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 132,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 133,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 134,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 135,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 136,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 137,                  /* tOBJECT  */
  YYSYMBOL_tODL = 138,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 139,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 140,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 141,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 142,                     /* tOUT  */
  YYSYMBOL_tOVERLOAD = 143,                /* tOVERLOAD  */
  YYSYMBOL_tPARTIALIGNORE = 144,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 145,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 146,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 147,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 148,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 149,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 150,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 151,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 152,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 153,                   /* tPROXY  */
  YYSYMBOL_tPTR = 154,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 155,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 156,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 157,                /* tREADONLY  */
  YYSYMBOL_tREF = 158,                     /* tREF  */
  YYSYMBOL_tREGISTER = 159,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 160,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 161,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 162,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 163,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 164,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 165,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 166,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 167,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 168,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 169,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 170,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 171,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 172,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 173,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 174,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 175,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 176,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 177,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 178,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 179,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 180,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 181,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 182,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 183,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 184,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 185,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 186,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 187,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 188,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 189,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 190,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 191,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 192,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 193,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 194,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 195,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 196,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 197,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 198,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 199,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 200,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 201,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 202,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 203,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 204,                    /* tFREE  */
  YYSYMBOL_tBOTH = 205,                    /* tBOTH  */
  YYSYMBOL_206_ = 206,                     /* ','  */
  YYSYMBOL_207_ = 207,                     /* '?'  */
  YYSYMBOL_208_ = 208,                     /* ':'  */
  YYSYMBOL_209_ = 209,                     /* '|'  */
  YYSYMBOL_210_ = 210,                     /* '^'  */
  YYSYMBOL_211_ = 211,                     /* '&'  */
  YYSYMBOL_212_ = 212,                     /* '<'  */
  YYSYMBOL_213_ = 213,                     /* '>'  */
  YYSYMBOL_214_ = 214,                     /* '-'  */
  YYSYMBOL_215_ = 215,                     /* '+'  */
  YYSYMBOL_216_ = 216,                     /* '*'  */
  YYSYMBOL_217_ = 217,                     /* '/'  */
  YYSYMBOL_218_ = 218,                     /* '%'  */
  YYSYMBOL_219_ = 219,                     /* '!'  */
  YYSYMBOL_220_ = 220,                     /* '~'  */
  YYSYMBOL_CAST = 221,                     /* CAST  */
  YYSYMBOL_PPTR = 222,                     /* PPTR  */
  YYSYMBOL_POS = 223,                      /* POS  */
  YYSYMBOL_NEG = 224,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 225,                /* ADDRESSOF  */
  YYSYMBOL_226_ = 226,                     /* '.'  */
  YYSYMBOL_227_ = 227,                     /* '['  */
  YYSYMBOL_228_ = 228,                     /* ']'  */
  YYSYMBOL_229_ = 229,                     /* ';'  */
  YYSYMBOL_230_ = 230,                     /* '{'  */
  YYSYMBOL_231_ = 231,                     /* '}'  */
  YYSYMBOL_232_ = 232,                     /* '('  */
  YYSYMBOL_233_ = 233,                     /* ')'  */
  YYSYMBOL_234_ = 234,                     /* '='  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_input = 236,                    /* input  */
  YYSYMBOL_m_acf = 237,                    /* m_acf  */
  YYSYMBOL_decl_statements = 238,          /* decl_statements  */
  YYSYMBOL_decl_block = 239,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 240,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 241,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 242,           /* gbl_statements  */
  YYSYMBOL_243_1 = 243,                    /* $@1  */
  YYSYMBOL_imp_statements = 244,           /* imp_statements  */
  YYSYMBOL_245_2 = 245,                    /* $@2  */
  YYSYMBOL_int_statements = 246,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 247,            /* semicolon_opt  */
  YYSYMBOL_statement = 248,                /* statement  */
  YYSYMBOL_pragma_warning = 249,           /* pragma_warning  */
  YYSYMBOL_warnings = 250,                 /* warnings  */
  YYSYMBOL_typedecl = 251,                 /* typedecl  */
  YYSYMBOL_cppquote = 252,                 /* cppquote  */
  YYSYMBOL_import_start = 253,             /* import_start  */
  YYSYMBOL_import = 254,                   /* import  */
  YYSYMBOL_importlib = 255,                /* importlib  */
  YYSYMBOL_libraryhdr = 256,               /* libraryhdr  */
  YYSYMBOL_library_start = 257,            /* library_start  */
  YYSYMBOL_librarydef = 258,               /* librarydef  */
  YYSYMBOL_m_args = 259,                   /* m_args  */
  YYSYMBOL_arg_list = 260,                 /* arg_list  */
  YYSYMBOL_args = 261,                     /* args  */
  YYSYMBOL_arg = 262,                      /* arg  */
  YYSYMBOL_array = 263,                    /* array  */
  YYSYMBOL_m_attributes = 264,             /* m_attributes  */
  YYSYMBOL_attributes = 265,               /* attributes  */
  YYSYMBOL_attrib_list = 266,              /* attrib_list  */
  YYSYMBOL_str_list = 267,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 268,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 269,             /* contract_ver  */
  YYSYMBOL_contract_req = 270,             /* contract_req  */
  YYSYMBOL_static_attr = 271,              /* static_attr  */
  YYSYMBOL_activatable_attr = 272,         /* activatable_attr  */
  YYSYMBOL_attribute = 273,                /* attribute  */
  YYSYMBOL_uuid_string = 274,              /* uuid_string  */
  YYSYMBOL_callconv = 275,                 /* callconv  */
  YYSYMBOL_cases = 276,                    /* cases  */
  YYSYMBOL_case = 277,                     /* case  */
  YYSYMBOL_enums = 278,                    /* enums  */
  YYSYMBOL_enum_list = 279,                /* enum_list  */
  YYSYMBOL_enum_member = 280,              /* enum_member  */
  YYSYMBOL_enum = 281,                     /* enum  */
  YYSYMBOL_enumdef = 282,                  /* enumdef  */
  YYSYMBOL_m_exprs = 283,                  /* m_exprs  */
  YYSYMBOL_m_expr = 284,                   /* m_expr  */
  YYSYMBOL_expr = 285,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 286,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 287,           /* expr_int_const  */
  YYSYMBOL_expr_const = 288,               /* expr_const  */
  YYSYMBOL_fields = 289,                   /* fields  */
  YYSYMBOL_field = 290,                    /* field  */
  YYSYMBOL_ne_union_field = 291,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 292,          /* ne_union_fields  */
  YYSYMBOL_union_field = 293,              /* union_field  */
  YYSYMBOL_s_field = 294,                  /* s_field  */
  YYSYMBOL_funcdef = 295,                  /* funcdef  */
  YYSYMBOL_declaration = 296,              /* declaration  */
  YYSYMBOL_m_ident = 297,                  /* m_ident  */
  YYSYMBOL_m_typename = 298,               /* m_typename  */
  YYSYMBOL_typename = 299,                 /* typename  */
  YYSYMBOL_ident = 300,                    /* ident  */
  YYSYMBOL_base_type = 301,                /* base_type  */
  YYSYMBOL_m_int = 302,                    /* m_int  */
  YYSYMBOL_int_std = 303,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 304,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 305,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 306,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 307,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 308,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 309,                  /* coclass  */
  YYSYMBOL_coclassdef = 310,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 311,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 312,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 313,              /* apicontract  */
  YYSYMBOL_apicontract_def = 314,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 315,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 316,         /* class_interfaces  */
  YYSYMBOL_class_interface = 317,          /* class_interface  */
  YYSYMBOL_dispinterface = 318,            /* dispinterface  */
  YYSYMBOL_dispattributes = 319,           /* dispattributes  */
  YYSYMBOL_dispint_props = 320,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 321,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 322,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 323,                  /* inherit  */
  YYSYMBOL_type_parameter = 324,           /* type_parameter  */
  YYSYMBOL_type_parameters = 325,          /* type_parameters  */
  YYSYMBOL_interface = 326,                /* interface  */
  YYSYMBOL_327_3 = 327,                    /* $@3  */
  YYSYMBOL_328_4 = 328,                    /* $@4  */
  YYSYMBOL_delegatedef = 329,              /* delegatedef  */
  YYSYMBOL_330_5 = 330,                    /* $@5  */
  YYSYMBOL_331_6 = 331,                    /* $@6  */
  YYSYMBOL_required_types = 332,           /* required_types  */
  YYSYMBOL_requires = 333,                 /* requires  */
  YYSYMBOL_interfacedef = 334,             /* interfacedef  */
  YYSYMBOL_335_7 = 335,                    /* $@7  */
  YYSYMBOL_interfaceref = 336,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 337,         /* dispinterfaceref  */
  YYSYMBOL_module = 338,                   /* module  */
  YYSYMBOL_moduledef = 339,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 340,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 341,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 342,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 343,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 344,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 345,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 346,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 347,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 348,               /* declarator  */
  YYSYMBOL_direct_declarator = 349,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 350,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 351, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 352,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 353, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 354,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 355, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 356,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 357,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 358,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 359,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 360,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 361,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 362,          /* init_declarator  */
  YYSYMBOL_threading_type = 363,           /* threading_type  */
  YYSYMBOL_pointer_type = 364,             /* pointer_type  */
  YYSYMBOL_structdef = 365,                /* structdef  */
  YYSYMBOL_unqualified_type = 366,         /* unqualified_type  */
  YYSYMBOL_type = 367,                     /* type  */
  YYSYMBOL_typedef = 368,                  /* typedef  */
  YYSYMBOL_uniondef = 369,                 /* uniondef  */
  YYSYMBOL_version = 370,                  /* version  */
  YYSYMBOL_acf_statements = 371,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 372,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 373,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 374,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 375,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 376,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 377,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 378,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 379           /* allocate_option  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
         || (defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

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
#define YYLAST   3854

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  145
/* YYNRULES -- Number of rules.  */
#define YYNRULES  494
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  904

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   465


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
       2,     2,     2,   219,     2,     2,     2,   218,   211,     2,
     232,   233,   216,   215,   206,   214,   226,   217,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   208,   229,
     212,   234,   213,   207,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   227,     2,   228,   210,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   230,   209,   231,   220,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   221,   222,   223,   224,   225
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   354,   354,   369,   369,   371,   372,   378,   380,   381,
     385,   387,   388,   388,   390,   391,   392,   393,   394,   397,
     400,   401,   403,   404,   406,   407,   408,   409,   412,   413,
     414,   415,   415,   417,   418,   419,   420,   423,   424,   426,
     427,   429,   430,   431,   432,   433,   436,   437,   440,   441,
     445,   446,   447,   448,   449,   450,   451,   454,   462,   470,
     471,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     486,   488,   495,   501,   505,   507,   511,   515,   516,   519,
     520,   523,   524,   528,   533,   540,   544,   545,   548,   549,
     553,   556,   557,   558,   561,   562,   566,   567,   568,   572,
     573,   576,   582,   588,   592,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   714,   715,   720,   721,
     722,   723,   726,   727,   730,   734,   740,   741,   742,   745,
     749,   761,   766,   770,   775,   778,   779,   782,   783,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   825,   827,   828,
     831,   832,   835,   841,   847,   848,   851,   856,   863,   864,
     867,   868,   872,   873,   876,   880,   886,   894,   898,   903,
     904,   907,   908,   911,   912,   915,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   931,   932,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   947,   948,
     952,   953,   956,   961,   962,   963,   964,   965,   969,   970,
     974,   977,   981,   984,   988,   991,   995,   996,   999,  1000,
    1004,  1005,  1008,  1011,  1014,  1015,  1018,  1019,  1023,  1025,
    1029,  1030,  1031,  1034,  1038,  1039,  1043,  1044,  1044,  1044,
    1048,  1053,  1054,  1052,  1061,  1062,  1063,  1064,  1066,  1067,
    1070,  1070,  1083,  1087,  1088,  1089,  1093,  1096,  1099,  1104,
    1105,  1106,  1110,  1114,  1117,  1118,  1121,  1122,  1126,  1128,
    1132,  1133,  1137,  1138,  1139,  1143,  1145,  1146,  1150,  1151,
    1152,  1153,  1158,  1160,  1161,  1166,  1168,  1172,  1173,  1178,
    1179,  1180,  1181,  1185,  1193,  1195,  1196,  1201,  1203,  1207,
    1208,  1215,  1216,  1217,  1218,  1219,  1223,  1230,  1231,  1234,
    1235,  1238,  1245,  1246,  1251,  1252,  1256,  1257,  1258,  1259,
    1260,  1261,  1265,  1266,  1267,  1270,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,  1287,  1288,  1289,  1292,
    1299,  1301,  1307,  1308,  1309,  1313,  1314,  1318,  1319,  1323,
    1330,  1339,  1340,  1344,  1345,  1349,  1351,  1352,  1353,  1357,
    1358,  1363,  1364,  1365,  1366
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
  "tDECLARE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDELEGATE",
  "tDEFAULTCOLLELEM", "tDEFAULTVALUE", "tDEFAULTVTABLE",
  "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME",
  "tDONTFREE", "tDOUBLE", "tDUAL", "tENABLEALLOCATE", "tENCODE",
  "tENDPOINT", "tENTRY", "tENUM", "tERRORSTATUST", "tEVENTADD",
  "tEVENTREMOVE", "tEXCLUSIVETO", "tEXPLICITHANDLE", "tEXTERN", "tFALSE",
  "tFASTCALL", "tFAULTSTATUS", "tFLAGS", "tFLOAT", "tFORCEALLOCATE",
  "tHANDLE", "tHANDLET", "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING",
  "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID",
  "tIDEMPOTENT", "tIGNORE", "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE",
  "tIMPORT", "tIMPORTLIB", "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC",
  "tINT", "tINT32", "tINT3264", "tINT64", "tINTERFACE", "tLCID",
  "tLENGTHIS", "tLIBRARY", "tLICENSED", "tLOCAL", "tLONG",
  "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT",
  "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tOVERLOAD",
  "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT", "tPRAGMA_WARNING",
  "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF",
  "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER",
  "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES", "tRESTRICTED", "tRETVAL",
  "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT", "tSIGNED", "tSINGLENODE",
  "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTANDARD", "tSTATIC",
  "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT", "tSWITCH",
  "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS", "tTRUE",
  "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
  "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG",
  "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT",
  "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'", "'['", "']'",
  "';'", "'{'", "'}'", "'('", "')'", "'='", "$accept", "input", "m_acf",
  "decl_statements", "decl_block", "imp_decl_statements", "imp_decl_block",
  "gbl_statements", "$@1", "imp_statements", "$@2", "int_statements",
  "semicolon_opt", "statement", "pragma_warning", "warnings", "typedecl",
  "cppquote", "import_start", "import", "importlib", "libraryhdr",
  "library_start", "librarydef", "m_args", "arg_list", "args", "arg",
  "array", "m_attributes", "attributes", "attrib_list", "str_list",
  "marshaling_behavior", "contract_ver", "contract_req", "static_attr",
  "activatable_attr", "attribute", "uuid_string", "callconv", "cases",
  "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
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
  "interface", "$@3", "$@4", "delegatedef", "$@5", "$@6", "required_types",
  "requires", "interfacedef", "$@7", "interfaceref", "dispinterfaceref",
  "module", "moduledef", "storage_cls_spec", "function_specifier",
  "type_qualifier", "m_type_qual_list", "decl_spec",
  "unqualified_decl_spec", "m_decl_spec_no_type", "decl_spec_no_type",
  "declarator", "direct_declarator", "abstract_declarator",
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

#define YYPACT_NINF (-653)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-482)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -653,   178,  1906,  -653,   -14,  -653,   -28,   -33,   116,  -653,
    -653,  -653,   116,  -653,   -11,     2,   116,  -653,   154,  -653,
    -653,  -653,  -653,   131,   248,  -653,  -653,  -653,  -653,  -653,
     116,   131,   281,    55,  -653,   116,    61,   131,   394,  -653,
    -653,   180,   257,   394,  -653,  -653,  3654,  -653,  -653,  -653,
    -653,   105,  -653,  -653,  -653,  -653,  -653,    22,  2988,   112,
     129,  -653,  -653,  -653,   319,   133,  -653,   136,  -653,   138,
    -653,   145,  -653,  -122,   147,   228,   148,   149,  -653,  -653,
    -653,    54,    54,    54,   253,  3244,   150,  -653,    54,   151,
     159,  -653,    56,  -653,   -33,   251,  -653,  -653,  -653,  -653,
     381,  -653,  -653,   -61,   161,  -653,  -653,  -653,   163,   182,
    -653,  -653,    76,  -653,  3244,  -653,  -653,    84,   165,   -87,
     -91,  -653,   167,  -653,   171,  -653,  -653,   174,  -653,  -653,
    -653,   183,   184,  -653,  -653,  -653,  -653,  -653,   186,   187,
    -653,   192,  -653,  -653,  -653,  -653,   193,  -653,  -653,  -653,
     196,  -653,  -653,  -653,   201,   202,  -653,  -653,   208,  -653,
    -653,  -653,  -653,  -653,   209,   210,   213,   214,   215,  -653,
     218,  -653,  -653,   220,  -653,   224,  -653,  -653,   226,   229,
    -653,  -653,   231,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,   232,  -653,  -653,   234,  -653,   235,
     239,  -653,  -653,  -653,  -653,  -653,  -653,   242,  -653,  -653,
     243,  -653,  -653,  -653,   244,  -653,   245,  -653,  -653,   247,
     249,   252,   254,  -653,  -653,  -653,   255,   261,  -653,  -653,
     264,   265,   266,   -57,  -653,  -653,  -653,  2053,  1104,  3244,
     116,   195,   230,   328,   116,   339,   352,   279,   185,   280,
     283,   284,  -653,   253,   282,   287,  -653,   293,   309,  3347,
    -653,  -653,  -653,   521,  -653,  -653,   295,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   253,
     253,  -653,  -653,   292,  -110,  -653,  -653,  -653,    54,  -653,
    -653,  -653,   298,  -653,  -653,  -653,   -54,  -653,  -653,   522,
     310,   -40,   -41,  -653,  -653,   329,   337,   314,  -653,   327,
    -653,  3215,   559,   197,   116,   216,  3215,   563,   197,   216,
     564,   565,   216,  3215,   216,   571,   572,   216,   573,   216,
     216,  2559,   216,   216,    33,   576,   579,   -49,   580,   216,
    3244,   216,  3215,   216,  3244,   299,  3244,  3244,   197,   190,
     588,  3244,  3654,   345,  -653,   368,   367,  -653,  -653,  -653,
    -653,   371,  -653,   372,  -653,   373,  -653,   -12,   375,   376,
    -653,  -653,  -653,   148,   116,  -653,  3215,  -653,  -653,   377,
    -653,   377,   -84,  -653,  -653,  -653,   385,   410,  -653,  -653,
    -653,   319,    43,   403,  -653,   -99,  -653,  -653,   -18,   304,
     387,  -653,   216,   584,  2559,  -653,  -653,    74,    56,  -653,
     392,  -653,   356,  -653,   116,   395,   417,   391,  -653,   116,
     622,   622,  -653,    39,   195,    41,  -653,   396,   433,   397,
    -653,  -653,   407,   408,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,   411,  -653,   216,   216,   216,   216,   216,
     216,   885,  2772,  -107,  -653,   409,   439,   420,   415,   444,
    2772,   418,   421,  -653,   -88,   423,   425,   426,   427,   428,
     429,   430,   431,  1650,   432,  3215,   262,   434,   -82,  -653,
    2772,  -653,  -653,  -653,   436,   437,   442,   443,   446,   451,
     447,   -79,   448,   466,  2373,   449,  -653,  -653,  -653,  -653,
    -653,  -653,   450,   452,   453,   454,   458,  -653,   456,   457,
     460,  -653,  3654,  -653,   668,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -100,   253,  1533,    67,    68,   148,   356,   536,
    -653,  -653,  -653,  3347,  -653,  1396,   494,   -48,   476,  -653,
    -653,  -653,  -653,   905,  -653,  2669,   473,   501,  -653,  -653,
    -653,  -653,  -653,  -653,   -78,  -653,  -653,   524,   496,  -653,
    -653,   109,   216,  -653,  -653,   506,  -653,    44,    47,  -653,
    3215,  -653,  3215,   481,  -653,   486,  -653,   488,  -653,  3112,
    -653,  -653,  -653,  3392,    37,    37,    37,    37,    37,    37,
    -653,  2449,   241,  3495,    54,   216,   216,   715,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   716,   216,   216,  -653,  -653,
     563,   717,  -653,   216,  -653,  -653,   712,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   262,  -653,
    2185,  -653,   262,  -653,  -653,  -653,   -71,  -653,   216,  -653,
    -653,  -653,  -653,  -653,  -653,   216,  -653,  -653,  -653,  3215,
    -653,  -653,  -653,  -653,  -653,  -653,   718,  -653,  -653,  -653,
    -653,   -39,   489,  -653,  -653,  2559,  -653,   520,   148,  -653,
     541,  3215,   148,    32,  -653,   148,  -653,   133,  -653,   356,
     498,  -653,  -653,  -653,   523,   500,  1760,   499,  -653,  -653,
    -653,  2456,    74,  -653,   505,   502,   524,  3347,  -653,  -653,
     116,   525,  -653,  -653,  -653,   262,   510,   253,    42,   116,
    -653,  -653,  -653,  -653,   241,  -653,  -653,  2332,  -653,   241,
    -653,   507,   -50,    54,  -653,   155,   155,  -653,  1168,  1168,
     618,   618,  2099,   732,  2744,  2790,  2270,   593,   618,   618,
     194,   194,    37,    37,    37,  -653,  2691,  -653,  -653,   508,
    -653,  -653,    85,  -653,   509,   262,   511,  -653,  2559,  -653,
    -653,   512,  -653,  -653,   356,  -653,   148,  1250,   116,   527,
     253,  -653,  -653,   116,   356,   529,   532,  -653,   133,  -653,
     528,  -653,  -653,  -653,  -653,  3215,   533,  -653,  -653,  -653,
    -653,  -653,   730,  -653,  -653,   -93,  -653,  -653,   555,  -653,
     -96,  -653,  -653,   534,  -653,   535,   652,  -653,   537,   262,
     538,  -653,   216,  2559,  -653,  -653,   216,  -653,  -653,  -653,
      85,  -653,  -653,  -653,   540,  -653,   567,  -653,  -653,   -90,
     148,  -653,  -653,   547,   319,  -653,  -653,  -653,   356,  1657,
    -653,   551,   552,   216,  -653,   262,  -653,  -653,  -653,  -653,
      85,  -653,  -653,  -653,    37,   549,  2772,  -653,  -653,  3347,
     553,  -653,   554,   133,  -653,   148,  -653,  -653,  -653,  -653,
      38,  -653,  -653,   -53,  2559,  -653,   216,   578,  -653,  -653,
     558,   556,   582,   135,  -653,  -653,   135,  -653,  -653,   585,
     148,  -653,  -653,  -653
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   303,    55,   465,   475,     0,   314,
     306,   325,     0,   393,     0,     0,     0,   313,   301,   315,
     389,   312,   316,   317,     0,   392,   319,   326,   327,   324,
       0,   317,     0,     0,   391,     0,     0,   317,     0,   321,
     390,   301,   301,   311,   456,   307,   105,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   458,
       0,   330,   457,   308,     0,     0,   468,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   400,   400,   400,     0,     0,   460,   466,   400,     0,
     462,   328,     0,     4,   475,     0,   303,   304,   344,   340,
       0,     5,   352,   459,     0,   302,   318,   323,     0,   366,
     322,   346,     0,   342,     0,   320,   309,   461,     0,   463,
       0,   310,     0,   107,     0,   109,   110,     0,   111,   112,
     113,     0,     0,   116,   117,   118,   119,   120,     0,     0,
     123,     0,   125,   126,   127,   128,     0,   130,   131,   132,
       0,   134,   135,   136,     0,     0,   139,   140,     0,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,   152,
       0,   154,   155,     0,   157,     0,   159,   160,   163,     0,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   179,   180,     0,   182,     0,
       0,   185,   186,   187,   188,   454,   189,     0,   191,   452,
       0,   193,   194,   195,     0,   197,     0,   199,   200,     0,
       0,     0,     0,   205,   453,   206,     0,     0,   210,   211,
       0,     0,     0,     0,    91,   215,    51,    88,    88,     0,
       0,    88,     0,   301,     0,   301,   301,     0,   458,     0,
       0,     0,   380,     0,   460,   462,    52,   303,   467,     0,
      18,    22,    20,     0,    12,    15,     0,    49,   382,    14,
     404,   401,   403,   402,   218,   219,   220,   221,   394,     0,
       0,   305,   408,   444,   407,   298,   458,   460,   400,   462,
     396,    54,     0,   487,   486,   488,     0,   483,   476,     0,
       0,     0,    88,    71,   367,     0,     0,     0,   284,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,    90,    72,     0,     0,    45,    42,    43,
      44,     0,    36,     0,    40,     0,    38,     0,     0,     0,
      34,    33,    41,    48,     0,   387,     0,    89,    46,   459,
      74,   461,   463,    75,   348,   348,     0,   360,   297,   329,
     333,     0,   334,   336,   338,     0,   347,    11,     0,     0,
       0,   406,     0,     0,    77,   410,   397,     0,     0,   482,
       0,    70,     0,     7,     0,     0,   228,   233,   229,     0,
       0,     0,   464,    88,    88,    88,   104,     0,     0,     0,
     217,   216,     0,     0,   248,   239,   240,   241,   245,   246,
     247,   242,   243,     0,   244,     0,     0,     0,     0,     0,
       0,     0,   282,     0,   280,     0,     0,    99,     0,     0,
     283,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,   235,
     238,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,   446,   447,   448,
     449,   450,     0,     0,     0,     0,   472,   474,     0,     0,
       0,    92,   105,     8,     0,    35,    39,    37,    31,    30,
      29,    76,     0,     0,    88,    88,    88,    48,     0,   378,
     331,   335,   337,     0,   332,    88,     0,    88,     0,   395,
     405,   409,   445,     0,    87,     0,     0,    81,    78,    79,
     493,   491,   494,   492,     0,   489,   484,   477,     0,   231,
     234,    88,     0,   363,   364,   368,    59,     0,     0,   455,
       0,   285,     0,     0,   470,    89,   291,     0,   106,     0,
     108,   209,   114,     0,   272,   271,   270,   273,   268,   269,
     465,     0,   417,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   121,
       0,     0,   122,     0,   129,   133,     0,   137,   138,   141,
     147,   148,   149,   150,   151,   153,   156,   158,   429,   394,
      77,   434,   429,   431,   430,    84,   426,   162,   237,   161,
     166,   178,   181,   183,   184,     0,   192,   196,   198,     0,
     201,   202,   204,   203,   207,   208,     0,   212,   213,   214,
      93,     0,     0,    28,   371,    77,   437,   469,    48,    47,
       0,    89,    48,     0,   349,    48,   345,   361,   362,     0,
       0,   339,    13,   354,     0,     0,     0,     0,    86,    85,
     411,     0,     0,   485,   481,     0,   477,     0,   230,   232,
       0,     0,    60,    57,    58,     0,   462,     0,   460,   299,
     289,   288,   101,   103,   417,   279,   394,    77,   421,   417,
     418,     0,   414,   400,   398,   261,   262,   274,   255,   256,
     259,   260,   250,   251,     0,   252,   253,   254,   258,   257,
     264,   263,   266,   267,   265,   275,     0,   281,   100,     0,
      95,    83,   429,   394,     0,   429,     0,   425,    77,   433,
     236,     0,   102,   473,     0,    10,    48,    88,     0,     0,
       0,   388,   341,     0,     0,     0,     0,   343,   374,   375,
     379,    46,   356,   355,   358,     0,     0,   296,   359,    82,
      80,   490,     0,   480,   478,     0,   365,   369,   439,   442,
       0,   287,   294,     0,   300,     0,   417,   394,     0,   429,
       0,   413,     0,    77,   420,   399,     0,   278,   124,   424,
     429,   435,   428,   432,     0,   190,     0,    73,    32,     0,
      48,   438,   386,   330,     0,   385,   350,   351,     0,    88,
     357,     0,     0,     0,   441,     0,   286,   222,   277,   412,
     429,   422,   416,   419,   276,     0,   249,   427,   436,     0,
       0,   370,   331,   376,   377,    48,   479,     6,   440,   443,
       0,   415,   423,     0,    77,   381,     0,     0,   471,   223,
       0,     0,     0,    88,     9,   372,    88,   293,   225,     0,
      48,   224,   292,   373
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -653,  -653,  -653,  -653,  -653,  -653,  -653,   399,  -653,   -52,
    -653,     1,  -322,    -1,  -653,   380,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,    20,  -592,  -653,  -653,  -292,  -241,  -222,
      -2,  -653,  -653,  -653,   477,  -259,  -653,  -653,  -284,  -207,
     -80,  -653,  -653,  -653,  -653,  -653,   256,    16,   474,   170,
     424,  -653,  -280,  -277,  -653,  -653,  -653,  -653,   -74,  -333,
    -653,   134,  -653,    45,    -6,   -64,  -254,   127,   137,  -217,
    -245,  -252,   290,  -652,     9,    21,    13,    23,    15,    28,
      29,   440,  -653,    19,  -653,  -653,  -653,  -653,  -653,   119,
      53,     6,  -653,  -653,    30,  -653,  -653,  -653,  -653,    35,
    -653,  -653,  -653,  -653,    36,  -653,  -653,  -365,  -576,     7,
     258,   -42,   -55,  -218,  -653,  -653,  -653,  -623,  -653,  -645,
    -653,  -476,  -653,  -653,  -653,   -16,  -653,   587,  -653,   513,
      11,  -395,   -19,  -653,    14,  -653,   743,   140,  -653,  -653,
     139,  -653,   445,  -653,   153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    47,   301,    48,   671,   357,     2,   397,   237,
     673,   524,   268,   358,    50,   567,    51,    52,    53,    54,
     359,   247,    55,   360,   546,   547,   548,   549,   641,    57,
     377,   233,   464,   484,   722,   426,   492,   427,   234,   432,
     642,   880,   889,   415,   416,   417,   418,   286,   478,   479,
     452,   453,   454,   461,   423,   571,   576,   425,   898,   899,
     796,    60,   813,   104,    61,   643,    62,   107,    63,    64,
      65,    66,   394,   395,   361,   362,   363,   364,   365,   366,
     367,   525,   684,   368,    75,   537,   696,    76,   529,   564,
     565,   369,   419,   711,   370,   778,   900,   790,   690,   371,
     387,   785,   786,   242,   372,    81,    82,    83,   399,   476,
     592,   270,    85,   283,   284,   730,   820,   731,   732,   644,
     766,   645,   646,   677,   854,   809,   810,   285,   502,   235,
     287,    87,    88,    89,   289,   508,    93,   705,   706,    94,
      95,   296,   297,   554,   555
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    49,    98,   238,   280,   390,    99,   393,    77,    84,
     102,    67,   105,    86,   392,    69,    90,    71,    59,   376,
     282,    74,    56,    68,   109,    70,   271,   271,   271,   113,
      72,    73,    78,   271,   539,   105,   105,    79,    80,   474,
     272,   273,   391,   405,   467,   465,   290,   470,   764,   472,
     712,   521,   477,   712,   597,   805,   594,   455,   258,   489,
     481,   400,   401,   762,   252,   253,   288,   249,   511,   254,
     808,   250,   255,   251,   248,   412,   774,   694,   281,   305,
     414,   886,  -481,   779,   239,   292,   118,   120,    96,   309,
      97,   573,   577,  -303,   266,   307,  -303,    30,   887,   617,
     783,   815,   550,    13,   263,   205,   821,   533,   264,   209,
     855,   459,   674,   533,   534,   293,   710,   403,   626,    96,
     852,    97,   404,   870,   648,   542,   618,   648,   702,   274,
     294,   536,   675,   856,    13,   818,   306,    20,   295,   310,
     224,   505,   -66,  -303,   551,   627,  -303,   784,   240,   352,
     816,   649,   408,   533,   657,   703,   403,   103,   110,    97,
     890,   768,   761,    25,   115,   482,   767,   558,   -62,  -303,
     275,   353,   597,   280,   409,   116,   834,   403,     3,    46,
     121,   540,   823,   117,  -304,    97,    46,   830,   594,   282,
    -226,   413,   775,   859,    92,   391,   506,   507,   733,   280,
     280,   570,   572,   572,   695,   686,   430,   483,   241,   431,
     808,   597,    91,    34,   263,   282,   282,   883,   518,   434,
     374,   100,   435,   436,   437,   438,   439,   440,   670,    40,
     276,   865,   101,   271,   375,    58,    58,   105,   380,   105,
     105,   860,   106,   552,    84,    84,   406,   281,    86,    86,
     433,    90,    90,    59,    59,   259,    96,   108,    97,   531,
     119,   277,    97,   615,   616,    96,    46,    97,    46,   888,
     569,  -295,   574,   281,   281,  -295,   688,   713,   553,   390,
     714,   393,   709,   687,   111,   274,   829,   112,   392,   832,
     118,   120,   891,   114,    46,    46,    16,   274,   682,   685,
     441,   639,   680,   683,   683,   676,   274,    96,   281,    97,
     522,   391,   403,   -64,  -303,   572,   391,   640,   428,   280,
     723,   490,   257,   456,    97,   495,   275,   503,   504,   475,
     466,   379,   510,    97,   236,   282,    46,   757,   275,   414,
    -227,   -61,   381,   862,    97,   259,   759,   275,   274,   493,
     559,   728,   442,    13,   867,   382,   781,    97,   256,     4,
     782,    97,    46,   787,   897,   260,   299,   261,   281,   610,
     611,   612,   613,   614,   262,   771,   265,   267,   269,   -63,
     291,   615,   616,   523,   881,   530,   276,   443,   -65,   275,
     300,   302,   303,   281,   304,   308,   593,   539,   276,   311,
     772,   444,   475,   312,   538,   769,   313,   276,   281,   800,
     612,   613,   614,   563,   -67,   314,   315,   277,   316,   317,
     615,   616,    46,   575,   318,   319,   496,   445,   320,   277,
     446,   447,   448,   321,   322,   449,   450,   789,   277,    11,
     323,   324,   325,   280,   788,   326,   327,   328,   451,   276,
     329,   539,   330,   390,   837,   393,   331,   726,   332,   282,
     378,   333,   392,   334,   335,   539,   336,   337,   403,   278,
     281,   338,   391,   727,   339,   340,   341,   342,   639,   343,
     277,   344,   638,   728,   345,   279,   346,   347,   728,   403,
     391,   824,    23,   348,   640,   539,   349,   350,   351,   812,
     497,   498,   499,   500,   501,    26,    27,    28,    29,   383,
     384,   -68,   729,   385,   386,    31,   -69,   281,   871,   389,
     278,  -331,   681,   679,   396,   398,   402,   410,   593,   836,
     407,    84,   845,    58,    49,    86,   279,   420,    90,   271,
      59,    77,    84,   411,    67,   421,    86,   422,    69,    90,
      71,    59,   734,   885,    74,    56,    68,   391,    70,   424,
     765,    37,   841,    72,    73,    78,    39,   844,   429,   457,
      79,    80,   512,   462,   463,   728,   878,   715,   903,   717,
     468,   469,   471,   718,   716,   485,   456,   434,   486,   488,
     435,   436,   437,   438,   439,   440,   874,   509,   513,   514,
     515,   516,   517,   873,   519,   520,   892,  -303,   595,   596,
     597,   598,   599,   600,   601,   390,   527,   393,   528,   532,
     541,   777,   557,   561,   392,   562,   560,   680,   566,   578,
     580,   391,   281,   595,   596,   597,   281,   280,   475,   579,
     581,   582,   619,   583,   729,   620,   621,   819,   622,   729,
     623,   624,   391,   282,   625,   814,   628,   655,   629,   630,
     631,   632,   633,   634,   635,   637,   456,   647,   441,   650,
     651,   572,   659,   475,   572,   652,   653,   672,   271,   654,
     656,   658,   661,   662,   666,   663,   664,   665,   253,   667,
     668,   825,   254,   669,   795,   255,   274,   248,   689,   475,
     280,    13,   693,    84,   563,   697,   700,   701,   707,   281,
     704,   281,   710,   281,   719,   720,   282,   721,   737,   755,
     442,   760,   776,   758,   773,   475,   780,   241,   791,   793,
     798,   792,    92,   803,   848,   851,   729,   275,   807,   811,
     822,   828,   831,   460,   833,   835,   460,   595,   596,   597,
     598,   599,   600,   601,   473,   443,   281,   480,   846,   281,
     840,   847,   850,   853,   857,   480,   475,   494,   858,   444,
     861,   863,   563,   868,   281,    58,  -383,   842,   843,   869,
     876,   877,   882,  -384,    84,   884,   893,   894,    86,   895,
     896,    90,   849,    59,   458,   445,   535,   276,   446,   447,
     543,   568,   253,   449,   450,   608,   609,   610,   611,   612,
     613,   614,   544,   281,   902,   491,   451,   708,   770,   615,
     616,   475,   901,   691,   281,   526,   460,   545,   277,   806,
     797,   839,   610,   611,   612,   613,   614,   298,   872,   879,
     388,   724,     0,   802,   615,   616,   804,   681,   679,   281,
     487,     0,     0,   556,   281,   801,    84,     0,     0,     0,
      86,     0,     0,    90,     0,    59,     0,     0,   726,   584,
     585,   586,   587,   588,   589,   591,     0,     0,     0,   403,
       0,     0,   475,     0,   727,     0,     0,     0,   434,     0,
     590,   435,   436,   437,   438,   439,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,     0,
       0,   435,   436,   437,   438,   439,   440,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
      11,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,     0,     0,     0,     0,     0,    17,     0,   615,   616,
       0,     0,   243,    19,     0,     0,     0,   587,    20,   441,
       0,     0,     0,    21,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,   441,
       0,     0,     0,     0,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   735,
     736,   442,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   753,   754,     0,
     756,   442,     0,     0,    34,     0,     0,   460,     0,     0,
       0,    36,    37,    38,     0,     0,   443,    39,     0,     0,
      40,     0,     0,     0,   245,     0,     0,     0,     0,     0,
     444,     0,   480,   246,     0,    43,   443,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
     444,     0,     0,     0,     0,     0,   445,     0,     0,   446,
     447,   448,     0,     0,   449,   450,     0,     4,     5,     6,
       0,     0,     0,     0,     0,     0,   445,   451,     0,   446,
     447,   448,     0,     0,   449,   450,     0,     0,     0,     0,
       0,     0,     0,   698,     0,     8,     0,   451,     0,     0,
       0,     9,     0,    10,     0,     0,     0,     0,     0,    11,
      12,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      14,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,   595,   596,   597,     0,    20,   600,   601,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
     356,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   864,     0,     0,     0,
     866,    33,     0,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    35,
      36,    37,    38,     0,     0,     0,    39,   460,     0,    40,
       0,     8,     0,    41,     0,     0,     0,     9,     0,    10,
       0,     0,    42,     0,    43,    11,    12,     0,     0,    13,
       0,     0,    44,    45,     0,     0,    14,     0,   355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,     0,     0,     0,     0,     0,    18,    19,     0,
       0,    46,     0,    20,     0,   373,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,    24,   356,     0,     0,    25,
       0,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,    32,     0,
     608,   609,   610,   611,   612,   613,   614,     0,     0,     0,
       0,     0,     0,     0,   615,   616,     0,    33,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,    35,    36,    37,    38,     0,
       0,     0,    39,     0,     0,    40,     0,     8,     0,    41,
       0,     0,     0,     9,     0,    10,     0,     0,    42,     0,
      43,    11,    12,     0,     0,    13,     0,     0,    44,    45,
       0,     0,    14,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    19,     0,     0,    46,     0,    20,
       0,   838,     0,     0,    21,     0,     0,    22,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    35,    36,    37,    38,     0,     0,     0,    39,     0,
       9,    40,    10,     0,     0,    41,     0,     0,    11,     0,
       0,     0,    13,     0,    42,     0,    43,     0,     0,    14,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    21,     0,    46,    22,     0,     0,   692,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,   595,   596,   597,   598,   599,
     600,   601,   602,   603,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     9,     0,    10,     0,     0,    36,
      37,    38,    11,     0,     0,    39,    13,     0,    40,     0,
       0,     0,    41,    14,     0,     0,     0,     0,     0,     0,
       0,    42,     0,    43,     0,     0,     0,     0,    17,     0,
       0,    44,    45,     0,    18,    19,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
      46,     0,    24,     4,   678,     6,    25,     0,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    10,
       0,     0,     0,     0,    33,    11,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,     0,    39,
       0,    17,    40,     0,     0,     0,    41,   243,    19,     0,
       0,     0,     0,    20,     0,    42,     0,    43,    21,     0,
       0,    22,     0,     0,     0,    44,    45,   604,    23,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,    25,
       0,    26,    27,    28,    29,     0,   615,   616,     0,     0,
       0,    31,     0,   636,    46,     0,     0,     0,   875,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -3,     0,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,    34,
       7,     0,     0,     0,     0,     0,    36,    37,    38,     0,
       0,     0,    39,     0,     0,    40,     0,     8,     0,   245,
       0,     0,     0,     9,     0,    10,     0,     0,   246,     0,
      43,    11,    12,     0,     0,    13,     0,     0,    44,    45,
       0,     0,    14,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    19,     0,     0,    46,     0,    20,
       0,   794,     0,     0,    21,     0,     0,    22,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     4,     5,     6,     0,
       0,     0,     0,     0,     0,    34,   354,     0,     0,     0,
       0,    35,    36,    37,    38,     0,     0,     0,    39,     0,
       0,    40,     0,     0,     8,    41,     0,     0,     0,     0,
       9,     0,    10,     0,    42,     0,    43,     0,    11,    12,
       0,     0,    13,     0,    44,    45,     0,     0,     0,    14,
       0,   355,     0,     0,   595,   596,   597,   598,   599,   600,
     601,    16,   603,     0,    17,     0,     0,     0,     0,     0,
      18,    19,     0,    46,     0,     0,    20,     0,     0,     0,
       0,    21,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,    24,   356,
       0,     0,    25,     0,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     4,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,    35,    36,
      37,    38,     9,     0,    10,    39,     0,     0,    40,   274,
      11,     0,    41,     0,    13,     0,     0,     0,     0,     0,
       0,    42,     0,    43,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,    17,     0,     0,     0,
       0,     0,   243,    19,     0,     0,     0,     0,    20,     0,
     275,     0,     0,    21,     0,     0,    22,     0,     0,     0,
      46,     0,     0,    23,     0,   595,   596,   597,   598,   599,
     600,   601,     0,     0,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,     0,     0,     0,   615,   616,     0,     0,     0,
     276,     0,     0,     0,     0,     4,     0,     6,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,     0,    39,     0,     0,
      40,   277,     0,     0,   245,     0,     0,     0,     0,     9,
       0,    10,     0,   246,     0,    43,   274,    11,     0,     0,
       0,    13,     0,    44,    45,     0,     0,     0,   595,   596,
     597,   598,   599,   600,   601,   602,   603,     0,     0,     0,
       0,   763,     0,    17,     0,     0,     0,     0,     0,   243,
      19,     0,    46,     0,     0,    20,     0,   275,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     4,
       0,     6,     0,     0,   595,   596,   597,   598,   599,   600,
     601,   602,   603,     0,     0,     0,     0,   276,     0,     0,
     799,   607,   608,   609,   610,   611,   612,   613,   614,     0,
       0,    34,     0,     9,     0,    10,   615,   616,    36,    37,
      38,    11,     0,     0,    39,    13,     0,    40,   277,     0,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
     246,     0,    43,     0,     0,     0,     0,    17,     0,     0,
      44,    45,     0,   243,    19,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    21,     0,     0,    22,   817,     0,
       0,     0,     0,     0,    23,     0,     0,     0,     0,    46,
       0,     0,     4,     0,     6,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
     604,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,     0,     0,     0,     0,     9,     0,    10,   615,
     616,     0,     0,     0,    11,     0,   660,     0,    13,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    39,     0,
      17,    40,     0,     0,     0,   245,   243,    19,     0,     0,
       0,     0,    20,     0,   246,     0,    43,    21,     0,     0,
      22,     0,     0,     0,    44,    45,   604,    23,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,    25,     0,
      26,    27,    28,    29,     0,   615,   616,     0,     0,     0,
      31,     0,   725,    46,   595,   596,   597,   598,   599,   600,
     601,   602,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   595,   596,   597,   598,
     599,   600,   601,   602,   603,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
       0,    39,     0,     0,    40,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,   246,     0,    43,
       0,     0,     0,     0,     0,     0,     0,    44,    45,   595,
     596,   597,   598,   599,   600,   601,   602,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,   595,   596,   597,
     598,   599,   600,   601,   602,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   595,   596,   597,   598,   599,
     600,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   604,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   699,   604,     0,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
       0,     0,     0,     0,     0,     0,     0,   615,   616,   827,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   826,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,     0,     0,     0,     0,     0,     0,     0,
     615,   616,     0,     0,     0,     0,     0,     0,     0,   604,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,     4,     0,     6,     0,     0,     0,     0,   615,   616,
     606,   607,   608,   609,   610,   611,   612,   613,   614,     0,
       0,     0,     0,     0,     0,     0,   615,   616,     0,     8,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,     0,    11,    12,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -353,     0,     0,    17,
       0,     0,     0,     0,     0,   243,    19,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,    30,     0,     0,   244,     0,     0,    31,
       0,     0,     0,     0,     0,     4,     0,     6,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     9,
       0,    10,     0,    35,    36,    37,    38,    11,     0,     0,
      39,    13,     0,    40,     0,     0,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,    43,     0,
       0,     0,     0,    17,     0,     0,    44,    45,     0,   243,
      19,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       6,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     6,
       0,     0,     9,     0,    10,     0,     0,     0,     0,     0,
      11,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     9,     0,    10,    39,     0,    17,    40,     0,    11,
       0,   245,   243,    19,     0,     0,     0,     0,    20,     0,
     246,     0,    43,    21,     0,     0,    22,     0,     0,     0,
      44,    45,     0,    23,     0,    17,     0,     0,     0,     0,
       0,   243,    19,     0,    25,     0,    26,    27,    28,    29,
       0,     0,    21,     0,     0,    22,    31,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    97,     0,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     9,     0,    10,    39,     0,     0,
      40,     0,    11,     0,   245,     0,     0,   590,     0,     0,
       0,     0,     0,   246,     0,    43,     0,     0,     0,     0,
      36,    37,    38,    44,    45,     0,    39,     0,    17,     0,
       0,     0,     0,   245,     0,    19,     0,     0,     0,     9,
       0,    10,   246,     0,    43,    21,     0,    11,    22,     0,
       0,    13,    44,    45,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      28,    29,     0,    17,     0,     0,     0,     0,    31,   243,
      19,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,    37,    38,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,    43,     0,     0,
      11,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,    17,    40,     0,     0,
       0,   245,   243,    19,     0,     0,     0,     0,     0,     0,
     246,     0,    43,    21,     0,     0,    22,     0,     0,     0,
      44,    45,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,   122,
     123,     0,     0,   246,   124,    43,   125,   126,   127,   128,
     129,     0,   130,    44,    45,   131,     0,   132,     0,     0,
       0,   133,   134,     0,   135,   136,   137,   138,   139,   140,
       0,   141,     0,   142,   143,   144,     0,   145,   146,   147,
     148,   149,     0,   150,     0,     0,   151,   152,   153,   154,
     155,     0,     0,   156,   157,   158,   159,     0,     0,     0,
     160,   161,     0,   162,   163,     0,   164,   165,   166,   167,
     168,   169,     0,   170,   171,   172,   173,   174,   175,     0,
       0,   176,     0,     0,   177,     0,     0,     0,     0,     0,
     178,   179,     0,   180,   181,     0,   182,   183,   184,     0,
       0,     0,     0,   185,   186,   187,     0,   188,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,     0,   200,     0,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,     0,   212,   213,     0,
       0,     0,     0,     0,   214,     0,     0,   215,     0,   216,
       0,   217,   218,     0,     0,   219,   220,   221,   222,     0,
       0,   223,     0,   224,     0,   225,   226,   227,   228,   229,
     230,   231,     0,     0,   232
};

static const yytype_int16 yycheck[] =
{
       2,     2,     8,    55,    84,   259,    12,   259,     2,     2,
      16,     2,    18,     2,   259,     2,     2,     2,     2,   241,
      84,     2,     2,     2,    30,     2,    81,    82,    83,    35,
       2,     2,     2,    88,   399,    41,    42,     2,     2,   331,
      82,    83,   259,   284,   324,   322,    88,   327,   640,   329,
       6,   373,   332,     6,    17,   707,   451,   316,    64,   339,
      27,   279,   280,   639,    58,    58,    85,    58,   352,    58,
     715,    58,    58,    58,    58,   115,   115,   125,    84,     3,
     302,    43,   115,   675,    62,    29,    41,    42,     3,   180,
       5,   424,   425,   180,    75,   114,   180,   115,    60,   206,
      68,   724,    28,    49,   226,   154,   729,   206,   230,   158,
     206,   318,   212,   206,   213,    59,   206,   227,   206,     3,
     213,     5,   232,   213,   206,   402,   233,   206,   206,    44,
      74,   149,   232,   229,    49,   727,    60,    83,    82,   230,
     189,   348,   229,   230,    70,   233,   230,   115,   126,   206,
     726,   233,   206,   206,   233,   233,   227,     3,    31,     5,
     213,   232,   638,   109,    37,   132,   642,   412,   229,   230,
      85,   228,    17,   253,   228,    38,   768,   227,     0,   227,
      43,   399,   232,     3,   212,     5,   227,   763,   583,   253,
     231,   231,   231,   816,   227,   412,     6,     7,   593,   279,
     280,   423,   424,   425,   537,   527,     9,   174,   186,    12,
     855,    17,   226,   159,   226,   279,   280,   869,   230,     3,
     239,   232,     6,     7,     8,     9,    10,    11,   512,   175,
     145,   823,   230,   288,   240,   237,   238,   243,   244,   245,
     246,   817,   111,   169,   237,   238,   288,   253,   237,   238,
     314,   237,   238,   237,   238,   212,     3,     9,     5,   216,
       3,   176,     5,   226,   227,     3,   227,     5,   227,   231,
     231,   229,   231,   279,   280,   233,   528,   233,   204,   533,
     233,   533,   562,   528,     3,    44,   762,   232,   533,   765,
     245,   246,   884,   232,   227,   227,    68,    44,   231,   231,
      84,   216,   524,   525,   526,   523,    44,     3,   314,     5,
     374,   528,   227,   229,   230,   537,   533,   232,   311,   399,
     579,   340,     3,   316,     5,   344,    85,   346,   347,   331,
     323,     3,   351,     5,   229,   399,   227,   617,    85,   561,
     231,   229,     3,   819,     5,   212,   623,    85,    44,   342,
     414,   592,   136,    49,   830,     3,   678,     5,   229,     3,
     682,     5,   227,   685,   229,   229,   115,   229,   374,   214,
     215,   216,   217,   218,   229,   655,   229,   229,   229,   229,
     229,   226,   227,   376,   860,   391,   145,   171,   229,    85,
       9,   230,   229,   399,   212,   230,   451,   762,   145,   232,
     659,   185,   404,   232,   398,   646,   232,   145,   414,   701,
     216,   217,   218,   419,   229,   232,   232,   176,   232,   232,
     226,   227,   227,   425,   232,   232,   127,   211,   232,   176,
     214,   215,   216,   232,   232,   219,   220,   689,   176,    45,
     232,   232,   232,   523,   689,   232,   232,   232,   232,   145,
     232,   816,   232,   707,   776,   707,   232,   216,   232,   523,
     230,   232,   707,   232,   232,   830,   232,   232,   227,   216,
     476,   232,   689,   232,   232,   232,   232,   232,   216,   232,
     176,   232,   475,   724,   232,   232,   232,   232,   729,   227,
     707,   732,    98,   232,   232,   860,   232,   232,   232,   717,
     201,   202,   203,   204,   205,   111,   112,   113,   114,   230,
     230,   229,   592,   230,   230,   121,   229,   523,   840,   226,
     216,   212,   524,   524,     3,   230,   234,     5,   583,   774,
     232,   524,   784,   535,   535,   524,   232,   208,   524,   594,
     524,   535,   535,   233,   535,   208,   535,   233,   535,   535,
     535,   535,   594,   875,   535,   535,   535,   774,   535,   232,
     640,   167,   780,   535,   535,   535,   172,   784,     9,     6,
     535,   535,   227,     9,     9,   816,   853,   570,   900,   572,
       9,     9,     9,   572,   570,     9,   579,     3,     9,     9,
       6,     7,     8,     9,    10,    11,   848,     9,   230,   232,
     229,   229,   229,   848,   229,   229,   886,   230,    15,    16,
      17,    18,    19,    20,    21,   869,   231,   869,   208,   216,
     233,   673,   230,   206,   869,   234,   231,   849,     6,   233,
     233,   848,   638,    15,    16,    17,   642,   717,   640,   206,
     233,   233,   233,   232,   724,   206,   226,   727,   233,   729,
     206,   233,   869,   717,   233,   719,   233,   206,   233,   233,
     233,   233,   233,   233,   233,   233,   659,   233,    84,   233,
     233,   893,   206,   675,   896,   233,   233,     9,   733,   233,
     233,   233,   233,   233,   226,   233,   233,   233,   681,   233,
     233,   733,   681,   233,   696,   681,    44,   681,   162,   701,
     780,    49,   208,   696,   710,   229,   233,   206,   212,   715,
     186,   717,   206,   719,   233,   229,   780,   229,     3,     3,
     136,     9,   233,     6,     6,   727,   206,   186,   230,   229,
     231,   208,   227,   231,   206,     5,   816,    85,   213,   229,
     233,   233,   233,   319,   233,   233,   322,    15,    16,    17,
      18,    19,    20,    21,   330,   171,   762,   333,   229,   765,
     233,   229,   229,   208,   230,   341,   768,   343,   233,   185,
     233,   233,   778,   233,   780,   777,   229,   783,   784,   212,
     229,   229,   233,   229,   777,   232,   208,   229,   777,   233,
     208,   777,   791,   777,   317,   211,   397,   145,   214,   215,
     216,   421,   795,   219,   220,   212,   213,   214,   215,   216,
     217,   218,   228,   819,   229,   341,   232,   561,   648,   226,
     227,   823,   896,   533,   830,   385,   402,   403,   176,   710,
     696,   778,   214,   215,   216,   217,   218,    94,   844,   855,
     253,   583,    -1,   704,   226,   227,   706,   849,   849,   855,
     337,    -1,    -1,   408,   860,   702,   849,    -1,    -1,    -1,
     849,    -1,    -1,   849,    -1,   849,    -1,    -1,   216,   445,
     446,   447,   448,   449,   450,   451,    -1,    -1,    -1,   227,
      -1,    -1,   884,    -1,   232,    -1,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,    -1,    71,    -1,   226,   227,
      -1,    -1,    77,    78,    -1,    -1,    -1,   543,    83,    84,
      -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,   109,    -1,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   595,
     596,   136,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,    -1,
     616,   136,    -1,    -1,   159,    -1,    -1,   623,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,   171,   172,    -1,    -1,
     175,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    -1,
     185,    -1,   648,   188,    -1,   190,   171,    -1,    -1,    -1,
      -1,    -1,    -1,   198,   199,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,    -1,    -1,   219,   220,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   232,    -1,   214,
     215,   216,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,    -1,    31,    -1,   232,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    15,    16,    17,    -1,    83,    20,    21,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,   109,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   822,    -1,    -1,    -1,
     826,   147,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,   172,   853,    -1,   175,
      -1,    31,    -1,   179,    -1,    -1,    -1,    37,    -1,    39,
      -1,    -1,   188,    -1,   190,    45,    46,    -1,    -1,    49,
      -1,    -1,   198,   199,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,   227,    -1,    83,    -1,   231,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,   147,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,    -1,   172,    -1,    -1,   175,    -1,    31,    -1,   179,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,   188,    -1,
     190,    45,    46,    -1,    -1,    49,    -1,    -1,   198,   199,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,   227,    -1,    83,
      -1,   231,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,   172,    -1,
      37,   175,    39,    -1,    -1,   179,    -1,    -1,    45,    -1,
      -1,    -1,    49,    -1,   188,    -1,   190,    -1,    -1,    56,
      -1,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    88,    -1,   227,    91,    -1,    -1,   231,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,   109,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    37,    -1,    39,    -1,    -1,   166,
     167,   168,    45,    -1,    -1,   172,    49,    -1,   175,    -1,
      -1,    -1,   179,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,   190,    -1,    -1,    -1,    -1,    71,    -1,
      -1,   198,   199,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     227,    -1,   105,     3,   231,     5,   109,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,   147,    45,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,   172,
      -1,    71,   175,    -1,    -1,    -1,   179,    77,    78,    -1,
      -1,    -1,    -1,    83,    -1,   188,    -1,   190,    88,    -1,
      -1,    91,    -1,    -1,    -1,   198,   199,   207,    98,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   109,
      -1,   111,   112,   113,   114,    -1,   226,   227,    -1,    -1,
      -1,   121,    -1,   233,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      14,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,   172,    -1,    -1,   175,    -1,    31,    -1,   179,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,   188,    -1,
     190,    45,    46,    -1,    -1,    49,    -1,    -1,   198,   199,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,   227,    -1,    83,
      -1,   231,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,   109,    -1,   111,   112,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   147,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    13,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,   172,    -1,
      -1,   175,    -1,    -1,    31,   179,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,   188,    -1,   190,    -1,    45,    46,
      -1,    -1,    49,    -1,   198,   199,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    68,    23,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,   227,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,    37,    -1,    39,   172,    -1,    -1,   175,    44,
      45,    -1,   179,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,   188,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   198,   199,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    83,    -1,
      85,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
     227,    -1,    -1,    98,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,   109,    -1,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,
     145,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,
     175,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,   188,    -1,   190,    44,    45,    -1,    -1,
      -1,    49,    -1,   198,   199,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,   216,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    -1,   227,    -1,    -1,    83,    -1,    85,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      24,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,   159,    -1,    37,    -1,    39,   226,   227,   166,   167,
     168,    45,    -1,    -1,   172,    49,    -1,   175,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,    -1,    -1,    -1,    -1,    71,    -1,    -1,
     198,   199,    -1,    77,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    91,   216,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   227,
      -1,    -1,     3,    -1,     5,   109,    -1,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    37,    -1,    39,   226,
     227,    -1,    -1,    -1,    45,    -1,   233,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,   172,    -1,
      71,   175,    -1,    -1,    -1,   179,    77,    78,    -1,    -1,
      -1,    -1,    83,    -1,   188,    -1,   190,    88,    -1,    -1,
      91,    -1,    -1,    -1,   198,   199,   207,    98,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   109,    -1,
     111,   112,   113,   114,    -1,   226,   227,    -1,    -1,    -1,
     121,    -1,   233,   227,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,   172,    -1,    -1,   175,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     3,    -1,     5,    -1,    -1,    -1,    -1,   226,   227,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,
     112,   113,   114,   115,    -1,    -1,   118,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    37,
      -1,    39,    -1,   165,   166,   167,   168,    45,    -1,    -1,
     172,    49,    -1,   175,    -1,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,
      -1,    -1,    -1,    71,    -1,    -1,   198,   199,    -1,    77,
      78,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,   109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,    37,    -1,    39,   172,    -1,    71,   175,    -1,    45,
      -1,   179,    77,    78,    -1,    -1,    -1,    -1,    83,    -1,
     188,    -1,   190,    88,    -1,    -1,    91,    -1,    -1,    -1,
     198,   199,    -1,    98,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,   109,    -1,   111,   112,   113,   114,
      -1,    -1,    88,    -1,    -1,    91,   121,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,    -1,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    37,    -1,    39,   172,    -1,    -1,
     175,    -1,    45,    -1,   179,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,   188,    -1,   190,    -1,    -1,    -1,    -1,
     166,   167,   168,   198,   199,    -1,   172,    -1,    71,    -1,
      -1,    -1,    -1,   179,    -1,    78,    -1,    -1,    -1,    37,
      -1,    39,   188,    -1,   190,    88,    -1,    45,    91,    -1,
      -1,    49,   198,   199,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    71,    -1,    -1,    -1,    -1,   121,    77,
      78,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,   109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   167,   168,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    -1,   190,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,   172,    -1,    71,   175,    -1,    -1,
      -1,   179,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
     188,    -1,   190,    88,    -1,    -1,    91,    -1,    -1,    -1,
     198,   199,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,   188,    30,   190,    32,    33,    34,    35,
      36,    -1,    38,   198,   199,    41,    -1,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    57,    -1,    59,    60,    61,    -1,    63,    64,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    73,    74,    75,
      76,    -1,    -1,    79,    80,    81,    82,    -1,    -1,    -1,
      86,    87,    -1,    89,    90,    -1,    92,    93,    94,    95,
      96,    97,    -1,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,   119,   120,    -1,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,   130,   131,    -1,   133,   134,   135,
      -1,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
     146,    -1,   148,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,   158,    -1,   160,   161,    -1,   163,   164,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,   184,    -1,
      -1,   187,    -1,   189,    -1,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,   200
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,   242,     0,     3,     4,     5,    14,    31,    37,
      39,    45,    46,    49,    56,    58,    68,    71,    77,    78,
      83,    88,    91,    98,   105,   109,   111,   112,   113,   114,
     115,   121,   128,   147,   159,   165,   166,   167,   168,   172,
     175,   179,   188,   190,   198,   199,   227,   237,   239,   248,
     249,   251,   252,   253,   254,   257,   258,   264,   265,   282,
     296,   299,   301,   303,   304,   305,   306,   309,   310,   311,
     312,   313,   314,   315,   318,   319,   322,   326,   329,   334,
     339,   340,   341,   342,   344,   347,   365,   366,   367,   368,
     369,   226,   227,   371,   374,   375,     3,     5,   299,   299,
     232,   230,   299,     3,   298,   299,   111,   302,     9,   299,
     302,     3,   232,   299,   232,   302,   303,     3,   298,     3,
     298,   303,    25,    26,    30,    32,    33,    34,    35,    36,
      38,    41,    43,    47,    48,    50,    51,    52,    53,    54,
      55,    57,    59,    60,    61,    63,    64,    65,    66,    67,
      69,    72,    73,    74,    75,    76,    79,    80,    81,    82,
      86,    87,    89,    90,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   107,   110,   116,   117,
     119,   120,   122,   123,   124,   129,   130,   131,   133,   134,
     135,   137,   138,   139,   140,   141,   142,   143,   144,   146,
     148,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   163,   164,   170,   173,   175,   177,   178,   181,
     182,   183,   184,   187,   189,   191,   192,   193,   194,   195,
     196,   197,   200,   266,   273,   364,   229,   244,   244,    62,
     126,   186,   338,    77,   118,   179,   188,   256,   282,   309,
     311,   313,   326,   344,   365,   369,   229,     3,   299,   212,
     229,   229,   229,   226,   230,   229,   318,   229,   247,   229,
     346,   347,   346,   346,    44,    85,   145,   176,   216,   232,
     275,   299,   300,   348,   349,   362,   282,   365,   367,   369,
     346,   229,    29,    59,    74,    82,   376,   377,   371,   115,
       9,   238,   230,   229,   212,     3,    60,   367,   230,   180,
     230,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   206,   228,    13,    58,   106,   241,   248,   255,
     258,   309,   310,   311,   312,   313,   314,   315,   318,   326,
     329,   334,   339,   231,   367,   299,   264,   265,   230,     3,
     299,     3,     3,   230,   230,   230,   230,   335,   362,   226,
     301,   304,   305,   306,   307,   308,     3,   243,   230,   343,
     348,   348,   234,   227,   232,   263,   346,   232,   206,   228,
       5,   233,   115,   231,   264,   278,   279,   280,   281,   327,
     208,   208,   233,   289,   232,   292,   270,   272,   344,     9,
       9,    12,   274,   300,     3,     6,     7,     8,     9,    10,
      11,    84,   136,   171,   185,   211,   214,   215,   216,   219,
     220,   232,   285,   286,   287,   270,   344,     6,   269,   274,
     285,   288,     9,     9,   267,   288,   344,   287,     9,     9,
     287,     9,   287,   285,   262,   265,   344,   287,   283,   284,
     285,    27,   132,   174,   268,     9,     9,   364,     9,   287,
     367,   283,   271,   344,   285,   367,   127,   201,   202,   203,
     204,   205,   363,   367,   367,   274,     6,     7,   370,     9,
     367,   273,   227,   230,   232,   229,   229,   229,   230,   229,
     229,   247,   300,   344,   246,   316,   316,   231,   208,   323,
     299,   216,   216,   206,   213,   242,   149,   320,   326,   342,
     348,   233,   288,   216,   228,   285,   259,   260,   261,   262,
      28,    70,   169,   204,   378,   379,   377,   230,   305,   300,
     231,   206,   234,   299,   324,   325,     6,   250,   250,   231,
     264,   290,   264,   294,   231,   265,   291,   294,   233,   206,
     233,   233,   233,   232,   285,   285,   285,   285,   285,   285,
       5,   285,   345,   347,   366,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   207,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   226,   227,   206,   233,   233,
     206,   226,   233,   206,   233,   233,   206,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   344,   216,
     232,   263,   275,   300,   354,   356,   357,   233,   206,   233,
     233,   233,   233,   233,   233,   206,   233,   233,   233,   206,
     233,   233,   233,   233,   233,   233,   226,   233,   233,   233,
     273,   240,     9,   245,   212,   232,   348,   358,   231,   248,
     264,   265,   231,   264,   317,   231,   247,   305,   306,   162,
     333,   307,   231,   208,   125,   294,   321,   229,   228,   228,
     233,   206,   206,   233,   186,   372,   373,   212,   281,   287,
     206,   328,     6,   233,   233,   344,   369,   344,   365,   233,
     229,   229,   269,   270,   345,   233,   216,   232,   263,   275,
     350,   352,   353,   366,   346,   285,   285,     3,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,     3,   285,   287,     6,   288,
       9,   356,   343,   216,   259,   275,   355,   356,   232,   263,
     284,   287,   270,     6,   115,   231,   233,   244,   330,   259,
     206,   247,   247,    68,   115,   336,   337,   247,   305,   306,
     332,   230,   208,   229,   231,   265,   295,   296,   231,    24,
     262,   379,   375,   231,   372,   308,   324,   213,   354,   360,
     361,   229,   348,   297,   300,   352,   343,   216,   259,   275,
     351,   352,   233,   232,   263,   346,   208,   228,   233,   356,
     343,   233,   356,   233,   259,   233,   305,   247,   231,   325,
     233,   348,   299,   299,   304,   306,   229,   229,   206,   246,
     229,     5,   213,   208,   359,   206,   229,   230,   233,   352,
     343,   233,   356,   233,   285,   259,   285,   356,   233,   212,
     213,   247,   299,   305,   306,   231,   229,   229,   288,   360,
     276,   356,   233,   308,   232,   247,    43,    60,   231,   277,
     213,   259,   287,   208,   229,   233,   208,   229,   293,   294,
     331,   293,   229,   247
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   237,   237,   238,   238,   239,   240,   240,
     241,   242,   243,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   244,   244,
     244,   245,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   246,   246,   247,   247,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   263,   263,   264,   264,
     265,   266,   266,   266,   267,   267,   268,   268,   268,   269,
     269,   270,   271,   272,   272,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   274,   274,   275,   275,
     275,   275,   276,   276,   277,   277,   278,   278,   278,   279,
     279,   280,   281,   281,   282,   283,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     286,   286,   287,   288,   289,   289,   290,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   304,
     305,   305,   306,   307,   307,   307,   307,   307,   308,   308,
     309,   310,   311,   312,   313,   314,   315,   315,   316,   316,
     317,   317,   318,   319,   320,   320,   321,   321,   322,   322,
     323,   323,   323,   324,   325,   325,   326,   327,   328,   326,
     329,   330,   331,   329,   332,   332,   332,   332,   333,   333,
     335,   334,   334,   336,   336,   336,   337,   338,   339,   340,
     340,   340,   341,   342,   343,   343,   344,   344,   345,   345,
     346,   346,   347,   347,   347,   348,   348,   348,   349,   349,
     349,   349,   350,   350,   350,   351,   351,   352,   352,   353,
     353,   353,   353,   353,   354,   354,   354,   355,   355,   356,
     356,   357,   357,   357,   357,   357,   357,   358,   358,   359,
     359,   360,   361,   361,   362,   362,   363,   363,   363,   363,
     363,   363,   364,   364,   364,   365,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   367,   367,   367,   368,
     369,   369,   370,   370,   370,   371,   371,   372,   372,   373,
     374,   375,   375,   376,   376,   377,   377,   377,   377,   378,
     378,   379,   379,   379,   379
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     7,     4,     0,     7,
       4,     0,     0,     6,     3,     3,     2,     2,     3,     2,
       3,     2,     3,     2,     2,     2,     2,     2,     0,     3,
       3,     0,     6,     2,     2,     3,     2,     3,     2,     3,
       2,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     6,     1,
       2,     1,     2,     1,     2,     1,     2,     2,     2,     2,
       4,     3,     3,     5,     2,     3,     4,     0,     1,     1,
       3,     1,     3,     3,     2,     3,     3,     2,     0,     1,
       3,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     0,     4,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     4,     4,     1,     6,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     1,     1,     1,     4,     4,     1,
       1,     4,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     1,     4,     1,     1,     4,     1,     4,     1,
       1,     4,     4,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     4,     1,     4,     4,     1,     1,     1,     1,     1,
       6,     1,     4,     1,     1,     1,     4,     1,     4,     1,
       1,     4,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     4,     3,     0,     2,     1,     1,
       3,     2,     3,     1,     5,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     5,     4,     3,
       1,     3,     1,     1,     0,     2,     4,     3,     2,     2,
       0,     2,     2,     1,     3,     2,     1,     3,     2,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     2,     3,
       1,     2,     4,     1,     1,     2,     1,     2,     1,     3,
       2,     6,     2,     6,     2,     5,     2,     3,     0,     2,
       3,     3,     2,     1,     2,     3,     2,     3,     6,     6,
       0,     2,     2,     1,     1,     3,     2,     0,     0,     7,
       8,     0,     0,    13,     1,     1,     3,     3,     0,     2,
       0,     9,     2,     2,     3,     2,     2,     2,     6,     1,
       1,     1,     1,     1,     0,     2,     2,     3,     2,     3,
       0,     1,     2,     2,     2,     3,     2,     1,     1,     3,
       2,     4,     3,     2,     1,     3,     2,     0,     1,     3,
       2,     1,     3,     4,     3,     2,     1,     3,     2,     0,
       1,     1,     3,     2,     1,     3,     4,     1,     3,     0,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     1,     1,     2,
       1,     2,     1,     2,     4,     1,     1,     2,     1,     5,
       5,    10,     1,     3,     1,     0,     2,     0,     2,     4,
       6,     0,     3,     1,     3,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PARSER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PARSER_EMPTY)                                        \
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
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF


/* Enable debugging if requested.  */
#if PARSER_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
#else /* !PARSER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PARSER_DEBUG */


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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= PARSER_EOF)
    {
      yychar = PARSER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PARSER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PARSER_UNDEF;
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
  yychar = PARSER_EMPTY;
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
#line 354 "tools/widl/parser.y"
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
#line 3435 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3441 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 373 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3449 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 378 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3455 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 380 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3461 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3467 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 385 "tools/widl/parser.y"
                                                     { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3473 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3479 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 388 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3485 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 389 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3491 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3497 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 391 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3503 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3509 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3515 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3523 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 397 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3531 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3537 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3544 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3550 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 404 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3557 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3563 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3569 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3575 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3581 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3587 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3593 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3599 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 415 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3605 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 416 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3611 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3617 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3623 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3629 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 420 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3637 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3643 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3650 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 426 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3656 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3663 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3669 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3675 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 431 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3681 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3687 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3693 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3699 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3705 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3711 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 446 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3717 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 447 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3723 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3729 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 449 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3735 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3741 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 451 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3747 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 455 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3759 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 463 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3768 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 470 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3774 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 471 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3780 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM aIDENTIFIER  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3786 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3792 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION aIDENTIFIER  */
#line 480 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3798 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 481 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3804 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 482 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3810 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3816 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 486 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3822 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3832 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 495 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3841 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3847 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3853 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3861 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3867 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3873 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 519 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3879 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 520 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3885 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(xstrdup("...")) ); }
#line 3891 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 528 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3901 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 533 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3920 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3926 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3932 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3938 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3944 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3950 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3956 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3962 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3968 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3974 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3980 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3986 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3992 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3998 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 4004 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 576 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 4014 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 582 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4023 "tools/widl/parser.tab.c"
    break;

  case 103: /* activatable_attr: decl_spec ',' contract_req  */
#line 588 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4032 "tools/widl/parser.tab.c"
    break;

  case 104: /* activatable_attr: contract_req  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 4038 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: %empty  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 4044 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tACTIVATABLE '(' activatable_attr ')'  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 4050 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tAGGREGATABLE  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 4056 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 4062 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tAPPOBJECT  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 4068 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tASYNC  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 4074 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tAUTOHANDLE  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 4080 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tBINDABLE  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 4086 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tBROADCAST  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 4092 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tCALLAS '(' ident ')'  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 4098 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 4104 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tCODE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 4110 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCOMMSTATUS  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 4116 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCONTEXTHANDLE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 4122 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4128 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4134 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 4140 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 4146 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tCONTROL  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 4152 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 613 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 4158 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tDECODE  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 4164 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tDEFAULT  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 4170 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tDEFAULTBIND  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 4176 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tDEFAULTCOLLELEM  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 4182 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 4188 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDEFAULTVTABLE  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 4194 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 4200 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDISPLAYBIND  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 4206 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 4212 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tDUAL  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 4218 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tENABLEALLOCATE  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 4224 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tENCODE  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4230 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tENDPOINT '(' str_list ')'  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4236 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tENTRY '(' expr_const ')'  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4242 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tEVENTADD  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4248 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tEVENTREMOVE  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4254 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 630 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4262 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tEXPLICITHANDLE  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4268 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tFAULTSTATUS  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4274 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tFLAGS  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4280 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tFORCEALLOCATE  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4286 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tHANDLE  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4292 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4298 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4304 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4310 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 641 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4316 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4322 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tHIDDEN  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4328 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tID '(' expr_int_const ')'  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4334 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tIDEMPOTENT  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4340 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tIGNORE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4346 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tIIDIS '(' expr ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4352 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tIMMEDIATEBIND  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4358 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4364 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tIN  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4370 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tINPUTSYNC  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4376 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4382 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tLCID '(' expr_int_const ')'  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4388 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tLCID  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4394 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tLICENSED  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4400 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tLOCAL  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4406 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4412 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tMAYBE  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4418 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tMESSAGE  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4424 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tNOCODE  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4430 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tNONBROWSABLE  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4436 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tNONCREATABLE  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4442 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tNONEXTENSIBLE  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4448 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tNOTIFY  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4454 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tNOTIFYFLAG  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4460 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tOBJECT  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4466 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tODL  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4472 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tOLEAUTOMATION  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4478 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4484 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tOPTIONAL  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4490 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tOUT  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4496 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tOVERLOAD '(' aSTRING ')'  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OVERLOAD, (yyvsp[-1].str)); }
#line 4502 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tPARTIALIGNORE  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4508 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4514 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tPROGID '(' aSTRING ')'  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4520 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tPROPGET  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4526 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tPROPPUT  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4532 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tPROPPUTREF  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4538 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tPROXY  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4544 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tPUBLIC  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4550 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 683 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4558 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tREADONLY  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4564 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tREPRESENTAS '(' type ')'  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4570 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tREQUESTEDIT  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4576 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tRESTRICTED  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4582 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tRETVAL  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4588 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4594 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tSOURCE  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4600 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tSTATIC '(' static_attr ')'  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4606 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4612 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tSTRING  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4618 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tSWITCHIS '(' expr ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4630 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tTRANSMITAS '(' type ')'  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4636 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tTHREADING '(' threading_type ')'  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4642 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tUIDEFAULT  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4648 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tUSESGETLASTERROR  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4654 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4660 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tUUID '(' uuid_string ')'  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4666 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4672 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tV1ENUM  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4678 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tVARARG  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4684 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: tVERSION '(' version ')'  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4690 "tools/widl/parser.tab.c"
    break;

  case 213: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4696 "tools/widl/parser.tab.c"
    break;

  case 214: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4702 "tools/widl/parser.tab.c"
    break;

  case 215: /* attribute: pointer_type  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4708 "tools/widl/parser.tab.c"
    break;

  case 217: /* uuid_string: aSTRING  */
#line 715 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4716 "tools/widl/parser.tab.c"
    break;

  case 218: /* callconv: tCDECL  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4722 "tools/widl/parser.tab.c"
    break;

  case 219: /* callconv: tFASTCALL  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4728 "tools/widl/parser.tab.c"
    break;

  case 220: /* callconv: tPASCAL  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4734 "tools/widl/parser.tab.c"
    break;

  case 221: /* callconv: tSTDCALL  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4740 "tools/widl/parser.tab.c"
    break;

  case 222: /* cases: %empty  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4746 "tools/widl/parser.tab.c"
    break;

  case 223: /* cases: cases case  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4752 "tools/widl/parser.tab.c"
    break;

  case 224: /* case: tCASE expr_int_const ':' union_field  */
#line 730 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4761 "tools/widl/parser.tab.c"
    break;

  case 225: /* case: tDEFAULT ':' union_field  */
#line 734 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4770 "tools/widl/parser.tab.c"
    break;

  case 226: /* enums: %empty  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4776 "tools/widl/parser.tab.c"
    break;

  case 227: /* enums: enum_list ','  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4782 "tools/widl/parser.tab.c"
    break;

  case 229: /* enum_list: enum  */
#line 745 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4791 "tools/widl/parser.tab.c"
    break;

  case 230: /* enum_list: enum_list ',' enum  */
#line 749 "tools/widl/parser.y"
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
#line 4806 "tools/widl/parser.tab.c"
    break;

  case 231: /* enum_member: m_attributes ident  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4814 "tools/widl/parser.tab.c"
    break;

  case 232: /* enum: enum_member '=' expr_int_const  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4823 "tools/widl/parser.tab.c"
    break;

  case 233: /* enum: enum_member  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4831 "tools/widl/parser.tab.c"
    break;

  case 234: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4837 "tools/widl/parser.tab.c"
    break;

  case 235: /* m_exprs: m_expr  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4843 "tools/widl/parser.tab.c"
    break;

  case 236: /* m_exprs: m_exprs ',' m_expr  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4849 "tools/widl/parser.tab.c"
    break;

  case 237: /* m_expr: %empty  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4855 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: aNUM  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4861 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: aHEXNUM  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4867 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: aDOUBLE  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4873 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: tFALSE  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4879 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: tNULL  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4885 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: tTRUE  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4891 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: aSTRING  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4897 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: aWSTRING  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4903 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: aSQSTRING  */
#line 794 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4909 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: aIDENTIFIER  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4915 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '?' expr ':' expr  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4921 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr LOGICALOR expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4927 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr LOGICALAND expr  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4933 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '|' expr  */
#line 799 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4939 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr '^' expr  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4945 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr '&' expr  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4951 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr EQUALITY expr  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4957 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr INEQUALITY expr  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4963 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr '>' expr  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4969 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '<' expr  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4975 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr GREATEREQUAL expr  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4981 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr LESSEQUAL expr  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4987 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr SHL expr  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4993 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr SHR expr  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4999 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr '+' expr  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5005 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr '-' expr  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5011 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: expr '%' expr  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5017 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: expr '*' expr  */
#line 813 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5023 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr '/' expr  */
#line 814 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5029 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: '!' expr  */
#line 815 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 5035 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: '~' expr  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 5041 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: '+' expr  */
#line 817 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 5047 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: '-' expr  */
#line 818 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 5053 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: '&' expr  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 5059 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: '*' expr  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 5065 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 821 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5071 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: expr '.' aIDENTIFIER  */
#line 822 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5077 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5083 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 826 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5089 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr: expr '[' expr ']'  */
#line 827 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5095 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr: '(' expr ')'  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5101 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr_list_int_const: expr_int_const  */
#line 831 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5107 "tools/widl/parser.tab.c"
    break;

  case 281: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 832 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5113 "tools/widl/parser.tab.c"
    break;

  case 282: /* expr_int_const: expr  */
#line 835 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5122 "tools/widl/parser.tab.c"
    break;

  case 283: /* expr_const: expr  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5131 "tools/widl/parser.tab.c"
    break;

  case 284: /* fields: %empty  */
#line 847 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5137 "tools/widl/parser.tab.c"
    break;

  case 285: /* fields: fields field  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5143 "tools/widl/parser.tab.c"
    break;

  case 286: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 852 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5152 "tools/widl/parser.tab.c"
    break;

  case 287: /* field: m_attributes uniondef ';'  */
#line 856 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5161 "tools/widl/parser.tab.c"
    break;

  case 288: /* ne_union_field: s_field ';'  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5167 "tools/widl/parser.tab.c"
    break;

  case 289: /* ne_union_field: attributes ';'  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5173 "tools/widl/parser.tab.c"
    break;

  case 290: /* ne_union_fields: %empty  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5179 "tools/widl/parser.tab.c"
    break;

  case 291: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5185 "tools/widl/parser.tab.c"
    break;

  case 292: /* union_field: s_field ';'  */
#line 872 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5191 "tools/widl/parser.tab.c"
    break;

  case 293: /* union_field: ';'  */
#line 873 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5197 "tools/widl/parser.tab.c"
    break;

  case 294: /* s_field: m_attributes decl_spec declarator  */
#line 876 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5206 "tools/widl/parser.tab.c"
    break;

  case 295: /* s_field: m_attributes structdef  */
#line 880 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5215 "tools/widl/parser.tab.c"
    break;

  case 296: /* funcdef: declaration  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5225 "tools/widl/parser.tab.c"
    break;

  case 297: /* declaration: attributes decl_spec init_declarator  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5233 "tools/widl/parser.tab.c"
    break;

  case 298: /* declaration: decl_spec init_declarator  */
#line 898 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5241 "tools/widl/parser.tab.c"
    break;

  case 299: /* m_ident: %empty  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5247 "tools/widl/parser.tab.c"
    break;

  case 301: /* m_typename: %empty  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5253 "tools/widl/parser.tab.c"
    break;

  case 305: /* ident: typename  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5259 "tools/widl/parser.tab.c"
    break;

  case 306: /* base_type: tBYTE  */
#line 918 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5265 "tools/widl/parser.tab.c"
    break;

  case 307: /* base_type: tWCHAR  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5271 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tSIGNED int_std  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5277 "tools/widl/parser.tab.c"
    break;

  case 310: /* base_type: tUNSIGNED int_std  */
#line 922 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5283 "tools/widl/parser.tab.c"
    break;

  case 311: /* base_type: tUNSIGNED  */
#line 923 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5289 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tFLOAT  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5295 "tools/widl/parser.tab.c"
    break;

  case 313: /* base_type: tDOUBLE  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5301 "tools/widl/parser.tab.c"
    break;

  case 314: /* base_type: tBOOLEAN  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5307 "tools/widl/parser.tab.c"
    break;

  case 315: /* base_type: tERRORSTATUST  */
#line 927 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5313 "tools/widl/parser.tab.c"
    break;

  case 316: /* base_type: tHANDLET  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5319 "tools/widl/parser.tab.c"
    break;

  case 319: /* int_std: tINT  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5325 "tools/widl/parser.tab.c"
    break;

  case 320: /* int_std: tSHORT m_int  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5331 "tools/widl/parser.tab.c"
    break;

  case 321: /* int_std: tSMALL  */
#line 937 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5337 "tools/widl/parser.tab.c"
    break;

  case 322: /* int_std: tLONG m_int  */
#line 938 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5343 "tools/widl/parser.tab.c"
    break;

  case 323: /* int_std: tHYPER m_int  */
#line 939 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5349 "tools/widl/parser.tab.c"
    break;

  case 324: /* int_std: tINT64  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5355 "tools/widl/parser.tab.c"
    break;

  case 325: /* int_std: tCHAR  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5361 "tools/widl/parser.tab.c"
    break;

  case 326: /* int_std: tINT32  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5367 "tools/widl/parser.tab.c"
    break;

  case 327: /* int_std: tINT3264  */
#line 943 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5373 "tools/widl/parser.tab.c"
    break;

  case 328: /* namespace_pfx: aIDENTIFIER '.'  */
#line 947 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5379 "tools/widl/parser.tab.c"
    break;

  case 329: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5385 "tools/widl/parser.tab.c"
    break;

  case 330: /* qualified_type: typename  */
#line 952 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5391 "tools/widl/parser.tab.c"
    break;

  case 331: /* qualified_type: namespace_pfx typename  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5397 "tools/widl/parser.tab.c"
    break;

  case 332: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 957 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5403 "tools/widl/parser.tab.c"
    break;

  case 333: /* parameterized_type_arg: base_type  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5409 "tools/widl/parser.tab.c"
    break;

  case 334: /* parameterized_type_arg: qualified_type  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5415 "tools/widl/parser.tab.c"
    break;

  case 335: /* parameterized_type_arg: qualified_type '*'  */
#line 963 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5421 "tools/widl/parser.tab.c"
    break;

  case 336: /* parameterized_type_arg: parameterized_type  */
#line 964 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5427 "tools/widl/parser.tab.c"
    break;

  case 337: /* parameterized_type_arg: parameterized_type '*'  */
#line 965 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5433 "tools/widl/parser.tab.c"
    break;

  case 338: /* parameterized_type_args: parameterized_type_arg  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5439 "tools/widl/parser.tab.c"
    break;

  case 339: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 971 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5445 "tools/widl/parser.tab.c"
    break;

  case 340: /* coclass: tCOCLASS typename  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5451 "tools/widl/parser.tab.c"
    break;

  case 341: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 978 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5457 "tools/widl/parser.tab.c"
    break;

  case 342: /* runtimeclass: tRUNTIMECLASS typename  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5463 "tools/widl/parser.tab.c"
    break;

  case 343: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5469 "tools/widl/parser.tab.c"
    break;

  case 344: /* apicontract: tAPICONTRACT typename  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5475 "tools/widl/parser.tab.c"
    break;

  case 345: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5481 "tools/widl/parser.tab.c"
    break;

  case 346: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 5487 "tools/widl/parser.tab.c"
    break;

  case 347: /* namespacedef: namespacedef '.' aIDENTIFIER  */
#line 996 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 5493 "tools/widl/parser.tab.c"
    break;

  case 348: /* class_interfaces: %empty  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5499 "tools/widl/parser.tab.c"
    break;

  case 349: /* class_interfaces: class_interfaces class_interface  */
#line 1000 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5505 "tools/widl/parser.tab.c"
    break;

  case 350: /* class_interface: m_attributes interfaceref ';'  */
#line 1004 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5511 "tools/widl/parser.tab.c"
    break;

  case 351: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 1005 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5517 "tools/widl/parser.tab.c"
    break;

  case 352: /* dispinterface: tDISPINTERFACE typename  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5523 "tools/widl/parser.tab.c"
    break;

  case 353: /* dispattributes: attributes  */
#line 1011 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5529 "tools/widl/parser.tab.c"
    break;

  case 354: /* dispint_props: tPROPERTIES ':'  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5535 "tools/widl/parser.tab.c"
    break;

  case 355: /* dispint_props: dispint_props s_field ';'  */
#line 1015 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5541 "tools/widl/parser.tab.c"
    break;

  case 356: /* dispint_meths: tMETHODS ':'  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5547 "tools/widl/parser.tab.c"
    break;

  case 357: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5553 "tools/widl/parser.tab.c"
    break;

  case 358: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1024 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5559 "tools/widl/parser.tab.c"
    break;

  case 359: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5565 "tools/widl/parser.tab.c"
    break;

  case 360: /* inherit: %empty  */
#line 1029 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5571 "tools/widl/parser.tab.c"
    break;

  case 361: /* inherit: ':' qualified_type  */
#line 1030 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5577 "tools/widl/parser.tab.c"
    break;

  case 362: /* inherit: ':' parameterized_type  */
#line 1031 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5583 "tools/widl/parser.tab.c"
    break;

  case 363: /* type_parameter: typename  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5589 "tools/widl/parser.tab.c"
    break;

  case 364: /* type_parameters: type_parameter  */
#line 1038 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5595 "tools/widl/parser.tab.c"
    break;

  case 365: /* type_parameters: type_parameters ',' type_parameter  */
#line 1039 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5601 "tools/widl/parser.tab.c"
    break;

  case 366: /* interface: tINTERFACE typename  */
#line 1043 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5607 "tools/widl/parser.tab.c"
    break;

  case 367: /* $@3: %empty  */
#line 1044 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5613 "tools/widl/parser.tab.c"
    break;

  case 368: /* $@4: %empty  */
#line 1044 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5619 "tools/widl/parser.tab.c"
    break;

  case 369: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1045 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5625 "tools/widl/parser.tab.c"
    break;

  case 370: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						}
#line 5633 "tools/widl/parser.tab.c"
    break;

  case 371: /* $@5: %empty  */
#line 1053 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5639 "tools/widl/parser.tab.c"
    break;

  case 372: /* $@6: %empty  */
#line 1054 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5645 "tools/widl/parser.tab.c"
    break;

  case 373: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1055 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))));
						}
#line 5653 "tools/widl/parser.tab.c"
    break;

  case 374: /* required_types: qualified_type  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5659 "tools/widl/parser.tab.c"
    break;

  case 375: /* required_types: parameterized_type  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5665 "tools/widl/parser.tab.c"
    break;

  case 376: /* required_types: required_types ',' qualified_type  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5671 "tools/widl/parser.tab.c"
    break;

  case 377: /* required_types: required_types ',' parameterized_type  */
#line 1064 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5677 "tools/widl/parser.tab.c"
    break;

  case 378: /* requires: %empty  */
#line 1066 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5683 "tools/widl/parser.tab.c"
    break;

  case 379: /* requires: tREQUIRES required_types  */
#line 1067 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5689 "tools/widl/parser.tab.c"
    break;

  case 380: /* $@7: %empty  */
#line 1070 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5695 "tools/widl/parser.tab.c"
    break;

  case 381: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1072 "tools/widl/parser.y"
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
#line 5711 "tools/widl/parser.tab.c"
    break;

  case 382: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1083 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5717 "tools/widl/parser.tab.c"
    break;

  case 383: /* interfaceref: tINTERFACE typename  */
#line 1087 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5723 "tools/widl/parser.tab.c"
    break;

  case 384: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5729 "tools/widl/parser.tab.c"
    break;

  case 385: /* interfaceref: tINTERFACE parameterized_type  */
#line 1089 "tools/widl/parser.y"
                                                { if (type_get_type(((yyval.type) = (yyvsp[0].type))) != TYPE_INTERFACE) error_loc("%s is not an interface\n", (yyval.type)->name); }
#line 5735 "tools/widl/parser.tab.c"
    break;

  case 386: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1093 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5741 "tools/widl/parser.tab.c"
    break;

  case 387: /* module: tMODULE typename  */
#line 1096 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5747 "tools/widl/parser.tab.c"
    break;

  case 388: /* moduledef: m_attributes module '{' int_statements '}' semicolon_opt  */
#line 1100 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5753 "tools/widl/parser.tab.c"
    break;

  case 389: /* storage_cls_spec: tEXTERN  */
#line 1104 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5759 "tools/widl/parser.tab.c"
    break;

  case 390: /* storage_cls_spec: tSTATIC  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5765 "tools/widl/parser.tab.c"
    break;

  case 391: /* storage_cls_spec: tREGISTER  */
#line 1106 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5771 "tools/widl/parser.tab.c"
    break;

  case 392: /* function_specifier: tINLINE  */
#line 1110 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5777 "tools/widl/parser.tab.c"
    break;

  case 393: /* type_qualifier: tCONST  */
#line 1114 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5783 "tools/widl/parser.tab.c"
    break;

  case 394: /* m_type_qual_list: %empty  */
#line 1117 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5789 "tools/widl/parser.tab.c"
    break;

  case 395: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1118 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5795 "tools/widl/parser.tab.c"
    break;

  case 396: /* decl_spec: type m_decl_spec_no_type  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5801 "tools/widl/parser.tab.c"
    break;

  case 397: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5807 "tools/widl/parser.tab.c"
    break;

  case 398: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5813 "tools/widl/parser.tab.c"
    break;

  case 399: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1129 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5819 "tools/widl/parser.tab.c"
    break;

  case 400: /* m_decl_spec_no_type: %empty  */
#line 1132 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5825 "tools/widl/parser.tab.c"
    break;

  case 402: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5831 "tools/widl/parser.tab.c"
    break;

  case 403: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1138 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5837 "tools/widl/parser.tab.c"
    break;

  case 404: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5843 "tools/widl/parser.tab.c"
    break;

  case 405: /* declarator: '*' m_type_qual_list declarator  */
#line 1144 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5849 "tools/widl/parser.tab.c"
    break;

  case 406: /* declarator: callconv declarator  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5855 "tools/widl/parser.tab.c"
    break;

  case 408: /* direct_declarator: ident  */
#line 1150 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5861 "tools/widl/parser.tab.c"
    break;

  case 409: /* direct_declarator: '(' declarator ')'  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5867 "tools/widl/parser.tab.c"
    break;

  case 410: /* direct_declarator: direct_declarator array  */
#line 1152 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5873 "tools/widl/parser.tab.c"
    break;

  case 411: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5879 "tools/widl/parser.tab.c"
    break;

  case 412: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5885 "tools/widl/parser.tab.c"
    break;

  case 413: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5891 "tools/widl/parser.tab.c"
    break;

  case 415: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1167 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5897 "tools/widl/parser.tab.c"
    break;

  case 416: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1168 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5903 "tools/widl/parser.tab.c"
    break;

  case 417: /* m_abstract_declarator: %empty  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5909 "tools/widl/parser.tab.c"
    break;

  case 419: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5915 "tools/widl/parser.tab.c"
    break;

  case 420: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1179 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5921 "tools/widl/parser.tab.c"
    break;

  case 421: /* abstract_direct_declarator: array  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5927 "tools/widl/parser.tab.c"
    break;

  case 422: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5935 "tools/widl/parser.tab.c"
    break;

  case 423: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5943 "tools/widl/parser.tab.c"
    break;

  case 424: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1194 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5949 "tools/widl/parser.tab.c"
    break;

  case 425: /* any_declarator: callconv m_any_declarator  */
#line 1195 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5955 "tools/widl/parser.tab.c"
    break;

  case 427: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5961 "tools/widl/parser.tab.c"
    break;

  case 428: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1203 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5967 "tools/widl/parser.tab.c"
    break;

  case 429: /* m_any_declarator: %empty  */
#line 1207 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5973 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_direct_declarator: ident  */
#line 1215 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5979 "tools/widl/parser.tab.c"
    break;

  case 432: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1216 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5985 "tools/widl/parser.tab.c"
    break;

  case 433: /* any_direct_declarator: any_direct_declarator array  */
#line 1217 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5991 "tools/widl/parser.tab.c"
    break;

  case 434: /* any_direct_declarator: array  */
#line 1218 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5997 "tools/widl/parser.tab.c"
    break;

  case 435: /* any_direct_declarator: '(' m_args ')'  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6005 "tools/widl/parser.tab.c"
    break;

  case 436: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1224 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6013 "tools/widl/parser.tab.c"
    break;

  case 437: /* declarator_list: declarator  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6019 "tools/widl/parser.tab.c"
    break;

  case 438: /* declarator_list: declarator_list ',' declarator  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6025 "tools/widl/parser.tab.c"
    break;

  case 439: /* m_bitfield: %empty  */
#line 1234 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 6031 "tools/widl/parser.tab.c"
    break;

  case 440: /* m_bitfield: ':' expr_const  */
#line 1235 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 6037 "tools/widl/parser.tab.c"
    break;

  case 441: /* struct_declarator: any_declarator m_bitfield  */
#line 1238 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 6046 "tools/widl/parser.tab.c"
    break;

  case 442: /* struct_declarator_list: struct_declarator  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6052 "tools/widl/parser.tab.c"
    break;

  case 443: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1247 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6058 "tools/widl/parser.tab.c"
    break;

  case 444: /* init_declarator: declarator  */
#line 1251 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 6064 "tools/widl/parser.tab.c"
    break;

  case 445: /* init_declarator: declarator '=' expr_const  */
#line 1252 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 6070 "tools/widl/parser.tab.c"
    break;

  case 446: /* threading_type: tAPARTMENT  */
#line 1256 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 6076 "tools/widl/parser.tab.c"
    break;

  case 447: /* threading_type: tNEUTRAL  */
#line 1257 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6082 "tools/widl/parser.tab.c"
    break;

  case 448: /* threading_type: tSINGLE  */
#line 1258 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6088 "tools/widl/parser.tab.c"
    break;

  case 449: /* threading_type: tFREE  */
#line 1259 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6094 "tools/widl/parser.tab.c"
    break;

  case 450: /* threading_type: tBOTH  */
#line 1260 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6100 "tools/widl/parser.tab.c"
    break;

  case 451: /* threading_type: tMTA  */
#line 1261 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6106 "tools/widl/parser.tab.c"
    break;

  case 452: /* pointer_type: tREF  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6112 "tools/widl/parser.tab.c"
    break;

  case 453: /* pointer_type: tUNIQUE  */
#line 1266 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6118 "tools/widl/parser.tab.c"
    break;

  case 454: /* pointer_type: tPTR  */
#line 1267 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6124 "tools/widl/parser.tab.c"
    break;

  case 455: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1270 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6130 "tools/widl/parser.tab.c"
    break;

  case 456: /* unqualified_type: tVOID  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6136 "tools/widl/parser.tab.c"
    break;

  case 457: /* unqualified_type: base_type  */
#line 1275 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6142 "tools/widl/parser.tab.c"
    break;

  case 458: /* unqualified_type: enumdef  */
#line 1276 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6148 "tools/widl/parser.tab.c"
    break;

  case 459: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1277 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6154 "tools/widl/parser.tab.c"
    break;

  case 460: /* unqualified_type: structdef  */
#line 1278 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6160 "tools/widl/parser.tab.c"
    break;

  case 461: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6166 "tools/widl/parser.tab.c"
    break;

  case 462: /* unqualified_type: uniondef  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6172 "tools/widl/parser.tab.c"
    break;

  case 463: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1281 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6178 "tools/widl/parser.tab.c"
    break;

  case 464: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1282 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6184 "tools/widl/parser.tab.c"
    break;

  case 465: /* unqualified_type: aKNOWNTYPE  */
#line 1283 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6190 "tools/widl/parser.tab.c"
    break;

  case 467: /* type: namespace_pfx typename  */
#line 1288 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6196 "tools/widl/parser.tab.c"
    break;

  case 468: /* type: parameterized_type  */
#line 1289 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6202 "tools/widl/parser.tab.c"
    break;

  case 469: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1293 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6211 "tools/widl/parser.tab.c"
    break;

  case 470: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1300 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6217 "tools/widl/parser.tab.c"
    break;

  case 471: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1303 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6223 "tools/widl/parser.tab.c"
    break;

  case 472: /* version: aNUM  */
#line 1307 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6229 "tools/widl/parser.tab.c"
    break;

  case 473: /* version: aNUM '.' aNUM  */
#line 1308 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6235 "tools/widl/parser.tab.c"
    break;

  case 474: /* version: aHEXNUM  */
#line 1309 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6241 "tools/widl/parser.tab.c"
    break;

  case 479: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1324 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6249 "tools/widl/parser.tab.c"
    break;

  case 480: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1331 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6259 "tools/widl/parser.tab.c"
    break;

  case 481: /* acf_attributes: %empty  */
#line 1339 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6265 "tools/widl/parser.tab.c"
    break;

  case 482: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1340 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6271 "tools/widl/parser.tab.c"
    break;

  case 483: /* acf_attribute_list: acf_attribute  */
#line 1344 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6277 "tools/widl/parser.tab.c"
    break;

  case 484: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1345 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6283 "tools/widl/parser.tab.c"
    break;

  case 485: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1350 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 6289 "tools/widl/parser.tab.c"
    break;

  case 486: /* acf_attribute: tENCODE  */
#line 1351 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 6295 "tools/widl/parser.tab.c"
    break;

  case 487: /* acf_attribute: tDECODE  */
#line 1352 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 6301 "tools/widl/parser.tab.c"
    break;

  case 488: /* acf_attribute: tEXPLICITHANDLE  */
#line 1353 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 6307 "tools/widl/parser.tab.c"
    break;

  case 489: /* allocate_option_list: allocate_option  */
#line 1357 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6313 "tools/widl/parser.tab.c"
    break;

  case 490: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1359 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6319 "tools/widl/parser.tab.c"
    break;

  case 491: /* allocate_option: tDONTFREE  */
#line 1363 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6325 "tools/widl/parser.tab.c"
    break;

  case 492: /* allocate_option: tFREE  */
#line 1364 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6331 "tools/widl/parser.tab.c"
    break;

  case 493: /* allocate_option: tALLNODES  */
#line 1365 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6337 "tools/widl/parser.tab.c"
    break;

  case 494: /* allocate_option: tSINGLENODE  */
#line 1366 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6343 "tools/widl/parser.tab.c"
    break;


#line 6347 "tools/widl/parser.tab.c"

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
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = PARSER_EMPTY;
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != PARSER_EMPTY)
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

#line 1369 "tools/widl/parser.y"


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

attr_t *make_attrp(enum attr_type type, void *val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.pval = val;
  return a;
}

static attr_t *make_custom_attr(struct uuid *id, expr_t *pval)
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

static void push_namespaces(str_list_t *names)
{
  const struct str_list_entry_t *name;
  LIST_FOR_EACH_ENTRY(name, names, const struct str_list_entry_t, entry)
    push_namespace(name->str);
}

static void pop_namespaces(str_list_t *names)
{
  const struct str_list_entry_t *name;
  LIST_FOR_EACH_ENTRY_REV(name, names, const struct str_list_entry_t, entry)
    pop_namespace(name->str);
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
  {
    type->c_name = name;
    type->qualified_name = name;
  }
  else
  {
    type->c_name = format_namespace(namespace, "__x_", "_C", name, use_abi_namespace ? "ABI" : NULL);
    type->qualified_name = format_namespace(namespace, "", "::", name, use_abi_namespace ? "ABI" : NULL);
  }
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
    char *dst = replace_extension( get_basename(input_idl_name), ".idl", "" );
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
    /* ATTR_ACTIVATABLE */         { 0, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "activatable" },
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
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, "hidden" },
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
    /* ATTR_OVERLOAD */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "overload" },
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
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 1, 1, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
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
    case TYPE_DELEGATE:
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
                begin_args = append_var(begin_args, copy_var(arg, xstrdup(arg->name), arg_in_attrs));
            if (is_attr(arg->attrs, ATTR_OUT))
                finish_args = append_var(finish_args, copy_var(arg, xstrdup(arg->name), arg_out_attrs));
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

static statement_t *make_statement_delegate(type_t *ret, var_list_t *args)
{
    declarator_t *decl = make_declarator(make_var(xstrdup("Invoke")));
    decl_spec_t *spec = make_decl_spec(ret, NULL, NULL, STG_NONE, 0, 0);
    append_chain_type(decl, type_new_function(args), 0);
    return make_statement_declaration(declare_var(NULL, spec, decl, FALSE));
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
