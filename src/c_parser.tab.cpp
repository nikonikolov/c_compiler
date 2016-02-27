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

#line 67 "src/c_parser.tab.cpp" /* yacc.c:339  */

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
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y" /* yacc.c:355  */

  #include <iostream>
  #include <string>  
  #include "helper.hpp"
  #include "DataStructures/Function.h"
  #include "DataStructures/Loop.h"
  #include "DataStructures/Variable.h"
  #include "DataStructures/Conditional.h"
  #include "DataStructures/VarDeclaration.h"
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);

  //extern Function* root;
  

#line 117 "src/c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO = 258,
    DOUBLE = 259,
    INT = 260,
    STRUCT = 261,
    BREAK = 262,
    ELSE = 263,
    LONG = 264,
    SWITCH = 265,
    CASE = 266,
    ENUM = 267,
    REGISTER = 268,
    TYPEDEF = 269,
    CHAR = 270,
    EXTERN = 271,
    RETURN = 272,
    UNION = 273,
    CONST = 274,
    FLOAT = 275,
    SHORT = 276,
    UNSIGNED = 277,
    CONTINUE = 278,
    FOR = 279,
    SIGNED = 280,
    VOID = 281,
    DEFAULT = 282,
    GOTO = 283,
    VOLATILE = 284,
    DO = 285,
    IF = 286,
    STATIC = 287,
    WHILE = 288,
    LSQUARE = 289,
    RSQUARE = 290,
    LBRACKET = 291,
    RBRACKET = 292,
    LCURLY = 293,
    RCURLY = 294,
    THREE_DOTS = 295,
    DOT = 296,
    PTR_OP = 297,
    PLUS_PLUS = 298,
    MINUS_MINUS = 299,
    SIZEOF = 300,
    LSHIFT = 301,
    RSHIFT = 302,
    LESS_OR_EQUAL = 303,
    MORE_OR_EQUAL = 304,
    LOGICAL_EQUALITY = 305,
    LOGICAL_INEQUALITY = 306,
    LOGICAL_AND = 307,
    LOGICAL_OR = 308,
    Q_MARK = 309,
    COLON = 310,
    MULT_EQUALS = 311,
    DIV_EQUALS = 312,
    PERCENT_EQUALS = 313,
    PLUS_EQUALS = 314,
    MINUS_EQUALS = 315,
    LSHIFT_EQUALS = 316,
    RSHIFT_EQUALS = 317,
    AND_EQUALS = 318,
    XOR_EQUALS = 319,
    OR_EQUALS = 320,
    COMMA = 321,
    HASH = 322,
    HASH_HASH = 323,
    SEMI_COLON = 324,
    EQUALS = 325,
    BITWISE_OR = 326,
    BITWISE_AND = 327,
    BITWISE_XOR = 328,
    MULT = 329,
    PLUS = 330,
    MINUS = 331,
    WAVE = 332,
    EXL_MARK = 333,
    DIV = 334,
    PERCENT = 335,
    LOGICAL_MORE = 336,
    LOGICAL_LESS = 337,
    FLOATING_CONST = 338,
    INTEGER_CONST = 339,
    CHAR_CONST = 340,
    IDENTIFIER = 341,
    STRING_LITERAL = 342,
    PREPROCESSOR_INCLUDE = 343,
    EOLINE = 344
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "src/c_parser.y" /* yacc.c:355  */

  char* strval;
  int intval;
  Variable* varptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable>* vector_var_ptr;
  vector<Statement*>* vector_statement_pointers_ptr;
  
  vector<ConditionalCase*>* vector_conditional_case_pointers_ptr;
  
  Function* fn_ptr;
  Statement* statement_ptr;

#line 234 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 100 "src/c_parser.y" /* yacc.c:358  */

  /* put additional C++ code here */
  // Probably a better idea to make root pointer to Program in the end as function will not inherit from statement
  vector<Statement*>* root=NULL;

#line 256 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   320

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   132,   133,   134,   146,   146,   146,   161,
     165,   166,   167,   168,   172,   173,   188,   189,   206,   207,
     208,   209,   210,   211,   214,   215,   220,   221,   222,   223,
     224,   225,   226,   227,   243,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   275,   276,   277,   278,
     279,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   311,   315,   316,   317,   324,   325,   331,   332,   354,
     355,   356,   357,   358,   359,   360,   361,   364,   365,   383,
     384,   387,   388,   392,   394,   398,   399,   400,   410,   411,
     412,   413,   418,   419,   422,   423,   428,   429,   433,   439,
     440,   441,   452,   453
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "DOUBLE", "INT", "STRUCT",
  "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER", "TYPEDEF",
  "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT", "SHORT",
  "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT", "GOTO",
  "VOLATILE", "DO", "IF", "STATIC", "WHILE", "LSQUARE", "RSQUARE",
  "LBRACKET", "RBRACKET", "LCURLY", "RCURLY", "THREE_DOTS", "DOT",
  "PTR_OP", "PLUS_PLUS", "MINUS_MINUS", "SIZEOF", "LSHIFT", "RSHIFT",
  "LESS_OR_EQUAL", "MORE_OR_EQUAL", "LOGICAL_EQUALITY",
  "LOGICAL_INEQUALITY", "LOGICAL_AND", "LOGICAL_OR", "Q_MARK", "COLON",
  "MULT_EQUALS", "DIV_EQUALS", "PERCENT_EQUALS", "PLUS_EQUALS",
  "MINUS_EQUALS", "LSHIFT_EQUALS", "RSHIFT_EQUALS", "AND_EQUALS",
  "XOR_EQUALS", "OR_EQUALS", "COMMA", "HASH", "HASH_HASH", "SEMI_COLON",
  "EQUALS", "BITWISE_OR", "BITWISE_AND", "BITWISE_XOR", "MULT", "PLUS",
  "MINUS", "WAVE", "EXL_MARK", "DIV", "PERCENT", "LOGICAL_MORE",
  "LOGICAL_LESS", "FLOATING_CONST", "INTEGER_CONST", "CHAR_CONST",
  "IDENTIFIER", "STRING_LITERAL", "PREPROCESSOR_INCLUDE", "EOLINE",
  "$accept", "program", "CONSTANT", "declaration", "initialization_list",
  "bracketed_identifier", "assignment_expression_list",
  "equality_expression", "bracketed_const", "COMPARISON_OPERATOR",
  "assignment_expression", "ASSIGNMENT_OPERATOR", "arithmetic_expression",
  "ARITHMETIC_OPERATOR", "fn_declaration", "fn_params_list", "loop",
  "for_loop", "for_loop_decl_statement", "while_loop",
  "if_block_statement", "else_statement_list", "if_statement",
  "else_statement", "compound_statement", "declaration_list",
  "statement_list", "statement", "semi_colon_statement",
  "return_statement", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -25,    13,   -98,   -98,   -14,   -11,   -52,   250,   -98,
     -98,   -98,   -98,   -98,    -7,    21,   -14,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,    84,
     -98,   -14,    37,   250,   -98,    84,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   225,   -98,     4,    33,    -7,    41,   203,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
      84,    15,   -98,   -14,   -98,   -98,   225,   -14,    45,    14,
      20,    46,   -98,   -98,   -98,   250,    18,   -98,   -98,   -98,
     -98,    69,    16,    40,   -98,   -98,   -98,   -98,   104,   -98,
     -98,   163,    22,   -33,   213,   -28,   104,   104,   -98,    75,
      69,   -98,   -98,   -98,   117,   -98,   -98,   186,    52,    41,
     146,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -14,
     -98,    84,    88,    17,   -98,    56,    63,    67,    69,   -98,
     -98,   -98,   -98,   -98,   -98,   225,   -14,    36,   -14,    96,
      75,    75,    75,    44,   -14,   -98,   -14,    38,   -98,   -98,
     -98,   -98,   -98,   -98,    44,    44,   -14,    44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     2,     0,    14,     0,    10,    11,
       1,     5,     4,    14,     0,    64,     0,     9,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    35,     0,
      15,     0,     0,    13,    12,     0,     6,     7,     8,    14,
      24,    47,    48,    34,    62,     0,     0,    47,    48,     0,
      59,    60,    52,    53,    51,    54,    55,    56,    57,    58,
       0,     0,    61,     0,    25,    50,    49,     0,     0,     0,
       0,     0,    91,   101,    92,     0,     0,    96,    65,    66,
      97,    79,     0,     0,    94,    98,    99,    63,     0,   103,
      14,    47,     0,    48,     0,     0,     0,     0,   100,     0,
      80,    81,    90,    93,     0,    89,    95,    47,     0,    48,
       0,    32,    33,    26,    27,    28,    29,    30,    31,     0,
     102,     0,     0,     0,    16,     0,     0,     0,    79,    86,
      87,    82,    88,    23,    18,    22,    76,     0,     0,     0,
       0,     0,     0,    74,    75,    17,    73,     0,    67,    68,
      83,    84,    77,    78,    72,    71,    70,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,     8,   -98,     0,    97,   -69,   -26,   -87,
      -1,   -98,   -23,   -98,   110,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,    24,    25,   -97,   -98,    51,   -24,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    40,     3,     7,    75,   123,    92,    93,   119,
      76,    29,    94,    60,     4,    32,    77,    78,   125,    79,
      80,   100,    81,   101,    62,    82,    83,    84,    85,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,     8,   129,    42,   -19,    14,    43,   121,     5,    48,
      11,     5,    49,    10,    16,    34,    33,    17,     1,   108,
      67,    67,     5,   121,     1,    15,    31,   126,   127,    41,
      30,    44,    68,    68,    42,    47,   -19,    66,    63,    69,
      69,   122,    61,   148,   150,   152,    70,    70,    71,    71,
      95,     5,     5,   137,    72,   102,    96,    68,    13,   106,
      41,     6,   109,    87,    69,   110,     9,     8,    91,    74,
     147,    70,    13,    71,    45,   130,     5,    99,    64,   105,
     106,    88,    97,   138,    73,    73,   139,    98,   107,   133,
     103,   120,    68,   140,   124,    42,    91,    91,   135,    69,
     141,    13,    13,    46,   142,   144,    70,   156,    71,    73,
     138,     5,    12,    61,    89,     0,   149,   151,   153,   134,
      35,    41,    91,   128,    88,   131,    13,     0,    36,    37,
      38,    90,    88,   104,    68,   124,     0,   145,     0,    91,
      88,    69,     0,   124,    73,   124,     0,     0,    70,     0,
      71,     0,     0,     5,     0,   124,   132,   136,     0,     0,
       0,    13,     0,     0,     0,   146,     0,    36,    37,    38,
      39,    36,    37,    38,    90,     0,     0,     0,     0,    36,
      37,    38,    90,    65,     0,     0,    73,    36,    37,    38,
      90,     0,    50,    51,   111,   112,   113,   114,   115,   116,
     -20,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,    52,    53,    54,
      55,    56,    57,    30,     0,    58,    59,   117,   118,     0,
       0,     0,   -20,   143,   111,   112,   113,   114,   115,   116,
      65,   154,     0,   155,   117,   118,     0,     0,     0,    50,
      51,     0,     0,   157,     0,     0,     0,     0,     0,    50,
      51,   111,   112,   113,   114,   115,   116,   117,   118,     0,
       0,    50,    51,     0,    52,    53,    54,    55,    56,    57,
       0,     0,    58,    59,    52,    53,    54,    55,    56,    57,
       0,     0,    58,    59,   117,   118,    52,    53,    54,    55,
      56,    57,     0,     0,    58,    59,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,     0,     0,
      28
};

static const yytype_int16 yycheck[] =
{
       1,     1,    99,    29,    37,     5,    29,    94,    36,    35,
       2,    36,    35,     0,    66,    16,    16,    69,     5,    88,
       5,     5,    36,   110,     5,    36,     5,    96,    97,    29,
      37,    31,    17,    17,    60,    35,    69,    60,     5,    24,
      24,    69,    38,   140,   141,   142,    31,    31,    33,    33,
      36,    36,    36,   122,    39,    39,    36,    17,    86,    83,
      60,    86,    88,    63,    24,    88,    67,    67,    68,    61,
     139,    31,    86,    33,    37,    99,    36,     8,    37,    39,
     104,    36,    36,    66,    69,    69,    69,    69,    88,    37,
      82,    69,    17,    37,    95,   121,    96,    97,   121,    24,
      37,    86,    86,    66,    37,    69,    31,    69,    33,    69,
      66,    36,     2,    38,    69,    -1,   140,   141,   142,   119,
      36,   121,   122,    99,    36,   100,    86,    -1,    83,    84,
      85,    86,    36,    82,    17,   136,    -1,   138,    -1,   139,
      36,    24,    -1,   144,    69,   146,    -1,    -1,    31,    -1,
      33,    -1,    -1,    36,    -1,   156,    39,    69,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    69,    -1,    83,    84,    85,
      86,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    37,    -1,    -1,    69,    83,    84,    85,
      86,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      37,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    71,    72,    73,
      74,    75,    76,    37,    -1,    79,    80,    81,    82,    -1,
      -1,    -1,    69,   136,    48,    49,    50,    51,    52,    53,
      37,   144,    -1,   146,    81,    82,    -1,    -1,    -1,    46,
      47,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    81,    82,    -1,
      -1,    46,    47,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    81,    82,    71,    72,    73,    74,
      75,    76,    -1,    -1,    79,    80,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    91,    93,   104,    36,    86,    94,    95,   100,
       0,    93,   104,    86,    95,    36,    66,    69,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    70,   101,
      37,     5,   105,    95,   100,    36,    83,    84,    85,    86,
      92,    95,    98,   102,    95,    37,    66,    95,    98,   102,
      46,    47,    71,    72,    73,    74,    75,    76,    79,    80,
     103,    38,   114,     5,    37,    37,   102,     5,    17,    24,
      31,    33,    39,    69,    93,    95,   100,   106,   107,   109,
     110,   112,   115,   116,   117,   118,   119,    95,    36,    69,
      86,    95,    97,    98,   102,    36,    36,    36,    69,     8,
     111,   113,    39,    93,   116,    39,   117,    95,    97,    98,
     102,    48,    49,    50,    51,    52,    53,    81,    82,    99,
      69,    99,    69,    96,   100,   108,    97,    97,   112,   114,
     117,   113,    39,    37,    95,   102,    69,    97,    66,    69,
      37,    37,    37,    96,    69,   100,    69,    97,   114,   117,
     114,   117,   114,   117,    96,    96,    69,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    93,
      94,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    97,    97,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   105,   105,   105,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     3,
       1,     1,     3,     3,     1,     3,     1,     3,     3,     1,
       1,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     2,     4,     0,     1,     1,     5,     5,     5,
       4,     4,     4,     3,     3,     3,     2,     5,     5,     1,
       2,     1,     2,     5,     5,     2,     2,     2,     4,     3,
       3,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       2,     1,     3,     2
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
#line 131 "src/c_parser.y" /* yacc.c:1646  */
    { root = new vector<Statement*>; root->push_back((yyvsp[0].statement_ptr));}
#line 1505 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 132 "src/c_parser.y" /* yacc.c:1646  */
    { root = new vector<Statement*>; root->push_back((yyvsp[0].statement_ptr));}
#line 1511 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 133 "src/c_parser.y" /* yacc.c:1646  */
    { root->push_back((yyvsp[0].statement_ptr)); }
#line 1517 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 134 "src/c_parser.y" /* yacc.c:1646  */
    { root->push_back((yyvsp[0].statement_ptr)); }
#line 1523 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 161 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new VarDeclaration(int_type, (yyvsp[-1].vector_var_ptr));}
#line 1529 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr) = new vector<Variable>; (yyval.vector_var_ptr)->push_back(Variable((yyvsp[0].strval)));}
#line 1535 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr) = new vector<Variable>; (yyval.vector_var_ptr)->push_back(Variable((yyvsp[0].strval)));}
#line 1541 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr)->push_back(Variable((yyvsp[0].strval)));}
#line 1547 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr)->push_back(Variable((yyvsp[0].strval)));}
#line 1553 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1559 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 173 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[-1].strval); }
#line 1565 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval)=(yyvsp[-2].strval); }
#line 1571 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 312 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Function(int_type, (yyvsp[-4].strval), (yyvsp[-2].vector_var_ptr), (yyvsp[0].vector_statement_pointers_ptr)); }
#line 1577 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 315 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr) = new vector<Variable>; (yyval.vector_var_ptr)->push_back(Variable(int_type, (yyvsp[0].strval)));}
#line 1583 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 316 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr)->push_back(Variable(int_type, (yyvsp[0].strval))); }
#line 1589 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 317 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_ptr) = NULL; }
#line 1595 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 324 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 1601 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 325 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 1607 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 331 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].vector_statement_pointers_ptr)); }
#line 1613 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 332 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].statement_ptr)); }
#line 1619 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 364 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].vector_statement_pointers_ptr)); }
#line 1625 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 365 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].statement_ptr)); }
#line 1631 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 383 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional((yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 1637 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 384 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional(vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr),(yyvsp[0].vector_conditional_case_pointers_ptr))); }
#line 1643 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 387 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = (yyvsp[0].vector_conditional_case_pointers_ptr); }
#line 1649 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 388 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr), (yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 1655 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 393 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].vector_statement_pointers_ptr))); }
#line 1661 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 395 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr))); }
#line 1667 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 398 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = (yyvsp[0].vector_conditional_case_pointers_ptr); }
#line 1673 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 399 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].vector_statement_pointers_ptr))); }
#line 1679 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 400 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr))); }
#line 1685 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 410 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)=vec_append((yyvsp[-2].vector_statement_pointers_ptr), (yyvsp[-1].vector_statement_pointers_ptr)); }
#line 1691 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 411 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)=(yyvsp[-1].vector_statement_pointers_ptr); }
#line 1697 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 412 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)=(yyvsp[-1].vector_statement_pointers_ptr); }
#line 1703 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 413 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)=NULL; }
#line 1709 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 418 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr) = new vector<Statement*>; (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1715 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 419 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1721 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 422 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr) = new vector<Statement*>; (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1727 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 423 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1733 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 428 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 1739 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 429 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 1745 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 433 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=NULL; }
#line 1751 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1755 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 460 "src/c_parser.y" /* yacc.c:1906  */
  

int yyerror(const char* s){ 
    std::cerr <<"************ Parser error in file: "<< source_file<<" at line: "<<input_file_line << std::endl;
    return -1;
}

int main(){

  yydebug=1;

  cerr<<" ************************** Parsing starts **************************"<<endl;
  yyparse();
  cerr<<"************************** Parsing successful **************************"<<endl;

  if(root==NULL) return 0;

  cerr<<"************************** Printing starts **************************"<<endl;

  vector<Statement*>::iterator it;
  for(it=root->begin(); it!=root->end(); ++it){
    if(*it!=NULL) (*it)->pretty_print(0);
  }

  cerr<<"************************** Printing successful **************************"<<endl;

  return 0;
}





