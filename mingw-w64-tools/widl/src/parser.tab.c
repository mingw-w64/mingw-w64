/* A Bison parser, made by GNU Bison 3.6.2.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

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
#line 1 "parser.y"

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

static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs);
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

static typelib_t *current_typelib;


#line 207 "parser.tab.c"

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
    tAGGREGATABLE = 280,           /* tAGGREGATABLE  */
    tALLOCATE = 281,               /* tALLOCATE  */
    tANNOTATION = 282,             /* tANNOTATION  */
    tAPPOBJECT = 283,              /* tAPPOBJECT  */
    tASYNC = 284,                  /* tASYNC  */
    tASYNCUUID = 285,              /* tASYNCUUID  */
    tAUTOHANDLE = 286,             /* tAUTOHANDLE  */
    tBINDABLE = 287,               /* tBINDABLE  */
    tBOOLEAN = 288,                /* tBOOLEAN  */
    tBROADCAST = 289,              /* tBROADCAST  */
    tBYTE = 290,                   /* tBYTE  */
    tBYTECOUNT = 291,              /* tBYTECOUNT  */
    tCALLAS = 292,                 /* tCALLAS  */
    tCALLBACK = 293,               /* tCALLBACK  */
    tCASE = 294,                   /* tCASE  */
    tCDECL = 295,                  /* tCDECL  */
    tCHAR = 296,                   /* tCHAR  */
    tCOCLASS = 297,                /* tCOCLASS  */
    tCODE = 298,                   /* tCODE  */
    tCOMMSTATUS = 299,             /* tCOMMSTATUS  */
    tCONST = 300,                  /* tCONST  */
    tCONTEXTHANDLE = 301,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 302, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 303, /* tCONTEXTHANDLESERIALIZE  */
    tCONTROL = 304,                /* tCONTROL  */
    tCPPQUOTE = 305,               /* tCPPQUOTE  */
    tDECODE = 306,                 /* tDECODE  */
    tDEFAULT = 307,                /* tDEFAULT  */
    tDEFAULTBIND = 308,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 309,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 310,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 311,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 312, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 313,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 314,          /* tDISPINTERFACE  */
    tDLLNAME = 315,                /* tDLLNAME  */
    tDOUBLE = 316,                 /* tDOUBLE  */
    tDUAL = 317,                   /* tDUAL  */
    tENABLEALLOCATE = 318,         /* tENABLEALLOCATE  */
    tENCODE = 319,                 /* tENCODE  */
    tENDPOINT = 320,               /* tENDPOINT  */
    tENTRY = 321,                  /* tENTRY  */
    tENUM = 322,                   /* tENUM  */
    tERRORSTATUST = 323,           /* tERRORSTATUST  */
    tEXPLICITHANDLE = 324,         /* tEXPLICITHANDLE  */
    tEXTERN = 325,                 /* tEXTERN  */
    tFALSE = 326,                  /* tFALSE  */
    tFASTCALL = 327,               /* tFASTCALL  */
    tFAULTSTATUS = 328,            /* tFAULTSTATUS  */
    tFLOAT = 329,                  /* tFLOAT  */
    tFORCEALLOCATE = 330,          /* tFORCEALLOCATE  */
    tHANDLE = 331,                 /* tHANDLE  */
    tHANDLET = 332,                /* tHANDLET  */
    tHELPCONTEXT = 333,            /* tHELPCONTEXT  */
    tHELPFILE = 334,               /* tHELPFILE  */
    tHELPSTRING = 335,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 336,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 337,          /* tHELPSTRINGDLL  */
    tHIDDEN = 338,                 /* tHIDDEN  */
    tHYPER = 339,                  /* tHYPER  */
    tID = 340,                     /* tID  */
    tIDEMPOTENT = 341,             /* tIDEMPOTENT  */
    tIGNORE = 342,                 /* tIGNORE  */
    tIIDIS = 343,                  /* tIIDIS  */
    tIMMEDIATEBIND = 344,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 345,         /* tIMPLICITHANDLE  */
    tIMPORT = 346,                 /* tIMPORT  */
    tIMPORTLIB = 347,              /* tIMPORTLIB  */
    tIN = 348,                     /* tIN  */
    tIN_LINE = 349,                /* tIN_LINE  */
    tINLINE = 350,                 /* tINLINE  */
    tINPUTSYNC = 351,              /* tINPUTSYNC  */
    tINT = 352,                    /* tINT  */
    tINT32 = 353,                  /* tINT32  */
    tINT3264 = 354,                /* tINT3264  */
    tINT64 = 355,                  /* tINT64  */
    tINTERFACE = 356,              /* tINTERFACE  */
    tLCID = 357,                   /* tLCID  */
    tLENGTHIS = 358,               /* tLENGTHIS  */
    tLIBRARY = 359,                /* tLIBRARY  */
    tLICENSED = 360,               /* tLICENSED  */
    tLOCAL = 361,                  /* tLOCAL  */
    tLONG = 362,                   /* tLONG  */
    tMAYBE = 363,                  /* tMAYBE  */
    tMESSAGE = 364,                /* tMESSAGE  */
    tMETHODS = 365,                /* tMETHODS  */
    tMODULE = 366,                 /* tMODULE  */
    tNAMESPACE = 367,              /* tNAMESPACE  */
    tNOCODE = 368,                 /* tNOCODE  */
    tNONBROWSABLE = 369,           /* tNONBROWSABLE  */
    tNONCREATABLE = 370,           /* tNONCREATABLE  */
    tNONEXTENSIBLE = 371,          /* tNONEXTENSIBLE  */
    tNOTIFY = 372,                 /* tNOTIFY  */
    tNOTIFYFLAG = 373,             /* tNOTIFYFLAG  */
    tNULL = 374,                   /* tNULL  */
    tOBJECT = 375,                 /* tOBJECT  */
    tODL = 376,                    /* tODL  */
    tOLEAUTOMATION = 377,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 378,               /* tOPTIMIZE  */
    tOPTIONAL = 379,               /* tOPTIONAL  */
    tOUT = 380,                    /* tOUT  */
    tPARTIALIGNORE = 381,          /* tPARTIALIGNORE  */
    tPASCAL = 382,                 /* tPASCAL  */
    tPOINTERDEFAULT = 383,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 384,         /* tPRAGMA_WARNING  */
    tPROGID = 385,                 /* tPROGID  */
    tPROPERTIES = 386,             /* tPROPERTIES  */
    tPROPGET = 387,                /* tPROPGET  */
    tPROPPUT = 388,                /* tPROPPUT  */
    tPROPPUTREF = 389,             /* tPROPPUTREF  */
    tPROXY = 390,                  /* tPROXY  */
    tPTR = 391,                    /* tPTR  */
    tPUBLIC = 392,                 /* tPUBLIC  */
    tRANGE = 393,                  /* tRANGE  */
    tREADONLY = 394,               /* tREADONLY  */
    tREF = 395,                    /* tREF  */
    tREGISTER = 396,               /* tREGISTER  */
    tREPRESENTAS = 397,            /* tREPRESENTAS  */
    tREQUESTEDIT = 398,            /* tREQUESTEDIT  */
    tRESTRICTED = 399,             /* tRESTRICTED  */
    tRETVAL = 400,                 /* tRETVAL  */
    tSAFEARRAY = 401,              /* tSAFEARRAY  */
    tSHORT = 402,                  /* tSHORT  */
    tSIGNED = 403,                 /* tSIGNED  */
    tSIZEIS = 404,                 /* tSIZEIS  */
    tSIZEOF = 405,                 /* tSIZEOF  */
    tSMALL = 406,                  /* tSMALL  */
    tSOURCE = 407,                 /* tSOURCE  */
    tSTATIC = 408,                 /* tSTATIC  */
    tSTDCALL = 409,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 410,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 411,                 /* tSTRING  */
    tSTRUCT = 412,                 /* tSTRUCT  */
    tSWITCH = 413,                 /* tSWITCH  */
    tSWITCHIS = 414,               /* tSWITCHIS  */
    tSWITCHTYPE = 415,             /* tSWITCHTYPE  */
    tTHREADING = 416,              /* tTHREADING  */
    tTRANSMITAS = 417,             /* tTRANSMITAS  */
    tTRUE = 418,                   /* tTRUE  */
    tTYPEDEF = 419,                /* tTYPEDEF  */
    tUIDEFAULT = 420,              /* tUIDEFAULT  */
    tUNION = 421,                  /* tUNION  */
    tUNIQUE = 422,                 /* tUNIQUE  */
    tUNSIGNED = 423,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 424,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 425,            /* tUSERMARSHAL  */
    tUUID = 426,                   /* tUUID  */
    tV1ENUM = 427,                 /* tV1ENUM  */
    tVARARG = 428,                 /* tVARARG  */
    tVERSION = 429,                /* tVERSION  */
    tVIPROGID = 430,               /* tVIPROGID  */
    tVOID = 431,                   /* tVOID  */
    tWCHAR = 432,                  /* tWCHAR  */
    tWIREMARSHAL = 433,            /* tWIREMARSHAL  */
    tAPARTMENT = 434,              /* tAPARTMENT  */
    tNEUTRAL = 435,                /* tNEUTRAL  */
    tSINGLE = 436,                 /* tSINGLE  */
    tFREE = 437,                   /* tFREE  */
    tBOTH = 438,                   /* tBOTH  */
    CAST = 439,                    /* CAST  */
    PPTR = 440,                    /* PPTR  */
    POS = 441,                     /* POS  */
    NEG = 442,                     /* NEG  */
    ADDRESSOF = 443                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 129 "parser.y"

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

#line 471 "parser.tab.c"

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
  YYSYMBOL_tAGGREGATABLE = 25,             /* tAGGREGATABLE  */
  YYSYMBOL_tALLOCATE = 26,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 27,               /* tANNOTATION  */
  YYSYMBOL_tAPPOBJECT = 28,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 29,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 30,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 31,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 32,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 33,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 34,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 35,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 36,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 37,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 38,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tCDECL = 40,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 41,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 42,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 43,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 44,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 45,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 46,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 47, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 48,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTROL = 49,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 50,                 /* tCPPQUOTE  */
  YYSYMBOL_tDECODE = 51,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 52,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 53,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 54,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 55,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 56,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 57,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 58,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 59,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 60,                  /* tDLLNAME  */
  YYSYMBOL_tDOUBLE = 61,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 62,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 63,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 64,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 65,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 66,                    /* tENTRY  */
  YYSYMBOL_tENUM = 67,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 68,             /* tERRORSTATUST  */
  YYSYMBOL_tEXPLICITHANDLE = 69,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 70,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 71,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 72,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 73,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLOAT = 74,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 75,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 76,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 77,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 78,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 79,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 80,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 81,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 82,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 83,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 84,                    /* tHYPER  */
  YYSYMBOL_tID = 85,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 86,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 87,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 88,                    /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 89,            /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 90,           /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 91,                   /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 92,                /* tIMPORTLIB  */
  YYSYMBOL_tIN = 93,                       /* tIN  */
  YYSYMBOL_tIN_LINE = 94,                  /* tIN_LINE  */
  YYSYMBOL_tINLINE = 95,                   /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 96,                /* tINPUTSYNC  */
  YYSYMBOL_tINT = 97,                      /* tINT  */
  YYSYMBOL_tINT32 = 98,                    /* tINT32  */
  YYSYMBOL_tINT3264 = 99,                  /* tINT3264  */
  YYSYMBOL_tINT64 = 100,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 101,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 102,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 103,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 104,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 105,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 106,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 107,                    /* tLONG  */
  YYSYMBOL_tMAYBE = 108,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 109,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 110,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 111,                  /* tMODULE  */
  YYSYMBOL_tNAMESPACE = 112,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 113,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 114,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 115,            /* tNONCREATABLE  */
  YYSYMBOL_tNONEXTENSIBLE = 116,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 117,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 118,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 119,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 120,                  /* tOBJECT  */
  YYSYMBOL_tODL = 121,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 122,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 123,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 124,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 125,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 126,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 127,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 128,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 129,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 130,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 131,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 132,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 133,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 134,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 135,                   /* tPROXY  */
  YYSYMBOL_tPTR = 136,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 137,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 138,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 139,                /* tREADONLY  */
  YYSYMBOL_tREF = 140,                     /* tREF  */
  YYSYMBOL_tREGISTER = 141,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 142,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 143,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 144,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 145,                  /* tRETVAL  */
  YYSYMBOL_tSAFEARRAY = 146,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 147,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 148,                  /* tSIGNED  */
  YYSYMBOL_tSIZEIS = 149,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 150,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 151,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 152,                  /* tSOURCE  */
  YYSYMBOL_tSTATIC = 153,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 154,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 155,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 156,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 157,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 158,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 159,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 160,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 161,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 162,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 163,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 164,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 165,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 166,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 167,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 168,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 169,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 170,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 171,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 172,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 173,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 174,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 175,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 176,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 177,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 178,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 179,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 180,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 181,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 182,                    /* tFREE  */
  YYSYMBOL_tBOTH = 183,                    /* tBOTH  */
  YYSYMBOL_184_ = 184,                     /* ','  */
  YYSYMBOL_185_ = 185,                     /* '?'  */
  YYSYMBOL_186_ = 186,                     /* ':'  */
  YYSYMBOL_187_ = 187,                     /* '|'  */
  YYSYMBOL_188_ = 188,                     /* '^'  */
  YYSYMBOL_189_ = 189,                     /* '&'  */
  YYSYMBOL_190_ = 190,                     /* '<'  */
  YYSYMBOL_191_ = 191,                     /* '>'  */
  YYSYMBOL_192_ = 192,                     /* '-'  */
  YYSYMBOL_193_ = 193,                     /* '+'  */
  YYSYMBOL_194_ = 194,                     /* '*'  */
  YYSYMBOL_195_ = 195,                     /* '/'  */
  YYSYMBOL_196_ = 196,                     /* '%'  */
  YYSYMBOL_197_ = 197,                     /* '!'  */
  YYSYMBOL_198_ = 198,                     /* '~'  */
  YYSYMBOL_CAST = 199,                     /* CAST  */
  YYSYMBOL_PPTR = 200,                     /* PPTR  */
  YYSYMBOL_POS = 201,                      /* POS  */
  YYSYMBOL_NEG = 202,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 203,                /* ADDRESSOF  */
  YYSYMBOL_204_ = 204,                     /* '.'  */
  YYSYMBOL_205_ = 205,                     /* '['  */
  YYSYMBOL_206_ = 206,                     /* ']'  */
  YYSYMBOL_207_ = 207,                     /* '{'  */
  YYSYMBOL_208_ = 208,                     /* '}'  */
  YYSYMBOL_209_ = 209,                     /* ';'  */
  YYSYMBOL_210_ = 210,                     /* '('  */
  YYSYMBOL_211_ = 211,                     /* ')'  */
  YYSYMBOL_212_ = 212,                     /* '='  */
  YYSYMBOL_YYACCEPT = 213,                 /* $accept  */
  YYSYMBOL_input = 214,                    /* input  */
  YYSYMBOL_m_acf = 215,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 216,           /* gbl_statements  */
  YYSYMBOL_217_1 = 217,                    /* $@1  */
  YYSYMBOL_imp_statements = 218,           /* imp_statements  */
  YYSYMBOL_219_2 = 219,                    /* $@2  */
  YYSYMBOL_int_statements = 220,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 221,            /* semicolon_opt  */
  YYSYMBOL_statement = 222,                /* statement  */
  YYSYMBOL_pragma_warning = 223,           /* pragma_warning  */
  YYSYMBOL_warnings = 224,                 /* warnings  */
  YYSYMBOL_typedecl = 225,                 /* typedecl  */
  YYSYMBOL_cppquote = 226,                 /* cppquote  */
  YYSYMBOL_import_start = 227,             /* import_start  */
  YYSYMBOL_import = 228,                   /* import  */
  YYSYMBOL_importlib = 229,                /* importlib  */
  YYSYMBOL_libraryhdr = 230,               /* libraryhdr  */
  YYSYMBOL_library_start = 231,            /* library_start  */
  YYSYMBOL_librarydef = 232,               /* librarydef  */
  YYSYMBOL_m_args = 233,                   /* m_args  */
  YYSYMBOL_arg_list = 234,                 /* arg_list  */
  YYSYMBOL_args = 235,                     /* args  */
  YYSYMBOL_arg = 236,                      /* arg  */
  YYSYMBOL_array = 237,                    /* array  */
  YYSYMBOL_m_attributes = 238,             /* m_attributes  */
  YYSYMBOL_attributes = 239,               /* attributes  */
  YYSYMBOL_attrib_list = 240,              /* attrib_list  */
  YYSYMBOL_str_list = 241,                 /* str_list  */
  YYSYMBOL_attribute = 242,                /* attribute  */
  YYSYMBOL_uuid_string = 243,              /* uuid_string  */
  YYSYMBOL_callconv = 244,                 /* callconv  */
  YYSYMBOL_cases = 245,                    /* cases  */
  YYSYMBOL_case = 246,                     /* case  */
  YYSYMBOL_enums = 247,                    /* enums  */
  YYSYMBOL_enum_list = 248,                /* enum_list  */
  YYSYMBOL_enum = 249,                     /* enum  */
  YYSYMBOL_enumdef = 250,                  /* enumdef  */
  YYSYMBOL_m_exprs = 251,                  /* m_exprs  */
  YYSYMBOL_m_expr = 252,                   /* m_expr  */
  YYSYMBOL_expr = 253,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 254,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 255,           /* expr_int_const  */
  YYSYMBOL_expr_const = 256,               /* expr_const  */
  YYSYMBOL_fields = 257,                   /* fields  */
  YYSYMBOL_field = 258,                    /* field  */
  YYSYMBOL_ne_union_field = 259,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 260,          /* ne_union_fields  */
  YYSYMBOL_union_field = 261,              /* union_field  */
  YYSYMBOL_s_field = 262,                  /* s_field  */
  YYSYMBOL_funcdef = 263,                  /* funcdef  */
  YYSYMBOL_declaration = 264,              /* declaration  */
  YYSYMBOL_m_ident = 265,                  /* m_ident  */
  YYSYMBOL_t_ident = 266,                  /* t_ident  */
  YYSYMBOL_ident = 267,                    /* ident  */
  YYSYMBOL_base_type = 268,                /* base_type  */
  YYSYMBOL_m_int = 269,                    /* m_int  */
  YYSYMBOL_int_std = 270,                  /* int_std  */
  YYSYMBOL_coclass = 271,                  /* coclass  */
  YYSYMBOL_coclasshdr = 272,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 273,               /* coclassdef  */
  YYSYMBOL_namespacedef = 274,             /* namespacedef  */
  YYSYMBOL_coclass_ints = 275,             /* coclass_ints  */
  YYSYMBOL_coclass_int = 276,              /* coclass_int  */
  YYSYMBOL_dispinterface = 277,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 278,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 279,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 280,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 281,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 282,                  /* inherit  */
  YYSYMBOL_interface = 283,                /* interface  */
  YYSYMBOL_interfacehdr = 284,             /* interfacehdr  */
  YYSYMBOL_interfacedef = 285,             /* interfacedef  */
  YYSYMBOL_interfacedec = 286,             /* interfacedec  */
  YYSYMBOL_module = 287,                   /* module  */
  YYSYMBOL_modulehdr = 288,                /* modulehdr  */
  YYSYMBOL_moduledef = 289,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 290,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 291,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 292,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 293,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 294,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 295,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 296,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 297,               /* declarator  */
  YYSYMBOL_direct_declarator = 298,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 299,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 300, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 301,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 302, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 303,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 304, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 305,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 306,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 307,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 308,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 309,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 310,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 311,          /* init_declarator  */
  YYSYMBOL_threading_type = 312,           /* threading_type  */
  YYSYMBOL_pointer_type = 313,             /* pointer_type  */
  YYSYMBOL_structdef = 314,                /* structdef  */
  YYSYMBOL_type = 315,                     /* type  */
  YYSYMBOL_typedef = 316,                  /* typedef  */
  YYSYMBOL_uniondef = 317,                 /* uniondef  */
  YYSYMBOL_version = 318,                  /* version  */
  YYSYMBOL_acf_statements = 319,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 320,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 321,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 322,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 323,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 324,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 325             /* acf_attribute  */
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
#define YYLAST   3047

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  213
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  410
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  718

#define YYMAXUTOK   443


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
       2,     2,     2,   197,     2,     2,     2,   196,   189,     2,
     210,   211,   194,   193,   184,   192,   204,   195,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   186,   209,
     190,   212,   191,   185,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   205,     2,   206,   188,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   207,   187,   208,   198,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   199,
     200,   201,   202,   203
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   315,   315,   329,   329,   331,   332,   332,   334,   335,
     336,   339,   342,   343,   344,   347,   348,   349,   349,   351,
     352,   353,   356,   357,   358,   359,   362,   363,   366,   367,
     371,   372,   373,   374,   375,   376,   377,   380,   391,   392,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   407,
     409,   417,   423,   427,   428,   430,   434,   438,   439,   442,
     443,   446,   447,   451,   456,   463,   467,   468,   471,   472,
     476,   479,   480,   481,   484,   485,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   594,   595,   600,   601,
     602,   603,   606,   607,   610,   614,   620,   621,   622,   625,
     629,   641,   645,   650,   653,   654,   657,   658,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   700,   702,   703,   706,
     707,   710,   716,   722,   723,   726,   731,   738,   739,   742,
     743,   747,   748,   751,   755,   761,   769,   773,   778,   779,
     782,   783,   784,   787,   789,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   805,   806,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   820,   821,   829,
     835,   839,   842,   843,   847,   850,   851,   854,   863,   864,
     867,   868,   871,   877,   883,   884,   887,   888,   891,   898,
     907,   912,   916,   917,   920,   921,   924,   929,   936,   937,
     938,   942,   946,   949,   950,   953,   954,   958,   959,   963,
     964,   965,   969,   971,   972,   976,   977,   978,   979,   984,
     986,   987,   992,   994,   998,   999,  1004,  1005,  1006,  1007,
    1011,  1019,  1021,  1022,  1027,  1029,  1033,  1034,  1041,  1042,
    1043,  1044,  1045,  1049,  1056,  1057,  1060,  1061,  1064,  1071,
    1072,  1077,  1078,  1082,  1083,  1084,  1085,  1086,  1090,  1091,
    1092,  1095,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1110,  1117,  1119,  1125,  1126,  1127,  1131,  1132,
    1135,  1136,  1139,  1144,  1152,  1153,  1156,  1157,  1160,  1161,
    1162
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
  "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tAGGREGATABLE", "tALLOCATE",
  "tANNOTATION", "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE",
  "tBINDABLE", "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS",
  "tCALLBACK", "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE",
  "tCOMMSTATUS", "tCONST", "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE",
  "tCONTEXTHANDLESERIALIZE", "tCONTROL", "tCPPQUOTE", "tDECODE",
  "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM", "tDEFAULTVALUE",
  "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND",
  "tDISPINTERFACE", "tDLLNAME", "tDOUBLE", "tDUAL", "tENABLEALLOCATE",
  "tENCODE", "tENDPOINT", "tENTRY", "tENUM", "tERRORSTATUST",
  "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL", "tFAULTSTATUS",
  "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET", "tHELPCONTEXT",
  "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL",
  "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE", "tIIDIS",
  "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB", "tIN",
  "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT", "tODL",
  "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tPARTIALIGNORE",
  "tPASCAL", "tPOINTERDEFAULT", "tPRAGMA_WARNING", "tPROGID",
  "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF", "tPROXY", "tPTR",
  "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER", "tREPRESENTAS",
  "tREQUESTEDIT", "tRESTRICTED", "tRETVAL", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTATIC",
  "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT", "tSWITCH",
  "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS", "tTRUE",
  "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
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
  "attribute", "uuid_string", "callconv", "cases", "case", "enums",
  "enum_list", "enum", "enumdef", "m_exprs", "m_expr", "expr",
  "expr_list_int_const", "expr_int_const", "expr_const", "fields", "field",
  "ne_union_field", "ne_union_fields", "union_field", "s_field", "funcdef",
  "declaration", "m_ident", "t_ident", "ident", "base_type", "m_int",
  "int_std", "coclass", "coclasshdr", "coclassdef", "namespacedef",
  "coclass_ints", "coclass_int", "dispinterface", "dispinterfacehdr",
  "dispint_props", "dispint_meths", "dispinterfacedef", "inherit",
  "interface", "interfacehdr", "interfacedef", "interfacedec", "module",
  "modulehdr", "moduledef", "storage_cls_spec", "function_specifier",
  "type_qualifier", "m_type_qual_list", "decl_spec", "m_decl_spec_no_type",
  "decl_spec_no_type", "declarator", "direct_declarator",
  "abstract_declarator", "abstract_declarator_no_direct",
  "m_abstract_declarator", "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version",
  "acf_statements", "acf_int_statements", "acf_int_statement",
  "acf_interface", "acf_attributes", "acf_attribute_list", "acf_attribute", YY_NULLPTR
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
     435,   436,   437,   438,    44,    63,    58,   124,    94,    38,
      60,    62,    45,    43,    42,    47,    37,    33,   126,   439,
     440,   441,   442,   443,    46,    91,    93,   123,   125,    59,
      40,    41,    61
};
#endif

#define YYPACT_NINF (-560)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-405)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -560,    94,  1606,  -560,  -560,  -560,   -57,  -560,  -560,  -560,
     147,  -560,   -89,   165,  -560,   169,  -560,  -560,  -560,  -560,
      35,   149,  -560,  -560,  -560,  -560,  -560,   172,    35,   164,
     -34,  -560,   -29,    35,   333,  -560,  -560,   192,   197,   333,
    -560,  -560,  2869,  -560,  -560,  -560,   -27,  -560,  -560,  -560,
    -560,  -560,    21,  2567,   -13,   -10,  -560,  -560,     9,   -36,
    -560,     2,    12,    38,    23,    46,    41,  -560,  -560,    57,
    -560,   128,   128,   128,   175,  2716,    76,   128,    81,    88,
      61,  -560,   -57,   219,  -560,  -560,   315,  -560,  -560,    15,
    -560,   121,  -560,  -560,   123,  -560,  -560,  -560,  -560,   331,
    2716,  -560,  -560,    58,   129,   -94,  -112,  -560,  -560,   130,
    -560,  -560,   131,  -560,  -560,  -560,   132,   134,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   138,  -560,
    -560,  -560,   140,  -560,  -560,  -560,   141,   146,  -560,  -560,
    -560,  -560,   150,   151,   153,   157,   158,  -560,   160,  -560,
    -560,   161,  -560,   163,  -560,  -560,   166,   167,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   168,  -560,  -560,  -560,   170,   171,  -560,  -560,  -560,
    -560,  -560,  -560,   174,  -560,  -560,   185,  -560,  -560,  -560,
     187,  -560,  -560,  -560,   188,   189,   190,   191,  -560,  -560,
    -560,   195,   196,  -560,  -560,   206,   209,   211,  -132,  -560,
    -560,  -560,  1736,   851,   133,   267,   270,   273,   283,   286,
     220,   148,  -560,  -560,  -560,  -560,   175,   173,   216,  -560,
    -560,  -560,  -560,  -560,   -42,  -560,  -560,  -560,   290,   222,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,   175,   175,  -560,   127,  -101,  -560,  -560,  -560,
     128,  -560,  -560,  -560,  -560,  -560,  -560,  -119,  -560,  -560,
     374,   215,   291,  -560,   249,   225,  -560,   227,  -560,   429,
      84,   291,   710,   710,   430,   432,   710,   710,   435,   458,
     710,   461,   710,   710,  2097,   710,   710,   463,   -68,   464,
     710,  2716,   710,   710,  2716,   -38,  2716,  2716,    84,   324,
     466,  2716,  2869,   271,  -560,   268,  -560,  -560,  -560,   272,
    -560,   278,  -560,  -560,  -560,    23,  2612,  -560,   279,  -560,
    -560,  -560,  -560,   279,   -91,  -560,  -560,  -122,  -560,   293,
     -65,   280,   284,  -560,  -560,  1193,    52,   266,  -560,   710,
     542,  2097,  -560,  -560,    61,  -560,   285,  -560,   282,   303,
    -560,   281,   488,  -560,   -49,   133,   -39,   294,  -560,  -560,
     295,   296,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   305,  -560,   710,   710,   710,   710,   710,   710,   596,
    2299,  -135,  -560,  2299,   306,   307,  -560,  -111,   308,   309,
     314,   316,   317,   323,   326,   371,   327,  2612,    77,   328,
    -106,  -560,  2299,   329,   330,   332,   311,   335,  -100,  1397,
     343,  -560,  -560,  -560,  -560,  -560,   344,   346,   359,   360,
     292,  -560,   361,   362,   367,  -560,  2869,   492,  -560,  -560,
    -560,   175,    23,   -11,  -560,  1089,  -560,   340,  2612,   370,
    1476,   334,   413,  1297,    23,  -560,  2612,  -560,  -560,  -560,
    -560,   611,  -560,  2190,   377,   402,  -560,  -560,  -560,   380,
    -560,   291,   710,  -560,    18,  -560,  2612,  -560,   378,  -560,
     384,  -560,   389,  -560,  -560,  -560,  2612,    36,    36,    36,
      36,    36,    36,  2102,   496,   710,   710,   597,   710,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,   710,   710,   710,   710,   605,   710,   710,  -560,  -560,
    -560,   600,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,    77,  -560,  1833,  -560,    77,  -560,  -560,  -560,
     -87,  -560,   710,  -560,  -560,  -560,  -560,   710,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,   604,  -560,  -560,  -560,
    -560,   400,  -560,  -560,   428,  -560,  -560,  -560,  -560,   175,
     116,  -560,  -560,  2612,   407,  -560,  -560,  -560,    23,  -560,
    -560,  -560,  -560,  2009,   419,   417,   380,  -560,  -560,  -560,
    -560,    77,   418,   291,  -560,  -560,   496,  -560,  -560,  1921,
    -560,   496,  -560,   415,   -74,   318,   318,  -560,   575,   575,
     482,   482,  2318,  2337,  2260,  2372,  2394,   218,   482,   482,
      54,    54,    36,    36,    36,  -560,  2212,  -560,  -560,  -560,
      74,  -560,   421,    77,   422,  -560,  2097,  -560,  -560,   424,
    -560,    23,   970,   175,  -560,  -560,  1401,  -560,  -560,  -560,
     623,  -560,  -560,   444,  -560,  -103,  -560,   431,  -560,   425,
     375,  -560,   434,    77,   437,  -560,   710,  2097,  -560,   710,
    -560,  -560,    74,  -560,  -560,  -560,   440,  -560,  -560,  -560,
    -560,    23,   433,   710,  -560,    77,  -560,  -560,  -560,  -560,
      74,  -560,  -560,  -560,    36,   441,  2299,  -560,  -560,  -560,
    -560,  -560,  -560,    -1,  -560,  -560,   710,   453,  -560,  -560,
     468,   -58,   -58,  -560,  -560,   447,  -560,  -560
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    35,   383,   398,   273,   265,   284,
       0,   322,     0,     0,   272,   260,   274,   318,   271,   275,
     276,     0,   321,   278,   285,   286,   283,     0,   276,     0,
       0,   320,     0,   276,     0,   280,   319,   260,   260,   270,
     382,   266,    76,     2,    14,    36,     0,    30,    15,    33,
      15,    13,     0,    69,   385,     0,   384,   267,     0,     0,
      11,     0,     0,     0,    28,     0,   304,     9,     8,     0,
      12,   327,   327,   327,     0,     0,   387,   327,     0,   389,
       0,     4,   398,     0,   287,   288,     0,   295,   296,   386,
     262,     0,   277,   282,     0,   306,   307,   281,   291,     0,
       0,   279,   268,   388,     0,   390,     0,   269,    77,     0,
      79,    80,     0,    81,    82,    83,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   115,     0,   117,
     118,     0,   120,     0,   122,   123,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   141,   142,   143,     0,     0,   146,   147,   148,
     149,   380,   150,     0,   152,   378,     0,   154,   155,   156,
       0,   158,   159,   160,     0,     0,     0,     0,   165,   379,
     166,     0,     0,   170,   171,     0,     0,     0,     0,    71,
     175,    31,    68,    68,    68,   260,     0,     0,   260,   260,
       0,   385,   289,   297,   308,   316,     0,   387,   389,    32,
      10,   292,     6,   313,     0,    29,   311,   312,     0,     0,
      26,   331,   328,   330,   329,   263,   264,   178,   179,   180,
     181,   323,     0,     0,   335,   371,   334,   257,   385,   387,
     327,   389,   325,    34,   409,   408,   410,     0,   406,   399,
       0,     0,   186,    50,     0,     0,   243,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    70,    51,     0,    23,    24,    25,     0,
      21,     0,    19,    16,    22,    28,     0,    69,   386,    53,
      54,   314,   315,   388,   390,    55,   256,    68,     5,     0,
      68,     0,     0,   305,    26,    68,     0,     0,   333,     0,
       0,    57,   337,   326,     0,   405,     0,    49,     0,   188,
     189,   192,     0,   391,    68,    68,    68,     0,   177,   176,
       0,     0,   207,   198,   199,   200,   204,   205,   206,   201,
     202,     0,   203,     0,     0,     0,     0,     0,     0,     0,
     241,     0,   239,   242,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     0,
       0,   194,   197,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,     0,     0,     0,     0,
     395,   397,     0,     0,     0,    72,    76,     0,    20,    17,
      56,     0,    28,     0,   293,    68,   298,     0,     0,     0,
       0,     0,     0,    68,    28,    27,    69,   324,   332,   336,
     372,     0,    67,     0,     0,    61,    58,    59,   407,   400,
     193,   187,     0,    38,     0,   381,     0,   244,     0,   393,
      69,   250,     0,    78,   169,    84,     0,   231,   230,   229,
     232,   227,   228,     0,   344,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    96,
     100,     0,   104,   105,   110,   111,   112,   113,   114,   116,
     119,   121,   356,   323,    57,   361,   356,   358,   357,    64,
     353,   125,   196,   124,   140,   144,   145,     0,   153,   157,
     161,   162,   164,   163,   167,   168,     0,   172,   173,   174,
      73,     0,    15,   364,   392,   290,   294,     7,   300,     0,
     387,   299,   302,     0,     0,   255,   303,    26,    28,   317,
      66,    65,   338,     0,   404,     0,   400,   190,   191,    39,
      37,     0,   389,   258,   248,   247,   344,   238,   323,    57,
     348,   344,   345,     0,   341,   220,   221,   233,   214,   215,
     218,   219,   209,   210,     0,   211,   212,   213,   217,   216,
     223,   222,   225,   226,   224,   234,     0,   240,    75,    63,
     356,   323,     0,   356,     0,   352,    57,   360,   195,     0,
     396,    28,    68,     0,   253,   301,    68,   309,    62,    60,
       0,   403,   401,   366,   369,     0,   246,     0,   259,     0,
     344,   323,     0,   356,     0,   340,     0,    57,   347,     0,
     237,   351,   356,   362,   355,   359,     0,   151,    52,    18,
     365,    28,     0,     0,   368,     0,   245,   182,   236,   339,
     356,   349,   343,   346,   235,     0,   208,   354,   363,   310,
     402,   367,   370,     0,   342,   350,     0,     0,   394,   183,
       0,    68,    68,   252,   185,     0,   184,   251
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -560,  -560,  -560,   320,  -560,   -46,  -560,  -317,  -315,     0,
    -560,  -560,  -560,  -560,  -560,   208,  -560,  -560,  -560,    10,
    -514,  -560,  -560,  -261,  -242,  -203,    -2,  -560,  -560,  -272,
     354,   -66,  -560,  -560,  -560,  -560,   198,    13,   366,   137,
    -195,  -560,  -264,  -280,  -560,  -560,  -560,  -560,   -41,  -237,
    -560,   233,  -560,    25,   -69,  -560,    42,    99,     5,  -560,
      11,    17,  -560,  -560,   619,  -560,  -560,  -560,  -560,  -560,
     -18,  -560,    19,    16,  -560,  -560,    20,  -560,  -560,  -307,
    -496,   -52,   -43,   -30,  -236,  -560,  -560,  -560,  -540,  -560,
    -559,  -560,    51,  -560,  -560,  -560,     3,  -560,   459,  -560,
     391,     1,   -50,  -560,     7,  -560,   615,   112,  -560,  -560,
     115,  -560,   348
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    43,     2,   338,   212,   562,   345,   236,   316,
      45,   474,    46,    47,    48,    49,   317,   220,    50,   318,
     464,   465,   466,   467,   535,    52,   327,   208,   397,   209,
     370,   536,   703,   709,   358,   359,   360,   258,   410,   411,
     390,   391,   392,   394,   364,   477,   481,   366,   714,   715,
     574,    55,   657,    91,   537,    56,    93,    57,   319,    59,
     320,   321,   337,   444,    62,    63,   340,   450,    64,   239,
      65,    66,   322,   323,   225,    69,   324,    71,    72,    73,
     346,    74,   241,    75,   255,   256,   602,   664,   603,   604,
     538,   634,   539,   540,   564,   684,   654,   655,   257,   426,
     210,   259,    77,    78,   261,   432,    81,   585,   586,    82,
      83,   267,   268
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   226,    44,    76,   213,   254,   398,    58,   253,    79,
     440,   326,    51,    60,   352,    54,   347,   348,    68,    61,
     632,    67,    70,   399,   589,   260,   402,   453,   404,   243,
     244,   409,   653,   406,   262,   224,   416,   630,   706,   457,
     435,   242,   242,   242,  -404,   447,   277,   242,    13,   517,
     275,   707,   312,   497,   227,   245,   659,   246,   222,    27,
     228,   665,   104,   106,  -261,   354,   221,  -261,   181,   460,
      97,   497,   185,   521,   313,   101,   518,   245,   542,   246,
     245,   685,   246,    42,   542,   662,   442,   355,   393,   339,
      27,   393,   247,   368,     3,   278,   369,    11,   405,   199,
     522,   412,   660,   449,   350,   543,   686,   412,   419,   351,
     458,   549,   264,  -261,   247,   -45,  -261,   247,   350,    11,
     689,    86,   676,   636,   248,   265,   653,   565,   478,   482,
     266,   350,    92,   102,   443,   672,   667,   448,   107,   579,
      42,   421,   422,   423,   424,   425,   248,    42,    80,   248,
      84,   713,    85,   695,   393,   463,    42,   254,    94,   475,
     253,   476,   448,   448,   560,   690,    42,    98,    87,   479,
      88,   231,    89,    11,    90,    95,    99,    96,   245,   249,
     246,   100,   211,   254,   254,   214,   253,   253,   487,   488,
     489,   490,   491,   492,   493,   103,   -40,    90,    17,   229,
     105,   249,    90,   361,   249,   563,   250,   708,   588,   232,
      53,    53,   371,    76,    76,   247,   341,   353,   230,    79,
      79,   233,  -261,    22,   -41,    54,    54,   238,   250,   590,
     242,   250,   235,   495,   496,   497,   498,   499,   500,   501,
     515,   516,   408,   104,   106,   234,   251,   248,   512,   513,
     514,   417,   600,   627,   420,   237,   427,   428,   515,   516,
     646,   434,   252,   647,   240,  -261,   490,   -43,   533,    31,
     328,   533,    90,   329,   441,   330,   331,   254,   332,   350,
     253,    36,   350,   639,   534,   -42,   333,   534,    90,   334,
     263,    90,   407,   342,   245,   343,   246,   -44,   637,   408,
     605,   606,   249,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     270,   626,   649,   457,   271,  -254,   678,  -254,   272,   250,
     430,   431,   273,   644,   274,   497,   276,   494,    42,   349,
     279,   280,   281,   456,   282,   455,    76,   412,   283,   407,
     284,   285,    79,   457,   600,   532,   286,   -46,    54,   600,
     287,   288,   668,   289,   480,   457,   699,   290,   291,   251,
     292,   293,   254,   294,     9,   253,   295,   296,   297,   356,
     298,   299,   -47,   457,   300,   252,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   301,   569,   302,   303,   304,
     305,   306,   361,   701,   226,   307,   308,   680,   508,   509,
     510,   511,   512,   513,   514,   247,   309,    20,   600,   310,
      11,   311,   515,   516,   591,   -48,   357,   335,   601,   344,
      23,    24,    25,    26,   596,   362,   363,   365,   367,   395,
      28,   396,   710,    53,   400,    44,    76,   248,   573,   570,
      58,   456,    79,   455,    76,    51,    60,   227,    54,   566,
      79,    68,    61,   228,    67,    70,    54,   401,   633,   221,
     403,   694,   413,   415,   696,   433,   436,   459,   437,   446,
      33,   438,   408,   592,    35,   439,  -261,   471,   393,   451,
     470,   452,   469,   472,   473,   547,   556,   495,   496,   497,
     254,   561,   249,   253,    21,   483,   484,   485,   448,   448,
     510,   511,   512,   513,   514,   486,   642,   519,   520,   523,
     524,   226,   515,   516,   658,   525,   568,   526,   527,   250,
     601,   408,   407,   663,   528,   601,   247,   529,   531,   541,
     544,   545,   576,   546,   584,   372,   548,   408,   373,   374,
     375,   376,   377,   378,   551,   552,   504,   553,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   248,   598,
     554,   555,   557,   558,   254,   515,   516,   253,   559,   571,
     350,   407,   530,   629,   408,   599,   583,   635,   582,   593,
     495,   496,   497,   594,   601,   500,   501,   407,   595,   372,
     607,     5,   373,   374,   375,   376,   377,   378,   625,   628,
     640,   641,   643,   379,   372,   408,   645,   373,   374,   375,
     376,   377,   378,   249,    80,   651,   666,   656,   682,     7,
     683,     8,   673,   675,   407,   677,   688,     9,   687,   711,
      53,    11,   700,    76,   456,   691,   455,    76,   693,    79,
     250,   698,   705,    79,   712,    54,   717,    14,   445,    54,
     577,   380,   429,   215,    16,   407,    17,   379,   418,   587,
      18,   716,   223,    19,   510,   511,   512,   513,   514,   638,
      20,   671,   379,   575,   674,   336,   515,   516,   702,   414,
     598,    22,   381,    23,    24,    25,    26,   269,   652,   650,
       0,   350,   468,    28,     0,   382,   599,     0,     0,     0,
       0,     0,     0,   372,   692,   380,   373,   374,   375,   376,
     377,   378,     0,   697,     0,     0,     0,     0,     0,     0,
     380,   383,     0,     0,   384,   385,   461,    31,     0,   387,
     388,   704,    32,    33,    34,     0,   381,    35,   462,    36,
       0,     0,   389,   218,     0,     0,     0,     0,     0,   382,
       0,   381,   219,     0,    39,   508,   509,   510,   511,   512,
     513,   514,    40,    41,   382,     0,     0,     0,     0,   515,
     516,   379,     0,     0,     0,   383,     0,     0,   384,   385,
     386,     0,     0,   387,   388,     0,     0,     0,     0,     0,
     383,     0,     0,   384,   385,   386,   389,     0,   387,   388,
       0,     0,     0,     0,     0,     0,     0,   580,     0,     0,
       0,   389,     0,     0,     0,     0,     0,     0,     0,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     9,    10,     0,     0,    11,     0,     0,   383,
       0,    12,   384,   385,   386,     0,     0,   387,   388,     0,
      13,     0,    14,     0,     0,     0,     0,     0,    15,    16,
     389,    17,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,   315,     0,     0,    22,     0,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
       0,     0,    35,     7,    36,     8,     0,     0,    37,     0,
       0,     9,    10,     0,     0,    11,     0,    38,     0,    39,
      12,     0,     0,     0,     0,     0,     0,    40,    41,    13,
       0,    14,     0,     0,     0,     0,     0,    15,    16,     0,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    20,     0,    42,     0,     0,   325,
       0,    21,   315,     0,     0,    22,     0,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,    32,    33,    34,     0,
       0,    35,     7,    36,     8,     0,     0,    37,     0,     0,
       9,    10,     0,     0,    11,     0,    38,     0,    39,    12,
       0,     0,     0,     0,     0,     0,    40,    41,    13,     0,
      14,     0,     0,     0,     0,     0,    15,    16,     0,    17,
       0,     0,     0,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    20,     0,    42,     0,     0,   679,     0,
      21,     0,     0,     0,    22,     0,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,    28,     4,     5,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     8,     0,
      31,     0,     0,     0,     9,    32,    33,    34,    11,     0,
      35,     0,    36,    12,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    14,    38,     0,    39,     0,     0,
      15,    16,     0,    17,     0,    40,    41,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,     0,
      23,    24,    25,    26,    42,     0,     0,   567,     0,     0,
      28,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     8,     0,    31,     0,     0,     0,     9,    32,
      33,    34,    11,     0,    35,     0,    36,    12,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,    14,    38,
       0,    39,     0,     0,    15,    16,     0,    17,     0,    40,
      41,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,    24,    25,    26,    42,     0,
       0,   454,     0,     0,    28,     4,     5,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,   501,   502,
     503,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,    31,     0,
       0,     0,     9,    32,    33,    34,    11,     0,    35,     0,
      36,    12,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    14,    38,     0,    39,     0,     0,    15,    16,
       0,    17,     0,    40,    41,    18,     0,     0,    19,     0,
       0,     5,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,    23,    24,
      25,    26,    42,     0,     0,   578,     0,     0,    28,     7,
       0,     8,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    31,   215,    16,     0,    17,    32,    33,    34,
      18,     0,    35,    19,    36,     0,     0,     0,    37,     0,
      20,     0,     0,     0,     0,     0,     0,    38,     0,    39,
       0,    22,     0,    23,    24,    25,    26,    40,    41,     0,
       0,     0,   504,    28,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,     0,     0,     0,     0,     0,     0,
       0,   515,   516,     0,     0,     0,    42,     0,   550,   681,
       4,     5,     0,     0,     0,     0,     0,    31,     0,     0,
       6,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     7,
       0,     8,   219,     0,    39,     0,     0,     9,    10,     0,
       0,    11,    40,    41,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
      18,    42,     0,    19,   572,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     0,     0,    31,     0,   314,
       0,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     7,
     -68,     8,    38,     0,    39,     0,     0,     9,    10,     0,
       0,    11,    40,    41,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
      18,    42,     0,    19,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,   315,     0,
       0,    22,     0,    23,    24,    25,    26,    27,     5,     0,
       0,     0,     0,    28,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     7,     0,     8,     0,
       0,     0,     0,   247,     9,     0,     0,    31,    11,     0,
       0,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,    37,    14,     0,     0,     0,     0,     0,
     215,    16,    38,    17,    39,   248,     0,    18,     0,     0,
      19,     0,    40,    41,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    22,     0,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
      28,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
     249,   247,     9,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    32,
      33,    34,    14,     0,    35,     0,    36,   250,   215,    16,
     218,    17,     0,   248,     0,    18,     0,     0,    19,   219,
       0,    39,     0,     0,     0,    20,     0,     0,     0,    40,
      41,     0,     0,     0,     5,     0,    22,     0,    23,    24,
      25,    26,     0,     0,     0,     0,     0,   631,    28,     0,
       0,     0,     0,   648,     0,     0,     0,     0,    42,     0,
       0,     0,     7,     0,     8,     0,     0,     0,   249,     0,
       9,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
      14,     0,    35,     0,    36,   250,   215,    16,   218,    17,
       0,     0,     0,    18,     0,     0,    19,   219,     0,    39,
       0,     0,     0,    20,     0,     0,     0,    40,    41,     0,
       0,     0,     5,     0,    22,     0,    23,    24,    25,    26,
       0,     0,     0,     0,     0,   661,    28,   495,   496,   497,
     498,   499,   500,   501,   502,   503,    42,     0,     0,     0,
       7,     0,     8,     0,     0,     0,     0,     0,     9,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,    32,    33,    34,    14,     0,
      35,     0,    36,     0,   215,    16,   218,    17,     0,     0,
       0,    18,     0,     0,    19,   219,     0,    39,     0,     0,
       0,    20,     0,     0,     0,    40,    41,     0,     0,     0,
       0,     0,    22,     0,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,    28,   495,   496,   497,   498,   499,
     500,   501,   502,   503,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   499,   500,   501,   502,   503,     0,     0,    31,     0,
       0,     0,     0,    32,    33,    34,     0,     0,    35,     0,
      36,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    41,   495,   496,   497,   498,   499,
     500,   501,   502,   503,     0,     0,     0,   504,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,     0,
       0,     0,    42,     0,     0,     0,   515,   516,     0,     0,
       0,     0,     0,   597,   495,   496,   497,   498,   499,   500,
     501,   502,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,   501,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   495,   496,   497,
     498,   499,   500,   501,   515,   516,   581,   504,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   495,
     496,   497,   498,   499,   500,   501,   515,   516,   670,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   669,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,     0,     0,     0,
       0,     0,     0,     0,   515,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,     0,     0,     0,     0,
       0,     0,     0,   515,   516,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,     0,     0,     0,     0,     0,
       0,     0,   515,   516,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,     0,     0,     0,     0,     0,     0,
       0,   515,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,   507,   508,   509,   510,   511,   512,   513,   514,     0,
       0,     0,     5,     0,     0,     0,   515,   516,     0,     0,
       0,     0,     0,   507,   508,   509,   510,   511,   512,   513,
     514,     0,     0,     0,     0,     0,     0,     0,   515,   516,
       7,     0,     8,     0,     0,     0,     0,     0,     9,    10,
       0,     0,    11,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,   215,    16,     0,    17,     0,     0,
       0,    18,     0,     0,    19,     7,     0,     8,     0,     0,
       0,    20,     0,     9,     0,     0,     0,    11,     0,     0,
       0,     0,    22,     0,    23,    24,    25,    26,    27,     0,
       0,   216,     0,    14,    28,     0,     0,     0,   217,   215,
      16,     0,    17,     0,     0,     0,    18,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    31,    23,
      24,    25,    26,    32,    33,    34,     0,     0,    35,    28,
      36,     5,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,     0,     0,     0,     7,
       0,     8,     0,    31,     0,     0,     0,     9,    32,    33,
      34,     0,     0,    35,     0,    36,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,    14,   219,     0,
      39,     0,     0,   215,    16,     0,     0,     0,    40,    41,
      18,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,     0,    35,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   219,     0,    39,     0,     0,     0,     0,     0,
       0,     0,    40,    41,   108,     0,   109,   110,   111,   112,
     113,   114,     0,   115,     0,     0,   116,     0,   117,     0,
       0,     0,   118,   119,     0,   120,   121,   122,   123,     0,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,     0,     0,   138,     0,
       0,     0,   139,     0,   140,   141,     0,   142,   143,   144,
     145,   146,   147,     0,   148,   149,   150,   151,   152,   153,
       0,     0,   154,     0,     0,   155,     0,     0,     0,     0,
       0,   156,   157,     0,   158,   159,     0,   160,   161,     0,
       0,     0,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,     0,   175,     0,   176,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,     0,     0,   190,     0,
       0,   191,     0,     0,   192,   193,     0,     0,   194,   195,
     196,   197,     0,     0,   198,     0,   199,     0,   200,   201,
     202,   203,   204,   205,   206,     0,     0,   207
};

static const yytype_int16 yycheck[] =
{
       2,    53,     2,     2,    50,    74,   286,     2,    74,     2,
     325,   214,     2,     2,   256,     2,   252,   253,     2,     2,
     534,     2,     2,   287,     6,    75,   290,   344,   292,    72,
      73,   295,   591,   294,    77,    53,   300,   533,    39,   346,
     312,    71,    72,    73,   101,   110,   158,    77,    59,   184,
     100,    52,   184,    17,    53,     3,   596,     5,    53,   101,
      53,   601,    37,    38,   158,   184,    53,   158,   136,   349,
      28,    17,   140,   184,   206,    33,   211,     3,   184,     5,
       3,   184,     5,   205,   184,   599,   208,   206,   283,   131,
     101,   286,    40,     9,     0,   207,    12,    45,   293,   167,
     211,   296,   598,   340,   205,   211,   209,   302,   303,   210,
     346,   211,    51,   207,    40,   209,   207,    40,   205,    45,
     660,   210,   636,   210,    72,    64,   685,   442,   365,   366,
      69,   205,    97,    34,   337,   631,   210,   340,    39,   454,
     205,   179,   180,   181,   182,   183,    72,   205,   205,    72,
       3,   209,     5,   667,   349,   350,   205,   226,     9,   208,
     226,   364,   365,   366,   436,   661,   205,     3,     3,   208,
       5,   207,     3,    45,     5,     3,   210,     5,     3,   127,
       5,   210,   209,   252,   253,   164,   252,   253,   383,   384,
     385,   386,   387,   388,   389,     3,   209,     5,    70,   209,
       3,   127,     5,   272,   127,   441,   154,   208,   472,   207,
     212,   213,   281,   212,   213,    40,   234,   260,   209,   212,
     213,   209,   207,    95,   209,   212,   213,   186,   154,   211,
     260,   154,   209,    15,    16,    17,    18,    19,    20,    21,
     204,   205,   294,   218,   219,   207,   194,    72,   194,   195,
     196,   301,   494,   517,   304,   209,   306,   307,   204,   205,
     577,   311,   210,   578,   207,   207,   461,   209,   194,   141,
       3,   194,     5,     3,   326,     5,     3,   346,     5,   205,
     346,   153,   205,   547,   210,   209,     3,   210,     5,     3,
     209,     5,   294,     3,     3,     5,     5,   209,   540,   351,
     495,   496,   127,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     101,   516,   583,   630,     9,   209,   641,   211,   207,   154,
       6,     7,   209,   569,     3,    17,   207,   389,   205,   212,
     210,   210,   210,   345,   210,   345,   345,   542,   210,   351,
     210,   210,   345,   660,   596,   407,   210,   209,   345,   601,
     210,   210,   604,   210,   366,   672,   681,   210,   210,   194,
     210,   210,   441,   210,    41,   441,   210,   210,   210,     5,
     210,   210,   209,   690,   210,   210,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   210,   448,   210,   210,   210,
     210,   210,   471,   683,   456,   210,   210,   643,   190,   191,
     192,   193,   194,   195,   196,    40,   210,    84,   660,   210,
      45,   210,   204,   205,   476,   209,   211,   207,   494,   207,
      97,    98,    99,   100,   486,   186,   211,   210,     9,     9,
     107,     9,   706,   445,     9,   445,   445,    72,   450,   448,
     445,   453,   445,   453,   453,   445,   445,   456,   445,   443,
     453,   445,   445,   456,   445,   445,   453,     9,   534,   456,
       9,   666,     9,     9,   669,     9,   205,   211,   210,   186,
     147,   209,   534,   476,   151,   207,   207,   184,   683,   209,
     208,   207,   207,   212,     6,   184,   204,    15,    16,    17,
     569,     9,   127,   569,    91,   211,   211,   211,   711,   712,
     192,   193,   194,   195,   196,   210,   562,   211,   211,   211,
     211,   573,   204,   205,   593,   211,   186,   211,   211,   154,
     596,   583,   534,   599,   211,   601,    40,   211,   211,   211,
     211,   211,   208,   211,   164,     3,   211,   599,     6,     7,
       8,     9,    10,    11,   211,   211,   185,   211,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    72,   194,
     211,   211,   211,   211,   643,   204,   205,   643,   211,   209,
     205,   583,   211,   532,   636,   210,   184,   536,   211,   211,
      15,    16,    17,   209,   660,    20,    21,   599,   209,     3,
       3,     5,     6,     7,     8,     9,    10,    11,     3,     9,
       6,   211,   184,    71,     3,   667,   209,     6,     7,     8,
       9,    10,    11,   127,   205,   208,   211,   209,     5,    33,
     186,    35,   211,   211,   636,   211,   211,    41,   207,   186,
     642,    45,   209,   642,   646,   211,   646,   646,   211,   642,
     154,   211,   211,   646,   186,   642,   209,    61,   338,   646,
     452,   119,   308,    67,    68,   667,    70,    71,   302,   471,
      74,   712,    53,    77,   192,   193,   194,   195,   196,   542,
      84,   630,    71,   450,   633,   226,   204,   205,   685,   298,
     194,    95,   150,    97,    98,    99,   100,    82,   586,   584,
      -1,   205,   354,   107,    -1,   163,   210,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   663,   119,     6,     7,     8,     9,
      10,    11,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   189,    -1,    -1,   192,   193,   194,   141,    -1,   197,
     198,   690,   146,   147,   148,    -1,   150,   151,   206,   153,
      -1,    -1,   210,   157,    -1,    -1,    -1,    -1,    -1,   163,
      -1,   150,   166,    -1,   168,   190,   191,   192,   193,   194,
     195,   196,   176,   177,   163,    -1,    -1,    -1,    -1,   204,
     205,    71,    -1,    -1,    -1,   189,    -1,    -1,   192,   193,
     194,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,   192,   193,   194,   210,    -1,   197,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    45,    -1,    -1,   189,
      -1,    50,   192,   193,   194,    -1,    -1,   197,   198,    -1,
      59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
     210,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,    -1,   151,    33,   153,    35,    -1,    -1,   157,    -1,
      -1,    41,    42,    -1,    -1,    45,    -1,   166,    -1,   168,
      50,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,   205,    -1,    -1,   208,
      -1,    91,    92,    -1,    -1,    95,    -1,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
      -1,   151,    33,   153,    35,    -1,    -1,   157,    -1,    -1,
      41,    42,    -1,    -1,    45,    -1,   166,    -1,   168,    50,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,   205,    -1,    -1,   208,    -1,
      91,    -1,    -1,    -1,    95,    -1,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,   107,     4,     5,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
     141,    -1,    -1,    -1,    41,   146,   147,   148,    45,    -1,
     151,    -1,   153,    50,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,   166,    -1,   168,    -1,    -1,
      67,    68,    -1,    70,    -1,   176,   177,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      97,    98,    99,   100,   205,    -1,    -1,   208,    -1,    -1,
     107,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,   141,    -1,    -1,    -1,    41,   146,
     147,   148,    45,    -1,   151,    -1,   153,    50,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,   166,
      -1,   168,    -1,    -1,    67,    68,    -1,    70,    -1,   176,
     177,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,   205,    -1,
      -1,   208,    -1,    -1,   107,     4,     5,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,   141,    -1,
      -1,    -1,    41,   146,   147,   148,    45,    -1,   151,    -1,
     153,    50,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,   166,    -1,   168,    -1,    -1,    67,    68,
      -1,    70,    -1,   176,   177,    74,    -1,    -1,    77,    -1,
      -1,     5,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    97,    98,
      99,   100,   205,    -1,    -1,   208,    -1,    -1,   107,    33,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,   141,    67,    68,    -1,    70,   146,   147,   148,
      74,    -1,   151,    77,   153,    -1,    -1,    -1,   157,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,
      -1,    95,    -1,    97,    98,    99,   100,   176,   177,    -1,
      -1,    -1,   185,   107,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,   205,    -1,   211,   208,
       4,     5,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      14,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,   166,    -1,   168,    -1,    -1,    41,    42,    -1,
      -1,    45,   176,   177,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,
      74,   205,    -1,    77,   208,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,   141,    -1,    13,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    33,
     164,    35,   166,    -1,   168,    -1,    -1,    41,    42,    -1,
      -1,    45,   176,   177,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,
      74,   205,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      -1,    95,    -1,    97,    98,    99,   100,   101,     5,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    33,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,   141,    45,    -1,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,   166,    70,   168,    72,    -1,    74,    -1,    -1,
      77,    -1,   176,   177,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    95,    -1,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
     127,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,   146,
     147,   148,    61,    -1,   151,    -1,   153,   154,    67,    68,
     157,    70,    -1,    72,    -1,    74,    -1,    -1,    77,   166,
      -1,   168,    -1,    -1,    -1,    84,    -1,    -1,    -1,   176,
     177,    -1,    -1,    -1,     5,    -1,    95,    -1,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   194,   107,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,   127,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,
      61,    -1,   151,    -1,   153,   154,    67,    68,   157,    70,
      -1,    -1,    -1,    74,    -1,    -1,    77,   166,    -1,   168,
      -1,    -1,    -1,    84,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,     5,    -1,    95,    -1,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,   194,   107,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   205,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,    -1,    -1,    -1,    -1,   146,   147,   148,    61,    -1,
     151,    -1,   153,    -1,    67,    68,   157,    70,    -1,    -1,
      -1,    74,    -1,    -1,    77,   166,    -1,   168,    -1,    -1,
      -1,    84,    -1,    -1,    -1,   176,   177,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,   141,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,
     153,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,   205,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,   211,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    15,    16,    17,
      18,    19,    20,    21,   204,   205,   206,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    15,
      16,    17,    18,    19,    20,    21,   204,   205,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,     5,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    77,    33,    -1,    35,    -1,    -1,
      -1,    84,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,   101,    -1,
      -1,   104,    -1,    61,   107,    -1,    -1,    -1,   111,    67,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,   141,    97,
      98,    99,   100,   146,   147,   148,    -1,    -1,   151,   107,
     153,     5,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,    -1,    -1,    -1,    -1,    33,
      -1,    35,    -1,   141,    -1,    -1,    -1,    41,   146,   147,
     148,    -1,    -1,   151,    -1,   153,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,   166,    -1,
     168,    -1,    -1,    67,    68,    -1,    -1,    -1,   176,   177,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   177,    25,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    43,    44,    -1,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,   105,   106,    -1,   108,   109,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,   142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,   155,   156,    -1,    -1,   159,   160,
     161,   162,    -1,    -1,   165,    -1,   167,    -1,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,   178
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   214,   216,     0,     4,     5,    14,    33,    35,    41,
      42,    45,    50,    59,    61,    67,    68,    70,    74,    77,
      84,    91,    95,    97,    98,    99,   100,   101,   107,   112,
     129,   141,   146,   147,   148,   151,   153,   157,   166,   168,
     176,   177,   205,   215,   222,   223,   225,   226,   227,   228,
     231,   232,   238,   239,   250,   264,   268,   270,   271,   272,
     273,   274,   277,   278,   281,   283,   284,   285,   286,   288,
     289,   290,   291,   292,   294,   296,   314,   315,   316,   317,
     205,   319,   322,   323,     3,     5,   210,     3,     5,     3,
       5,   266,    97,   269,     9,     3,     5,   269,     3,   210,
     210,   269,   270,     3,   266,     3,   266,   270,    25,    27,
      28,    29,    30,    31,    32,    34,    37,    39,    43,    44,
      46,    47,    48,    49,    51,    52,    53,    54,    55,    56,
      57,    58,    60,    62,    63,    64,    65,    66,    69,    73,
      75,    76,    78,    79,    80,    81,    82,    83,    85,    86,
      87,    88,    89,    90,    93,    96,   102,   103,   105,   106,
     108,   109,   113,   114,   115,   116,   117,   118,   120,   121,
     122,   123,   124,   125,   126,   128,   130,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   142,   143,   144,   145,
     149,   152,   155,   156,   159,   160,   161,   162,   165,   167,
     169,   170,   171,   172,   173,   174,   175,   178,   240,   242,
     313,   209,   218,   218,   164,    67,   104,   111,   157,   166,
     230,   250,   271,   277,   283,   287,   294,   314,   317,   209,
     209,   207,   207,   209,   207,   209,   221,   209,   186,   282,
     207,   295,   296,   295,   295,     3,     5,    40,    72,   127,
     154,   194,   210,   244,   267,   297,   298,   311,   250,   314,
     315,   317,   295,   209,    51,    64,    69,   324,   325,   319,
     101,     9,   207,   209,     3,   315,   207,   158,   207,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   184,   206,    13,    92,   222,   229,   232,   271,
     273,   274,   285,   286,   289,   208,   238,   239,     3,     3,
       5,     3,     5,     3,     3,   207,   311,   275,   217,   131,
     279,   283,     3,     5,   207,   220,   293,   297,   297,   212,
     205,   210,   237,   295,   184,   206,     5,   211,   247,   248,
     249,   267,   186,   211,   257,   210,   260,     9,     9,    12,
     243,   267,     3,     6,     7,     8,     9,    10,    11,    71,
     119,   150,   163,   189,   192,   193,   194,   197,   198,   210,
     253,   254,   255,   253,   256,     9,     9,   241,   256,   255,
       9,     9,   255,     9,   255,   253,   236,   239,   294,   255,
     251,   252,   253,     9,   313,     9,   255,   315,   251,   253,
     315,   179,   180,   181,   182,   183,   312,   315,   315,   243,
       6,     7,   318,     9,   315,   242,   205,   210,   209,   207,
     221,   294,   208,   238,   276,   216,   186,   110,   238,   262,
     280,   209,   207,   220,   208,   222,   239,   292,   297,   211,
     256,   194,   206,   253,   233,   234,   235,   236,   325,   207,
     208,   184,   212,     6,   224,   208,   238,   258,   262,   208,
     239,   259,   262,   211,   211,   211,   210,   253,   253,   253,
     253,   253,   253,   253,   294,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   185,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   204,   205,   184,   211,   211,
     211,   184,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   294,   194,   210,   237,   244,   267,   303,   305,
     306,   211,   184,   211,   211,   211,   211,   184,   211,   211,
     211,   211,   211,   211,   211,   211,   204,   211,   211,   211,
     242,     9,   219,   297,   307,   221,   286,   208,   186,   294,
     314,   209,   208,   239,   263,   264,   208,   228,   208,   221,
     206,   206,   211,   184,   164,   320,   321,   249,   255,     6,
     211,   294,   317,   211,   209,   209,   294,   211,   194,   210,
     237,   244,   299,   301,   302,   253,   253,     3,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,     3,   253,   255,     9,   305,
     293,   194,   233,   244,   304,   305,   210,   237,   252,   255,
       6,   211,   218,   184,   297,   209,   220,   221,    24,   236,
     323,   208,   320,   303,   309,   310,   209,   265,   267,   301,
     293,   194,   233,   244,   300,   301,   211,   210,   237,   186,
     206,   305,   293,   211,   305,   211,   233,   211,   221,   208,
     297,   208,     5,   186,   308,   184,   209,   207,   211,   301,
     293,   211,   305,   211,   253,   233,   253,   305,   211,   221,
     209,   256,   309,   245,   305,   211,    39,    52,   208,   246,
     255,   186,   186,   209,   261,   262,   261,   209
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   213,   214,   215,   215,   216,   217,   216,   216,   216,
     216,   216,   216,   216,   216,   218,   218,   219,   218,   218,
     218,   218,   218,   218,   218,   218,   220,   220,   221,   221,
     222,   222,   222,   222,   222,   222,   222,   223,   224,   224,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     227,   228,   229,   230,   230,   231,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   238,   238,
     239,   240,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   245,   245,   246,   246,   247,   247,   247,   248,
     248,   249,   249,   250,   251,   251,   252,   252,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   255,   256,   257,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   264,   264,   265,   265,
     266,   266,   266,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   272,
     273,   274,   275,   275,   276,   277,   277,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   283,   283,   284,   285,
     285,   285,   286,   286,   287,   287,   288,   289,   290,   290,
     290,   291,   292,   293,   293,   294,   294,   295,   295,   296,
     296,   296,   297,   297,   297,   298,   298,   298,   298,   299,
     299,   299,   300,   300,   301,   301,   302,   302,   302,   302,
     302,   303,   303,   303,   304,   304,   305,   305,   306,   306,
     306,   306,   306,   306,   307,   307,   308,   308,   309,   310,
     310,   311,   311,   312,   312,   312,   312,   312,   313,   313,
     313,   314,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   316,   317,   317,   318,   318,   318,   319,   319,
     320,   320,   321,   322,   323,   323,   324,   324,   325,   325,
     325
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     2,     2,
       3,     2,     2,     2,     2,     0,     2,     0,     6,     2,
       3,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       1,     2,     1,     2,     1,     2,     2,     2,     2,     4,
       3,     3,     5,     2,     2,     3,     4,     0,     1,     1,
       3,     1,     3,     3,     2,     3,     3,     2,     0,     1,
       3,     1,     3,     4,     1,     3,     0,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     1,     4,     1,     1,     4,
       1,     4,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     6,     1,     4,     1,     1,     1,     4,     1,     1,
       1,     4,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     4,     3,     0,     2,     1,     1,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     3,     3,     5,     5,     4,     3,     1,
       3,     1,     1,     0,     2,     4,     3,     2,     2,     0,
       2,     2,     1,     3,     2,     1,     3,     2,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     2,     2,     2,
       5,     2,     0,     2,     2,     2,     2,     2,     2,     3,
       2,     3,     5,     5,     0,     2,     2,     2,     2,     6,
       8,     2,     2,     2,     2,     2,     2,     5,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     0,     1,     2,
       2,     2,     3,     2,     1,     1,     3,     2,     4,     3,
       2,     1,     3,     2,     0,     1,     3,     2,     1,     3,
       4,     3,     2,     1,     3,     2,     0,     1,     1,     3,
       2,     1,     3,     4,     1,     3,     0,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     4,     5,     5,    10,     1,     3,     1,     0,     2,
       0,     2,     4,     6,     0,     3,     1,     3,     1,     1,
       1
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


/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
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

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 315 "parser.y"
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
#line 3115 "parser.tab.c"
    break;

  case 5:
#line 331 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3121 "parser.tab.c"
    break;

  case 6:
#line 332 "parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3127 "parser.tab.c"
    break;

  case 7:
#line 333 "parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3133 "parser.tab.c"
    break;

  case 8:
#line 334 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3139 "parser.tab.c"
    break;

  case 9:
#line 335 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3145 "parser.tab.c"
    break;

  case 10:
#line 336 "parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3153 "parser.tab.c"
    break;

  case 11:
#line 339 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3161 "parser.tab.c"
    break;

  case 12:
#line 342 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3167 "parser.tab.c"
    break;

  case 13:
#line 343 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3173 "parser.tab.c"
    break;

  case 14:
#line 344 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3179 "parser.tab.c"
    break;

  case 15:
#line 347 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3185 "parser.tab.c"
    break;

  case 16:
#line 348 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3191 "parser.tab.c"
    break;

  case 17:
#line 349 "parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3197 "parser.tab.c"
    break;

  case 18:
#line 350 "parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3203 "parser.tab.c"
    break;

  case 19:
#line 351 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3209 "parser.tab.c"
    break;

  case 20:
#line 352 "parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3215 "parser.tab.c"
    break;

  case 21:
#line 353 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3223 "parser.tab.c"
    break;

  case 22:
#line 356 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3229 "parser.tab.c"
    break;

  case 23:
#line 357 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3235 "parser.tab.c"
    break;

  case 24:
#line 358 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3241 "parser.tab.c"
    break;

  case 25:
#line 359 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3247 "parser.tab.c"
    break;

  case 26:
#line 362 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3253 "parser.tab.c"
    break;

  case 27:
#line 363 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3259 "parser.tab.c"
    break;

  case 30:
#line 371 "parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3265 "parser.tab.c"
    break;

  case 31:
#line 372 "parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3271 "parser.tab.c"
    break;

  case 32:
#line 373 "parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3277 "parser.tab.c"
    break;

  case 33:
#line 374 "parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3283 "parser.tab.c"
    break;

  case 34:
#line 375 "parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3289 "parser.tab.c"
    break;

  case 35:
#line 376 "parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3295 "parser.tab.c"
    break;

  case 36:
#line 377 "parser.y"
                         { (yyval.statement) = NULL; }
#line 3301 "parser.tab.c"
    break;

  case 37:
#line 381 "parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3313 "parser.tab.c"
    break;

  case 38:
#line 391 "parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3319 "parser.tab.c"
    break;

  case 39:
#line 392 "parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3325 "parser.tab.c"
    break;

  case 41:
#line 397 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3331 "parser.tab.c"
    break;

  case 43:
#line 399 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3337 "parser.tab.c"
    break;

  case 45:
#line 401 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3343 "parser.tab.c"
    break;

  case 46:
#line 402 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3349 "parser.tab.c"
    break;

  case 47:
#line 403 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3355 "parser.tab.c"
    break;

  case 48:
#line 404 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3361 "parser.tab.c"
    break;

  case 49:
#line 407 "parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3367 "parser.tab.c"
    break;

  case 50:
#line 409 "parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3378 "parser.tab.c"
    break;

  case 51:
#line 417 "parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3387 "parser.tab.c"
    break;

  case 52:
#line 424 "parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3393 "parser.tab.c"
    break;

  case 53:
#line 427 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3399 "parser.tab.c"
    break;

  case 54:
#line 428 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3405 "parser.tab.c"
    break;

  case 55:
#line 430 "parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3413 "parser.tab.c"
    break;

  case 56:
#line 435 "parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3419 "parser.tab.c"
    break;

  case 57:
#line 438 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3425 "parser.tab.c"
    break;

  case 59:
#line 442 "parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3431 "parser.tab.c"
    break;

  case 60:
#line 443 "parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3437 "parser.tab.c"
    break;

  case 62:
#line 447 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3443 "parser.tab.c"
    break;

  case 63:
#line 451 "parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3453 "parser.tab.c"
    break;

  case 64:
#line 456 "parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3463 "parser.tab.c"
    break;

  case 65:
#line 463 "parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3472 "parser.tab.c"
    break;

  case 66:
#line 467 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3478 "parser.tab.c"
    break;

  case 67:
#line 468 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3484 "parser.tab.c"
    break;

  case 68:
#line 471 "parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3490 "parser.tab.c"
    break;

  case 70:
#line 476 "parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3496 "parser.tab.c"
    break;

  case 71:
#line 479 "parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3502 "parser.tab.c"
    break;

  case 72:
#line 480 "parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3508 "parser.tab.c"
    break;

  case 73:
#line 481 "parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3514 "parser.tab.c"
    break;

  case 74:
#line 484 "parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3520 "parser.tab.c"
    break;

  case 75:
#line 485 "parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3526 "parser.tab.c"
    break;

  case 76:
#line 488 "parser.y"
                                                { (yyval.attr) = NULL; }
#line 3532 "parser.tab.c"
    break;

  case 77:
#line 489 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3538 "parser.tab.c"
    break;

  case 78:
#line 490 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3544 "parser.tab.c"
    break;

  case 79:
#line 491 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3550 "parser.tab.c"
    break;

  case 80:
#line 492 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3556 "parser.tab.c"
    break;

  case 81:
#line 493 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3562 "parser.tab.c"
    break;

  case 82:
#line 494 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3568 "parser.tab.c"
    break;

  case 83:
#line 495 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3574 "parser.tab.c"
    break;

  case 84:
#line 496 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3580 "parser.tab.c"
    break;

  case 85:
#line 497 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3586 "parser.tab.c"
    break;

  case 86:
#line 498 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3592 "parser.tab.c"
    break;

  case 87:
#line 499 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3598 "parser.tab.c"
    break;

  case 88:
#line 500 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3604 "parser.tab.c"
    break;

  case 89:
#line 501 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3610 "parser.tab.c"
    break;

  case 90:
#line 502 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3616 "parser.tab.c"
    break;

  case 91:
#line 503 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3622 "parser.tab.c"
    break;

  case 92:
#line 504 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3628 "parser.tab.c"
    break;

  case 93:
#line 505 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3634 "parser.tab.c"
    break;

  case 94:
#line 506 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3640 "parser.tab.c"
    break;

  case 95:
#line 507 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3646 "parser.tab.c"
    break;

  case 96:
#line 508 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3652 "parser.tab.c"
    break;

  case 97:
#line 509 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3658 "parser.tab.c"
    break;

  case 98:
#line 510 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3664 "parser.tab.c"
    break;

  case 99:
#line 511 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3670 "parser.tab.c"
    break;

  case 100:
#line 512 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3676 "parser.tab.c"
    break;

  case 101:
#line 513 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3682 "parser.tab.c"
    break;

  case 102:
#line 514 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3688 "parser.tab.c"
    break;

  case 103:
#line 515 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3694 "parser.tab.c"
    break;

  case 104:
#line 516 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3700 "parser.tab.c"
    break;

  case 105:
#line 517 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3706 "parser.tab.c"
    break;

  case 106:
#line 518 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3712 "parser.tab.c"
    break;

  case 107:
#line 519 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3718 "parser.tab.c"
    break;

  case 108:
#line 520 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3724 "parser.tab.c"
    break;

  case 109:
#line 521 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3730 "parser.tab.c"
    break;

  case 110:
#line 522 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3736 "parser.tab.c"
    break;

  case 111:
#line 523 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3742 "parser.tab.c"
    break;

  case 112:
#line 524 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3748 "parser.tab.c"
    break;

  case 113:
#line 525 "parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3754 "parser.tab.c"
    break;

  case 114:
#line 526 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3760 "parser.tab.c"
    break;

  case 115:
#line 527 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3766 "parser.tab.c"
    break;

  case 116:
#line 528 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3772 "parser.tab.c"
    break;

  case 117:
#line 529 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3778 "parser.tab.c"
    break;

  case 118:
#line 530 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3784 "parser.tab.c"
    break;

  case 119:
#line 531 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3790 "parser.tab.c"
    break;

  case 120:
#line 532 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3796 "parser.tab.c"
    break;

  case 121:
#line 533 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3802 "parser.tab.c"
    break;

  case 122:
#line 534 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 3808 "parser.tab.c"
    break;

  case 123:
#line 535 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3814 "parser.tab.c"
    break;

  case 124:
#line 536 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3820 "parser.tab.c"
    break;

  case 125:
#line 537 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3826 "parser.tab.c"
    break;

  case 126:
#line 538 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3832 "parser.tab.c"
    break;

  case 127:
#line 539 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3838 "parser.tab.c"
    break;

  case 128:
#line 540 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3844 "parser.tab.c"
    break;

  case 129:
#line 541 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3850 "parser.tab.c"
    break;

  case 130:
#line 542 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3856 "parser.tab.c"
    break;

  case 131:
#line 543 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3862 "parser.tab.c"
    break;

  case 132:
#line 544 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3868 "parser.tab.c"
    break;

  case 133:
#line 545 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3874 "parser.tab.c"
    break;

  case 134:
#line 546 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3880 "parser.tab.c"
    break;

  case 135:
#line 547 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3886 "parser.tab.c"
    break;

  case 136:
#line 548 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3892 "parser.tab.c"
    break;

  case 137:
#line 549 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3898 "parser.tab.c"
    break;

  case 138:
#line 550 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3904 "parser.tab.c"
    break;

  case 139:
#line 551 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3910 "parser.tab.c"
    break;

  case 140:
#line 552 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3916 "parser.tab.c"
    break;

  case 141:
#line 553 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3922 "parser.tab.c"
    break;

  case 142:
#line 554 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3928 "parser.tab.c"
    break;

  case 143:
#line 555 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3934 "parser.tab.c"
    break;

  case 144:
#line 556 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3940 "parser.tab.c"
    break;

  case 145:
#line 557 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3946 "parser.tab.c"
    break;

  case 146:
#line 558 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3952 "parser.tab.c"
    break;

  case 147:
#line 559 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3958 "parser.tab.c"
    break;

  case 148:
#line 560 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3964 "parser.tab.c"
    break;

  case 149:
#line 561 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 3970 "parser.tab.c"
    break;

  case 150:
#line 562 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 3976 "parser.tab.c"
    break;

  case 151:
#line 564 "parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 3984 "parser.tab.c"
    break;

  case 152:
#line 567 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 3990 "parser.tab.c"
    break;

  case 153:
#line 568 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 3996 "parser.tab.c"
    break;

  case 154:
#line 569 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4002 "parser.tab.c"
    break;

  case 155:
#line 570 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4008 "parser.tab.c"
    break;

  case 156:
#line 571 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4014 "parser.tab.c"
    break;

  case 157:
#line 572 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4020 "parser.tab.c"
    break;

  case 158:
#line 573 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4026 "parser.tab.c"
    break;

  case 159:
#line 574 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4032 "parser.tab.c"
    break;

  case 160:
#line 575 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4038 "parser.tab.c"
    break;

  case 161:
#line 576 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4044 "parser.tab.c"
    break;

  case 162:
#line 577 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4050 "parser.tab.c"
    break;

  case 163:
#line 578 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4056 "parser.tab.c"
    break;

  case 164:
#line 579 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4062 "parser.tab.c"
    break;

  case 165:
#line 580 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4068 "parser.tab.c"
    break;

  case 166:
#line 581 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4074 "parser.tab.c"
    break;

  case 167:
#line 582 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4080 "parser.tab.c"
    break;

  case 168:
#line 583 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4086 "parser.tab.c"
    break;

  case 169:
#line 584 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4092 "parser.tab.c"
    break;

  case 170:
#line 585 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4098 "parser.tab.c"
    break;

  case 171:
#line 586 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4104 "parser.tab.c"
    break;

  case 172:
#line 587 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4110 "parser.tab.c"
    break;

  case 173:
#line 588 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4116 "parser.tab.c"
    break;

  case 174:
#line 589 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4122 "parser.tab.c"
    break;

  case 175:
#line 590 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4128 "parser.tab.c"
    break;

  case 177:
#line 595 "parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4136 "parser.tab.c"
    break;

  case 178:
#line 600 "parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4142 "parser.tab.c"
    break;

  case 179:
#line 601 "parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4148 "parser.tab.c"
    break;

  case 180:
#line 602 "parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4154 "parser.tab.c"
    break;

  case 181:
#line 603 "parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4160 "parser.tab.c"
    break;

  case 182:
#line 606 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4166 "parser.tab.c"
    break;

  case 183:
#line 607 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4172 "parser.tab.c"
    break;

  case 184:
#line 610 "parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4181 "parser.tab.c"
    break;

  case 185:
#line 614 "parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4190 "parser.tab.c"
    break;

  case 186:
#line 620 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4196 "parser.tab.c"
    break;

  case 187:
#line 621 "parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4202 "parser.tab.c"
    break;

  case 189:
#line 625 "parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4211 "parser.tab.c"
    break;

  case 190:
#line 629 "parser.y"
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
#line 4226 "parser.tab.c"
    break;

  case 191:
#line 641 "parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4235 "parser.tab.c"
    break;

  case 192:
#line 645 "parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4243 "parser.tab.c"
    break;

  case 193:
#line 650 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4249 "parser.tab.c"
    break;

  case 194:
#line 653 "parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4255 "parser.tab.c"
    break;

  case 195:
#line 654 "parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4261 "parser.tab.c"
    break;

  case 196:
#line 657 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4267 "parser.tab.c"
    break;

  case 198:
#line 661 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4273 "parser.tab.c"
    break;

  case 199:
#line 662 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4279 "parser.tab.c"
    break;

  case 200:
#line 663 "parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4285 "parser.tab.c"
    break;

  case 201:
#line 664 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4291 "parser.tab.c"
    break;

  case 202:
#line 665 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4297 "parser.tab.c"
    break;

  case 203:
#line 666 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4303 "parser.tab.c"
    break;

  case 204:
#line 667 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4309 "parser.tab.c"
    break;

  case 205:
#line 668 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4315 "parser.tab.c"
    break;

  case 206:
#line 669 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4321 "parser.tab.c"
    break;

  case 207:
#line 670 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4327 "parser.tab.c"
    break;

  case 208:
#line 671 "parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4333 "parser.tab.c"
    break;

  case 209:
#line 672 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4339 "parser.tab.c"
    break;

  case 210:
#line 673 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4345 "parser.tab.c"
    break;

  case 211:
#line 674 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4351 "parser.tab.c"
    break;

  case 212:
#line 675 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4357 "parser.tab.c"
    break;

  case 213:
#line 676 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4363 "parser.tab.c"
    break;

  case 214:
#line 677 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4369 "parser.tab.c"
    break;

  case 215:
#line 678 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4375 "parser.tab.c"
    break;

  case 216:
#line 679 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4381 "parser.tab.c"
    break;

  case 217:
#line 680 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4387 "parser.tab.c"
    break;

  case 218:
#line 681 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4393 "parser.tab.c"
    break;

  case 219:
#line 682 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4399 "parser.tab.c"
    break;

  case 220:
#line 683 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4405 "parser.tab.c"
    break;

  case 221:
#line 684 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4411 "parser.tab.c"
    break;

  case 222:
#line 685 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4417 "parser.tab.c"
    break;

  case 223:
#line 686 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4423 "parser.tab.c"
    break;

  case 224:
#line 687 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4429 "parser.tab.c"
    break;

  case 225:
#line 688 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4435 "parser.tab.c"
    break;

  case 226:
#line 689 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4441 "parser.tab.c"
    break;

  case 227:
#line 690 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4447 "parser.tab.c"
    break;

  case 228:
#line 691 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4453 "parser.tab.c"
    break;

  case 229:
#line 692 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4459 "parser.tab.c"
    break;

  case 230:
#line 693 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4465 "parser.tab.c"
    break;

  case 231:
#line 694 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4471 "parser.tab.c"
    break;

  case 232:
#line 695 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4477 "parser.tab.c"
    break;

  case 233:
#line 696 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4483 "parser.tab.c"
    break;

  case 234:
#line 697 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4489 "parser.tab.c"
    break;

  case 235:
#line 699 "parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4495 "parser.tab.c"
    break;

  case 236:
#line 701 "parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4501 "parser.tab.c"
    break;

  case 237:
#line 702 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4507 "parser.tab.c"
    break;

  case 238:
#line 703 "parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4513 "parser.tab.c"
    break;

  case 239:
#line 706 "parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4519 "parser.tab.c"
    break;

  case 240:
#line 707 "parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4525 "parser.tab.c"
    break;

  case 241:
#line 710 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4534 "parser.tab.c"
    break;

  case 242:
#line 716 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4543 "parser.tab.c"
    break;

  case 243:
#line 722 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4549 "parser.tab.c"
    break;

  case 244:
#line 723 "parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4555 "parser.tab.c"
    break;

  case 245:
#line 727 "parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4564 "parser.tab.c"
    break;

  case 246:
#line 731 "parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4573 "parser.tab.c"
    break;

  case 247:
#line 738 "parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4579 "parser.tab.c"
    break;

  case 248:
#line 739 "parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4585 "parser.tab.c"
    break;

  case 249:
#line 742 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4591 "parser.tab.c"
    break;

  case 250:
#line 743 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4597 "parser.tab.c"
    break;

  case 251:
#line 747 "parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4603 "parser.tab.c"
    break;

  case 252:
#line 748 "parser.y"
                                                { (yyval.var) = NULL; }
#line 4609 "parser.tab.c"
    break;

  case 253:
#line 751 "parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4618 "parser.tab.c"
    break;

  case 254:
#line 755 "parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4627 "parser.tab.c"
    break;

  case 255:
#line 761 "parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4637 "parser.tab.c"
    break;

  case 256:
#line 770 "parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4645 "parser.tab.c"
    break;

  case 257:
#line 773 "parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4653 "parser.tab.c"
    break;

  case 258:
#line 778 "parser.y"
                                                { (yyval.var) = NULL; }
#line 4659 "parser.tab.c"
    break;

  case 260:
#line 782 "parser.y"
                                                { (yyval.str) = NULL; }
#line 4665 "parser.tab.c"
    break;

  case 261:
#line 783 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4671 "parser.tab.c"
    break;

  case 262:
#line 784 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4677 "parser.tab.c"
    break;

  case 263:
#line 787 "parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4683 "parser.tab.c"
    break;

  case 264:
#line 789 "parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4689 "parser.tab.c"
    break;

  case 265:
#line 792 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4695 "parser.tab.c"
    break;

  case 266:
#line 793 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4701 "parser.tab.c"
    break;

  case 268:
#line 795 "parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4707 "parser.tab.c"
    break;

  case 269:
#line 796 "parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4713 "parser.tab.c"
    break;

  case 270:
#line 797 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4719 "parser.tab.c"
    break;

  case 271:
#line 798 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4725 "parser.tab.c"
    break;

  case 272:
#line 799 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4731 "parser.tab.c"
    break;

  case 273:
#line 800 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4737 "parser.tab.c"
    break;

  case 274:
#line 801 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4743 "parser.tab.c"
    break;

  case 275:
#line 802 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4749 "parser.tab.c"
    break;

  case 278:
#line 809 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4755 "parser.tab.c"
    break;

  case 279:
#line 810 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4761 "parser.tab.c"
    break;

  case 280:
#line 811 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4767 "parser.tab.c"
    break;

  case 281:
#line 812 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4773 "parser.tab.c"
    break;

  case 282:
#line 813 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4779 "parser.tab.c"
    break;

  case 283:
#line 814 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4785 "parser.tab.c"
    break;

  case 284:
#line 815 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4791 "parser.tab.c"
    break;

  case 285:
#line 816 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4797 "parser.tab.c"
    break;

  case 286:
#line 817 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4803 "parser.tab.c"
    break;

  case 287:
#line 820 "parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4809 "parser.tab.c"
    break;

  case 288:
#line 821 "parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4820 "parser.tab.c"
    break;

  case 289:
#line 829 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4829 "parser.tab.c"
    break;

  case 290:
#line 836 "parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4835 "parser.tab.c"
    break;

  case 291:
#line 839 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4841 "parser.tab.c"
    break;

  case 292:
#line 842 "parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 4847 "parser.tab.c"
    break;

  case 293:
#line 843 "parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4853 "parser.tab.c"
    break;

  case 294:
#line 847 "parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4859 "parser.tab.c"
    break;

  case 295:
#line 850 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4865 "parser.tab.c"
    break;

  case 296:
#line 851 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4871 "parser.tab.c"
    break;

  case 297:
#line 854 "parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4883 "parser.tab.c"
    break;

  case 298:
#line 863 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4889 "parser.tab.c"
    break;

  case 299:
#line 864 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4895 "parser.tab.c"
    break;

  case 300:
#line 867 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4901 "parser.tab.c"
    break;

  case 301:
#line 868 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4907 "parser.tab.c"
    break;

  case 302:
#line 874 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4915 "parser.tab.c"
    break;

  case 303:
#line 878 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4923 "parser.tab.c"
    break;

  case 304:
#line 883 "parser.y"
                                                { (yyval.type) = NULL; }
#line 4929 "parser.tab.c"
    break;

  case 305:
#line 884 "parser.y"
                                                { (yyval.type) = find_type_or_error2((yyvsp[0].str), 0); }
#line 4935 "parser.tab.c"
    break;

  case 306:
#line 887 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4941 "parser.tab.c"
    break;

  case 307:
#line 888 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4947 "parser.tab.c"
    break;

  case 308:
#line 891 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 4957 "parser.tab.c"
    break;

  case 309:
#line 899 "parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 4968 "parser.tab.c"
    break;

  case 310:
#line 909 "parser.y"
                                                { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 4976 "parser.tab.c"
    break;

  case 311:
#line 912 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 4982 "parser.tab.c"
    break;

  case 312:
#line 916 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 4988 "parser.tab.c"
    break;

  case 313:
#line 917 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 4994 "parser.tab.c"
    break;

  case 314:
#line 920 "parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5000 "parser.tab.c"
    break;

  case 315:
#line 921 "parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5006 "parser.tab.c"
    break;

  case 316:
#line 924 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5014 "parser.tab.c"
    break;

  case 317:
#line 930 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5022 "parser.tab.c"
    break;

  case 318:
#line 936 "parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5028 "parser.tab.c"
    break;

  case 319:
#line 937 "parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5034 "parser.tab.c"
    break;

  case 320:
#line 938 "parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5040 "parser.tab.c"
    break;

  case 321:
#line 942 "parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5046 "parser.tab.c"
    break;

  case 322:
#line 946 "parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5052 "parser.tab.c"
    break;

  case 323:
#line 949 "parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5058 "parser.tab.c"
    break;

  case 324:
#line 950 "parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5064 "parser.tab.c"
    break;

  case 325:
#line 953 "parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5070 "parser.tab.c"
    break;

  case 326:
#line 955 "parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5076 "parser.tab.c"
    break;

  case 327:
#line 958 "parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5082 "parser.tab.c"
    break;

  case 329:
#line 963 "parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5088 "parser.tab.c"
    break;

  case 330:
#line 964 "parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5094 "parser.tab.c"
    break;

  case 331:
#line 965 "parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5100 "parser.tab.c"
    break;

  case 332:
#line 970 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5106 "parser.tab.c"
    break;

  case 333:
#line 971 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5112 "parser.tab.c"
    break;

  case 335:
#line 976 "parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5118 "parser.tab.c"
    break;

  case 336:
#line 977 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5124 "parser.tab.c"
    break;

  case 337:
#line 978 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5130 "parser.tab.c"
    break;

  case 338:
#line 979 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5136 "parser.tab.c"
    break;

  case 339:
#line 985 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5142 "parser.tab.c"
    break;

  case 340:
#line 986 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5148 "parser.tab.c"
    break;

  case 342:
#line 993 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5154 "parser.tab.c"
    break;

  case 343:
#line 994 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5160 "parser.tab.c"
    break;

  case 344:
#line 998 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5166 "parser.tab.c"
    break;

  case 346:
#line 1004 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5172 "parser.tab.c"
    break;

  case 347:
#line 1005 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5178 "parser.tab.c"
    break;

  case 348:
#line 1006 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5184 "parser.tab.c"
    break;

  case 349:
#line 1008 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5192 "parser.tab.c"
    break;

  case 350:
#line 1012 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5200 "parser.tab.c"
    break;

  case 351:
#line 1020 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5206 "parser.tab.c"
    break;

  case 352:
#line 1021 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5212 "parser.tab.c"
    break;

  case 354:
#line 1028 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5218 "parser.tab.c"
    break;

  case 355:
#line 1029 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5224 "parser.tab.c"
    break;

  case 356:
#line 1033 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5230 "parser.tab.c"
    break;

  case 358:
#line 1041 "parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5236 "parser.tab.c"
    break;

  case 359:
#line 1042 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5242 "parser.tab.c"
    break;

  case 360:
#line 1043 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5248 "parser.tab.c"
    break;

  case 361:
#line 1044 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5254 "parser.tab.c"
    break;

  case 362:
#line 1046 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5262 "parser.tab.c"
    break;

  case 363:
#line 1050 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5270 "parser.tab.c"
    break;

  case 364:
#line 1056 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5276 "parser.tab.c"
    break;

  case 365:
#line 1057 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5282 "parser.tab.c"
    break;

  case 366:
#line 1060 "parser.y"
                                                { (yyval.expr) = NULL; }
#line 5288 "parser.tab.c"
    break;

  case 367:
#line 1061 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5294 "parser.tab.c"
    break;

  case 368:
#line 1064 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5303 "parser.tab.c"
    break;

  case 369:
#line 1071 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5309 "parser.tab.c"
    break;

  case 370:
#line 1073 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5315 "parser.tab.c"
    break;

  case 371:
#line 1077 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5321 "parser.tab.c"
    break;

  case 372:
#line 1078 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5327 "parser.tab.c"
    break;

  case 373:
#line 1082 "parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5333 "parser.tab.c"
    break;

  case 374:
#line 1083 "parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5339 "parser.tab.c"
    break;

  case 375:
#line 1084 "parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5345 "parser.tab.c"
    break;

  case 376:
#line 1085 "parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5351 "parser.tab.c"
    break;

  case 377:
#line 1086 "parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5357 "parser.tab.c"
    break;

  case 378:
#line 1090 "parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5363 "parser.tab.c"
    break;

  case 379:
#line 1091 "parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5369 "parser.tab.c"
    break;

  case 380:
#line 1092 "parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5375 "parser.tab.c"
    break;

  case 381:
#line 1095 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5381 "parser.tab.c"
    break;

  case 382:
#line 1098 "parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5387 "parser.tab.c"
    break;

  case 383:
#line 1099 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 5393 "parser.tab.c"
    break;

  case 384:
#line 1100 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5399 "parser.tab.c"
    break;

  case 385:
#line 1101 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5405 "parser.tab.c"
    break;

  case 386:
#line 1102 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5411 "parser.tab.c"
    break;

  case 387:
#line 1103 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5417 "parser.tab.c"
    break;

  case 388:
#line 1104 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5423 "parser.tab.c"
    break;

  case 389:
#line 1105 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5429 "parser.tab.c"
    break;

  case 390:
#line 1106 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5435 "parser.tab.c"
    break;

  case 391:
#line 1107 "parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5441 "parser.tab.c"
    break;

  case 392:
#line 1111 "parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5450 "parser.tab.c"
    break;

  case 393:
#line 1118 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5456 "parser.tab.c"
    break;

  case 394:
#line 1121 "parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5462 "parser.tab.c"
    break;

  case 395:
#line 1125 "parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5468 "parser.tab.c"
    break;

  case 396:
#line 1126 "parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5474 "parser.tab.c"
    break;

  case 397:
#line 1127 "parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5480 "parser.tab.c"
    break;

  case 402:
#line 1140 "parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5488 "parser.tab.c"
    break;

  case 403:
#line 1145 "parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5498 "parser.tab.c"
    break;

  case 404:
#line 1152 "parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5504 "parser.tab.c"
    break;

  case 405:
#line 1153 "parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5510 "parser.tab.c"
    break;

  case 406:
#line 1156 "parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5516 "parser.tab.c"
    break;

  case 407:
#line 1157 "parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5522 "parser.tab.c"
    break;

  case 408:
#line 1160 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5528 "parser.tab.c"
    break;

  case 409:
#line 1161 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5534 "parser.tab.c"
    break;

  case 410:
#line 1162 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5540 "parser.tab.c"
    break;


#line 5544 "parser.tab.c"

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
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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

#line 1164 "parser.y"


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

static attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
{
    attr_t *attr_existing;
    if (!attr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    LIST_FOR_EACH_ENTRY(attr_existing, list, attr_t, entry)
        if (attr_existing->type == attr->type)
        {
            parser_warning("duplicate attribute %s\n", get_attr_display_name(attr->type));
            /* use the last attribute, like MIDL does */
            list_remove(&attr_existing->entry);
            break;
        }
    list_add_tail( list, &attr->entry );
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
    type->c_name = format_namespace(namespace, "__x_", "_C", name);
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
  type_t *type = find_type(name, NULL, t);
  if (!type) {
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
  return find_type(name, current_namespace, 0) != NULL;
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
    unsigned int on_interface : 1;
    unsigned int on_function : 1;
    unsigned int on_arg : 1;
    unsigned int on_type : 1;
    unsigned int on_enum : 1;
    unsigned int on_struct : 2;
    unsigned int on_union : 1;
    unsigned int on_field : 1;
    unsigned int on_library : 1;
    unsigned int on_dispinterface : 1;
    unsigned int on_module : 1;
    unsigned int on_coclass : 1;
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF I Fn ARG T En St Un Fi  L  DI M  C  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "aggregatable" },
    /* ATTR_ANNOTATION */          { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTROL */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, "control" },
    /* ATTR_DECODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MAYBE */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 1, 0, 0, 1, 1, 2, 0, 0, 1, 0, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

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
