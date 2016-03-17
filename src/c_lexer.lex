
/* 
	Flex will pick the longest matching token
	For matches of the same length it will pick the first 
	Flex cares about white space. Start all rules at the very beginning of a line
*/


%option noyywrap

/* include this option to avoid dependencies on function yywrap (yywrap is only needed if more than one file need to be processed) */



%{
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
//#include "c_parser.tab.hpp"
#include "../src_tmp/parser_expr.tab.hpp"

using namespace std;


%}


/* ============================================== Named patterns definitions ============================================== */

/* 
	1. be EXTREMELY careful with operators that are also defined in regexes: +  *  |  ^  [  ]  (  )  {  }  .  ?
	2. EXTREMELY careful with order - don't let a single symbol operator to be recognized inappropriately as part of a bigger operator
*/



/* -------------------------------------------------------- KEYWORDS -------------------------------------------------------- */

Keyword 				auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while

/* -------------------------------------------------------- IDENTIFIERS -------------------------------------------------------- */

Identifier 				([a-zA-Z_]+[a-zA-Z0-9_]*)		
/* Pointers are in the operators scope */


/* -------------------------------------------------------- CONSTANTS -------------------------------------------------------- */

EXPONENT				([eE]{1}[+-]?[0-9]+)
FRACTIONAL_CONST		(([0-9]*\.[0-9]+)|([0-9]+\.))
FLOATING_SUFFIX			([flFL])
Floating_const			(({FRACTIONAL_CONST}{EXPONENT}?{FLOATING_SUFFIX}?)|([0-9]+{EXPONENT}{FLOATING_SUFFIX}?))
/* 0.0 is recognized */

LONG_SUFFIX				([lL])
UNSIGNED_SUFFIX			([uU])
INT_SUFFIX				(({UNSIGNED_SUFFIX}{LONG_SUFFIX}?)|({LONG_SUFFIX}{UNSIGNED_SUFFIX}?))
HEX_DIGIT				([a-fA-F0-9])
NONZERO_DIGIT			([1-9])
HEX_CONST				(0[xX]{HEX_DIGIT}+)
OCTAL_DIGIT				([0-7])
OCTAL_CONST				(0{OCTAL_DIGIT}*)
DECIMAL_CONST			({NONZERO_DIGIT}[0-9]*)
/*Integer_const			(({DECIMAL_CONST}{INT_SUFFIX}?)|({HEX_CONST}{INT_SUFFIX}?)|({OCTAL_CONST}{INT_SUFFIX}?))*/
Decimal_constant 		({DECIMAL_CONST}{INT_SUFFIX}?)
Hex_constant 			({HEX_CONST}{INT_SUFFIX}?)
Octal_constant			({OCTAL_CONST}{INT_SUFFIX}?)
/* NOTE: 0 currently recognized in OCTAL */

ENUM_CONST				{Identifier}

HEX_ESC_SEQUENCE		((\\)x{HEX_DIGIT}+)
OCTAL_ESC_SEQUENCE		((\\){OCTAL_DIGIT}{1,3})										
SIMPLE_ESC_SEQUENCE		(((\\)(\'))|((\\)(\"))|((\\)(\?))|((\\){2})|(\\a)|(\\b)|(\\f)|(\\n)|(\\r)|(\\t)|(\\v))

/*
SIMPLE_ESC_SEQUENCE		(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)					
SIMPLE_ESC_SEQUENCE		(((\\)(\?))|((\\){2})|(\a)|(\b)|(\f)|(\n)|(\r)|(\t)|(\v))
*/
ESC_SEQUENCE 			({HEX_ESC_SEQUENCE}|{OCTAL_ESC_SEQUENCE}|{SIMPLE_ESC_SEQUENCE})

C_CHAR					[^(\')(\\)(\n)]|{ESC_SEQUENCE} 								
C_CHAR_SEQUENCE			{C_CHAR}+												
Char_const				(\'{C_CHAR_SEQUENCE}\'|L\'{C_CHAR_SEQUENCE}\')				


/* -------------------------------------------------------- STRING LITERALS ------------------------------------------------------- */

S_CHAR					[^\"\\\n]|{ESC_SEQUENCE}								
S_CHAR_SEQUENCE			{S_CHAR}+												
StringLiteral			((\"{S_CHAR_SEQUENCE}?\")|(L\"{S_CHAR_SEQUENCE}?\"))

/* -------------------------------------------------------- OPERATORS -------------------------------------------------------- */


Operator 	((\[)|(\])|\(|\)|\{|\}|(\.\.\.)|(\.)|->|(\+\+)|--|sizeof|<<|>>|<=|>=|==|(!=)|(\|)|(&&)|(\|\|)|(\?)|(:)|(\*=)|(\/=)|(%=)|(\+=)|-=|<<=|>>=|&=|(\^=)|(\|=)|,|##|#|;|=|&|(\*)|(\+)|-|~|!|(\/)|%|<|>|(\^))		


/* -------------------------------------------------------- INVALID -------------------------------------------------------- */

Invalid 				.

/* -------------------------------------------------------- PREPROCESSOR -------------------------------------------------------- */

Preprocessor 			^#[ ].+$


/* NB: Regexes that might need fixing:
	SIMPLE_ESC_SEQUENCE
	SCHAR 	- should be fine
*/

/* ============================================== Pattern matching rule section ============================================== */
%%
[\n]				{ input_file_line++; source_file_line++; }
[ ]|[\t]			{ }
auto				{ yylval.strval = strdup(yytext); return AUTO; }
double				{ yylval.strval = strdup(yytext); return DOUBLE; }
int					{ yylval.strval = strdup(yytext); return INT; }
struct				{ yylval.strval = strdup(yytext); return STRUCT; }
break				{ yylval.strval = strdup(yytext); return BREAK; }
else				{ yylval.strval = strdup(yytext); return ELSE; }
long				{ yylval.strval = strdup(yytext); return LONG; }
switch				{ yylval.strval = strdup(yytext); return SWITCH; }
case				{ yylval.strval = strdup(yytext); return CASE; }
enum				{ yylval.strval = strdup(yytext); return ENUM; }
register			{ yylval.strval = strdup(yytext); return REGISTER; }
typedef				{ yylval.strval = strdup(yytext); return TYPEDEF; }
char				{ yylval.strval = strdup(yytext); return CHAR; }
extern				{ yylval.strval = strdup(yytext); return EXTERN; }
return				{ yylval.strval = strdup(yytext); return RETURN; }
union				{ yylval.strval = strdup(yytext); return UNION; }
const				{ yylval.strval = strdup(yytext); return CONST; }
float				{ yylval.strval = strdup(yytext); return FLOAT; }
short				{ yylval.strval = strdup(yytext); return SHORT; }
unsigned			{ yylval.strval = strdup(yytext); return UNSIGNED; }
continue			{ yylval.strval = strdup(yytext); return CONTINUE; }
for					{ yylval.strval = strdup(yytext); return FOR; }
signed				{ yylval.strval = strdup(yytext); return SIGNED; }
void				{ yylval.strval = strdup(yytext); return VOID; }
default				{ yylval.strval = strdup(yytext); return DEFAULT; }
goto				{ yylval.strval = strdup(yytext); return GOTO; }
volatile			{ yylval.strval = strdup(yytext); return VOLATILE; }
do					{ yylval.strval = strdup(yytext); return DO; }
if					{ yylval.strval = strdup(yytext); return IF; }
static				{ yylval.strval = strdup(yytext); return STATIC; }
while				{ yylval.strval = strdup(yytext); return WHILE; }
sizeof				{ yylval.strval = strdup(yytext); return SIZEOF; }
{Identifier}		{ yylval.strval = strdup(yytext); return IDENTIFIER; }
{Floating_const}	{ yylval.floatval = to_double64(yytext); return FLOATING_CONST; }
{Decimal_constant}	{ yylval.intval = dec_to_uint64(yytext); return INTEGER_CONST; }
{Octal_constant}	{ yylval.intval = dec_to_uint64(yytext); return INTEGER_CONST; }
{Hex_constant}		{ yylval.intval = dec_to_uint64(yytext); return INTEGER_CONST; }
{Char_const}		{ return CHAR_CONST; }
\[					{ return LSQUARE; }
\]					{ return RSQUARE; }
\(					{ return LBRACKET; }
\)					{ return RBRACKET; }
\{					{ return LCURLY; }
\}					{ return RCURLY; }
\.\.\.				{ return THREE_DOTS; }
\.					{ yylval.strval = strdup(yytext); return DOT; }
\-\>				{ yylval.strval = strdup(yytext); return PTR_OP; }
\+\+				{ yylval.strval = strdup(yytext); return PLUS_PLUS; }
\-\-				{ yylval.strval = strdup(yytext); return MINUS_MINUS; }
\<\<				{ yylval.strval = strdup(yytext); return LSHIFT; }
\>\>				{ yylval.strval = strdup(yytext); return RSHIFT; }
\<\=				{ yylval.strval = strdup(yytext); return LESS_OR_EQUAL; }
\>\=				{ yylval.strval = strdup(yytext); return MORE_OR_EQUAL; }
\=\=				{ yylval.strval = strdup(yytext); return LOGICAL_EQUALITY; }
\!\=				{ yylval.strval = strdup(yytext); return LOGICAL_INEQUALITY; }
\&\&				{ yylval.strval = strdup(yytext); return LOGICAL_AND; }
\|\|				{ yylval.strval = strdup(yytext); return LOGICAL_OR; }
\?					{ yylval.strval = strdup(yytext); return Q_MARK; }
\:					{ yylval.strval = strdup(yytext); return COLON; }
\*\=				{ yylval.strval = strdup(yytext); return MULT_EQUALS; }
\/\=				{ yylval.strval = strdup(yytext); return DIV_EQUALS; }
\%\=				{ yylval.strval = strdup(yytext); return PERCENT_EQUALS; }
\+\=				{ yylval.strval = strdup(yytext); return PLUS_EQUALS; }
\-\=				{ yylval.strval = strdup(yytext); return MINUS_EQUALS; }
\<\<\=				{ yylval.strval = strdup(yytext); return LSHIFT_EQUALS; }
\>\>\=				{ yylval.strval = strdup(yytext); return RSHIFT_EQUALS; }
\&\=				{ yylval.strval = strdup(yytext); return AND_EQUALS; }
\^\=				{ yylval.strval = strdup(yytext); return XOR_EQUALS; }
\|\=				{ yylval.strval = strdup(yytext); return OR_EQUALS; }
\,					{ yylval.strval = strdup(yytext); return COMMA; }
\#\#				{ return HASH; }
\#					{ return HASH_HASH; }
\;					{ return SEMI_COLON; }
\=					{ yylval.strval = strdup(yytext); return EQUALS; }
\|					{ yylval.strval = strdup(yytext); return BITWISE_OR; }
\&					{ yylval.strval = strdup(yytext); return BITWISE_AND; }
\*					{ yylval.strval = strdup(yytext); return MULT; }
\+					{ yylval.strval = strdup(yytext); return PLUS; }
\-					{ yylval.strval = strdup(yytext); return MINUS; }
\~					{ yylval.strval = strdup(yytext); return WAVE; }
\!					{ yylval.strval = strdup(yytext); return EXL_MARK; }
\/					{ yylval.strval = strdup(yytext); return DIV; }
\%					{ yylval.strval = strdup(yytext); return PERCENT; }
\<					{ yylval.strval = strdup(yytext); return LOGICAL_LESS; }
\>					{ yylval.strval = strdup(yytext); return LOGICAL_MORE; }
\^					{ yylval.strval = strdup(yytext); return BITWISE_XOR; }
{StringLiteral}		{ yylval.strval = strdup(yytext); return STRING_LITERAL; }
{Preprocessor}		{ process_prep_include(yytext); yylval.strval = strdup(yytext); }
{Invalid}			{ cerr<<"In file "<<source_file<<": Invalid syntax at line "<<source_file_line<<endl; exit(EXIT_FAILURE); }
%%
/* ==================== User function section - optional. Define the functions called on regex matches here ==================== */

//{Integer_const}		{ yylval.intval = atoi(yytext); return INTEGER_CONST; }


/*
int main(){
  	cerr<<"Lexing starts"<<endl;

	yylex();

  	cerr<<"Lexing starts"<<endl;

	return 0;
}
*/