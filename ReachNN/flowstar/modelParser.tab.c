/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "modelParser.y" /* yacc.c:339  */

	/*---
	Flow*: A Verification Tool for Cyber-Physical Systems.
	Authors: Xin Chen, Sriram Sankaranarayanan, and Erika Abraham.
	Email: Xin Chen <chenxin415@gmail.com> if you have questions or comments.

	The code is released as is under the GNU General Public License (GPL).
	---*/


	#include "modelParser.h"

	extern int yyerror(const char *);
	extern int yyerror(std::string);
	extern int yylex();
	extern int yyparse();
	bool err;

	int lineNum = 1;

	std::vector<flowstar::Flowpipe> initialSets;

	void parseError(const char *str, int lnum)
	{
		std::cerr << "Error @line " << lineNum << ":" << std::string(str) << std::endl;
		exit(1);
	}

#line 95 "modelParser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "modelParser.tab.h".  */
#ifndef YY_YY_MODELPARSER_TAB_H_INCLUDED
# define YY_YY_MODELPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    IDENT = 259,
    STATEVAR = 260,
    TMVAR = 261,
    TM = 262,
    EQ = 263,
    GEQ = 264,
    LEQ = 265,
    ASSIGN = 266,
    END = 267,
    MODE = 268,
    INIT = 269,
    BELONGSTO = 270,
    PARAAGGREG = 271,
    INTAGGREG = 272,
    TMAGGREG = 273,
    OUTPUT = 274,
    NOOUTPUT = 275,
    CONTINUOUS = 276,
    HYBRID = 277,
    SETTING = 278,
    FIXEDST = 279,
    FIXEDORD = 280,
    ADAPTIVEST = 281,
    ADAPTIVEORD = 282,
    ORDER = 283,
    MIN = 284,
    MAX = 285,
    REMEST = 286,
    INTERVAL = 287,
    OCTAGON = 288,
    GRID = 289,
    PLOT = 290,
    QRPRECOND = 291,
    IDPRECOND = 292,
    TIME = 293,
    MODES = 294,
    JUMPS = 295,
    INV = 296,
    GUARD = 297,
    RESET = 298,
    START = 299,
    MAXJMPS = 300,
    PRINTON = 301,
    PRINTOFF = 302,
    UNSAFESET = 303,
    CONTINUOUSFLOW = 304,
    HYBRIDFLOW = 305,
    TAYLOR_PICARD = 306,
    TAYLOR_REMAINDER = 307,
    TAYLOR_POLYNOMIAL = 308,
    EXP = 309,
    SIN = 310,
    COS = 311,
    LOG = 312,
    SQRT = 313,
    ODE = 314,
    CUTOFF = 315,
    PRECISION = 316,
    GNUPLOT = 317,
    MATLAB = 318,
    COMPUTATIONPATHS = 319,
    LTIODE = 320,
    LTVODE = 321,
    PAR = 322,
    UNC = 323,
    UNIVARIATE_POLYNOMIAL = 324,
    MULTIVARIATE_POLYNOMIAL = 325,
    TIME_INV = 326,
    TIME_VAR = 327,
    STEP = 328,
    TRUE = 329,
    FALSE = 330,
    LINEARCONTINUOUSFLOW = 331,
    EXPRESSION = 332,
    MATRIX = 333,
    uminus = 334
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "modelParser.y" /* yacc.c:355  */

	double															dblVal;
	int																intVal;
	std::string														*identifier;
	std::vector<flowstar::Interval>									*intVec;
	std::vector<std::vector<flowstar::Interval> >					*intsVec;
	flowstar::Polynomial<flowstar::Interval>						*intPoly;
	flowstar::Polynomial<flowstar::Real>							*realPoly;
	flowstar::UnivariatePolynomial<flowstar::Real>					*uniPoly;
	std::vector<flowstar::Polynomial<flowstar::Interval> >			*intPolyVec;
	std::vector<flowstar::UnivariatePolynomial<flowstar::Real> >	*uniPolyVec;
	std::vector<flowstar::Flowpipe>									*flowpipeVec;
	std::vector<flowstar::Constraint>								*constraintVec;
	flowstar::TaylorModelVec<flowstar::Real>						*taylorModelVec;
	flowstar::Expression_AST<flowstar::Interval>					*pIntExpression;
	std::vector<flowstar::Expression_AST<flowstar::Interval> >		*intExpressionVec;
	LTI_Term														*pLTITerm;
	LTI_ODE_description												*pLTIDescription;
	LTV_Term														*pLTVTerm;
	LTV_ODE_description												*pLTVDescription;

#line 237 "modelParser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MODELPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "modelParser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    93,
      87,    88,    81,    79,    90,    80,     2,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    91,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,     2,    86,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    83
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   240,   290,   296,   304,   312,   320,   325,
     333,   350,   356,   375,   384,   392,   400,   408,   413,   421,
     438,   444,   460,   467,   475,   483,   488,   496,   502,   508,
     515,   522,   527,   535,   541,   547,   553,   559,   569,   595,
     623,   635,   648,   667,   672,   685,   700,   732,   764,   798,
     815,   831,   855,   883,   912,   941,   971,  1000,  1029,  1061,
    1068,  1075,  1082,  1090,  1095,  1102,  1122,  1129,  1139,  1149,
    1174,  1181,  1188,  1197,  1204,  1209,  1220,  1225,  1230,  1243,
    1258,  1270,  1284,  1311,  1318,  1343,  1370,  1378,  1386,  1391,
    1399,  1416,  1422,  1440,  1446,  1471,  1477,  1491,  1505,  1521,
    1538,  1557,  1576,  1582,  1591,  1604,  1620,  1651,  1685,  1703,
    1721,  1741,  1762,  1791,  1819
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "IDENT", "STATEVAR", "TMVAR",
  "TM", "EQ", "GEQ", "LEQ", "ASSIGN", "END", "MODE", "INIT", "BELONGSTO",
  "PARAAGGREG", "INTAGGREG", "TMAGGREG", "OUTPUT", "NOOUTPUT",
  "CONTINUOUS", "HYBRID", "SETTING", "FIXEDST", "FIXEDORD", "ADAPTIVEST",
  "ADAPTIVEORD", "ORDER", "MIN", "MAX", "REMEST", "INTERVAL", "OCTAGON",
  "GRID", "PLOT", "QRPRECOND", "IDPRECOND", "TIME", "MODES", "JUMPS",
  "INV", "GUARD", "RESET", "START", "MAXJMPS", "PRINTON", "PRINTOFF",
  "UNSAFESET", "CONTINUOUSFLOW", "HYBRIDFLOW", "TAYLOR_PICARD",
  "TAYLOR_REMAINDER", "TAYLOR_POLYNOMIAL", "EXP", "SIN", "COS", "LOG",
  "SQRT", "ODE", "CUTOFF", "PRECISION", "GNUPLOT", "MATLAB",
  "COMPUTATIONPATHS", "LTIODE", "LTVODE", "PAR", "UNC",
  "UNIVARIATE_POLYNOMIAL", "MULTIVARIATE_POLYNOMIAL", "TIME_INV",
  "TIME_VAR", "STEP", "TRUE", "FALSE", "LINEARCONTINUOUSFLOW",
  "EXPRESSION", "MATRIX", "'+'", "'-'", "'*'", "'/'", "uminus", "'^'",
  "'{'", "'}'", "'('", "')'", "'['", "','", "']'", "':'", "'\\''",
  "$accept", "model", "multivariate_polynomial", "univariate_polynomial",
  "expression", "continuous", "stateVarDecls", "stateIdDeclList",
  "setting", "remainder_estimation", "remainders", "plotting",
  "output_env", "printing", "ode", "init", "interval_vector",
  "set_of_interval_vectors", "unsafe_setting", "constraints", "tmVarDecls",
  "tmIdDeclList", "continuous_flowpipes", "vector_of_Taylor_models",
  "domain_setting", "Taylor_model_polynomial", "lti_ode", "lti_polynomial",
  "lti_term", "tv_par_list", "ltv_ode", "ltv_polynomial", "ltv_term", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    43,
      45,    42,    47,   334,    94,   123,   125,    40,    41,    91,
      44,    93,    58,    39
};
# endif

#define YYPACT_NINF -311

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-311)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    46,   -73,   -11,    -1,    99,     0,  -311,    27,   115,
      14,    11,  -311,   150,   160,   116,   144,    94,   167,  -311,
    -311,    14,    14,   151,   179,  -311,  -311,   113,   139,   145,
     157,   169,    11,    11,   201,   171,   206,   210,   217,   234,
     244,   251,   261,  -311,   222,   188,   190,   143,   182,    14,
      14,    14,   272,  -311,    11,    11,    11,    11,    11,   192,
      83,   189,    11,    11,    11,    11,   274,  -311,   191,   193,
     276,   194,   195,   278,   218,   202,  -311,    81,  -311,   283,
     -45,   -45,   190,  -311,    97,   107,   117,   127,   137,  -311,
     285,    59,    59,   192,   192,  -311,   286,   287,   199,   288,
     289,   204,   292,  -311,   293,   212,   213,   207,  -311,  -311,
    -311,  -311,  -311,   209,  -311,  -311,   297,  -311,  -311,   298,
     131,     1,   265,   275,    -5,  -311,  -311,  -311,  -311,   290,
     301,  -311,   291,   222,  -311,    -2,   303,   304,   223,   226,
     227,   309,  -311,   310,   266,   313,   294,   228,   314,  -311,
     315,  -311,  -311,   235,  -311,     8,     0,   296,   236,    36,
      37,   230,   -37,    38,   318,  -311,   317,   147,   324,   243,
     237,   319,   238,   320,   321,   247,   331,   245,   322,   333,
     254,   248,   -15,   338,   257,   258,  -311,   335,   260,   339,
     263,    15,   343,  -311,   341,   267,  -311,   264,  -311,    48,
     262,  -311,   346,   295,   327,   323,    39,    11,   268,     3,
     268,  -311,     9,    31,   123,  -311,   271,    15,   268,   354,
     355,  -311,  -311,   357,   270,   360,   361,   362,   352,   187,
    -311,   281,   364,   284,   299,  -311,    24,   367,   133,  -311,
     300,  -311,  -311,  -311,    31,    31,   149,     9,     9,   302,
     123,   305,  -311,   104,    40,   355,   282,   306,   312,   307,
     294,   308,    41,  -311,   356,  -311,   370,  -311,   311,    24,
      24,  -311,   316,   155,    31,    31,    31,   372,   325,  -311,
    -311,   373,  -311,    34,   326,   363,  -311,    42,   376,   378,
     379,   353,     0,   268,  -311,   328,    43,  -311,   381,  -311,
    -311,  -311,    68,    68,   316,  -311,   384,   230,    44,  -311,
    -311,    34,    34,    89,   382,   329,  -311,   330,   332,   131,
     386,   351,   334,   387,  -311,   336,  -311,   380,   340,   161,
      17,    34,    34,   389,   342,   393,  -311,   395,   200,   337,
     396,  -311,   344,  -311,   345,    34,  -311,   399,    74,    74,
     340,  -311,   400,   347,   348,  -311,  -311,  -311,   349,   350,
     401,   268,   358,   359,   402,  -311,   404,   405,   365,   366,
     408,  -311,   368,   374,   375,  -311,  -311,   369,  -311,   409,
     410,  -311,   131,   131,   200,   200,  -311,  -311
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    45,    43,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,    14,
      12,     0,     0,     0,     0,    31,    29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    74,     0,    11,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     8,     0,
       6,     7,     9,    10,     0,     0,     0,     0,     0,    25,
       0,    23,    24,    26,    32,    27,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,    33,    34,
      35,    36,    37,     0,    53,    54,     0,    56,    57,     0,
       0,     0,     0,     0,     0,    13,    30,    55,    58,     0,
       0,    62,     0,    74,    73,     0,     0,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,    66,    95,
       0,    61,    60,     0,    75,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,   104,     0,     0,    79,    77,    83,     0,
       0,    50,     0,     0,     0,     0,     0,     0,    70,     0,
      70,   113,     0,     0,   107,   111,     0,     0,    70,     0,
       0,    83,     3,     0,     0,     0,     0,     0,     0,    65,
      70,     0,    68,    67,   103,   101,     0,     0,    94,    99,
       0,   110,    22,    21,     0,     0,     0,     0,     0,     0,
     106,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    70,     0,    98,     0,     0,
       0,    40,    20,     0,     0,     0,     0,     0,   114,   108,
     109,     0,    41,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,    70,    72,     0,     0,   100,     0,    96,
      97,    17,    15,    16,    18,    19,     0,     0,     0,    93,
      92,     0,     0,     0,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,    71,     0,   112,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,    39,     0,   102,     0,     0,    88,     0,    86,    87,
      89,    90,     0,     0,     0,    63,    64,    46,     0,     0,
       0,    70,     0,     0,     0,    51,     0,     0,     0,     0,
       0,    85,     0,     0,     0,    69,    42,     0,    84,     0,
       0,    82,     0,     0,     0,     0,    47,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -311,  -311,   110,  -129,   -32,  -311,   407,  -311,  -311,   154,
    -311,  -153,  -310,  -123,   233,  -208,  -201,  -311,   371,  -311,
    -311,  -311,  -311,   205,   170,  -175,  -311,  -311,  -160,  -311,
     148,   211,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    24,   246,    35,    17,     6,     8,   106,   156,
     182,    15,   133,   357,   159,   231,   232,   233,    76,   121,
     180,   197,   199,   220,   254,   348,   160,   238,   239,   162,
     163,   214,   215
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      59,    60,   240,   167,    25,    26,   234,   235,   145,   338,
     251,   165,     9,   211,    25,    26,   241,    19,    20,   211,
     309,   310,    84,    85,    86,    87,    88,   234,   235,   262,
      91,    92,    93,    94,   242,   243,    51,   309,   310,    52,
     170,   172,   177,   170,   285,   264,   285,   264,   177,   175,
       7,   279,   280,   176,   138,    27,    28,    29,    30,    31,
     139,   140,    13,    14,   296,    27,    28,    29,    30,    31,
       1,   201,   384,   385,    10,   202,   267,    62,    63,    64,
      65,    32,    66,   236,    11,   322,     2,   134,    33,   135,
      34,    32,   237,   166,    21,   212,   213,   311,    33,    12,
      34,    22,   213,    23,   312,   104,   347,   105,   313,   299,
     300,   244,   283,   237,   311,   272,   273,    16,   245,   284,
       1,   312,   171,   173,   178,   228,   286,   294,   316,   324,
     327,    46,    47,   221,   222,     3,   328,   329,   129,   321,
      64,    65,     4,    66,    42,   302,   303,   304,    43,   276,
     130,   131,   277,   369,    48,   332,   349,   350,   333,    80,
      81,    82,    62,    63,    64,    65,   132,    66,   330,   331,
     332,    89,   183,   333,   184,   229,    62,    63,    64,    65,
      44,    66,    36,    37,    38,   108,    62,    63,    64,    65,
      45,    66,    39,    40,    41,   109,    62,    63,    64,    65,
      54,    66,   247,   248,    61,   110,    62,    63,    64,    65,
      68,    66,   269,   270,    69,   111,    62,    63,    64,    65,
      70,    66,    49,    50,    51,   112,    55,    52,   274,   275,
     276,    78,    56,   277,   274,   275,   276,   278,    71,   277,
     345,   331,   332,   301,    57,   333,   355,   356,    72,   346,
      62,    63,    64,    65,    73,    66,    58,    67,    49,    50,
      51,   386,   387,    52,    74,    53,    62,    63,    64,    65,
      75,    66,    79,    77,    52,    83,    66,    95,   102,    90,
      98,    96,   101,    97,    99,   100,   107,   103,   113,   116,
     114,   115,   117,   118,   119,   120,   122,   123,   125,   124,
     126,   127,   128,   136,   137,   142,   146,   147,   148,   141,
     143,   149,   150,   151,   152,   153,   154,   158,   157,   161,
     164,   181,   169,   174,   179,   155,   168,   185,   186,   191,
     187,   189,   192,   188,   190,   193,   195,   196,   194,   198,
     200,   203,   204,   207,   205,   208,   216,   209,   210,   217,
     224,   223,   218,   230,   219,   225,   226,   249,   252,   253,
     256,   227,   257,   258,   259,   260,   261,   263,   264,   265,
     268,   295,   288,   290,   297,   305,   340,   307,   315,   317,
     266,   318,   319,   320,   325,   334,   271,   281,   326,   339,
     342,   282,   351,   293,   344,   289,   353,   291,   354,   359,
     277,   298,   362,   363,   368,   372,   306,   373,   374,   366,
     367,   377,   382,   383,   292,   314,    18,   323,   335,   206,
     341,   336,   337,   358,   333,   287,   255,   343,   250,   308,
     361,     0,   352,     0,   360,   379,   380,   364,     0,   365,
       0,     0,     0,     0,     0,     0,     0,     0,   370,     0,
     371,     0,   376,     0,     0,     0,   375,     0,     0,   378,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144
};

static const yytype_int16 yycheck[] =
{
      32,    33,   210,   156,     3,     4,     3,     4,    10,   319,
     218,     3,    85,     4,     3,     4,   212,     3,     4,     4,
       3,     4,    54,    55,    56,    57,    58,     3,     4,   230,
      62,    63,    64,    65,     3,     4,    81,     3,     4,    84,
       4,     4,     4,     4,     4,     4,     4,     4,     4,    86,
       4,   247,   248,    90,    59,    54,    55,    56,    57,    58,
      65,    66,    62,    63,   265,    54,    55,    56,    57,    58,
       5,    86,   382,   383,    85,    90,   236,    79,    80,    81,
      82,    80,    84,    80,    85,   293,    21,    86,    87,   121,
      89,    80,    89,    85,    80,    80,    87,    80,    87,     0,
      89,    87,    87,    89,    87,    24,    89,    26,   283,   269,
     270,    80,     8,    89,    80,   244,   245,    90,    87,    15,
       5,    87,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    21,    22,    85,    86,    70,   311,   312,     7,   292,
      81,    82,    77,    84,    28,   274,   275,   276,     4,    81,
      19,    20,    84,   361,     3,    81,   331,   332,    84,    49,
      50,    51,    79,    80,    81,    82,    35,    84,    79,    80,
      81,    88,    25,    84,    27,   207,    79,    80,    81,    82,
      86,    84,    32,    33,    34,    88,    79,    80,    81,    82,
      23,    84,    32,    33,    34,    88,    79,    80,    81,    82,
      87,    84,    79,    80,     3,    88,    79,    80,    81,    82,
       4,    84,    79,    80,     4,    88,    79,    80,    81,    82,
       3,    84,    79,    80,    81,    88,    87,    84,    79,    80,
      81,    88,    87,    84,    79,    80,    81,    88,     4,    84,
      79,    80,    81,    88,    87,    84,    46,    47,     4,    88,
      79,    80,    81,    82,     3,    84,    87,    86,    79,    80,
      81,   384,   385,    84,     3,    86,    79,    80,    81,    82,
      48,    84,    90,    85,    84,     3,    84,     3,    60,    90,
       4,    90,     4,    90,    90,    90,     3,    85,     3,    90,
       4,     4,     4,     4,    90,     3,     3,    85,    91,    86,
      91,     4,     4,    38,    29,     4,     3,     3,    85,    19,
      19,    85,    85,     4,     4,    49,     3,     3,    90,     4,
      85,     4,    86,    93,     6,    31,    30,     3,    85,     8,
      93,    93,    85,    14,    14,     4,    14,     4,    93,    85,
      92,     3,    85,     8,    86,    85,     3,     8,    85,     8,
       4,    89,    85,    85,    90,    60,    29,    86,     4,     4,
       3,    38,    92,     3,     3,     3,    14,    86,     4,    85,
       3,    15,    90,    61,     4,     3,    25,     4,    15,     3,
      81,     3,     3,    30,     3,     3,    86,    85,     4,     3,
       3,    86,     3,    85,    14,    89,     3,    90,     3,     3,
      84,    90,     3,     3,     3,     3,    81,     3,     3,    60,
      60,     3,     3,     3,   260,    89,     9,    89,    89,   186,
      86,    91,    90,    86,    84,   255,   221,    91,   217,   281,
      85,    -1,    90,    -1,    90,    61,    61,    90,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      91,    -1,    86,    -1,    -1,    -1,    91,    -1,    -1,    91,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    21,    70,    77,    95,   100,     4,   101,    85,
      85,    85,     0,    62,    63,   105,    90,    99,   100,     3,
       4,    80,    87,    89,    96,     3,     4,    54,    55,    56,
      57,    58,    80,    87,    89,    98,    32,    33,    34,    32,
      33,    34,    28,     4,    86,    23,    96,    96,     3,    79,
      80,    81,    84,    86,    87,    87,    87,    87,    87,    98,
      98,     3,    79,    80,    81,    82,    84,    86,     4,     4,
       3,     4,     4,     3,     3,    48,   112,    85,    88,    90,
      96,    96,    96,     3,    98,    98,    98,    98,    98,    88,
      90,    98,    98,    98,    98,     3,    90,    90,     4,    90,
      90,     4,    60,    85,    24,    26,   102,     3,    88,    88,
      88,    88,    88,     3,     4,     4,    90,     4,     4,    90,
       3,   113,     3,    85,    86,    91,    91,     4,     4,     7,
      19,    20,    35,   106,    86,    98,    38,    29,    59,    65,
      66,    19,     4,    19,   112,    10,     3,     3,    85,    85,
      85,     4,     4,    49,     3,    31,   103,    90,     3,   108,
     120,     4,   123,   124,    85,     3,    85,   105,    30,    86,
       4,    86,     4,    86,    93,    86,    90,     4,    86,     6,
     114,     4,   104,    25,    27,     3,    85,    93,    14,    93,
      14,     8,    85,     4,    93,    14,     4,   115,    85,   116,
      92,    86,    90,     3,    85,    86,   108,     8,    85,     8,
      85,     4,    80,    87,   125,   126,     3,     8,    85,    90,
     117,    85,    86,    89,     4,    60,    29,    38,    86,    98,
      85,   109,   110,   111,     3,     4,    80,    89,   121,   122,
     109,   126,     3,     4,    80,    87,    97,    79,    80,    86,
     125,   109,     4,     4,   118,   117,     3,    92,     3,     3,
       3,    14,   110,    86,     4,    85,    81,   122,     3,    79,
      80,    86,    97,    97,    79,    80,    81,    84,    88,   126,
     126,    85,    86,     8,    15,     4,    86,   118,    90,    89,
      61,    90,   103,    85,    86,    15,   110,     4,    90,   122,
     122,    88,    97,    97,    97,     3,    81,     4,   124,     3,
       4,    80,    87,   119,    89,    15,    86,     3,     3,     3,
      30,   105,   109,    89,    86,     3,     4,    86,   119,   119,
      79,    80,    81,    84,     3,    89,    91,    90,   106,     3,
      25,    86,     3,    91,    14,    79,    88,    89,   119,   119,
     119,     3,    90,     3,     3,    46,    47,   107,    86,     3,
      90,    85,     3,     3,    90,    91,    60,    60,     3,   109,
      90,    91,     3,     3,     3,    91,    86,     3,    91,    61,
      61,    91,     3,     3,   106,   106,   107,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   101,   101,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,    13,     4,     4,     3,     3,     3,     3,
       3,     2,     1,     5,     1,     3,     3,     3,     3,     3,
       2,     1,     1,     3,     3,     3,     3,     3,     2,     1,
       5,     1,     3,     4,     4,     4,     4,     4,    13,    16,
      13,    13,    19,     2,     3,     1,    14,    20,    20,     2,
       4,     9,     7,     5,     5,     6,     5,     5,     6,     2,
       3,     3,     1,     1,     1,     5,     0,     1,     1,     8,
       0,     4,     3,     4,     0,     4,     0,     2,     3,     1,
       5,     4,    10,     0,     8,     7,     3,     3,     3,     3,
       3,     2,     1,     1,     5,     0,     3,     3,     2,     1,
       3,     1,     5,     1,     3,     1,     5,     4,     3,     3,
       2,     1,     5,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 116 "modelParser.y" /* yacc.c:1646  */
    {
	int mkres = mkdir(outputDir.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if(mkres < 0 && errno != EEXIST)
	{
		printf("Can not create the directory for output files.\n");
		exit(1);
	}

	mkres = mkdir(imageDir.c_str(), S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	if(mkres < 0 && errno != EEXIST)
	{
		printf("Can not create the directory for images.\n");
		exit(1);
	}

	tmVars.declareVar("local_t");
	for(unsigned int i=0; i<stateVars.varNames.size(); ++i)
	{
		tmVars.declareVar(stateVars.varNames[i] + "_0");
	}

	int result;
	Continuous_Reachability reachability(problem_description);

	clock_t begin, end;
	begin = clock();
	result = reachability.run();
	end = clock();

	printf("\n");

	if(reachability.bSafetyChecking)
	{
		switch(result)
		{
		case COMPLETED_UNSAFE:
			printf("Computation completed: %ld flowpipe(s) computed.\n\n", reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT RED_COLOR "UNSAFE\n\n" RESET_COLOR);
			break;
		case COMPLETED_SAFE:
			printf("Computation completed: %ld flowpipe(s) computed.\n\n", reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT GREEN_COLOR "SAFE\n\n" RESET_COLOR);
			break;
		case COMPLETED_UNKNOWN:
			printf("Computation completed: %ld flowpipe(s) computed.\n\n", reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT BLUE_COLOR "UNKNOWN\n\n" RESET_COLOR);
			break;
		case UNCOMPLETED_UNSAFE:
			printf(BOLD_FONT RED_COLOR "Computation not completed: %ld flowpipe(s) computed.\n" RESET_COLOR, reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Please try smaller step sizes or larger Taylor model orders.\n\n" RESET_COLOR);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT RED_COLOR "UNSAFE\n\n" RESET_COLOR);
			break;
		case UNCOMPLETED_SAFE:
			printf(BOLD_FONT RED_COLOR "Computation not completed: %ld flowpipe(s) computed.\n" RESET_COLOR, reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Please try smaller step sizes or larger Taylor model orders.\n\n" RESET_COLOR);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT GREEN_COLOR "SAFE\n\n" RESET_COLOR);
			break;
		case UNCOMPLETED_UNKNOWN:
			printf(BOLD_FONT RED_COLOR "Computation not completed: %ld flowpipe(s) computed.\n" RESET_COLOR, reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Please try smaller step sizes or larger Taylor model orders.\n\n" RESET_COLOR);
			printf(BOLD_FONT "Result of the safety verification on the computed flowpipes: " RESET_COLOR);
			printf(BOLD_FONT BLUE_COLOR "UNKNOWN\n\n" RESET_COLOR);
			break;
		}

		printf("Total time cost:" BOLD_FONT " %lf" RESET_COLOR " seconds.\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
	}
	else
	{
		if(result == COMPLETED_SAFE)
		{
			printf("Computation completed: %ld flowpipe(s) computed.\n", reachability.result_of_reachability.num_of_flowpipes);
		}
		else
		{
			printf(BOLD_FONT RED_COLOR "Computation not completed: %ld flowpipe(s) computed.\n" RESET_COLOR, reachability.result_of_reachability.num_of_flowpipes);
			printf(BOLD_FONT "Please try smaller step sizes or larger Taylor model orders.\n" RESET_COLOR);
		}

		printf("Total time cost:" BOLD_FONT " %lf" RESET_COLOR " seconds.\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
	}

	if(problem_description.bPlot)
	{
		if(problem_description.bTMOutput)
		{
			reachability.prepareForTMOutput();

			reachability.p_p_setting->bProjected = false;
			reachability.plot_2D();

			std::ofstream os(outputDir + problem_description.fileName + ".flow", std::ofstream::out);

			reachability.tmOutput(os);

			os.close();
		}
		else
		{
			reachability.prepareForPlotting();
		
			reachability.p_p_setting->bProjected = true;
			reachability.plot_2D();
		}
	}
	else
	{
		if(problem_description.bTMOutput)
		{
			reachability.prepareForTMOutput();
			
			std::ofstream os(outputDir + problem_description.fileName + ".flow", std::ofstream::out);
			reachability.tmOutput(os);

			os.close();
		}
	}
}
#line 1732 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 241 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[-9].dblVal) <= 0)
	{
		parseError("The cutoff threshold should be a positive number.", lineNum);
		exit(1);
	}

	problem_description.order_min = (int)(yyvsp[-9].dblVal);

	flowstar::Interval I(-(yyvsp[-7].dblVal),(yyvsp[-7].dblVal));
	problem_description.setCutoff(I);

	reachability_for_outputFile.setup(problem_description);

	clock_t begin, end;
	int checkingResult;
	printf("Safety checking ...\n");
	begin = clock();

	if(reachability_for_outputFile.bSafetyChecking)
	{
		checkingResult = reachability_for_outputFile.safetyChecking();
	}

	end = clock();
	printf("Done.\n");
	printf("Time cost of safety verification:" BOLD_FONT " %lf" RESET_COLOR " seconds.\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
	printf(BOLD_FONT "Result of safety verification: " RESET_COLOR);

	switch(checkingResult)
	{
	case UNSAFE:
		printf(BOLD_FONT RED_COLOR "UNSAFE\n\n" RESET_COLOR);
		break;
	case SAFE:
		printf(BOLD_FONT GREEN_COLOR "SAFE\n\n" RESET_COLOR);
		break;
	case UNKNOWN:
		printf(BOLD_FONT BLUE_COLOR "UNKNOWN\n\n" RESET_COLOR);
		break;
	}

	if(problem_description.bPlot)
	{
		reachability_for_outputFile.p_p_setting->bProjected = false;
		reachability_for_outputFile.plot_2D();
	}
}
#line 1785 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 291 "modelParser.y" /* yacc.c:1646  */
    {
	flowstar::multivariate_polynomial_setting.result = *(yyvsp[-1].intPoly);
	delete (yyvsp[-1].intPoly);
}
#line 1794 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 297 "modelParser.y" /* yacc.c:1646  */
    {
	flowstar::expression_ast_setting.result = *(yyvsp[-1].pIntExpression);
	delete (yyvsp[-1].pIntExpression);
}
#line 1803 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 305 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intPoly) = (yyvsp[-2].intPoly);
	*(yyval.intPoly) += *(yyvsp[0].intPoly);

	delete (yyvsp[0].intPoly);
}
#line 1814 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 313 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intPoly) = (yyvsp[-2].intPoly);
	*(yyval.intPoly) -= *(yyvsp[0].intPoly);

	delete (yyvsp[0].intPoly);
}
#line 1825 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 321 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intPoly) = (yyvsp[-1].intPoly); 
}
#line 1833 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 326 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intPoly) = (yyvsp[-2].intPoly);
	*(yyval.intPoly) *= *(yyvsp[0].intPoly);

	delete (yyvsp[0].intPoly);
}
#line 1844 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 334 "modelParser.y" /* yacc.c:1646  */
    {
	int exp = (int) (yyvsp[0].dblVal);

	if(exp == 0)
	{
		(yyval.intPoly) = new flowstar::Polynomial<flowstar::Interval>(1, stateVars.size() + 1);
	}
	else
	{
		(yyval.intPoly) = new flowstar::Polynomial<flowstar::Interval>;
		(*(yyvsp[-2].intPoly)).pow(*(yyval.intPoly), exp);
	}

	delete (yyvsp[-2].intPoly);
}
#line 1864 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 351 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intPoly) = (yyvsp[0].intPoly);
	*(yyval.intPoly) *= -1;
}
#line 1873 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 357 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	unsigned int numVars = stateVars.size() + 1;
	(yyval.intPoly) = new flowstar::Polynomial<flowstar::Interval>(1, numVars);
	(yyval.intPoly)->mul_assign(id + 1, 1);

	delete (yyvsp[0].identifier);
}
#line 1895 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 376 "modelParser.y" /* yacc.c:1646  */
    {
	unsigned int numVars = stateVars.size() + 1;
	flowstar::Interval I((yyvsp[-3].dblVal), (yyvsp[-1].dblVal));
	(yyval.intPoly) = new flowstar::Polynomial<flowstar::Interval>(I, numVars);
	flowstar::multivariate_polynomial_setting.bDeterministic = false;
	problem_description.bDeterministic = false;
}
#line 1907 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 385 "modelParser.y" /* yacc.c:1646  */
    {
	unsigned int numVars = stateVars.size() + 1;
	(yyval.intPoly) = new flowstar::Polynomial<flowstar::Interval>((yyvsp[0].dblVal), numVars);
}
#line 1916 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 393 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = (yyvsp[-2].uniPoly);
	(*(yyval.uniPoly)) += (*(yyvsp[0].uniPoly));

	delete (yyvsp[0].uniPoly);
}
#line 1927 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 401 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = (yyvsp[-2].uniPoly);
	(*(yyval.uniPoly)) -= (*(yyvsp[0].uniPoly));

	delete (yyvsp[0].uniPoly);
}
#line 1938 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 409 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = (yyvsp[-1].uniPoly); 
}
#line 1946 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 414 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = (yyvsp[-2].uniPoly);
	(*(yyval.uniPoly)) *= (*(yyvsp[0].uniPoly));

	delete (yyvsp[0].uniPoly);
}
#line 1957 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 422 "modelParser.y" /* yacc.c:1646  */
    {
	int exp = (int) (yyvsp[0].dblVal);

	if(exp == 0)
	{
		(yyval.uniPoly) = new flowstar::UnivariatePolynomial<flowstar::Real>(1);
	}
	else
	{
		(yyval.uniPoly) = new flowstar::UnivariatePolynomial<flowstar::Real>;
		(*(yyvsp[-2].uniPoly)).pow(*(yyval.uniPoly), exp);
	}

	delete (yyvsp[-2].uniPoly);
}
#line 1977 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 439 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = (yyvsp[0].uniPoly);
	(*(yyval.uniPoly)) *= -1;
}
#line 1986 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 445 "modelParser.y" /* yacc.c:1646  */
    {
	std::string tVar("t");
	if((yyvsp[0].identifier)->compare(tVar) == 0)
	{
		(yyval.uniPoly) = new flowstar::UnivariatePolynomial<flowstar::Real>(1, 1);
	}
	else
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "The time variable should be denoted by t.");
		parseError(errMsg, lineNum);
		exit(1);
	}
}
#line 2005 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 461 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPoly) = new flowstar::UnivariatePolynomial<flowstar::Real>((yyvsp[0].dblVal));
}
#line 2013 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 468 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-2].pIntExpression);
	(*(yyval.pIntExpression)) += (*(yyvsp[0].pIntExpression));

	delete (yyvsp[0].pIntExpression);
}
#line 2024 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 476 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-2].pIntExpression);
	(*(yyval.pIntExpression)) -= (*(yyvsp[0].pIntExpression));

	delete (yyvsp[0].pIntExpression);
}
#line 2035 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 484 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression); 
}
#line 2043 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 489 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-2].pIntExpression);
	(*(yyval.pIntExpression)) *= (*(yyvsp[0].pIntExpression));

	delete (yyvsp[0].pIntExpression);
}
#line 2054 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 497 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-2].pIntExpression);
	(yyval.pIntExpression)->pow_assign((int)(yyvsp[0].dblVal));
}
#line 2063 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 503 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[0].pIntExpression);
	(yyval.pIntExpression)->inv_assign();
}
#line 2072 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 509 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = new flowstar::Expression_AST<flowstar::Interval>(*(yyvsp[0].identifier), stateVars);

	delete (yyvsp[0].identifier);
}
#line 2082 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 516 "modelParser.y" /* yacc.c:1646  */
    {
	flowstar::Interval I((yyvsp[-3].dblVal), (yyvsp[-1].dblVal));
	(yyval.pIntExpression) = new flowstar::Expression_AST<flowstar::Interval>(I);
	problem_description.bDeterministic = false;
}
#line 2092 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 523 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = new flowstar::Expression_AST<flowstar::Interval>((yyvsp[0].dblVal));
}
#line 2100 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 528 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-2].pIntExpression);
	(*(yyval.pIntExpression)) /= (*(yyvsp[0].pIntExpression));

	delete (yyvsp[0].pIntExpression);
}
#line 2111 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 536 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression);
	(yyval.pIntExpression)->exp_assign();
}
#line 2120 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 542 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression);
	(yyval.pIntExpression)->sin_assign();
}
#line 2129 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 548 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression);
	(yyval.pIntExpression)->cos_assign();
}
#line 2138 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 554 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression);
	(yyval.pIntExpression)->log_assign();
}
#line 2147 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 560 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pIntExpression) = (yyvsp[-1].pIntExpression);
	(yyval.pIntExpression)->sqrt_assign();
}
#line 2156 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 570 "modelParser.y" /* yacc.c:1646  */
    {
	if(problem_description.bDeterministic)
	{
		problem_description.type_of_dynamics = DETERMINISTIC_DYN;
		problem_description.deterministic_dynamics.clear();

		for(unsigned int i=0; i<(yyvsp[-5].intExpressionVec)->size(); ++i)
		{
			flowstar::Expression_AST<Real> tmp;
			(*(yyvsp[-5].intExpressionVec))[i].toReal(tmp);
			problem_description.deterministic_dynamics.push_back(tmp);
		}
	}
	else
	{
		problem_description.type_of_dynamics = NONDETERMINISTIC_DYN;
		problem_description.nondeterministic_dynamics = *(yyvsp[-5].intExpressionVec);
	}

	problem_description.initialSets = *(yyvsp[-1].flowpipeVec);

	delete (yyvsp[-5].intExpressionVec);
	delete (yyvsp[-1].flowpipeVec);
}
#line 2185 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 596 "modelParser.y" /* yacc.c:1646  */
    {
	if(problem_description.bDeterministic)
	{
		problem_description.type_of_dynamics = DETERMINISTIC_DYN;
		problem_description.deterministic_dynamics.clear();

		for(unsigned int i=0; i<(yyvsp[-5].intExpressionVec)->size(); ++i)
		{
			flowstar::Expression_AST<Real> tmp;
			(*(yyvsp[-5].intExpressionVec))[i].toReal(tmp);
			problem_description.deterministic_dynamics.push_back(tmp);
		}
	}
	else
	{
		problem_description.type_of_dynamics = NONDETERMINISTIC_DYN;
		problem_description.nondeterministic_dynamics = *(yyvsp[-5].intExpressionVec);
	}

	problem_description.bSymbolicRemainder = true;
	problem_description.queue_size = (int)(yyvsp[-8].dblVal);
	problem_description.initialSets = *(yyvsp[-1].flowpipeVec);

	delete (yyvsp[-5].intExpressionVec);
	delete (yyvsp[-1].flowpipeVec);
}
#line 2216 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 624 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.type_of_dynamics = LINEAR_TIME_INVARIANT;
	problem_description.rm_dyn_A = (yyvsp[-5].pLTIDescription)->dyn_A;
	problem_description.utm_dyn_B = (yyvsp[-5].pLTIDescription)->dyn_B;

	problem_description.initialSets = *(yyvsp[-1].flowpipeVec);

	delete (yyvsp[-5].pLTIDescription);
	delete (yyvsp[-1].flowpipeVec);
}
#line 2231 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 636 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.type_of_dynamics = LINEAR_TIME_VARYING;
	problem_description.upm_dyn_A = (yyvsp[-5].pLTVDescription)->dyn_A;
	problem_description.upm_dyn_B = (yyvsp[-5].pLTVDescription)->dyn_B;

	problem_description.initialSets = *(yyvsp[-1].flowpipeVec);

	delete (yyvsp[-5].pLTVDescription);
	delete (yyvsp[-1].flowpipeVec);
}
#line 2246 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 649 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.type_of_dynamics = LINEAR_TIME_VARYING;
	problem_description.upm_dyn_A = (yyvsp[-5].pLTVDescription)->dyn_A;
	problem_description.upm_dyn_B = (yyvsp[-5].pLTVDescription)->dyn_B;
	problem_description.upm_dyn_tv = (yyvsp[-5].pLTVDescription)->dyn_tv;

	problem_description.queue_size = (unsigned int)(yyvsp[-8].dblVal);

	problem_description.initialSets = *(yyvsp[-1].flowpipeVec);

	delete (yyvsp[-5].pLTVDescription);
	delete (yyvsp[-1].flowpipeVec);
}
#line 2264 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 668 "modelParser.y" /* yacc.c:1646  */
    {
}
#line 2271 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 673 "modelParser.y" /* yacc.c:1646  */
    {
	if(stateVars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 2287 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 686 "modelParser.y" /* yacc.c:1646  */
    {
	if(stateVars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 2303 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 701 "modelParser.y" /* yacc.c:1646  */
    {
	bool bValid = problem_description.setFixedStepsize((yyvsp[-12].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setFixedOrder((unsigned int)(yyvsp[-6].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setTimeHorizon((yyvsp[-10].dblVal));

	if(!bValid)
		exit(0);

	if((yyvsp[-4].dblVal) <= 0)
	{
		parseError("The cutoff threshold should be positive", lineNum);
		exit(1);
	}

	Interval cutoff_threshold(-(yyvsp[-4].dblVal),(yyvsp[-4].dblVal));
	problem_description.setCutoff(cutoff_threshold);

	bValid = problem_description.setPrecision((yyvsp[-2].dblVal));

	if(!bValid)
		exit(0);
}
#line 2338 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 733 "modelParser.y" /* yacc.c:1646  */
    {
	bool bValid = problem_description.setFixedStepsize((yyvsp[-18].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setAdaptiveOrder((unsigned int)(yyvsp[-10].dblVal), (unsigned int)(yyvsp[-7].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setTimeHorizon((yyvsp[-16].dblVal));

	if(!bValid)
		exit(0);

	if((yyvsp[-4].dblVal) <= 0)
	{
		parseError("The cutoff threshold should be positive", lineNum);
		exit(1);
	}

	Interval cutoff_threshold(-(yyvsp[-4].dblVal),(yyvsp[-4].dblVal));
	problem_description.setCutoff(cutoff_threshold);

	bValid = problem_description.setPrecision((yyvsp[-2].dblVal));

	if(!bValid)
		exit(0);
}
#line 2373 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 765 "modelParser.y" /* yacc.c:1646  */
    {
	bool bValid = problem_description.setAdaptiveStepsize((yyvsp[-16].dblVal), (yyvsp[-13].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setFixedOrder((unsigned int)(yyvsp[-6].dblVal));

	if(!bValid)
		exit(0);

	bValid = problem_description.setTimeHorizon((yyvsp[-10].dblVal));

	if(!bValid)
		exit(0);

	if((yyvsp[-4].dblVal) <= 0)
	{
		parseError("The cutoff threshold should be positive", lineNum);
		exit(1);
	}

	Interval cutoff_threshold(-(yyvsp[-4].dblVal),(yyvsp[-4].dblVal));
	problem_description.setCutoff(cutoff_threshold);

	bValid = problem_description.setPrecision((yyvsp[-2].dblVal));

	if(!bValid)
		exit(0);
}
#line 2408 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 799 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].dblVal) <= 0)
	{
		parseError("Remainder estimation should be a positive number.", lineNum);
		exit(1);
	}

	Interval I(-(yyvsp[0].dblVal), (yyvsp[0].dblVal));
	problem_description.remainder_estimation.clear();

	for(unsigned int i=0; i<stateVars.size(); ++i)
	{
		problem_description.remainder_estimation.push_back(I);
	}
}
#line 2428 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 816 "modelParser.y" /* yacc.c:1646  */
    {
	for(int i=0; i<(yyvsp[-1].intVec)->size(); ++i)
	{
		if((*(yyvsp[-1].intVec))[i].inf() >= (*(yyvsp[-1].intVec))[i].sup() - THRESHOLD_LOW)
		{
			parseError("Invalid remainder estimation.", lineNum);
			exit(0);
		}
	}

	problem_description.setRemainderEstimation(*(yyvsp[-1].intVec));
	delete (yyvsp[-1].intVec);
}
#line 2446 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 832 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intVec) = (yyvsp[-8].intVec);
	int id = stateVars.getIDForVar(*(yyvsp[-6].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-6].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) >= (yyvsp[-1].dblVal))
	{
		parseError("Invalid remainder estimation.", lineNum);
		exit(1);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	(*(yyval.intVec))[id] = I;
	delete (yyvsp[-6].identifier);
}
#line 2473 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 856 "modelParser.y" /* yacc.c:1646  */
    {
	int numVars = stateVars.size();
	(yyval.intVec) = new std::vector<flowstar::Interval>(numVars);

	int id = stateVars.getIDForVar(*(yyvsp[-6].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-6].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) >= (yyvsp[-1].dblVal))
	{
		parseError("Invalid remainder estimation.", lineNum);
		exit(0);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	(*(yyval.intVec))[id] = I;
	delete (yyvsp[-6].identifier);
}
#line 2502 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 884 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_GNUPLOT);
	problem_description.setObjectType(PLOT_INTERVAL);

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2534 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 913 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_GNUPLOT);
	problem_description.setObjectType(PLOT_OCTAGON);

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2566 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 942 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_GNUPLOT);
	problem_description.setObjectType(PLOT_GRID);
	problem_description.setNumOfPieces((unsigned int)(yyvsp[-3].dblVal));

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2599 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 972 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_MATLAB);
	problem_description.setObjectType(PLOT_INTERVAL);

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2631 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1001 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_MATLAB);
	problem_description.setObjectType(PLOT_OCTAGON);

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2663 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1030 "modelParser.y" /* yacc.c:1646  */
    {
	int x = stateVars.getIDForVar(*(yyvsp[-2].identifier));
	int y = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(x < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-2].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	if(y < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	problem_description.setOutputDims(x, y);
	problem_description.setFileType(PLOT_MATLAB);
	problem_description.setObjectType(PLOT_GRID);
	problem_description.setNumOfPieces((unsigned int)(yyvsp[-3].dblVal));

	delete (yyvsp[-2].identifier);
	delete (yyvsp[0].identifier);
}
#line 2696 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1062 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.setFileName(*(yyvsp[0].identifier));
	problem_description.plotOn();
	problem_description.tmOutputOn();
}
#line 2706 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1069 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.setFileName(*(yyvsp[0].identifier));
	problem_description.plotOn();
	problem_description.tmOutputOff();
}
#line 2716 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1076 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.setFileName(*(yyvsp[0].identifier));
	problem_description.plotOff();
	problem_description.tmOutputOn();
}
#line 2726 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1083 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.plotOff();
	problem_description.tmOutputOff();
}
#line 2735 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1091 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.printOn();
}
#line 2743 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1096 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.printOff();
}
#line 2751 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1103 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intExpressionVec) = (yyvsp[-4].intExpressionVec);

	int id = stateVars.getIDForVar(*(yyvsp[-3].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-3].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	(*(yyval.intExpressionVec))[id] = *(yyvsp[0].pIntExpression);

	delete (yyvsp[-3].identifier);
	delete (yyvsp[0].pIntExpression);
}
#line 2774 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1122 "modelParser.y" /* yacc.c:1646  */
    {
	unsigned int numVars = stateVars.size();
	(yyval.intExpressionVec) = new std::vector<flowstar::Expression_AST<flowstar::Interval> >(numVars);
}
#line 2783 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1130 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.flowpipeVec) = new std::vector<flowstar::Flowpipe>();
	for(unsigned int i=0; i<(yyvsp[0].intsVec)->size(); ++i)
	{
		flowstar::Flowpipe initialSet((*(yyvsp[0].intsVec))[i]);
		(yyval.flowpipeVec)->push_back(initialSet);
	}
}
#line 2796 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1140 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.flowpipeVec) = new std::vector<flowstar::Flowpipe>(1);
	flowstar::Flowpipe initialSet(*(yyvsp[0].intVec));
	(*(yyval.flowpipeVec))[0] = initialSet;
	delete (yyvsp[0].intVec);
}
#line 2807 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1150 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[-6].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-6].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) > (yyvsp[-1].dblVal))
	{
		parseError("Invalid interval.", lineNum);
		exit(1);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	(yyval.intVec) = (yyvsp[-7].intVec);
	(*(yyval.intVec))[id] = I;

	delete (yyvsp[-6].identifier);
}
#line 2835 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1174 "modelParser.y" /* yacc.c:1646  */
    {
	int numVars = stateVars.size();
	(yyval.intVec) = new std::vector<flowstar::Interval>(numVars);
}
#line 2844 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1182 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intsVec)->push_back(*(yyvsp[-1].intVec));

	delete (yyvsp[-1].intVec);
}
#line 2854 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1189 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intsVec) = new std::vector<std::vector<flowstar::Interval> >(0);
	(yyval.intsVec)->push_back(*(yyvsp[-1].intVec));

	delete (yyvsp[-1].intVec);
}
#line 2865 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1198 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.safetyCheckingOn();
	problem_description.setUnsafe(*(yyvsp[-1].constraintVec));
	delete (yyvsp[-1].constraintVec);
}
#line 2875 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1204 "modelParser.y" /* yacc.c:1646  */
    {
	problem_description.safetyCheckingOff();
}
#line 2883 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1210 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.constraintVec) = (yyvsp[-3].constraintVec);
	flowstar::Expression_AST<flowstar::Real> realExp;
	(yyvsp[-2].pIntExpression)->toReal(realExp);
	flowstar::Constraint constraint(realExp, (yyvsp[0].dblVal));
	(yyval.constraintVec)->push_back(constraint);

	delete (yyvsp[-2].pIntExpression);
}
#line 2897 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1220 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.constraintVec) = new std::vector<Constraint>();
}
#line 2905 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1226 "modelParser.y" /* yacc.c:1646  */
    {
}
#line 2912 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1231 "modelParser.y" /* yacc.c:1646  */
    {
	if(tmVars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "TM variable %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 2928 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1244 "modelParser.y" /* yacc.c:1646  */
    {
	if(tmVars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "TM variable %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 2944 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1259 "modelParser.y" /* yacc.c:1646  */
    {
	reachability_for_outputFile.result_of_reachability.tmv_flowpipes.push_back(*(yyvsp[-2].taylorModelVec));

	Flowpipe flowpipe;
	flowpipe.domain = *(yyvsp[-1].intVec);
	reachability_for_outputFile.result_of_reachability.nonlinear_flowpipes.push_back(flowpipe);

	delete (yyvsp[-2].taylorModelVec);
	delete (yyvsp[-1].intVec);
}
#line 2959 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1271 "modelParser.y" /* yacc.c:1646  */
    {
	reachability_for_outputFile.result_of_reachability.tmv_flowpipes.push_back(*(yyvsp[-2].taylorModelVec));

	Flowpipe flowpipe;
	flowpipe.domain = *(yyvsp[-1].intVec);
	reachability_for_outputFile.result_of_reachability.nonlinear_flowpipes.push_back(flowpipe);

	delete (yyvsp[-2].taylorModelVec);
	delete (yyvsp[-1].intVec);
}
#line 2974 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1285 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[-8].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-8].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) > (yyvsp[-1].dblVal))
	{
		parseError("Invalid interval remainder.", lineNum);
		exit(1);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	flowstar::TaylorModel<Real> tm(*(yyvsp[-6].realPoly), I);
	(yyval.taylorModelVec) = (yyvsp[-9].taylorModelVec);
	(yyval.taylorModelVec)->tms[id] = tm;

	delete (yyvsp[-8].identifier);
	delete (yyvsp[-6].realPoly);
}
#line 3004 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1311 "modelParser.y" /* yacc.c:1646  */
    {
	std::vector<TaylorModel<Real> > tmv(stateVars.size());
	(yyval.taylorModelVec) = new TaylorModelVec<Real>();
	(yyval.taylorModelVec)->tms = tmv;
}
#line 3014 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1319 "modelParser.y" /* yacc.c:1646  */
    {
	int id = tmVars.getIDForVar(*(yyvsp[-6].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Taylor model variable %s is not declared.", (*(yyvsp[-6].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) > (yyvsp[-1].dblVal))
	{
		parseError("Invalid interval.", lineNum);
		exit(1);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	(yyval.intVec) = (yyvsp[-7].intVec);
	(*(yyval.intVec))[id] = I;

	delete (yyvsp[-6].identifier);
}
#line 3042 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1344 "modelParser.y" /* yacc.c:1646  */
    {
	int id = tmVars.getIDForVar(*(yyvsp[-6].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Taylor model variable %s is not declared.", (*(yyvsp[-6].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	if((yyvsp[-3].dblVal) > (yyvsp[-1].dblVal))
	{
		parseError("Invalid interval.", lineNum);
		exit(1);
	}

	flowstar::Interval I((yyvsp[-3].dblVal),(yyvsp[-1].dblVal));
	(yyval.intVec) = new std::vector<Interval>(tmVars.size());
	(*(yyval.intVec))[id] = I;

	delete (yyvsp[-6].identifier);
}
#line 3070 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1371 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = (yyvsp[-2].realPoly);
	*(yyval.realPoly) += *(yyvsp[0].realPoly);

	delete (yyvsp[0].realPoly);
}
#line 3081 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1379 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = (yyvsp[-2].realPoly);
	*(yyval.realPoly) -= *(yyvsp[0].realPoly);

	delete (yyvsp[0].realPoly);
}
#line 3092 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1387 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = (yyvsp[-1].realPoly); 
}
#line 3100 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1392 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = (yyvsp[-2].realPoly);
	*(yyval.realPoly) *= *(yyvsp[0].realPoly);

	delete (yyvsp[0].realPoly);
}
#line 3111 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1400 "modelParser.y" /* yacc.c:1646  */
    {
	int exp = (int) (yyvsp[0].dblVal);

	if(exp == 0)
	{
		(yyval.realPoly) = new flowstar::Polynomial<flowstar::Real>(1, tmVars.size());
	}
	else
	{
		(yyval.realPoly) = new flowstar::Polynomial<flowstar::Real>();
		(*(yyvsp[-2].realPoly)).pow(*(yyval.realPoly), exp);
	}

	delete (yyvsp[-2].realPoly);
}
#line 3131 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1417 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = (yyvsp[0].realPoly);
	*(yyval.realPoly) *= -1;
}
#line 3140 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1423 "modelParser.y" /* yacc.c:1646  */
    {
	int id = tmVars.getIDForVar(*(yyvsp[0].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Taylor model variable %s is not declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(1);
	}

	(yyval.realPoly) = new flowstar::Polynomial<flowstar::Real>(1, tmVars.size());
	(yyval.realPoly)->mul_assign(id, 1);

	delete (yyvsp[0].identifier);
}
#line 3161 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1441 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.realPoly) = new flowstar::Polynomial<flowstar::Real>((yyvsp[0].dblVal), tmVars.size());
}
#line 3169 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1447 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[-3].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-3].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	unsigned int n = (yyvsp[0].intVec)->size();
	for(unsigned int i=0; i<n-1; ++i)
	{
		(yyval.pLTIDescription)->dyn_A[id][i] = (*(yyvsp[0].intVec))[i].toReal();
	}

	UnivariateTaylorModel<Real> tmp((*(yyvsp[0].intVec)).back());
	(yyval.pLTIDescription)->dyn_B[id][0] = tmp;

	delete (yyvsp[-3].identifier);
	delete (yyvsp[0].intVec);
}
#line 3197 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1471 "modelParser.y" /* yacc.c:1646  */
    {
	unsigned int numVars = stateVars.size();
	(yyval.pLTIDescription) = new LTI_ODE_description(numVars);
}
#line 3206 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1478 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].pLTITerm)->varID >= 0)
	{
		(*(yyval.intVec))[(yyvsp[0].pLTITerm)->varID] += (yyvsp[0].pLTITerm)->coefficient;
	}
	else
	{
		(*(yyval.intVec)).back() += (yyvsp[0].pLTITerm)->coefficient;
	}

	delete (yyvsp[0].pLTITerm);
}
#line 3223 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1492 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].pLTITerm)->varID >= 0)
	{
		(*(yyval.intVec))[(yyvsp[0].pLTITerm)->varID] -= (yyvsp[0].pLTITerm)->coefficient;
	}
	else
	{
		(*(yyval.intVec)).back() -= (yyvsp[0].pLTITerm)->coefficient;
	}

	delete (yyvsp[0].pLTITerm);
}
#line 3240 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1506 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intVec) = new std::vector<Interval>(stateVars.size() + 1);

	if((yyvsp[0].pLTITerm)->varID >= 0)
	{
		(*(yyval.intVec))[(yyvsp[0].pLTITerm)->varID] -= (yyvsp[0].pLTITerm)->coefficient;
	}
	else
	{
		(*(yyval.intVec)).back() -= (yyvsp[0].pLTITerm)->coefficient;
	}

	delete (yyvsp[0].pLTITerm);
}
#line 3259 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1522 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.intVec) = new std::vector<Interval>(stateVars.size() + 1);

	if((yyvsp[0].pLTITerm)->varID >= 0)
	{
		(*(yyval.intVec))[(yyvsp[0].pLTITerm)->varID] += (yyvsp[0].pLTITerm)->coefficient;
	}
	else
	{
		(*(yyval.intVec)).back() += (yyvsp[0].pLTITerm)->coefficient;
	}

	delete (yyvsp[0].pLTITerm);
}
#line 3278 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1539 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(id >= 0)
	{
		(yyval.pLTITerm) = new LTI_Term((yyvsp[-2].dblVal), id, -1);
	}
	else
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Symbol %s is not defined.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 3300 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1558 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(id >= 0)
	{
		(yyval.pLTITerm) = new LTI_Term(1, id, -1);
	}
	else
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Symbol %s is not defined.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 3322 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1577 "modelParser.y" /* yacc.c:1646  */
    {
	Interval I((yyvsp[-3].dblVal), (yyvsp[-1].dblVal));
	(yyval.pLTITerm) = new LTI_Term(I, -1, -1);
}
#line 3331 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1583 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pLTITerm) = new LTI_Term((yyvsp[0].dblVal), -1, -1);
}
#line 3339 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1592 "modelParser.y" /* yacc.c:1646  */
    {
	if(tvPars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Symbol %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 3355 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1605 "modelParser.y" /* yacc.c:1646  */
    {
	if(tvPars.declareVar(*(yyvsp[0].identifier)) < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "Symbol %s has already been declared.", (*(yyvsp[0].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	delete (yyvsp[0].identifier);
}
#line 3371 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1621 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[-3].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-3].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	unsigned int numVars = stateVars.size();
	unsigned int numTVPars = tvPars.size();

	for(unsigned int i=0; i<numVars; ++i)
	{
		(yyval.pLTVDescription)->dyn_A[id][i] = (*(yyvsp[0].uniPolyVec))[i];
	}

	(yyval.pLTVDescription)->dyn_B[id][0] = (*(yyvsp[0].uniPolyVec))[numVars];

	for(unsigned int i=0; i<numTVPars; ++i)
	{
		(yyval.pLTVDescription)->dyn_tv[id][i] = (*(yyvsp[0].uniPolyVec))[i + numTVPars + 1];
	}

	delete (yyvsp[-3].identifier);
	delete (yyvsp[0].uniPolyVec);
}
#line 3405 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1652 "modelParser.y" /* yacc.c:1646  */
    {
	unsigned int numVars = stateVars.size();
	unsigned int numTVPars = tvPars.size();

	(yyval.pLTVDescription) = new LTV_ODE_description(numVars, numTVPars);

	int id = stateVars.getIDForVar(*(yyvsp[-3].identifier));

	if(id < 0)
	{
		char errMsg[MSG_SIZE];
		sprintf(errMsg, "State variable %s is not declared.", (*(yyvsp[-3].identifier)).c_str());
		parseError(errMsg, lineNum);
		exit(0);
	}

	for(unsigned int i=0; i<numVars; ++i)
	{
		(yyval.pLTVDescription)->dyn_A[id][i] = (*(yyvsp[0].uniPolyVec))[i];
	}

	(yyval.pLTVDescription)->dyn_B[id][0] = (*(yyvsp[0].uniPolyVec))[numVars];

	for(unsigned int i=0; i<numTVPars; ++i)
	{
		(yyval.pLTVDescription)->dyn_tv[id][i] = (*(yyvsp[0].uniPolyVec))[i + numVars + 1];
	}

	delete (yyvsp[-3].identifier);
	delete (yyvsp[0].uniPolyVec);
}
#line 3441 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1686 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].pLTVTerm)->varID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->varID] += (yyvsp[0].pLTVTerm)->coefficient;
	}
	else if((yyvsp[0].pLTVTerm)->tvParID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->tvParID + stateVars.size() + 1] += (yyvsp[0].pLTVTerm)->coefficient;
	}
	else
	{
		(*(yyval.uniPolyVec))[stateVars.size()] += (yyvsp[0].pLTVTerm)->coefficient;
	}

	delete (yyvsp[0].pLTVTerm);
}
#line 3462 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1704 "modelParser.y" /* yacc.c:1646  */
    {
	if((yyvsp[0].pLTVTerm)->varID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->varID] -= (yyvsp[0].pLTVTerm)->coefficient;
	}
	else if((yyvsp[0].pLTVTerm)->tvParID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->tvParID + stateVars.size() + 1] -= (yyvsp[0].pLTVTerm)->coefficient;
	}
	else
	{
		(*(yyval.uniPolyVec))[stateVars.size()] -= (yyvsp[0].pLTVTerm)->coefficient;
	}

	delete (yyvsp[0].pLTVTerm);
}
#line 3483 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1722 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPolyVec) = new std::vector<UnivariatePolynomial<Real> >(stateVars.size() + 1 + tvPars.size());

	if((yyvsp[0].pLTVTerm)->varID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->varID] -= (yyvsp[0].pLTVTerm)->coefficient;
	}
	else if((yyvsp[0].pLTVTerm)->tvParID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->tvParID + stateVars.size() + 1] -= (yyvsp[0].pLTVTerm)->coefficient;
	}
	else
	{
		(*(yyval.uniPolyVec))[stateVars.size()] -= (yyvsp[0].pLTVTerm)->coefficient;
	}

	delete (yyvsp[0].pLTVTerm);
}
#line 3506 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1742 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.uniPolyVec) = new std::vector<UnivariatePolynomial<Real> >(stateVars.size() + 1 + tvPars.size());

	if((yyvsp[0].pLTVTerm)->varID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->varID] += (yyvsp[0].pLTVTerm)->coefficient;
	}
	else if((yyvsp[0].pLTVTerm)->tvParID >= 0)
	{
		(*(yyval.uniPolyVec))[(yyvsp[0].pLTVTerm)->tvParID + stateVars.size() + 1] += (yyvsp[0].pLTVTerm)->coefficient;
	}
	else
	{
		(*(yyval.uniPolyVec))[stateVars.size()] += (yyvsp[0].pLTVTerm)->coefficient;
	}

	delete (yyvsp[0].pLTVTerm);
}
#line 3529 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1763 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(id >= 0)
	{
		(yyval.pLTVTerm) = new LTV_Term(*(yyvsp[-3].uniPoly), id, -1, -1);
	}
	else
	{
		id = tvPars.getIDForVar(*(yyvsp[0].identifier));

		if(id >= 0)
		{
			(yyval.pLTVTerm) = new LTV_Term(*(yyvsp[-3].uniPoly), -1, -1, id);
		}
		else
		{
			char errMsg[MSG_SIZE];
			sprintf(errMsg, "Symbol %s is not defined.", (*(yyvsp[0].identifier)).c_str());
			parseError(errMsg, lineNum);
			exit(0);
		}
	}

	delete (yyvsp[-3].uniPoly);
	delete (yyvsp[0].identifier);
}
#line 3561 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1792 "modelParser.y" /* yacc.c:1646  */
    {
	int id = stateVars.getIDForVar(*(yyvsp[0].identifier));

	if(id >= 0)
	{
		(yyval.pLTVTerm) = new LTV_Term(1, id, -1, -1);
	}
	else
	{
		id = tvPars.getIDForVar(*(yyvsp[0].identifier));

		if(id >= 0)
		{
			(yyval.pLTVTerm) = new LTV_Term(1, -1, -1, id);
		}
		else
		{
			char errMsg[MSG_SIZE];
			sprintf(errMsg, "Symbol %s is not defined.", (*(yyvsp[0].identifier)).c_str());
			parseError(errMsg, lineNum);
			exit(0);
		}
	}

	delete (yyvsp[0].identifier);
}
#line 3592 "modelParser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1820 "modelParser.y" /* yacc.c:1646  */
    {
	(yyval.pLTVTerm) = new LTV_Term(*(yyvsp[-1].uniPoly), -1, -1, -1);
	delete (yyvsp[-1].uniPoly);
}
#line 3601 "modelParser.tab.c" /* yacc.c:1646  */
    break;


#line 3605 "modelParser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1835 "modelParser.y" /* yacc.c:1906  */


int yyerror(const char * what)
{
	fprintf(stderr, "Error line %d: %s\n", lineNum, what);
	err = true;
	return 1;
}

int yyerror(std::string what)
{
	std::cerr << "Error line "<< lineNum << " " << what << std::endl;
	err = true;
	return 1;
}
