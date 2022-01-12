/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     kBINBG = 258,
     kBINED = 259,
     kBEGIN = 260,
     kEND = 261,
     kFUNC = 262,
     kNATIVE = 263,
     kCALL = 264,
     kWITH = 265,
     kFOR = 266,
     kFOREACH = 267,
     kTO = 268,
     kBY = 269,
     kSELF = 270,
     kINHERITED = 271,
     kIF = 272,
     kTRY = 273,
     kONEXCEPTION = 274,
     kLOOP = 275,
     kWHILE = 276,
     kREPEAT = 277,
     kUNTIL = 278,
     kDO = 279,
     kIN = 280,
     kGLOBAL = 281,
     kLOCAL = 282,
     kCONSTANT = 283,
     k3READER = 284,
     kERROR = 285,
     kSYMBOL = 286,
     kSTRING = 287,
     kREGEX = 288,
     kINTEGER = 289,
     kREAL = 290,
     kCHARACTER = 291,
     kSPECIAL = 292,
     kMAGICPOINTER = 293,
     kTRUE = 294,
     kNIL = 295,
     kUNBIND = 296,
     kEXPR2 = 297,
     kRETURN = 298,
     kBREAK = 299,
     kTHEN = 300,
     kELSE = 301,
     kASNOP = 302,
     kOROP = 303,
     kANDOP = 304,
     kNOTOP = 305,
     kRELOP = 306,
     kEXISTS = 307,
     kSTROP = 308,
     kADDOP = 309,
     kMULOP = 310,
     kSFTOP = 311,
     kUMINUS = 312,
     kSNDOP = 313
   };
#endif
/* Tokens.  */
#define kBINBG 258
#define kBINED 259
#define kBEGIN 260
#define kEND 261
#define kFUNC 262
#define kNATIVE 263
#define kCALL 264
#define kWITH 265
#define kFOR 266
#define kFOREACH 267
#define kTO 268
#define kBY 269
#define kSELF 270
#define kINHERITED 271
#define kIF 272
#define kTRY 273
#define kONEXCEPTION 274
#define kLOOP 275
#define kWHILE 276
#define kREPEAT 277
#define kUNTIL 278
#define kDO 279
#define kIN 280
#define kGLOBAL 281
#define kLOCAL 282
#define kCONSTANT 283
#define k3READER 284
#define kERROR 285
#define kSYMBOL 286
#define kSTRING 287
#define kREGEX 288
#define kINTEGER 289
#define kREAL 290
#define kCHARACTER 291
#define kSPECIAL 292
#define kMAGICPOINTER 293
#define kTRUE 294
#define kNIL 295
#define kUNBIND 296
#define kEXPR2 297
#define kRETURN 298
#define kBREAK 299
#define kTHEN 300
#define kELSE 301
#define kASNOP 302
#define kOROP 303
#define kANDOP 304
#define kNOTOP 305
#define kRELOP 306
#define kEXISTS 307
#define kSTROP 308
#define kADDOP 309
#define kMULOP 310
#define kSFTOP 311
#define kUMINUS 312
#define kSNDOP 313




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "src/parser/newt.y"
{
    newtRefVar	obj;	// オブジェクト
    uint32_t	op;		// 演算子
    nps_node_t	node;	// ノード
}
/* Line 1529 of yacc.c.  */
#line 171 "/Users/matt/dev/newt64.github/build/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

