
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/integrador.y"

    #include <stdio.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>

    int yylex();
    int yywrap(){ return(1); }
    void yyerror (char const *s) {}

    FILE* yyin;

    int numeroLinea = 1;



/* Line 189 of yacc.c  */
#line 90 "integrador.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFICADOR = 258,
     OPERADOR_ASIGNACION = 259,
     OPERADOR_O_LOGICO = 260,
     OPERADOR_Y_LOGICO = 261,
     OPERADOR_O_INCLUSIVO = 262,
     OPERADOR_O_EXCLUSIVO = 263,
     OPERADOR_Y = 264,
     OPERADOR_IGUALDAD = 265,
     OPERADOR_RELACIONAL = 266,
     OPERADOR_CORRIMIENTO = 267,
     OPERADOR_ADITIVO = 268,
     OPERADOR_MULTIPLICATIVO = 269,
     OPERADOR_INCREMENTO = 270,
     OPERADOR_UNARIO = 271,
     OPERADOR_SIZEOF = 272,
     OPERADOR_SELECCION_MIEMBRO = 273,
     CONSTANTE_CADENA = 274,
     CONSTANTE_DECIMAL = 275,
     CONSTANTE_OCTAL = 276,
     CONSTANTE_HEXADECIMAL = 277,
     CONSTANTE_REAL = 278,
     CONSTANTE_CARACTER = 279,
     TIPO_DATO = 280,
     ESPECIFICADOR_CLASE_ALMACENAMIENTO = 281,
     CALIFICADOR_TIPO = 282,
     STRUCT_O_UNION = 283,
     ELLIPSIS = 284,
     ENUM = 285,
     IF = 286,
     ELSE = 287,
     SWITCH = 288,
     WHILE = 289,
     DO = 290,
     FOR = 291,
     CASE = 292,
     DEFAULT = 293,
     CONTINUE = 294,
     BREAK = 295,
     RETURN = 296,
     GOTO = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "../src/integrador.y"

    char cadena[100];
    int entero;
    float real;



/* Line 214 of yacc.c  */
#line 176 "integrador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "integrador.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNRULES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,    54,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    55,
       2,    51,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    18,    22,
      24,    28,    30,    36,    38,    42,    44,    48,    50,    54,
      56,    60,    62,    66,    68,    72,    74,    78,    80,    84,
      86,    90,    92,    96,    98,   103,   105,   108,   111,   114,
     119,   121,   126,   131,   135,   138,   140,   144,   146,   148,
     150,   154,   156,   158,   160,   162,   164,   166,   169,   172,
     175,   178,   180,   184,   186,   190,   192,   196,   201,   203,
     207,   209,   211,   213,   216,   218,   221,   223,   227,   232,
     237,   239,   243,   245,   249,   252,   255,   261,   264,   266,
     270,   272,   276,   278,   280,   282,   284,   287,   291,   296,
     301,   303,   305,   307,   309,   311,   314,   315,   317,   322,
     324,   327,   329,   332,   338,   346,   352,   358,   363,   367,
     371,   377,   385,   395,   398,   401,   405,   409,   410,   412,
     413,   415,   416,   418,   419,   421,   422,   424,   425,   427,
     428,   430,   431,   433,   434,   436,   437,   439,   440
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    -1,    57,    58,    -1,    79,    43,    -1,
     100,    43,    -1,     1,    43,    -1,    60,    -1,    59,    44,
      60,    -1,    61,    -1,    73,     4,    60,    -1,    62,    -1,
      62,    45,    59,    46,    61,    -1,    63,    -1,    62,     5,
      63,    -1,    64,    -1,    63,     6,    64,    -1,    65,    -1,
      64,     7,    65,    -1,    66,    -1,    65,     8,    66,    -1,
      67,    -1,    66,     9,    67,    -1,    68,    -1,    67,    10,
      68,    -1,    69,    -1,    68,    11,    69,    -1,    70,    -1,
      69,    12,    70,    -1,    71,    -1,    70,    13,    71,    -1,
      72,    -1,    71,    14,    72,    -1,    73,    -1,    47,    97,
      48,    72,    -1,    74,    -1,    15,    73,    -1,    16,    72,
      -1,    17,    73,    -1,    17,    47,    97,    48,    -1,    76,
      -1,    74,    49,    59,    50,    -1,    74,    47,   110,    48,
      -1,    74,    18,     3,    -1,    74,    15,    -1,    60,    -1,
      75,    44,    60,    -1,     3,    -1,    78,    -1,    19,    -1,
      47,    59,    48,    -1,    61,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    80,   111,    -1,    26,
     112,    -1,    85,   112,    -1,    27,   112,    -1,    82,    -1,
      81,    44,    82,    -1,    86,    -1,    86,    51,    83,    -1,
      60,    -1,    52,    84,    53,    -1,    52,    84,    44,    53,
      -1,    83,    -1,    84,    44,    83,    -1,    25,    -1,    92,
      -1,    96,    -1,   114,    88,    -1,    54,    -1,    54,    87,
      -1,     3,    -1,    47,    86,    48,    -1,    88,    49,   115,
      50,    -1,    88,    47,    89,    48,    -1,    90,    -1,    90,
      44,    29,    -1,    91,    -1,    90,    44,    91,    -1,    80,
      86,    -1,    80,   116,    -1,    30,   113,    52,    93,    53,
      -1,    30,     3,    -1,    94,    -1,    93,    44,    94,    -1,
      95,    -1,    95,    51,    77,    -1,     3,    -1,     3,    -1,
     116,    -1,    87,    -1,   114,    99,    -1,    47,    98,    48,
      -1,   118,    49,   115,    50,    -1,   118,    47,   117,    48,
      -1,   101,    -1,   103,    -1,   106,    -1,   108,    -1,   109,
      -1,   102,    55,    -1,    -1,    59,    -1,    52,   119,   120,
      53,    -1,    79,    -1,   104,    79,    -1,   100,    -1,   105,
     100,    -1,    31,    47,    59,    48,   100,    -1,    31,    47,
      59,    48,   100,    32,   100,    -1,    33,    47,    59,    48,
     100,    -1,    33,    47,    59,    48,   107,    -1,    37,    77,
      46,   100,    -1,    38,    46,   100,    -1,     3,    46,   100,
      -1,    34,    47,    59,    48,   100,    -1,    35,   100,    34,
      47,    59,    48,    55,    -1,    36,    47,   102,    55,   102,
      55,   102,    48,   100,    -1,    39,    55,    -1,    40,    55,
      -1,    41,   102,    55,    -1,    42,     3,    55,    -1,    -1,
      75,    -1,    -1,    81,    -1,    -1,    80,    -1,    -1,     3,
      -1,    -1,    87,    -1,    -1,    77,    -1,    -1,    98,    -1,
      -1,    89,    -1,    -1,    99,    -1,    -1,   104,    -1,    -1,
     105,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    79,    82,    83,    84,    88,    89,    92,
      93,    96,    97,   100,   101,   104,   105,   108,   109,   112,
     113,   116,   117,   120,   121,   124,   125,   128,   129,   132,
     133,   136,   137,   140,   141,   144,   145,   146,   147,   148,
     151,   152,   153,   154,   155,   158,   159,   162,   163,   164,
     165,   168,   171,   172,   173,   174,   175,   181,   184,   185,
     186,   189,   190,   193,   194,   197,   198,   199,   202,   203,
     206,   208,   209,   238,   241,   242,   249,   250,   251,   252,
     257,   258,   261,   262,   265,   266,   269,   270,   273,   274,
     277,   278,   281,   284,   287,   290,   291,   294,   295,   296,
     301,   302,   303,   304,   305,   308,   311,   312,   314,   317,
     318,   321,   322,   325,   326,   327,   328,   331,   332,   333,
     336,   337,   338,   341,   342,   343,   344,   350,   351,   356,
     357,   360,   361,   364,   365,   376,   377,   384,   385,   388,
     389,   392,   393,   395,   396,   400,   401,   404,   405
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "OPERADOR_ASIGNACION",
  "OPERADOR_O_LOGICO", "OPERADOR_Y_LOGICO", "OPERADOR_O_INCLUSIVO",
  "OPERADOR_O_EXCLUSIVO", "OPERADOR_Y", "OPERADOR_IGUALDAD",
  "OPERADOR_RELACIONAL", "OPERADOR_CORRIMIENTO", "OPERADOR_ADITIVO",
  "OPERADOR_MULTIPLICATIVO", "OPERADOR_INCREMENTO", "OPERADOR_UNARIO",
  "OPERADOR_SIZEOF", "OPERADOR_SELECCION_MIEMBRO", "CONSTANTE_CADENA",
  "CONSTANTE_DECIMAL", "CONSTANTE_OCTAL", "CONSTANTE_HEXADECIMAL",
  "CONSTANTE_REAL", "CONSTANTE_CARACTER", "TIPO_DATO",
  "ESPECIFICADOR_CLASE_ALMACENAMIENTO", "CALIFICADOR_TIPO",
  "STRUCT_O_UNION", "ELLIPSIS", "ENUM", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "CASE", "DEFAULT", "CONTINUE", "BREAK", "RETURN", "GOTO",
  "'\\n'", "','", "'?'", "':'", "'('", "')'", "'['", "']'", "'='", "'{'",
  "'}'", "'*'", "';'", "$accept", "input", "line", "expresion",
  "expresionAsignacion", "expresionCondicional", "expresionOLogico",
  "expresionYLogico", "expresionOInclusivo", "expresionOExcluyente",
  "expresionY", "expresionIgualdad", "expresionRelacional",
  "expresionCorrimiento", "expresionAditiva", "expresionMultiplicativa",
  "expresionConversion", "expresionUnaria", "expresionSufijo",
  "listaArgumentos", "expresionPrimaria", "expresionConstante",
  "constante", "declaracion", "especificadoresDeclaracion",
  "listaDeclaradores", "declarador", "inicializador",
  "listaInicializadores", "especificadorTipo", "decla", "puntero",
  "declaradorDirecto", "listaTiposParametros", "listaParametros",
  "declaracionParametro", "especificadorEnum", "listaEnumeradores",
  "enumerador", "constanteEnumeracion", "nombreTypedef", "nombreTipo",
  "declaradorAbstracto", "declaradorAbstractoDirecto", "sentencia",
  "sentenciaExpresion", "expresion_", "sentenciaCompuesta",
  "listaDeclaraciones", "listaSentencias", "sentenciaSeleccion",
  "sentenciaEtiquetada", "sentenciaIteracion", "sentenciaSalto",
  "listaArgumentos_", "listaDeclaradores_", "especificadoresDeclaracion_",
  "IDENTIFICADOR_", "puntero_", "expresionConstante_",
  "declaradorAbstracto_", "listaTiposParametros_",
  "declaradorAbstractoDirecto_", "listaDeclaraciones_", "listaSentencias_", 0
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
     295,   296,   297,    10,    44,    63,    58,    40,    41,    91,
      93,    61,   123,   125,    42,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    78,    78,    78,    78,    78,    79,    80,    80,
      80,    81,    81,    82,    82,    83,    83,    83,    84,    84,
      85,    85,    85,    86,    87,    87,    88,    88,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    96,    97,    98,    98,    99,    99,    99,
     100,   100,   100,   100,   100,   101,   102,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     108,   108,   108,   109,   109,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     4,     1,     2,     2,     2,     4,
       1,     4,     4,     3,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     3,     1,     3,     1,     3,     4,     1,     3,
       1,     1,     1,     2,     1,     2,     1,     3,     4,     4,
       1,     3,     1,     3,     2,     2,     5,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     3,     4,     4,
       1,     1,     1,     1,     1,     2,     0,     1,     4,     1,
       2,     1,     2,     5,     7,     5,     5,     4,     3,     3,
       5,     7,     9,     2,     2,     3,     3,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    47,     0,     0,     0,    49,    52,
      53,    54,    55,    56,    70,   131,   131,   133,     0,     0,
       0,   106,     0,     0,     0,   106,     0,   135,   145,     3,
     107,     7,     9,    11,    13,    15,    17,    19,    21,    23,
      25,    27,    29,    31,    33,    35,    40,    48,     0,   129,
     131,    71,    72,     0,   100,     0,   101,   102,   103,   104,
       6,    47,     0,    36,    37,    33,   135,    38,    93,   132,
      58,    60,    87,     0,     0,     0,     0,     0,   106,   123,
     124,     0,     0,    74,     0,   136,     0,   140,   143,    94,
     109,   146,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,   127,     0,
       4,   130,    61,    63,   136,    57,     0,    59,     5,   105,
       0,     0,     0,     0,     0,     0,     0,   125,   126,    75,
      50,     0,   135,    96,     0,   110,   111,   106,     0,     8,
      14,     0,    16,    18,    20,    22,    24,    26,    28,    30,
      32,    10,    43,    45,   128,     0,     0,   135,     0,    76,
     135,    73,    39,    92,     0,    88,    90,   106,   106,   106,
       0,   106,    34,     0,   141,   137,   112,   108,     0,     0,
      42,    41,    62,     0,    65,    64,     0,     0,   137,     0,
      86,     0,   113,    47,     0,     0,   115,   116,   120,     0,
       0,    97,   135,   142,    80,    82,     0,    51,   138,     0,
      12,    46,    68,     0,    77,     0,     0,    89,    91,   106,
     106,     0,   106,     0,   106,    84,   143,    85,     0,    99,
      98,     0,    66,    79,    78,   114,   119,   106,   118,   121,
       0,   135,    81,    83,    67,    69,   117,   106,   122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   154,
      46,   208,    47,    48,    49,   111,   112,   185,   213,    50,
     113,    85,   161,   203,   204,   205,    51,   164,   165,   166,
      52,    86,    87,   133,    53,    54,    55,    56,    91,   137,
      57,   197,    58,    59,   155,   115,    70,    73,    88,   209,
      89,   206,   134,    92,   138
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -170
static const yytype_int16 yypact[] =
{
    -170,   208,  -170,   -32,    25,   121,   452,   463,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,    12,    12,    19,   -13,    -7,
       1,   418,     7,     9,    53,   452,    30,   249,    12,  -170,
      36,  -170,  -170,    18,   105,   120,   124,   126,   129,   145,
     150,   151,   153,  -170,   161,    26,  -170,  -170,   127,   115,
      12,  -170,  -170,   128,  -170,   117,  -170,  -170,  -170,  -170,
    -170,  -170,   452,  -170,  -170,  -170,   249,  -170,  -170,  -170,
    -170,  -170,  -170,   122,   452,   452,   452,   143,   452,  -170,
    -170,   130,   131,   115,    33,    65,   132,  -170,   134,  -170,
    -170,    12,   259,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,  -170,   180,   452,   452,
    -170,   140,  -170,   136,  -170,  -170,    13,  -170,  -170,  -170,
     141,   187,    74,    77,    82,   146,   137,  -170,  -170,  -170,
    -170,   452,   115,    20,    46,  -170,  -170,   299,   142,  -170,
     105,    28,   120,   124,   126,   129,   145,   150,   151,   153,
    -170,  -170,  -170,  -170,   156,   149,   -25,   115,    67,  -170,
     115,   112,  -170,  -170,   -26,  -170,   152,   418,   378,   418,
     452,   452,  -170,   157,    12,   452,  -170,  -170,   452,   452,
    -170,  -170,  -170,    67,  -170,  -170,   158,    12,   452,   187,
    -170,   452,   172,   164,   452,   166,  -170,  -170,  -170,    85,
     160,  -170,    -1,  -170,   163,  -170,   165,  -170,  -170,   167,
    -170,  -170,  -170,   -23,  -170,   170,   169,  -170,  -170,   418,
     418,   174,   418,   181,   452,  -170,    14,  -170,   125,  -170,
    -170,   339,  -170,  -170,  -170,  -170,  -170,   418,  -170,  -170,
     173,   115,  -170,  -170,  -170,  -170,  -170,   418,  -170
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,  -170,   -17,   -73,   -12,  -170,   159,   144,   148,
     139,   123,   154,   155,   175,   182,     3,     0,  -170,  -170,
    -170,  -165,  -170,   -15,   -14,  -170,    89,  -169,  -170,  -170,
    -136,   -37,  -170,    64,  -170,    29,  -170,  -170,    69,  -170,
    -170,   193,  -124,  -170,   -21,  -170,   -22,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,    15,  -170,   -45,    73,
      84,  -170,  -170,  -170,  -170
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -149
static const yytype_int16 yytable[] =
{
      77,    69,    69,    81,   116,    63,    65,    67,   173,    64,
      84,    60,   114,    90,   212,    68,   159,   159,   189,    93,
     139,   231,    72,    94,   186,   181,   218,   190,   -93,   221,
     232,    71,   151,    82,    74,   153,    69,    14,    15,    16,
      75,   106,    17,  -139,   107,    84,   129,  -139,    76,    84,
     -93,   -93,   -93,    83,    78,   -93,   126,   122,   123,   124,
     160,   241,   245,    95,    79,   117,   225,  -144,   -93,  -144,
      61,   136,    93,   108,   178,   109,   135,    93,   141,   -93,
      93,   130,     5,     6,     7,   184,     8,     9,    10,    11,
      12,    13,   156,   174,    65,   175,    65,    65,    65,    65,
      65,    65,    65,    65,    65,   186,   211,   150,    80,   -95,
     184,    96,   116,   -95,    27,   116,   176,   173,    93,   183,
     114,    93,   167,   114,    61,   168,    93,    97,    68,    93,
     169,    65,    98,   223,   172,    99,     5,     6,     7,   100,
       8,     9,    10,    11,    12,    13,   192,   196,   198,   200,
      14,    15,    16,   199,   242,    17,   101,   226,   184,   187,
     202,   188,   102,   207,   103,   105,   210,   104,    62,    83,
     110,   118,   119,   202,   121,    65,   207,   125,    65,   207,
     131,   132,   207,   152,   157,   127,   128,   158,    65,   162,
     163,    65,   171,   170,    65,   177,   226,   180,   235,   236,
     179,   238,   240,   191,   219,   201,   214,   228,     2,     3,
     220,     4,   222,   229,   202,   224,   246,   230,   233,   234,
     237,   247,   145,     5,     6,     7,   248,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   239,   144,    17,    18,
     142,    19,    20,    21,    22,   143,   182,    23,    24,    25,
      26,   215,    61,   140,   146,    27,   147,   243,   217,   120,
      28,   216,    61,  -106,     5,     6,     7,     0,     8,     9,
      10,    11,    12,    13,     5,     6,     7,   148,     8,     9,
      10,    11,    12,    13,     0,   149,   227,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    27,  -139,    23,    24,
      25,    26,    61,    83,     0,     0,    27,     0,     0,     0,
       0,    28,  -147,     0,     5,     6,     7,     0,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,     0,     0,    23,    24,
      25,    26,    61,     0,     0,     0,    27,     0,     0,     0,
       0,    28,  -148,     0,     5,     6,     7,     0,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,     0,     0,     0,     0,    27,     0,     0,     0,
       0,   183,   244,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,   194,   195,    23,    24,    25,
      26,    61,     0,     0,     0,    27,     0,     0,     0,     0,
      28,     0,     0,     5,     6,     7,     0,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    61,     0,    23,    24,    25,
      26,     0,     0,     0,     0,    27,    61,     5,     6,     7,
      28,     8,     9,    10,    11,    12,    13,     0,     5,     6,
       7,     0,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66
};

static const yytype_int16 yycheck[] =
{
      21,    15,    16,    25,    49,     5,     6,     7,   132,     6,
      27,    43,    49,    28,   183,     3,     3,     3,    44,    44,
      93,    44,     3,     5,   160,    50,   191,    53,     3,   194,
      53,    16,   105,     3,    47,   108,    50,    25,    26,    27,
      47,    15,    30,    44,    18,    62,    83,    48,    47,    66,
      25,    26,    27,    54,    47,    30,    78,    74,    75,    76,
      47,    47,   231,    45,    55,    50,   202,    47,    43,    49,
       3,    92,    44,    47,    46,    49,    91,    44,    95,    54,
      44,    48,    15,    16,    17,   158,    19,    20,    21,    22,
      23,    24,   109,    47,    94,    49,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   241,   179,   104,    55,    44,
     183,     6,   157,    48,    47,   160,   137,   241,    44,    52,
     157,    44,    48,   160,     3,    48,    44,     7,     3,    44,
      48,   131,     8,    48,   131,     9,    15,    16,    17,    10,
      19,    20,    21,    22,    23,    24,   167,   168,   169,   171,
      25,    26,    27,   170,    29,    30,    11,   202,   231,    47,
     174,    49,    12,   175,    13,     4,   178,    14,    47,    54,
      43,    43,    55,   187,    52,   175,   188,    34,   178,   191,
      48,    47,   194,     3,    44,    55,    55,    51,   188,    48,
       3,   191,    55,    47,   194,    53,   241,    48,   219,   220,
      44,   222,   224,    51,    32,    48,    48,    44,     0,     1,
      46,     3,    46,    48,   228,    55,   237,    50,    48,    50,
      46,    48,    99,    15,    16,    17,   247,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    55,    98,    30,    31,
      96,    33,    34,    35,    36,    97,   157,    39,    40,    41,
      42,   187,     3,    94,   100,    47,   101,   228,   189,    66,
      52,   188,     3,    55,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    15,    16,    17,   102,    19,    20,
      21,    22,    23,    24,    -1,   103,   202,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    36,    47,    48,    39,    40,
      41,    42,     3,    54,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    36,    -1,    -1,    39,    40,
      41,    42,     3,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     3,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,    34,    35,    36,     3,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,     3,    15,    16,    17,
      52,    19,    20,    21,    22,    23,    24,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,     0,     1,     3,    15,    16,    17,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    30,    31,    33,
      34,    35,    36,    39,    40,    41,    42,    47,    52,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    78,    79,    80,
      85,    92,    96,   100,   101,   102,   103,   106,   108,   109,
      43,     3,    47,    73,    72,    73,    47,    73,     3,    80,
     112,   112,     3,   113,    47,    47,    47,   100,    47,    55,
      55,   102,     3,    54,    59,    87,    97,    98,   114,   116,
      79,   104,   119,    44,     5,    45,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     4,    15,    18,    47,    49,
      43,    81,    82,    86,    87,   111,   114,   112,    43,    55,
      97,    52,    59,    59,    59,    34,   102,    55,    55,    87,
      48,    48,    47,    99,   118,    79,   100,   105,   120,    60,
      63,    59,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    60,     3,    60,    75,   110,    59,    44,    51,     3,
      47,    88,    48,     3,    93,    94,    95,    48,    48,    48,
      47,    55,    72,    98,    47,    49,   100,    53,    46,    44,
      48,    50,    82,    52,    60,    83,    86,    47,    49,    44,
      53,    51,   100,     3,    37,    38,   100,   107,   100,    59,
     102,    48,    80,    89,    90,    91,   117,    61,    77,   115,
      61,    60,    83,    84,    48,    89,   115,    94,    77,    32,
      46,    77,    46,    48,    55,    86,   114,   116,    44,    48,
      50,    44,    53,    48,    50,   100,   100,    46,   100,    55,
     102,    47,    29,    91,    53,    83,   100,    48,   100
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 4:

/* Line 1455 of yacc.c  */
#line 82 "../src/integrador.y"
    { numeroLinea++; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 83 "../src/integrador.y"
    { numeroLinea++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 84 "../src/integrador.y"
    { printf("\n***Error sintactico - Linea %i***\n", numeroLinea); numeroLinea++; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 184 "../src/integrador.y"
    { printf(" - Clase de almacenamiento : %s", (yyvsp[(1) - (2)].cadena));    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 185 "../src/integrador.y"
    { printf(" - Tipo : %s", (yyvsp[(1) - (2)].cadena));                       ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 186 "../src/integrador.y"
    { printf(" - Calificador : %s", (yyvsp[(1) - (2)].cadena));                ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 193 "../src/integrador.y"
    { printf("\nSe declaro una variable");    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 194 "../src/integrador.y"
    { printf("\nSe inicializo una variable"); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 252 "../src/integrador.y"
    { printf("\nSe declaro una funcion"); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 311 "../src/integrador.y"
    { printf("\nSentencia expresion - VACIA.");   ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 314 "../src/integrador.y"
    { printf("\nSentencia expresion - COMPUESTA.");   ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 325 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - IF.");         ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 326 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - IF/ELSE.");    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 327 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - SWITCH.");     ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 328 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - SWITCH.");     ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 336 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - WHILE.");      ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 337 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - DO/WHILE.");   ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 338 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - FOR.");        ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 341 "../src/integrador.y"
    { printf("\nSentencia de SALTO - CONTINUE.");   ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 342 "../src/integrador.y"
    { printf("\nSentencia de SALTO - BREAK.");      ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 343 "../src/integrador.y"
    { printf("\nSentencia de SALTO - RETURN.");     ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 344 "../src/integrador.y"
    { printf("\nSentencia de SALTO - GOTO.");       ;}
    break;



/* Line 1455 of yacc.c  */
#line 1845 "integrador.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 408 "../src/integrador.y"


int main() {
    yyin = fopen("test.c", "r");
    yyparse();
}
