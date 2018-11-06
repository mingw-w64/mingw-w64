/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_PARSER_PARSER_TAB_H_INCLUDED
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
#line 140 "parser.y" /* yacc.c:1910  */

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

#line 270 "parser.tab.h" /* yacc.c:1910  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_PARSER_TAB_H_INCLUDED  */
