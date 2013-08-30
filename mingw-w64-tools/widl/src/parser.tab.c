/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yylval          parser_lval
#define yychar          parser_char
#define yydebug         parser_debug
#define yynerrs         parser_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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

#if defined(YYBYACC)
	/* Berkeley yacc (byacc) doesn't seem to know about these */
	/* Some *BSD supplied versions do define these though */
# ifndef YYEMPTY
#  define YYEMPTY	(-1)	/* Empty lookahead value of yychar */
# endif
# ifndef YYLEX
#  define YYLEX		yylex()
# endif

#elif defined(YYBISON)
	/* Bison was used for original development */
	/* #define YYEMPTY -2 */
	/* #define YYLEX   yylex() */

#else
	/* No yacc we know yet */
# if !defined(YYEMPTY) || !defined(YYLEX)
#  error Yacc version/type unknown. This version needs to be verified for settings of YYEMPTY and YYLEX.
# elif defined(__GNUC__)	/* gcc defines the #warning directive */
#  warning Yacc version/type unknown. It defines YYEMPTY and YYLEX, but is not tested
  /* #else we just take a chance that it works... */
# endif
#endif

#define YYERROR_VERBOSE

static unsigned char pointer_default = RPC_FC_UP;

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

typedef struct _decl_spec_t
{
  type_t *type;
  attr_list_t *attrs;
  enum storage_class stgclass;
} decl_spec_t;

typelist_t incomplete_types = LIST_INIT(incomplete_types);

static void fix_incomplete(void);
static void fix_incomplete_types(type_t *complete_type);

static str_list_t *append_str(str_list_t *list, char *str);
static attr_list_t *append_attr(attr_list_t *list, attr_t *attr);
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right, attr_t *attr, enum storage_class stgclass);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_attrp(enum attr_type type, void *val);
static expr_list_t *append_expr(expr_list_t *list, expr_t *expr);
static array_dims_t *append_array(array_dims_t *list, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, const declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface);
static ifref_t *make_ifref(type_t *iface);
static var_list_t *append_var_list(var_list_t *list, var_list_t *vars);
static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *p);
static declarator_t *make_declarator(var_t *var);
static type_t *make_safearray(type_t *type);
static typelib_t *make_library(const char *name, const attr_list_t *attrs);
static type_t *append_ptrchain_type(type_t *ptrchain, type_t *type);

static type_t *reg_typedefs(decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs);
static type_t *find_type_or_error(const char *name, int t);
static type_t *find_type_or_error2(char *name, int t);

static var_t *reg_const(var_t *var);

static char *gen_name(void);
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

static statement_t *make_statement(enum statement_type type);
static statement_t *make_statement_type_decl(type_t *type);
static statement_t *make_statement_reference(type_t *type);
static statement_t *make_statement_declaration(var_t *var);
static statement_t *make_statement_library(typelib_t *typelib);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names);
static statement_t *make_statement_import(const char *str);
static statement_t *make_statement_typedef(var_list_t *names);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);



/* Line 189 of yacc.c  */
#line 236 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     aIDENTIFIER = 258,
     aKNOWNTYPE = 259,
     aNUM = 260,
     aHEXNUM = 261,
     aDOUBLE = 262,
     aSTRING = 263,
     aWSTRING = 264,
     aSQSTRING = 265,
     aUUID = 266,
     aEOF = 267,
     SHL = 268,
     SHR = 269,
     MEMBERPTR = 270,
     EQUALITY = 271,
     INEQUALITY = 272,
     GREATEREQUAL = 273,
     LESSEQUAL = 274,
     LOGICALOR = 275,
     LOGICALAND = 276,
     ELLIPSIS = 277,
     tAGGREGATABLE = 278,
     tALLOCATE = 279,
     tANNOTATION = 280,
     tAPPOBJECT = 281,
     tASYNC = 282,
     tASYNCUUID = 283,
     tAUTOHANDLE = 284,
     tBINDABLE = 285,
     tBOOLEAN = 286,
     tBROADCAST = 287,
     tBYTE = 288,
     tBYTECOUNT = 289,
     tCALLAS = 290,
     tCALLBACK = 291,
     tCASE = 292,
     tCDECL = 293,
     tCHAR = 294,
     tCOCLASS = 295,
     tCODE = 296,
     tCOMMSTATUS = 297,
     tCONST = 298,
     tCONTEXTHANDLE = 299,
     tCONTEXTHANDLENOSERIALIZE = 300,
     tCONTEXTHANDLESERIALIZE = 301,
     tCONTROL = 302,
     tCPPQUOTE = 303,
     tDECODE = 304,
     tDEFAULT = 305,
     tDEFAULTBIND = 306,
     tDEFAULTCOLLELEM = 307,
     tDEFAULTVALUE = 308,
     tDEFAULTVTABLE = 309,
     tDISABLECONSISTENCYCHECK = 310,
     tDISPLAYBIND = 311,
     tDISPINTERFACE = 312,
     tDLLNAME = 313,
     tDOUBLE = 314,
     tDUAL = 315,
     tENABLEALLOCATE = 316,
     tENCODE = 317,
     tENDPOINT = 318,
     tENTRY = 319,
     tENUM = 320,
     tERRORSTATUST = 321,
     tEXPLICITHANDLE = 322,
     tEXTERN = 323,
     tFALSE = 324,
     tFASTCALL = 325,
     tFAULTSTATUS = 326,
     tFLOAT = 327,
     tFORCEALLOCATE = 328,
     tHANDLE = 329,
     tHANDLET = 330,
     tHELPCONTEXT = 331,
     tHELPFILE = 332,
     tHELPSTRING = 333,
     tHELPSTRINGCONTEXT = 334,
     tHELPSTRINGDLL = 335,
     tHIDDEN = 336,
     tHYPER = 337,
     tID = 338,
     tIDEMPOTENT = 339,
     tIGNORE = 340,
     tIIDIS = 341,
     tIMMEDIATEBIND = 342,
     tIMPLICITHANDLE = 343,
     tIMPORT = 344,
     tIMPORTLIB = 345,
     tIN = 346,
     tIN_LINE = 347,
     tINLINE = 348,
     tINPUTSYNC = 349,
     tINT = 350,
     tINT3264 = 351,
     tINT64 = 352,
     tINTERFACE = 353,
     tLCID = 354,
     tLENGTHIS = 355,
     tLIBRARY = 356,
     tLICENSED = 357,
     tLOCAL = 358,
     tLONG = 359,
     tMAYBE = 360,
     tMESSAGE = 361,
     tMETHODS = 362,
     tMODULE = 363,
     tNAMESPACE = 364,
     tNOCODE = 365,
     tNONBROWSABLE = 366,
     tNONCREATABLE = 367,
     tNONEXTENSIBLE = 368,
     tNOTIFY = 369,
     tNOTIFYFLAG = 370,
     tNULL = 371,
     tOBJECT = 372,
     tODL = 373,
     tOLEAUTOMATION = 374,
     tOPTIMIZE = 375,
     tOPTIONAL = 376,
     tOUT = 377,
     tPARTIALIGNORE = 378,
     tPASCAL = 379,
     tPOINTERDEFAULT = 380,
     tPROGID = 381,
     tPROPERTIES = 382,
     tPROPGET = 383,
     tPROPPUT = 384,
     tPROPPUTREF = 385,
     tPROXY = 386,
     tPTR = 387,
     tPUBLIC = 388,
     tRANGE = 389,
     tREADONLY = 390,
     tREF = 391,
     tREGISTER = 392,
     tREPRESENTAS = 393,
     tREQUESTEDIT = 394,
     tRESTRICTED = 395,
     tRETVAL = 396,
     tSAFEARRAY = 397,
     tSHORT = 398,
     tSIGNED = 399,
     tSIZEIS = 400,
     tSIZEOF = 401,
     tSMALL = 402,
     tSOURCE = 403,
     tSTATIC = 404,
     tSTDCALL = 405,
     tSTRICTCONTEXTHANDLE = 406,
     tSTRING = 407,
     tSTRUCT = 408,
     tSWITCH = 409,
     tSWITCHIS = 410,
     tSWITCHTYPE = 411,
     tTHREADING = 412,
     tTRANSMITAS = 413,
     tTRUE = 414,
     tTYPEDEF = 415,
     tUIDEFAULT = 416,
     tUNION = 417,
     tUNIQUE = 418,
     tUNSIGNED = 419,
     tUSESGETLASTERROR = 420,
     tUSERMARSHAL = 421,
     tUUID = 422,
     tV1ENUM = 423,
     tVARARG = 424,
     tVERSION = 425,
     tVIPROGID = 426,
     tVOID = 427,
     tWCHAR = 428,
     tWIREMARSHAL = 429,
     tAPARTMENT = 430,
     tNEUTRAL = 431,
     tSINGLE = 432,
     tFREE = 433,
     tBOTH = 434,
     ADDRESSOF = 435,
     NEG = 436,
     POS = 437,
     PPTR = 438,
     CAST = 439
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 155 "parser.y"

	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	array_dims_t *array_dims;
	type_t *type;
	var_t *var;
	var_list_t *var_list;
	declarator_t *declarator;
	declarator_list_t *declarator_list;
	statement_t *statement;
	statement_list_t *stmt_list;
	ifref_t *ifref;
	ifref_list_t *ifref_list;
	char *str;
	UUID *uuid;
	unsigned int num;
	double dbl;
	interface_info_t ifinfo;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;



/* Line 214 of yacc.c  */
#line 485 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 497 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3002

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  386
/* YYNRULES -- Number of states.  */
#define YYNSTATES  678

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   439

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   193,     2,     2,     2,   192,   185,     2,
     206,   207,   190,   189,   180,   188,   200,   191,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   182,   205,
     186,   208,   187,   181,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   201,     2,   202,   184,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,   183,   204,   194,     2,     2,     2,
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
     175,   176,   177,   178,   179,   195,   196,   197,   198,   199
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    12,    15,    18,    22,    25,
      28,    31,    34,    35,    38,    44,    47,    51,    54,    57,
      60,    63,    66,    67,    70,    71,    73,    75,    78,    81,
      83,    86,    88,    91,    93,    96,    98,   101,   104,   107,
     110,   115,   119,   123,   129,   132,   136,   141,   142,   144,
     146,   150,   152,   156,   160,   163,   167,   171,   174,   175,
     177,   181,   183,   187,   192,   194,   198,   199,   201,   206,
     208,   210,   212,   214,   216,   221,   226,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   251,   253,   255,
     257,   262,   264,   266,   268,   273,   278,   280,   282,   284,
     286,   291,   296,   301,   306,   311,   313,   318,   320,   322,
     327,   329,   334,   336,   338,   343,   348,   350,   352,   354,
     356,   358,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   381,   383,   385,   387,   392,   397,   399,   401,   403,
     405,   407,   414,   416,   421,   423,   425,   427,   432,   434,
     436,   438,   443,   448,   453,   458,   460,   462,   467,   472,
     477,   479,   481,   486,   491,   496,   498,   500,   502,   504,
     506,   508,   510,   511,   514,   519,   523,   524,   527,   529,
     531,   535,   539,   541,   547,   549,   553,   554,   556,   558,
     560,   562,   564,   566,   568,   570,   572,   574,   576,   582,
     586,   590,   594,   598,   602,   606,   610,   614,   618,   622,
     626,   630,   634,   638,   642,   646,   650,   654,   657,   660,
     663,   666,   669,   672,   676,   680,   686,   692,   697,   701,
     703,   707,   709,   711,   712,   715,   720,   724,   727,   730,
     731,   734,   737,   739,   743,   746,   748,   752,   755,   756,
     758,   759,   761,   763,   765,   767,   769,   771,   773,   776,
     779,   781,   783,   785,   787,   789,   791,   792,   794,   796,
     799,   801,   804,   807,   809,   811,   813,   816,   819,   822,
     828,   831,   832,   835,   838,   841,   844,   847,   850,   854,
     857,   861,   867,   873,   874,   877,   880,   883,   886,   893,
     902,   905,   908,   911,   914,   917,   920,   926,   928,   930,
     932,   934,   936,   937,   940,   943,   947,   948,   950,   953,
     956,   959,   963,   966,   968,   970,   974,   977,   982,   986,
     989,   991,   995,   998,   999,  1001,  1005,  1008,  1010,  1014,
    1019,  1023,  1026,  1028,  1032,  1035,  1036,  1038,  1040,  1044,
    1047,  1049,  1053,  1058,  1060,  1064,  1065,  1068,  1071,  1073,
    1077,  1079,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1105,  1107,  1109,  1111,  1113,  1116,  1118,  1121,  1123,
    1126,  1131,  1137,  1143,  1154,  1156,  1160
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     210,     0,    -1,   211,    -1,    -1,   211,   265,   203,   211,
     204,    -1,   211,   277,    -1,   211,   276,    -1,   211,   262,
     205,    -1,   211,   264,    -1,   211,   280,    -1,   211,   223,
      -1,   211,   215,    -1,    -1,   212,   277,    -1,   212,   265,
     203,   212,   204,    -1,   212,   276,    -1,   212,   262,   205,
      -1,   212,   264,    -1,   212,   280,    -1,   212,   215,    -1,
     212,   220,    -1,   212,   223,    -1,    -1,   213,   215,    -1,
      -1,   205,    -1,   217,    -1,   216,   205,    -1,   255,   205,
      -1,   219,    -1,   307,   205,    -1,   241,    -1,    65,     3,
      -1,   305,    -1,   153,     3,    -1,   308,    -1,   162,     3,
      -1,   230,   241,    -1,   230,   305,    -1,   230,   308,    -1,
      48,   206,     8,   207,    -1,    89,     8,   205,    -1,   218,
     212,    12,    -1,    90,   206,     8,   207,   214,    -1,   101,
       3,    -1,   230,   221,   203,    -1,   222,   212,   204,   214,
      -1,    -1,   226,    -1,   227,    -1,   225,   180,   227,    -1,
     225,    -1,   225,   180,    22,    -1,   230,   285,   296,    -1,
     285,   296,    -1,   201,   244,   202,    -1,   201,   190,   202,
      -1,   201,   202,    -1,    -1,   230,    -1,   201,   231,   202,
      -1,   233,    -1,   231,   180,   233,    -1,   231,   202,   201,
     233,    -1,     8,    -1,   232,   180,     8,    -1,    -1,    23,
      -1,    25,   206,     8,   207,    -1,    26,    -1,    27,    -1,
      29,    -1,    30,    -1,    32,    -1,    35,   206,   258,   207,
      -1,    37,   206,   245,   207,    -1,    41,    -1,    42,    -1,
      44,    -1,    45,    -1,    46,    -1,    47,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,   206,   247,   207,
      -1,    54,    -1,    55,    -1,    56,    -1,    58,   206,     8,
     207,    -1,    60,    -1,    61,    -1,    62,    -1,    63,   206,
     232,   207,    -1,    64,   206,   247,   207,    -1,    67,    -1,
      71,    -1,    73,    -1,    74,    -1,    76,   206,   246,   207,
      -1,    77,   206,     8,   207,    -1,    78,   206,     8,   207,
      -1,    79,   206,   246,   207,    -1,    80,   206,     8,   207,
      -1,    81,    -1,    83,   206,   246,   207,    -1,    84,    -1,
      85,    -1,    86,   206,   244,   207,    -1,    87,    -1,    88,
     206,   227,   207,    -1,    91,    -1,    94,    -1,   100,   206,
     242,   207,    -1,    99,   206,   246,   207,    -1,    99,    -1,
     102,    -1,   103,    -1,   105,    -1,   106,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     117,    -1,   118,    -1,   119,    -1,   120,   206,     8,   207,
      -1,   121,    -1,   122,    -1,   123,    -1,   125,   206,   304,
     207,    -1,   126,   206,     8,   207,    -1,   128,    -1,   129,
      -1,   130,    -1,   131,    -1,   133,    -1,   134,   206,   246,
     180,   246,   207,    -1,   135,    -1,   138,   206,   306,   207,
      -1,   139,    -1,   140,    -1,   141,    -1,   145,   206,   242,
     207,    -1,   148,    -1,   151,    -1,   152,    -1,   155,   206,
     244,   207,    -1,   156,   206,   306,   207,    -1,   158,   206,
     306,   207,    -1,   157,   206,   303,   207,    -1,   161,    -1,
     165,    -1,   166,   206,   306,   207,    -1,   167,   206,   234,
     207,    -1,    28,   206,   234,   207,    -1,   168,    -1,   169,
      -1,   170,   206,   309,   207,    -1,   171,   206,     8,   207,
      -1,   174,   206,   306,   207,    -1,   304,    -1,    11,    -1,
       8,    -1,    38,    -1,    70,    -1,   124,    -1,   150,    -1,
      -1,   236,   237,    -1,    37,   246,   182,   252,    -1,    50,
     182,   252,    -1,    -1,   239,   180,    -1,   239,    -1,   240,
      -1,   239,   180,   240,    -1,   258,   208,   246,    -1,   258,
      -1,    65,   257,   203,   238,   204,    -1,   243,    -1,   242,
     180,   243,    -1,    -1,   244,    -1,     5,    -1,     6,    -1,
       7,    -1,    69,    -1,   116,    -1,   159,    -1,     8,    -1,
       9,    -1,    10,    -1,     3,    -1,   244,   181,   244,   182,
     244,    -1,   244,    20,   244,    -1,   244,    21,   244,    -1,
     244,   183,   244,    -1,   244,   184,   244,    -1,   244,   185,
     244,    -1,   244,    16,   244,    -1,   244,    17,   244,    -1,
     244,   187,   244,    -1,   244,   186,   244,    -1,   244,    18,
     244,    -1,   244,    19,   244,    -1,   244,    13,   244,    -1,
     244,    14,   244,    -1,   244,   189,   244,    -1,   244,   188,
     244,    -1,   244,   192,   244,    -1,   244,   190,   244,    -1,
     244,   191,   244,    -1,   193,   244,    -1,   194,   244,    -1,
     189,   244,    -1,   188,   244,    -1,   185,   244,    -1,   190,
     244,    -1,   244,    15,     3,    -1,   244,   200,     3,    -1,
     206,   285,   292,   207,   244,    -1,   146,   206,   285,   292,
     207,    -1,   244,   201,   244,   202,    -1,   206,   244,   207,
      -1,   246,    -1,   245,   180,   246,    -1,   244,    -1,   244,
      -1,    -1,   248,   249,    -1,   229,   285,   301,   205,    -1,
     229,   308,   205,    -1,   253,   205,    -1,   230,   205,    -1,
      -1,   251,   250,    -1,   253,   205,    -1,   205,    -1,   229,
     285,   288,    -1,   229,   305,    -1,   255,    -1,   230,   285,
     302,    -1,   285,   302,    -1,    -1,   258,    -1,    -1,     3,
      -1,     4,    -1,     3,    -1,     4,    -1,    33,    -1,   173,
      -1,   261,    -1,   144,   261,    -1,   164,   261,    -1,   164,
      -1,    72,    -1,    59,    -1,    31,    -1,    66,    -1,    75,
      -1,    -1,    95,    -1,    95,    -1,   143,   260,    -1,   147,
      -1,   104,   260,    -1,    82,   260,    -1,    97,    -1,    39,
      -1,    96,    -1,    40,     3,    -1,    40,     4,    -1,   230,
     262,    -1,   263,   203,   266,   204,   214,    -1,   109,     3,
      -1,    -1,   266,   267,    -1,   229,   277,    -1,    57,     3,
      -1,    57,     4,    -1,   230,   268,    -1,   127,   182,    -1,
     270,   253,   205,    -1,   107,   182,    -1,   271,   254,   205,
      -1,   269,   203,   270,   271,   204,    -1,   269,   203,   274,
     205,   204,    -1,    -1,   182,     4,    -1,    98,     3,    -1,
      98,     4,    -1,   230,   274,    -1,   275,   273,   203,   213,
     204,   214,    -1,   275,   182,     3,   203,   219,   213,   204,
     214,    -1,   272,   214,    -1,   274,   205,    -1,   268,   205,
      -1,   108,     3,    -1,   108,     4,    -1,   230,   278,    -1,
     279,   203,   213,   204,   214,    -1,    68,    -1,   149,    -1,
     137,    -1,    93,    -1,    43,    -1,    -1,   284,   283,    -1,
     306,   286,    -1,   287,   306,   286,    -1,    -1,   287,    -1,
     283,   286,    -1,   282,   286,    -1,   281,   286,    -1,   190,
     284,   288,    -1,   235,   288,    -1,   289,    -1,   258,    -1,
     206,   288,   207,    -1,   289,   228,    -1,   289,   206,   224,
     207,    -1,   190,   284,   292,    -1,   235,   292,    -1,   293,
      -1,   190,   284,   296,    -1,   235,   296,    -1,    -1,   290,
      -1,   206,   291,   207,    -1,   293,   228,    -1,   228,    -1,
     206,   224,   207,    -1,   293,   206,   224,   207,    -1,   190,
     284,   296,    -1,   235,   296,    -1,   297,    -1,   190,   284,
     296,    -1,   235,   296,    -1,    -1,   294,    -1,   258,    -1,
     206,   295,   207,    -1,   297,   228,    -1,   228,    -1,   206,
     224,   207,    -1,   297,   206,   224,   207,    -1,   288,    -1,
     298,   180,   288,    -1,    -1,   182,   247,    -1,   294,   299,
      -1,   300,    -1,   301,   180,   300,    -1,   288,    -1,   288,
     208,   247,    -1,   175,    -1,   176,    -1,   177,    -1,   178,
      -1,   179,    -1,   136,    -1,   163,    -1,   132,    -1,   153,
     257,   203,   248,   204,    -1,   172,    -1,     4,    -1,   259,
      -1,   241,    -1,    65,     3,    -1,   305,    -1,   153,     3,
      -1,   308,    -1,   162,     3,    -1,   142,   206,   306,   207,
      -1,   229,   160,   229,   285,   298,    -1,   162,   257,   203,
     251,   204,    -1,   162,   257,   154,   206,   253,   207,   256,
     203,   236,   204,    -1,     5,    -1,     5,   200,     5,    -1,
       6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   331,   331,   345,   346,   348,   349,   350,   353,   356,
     357,   358,   361,   362,   363,   364,   365,   366,   369,   370,
     371,   372,   375,   376,   379,   380,   384,   385,   386,   387,
     388,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     403,   405,   413,   419,   423,   425,   429,   436,   437,   440,
     441,   444,   445,   449,   454,   461,   465,   466,   469,   470,
     474,   477,   478,   479,   482,   483,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   592,   593,   598,   599,
     600,   601,   604,   605,   608,   612,   618,   619,   620,   623,
     627,   639,   643,   648,   651,   652,   655,   656,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   698,   700,   701,   704,
     705,   708,   714,   720,   721,   724,   729,   736,   737,   740,
     741,   745,   746,   749,   753,   759,   767,   771,   776,   777,
     780,   781,   782,   785,   787,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   803,   804,   807,   808,
     809,   810,   811,   812,   813,   814,   817,   818,   826,   832,
     836,   840,   841,   845,   848,   849,   852,   861,   862,   865,
     866,   869,   875,   881,   882,   885,   886,   889,   899,   908,
     914,   918,   919,   922,   923,   926,   931,   938,   939,   940,
     944,   948,   951,   952,   955,   956,   960,   961,   965,   966,
     967,   971,   973,   975,   979,   980,   981,   982,   990,   992,
     994,   999,  1001,  1006,  1007,  1012,  1013,  1014,  1015,  1020,
    1029,  1031,  1032,  1037,  1039,  1043,  1044,  1051,  1052,  1053,
    1054,  1055,  1060,  1068,  1069,  1072,  1073,  1076,  1083,  1084,
    1089,  1090,  1094,  1095,  1096,  1097,  1098,  1102,  1103,  1104,
    1107,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,
    1119,  1122,  1130,  1132,  1138,  1139,  1140
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "aIDENTIFIER", "aKNOWNTYPE", "aNUM",
  "aHEXNUM", "aDOUBLE", "aSTRING", "aWSTRING", "aSQSTRING", "aUUID",
  "aEOF", "SHL", "SHR", "MEMBERPTR", "EQUALITY", "INEQUALITY",
  "GREATEREQUAL", "LESSEQUAL", "LOGICALOR", "LOGICALAND", "ELLIPSIS",
  "tAGGREGATABLE", "tALLOCATE", "tANNOTATION", "tAPPOBJECT", "tASYNC",
  "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN", "tBROADCAST",
  "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE", "tCDECL",
  "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST", "tCONTEXTHANDLE",
  "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE", "tCONTROL",
  "tCPPQUOTE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDOUBLE", "tDUAL",
  "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL",
  "tFAULTSTATUS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT3264", "tINT64",
  "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED", "tLOCAL",
  "tLONG", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE", "tNAMESPACE",
  "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE", "tNONEXTENSIBLE", "tNOTIFY",
  "tNOTIFYFLAG", "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE",
  "tOPTIONAL", "tOUT", "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT",
  "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF",
  "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER",
  "tREPRESENTAS", "tREQUESTEDIT", "tRESTRICTED", "tRETVAL", "tSAFEARRAY",
  "tSHORT", "tSIGNED", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE",
  "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT",
  "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS",
  "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
  "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG",
  "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT",
  "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "ADDRESSOF", "NEG", "POS", "PPTR", "CAST", "'.'", "'['", "']'",
  "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept", "input",
  "gbl_statements", "imp_statements", "int_statements", "semicolon_opt",
  "statement", "typedecl", "cppquote", "import_start", "import",
  "importlib", "libraryhdr", "library_start", "librarydef", "m_args",
  "arg_list", "args", "arg", "array", "m_attributes", "attributes",
  "attrib_list", "str_list", "attribute", "uuid_string", "callconv",
  "cases", "case", "enums", "enum_list", "enum", "enumdef", "m_exprs",
  "m_expr", "expr", "expr_list_int_const", "expr_int_const", "expr_const",
  "fields", "field", "ne_union_field", "ne_union_fields", "union_field",
  "s_field", "funcdef", "declaration", "m_ident", "t_ident", "ident",
  "base_type", "m_int", "int_std", "coclass", "coclasshdr", "coclassdef",
  "namespacedef", "coclass_ints", "coclass_int", "dispinterface",
  "dispinterfacehdr", "dispint_props", "dispint_meths", "dispinterfacedef",
  "inherit", "interface", "interfacehdr", "interfacedef", "interfacedec",
  "module", "modulehdr", "moduledef", "storage_cls_spec",
  "function_specifier", "type_qualifier", "m_type_qual_list", "decl_spec",
  "m_decl_spec_no_type", "decl_spec_no_type", "declarator",
  "direct_declarator", "abstract_declarator",
  "abstract_declarator_no_direct", "m_abstract_declarator",
  "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
      44,    63,    58,   124,    94,    38,    60,    62,    45,    43,
      42,    47,    37,    33,   126,   435,   436,   437,   438,   439,
      46,    91,    93,   123,   125,    59,    40,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   209,   210,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   214,   214,   215,   215,   215,   215,
     215,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   224,   225,
     225,   226,   226,   227,   227,   228,   228,   228,   229,   229,
     230,   231,   231,   231,   232,   232,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   234,   234,   235,   235,
     235,   235,   236,   236,   237,   237,   238,   238,   238,   239,
     239,   240,   240,   241,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     245,   246,   247,   248,   248,   249,   249,   250,   250,   251,
     251,   252,   252,   253,   253,   254,   255,   255,   256,   256,
     257,   257,   257,   258,   258,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   260,   260,   261,   261,
     261,   261,   261,   261,   261,   261,   262,   262,   263,   264,
     265,   266,   266,   267,   268,   268,   269,   270,   270,   271,
     271,   272,   272,   273,   273,   274,   274,   275,   276,   276,
     276,   277,   277,   278,   278,   279,   280,   281,   281,   281,
     282,   283,   284,   284,   285,   285,   286,   286,   287,   287,
     287,   288,   288,   288,   289,   289,   289,   289,   290,   290,
     290,   291,   291,   292,   292,   293,   293,   293,   293,   293,
     294,   294,   294,   295,   295,   296,   296,   297,   297,   297,
     297,   297,   297,   298,   298,   299,   299,   300,   301,   301,
     302,   302,   303,   303,   303,   303,   303,   304,   304,   304,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   307,   308,   308,   309,   309,   309
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     5,     2,     2,     3,     2,     2,
       2,     2,     0,     2,     5,     2,     3,     2,     2,     2,
       2,     2,     0,     2,     0,     1,     1,     2,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     2,     2,     2,
       4,     3,     3,     5,     2,     3,     4,     0,     1,     1,
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
       1,     2,     2,     1,     1,     1,     2,     2,     2,     5,
       2,     0,     2,     2,     2,     2,     2,     2,     3,     2,
       3,     5,     5,     0,     2,     2,     2,     2,     6,     8,
       2,     2,     2,     2,     2,     2,     5,     1,     1,     1,
       1,     1,     0,     2,     2,     3,     0,     1,     2,     2,
       2,     3,     2,     1,     1,     3,     2,     4,     3,     2,
       1,     3,     2,     0,     1,     3,     2,     1,     3,     4,
       3,     2,     1,     3,     2,     0,     1,     1,     3,     2,
       1,     3,     4,     1,     3,     0,     2,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       4,     5,     5,    10,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     2,     1,   372,   263,   255,   274,     0,   311,
       0,     0,   262,   250,   264,   307,   261,   265,   266,     0,
     310,   268,   275,   273,     0,   266,     0,   309,     0,   266,
       0,   270,   308,   250,   250,   260,   371,   256,    66,    11,
       0,    26,    12,    29,    12,    10,     0,    59,   374,     0,
     373,   257,     0,     0,     8,     0,     0,     0,    24,     0,
     293,     6,     5,     0,     9,   316,   316,   316,     0,     0,
     376,   316,     0,   378,   276,   277,     0,   284,   285,   375,
     252,     0,   267,   272,     0,   295,   296,   271,   280,     0,
     269,   258,   377,     0,   379,     0,   259,    67,     0,    69,
      70,     0,    71,    72,    73,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    87,    88,
      89,     0,    91,    92,    93,     0,     0,    96,    97,    98,
      99,     0,     0,     0,     0,     0,   105,     0,   107,   108,
       0,   110,     0,   112,   113,   116,     0,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,   131,   132,   133,     0,     0,   136,   137,   138,   139,
     369,   140,     0,   142,   367,     0,   144,   145,   146,     0,
     148,   149,   150,     0,     0,     0,     0,   155,   368,   156,
       0,     0,   160,   161,     0,     0,     0,     0,    61,   165,
      27,    58,    58,    58,   250,     0,     0,   250,   250,     0,
     374,   278,   286,   297,   305,     0,   376,   378,    28,     7,
     281,     3,   302,     0,    25,   300,   301,     0,     0,    22,
     320,   317,   319,   318,   253,   254,   168,   169,   170,   171,
     312,     0,     0,   324,   360,   323,   247,   374,   376,   316,
     378,   314,    30,     0,   176,    41,     0,   233,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    60,    42,     0,    19,    20,    21,
       0,    17,     0,    15,    13,    18,    24,     0,    59,   375,
      44,   303,   304,   377,   379,    45,   246,    58,    58,     0,
      58,     0,     0,   294,    22,    58,     0,     0,   322,     0,
       0,    47,   326,   315,    40,     0,   178,   179,   182,   380,
      58,    58,    58,     0,   167,   166,     0,     0,   197,   188,
     189,   190,   194,   195,   196,   191,   192,     0,   193,     0,
       0,     0,     0,     0,     0,     0,   231,     0,   229,   232,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,     0,     0,   184,   187,     0,
       0,     0,     0,     0,     0,     0,     0,   362,   363,   364,
     365,   366,     0,     0,     0,     0,   384,   386,     0,     0,
       0,    62,    66,     0,    16,    12,    46,     0,    24,     0,
     282,     4,   287,     0,     0,     0,     0,     0,     0,    58,
      24,    23,    59,   313,   321,   325,   361,     0,    57,     0,
       0,    51,    48,    49,   183,   177,     0,   370,     0,   234,
       0,   382,    59,   240,     0,    68,   159,    74,     0,   221,
     220,   219,   222,   217,   218,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    86,    90,     0,    94,    95,   100,   101,   102,   103,
     104,   106,   109,   111,   345,   312,    47,   350,   345,   347,
     346,    54,   342,   115,   186,   114,   130,   134,   135,     0,
     143,   147,   151,   152,   154,   153,   157,   158,     0,   162,
     163,   164,    63,     0,    58,   353,   381,   279,   283,   289,
       0,   376,   288,   291,     0,     0,   245,   292,    22,    24,
     306,    56,    55,   327,     0,   180,   181,     0,   378,   248,
     238,   237,   333,   228,   312,    47,   337,   333,   334,     0,
     330,   210,   211,   223,   204,   205,   208,   209,   199,   200,
       0,   201,   202,   203,   207,   206,   213,   212,   215,   216,
     214,   224,     0,   230,    65,    53,   345,   312,     0,   345,
       0,   341,    47,   349,   185,     0,   385,    24,    14,     0,
     243,   290,    58,   298,    52,    50,   355,   358,     0,   236,
       0,   249,     0,   333,   312,     0,   345,     0,   329,     0,
      47,   336,     0,   227,   340,   345,   351,   344,   348,     0,
     141,    43,   354,    24,     0,   357,     0,   235,   172,   226,
     328,   345,   338,   332,   335,   225,     0,   198,   343,   352,
     299,   356,   359,     0,   331,   339,     0,     0,   383,   173,
       0,    58,    58,   242,   175,     0,   174,   241
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   201,   325,   225,   297,    40,    41,    42,
      43,   298,   209,    44,   299,   440,   441,   442,   443,   507,
      46,   308,   197,   373,   198,   346,   508,   663,   669,   335,
     336,   337,   247,   386,   387,   366,   367,   368,   370,   340,
     449,   453,   342,   674,   675,   545,    49,   620,    81,   509,
      50,    83,    51,   300,    53,   301,   302,   317,   420,    56,
      57,   320,   426,    58,   228,    59,    60,   303,   304,   214,
      63,   305,    65,    66,    67,   326,    68,   230,    69,   244,
     245,   568,   627,   569,   570,   510,   600,   511,   512,   536,
     645,   617,   618,   246,   402,   199,   248,    71,    72,   250,
     408
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -531
static const yytype_int16 yypact[] =
{
    -531,    75,  1662,  -531,  -531,  -531,  -531,  -531,    95,  -531,
     -91,   151,  -531,   240,  -531,  -531,  -531,  -531,    37,   116,
    -531,  -531,  -531,  -531,   245,    37,   156,  -531,   -30,    37,
     525,  -531,  -531,   249,   251,   525,  -531,  -531,  2828,  -531,
     -23,  -531,  -531,  -531,  -531,  -531,    24,  2505,    -9,    -7,
    -531,  -531,    -4,    54,  -531,    58,     6,    62,    16,    67,
      96,  -531,  -531,    79,  -531,     9,     9,     9,   446,  2677,
      80,     9,    85,    97,  -531,  -531,   170,  -531,  -531,  -138,
    -531,   100,  -531,  -531,    99,  -531,  -531,  -531,  -531,  2677,
    -531,  -531,   -56,   102,  -111,  -110,  -531,  -531,     0,  -531,
    -531,   103,  -531,  -531,  -531,   106,   107,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,   112,  -531,  -531,
    -531,   125,  -531,  -531,  -531,   130,   131,  -531,  -531,  -531,
    -531,   142,   143,   150,   161,   162,  -531,   163,  -531,  -531,
     165,  -531,   166,  -531,  -531,   167,   171,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,
     172,  -531,  -531,  -531,   175,   177,  -531,  -531,  -531,  -531,
    -531,  -531,   178,  -531,  -531,   182,  -531,  -531,  -531,   183,
    -531,  -531,  -531,   184,   185,   186,   187,  -531,  -531,  -531,
     188,   190,  -531,  -531,   191,   193,   194,   -51,  -531,  -531,
    -531,  1545,   850,   110,   256,   305,   264,   273,   277,   119,
     196,  -531,  -531,  -531,  -531,   446,   206,   207,  -531,  -531,
    -531,  -531,  -531,   -32,  -531,  -531,  -531,   292,   212,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,
    -531,   446,   446,  -531,   208,  -133,  -531,  -531,  -531,     9,
    -531,  -531,  -531,   210,   296,  -531,   214,  -531,   216,  -531,
     406,   158,   296,   449,   449,   412,   415,   449,   449,   418,
     421,   449,   426,   449,   449,  2093,   449,   449,   429,   -87,
     430,   449,  2677,   449,   449,  2677,   -14,  2677,  2677,   158,
     211,   433,  2677,  2828,   241,  -531,   237,  -531,  -531,  -531,
     243,  -531,   242,  -531,  -531,  -531,    16,  2591,  -531,   250,
    -531,  -531,  -531,   250,  -107,  -531,  -531,   -34,  1084,   278,
     -75,   257,   260,  -531,  -531,  1170,   101,   258,  -531,   449,
      81,  2093,  -531,  -531,  -531,   263,   284,  -531,   261,  -531,
     -29,   110,   -27,   267,  -531,  -531,   268,   269,  -531,  -531,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,   276,  -531,   449,
     449,   449,   449,   449,   449,   706,  2316,  -129,  -531,  2316,
     272,   279,  -531,  -127,   281,   282,   285,   287,   288,   294,
     295,   777,   301,  2591,   443,   303,   -99,  -531,  2316,   304,
     307,   308,   290,   312,   -80,  2099,   314,  -531,  -531,  -531,
    -531,  -531,   317,   318,   324,   326,   283,  -531,   327,   329,
     333,  -531,  2828,   477,  -531,  -531,  -531,   446,    16,     5,
    -531,  -531,  -531,   309,  2591,   343,  1428,   347,   464,  1256,
      16,  -531,  2591,  -531,  -531,  -531,  -531,   104,  -531,  2254,
     348,   374,  -531,  -531,  -531,   296,   449,  -531,  2591,  -531,
     349,  -531,   353,  -531,   354,  -531,  -531,  -531,  2591,    18,
      18,    18,    18,    18,    18,  2185,   316,   449,   449,   557,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   563,   449,   449,
    -531,  -531,  -531,   560,  -531,  -531,  -531,  -531,  -531,  -531,
    -531,  -531,  -531,  -531,   443,  -531,  1748,  -531,   443,  -531,
    -531,  -531,   -73,  -531,   449,  -531,  -531,  -531,  -531,   449,
    -531,  -531,  -531,  -531,  -531,  -531,  -531,  -531,   564,  -531,
    -531,  -531,  -531,   364,   967,  -531,   399,  -531,  -531,  -531,
     446,   -24,  -531,  -531,  2591,   375,  -531,  -531,  -531,    16,
    -531,  -531,  -531,  -531,  2007,  -531,  -531,   443,   376,   296,
    -531,  -531,   316,  -531,  -531,  1875,  -531,   316,  -531,   377,
     -70,   218,   218,  -531,   531,   531,   338,   338,  2210,   174,
     646,  1263,  1350,  2332,   338,   338,    22,    22,    18,    18,
      18,  -531,  2294,  -531,  -531,  -531,    36,  -531,   379,   443,
     380,  -531,  2093,  -531,  -531,   381,  -531,    16,  -531,   446,
    -531,  -531,  1342,  -531,  -531,  -531,   400,  -531,  -120,  -531,
     386,  -531,   383,   554,  -531,   384,   443,   387,  -531,   449,
    2093,  -531,   449,  -531,  -531,    36,  -531,  -531,  -531,   391,
    -531,  -531,  -531,    16,   449,  -531,   443,  -531,  -531,  -531,
    -531,    36,  -531,  -531,  -531,    18,   392,  2316,  -531,  -531,
    -531,  -531,  -531,    32,  -531,  -531,   449,   401,  -531,  -531,
     419,   -67,   -67,  -531,  -531,   397,  -531,  -531
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -531,  -531,   382,   -33,  -301,  -293,    -1,  -531,  -531,  -531,
     176,  -531,  -531,  -531,    23,  -482,  -531,  -531,  -253,  -228,
    -199,    -2,  -531,  -531,  -267,   320,   -62,  -531,  -531,  -531,
    -531,   160,     7,   323,    98,   213,  -531,  -261,  -259,  -531,
    -531,  -531,  -531,   -58,  -219,  -531,   192,  -531,    38,   -47,
    -531,   127,   105,    17,  -531,    26,    27,  -531,  -531,   569,
    -531,  -531,  -531,  -531,  -531,     8,  -531,    28,    12,  -531,
    -531,    29,  -531,  -531,  -308,  -467,   -45,   -25,    -8,  -207,
    -531,  -531,  -531,  -506,  -531,  -530,  -531,  -128,  -531,  -531,
    -531,   -21,  -531,   402,  -531,   344,     1,   -53,  -531,     3,
    -531
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -252
static const yytype_int16 yytable[] =
{
      47,    39,   215,    70,   307,    73,   242,   375,   374,    48,
     378,   202,   380,   416,    62,   385,   249,   332,   433,    52,
     392,   243,   382,   429,   598,    45,   411,   616,    54,    55,
      61,    64,   423,   469,   327,   328,   256,   469,   596,   234,
     235,   232,   233,  -251,   258,   170,   251,  -251,   216,   174,
     217,   489,     9,   493,   210,   213,   622,   231,   231,   231,
     646,   628,    11,   231,   211,  -251,    24,   -32,   330,   666,
     436,    93,    95,   331,   236,     3,   188,    15,   490,     9,
     494,   514,   667,   625,   348,   647,   349,   350,   351,   352,
     353,   354,  -251,   259,   -36,   319,  -251,   623,    74,    75,
     514,   425,    20,    24,   234,   235,   237,   348,   515,   349,
     350,   351,   352,   353,   354,    76,   616,   650,   419,   434,
     639,   424,   450,   454,    84,   537,    38,   521,   330,   293,
     635,   330,    82,   602,    38,    91,   630,   550,   673,   236,
      96,   448,   424,   424,     9,   532,    27,  -251,   656,   -34,
     355,   294,    87,   242,    77,    78,    90,   651,    32,    88,
     238,   397,   398,   399,   400,   401,   344,    38,   243,   345,
     418,   237,    38,   355,    38,   447,    89,   451,   253,   242,
     242,  -244,   200,  -244,   203,   556,   239,   467,   468,   469,
     470,   471,   472,   473,   243,   243,   -31,   356,   218,    47,
      47,   219,    70,    70,    73,    73,   260,   338,    48,    48,
     535,   222,   484,   485,   486,   347,   406,   407,   487,   488,
     356,   224,   487,   488,   333,   238,   505,   357,   593,   393,
     384,   321,   396,   469,   403,   404,   668,   330,   566,   410,
     358,   231,   506,    79,    80,    93,    95,   612,    85,    86,
     357,   239,    92,    80,    94,    80,   613,   220,   605,   309,
      80,   221,   417,   358,   242,   223,   359,   311,   312,   360,
     361,   437,   226,   383,   363,   364,   313,    80,   227,   243,
     314,    80,   229,   438,   603,   -33,   384,   365,   433,   359,
     252,   240,   360,   361,   362,   322,   323,   363,   364,   234,
     235,   615,   -35,   254,   255,   257,   551,   241,   310,   261,
     365,    38,   262,   263,   641,   433,    47,    39,   264,    70,
     466,    73,   315,   432,   431,    48,    70,   433,    73,   383,
      62,   265,    48,   610,   566,    52,   266,   267,   504,   566,
     452,    45,   631,   433,    54,    55,    61,    64,   268,   269,
     660,   467,   468,   469,   236,   242,   270,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   271,   272,   273,
     243,   274,   275,   276,   487,   488,   595,   277,   278,   540,
     601,   279,   534,   280,   281,   661,   237,   215,   282,   283,
     284,   285,   286,   287,   288,   566,   289,   290,   338,   291,
     292,   -37,   642,   557,   567,   670,   482,   483,   484,   485,
     486,   -38,   -39,   562,   343,   324,   329,   334,   487,   488,
     371,   339,   341,   372,   544,   541,   376,   432,   431,   377,
      70,   538,    73,   216,   379,   217,    48,   389,   391,   210,
     238,   409,   412,   413,   599,   415,   234,   235,   414,   234,
     235,   558,   348,  -251,   349,   350,   351,   352,   353,   354,
     422,   384,   427,   428,   445,   435,   239,   444,   634,   446,
     519,   637,   424,   424,   455,   456,   457,   369,   242,   491,
     369,   236,   458,   528,   236,   533,   492,   381,   495,   496,
     388,   539,   497,   243,   498,   499,   388,   395,   653,   215,
     567,   500,   501,   626,   383,   567,   564,   658,   503,   384,
     513,   516,   621,   237,   517,   518,   237,   330,   355,   520,
     384,   523,   565,   664,   524,   525,   482,   483,   484,   485,
     486,   526,    47,   527,   529,    70,   530,    73,   487,   488,
     531,    48,   369,   439,   467,   468,   469,   242,   542,   472,
     473,   547,   383,    19,   554,   553,   559,   384,   560,   561,
     573,   567,   243,   383,     7,   356,   591,   238,   594,   606,
     238,   607,   459,   460,   461,   462,   463,   464,   465,   609,
     611,   619,   644,   671,   629,   384,   636,   638,   640,   648,
     649,   652,   236,   239,   654,   357,   239,     9,   659,   665,
     383,   672,   677,   318,   548,   555,   394,    18,   358,   405,
     432,   431,   604,    70,   676,    73,   212,   316,   546,    48,
      21,    22,    23,   390,   237,   662,     0,     0,   383,    25,
       0,     0,     0,   505,   359,     0,   240,   360,   361,   362,
       0,     0,   363,   364,   330,     0,     0,     0,     0,   506,
     462,     0,   241,     0,     0,   365,     0,     0,     0,   467,
     468,   469,   470,   471,   472,   473,   474,   475,    29,     0,
       0,     0,    31,     0,     0,     0,     0,     0,   238,     0,
     571,   572,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
       0,   592,     0,     0,   239,     0,     0,     0,     0,   348,
       4,   349,   350,   351,   352,   353,   354,   480,   481,   482,
     483,   484,   485,   486,     0,     0,     0,   388,     0,     0,
       0,   487,   488,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     0,   564,     7,     0,     0,     0,     9,
       0,     0,     0,     0,     0,   330,     0,     0,     0,     0,
     565,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,   204,    14,     0,    15,   355,     0,     0,    16,     0,
       0,    17,     0,     0,     0,     0,     0,     0,    18,     0,
     467,   468,   469,   470,   471,   472,   473,   474,   475,    20,
       0,    21,    22,    23,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,     0,     0,     0,     0,   476,   632,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     0,
       0,     0,   655,    27,     0,   657,   487,   488,    28,    29,
      30,     0,   357,    31,     4,    32,     0,   369,     0,   207,
       0,     0,     0,     0,     0,   358,     0,     0,   208,     0,
      35,     0,     0,     0,     0,     0,     0,     0,    36,    37,
       0,     5,     0,     6,     0,     0,     0,     0,     0,     7,
       8,   359,     0,     9,   360,   361,   362,     0,    10,   363,
     364,     0,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,   365,     0,     0,    13,    14,     0,    15,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     0,    19,
     296,     0,     0,    20,     0,    21,    22,    23,    24,     0,
       0,     0,     0,     0,    25,     0,     0,     0,   476,    26,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
       0,     4,     0,     0,     0,     0,     0,   487,   488,     0,
       0,     0,     0,     0,   502,     0,     0,    27,     0,     0,
       0,     0,    28,    29,    30,     0,     0,    31,     5,    32,
       6,     0,     0,    33,     0,     0,     7,     8,     0,     0,
       9,     0,    34,     0,    35,    10,     0,     0,     0,     0,
       0,     0,    36,    37,    11,     0,    12,     0,     0,     0,
       0,     0,    13,    14,     0,    15,     0,     0,     0,    16,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    18,
       0,    38,     0,     0,   306,     0,    19,   296,     0,     0,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    28,
      29,    30,     0,     0,    31,     5,    32,     6,     0,     0,
      33,     0,     0,     7,     8,     0,     0,     9,     0,    34,
       0,    35,    10,     0,     0,     0,     0,     0,     0,    36,
      37,    11,     0,    12,     0,     0,     0,     0,     0,    13,
      14,     0,    15,     0,     0,     0,    16,     0,     0,    17,
       0,     0,     0,     0,     0,     0,    18,     0,    38,     0,
       0,   608,     0,    19,     4,     0,     0,    20,     0,    21,
      22,    23,    24,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     9,     0,     0,     0,     0,    10,     0,
       0,    27,     0,     0,     0,     0,    28,    29,    30,    12,
       0,    31,     0,    32,     0,    13,    14,    33,    15,     0,
       0,     0,    16,     0,     0,    17,    34,     0,    35,     0,
       0,     0,    18,     0,     0,     0,    36,    37,     0,    19,
       4,     0,     0,    20,     0,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    25,     0,   467,   468,   469,   470,
     471,   472,   473,     0,     0,    38,     0,     5,   421,     6,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     9,
       0,     0,     0,     0,    10,     0,     0,    27,     0,     0,
       0,     0,    28,    29,    30,    12,     0,    31,     0,    32,
       0,    13,    14,    33,    15,     0,     0,     0,    16,     0,
       0,    17,    34,     0,    35,     0,     0,     0,    18,     0,
       0,     0,    36,    37,     0,    19,     4,     0,     0,    20,
       0,    21,    22,    23,     0,     0,     0,     0,     0,     0,
      25,     0,     0,   467,   468,   469,   470,   471,   472,   473,
       0,    38,     0,     5,   430,     6,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     9,     0,     0,     0,     0,
      10,     0,     0,    27,     0,     0,     0,     0,    28,    29,
      30,    12,     0,    31,     0,    32,     0,    13,    14,    33,
      15,     0,     0,     0,    16,     0,     0,    17,    34,     0,
      35,     0,     0,     0,    18,     0,     0,     0,    36,    37,
       0,    19,     4,     0,     0,    20,     0,    21,    22,    23,
       0,     0,     0,     0,     0,     0,    25,   478,   479,   480,
     481,   482,   483,   484,   485,   486,     0,    38,     0,     5,
     549,     6,     0,   487,   488,     0,     0,     7,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,    28,    29,    30,    12,     0,    31,
       0,    32,     0,   204,    14,    33,    15,     0,     0,     0,
      16,     0,     0,    17,    34,     0,    35,     0,     0,     0,
      18,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,     0,     0,     0,     0,
       0,     0,    25,     0,     0,   479,   480,   481,   482,   483,
     484,   485,   486,    38,     0,     0,   643,     0,     0,     4,
     487,   488,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
      28,    29,    30,     0,     0,    31,     5,    32,     6,     0,
       0,   207,     0,     0,     7,     8,     0,     0,     9,     0,
     208,     0,    35,    10,     0,     0,     0,     0,     0,     0,
      36,    37,    11,     0,    12,     0,     0,     0,     0,     0,
      13,    14,     0,    15,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     0,     0,     0,     0,    18,     0,    38,
       0,     0,   543,     0,    19,   296,     0,     0,    20,     0,
      21,    22,    23,    24,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,    31,     5,    32,     6,     0,     0,    33,     0,
       0,     7,     8,     0,     0,     9,     0,    34,     0,    35,
      10,     0,     0,     0,     0,     0,     0,    36,    37,    11,
       0,    12,     0,     0,     0,     0,     0,    13,    14,     0,
      15,     0,     0,     0,    16,     0,     0,    17,     0,     0,
       0,     0,     0,     0,    18,     0,    38,     0,     0,     0,
       0,    19,     4,     0,     0,    20,     0,    21,    22,    23,
      24,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     6,     0,     0,     0,     0,   236,     7,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,    28,    29,    30,    12,     0,    31,
       0,    32,     0,   204,    14,    33,    15,     0,   237,     0,
      16,     0,   -58,    17,    34,     0,    35,     0,     0,     0,
      18,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,     0,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
      28,    29,    30,     0,     0,    31,     0,    32,   239,     0,
       0,   207,     0,     0,     0,     0,     5,     0,     6,     0,
     208,     0,    35,   236,     7,     0,     0,     0,     9,     0,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,   597,     0,
     204,    14,     0,    15,     0,   237,     0,    16,     0,    38,
      17,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,    23,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,    27,     0,     0,     0,     0,    28,    29,    30,
       0,     0,    31,     0,    32,   239,     0,     0,   207,   614,
       0,     0,     0,     0,     0,     0,     0,   208,     5,    35,
       6,     0,     0,     0,     0,     0,     7,    36,    37,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   624,    12,     0,     0,     0,
       0,     0,   204,    14,     0,    15,    38,     0,     0,    16,
       0,     0,    17,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
      20,     0,    21,    22,    23,     0,     0,     0,     0,     0,
       0,    25,   467,   468,   469,   470,   471,   472,   473,   474,
     475,     0,     0,     0,     5,     0,     6,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,    28,
      29,    30,    12,     0,    31,     0,    32,     0,   204,    14,
     207,    15,     0,     0,     0,    16,     0,     0,    17,   208,
       0,    35,     0,     0,     0,    18,     0,     0,     0,    36,
      37,     0,     0,     0,     0,     0,    20,     0,    21,    22,
      23,     0,     0,     0,     0,     0,     0,    25,   467,   468,
     469,   470,   471,   472,   473,   474,   475,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   467,   468,   469,   470,   471,   472,   473,
      27,   475,     0,     0,     0,    28,    29,    30,     0,     0,
      31,     0,    32,     0,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,    35,     0,     0,
       0,     0,     0,     0,     0,    36,    37,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
     476,     0,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,     0,     0,    38,     0,     0,     0,     0,   487,
     488,     0,     0,     0,     0,     0,   522,   467,   468,   469,
     470,   471,   472,   473,   474,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
     468,   469,   470,   471,   472,   473,   474,   475,     0,     0,
       0,     0,     0,     0,     0,   467,   468,   469,   470,   471,
     472,   473,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   476,     0,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,     0,     0,
       0,     0,     0,     0,     0,   487,   488,     0,     0,     0,
       0,     0,   563,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,     0,     0,     0,     0,     0,     0,     0,
     487,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,     0,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   552,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,     0,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   633,   476,     0,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,     4,
       0,     0,     0,     0,     0,     0,   487,   488,   480,   481,
     482,   483,   484,   485,   486,     0,     0,     0,     0,     0,
       0,     0,   487,   488,     0,     0,     5,     0,     6,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,     0,     0,
     204,    14,     0,    15,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,    20,     0,
      21,    22,    23,    24,     0,     0,   205,     0,     0,    25,
       0,     0,     0,   206,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     6,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,    28,    29,    30,
      12,     0,    31,     0,    32,     0,   204,    14,   207,    15,
       0,     0,     0,    16,     0,     0,    17,   208,     0,    35,
       0,     0,     0,    18,     0,     0,     0,    36,    37,     0,
       0,     4,     0,     0,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       6,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    28,    29,    30,    12,     0,    31,     0,
      32,     0,   204,    14,   207,     0,     0,     0,     0,    16,
       0,     0,    17,   208,     0,    35,     0,     0,     0,    18,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,    31,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,    35,     0,     0,     0,     0,     0,     0,     0,    36,
      37,    97,     0,    98,    99,   100,   101,   102,   103,     0,
     104,     0,     0,   105,     0,   106,     0,     0,     0,   107,
     108,     0,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,   118,   119,   120,     0,   121,     0,   122,   123,
     124,   125,   126,     0,     0,   127,     0,     0,     0,   128,
       0,   129,   130,     0,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   139,   140,   141,   142,     0,     0,   143,
       0,     0,   144,     0,     0,     0,     0,   145,   146,     0,
     147,   148,     0,   149,   150,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,   175,   176,   177,   178,
       0,     0,     0,   179,     0,     0,   180,     0,     0,   181,
     182,     0,     0,   183,   184,   185,   186,     0,     0,   187,
       0,   188,     0,   189,   190,   191,   192,   193,   194,   195,
       0,     0,   196
};

static const yytype_int16 yycheck[] =
{
       2,     2,    47,     2,   203,     2,    68,   268,   267,     2,
     271,    44,   273,   306,     2,   276,    69,   245,   326,     2,
     281,    68,   275,   324,   506,     2,   293,   557,     2,     2,
       2,     2,   107,    15,   241,   242,    89,    15,   505,     3,
       4,    66,    67,   154,   154,   132,    71,   154,    47,   136,
      47,   180,    43,   180,    47,    47,   562,    65,    66,    67,
     180,   567,    57,    71,    47,   203,    98,   205,   201,    37,
     329,    33,    34,   206,    38,     0,   163,    68,   207,    43,
     207,   180,    50,   565,     3,   205,     5,     6,     7,     8,
       9,    10,   203,   203,   205,   127,   203,   564,     3,     4,
     180,   320,    93,    98,     3,     4,    70,     3,   207,     5,
       6,     7,     8,     9,    10,   206,   646,   623,   317,   326,
     602,   320,   341,   342,     8,   418,   201,   207,   201,   180,
     597,   201,    95,   206,   201,    30,   206,   430,   205,    38,
      35,   340,   341,   342,    43,   412,   137,   203,   630,   205,
      69,   202,    25,   215,     3,     4,    29,   624,   149,     3,
     124,   175,   176,   177,   178,   179,     8,   201,   215,    11,
     204,    70,   201,    69,   201,   204,   206,   204,     8,   241,
     242,   205,   205,   207,   160,   446,   150,    13,    14,    15,
      16,    17,    18,    19,   241,   242,   205,   116,   205,   201,
     202,   205,   201,   202,   201,   202,   206,   254,   201,   202,
     417,   205,   190,   191,   192,   262,     5,     6,   200,   201,
     116,   205,   200,   201,   249,   124,   190,   146,   489,   282,
     275,   223,   285,    15,   287,   288,   204,   201,   466,   292,
     159,   249,   206,     3,     4,   207,   208,   548,     3,     4,
     146,   150,     3,     4,     3,     4,   549,   203,   519,     3,
       4,   203,   307,   159,   326,   203,   185,     3,     4,   188,
     189,   190,   205,   275,   193,   194,     3,     4,   182,   326,
       3,     4,   203,   202,   512,   205,   331,   206,   596,   185,
     205,   190,   188,   189,   190,     3,     4,   193,   194,     3,
       4,   554,   205,   203,   205,   203,   202,   206,     3,   206,
     206,   201,   206,   206,   607,   623,   318,   318,   206,   318,
     365,   318,   203,   325,   325,   318,   325,   635,   325,   331,
     318,   206,   325,   540,   562,   318,   206,   206,   383,   567,
     342,   318,   570,   651,   318,   318,   318,   318,   206,   206,
     643,    13,    14,    15,    38,   417,   206,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   206,   206,   206,
     417,   206,   206,   206,   200,   201,   504,   206,   206,   424,
     508,   206,   415,   206,   206,   644,    70,   432,   206,   206,
     206,   206,   206,   206,   206,   623,   206,   206,   445,   206,
     206,   205,   609,   448,   466,   666,   188,   189,   190,   191,
     192,   205,   205,   458,     8,   203,   208,   207,   200,   201,
       8,   207,   206,     8,   426,   424,     8,   429,   429,     8,
     429,   419,   429,   432,     8,   432,   429,     8,     8,   432,
     124,     8,   201,   206,   506,   203,     3,     4,   205,     3,
       4,   448,     3,   203,     5,     6,     7,     8,     9,    10,
     182,   506,   205,   203,   180,   207,   150,   204,   596,   208,
     180,   599,   671,   672,   207,   207,   207,   264,   540,   207,
     267,    38,   206,   200,    38,     8,   207,   274,   207,   207,
     277,   182,   207,   540,   207,   207,   283,   284,   626,   544,
     562,   207,   207,   565,   506,   567,   190,   635,   207,   554,
     207,   207,   559,    70,   207,   207,    70,   201,    69,   207,
     565,   207,   206,   651,   207,   207,   188,   189,   190,   191,
     192,   207,   534,   207,   207,   534,   207,   534,   200,   201,
     207,   534,   329,   330,    13,    14,    15,   609,   205,    18,
      19,   204,   554,    89,   180,   207,   207,   602,   205,   205,
       3,   623,   609,   565,    39,   116,     3,   124,     8,     5,
     124,   207,   359,   360,   361,   362,   363,   364,   365,   180,
     205,   205,   182,   182,   207,   630,   207,   207,   207,   203,
     207,   207,    38,   150,   207,   146,   150,    43,   207,   207,
     602,   182,   205,   221,   428,   445,   283,    82,   159,   289,
     612,   612,   514,   612,   672,   612,    47,   215,   426,   612,
      95,    96,    97,   279,    70,   646,    -1,    -1,   630,   104,
      -1,    -1,    -1,   190,   185,    -1,   190,   188,   189,   190,
      -1,    -1,   193,   194,   201,    -1,    -1,    -1,    -1,   206,
     437,    -1,   206,    -1,    -1,   206,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   143,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,   124,    -1,
     467,   468,    -1,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
      -1,   488,    -1,    -1,   150,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,   514,    -1,    -1,
      -1,   200,   201,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,   190,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    -1,    -1,    72,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,   629,   137,    -1,   632,   200,   201,   142,   143,
     144,    -1,   146,   147,     4,   149,    -1,   644,    -1,   153,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
      -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    39,
      40,   185,    -1,    43,   188,   189,   190,    -1,    48,   193,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,   206,    -1,    -1,    65,    66,    -1,    68,    -1,
      -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    -1,    93,    -1,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,   181,   109,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
      -1,     4,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,   144,    -1,    -1,   147,    31,   149,
      33,    -1,    -1,   153,    -1,    -1,    39,    40,    -1,    -1,
      43,    -1,   162,    -1,   164,    48,    -1,    -1,    -1,    -1,
      -1,    -1,   172,   173,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,   201,    -1,    -1,   204,    -1,    89,    90,    -1,    -1,
      93,    -1,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,    -1,   147,    31,   149,    33,    -1,    -1,
     153,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,   162,
      -1,   164,    48,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,   201,    -1,
      -1,   204,    -1,    89,     4,    -1,    -1,    93,    -1,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,   137,    -1,    -1,    -1,    -1,   142,   143,   144,    59,
      -1,   147,    -1,   149,    -1,    65,    66,   153,    68,    -1,
      -1,    -1,    72,    -1,    -1,    75,   162,    -1,   164,    -1,
      -1,    -1,    82,    -1,    -1,    -1,   172,   173,    -1,    89,
       4,    -1,    -1,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,   201,    -1,    31,   204,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,   144,    59,    -1,   147,    -1,   149,
      -1,    65,    66,   153,    68,    -1,    -1,    -1,    72,    -1,
      -1,    75,   162,    -1,   164,    -1,    -1,    -1,    82,    -1,
      -1,    -1,   172,   173,    -1,    89,     4,    -1,    -1,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      -1,   201,    -1,    31,   204,    33,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,   143,
     144,    59,    -1,   147,    -1,   149,    -1,    65,    66,   153,
      68,    -1,    -1,    -1,    72,    -1,    -1,    75,   162,    -1,
     164,    -1,    -1,    -1,    82,    -1,    -1,    -1,   172,   173,
      -1,    89,     4,    -1,    -1,    93,    -1,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   184,   185,   186,
     187,   188,   189,   190,   191,   192,    -1,   201,    -1,    31,
     204,    33,    -1,   200,   201,    -1,    -1,    39,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,   142,   143,   144,    59,    -1,   147,
      -1,   149,    -1,    65,    66,   153,    68,    -1,    -1,    -1,
      72,    -1,    -1,    75,   162,    -1,   164,    -1,    -1,    -1,
      82,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,   185,   186,   187,   188,   189,
     190,   191,   192,   201,    -1,    -1,   204,    -1,    -1,     4,
     200,   201,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
     142,   143,   144,    -1,    -1,   147,    31,   149,    33,    -1,
      -1,   153,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,
     162,    -1,   164,    48,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,   201,
      -1,    -1,   204,    -1,    89,    90,    -1,    -1,    93,    -1,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,    -1,   147,    31,   149,    33,    -1,    -1,   153,    -1,
      -1,    39,    40,    -1,    -1,    43,    -1,   162,    -1,   164,
      48,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,    57,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    -1,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,   201,    -1,    -1,    -1,
      -1,    89,     4,    -1,    -1,    93,    -1,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,   142,   143,   144,    59,    -1,   147,
      -1,   149,    -1,    65,    66,   153,    68,    -1,    70,    -1,
      72,    -1,   160,    75,   162,    -1,   164,    -1,    -1,    -1,
      82,    -1,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    -1,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
     142,   143,   144,    -1,    -1,   147,    -1,   149,   150,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
     162,    -1,   164,    38,    39,    -1,    -1,    -1,    43,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,   190,    -1,
      65,    66,    -1,    68,    -1,    70,    -1,    72,    -1,   201,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,   137,    -1,    -1,    -1,    -1,   142,   143,   144,
      -1,    -1,   147,    -1,   149,   150,    -1,    -1,   153,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    31,   164,
      33,    -1,    -1,    -1,    -1,    -1,    39,   172,   173,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    59,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,   201,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      93,    -1,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,    59,    -1,   147,    -1,   149,    -1,    65,    66,
     153,    68,    -1,    -1,    -1,    72,    -1,    -1,    75,   162,
      -1,   164,    -1,    -1,    -1,    82,    -1,    -1,    -1,   172,
     173,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,   104,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
     137,    21,    -1,    -1,    -1,   142,   143,   144,    -1,    -1,
     147,    -1,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,    -1,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
     181,    -1,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,   201,    -1,    -1,    -1,    -1,   200,
     201,    -1,    -1,    -1,    -1,    -1,   207,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,    -1,
      -1,    -1,   207,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,   202,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     4,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,   142,   143,   144,
      59,    -1,   147,    -1,   149,    -1,    65,    66,   153,    68,
      -1,    -1,    -1,    72,    -1,    -1,    75,   162,    -1,   164,
      -1,    -1,    -1,    82,    -1,    -1,    -1,   172,   173,    -1,
      -1,     4,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   142,   143,   144,    59,    -1,   147,    -1,
     149,    -1,    65,    66,   153,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    75,   162,    -1,   164,    -1,    -1,    -1,    82,
      -1,    -1,    -1,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,    23,    -1,    25,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,
      42,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,    -1,
     102,   103,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,   138,   139,   140,   141,
      -1,    -1,    -1,   145,    -1,    -1,   148,    -1,    -1,   151,
     152,    -1,    -1,   155,   156,   157,   158,    -1,    -1,   161,
      -1,   163,    -1,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,   174
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   210,   211,     0,     4,    31,    33,    39,    40,    43,
      48,    57,    59,    65,    66,    68,    72,    75,    82,    89,
      93,    95,    96,    97,    98,   104,   109,   137,   142,   143,
     144,   147,   149,   153,   162,   164,   172,   173,   201,   215,
     216,   217,   218,   219,   222,   223,   229,   230,   241,   255,
     259,   261,   262,   263,   264,   265,   268,   269,   272,   274,
     275,   276,   277,   279,   280,   281,   282,   283,   285,   287,
     305,   306,   307,   308,     3,     4,   206,     3,     4,     3,
       4,   257,    95,   260,     8,     3,     4,   260,     3,   206,
     260,   261,     3,   257,     3,   257,   261,    23,    25,    26,
      27,    28,    29,    30,    32,    35,    37,    41,    42,    44,
      45,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    58,    60,    61,    62,    63,    64,    67,    71,    73,
      74,    76,    77,    78,    79,    80,    81,    83,    84,    85,
      86,    87,    88,    91,    94,    99,   100,   102,   103,   105,
     106,   110,   111,   112,   113,   114,   115,   117,   118,   119,
     120,   121,   122,   123,   125,   126,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   138,   139,   140,   141,   145,
     148,   151,   152,   155,   156,   157,   158,   161,   163,   165,
     166,   167,   168,   169,   170,   171,   174,   231,   233,   304,
     205,   212,   212,   160,    65,   101,   108,   153,   162,   221,
     241,   262,   268,   274,   278,   285,   305,   308,   205,   205,
     203,   203,   205,   203,   205,   214,   205,   182,   273,   203,
     286,   287,   286,   286,     3,     4,    38,    70,   124,   150,
     190,   206,   235,   258,   288,   289,   302,   241,   305,   306,
     308,   286,   205,     8,   203,   205,   306,   203,   154,   203,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   180,   202,    12,    90,   215,   220,   223,
     262,   264,   265,   276,   277,   280,   204,   229,   230,     3,
       3,     3,     4,     3,     3,   203,   302,   266,   211,   127,
     270,   274,     3,     4,   203,   213,   284,   288,   288,   208,
     201,   206,   228,   286,   207,   238,   239,   240,   258,   207,
     248,   206,   251,     8,     8,    11,   234,   258,     3,     5,
       6,     7,     8,     9,    10,    69,   116,   146,   159,   185,
     188,   189,   190,   193,   194,   206,   244,   245,   246,   244,
     247,     8,     8,   232,   247,   246,     8,     8,   246,     8,
     246,   244,   227,   230,   285,   246,   242,   243,   244,     8,
     304,     8,   246,   306,   242,   244,   306,   175,   176,   177,
     178,   179,   303,   306,   306,   234,     5,     6,   309,     8,
     306,   233,   201,   206,   205,   203,   214,   285,   204,   229,
     267,   204,   182,   107,   229,   253,   271,   205,   203,   213,
     204,   215,   230,   283,   288,   207,   247,   190,   202,   244,
     224,   225,   226,   227,   204,   180,   208,   204,   229,   249,
     253,   204,   230,   250,   253,   207,   207,   207,   206,   244,
     244,   244,   244,   244,   244,   244,   285,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   181,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   200,   201,   180,
     207,   207,   207,   180,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   285,   190,   206,   228,   235,   258,
     294,   296,   297,   207,   180,   207,   207,   207,   207,   180,
     207,   207,   207,   207,   207,   207,   207,   207,   200,   207,
     207,   207,   233,     8,   212,   288,   298,   214,   277,   182,
     285,   305,   205,   204,   230,   254,   255,   204,   219,   204,
     214,   202,   202,   207,   180,   240,   246,   285,   308,   207,
     205,   205,   285,   207,   190,   206,   228,   235,   290,   292,
     293,   244,   244,     3,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,     3,   244,   246,     8,   296,   284,   190,   224,   235,
     295,   296,   206,   228,   243,   246,     5,   207,   204,   180,
     288,   205,   213,   214,    22,   227,   294,   300,   301,   205,
     256,   258,   292,   284,   190,   224,   235,   291,   292,   207,
     206,   228,   182,   202,   296,   284,   207,   296,   207,   224,
     207,   214,   288,   204,   182,   299,   180,   205,   203,   207,
     292,   284,   207,   296,   207,   244,   224,   244,   296,   207,
     214,   247,   300,   236,   296,   207,    37,    50,   204,   237,
     246,   182,   182,   205,   252,   253,   252,   205
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1464 of yacc.c  */
#line 331 "parser.y"
    { fix_incomplete();
						  check_statements((yyvsp[(1) - (1)].stmt_list), FALSE);
						  check_all_user_types((yyvsp[(1) - (1)].stmt_list));
						  write_header((yyvsp[(1) - (1)].stmt_list));
						  write_id_data((yyvsp[(1) - (1)].stmt_list));
						  write_proxies((yyvsp[(1) - (1)].stmt_list));
						  write_client((yyvsp[(1) - (1)].stmt_list));
						  write_server((yyvsp[(1) - (1)].stmt_list));
						  write_regscript((yyvsp[(1) - (1)].stmt_list));
						  write_dlldata((yyvsp[(1) - (1)].stmt_list));
						  write_local_stubs((yyvsp[(1) - (1)].stmt_list));
						;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 345 "parser.y"
    { (yyval.stmt_list) = NULL; ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 347 "parser.y"
    { (yyval.stmt_list) = append_statements((yyvsp[(1) - (5)].stmt_list), (yyvsp[(4) - (5)].stmt_list)); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 348 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_reference((yyvsp[(2) - (2)].type))); ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 349 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_type_decl((yyvsp[(2) - (2)].type))); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 350 "parser.y"
    { (yyval.stmt_list) = (yyvsp[(1) - (3)].stmt_list);
						  reg_type((yyvsp[(2) - (3)].type), (yyvsp[(2) - (3)].type)->name, 0);
						;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 353 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_type_decl((yyvsp[(2) - (2)].type)));
						  reg_type((yyvsp[(2) - (2)].type), (yyvsp[(2) - (2)].type)->name, 0);
						;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 356 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_module((yyvsp[(2) - (2)].type))); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 357 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_library((yyvsp[(2) - (2)].typelib))); ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 358 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), (yyvsp[(2) - (2)].statement)); ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 361 "parser.y"
    { (yyval.stmt_list) = NULL; ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 362 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_reference((yyvsp[(2) - (2)].type))); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 363 "parser.y"
    { (yyval.stmt_list) = append_statements((yyvsp[(1) - (5)].stmt_list), (yyvsp[(4) - (5)].stmt_list)); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 364 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_type_decl((yyvsp[(2) - (2)].type))); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 365 "parser.y"
    { (yyval.stmt_list) = (yyvsp[(1) - (3)].stmt_list); reg_type((yyvsp[(2) - (3)].type), (yyvsp[(2) - (3)].type)->name, 0); ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 366 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_type_decl((yyvsp[(2) - (2)].type)));
						  reg_type((yyvsp[(2) - (2)].type), (yyvsp[(2) - (2)].type)->name, 0);
						;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 369 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_module((yyvsp[(2) - (2)].type))); ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 370 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), (yyvsp[(2) - (2)].statement)); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 371 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_importlib((yyvsp[(2) - (2)].str))); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 372 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), make_statement_library((yyvsp[(2) - (2)].typelib))); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 375 "parser.y"
    { (yyval.stmt_list) = NULL; ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 376 "parser.y"
    { (yyval.stmt_list) = append_statement((yyvsp[(1) - (2)].stmt_list), (yyvsp[(2) - (2)].statement)); ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 384 "parser.y"
    { (yyval.statement) = make_statement_cppquote((yyvsp[(1) - (1)].str)); ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 385 "parser.y"
    { (yyval.statement) = make_statement_type_decl((yyvsp[(1) - (2)].type)); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 386 "parser.y"
    { (yyval.statement) = make_statement_declaration((yyvsp[(1) - (2)].var)); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 387 "parser.y"
    { (yyval.statement) = make_statement_import((yyvsp[(1) - (1)].str)); ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 388 "parser.y"
    { (yyval.statement) = (yyvsp[(1) - (2)].statement); ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 393 "parser.y"
    { (yyval.type) = type_new_enum((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 395 "parser.y"
    { (yyval.type) = type_new_struct((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 397 "parser.y"
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 398 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[(1) - (2)].attr_list)); ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 399 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[(1) - (2)].attr_list)); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 400 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); (yyval.type)->attrs = check_union_attrs((yyvsp[(1) - (2)].attr_list)); ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 403 "parser.y"
    { (yyval.str) = (yyvsp[(3) - (4)].str); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 405 "parser.y"
    { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[(2) - (3)].str);
						  (yyval.import)->import_performed = do_import((yyvsp[(2) - (3)].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 413 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (3)].import)->name;
						  if ((yyvsp[(1) - (3)].import)->import_performed) pop_import();
						  free((yyvsp[(1) - (3)].import));
						;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 420 "parser.y"
    { (yyval.str) = (yyvsp[(3) - (5)].str); if(!parse_only) add_importlib((yyvsp[(3) - (5)].str)); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 423 "parser.y"
    { (yyval.str) = (yyvsp[(2) - (2)].str); ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 425 "parser.y"
    { (yyval.typelib) = make_library((yyvsp[(2) - (3)].str), check_library_attrs((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].attr_list)));
						  if (!parse_only) start_typelib((yyval.typelib));
						;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 430 "parser.y"
    { (yyval.typelib) = (yyvsp[(1) - (4)].typelib);
						  (yyval.typelib)->stmts = (yyvsp[(2) - (4)].stmt_list);
						  if (!parse_only) end_typelib();
						;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 436 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 440 "parser.y"
    { check_arg_attrs((yyvsp[(1) - (1)].var)); (yyval.var_list) = append_var( NULL, (yyvsp[(1) - (1)].var) ); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 441 "parser.y"
    { check_arg_attrs((yyvsp[(3) - (3)].var)); (yyval.var_list) = append_var( (yyvsp[(1) - (3)].var_list), (yyvsp[(3) - (3)].var) ); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 445 "parser.y"
    { (yyval.var_list) = append_var( (yyvsp[(1) - (3)].var_list), make_var(strdup("...")) ); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 449 "parser.y"
    { if ((yyvsp[(2) - (3)].declspec)->stgclass != STG_NONE && (yyvsp[(2) - (3)].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[(1) - (3)].attr_list), (yyvsp[(2) - (3)].declspec), (yyvsp[(3) - (3)].declarator), TRUE);
						  free((yyvsp[(2) - (3)].declspec)); free((yyvsp[(3) - (3)].declarator));
						;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 454 "parser.y"
    { if ((yyvsp[(1) - (2)].declspec)->stgclass != STG_NONE && (yyvsp[(1) - (2)].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[(1) - (2)].declspec), (yyvsp[(2) - (2)].declarator), TRUE);
						  free((yyvsp[(1) - (2)].declspec)); free((yyvsp[(2) - (2)].declarator));
						;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 461 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("array dimension is not an integer constant\n");
						;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 465 "parser.y"
    { (yyval.expr) = make_expr(EXPR_VOID); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 466 "parser.y"
    { (yyval.expr) = make_expr(EXPR_VOID); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 469 "parser.y"
    { (yyval.attr_list) = NULL; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 474 "parser.y"
    { (yyval.attr_list) = (yyvsp[(2) - (3)].attr_list); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 477 "parser.y"
    { (yyval.attr_list) = append_attr( NULL, (yyvsp[(1) - (1)].attr) ); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 478 "parser.y"
    { (yyval.attr_list) = append_attr( (yyvsp[(1) - (3)].attr_list), (yyvsp[(3) - (3)].attr) ); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 479 "parser.y"
    { (yyval.attr_list) = append_attr( (yyvsp[(1) - (4)].attr_list), (yyvsp[(4) - (4)].attr) ); ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 482 "parser.y"
    { (yyval.str_list) = append_str( NULL, (yyvsp[(1) - (1)].str) ); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 483 "parser.y"
    { (yyval.str_list) = append_str( (yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str) ); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 486 "parser.y"
    { (yyval.attr) = NULL; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 487 "parser.y"
    { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 488 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 489 "parser.y"
    { (yyval.attr) = make_attr(ATTR_APPOBJECT); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 490 "parser.y"
    { (yyval.attr) = make_attr(ATTR_ASYNC); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 491 "parser.y"
    { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 492 "parser.y"
    { (yyval.attr) = make_attr(ATTR_BINDABLE); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 493 "parser.y"
    { (yyval.attr) = make_attr(ATTR_BROADCAST); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 494 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[(3) - (4)].var)); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 495 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[(3) - (4)].expr_list)); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 496 "parser.y"
    { (yyval.attr) = make_attr(ATTR_CODE); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 497 "parser.y"
    { (yyval.attr) = make_attr(ATTR_COMMSTATUS); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 498 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 499 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 500 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 501 "parser.y"
    { (yyval.attr) = make_attr(ATTR_CONTROL); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 502 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DECODE); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 503 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DEFAULT); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 504 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); ;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 505 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 506 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 507 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 508 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 509 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 510 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 511 "parser.y"
    { (yyval.attr) = make_attr(ATTR_DUAL); ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 512 "parser.y"
    { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 513 "parser.y"
    { (yyval.attr) = make_attr(ATTR_ENCODE); ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 514 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[(3) - (4)].str_list)); ;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 515 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 516 "parser.y"
    { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 517 "parser.y"
    { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 518 "parser.y"
    { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 519 "parser.y"
    { (yyval.attr) = make_attr(ATTR_HANDLE); ;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 520 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 521 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 522 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 523 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 524 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 525 "parser.y"
    { (yyval.attr) = make_attr(ATTR_HIDDEN); ;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 526 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 527 "parser.y"
    { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 528 "parser.y"
    { (yyval.attr) = make_attr(ATTR_IGNORE); ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 529 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 530 "parser.y"
    { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 531 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[(3) - (4)].var)); ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 532 "parser.y"
    { (yyval.attr) = make_attr(ATTR_IN); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 533 "parser.y"
    { (yyval.attr) = make_attr(ATTR_INPUTSYNC); ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 534 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[(3) - (4)].expr_list)); ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 535 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 536 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PARAMLCID); ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 537 "parser.y"
    { (yyval.attr) = make_attr(ATTR_LICENSED); ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 538 "parser.y"
    { (yyval.attr) = make_attr(ATTR_LOCAL); ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 539 "parser.y"
    { (yyval.attr) = make_attr(ATTR_MAYBE); ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 540 "parser.y"
    { (yyval.attr) = make_attr(ATTR_MESSAGE); ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 541 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NOCODE); ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 542 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 543 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NONCREATABLE); ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 544 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 545 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NOTIFY); ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 546 "parser.y"
    { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 547 "parser.y"
    { (yyval.attr) = make_attr(ATTR_OBJECT); ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 548 "parser.y"
    { (yyval.attr) = make_attr(ATTR_ODL); ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 549 "parser.y"
    { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 550 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 551 "parser.y"
    { (yyval.attr) = make_attr(ATTR_OPTIONAL); ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 552 "parser.y"
    { (yyval.attr) = make_attr(ATTR_OUT); ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 553 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 554 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[(3) - (4)].num)); ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 555 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 556 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PROPGET); ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 557 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PROPPUT); ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 558 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PROPPUTREF); ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 559 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PROXY); ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 560 "parser.y"
    { (yyval.attr) = make_attr(ATTR_PUBLIC); ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 562 "parser.y"
    { expr_list_t *list = append_expr( NULL, (yyvsp[(3) - (6)].expr) );
						  list = append_expr( list, (yyvsp[(5) - (6)].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 565 "parser.y"
    { (yyval.attr) = make_attr(ATTR_READONLY); ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 566 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[(3) - (4)].type)); ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 567 "parser.y"
    { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 568 "parser.y"
    { (yyval.attr) = make_attr(ATTR_RESTRICTED); ;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 569 "parser.y"
    { (yyval.attr) = make_attr(ATTR_RETVAL); ;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 570 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[(3) - (4)].expr_list)); ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 571 "parser.y"
    { (yyval.attr) = make_attr(ATTR_SOURCE); ;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 572 "parser.y"
    { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 573 "parser.y"
    { (yyval.attr) = make_attr(ATTR_STRING); ;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 574 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 575 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[(3) - (4)].type)); ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 576 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[(3) - (4)].type)); ;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 577 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[(3) - (4)].num)); ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 578 "parser.y"
    { (yyval.attr) = make_attr(ATTR_UIDEFAULT); ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 579 "parser.y"
    { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 580 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[(3) - (4)].type)); ;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 581 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[(3) - (4)].uuid)); ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 582 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[(3) - (4)].uuid)); ;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 583 "parser.y"
    { (yyval.attr) = make_attr(ATTR_V1ENUM); ;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 584 "parser.y"
    { (yyval.attr) = make_attr(ATTR_VARARG); ;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 585 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[(3) - (4)].num)); ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 586 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[(3) - (4)].str)); ;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 587 "parser.y"
    { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[(3) - (4)].type)); ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 588 "parser.y"
    { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[(1) - (1)].num)); ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 593 "parser.y"
    { if (!is_valid_uuid((yyvsp[(1) - (1)].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[(1) - (1)].str));
						  (yyval.uuid) = parse_uuid((yyvsp[(1) - (1)].str)); ;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 598 "parser.y"
    { (yyval.str) = xstrdup("__cdecl"); ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 599 "parser.y"
    { (yyval.str) = xstrdup("__fastcall"); ;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 600 "parser.y"
    { (yyval.str) = xstrdup("__pascal"); ;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 601 "parser.y"
    { (yyval.str) = xstrdup("__stdcall"); ;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 604 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 605 "parser.y"
    { (yyval.var_list) = append_var( (yyvsp[(1) - (2)].var_list), (yyvsp[(2) - (2)].var) ); ;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 608 "parser.y"
    { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[(2) - (4)].expr) ));
						  (yyval.var) = (yyvsp[(4) - (4)].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 612 "parser.y"
    { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[(3) - (3)].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 618 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 619 "parser.y"
    { (yyval.var_list) = (yyvsp[(1) - (2)].var_list); ;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 623 "parser.y"
    { if (!(yyvsp[(1) - (1)].var)->eval)
						    (yyvsp[(1) - (1)].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[(1) - (1)].var) );
						;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 627 "parser.y"
    { if (!(yyvsp[(3) - (3)].var)->eval)
                                                  {
                                                    var_t *last = LIST_ENTRY( list_tail((yyval.var_list)), var_t, entry );
                                                    enum expr_type type = EXPR_NUM;
                                                    if (last->eval->type == EXPR_HEXNUM) type = EXPR_HEXNUM;
                                                    if (last->eval->cval + 1 < 0) type = EXPR_HEXNUM;
                                                    (yyvsp[(3) - (3)].var)->eval = make_exprl(type, last->eval->cval + 1);
                                                  }
                                                  (yyval.var_list) = append_var( (yyvsp[(1) - (3)].var_list), (yyvsp[(3) - (3)].var) );
						;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 639 "parser.y"
    { (yyval.var) = reg_const((yyvsp[(1) - (3)].var));
						  (yyval.var)->eval = (yyvsp[(3) - (3)].expr);
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 643 "parser.y"
    { (yyval.var) = reg_const((yyvsp[(1) - (1)].var));
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 648 "parser.y"
    { (yyval.type) = type_new_enum((yyvsp[(2) - (5)].str), TRUE, (yyvsp[(4) - (5)].var_list)); ;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 651 "parser.y"
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 652 "parser.y"
    { (yyval.expr_list) = append_expr( (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 655 "parser.y"
    { (yyval.expr) = make_expr(EXPR_VOID); ;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 659 "parser.y"
    { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[(1) - (1)].num)); ;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 660 "parser.y"
    { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[(1) - (1)].num)); ;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 661 "parser.y"
    { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[(1) - (1)].dbl)); ;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 662 "parser.y"
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); ;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 663 "parser.y"
    { (yyval.expr) = make_exprl(EXPR_NUM, 0); ;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 664 "parser.y"
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); ;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 665 "parser.y"
    { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[(1) - (1)].str)); ;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 666 "parser.y"
    { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[(1) - (1)].str)); ;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 667 "parser.y"
    { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[(1) - (1)].str)); ;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 668 "parser.y"
    { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[(1) - (1)].str)); ;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 669 "parser.y"
    { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[(1) - (5)].expr), (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 670 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 671 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 672 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 673 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 674 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 675 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 676 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 677 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 678 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 679 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 680 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 681 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 682 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 683 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 684 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 685 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 686 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 687 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 688 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 689 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 690 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 691 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 692 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 693 "parser.y"
    { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 694 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[(1) - (3)].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[(3) - (3)].str))); ;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 695 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[(1) - (3)].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[(3) - (3)].str))); ;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 697 "parser.y"
    { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[(2) - (5)].declspec), (yyvsp[(3) - (5)].declarator), 0), (yyvsp[(5) - (5)].expr)); free((yyvsp[(2) - (5)].declspec)); free((yyvsp[(3) - (5)].declarator)); ;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 699 "parser.y"
    { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[(3) - (5)].declspec), (yyvsp[(4) - (5)].declarator), 0), NULL); free((yyvsp[(3) - (5)].declspec)); free((yyvsp[(4) - (5)].declarator)); ;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 700 "parser.y"
    { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 701 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 704 "parser.y"
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[(1) - (1)].expr) ); ;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 705 "parser.y"
    { (yyval.expr_list) = append_expr( (yyvsp[(1) - (3)].expr_list), (yyvsp[(3) - (3)].expr) ); ;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 708 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 714 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 720 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 721 "parser.y"
    { (yyval.var_list) = append_var_list((yyvsp[(1) - (2)].var_list), (yyvsp[(2) - (2)].var_list)); ;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 725 "parser.y"
    { const char *first = LIST_ENTRY(list_head((yyvsp[(3) - (4)].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[(1) - (4)].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[(1) - (4)].attr_list), (yyvsp[(2) - (4)].declspec), (yyvsp[(3) - (4)].declarator_list));
						;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 729 "parser.y"
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[(2) - (3)].type); v->attrs = (yyvsp[(1) - (3)].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 736 "parser.y"
    { (yyval.var) = (yyvsp[(1) - (2)].var); ;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 737 "parser.y"
    { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[(1) - (2)].attr_list); ;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 740 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 741 "parser.y"
    { (yyval.var_list) = append_var( (yyvsp[(1) - (2)].var_list), (yyvsp[(2) - (2)].var) ); ;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 745 "parser.y"
    { (yyval.var) = (yyvsp[(1) - (2)].var); ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 746 "parser.y"
    { (yyval.var) = NULL; ;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 749 "parser.y"
    { (yyval.var) = declare_var(check_field_attrs((yyvsp[(3) - (3)].declarator)->var->name, (yyvsp[(1) - (3)].attr_list)),
						                (yyvsp[(2) - (3)].declspec), (yyvsp[(3) - (3)].declarator), FALSE);
						  free((yyvsp[(3) - (3)].declarator));
						;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 753 "parser.y"
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[(2) - (2)].type); v->attrs = (yyvsp[(1) - (2)].attr_list);
						  (yyval.var) = v;
						;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 759 "parser.y"
    { (yyval.var) = (yyvsp[(1) - (1)].var);
						  if (type_get_type((yyval.var)->type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 768 "parser.y"
    { (yyval.var) = declare_var((yyvsp[(1) - (3)].attr_list), (yyvsp[(2) - (3)].declspec), (yyvsp[(3) - (3)].declarator), FALSE);
						  free((yyvsp[(3) - (3)].declarator));
						;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 771 "parser.y"
    { (yyval.var) = declare_var(NULL, (yyvsp[(1) - (2)].declspec), (yyvsp[(2) - (2)].declarator), FALSE);
						  free((yyvsp[(2) - (2)].declarator));
						;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 776 "parser.y"
    { (yyval.var) = NULL; ;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 780 "parser.y"
    { (yyval.str) = NULL; ;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 781 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 782 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 785 "parser.y"
    { (yyval.var) = make_var((yyvsp[(1) - (1)].str)); ;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 787 "parser.y"
    { (yyval.var) = make_var((yyvsp[(1) - (1)].str)); ;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 790 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 791 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 793 "parser.y"
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[(2) - (2)].type)), -1); ;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 794 "parser.y"
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[(2) - (2)].type)), 1); ;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 795 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); ;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 796 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 797 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 798 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 799 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 800 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 807 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 808 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); ;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 809 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); ;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 810 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); ;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 811 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); ;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 812 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); ;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 813 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); ;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 814 "parser.y"
    { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); ;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 817 "parser.y"
    { (yyval.type) = type_new_coclass((yyvsp[(2) - (2)].str)); ;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 818 "parser.y"
    { (yyval.type) = find_type((yyvsp[(2) - (2)].str), 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[(2) - (2)].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 826 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[(2) - (2)].type)->name, (yyvsp[(1) - (2)].attr_list));
						;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 833 "parser.y"
    { (yyval.type) = type_coclass_define((yyvsp[(1) - (5)].type), (yyvsp[(3) - (5)].ifref_list)); ;}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 837 "parser.y"
    { fprintf (stderr, "NS<%s>\n", (yyvsp[(2) - (2)].str)); (yyval.type)=NULL; ;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 840 "parser.y"
    { (yyval.ifref_list) = NULL; ;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 841 "parser.y"
    { (yyval.ifref_list) = append_ifref( (yyvsp[(1) - (2)].ifref_list), (yyvsp[(2) - (2)].ifref) ); ;}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 845 "parser.y"
    { (yyval.ifref) = make_ifref((yyvsp[(2) - (2)].type)); (yyval.ifref)->attrs = (yyvsp[(1) - (2)].attr_list); ;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 848 "parser.y"
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[(2) - (2)].str), 0); ;}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 849 "parser.y"
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[(2) - (2)].str), 0); ;}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 852 "parser.y"
    { attr_t *attrs;
						  (yyval.type) = (yyvsp[(2) - (2)].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[(2) - (2)].type)->name, (yyvsp[(1) - (2)].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						;}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 861 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 862 "parser.y"
    { (yyval.var_list) = append_var( (yyvsp[(1) - (3)].var_list), (yyvsp[(2) - (3)].var) ); ;}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 865 "parser.y"
    { (yyval.var_list) = NULL; ;}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 866 "parser.y"
    { (yyval.var_list) = append_var( (yyvsp[(1) - (3)].var_list), (yyvsp[(2) - (3)].var) ); ;}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 872 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (5)].type);
						  type_dispinterface_define((yyval.type), (yyvsp[(3) - (5)].var_list), (yyvsp[(4) - (5)].var_list));
						;}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 876 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (5)].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[(3) - (5)].type));
						;}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 881 "parser.y"
    { (yyval.type) = NULL; ;}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 882 "parser.y"
    { (yyval.type) = find_type_or_error2((yyvsp[(2) - (2)].str), 0); ;}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 885 "parser.y"
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[(2) - (2)].str), 0); ;}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 886 "parser.y"
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[(2) - (2)].str), 0); ;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 889 "parser.y"
    { (yyval.ifinfo).interface = (yyvsp[(2) - (2)].type);
						  (yyval.ifinfo).old_pointer_default = pointer_default;
						  if (is_attr((yyvsp[(1) - (2)].attr_list), ATTR_POINTERDEFAULT))
						    pointer_default = get_attrv((yyvsp[(1) - (2)].attr_list), ATTR_POINTERDEFAULT);
						  check_def((yyvsp[(2) - (2)].type));
						  (yyvsp[(2) - (2)].type)->attrs = check_iface_attrs((yyvsp[(2) - (2)].type)->name, (yyvsp[(1) - (2)].attr_list));
						  (yyvsp[(2) - (2)].type)->defined = TRUE;
						;}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 900 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (6)].ifinfo).interface;
						  if((yyval.type) == (yyvsp[(2) - (6)].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[(2) - (6)].type), (yyvsp[(4) - (6)].stmt_list));
						  pointer_default = (yyvsp[(1) - (6)].ifinfo).old_pointer_default;
						;}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 910 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (8)].ifinfo).interface;
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[(3) - (8)].str), 0), (yyvsp[(6) - (8)].stmt_list));
						  pointer_default = (yyvsp[(1) - (8)].ifinfo).old_pointer_default;
						;}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 914 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (2)].type); ;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 918 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (2)].type); ;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 919 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (2)].type); ;}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 922 "parser.y"
    { (yyval.type) = type_new_module((yyvsp[(2) - (2)].str)); ;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 923 "parser.y"
    { (yyval.type) = type_new_module((yyvsp[(2) - (2)].str)); ;}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 926 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[(2) - (2)].type)->name, (yyvsp[(1) - (2)].attr_list));
						;}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 932 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (5)].type);
                                                  type_module_define((yyval.type), (yyvsp[(3) - (5)].stmt_list));
						;}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 938 "parser.y"
    { (yyval.stgclass) = STG_EXTERN; ;}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 939 "parser.y"
    { (yyval.stgclass) = STG_STATIC; ;}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 940 "parser.y"
    { (yyval.stgclass) = STG_REGISTER; ;}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 944 "parser.y"
    { (yyval.attr) = make_attr(ATTR_INLINE); ;}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 948 "parser.y"
    { (yyval.attr) = make_attr(ATTR_CONST); ;}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 951 "parser.y"
    { (yyval.attr_list) = NULL; ;}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 952 "parser.y"
    { (yyval.attr_list) = append_attr((yyvsp[(1) - (2)].attr_list), (yyvsp[(2) - (2)].attr)); ;}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 955 "parser.y"
    { (yyval.declspec) = make_decl_spec((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].declspec), NULL, NULL, STG_NONE); ;}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 957 "parser.y"
    { (yyval.declspec) = make_decl_spec((yyvsp[(2) - (3)].type), (yyvsp[(1) - (3)].declspec), (yyvsp[(3) - (3)].declspec), NULL, STG_NONE); ;}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 960 "parser.y"
    { (yyval.declspec) = NULL; ;}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 965 "parser.y"
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[(2) - (2)].declspec), NULL, (yyvsp[(1) - (2)].attr), STG_NONE); ;}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 966 "parser.y"
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[(2) - (2)].declspec), NULL, (yyvsp[(1) - (2)].attr), STG_NONE); ;}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 967 "parser.y"
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[(2) - (2)].declspec), NULL, NULL, (yyvsp[(1) - (2)].stgclass)); ;}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 972 "parser.y"
    { (yyval.declarator) = (yyvsp[(3) - (3)].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[(2) - (3)].attr_list))); ;}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 973 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (2)].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str))); ;}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 979 "parser.y"
    { (yyval.declarator) = make_declarator((yyvsp[(1) - (1)].var)); ;}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 980 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (3)].declarator); ;}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 981 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (2)].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 982 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[(3) - (4)].var_list)));
						  (yyval.declarator)->type = NULL;
						;}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 991 "parser.y"
    { (yyval.declarator) = (yyvsp[(3) - (3)].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[(2) - (3)].attr_list))); ;}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 992 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (2)].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str))); ;}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 1000 "parser.y"
    { (yyval.declarator) = (yyvsp[(3) - (3)].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[(2) - (3)].attr_list))); ;}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 1001 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (2)].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str))); ;}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 1006 "parser.y"
    { (yyval.declarator) = make_declarator(NULL); ;}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 1012 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (3)].declarator); ;}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 1013 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (2)].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 1014 "parser.y"
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[(1) - (1)].expr)); ;}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 1016 "parser.y"
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[(2) - (3)].var_list)));
						  (yyval.declarator)->type = NULL;
						;}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 1021 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[(3) - (4)].var_list)));
						  (yyval.declarator)->type = NULL;
						;}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 1030 "parser.y"
    { (yyval.declarator) = (yyvsp[(3) - (3)].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[(2) - (3)].attr_list))); ;}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 1031 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (2)].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str))); ;}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 1038 "parser.y"
    { (yyval.declarator) = (yyvsp[(3) - (3)].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[(2) - (3)].attr_list))); ;}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 1039 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (2)].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[(1) - (2)].str))); ;}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 1043 "parser.y"
    { (yyval.declarator) = make_declarator(NULL); ;}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 1051 "parser.y"
    { (yyval.declarator) = make_declarator((yyvsp[(1) - (1)].var)); ;}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 1052 "parser.y"
    { (yyval.declarator) = (yyvsp[(2) - (3)].declarator); ;}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 1053 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (2)].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 1054 "parser.y"
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[(1) - (1)].expr)); ;}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 1056 "parser.y"
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[(2) - (3)].var_list)));
						  (yyval.declarator)->type = NULL;
						;}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 1061 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[(3) - (4)].var_list)));
						  (yyval.declarator)->type = NULL;
						;}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 1068 "parser.y"
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[(1) - (1)].declarator) ); ;}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 1069 "parser.y"
    { (yyval.declarator_list) = append_declarator( (yyvsp[(1) - (3)].declarator_list), (yyvsp[(3) - (3)].declarator) ); ;}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 1072 "parser.y"
    { (yyval.expr) = NULL; ;}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 1073 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (2)].expr); ;}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 1076 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (2)].declarator); (yyval.declarator)->bits = (yyvsp[(2) - (2)].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						;}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 1083 "parser.y"
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[(1) - (1)].declarator) ); ;}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 1085 "parser.y"
    { (yyval.declarator_list) = append_declarator( (yyvsp[(1) - (3)].declarator_list), (yyvsp[(3) - (3)].declarator) ); ;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 1089 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (1)].declarator); ;}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 1090 "parser.y"
    { (yyval.declarator) = (yyvsp[(1) - (3)].declarator); (yyvsp[(1) - (3)].declarator)->var->eval = (yyvsp[(3) - (3)].expr); ;}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 1094 "parser.y"
    { (yyval.num) = THREADING_APARTMENT; ;}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 1095 "parser.y"
    { (yyval.num) = THREADING_NEUTRAL; ;}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 1096 "parser.y"
    { (yyval.num) = THREADING_SINGLE; ;}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 1097 "parser.y"
    { (yyval.num) = THREADING_FREE; ;}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 1098 "parser.y"
    { (yyval.num) = THREADING_BOTH; ;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 1102 "parser.y"
    { (yyval.num) = RPC_FC_RP; ;}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 1103 "parser.y"
    { (yyval.num) = RPC_FC_UP; ;}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 1104 "parser.y"
    { (yyval.num) = RPC_FC_FP; ;}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1107 "parser.y"
    { (yyval.type) = type_new_struct((yyvsp[(2) - (5)].str), TRUE, (yyvsp[(4) - (5)].var_list)); ;}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1110 "parser.y"
    { (yyval.type) = type_new_void(); ;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1111 "parser.y"
    { (yyval.type) = find_type_or_error((yyvsp[(1) - (1)].str), 0); ;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1112 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 1113 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 1114 "parser.y"
    { (yyval.type) = type_new_enum((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1115 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1116 "parser.y"
    { (yyval.type) = type_new_struct((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1117 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1118 "parser.y"
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[(2) - (2)].str), FALSE, NULL); ;}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1119 "parser.y"
    { (yyval.type) = make_safearray((yyvsp[(3) - (4)].type)); ;}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1123 "parser.y"
    {
						  (yyvsp[(1) - (5)].attr_list) = append_attribs ((yyvsp[(1) - (5)].attr_list), (yyvsp[(3) - (5)].attr_list));
						  reg_typedefs((yyvsp[(4) - (5)].declspec), (yyvsp[(5) - (5)].declarator_list), check_typedef_attrs((yyvsp[(1) - (5)].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[(5) - (5)].declarator_list));
						;}
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1131 "parser.y"
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[(2) - (5)].str), TRUE, (yyvsp[(4) - (5)].var_list)); ;}
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1134 "parser.y"
    { (yyval.type) = type_new_encapsulated_union((yyvsp[(2) - (10)].str), (yyvsp[(5) - (10)].var), (yyvsp[(7) - (10)].var), (yyvsp[(9) - (10)].var_list)); ;}
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1138 "parser.y"
    { (yyval.num) = MAKEVERSION((yyvsp[(1) - (1)].num), 0); ;}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1139 "parser.y"
    { (yyval.num) = MAKEVERSION((yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].num)); ;}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1140 "parser.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;



/* Line 1464 of yacc.c  */
#line 5572 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 1143 "parser.y"


static void decl_builtin_basic(const char *name, enum type_basic_type type)
{
  type_t *t = type_new_basic(type);
  reg_type(t, name, 0);
}

static void decl_builtin_alias(const char *name, type_t *t)
{
  reg_type(type_new_alias(t, name), name, 0);
}

void init_types(void)
{
  decl_builtin_basic("byte", TYPE_BASIC_BYTE);
  decl_builtin_basic("wchar_t", TYPE_BASIC_WCHAR);
  decl_builtin_basic("float", TYPE_BASIC_FLOAT);
  decl_builtin_basic("double", TYPE_BASIC_DOUBLE);
  decl_builtin_basic("error_status_t", TYPE_BASIC_ERROR_STATUS_T);
  decl_builtin_basic("handle_t", TYPE_BASIC_HANDLE);
  decl_builtin_alias("boolean", type_new_basic(TYPE_BASIC_BYTE));
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

static attr_list_t *dupattrs(const attr_list_t *list)
{
  attr_list_t *new_list;
  const attr_t *attr;

  if (!list) return NULL;

  new_list = xmalloc( sizeof(*list) );
  list_init( new_list );
  LIST_FOR_EACH_ENTRY(attr, list, const attr_t, entry)
  {
    attr_t *new_attr = xmalloc(sizeof(*new_attr));
    *new_attr = *attr;
    list_add_tail(new_list, &new_attr->entry);
  }
  return new_list;
}

static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right, attr_t *attr, enum storage_class stgclass)
{
  decl_spec_t *declspec = left ? left : right;
  if (!declspec)
  {
    declspec = xmalloc(sizeof(*declspec));
    declspec->type = NULL;
    declspec->attrs = NULL;
    declspec->stgclass = STG_NONE;
  }
  declspec->type = type;
  if (left && declspec != left)
  {
    declspec->attrs = append_attr_list(declspec->attrs, left->attrs);
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = left->stgclass;
    else if (left->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    assert(!left->type);
    free(left);
  }
  if (right && declspec != right)
  {
    declspec->attrs = append_attr_list(declspec->attrs, right->attrs);
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = right->stgclass;
    else if (right->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    assert(!right->type);
    free(right);
  }

  declspec->attrs = append_attr(declspec->attrs, attr);
  if (declspec->stgclass == STG_NONE)
    declspec->stgclass = stgclass;
  else if (stgclass != STG_NONE)
    error_loc("only one storage class can be specified\n");

  /* apply attributes to type */
  if (type && declspec->attrs)
  {
    attr_list_t *attrs;
    declspec->type = duptype(type, 1);
    attrs = dupattrs(type->attrs);
    declspec->type->attrs = append_attr_list(attrs, declspec->attrs);
    declspec->attrs = NULL;
  }

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

static array_dims_t *append_array(array_dims_t *list, expr_t *expr)
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

static type_t *append_ptrchain_type(type_t *ptrchain, type_t *type)
{
  type_t *ptrchain_type;
  if (!ptrchain)
    return type;
  for (ptrchain_type = ptrchain; type_pointer_get_ref(ptrchain_type); ptrchain_type = type_pointer_get_ref(ptrchain_type))
    ;
  assert(ptrchain_type->type_type == TYPE_POINTER);
  ptrchain_type->details.pointer.ref = type;
  return ptrchain;
}

static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, const declarator_t *decl,
                       int top)
{
  var_t *v = decl->var;
  expr_list_t *sizes = get_attrp(attrs, ATTR_SIZEIS);
  expr_list_t *lengs = get_attrp(attrs, ATTR_LENGTHIS);
  int sizeless;
  expr_t *dim;
  type_t **ptype;
  array_dims_t *arr = decl ? decl->array : NULL;
  type_t *func_type = decl ? decl->func_type : NULL;
  type_t *type = decl_spec->type;

  if (is_attr(type->attrs, ATTR_INLINE))
  {
    if (!func_type)
      error_loc("inline attribute applied to non-function type\n");
    else
    {
      type_t *t;
      /* move inline attribute from return type node to function node */
      for (t = func_type; is_ptr(t); t = type_pointer_get_ref(t))
        ;
      t->attrs = move_attr(t->attrs, type->attrs, ATTR_INLINE);
    }
  }

  /* add type onto the end of the pointers in pident->type */
  v->type = append_ptrchain_type(decl ? decl->type : NULL, type);
  v->stgclass = decl_spec->stgclass;
  v->attrs = attrs;

  /* check for pointer attribute being applied to non-pointer, non-array
   * type */
  if (!arr)
  {
    int ptr_attr = get_attrv(v->attrs, ATTR_POINTERTYPE);
    const type_t *ptr = NULL;
    /* pointer attributes on the left side of the type belong to the function
     * pointer, if one is being declared */
    type_t **pt = func_type ? &func_type : &v->type;
    for (ptr = *pt; ptr && !ptr_attr; )
    {
      ptr_attr = get_attrv(ptr->attrs, ATTR_POINTERTYPE);
      if (!ptr_attr && type_is_alias(ptr))
        ptr = type_alias_get_aliasee(ptr);
      else
        break;
    }
    if (is_ptr(ptr))
    {
      if (ptr_attr && ptr_attr != RPC_FC_UP &&
          type_get_type(type_pointer_get_ref(ptr)) == TYPE_INTERFACE)
          warning_loc_info(&v->loc_info,
                           "%s: pointer attribute applied to interface "
                           "pointer type has no effect\n", v->name);
      if (!ptr_attr && top && (*pt)->details.pointer.def_fc != RPC_FC_RP)
      {
        /* FIXME: this is a horrible hack to cope with the issue that we
         * store an offset to the typeformat string in the type object, but
         * two typeformat strings may be written depending on whether the
         * pointer is a toplevel parameter or not */
        *pt = duptype(*pt, 1);
      }
    }
    else if (ptr_attr)
       error_loc("%s: pointer attribute applied to non-pointer type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_STRING))
  {
    type_t *t = type;

    if (!is_ptr(v->type) && !arr)
      error_loc("'%s': [string] attribute applied to non-pointer, non-array type\n",
                v->name);

    while (is_ptr(t))
      t = type_pointer_get_ref(t);

    if (type_get_type(t) != TYPE_BASIC &&
        (get_basic_fc(t) != RPC_FC_CHAR &&
         get_basic_fc(t) != RPC_FC_BYTE &&
         get_basic_fc(t) != RPC_FC_WCHAR))
    {
      error_loc("'%s': [string] attribute is only valid on 'char', 'byte', or 'wchar_t' pointers and arrays\n",
                v->name);
    }
  }

  if (is_attr(v->attrs, ATTR_V1ENUM))
  {
    if (type_get_type_detect_alias(v->type) != TYPE_ENUM)
      error_loc("'%s': [v1_enum] attribute applied to non-enum type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_RANGE) && !is_allowed_range_type(v->type))
    error_loc("'%s': [range] attribute applied to non-integer type\n",
              v->name);

  ptype = &v->type;
  sizeless = FALSE;
  if (arr) LIST_FOR_EACH_ENTRY_REV(dim, arr, expr_t, entry)
  {
    if (sizeless)
      error_loc("%s: only the first array dimension can be unspecified\n", v->name);

    if (dim->is_const)
    {
      if (dim->cval <= 0)
        error_loc("%s: array dimension must be positive\n", v->name);

      /* FIXME: should use a type_memsize that allows us to pass in a pointer size */
      if (0)
      {
        unsigned int size = type_memsize(v->type);

        if (0xffffffffu / size < dim->cval)
          error_loc("%s: total array size is too large\n", v->name);
      }
    }
    else
      sizeless = TRUE;

    *ptype = type_new_array(NULL, *ptype, FALSE,
                            dim->is_const ? dim->cval : 0,
                            dim->is_const ? NULL : dim, NULL,
                            pointer_default);
  }

  ptype = &v->type;
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
                                  0, dim, NULL, 0);
      }
      else if (is_ptr(*ptype))
        *ptype = type_new_array((*ptype)->name, type_pointer_get_ref(*ptype), TRUE,
                                0, dim, NULL, pointer_default);
      else
        error_loc("%s: size_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem;
    else
      error_loc("%s: too many expressions in size_is attribute\n", v->name);
  }

  ptype = &v->type;
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
                                type_array_get_conformance(*ptype),
                                dim, type_array_get_ptr_default_fc(*ptype));
      }
      else
        error_loc("%s: length_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem;
    else
      error_loc("%s: too many expressions in length_is attribute\n", v->name);
  }

  /* v->type is currently pointing to the type on the left-side of the
   * declaration, so we need to fix this up so that it is the return type of the
   * function and make v->type point to the function side of the declaration */
  if (func_type)
  {
    type_t *ft, *t;
    type_t *return_type = v->type;
    v->type = func_type;
    for (ft = v->type; is_ptr(ft); ft = type_pointer_get_ref(ft))
      ;
    assert(type_get_type_detect_alias(ft) == TYPE_FUNCTION);
    ft->details.function->retval = make_var(xstrdup("_RetVal"));
    ft->details.function->retval->type = return_type;
    /* move calling convention attribute, if present, from pointer nodes to
     * function node */
    for (t = v->type; is_ptr(t); t = type_pointer_get_ref(t))
      ft->attrs = move_attr(ft->attrs, t->attrs, ATTR_CALLCONV);
  }
  else
  {
    type_t *t;
    for (t = v->type; is_ptr(t); t = type_pointer_get_ref(t))
      if (is_attr(t->attrs, ATTR_CALLCONV))
        error_loc("calling convention applied to non-function-pointer type\n");
  }

  if (decl->bits)
    v->type = type_new_bitfield(v->type, decl->bits);

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
  v->type = NULL;
  v->attrs = NULL;
  v->eval = NULL;
  v->stgclass = STG_NONE;
  init_loc_info(&v->loc_info);
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
  d->func_type = NULL;
  d->array = NULL;
  d->bits = NULL;
  return d;
}

static type_t *make_safearray(type_t *type)
{
  return type_new_array(NULL, type_new_alias(type, "SAFEARRAY"), TRUE, 0,
                        NULL, NULL, RPC_FC_RP);
}

static typelib_t *make_library(const char *name, const attr_list_t *attrs)
{
    typelib_t *typelib = xmalloc(sizeof(*typelib));
    typelib->name = xstrdup(name);
    typelib->attrs = attrs;
    list_init( &typelib->importlibs );
    return typelib;
}

#define HASHMAX 64

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

struct rtype {
  const char *name;
  type_t *type;
  int t;
  struct rtype *next;
};

struct rtype *type_hash[HASHMAX];

type_t *reg_type(type_t *type, const char *name, int t)
{
  struct rtype *nt;
  int hash;
  if (!name) {
    error_loc("registering named type without name\n");
    return type;
  }
  hash = hash_ident(name);
  nt = xmalloc(sizeof(struct rtype));
  nt->name = name;
  nt->type = type;
  nt->t = t;
  nt->next = type_hash[hash];
  type_hash[hash] = nt;
  if ((t == tsSTRUCT || t == tsUNION))
    fix_incomplete_types(type);
  return type;
}

static int is_incomplete(const type_t *t)
{
  return !t->defined &&
    (type_get_type_detect_alias(t) == TYPE_STRUCT ||
     type_get_type_detect_alias(t) == TYPE_UNION ||
     type_get_type_detect_alias(t) == TYPE_ENCAPSULATED_UNION);
}

void add_incomplete(type_t *t)
{
  struct typenode *tn = xmalloc(sizeof *tn);
  tn->type = t;
  list_add_tail(&incomplete_types, &tn->entry);
}

static void fix_type(type_t *t)
{
  if (type_is_alias(t) && is_incomplete(t)) {
    type_t *ot = type_alias_get_aliasee(t);
    fix_type(ot);
    if (type_get_type_detect_alias(ot) == TYPE_STRUCT ||
        type_get_type_detect_alias(ot) == TYPE_UNION ||
        type_get_type_detect_alias(ot) == TYPE_ENCAPSULATED_UNION)
      t->details.structure = ot->details.structure;
    t->defined = ot->defined;
  }
}

static void fix_incomplete(void)
{
  struct typenode *tn, *next;

  LIST_FOR_EACH_ENTRY_SAFE(tn, next, &incomplete_types, struct typenode, entry) {
    fix_type(tn->type);
    list_remove(&tn->entry);
    free(tn);
  }
}

static void fix_incomplete_types(type_t *complete_type)
{
  struct typenode *tn, *next;

  LIST_FOR_EACH_ENTRY_SAFE(tn, next, &incomplete_types, struct typenode, entry)
  {
    if (type_is_equal(complete_type, tn->type))
    {
      tn->type->details.structure = complete_type->details.structure;
      list_remove(&tn->entry);
      free(tn);
    }
  }
}

static type_t *reg_typedefs(decl_spec_t *decl_spec, declarator_list_t *decls, attr_list_t *attrs)
{
  const declarator_t *decl;
  type_t *type = decl_spec->type;

  /* We must generate names for tagless enum, struct or union.
     Typedef-ing a tagless enum, struct or union means we want the typedef
     to be included in a library hence the public attribute.  */
  if ((type_get_type_detect_alias(type) == TYPE_ENUM ||
       type_get_type_detect_alias(type) == TYPE_STRUCT ||
       type_get_type_detect_alias(type) == TYPE_UNION ||
       type_get_type_detect_alias(type) == TYPE_ENCAPSULATED_UNION) &&
      !type->name)
  {
    if (! is_attr(attrs, ATTR_PUBLIC) && ! is_attr (attrs, ATTR_HIDDEN))
      attrs = append_attr( attrs, make_attr(ATTR_PUBLIC) );
    type->name = gen_name();
  }
  else if (is_attr(attrs, ATTR_UUID) && !is_attr(attrs, ATTR_PUBLIC)
	   && !is_attr (attrs, ATTR_HIDDEN))
    attrs = append_attr( attrs, make_attr(ATTR_PUBLIC) );

  LIST_FOR_EACH_ENTRY( decl, decls, const declarator_t, entry )
  {

    if (decl->var->name) {
      type_t *cur;
      var_t *name;

      cur = find_type(decl->var->name, 0);

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
      cur = type_new_alias(name->type, name->name);
      cur->attrs = attrs;

      if (is_incomplete(cur))
        add_incomplete(cur);
      reg_type(cur, cur->name, 0);
    }
  }
  return type;
}

type_t *find_type(const char *name, int t)
{
  struct rtype *cur = type_hash[hash_ident(name)];
  while (cur && (cur->t != t || strcmp(cur->name, name)))
    cur = cur->next;
  return cur ? cur->type : NULL;
}

static type_t *find_type_or_error(const char *name, int t)
{
  type_t *type = find_type(name, t);
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
  return find_type(name, 0) != NULL;
}

type_t *get_type(enum type_type type, char *name, int t)
{
  type_t *tp;
  if (name) {
    tp = find_type(name, t);
    if (tp) {
      free(name);
      return tp;
    }
  }
  tp = make_type(type);
  tp->name = name;
  if (!name) return tp;
  return reg_type(tp, name, t);
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

static char *gen_name(void)
{
  static const char format[] = "__WIDL_%s_generated_name_%08lX";
  static unsigned long n = 0;
  static const char *file_id;
  static size_t size;
  char *name;

  if (! file_id)
  {
    char *dst = dup_basename(input_idl_name, ".idl");
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';

    size = sizeof format - 7 + strlen(file_id) + 8;
  }

  name = xmalloc(size);
  sprintf(name, format, file_id, n++);
  return name;
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
    unsigned int on_struct : 1;
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
    /* ATTR_ASYNCUUID */	   { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONST */               { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "const" },
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
    /* ATTR_INLINE */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inline" },
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
    /* ATTR_UUID */                { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, "version" },
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
        if (type_get_type( var->type) == TYPE_BASIC &&
            type_basic_get_type( var->type ) == TYPE_BASIC_HANDLE)
            continue;
        if (is_aliaschain_attr( var->type, ATTR_HANDLE ))
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
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_struct)
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
    return (type_memsize(type_pointer_get_ref(type)) == 16);
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
    type_t *type = arg->type;
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
        (is_attr(arg->attrs, ATTR_STRING) || is_aliaschain_attr(arg->type, ATTR_STRING)))
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
                t = type_pointer_get_ref(t);
            if (is_aliaschain_attr(t, ATTR_RANGE))
                warning_loc_info(&arg->loc_info, "%s: range not verified for a string of ranged types\n", arg->name);
            break;
        }
        case TGT_POINTER:
            type = type_pointer_get_ref(type);
            more_to_do = TRUE;
            break;
        case TGT_ARRAY:
            type = type_array_get_element(type);
            more_to_do = TRUE;
            break;
        case TGT_USER_TYPE:
        case TGT_IFACE_POINTER:
        case TGT_BASIC:
        case TGT_ENUM:
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
            error_loc_info(&var->loc_info, "undefined type declaration %s\n", type->name);
    }
    else if (type_get_type(type) == TYPE_UNION || type_get_type(type) == TYPE_ENCAPSULATED_UNION)
        fields = type_union_get_cases(type);

    if (fields) LIST_FOR_EACH_ENTRY( field, fields, const var_t, entry )
        if (field->type) check_field_common(type, type->name, field);
}

/* checks that arguments for a function make sense for marshalling and unmarshalling */
static void check_remoting_args(const var_t *func)
{
    const char *funcname = func->name;
    const var_t *arg;

    if (func->type->details.function->args) LIST_FOR_EACH_ENTRY( arg, func->type->details.function->args, const var_t, entry )
    {
        const type_t *type = arg->type;

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

        check_field_common(func->type, funcname, arg);
    }

    if (type_get_type(type_function_get_rettype(func->type)) != TYPE_VOID)
    {
        var_t var;
        var = *func;
        var.type = type_function_get_rettype(func->type);
        var.name = xstrdup("return value");
        check_field_common(func->type, funcname, &var);
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
        idl_handle->type = find_type_or_error("handle_t", 0);
        type_function_add_head_arg(func->type, idl_handle);
    }
}

static void check_functions(const type_t *iface, int is_inside_library)
{
    const statement_t *stmt;
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

static void check_statements(const statement_list_t *stmts, int is_inside_library)
{
    const statement_t *stmt;

    if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
    {
      if (stmt->type == STMT_LIBRARY)
          check_statements(stmt->u.lib->stmts, TRUE);
      else if (stmt->type == STMT_TYPE && type_get_type(stmt->u.type) == TYPE_INTERFACE)
          check_functions(stmt->u.type, is_inside_library);
    }
}

static void check_all_user_types(const statement_list_t *stmts)
{
  const statement_t *stmt;

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
        check_for_additional_prototype_types(func->type->details.function->args);
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
    if (var->stgclass == STG_EXTERN && var->eval)
        warning("'%s' initialised and declared extern\n", var->name);
    if (is_const_decl(var))
    {
        if (var->eval)
            reg_const(var);
    }
    else if (type_get_type(var->type) == TYPE_FUNCTION)
        check_function_attrs(var->name, var->attrs);
    else if (var->stgclass == STG_NONE || var->stgclass == STG_REGISTER)
        error_loc("instantiation of data is illegal\n");
    return stmt;
}

static statement_t *make_statement_library(typelib_t *typelib)
{
    statement_t *stmt = make_statement(STMT_LIBRARY);
    stmt->u.lib = typelib;
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

static statement_t *make_statement_typedef(declarator_list_t *decls)
{
    declarator_t *decl, *next;
    statement_t *stmt;
    type_list_t **type_list;

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    type_list = &stmt->u.type_list;

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

