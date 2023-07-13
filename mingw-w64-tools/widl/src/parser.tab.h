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
    tDEFAULTCOLLELEM = 322,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 323,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 324,          /* tDEFAULTVTABLE  */
    tDEPRECATED = 325,             /* tDEPRECATED  */
    tDISABLECONSISTENCYCHECK = 326, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 327,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 328,          /* tDISPINTERFACE  */
    tDLLNAME = 329,                /* tDLLNAME  */
    tDONTFREE = 330,               /* tDONTFREE  */
    tDOUBLE = 331,                 /* tDOUBLE  */
    tDUAL = 332,                   /* tDUAL  */
    tENABLEALLOCATE = 333,         /* tENABLEALLOCATE  */
    tENCODE = 334,                 /* tENCODE  */
    tENDPOINT = 335,               /* tENDPOINT  */
    tENTRY = 336,                  /* tENTRY  */
    tENUM = 337,                   /* tENUM  */
    tERRORSTATUST = 338,           /* tERRORSTATUST  */
    tEVENTADD = 339,               /* tEVENTADD  */
    tEVENTREMOVE = 340,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 341,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 342,         /* tEXPLICITHANDLE  */
    tEXTERN = 343,                 /* tEXTERN  */
    tFALSE = 344,                  /* tFALSE  */
    tFAULTSTATUS = 345,            /* tFAULTSTATUS  */
    tFLAGS = 346,                  /* tFLAGS  */
    tFLOAT = 347,                  /* tFLOAT  */
    tFORCEALLOCATE = 348,          /* tFORCEALLOCATE  */
    tHANDLE = 349,                 /* tHANDLE  */
    tHANDLET = 350,                /* tHANDLET  */
    tHELPCONTEXT = 351,            /* tHELPCONTEXT  */
    tHELPFILE = 352,               /* tHELPFILE  */
    tHELPSTRING = 353,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 354,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 355,          /* tHELPSTRINGDLL  */
    tHIDDEN = 356,                 /* tHIDDEN  */
    tHYPER = 357,                  /* tHYPER  */
    tID = 358,                     /* tID  */
    tIDEMPOTENT = 359,             /* tIDEMPOTENT  */
    tIGNORE = 360,                 /* tIGNORE  */
    tIIDIS = 361,                  /* tIIDIS  */
    tIMMEDIATEBIND = 362,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 363,         /* tIMPLICITHANDLE  */
    tIMPORT = 364,                 /* tIMPORT  */
    tIMPORTLIB = 365,              /* tIMPORTLIB  */
    tIN = 366,                     /* tIN  */
    tIN_LINE = 367,                /* tIN_LINE  */
    tINLINE = 368,                 /* tINLINE  */
    tINPUTSYNC = 369,              /* tINPUTSYNC  */
    tINT = 370,                    /* tINT  */
    tINT32 = 371,                  /* tINT32  */
    tINT3264 = 372,                /* tINT3264  */
    tINT64 = 373,                  /* tINT64  */
    tINTERFACE = 374,              /* tINTERFACE  */
    tLCID = 375,                   /* tLCID  */
    tLENGTHIS = 376,               /* tLENGTHIS  */
    tLIBRARY = 377,                /* tLIBRARY  */
    tLICENSED = 378,               /* tLICENSED  */
    tLOCAL = 379,                  /* tLOCAL  */
    tLONG = 380,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 381,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 382,                  /* tMAYBE  */
    tMESSAGE = 383,                /* tMESSAGE  */
    tMETHODS = 384,                /* tMETHODS  */
    tMODULE = 385,                 /* tMODULE  */
    tMTA = 386,                    /* tMTA  */
    tNAMESPACE = 387,              /* tNAMESPACE  */
    tNOCODE = 388,                 /* tNOCODE  */
    tNONBROWSABLE = 389,           /* tNONBROWSABLE  */
    tNONCREATABLE = 390,           /* tNONCREATABLE  */
    tNONE = 391,                   /* tNONE  */
    tNONEXTENSIBLE = 392,          /* tNONEXTENSIBLE  */
    tNOTIFY = 393,                 /* tNOTIFY  */
    tNOTIFYFLAG = 394,             /* tNOTIFYFLAG  */
    tNULL = 395,                   /* tNULL  */
    tOBJECT = 396,                 /* tOBJECT  */
    tODL = 397,                    /* tODL  */
    tOLEAUTOMATION = 398,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 399,               /* tOPTIMIZE  */
    tOPTIONAL = 400,               /* tOPTIONAL  */
    tOUT = 401,                    /* tOUT  */
    tOVERLOAD = 402,               /* tOVERLOAD  */
    tPARTIALIGNORE = 403,          /* tPARTIALIGNORE  */
    tPOINTERDEFAULT = 404,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 405,         /* tPRAGMA_WARNING  */
    tPROGID = 406,                 /* tPROGID  */
    tPROPERTIES = 407,             /* tPROPERTIES  */
    tPROPGET = 408,                /* tPROPGET  */
    tPROPPUT = 409,                /* tPROPPUT  */
    tPROPPUTREF = 410,             /* tPROPPUTREF  */
    tPROTECTED = 411,              /* tPROTECTED  */
    tPROXY = 412,                  /* tPROXY  */
    tPTR = 413,                    /* tPTR  */
    tPUBLIC = 414,                 /* tPUBLIC  */
    tRANGE = 415,                  /* tRANGE  */
    tREADONLY = 416,               /* tREADONLY  */
    tREF = 417,                    /* tREF  */
    tREGISTER = 418,               /* tREGISTER  */
    tREPRESENTAS = 419,            /* tREPRESENTAS  */
    tREQUESTEDIT = 420,            /* tREQUESTEDIT  */
    tREQUIRES = 421,               /* tREQUIRES  */
    tRESTRICTED = 422,             /* tRESTRICTED  */
    tRETVAL = 423,                 /* tRETVAL  */
    tRUNTIMECLASS = 424,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 425,              /* tSAFEARRAY  */
    tSHORT = 426,                  /* tSHORT  */
    tSIGNED = 427,                 /* tSIGNED  */
    tSINGLENODE = 428,             /* tSINGLENODE  */
    tSIZEIS = 429,                 /* tSIZEIS  */
    tSIZEOF = 430,                 /* tSIZEOF  */
    tSMALL = 431,                  /* tSMALL  */
    tSOURCE = 432,                 /* tSOURCE  */
    tSTANDARD = 433,               /* tSTANDARD  */
    tSTATIC = 434,                 /* tSTATIC  */
    tSTRICTCONTEXTHANDLE = 435,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 436,                 /* tSTRING  */
    tSTRUCT = 437,                 /* tSTRUCT  */
    tSWITCH = 438,                 /* tSWITCH  */
    tSWITCHIS = 439,               /* tSWITCHIS  */
    tSWITCHTYPE = 440,             /* tSWITCHTYPE  */
    tTHREADING = 441,              /* tTHREADING  */
    tTRANSMITAS = 442,             /* tTRANSMITAS  */
    tTRUE = 443,                   /* tTRUE  */
    tTYPEDEF = 444,                /* tTYPEDEF  */
    tUIDEFAULT = 445,              /* tUIDEFAULT  */
    tUNION = 446,                  /* tUNION  */
    tUNIQUE = 447,                 /* tUNIQUE  */
    tUNSIGNED = 448,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 449,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 450,            /* tUSERMARSHAL  */
    tUUID = 451,                   /* tUUID  */
    tV1ENUM = 452,                 /* tV1ENUM  */
    tVARARG = 453,                 /* tVARARG  */
    tVERSION = 454,                /* tVERSION  */
    tVIPROGID = 455,               /* tVIPROGID  */
    tVOID = 456,                   /* tVOID  */
    tWCHAR = 457,                  /* tWCHAR  */
    tWIREMARSHAL = 458,            /* tWIREMARSHAL  */
    tAPARTMENT = 459,              /* tAPARTMENT  */
    tNEUTRAL = 460,                /* tNEUTRAL  */
    tSINGLE = 461,                 /* tSINGLE  */
    tFREE = 462,                   /* tFREE  */
    tBOTH = 463,                   /* tBOTH  */
    CAST = 464,                    /* CAST  */
    PPTR = 465,                    /* PPTR  */
    POS = 466,                     /* POS  */
    NEG = 467,                     /* NEG  */
    ADDRESSOF = 468                /* ADDRESSOF  */
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
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;
	struct namespace *namespace;

#line 323 "tools/widl/parser.tab.h"

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
void pop_import( PARSER_LTYPE *yylloc );

# define YYLLOC_DEFAULT( cur, rhs, n ) \
        do { if (n) init_location( &(cur), &YYRHSLOC( rhs, 1 ), &YYRHSLOC( rhs, n ) ); \
             else init_location( &(cur), &YYRHSLOC( rhs, 0 ), NULL ); } while(0)


#line 363 "tools/widl/parser.tab.h"

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
