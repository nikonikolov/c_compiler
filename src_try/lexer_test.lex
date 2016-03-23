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

using namespace std;

int input_file_line=1;
int source_file_line=1;
string source_file="";

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


void process_prep(const string& content){
	stringstream ss;
	ss<<content;
	string out;
	ss>>out;
	ss>>out;
	source_file_line = atoi(out.c_str())-1;
	ss>>source_file;
	source_file = source_file.substr(1, source_file.size()-2);
}

class Token{
public:
	

	Token (string textin, string class_tin, token_type token_type_in, int input_linein, string sourcein, int source_linein) :
	text(textin), class_t(class_tin), input_line(input_linein), source(sourcein), source_line(source_linein) {
		if(token_type_in==Identifier_token)			ttype = "TIdentifier";
		else if(token_type_in==Keyword_token)		ttype = "T"+text;
		else if(token_type_in==Int_const_token) 	ttype = "TIntConstant";
		else if(token_type_in==Float_const_token) 	ttype = "TFloatConstant";
		else if(token_type_in==Char_const_token) 	ttype = "TCharConstant";
		else if(token_type_in==StringLiteral_token)	ttype = "TStringLiteral";
		else if(token_type_in==Operator_token)		ttype = "T"+text;
		else if(token_type_in==Invalid_token)		ttype = "TInvalid";
	}

	friend ostream& operator << (std::ostream& out, const Token& Tin);
private:
	string text;
	string class_t;
	string ttype;
	int input_line;
	string source;	
	int source_line;

};


ostream& operator << (std::ostream& out, const Token& Tin){
	out<<Tin.text<<" "<<Tin.class_t<<" "<<Tin.ttype<<" "<<Tin.input_line<<" "<<Tin.source<<" "<<Tin.source_line;
	return out;
}

/* ------------------------------------------------------ END HELP METHODS ------------------------------------------------------ */

%}


/* ============================================== Named patterns definitions ============================================== */

/* 
	1. be EXTREMELY careful with operators that are also defined in regexes: +  *  |  ^  [  ]  (  )  {  }  .  ?
	2. EXTREMELY careful with order - don't let a single symbol operator to be recognized inappropriately as part of a bigger operator
*/



/* -------------------------------------------------------- KEYWORDS -------------------------------------------------------- */

Keyword 				auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|volatile|do|if|static|while


/*
Keyword 				((auto)|(double)|(int)|(struct)|(break)|(else)|(long)|(switch)|(case)|(enum)|(register)|(typedef)|(char)|(extern)|(return)|(union)|(const)|(float)|(short)|(unsigned)|(continue)|(for)|(signed)|(void)|(default)|(goto)|(sizeof)|(volatile)|(do)|(if)|(static)|(while))

Keyword 				('auto'|'double'|'int'|'struct'|'break'|'else'|'long'|'switch'|'case'|'enum'|'register'|'typedef'|'char'|'extern'|'return'|'union'|'const'|'float'|'short'|'unsigned'|'continue'|'for'|'signed'|'void'|'default'|'goto'|'sizeof'|'volatile'|'do'|'if'|'static'|'while')

Keyword 				('auto'|'double'|'int'|'struct'|'break'|'else'|'long'|'switch'|'case'|'enum'|'register'|'typedef'|'char'|'extern'|'return'|'union'|'const'|'float'|'short'|'unsigned'|'continue'|'for'|'signed'|'void'|'default'|'goto'|'sizeof'|'volatile'|'do'|'if'|'static'|'while')

Keyword 				auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while
*/

/* -------------------------------------------------------- IDENTIFIERS -------------------------------------------------------- */

Identifier 				([a-zA-Z_]+[a-zA-Z0-9_]*)		
/* Pointers are in the operators scope */


/* -------------------------------------------------------- CONSTANTS -------------------------------------------------------- */

EXPONENT				([eE]{1}[+-]?[0-9]+)
FRACTIONAL_CONST		(([0-9]*\.[0-9]+)|([0-9]+\.))
FLOATING_SUFFIX			([flFL])
FLOATING_CONST			(({FRACTIONAL_CONST}{EXPONENT}?{FLOATING_SUFFIX}?)|([0-9]+{EXPONENT}{FLOATING_SUFFIX}?))

LONG_SUFFIX				([lL])
UNSIGNED_SUFFIX			([uU])
INT_SUFFIX				(({UNSIGNED_SUFFIX}{LONG_SUFFIX}?)|({LONG_SUFFIX}{UNSIGNED_SUFFIX}?))
HEX_DIGIT				([a-fA-F0-9])
NONZERO_DIGIT			([1-9])
HEX_CONST				(0[xX]{HEX_DIGIT}+)
OCTAL_DIGIT				([0-7])
OCTAL_CONST				(0{OCTAL_DIGIT}*)
DECIMAL_CONST			({NONZERO_DIGIT}[0-9]*)
INTEGER_CONST			(({DECIMAL_CONST}{INT_SUFFIX}?)|({HEX_CONST}{INT_SUFFIX}?)|({OCTAL_CONST}{INT_SUFFIX}?))

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
CHAR_CONST				(\'{C_CHAR_SEQUENCE}\'|L\'{C_CHAR_SEQUENCE}\')				


Constant 				({FLOATING_CONST}|{INTEGER_CONST}|{ENUM_CONST}|{CHAR_CONST})

/* -------------------------------------------------------- STRING LITERALS ------------------------------------------------------- */

S_CHAR					[^\"\\\n]|{ESC_SEQUENCE}								
S_CHAR_SEQUENCE			{S_CHAR}+												
StringLiteral			((\"{S_CHAR_SEQUENCE}?\")|(L\"{S_CHAR_SEQUENCE}?\"))

/* -------------------------------------------------------- OPERATORS -------------------------------------------------------- */


Operator 	((\[)|(\])|\(|\)|\{|\}|(\.\.\.)|(\.)|->|(\+\+)|--|sizeof|<<|>>|<=|>=|==|(!=)|(\|)|(&&)|(\|\|)|(\?)|(:)|(\*=)|(\/=)|(%=)|(\+=)|-=|<<=|>>=|&=|(\^=)|(\|=)|,|##|#|;|=|&|(\*)|(\+)|-|~|!|(\/)|%|<|>|(\^))		


/* WHY IS sizeof BOTH A KEYWORD AND AN OPERATOR
 What about \n \t ... - you whould probably recognize them so that you know a new token comes in
*/

/* -------------------------------------------------------- INVALID -------------------------------------------------------- */

Invalid 				.

/* -------------------------------------------------------- PREPROCESSOR -------------------------------------------------------- */

Preprocessor 			^#[ ].+$


/* NB - REGEX NOT SURE ABOUT:
	SIMPLE_ESC_SEQUENCE
	SCHAR 	- should be fine
*/

/* ============================================== Pattern matching rule section ============================================== */
/* What happens when no more input */
%%
[\n]				{ 	input_file_line++; source_file_line++; }
[ ]|[\t]			{ }
{Keyword}			{ cout<<Token(yytext, "Keyword", Keyword_token, input_file_line, source_file, source_file_line)<<endl; }
{Identifier}		{ cout<<Token(yytext, "Identifier", Identifier_token, input_file_line, source_file, source_file_line)<<endl; }
{FLOATING_CONST}	{ cout<<Token(yytext, "Constant", Float_const_token, input_file_line, source_file, source_file_line)<<endl; }
{INTEGER_CONST}		{ cout<<Token(yytext, "Constant", Int_const_token, input_file_line, source_file, source_file_line)<<endl; }
{CHAR_CONST}		{ cout<<Token(yytext, "Constant", Char_const_token, input_file_line, source_file, source_file_line)<<endl; }
{Operator}			{ cout<<Token(yytext, "Operator", Operator_token, input_file_line, source_file, source_file_line)<<endl; }
{StringLiteral}		{ cout<<Token(yytext, "StringLiteral", StringLiteral_token, input_file_line, source_file, source_file_line)<<endl; }
{Preprocessor}		{	process_prep(yytext);	}
{Invalid}			{ cout<<Token(yytext, "Invalid", Invalid_token, input_file_line, source_file, source_file_line)<<endl; }
%%
/* ==================== User function section - optional. Define the functions called on regex matches here ==================== */

//{Constant}			{ cout<<Token(yytext, "Constant", Constant_token, input_file_line, source_file, source_file_line)<<endl; }

int main(){

	yylex();

	return 0;
}