
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
#include <boost/regex.hpp>

using namespace std;

int input_file_line=1;
int source_file_line;
string source_file;
%}


/* ============================================== Named patterns definitions ============================================== */

/* 
	1. be EXTREMELY careful with operators that are also defined in regexes: +  *  |  ^  [  ]  (  )  {  }  .  ?
	2. EXTREMELY careful with order - don't let a single symbol operator to be recognized inappropriately as part of a bigger operator
*/


/* -------------------------------------------------------- IDENTIFIERS -------------------------------------------------------- */

Identifier 				[a-zA-Z_]+[a-zA-Z0-9_]*		// Pointers are in the operators scope


/* -------------------------------------------------------- KEYWORDS -------------------------------------------------------- */

Keyword 	(auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while)



/* -------------------------------------------------------- CONSTANTS -------------------------------------------------------- */

EXPONENT				[eE]{1}[+-]?[0-9]+
FRACTIONAL_CONST		([0-9]*/.[0-9]+)|([0-9]+/.)
FLOATING_SUFFIX			[flFL]
FLOATING_CONST			({FRACTIONAL_CONST}{EXPONENT}?{FLOATING_SUFFIX}?)|([0-9]+{EXPONENT}{FLOATING_SUFFIX}?)

LONG_SUFFIX				[lL]
UNSIGNED_SUFFIX			[uU]
INT_SUFFIX				({UNSIGNED_SUFFIX}{LONG_SUFFIX}?)|({LOND_SUFFIX}{UNSIGNED_SUFFIX}?)
HEX_DIGIT				[a-fA-F0-9]
NONZERO_DIGIT			[1-9]
HEX_CONST				0[xX]{HEX_DIGIT}+
OCTAL_DIGIT				[0-7]					// is ? safe
OCTAL_CONST				0{OCTAL_DIGIT}+
DECIMAL_COSNT			{NONZERO_DIGIT}[0-9]*
INTEGER_CONST			({DECIMAL_CONST}{INT_SUFFIX}?)|({HEX_CONST}{INT_SUFFIX}?)|({OCTAL_CONST}{INT_SUFFIX}?)

ENUM_CONST				{Identifier}

HEX_ESC_SEQUENCE		\x{HEX_DIGIT}+
OCTAL_ESC_SEQUENCE		\{OCTAL_DIGIT}{1-3}										// Not sure whether 3 times is the max
SIMPLE_ESC_SEQUENCE		(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)					// Make sure no regex-specific symbols inside
ESC_SEQUENCE 			({HEX_ESC_SEQUENCE}|{OCTAL_ESC_SEQUENCE}|{SIMPLE_ESC_SEQUENCE})
				// Not sure whether only one char allowed and whether and OR or they should be sequential^^
C_CHAR					[^'\(\n)]|{ESC_SEQUENCE} 								
C_CHAR_SEQUENCE			{C_CHAR}+												// only one or many c-chars
CHAR_CONST				('{C_CHAR_SEQUENCE}'|L'{C_CHAR_SEQUENCE}')				// Not sure about the quotes


/*
ESC_SEQUENCE 			(\x{HEX_DIGIT}+|\{OCTAL_DIGIT}{1-3}|{(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)})
				// Not sure whether only one char allowed and whether and OR or they should be sequential^^
C_CHAR					[^'\(\n)]|(\x{HEX_DIGIT}+|\{OCTAL_DIGIT}{1-3}|{(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)}) 								
C_CHAR_SEQUENCE			[^'\(\n)]|(\x{HEX_DIGIT}+|\{OCTAL_DIGIT}{1-3}|{(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)})+												// only one or many c-chars
CHAR_CONST				('[^'\(\n)]|(\x[a-fA-F0-9]+|\[0-7]{1-3}|{(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)})+'|L'[^'\(\n)]|(\x[a-fA-F0-9]+|\[0-7]{1-3}|{(\'|\"|\\?|\\|\a|\b|\f|\\n|\\r|\\t|\v)})+')				// Not sure about the quotes
*/

Constant 				({FLOATING_CONST}|{INTEGER_CONST}|{ENUM_CONST}|{CHAR_CONST})

/* -------------------------------------------------------- STRING LITERALS ------------------------------------------------------- */

S_CHAR					[^"\(\n)]|{ESC_SEQUENCE} 								// what about commas and other punctuators
S_CHAR_SEQUENCE			{S_CHAR}+												// only one or many s-chars?
String_literal			(("{S_CHAR_SEQUENCE}?")|(L"{S_CHAR_SEQUENCE}?"))		// Not sure about the quotes

/* -------------------------------------------------------- OPERATORS -------------------------------------------------------- */


Operator 	(\[|\]|\(|\)|\{|\}|/././.|\.|->|++|--|sizeof|<<|>>|<=|>=|==|!=|\||&&|\|\||\?|:|\*=|/=|%=|\+=|-=|<<=|>>=|&=|\^=|\|=|,|##|#|;|=|&|\*|\+|-|~|!|/|%|<|>|\^)		


// WHY IS sizeof BOTH A KEYWORD AND AN OPERATOR
// What about \n \t ... - you whould probably recognize them so that you know a new token comes in

/* -------------------------------------------------------- INVALID -------------------------------------------------------- */

Invalid 				\S+

/* -------------------------------------------------------- PREPROCESSOR -------------------------------------------------------- */

Preprocessor 			^# .+$



%%
/* ============================================== Pattern matching rule section ============================================== */

/* ------------------------------------------------------ UNNAMED PATTERNS ------------------------------------------------------ */

[\n]				{ 	input_file_line++; source_file_line++; }


/* ------------------------------------------------------ NAMED PATTERNS ------------------------------------------------------ */

{Identifier}		{cout<<Token{yytext, "Identifier", "TokenIdentifier", input_file_line, source_file, source_file_line}<<endl;}
{Keyword}			{cout<<Token{yytext, "Keyword", "TokenKeyword", input_file_line, source_file, source_file_line}<<endl;}
{Constant}			{cout<<Token{yytext, "Constant", "TokenConstant", input_file_line, source_file, source_file_line}<<endl;}
{Operator}			{cout<<Token{yytext, "Operator", "TokenOperator", input_file_line, source_file, source_file_line}<<endl;}
{String_literal}	{cout<<Token{yytext, "StringLiteral", "TokenStringLiteral", input_file_line, source_file, source_file_line}<<endl;}
{Preprocessor}		{	process_prep(yytext);	}

{Invalid}			{cout<<Token{yytext, "Invalid", "TokenInvalid", input_file_line, source_file, source_file_line}<<endl;}

// What happens when no more input




%%
/* ==================== User function section - optional. Define the functions called on regex matches here ==================== */

const boost::regex source_file_regex("\\A\"(.+)\"\\z");
const boost::regex source_line_regex("\\A# (\\d+)\\z");

const std::string str_format("\\1");

std::string get_source_file(const std::string& s){
   return boost::regex_replace(s, source_file_regex, str_format, boost::match_default | boost::format_sed);
}	

std::string get_source_line(const std::string& s){
   return boost::regex_replace(s, source_line_regex, str_format, boost::match_default | boost::format_sed);
}	

process_prep(const string& content){
	int line = atoi(get_source_line(content).c_str());
	string source = get_source_file(content);
	
	source_file_line = line-1;
	source_file = source;
}

struct Token{
	string text;
	string class;
	string type;
	int input_line;
	string source;	
	int source_line;
};

ostream& operator << (std::ostream& out, const Token& Tin){
	out <<Tin.text<<" "<<Tin.class<<" "<<Tin.type<<" "<<Tin.input_line<<" "<<Tin.source<<" "<<Tin.source_line;
	return out;
}

int main(){

	yylex();

	return 0;
}
