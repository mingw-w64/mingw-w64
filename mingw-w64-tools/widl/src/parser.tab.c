/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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
static statement_t *make_statement_pragma(const char *str);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names);
static statement_t *make_statement_import(const char *str);
static statement_t *make_statement_typedef(var_list_t *names);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);


#line 203 "parser.tab.c" /* yacc.c:339  */

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
    tINT3264 = 352,
    tINT64 = 353,
    tINTERFACE = 354,
    tLCID = 355,
    tLENGTHIS = 356,
    tLIBRARY = 357,
    tLICENSED = 358,
    tLOCAL = 359,
    tLONG = 360,
    tMAYBE = 361,
    tMESSAGE = 362,
    tMETHODS = 363,
    tMODULE = 364,
    tNAMESPACE = 365,
    tNOCODE = 366,
    tNONBROWSABLE = 367,
    tNONCREATABLE = 368,
    tNONEXTENSIBLE = 369,
    tNOTIFY = 370,
    tNOTIFYFLAG = 371,
    tNULL = 372,
    tOBJECT = 373,
    tODL = 374,
    tOLEAUTOMATION = 375,
    tOPTIMIZE = 376,
    tOPTIONAL = 377,
    tOUT = 378,
    tPARTIALIGNORE = 379,
    tPASCAL = 380,
    tPOINTERDEFAULT = 381,
    tPROGID = 382,
    tPROPERTIES = 383,
    tPROPGET = 384,
    tPROPPUT = 385,
    tPROPPUTREF = 386,
    tPROXY = 387,
    tPTR = 388,
    tPUBLIC = 389,
    tRANGE = 390,
    tREADONLY = 391,
    tREF = 392,
    tREGISTER = 393,
    tREPRESENTAS = 394,
    tREQUESTEDIT = 395,
    tRESTRICTED = 396,
    tRETVAL = 397,
    tSAFEARRAY = 398,
    tSHORT = 399,
    tSIGNED = 400,
    tSIZEIS = 401,
    tSIZEOF = 402,
    tSMALL = 403,
    tSOURCE = 404,
    tSTATIC = 405,
    tSTDCALL = 406,
    tSTRICTCONTEXTHANDLE = 407,
    tSTRING = 408,
    tSTRUCT = 409,
    tSWITCH = 410,
    tSWITCHIS = 411,
    tSWITCHTYPE = 412,
    tTHREADING = 413,
    tTRANSMITAS = 414,
    tTRUE = 415,
    tTYPEDEF = 416,
    tUIDEFAULT = 417,
    tUNION = 418,
    tUNIQUE = 419,
    tUNSIGNED = 420,
    tUSESGETLASTERROR = 421,
    tUSERMARSHAL = 422,
    tUUID = 423,
    tV1ENUM = 424,
    tVARARG = 425,
    tVERSION = 426,
    tVIPROGID = 427,
    tVOID = 428,
    tWCHAR = 429,
    tWIREMARSHAL = 430,
    tAPARTMENT = 431,
    tNEUTRAL = 432,
    tSINGLE = 433,
    tFREE = 434,
    tBOTH = 435,
    CAST = 436,
    PPTR = 437,
    POS = 438,
    NEG = 439,
    ADDRESSOF = 440
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 129 "parser.y" /* yacc.c:355  */

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

#line 453 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);



/* Copy the second part of user declarations.  */

#line 470 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   3077

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  210
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  387
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  679

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   440

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   194,     2,     2,     2,   193,   186,     2,
     207,   208,   191,   190,   181,   189,   201,   192,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   183,   206,
     187,   209,   188,   182,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   202,     2,   203,   185,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   204,   184,   205,   195,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   196,   197,   198,   199,
     200
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   308,   308,   322,   323,   325,   326,   327,   330,   333,
     334,   335,   338,   339,   340,   342,   343,   344,   347,   348,
     349,   350,   353,   354,   357,   358,   362,   363,   364,   365,
     366,   367,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   382,   384,   392,   398,   402,   404,   408,   415,   416,
     419,   420,   423,   424,   428,   433,   440,   444,   445,   448,
     449,   453,   456,   457,   458,   461,   462,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   571,   572,   577,
     578,   579,   580,   583,   584,   587,   591,   597,   598,   599,
     602,   606,   618,   622,   627,   630,   631,   634,   635,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   677,   679,   680,
     683,   684,   687,   693,   699,   700,   703,   708,   715,   716,
     719,   720,   724,   725,   728,   732,   738,   746,   750,   755,
     756,   759,   760,   761,   764,   766,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   782,   783,   786,
     787,   788,   789,   790,   791,   792,   793,   796,   797,   805,
     811,   815,   818,   819,   823,   826,   827,   830,   839,   840,
     843,   844,   847,   853,   859,   860,   863,   864,   867,   877,
     886,   892,   896,   897,   900,   901,   904,   909,   916,   917,
     918,   922,   926,   929,   930,   933,   934,   938,   939,   943,
     944,   945,   949,   951,   953,   957,   958,   959,   960,   968,
     970,   972,   977,   979,   984,   985,   990,   991,   992,   993,
     998,  1007,  1009,  1010,  1015,  1017,  1021,  1022,  1029,  1030,
    1031,  1032,  1033,  1038,  1046,  1047,  1050,  1051,  1054,  1061,
    1062,  1067,  1068,  1072,  1073,  1074,  1075,  1076,  1080,  1081,
    1082,  1085,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1100,  1107,  1109,  1115,  1116,  1117
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
  "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'", "'['", "']'",
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
     435,    44,    63,    58,   124,    94,    38,    60,    62,    45,
      43,    42,    47,    37,    33,   126,   436,   437,   438,   439,
     440,    46,    91,    93,   123,   125,    59,    40,    41,    61
};
# endif

#define YYPACT_NINF -526

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-526)))

#define YYTABLE_NINF -253

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -526,    59,  1737,  -526,  -526,  -526,  -526,  -526,  -526,   163,
    -526,  -138,   169,  -526,   194,  -526,  -526,  -526,  -526,    12,
      73,  -526,  -526,  -526,  -526,   219,    12,   120,  -526,   -64,
      12,   300,  -526,  -526,   266,   270,   300,  -526,  -526,  2902,
    -526,   -48,  -526,  -526,  -526,  -526,  -526,    46,  2579,   -44,
     -23,  -526,  -526,    39,    19,  -526,    48,    47,    54,    62,
      76,   -33,  -526,  -526,    82,  -526,    96,    96,    96,    57,
    2751,    86,    96,    87,    90,  -526,  -526,   223,  -526,  -526,
      72,  -526,    95,  -526,  -526,   103,  -526,  -526,  -526,  -526,
    2751,  -526,  -526,    99,   112,  -112,  -109,  -526,  -526,    21,
    -526,  -526,    56,  -526,  -526,  -526,    93,   156,  -526,  -526,
    -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,   157,  -526,
    -526,  -526,   162,  -526,  -526,  -526,   164,   168,  -526,  -526,
    -526,  -526,   170,   171,   173,   174,   175,  -526,   177,  -526,
    -526,   178,  -526,   179,  -526,  -526,   184,   186,  -526,  -526,
    -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,
    -526,   187,  -526,  -526,  -526,   193,   196,  -526,  -526,  -526,
    -526,  -526,  -526,   197,  -526,  -526,   200,  -526,  -526,  -526,
     201,  -526,  -526,  -526,   202,   203,   215,   216,  -526,  -526,
    -526,   220,   225,  -526,  -526,   228,   231,   234,   -56,  -526,
    -526,  -526,  1620,   877,   136,   301,   373,   329,   347,   356,
     226,   195,  -526,  -526,  -526,  -526,    57,   237,   239,  -526,
    -526,  -526,  -526,  -526,   -22,  -526,  -526,  -526,   357,   242,
    -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,
    -526,  -526,    57,    57,  -526,   238,  -141,  -526,  -526,  -526,
      96,  -526,  -526,  -526,   241,   365,  -526,   243,  -526,   247,
    -526,   453,   161,   365,   713,   713,   454,   455,   713,   713,
     456,   457,   713,   458,   713,   713,  2168,   713,   713,   459,
     -54,   461,   713,  2751,   713,   713,  2751,   135,  2751,  2751,
     161,   130,   462,  2751,  2902,   271,  -526,   265,  -526,  -526,
    -526,   273,  -526,   276,  -526,  -526,  -526,    62,  2665,  -526,
     277,  -526,  -526,  -526,   277,  -105,  -526,  -526,   -18,  1111,
     294,   -76,   280,   278,  -526,  -526,  1213,    42,   279,  -526,
     713,    94,  2168,  -526,  -526,  -526,   284,   309,  -526,   282,
    -526,   -13,   136,   -11,   288,  -526,  -526,   289,   291,  -526,
    -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,   285,  -526,
     713,   713,   713,   713,   713,   713,   703,  2390,   -91,  -526,
    2390,   292,   296,  -526,   -70,   298,   302,   303,   304,   305,
     306,   307,   398,   308,  2665,    88,   310,   -66,  -526,  2390,
     311,   313,   314,   321,   315,   -63,  2174,   316,  -526,  -526,
    -526,  -526,  -526,   317,   318,   319,   322,   328,  -526,   323,
     324,   326,  -526,  2902,   499,  -526,  -526,  -526,    57,    62,
     -21,  -526,  -526,  -526,   352,  2665,   331,  1503,   334,   419,
    1315,    62,  -526,  2665,  -526,  -526,  -526,  -526,   450,  -526,
    1425,   336,   366,  -526,  -526,  -526,   365,   713,  -526,  2665,
    -526,   338,  -526,   342,  -526,   343,  -526,  -526,  -526,  2665,
      18,    18,    18,    18,    18,    18,  2260,   248,   713,   713,
     547,   713,   713,   713,   713,   713,   713,   713,   713,   713,
     713,   713,   713,   713,   713,   713,   713,   713,   548,   713,
     713,  -526,  -526,  -526,   543,  -526,  -526,  -526,  -526,  -526,
    -526,  -526,  -526,  -526,  -526,    88,  -526,  1823,  -526,    88,
    -526,  -526,  -526,  -137,  -526,   713,  -526,  -526,  -526,  -526,
     713,  -526,  -526,  -526,  -526,  -526,  -526,  -526,  -526,   549,
    -526,  -526,  -526,  -526,   346,   994,  -526,   375,  -526,  -526,
    -526,    57,   166,  -526,  -526,  2665,   351,  -526,  -526,  -526,
      62,  -526,  -526,  -526,  -526,  2082,  -526,  -526,    88,   354,
     365,  -526,  -526,   248,  -526,  -526,  1950,  -526,   248,  -526,
     350,  -135,    25,    25,  -526,   603,   603,   165,   165,   817,
    2285,  2369,  2408,  2440,   740,   165,   165,    64,    64,    18,
      18,    18,  -526,  2329,  -526,  -526,  -526,    70,  -526,   353,
      88,   355,  -526,  2168,  -526,  -526,   358,  -526,    62,  -526,
      57,  -526,  -526,  1417,  -526,  -526,  -526,   379,  -526,   -94,
    -526,   364,  -526,   361,   100,  -526,   369,    88,   370,  -526,
     713,  2168,  -526,   713,  -526,  -526,    70,  -526,  -526,  -526,
     371,  -526,  -526,  -526,    62,   713,  -526,    88,  -526,  -526,
    -526,  -526,    70,  -526,  -526,  -526,    18,   384,  2390,  -526,
    -526,  -526,  -526,  -526,    -3,  -526,  -526,   713,   411,  -526,
    -526,   412,   -86,   -86,  -526,  -526,   390,  -526,  -526
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     2,     1,    31,   373,   264,   256,   275,     0,
     312,     0,     0,   263,   251,   265,   308,   262,   266,   267,
       0,   311,   269,   276,   274,     0,   267,     0,   310,     0,
     267,     0,   271,   309,   251,   251,   261,   372,   257,    67,
      11,     0,    26,    12,    29,    12,    10,     0,    60,   375,
       0,   374,   258,     0,     0,     8,     0,     0,     0,    24,
       0,   294,     6,     5,     0,     9,   317,   317,   317,     0,
       0,   377,   317,     0,   379,   277,   278,     0,   285,   286,
     376,   253,     0,   268,   273,     0,   296,   297,   272,   281,
       0,   270,   259,   378,     0,   380,     0,   260,    68,     0,
      70,    71,     0,    72,    73,    74,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,    88,
      89,    90,     0,    92,    93,    94,     0,     0,    97,    98,
      99,   100,     0,     0,     0,     0,     0,   106,     0,   108,
     109,     0,   111,     0,   113,   114,   117,     0,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   132,   133,   134,     0,     0,   137,   138,   139,
     140,   370,   141,     0,   143,   368,     0,   145,   146,   147,
       0,   149,   150,   151,     0,     0,     0,     0,   156,   369,
     157,     0,     0,   161,   162,     0,     0,     0,     0,    62,
     166,    27,    59,    59,    59,   251,     0,     0,   251,   251,
       0,   375,   279,   287,   298,   306,     0,   377,   379,    28,
       7,   282,     3,   303,     0,    25,   301,   302,     0,     0,
      22,   321,   318,   320,   319,   254,   255,   169,   170,   171,
     172,   313,     0,     0,   325,   361,   324,   248,   375,   377,
     317,   379,   315,    30,     0,   177,    42,     0,   234,     0,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    61,    43,     0,    19,    20,
      21,     0,    17,     0,    15,    13,    18,    24,     0,    60,
     376,    45,   304,   305,   378,   380,    46,   247,    59,    59,
       0,    59,     0,     0,   295,    22,    59,     0,     0,   323,
       0,     0,    48,   327,   316,    41,     0,   179,   180,   183,
     381,    59,    59,    59,     0,   168,   167,     0,     0,   198,
     189,   190,   191,   195,   196,   197,   192,   193,     0,   194,
       0,     0,     0,     0,     0,     0,     0,   232,     0,   230,
     233,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   346,     0,     0,   185,   188,
       0,     0,     0,     0,     0,     0,     0,     0,   363,   364,
     365,   366,   367,     0,     0,     0,     0,   385,   387,     0,
       0,     0,    63,    67,     0,    16,    12,    47,     0,    24,
       0,   283,     4,   288,     0,     0,     0,     0,     0,     0,
      59,    24,    23,    60,   314,   322,   326,   362,     0,    58,
       0,     0,    52,    49,    50,   184,   178,     0,   371,     0,
     235,     0,   383,    60,   241,     0,    69,   160,    75,     0,
     222,   221,   220,   223,   218,   219,     0,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    87,    91,     0,    95,    96,   101,   102,   103,
     104,   105,   107,   110,   112,   346,   313,    48,   351,   346,
     348,   347,    55,   343,   116,   187,   115,   131,   135,   136,
       0,   144,   148,   152,   153,   155,   154,   158,   159,     0,
     163,   164,   165,    64,     0,    59,   354,   382,   280,   284,
     290,     0,   377,   289,   292,     0,     0,   246,   293,    22,
      24,   307,    57,    56,   328,     0,   181,   182,     0,   379,
     249,   239,   238,   334,   229,   313,    48,   338,   334,   335,
       0,   331,   211,   212,   224,   205,   206,   209,   210,   200,
     201,     0,   202,   203,   204,   208,   207,   214,   213,   216,
     217,   215,   225,     0,   231,    66,    54,   346,   313,     0,
     346,     0,   342,    48,   350,   186,     0,   386,    24,    14,
       0,   244,   291,    59,   299,    53,    51,   356,   359,     0,
     237,     0,   250,     0,   334,   313,     0,   346,     0,   330,
       0,    48,   337,     0,   228,   341,   346,   352,   345,   349,
       0,   142,    44,   355,    24,     0,   358,     0,   236,   173,
     227,   329,   346,   339,   333,   336,   226,     0,   199,   344,
     353,   300,   357,   360,     0,   332,   340,     0,     0,   384,
     174,     0,    59,    59,   243,   176,     0,   175,   242
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -526,  -526,   359,   -28,  -305,  -300,    -1,  -526,  -526,  -526,
     176,  -526,  -526,  -526,    23,  -468,  -526,  -526,  -257,  -232,
    -189,    -2,  -526,  -526,  -267,   312,   -65,  -526,  -526,  -526,
    -526,   152,     7,   320,    92,   210,  -526,  -261,  -256,  -526,
    -526,  -526,  -526,   -60,  -187,  -526,   181,  -526,    22,   -67,
    -526,   131,    40,    16,  -526,    24,    26,  -526,  -526,   555,
    -526,  -526,  -526,  -526,  -526,   -12,  -526,    28,     4,  -526,
    -526,    29,  -526,  -526,  -287,  -477,   -38,    17,   -14,  -220,
    -526,  -526,  -526,  -500,  -526,  -525,  -526,  -467,  -526,  -526,
    -526,   -32,  -526,   393,  -526,   341,     1,   -46,  -526,     3,
    -526
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   202,   326,   226,   298,    41,    42,    43,
      44,   299,   210,    45,   300,   441,   442,   443,   444,   508,
      47,   309,   198,   374,   199,   347,   509,   664,   670,   336,
     337,   338,   248,   387,   388,   367,   368,   369,   371,   341,
     450,   454,   343,   675,   676,   546,    50,   621,    82,   510,
      51,    84,    52,   301,    54,   302,   303,   318,   421,    57,
      58,   321,   427,    59,   229,    60,    61,   304,   305,   215,
      64,   306,    66,    67,    68,   327,    69,   231,    70,   245,
     246,   569,   628,   570,   571,   511,   601,   512,   513,   537,
     646,   618,   619,   247,   403,   200,   249,    72,    73,   251,
     409
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    40,   244,    71,   243,    74,    63,   417,   376,    49,
     216,   379,   375,   381,   333,   308,   386,   203,    53,   383,
     430,   393,   328,   329,   250,    46,    55,   412,    56,   597,
      62,    65,   424,   617,   470,   667,   214,    12,   596,   599,
     434,   470,   602,  -252,   257,   235,   259,   236,   668,   217,
    -252,   218,   232,   232,   232,   211,    94,    96,   232,     3,
     235,   331,   236,   623,   212,   331,   332,   331,   629,    77,
     603,    92,   631,   235,   437,   236,    97,    25,    25,   171,
     470,   237,    85,   175,   233,   234,    10,   647,   624,   252,
     490,   235,  -252,   236,   -37,   260,   237,   349,   626,  -252,
     350,   351,   352,   353,   354,   355,   320,   435,    83,   237,
     189,   494,   648,   238,    10,   515,    39,   491,   515,   538,
     674,   636,   617,    89,   651,   294,    39,   237,   238,   420,
     635,   551,   425,   638,   426,   640,   407,   408,   495,   237,
      10,   238,   516,    90,    10,   522,   533,   295,   652,   244,
     228,   243,   449,   425,   425,   451,   455,    88,   201,   238,
     654,    91,   -32,   657,   356,    16,    75,   239,    76,   659,
     345,   238,    78,   346,    79,   244,   244,   243,   243,   468,
     469,   470,   239,   219,    39,   665,   557,   419,   339,    39,
      21,    39,   448,   240,   452,   239,   348,    80,   536,    81,
      48,    48,   669,    71,    71,    74,    74,   204,   240,    49,
      49,   357,   322,   239,   483,   484,   485,   486,   487,   488,
     489,   240,    86,   221,    87,   239,   488,   489,   261,   594,
      94,    96,   254,   241,    28,   567,   232,   394,   385,   240,
     397,   358,   404,   405,   613,   220,    33,   411,   241,   242,
     614,   240,   222,   223,   359,   485,   486,   487,   224,   606,
     244,   506,   243,   262,   242,   488,   489,   334,   225,    93,
     418,    81,   331,    95,   384,    81,  -252,   507,   -33,   506,
     360,   604,   227,   361,   362,   438,   230,   237,   364,   365,
     331,   565,   -34,   253,   385,   507,   -36,   439,   616,   255,
     263,   366,   331,  -252,   310,   -35,    81,   566,   642,   256,
     434,   398,   399,   400,   401,   402,   258,    48,    40,   238,
      71,   611,    74,    63,   433,   432,    49,    71,   467,    74,
     384,   567,   312,    49,   313,    53,   567,   434,    39,   632,
       8,   453,    46,    55,   661,    56,   505,    62,    65,   434,
     314,   244,    81,   243,   483,   484,   485,   486,   487,   315,
     323,    81,   324,   264,   265,   434,   488,   489,   235,   266,
     236,   267,  -245,   239,  -245,   268,   311,   269,   270,   339,
     271,   272,   273,    19,   274,   275,   276,   541,   535,   662,
     643,   277,   567,   278,   279,   216,    22,    23,    24,   240,
     280,   -38,   568,   281,   282,    26,   671,   283,   284,   285,
     286,   558,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   563,   287,   288,   539,   545,   542,   289,   433,   432,
     316,    71,   290,    74,   217,   291,   218,    49,   292,   565,
     211,   293,   600,   -39,    30,   -40,   325,   330,    32,   335,
     331,   340,   559,   349,   342,   566,   350,   351,   352,   353,
     354,   355,   344,   372,   373,   377,   378,   380,   390,   385,
     392,   410,   414,   413,   244,   370,   243,   423,   370,   415,
     416,  -252,   429,   425,   425,   382,   428,   436,   389,   445,
     446,   447,   459,   622,   389,   396,   456,   457,   568,   458,
     492,   627,   520,   568,   493,   384,   496,   216,   534,    20,
     497,   498,   499,   500,   501,   502,   504,   385,   514,   517,
     356,   518,   519,   521,   524,   525,   526,   527,   385,   529,
     528,   530,   531,    48,   532,   540,    71,   543,    74,   548,
     370,   440,    49,   244,   554,   243,   560,   555,   561,   562,
     574,   592,   595,   384,   608,   607,   610,   612,   630,   568,
     620,   637,   645,   639,   384,   385,   641,   357,   649,   650,
     460,   461,   462,   463,   464,   465,   466,   653,   655,   660,
     477,   319,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   666,   385,   672,   673,   678,   358,   556,   488,
     489,   384,   406,   213,   395,   549,   503,   605,   547,   317,
     359,   433,   432,   677,    71,   663,    74,   468,   469,   470,
      49,   391,   473,   474,     0,     0,     0,     0,     0,   384,
       0,     0,     0,     0,     0,     0,   360,     0,     0,   361,
     362,   363,     0,     0,   364,   365,     0,     0,   463,     0,
       0,     0,     0,   552,     0,     0,     0,   366,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
       0,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,     0,   593,
       0,     0,     0,     0,     0,     0,   349,     0,     5,   350,
     351,   352,   353,   354,   355,     0,   349,     0,     0,   350,
     351,   352,   353,   354,   355,   389,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     7,     0,     0,
       0,     0,     0,     8,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,   468,   469,   470,   471,   472,   473,
     474,     0,     0,    13,     0,     0,     0,     0,     0,   205,
      15,     0,    16,   356,     0,     0,    17,     0,     0,    18,
       0,     0,     0,   356,     0,     0,    19,     0,     0,     0,
     481,   482,   483,   484,   485,   486,   487,    21,     0,    22,
      23,    24,     0,     0,   488,   489,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   468,   469,   470,   471,   472,   473,   474,     0,   476,
     656,    28,     0,   658,     0,     0,    29,    30,    31,     0,
     358,    32,     0,    33,     0,   370,     0,   208,     0,     0,
     358,     0,     0,   359,     0,     0,   209,     0,    36,     0,
       0,     0,     0,   359,     0,     0,    37,    38,     0,     0,
       0,     4,     5,     0,     0,     0,     0,     0,     0,   360,
       0,     0,   361,   362,   363,     0,     0,   364,   365,   360,
       0,     0,   361,   362,   363,     0,     0,   364,   365,     6,
     366,     7,     0,     0,     0,     0,     0,     8,     9,     0,
     366,    10,     0,     0,     0,     0,    11,   481,   482,   483,
     484,   485,   486,   487,     0,    12,     0,    13,     0,     0,
       0,   488,   489,    14,    15,     0,    16,     0,     0,     0,
      17,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    20,   297,     0,
       0,    21,     0,    22,    23,    24,    25,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       0,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,     0,     0,     0,     0,    28,     0,     0,   488,   489,
      29,    30,    31,     0,     0,    32,     6,    33,     7,     0,
       0,    34,     0,     0,     8,     9,     0,     0,    10,     0,
      35,     0,    36,    11,     0,     0,     0,     0,     0,     0,
      37,    38,    12,     0,    13,     0,     0,     0,     0,     0,
      14,    15,     0,    16,     0,     0,     0,    17,     0,     0,
      18,     0,     0,     0,     0,     0,     0,    19,     0,    39,
       0,     0,   307,     0,    20,   297,     0,     0,    21,     0,
      22,    23,    24,    25,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,    29,    30,    31,
       0,     0,    32,     6,    33,     7,     0,     0,    34,     0,
       0,     8,     9,     0,     0,    10,     0,    35,     0,    36,
      11,     0,     0,     0,     0,     0,     0,    37,    38,    12,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,    17,     0,     0,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    39,     0,     0,   609,
       0,    20,     0,     0,     0,    21,     0,    22,    23,    24,
      25,     0,     0,     0,     0,     0,    26,     4,     5,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     7,     0,    28,
       0,     0,     0,     8,    29,    30,    31,    10,     0,    32,
       0,    33,    11,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    13,    35,     0,    36,     0,     0,    14,
      15,     0,    16,     0,    37,    38,    17,     0,     0,    18,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,     0,    22,
      23,    24,     0,    39,     0,     0,   422,     0,    26,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     7,
       0,    28,     0,     0,     0,     8,    29,    30,    31,    10,
       0,    32,     0,    33,    11,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,    13,    35,     0,    36,     0,
       0,    14,    15,     0,    16,     0,    37,    38,    17,     0,
       0,    18,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,    21,
       0,    22,    23,    24,     0,    39,     0,     0,   431,     0,
      26,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
     469,   470,   471,   472,   473,   474,   475,   476,     0,     6,
       0,     7,     0,    28,     0,     0,     0,     8,    29,    30,
      31,    10,     0,    32,     0,    33,    11,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    13,    35,     0,
      36,     0,     0,    14,    15,     0,    16,     0,    37,    38,
      17,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    20,     5,     0,
       0,    21,     0,    22,    23,    24,     0,    39,     0,     0,
     550,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     7,     0,     0,
       0,     0,     0,     8,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
      29,    30,    31,    13,     0,    32,     0,    33,     0,   205,
      15,    34,    16,     0,     0,     0,    17,     0,     0,    18,
      35,     0,    36,     0,     0,     0,    19,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,    21,     0,    22,
      23,    24,     0,     0,     0,     0,     0,   477,    26,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,    39,
       0,     0,   644,     0,     4,     5,   488,   489,   553,     0,
       0,     0,     0,   296,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    29,    30,    31,     0,
       0,    32,     6,    33,     7,     0,     0,   208,     0,     0,
       8,     9,     0,     0,    10,     0,   209,     0,    36,    11,
       0,     0,     0,     0,     0,     0,    37,    38,    12,     0,
      13,     0,     0,     0,     0,     0,    14,    15,     0,    16,
       0,     0,     0,    17,     0,     0,    18,     0,     0,     0,
       0,     0,     0,    19,     0,    39,     0,     0,   544,     0,
      20,   297,     0,     0,    21,     0,    22,    23,    24,    25,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,    29,    30,    31,     0,     0,    32,     6,
      33,     7,     0,     0,    34,     0,     0,     8,     9,     0,
       0,    10,     0,    35,     0,    36,    11,     0,     0,     0,
       0,     0,     0,    37,    38,    12,     0,    13,     0,     0,
       0,     0,     0,    14,    15,     0,    16,     0,     0,     0,
      17,     0,     0,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    39,     0,     0,     0,     0,    20,     5,     0,
       0,    21,     0,    22,    23,    24,    25,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     7,     0,     0,
       0,     0,   237,     8,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
      29,    30,    31,    13,     0,    32,     0,    33,     0,   205,
      15,    34,    16,     0,   238,     0,    17,     0,   -59,    18,
      35,     0,    36,     0,     0,     0,    19,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,    21,     0,    22,
      23,    24,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    29,    30,    31,     0,
       0,    32,     0,    33,   240,     0,     0,   208,     0,     0,
       0,     0,     6,     0,     7,     0,   209,     0,    36,   237,
       8,     0,     0,     0,    10,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,   598,     0,   205,    15,     0,    16,
       0,   238,     0,    17,     0,    39,    18,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,    28,     0,
       0,     0,     0,    29,    30,    31,     0,     0,    32,     0,
      33,   240,     0,     0,   208,   615,     0,     0,     0,     0,
       0,     0,     0,   209,     6,    36,     7,     0,     0,     0,
       0,     0,     8,    37,    38,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,    13,     0,     0,     0,     0,     0,   205,    15,
       0,    16,    39,     0,     0,    17,     0,     0,    18,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,    21,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,    26,   468,   469,
     470,   471,   472,   473,   474,   475,   476,     0,     0,     0,
       6,     0,     7,     0,     0,     0,     0,     0,     8,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,    29,    30,    31,    13,     0,
      32,     0,    33,     0,   205,    15,   208,    16,     0,     0,
       0,    17,     0,     0,    18,   209,     0,    36,     0,     0,
       0,    19,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,    21,     0,    22,    23,    24,     0,     0,     0,
       0,     0,     0,    26,   468,   469,   470,   471,   472,   473,
     474,   475,   476,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
     469,   470,   471,   472,   473,   474,    28,     0,     0,     0,
       0,    29,    30,    31,     0,     0,    32,     0,    33,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    37,    38,   468,   469,   470,   471,   472,   473,   474,
     475,   476,     0,     0,     0,     0,   477,     0,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,     0,     0,
      39,     0,     0,     0,     0,   488,   489,     0,     0,     0,
       0,     0,   523,   468,   469,   470,   471,   472,   473,   474,
     475,   476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,   469,   470,   471,   472,   473,
     474,   475,   476,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   469,   470,   471,   472,   473,   474,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   477,     0,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   468,   469,   470,   471,   472,   473,
     474,   488,   489,     0,     0,     0,     0,     0,   564,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,     0,
       0,     0,     0,     0,     0,     0,   488,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   477,     0,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,     0,     0,     0,     0,     0,
     488,   489,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   477,   633,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,     0,     0,     0,     0,     0,
     488,   489,   477,     0,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     5,     0,     0,     0,     0,     0,
       0,   488,   489,   479,   480,   481,   482,   483,   484,   485,
     486,   487,     0,     0,     0,     0,     0,     0,     0,   488,
     489,     6,     0,     7,     0,     0,     0,     0,     0,     8,
       9,     0,     0,    10,     0,     0,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,     0,    12,     0,    13,
       0,   488,   489,     0,     0,   205,    15,     0,    16,     0,
       0,     0,    17,     0,     0,    18,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,    21,     0,    22,    23,    24,    25,     0,
       0,   206,     0,     0,    26,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     0,     7,
       0,     0,     0,     0,     0,     8,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,    29,    30,    31,    13,     0,    32,     0,    33,
       0,   205,    15,   208,    16,     0,     0,     0,    17,     0,
       0,    18,   209,     0,    36,     0,     0,     0,    19,     0,
       0,     0,    37,    38,     0,     0,     5,     0,     0,    21,
       0,    22,    23,    24,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,     7,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,    29,    30,
      31,    13,     0,    32,     0,    33,     0,   205,    15,   208,
       0,     0,     0,     0,    17,     0,     0,    18,   209,     0,
      36,     0,     0,     0,    19,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,    31,     0,     0,    32,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,   209,     0,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    98,     0,    99,   100,
     101,   102,   103,   104,     0,   105,     0,     0,   106,     0,
     107,     0,     0,     0,   108,   109,     0,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,   122,     0,   123,   124,   125,   126,   127,     0,     0,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,   135,   136,   137,     0,   138,   139,   140,   141,
     142,   143,     0,     0,   144,     0,     0,   145,     0,     0,
       0,     0,   146,   147,     0,   148,   149,     0,   150,   151,
       0,     0,     0,   152,   153,   154,   155,   156,   157,     0,
     158,   159,   160,   161,   162,   163,   164,     0,   165,   166,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   179,     0,     0,     0,   180,     0,
       0,   181,     0,     0,   182,   183,     0,     0,   184,   185,
     186,   187,     0,     0,   188,     0,   189,     0,   190,   191,
     192,   193,   194,   195,   196,     0,     0,   197
};

static const yytype_int16 yycheck[] =
{
       2,     2,    69,     2,    69,     2,     2,   307,   269,     2,
      48,   272,   268,   274,   246,   204,   277,    45,     2,   276,
     325,   282,   242,   243,    70,     2,     2,   294,     2,   506,
       2,     2,   108,   558,    16,    38,    48,    58,   505,   507,
     327,    16,   509,   155,    90,     3,   155,     5,    51,    48,
     155,    48,    66,    67,    68,    48,    34,    35,    72,     0,
       3,   202,     5,   563,    48,   202,   207,   202,   568,   207,
     207,    31,   207,     3,   330,     5,    36,    99,    99,   133,
      16,    39,     9,   137,    67,    68,    44,   181,   565,    72,
     181,     3,   204,     5,   206,   204,    39,     3,   566,   204,
       6,     7,     8,     9,    10,    11,   128,   327,    96,    39,
     164,   181,   206,    71,    44,   181,   202,   208,   181,   419,
     206,   598,   647,     3,   624,   181,   202,    39,    71,   318,
     597,   431,   321,   600,   321,   603,     6,     7,   208,    39,
      44,    71,   208,   207,    44,   208,   413,   203,   625,   216,
     183,   216,   341,   342,   343,   342,   343,    26,   206,    71,
     627,    30,   206,   631,    70,    69,     3,   125,     5,   636,
       9,    71,     3,    12,     5,   242,   243,   242,   243,    14,
      15,    16,   125,   206,   202,   652,   447,   205,   255,   202,
      94,   202,   205,   151,   205,   125,   263,     3,   418,     5,
     202,   203,   205,   202,   203,   202,   203,   161,   151,   202,
     203,   117,   224,   125,   189,   190,   191,   192,   193,   201,
     202,   151,     3,   204,     5,   125,   201,   202,   207,   490,
     208,   209,     9,   191,   138,   467,   250,   283,   276,   151,
     286,   147,   288,   289,   549,   206,   150,   293,   191,   207,
     550,   151,   204,   206,   160,   191,   192,   193,   204,   520,
     327,   191,   327,   207,   207,   201,   202,   250,   206,     3,
     308,     5,   202,     3,   276,     5,   204,   207,   206,   191,
     186,   513,   206,   189,   190,   191,   204,    39,   194,   195,
     202,   191,   206,   206,   332,   207,   206,   203,   555,   204,
     207,   207,   202,   204,     3,   206,     5,   207,   608,   206,
     597,   176,   177,   178,   179,   180,   204,   319,   319,    71,
     319,   541,   319,   319,   326,   326,   319,   326,   366,   326,
     332,   563,     3,   326,     5,   319,   568,   624,   202,   571,
      40,   343,   319,   319,   644,   319,   384,   319,   319,   636,
       3,   418,     5,   418,   189,   190,   191,   192,   193,     3,
       3,     5,     5,   207,   207,   652,   201,   202,     3,   207,
       5,   207,   206,   125,   208,   207,     3,   207,   207,   446,
     207,   207,   207,    83,   207,   207,   207,   425,   416,   645,
     610,   207,   624,   207,   207,   433,    96,    97,    98,   151,
     207,   206,   467,   207,   207,   105,   667,   207,   207,   207,
     207,   449,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   459,   207,   207,   420,   427,   425,   207,   430,   430,
     204,   430,   207,   430,   433,   207,   433,   430,   207,   191,
     433,   207,   507,   206,   144,   206,   204,   209,   148,   208,
     202,   208,   449,     3,   207,   207,     6,     7,     8,     9,
      10,    11,     9,     9,     9,     9,     9,     9,     9,   507,
       9,     9,   207,   202,   541,   265,   541,   183,   268,   206,
     204,   204,   204,   672,   673,   275,   206,   208,   278,   205,
     181,   209,   207,   560,   284,   285,   208,   208,   563,   208,
     208,   566,   181,   568,   208,   507,   208,   545,     9,    90,
     208,   208,   208,   208,   208,   208,   208,   555,   208,   208,
      70,   208,   208,   208,   208,   208,   208,   208,   566,   201,
     208,   208,   208,   535,   208,   183,   535,   206,   535,   205,
     330,   331,   535,   610,   208,   610,   208,   181,   206,   206,
       3,     3,     9,   555,   208,     6,   181,   206,   208,   624,
     206,   208,   183,   208,   566,   603,   208,   117,   204,   208,
     360,   361,   362,   363,   364,   365,   366,   208,   208,   208,
     182,   222,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   208,   631,   183,   183,   206,   147,   446,   201,
     202,   603,   290,    48,   284,   429,   208,   515,   427,   216,
     160,   613,   613,   673,   613,   647,   613,    14,    15,    16,
     613,   280,    19,    20,    -1,    -1,    -1,    -1,    -1,   631,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,   189,
     190,   191,    -1,    -1,   194,   195,    -1,    -1,   438,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,   469,
      -1,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,    -1,   489,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    -1,     3,    -1,    -1,     6,
       7,     8,     9,    10,    11,   515,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    69,    70,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    -1,    70,    -1,    -1,    83,    -1,    -1,    -1,
     187,   188,   189,   190,   191,   192,   193,    94,    -1,    96,
      97,    98,    -1,    -1,   201,   202,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
     630,   138,    -1,   633,    -1,    -1,   143,   144,   145,    -1,
     147,   148,    -1,   150,    -1,   645,    -1,   154,    -1,    -1,
     147,    -1,    -1,   160,    -1,    -1,   163,    -1,   165,    -1,
      -1,    -1,    -1,   160,    -1,    -1,   173,   174,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,   189,   190,   191,    -1,    -1,   194,   195,   186,
      -1,    -1,   189,   190,   191,    -1,    -1,   194,   195,    32,
     207,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
     207,    44,    -1,    -1,    -1,    -1,    49,   187,   188,   189,
     190,   191,   192,   193,    -1,    58,    -1,    60,    -1,    -1,
      -1,   201,   202,    66,    67,    -1,    69,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      -1,    94,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   138,    -1,    -1,   201,   202,
     143,   144,   145,    -1,    -1,   148,    32,   150,    34,    -1,
      -1,   154,    -1,    -1,    40,    41,    -1,    -1,    44,    -1,
     163,    -1,   165,    49,    -1,    -1,    -1,    -1,    -1,    -1,
     173,   174,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    69,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,   202,
      -1,    -1,   205,    -1,    90,    91,    -1,    -1,    94,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,   143,   144,   145,
      -1,    -1,   148,    32,   150,    34,    -1,    -1,   154,    -1,
      -1,    40,    41,    -1,    -1,    44,    -1,   163,    -1,   165,
      49,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,   202,    -1,    -1,   205,
      -1,    90,    -1,    -1,    -1,    94,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,   105,     4,     5,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,   138,
      -1,    -1,    -1,    40,   143,   144,   145,    44,    -1,   148,
      -1,   150,    49,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,   163,    -1,   165,    -1,    -1,    66,
      67,    -1,    69,    -1,   173,   174,    73,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    -1,   202,    -1,    -1,   205,    -1,   105,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      -1,   138,    -1,    -1,    -1,    40,   143,   144,   145,    44,
      -1,   148,    -1,   150,    49,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,   163,    -1,   165,    -1,
      -1,    66,    67,    -1,    69,    -1,   173,   174,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    -1,   202,    -1,    -1,   205,    -1,
     105,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    32,
      -1,    34,    -1,   138,    -1,    -1,    -1,    40,   143,   144,
     145,    44,    -1,   148,    -1,   150,    49,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,   163,    -1,
     165,    -1,    -1,    66,    67,    -1,    69,    -1,   173,   174,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,     5,    -1,
      -1,    94,    -1,    96,    97,    98,    -1,   202,    -1,    -1,
     205,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,    60,    -1,   148,    -1,   150,    -1,    66,
      67,   154,    69,    -1,    -1,    -1,    73,    -1,    -1,    76,
     163,    -1,   165,    -1,    -1,    -1,    83,    -1,    -1,    -1,
     173,   174,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,   182,   105,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   202,
      -1,    -1,   205,    -1,     4,     5,   201,   202,   203,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
      -1,   148,    32,   150,    34,    -1,    -1,   154,    -1,    -1,
      40,    41,    -1,    -1,    44,    -1,   163,    -1,   165,    49,
      -1,    -1,    -1,    -1,    -1,    -1,   173,   174,    58,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,   202,    -1,    -1,   205,    -1,
      90,    91,    -1,    -1,    94,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,   148,    32,
     150,    34,    -1,    -1,   154,    -1,    -1,    40,    41,    -1,
      -1,    44,    -1,   163,    -1,   165,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   173,   174,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,   202,    -1,    -1,    -1,    -1,    90,     5,    -1,
      -1,    94,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
     143,   144,   145,    60,    -1,   148,    -1,   150,    -1,    66,
      67,   154,    69,    -1,    71,    -1,    73,    -1,   161,    76,
     163,    -1,   165,    -1,    -1,    -1,    83,    -1,    -1,    -1,
     173,   174,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
      -1,   148,    -1,   150,   151,    -1,    -1,   154,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,   163,    -1,   165,    39,
      40,    -1,    -1,    -1,    44,    -1,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,   191,    -1,    66,    67,    -1,    69,
      -1,    71,    -1,    73,    -1,   202,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,    -1,    -1,   148,    -1,
     150,   151,    -1,    -1,   154,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    32,   165,    34,    -1,    -1,    -1,
      -1,    -1,    40,   173,   174,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    69,   202,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    94,    -1,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,    60,    -1,
     148,    -1,   150,    -1,    66,    67,   154,    69,    -1,    -1,
      -1,    73,    -1,    -1,    76,   163,    -1,   165,    -1,    -1,
      -1,    83,    -1,    -1,    -1,   173,   174,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,   148,    -1,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   163,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   182,    -1,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     202,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
      -1,    -1,   208,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,    -1,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    14,    15,    16,    17,    18,    19,
      20,   201,   202,    -1,    -1,    -1,    -1,    -1,   208,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,    -1,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   202,   182,    -1,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   201,   202,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,    32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    44,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    58,    -1,    60,
      -1,   201,   202,    -1,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,    60,    -1,   148,    -1,   150,
      -1,    66,    67,   154,    69,    -1,    -1,    -1,    73,    -1,
      -1,    76,   163,    -1,   165,    -1,    -1,    -1,    83,    -1,
      -1,    -1,   173,   174,    -1,    -1,     5,    -1,    -1,    94,
      -1,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,   143,   144,
     145,    60,    -1,   148,    -1,   150,    -1,    66,    67,   154,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,   163,    -1,
     165,    -1,    -1,    -1,    83,    -1,    -1,    -1,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,   174,    24,    -1,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    42,    43,    -1,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    -1,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    -1,   100,   101,    -1,   103,   104,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,    -1,   126,   127,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,   139,   140,   141,   142,    -1,    -1,    -1,   146,    -1,
      -1,   149,    -1,    -1,   152,   153,    -1,    -1,   156,   157,
     158,   159,    -1,    -1,   162,    -1,   164,    -1,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,   175
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   211,   212,     0,     4,     5,    32,    34,    40,    41,
      44,    49,    58,    60,    66,    67,    69,    73,    76,    83,
      90,    94,    96,    97,    98,    99,   105,   110,   138,   143,
     144,   145,   148,   150,   154,   163,   165,   173,   174,   202,
     216,   217,   218,   219,   220,   223,   224,   230,   231,   242,
     256,   260,   262,   263,   264,   265,   266,   269,   270,   273,
     275,   276,   277,   278,   280,   281,   282,   283,   284,   286,
     288,   306,   307,   308,   309,     3,     5,   207,     3,     5,
       3,     5,   258,    96,   261,     9,     3,     5,   261,     3,
     207,   261,   262,     3,   258,     3,   258,   262,    24,    26,
      27,    28,    29,    30,    31,    33,    36,    38,    42,    43,
      45,    46,    47,    48,    50,    51,    52,    53,    54,    55,
      56,    57,    59,    61,    62,    63,    64,    65,    68,    72,
      74,    75,    77,    78,    79,    80,    81,    82,    84,    85,
      86,    87,    88,    89,    92,    95,   100,   101,   103,   104,
     106,   107,   111,   112,   113,   114,   115,   116,   118,   119,
     120,   121,   122,   123,   124,   126,   127,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   139,   140,   141,   142,
     146,   149,   152,   153,   156,   157,   158,   159,   162,   164,
     166,   167,   168,   169,   170,   171,   172,   175,   232,   234,
     305,   206,   213,   213,   161,    66,   102,   109,   154,   163,
     222,   242,   263,   269,   275,   279,   286,   306,   309,   206,
     206,   204,   204,   206,   204,   206,   215,   206,   183,   274,
     204,   287,   288,   287,   287,     3,     5,    39,    71,   125,
     151,   191,   207,   236,   259,   289,   290,   303,   242,   306,
     307,   309,   287,   206,     9,   204,   206,   307,   204,   155,
     204,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   181,   203,    13,    91,   216,   221,
     224,   263,   265,   266,   277,   278,   281,   205,   230,   231,
       3,     3,     3,     5,     3,     3,   204,   303,   267,   212,
     128,   271,   275,     3,     5,   204,   214,   285,   289,   289,
     209,   202,   207,   229,   287,   208,   239,   240,   241,   259,
     208,   249,   207,   252,     9,     9,    12,   235,   259,     3,
       6,     7,     8,     9,    10,    11,    70,   117,   147,   160,
     186,   189,   190,   191,   194,   195,   207,   245,   246,   247,
     245,   248,     9,     9,   233,   248,   247,     9,     9,   247,
       9,   247,   245,   228,   231,   286,   247,   243,   244,   245,
       9,   305,     9,   247,   307,   243,   245,   307,   176,   177,
     178,   179,   180,   304,   307,   307,   235,     6,     7,   310,
       9,   307,   234,   202,   207,   206,   204,   215,   286,   205,
     230,   268,   205,   183,   108,   230,   254,   272,   206,   204,
     214,   205,   216,   231,   284,   289,   208,   248,   191,   203,
     245,   225,   226,   227,   228,   205,   181,   209,   205,   230,
     250,   254,   205,   231,   251,   254,   208,   208,   208,   207,
     245,   245,   245,   245,   245,   245,   245,   286,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   182,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   201,   202,
     181,   208,   208,   208,   181,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   286,   191,   207,   229,   236,
     259,   295,   297,   298,   208,   181,   208,   208,   208,   208,
     181,   208,   208,   208,   208,   208,   208,   208,   208,   201,
     208,   208,   208,   234,     9,   213,   289,   299,   215,   278,
     183,   286,   306,   206,   205,   231,   255,   256,   205,   220,
     205,   215,   203,   203,   208,   181,   241,   247,   286,   309,
     208,   206,   206,   286,   208,   191,   207,   229,   236,   291,
     293,   294,   245,   245,     3,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,     3,   245,   247,     9,   297,   285,   191,   225,
     236,   296,   297,   207,   229,   244,   247,     6,   208,   205,
     181,   289,   206,   214,   215,    23,   228,   295,   301,   302,
     206,   257,   259,   293,   285,   191,   225,   236,   292,   293,
     208,   207,   229,   183,   203,   297,   285,   208,   297,   208,
     225,   208,   215,   289,   205,   183,   300,   181,   206,   204,
     208,   293,   285,   208,   297,   208,   245,   225,   245,   297,
     208,   215,   248,   301,   237,   297,   208,    38,    51,   205,
     238,   247,   183,   183,   206,   253,   254,   253,   206
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   210,   211,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   214,   214,   215,   215,   216,   216,   216,   216,
     216,   216,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   225,
     226,   226,   227,   227,   228,   228,   229,   229,   229,   230,
     230,   231,   232,   232,   232,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   235,   236,
     236,   236,   236,   237,   237,   238,   238,   239,   239,   239,
     240,   240,   241,   241,   242,   243,   243,   244,   244,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     246,   246,   247,   248,   249,   249,   250,   250,   251,   251,
     252,   252,   253,   253,   254,   254,   255,   256,   256,   257,
     257,   258,   258,   258,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   261,   261,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   263,   264,
     265,   266,   267,   267,   268,   269,   269,   270,   271,   271,
     272,   272,   273,   273,   274,   274,   275,   275,   276,   277,
     277,   277,   278,   278,   279,   279,   280,   281,   282,   282,
     282,   283,   284,   285,   285,   286,   286,   287,   287,   288,
     288,   288,   289,   289,   289,   290,   290,   290,   290,   291,
     291,   291,   292,   292,   293,   293,   294,   294,   294,   294,
     294,   295,   295,   295,   296,   296,   297,   297,   298,   298,
     298,   298,   298,   298,   299,   299,   300,   300,   301,   302,
     302,   303,   303,   304,   304,   304,   304,   304,   305,   305,
     305,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   308,   309,   309,   310,   310,   310
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     5,     2,     2,     3,     2,     2,
       2,     2,     0,     2,     5,     2,     3,     2,     2,     2,
       2,     2,     0,     2,     0,     1,     1,     2,     2,     1,
       2,     1,     1,     2,     1,     2,     1,     2,     2,     2,
       2,     4,     3,     3,     5,     2,     3,     4,     0,     1,
       1,     3,     1,     3,     3,     2,     3,     3,     2,     0,
       1,     3,     1,     3,     4,     1,     3,     0,     1,     4,
       1,     1,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     1,     4,     1,     1,
       4,     1,     4,     1,     1,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     1,     6,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     4,     4,     1,     1,     4,     4,
       4,     1,     1,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     4,     3,     0,     2,     1,
       1,     3,     3,     1,     5,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     5,     4,     3,
       1,     3,     1,     1,     0,     2,     4,     3,     2,     2,
       0,     2,     2,     1,     3,     2,     1,     3,     2,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     2,     2,     2,
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
       2,     4,     5,     5,    10,     1,     3,     1
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
#line 308 "parser.y" /* yacc.c:1646  */
    { fix_incomplete();
						  check_statements((yyvsp[0].stmt_list), FALSE);
						  check_all_user_types((yyvsp[0].stmt_list));
						  write_header((yyvsp[0].stmt_list));
						  write_id_data((yyvsp[0].stmt_list));
						  write_proxies((yyvsp[0].stmt_list));
						  write_client((yyvsp[0].stmt_list));
						  write_server((yyvsp[0].stmt_list));
						  write_regscript((yyvsp[0].stmt_list));
						  write_dlldata((yyvsp[0].stmt_list));
						  write_local_stubs((yyvsp[0].stmt_list));
						}
#line 2592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = NULL; }
#line 2598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statements((yyvsp[-4].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, 0);
						}
#line 2624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 330 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, 0);
						}
#line 2632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = NULL; }
#line 2656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statements((yyvsp[-4].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, 0); }
#line 2680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, 0);
						}
#line 2688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 2706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = NULL; }
#line 2718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 362 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 2730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 2736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 2742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 2748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 2754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 2760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), FALSE, NULL); }
#line 2766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 374 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), FALSE, NULL); }
#line 2772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 2778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 2784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 378 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 2790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 379 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 2796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 382 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 2802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 384 "parser.y" /* yacc.c:1646  */
    { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 2813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 2822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 399 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str)); }
#line 2828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 404 "parser.y" /* yacc.c:1646  */
    { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only) start_typelib((yyval.typelib));
						}
#line 2842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 409 "parser.y" /* yacc.c:1646  */
    { (yyval.typelib) = (yyvsp[-3].typelib);
						  (yyval.typelib)->stmts = (yyvsp[-2].stmt_list);
						  if (!parse_only) end_typelib();
						}
#line 2851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 415 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 2857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 419 "parser.y" /* yacc.c:1646  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 2863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 420 "parser.y" /* yacc.c:1646  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 2869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 424 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 2875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 428 "parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 433 "parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2895 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 440 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("array dimension is not an integer constant\n");
						}
#line 2904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 444 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 445 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 448 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = NULL; }
#line 2922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 453 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 2928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 456 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 2934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 2940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 458 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 2946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 461 "parser.y" /* yacc.c:1646  */
    { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 2952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 462 "parser.y" /* yacc.c:1646  */
    { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 2958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 465 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = NULL; }
#line 2964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 2970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 467 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 2976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 2982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 2988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 470 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 2994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 471 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 472 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 473 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 474 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 475 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 479 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 480 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 481 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 482 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 483 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 485 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3084 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 486 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3090 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 487 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3096 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3108 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 490 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 491 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 492 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 493 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3138 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 495 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 496 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 497 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 499 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 500 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 501 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 502 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 503 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 504 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 505 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 506 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 507 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 508 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 509 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 510 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3234 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 511 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_IN); }
#line 3240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 512 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 513 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3252 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 514 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3258 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 515 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 516 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3270 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 517 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3276 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 518 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 519 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 520 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3294 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 521 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3300 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 522 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3306 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 523 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3312 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 524 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 525 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 526 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 527 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 528 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 529 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 530 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3354 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 531 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 532 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 533 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 534 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 535 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 536 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 537 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 538 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 3402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 539 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 3408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 541 "parser.y" /* yacc.c:1646  */
    { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 3416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 544 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 3422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 545 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 3428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 546 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 3434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 547 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 3440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 548 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 3446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 549 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 3452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 550 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 3458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 551 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 3464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 552 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_STRING); }
#line 3470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 553 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 3476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 554 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 3482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 555 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 3488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 556 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 3494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 557 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 3500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 558 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 3506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 559 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 3512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 560 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 3518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 561 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 3524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 562 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 3530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 563 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 3536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 564 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 3542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 565 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 3548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 566 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 3554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 567 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 3560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 572 "parser.y" /* yacc.c:1646  */
    { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 3568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 577 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = xstrdup("__cdecl"); }
#line 3574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 578 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = xstrdup("__fastcall"); }
#line 3580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 579 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = xstrdup("__pascal"); }
#line 3586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 580 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = xstrdup("__stdcall"); }
#line 3592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 583 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 3598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 584 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 3604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 587 "parser.y" /* yacc.c:1646  */
    { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 591 "parser.y" /* yacc.c:1646  */
    { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 597 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 3628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 598 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 3634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 602 "parser.y" /* yacc.c:1646  */
    { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 3643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 606 "parser.y" /* yacc.c:1646  */
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
#line 3658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 618 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 622 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 627 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_enum((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 3681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 630 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 3687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 631 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 3693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 634 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 638 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 3705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 639 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 3711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 640 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 3717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 641 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 3723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 642 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 3729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 643 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 3735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 644 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 3741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 645 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 3747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 646 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 3753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 647 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 3759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 648 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 649 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 650 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 651 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 652 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 653 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 654 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 655 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 656 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 657 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 658 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 659 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 660 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 661 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 662 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 663 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 664 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 665 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 666 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 667 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 3879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 668 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 3885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 669 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 3891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 670 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 3897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 671 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 3903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 672 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 3909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 673 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 674 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 676 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 3927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 678 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 3933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 679 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 680 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 683 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 3951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 684 "parser.y" /* yacc.c:1646  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 3957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 687 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 3966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 693 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 3975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 699 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 3981 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 700 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 3987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 704 "parser.y" /* yacc.c:1646  */
    { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 3996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 708 "parser.y" /* yacc.c:1646  */
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 715 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 716 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 719 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 4023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 720 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 724 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 725 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = NULL; }
#line 4041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 728 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 732 "parser.y" /* yacc.c:1646  */
    { var_t *v = make_var(NULL);
						  v->type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 738 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 747 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 750 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 755 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = NULL; }
#line 4091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 759 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 4097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 760 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 761 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 764 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 766 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 769 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 770 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 772 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 773 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4145 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 774 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 775 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 776 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 777 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 778 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4175 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 779 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 786 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 787 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 788 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 789 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 790 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 791 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 792 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4223 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 793 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 796 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 797 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type((yyvsp[0].str), 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 805 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4255 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 812 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 815 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = NULL; }
#line 4267 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 818 "parser.y" /* yacc.c:1646  */
    { (yyval.ifref_list) = NULL; }
#line 4273 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 819 "parser.y" /* yacc.c:1646  */
    { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4279 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 823 "parser.y" /* yacc.c:1646  */
    { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 826 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 4291 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 827 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 4297 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 830 "parser.y" /* yacc.c:1646  */
    { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 839 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 4315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 840 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4321 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 843 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = NULL; }
#line 4327 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 844 "parser.y" /* yacc.c:1646  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 850 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 854 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 859 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = NULL; }
#line 4355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 860 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error2((yyvsp[0].str), 0); }
#line 4361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 863 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 4367 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 864 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 4373 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 867 "parser.y" /* yacc.c:1646  */
    { (yyval.ifinfo).interface = (yyvsp[0].type);
						  (yyval.ifinfo).old_pointer_default = pointer_default;
						  if (is_attr((yyvsp[-1].attr_list), ATTR_POINTERDEFAULT))
						    pointer_default = get_attrv((yyvsp[-1].attr_list), ATTR_POINTERDEFAULT);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 4386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 878 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-5].ifinfo).interface;
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  pointer_default = (yyvsp[-5].ifinfo).old_pointer_default;
						}
#line 4397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 888 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-7].ifinfo).interface;
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						  pointer_default = (yyvsp[-7].ifinfo).old_pointer_default;
						}
#line 4406 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 892 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 896 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 897 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 900 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 901 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 904 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 910 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 4452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 916 "parser.y" /* yacc.c:1646  */
    { (yyval.stgclass) = STG_EXTERN; }
#line 4458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 917 "parser.y" /* yacc.c:1646  */
    { (yyval.stgclass) = STG_STATIC; }
#line 4464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 918 "parser.y" /* yacc.c:1646  */
    { (yyval.stgclass) = STG_REGISTER; }
#line 4470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 922 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_INLINE); }
#line 4476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 926 "parser.y" /* yacc.c:1646  */
    { (yyval.attr) = make_attr(ATTR_CONST); }
#line 4482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 929 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = NULL; }
#line 4488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 930 "parser.y" /* yacc.c:1646  */
    { (yyval.attr_list) = append_attr((yyvsp[-1].attr_list), (yyvsp[0].attr)); }
#line 4494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 933 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, NULL, STG_NONE); }
#line 4500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 935 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), NULL, STG_NONE); }
#line 4506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 938 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = NULL; }
#line 4512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 943 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].attr), STG_NONE); }
#line 4518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 944 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].attr), STG_NONE); }
#line 4524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 945 "parser.y" /* yacc.c:1646  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, NULL, (yyvsp[-1].stgclass)); }
#line 4530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 950 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 951 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 957 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 958 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 959 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[0].expr)); }
#line 4561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 960 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 969 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 970 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 978 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 979 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); if ((yyval.declarator)->func_type) (yyval.declarator)->func_type->attrs = append_attr((yyval.declarator)->func_type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str)));
						           else if ((yyval.declarator)->type) (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 984 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 990 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 991 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[0].expr)); }
#line 4614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 992 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[0].expr)); }
#line 4620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 994 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 999 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1008 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1009 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1016 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type = append_ptrchain_type((yyval.declarator)->type, type_new_pointer(pointer_default, NULL, (yyvsp[-1].attr_list))); }
#line 4656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1017 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->type->attrs = append_attr((yyval.declarator)->type->attrs, make_attrp(ATTR_CALLCONV, (yyvsp[-1].str))); }
#line 4662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1021 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1029 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1030 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1031 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[0].expr)); }
#line 4686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1032 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL); (yyval.declarator)->array = append_array((yyval.declarator)->array, (yyvsp[0].expr)); }
#line 4692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1034 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = make_declarator(NULL);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1039 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  (yyval.declarator)->func_type = append_ptrchain_type((yyval.declarator)->type, type_new_function((yyvsp[-1].var_list)));
						  (yyval.declarator)->type = NULL;
						}
#line 4710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1046 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1047 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1050 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 4728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1051 "parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 4734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1054 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 4743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1061 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1063 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1067 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[0].declarator); }
#line 4761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1068 "parser.y" /* yacc.c:1646  */
    { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 4767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1072 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = THREADING_APARTMENT; }
#line 4773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1073 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = THREADING_NEUTRAL; }
#line 4779 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1074 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = THREADING_SINGLE; }
#line 4785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1075 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = THREADING_FREE; }
#line 4791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1076 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = THREADING_BOTH; }
#line 4797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1080 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = RPC_FC_RP; }
#line 4803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1081 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = RPC_FC_UP; }
#line 4809 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1082 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = RPC_FC_FP; }
#line 4815 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1085 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_struct((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 4821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1088 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_void(); }
#line 4827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1089 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1090 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4839 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1091 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1092 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), FALSE, NULL); }
#line 4851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1093 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1094 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), FALSE, NULL); }
#line 4863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1095 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1096 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 4875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1097 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 4881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1101 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list));
						}
#line 4890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1108 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 4896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1111 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 4902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1115 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 4908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1116 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 4914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1117 "parser.y" /* yacc.c:1646  */
    { (yyval.num) = (yyvsp[0].num); }
#line 4920 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 4924 "parser.tab.c" /* yacc.c:1646  */
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
#line 1120 "parser.y" /* yacc.c:1906  */


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
	   && !is_attr(attrs, ATTR_HIDDEN))
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
