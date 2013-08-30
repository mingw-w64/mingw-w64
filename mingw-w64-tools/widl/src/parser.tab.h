/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
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



/* Line 1685 of yacc.c  */
#line 264 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE parser_lval;


