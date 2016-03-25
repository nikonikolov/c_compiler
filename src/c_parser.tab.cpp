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
  #include "DataStructures/Variable.h"

  #include "DataStructures/ForLoop.h"
  #include "DataStructures/WhileLoop.h"
  #include "DataStructures/Conditional.h"
  #include "DataStructures/VarDeclaration.h"
  #include "DataStructures/ReturnStatement.h"
  #include "DataStructures/CompoundStatement.h"

  #include "DataStructures/Constant.h"
  #include "DataStructures/VarExpr.h"
  #include "DataStructures/FnCall.h"
  #include "DataStructures/BaseExpression.h"
  #include "DataStructures/ArrayExpression.h"
  #include "DataStructures/Expression.h"
  #include "DataStructures/AddressExpression.h"
  #include "DataStructures/DereferenceExpression.h"
  #include "DataStructures/ConditionalExpression.h"
  #include "DataStructures/AssignmentExpression.h"
  #include "DataStructures/ExpressionStatement.h"
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);

  extern Program* root;


#line 134 "src/c_parser.tab.cpp" /* yacc.c:355  */

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
#line 38 "src/c_parser.y" /* yacc.c:355  */

  char* strval;
  uint64_t uint64val;
  int intval;
  double64_t floatval;

  Variable* var_ptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable*>*        vector_vars_ptrs_ptr;
  vector<Statement*>*       vector_statement_pointers_ptr;
  vector<Expression*>*      vector_expr_pointers_ptr;
  vector<ConditionalCase*>* vector_conditional_case_pointers_ptr;
  vector<VarDeclaration*>*  vector_var_declarations_ptrs_ptr;
  vector<BaseExpression*>*  vector_base_expression_ptrs_ptr;
  
  Function* fn_ptr;
  Statement* statement_ptr;
  CompoundStatement* compound_statement_ptr;
  BaseExpression* base_expr_ptr;
  ExpressionStatement* expr_statement_ptr;
  VarDeclaration* var_declaration_ptr;
  ArrayExpression* arr_expr_ptr;

  ForLoopTuple* fl_tuple;

#line 261 "src/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 162 "src/c_parser.y" /* yacc.c:358  */

  /* put additional C++ code here */
  Program* root=NULL;

#line 282 "src/c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   802

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

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
       0,   189,   189,   190,   191,   192,   193,   194,   206,   207,
     208,   238,   239,   240,   253,   255,   270,   271,   275,   276,
     282,   283,   287,   288,   290,   291,   295,   296,   303,   305,
     307,   311,   313,   328,   330,   332,   334,   349,   351,   355,
     358,   360,   363,   366,   368,   372,   373,   380,   382,   384,
     386,   388,   390,   392,   395,   399,   401,   403,   405,   410,
     411,   419,   421,   424,   427,   435,   437,   440,   448,   450,
     452,   459,   461,   464,   467,   470,   478,   480,   483,   491,
     493,   501,   503,   511,   513,   521,   523,   531,   533,   541,
     543,   551,   553,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   571,   578,   580,   587,   610,   616,
     620,   622,   623,   627,   628,   639,   640,   641,   645,   647,
     651,   652,   655,   656,   657,   658,   659,   660,   661,   662,
     666,   668,   689,   690,   693,   694,   698,   701,   706,   708,
     722,   723,   724,   725,   729,   730,   733,   734,   739,   740,
     741,   742,   743,   748,   752,   753,   764,   765
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
  "declarator", "direct_declarator", "pointer", "initializer",
  "initializer_list", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "UNARY_OPERATOR",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "ASSIGNMENT_OPERATOR",
  "expression", "expression_list", "constant_expression", "fn_prototype",
  "fn_declaration", "fn_params_list", "bracketed_identifier", "loop",
  "do_while_loop", "for_loop", "for_loop_decl_statement", "while_loop",
  "if_block_statement", "else_statement_list", "if_statement",
  "else_statement", "compound_statement", "declaration_list",
  "statement_list", "statement", "expression_statement",
  "semi_colon_statement", "return_statement", YY_NULLPTR
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

#define YYPACT_NINF -191

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-191)))

#define YYTABLE_NINF -114

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -11,    15,  -191,  -191,  -191,     7,  -191,  -191,     1,
     -50,  -191,   -44,     8,    11,  -191,  -191,  -191,  -191,  -191,
      20,    63,     7,  -191,   506,   438,  -191,     8,  -191,    -2,
      -7,  -191,   166,   506,   644,   644,   681,   700,   700,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,    41,  -191,  -191,  -191,
    -191,    84,   732,   700,  -191,   -39,   -53,    56,   -43,    58,
      10,    37,    42,    70,    62,  -191,  -191,  -191,    88,  -191,
    -191,  -191,    96,    -2,  -191,  -191,   -17,   128,  -191,  -191,
    -191,   101,   105,    93,  -191,   -10,   700,  -191,  -191,   271,
    -191,  -191,  -191,   700,    59,    86,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,   700,
    -191,   700,   700,   700,   700,   700,   700,   700,   700,   700,
     700,   700,   700,   700,   700,   700,   700,   700,   700,   700,
     551,  -191,   137,   188,  -191,  -191,    -2,   700,  -191,  -191,
    -191,   490,   138,   143,  -191,  -191,  -191,  -191,  -191,  -191,
     -39,   -39,   -53,   -53,    56,    56,    56,    56,   -43,   -43,
      58,    10,    37,    42,    70,   124,  -191,    -6,  -191,     9,
     570,   144,   422,   146,   147,  -191,  -191,  -191,  -191,   -33,
    -191,  -191,  -191,  -191,  -191,   176,  -191,   253,   335,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,   700,
    -191,   700,  -191,   118,   607,   155,   156,   700,   700,   700,
    -191,   422,   176,  -191,  -191,  -191,   358,  -191,  -191,  -191,
    -191,  -191,   626,    30,   153,   158,   159,    53,    54,  -191,
    -191,  -191,  -191,  -191,   700,    32,   663,   422,   700,   700,
     422,   422,   125,   700,   700,    38,  -191,  -191,    55,    57,
    -191,  -191,  -191,  -191,   125,   125,   700,   123,   127,   125,
    -191,  -191
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     4,     2,     0,    15,    26,    22,
       0,    16,    18,    20,     0,     1,     6,     7,     5,    22,
       0,   112,     0,    14,     0,     0,    27,    21,    23,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,     9,     8,    10,    33,    35,    34,    19,
      37,    47,    59,     0,    61,    65,    68,    71,    76,    79,
      81,    83,    85,    87,    89,    91,   104,    28,     0,    25,
      59,   107,     0,     0,   113,   110,     0,     0,    12,    11,
      13,     0,     0,     0,    31,     0,     0,    48,    49,     0,
      53,    52,    51,     0,     0,     0,    43,    44,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    93,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,   108,   109,     0,     0,    36,   114,
      29,     0,     0,     0,    41,    42,    92,    62,    63,    64,
      66,    67,    69,    70,    74,    75,    73,    72,    77,    78,
      80,    82,    84,    86,    88,     0,    40,     0,    45,     0,
       0,     0,     0,     0,     0,   143,   155,   144,   105,     0,
     148,   117,   115,   116,   149,   132,   152,     0,     0,   146,
     150,   151,   154,   111,    60,    30,    32,    54,    38,     0,
      39,     0,   157,     0,     0,     0,     0,     0,     0,     0,
     153,     0,   133,   134,   142,   145,     0,   141,   147,    90,
      46,   156,     0,     0,     0,     0,     0,     0,     0,   106,
     138,   139,   135,   140,   129,     0,     0,     0,     0,     0,
       0,     0,   127,   128,   126,     0,   120,   121,     0,     0,
     136,   137,   130,   131,   125,   124,   123,     0,     0,   122,
     118,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,  -191,    -1,  -191,   175,   192,   185,  -191,
     -30,  -191,  -191,  -191,  -191,    36,  -191,   -25,    26,    27,
      16,    44,    76,    78,    75,    77,    79,  -191,   -23,    97,
    -191,   -24,  -190,  -191,   206,   211,  -191,   -22,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,     2,   -72,  -191,    28,
    -161,  -191,  -191,  -191
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    48,    81,     3,    10,    11,    12,    13,    14,
      49,    85,    50,    51,   167,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     109,   178,   179,    72,     4,     5,    30,    68,   180,   181,
     182,   224,   183,   184,   212,   185,   213,   186,   187,   188,
     189,   190,   191,   192
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    16,    71,    84,   135,   118,   119,    75,    82,    67,
      83,   206,    91,    92,   223,    15,    22,   227,   228,    23,
       1,   133,   114,   115,     1,     6,    24,   218,   110,   140,
      76,   200,   235,   209,    73,   111,   210,    21,   120,   121,
     112,   113,    25,     6,   242,     6,   245,     6,   248,   249,
     231,   132,   134,   254,   255,   218,   141,    28,     7,    77,
     201,    70,    82,     8,    83,    82,   259,    83,    29,   143,
      87,    88,    90,    70,    70,     9,   247,  -113,     7,   251,
     253,     8,   124,     8,    74,    26,   147,   148,   149,    70,
     240,   241,   257,    19,   258,    19,   209,    19,   209,   236,
     205,   243,   116,   117,   209,   165,   168,   256,   122,   123,
     125,   196,   194,   126,   193,   128,   129,    67,    93,   209,
     209,   209,   127,   209,   130,    94,    95,    96,    97,   130,
     139,   131,   177,   136,   154,   155,   156,   157,   137,   230,
     150,   151,   138,   152,   153,   144,   203,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,   246,   158,   159,   250,   252,
      78,    79,   145,    70,   139,   197,   219,   220,   198,   199,
     204,    80,   207,   208,   211,   229,   215,   221,   225,   226,
     237,   209,   260,   169,   238,   239,   261,    31,    20,    27,
     160,   162,    32,   161,   163,   170,   146,   164,    17,    34,
      35,    36,   171,    18,   232,   216,     0,     0,   172,   173,
       0,   174,     0,     0,    32,     0,   133,   175,     0,     0,
       0,    34,    35,    36,     0,    70,     0,     0,    37,     0,
      38,    39,    40,    41,    42,     0,     0,     0,     0,    43,
      44,    45,    46,    47,     0,     0,     0,   176,   169,     0,
      37,     0,    38,    39,    40,    41,    42,     0,     0,     0,
     170,    43,    44,    45,    46,    47,   142,   171,     0,     0,
       0,     0,     0,   172,   173,     0,   174,     0,     0,    32,
       0,   133,   214,     0,     0,     0,    34,    35,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,     0,
       0,     0,   176,     0,     0,    37,     0,    38,    39,    40,
      41,    42,     0,     0,     0,     0,    43,    44,    45,    46,
      47,     0,     0,    37,     0,    38,    39,    40,    41,    42,
       0,     0,   170,     0,    43,    44,    45,    46,    47,   171,
       0,     0,     0,     0,     0,   172,   173,     0,   174,     0,
       0,    32,     0,   133,   217,   170,     0,     0,    34,    35,
      36,     0,   171,     0,     0,     0,     0,     0,   172,   173,
       0,   174,     0,     0,    32,     0,   133,   233,     0,     0,
       0,    34,    35,    36,   176,     0,     0,    37,     0,    38,
      39,    40,    41,    42,     0,     0,     0,     0,    43,    44,
      45,    46,    47,     0,     0,     0,     0,   176,     0,     0,
      37,     0,    38,    39,    40,    41,    42,     0,     0,   170,
       0,    43,    44,    45,    46,    47,   171,     0,     0,     0,
       0,     0,   172,   173,     0,   174,     0,     0,    32,     0,
     133,     0,     0,     0,     0,    34,    35,    36,     0,     0,
       0,     0,     0,    69,    32,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,    37,     0,    38,    39,    40,    41,
      42,     0,     0,     0,     0,    43,    44,    45,    46,    47,
      37,     0,    38,    39,    40,    41,    42,     0,     0,     0,
       0,    43,    44,    45,    46,    47,    32,     0,    33,   195,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
       0,     0,    32,     0,    33,     0,     0,     0,     0,    34,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    38,    39,    40,    41,    42,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    37,     0,
      38,    39,    40,    41,    42,     0,     0,    32,   166,    43,
      44,    45,    46,    47,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    38,    39,    40,    41,    42,
       0,     0,     0,     0,    43,    44,    45,    46,    47,   202,
       0,     0,    37,    32,    38,    39,    40,    41,    42,     0,
      34,    35,    36,    43,    44,    45,    46,    47,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,    34,
      35,    36,     0,     0,     0,     0,   222,     0,     0,    37,
      86,    38,    39,    40,    41,    42,     0,    34,    35,    36,
      43,    44,    45,    46,    47,   234,     0,     0,    37,    32,
      38,    39,    40,    41,    42,     0,    34,    35,    36,    43,
      44,    45,    46,    47,     0,     0,    37,    89,    38,    39,
      40,    41,    42,     0,    34,    35,    36,    43,    44,    45,
      46,    47,   244,     0,     0,    37,    32,    38,    39,    40,
      41,    42,     0,    34,    35,    36,    43,    44,    45,    46,
      47,     0,     0,    37,     0,    38,    39,    40,    41,    42,
       0,     0,     0,     0,    43,    44,    45,    46,    47,     0,
       0,     0,    37,     0,    38,    39,    40,    41,    42,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108
};

static const yytype_int16 yycheck[] =
{
      24,     2,    25,    33,    76,    48,    49,    29,    32,    33,
      32,   172,    37,    38,   204,     0,    66,   207,   208,    69,
       5,    38,    75,    76,     5,    36,    70,   188,    53,    39,
      37,    37,   222,    66,    36,    74,    69,    36,    81,    82,
      79,    80,    34,    36,   234,    36,   236,    36,   238,   239,
     211,    73,    69,   243,   244,   216,    66,    37,    69,    66,
      66,    25,    86,    74,    86,    89,   256,    89,     5,    93,
      34,    35,    36,    37,    38,    86,   237,    36,    69,   240,
     241,    74,    72,    74,    86,    74,   111,   112,   113,    53,
      37,    37,    37,    86,    37,    86,    66,    86,    66,    69,
     172,    69,    46,    47,    66,   129,   130,    69,    50,    51,
      73,   141,   137,    71,   136,    53,    54,   141,    34,    66,
      66,    66,    52,    66,    36,    41,    42,    43,    44,    36,
      37,    35,   133,     5,   118,   119,   120,   121,    37,   211,
     114,   115,    37,   116,   117,    86,   170,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   237,   122,   123,   240,   241,
       4,     5,    86,   137,    37,    37,   199,   201,    35,    55,
      36,    15,    36,    36,     8,   209,   187,    69,    33,    33,
      37,    66,    69,     5,    36,    36,    69,    22,     6,    14,
     124,   126,    36,   125,   127,    17,   109,   128,     2,    43,
      44,    45,    24,     2,   212,   187,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    -1,   199,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    69,     5,    -1,
      72,    -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      17,    83,    84,    85,    86,    87,     5,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,
      -1,    38,    39,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      87,    -1,    -1,    72,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    17,    -1,    83,    84,    85,    86,    87,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    -1,    38,    39,    17,    -1,    -1,    43,    44,
      45,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    78,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    78,    -1,    -1,    17,
      -1,    83,    84,    85,    86,    87,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      72,    -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    36,    -1,    38,    39,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    72,    -1,
      74,    75,    76,    77,    78,    -1,    -1,    36,    37,    83,
      84,    85,    86,    87,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,    69,
      -1,    -1,    72,    36,    74,    75,    76,    77,    78,    -1,
      43,    44,    45,    83,    84,    85,    86,    87,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,
      36,    74,    75,    76,    77,    78,    -1,    43,    44,    45,
      83,    84,    85,    86,    87,    69,    -1,    -1,    72,    36,
      74,    75,    76,    77,    78,    -1,    43,    44,    45,    83,
      84,    85,    86,    87,    -1,    -1,    72,    36,    74,    75,
      76,    77,    78,    -1,    43,    44,    45,    83,    84,    85,
      86,    87,    69,    -1,    -1,    72,    36,    74,    75,    76,
      77,    78,    -1,    43,    44,    45,    83,    84,    85,    86,
      87,    -1,    -1,    72,    -1,    74,    75,    76,    77,    78,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,    -1,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    78,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    89,    92,   122,   123,    36,    69,    74,    86,
      93,    94,    95,    96,    97,     0,    92,   122,   123,    86,
      95,    36,    66,    69,    70,    34,    74,    96,    37,     5,
     124,    94,    36,    38,    43,    44,    45,    72,    74,    75,
      76,    77,    78,    83,    84,    85,    86,    87,    90,    98,
     100,   101,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   119,   125,    35,
     103,   116,   121,    36,    86,   125,    37,    66,     4,     5,
      15,    91,   119,   125,    98,    99,    36,   103,   103,    36,
     103,   105,   105,    34,    41,    42,    43,    44,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    70,   118,
     105,    74,    79,    80,    75,    76,    46,    47,    48,    49,
      81,    82,    50,    51,    72,    73,    71,    52,    53,    54,
      36,    35,   125,    38,    69,   135,     5,    37,    37,    37,
      39,    66,     5,   119,    86,    86,   117,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     110,   111,   112,   113,   114,   119,    37,   102,   119,     5,
      17,    24,    30,    31,    33,    39,    69,    92,   119,   120,
     126,   127,   128,   130,   131,   133,   135,   136,   137,   138,
     139,   140,   141,   125,   105,    39,    98,    37,    35,    55,
      37,    66,    69,   119,    36,   135,   138,    36,    36,    66,
      69,     8,   132,   134,    39,    92,   137,    39,   138,   116,
     119,    69,    69,   120,   129,    33,    33,   120,   120,   119,
     135,   138,   134,    39,    69,   120,    69,    37,    36,    36,
      37,    37,   120,    69,    69,   120,   135,   138,   120,   120,
     135,   138,   135,   138,   120,   120,    69,    37,    37,   120,
      69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    99,    99,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   104,   104,   105,
     105,   106,   106,   106,   106,   107,   107,   107,   108,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   120,   120,   121,   122,   123,
     124,   124,   124,   125,   125,   126,   126,   126,   127,   127,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     138,   138,   138,   139,   140,   140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     3,     1,     3,
       1,     2,     1,     3,     4,     3,     1,     2,     1,     3,
       4,     1,     3,     1,     1,     1,     3,     1,     4,     4,
       3,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     6,     6,
       2,     4,     0,     1,     3,     1,     1,     1,     7,     7,
       5,     5,     5,     4,     4,     4,     3,     3,     3,     2,
       5,     5,     1,     2,     1,     2,     5,     5,     2,     2,
       4,     3,     3,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2
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
#line 189 "src/c_parser.y" /* yacc.c:1646  */
    { root = new Program(); root->insert_fn((yyvsp[0].fn_ptr));}
#line 1687 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 190 "src/c_parser.y" /* yacc.c:1646  */
    { root = new Program(); root->push_var_back((yyvsp[0].var_declaration_ptr));}
#line 1693 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 191 "src/c_parser.y" /* yacc.c:1646  */
    { root = new Program(); root->insert_fn_prototype((yyvsp[0].fn_ptr));}
#line 1699 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 192 "src/c_parser.y" /* yacc.c:1646  */
    { root->insert_fn((yyvsp[0].fn_ptr)); }
#line 1705 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 193 "src/c_parser.y" /* yacc.c:1646  */
    { root->push_var_back((yyvsp[0].var_declaration_ptr)); }
#line 1711 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 194 "src/c_parser.y" /* yacc.c:1646  */
    { root->insert_fn_prototype((yyvsp[0].fn_ptr));}
#line 1717 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<double64_t>((yyvsp[0].floatval));}
#line 1723 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<uint64_t>((yyvsp[0].uint64val));}
#line 1729 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 238 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1735 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 239 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1741 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 240 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1747 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 253 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_declaration_ptr) = new VarDeclaration((yyvsp[-2].strval), (yyvsp[-1].vector_vars_ptrs_ptr)); }
#line 1753 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 255 "src/c_parser.y" /* yacc.c:1646  */
    { cerr<<"Warning: Useless definition in file "<<source_file<<", Line: "<<input_file_line<<endl;}
#line 1759 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 270 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = new vector<Variable*>; (yyval.vector_vars_ptrs_ptr)->push_back((yyvsp[0].var_ptr)); }
#line 1765 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 271 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr)->push_back((yyvsp[0].var_ptr)); }
#line 1771 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 275 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[0].var_ptr);}
#line 1777 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 276 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-2].var_ptr); (yyval.var_ptr)->set_init_val((yyvsp[0].base_expr_ptr));}
#line 1783 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 282 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[0].var_ptr); }
#line 1789 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 283 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[0].var_ptr); (yyval.var_ptr)->inc_deref_lvl((yyvsp[-1].intval)); }
#line 1795 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 287 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = new Variable(NULL, (yyvsp[0].strval), source_line, source_file); }
#line 1801 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 288 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-1].var_ptr); }
#line 1807 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-3].var_ptr); (yyval.var_ptr)->inc_array_size((yyvsp[-1].base_expr_ptr)); }
#line 1813 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 291 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.var_ptr) = (yyvsp[-2].var_ptr); (yyval.var_ptr)->inc_array_size(NULL); }
#line 1819 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 295 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.intval)=1; }
#line 1825 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 296 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.intval)=(yyvsp[-1].intval); (yyval.intval)++; }
#line 1831 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 303 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1837 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[-1].arr_expr_ptr); }
#line 1843 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new ArrayExpression((yyvsp[-2].arr_expr_ptr), source_line, source_file); }
#line 1849 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 311 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.arr_expr_ptr) = new ArrayExpression((yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1855 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 313 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.arr_expr_ptr) = (yyvsp[-2].arr_expr_ptr); (yyval.arr_expr_ptr)->push_back_mem((yyvsp[0].base_expr_ptr));}
#line 1861 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 328 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new VarExpr((yyvsp[0].strval), source_line, source_file);}
#line 1867 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 330 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1873 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 334 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[-1].base_expr_ptr); }
#line 1879 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 349 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 1885 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 352 "src/c_parser.y" /* yacc.c:1646  */
    { BaseExpression* deref = new Expression((yyvsp[-3].base_expr_ptr), strdup("+"), (yyvsp[-1].base_expr_ptr), source_line, source_file);
                                                                (yyval.base_expr_ptr) = new DereferenceExpression(deref, source_line, source_file); }
#line 1892 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 356 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new FnCall((yyvsp[-3].strval),(yyvsp[-1].vector_base_expression_ptrs_ptr),source_line,source_file); }
#line 1898 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 358 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new FnCall((yyvsp[-2].strval),NULL,source_line,source_file); }
#line 1904 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 366 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-1].base_expr_ptr), (yyvsp[0].strval), NULL, source_line, source_file);}
#line 1910 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 368 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-1].base_expr_ptr), (yyvsp[0].strval), NULL, source_line, source_file);}
#line 1916 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 372 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_base_expression_ptrs_ptr) = new vector<BaseExpression*>; (yyval.vector_base_expression_ptrs_ptr)->push_back((yyvsp[0].base_expr_ptr)); }
#line 1922 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 373 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_base_expression_ptrs_ptr)->push_back((yyvsp[0].base_expr_ptr)); }
#line 1928 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 380 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 1934 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 382 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1940 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 384 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1946 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1952 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 388 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new DereferenceExpression((yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1958 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 390 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AddressExpression((yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1964 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 392 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression(NULL, (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 1970 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 395 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Constant<uint64_t>(sizeof(int), source_line, source_file);}
#line 1976 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 399 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1982 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 401 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1988 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 403 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 1994 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 405 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2000 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 410 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2006 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 411 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2012 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 419 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 2018 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 422 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2024 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 425 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2030 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 428 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2036 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 435 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2042 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 438 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2048 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 441 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2054 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 448 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 2060 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 450 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2066 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 452 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2072 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 459 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2078 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2084 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 465 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2090 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 468 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2096 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 471 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2102 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 478 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2108 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 481 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2114 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 484 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2120 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 491 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2126 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 494 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2132 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 501 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2138 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 504 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2144 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 511 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2150 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2156 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 521 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2162 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 524 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2168 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 531 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2174 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 534 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new Expression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2180 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 541 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2186 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 544 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new ConditionalExpression((yyvsp[-4].base_expr_ptr), (yyvsp[-2].base_expr_ptr), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2192 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 551 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr); }
#line 2198 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 554 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = new AssignmentExpression((yyvsp[-2].base_expr_ptr), (yyvsp[-1].strval), (yyvsp[0].base_expr_ptr), source_line, source_file);}
#line 2204 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 557 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2210 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 558 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2216 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 559 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2222 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 560 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2228 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 561 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2234 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 562 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2240 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 563 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2246 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 564 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2252 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 565 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2258 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 566 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2264 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 567 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval);}
#line 2270 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 571 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.base_expr_ptr) = (yyvsp[0].base_expr_ptr);}
#line 2276 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 578 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_base_expression_ptrs_ptr) = new vector<BaseExpression*>; (yyval.vector_base_expression_ptrs_ptr)->push_back((yyvsp[0].base_expr_ptr));}
#line 2282 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 580 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_base_expression_ptrs_ptr)->push_back((yyvsp[0].base_expr_ptr));}
#line 2288 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 611 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fn_ptr) = new Function(new Variable((yyvsp[-5].strval), NULL), (yyvsp[-4].strval), (yyvsp[-2].vector_vars_ptrs_ptr), NULL); }
#line 2294 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 617 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fn_ptr) = new Function(new Variable((yyvsp[-5].strval), NULL), (yyvsp[-4].strval), (yyvsp[-2].vector_vars_ptrs_ptr), (yyvsp[0].compound_statement_ptr)); }
#line 2300 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 620 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = new vector<Variable*>; 
                                                                  (yyval.vector_vars_ptrs_ptr)->push_back(new Variable((yyvsp[-1].strval), (yyvsp[0].strval), source_line, source_file));}
#line 2307 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 622 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr)->push_back(new Variable((yyvsp[-1].strval), (yyvsp[0].strval), source_line, source_file));}
#line 2313 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 623 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_vars_ptrs_ptr) = NULL; }
#line 2319 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 627 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[0].strval); }
#line 2325 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 628 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.strval) = (yyvsp[-1].strval); }
#line 2331 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 639 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2337 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 640 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2343 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 641 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2349 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 646 "src/c_parser.y" /* yacc.c:1646  */
    { int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1; (yyval.statement_ptr) = new WhileLoop(((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), (yyvsp[-5].compound_statement_ptr), ST_dowhile_loop); }
#line 2355 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 648 "src/c_parser.y" /* yacc.c:1646  */
    { int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1; (yyval.statement_ptr) = new WhileLoop(((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), (yyvsp[-5].statement_ptr), ST_dowhile_loop); }
#line 2361 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 651 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ForLoop((yyvsp[-2].fl_tuple), (yyvsp[0].compound_statement_ptr)); }
#line 2367 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 652 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ForLoop((yyvsp[-2].fl_tuple), (yyvsp[0].statement_ptr)); }
#line 2373 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 655 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple((yyvsp[-4].vector_base_expression_ptrs_ptr), (yyvsp[-2].vector_base_expression_ptrs_ptr), (yyvsp[0].vector_base_expression_ptrs_ptr)); }
#line 2379 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 656 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple((yyvsp[-3].vector_base_expression_ptrs_ptr), (yyvsp[-1].vector_base_expression_ptrs_ptr), NULL); }
#line 2385 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 657 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple((yyvsp[-3].vector_base_expression_ptrs_ptr), NULL, (yyvsp[0].vector_base_expression_ptrs_ptr)); }
#line 2391 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 658 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple(NULL, (yyvsp[-2].vector_base_expression_ptrs_ptr), (yyvsp[0].vector_base_expression_ptrs_ptr)); }
#line 2397 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 659 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple((yyvsp[-2].vector_base_expression_ptrs_ptr), NULL, NULL); }
#line 2403 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 660 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple(NULL, NULL, (yyvsp[0].vector_base_expression_ptrs_ptr)); }
#line 2409 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 661 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple(NULL, (yyvsp[-1].vector_base_expression_ptrs_ptr), NULL); }
#line 2415 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 662 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.fl_tuple) = new ForLoopTuple(NULL, NULL, NULL); }
#line 2421 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 667 "src/c_parser.y" /* yacc.c:1646  */
    { int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1; (yyval.statement_ptr) = new WhileLoop(((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), (yyvsp[0].compound_statement_ptr), ST_while_loop); }
#line 2427 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 669 "src/c_parser.y" /* yacc.c:1646  */
    { int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1; (yyval.statement_ptr) = new WhileLoop(((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), (yyvsp[0].statement_ptr), ST_while_loop); }
#line 2433 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 689 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional((yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 2439 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 690 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Conditional(vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr),(yyvsp[0].vector_conditional_case_pointers_ptr))); }
#line 2445 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 693 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = (yyvsp[0].vector_conditional_case_pointers_ptr); }
#line 2451 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 694 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = vec_append((yyvsp[-1].vector_conditional_case_pointers_ptr), (yyvsp[0].vector_conditional_case_pointers_ptr)); }
#line 2457 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 699 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1;
                  (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].compound_statement_ptr),((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), source_line, source_file)); }
#line 2464 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 702 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; int last = (yyvsp[-2].vector_base_expression_ptrs_ptr)->size()-1;
                  (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr),((*((yyvsp[-2].vector_base_expression_ptrs_ptr)))[last]), source_line, source_file)); }
#line 2471 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 707 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].compound_statement_ptr), NULL, source_line, source_file)); }
#line 2477 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 709 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_conditional_case_pointers_ptr) = new vector<ConditionalCase*>; (yyval.vector_conditional_case_pointers_ptr)->push_back(new ConditionalCase((yyvsp[0].statement_ptr), NULL, source_line, source_file)); }
#line 2483 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 722 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement((yyvsp[-2].vector_var_declarations_ptrs_ptr), (yyvsp[-1].vector_statement_pointers_ptr));}
#line 2489 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 723 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement(NULL,(yyvsp[-1].vector_statement_pointers_ptr));}
#line 2495 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 724 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=new CompoundStatement((yyvsp[-1].vector_var_declarations_ptrs_ptr),NULL);}
#line 2501 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 725 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr)=NULL; }
#line 2507 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 729 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_declarations_ptrs_ptr) = new vector<VarDeclaration*>; (yyval.vector_var_declarations_ptrs_ptr)->push_back((yyvsp[0].var_declaration_ptr));}
#line 2513 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 730 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_var_declarations_ptrs_ptr)->push_back((yyvsp[0].var_declaration_ptr));}
#line 2519 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 733 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr) = new vector<Statement*>; (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 2525 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 734 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.vector_statement_pointers_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 2531 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 739 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2537 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 740 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2543 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 741 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2549 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 742 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr); }
#line 2555 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 743 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].compound_statement_ptr); }
#line 2561 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 748 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ExpressionStatement((yyvsp[-1].vector_base_expression_ptrs_ptr));}
#line 2567 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 752 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=(yyvsp[0].statement_ptr);}
#line 2573 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 753 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr)=NULL;}
#line 2579 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 764 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ReturnStatement((yyvsp[-1].base_expr_ptr), source_line, source_file);}
#line 2585 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 765 "src/c_parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new ReturnStatement(NULL, source_line, source_file);}
#line 2591 "src/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2595 "src/c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 771 "src/c_parser.y" /* yacc.c:1906  */
  

int yyerror(const char* s){ 
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
  std::cerr <<"File: "<< source_file<<", Line: "<<input_file_line << std::endl;
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
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



