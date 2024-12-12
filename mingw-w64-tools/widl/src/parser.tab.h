/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
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
/* "%code requires" blocks.  */
#line 110 "tools/widl/parser.y"


#define PARSER_LTYPE struct location


#line 63 "tools/widl/parser.tab.h"

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
    tCDECL = 267,                  /* tCDECL  */
    tFASTCALL = 268,               /* tFASTCALL  */
    tPASCAL = 269,                 /* tPASCAL  */
    tSTDCALL = 270,                /* tSTDCALL  */
    aUUID = 271,                   /* aUUID  */
    aEOF = 272,                    /* aEOF  */
    aACF = 273,                    /* aACF  */
    SHL = 274,                     /* SHL  */
    SHR = 275,                     /* SHR  */
    MEMBERPTR = 276,               /* MEMBERPTR  */
    EQUALITY = 277,                /* EQUALITY  */
    INEQUALITY = 278,              /* INEQUALITY  */
    GREATEREQUAL = 279,            /* GREATEREQUAL  */
    LESSEQUAL = 280,               /* LESSEQUAL  */
    LOGICALOR = 281,               /* LOGICALOR  */
    LOGICALAND = 282,              /* LOGICALAND  */
    ELLIPSIS = 283,                /* ELLIPSIS  */
    tACTIVATABLE = 284,            /* tACTIVATABLE  */
    tAGGREGATABLE = 285,           /* tAGGREGATABLE  */
    tAGILE = 286,                  /* tAGILE  */
    tALLNODES = 287,               /* tALLNODES  */
    tALLOCATE = 288,               /* tALLOCATE  */
    tANNOTATION = 289,             /* tANNOTATION  */
    tAPICONTRACT = 290,            /* tAPICONTRACT  */
    tAPPOBJECT = 291,              /* tAPPOBJECT  */
    tASYNC = 292,                  /* tASYNC  */
    tASYNCUUID = 293,              /* tASYNCUUID  */
    tAUTOHANDLE = 294,             /* tAUTOHANDLE  */
    tBINDABLE = 295,               /* tBINDABLE  */
    tBOOLEAN = 296,                /* tBOOLEAN  */
    tBROADCAST = 297,              /* tBROADCAST  */
    tBYTE = 298,                   /* tBYTE  */
    tBYTECOUNT = 299,              /* tBYTECOUNT  */
    tCALLAS = 300,                 /* tCALLAS  */
    tCALLBACK = 301,               /* tCALLBACK  */
    tCASE = 302,                   /* tCASE  */
    tCHAR = 303,                   /* tCHAR  */
    tCOCLASS = 304,                /* tCOCLASS  */
    tCODE = 305,                   /* tCODE  */
    tCOMMSTATUS = 306,             /* tCOMMSTATUS  */
    tCOMPOSABLE = 307,             /* tCOMPOSABLE  */
    tCONST = 308,                  /* tCONST  */
    tCONTEXTHANDLE = 309,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 310, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 311, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 312,               /* tCONTRACT  */
    tCONTRACTVERSION = 313,        /* tCONTRACTVERSION  */
    tCONTROL = 314,                /* tCONTROL  */
    tCPPQUOTE = 315,               /* tCPPQUOTE  */
    tCUSTOM = 316,                 /* tCUSTOM  */
    tDECLARE = 317,                /* tDECLARE  */
    tDECODE = 318,                 /* tDECODE  */
    tDEFAULT = 319,                /* tDEFAULT  */
    tDEFAULTBIND = 320,            /* tDEFAULTBIND  */
    tDELEGATE = 321,               /* tDELEGATE  */
    tDEFAULT_OVERLOAD = 322,       /* tDEFAULT_OVERLOAD  */
    tDEFAULTCOLLELEM = 323,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 324,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 325,          /* tDEFAULTVTABLE  */
    tDEPRECATED = 326,             /* tDEPRECATED  */
    tDISABLECONSISTENCYCHECK = 327, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 328,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 329,          /* tDISPINTERFACE  */
    tDLLNAME = 330,                /* tDLLNAME  */
    tDONTFREE = 331,               /* tDONTFREE  */
    tDOUBLE = 332,                 /* tDOUBLE  */
    tDUAL = 333,                   /* tDUAL  */
    tENABLEALLOCATE = 334,         /* tENABLEALLOCATE  */
    tENCODE = 335,                 /* tENCODE  */
    tENDPOINT = 336,               /* tENDPOINT  */
    tENTRY = 337,                  /* tENTRY  */
    tENUM = 338,                   /* tENUM  */
    tERRORSTATUST = 339,           /* tERRORSTATUST  */
    tEVENTADD = 340,               /* tEVENTADD  */
    tEVENTREMOVE = 341,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 342,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 343,         /* tEXPLICITHANDLE  */
    tEXTERN = 344,                 /* tEXTERN  */
    tFALSE = 345,                  /* tFALSE  */
    tFAULTSTATUS = 346,            /* tFAULTSTATUS  */
    tFLAGS = 347,                  /* tFLAGS  */
    tFLOAT = 348,                  /* tFLOAT  */
    tFORCEALLOCATE = 349,          /* tFORCEALLOCATE  */
    tHANDLE = 350,                 /* tHANDLE  */
    tHANDLET = 351,                /* tHANDLET  */
    tHELPCONTEXT = 352,            /* tHELPCONTEXT  */
    tHELPFILE = 353,               /* tHELPFILE  */
    tHELPSTRING = 354,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 355,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 356,          /* tHELPSTRINGDLL  */
    tHIDDEN = 357,                 /* tHIDDEN  */
    tHYPER = 358,                  /* tHYPER  */
    tID = 359,                     /* tID  */
    tIDEMPOTENT = 360,             /* tIDEMPOTENT  */
    tIGNORE = 361,                 /* tIGNORE  */
    tIIDIS = 362,                  /* tIIDIS  */
    tIMMEDIATEBIND = 363,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 364,         /* tIMPLICITHANDLE  */
    tIMPORT = 365,                 /* tIMPORT  */
    tIMPORTLIB = 366,              /* tIMPORTLIB  */
    tIN = 367,                     /* tIN  */
    tIN_LINE = 368,                /* tIN_LINE  */
    tINLINE = 369,                 /* tINLINE  */
    tINPUTSYNC = 370,              /* tINPUTSYNC  */
    tINT = 371,                    /* tINT  */
    tINT32 = 372,                  /* tINT32  */
    tINT3264 = 373,                /* tINT3264  */
    tINT64 = 374,                  /* tINT64  */
    tINTERFACE = 375,              /* tINTERFACE  */
    tLCID = 376,                   /* tLCID  */
    tLENGTHIS = 377,               /* tLENGTHIS  */
    tLIBRARY = 378,                /* tLIBRARY  */
    tLICENSED = 379,               /* tLICENSED  */
    tLOCAL = 380,                  /* tLOCAL  */
    tLONG = 381,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 382,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 383,                  /* tMAYBE  */
    tMESSAGE = 384,                /* tMESSAGE  */
    tMETHODS = 385,                /* tMETHODS  */
    tMODULE = 386,                 /* tMODULE  */
    tMTA = 387,                    /* tMTA  */
    tNAMESPACE = 388,              /* tNAMESPACE  */
    tNOCODE = 389,                 /* tNOCODE  */
    tNONBROWSABLE = 390,           /* tNONBROWSABLE  */
    tNONCREATABLE = 391,           /* tNONCREATABLE  */
    tNONE = 392,                   /* tNONE  */
    tNONEXTENSIBLE = 393,          /* tNONEXTENSIBLE  */
    tNOTIFY = 394,                 /* tNOTIFY  */
    tNOTIFYFLAG = 395,             /* tNOTIFYFLAG  */
    tNULL = 396,                   /* tNULL  */
    tOBJECT = 397,                 /* tOBJECT  */
    tODL = 398,                    /* tODL  */
    tOLEAUTOMATION = 399,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 400,               /* tOPTIMIZE  */
    tOPTIONAL = 401,               /* tOPTIONAL  */
    tOUT = 402,                    /* tOUT  */
    tOVERLOAD = 403,               /* tOVERLOAD  */
    tPARTIALIGNORE = 404,          /* tPARTIALIGNORE  */
    tPOINTERDEFAULT = 405,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 406,         /* tPRAGMA_WARNING  */
    tPROGID = 407,                 /* tPROGID  */
    tPROPERTIES = 408,             /* tPROPERTIES  */
    tPROPGET = 409,                /* tPROPGET  */
    tPROPPUT = 410,                /* tPROPPUT  */
    tPROPPUTREF = 411,             /* tPROPPUTREF  */
    tPROTECTED = 412,              /* tPROTECTED  */
    tPROXY = 413,                  /* tPROXY  */
    tPTR = 414,                    /* tPTR  */
    tPUBLIC = 415,                 /* tPUBLIC  */
    tRANGE = 416,                  /* tRANGE  */
    tREADONLY = 417,               /* tREADONLY  */
    tREF = 418,                    /* tREF  */
    tREGISTER = 419,               /* tREGISTER  */
    tREPRESENTAS = 420,            /* tREPRESENTAS  */
    tREQUESTEDIT = 421,            /* tREQUESTEDIT  */
    tREQUIRES = 422,               /* tREQUIRES  */
    tRESTRICTED = 423,             /* tRESTRICTED  */
    tRETVAL = 424,                 /* tRETVAL  */
    tRUNTIMECLASS = 425,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 426,              /* tSAFEARRAY  */
    tSHORT = 427,                  /* tSHORT  */
    tSIGNED = 428,                 /* tSIGNED  */
    tSINGLENODE = 429,             /* tSINGLENODE  */
    tSIZEIS = 430,                 /* tSIZEIS  */
    tSIZEOF = 431,                 /* tSIZEOF  */
    tSMALL = 432,                  /* tSMALL  */
    tSOURCE = 433,                 /* tSOURCE  */
    tSTANDARD = 434,               /* tSTANDARD  */
    tSTATIC = 435,                 /* tSTATIC  */
    tSTRICTCONTEXTHANDLE = 436,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 437,                 /* tSTRING  */
    tSTRUCT = 438,                 /* tSTRUCT  */
    tSWITCH = 439,                 /* tSWITCH  */
    tSWITCHIS = 440,               /* tSWITCHIS  */
    tSWITCHTYPE = 441,             /* tSWITCHTYPE  */
    tTHREADING = 442,              /* tTHREADING  */
    tTRANSMITAS = 443,             /* tTRANSMITAS  */
    tTRUE = 444,                   /* tTRUE  */
    tTYPEDEF = 445,                /* tTYPEDEF  */
    tUIDEFAULT = 446,              /* tUIDEFAULT  */
    tUNION = 447,                  /* tUNION  */
    tUNIQUE = 448,                 /* tUNIQUE  */
    tUNSIGNED = 449,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 450,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 451,            /* tUSERMARSHAL  */
    tUUID = 452,                   /* tUUID  */
    tV1ENUM = 453,                 /* tV1ENUM  */
    tVARARG = 454,                 /* tVARARG  */
    tVERSION = 455,                /* tVERSION  */
    tVIPROGID = 456,               /* tVIPROGID  */
    tVOID = 457,                   /* tVOID  */
    tWCHAR = 458,                  /* tWCHAR  */
    tWIREMARSHAL = 459,            /* tWIREMARSHAL  */
    tAPARTMENT = 460,              /* tAPARTMENT  */
    tNEUTRAL = 461,                /* tNEUTRAL  */
    tSINGLE = 462,                 /* tSINGLE  */
    tFREE = 463,                   /* tFREE  */
    tBOTH = 464,                   /* tBOTH  */
    CAST = 465,                    /* CAST  */
    PPTR = 466,                    /* PPTR  */
    POS = 467,                     /* POS  */
    NEG = 468,                     /* NEG  */
    ADDRESSOF = 469                /* ADDRESSOF  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 134 "tools/widl/parser.y"

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
	struct integer integer;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;
	struct namespace *namespace;

#line 325 "tools/widl/parser.tab.h"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined PARSER_LTYPE && ! defined PARSER_LTYPE_IS_DECLARED
typedef struct PARSER_LTYPE PARSER_LTYPE;
struct PARSER_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define PARSER_LTYPE_IS_DECLARED 1
# define PARSER_LTYPE_IS_TRIVIAL 1
#endif




int parser_parse (void);

/* "%code provides" blocks.  */
#line 117 "tools/widl/parser.y"


int parser_lex( PARSER_STYPE *yylval, PARSER_LTYPE *yylloc );
void push_import( const char *fname, PARSER_LTYPE *yylloc );
PARSER_LTYPE pop_import(void);

# define YYLLOC_DEFAULT( cur, rhs, n ) \
        do { if (n) init_location( &(cur), &YYRHSLOC( rhs, 1 ), &YYRHSLOC( rhs, n ) ); \
             else init_location( &(cur), &YYRHSLOC( rhs, 0 ), NULL ); } while(0)


#line 365 "tools/widl/parser.tab.h"

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
