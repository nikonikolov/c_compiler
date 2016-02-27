
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
#include "c_parser.tab.hpp"

using namespace std;


/* -------------------------------------------------------- HELP METHODS -------------------------------------------------------- */

enum token_type{
	Identifier_token, 
	Keyword_token,
	Constant_token,
	Operator_token,
	StringLiteral_token,
	Invalid_token,
	Enum_const_token,
	Char_const_token,
	Int_const_token,
	Float_const_token,
	Empty_token
};





/* ------------------------------------------------------ END HELP METHODS ------------------------------------------------------ */

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
Integer_const			(({DECIMAL_CONST}{INT_SUFFIX}?)|({HEX_CONST}{INT_SUFFIX}?)|({OCTAL_CONST}{INT_SUFFIX}?))
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
[\n]				{ input_file_line++; source_file_line++; /*return EOLINE;*/ }
[ ]|[\t]			{ }
auto				{ return AUTO; }
double				{ return DOUBLE; }
int					{ return INT; }
struct				{ return STRUCT; }
break				{ return BREAK; }
else				{ return ELSE; }
long				{ return LONG; }
switch				{ return SWITCH; }
case				{ return CASE; }
enum				{ return ENUM; }
register			{ return REGISTER; }
typedef				{ return TYPEDEF; }
char				{ return CHAR; }
extern				{ return EXTERN; }
return				{ return RETURN; }
union				{ return UNION; }
const				{ return CONST; }
float				{ return FLOAT; }
short				{ return SHORT; }
unsigned			{ return UNSIGNED; }
continue			{ return CONTINUE; }
for					{ return FOR; }
signed				{ return SIGNED; }
void				{ return VOID; }
default				{ return DEFAULT; }
goto				{ return GOTO; }
volatile			{ return VOLATILE; }
do					{ return DO; }
if					{ return IF; }
static				{ return STATIC; }
while				{ return WHILE; }
sizeof				{ return SIZEOF; }
{Identifier}		{ yylval.strval = strdup(yytext); return IDENTIFIER; }
{Floating_const}	{ return FLOATING_CONST; }
{Integer_const}		{ yylval.intval = atoi(yytext); return INTEGER_CONST; }
{Char_const}		{ return CHAR_CONST; }
\[					{ return LSQUARE; }
\]					{ return RSQUARE; }
\(					{ return LBRACKET; }
\)					{ return RBRACKET; }
\{					{ return LCURLY; }
\}					{ return RCURLY; }
\.\.\.				{ return THREE_DOTS; }
\.					{ return DOT; }
\-\>				{ return PTR_OP; }
\+\+				{ return PLUS_PLUS; }
\-\-				{ return MINUS_MINUS; }
\<\<				{ return LSHIFT; }
\>\>				{ return RSHIFT; }
\<\=				{ return LESS_OR_EQUAL; }
\>\=				{ return MORE_OR_EQUAL; }
\=\=				{ return LOGICAL_EQUALITY; }
\!\=				{ return LOGICAL_INEQUALITY; }
\&\&				{ return LOGICAL_AND; }
\|\|				{ return LOGICAL_OR; }
\?					{ return Q_MARK; }
\:					{ return COLON; }
\*\=				{ return MULT_EQUALS; }
\/\=				{ return DIV_EQUALS; }
\%\=				{ return PERCENT_EQUALS; }
\+\=				{ return PLUS_EQUALS; }
\-\=				{ return MINUS_EQUALS; }
\<\<\=				{ return LSHIFT_EQUALS; }
\>\>\=				{ return RSHIFT_EQUALS; }
\&\=				{ return AND_EQUALS; }
\^\=				{ return XOR_EQUALS; }
\|\=				{ return OR_EQUALS; }
\,					{ return COMMA; }
\#\#				{ return HASH; }
\#					{ return HASH_HASH; }
\;					{ return SEMI_COLON; }
\=					{ return EQUALS; }
\|					{ return BITWISE_OR; }
\&					{ return BITWISE_AND; }
\*					{ return MULT; }
\+					{ return PLUS; }
\-					{ return MINUS; }
\~					{ return WAVE; }
\!					{ return EXL_MARK; }
\/					{ return DIV; }
\%					{ return PERCENT; }
\<					{ return LOGICAL_LESS; }
\>					{ return LOGICAL_MORE; }
\^					{ return BITWISE_XOR; }
{StringLiteral}		{ return STRING_LITERAL; }
{Preprocessor}		{ process_prep_include(yytext); yylval.strval = strdup(yytext); }
{Invalid}			{ cout<<"In file "<<source_file<<": Invalid syntax at line "<<source_file_line<<endl; exit(EXIT_FAILURE); }
%%
/* ==================== User function section - optional. Define the functions called on regex matches here ==================== */

/*
int main(){
  	cout<<"Lexing starts"<<endl;

	yylex();

  	cout<<"Lexing starts"<<endl;

	return 0;
}
*/