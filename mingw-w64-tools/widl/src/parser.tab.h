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
    tAGILE = 281,                  /* tAGILE  */
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
    tEVENTADD = 331,               /* tEVENTADD  */
    tEVENTREMOVE = 332,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 333,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 334,         /* tEXPLICITHANDLE  */
    tEXTERN = 335,                 /* tEXTERN  */
    tFALSE = 336,                  /* tFALSE  */
    tFASTCALL = 337,               /* tFASTCALL  */
    tFAULTSTATUS = 338,            /* tFAULTSTATUS  */
    tFLAGS = 339,                  /* tFLAGS  */
    tFLOAT = 340,                  /* tFLOAT  */
    tFORCEALLOCATE = 341,          /* tFORCEALLOCATE  */
    tHANDLE = 342,                 /* tHANDLE  */
    tHANDLET = 343,                /* tHANDLET  */
    tHELPCONTEXT = 344,            /* tHELPCONTEXT  */
    tHELPFILE = 345,               /* tHELPFILE  */
    tHELPSTRING = 346,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 347,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 348,          /* tHELPSTRINGDLL  */
    tHIDDEN = 349,                 /* tHIDDEN  */
    tHYPER = 350,                  /* tHYPER  */
    tID = 351,                     /* tID  */
    tIDEMPOTENT = 352,             /* tIDEMPOTENT  */
    tIGNORE = 353,                 /* tIGNORE  */
    tIIDIS = 354,                  /* tIIDIS  */
    tIMMEDIATEBIND = 355,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 356,         /* tIMPLICITHANDLE  */
    tIMPORT = 357,                 /* tIMPORT  */
    tIMPORTLIB = 358,              /* tIMPORTLIB  */
    tIN = 359,                     /* tIN  */
    tIN_LINE = 360,                /* tIN_LINE  */
    tINLINE = 361,                 /* tINLINE  */
    tINPUTSYNC = 362,              /* tINPUTSYNC  */
    tINT = 363,                    /* tINT  */
    tINT32 = 364,                  /* tINT32  */
    tINT3264 = 365,                /* tINT3264  */
    tINT64 = 366,                  /* tINT64  */
    tINTERFACE = 367,              /* tINTERFACE  */
    tLCID = 368,                   /* tLCID  */
    tLENGTHIS = 369,               /* tLENGTHIS  */
    tLIBRARY = 370,                /* tLIBRARY  */
    tLICENSED = 371,               /* tLICENSED  */
    tLOCAL = 372,                  /* tLOCAL  */
    tLONG = 373,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 374,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 375,                  /* tMAYBE  */
    tMESSAGE = 376,                /* tMESSAGE  */
    tMETHODS = 377,                /* tMETHODS  */
    tMODULE = 378,                 /* tMODULE  */
    tMTA = 379,                    /* tMTA  */
    tNAMESPACE = 380,              /* tNAMESPACE  */
    tNOCODE = 381,                 /* tNOCODE  */
    tNONBROWSABLE = 382,           /* tNONBROWSABLE  */
    tNONCREATABLE = 383,           /* tNONCREATABLE  */
    tNONE = 384,                   /* tNONE  */
    tNONEXTENSIBLE = 385,          /* tNONEXTENSIBLE  */
    tNOTIFY = 386,                 /* tNOTIFY  */
    tNOTIFYFLAG = 387,             /* tNOTIFYFLAG  */
    tNULL = 388,                   /* tNULL  */
    tOBJECT = 389,                 /* tOBJECT  */
    tODL = 390,                    /* tODL  */
    tOLEAUTOMATION = 391,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 392,               /* tOPTIMIZE  */
    tOPTIONAL = 393,               /* tOPTIONAL  */
    tOUT = 394,                    /* tOUT  */
    tPARTIALIGNORE = 395,          /* tPARTIALIGNORE  */
    tPASCAL = 396,                 /* tPASCAL  */
    tPOINTERDEFAULT = 397,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 398,         /* tPRAGMA_WARNING  */
    tPROGID = 399,                 /* tPROGID  */
    tPROPERTIES = 400,             /* tPROPERTIES  */
    tPROPGET = 401,                /* tPROPGET  */
    tPROPPUT = 402,                /* tPROPPUT  */
    tPROPPUTREF = 403,             /* tPROPPUTREF  */
    tPROXY = 404,                  /* tPROXY  */
    tPTR = 405,                    /* tPTR  */
    tPUBLIC = 406,                 /* tPUBLIC  */
    tRANGE = 407,                  /* tRANGE  */
    tREADONLY = 408,               /* tREADONLY  */
    tREF = 409,                    /* tREF  */
    tREGISTER = 410,               /* tREGISTER  */
    tREPRESENTAS = 411,            /* tREPRESENTAS  */
    tREQUESTEDIT = 412,            /* tREQUESTEDIT  */
    tRESTRICTED = 413,             /* tRESTRICTED  */
    tRETVAL = 414,                 /* tRETVAL  */
    tRUNTIMECLASS = 415,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 416,              /* tSAFEARRAY  */
    tSHORT = 417,                  /* tSHORT  */
    tSIGNED = 418,                 /* tSIGNED  */
    tSINGLENODE = 419,             /* tSINGLENODE  */
    tSIZEIS = 420,                 /* tSIZEIS  */
    tSIZEOF = 421,                 /* tSIZEOF  */
    tSMALL = 422,                  /* tSMALL  */
    tSOURCE = 423,                 /* tSOURCE  */
    tSTANDARD = 424,               /* tSTANDARD  */
    tSTATIC = 425,                 /* tSTATIC  */
    tSTDCALL = 426,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 427,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 428,                 /* tSTRING  */
    tSTRUCT = 429,                 /* tSTRUCT  */
    tSWITCH = 430,                 /* tSWITCH  */
    tSWITCHIS = 431,               /* tSWITCHIS  */
    tSWITCHTYPE = 432,             /* tSWITCHTYPE  */
    tTHREADING = 433,              /* tTHREADING  */
    tTRANSMITAS = 434,             /* tTRANSMITAS  */
    tTRUE = 435,                   /* tTRUE  */
    tTYPEDEF = 436,                /* tTYPEDEF  */
    tUIDEFAULT = 437,              /* tUIDEFAULT  */
    tUNION = 438,                  /* tUNION  */
    tUNIQUE = 439,                 /* tUNIQUE  */
    tUNSIGNED = 440,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 441,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 442,            /* tUSERMARSHAL  */
    tUUID = 443,                   /* tUUID  */
    tV1ENUM = 444,                 /* tV1ENUM  */
    tVARARG = 445,                 /* tVARARG  */
    tVERSION = 446,                /* tVERSION  */
    tVIPROGID = 447,               /* tVIPROGID  */
    tVOID = 448,                   /* tVOID  */
    tWCHAR = 449,                  /* tWCHAR  */
    tWIREMARSHAL = 450,            /* tWIREMARSHAL  */
    tAPARTMENT = 451,              /* tAPARTMENT  */
    tNEUTRAL = 452,                /* tNEUTRAL  */
    tSINGLE = 453,                 /* tSINGLE  */
    tFREE = 454,                   /* tFREE  */
    tBOTH = 455,                   /* tBOTH  */
    CAST = 456,                    /* CAST  */
    PPTR = 457,                    /* PPTR  */
    POS = 458,                     /* POS  */
    NEG = 459,                     /* NEG  */
    ADDRESSOF = 460                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
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
	struct namespace *namespace;

#line 299 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
