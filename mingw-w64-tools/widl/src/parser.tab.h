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

#line 302 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
