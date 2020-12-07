/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
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

#line 289 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
