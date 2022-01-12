/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 12 "src/parser/newt.y"


/* ヘッダファイル */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "yacc.h"

#include "NewtCore.h"
#include "NewtParser.h"


/* マクロ */
#define SYMCHECK(v, sym)	if (v != sym) NPSError(kNErrSyntaxError);
#define TYPECHECK(v)		if (! (v == NS_INT || v == NSSYM0(array))) NPSError(kNErrSyntaxError);
#define ERR_NOS2C(msg)		if (NEWT_MODE_NOS2) yyerror(msg);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "src/parser/newt.y"
{
    newtRefVar	obj;	// オブジェクト
    uint32_t	op;		// 演算子
    nps_node_t	node;	// ノード
}
/* Line 193 of yacc.c.  */
#line 239 "/Users/matt/dev/newt64.github/build/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 252 "/Users/matt/dev/newt64.github/build/y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  118
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   661

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  299

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      64,    65,     2,     2,    45,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    66,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    69,     2,     2,     2,     2,
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
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    15,    19,    21,
      23,    25,    27,    29,    31,    33,    37,    41,    43,    45,
      47,    49,    51,    53,    56,    60,    62,    65,    67,    70,
      72,    74,    76,    80,    84,    88,    92,    96,   100,   104,
     107,   110,   114,   116,   120,   121,   123,   126,   130,   134,
     137,   139,   141,   143,   145,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   182,   186,   192,   196,   197,   199,   202,   206,   210,
     211,   215,   218,   224,   230,   234,   235,   237,   241,   247,
     253,   257,   261,   268,   271,   273,   274,   276,   279,   283,
     284,   286,   289,   293,   297,   298,   300,   301,   303,   307,
     309,   313,   315,   318,   321,   323,   327,   333,   338,   341,
     344,   348,   353,   358,   365,   366,   368,   372,   378,   384,
     391,   398,   405,   412,   417,   424,   427,   437,   445,   455,
     460,   465,   466,   469,   471,   473,   474,   476,   478,   481,
     486,   489,   493,   495,   499,   501,   505,   507,   511,   515,
     518,   520,   523,   526
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    72,    -1,    -1,    73,    -1,    72,    66,
      -1,    72,    66,    73,    -1,    72,     1,    66,    -1,    74,
      -1,   118,    -1,    76,    -1,    77,    -1,    80,    -1,    90,
      -1,    75,    -1,    75,    48,    74,    -1,    38,    48,    74,
      -1,   102,    -1,   103,    -1,   105,    -1,   106,    -1,   107,
      -1,    44,    -1,    44,    74,    -1,    18,    78,   111,    -1,
     113,    -1,    28,   116,    -1,    43,    -1,    43,    74,    -1,
      31,    -1,   100,    -1,   101,    -1,    74,    55,    74,    -1,
      74,    56,    74,    -1,    74,    57,    74,    -1,    74,    52,
      74,    -1,    74,    50,    74,    -1,    74,    49,    74,    -1,
      74,    54,    74,    -1,    55,    74,    -1,    51,    74,    -1,
      64,    74,    65,    -1,    15,    -1,     5,    78,     6,    -1,
      -1,    74,    -1,    78,    66,    -1,    78,    66,    74,    -1,
      78,     1,    66,    -1,    79,    32,    -1,    32,    -1,    81,
      -1,    79,    -1,    88,    -1,    67,    82,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
      40,    -1,    41,    -1,    81,    -1,    79,    -1,    31,    -1,
      83,    -1,    84,    -1,    86,    -1,    88,    -1,    31,    63,
      31,    -1,    31,    63,    83,    -1,    59,    31,    61,    85,
      60,    -1,    59,    85,    60,    -1,    -1,    82,    -1,    85,
      45,    -1,    85,    45,    82,    -1,    68,    87,    69,    -1,
      -1,    31,    61,    82,    -1,    87,    45,    -1,    87,    45,
      31,    61,    82,    -1,     3,    31,    61,    89,     4,    -1,
       3,    89,     4,    -1,    -1,    82,    -1,    89,    45,    82,
      -1,    59,    31,    61,    91,    60,    -1,    59,    34,    61,
      91,    60,    -1,    59,    91,    60,    -1,    68,    92,    69,
      -1,     7,    94,    64,    95,    65,    74,    -1,    33,    79,
      -1,    33,    -1,    -1,    74,    -1,    91,    45,    -1,    91,
      45,    74,    -1,    -1,    93,    -1,    92,    45,    -1,    92,
      45,    93,    -1,    31,    61,    74,    -1,    -1,     8,    -1,
      -1,    96,    -1,    96,    45,    98,    -1,    97,    -1,    96,
      45,    97,    -1,    31,    -1,    99,    31,    -1,    31,    29,
      -1,    31,    -1,    74,    63,    31,    -1,    74,    63,    64,
      74,    65,    -1,    74,    59,    74,    60,    -1,    31,    53,
      -1,   100,    53,    -1,    61,    31,    53,    -1,    74,    61,
      31,    53,    -1,    31,    64,   104,    65,    -1,     9,    74,
      10,    64,   104,    65,    -1,    -1,    74,    -1,   104,    45,
      74,    -1,    61,    31,    64,   104,    65,    -1,    62,    31,
      64,   104,    65,    -1,    74,    61,    31,    64,   104,    65,
      -1,    74,    62,    31,    64,   104,    65,    -1,    16,    61,
      31,    64,   104,    65,    -1,    16,    62,    31,    64,   104,
      65,    -1,    17,    74,    46,    74,    -1,    17,    74,    46,
      74,    47,    74,    -1,    20,    74,    -1,    11,    31,    48,
      74,    13,    74,   108,    24,    74,    -1,    12,    31,   110,
      25,    74,   109,    74,    -1,    12,    31,    45,    31,   110,
      25,    74,   109,    74,    -1,    21,    74,    24,    74,    -1,
      22,    78,    23,    74,    -1,    -1,    14,    74,    -1,    24,
      -1,    31,    -1,    -1,    31,    -1,   112,    -1,   111,   112,
      -1,    19,    31,    24,    74,    -1,    27,   114,    -1,    27,
      31,   114,    -1,   115,    -1,   114,    45,   115,    -1,    31,
      -1,    31,    48,    74,    -1,   117,    -1,   116,    45,   117,
      -1,    31,    48,    74,    -1,    26,   115,    -1,   119,    -1,
      26,   120,    -1,     7,   120,    -1,    31,    64,    95,    65,
      74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   167,   168,   169,   171,   173,   177,   178,
     182,   183,   184,   185,   186,   187,   188,   192,   193,   194,
     195,   196,   199,   200,   203,   206,   207,   210,   211,   215,
     216,   217,   222,   223,   224,   225,   226,   227,   228,   231,
     246,   248,   249,   253,   257,   258,   259,   261,   263,   266,
     272,   276,   277,   278,   282,   287,   288,   289,   290,   291,
     292,   293,   294,   302,   303,   304,   305,   306,   307,   308,
     312,   313,   317,   318,   322,   323,   324,   325,   329,   333,
     334,   335,   336,   341,   342,   346,   347,   348,   353,   357,
     358,   361,   364,   368,   369,   373,   374,   375,   376,   381,
     382,   383,   384,   389,   392,   394,   398,   399,   400,   405,
     406,   411,   412,   416,   423,   427,   428,   432,   436,   437,
     438,   439,   443,   444,   449,   450,   451,   455,   457,   460,
     462,   465,   467,   472,   473,   478,   479,   481,   483,   485,
     486,   490,   491,   495,   496,   500,   501,   505,   511,   515,
     519,   520,   533,   535,   540,   541,   545,   546,   551,   555,
     556,   560,   561,   565
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "kBINBG", "kBINED", "kBEGIN", "kEND",
  "kFUNC", "kNATIVE", "kCALL", "kWITH", "kFOR", "kFOREACH", "kTO", "kBY",
  "kSELF", "kINHERITED", "kIF", "kTRY", "kONEXCEPTION", "kLOOP", "kWHILE",
  "kREPEAT", "kUNTIL", "kDO", "kIN", "kGLOBAL", "kLOCAL", "kCONSTANT",
  "k3READER", "kERROR", "kSYMBOL", "kSTRING", "kREGEX", "kINTEGER",
  "kREAL", "kCHARACTER", "kSPECIAL", "kMAGICPOINTER", "kTRUE", "kNIL",
  "kUNBIND", "kEXPR2", "kRETURN", "kBREAK", "','", "kTHEN", "kELSE",
  "kASNOP", "kOROP", "kANDOP", "kNOTOP", "kRELOP", "kEXISTS", "kSTROP",
  "kADDOP", "kMULOP", "kSFTOP", "kUMINUS", "'['", "']'", "':'", "kSNDOP",
  "'.'", "'('", "')'", "';'", "'''", "'{'", "'}'", "$accept", "input",
  "constituent_list", "constituent", "expr", "lvalue", "simple_expr",
  "compound_expr", "expr_sequence", "string", "literal", "simple_literal",
  "object", "path_expr", "array", "array_item_list", "frame",
  "frame_slot_list", "binary", "binary_item_list", "constructor",
  "expr_list", "frame_constructor_list", "frame_slot_value",
  "func_keyword", "formal_argument_list", "formal_argument_list2",
  "formal_argument", "indefinite_argument", "type", "frame_accessor",
  "array_accessor", "exists_expr", "function_call", "actual_argument_list",
  "message_send", "if_expr", "iteration", "by_expr", "foreach_operator",
  "deeply", "onexcp_list", "onexcp", "local_declaration",
  "l_init_clause_list", "init_clause", "c_init_clause_list",
  "c_init_clause", "global_declaration", "global_function_decl",
  "function_decl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    91,
      93,    58,   313,    46,    40,    41,    59,    39,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    87,
      87,    87,    87,    88,    88,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    92,
      92,    92,    92,    93,    94,    94,    95,    95,    95,    96,
      96,    97,    97,    98,    99,   100,   100,   101,   102,   102,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   117,   118,
     118,   119,   119,   120
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     2,     1,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     1,     3,     0,     1,     2,     3,     3,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     5,     3,     0,     1,     2,     3,     3,     0,
       3,     2,     5,     5,     3,     0,     1,     3,     5,     5,
       3,     3,     6,     2,     1,     0,     1,     2,     3,     0,
       1,     2,     3,     3,     0,     1,     0,     1,     3,     1,
       3,     1,     2,     2,     1,     3,     5,     4,     2,     2,
       3,     4,     4,     6,     0,     1,     3,     5,     5,     6,
       6,     6,     6,     4,     6,     2,     9,     7,     9,     4,
       4,     0,     2,     1,     1,     0,     1,     1,     2,     4,
       2,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       1,     2,     2,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    85,    44,   104,     0,     0,     0,    42,     0,     0,
      44,     0,     0,    44,     0,     0,     0,    29,    50,    94,
      55,    56,    57,    58,    59,    60,    61,    62,    27,    22,
       0,     0,    95,     0,     0,     0,     0,    99,     0,     0,
       4,     8,    14,    10,    11,    52,    12,    51,    53,    13,
      30,    31,    17,    18,    19,    20,    21,    25,     9,   160,
      65,    59,    74,    79,    64,    63,    86,    66,    67,    68,
      69,     0,   104,    45,     0,   105,     0,     0,   162,     0,
       0,   145,     0,     0,     0,     0,   135,     0,     0,   154,
     159,   161,   154,   150,   152,     0,    26,   156,   118,   124,
      93,     0,    28,    23,    40,    39,    29,    55,    96,     0,
       0,     0,     0,    65,    54,     0,     0,   100,     1,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,   119,    85,     0,    65,    75,     0,
       0,     0,    84,     0,     0,    43,    46,   106,   106,     0,
       0,   146,     0,     0,     0,     0,     0,     0,    24,   147,
       0,     0,     0,   154,   151,     0,     0,     0,   125,     0,
      16,    95,    95,    97,    90,   120,   124,   124,    41,     0,
     101,    91,     7,     6,    37,    36,    35,    38,    32,    33,
      34,     0,     0,     0,   115,     0,    15,     0,    70,    71,
      74,    76,    73,     0,    81,    78,    87,    48,    47,   111,
       0,   107,   109,     0,     0,   124,     0,   145,     0,   124,
     124,   133,     0,   148,   139,   140,   155,   153,   158,   157,
       0,   122,     0,     0,    98,     0,     0,   103,   102,   117,
     121,   124,   124,     0,    83,     0,    77,    80,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,    88,    89,   127,   128,     0,     0,   116,    72,
       0,   163,   111,   110,   108,    92,   123,   141,     0,   143,
     144,     0,   131,   132,   134,   149,   129,   130,    82,   113,
       0,     0,     0,   137,   142,     0,     0,   136,   138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    40,   168,    42,    43,    44,    74,    45,
      46,    47,    66,    67,    68,   139,    69,   141,    48,    71,
      49,   109,   116,   117,    77,   210,   211,   212,   274,   213,
      50,    51,    52,    53,   169,    54,    55,    56,   291,   281,
     153,   158,   159,    57,    93,    94,    96,    97,    58,    59,
      78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -163
static const yytype_int16 yypact[] =
{
     282,    51,   348,    19,   348,     8,    15,  -163,   149,   348,
     348,   348,   348,   348,    34,    38,   113,   -19,  -163,    49,
    -163,  -163,  -163,  -163,    87,  -163,  -163,  -163,   348,   348,
     348,   348,   414,   117,   124,   348,   205,   127,   174,     5,
    -163,   586,   122,  -163,  -163,   156,  -163,  -163,  -163,  -163,
     128,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
       9,  -163,   453,   162,   156,  -163,  -163,  -163,  -163,  -163,
    -163,    14,   192,   586,    18,  -163,   140,   148,  -163,    50,
     165,   102,   183,   184,   507,     7,   586,   489,    32,     3,
    -163,  -163,   175,   180,  -163,   190,   187,  -163,  -163,   348,
     156,   348,   586,   586,   598,    77,   104,   159,   586,    17,
      89,   186,   522,   185,  -163,   194,   -25,  -163,  -163,   181,
     282,   348,   348,   348,   348,   348,   348,   348,   348,   220,
     222,   -15,   348,  -163,  -163,   205,   226,   106,  -163,    48,
     197,   -22,  -163,   205,   195,  -163,   348,   235,   235,   207,
     348,  -163,   239,   249,   211,   213,   348,   248,   261,  -163,
     348,   348,   348,   175,   180,   251,   348,   113,   586,    -9,
     586,   348,   348,   348,  -163,  -163,   348,   348,  -163,   348,
     127,  -163,  -163,  -163,   598,   598,   121,   135,   206,   273,
      77,   571,    90,   219,  -163,   348,   586,    21,   185,  -163,
     205,   205,  -163,   205,   253,  -163,  -163,  -163,   586,   257,
     227,   256,  -163,   274,   241,   348,   172,   276,   348,   348,
     348,   539,   287,  -163,   586,   586,   586,  -163,   586,  -163,
     348,  -163,    58,    70,   586,    -4,    -2,   586,  -163,  -163,
    -163,   348,   348,   554,  -163,    71,  -163,  -163,   263,   348,
     281,  -163,   348,    29,   348,   302,   473,    30,    31,   348,
     348,   586,  -163,  -163,  -163,  -163,    52,    69,  -163,  -163,
     205,   586,   170,  -163,  -163,   586,  -163,   446,   348,  -163,
    -163,   348,  -163,  -163,   586,   586,  -163,  -163,  -163,  -163,
     348,   304,   473,   586,   586,   348,   348,   586,   586
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   209,     0,  -163,  -163,  -163,    27,     2,
    -163,     6,   -14,   202,  -163,   131,  -163,  -163,    16,   204,
    -163,    -8,  -163,   160,  -163,   199,  -163,    92,  -163,  -163,
    -163,  -163,  -163,  -163,  -162,  -163,  -163,  -163,  -163,    53,
     137,  -163,   198,  -163,   260,   -13,  -163,   191,  -163,  -163,
     334
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -115
static const yytype_int16 yytable[] =
{
      41,    90,    73,    64,    79,    -2,   119,    65,   144,    84,
      73,    86,    87,    73,   235,   236,   194,    70,   142,   144,
     180,   100,   114,   204,   145,   244,   157,    75,   102,   103,
     104,   105,   108,   144,    98,   112,   230,    85,    64,    80,
      88,   230,    65,   230,   181,    99,    81,   205,   138,   195,
      76,   162,    70,   253,     1,   161,   231,   257,   258,   143,
     149,   264,   173,   265,    64,    89,   143,   147,    65,    92,
     135,   120,   136,   146,   230,   230,   230,   174,    70,   266,
     267,    18,    60,    18,   146,    20,    21,    22,    23,    61,
      25,    26,    27,   201,   276,   282,   283,   230,   146,   121,
     122,   170,   123,   173,   124,   125,   126,   127,   202,   128,
      62,   129,   130,   131,   230,   173,   201,   286,   262,    63,
      41,   184,   185,   186,   187,   188,   189,   190,   191,   206,
     263,   269,   196,   151,   287,   101,   128,    64,   129,   130,
     131,    65,   175,   240,    95,    64,   208,   152,   110,    65,
     216,    70,   227,   176,   241,   111,   221,    98,   115,    70,
     224,   225,   226,   232,   233,   171,   228,   200,    99,   136,
     132,   108,   108,   234,   118,   124,   125,   126,   127,   237,
     128,   134,   129,   130,   131,   254,   138,   246,   133,   247,
     125,   126,   127,   140,   128,   243,   129,   130,   131,   289,
      75,  -114,    64,    64,   147,    64,    65,    65,     1,    65,
      82,    83,   148,   150,   154,   155,    70,    70,   256,    70,
     172,   121,   122,   162,   123,   165,   124,   125,   126,   127,
     261,   128,   167,   129,   130,   131,   113,    18,   166,    20,
      21,    22,    23,    61,    25,    26,    27,   182,   136,   271,
     177,   192,   275,   193,   277,   179,   288,   198,   203,   284,
     285,   207,   126,   127,    62,   128,   209,   129,   130,   131,
     217,   215,    64,    63,   218,   219,    65,   220,   292,   222,
     157,   293,   163,   242,   248,     1,    70,     2,  -114,     3,
     294,     4,   249,     5,     6,   297,   298,     7,     8,     9,
      10,   250,    11,    12,    13,   251,   252,   151,    14,    15,
      16,   260,   272,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   270,    28,    29,   278,   295,   183,
     127,   245,   128,    30,   129,   130,   131,    31,   199,   197,
     238,    32,   273,    33,    34,   296,    35,   214,    91,    36,
      37,     1,   164,     2,   255,    72,   223,     4,   229,     5,
       6,     0,     0,     7,     8,     9,    10,     0,    11,    12,
      13,     0,     0,     0,     0,    15,    16,     0,     0,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,    31,     0,     0,     0,    32,     0,    33,
      34,     0,    35,     0,     0,    36,    37,     1,     0,     2,
       0,    72,     0,     4,     0,     5,     6,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,     0,     0,     0,
       0,    15,    16,     0,     0,   106,    18,    19,   107,    21,
      22,    23,    24,    25,    26,    27,     1,    28,    29,     0,
     290,     0,     0,     0,     0,    30,     0,     0,     0,    31,
       0,     0,     0,    32,     0,    33,    34,     0,    35,     0,
       0,    36,    37,     0,   137,    18,     0,    20,    21,    22,
      23,    61,    25,    26,    27,   121,   122,   279,   123,     0,
     124,   125,   126,   127,   280,   128,     0,   129,   130,   131,
       0,     0,    62,   160,     0,     0,     0,     0,     0,     0,
       0,    63,   121,   122,     0,   123,     0,   124,   125,   126,
     127,     0,   128,     0,   129,   130,   131,     0,   121,   122,
       0,   123,     0,   124,   125,   126,   127,     0,   128,     0,
     129,   130,   131,   156,     0,     0,   121,   122,     0,   123,
       0,   124,   125,   126,   127,     0,   128,     0,   129,   130,
     131,   121,   122,     0,   123,     0,   124,   125,   126,   127,
       0,   128,     0,   129,   130,   131,   259,   178,   121,   122,
       0,   123,     0,   124,   125,   126,   127,     0,   128,     0,
     129,   130,   131,   121,   122,     0,   123,     0,   124,   125,
     126,   127,     0,   128,     0,   129,   130,   131,     0,   268,
     121,   122,     0,   123,     0,   124,   125,   126,   127,     0,
     128,   239,   129,   130,   131,   121,   122,     0,   123,     0,
     124,   125,   126,   127,     0,   128,     0,   129,   130,   131,
     123,     0,   124,   125,   126,   127,     0,   128,     0,   129,
     130,   131
};

static const yytype_int16 yycheck[] =
{
       0,    14,     2,     1,     4,     0,     1,     1,     1,     9,
      10,    11,    12,    13,   176,   177,    31,     1,     4,     1,
      45,    19,    36,    45,     6,     4,    19,     8,    28,    29,
      30,    31,    32,     1,    53,    35,    45,    10,    36,    31,
      13,    45,    36,    45,    69,    64,    31,    69,    62,    64,
      31,    48,    36,   215,     3,    23,    65,   219,   220,    45,
      10,    65,    45,    65,    62,    31,    45,    64,    62,    31,
      61,    66,    63,    66,    45,    45,    45,    60,    62,   241,
     242,    32,    31,    32,    66,    34,    35,    36,    37,    38,
      39,    40,    41,    45,    65,    65,    65,    45,    66,    49,
      50,   101,    52,    45,    54,    55,    56,    57,    60,    59,
      59,    61,    62,    63,    45,    45,    45,    65,    60,    68,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   143,
      60,    60,   132,    31,    65,    48,    59,   135,    61,    62,
      63,   135,    53,    53,    31,   143,   146,    45,    31,   143,
     150,   135,   165,    64,    64,    31,   156,    53,    31,   143,
     160,   161,   162,   171,   172,    61,   166,    61,    64,    63,
      48,   171,   172,   173,     0,    54,    55,    56,    57,   179,
      59,    53,    61,    62,    63,    13,   200,   201,    32,   203,
      55,    56,    57,    31,    59,   195,    61,    62,    63,    29,
       8,    31,   200,   201,    64,   203,   200,   201,     3,   203,
      61,    62,    64,    48,    31,    31,   200,   201,   218,   203,
      61,    49,    50,    48,    52,    45,    54,    55,    56,    57,
     230,    59,    45,    61,    62,    63,    31,    32,    48,    34,
      35,    36,    37,    38,    39,    40,    41,    66,    63,   249,
      64,    31,   252,    31,   254,    61,   270,    31,    61,   259,
     260,    66,    56,    57,    59,    59,    31,    61,    62,    63,
      31,    64,   270,    68,    25,    64,   270,    64,   278,    31,
      19,   281,    31,    64,    31,     3,   270,     5,    31,     7,
     290,     9,    65,    11,    12,   295,   296,    15,    16,    17,
      18,    45,    20,    21,    22,    31,    65,    31,    26,    27,
      28,    24,    31,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    61,    43,    44,    25,    24,   120,
      57,   200,    59,    51,    61,    62,    63,    55,   136,   135,
     180,    59,   250,    61,    62,   292,    64,   148,    14,    67,
      68,     3,    92,     5,   217,     7,   158,     9,   167,    11,
      12,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    59,    -1,    61,
      62,    -1,    64,    -1,    -1,    67,    68,     3,    -1,     5,
      -1,     7,    -1,     9,    -1,    11,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     3,    43,    44,    -1,
      14,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    59,    -1,    61,    62,    -1,    64,    -1,
      -1,    67,    68,    -1,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    49,    50,    24,    52,    -1,
      54,    55,    56,    57,    31,    59,    -1,    61,    62,    63,
      -1,    -1,    59,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    49,    50,    -1,    52,    -1,    54,    55,    56,
      57,    -1,    59,    -1,    61,    62,    63,    -1,    49,    50,
      -1,    52,    -1,    54,    55,    56,    57,    -1,    59,    -1,
      61,    62,    63,    46,    -1,    -1,    49,    50,    -1,    52,
      -1,    54,    55,    56,    57,    -1,    59,    -1,    61,    62,
      63,    49,    50,    -1,    52,    -1,    54,    55,    56,    57,
      -1,    59,    -1,    61,    62,    63,    47,    65,    49,    50,
      -1,    52,    -1,    54,    55,    56,    57,    -1,    59,    -1,
      61,    62,    63,    49,    50,    -1,    52,    -1,    54,    55,
      56,    57,    -1,    59,    -1,    61,    62,    63,    -1,    65,
      49,    50,    -1,    52,    -1,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    49,    50,    -1,    52,    -1,
      54,    55,    56,    57,    -1,    59,    -1,    61,    62,    63,
      52,    -1,    54,    55,    56,    57,    -1,    59,    -1,    61,
      62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,     9,    11,    12,    15,    16,    17,
      18,    20,    21,    22,    26,    27,    28,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    43,    44,
      51,    55,    59,    61,    62,    64,    67,    68,    71,    72,
      73,    74,    75,    76,    77,    79,    80,    81,    88,    90,
     100,   101,   102,   103,   105,   106,   107,   113,   118,   119,
      31,    38,    59,    68,    79,    81,    82,    83,    84,    86,
      88,    89,     7,    74,    78,     8,    31,    94,   120,    74,
      31,    31,    61,    62,    74,    78,    74,    74,    78,    31,
     115,   120,    31,   114,   115,    31,   116,   117,    53,    64,
      79,    48,    74,    74,    74,    74,    31,    34,    74,    91,
      31,    31,    74,    31,    82,    31,    92,    93,     0,     1,
      66,    49,    50,    52,    54,    55,    56,    57,    59,    61,
      62,    63,    48,    32,    53,    61,    63,    31,    82,    85,
      31,    87,     4,    45,     1,     6,    66,    64,    64,    10,
      48,    31,    45,   110,    31,    31,    46,    19,   111,   112,
      24,    23,    48,    31,   114,    45,    48,    45,    74,   104,
      74,    61,    61,    45,    60,    53,    64,    64,    65,    61,
      45,    69,    66,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    31,    31,    31,    64,    74,    89,    31,    83,
      61,    45,    60,    61,    45,    69,    82,    66,    74,    31,
      95,    96,    97,    99,    95,    64,    74,    31,    25,    64,
      64,    74,    31,   112,    74,    74,    74,   115,    74,   117,
      45,    65,    91,    91,    74,   104,   104,    74,    93,    60,
      53,    64,    64,    74,     4,    85,    82,    82,    31,    65,
      45,    31,    65,   104,    13,   110,    74,   104,   104,    47,
      24,    74,    60,    60,    65,    65,   104,   104,    65,    60,
      61,    74,    31,    97,    98,    74,    65,    74,    25,    24,
      31,   109,    65,    65,    74,    74,    65,    65,    82,    29,
      14,   108,    74,    74,    74,    24,   109,    74,    74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 163 "src/parser/newt.y"
    {;}
    break;

  case 3:
#line 167 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 4:
#line 168 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSConstituentList, (yyvsp[(1) - (1)].node)); ;}
    break;

  case 6:
#line 172 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSConstituentList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 7:
#line 173 "src/parser/newt.y"
    { yyerrok; ;}
    break;

  case 12:
#line 184 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 14:
#line 186 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSLvalue, (yyvsp[(1) - (1)].node)); ;}
    break;

  case 15:
#line 187 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSAssign, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 16:
#line 188 "src/parser/newt.y"
    {	// マジックポインタの定義（独自拡張）
											ERR_NOS2C("Assign Magic Pointer");	// NOS2 非互換
											(yyval.node) = NPSGenNode2(kNPSAssign, (yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].node));
										;}
    break;

  case 22:
#line 199 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode0(kNPSBreak); ;}
    break;

  case 23:
#line 200 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSBreak, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 24:
#line 204 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSTry, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 26:
#line 207 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSConstant, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 27:
#line 210 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode0(kNPSReturn); ;}
    break;

  case 28:
#line 211 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSReturn, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 29:
#line 215 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 32:
#line 222 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP2((yyvsp[(2) - (3)].op), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 33:
#line 223 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP2((yyvsp[(2) - (3)].op), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 34:
#line 224 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP2((yyvsp[(2) - (3)].op), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 35:
#line 225 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP2((yyvsp[(2) - (3)].op), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 36:
#line 226 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSAnd, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 37:
#line 227 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSOr, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 38:
#line 228 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP2((yyvsp[(2) - (3)].op), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 39:
#line 232 "src/parser/newt.y"
    {
								if ((yyvsp[(1) - (2)].op) == '-')
								{
									if (NewtRefIsInteger((yyvsp[(2) - (2)].node)))
										(yyval.node) = NewtMakeInteger(- NewtRefToInteger((yyvsp[(2) - (2)].node)));
									else
										(yyval.node) = NPSGenOP2('-', NewtMakeInteger(0), (yyvsp[(2) - (2)].node));
								}
								else
								{
									(yyval.node) = (yyvsp[(2) - (2)].node);
								}
							;}
    break;

  case 40:
#line 246 "src/parser/newt.y"
    { (yyval.node) = NPSGenOP1((yyvsp[(1) - (2)].op), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 41:
#line 248 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 42:
#line 249 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode0(kNPSPushSelf); ;}
    break;

  case 43:
#line 253 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 44:
#line 257 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 47:
#line 262 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSConstituentList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 48:
#line 263 "src/parser/newt.y"
    { yyerrok; ;}
    break;

  case 49:
#line 266 "src/parser/newt.y"
    {
								newtRefVar str = NSSTR("");
								NcStrCat(str, (yyvsp[(1) - (2)].obj));
								NcStrCat(str, (yyvsp[(2) - (2)].obj));
								(yyval.obj) = str;
							;}
    break;

  case 50:
#line 272 "src/parser/newt.y"
    { (yyval.obj) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 52:
#line 277 "src/parser/newt.y"
    { (yyval.obj) = NPSGenNode1(kNPSClone, (yyvsp[(1) - (1)].obj)); ;}
    break;

  case 53:
#line 278 "src/parser/newt.y"
    {	// バイナリデータ（独自拡張）
							ERR_NOS2C("Binary Syntax");	// NOS2 非互換
							(yyval.obj) = NPSGenNode1(kNPSClone, (yyvsp[(1) - (1)].obj));
						;}
    break;

  case 54:
#line 282 "src/parser/newt.y"
    { (yyval.obj) = NewtPackLiteral((yyvsp[(2) - (2)].obj)); ;}
    break;

  case 60:
#line 292 "src/parser/newt.y"
    { (yyval.obj) = kNewtRefTRUE; ;}
    break;

  case 61:
#line 293 "src/parser/newt.y"
    { (yyval.obj) = kNewtRefNIL; ;}
    break;

  case 62:
#line 294 "src/parser/newt.y"
    {	// #UNBIND （独自拡張）
							ERR_NOS2C("Unbind Ref");	// NOS2 非互換
							(yyval.obj) = kNewtRefUnbind;
						;}
    break;

  case 69:
#line 308 "src/parser/newt.y"
    { ERR_NOS2C("Binary Syntax"); ;}
    break;

  case 70:
#line 312 "src/parser/newt.y"
    { (yyval.obj) = NPSMakePathExpr((yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].obj)); ;}
    break;

  case 71:
#line 313 "src/parser/newt.y"
    { (yyval.obj) = NPSInsertArraySlot((yyvsp[(3) - (3)].obj), 0, (yyvsp[(1) - (3)].obj)); ;}
    break;

  case 72:
#line 317 "src/parser/newt.y"
    { (yyval.obj) = NcSetClass((yyvsp[(4) - (5)].obj), (yyvsp[(2) - (5)].obj)); ;}
    break;

  case 73:
#line 318 "src/parser/newt.y"
    { (yyval.obj) = (yyvsp[(2) - (3)].obj); ;}
    break;

  case 74:
#line 322 "src/parser/newt.y"
    { (yyval.obj) = NPSMakeArray(kNewtRefUnbind); ;}
    break;

  case 75:
#line 323 "src/parser/newt.y"
    { (yyval.obj) = NPSMakeArray((yyvsp[(1) - (1)].obj)); ;}
    break;

  case 77:
#line 325 "src/parser/newt.y"
    { (yyval.obj) = NPSAddArraySlot((yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].obj)); ;}
    break;

  case 78:
#line 329 "src/parser/newt.y"
    { (yyval.obj) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 79:
#line 333 "src/parser/newt.y"
    { (yyval.node) = NPSMakeFrame(kNewtRefUnbind, kNewtRefUnbind); ;}
    break;

  case 80:
#line 334 "src/parser/newt.y"
    { (yyval.node) = NPSMakeFrame((yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].obj)); ;}
    break;

  case 82:
#line 337 "src/parser/newt.y"
    { (yyval.node) = NPSSetSlot((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].obj), (yyvsp[(5) - (5)].obj)); ;}
    break;

  case 83:
#line 341 "src/parser/newt.y"
    { (yyval.obj) = NcSetClass((yyvsp[(4) - (5)].obj), (yyvsp[(2) - (5)].obj)); ;}
    break;

  case 84:
#line 342 "src/parser/newt.y"
    { (yyval.obj) = (yyvsp[(2) - (3)].obj); ;}
    break;

  case 85:
#line 346 "src/parser/newt.y"
    { (yyval.obj) = NPSMakeBinary(kNewtRefUnbind); ;}
    break;

  case 86:
#line 347 "src/parser/newt.y"
    { (yyval.obj) = NPSMakeBinary((yyvsp[(1) - (1)].obj)); ;}
    break;

  case 87:
#line 348 "src/parser/newt.y"
    { (yyval.obj) = NPSAddARef((yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].obj)); ;}
    break;

  case 88:
#line 353 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMakeArray, (yyvsp[(2) - (5)].obj), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 89:
#line 357 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMakeArray, (yyvsp[(2) - (5)].obj), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 90:
#line 358 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMakeArray, kNewtRefUnbind, (yyvsp[(2) - (3)].node)); ;}
    break;

  case 91:
#line 361 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSMakeFrame, (yyvsp[(2) - (3)].node)); ;}
    break;

  case 92:
#line 365 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSFunc, (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node)); ;}
    break;

  case 93:
#line 368 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMakeRegex, (yyvsp[(1) - (2)].obj), (yyvsp[(2) - (2)].obj)); ;}
    break;

  case 94:
#line 369 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMakeRegex, (yyvsp[(1) - (1)].obj), kNewtRefNIL); ;}
    break;

  case 95:
#line 373 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 98:
#line 377 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 99:
#line 381 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 102:
#line 385 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 103:
#line 389 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSSlot, (yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 106:
#line 398 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 108:
#line 401 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 110:
#line 407 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 111:
#line 411 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 112:
#line 412 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSArg, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].obj)); ;}
    break;

  case 113:
#line 416 "src/parser/newt.y"
    {	// 不定長（独自拡張）
										ERR_NOS2C("Indefinite Argument");	// NOS2 非互換
										(yyval.node) = NPSGenNode1(kNPSIndefinite, (yyvsp[(1) - (2)].obj));
									;}
    break;

  case 114:
#line 423 "src/parser/newt.y"
    { TYPECHECK((yyvsp[(1) - (1)].obj)); (yyval.node) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 115:
#line 427 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSGetPath, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].obj)); ;}
    break;

  case 116:
#line 428 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSGetPath, (yyvsp[(1) - (5)].node), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 117:
#line 432 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSAref, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 118:
#line 436 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSExists, (yyvsp[(1) - (2)].obj)); ;}
    break;

  case 119:
#line 437 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSExists, (yyvsp[(1) - (2)].node)); ;}
    break;

  case 120:
#line 438 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMethodExists, kNewtRefUnbind, (yyvsp[(2) - (3)].obj)); ;}
    break;

  case 121:
#line 439 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSMethodExists, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].obj)); ;}
    break;

  case 122:
#line 443 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCall, (yyvsp[(1) - (4)].obj), (yyvsp[(3) - (4)].node)); ;}
    break;

  case 123:
#line 445 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSInvoke, (yyvsp[(2) - (6)].node), (yyvsp[(5) - (6)].node)); ;}
    break;

  case 124:
#line 449 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 126:
#line 451 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 127:
#line 456 "src/parser/newt.y"
    { (yyval.node) = NPSGenSend(kNewtRefUnbind, (yyvsp[(1) - (5)].op), (yyvsp[(2) - (5)].obj), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 128:
#line 458 "src/parser/newt.y"
    { (yyval.node) = NPSGenSend(kNewtRefUnbind, (yyvsp[(1) - (5)].op), (yyvsp[(2) - (5)].obj), (yyvsp[(4) - (5)].node)); ;}
    break;

  case 129:
#line 461 "src/parser/newt.y"
    { (yyval.node) = NPSGenSend((yyvsp[(1) - (6)].node), ':', (yyvsp[(3) - (6)].obj), (yyvsp[(5) - (6)].node)); ;}
    break;

  case 130:
#line 463 "src/parser/newt.y"
    { (yyval.node) = NPSGenSend((yyvsp[(1) - (6)].node), (yyvsp[(2) - (6)].op), (yyvsp[(3) - (6)].obj), (yyvsp[(5) - (6)].node)); ;}
    break;

  case 131:
#line 466 "src/parser/newt.y"
    { (yyval.node) = NPSGenResend(':', (yyvsp[(3) - (6)].obj), (yyvsp[(5) - (6)].node)); ;}
    break;

  case 132:
#line 468 "src/parser/newt.y"
    { (yyval.node) = NPSGenResend((yyvsp[(2) - (6)].op), (yyvsp[(3) - (6)].obj), (yyvsp[(5) - (6)].node)); ;}
    break;

  case 133:
#line 472 "src/parser/newt.y"
    { (yyval.node) = NPSGenIfThenElse((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), kNewtRefUnbind); ;}
    break;

  case 134:
#line 473 "src/parser/newt.y"
    { (yyval.node) = NPSGenIfThenElse((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node)); ;}
    break;

  case 135:
#line 478 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSLoop, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 136:
#line 480 "src/parser/newt.y"
    { (yyval.node) = NPSGenForLoop((yyvsp[(2) - (9)].obj), (yyvsp[(4) - (9)].node), (yyvsp[(6) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node)); ;}
    break;

  case 137:
#line 482 "src/parser/newt.y"
    { (yyval.node) = NPSGenForeach(kNewtRefUnbind, (yyvsp[(2) - (7)].obj), (yyvsp[(5) - (7)].node), (yyvsp[(3) - (7)].obj), (yyvsp[(6) - (7)].obj), (yyvsp[(7) - (7)].node)); ;}
    break;

  case 138:
#line 484 "src/parser/newt.y"
    { (yyval.node) = NPSGenForeach((yyvsp[(2) - (9)].obj), (yyvsp[(4) - (9)].obj), (yyvsp[(7) - (9)].node), (yyvsp[(5) - (9)].obj), (yyvsp[(8) - (9)].obj), (yyvsp[(9) - (9)].node)); ;}
    break;

  case 139:
#line 485 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSWhile, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 140:
#line 486 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSRepeat, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 141:
#line 490 "src/parser/newt.y"
    { (yyval.node) = kNewtRefUnbind; ;}
    break;

  case 142:
#line 491 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 143:
#line 495 "src/parser/newt.y"
    { (yyval.obj) = kNewtRefNIL; ;}
    break;

  case 144:
#line 496 "src/parser/newt.y"
    { SYMCHECK((yyvsp[(1) - (1)].obj), NSSYM0(collect)); (yyval.obj) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 145:
#line 500 "src/parser/newt.y"
    { (yyval.obj) = kNewtRefNIL; ;}
    break;

  case 146:
#line 501 "src/parser/newt.y"
    { SYMCHECK((yyvsp[(1) - (1)].obj), NSSYM0(deeply)); (yyval.obj) = kNewtRefTRUE; ;}
    break;

  case 148:
#line 511 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSOnexceptionList, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 149:
#line 515 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSOnexception, (yyvsp[(2) - (4)].obj), (yyvsp[(4) - (4)].node)); ;}
    break;

  case 150:
#line 519 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSLocal, kNewtRefUnbind, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 151:
#line 521 "src/parser/newt.y"
    {
				TYPECHECK((yyvsp[(2) - (3)].obj));
				(yyval.node) = NPSGenNode2(kNPSLocal, (yyvsp[(2) - (3)].obj), (yyvsp[(3) - (3)].node));
			;}
    break;

  case 153:
#line 536 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 154:
#line 540 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(1) - (1)].obj); ;}
    break;

  case 155:
#line 541 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSAssign, (yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 157:
#line 547 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSCommaList, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 158:
#line 551 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode2(kNPSAssign, (yyvsp[(1) - (3)].obj), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 159:
#line 555 "src/parser/newt.y"
    { (yyval.node) = NPSGenNode1(kNPSGlobal, (yyvsp[(2) - (2)].node)); ;}
    break;

  case 161:
#line 560 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 162:
#line 561 "src/parser/newt.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 163:
#line 565 "src/parser/newt.y"
    { (yyval.node) = NPSGenGlobalFn((yyvsp[(1) - (5)].obj), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2437 "/Users/matt/dev/newt64.github/build/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 568 "src/parser/newt.y"


