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
  #include "DataStructures/Program.h"
  #include "DataStructures/Function.h"
  #include "DataStructures/Loop.h"
  #include "DataStructures/Variable.h"
  #include "DataStructures/Constant.h"
  #include "DataStructures/Conditional.h"
  #include "DataStructures/VarDeclaration.h"
  #include "DataStructures/VarExpr.h"
  #include "DataStructures/ReturnStatement.h"
  #include "DataStructures/CompoundStatement.h"
  #include "DataStructures/BaseExpression.h"
  #include "DataStructures/TerneryExpression.h"
  #include "DataStructures/Expression.h"
  #include "DataStructures/AssignmentExpression.h"
  #include "DataStructures/ExpressionStatement.h"
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);

  extern Program* root;



#line 128 "src/c_parser.tab.cpp" /* yacc.c:355  */

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
    INTEGER_CONST = 338,
    FLOATING_CONST = 339,
    CHAR_CONST = 340,
    IDENTIFIER = 341,
    STRING_LITERAL = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "src/c_parser.y" /* yacc.c:355  */

  char* strval;
  uint64_t intval;
  //int intval;
  double64_t floatval;

  Variable* var_ptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable*>*        vector_vars_ptrs_ptr;
  vector<Statement*>*       vector_statement_pointers_ptr;
  vector<Expression*>*      vector_expr_pointers_ptr;
  vector<ConditionalCase*>* vector_conditional_case_pointers_ptr;
  vector<VarDeclaration*>* vector_var_declarations_ptrs_ptr;
  
  Function* fn_ptr;
  Statement* statement_ptr;
  CompoundStatement* compound_statement_ptr;
  BaseExpression* base_expr_ptr;
  ExpressionStatement* expr_statement_ptr;
  VarDeclaration* var_declaration_ptr;

#line 251 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 145 "src/c_parser.y" /* yacc.c:358  */

  /* put additional C++ code here */
  Program* root=NULL;

#line 272 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   699

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

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
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   173,   174,   175,   187,   188,   189,   219,
     220,   221,   241,   243,   258,   259,   263,   264,   270,   276,
     277,   292,   298,   300,   304,   305,   320,   322,   324,   326,
     333,   335,   337,   339,   341,   344,   347,   349,   353,   354,
     361,   363,   365,   367,   369,   372,   376,   378,   380,   382,
     384,   386,   389,   390,   397,   399,   401,   403,   410,   412,
     414,   421,   423,   425,   432,   434,   436,   438,   440,   447,
     449,   451,   458,   460,   467,   469,   476,   478,   485,   487,
     494,   496,   503,   505,   514,   516,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   533,   542,   544,
     569,   573,   575,   576,   580,   581,   587,   588,   589,   592,
     593,   596,   597,   618,   619,   620,   621,   622,   623,   624,
     625,   628,   629,   652,   653,   656,   657,   660,   662,   675,
     676,   690,   691,   692,   693,   697,   698,   701,   702,   707,
     708,   709,   710,   711,   716,   720,   721,   732,   733
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
  "LOGICAL_LESS", "INTEGER_CONST", "FLOATING_CONST", "CHAR_CONST",
  "IDENTIFIER", "STRING_LITERAL", "$accept", "program", "CONSTANT",
  "type_name", "declaration", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "initializer", "initializer_list",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "UNARY_OPERATOR", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "ASSIGNMENT_OPERATOR",
  "expression", "expression_list", "fn_declaration", "fn_params_list",
  "bracketed_identifier", "loop", "do_while_loop", "for_loop",
  "for_loop_decl_statement", "while_loop", "if_block_statement",
  "else_statement_list", "if_statement", "else_statement",
  "compound_statement", "declaration_list", "statement_list", "statement",
  "expression_statement", "semi_colon_statement", "return_statement", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -137

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-137)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -28,    14,  -137,  -137,   -15,  -137,    -8,   -40,  -137,
     -25,  -137,  -137,  -137,  -137,  -137,    -4,    11,   -15,  -137,
     418,  -137,   -14,   -34,  -137,    34,   418,   556,   556,   593,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,    39,   341,   612,  -137,   -56,    16,
       5,   -38,    49,     2,   -26,   -36,    51,    60,  -137,  -137,
     -14,  -137,  -137,    69,   110,  -137,  -137,  -137,    85,  -137,
      88,  -137,    -9,   612,  -137,  -137,   199,  -137,   612,   463,
      44,    46,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,   612,  -137,  -137,   612,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   612,   612,    96,   154,  -137,
     -14,   612,  -137,  -137,   402,    97,   100,  -137,   -24,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,   -56,   -56,    16,    16,
       5,     5,     5,     5,   -38,   -38,    49,     2,   -26,   -36,
      51,    81,  -137,   -21,   482,   120,   350,   121,   122,  -137,
    -137,  -137,  -137,   -35,  -137,  -137,  -137,  -137,  -137,   152,
    -137,   177,   263,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   612,   612,  -137,    93,   519,   131,
     139,   612,   612,   612,  -137,   350,   152,  -137,  -137,  -137,
     286,  -137,  -137,  -137,  -137,  -137,   538,   -29,   136,   138,
     140,   142,   -20,  -137,  -137,  -137,  -137,  -137,   612,    21,
     575,   350,   612,   612,   350,   350,   109,   612,   612,    35,
    -137,  -137,   -12,   -10,  -137,  -137,  -137,  -137,   109,   109,
     612,   108,   111,   109,  -137,  -137
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     2,     0,    13,    19,     0,    14,
      16,    18,     1,     5,     4,    19,     0,   103,     0,    12,
       0,    20,     0,     0,    15,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    51,     7,     6,     8,    26,
      28,    27,    17,    30,    40,    52,     0,    54,    58,    61,
      64,    69,    72,    74,    76,    78,    80,    82,    84,    21,
       0,   104,   101,     0,     0,    10,     9,    11,     0,    97,
       0,    24,     0,     0,    41,    42,     0,    44,     0,     0,
       0,     0,    36,    37,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    86,     0,    52,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,     0,    29,    22,     0,     0,     0,    33,     0,    38,
      34,    35,    85,    55,    56,    57,    59,    60,    62,    63,
      67,    68,    66,    65,    70,    71,    73,    75,    77,    79,
      81,     0,   105,     0,     0,     0,     0,     0,     0,   134,
     146,   135,    98,     0,   139,   108,   106,   107,   140,   123,
     143,     0,     0,   137,   141,   142,   145,   102,    53,    23,
      25,    45,    31,    32,     0,     0,   148,     0,     0,     0,
       0,     0,     0,     0,   144,     0,   124,   125,   133,   136,
       0,   132,   138,    39,    83,   147,     0,     0,     0,     0,
       0,     0,     0,    99,   129,   130,   126,   131,   120,     0,
       0,     0,     0,     0,     0,     0,   118,   119,   117,     0,
     111,   112,     0,     0,   127,   128,   121,   122,   116,   115,
     114,     0,     0,   113,   109,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,  -137,    -2,  -137,   163,   178,  -137,   -22,
    -137,  -137,  -137,  -137,    40,  -137,   -37,    22,    23,   -11,
      19,    75,    76,    78,    82,    74,  -137,    10,   -19,  -137,
     -23,   190,   198,  -137,   -54,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,     6,   -58,  -137,    32,  -136,  -137,  -137,
    -137
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    41,    68,     3,     8,     9,    10,    11,    42,
      72,    43,    44,   128,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    69,    95,
     162,   163,     4,    23,    62,   164,   165,   166,   208,   167,
     168,   196,   169,   197,   170,   171,   172,   173,   174,   175,
     176
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    59,    70,    63,    71,   119,   117,    59,     5,    97,
     105,   106,     1,   183,    12,     5,    22,   225,    98,     1,
     190,     5,    60,    99,   100,   241,    18,   242,    17,    19,
     123,   193,    64,    21,   194,   113,   202,   193,    65,    66,
     220,     6,   184,   107,   108,    20,   193,   112,     6,    67,
      70,   103,   104,    70,   193,   126,   193,   124,     7,   215,
     129,   133,   134,   135,   202,    15,   177,    74,    75,    77,
      25,    15,    61,    78,   111,    79,   132,    27,    28,    29,
      80,    81,    82,    83,   178,   231,    96,   193,   235,   237,
     227,   101,   102,   151,   140,   141,   142,   143,   189,   109,
     110,   193,   180,   114,   240,    59,    30,   118,    31,    32,
      33,    34,    35,   115,   116,   120,   161,    36,    37,    38,
      39,    40,   121,   136,   137,   122,   138,   139,   144,   145,
     130,   187,   131,   152,   181,   182,   185,   214,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,   188,   191,   192,   153,
     195,    96,   205,   230,   209,   203,   234,   236,   211,   199,
     213,   154,   210,   221,   222,   193,   223,   244,   155,   224,
     245,    24,   153,    16,   156,   157,   146,   158,   147,   150,
      25,   148,   118,   159,   154,   204,   149,    27,    28,    29,
      14,   155,   216,   200,   125,     0,     0,   156,   157,     0,
     158,     0,     0,    25,     0,   118,   198,     0,     0,     0,
      27,    28,    29,   160,     0,    96,    30,     0,    31,    32,
      33,    34,    35,     0,     0,    25,     0,    36,    37,    38,
      39,    40,    27,    28,    29,     0,   160,     0,     0,    30,
       0,    31,    32,    33,    34,    35,     0,     0,     0,     0,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,    30,     0,    31,    32,    33,    34,    35,     0,     0,
     154,     0,    36,    37,    38,    39,    40,   155,     0,     0,
       0,     0,     0,   156,   157,     0,   158,     0,     0,    25,
       0,   118,   201,   154,     0,     0,    27,    28,    29,     0,
     155,     0,     0,     0,     0,     0,   156,   157,     0,   158,
       0,     0,    25,     0,   118,   217,     0,     0,     0,    27,
      28,    29,   160,     0,     0,    30,     0,    31,    32,    33,
      34,    35,     0,     0,     0,     0,    36,    37,    38,    39,
      40,     0,     0,     0,     0,   160,     0,     0,    30,     0,
      31,    32,    33,    34,    35,     0,     0,   154,     0,    36,
      37,    38,    39,    40,   155,     0,     0,     0,   207,     0,
     156,   157,   212,   158,     0,     0,    25,     0,   118,     0,
       0,     0,     0,    27,    28,    29,   219,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,   226,     0,
     229,    94,   232,   233,     0,     0,     0,   238,   239,   160,
       0,     0,    30,     0,    31,    32,    33,    34,    35,     0,
     243,     0,     0,    36,    37,    38,    39,    40,    25,     0,
      26,   179,     0,     0,     0,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    25,     0,    26,     0,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    31,    32,    33,    34,
      35,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      30,     0,    31,    32,    33,    34,    35,     0,     0,    25,
     127,    36,    37,    38,    39,    40,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    31,    32,    33,
      34,    35,     0,     0,     0,     0,    36,    37,    38,    39,
      40,   186,     0,     0,    30,    25,    31,    32,    33,    34,
      35,     0,    27,    28,    29,    36,    37,    38,    39,    40,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    27,    28,    29,     0,     0,     0,     0,   206,     0,
       0,    30,    73,    31,    32,    33,    34,    35,     0,    27,
      28,    29,    36,    37,    38,    39,    40,   218,     0,     0,
      30,    25,    31,    32,    33,    34,    35,     0,    27,    28,
      29,    36,    37,    38,    39,    40,     0,     0,    30,    76,
      31,    32,    33,    34,    35,     0,    27,    28,    29,    36,
      37,    38,    39,    40,   228,     0,     0,    30,    25,    31,
      32,    33,    34,    35,     0,    27,    28,    29,    36,    37,
      38,    39,    40,     0,     0,    30,     0,    31,    32,    33,
      34,    35,     0,     0,     0,     0,    36,    37,    38,    39,
      40,     0,     0,     0,    30,     0,    31,    32,    33,    34,
      35,     0,     0,     0,     0,    36,    37,    38,    39,    40
};

static const yytype_int16 yycheck[] =
{
       2,    20,    25,    37,    26,    63,    60,    26,    36,    46,
      48,    49,     5,    37,     0,    36,     5,    37,    74,     5,
     156,    36,    36,    79,    80,    37,    66,    37,    36,    69,
      39,    66,    66,    37,    69,    71,   172,    66,     4,     5,
      69,    69,    66,    81,    82,    70,    66,    73,    69,    15,
      73,    46,    47,    76,    66,    78,    66,    66,    86,   195,
      79,    98,    99,   100,   200,    86,   120,    27,    28,    29,
      36,    86,    86,    34,    72,    36,    95,    43,    44,    45,
      41,    42,    43,    44,   121,   221,    46,    66,   224,   225,
      69,    75,    76,   116,   105,   106,   107,   108,   156,    50,
      51,    66,   124,    52,    69,   124,    72,    38,    74,    75,
      76,    77,    78,    53,    54,     5,   118,    83,    84,    85,
      86,    87,    37,   101,   102,    37,   103,   104,   109,   110,
      86,   154,    86,    37,    37,    35,    55,   195,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    36,    36,    36,     5,
       8,   121,    69,   221,    33,   184,   224,   225,   191,   171,
     193,    17,    33,    37,    36,    66,    36,    69,    24,    37,
      69,    18,     5,     5,    30,    31,   111,    33,   112,   115,
      36,   113,    38,    39,    17,   185,   114,    43,    44,    45,
       2,    24,   196,   171,     5,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,
      43,    44,    45,    69,    -1,   185,    72,    -1,    74,    75,
      76,    77,    78,    -1,    -1,    36,    -1,    83,    84,    85,
      86,    87,    43,    44,    45,    -1,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    78,    -1,    -1,
      17,    -1,    83,    84,    85,    86,    87,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,
      -1,    38,    39,    17,    -1,    -1,    43,    44,    45,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    78,    -1,    -1,    17,    -1,    83,
      84,    85,    86,    87,    24,    -1,    -1,    -1,   188,    -1,
      30,    31,   192,    33,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,    43,    44,    45,   206,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,   218,    -1,
     220,    70,   222,   223,    -1,    -1,    -1,   227,   228,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    78,    -1,
     240,    -1,    -1,    83,    84,    85,    86,    87,    36,    -1,
      38,    39,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      72,    -1,    74,    75,    76,    77,    78,    -1,    -1,    36,
      37,    83,    84,    85,    86,    87,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    69,    -1,    -1,    72,    36,    74,    75,    76,    77,
      78,    -1,    43,    44,    45,    83,    84,    85,    86,    87,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    36,    74,    75,    76,    77,    78,    -1,    43,
      44,    45,    83,    84,    85,    86,    87,    69,    -1,    -1,
      72,    36,    74,    75,    76,    77,    78,    -1,    43,    44,
      45,    83,    84,    85,    86,    87,    -1,    -1,    72,    36,
      74,    75,    76,    77,    78,    -1,    43,    44,    45,    83,
      84,    85,    86,    87,    69,    -1,    -1,    72,    36,    74,
      75,    76,    77,    78,    -1,    43,    44,    45,    83,    84,
      85,    86,    87,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    89,    92,   120,    36,    69,    86,    93,    94,
      95,    96,     0,    92,   120,    86,    95,    36,    66,    69,
      70,    37,     5,   121,    94,    36,    38,    43,    44,    45,
      72,    74,    75,    76,    77,    78,    83,    84,    85,    86,
      87,    90,    97,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      36,    86,   122,    37,    66,     4,     5,    15,    91,   116,
     118,    97,    98,    36,   102,   102,    36,   102,    34,    36,
      41,    42,    43,    44,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    70,   117,   102,   104,    74,    79,
      80,    75,    76,    46,    47,    48,    49,    81,    82,    50,
      51,    72,    73,    71,    52,    53,    54,   122,    38,   132,
       5,    37,    37,    39,    66,     5,   118,    37,   101,   116,
      86,    86,   116,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   108,   108,   109,   110,   111,   112,
     113,   118,    37,     5,    17,    24,    30,    31,    33,    39,
      69,    92,   118,   119,   123,   124,   125,   127,   128,   130,
     132,   133,   134,   135,   136,   137,   138,   122,   104,    39,
      97,    37,    35,    37,    66,    55,    69,   118,    36,   132,
     135,    36,    36,    66,    69,     8,   129,   131,    39,    92,
     134,    39,   135,   116,   115,    69,    69,   119,   126,    33,
      33,   118,   119,   118,   132,   135,   131,    39,    69,   119,
      69,    37,    36,    36,    37,    37,   119,    69,    69,   119,
     132,   135,   119,   119,   132,   135,   132,   135,   119,   119,
      69,    37,    37,   119,    69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    90,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    96,
      96,    97,    97,    97,    98,    98,    99,    99,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   119,   119,
     120,   121,   121,   121,   122,   122,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   136,   137,   137,   138,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     1,     3,     1,     1,
       3,     1,     3,     4,     1,     3,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     2,     4,     0,     1,     3,     1,     1,     1,     7,
       7,     5,     5,     5,     4,     4,     4,     3,     3,     3,
       2,     5,     5,     1,     2,     1,     2,     5,     5,     2,
       2,     4,     3,     3,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     2
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
#line 172 "src/c_parser.y" /* yacc.c:1646  */
    { root = new Program(); root->insert_fn((yyvsp[0].fn_ptr));}
#line 1645 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 173 "src/c_parser.y" /* yacc.c:1646  */
    { root = new Program(); root->push_var_back((yyvsp[0].var_declaration_ptr));}
#line 1651 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 174 "src/c_parser.y" /* yacc.c:1646  */
    { root->insert_fn((yyvsp[0].fn_ptr)); }
#line 1657 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 175 "src/c_parser.y" /* yacc.c:1646  */
    { root->push_var_back((yyvsp[0].var_declaration_ptr)); }
#line 1663 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 187 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<double64_t>((yyvsp[0].floatval));}
#line 1669 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 188 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<uint64_t>((yyvsp[0].intval));}
#line 1675 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 219 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1681 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 220 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1687 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 221 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1693 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 241 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_declaration_ptr) = new VarDeclaration((yyvsp[-2].strval), (yyvsp[-1].vector_vars_ptrs_ptr)); }
#line 1699 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 243 "src/c_parser.y" /* yacc.c:1646  */
    { cerr<<"Warning: Useless definition in file "<<source_file<<", Line: "<<input_file_line<<endl;}
#line 1705 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 258 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = new vector<Variable*>; (yyval.vector_vars_ptrs_ptr)->push_back((yyvsp[0].var_ptr)); }
#line 1711 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 259 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr)->push_back((yyvsp[0].var_ptr)); }
#line 1717 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 263 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[0].var_ptr);}
#line 1723 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 264 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-2].var_ptr); (yyval.var_ptr)->set_init_val((yyvsp[0].base_expr_ptr));}
#line 1729 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 270 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[0].var_ptr); }
#line 1735 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 276 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = new Variable((yyvsp[0].strval)); }
#line 1741 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 277 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-1].var_ptr); }
#line 1747 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 292 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1753 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 304 "src/c_parser.y" /* yacc.c:1646  */
    { /*$$ = new TerneryExpression(NULL,$1,NULL);*/}
#line 1759 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 305 "src/c_parser.y" /* yacc.c:1646  */
    { /*$$ = $1; $$->push_back_rhs($3);*/}
#line 1765 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 320 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new VarExpr((yyvsp[0].strval));}
#line 1771 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 322 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1777 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 326 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[-1].base_expr_ptr); }
#line 1783 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 333 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1789 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 347 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-1].base_expr_ptr), (yyvsp[0].strval), NULL);}
#line 1795 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 349 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-1].base_expr_ptr), (yyvsp[0].strval), NULL);}
#line 1801 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 361 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1807 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1813 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 365 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1819 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 367 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1825 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 369 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1831 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 372 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<int>(sizeof(int));}
#line 1837 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 376 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1843 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 378 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1849 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 380 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1855 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 382 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1861 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 384 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1867 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 386 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1873 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 389 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1879 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 390 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression(NULL, (yyvsp[-2].strval), (yyvsp[0].base_expr_ptr));}
#line 1885 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1891 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 399 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1897 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 401 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1903 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 403 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1909 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 410 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1915 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 412 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1921 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 414 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1927 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 421 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1933 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 423 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1939 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 425 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1945 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 432 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1951 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 434 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1957 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 436 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1963 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 438 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1969 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 440 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1975 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 447 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1981 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 449 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1987 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 451 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 1993 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 458 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1999 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 460 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2005 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 467 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2011 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 469 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2017 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 476 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2023 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 478 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2029 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 485 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2035 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 487 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2041 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 494 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2047 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 496 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2053 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 503 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2059 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2065 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 516 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr));}
#line 2071 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 519 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2077 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 520 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2083 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 521 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2089 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 522 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2095 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 523 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2101 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 524 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2107 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 525 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2113 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 526 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2119 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 527 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2125 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 528 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2131 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 529 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2137 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 533 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 2143 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 542 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr_statement_ptr) = new ExpressionStatement((yyvsp[0].base_expr_ptr));}
#line 2149 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 544 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.expr_statement_ptr)->push_back((yyvsp[0].base_expr_ptr));}
#line 2155 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 570 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fn_ptr) = new Function(new Variable((yyvsp[-5].strval), NULL), (yyvsp[-4].strval), (yyvsp[-2].vector_vars_ptrs_ptr), (yyvsp[0].compound_statement_ptr)); }
#line 2161 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 573 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = new vector<Variable*>; 
                                                                  (yyval.vector_vars_ptrs_ptr)->push_back(new Variable((yyvsp[-1].strval), (yyvsp[0].strval)));}
#line 2168 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 575 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr)->push_back(new Variable((yyvsp[-1].strval), (yyvsp[0].strval))); }
#line 2174 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 576 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = NULL; }
#line 2180 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 580 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2186 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 581 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[-1].strval); }
#line 2192 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 587 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2198 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 588 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2204 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 589 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2210 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 596 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].compound_statement_ptr)); }
#line 2216 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 597 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].statement_ptr)); }
#line 2222 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 628 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].compound_statement_ptr)); }
#line 2228 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 629 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Loop((yyvsp[0].statement_ptr)); }
#line 2234 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 652 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional((yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 2240 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 653 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional(vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr),(yyvsp[0].vector_conditional_case_pointers_ptr))); }
#line 2246 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 656 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = (yyvsp[0].vector_conditional_case_pointers_ptr); }
#line 2252 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 657 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr), (yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 2258 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 661 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].compound_statement_ptr),(yyvsp[-2].base_expr_ptr))); }
#line 2264 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 663 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr),(yyvsp[-2].base_expr_ptr))); }
#line 2270 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 675 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].compound_statement_ptr))); }
#line 2276 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 676 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr))); }
#line 2282 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 690 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement((yyvsp[-2].vector_var_declarations_ptrs_ptr), (yyvsp[-1].vector_statement_pointers_ptr));}
#line 2288 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 691 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement(NULL,(yyvsp[-1].vector_statement_pointers_ptr));}
#line 2294 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 692 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement((yyvsp[-1].vector_var_declarations_ptrs_ptr),NULL);}
#line 2300 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 693 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=NULL; }
#line 2306 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 697 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_declarations_ptrs_ptr) = new vector<VarDeclaration*>; (yyval.vector_var_declarations_ptrs_ptr)->push_back((yyvsp[0].var_declaration_ptr));}
#line 2312 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 698 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_declarations_ptrs_ptr)->push_back((yyvsp[0].var_declaration_ptr));}
#line 2318 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 701 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr) = new vector<Statement*>; (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 2324 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 702 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 2330 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 707 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2336 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 708 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2342 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 709 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2348 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 710 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2354 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 711 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].compound_statement_ptr); }
#line 2360 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 716 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = (yyvsp[-1].expr_statement_ptr);}
#line 2366 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 720 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr);}
#line 2372 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 721 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=NULL;}
#line 2378 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 732 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ReturnStatement((yyvsp[-1].base_expr_ptr));}
#line 2384 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 733 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ReturnStatement();}
#line 2390 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2394 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 739 "src/c_parser.y" /* yacc.c:1906  */
  

int yyerror(const char* s){ 
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
  std::cerr <<"File: "<< source_file<<", Line: "<<input_file_line << std::endl;
  return -1;
}
/*
int main(){

  yydebug=1;

  cerr<<"========================================= Parsing starts ========================================="<<endl;
  yyparse();
  cerr<<"========================================= Parsing successful ========================================="<<endl;

  if(root==NULL) return 0;

  cerr<<"========================================= Printing starts ========================================="<<endl;

  root->pretty_print(0);

  cerr<<"========================================= Printing successful ========================================="<<endl;

  return 0;
}
*/



