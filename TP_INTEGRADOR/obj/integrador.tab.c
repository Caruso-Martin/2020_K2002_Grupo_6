
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
     OPERADOR_IGUALDAD = 264,
     OPERADOR_RELACIONAL = 265,
     OPERADOR_CORRIMIENTO = 266,
     OPERADOR_MULTIPLICATIVO = 267,
     OPERADOR_INCREMENTO = 268,
     OPERADOR_SIZEOF = 269,
     OPERADOR_SELECCION_MIEMBRO = 270,
     CONSTANTE_CADENA = 271,
     CONSTANTE_DECIMAL = 272,
     CONSTANTE_OCTAL = 273,
     CONSTANTE_HEXADECIMAL = 274,
     CONSTANTE_REAL = 275,
     CONSTANTE_CARACTER = 276,
     TIPO_DATO = 277,
     IF = 278,
     ELSE = 279,
     SWITCH = 280,
     WHILE = 281,
     DO = 282,
     FOR = 283,
     CASE = 284,
     DEFAULT = 285,
     CONTINUE = 286,
     BREAK = 287,
     RETURN = 288,
     GOTO = 289
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
#line 168 "integrador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 180 "integrador.tab.c"

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
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,     2,    41,     2,
      45,    46,    44,    42,    37,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    36,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,    47,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    21,
      25,    27,    31,    35,    37,    43,    45,    49,    51,    55,
      57,    61,    63,    67,    69,    73,    75,    79,    81,    85,
      87,    91,    93,    97,   101,   103,   107,   111,   113,   118,
     120,   123,   126,   129,   134,   136,   138,   140,   142,   144,
     146,   148,   153,   158,   162,   165,   167,   171,   173,   175,
     177,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     201,   203,   207,   209,   213,   215,   219,   225,   227,   231,
     238,   245,   247,   251,   254,   255,   257,   260,   263,   265,
     268,   270,   275,   277,   279,   281,   283,   285,   287,   290,
     291,   293,   298,   300,   303,   305,   308,   314,   322,   328,
     333,   337,   341,   347,   355,   365,   368,   371,   375,   379,
     380,   382,   383,   385,   386,   388,   389,   391,   392
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,    77,    35,    -1,
      89,    35,    -1,     1,    35,    -1,     1,    36,    -1,    57,
      -1,    56,    37,    57,    -1,    58,    -1,    70,    38,    57,
      -1,    70,     4,    57,    -1,    59,    -1,    59,    39,    56,
      40,    58,    -1,    60,    -1,    59,     5,    60,    -1,    61,
      -1,    60,     6,    61,    -1,    62,    -1,    61,     7,    62,
      -1,    63,    -1,    62,     8,    63,    -1,    64,    -1,    63,
      41,    64,    -1,    65,    -1,    64,     9,    65,    -1,    66,
      -1,    65,    10,    66,    -1,    67,    -1,    66,    11,    67,
      -1,    68,    -1,    67,    42,    68,    -1,    67,    43,    68,
      -1,    69,    -1,    68,    44,    69,    -1,    68,    12,    69,
      -1,    70,    -1,    45,    22,    46,    69,    -1,    72,    -1,
      13,    70,    -1,    71,    69,    -1,    14,    70,    -1,    14,
      45,    22,    46,    -1,    41,    -1,    44,    -1,    42,    -1,
      43,    -1,    47,    -1,    48,    -1,    74,    -1,    72,    49,
      56,    50,    -1,    72,    45,    99,    46,    -1,    72,    15,
       3,    -1,    72,    13,    -1,    57,    -1,    73,    37,    57,
      -1,     3,    -1,    76,    -1,    16,    -1,    45,    56,    46,
      -1,    58,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    78,    -1,    83,    -1,    22,    79,    36,
      -1,    80,    -1,    79,    37,    80,    -1,    86,    -1,    86,
      38,    81,    -1,    57,    -1,    51,    82,    52,    -1,    51,
      82,    37,    82,    52,    -1,    81,    -1,    82,    37,    81,
      -1,    22,     3,    45,   101,    46,    36,    -1,    22,     3,
      45,   101,    46,    92,    -1,    85,    -1,    84,    37,    85,
      -1,    22,    86,    -1,    -1,    88,    -1,    87,    88,    -1,
      41,    88,    -1,    44,    -1,    44,    87,    -1,     3,    -1,
      88,    49,   100,    50,    -1,    90,    -1,    92,    -1,    95,
      -1,    97,    -1,    98,    -1,    96,    -1,    91,    36,    -1,
      -1,    56,    -1,    51,   102,   103,    52,    -1,    77,    -1,
      93,    77,    -1,    89,    -1,    94,    89,    -1,    23,    45,
      56,    46,    89,    -1,    23,    45,    56,    46,    89,    24,
      89,    -1,    25,    45,    56,    46,    89,    -1,    29,    75,
      40,    89,    -1,    30,    40,    89,    -1,     3,    40,    89,
      -1,    26,    45,    56,    46,    89,    -1,    27,    89,    26,
      45,    56,    46,    36,    -1,    28,    45,    91,    36,    91,
      36,    91,    46,    89,    -1,    31,    36,    -1,    32,    36,
      -1,    33,    91,    36,    -1,    34,     3,    36,    -1,    -1,
      73,    -1,    -1,    75,    -1,    -1,    84,    -1,    -1,    93,
      -1,    -1,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    75,    76,    77,    78,    83,    84,
      87,    88,    89,    92,    93,    96,    97,   100,   101,   104,
     105,   108,   109,   112,   113,   116,   117,   120,   121,   124,
     125,   128,   129,   130,   133,   134,   135,   138,   139,   142,
     143,   144,   145,   146,   149,   150,   151,   152,   153,   154,
     157,   158,   159,   160,   161,   164,   165,   168,   169,   170,
     171,   174,   177,   178,   179,   180,   181,   186,   187,   192,
     195,   196,   199,   200,   203,   204,   205,   208,   209,   214,
     215,   218,   219,   222,   227,   228,   229,   230,   233,   234,
     237,   238,   242,   243,   244,   245,   246,   247,   250,   253,
     254,   256,   259,   260,   263,   264,   267,   268,   269,   271,
     272,   273,   276,   277,   278,   281,   282,   283,   284,   290,
     291,   296,   297,   300,   301,   305,   306,   309,   310
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFICADOR", "OPERADOR_ASIGNACION",
  "OPERADOR_O_LOGICO", "OPERADOR_Y_LOGICO", "OPERADOR_O_INCLUSIVO",
  "OPERADOR_O_EXCLUSIVO", "OPERADOR_IGUALDAD", "OPERADOR_RELACIONAL",
  "OPERADOR_CORRIMIENTO", "OPERADOR_MULTIPLICATIVO", "OPERADOR_INCREMENTO",
  "OPERADOR_SIZEOF", "OPERADOR_SELECCION_MIEMBRO", "CONSTANTE_CADENA",
  "CONSTANTE_DECIMAL", "CONSTANTE_OCTAL", "CONSTANTE_HEXADECIMAL",
  "CONSTANTE_REAL", "CONSTANTE_CARACTER", "TIPO_DATO", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "CASE", "DEFAULT", "CONTINUE", "BREAK",
  "RETURN", "GOTO", "'\\n'", "';'", "','", "'='", "'?'", "':'", "'&'",
  "'+'", "'-'", "'*'", "'('", "')'", "'~'", "'!'", "'['", "']'", "'{'",
  "'}'", "$accept", "input", "line", "expresion", "expresionAsignacion",
  "expresionCondicional", "expresionOLogico", "expresionYLogico",
  "expresionOInclusivo", "expresionOExcluyente", "expresionY",
  "expresionIgualdad", "expresionRelacional", "expresionCorrimiento",
  "expresionAditiva", "expresionMultiplicativa", "expresionConversion",
  "expresionUnaria", "operadorUnario", "expresionSufijo",
  "listaArgumentos", "expresionPrimaria", "expresionConstante",
  "constante", "declaracion", "declaracionVariable", "listaDeclaradores",
  "declarador", "inicializador", "listaInicializadores",
  "declaracionFuncion", "listaParametros", "parametro", "decla", "puntero",
  "declaradorDirecto", "sentencia", "sentenciaExpresion", "expresion_",
  "sentenciaCompuesta", "listaDeclaraciones", "listaSentencias",
  "sentenciaSeleccion", "sentenciaEtiquetada", "sentenciaIteracion",
  "sentenciaSalto", "listaArgumentos_", "expresionConstante_",
  "listaParametros_", "listaDeclaraciones_", "listaSentencias_", 0
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
     285,   286,   287,   288,   289,    10,    59,    44,    61,    63,
      58,    38,    43,    45,    42,    40,    41,   126,    33,    91,
      93,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    55,    56,    56,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    69,    69,    70,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    76,    76,    76,    76,    76,    77,    77,    78,
      79,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    90,    91,
      91,    92,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     1,     3,
       1,     3,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     5,     1,     3,     6,
       6,     1,     3,     2,     0,     1,     2,     2,     1,     2,
       1,     4,     1,     1,     1,     1,     1,     1,     2,     0,
       1,     4,     1,     2,     1,     2,     5,     7,     5,     4,
       3,     3,     5,     7,     9,     2,     2,     3,     3,     0,
       1,     0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    57,     0,     0,    59,    62,    63,
      64,    65,    66,    84,     0,     0,     0,    99,     0,     0,
       0,     0,     0,    99,     0,    44,    46,    47,    45,     0,
      48,    49,   125,     3,   100,     8,    10,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    34,    37,     0,
      39,    50,    58,     0,    67,    68,     0,    92,     0,    93,
      94,    97,    95,    96,     6,     7,    99,    57,     0,    40,
       0,    42,    90,     0,    88,     0,    70,    72,     0,    85,
       0,     0,     0,     0,    99,    61,    37,     0,    99,   115,
     116,     0,     0,     0,     0,   102,   126,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    54,     0,   119,     0,     4,
       5,    98,   111,     0,   123,    90,    87,    89,    69,    84,
       0,    86,   121,     0,     0,     0,     0,     0,    99,   110,
     117,   118,     0,    60,   103,   104,    99,     0,     9,    16,
       0,    18,    20,    22,    24,    26,    28,    30,    32,    33,
      36,    35,    12,    11,    53,    55,   120,     0,     0,    43,
      84,   124,    81,     0,    71,     0,    74,    73,   122,     0,
      99,    99,    99,     0,    99,   109,    38,   105,   101,     0,
       0,    52,    51,    83,     0,     0,    77,     0,    91,   106,
     108,   112,     0,     0,    14,    56,    82,    79,    80,     0,
      75,    99,     0,    99,    77,     0,   107,   113,     0,     0,
      76,    99,    78,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     166,    51,    87,    52,    53,    54,    75,    76,   177,   197,
      55,   171,   172,    77,    78,    79,    56,    57,    58,    59,
      96,   146,    60,    61,    62,    63,   167,   179,   173,    97,
     147
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,   189,  -164,    58,   -12,   383,   395,  -164,  -164,  -164,
    -164,  -164,  -164,     4,    21,    25,    31,   311,    36,   431,
      48,    15,    59,   431,   109,  -164,  -164,  -164,  -164,   125,
    -164,  -164,    98,  -164,    86,  -164,  -164,    11,   118,   119,
     117,    90,   123,   124,   122,   -29,    67,  -164,    14,   431,
      29,  -164,  -164,   100,  -164,  -164,   101,  -164,   112,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,   311,  -164,   431,  -164,
     347,  -164,    92,   146,   106,     3,  -164,   113,   146,   103,
     431,   431,   431,   127,   431,  -164,  -164,   114,   311,  -164,
    -164,   121,   135,   115,   -15,  -164,    98,   225,   431,   431,
     431,   431,   431,   431,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,  -164,  -164,   152,   431,   431,  -164,
    -164,  -164,  -164,   128,   136,  -164,   103,  -164,  -164,    24,
      16,   103,   431,    40,    50,    73,   131,   141,   311,  -164,
    -164,  -164,   431,  -164,  -164,  -164,   268,   107,  -164,   118,
      52,   119,   117,    90,   123,   124,   122,   -29,    67,    67,
    -164,  -164,  -164,  -164,  -164,  -164,   142,   132,    32,  -164,
      24,   143,  -164,   137,  -164,    16,  -164,  -164,  -164,   110,
     311,   311,   311,   431,   431,  -164,  -164,  -164,  -164,   431,
     431,  -164,  -164,  -164,   136,   -25,  -164,   -28,  -164,   157,
    -164,  -164,    76,   148,  -164,  -164,  -164,  -164,  -164,    16,
    -164,   311,   149,   431,  -164,    38,  -164,  -164,   140,    16,
    -164,   311,  -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,   -27,   -92,   -14,  -164,    83,    87,    91,
      93,    94,    95,    89,   120,     6,   -26,    -2,  -164,  -164,
    -164,  -164,    65,  -164,   -24,  -164,  -164,    70,  -163,    -8,
    -164,  -164,    19,    54,   155,   -63,   -17,  -164,   -22,    66,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -129
static const yytype_int16 yytable[] =
{
      83,    91,    94,    69,    71,    85,   148,    72,    95,   209,
     126,   207,   196,   108,   109,   131,    99,    86,   112,    67,
     162,   163,    98,   114,   210,   165,    32,   125,    66,     5,
       6,   143,     7,     8,     9,    10,    11,    12,   176,   128,
     129,    94,   115,    94,   116,    73,   214,    86,    74,   122,
     100,    89,   113,   133,   134,   135,   222,    25,    26,    27,
      28,    29,   137,    30,    31,    73,    80,   175,    74,    98,
      81,   139,   144,   150,   117,   219,    82,    98,   118,   110,
     145,    84,   192,   176,   160,   161,   180,    98,    88,    98,
     220,   168,   189,    64,    65,    90,   181,    86,   205,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      98,   111,    92,    98,   158,   159,   186,   176,    85,   182,
      13,   185,   212,    98,   101,   103,   102,   176,    67,   187,
      86,   104,   105,   107,   106,   119,   120,   124,     5,     6,
      86,     7,     8,     9,    10,    11,    12,    93,   121,   125,
      74,   130,   132,   136,   138,   164,   202,   140,   170,   188,
     198,   142,   203,   199,   200,   201,    25,    26,    27,    28,
      29,   141,    30,    31,   169,   204,   183,   184,   191,   190,
     194,   211,   149,   195,   213,   217,   221,    86,   151,     2,
       3,   218,     4,   152,   216,   156,   153,   178,   154,   174,
     155,   215,     5,     6,   223,     7,     8,     9,    10,    11,
      12,    13,    14,   206,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   193,   -99,     0,   157,     4,   127,
      25,    26,    27,    28,    29,     0,    30,    31,     5,     6,
      32,     7,     8,     9,    10,    11,    12,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,   208,     0,     0,     0,     0,    25,    26,    27,    28,
      29,     4,    30,    31,     0,     0,    32,  -127,     0,     0,
       0,     5,     6,     0,     7,     8,     9,    10,    11,    12,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,     4,    30,    31,     0,     0,    32,
    -128,     0,     0,     0,     5,     6,     0,     7,     8,     9,
      10,    11,    12,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
      67,     0,    25,    26,    27,    28,    29,     0,    30,    31,
       5,     6,    32,     7,     8,     9,    10,    11,    12,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    25,    26,
      27,    28,    29,     0,    30,    31,     5,     6,    67,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     5,     6,
       0,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    68,     0,
      30,    31,     0,     0,    67,     0,    25,    26,    27,    28,
      70,     0,    30,    31,     5,     6,     0,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,     0,    30,    31
};

static const yytype_int16 yycheck[] =
{
      17,    23,    29,     5,     6,    19,    98,     3,    32,    37,
      73,    36,   175,    42,    43,    78,     5,    19,     4,     3,
     112,   113,    37,    49,    52,   117,    51,     3,    40,    13,
      14,    46,    16,    17,    18,    19,    20,    21,   130,    36,
      37,    68,    13,    70,    15,    41,   209,    49,    44,    66,
      39,    36,    38,    80,    81,    82,   219,    41,    42,    43,
      44,    45,    84,    47,    48,    41,    45,    51,    44,    37,
      45,    88,    96,   100,    45,    37,    45,    37,    49,    12,
      97,    45,    50,   175,   110,   111,    46,    37,    40,    37,
      52,   118,    40,    35,    36,    36,    46,    99,   190,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      37,    44,     3,    37,   108,   109,   142,   209,   132,    46,
      22,   138,    46,    37,     6,     8,     7,   219,     3,   146,
     132,    41,     9,    11,    10,    35,    35,    45,    13,    14,
     142,    16,    17,    18,    19,    20,    21,    22,    36,     3,
      44,    38,    49,    26,    40,     3,   183,    36,    22,    52,
      50,    46,   184,   180,   181,   182,    41,    42,    43,    44,
      45,    36,    47,    48,    46,   189,    45,    36,    46,    37,
      37,    24,    99,    46,    36,    36,    46,   189,   101,     0,
       1,   213,     3,   102,   211,   106,   103,   132,   104,   129,
     105,   209,    13,    14,   221,    16,    17,    18,    19,    20,
      21,    22,    23,   194,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   170,    36,    -1,   107,     3,    74,
      41,    42,    43,    44,    45,    -1,    47,    48,    13,    14,
      51,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,   195,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,     3,    47,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,     3,    47,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
       3,    -1,    41,    42,    43,    44,    45,    -1,    47,    48,
      13,    14,    51,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    41,    42,
      43,    44,    45,    -1,    47,    48,    13,    14,     3,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      47,    48,    -1,    -1,     3,    -1,    41,    42,    43,    44,
      45,    -1,    47,    48,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    -1,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,    13,    14,    16,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    41,    42,    43,    44,    45,
      47,    48,    51,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    74,    76,    77,    78,    83,    89,    90,    91,    92,
      95,    96,    97,    98,    35,    36,    40,     3,    45,    70,
      45,    70,     3,    41,    44,    79,    80,    86,    87,    88,
      45,    45,    45,    89,    45,    58,    70,    75,    40,    36,
      36,    91,     3,    22,    56,    77,    93,   102,    37,     5,
      39,     6,     7,     8,    41,     9,    10,    11,    42,    43,
      12,    44,     4,    38,    69,    13,    15,    45,    49,    35,
      35,    36,    89,    22,    45,     3,    88,    87,    36,    37,
      38,    88,    49,    56,    56,    56,    26,    91,    40,    89,
      36,    36,    46,    46,    77,    89,    94,   103,    57,    60,
      56,    61,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    69,    57,    57,     3,    57,    73,    99,    56,    46,
      22,    84,    85,   101,    80,    51,    57,    81,    75,   100,
      46,    46,    46,    45,    36,    89,    69,    89,    52,    40,
      37,    46,    50,    86,    37,    46,    81,    82,    50,    89,
      89,    89,    56,    91,    58,    57,    85,    36,    92,    37,
      52,    24,    46,    36,    81,    82,    89,    36,    91,    37,
      52,    46,    81,    89
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
#line 75 "../src/integrador.y"
    { numeroLinea++; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 76 "../src/integrador.y"
    { numeroLinea++; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 77 "../src/integrador.y"
    { strcpy((yyval.cadena), (yyvsp[(1) - (2)].cadena)); printf("\n***Error sintactico - Linea %i: %s***\n", numeroLinea, (yyvsp[(1) - (2)].cadena)); numeroLinea++; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 78 "../src/integrador.y"
    { strcpy((yyval.cadena), (yyvsp[(1) - (2)].cadena)); printf("\n***Error sintactico - Linea %i: %s***\n", numeroLinea, (yyvsp[(1) - (2)].cadena)); numeroLinea++; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 192 "../src/integrador.y"
    {printf("de tipo %s.", (yyvsp[(1) - (3)].cadena));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 195 "../src/integrador.y"
    { printf("\nSe declaro una variable ");    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 196 "../src/integrador.y"
    { printf("y otra variable ");               ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 200 "../src/integrador.y"
    { printf("y se inicializo.\n"); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 214 "../src/integrador.y"
    { printf("\nSe declaro una funcion\n"); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 215 "../src/integrador.y"
    { printf("\nSe definio una funcion\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 238 "../src/integrador.y"
    { printf("\nSe declaro un arreglo\n");  ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 253 "../src/integrador.y"
    { printf("\nSentencia expresion - VACIA.\n");   ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 254 "../src/integrador.y"
    { printf("\nSentencia expresion\n");   ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 256 "../src/integrador.y"
    { printf("\nSentencia expresion - COMPUESTA.\n");   ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 267 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - IF.\n");         ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 268 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - IF/ELSE.\n");    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 269 "../src/integrador.y"
    { printf("\nSentencia de SELECCION - SWITCH.\n");     ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 276 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - WHILE.\n");      ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 277 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - DO/WHILE.\n");   ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 278 "../src/integrador.y"
    { printf("\nSentencia de ITERACION - FOR.\n");        ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 281 "../src/integrador.y"
    { printf("\nSentencia de SALTO - CONTINUE.\n");   ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 282 "../src/integrador.y"
    { printf("\nSentencia de SALTO - BREAK.\n");      ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 283 "../src/integrador.y"
    { printf("\nSentencia de SALTO - RETURN.\n");     ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 284 "../src/integrador.y"
    { printf("\nSentencia de SALTO - GOTO.\n");       ;}
    break;



/* Line 1455 of yacc.c  */
#line 1813 "integrador.tab.c"
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
#line 313 "../src/integrador.y"


int main() {

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif 
    
    yyin = fopen("test.c", "r");
    yyparse();
}
