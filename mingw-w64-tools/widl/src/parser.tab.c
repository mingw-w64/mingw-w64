/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

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

/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

static unsigned char pointer_default = FC_UP;

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
static type_t *append_array(type_t *chain, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, const declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface);
static ifref_t *make_ifref(type_t *iface);
static var_list_t *append_var_list(var_list_t *list, var_list_t *vars);
static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *p);
static declarator_t *make_declarator(var_t *var);
static type_t *make_safearray(type_t *type);
static typelib_t *make_library(const char *name, const attr_list_t *attrs);
static type_t *append_chain_type(type_t *chain, type_t *type);
static warning_list_t *append_warning(warning_list_t *, int);

static type_t *reg_typedefs(decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs);
static type_t *find_type_or_error(const char *name, int t);
static type_t *find_type_or_error2(char *name, int t);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);

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
static statement_t *make_statement_pragma(const char *str);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names);
static statement_t *make_statement_import(const char *str);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;

static typelib_t *current_typelib;


#line 214 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    aIDENTIFIER = 258,
    aPRAGMA = 259,
    aKNOWNTYPE = 260,
    aNUM = 261,
    aHEXNUM = 262,
    aDOUBLE = 263,
    aSTRING = 264,
    aWSTRING = 265,
    aSQSTRING = 266,
    aUUID = 267,
    aEOF = 268,
    SHL = 269,
    SHR = 270,
    MEMBERPTR = 271,
    EQUALITY = 272,
    INEQUALITY = 273,
    GREATEREQUAL = 274,
    LESSEQUAL = 275,
    LOGICALOR = 276,
    LOGICALAND = 277,
    ELLIPSIS = 278,
    tAGGREGATABLE = 279,
    tALLOCATE = 280,
    tANNOTATION = 281,
    tAPPOBJECT = 282,
    tASYNC = 283,
    tASYNCUUID = 284,
    tAUTOHANDLE = 285,
    tBINDABLE = 286,
    tBOOLEAN = 287,
    tBROADCAST = 288,
    tBYTE = 289,
    tBYTECOUNT = 290,
    tCALLAS = 291,
    tCALLBACK = 292,
    tCASE = 293,
    tCDECL = 294,
    tCHAR = 295,
    tCOCLASS = 296,
    tCODE = 297,
    tCOMMSTATUS = 298,
    tCONST = 299,
    tCONTEXTHANDLE = 300,
    tCONTEXTHANDLENOSERIALIZE = 301,
    tCONTEXTHANDLESERIALIZE = 302,
    tCONTROL = 303,
    tCPPQUOTE = 304,
    tDECODE = 305,
    tDEFAULT = 306,
    tDEFAULTBIND = 307,
    tDEFAULTCOLLELEM = 308,
    tDEFAULTVALUE = 309,
    tDEFAULTVTABLE = 310,
    tDISABLECONSISTENCYCHECK = 311,
    tDISPLAYBIND = 312,
    tDISPINTERFACE = 313,
    tDLLNAME = 314,
    tDOUBLE = 315,
    tDUAL = 316,
    tENABLEALLOCATE = 317,
    tENCODE = 318,
    tENDPOINT = 319,
    tENTRY = 320,
    tENUM = 321,
    tERRORSTATUST = 322,
    tEXPLICITHANDLE = 323,
    tEXTERN = 324,
    tFALSE = 325,
    tFASTCALL = 326,
    tFAULTSTATUS = 327,
    tFLOAT = 328,
    tFORCEALLOCATE = 329,
    tHANDLE = 330,
    tHANDLET = 331,
    tHELPCONTEXT = 332,
    tHELPFILE = 333,
    tHELPSTRING = 334,
    tHELPSTRINGCONTEXT = 335,
    tHELPSTRINGDLL = 336,
    tHIDDEN = 337,
    tHYPER = 338,
    tID = 339,
    tIDEMPOTENT = 340,
    tIGNORE = 341,
    tIIDIS = 342,
    tIMMEDIATEBIND = 343,
    tIMPLICITHANDLE = 344,
    tIMPORT = 345,
    tIMPORTLIB = 346,
    tIN = 347,
    tIN_LINE = 348,
    tINLINE = 349,
    tINPUTSYNC = 350,
    tINT = 351,
    tINT32 = 352,
    tINT3264 = 353,
    tINT64 = 354,
    tINTERFACE = 355,
    tLCID = 356,
    tLENGTHIS = 357,
    tLIBRARY = 358,
    tLICENSED = 359,
    tLOCAL = 360,
    tLONG = 361,
    tMAYBE = 362,
    tMESSAGE = 363,
    tMETHODS = 364,
    tMODULE = 365,
    tNAMESPACE = 366,
    tNOCODE = 367,
    tNONBROWSABLE = 368,
    tNONCREATABLE = 369,
    tNONEXTENSIBLE = 370,
    tNOTIFY = 371,
    tNOTIFYFLAG = 372,
    tNULL = 373,
    tOBJECT = 374,
    tODL = 375,
    tOLEAUTOMATION = 376,
    tOPTIMIZE = 377,
    tOPTIONAL = 378,
    tOUT = 379,
    tPARTIALIGNORE = 380,
    tPASCAL = 381,
    tPOINTERDEFAULT = 382,
    tPRAGMA_WARNING = 383,
    tPROGID = 384,
    tPROPERTIES = 385,
    tPROPGET = 386,
    tPROPPUT = 387,
    tPROPPUTREF = 388,
    tPROXY = 389,
    tPTR = 390,
    tPUBLIC = 391,
    tRANGE = 392,
    tREADONLY = 393,
    tREF = 394,
    tREGISTER = 395,
    tREPRESENTAS = 396,
    tREQUESTEDIT = 397,
    tRESTRICTED = 398,
    tRETVAL = 399,
    tSAFEARRAY = 400,
    tSHORT = 401,
    tSIGNED = 402,
    tSIZEIS = 403,
    tSIZEOF = 404,
    tSMALL = 405,
    tSOURCE = 406,
    tSTATIC = 407,
    tSTDCALL = 408,
    tSTRICTCONTEXTHANDLE = 409,
    tSTRING = 410,
    tSTRUCT = 411,
    tSWITCH = 412,
    tSWITCHIS = 413,
    tSWITCHTYPE = 414,
    tTHREADING = 415,
    tTRANSMITAS = 416,
    tTRUE = 417,
    tTYPEDEF = 418,
    tUIDEFAULT = 419,
    tUNION = 420,
    tUNIQUE = 421,
    tUNSIGNED = 422,
    tUSESGETLASTERROR = 423,
    tUSERMARSHAL = 424,
    tUUID = 425,
    tV1ENUM = 426,
    tVARARG = 427,
    tVERSION = 428,
    tVIPROGID = 429,
    tVOID = 430,
    tWCHAR = 431,
    tWIREMARSHAL = 432,
    tAPARTMENT = 433,
    tNEUTRAL = 434,
    tSINGLE = 435,
    tFREE = 436,
    tBOTH = 437,
    CAST = 438,
    PPTR = 439,
    POS = 440,
    NEG = 441,
    ADDRESSOF = 442
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 140 "parser.y" /* yacc.c:355  */

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
	interface_info_t ifinfo;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;

#line 467 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);



/* Copy the second part of user declarations.  */

#line 484 "parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   3067

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  212
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  395
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  692

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   442

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   196,     2,     2,     2,   195,   188,     2,
     209,   210,   193,   192,   183,   191,   203,   194,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   185,   208,
     189,   211,   190,   184,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   204,     2,   205,   187,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   206,   186,   207,   197,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   181,   182,   198,   199,
     200,   201,   202
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   322,   322,   337,   338,   338,   340,   341,   342,   345,
     348,   349,   350,   353,   354,   355,   355,   357,   358,   359,
     362,   363,   364,   365,   368,   369,   372,   373,   377,   378,
     379,   380,   381,   382,   383,   386,   397,   398,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   413,   415,   423,
     429,   433,   434,   436,   440,   444,   445,   448,   449,   452,
     453,   457,   462,   469,   473,   474,   477,   478,   482,   485,
     486,   487,   490,   491,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   600,   601,   606,   607,   608,   609,
     612,   613,   616,   620,   626,   627,   628,   631,   635,   647,
     651,   656,   659,   660,   663,   664,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   706,   708,   709,   712,   713,   716,
     722,   728,   729,   732,   737,   744,   745,   748,   749,   753,
     754,   757,   761,   767,   775,   779,   784,   785,   788,   789,
     790,   793,   795,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   811,   812,   815,   816,   817,   818,
     819,   820,   821,   822,   823,   826,   827,   835,   841,   845,
     848,   849,   853,   856,   857,   860,   869,   870,   873,   874,
     877,   883,   889,   890,   893,   894,   897,   907,   916,   922,
     926,   927,   930,   931,   934,   939,   946,   947,   948,   952,
     956,   959,   960,   963,   964,   968,   969,   973,   974,   975,
     979,   981,   983,   987,   988,   989,   990,   998,  1000,  1002,
    1007,  1009,  1014,  1015,  1020,  1021,  1022,  1023,  1028,  1037,
    1039,  1040,  1045,  1047,  1051,  1052,  1059,  1060,  1061,  1062,
    1063,  1068,  1076,  1077,  1080,  1081,  1084,  1091,  1092,  1097,
    1098,  1102,  1103,  1104,  1105,  1106,  1110,  1111,  1112,  1115,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1130,  1137,  1139,  1145,  1146,  1147
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "aIDENTIFIER", "aPRAGMA", "aKNOWNTYPE",
  "aNUM", "aHEXNUM", "aDOUBLE", "aSTRING", "aWSTRING", "aSQSTRING",
  "aUUID", "aEOF", "SHL", "SHR", "MEMBERPTR", "EQUALITY", "INEQUALITY",
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
  "tSIGNED", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTATIC",
  "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT", "tSWITCH",
  "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS", "tTRUE",
  "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
  "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG",
  "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT",
  "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'", "'['", "']'",
  "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept", "input",
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
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     435,   436,   437,    44,    63,    58,   124,    94,    38,    60,
      62,    45,    43,    42,    47,    37,    33,   126,   438,   439,
     440,   441,   442,    46,    91,    93,   123,   125,    59,    40,
      41,    61
};
# endif

#define YYPACT_NINF -544

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-544)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -544,    67,  1755,  -544,  -544,  -544,  -544,  -544,  -544,    70,
    -544,   -84,   128,  -544,   136,  -544,  -544,  -544,  -544,    53,
     126,  -544,  -544,  -544,  -544,  -544,   142,    53,   153,   -46,
    -544,   -45,    53,   420,  -544,  -544,   188,   195,   420,  -544,
    -544,  2890,  -544,  -544,   -38,  -544,  -544,  -544,  -544,  -544,
      58,  2588,   -32,     2,  -544,  -544,     3,    64,  -544,    68,
      41,    85,    45,    56,   119,  -544,  -544,    99,  -544,    77,
      77,    77,    97,  2737,   109,    77,   110,   113,  -544,  -544,
     313,  -544,  -544,    18,  -544,   118,  -544,  -544,   117,  -544,
    -544,  -544,  -544,   325,  2737,  -544,  -544,    59,   123,  -103,
    -126,  -544,  -544,   122,  -544,  -544,   129,  -544,  -544,  -544,
     131,   135,  -544,  -544,  -544,  -544,  -544,  -544,  -544,  -544,
    -544,  -544,   137,  -544,  -544,  -544,   140,  -544,  -544,  -544,
     143,   145,  -544,  -544,  -544,  -544,   146,   147,   148,   150,
     154,  -544,   162,  -544,  -544,   174,  -544,   177,  -544,  -544,
     178,   183,  -544,  -544,  -544,  -544,  -544,  -544,  -544,  -544,
    -544,  -544,  -544,  -544,  -544,   184,  -544,  -544,  -544,   185,
     186,  -544,  -544,  -544,  -544,  -544,  -544,   187,  -544,  -544,
     190,  -544,  -544,  -544,   191,  -544,  -544,  -544,   192,   193,
     196,   197,  -544,  -544,  -544,   198,   201,  -544,  -544,   202,
     203,   204,  -117,  -544,  -544,  -544,  1636,   882,   133,   222,
     254,   266,   280,   281,   155,   127,  -544,  -544,  -544,  -544,
      97,   189,   206,  -544,  -544,  -544,  -544,  -544,   -41,  -544,
    -544,  -544,   289,   156,  -544,  -544,  -544,  -544,  -544,  -544,
    -544,  -544,  -544,  -544,  -544,  -544,    97,    97,  -544,   208,
    -133,  -544,  -544,  -544,    77,  -544,  -544,  -544,   141,   298,
    -544,   219,   205,  -544,   225,  -544,   408,   165,   298,    84,
      84,   419,   422,    84,    84,   445,   446,    84,   448,    84,
      84,  2109,    84,    84,   449,   -23,   450,    84,  2737,    84,
      84,  2737,   199,  2737,  2737,   165,   180,   452,  2737,  2890,
     258,  -544,   255,  -544,  -544,  -544,   260,  -544,   264,  -544,
    -544,  -544,    45,  2633,  -544,   267,  -544,  -544,  -544,  -544,
     267,  -108,  -544,  -544,     5,  -544,   284,   -62,   272,   275,
    -544,  -544,  1224,    39,   273,  -544,    84,   468,  2109,  -544,
    -544,  -544,   282,   307,  -544,   283,   485,  -544,    47,   133,
      51,   286,  -544,  -544,   287,   288,  -544,  -544,  -544,  -544,
    -544,  -544,  -544,  -544,  -544,   290,  -544,    84,    84,    84,
      84,    84,    84,   706,  2397,  -111,  -544,  2397,   294,   296,
    -544,  -106,   299,   300,   302,   310,   311,   312,   314,  1428,
     315,  2633,    43,   317,   -87,  -544,  2397,   319,   320,   321,
     340,   322,   -72,  2179,   323,  -544,  -544,  -544,  -544,  -544,
     324,   326,   327,   336,   332,  -544,   337,   341,   342,  -544,
    2890,   484,  -544,  -544,  -544,    97,    45,    28,  -544,  1120,
    -544,   365,  2633,   348,  1507,   351,   469,  1328,    45,  -544,
    2633,  -544,  -544,  -544,  -544,   716,  -544,  2300,   352,   377,
    -544,  -544,  -544,   298,    84,  -544,    20,  -544,  2633,  -544,
     354,  -544,   353,  -544,   359,  -544,  -544,  -544,  2633,    12,
      12,    12,    12,    12,    12,  2272,   263,    84,    84,   565,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,   568,    84,    84,
    -544,  -544,  -544,   563,  -544,  -544,  -544,  -544,  -544,  -544,
    -544,  -544,  -544,  -544,    43,  -544,  1885,  -544,    43,  -544,
    -544,  -544,   -42,  -544,    84,  -544,  -544,  -544,  -544,    84,
    -544,  -544,  -544,  -544,  -544,  -544,  -544,  -544,   567,  -544,
    -544,  -544,  -544,   364,  -544,  -544,   392,  -544,  -544,  -544,
    -544,    97,   105,  -544,  -544,  2633,   369,  -544,  -544,  -544,
      45,  -544,  -544,  -544,  -544,  2064,  -544,  -544,  -544,  -544,
      43,   370,   298,  -544,  -544,   263,  -544,  -544,  1930,  -544,
     263,  -544,   378,   -31,   181,   181,  -544,   743,   743,   104,
     104,   628,  2342,  2376,  2415,   406,   350,   104,   104,   116,
     116,    12,    12,    12,  -544,  2322,  -544,  -544,  -544,    35,
    -544,   379,    43,   380,  -544,  2109,  -544,  -544,   381,  -544,
      45,  1001,    97,  -544,  -544,  1432,  -544,  -544,  -544,   402,
    -544,  -127,  -544,   386,  -544,   393,    69,  -544,   394,    43,
     395,  -544,    84,  2109,  -544,    84,  -544,  -544,    35,  -544,
    -544,  -544,   396,  -544,  -544,  -544,  -544,    45,    84,  -544,
      43,  -544,  -544,  -544,  -544,    35,  -544,  -544,  -544,    12,
     397,  2397,  -544,  -544,  -544,  -544,  -544,    -8,  -544,  -544,
      84,   417,  -544,  -544,   423,  -107,  -107,  -544,  -544,   403,
    -544,  -544
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     2,     1,    33,   381,   271,   263,   282,     0,
     320,     0,     0,   270,   258,   272,   316,   269,   273,   274,
       0,   319,   276,   283,   284,   281,     0,   274,     0,     0,
     318,     0,   274,     0,   278,   317,   258,   258,   268,   380,
     264,    74,    12,    34,     0,    28,    13,    31,    13,    11,
       0,    67,   383,     0,   382,   265,     0,     0,     9,     0,
       0,     0,    26,     0,   302,     7,     6,     0,    10,   325,
     325,   325,     0,     0,   385,   325,     0,   387,   285,   286,
       0,   293,   294,   384,   260,     0,   275,   280,     0,   304,
     305,   279,   289,     0,     0,   277,   266,   386,     0,   388,
       0,   267,    75,     0,    77,    78,     0,    79,    80,    81,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    95,    96,    97,     0,    99,   100,   101,
       0,     0,   104,   105,   106,   107,     0,     0,     0,     0,
       0,   113,     0,   115,   116,     0,   118,     0,   120,   121,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,   139,   140,   141,     0,
       0,   144,   145,   146,   147,   378,   148,     0,   150,   376,
       0,   152,   153,   154,     0,   156,   157,   158,     0,     0,
       0,     0,   163,   377,   164,     0,     0,   168,   169,     0,
       0,     0,     0,    69,   173,    29,    66,    66,    66,   258,
       0,     0,   258,   258,     0,   383,   287,   295,   306,   314,
       0,   385,   387,    30,     8,   290,     4,   311,     0,    27,
     309,   310,     0,     0,    24,   329,   326,   328,   327,   261,
     262,   176,   177,   178,   179,   321,     0,     0,   333,   369,
     332,   255,   383,   385,   325,   387,   323,    32,     0,   184,
      48,     0,     0,   241,     0,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      68,    49,     0,    21,    22,    23,     0,    19,     0,    17,
      14,    20,    26,     0,    67,   384,    51,    52,   312,   313,
     386,   388,    53,   254,    66,     3,     0,    66,     0,     0,
     303,    24,    66,     0,     0,   331,     0,     0,    55,   335,
     324,    47,     0,   186,   187,   190,     0,   389,    66,    66,
      66,     0,   175,   174,     0,     0,   205,   196,   197,   198,
     202,   203,   204,   199,   200,     0,   201,     0,     0,     0,
       0,     0,     0,     0,   239,     0,   237,   240,     0,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,     0,     0,   192,   195,     0,     0,     0,
       0,     0,     0,     0,     0,   371,   372,   373,   374,   375,
       0,     0,     0,     0,   393,   395,     0,     0,     0,    70,
      74,     0,    18,    15,    54,     0,    26,     0,   291,    66,
     296,     0,     0,     0,     0,     0,     0,    66,    26,    25,
      67,   322,   330,   334,   370,     0,    65,     0,     0,    59,
      56,    57,   191,   185,     0,    36,     0,   379,     0,   242,
       0,   391,    67,   248,     0,    76,   167,    82,     0,   229,
     228,   227,   230,   225,   226,     0,   342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    94,    98,     0,   102,   103,   108,   109,   110,   111,
     112,   114,   117,   119,   354,   321,    55,   359,   354,   356,
     355,    62,   351,   123,   194,   122,   138,   142,   143,     0,
     151,   155,   159,   160,   162,   161,   165,   166,     0,   170,
     171,   172,    71,     0,    13,   362,   390,   288,   292,     5,
     298,     0,   385,   297,   300,     0,     0,   253,   301,    24,
      26,   315,    64,    63,   336,     0,   188,   189,    37,    35,
       0,   387,   256,   246,   245,   342,   236,   321,    55,   346,
     342,   343,     0,   339,   218,   219,   231,   212,   213,   216,
     217,   207,   208,     0,   209,   210,   211,   215,   214,   221,
     220,   223,   224,   222,   232,     0,   238,    73,    61,   354,
     321,     0,   354,     0,   350,    55,   358,   193,     0,   394,
      26,    66,     0,   251,   299,    66,   307,    60,    58,   364,
     367,     0,   244,     0,   257,     0,   342,   321,     0,   354,
       0,   338,     0,    55,   345,     0,   235,   349,   354,   360,
     353,   357,     0,   149,    50,    16,   363,    26,     0,   366,
       0,   243,   180,   234,   337,   354,   347,   341,   344,   233,
       0,   206,   352,   361,   308,   365,   368,     0,   340,   348,
       0,     0,   392,   181,     0,    66,    66,   250,   183,     0,
     182,   249
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -544,  -544,   291,  -544,   -44,  -544,  -317,  -304,     0,  -544,
    -544,  -544,  -544,  -544,   176,  -544,  -544,  -544,    11,  -471,
    -544,  -544,  -265,  -233,  -198,    -2,  -544,  -544,  -262,   329,
     -67,  -544,  -544,  -544,  -544,   161,    13,   331,    91,   212,
    -544,  -217,  -267,  -544,  -544,  -544,  -544,   -68,  -190,  -544,
     215,  -544,    48,   -65,  -544,   157,   152,    10,  -544,    17,
      19,  -544,  -544,   570,  -544,  -544,  -544,  -544,  -544,   -22,
    -544,    22,    16,  -544,  -544,    23,  -544,  -544,  -322,  -462,
     -50,   -20,   -36,  -224,  -544,  -544,  -544,  -512,  -544,  -543,
    -544,  -482,  -544,  -544,  -544,   -33,  -544,   409,  -544,   346,
       1,   -53,  -544,     7,  -544
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   325,   206,   544,   332,   230,   303,    43,
     456,    44,    45,    46,    47,   304,   214,    48,   305,   448,
     449,   450,   451,   517,    50,   314,   202,   381,   203,   354,
     518,   677,   683,   342,   343,   344,   252,   394,   395,   374,
     375,   376,   378,   348,   459,   463,   350,   688,   689,   556,
      53,   633,    85,   519,    54,    87,    55,   306,    57,   307,
     308,   324,   428,    60,    61,   327,   434,    62,   233,    63,
      64,   309,   310,   219,    67,   311,    69,    70,    71,   333,
      72,   235,    73,   249,   250,   581,   640,   582,   583,   520,
     613,   521,   522,   546,   659,   630,   631,   251,   410,   204,
     253,    75,    76,   255,   416
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,   220,    42,    74,   207,   247,   382,   248,   424,    77,
     313,   441,    56,    49,   437,    52,   390,   339,    66,    58,
     254,    59,   334,   335,    65,    68,   568,   629,   479,   218,
     680,   264,   608,   236,   236,   236,   614,   419,   239,   236,
     240,   262,   239,   681,   240,   611,   239,   431,   240,  -259,
     237,   238,   221,   609,  -259,   256,   660,   383,   222,    26,
     386,   216,   388,   635,   215,   393,   299,     3,   641,   444,
     400,   337,   499,    78,   241,    79,   338,   503,   241,    10,
     265,   661,   241,    10,    98,   100,    12,   356,   300,   326,
     357,   358,   359,   360,   361,   362,   524,    41,  -259,   500,
     239,   687,   240,  -259,   504,   -43,   242,   638,   241,   442,
     242,   524,   175,    10,   242,   636,   179,   629,   477,   478,
     479,    10,   547,   525,   664,    80,   427,   647,    26,   432,
     650,    81,   479,    82,   561,    88,   241,   433,   531,    83,
     242,    84,    41,   193,   652,    89,    16,    90,   648,    86,
     458,   432,   432,   247,   363,   248,    92,   667,   542,   460,
     464,   243,   337,    93,    94,   243,   672,   615,   242,   243,
     205,    21,   670,   337,   352,   665,   -38,   353,   643,   247,
     247,   248,   248,   678,    91,    96,   414,   415,   244,    95,
     101,    97,   244,    84,   345,   243,   244,   479,    99,   682,
      84,   545,   364,   355,    51,    51,   328,    74,    74,    41,
     223,   224,   426,    77,    77,   497,   498,    30,   236,    52,
      52,   208,   244,   243,  -259,   315,   -39,    84,   515,    35,
     569,   392,   245,   365,   340,   401,   515,   567,   404,   337,
     411,   412,   625,   579,   516,   418,   366,   337,   246,   227,
     244,    41,   516,   229,   457,    41,   626,   316,   461,   317,
      98,   100,   577,   425,   231,  -259,   247,   -41,   248,   318,
     225,   319,   367,   337,   226,   368,   369,   370,   578,   391,
     371,   372,   606,   320,   321,    84,    84,   441,   392,   616,
     245,   228,   329,   373,   330,   492,   493,   494,   495,   496,
     628,   239,   241,   240,   232,   234,   246,   497,   498,   494,
     495,   496,   618,  -252,   441,  -252,   654,   -40,   257,   497,
     498,   -42,   258,   476,   259,   260,   441,   623,   261,   263,
     440,   266,   439,    74,   242,   -44,   391,    41,   267,    77,
     268,   514,   579,   441,   269,    52,   270,   579,   462,   271,
     644,   341,   272,   674,   273,   274,   275,   276,   247,   277,
     248,   322,   331,   278,   477,   478,   479,   480,   481,   482,
     483,   279,   492,   493,   494,   495,   496,   405,   406,   407,
     408,   409,   551,   280,   497,   498,   281,   282,   345,   243,
     220,   675,   283,   284,   285,   286,   287,   -45,   656,   288,
     289,   290,   291,   579,   346,   292,   293,   294,   570,   580,
     295,   296,   297,   298,   -46,   347,   244,   351,   575,   336,
     477,   478,   479,   480,   481,   482,   483,    51,   379,    42,
      74,   380,   555,   552,   349,   440,    77,   439,    74,    56,
      49,   221,    52,   548,    77,    66,    58,   222,    59,   612,
      52,    65,    68,   215,   384,   385,   577,   387,   397,   399,
       8,   417,   420,   684,   421,   571,   392,   337,   422,   430,
     423,   356,   578,  -259,   357,   358,   359,   360,   361,   362,
     435,   436,   377,   443,   247,   377,   248,   432,   432,   452,
     453,   455,   389,   543,   454,   396,   465,   466,   467,   468,
     621,   396,   403,    19,   501,   220,   502,   634,   580,   505,
     506,   639,   507,   580,   391,   392,    22,    23,    24,    25,
     508,   509,   510,   529,   511,   513,    27,   523,   392,   526,
     527,   528,   530,   533,   534,   538,   535,   536,   363,   490,
     491,   492,   493,   494,   495,   496,   537,   539,   377,   447,
     550,   540,   541,   497,   498,   247,   553,   248,   558,    20,
     565,   573,   564,   391,   572,   392,    32,   574,   586,   580,
      34,   604,   607,   619,   620,   622,   391,   624,   632,   469,
     470,   471,   472,   473,   474,   475,   364,   658,   642,   649,
     651,   653,   662,   392,   489,   490,   491,   492,   493,   494,
     495,   496,   685,   663,   666,   668,   673,   679,   686,   497,
     498,   691,   559,   391,   566,   617,   429,   365,   690,    51,
     402,   217,    74,   440,   413,   439,    74,   676,    77,   323,
     366,   398,    77,     0,    52,     0,     0,     0,    52,     0,
       0,   391,   477,   478,   479,   480,   481,   482,   483,   557,
     485,     0,     0,     0,     0,     0,   367,   472,     0,   368,
     369,   445,     0,     0,   371,   372,     0,     0,     0,     0,
       0,     0,     0,   446,     0,     0,     0,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     585,     0,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   356,
     605,     5,   357,   358,   359,   360,   361,   362,     0,   356,
       0,     0,   357,   358,   359,   360,   361,   362,     0,     0,
       0,     0,     0,     0,     0,     0,   396,     0,     6,     0,
       7,     0,     0,     0,     0,     0,     8,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,   477,   478,   479,
       0,     0,   482,   483,     0,     0,    13,     0,     0,     0,
       0,     0,   209,    15,     0,    16,   363,     0,     0,    17,
       0,     0,    18,     0,     0,     0,   363,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,    27,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   364,     0,     0,     0,     0,     0,
       0,   497,   498,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,    31,    32,    33,   669,   365,    34,   671,    35,     0,
       0,     0,   212,     0,     0,   365,     0,     0,   366,     0,
     377,   213,     0,    38,     0,     0,     0,     0,   366,     0,
       0,    39,    40,     0,     0,     0,     4,     5,     0,     0,
       0,     0,     0,     0,   367,     0,     0,   368,   369,   370,
       0,     0,   371,   372,   367,     0,     0,   368,   369,   370,
       0,     0,   371,   372,     6,   373,     7,     0,     0,     0,
       0,   562,     8,     9,     0,   373,    10,     0,     0,     0,
       0,    11,   490,   491,   492,   493,   494,   495,   496,     0,
      12,     0,    13,     0,     0,     0,   497,   498,    14,    15,
       0,    16,     0,     0,     0,    17,     0,     0,    18,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    20,   302,     0,     0,    21,     0,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,    31,    32,    33,
       0,     0,    34,     6,    35,     7,     0,     0,    36,     0,
       0,     8,     9,     0,     0,    10,     0,    37,     0,    38,
      11,     0,     0,     0,     0,     0,     0,    39,    40,    12,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,    17,     0,     0,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    41,     0,     0,   312,
       0,    20,   302,     0,     0,    21,     0,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,    31,    32,    33,     0,
       0,    34,     6,    35,     7,     0,     0,    36,     0,     0,
       8,     9,     0,     0,    10,     0,    37,     0,    38,    11,
       0,     0,     0,     0,     0,     0,    39,    40,    12,     0,
      13,     0,     0,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,     0,     0,    18,     0,     0,     0,
       0,     0,     0,    19,     0,    41,     0,     0,   655,     0,
      20,     0,     0,     0,    21,     0,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    27,     0,     4,     5,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     7,     0,
      30,     0,     0,     0,     8,    31,    32,    33,    10,     0,
      34,     0,    35,    11,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,    13,    37,     0,    38,     0,     0,
      14,    15,     0,    16,     0,    39,    40,    17,     0,     0,
      18,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
      22,    23,    24,    25,    41,     0,     0,   549,     0,     0,
      27,     0,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     7,     0,    30,     0,     0,     0,     8,    31,
      32,    33,    10,     0,    34,     0,    35,    11,     0,     0,
      36,     0,     0,     0,     0,     0,     0,     0,    13,    37,
       0,    38,     0,     0,    14,    15,     0,    16,     0,    39,
      40,    17,     0,     0,    18,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,    21,     0,    22,    23,    24,    25,    41,     0,
       0,   438,     0,     0,    27,     0,     4,     5,     0,     0,
       0,     0,   477,   478,   479,   480,   481,   482,   483,   484,
     485,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     7,     0,    30,     0,
       0,     0,     8,    31,    32,    33,    10,     0,    34,     0,
      35,    11,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,    13,    37,     0,    38,     0,     0,    14,    15,
       0,    16,     0,    39,    40,    17,     0,     0,    18,     0,
       0,     0,     5,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,     0,    22,    23,
      24,    25,    41,     0,     0,   560,     0,     0,    27,     6,
       0,     7,     0,     0,     0,     0,     0,     8,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    30,   209,    15,     0,    16,    31,    32,    33,
      17,     0,    34,    18,    35,     0,     0,     0,    36,     0,
      19,     0,     0,     0,     0,     0,     0,    37,     0,    38,
       0,    21,     0,    22,    23,    24,    25,    39,    40,     0,
       0,     0,   486,    27,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,     0,     0,     0,     0,     0,     0,
       0,   497,   498,     0,     0,     0,    41,     0,   512,   657,
       4,     5,     0,     0,     0,     0,     0,    30,     0,   301,
       0,     0,    31,    32,    33,     0,     0,    34,     0,    35,
       0,     0,     0,   212,     0,     0,     0,     0,     6,     0,
       7,     0,   213,     0,    38,     0,     8,     9,     0,     0,
      10,     0,    39,    40,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,    16,     0,     0,     0,    17,
       0,    41,    18,     0,   554,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    20,   302,     0,     0,
      21,     0,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,    31,    32,    33,     0,     0,    34,     6,    35,     7,
       0,     0,    36,     0,     0,     8,     9,     0,     0,    10,
       0,    37,     0,    38,    11,     0,     0,     0,     0,     0,
       0,    39,    40,    12,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,    16,     0,     0,     0,    17,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      41,     0,     0,     0,     0,    20,     0,     0,     0,    21,
       0,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,    30,     0,     0,     0,     0,
      31,    32,    33,     0,     0,    34,     0,    35,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     6,   -66,     7,
      37,     0,    38,     0,   241,     8,     0,     0,     0,    10,
      39,    40,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,   209,    15,     0,    16,     0,   242,     0,    17,    41,
       0,    18,     6,     0,     7,     0,     0,     0,    19,   241,
       8,     0,     0,     0,    10,     0,     0,     0,     0,    21,
       0,    22,    23,    24,    25,     0,     0,     0,     0,     0,
      13,    27,     0,     0,     0,     0,   209,    15,     0,    16,
       0,   242,     0,    17,     0,     0,    18,     0,     0,     0,
       0,   243,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    30,    22,    23,    24,    25,
      31,    32,    33,     0,     0,    34,    27,    35,   244,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,     0,
     213,     0,    38,     0,     0,     0,   243,     0,     0,     0,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     5,
      30,     0,     0,     0,     0,    31,    32,    33,   610,     0,
      34,     0,    35,   244,     0,     0,   212,   627,     0,    41,
       0,     0,     0,     0,     0,   213,     6,    38,     7,     0,
       0,     0,     0,     0,     8,    39,    40,     0,    10,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,   637,    13,     0,     0,     0,     0,     0,
     209,    15,     0,    16,    41,     0,     0,    17,     0,     0,
      18,     6,     0,     7,     0,     0,     0,    19,     0,     8,
       0,     0,     0,    10,     0,     0,     0,     0,    21,     0,
      22,    23,    24,    25,     0,     0,     0,     0,     0,    13,
      27,     0,     0,     0,     0,   209,    15,     0,    16,     0,
       0,     0,    17,     0,     0,    18,     0,     0,     0,     0,
       0,     0,    19,   477,   478,   479,   480,   481,   482,   483,
     484,   485,     0,    21,    30,    22,    23,    24,    25,    31,
      32,    33,     0,     0,    34,    27,    35,     0,     0,     0,
     212,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,    38,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,    31,    32,    33,     0,     0,    34,
       0,    35,     0,     0,     0,   212,     0,     0,    41,     0,
       0,     0,     0,     0,   213,     0,    38,     0,     0,     0,
       0,     0,     0,     0,    39,    40,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,   477,   478,   479,   480,   481,   482,
     483,   484,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,   480,
     481,   482,   483,   484,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   478,   479,   480,
     481,   482,   483,   486,     0,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,     0,     0,     0,     0,     0,
       0,     0,   497,   498,     0,     0,     0,     0,     0,   532,
     477,   478,   479,   480,   481,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   477,   478,   479,   480,   481,   482,   483,   484,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
     478,   479,   480,   481,   482,   483,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   486,     0,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,     0,     0,
       0,     0,     0,     0,     0,   497,   498,     0,     0,     0,
       0,     0,   576,     0,   486,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,     0,     0,     0,     0,
       0,     0,     0,   497,   498,   563,   486,     0,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,     0,     0,
       0,     0,     0,     0,     0,   497,   498,   646,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,     0,     0,
       0,     0,     0,     0,     0,   497,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,   645,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,     0,     0,     0,     0,     0,     0,     0,   497,
     498,   486,     0,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,     5,     0,     0,     0,     0,     0,     0,
     497,   498,   488,   489,   490,   491,   492,   493,   494,   495,
     496,     0,     0,     0,     0,     0,     0,     0,   497,   498,
       6,     0,     7,     0,     0,     0,     0,     0,     8,     9,
       0,     0,    10,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,    12,     0,    13,     0,
       0,     0,     0,     0,   209,    15,     0,    16,     0,     0,
       0,    17,     0,     0,    18,     6,     0,     7,     0,     0,
       0,    19,     0,     8,     0,     0,     0,    10,     0,     0,
       0,     0,    21,     0,    22,    23,    24,    25,    26,     0,
       0,   210,     0,    13,    27,     0,     0,     0,   211,   209,
      15,     0,    16,     0,     0,     0,    17,     0,     0,    18,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    30,    22,
      23,    24,    25,    31,    32,    33,     0,     0,    34,    27,
      35,     0,     5,     0,   212,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,    38,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,     0,     0,     6,
       0,     7,     0,    30,     0,     0,     0,     8,    31,    32,
      33,     0,     0,    34,     0,    35,     0,     0,     0,   212,
       0,     0,     0,     0,     0,     0,     0,    13,   213,     0,
      38,     0,     0,   209,    15,     0,     0,     0,    39,    40,
      17,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,     0,     0,    34,     0,     0,
       0,     0,     0,   212,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,    38,     0,     0,     0,     0,     0,
       0,     0,    39,    40,   102,     0,   103,   104,   105,   106,
     107,   108,     0,   109,     0,     0,   110,     0,   111,     0,
       0,     0,   112,   113,     0,   114,   115,   116,   117,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,   129,   130,   131,     0,     0,   132,     0,
       0,     0,   133,     0,   134,   135,     0,   136,   137,   138,
     139,   140,   141,     0,   142,   143,   144,   145,   146,   147,
       0,     0,   148,     0,     0,   149,     0,     0,     0,     0,
       0,   150,   151,     0,   152,   153,     0,   154,   155,     0,
       0,     0,   156,   157,   158,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,     0,   169,     0,   170,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,   180,   181,   182,   183,     0,     0,     0,   184,     0,
       0,   185,     0,     0,   186,   187,     0,     0,   188,   189,
     190,   191,     0,     0,   192,     0,   193,     0,   194,   195,
     196,   197,   198,   199,   200,     0,     0,   201
};

static const yytype_int16 yycheck[] =
{
       2,    51,     2,     2,    48,    72,   273,    72,   312,     2,
     208,   333,     2,     2,   331,     2,   281,   250,     2,     2,
      73,     2,   246,   247,     2,     2,     6,   570,    16,    51,
      38,   157,   514,    69,    70,    71,   518,   299,     3,    75,
       5,    94,     3,    51,     5,   516,     3,   109,     5,   157,
      70,    71,    51,   515,   157,    75,   183,   274,    51,   100,
     277,    51,   279,   575,    51,   282,   183,     0,   580,   336,
     287,   204,   183,     3,    39,     5,   209,   183,    39,    44,
     206,   208,    39,    44,    36,    37,    58,     3,   205,   130,
       6,     7,     8,     9,    10,    11,   183,   204,   206,   210,
       3,   208,     5,   206,   210,   208,    71,   578,    39,   333,
      71,   183,   135,    44,    71,   577,   139,   660,    14,    15,
      16,    44,   426,   210,   636,   209,   324,   609,   100,   327,
     612,     3,    16,     5,   438,     9,    39,   327,   210,     3,
      71,     5,   204,   166,   615,     3,    69,     5,   610,    96,
     348,   349,   350,   220,    70,   220,     3,   639,   420,   349,
     350,   126,   204,   209,   209,   126,   648,   209,    71,   126,
     208,    94,   643,   204,     9,   637,   208,    12,   209,   246,
     247,   246,   247,   665,    27,    33,     6,     7,   153,    32,
      38,     3,   153,     5,   259,   126,   153,    16,     3,   207,
       5,   425,   118,   268,   206,   207,   228,   206,   207,   204,
     208,   208,   207,   206,   207,   203,   204,   140,   254,   206,
     207,   163,   153,   126,   206,     3,   208,     5,   193,   152,
     210,   281,   193,   149,   254,   288,   193,   454,   291,   204,
     293,   294,   559,   476,   209,   298,   162,   204,   209,   208,
     153,   204,   209,   208,   207,   204,   560,     3,   207,     5,
     212,   213,   193,   313,   208,   206,   333,   208,   333,     3,
     206,     5,   188,   204,   206,   191,   192,   193,   209,   281,
     196,   197,   499,     3,     3,     5,     5,   609,   338,   522,
     193,   206,     3,   209,     5,   191,   192,   193,   194,   195,
     565,     3,    39,     5,   185,   206,   209,   203,   204,   193,
     194,   195,   529,   208,   636,   210,   620,   208,   208,   203,
     204,   208,     9,   373,   206,   208,   648,   551,     3,   206,
     332,   209,   332,   332,    71,   208,   338,   204,   209,   332,
     209,   391,   575,   665,   209,   332,   209,   580,   350,   209,
     583,   210,   209,   657,   209,   209,   209,   209,   425,   209,
     425,   206,   206,   209,    14,    15,    16,    17,    18,    19,
      20,   209,   191,   192,   193,   194,   195,   178,   179,   180,
     181,   182,   432,   209,   203,   204,   209,   209,   453,   126,
     440,   658,   209,   209,   209,   209,   209,   208,   622,   209,
     209,   209,   209,   636,   185,   209,   209,   209,   458,   476,
     209,   209,   209,   209,   208,   210,   153,     9,   468,   211,
      14,    15,    16,    17,    18,    19,    20,   429,     9,   429,
     429,     9,   434,   432,   209,   437,   429,   437,   437,   429,
     429,   440,   429,   427,   437,   429,   429,   440,   429,   516,
     437,   429,   429,   440,     9,     9,   193,     9,     9,     9,
      40,     9,   204,   680,   209,   458,   516,   204,   208,   185,
     206,     3,   209,   206,     6,     7,     8,     9,    10,    11,
     208,   206,   270,   210,   551,   273,   551,   685,   686,   207,
     183,     6,   280,     9,   211,   283,   210,   210,   210,   209,
     544,   289,   290,    83,   210,   555,   210,   572,   575,   210,
     210,   578,   210,   580,   516,   565,    96,    97,    98,    99,
     210,   210,   210,   183,   210,   210,   106,   210,   578,   210,
     210,   210,   210,   210,   210,   203,   210,   210,    70,   189,
     190,   191,   192,   193,   194,   195,   210,   210,   336,   337,
     185,   210,   210,   203,   204,   622,   208,   622,   207,    90,
     183,   208,   210,   565,   210,   615,   146,   208,     3,   636,
     150,     3,     9,     6,   210,   183,   578,   208,   208,   367,
     368,   369,   370,   371,   372,   373,   118,   185,   210,   210,
     210,   210,   206,   643,   188,   189,   190,   191,   192,   193,
     194,   195,   185,   210,   210,   210,   210,   210,   185,   203,
     204,   208,   436,   615,   453,   524,   325,   149,   686,   621,
     289,    51,   621,   625,   295,   625,   625,   660,   621,   220,
     162,   285,   625,    -1,   621,    -1,    -1,    -1,   625,    -1,
      -1,   643,    14,    15,    16,    17,    18,    19,    20,   434,
      22,    -1,    -1,    -1,    -1,    -1,   188,   445,    -1,   191,
     192,   193,    -1,    -1,   196,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,
     478,    -1,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,     3,
     498,     5,     6,     7,     8,     9,    10,    11,    -1,     3,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   524,    -1,    32,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    70,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    -1,    70,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,   642,   149,   150,   645,   152,    -1,
      -1,    -1,   156,    -1,    -1,   149,    -1,    -1,   162,    -1,
     658,   165,    -1,   167,    -1,    -1,    -1,    -1,   162,    -1,
      -1,   175,   176,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,   191,   192,   193,
      -1,    -1,   196,   197,   188,    -1,    -1,   191,   192,   193,
      -1,    -1,   196,   197,    32,   209,    34,    -1,    -1,    -1,
      -1,   205,    40,    41,    -1,   209,    44,    -1,    -1,    -1,
      -1,    49,   189,   190,   191,   192,   193,   194,   195,    -1,
      58,    -1,    60,    -1,    -1,    -1,   203,   204,    66,    67,
      -1,    69,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,    94,    -1,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,    -1,   150,    32,   152,    34,    -1,    -1,   156,    -1,
      -1,    40,    41,    -1,    -1,    44,    -1,   165,    -1,   167,
      49,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,   204,    -1,    -1,   207,
      -1,    90,    91,    -1,    -1,    94,    -1,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
      -1,   150,    32,   152,    34,    -1,    -1,   156,    -1,    -1,
      40,    41,    -1,    -1,    44,    -1,   165,    -1,   167,    49,
      -1,    -1,    -1,    -1,    -1,    -1,   175,   176,    58,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,   204,    -1,    -1,   207,    -1,
      90,    -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,   106,    -1,     4,     5,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
     140,    -1,    -1,    -1,    40,   145,   146,   147,    44,    -1,
     150,    -1,   152,    49,    -1,    -1,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,   165,    -1,   167,    -1,    -1,
      66,    67,    -1,    69,    -1,   175,   176,    73,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,
      96,    97,    98,    99,   204,    -1,    -1,   207,    -1,    -1,
     106,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,   140,    -1,    -1,    -1,    40,   145,
     146,   147,    44,    -1,   150,    -1,   152,    49,    -1,    -1,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,   165,
      -1,   167,    -1,    -1,    66,    67,    -1,    69,    -1,   175,
     176,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    96,    97,    98,    99,   204,    -1,
      -1,   207,    -1,    -1,   106,    -1,     4,     5,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34,    -1,   140,    -1,
      -1,    -1,    40,   145,   146,   147,    44,    -1,   150,    -1,
     152,    49,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,   165,    -1,   167,    -1,    -1,    66,    67,
      -1,    69,    -1,   175,   176,    73,    -1,    -1,    76,    -1,
      -1,    -1,     5,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    96,    97,
      98,    99,   204,    -1,    -1,   207,    -1,    -1,   106,    32,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,   140,    66,    67,    -1,    69,   145,   146,   147,
      73,    -1,   150,    76,   152,    -1,    -1,    -1,   156,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,   165,    -1,   167,
      -1,    94,    -1,    96,    97,    98,    99,   175,   176,    -1,
      -1,    -1,   184,   106,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,    -1,    -1,    -1,   204,    -1,   210,   207,
       4,     5,    -1,    -1,    -1,    -1,    -1,   140,    -1,    13,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,   152,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,   165,    -1,   167,    -1,    40,    41,    -1,    -1,
      44,    -1,   175,   176,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,    73,
      -1,   204,    76,    -1,   207,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,
      94,    -1,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,    -1,   150,    32,   152,    34,
      -1,    -1,   156,    -1,    -1,    40,    41,    -1,    -1,    44,
      -1,   165,    -1,   167,    49,    -1,    -1,    -1,    -1,    -1,
      -1,   175,   176,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
     204,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,    -1,   150,    -1,   152,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    32,   163,    34,
     165,    -1,   167,    -1,    39,    40,    -1,    -1,    -1,    44,
     175,   176,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    69,    -1,    71,    -1,    73,   204,
      -1,    76,    32,    -1,    34,    -1,    -1,    -1,    83,    39,
      40,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      60,   106,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      -1,    71,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,   126,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,   140,    96,    97,    98,    99,
     145,   146,   147,    -1,    -1,   150,   106,   152,   153,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,    -1,   167,    -1,    -1,    -1,   126,    -1,    -1,    -1,
     175,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
     140,    -1,    -1,    -1,    -1,   145,   146,   147,   193,    -1,
     150,    -1,   152,   153,    -1,    -1,   156,    23,    -1,   204,
      -1,    -1,    -1,    -1,    -1,   165,    32,   167,    34,    -1,
      -1,    -1,    -1,    -1,    40,   175,   176,    -1,    44,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,   204,    -1,    -1,    73,    -1,    -1,
      76,    32,    -1,    34,    -1,    -1,    -1,    83,    -1,    40,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    94,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    60,
     106,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    94,   140,    96,    97,    98,    99,   145,
     146,   147,    -1,    -1,   150,   106,   152,    -1,    -1,    -1,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,   152,    -1,    -1,    -1,   156,    -1,    -1,   204,    -1,
      -1,    -1,    -1,    -1,   165,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   175,   176,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,   204,    -1,    -1,    -1,    -1,    -1,   210,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,   204,    -1,    -1,    -1,
      -1,    -1,   210,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,   204,   205,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
     204,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     5,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   204,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
      -1,    73,    -1,    -1,    76,    32,    -1,    34,    -1,    -1,
      -1,    83,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    98,    99,   100,    -1,
      -1,   103,    -1,    60,   106,    -1,    -1,    -1,   110,    66,
      67,    -1,    69,    -1,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,   140,    96,
      97,    98,    99,   145,   146,   147,    -1,    -1,   150,   106,
     152,    -1,     5,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,   140,    -1,    -1,    -1,    40,   145,   146,
     147,    -1,    -1,   150,    -1,   152,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,   165,    -1,
     167,    -1,    -1,    66,    67,    -1,    -1,    -1,   175,   176,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   175,   176,    24,    -1,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    42,    43,    -1,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    -1,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,   104,   105,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,   127,    -1,   129,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,   141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,   151,    -1,    -1,   154,   155,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,    -1,   166,    -1,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,   177
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   213,   214,     0,     4,     5,    32,    34,    40,    41,
      44,    49,    58,    60,    66,    67,    69,    73,    76,    83,
      90,    94,    96,    97,    98,    99,   100,   106,   111,   128,
     140,   145,   146,   147,   150,   152,   156,   165,   167,   175,
     176,   204,   220,   221,   223,   224,   225,   226,   229,   230,
     236,   237,   248,   262,   266,   268,   269,   270,   271,   272,
     275,   276,   279,   281,   282,   283,   284,   286,   287,   288,
     289,   290,   292,   294,   312,   313,   314,   315,     3,     5,
     209,     3,     5,     3,     5,   264,    96,   267,     9,     3,
       5,   267,     3,   209,   209,   267,   268,     3,   264,     3,
     264,   268,    24,    26,    27,    28,    29,    30,    31,    33,
      36,    38,    42,    43,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    59,    61,    62,    63,
      64,    65,    68,    72,    74,    75,    77,    78,    79,    80,
      81,    82,    84,    85,    86,    87,    88,    89,    92,    95,
     101,   102,   104,   105,   107,   108,   112,   113,   114,   115,
     116,   117,   119,   120,   121,   122,   123,   124,   125,   127,
     129,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     141,   142,   143,   144,   148,   151,   154,   155,   158,   159,
     160,   161,   164,   166,   168,   169,   170,   171,   172,   173,
     174,   177,   238,   240,   311,   208,   216,   216,   163,    66,
     103,   110,   156,   165,   228,   248,   269,   275,   281,   285,
     292,   312,   315,   208,   208,   206,   206,   208,   206,   208,
     219,   208,   185,   280,   206,   293,   294,   293,   293,     3,
       5,    39,    71,   126,   153,   193,   209,   242,   265,   295,
     296,   309,   248,   312,   313,   315,   293,   208,     9,   206,
     208,     3,   313,   206,   157,   206,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   183,
     205,    13,    91,   220,   227,   230,   269,   271,   272,   283,
     284,   287,   207,   236,   237,     3,     3,     5,     3,     5,
       3,     3,   206,   309,   273,   215,   130,   277,   281,     3,
       5,   206,   218,   291,   295,   295,   211,   204,   209,   235,
     293,   210,   245,   246,   247,   265,   185,   210,   255,   209,
     258,     9,     9,    12,   241,   265,     3,     6,     7,     8,
       9,    10,    11,    70,   118,   149,   162,   188,   191,   192,
     193,   196,   197,   209,   251,   252,   253,   251,   254,     9,
       9,   239,   254,   253,     9,     9,   253,     9,   253,   251,
     234,   237,   292,   253,   249,   250,   251,     9,   311,     9,
     253,   313,   249,   251,   313,   178,   179,   180,   181,   182,
     310,   313,   313,   241,     6,     7,   316,     9,   313,   240,
     204,   209,   208,   206,   219,   292,   207,   236,   274,   214,
     185,   109,   236,   260,   278,   208,   206,   218,   207,   220,
     237,   290,   295,   210,   254,   193,   205,   251,   231,   232,
     233,   234,   207,   183,   211,     6,   222,   207,   236,   256,
     260,   207,   237,   257,   260,   210,   210,   210,   209,   251,
     251,   251,   251,   251,   251,   251,   292,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   184,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   203,   204,   183,
     210,   210,   210,   183,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   292,   193,   209,   235,   242,   265,
     301,   303,   304,   210,   183,   210,   210,   210,   210,   183,
     210,   210,   210,   210,   210,   210,   210,   210,   203,   210,
     210,   210,   240,     9,   217,   295,   305,   219,   284,   207,
     185,   292,   312,   208,   207,   237,   261,   262,   207,   226,
     207,   219,   205,   205,   210,   183,   247,   253,     6,   210,
     292,   315,   210,   208,   208,   292,   210,   193,   209,   235,
     242,   297,   299,   300,   251,   251,     3,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,     3,   251,   253,     9,   303,   291,
     193,   231,   242,   302,   303,   209,   235,   250,   253,     6,
     210,   216,   183,   295,   208,   218,   219,    23,   234,   301,
     307,   308,   208,   263,   265,   299,   291,   193,   231,   242,
     298,   299,   210,   209,   235,   185,   205,   303,   291,   210,
     303,   210,   231,   210,   219,   207,   295,   207,   185,   306,
     183,   208,   206,   210,   299,   291,   210,   303,   210,   251,
     231,   251,   303,   210,   219,   254,   307,   243,   303,   210,
      38,    51,   207,   244,   253,   185,   185,   208,   259,   260,
     259,   208
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   212,   213,   214,   215,   214,   214,   214,   214,   214,
     214,   214,   214,   216,   216,   217,   216,   216,   216,   216,
     216,   216,   216,   216,   218,   218,   219,   219,   220,   220,
     220,   220,   220,   220,   220,   221,   222,   222,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   224,   225,   226,
     227,   228,   228,   229,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   235,   236,   236,   237,   238,
     238,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   241,   241,   242,   242,   242,   242,
     243,   243,   244,   244,   245,   245,   245,   246,   246,   247,
     247,   248,   249,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   252,   252,   253,
     254,   255,   255,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   262,   262,   263,   263,   264,   264,
     264,   265,   265,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   269,   269,   270,   271,   272,
     273,   273,   274,   275,   275,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   281,   281,   282,   283,   283,   283,
     284,   284,   285,   285,   286,   287,   288,   288,   288,   289,
     290,   291,   291,   292,   292,   293,   293,   294,   294,   294,
     295,   295,   295,   296,   296,   296,   296,   297,   297,   297,
     298,   298,   299,   299,   300,   300,   300,   300,   300,   301,
     301,   301,   302,   302,   303,   303,   304,   304,   304,   304,
     304,   304,   305,   305,   306,   306,   307,   308,   308,   309,
     309,   310,   310,   310,   310,   310,   311,   311,   311,   312,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     314,   315,   315,   316,   316,   316
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     0,     6,     2,     2,     3,     2,
       2,     2,     2,     0,     2,     0,     6,     2,     3,     2,
       2,     2,     2,     2,     0,     2,     0,     1,     1,     2,
       2,     1,     2,     1,     1,     6,     1,     2,     1,     2,
       1,     2,     1,     2,     2,     2,     2,     4,     3,     3,
       5,     2,     2,     3,     4,     0,     1,     1,     3,     1,
       3,     3,     2,     3,     3,     2,     0,     1,     3,     1,
       3,     4,     1,     3,     0,     1,     4,     1,     1,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     1,     4,     1,     1,     4,     1,     4,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     6,
       1,     4,     1,     1,     1,     4,     1,     1,     1,     4,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     4,     3,     0,     2,     1,     1,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     5,     5,     4,     3,     1,     3,     1,
       1,     0,     2,     4,     3,     2,     2,     0,     2,     2,
       1,     3,     2,     1,     3,     2,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     2,     2,     2,     5,     2,
       0,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       5,     5,     0,     2,     2,     2,     2,     6,     8,     2,
       2,     2,     2,     2,     2,     5,     1,     1,     1,     1,
       1,     0,     2,     2,     3,     0,     1,     2,     2,     2,
       3,     2,     1,     1,     3,     2,     4,     3,     2,     1,
       3,     2,     0,     1,     3,     2,     1,     3,     4,     3,
       2,     1,     3,     2,     0,     1,     1,     3,     2,     1,
       3,     4,     1,     3,     0,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     4,
       5,     5,    10,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 322 "parser.y" /* yacc.c:1648  */
    { fix_incomplete();
						  check_statements((yyvsp[0].stmt_list), FALSE);
						  check_all_user_types((yyvsp[0].stmt_list));
						  write_header((yyvsp[0].stmt_list));
						  write_id_data((yyvsp[0].stmt_list));
						  write_proxies((yyvsp[0].stmt_list));
						  write_client((yyvsp[0].stmt_list));
						  write_server((yyvsp[0].stmt_list));
						  write_regscript((yyvsp[0].stmt_list));
						  write_typelib_regscript((yyvsp[0].stmt_list));
						  write_dlldata((yyvsp[0].stmt_list));
						  write_local_stubs((yyvsp[0].stmt_list));
						}
#line 2617 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 3:
#line 337 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = NULL; }
#line 2623 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 4:
#line 338 "parser.y" /* yacc.c:1648  */
    { push_namespace((yyvsp[-1].str)); }
#line 2629 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 5:
#line 339 "parser.y" /* yacc.c:1648  */
    { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2635 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 6:
#line 340 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2641 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 7:
#line 341 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2647 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 8:
#line 342 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 2655 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 9:
#line 345 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 2663 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 10:
#line 348 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2669 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 11:
#line 349 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2675 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 12:
#line 350 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2681 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 13:
#line 353 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = NULL; }
#line 2687 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 14:
#line 354 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2693 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 15:
#line 355 "parser.y" /* yacc.c:1648  */
    { push_namespace((yyvsp[-1].str)); }
#line 2699 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 16:
#line 356 "parser.y" /* yacc.c:1648  */
    { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2705 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 17:
#line 357 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2711 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 18:
#line 358 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 2717 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 19:
#line 359 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 2725 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 20:
#line 362 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2731 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 21:
#line 363 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2737 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 22:
#line 364 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 2743 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 23:
#line 365 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2749 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 24:
#line 368 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = NULL; }
#line 2755 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 25:
#line 369 "parser.y" /* yacc.c:1648  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2761 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 28:
#line 377 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 2767 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 29:
#line 378 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 2773 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 30:
#line 379 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 2779 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 31:
#line 380 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 2785 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 32:
#line 381 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 2791 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 33:
#line 382 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 2797 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 34:
#line 383 "parser.y" /* yacc.c:1648  */
    { (yyval.statement) = NULL; }
#line 2803 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 35:
#line 387 "parser.y" /* yacc.c:1648  */
    {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 2815 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 36:
#line 397 "parser.y" /* yacc.c:1648  */
    { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 2821 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 37:
#line 398 "parser.y" /* yacc.c:1648  */
    { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 2827 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 39:
#line 403 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 2833 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 41:
#line 405 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 2839 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 43:
#line 407 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 2845 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 44:
#line 408 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 2851 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 45:
#line 409 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 2857 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 46:
#line 410 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 2863 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 47:
#line 413 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 2869 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 48:
#line 415 "parser.y" /* yacc.c:1648  */
    { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 2880 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 49:
#line 423 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 2889 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 50:
#line 430 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 2895 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 51:
#line 433 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2901 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 52:
#line 434 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2907 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 53:
#line 436 "parser.y" /* yacc.c:1648  */
    { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 2915 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 54:
#line 441 "parser.y" /* yacc.c:1648  */
    { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 2921 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 55:
#line 444 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 2927 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 57:
#line 448 "parser.y" /* yacc.c:1648  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 2933 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 58:
#line 449 "parser.y" /* yacc.c:1648  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 2939 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 60:
#line 453 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 2945 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 61:
#line 457 "parser.y" /* yacc.c:1648  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2955 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 62:
#line 462 "parser.y" /* yacc.c:1648  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2965 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 63:
#line 469 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 2974 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 64:
#line 473 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2980 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 65:
#line 474 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2986 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 66:
#line 477 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = NULL; }
#line 2992 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 68:
#line 482 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 2998 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 69:
#line 485 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3004 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 70:
#line 486 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3010 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 71:
#line 487 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3016 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 72:
#line 490 "parser.y" /* yacc.c:1648  */
    { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3022 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 73:
#line 491 "parser.y" /* yacc.c:1648  */
    { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3028 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 74:
#line 494 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = NULL; }
#line 3034 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 75:
#line 495 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3040 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 76:
#line 496 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3046 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 77:
#line 497 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3052 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 78:
#line 498 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3058 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 79:
#line 499 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3064 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 80:
#line 500 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3070 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 81:
#line 501 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3076 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 82:
#line 502 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3082 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 83:
#line 503 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3088 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 84:
#line 504 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3094 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 85:
#line 505 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3100 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 86:
#line 506 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3106 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 87:
#line 507 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3112 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 88:
#line 508 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3118 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 89:
#line 509 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3124 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 90:
#line 510 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3130 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 91:
#line 511 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3136 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 92:
#line 512 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3142 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 93:
#line 513 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3148 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 94:
#line 514 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3154 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 95:
#line 515 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3160 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 96:
#line 516 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3166 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 97:
#line 517 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3172 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 98:
#line 518 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3178 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 99:
#line 519 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3184 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 100:
#line 520 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3190 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 101:
#line 521 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3196 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 102:
#line 522 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3202 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 103:
#line 523 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3208 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 104:
#line 524 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3214 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 105:
#line 525 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3220 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 106:
#line 526 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3226 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 107:
#line 527 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3232 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 108:
#line 528 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3238 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 109:
#line 529 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3244 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 110:
#line 530 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3250 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 111:
#line 531 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3256 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 112:
#line 532 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3262 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 113:
#line 533 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3268 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 114:
#line 534 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3274 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 115:
#line 535 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3280 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 116:
#line 536 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3286 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 117:
#line 537 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3292 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 118:
#line 538 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3298 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 119:
#line 539 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3304 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 120:
#line 540 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_IN); }
#line 3310 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 121:
#line 541 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3316 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 122:
#line 542 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3322 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 123:
#line 543 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3328 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 124:
#line 544 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3334 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 125:
#line 545 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3340 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 126:
#line 546 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3346 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 127:
#line 547 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3352 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 128:
#line 548 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3358 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 129:
#line 549 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3364 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 130:
#line 550 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3370 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 131:
#line 551 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3376 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 132:
#line 552 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3382 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 133:
#line 553 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3388 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 134:
#line 554 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3394 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 135:
#line 555 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3400 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 136:
#line 556 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3406 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 137:
#line 557 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3412 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 138:
#line 558 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3418 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 139:
#line 559 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3424 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 140:
#line 560 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3430 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 141:
#line 561 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3436 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 142:
#line 562 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3442 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 143:
#line 563 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3448 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 144:
#line 564 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3454 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 145:
#line 565 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3460 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 146:
#line 566 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3466 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 147:
#line 567 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 3472 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 148:
#line 568 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 3478 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 149:
#line 570 "parser.y" /* yacc.c:1648  */
    { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 3486 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 150:
#line 573 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 3492 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 151:
#line 574 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 3498 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 152:
#line 575 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 3504 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 153:
#line 576 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 3510 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 154:
#line 577 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 3516 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 155:
#line 578 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 3522 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 156:
#line 579 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 3528 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 157:
#line 580 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 3534 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 158:
#line 581 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_STRING); }
#line 3540 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 159:
#line 582 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 3546 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 160:
#line 583 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 3552 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 161:
#line 584 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 3558 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 162:
#line 585 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 3564 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 163:
#line 586 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 3570 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 164:
#line 587 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 3576 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 165:
#line 588 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 3582 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 166:
#line 589 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 3588 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 167:
#line 590 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 3594 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 168:
#line 591 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 3600 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 169:
#line 592 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 3606 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 170:
#line 593 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 3612 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 171:
#line 594 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 3618 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 172:
#line 595 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 3624 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 173:
#line 596 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 3630 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 175:
#line 601 "parser.y" /* yacc.c:1648  */
    { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 3638 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 176:
#line 606 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = xstrdup("__cdecl"); }
#line 3644 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 177:
#line 607 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = xstrdup("__fastcall"); }
#line 3650 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 178:
#line 608 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = xstrdup("__pascal"); }
#line 3656 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 179:
#line 609 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = xstrdup("__stdcall"); }
#line 3662 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 180:
#line 612 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 3668 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 181:
#line 613 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 3674 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 182:
#line 616 "parser.y" /* yacc.c:1648  */
    { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3683 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 183:
#line 620 "parser.y" /* yacc.c:1648  */
    { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3692 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 184:
#line 626 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 3698 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 185:
#line 627 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 3704 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 187:
#line 631 "parser.y" /* yacc.c:1648  */
    { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 3713 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 188:
#line 635 "parser.y" /* yacc.c:1648  */
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
#line 3728 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 189:
#line 647 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3737 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 190:
#line 651 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3745 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 191:
#line 656 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 3751 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 192:
#line 659 "parser.y" /* yacc.c:1648  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 3757 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 193:
#line 660 "parser.y" /* yacc.c:1648  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 3763 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 194:
#line 663 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3769 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 196:
#line 667 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 3775 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 197:
#line 668 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 3781 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 198:
#line 669 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 3787 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 199:
#line 670 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 3793 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 200:
#line 671 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 3799 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 201:
#line 672 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 3805 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 202:
#line 673 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 3811 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 203:
#line 674 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 3817 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 204:
#line 675 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 3823 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 205:
#line 676 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 3829 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 206:
#line 677 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3835 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 207:
#line 678 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3841 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 208:
#line 679 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3847 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 209:
#line 680 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3853 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 210:
#line 681 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3859 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 211:
#line 682 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3865 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 212:
#line 683 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3871 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 213:
#line 684 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3877 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 214:
#line 685 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3883 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 215:
#line 686 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3889 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 216:
#line 687 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3895 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 217:
#line 688 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3901 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 218:
#line 689 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3907 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 219:
#line 690 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3913 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 220:
#line 691 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3919 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 221:
#line 692 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3925 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 222:
#line 693 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3931 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 223:
#line 694 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3937 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 224:
#line 695 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3943 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 225:
#line 696 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 3949 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 226:
#line 697 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 3955 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 227:
#line 698 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 3961 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 228:
#line 699 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 3967 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 229:
#line 700 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 3973 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 230:
#line 701 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 3979 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 231:
#line 702 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3985 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 232:
#line 703 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3991 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 233:
#line 705 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 3997 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 234:
#line 707 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4003 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 235:
#line 708 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4009 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 236:
#line 709 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 4015 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 237:
#line 712 "parser.y" /* yacc.c:1648  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4021 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 238:
#line 713 "parser.y" /* yacc.c:1648  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4027 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 239:
#line 716 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4036 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 240:
#line 722 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4045 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 241:
#line 728 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 4051 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 242:
#line 729 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4057 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 243:
#line 733 "parser.y" /* yacc.c:1648  */
    { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4066 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 244:
#line 737 "parser.y" /* yacc.c:1648  */
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4075 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 245:
#line 744 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4081 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 246:
#line 745 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4087 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 247:
#line 748 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 4093 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 248:
#line 749 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4099 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 249:
#line 753 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4105 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 250:
#line 754 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = NULL; }
#line 4111 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 251:
#line 757 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4120 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 252:
#line 761 "parser.y" /* yacc.c:1648  */
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4129 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 253:
#line 767 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4139 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 254:
#line 776 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4147 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 255:
#line 779 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4155 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 256:
#line 784 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = NULL; }
#line 4161 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 258:
#line 788 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = NULL; }
#line 4167 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 259:
#line 789 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4173 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 260:
#line 790 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4179 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 261:
#line 793 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4185 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 262:
#line 795 "parser.y" /* yacc.c:1648  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4191 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 263:
#line 798 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4197 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 264:
#line 799 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4203 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 266:
#line 801 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4209 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 267:
#line 802 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4215 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 268:
#line 803 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4221 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 269:
#line 804 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4227 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 270:
#line 805 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4233 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 271:
#line 806 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4239 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 272:
#line 807 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4245 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 273:
#line 808 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4251 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 276:
#line 815 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4257 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 277:
#line 816 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4263 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 278:
#line 817 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4269 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 279:
#line 818 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4275 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 280:
#line 819 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4281 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 281:
#line 820 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4287 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 282:
#line 821 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4293 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 283:
#line 822 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4299 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 284:
#line 823 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4305 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 285:
#line 826 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4311 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 286:
#line 827 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4322 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 287:
#line 835 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4331 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 288:
#line 842 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4337 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 289:
#line 845 "parser.y" /* yacc.c:1648  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4343 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 290:
#line 848 "parser.y" /* yacc.c:1648  */
    { (yyval.ifref_list) = NULL; }
#line 4349 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 291:
#line 849 "parser.y" /* yacc.c:1648  */
    { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4355 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 292:
#line 853 "parser.y" /* yacc.c:1648  */
    { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4361 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 293:
#line 856 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4367 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 294:
#line 857 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4373 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 295:
#line 860 "parser.y" /* yacc.c:1648  */
    { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4385 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 296:
#line 869 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 4391 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 297:
#line 870 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4397 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 298:
#line 873 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = NULL; }
#line 4403 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 299:
#line 874 "parser.y" /* yacc.c:1648  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4409 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 300:
#line 880 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4417 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 301:
#line 884 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4425 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 302:
#line 889 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = NULL; }
#line 4431 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 303:
#line 890 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error2((yyvsp[0].str), 0); }
#line 4437 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 304:
#line 893 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4443 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 305:
#line 894 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4449 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 306:
#line 897 "parser.y" /* yacc.c:1648  */
    { (yyval.ifinfo).interface = (yyvsp[0].type);
						  (yyval.ifinfo).old_pointer_default = pointer_default;
						  if (is_attr((yyvsp[-1].attr_list), ATTR_POINTERDEFAULT))
						    pointer_default = get_attrv((yyvsp[-1].attr_list), ATTR_POINTERDEFAULT);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 4462 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 307:
#line 908 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-5].ifinfo).interface;
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  pointer_default = (yyvsp[-5].ifinfo).old_pointer_default;
						}
#line 4473 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 308:
#line 918 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-7].ifinfo).interface;
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						  pointer_default = (yyvsp[-7].ifinfo).old_pointer_default;
						}
#line 4482 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 309:
#line 922 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4488 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 310:
#line 926 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4494 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 311:
#line 927 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4500 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 312:
#line 930 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4506 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 313:
#line 931 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4512 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 314:
#line 934 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4520 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 315:
#line 940 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 4528 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 316:
#line 946 "parser.y" /* yacc.c:1648  */
    { (yyval.stgclass) = STG_EXTERN; }
#line 4534 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 317:
#line 947 "parser.y" /* yacc.c:1648  */
    { (yyval.stgclass) = STG_STATIC; }
#line 4540 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 318:
#line 948 "parser.y" /* yacc.c:1648  */
    { (yyval.stgclass) = STG_REGISTER; }
#line 4546 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 319:
#line 952 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_INLINE); }
#line 4552 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 320:
#line 956 "parser.y" /* yacc.c:1648  */
    { (yyval.attr) = make_attr(ATTR_CONST); }
#line 4558 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 321:
#line 959 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = NULL; }
#line 4564 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 322:
#line 960 "parser.y" /* yacc.c:1648  */
    { (yyval.attr_list) = append_attr((yyvsp[-1].attr_list), (yyvsp[0].attr)); }
#line 4570 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 323:
#line 963 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, NULL, STG_NONE); }
#line 4576 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 324:
#line 965 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), NULL, STG_NONE); }
#line 4582 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 325:
#line 968 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = NULL; }
#line 4588 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 327:
#line 973 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].attr), STG_NONE); }
#line 4594 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 328:
#line 974 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].attr), STG_NONE); }
#line 4600 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 329:
#line 975 "parser.y" /* yacc.c:1648  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, NULL, (yyvsp[-1].stgclass)); }
#line 4606 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 330:
#line 980 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_chain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4612 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 331:
#line 981 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4619 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 333:
#line 987 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4625 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 334:
#line 988 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4631 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 335:
#line 989 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->type = append_array((yyval.declarator)->type, (yyvsp[0].expr)); }
#line 4637 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 336:
#line 990 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_chain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4646 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 337:
#line 999 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_chain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4652 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 338:
#line 1000 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4659 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 340:
#line 1008 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_chain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4665 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 341:
#line 1009 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4672 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 342:
#line 1014 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4678 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 344:
#line 1020 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4684 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 345:
#line 1021 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->type = append_array((yyval.declarator)->type, (yyvsp[0].expr)); }
#line 4690 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 346:
#line 1022 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->type = append_array((yyval.declarator)->type, (yyvsp[0].expr)); }
#line 4696 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 347:
#line 1024 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_chain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4705 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 348:
#line 1029 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_chain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4714 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 349:
#line 1038 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_chain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4720 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 350:
#line 1039 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4726 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 352:
#line 1046 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_chain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4732 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 353:
#line 1047 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4738 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 354:
#line 1051 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4744 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 356:
#line 1059 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4750 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 357:
#line 1060 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4756 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 358:
#line 1061 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->type = append_array((yyval.declarator)->type, (yyvsp[0].expr)); }
#line 4762 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 359:
#line 1062 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->type = append_array((yyval.declarator)->type, (yyvsp[0].expr)); }
#line 4768 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 360:
#line 1064 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_chain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4777 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 361:
#line 1069 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_chain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4786 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 362:
#line 1076 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4792 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 363:
#line 1077 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4798 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 364:
#line 1080 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = NULL; }
#line 4804 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 365:
#line 1081 "parser.y" /* yacc.c:1648  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 4810 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 366:
#line 1084 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 4819 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 367:
#line 1091 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4825 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 368:
#line 1093 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4831 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 369:
#line 1097 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[0].declarator); }
#line 4837 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 370:
#line 1098 "parser.y" /* yacc.c:1648  */
    { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 4843 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 371:
#line 1102 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = THREADING_APARTMENT; }
#line 4849 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 372:
#line 1103 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = THREADING_NEUTRAL; }
#line 4855 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 373:
#line 1104 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = THREADING_SINGLE; }
#line 4861 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 374:
#line 1105 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = THREADING_FREE; }
#line 4867 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 375:
#line 1106 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = THREADING_BOTH; }
#line 4873 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 376:
#line 1110 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = FC_RP; }
#line 4879 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 377:
#line 1111 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = FC_UP; }
#line 4885 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 378:
#line 1112 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = FC_FP; }
#line 4891 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 379:
#line 1115 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4897 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 380:
#line 1118 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_void(); }
#line 4903 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 381:
#line 1119 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4909 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 382:
#line 1120 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4915 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 383:
#line 1121 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4921 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 384:
#line 1122 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 4927 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 385:
#line 1123 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4933 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 386:
#line 1124 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 4939 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 387:
#line 1125 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4945 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 388:
#line 1126 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 4951 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 389:
#line 1127 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 4957 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 390:
#line 1131 "parser.y" /* yacc.c:1648  */
    { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list));
						}
#line 4966 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 391:
#line 1138 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 4972 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 392:
#line 1141 "parser.y" /* yacc.c:1648  */
    { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 4978 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 393:
#line 1145 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 4984 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 394:
#line 1146 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 4990 "parser.tab.c" /* yacc.c:1648  */
    break;

  case 395:
#line 1147 "parser.y" /* yacc.c:1648  */
    { (yyval.num) = (yyvsp[0].num); }
#line 4996 "parser.tab.c" /* yacc.c:1648  */
    break;


#line 5000 "parser.tab.c" /* yacc.c:1648  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 1150 "parser.y" /* yacc.c:1907  */


static void decl_builtin_basic(const char *name, enum type_basic_type type)
{
  type_t *t = type_new_basic(type);
  reg_type(t, name, NULL, 0);
}

static void decl_builtin_alias(const char *name, type_t *t)
{
  reg_type(type_new_alias(t, name), name, NULL, 0);
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

static type_t *append_array(type_t *chain, expr_t *expr)
{
    type_t *array;

    if (!expr)
        return chain;

    /* An array is always a reference pointer unless explicitly marked otherwise
     * (regardless of what the default pointer attribute is). */
    array = type_new_array(NULL, NULL, FALSE, expr->is_const ? expr->cval : 0,
            expr->is_const ? NULL : expr, NULL, FC_RP);

    return append_chain_type(chain, array);
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

static type_t *get_array_or_ptr_ref(type_t *type)
{
    if (is_ptr(type))
        return type_pointer_get_ref(type);
    else if (is_array(type))
        return type_array_get_element(type);
    return NULL;
}

static type_t *append_chain_type(type_t *chain, type_t *type)
{
    type_t *chain_type;

    if (!chain)
        return type;
    for (chain_type = chain; get_array_or_ptr_ref(chain_type); chain_type = get_array_or_ptr_ref(chain_type))
        ;

    if (is_ptr(chain_type))
        chain_type->details.pointer.ref = type;
    else if (is_array(chain_type))
        chain_type->details.array.elem = type;
    else
        assert(0);

    return chain;
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

static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, const declarator_t *decl,
                       int top)
{
  var_t *v = decl->var;
  expr_list_t *sizes = get_attrp(attrs, ATTR_SIZEIS);
  expr_list_t *lengs = get_attrp(attrs, ATTR_LENGTHIS);
  expr_t *dim;
  type_t **ptype;
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
  v->type = append_chain_type(decl ? decl->type : NULL, type);
  v->stgclass = decl_spec->stgclass;
  v->attrs = attrs;

  /* check for pointer attribute being applied to non-pointer, non-array
   * type */
  if (!is_array(v->type))
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
      if (ptr_attr && ptr_attr != FC_UP &&
          type_get_type(type_pointer_get_ref(ptr)) == TYPE_INTERFACE)
          warning_loc_info(&v->loc_info,
                           "%s: pointer attribute applied to interface "
                           "pointer type has no effect\n", v->name);
      if (!ptr_attr && top && (*pt)->details.pointer.def_fc != FC_RP)
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

    if (!is_ptr(v->type) && !is_array(v->type))
      error_loc("'%s': [string] attribute applied to non-pointer, non-array type\n",
                v->name);

    for (;;)
    {
        if (is_ptr(t))
            t = type_pointer_get_ref(t);
        else if (is_array(t))
            t = type_array_get_element(t);
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
    if (type_get_type_detect_alias(v->type) != TYPE_ENUM)
      error_loc("'%s': [v1_enum] attribute applied to non-enum type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_RANGE) && !is_allowed_range_type(v->type))
    error_loc("'%s': [range] attribute applied to non-integer type\n",
              v->name);

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
  d->bits = NULL;
  return d;
}

static type_t *make_safearray(type_t *type)
{
  return type_new_array(NULL, type_new_alias(type, "SAFEARRAY"), TRUE, 0,
                        NULL, NULL, FC_RP);
}

static typelib_t *make_library(const char *name, const attr_list_t *attrs)
{
    typelib_t *typelib = xmalloc(sizeof(*typelib));
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
      type->name = gen_name();

    /* replace existing attributes when generating a typelib */
    if (do_typelib)
        type->attrs = attrs;
  }

  LIST_FOR_EACH_ENTRY( decl, decls, const declarator_t, entry )
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
      cur = type_new_alias(name->type, name->name);
      cur->attrs = attrs;

      if (is_incomplete(cur))
        add_incomplete(cur);
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
