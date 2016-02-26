%code requires{
  #include <iostream>
  #include <string>  
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);
}

%union{
  string* str_t;
}

/* --------------------------------------------------- TOKENS KEYWORDS --------------------------------------------------- */

%token AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT 
%token UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE

/* --------------------------------------------------- TOKENS OPERATORS --------------------------------------------------- */

%token LSQUARE RSQUARE LBRACKET RBRACKET LCURLY RCURLY THREE_DOTS DOT PTR_OP PLUS_PLUS MINUS_MINUS SIZEOF LSHIFT RSHIFT 
%token LESS_OR_EQUAL MORE_OR_EQUAL LOGICAL_EQUALITY LOGICAL_INEQUALITY LOGICAL_AND LOGICAL_OR Q_MARK COLON MULT_EQUALS 
%token DIV_EQUALS PERCENT_EQUALS PLUS_EQUALS MINUS_EQUALS LSHIFT_EQUALS RSHIFT_EQUALS AND_EQUALS XOR_EQUALS OR_EQUALS 
%token COMMA HASH HASH_HASH SEMI_COLON EQUALS BITWISE_OR BITWISE_AND MULT PLUS MINUS WAVE EXL_MARK DIV PERCENT LOGICAL_LESS 
%token LOGICAL_MORE BITWISE_XOR

/* --------------------------------------------------- TOKENS CONSTANTS --------------------------------------------------- */

%token FLOATING_CONST INTEGER_CONST CHAR_CONST

/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token IDENTIFIER STRING_LITERAL

%type <str_t> DECLARATION_SPECIFIERS 
%type <str_t> DECLARATOR       
%type <str_t> DECLARATION_LIST 
%type <str_t> COMPOUND_STATEMENT


%{
  /* put additional C++ code here */
%}

%%

/*  UNCLEAR STUFF:
      1. What about multiple brackets around expressions 
*/

/* ============================================== 3.1 LEXICAL ELEMENTS ============================================== */

/* ---------------------------------------------- 3.1.3 CONSTANTS -------------------------------------------- */

CONSTANT : FLOATING_CONST | INTEGER_CONST | ENUMERATION_CONSTANT | CHAR_CONST ;


/* ============================================== 3.3 EXPRESSIONS ============================================== */


/* ---------------------------------------------- 3.3.1 PRIMARY EXPRESSIONS -------------------------------------------- */


PRIMARY_EXPRESSION  : IDENTIFIER
                    | CONSTANT
                    | STRING_LITERAL
                    | LBRACKET EXPRESSION RBRACKET
                    ;

/* ---------------------------------------------- 3.3.2 POSTFIX OPERATORS -------------------------------------------- */

POSTFIX_EXPRESSION  : PRIMARY_EXPRESSION
                    | POSTFIX_EXPRESSION LSQUARE EXPRESSION RSQUARE
                    | POSTFIX_EXPRESSION LBRACKET ARGUMENT_EXPRESSION_LIST RBRACKET
                    | POSTFIX_EXPRESSION LBRACKET  RBRACKET
                    | POSTFIX_EXPRESSION DOT IDENTIFIER
                    | POSTFIX_EXPRESSION PTR_OP IDENTIFIER
                    | POSTFIX_EXPRESSION PLUS_PLUS
                    | POSTFIX_EXPRESSION MINUS_MINUS
                    ;

ARGUMENT_EXPRESSION_LIST  : ASSIGNMENT_EXPRESSION
                          | ARGUMENT_EXPRESSION_LIST COMMA ASSIGNMENT_EXPRESSION
                          ;

/* ---------------------------------------------- 3.3.3 UNARY OPERATORS -------------------------------------------- */

UNARY_EXPRESSION  : POSTFIX_EXPRESSION
                  | PLUS_PLUS UNARY_EXPRESSION
                  | MINUS_MINUS UNARY_EXPRESSION
                  | UNARY_OPERATOR CAST_EXPRESSION
                  | SIZEOF UNARY_EXPRESSION
                  | SIZEOF LBRACKET TYPE_NAME RBRACKET
                  ;

UNARY_OPERATOR: LOGICAL_AND | MULT | PLUS | MINUS | WAVE | EXL_MARK ;


/* ---------------------------------------------- 3.3.4 CAST OPERATORS -------------------------------------------- */

CAST_EXPRESSION : UNARY_EXPRESSION
                | LBRACKET TYPE_NAME RBRACKET CAST_EXPRESSION
                ;

/* ---------------------------------------------- 3.3.5 MULTIPLICATIVE OPERATORS -------------------------------------------- */

MULTIPLICATIVE_EXPRESSION : CAST_EXPRESSION
                          | MULTIPLICATIVE_EXPRESSION MULT CAST_EXPRESSION
                          | MULTIPLICATIVE_EXPRESSION DIV CAST_EXPRESSION
                          | MULTIPLICATIVE_EXPRESSION PERCENT CAST_EXPRESSION
                          ;

/* ---------------------------------------------- 3.3.6 ADDITIVE OPERATORS -------------------------------------------- */

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION
                    | ADDITIVE_EXPRESSION PLUS MULTIPLICATIVE_EXPRESSION
                    | ADDITIVE_EXPRESSION MINUS MULTIPLICATIVE_EXPRESSION
                    ;


/* ---------------------------------------------- 3.3.7 BITWISE SHIFT OPERATORS -------------------------------------------- */

SHIFT_EXPRESSION  : ADDITIVE_EXPRESSION
                  | SHIFT_EXPRESSION LSHIFT ADDITIVE_EXPRESSION
                  | SHIFT_EXPRESSION RSHIFT ADDITIVE_EXPRESSION
                  ;

/* ---------------------------------------------- 3.3.8 RELATIONAL OPERATORS -------------------------------------------- */

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION
                      | RELATIONAL_EXPRESSION LOGICAL_LESS SHIFT_EXPRESSION
                      | RELATIONAL_EXPRESSION LOGICAL_MORE SHIFT_EXPRESSION
                      | RELATIONAL_EXPRESSION LESS_OR_EQUAL SHIFT_EXPRESSION
                      | RELATIONAL_EXPRESSION MORE_OR_EQUAL SHIFT_EXPRESSION                 
                      ;   

/* ---------------------------------------------- 3.3.9 EQUALITY OPERATORS -------------------------------------------- */

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION
                    | EQUALITY_EXPRESSION LOGICAL_EQUALITY RELATIONAL_EXPRESSION
                    | EQUALITY_EXPRESSION LOGICAL_INEQUALITY RELATIONAL_EXPRESSION                
                    ;

/* ---------------------------------------------- 3.3.10 BITWISE AND OPERATOR -------------------------------------------- */

AND_EXPRESSION  : EQUALITY_EXPRESSION
                | AND_EXPRESSION BITWISE_AND EQUALITY_EXPRESSION
                ;

/* -------------------------------------------- 3.3.11 BITWISE EXCLUSIVE OR OPERATOR ------------------------------------------ */

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION
                        | EXCLUSIVE_OR_EXPRESSION BITWISE_XOR AND_EXPRESSION
                        ;


/* -------------------------------------------- 3.3.12 BITWISE INCLUSIVE OR OPERATOR ------------------------------------------ */

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION
                        | INCLUSIVE_OR_EXPRESSION BITWISE_OR EXCLUSIVE_OR_EXPRESSION                        
                        ;

/* -------------------------------------------- 3.3.13 LOGICAL AND OPERATOR ------------------------------------------ */

LOGICAL_AND_EXPRESSION  : INCLUSIVE_OR_EXPRESSION
                        | LOGICAL_AND_EXPRESSION LOGICAL_AND INCLUSIVE_OR_EXPRESSION
                        ;

/* -------------------------------------------- 3.3.14 LOGICAL OR OPERATOR ------------------------------------------ */

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION
                      | LOGICAL_OR_EXPRESSION LOGICAL_OR LOGICAL_AND_EXPRESSION
                      ;

/* -------------------------------------------- 3.3.15 CONDITIONAL OPERATOR ------------------------------------------ */

CONDITIONAL_EXPRESSION  : LOGICAL_OR_EXPRESSION
                        | LOGICAL_OR_EXPRESSION Q_MARK EXPRESSION COLON CONDITIONAL_EXPRESSION 
                        ;

/* -------------------------------------------- 3.3.16 ASSIGNMENT OPERATOR ------------------------------------------ */

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION
                      | UNARY_EXPRESSION ASSIGNMENT_OPERATOR ASSIGNMENT_EXPRESSION
                      ;

ASSIGNMENT_OPERATOR : EQUALS
                    | MULT_EQUALS
                    | DIV_EQUALS
                    | PERCENT_EQUALS
                    | PLUS_EQUALS
                    | MINUS_EQUALS
                    | LSHIFT_EQUALS
                    | RSHIFT_EQUALS
                    | AND_EQUALS
                    | XOR_EQUALS
                    | OR_EQUALS
                    ;

/* -------------------------------------------- 3.3.17 COMMA OPERATOR ------------------------------------------ */

EXPRESSION  : ASSIGNMENT_EXPRESSION
            | EXPRESSION COMMA ASSIGNMENT_EXPRESSION
            ;


/* ============================================== 3.4 CONSTANT EXPRESSIONS ============================================== */

CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION ;

/* ============================================== 3.5 DECLARATIONS ============================================== */


DECLARATION : DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST
            | DECLARATION_SPECIFIERS
            ;

DECLARATION_SPECIFIERS  : STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIERS
                        | STORAGE_CLASS_SPECIFIER 
                        | TYPE_SPECIFIER DECLARATION_SPECIFIERS
                        | TYPE_SPECIFIER
                        | TYPE_QUALIFIER DECLARATION_SPECIFIERS
                        | TYPE_QUALIFIER
                        ;

INIT_DECLARATOR_LIST  : INIT_DECLARATOR
                      | INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR 
                      ;

INIT_DECLARATOR   : DECLARATOR
                  | DECLARATOR EQUALS INITIALIZER
                  ;


/* -------------------------------------------- 3.5.1 STORAGE_CLASS_SPECIFIERS ------------------------------------------ */

STORAGE_CLASS_SPECIFIER   : TYPEDEF
                          | EXTERN
                          | STATIC
                          | AUTO
                          | REGISTER
                          ;


/* -------------------------------------------- 3.5.2 TYPE SPECIFIERS -------------------------------------------- */

TYPE_SPECIFIER  : VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED | UNSIGNED 
                | STRUCT_OR_UNION_SPECIFIER | ENUM_SPECIFIER | TYPEDEF_NAME
                ;

/* ------------------------------------------ 3.5.2.1 STRUCTURE AND UNION SPECIFIERS ---------------------------------------- */

STRUCT_OR_UNION_SPECIFIER   : STRUCT_OR_UNION IDENTIFIER LCURLY STRUCT_DECLARATION_LIST RCURLY
                            | STRUCT_OR_UNION LCURLY STRUCT_DECLARATION_LIST RCURLY
                            | STRUCT_OR_UNION IDENTIFIER
                            ;

STRUCT_OR_UNION : STRUCT | UNION ;

STRUCT_DECLARATION_LIST : STRUCT_DECLARATION 
                        | STRUCT_DECLARATION_LIST STRUCT_DECLARATION
                        ;

STRUCT_DECLARATION :  SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST ;

SPECIFIER_QUALIFIER_LIST  : TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST
                          | TYPE_SPECIFIER
                          | TYPE_QUALIFIER SPECIFIER_QUALIFIER_LIST
                          | TYPE_QUALIFIER
                          ;

STRUCT_DECLARATOR_LIST  : STRUCT_DECLARATOR
                        | STRUCT_DECLARATOR_LIST COMMA STRUCT_DECLARATOR
                        ;

STRUCT_DECLARATOR   : DECLARATOR
                    | DECLARATOR COLON CONSTANT_EXPRESSION
                    | COLON CONSTANT_EXPRESSION
                    ;

/* ---------------------------------------------- 3.5.2.2 ENUMERATION SPECIFIERS -------------------------------------------- */

ENUM_SPECIFIER  : ENUM IDENTIFIER LCURLY ENUMERATOR_LIST RCURLY
                | ENUM LCURLY ENUMERATOR_LIST RCURLY
                | ENUM IDENTIFIER
                ;

ENUMERATOR_LIST : ENUMERATOR
                | ENUMERATOR_LIST COMMA ENUMERATOR
                ;

ENUMERATOR  : ENUMERATION_CONSTANT
            | ENUMERATION_CONSTANT EQUALS CONSTANT_EXPRESSION
            ;

ENUMERATION_CONSTANT : IDENTIFIER ;           


/* ---------------------------------------------- 3.5.3 TYPE QUALIFIERS -------------------------------------------- */

TYPE_QUALIFIER  : CONST
                | VOLATILE
                ;

/* ---------------------------------------------- 3.5.4 DECLARATORS -------------------------------------------- */

DECLARATOR  : POINTER DIRECT_DECLARATOR
            | DIRECT_DECLARATOR
            ;

// not sure about brackets
DIRECT_DECLARATOR : IDENTIFIER
                  | LBRACKET DECLARATOR RBRACKET
                  | DIRECT_DECLARATOR LSQUARE CONSTANT_EXPRESSION RSQUARE
                  | DIRECT_DECLARATOR LSQUARE RSQUARE
                  | DIRECT_DECLARATOR LBRACKET PARAMETER_TYPE_LIST RBRACKET
                  | DIRECT_DECLARATOR RBRACKET IDENTIFIER_LIST RBRACKET
                  | DIRECT_DECLARATOR RBRACKET RBRACKET
                  ;

POINTER : MULT TYPE_QUALIFIER_LIST
        | MULT 
        | MULT TYPE_QUALIFIER_LIST POINTER
        | MULT POINTER
        ;

TYPE_QUALIFIER_LIST : TYPE_QUALIFIER
                    | TYPE_QUALIFIER_LIST TYPE_QUALIFIER
                    ;

PARAMETER_TYPE_LIST : PARAMETER_LIST
                    | PARAMETER_LIST COMMA THREE_DOTS
                    ;

PARAMETER_LIST  : PARAMETER_DECLARATION
                | PARAMETER_LIST COMMA PARAMETER_DECLARATION
                ;

PARAMETER_DECLARATION : DECLARATION_SPECIFIERS DECLARATOR
                      | DECLARATION_SPECIFIERS ABSTRACT_DECLARATOR
                      | DECLARATION_SPECIFIERS
                      ;

IDENTIFIER_LIST : IDENTIFIER
                | IDENTIFIER_LIST COMMA IDENTIFIER
                ;

/* ---------------------------------------------- 3.5.5 TYPE NAMES -------------------------------------------- */

TYPE_NAME : SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR
          | SPECIFIER_QUALIFIER_LIST
          ;

ABSTRACT_DECLARATOR   : POINTER
                      | POINTER DIRECT_ABSTRACT_DECLARATOR
                      | DIRECT_ABSTRACT_DECLARATOR
                      ;

// !!! not sure about this one
DIRECT_ABSTRACT_DECLARATOR  : LBRACKET ABSTRACT_DECLARATOR RBRACKET
                            | DIRECT_ABSTRACT_DECLARATOR LSQUARE CONSTANT_EXPRESSION RSQUARE
                            | DIRECT_ABSTRACT_DECLARATOR LSQUARE RSQUARE
                            | LSQUARE CONSTANT_EXPRESSION RSQUARE
                            | LSQUARE RSQUARE
                            | DIRECT_ABSTRACT_DECLARATOR LBRACKET PARAMETER_TYPE_LIST RBRACKET
                            | DIRECT_ABSTRACT_DECLARATOR LBRACKET RBRACKET
                            | LBRACKET PARAMETER_TYPE_LIST RBRACKET
                            | LBRACKET RBRACKET
                            ; 


/* ---------------------------------------------- 3.5.6 TYPE DEFINITIONS -------------------------------------------- */

TYPEDEF_NAME : IDENTIFIER ;

/* ---------------------------------------------- 3.5.7 INITIALIZATION -------------------------------------------- */

INITIALIZER : ASSIGNMENT_EXPRESSION
            | LCURLY INITIALIZER_LIST RCURLY
            | LCURLY INITIALIZER_LIST COMMA RCURLY
            ;


INITIALIZER_LIST  : INITIALIZER
                  | INITIALIZER_LIST COMMA INITIALIZER
                  ;

/* ============================================== 3.6 STATEMENTS ============================================== */

STATEMENT   : LABELED_STATEMENT
            | COMPOUND_STATEMENT
            | EXPRESSION_STATEMENT
            | SELECTION_STATEMENT
            | ITERATION_STATEMENT
            | JUMP_STATEMENT
            ;

/* ---------------------------------------------- 3.6.1 LABELED STATEMENTS -------------------------------------------- */

LABELED_STATEMENT : IDENTIFIER COLON STATEMENT
                  | CASE CONSTANT_EXPRESSION COLON STATEMENT
                  | DEFAULT COLON STATEMENT
                  ;

/* ---------------------------------------------- 3.6.2 COMPOUND STATEMENTS -------------------------------------------- */

// not sure
COMPOUND_STATEMENT  : LCURLY DECLARATION_LIST STATEMENT_LIST RCURLY 
                    | LCURLY STATEMENT_LIST RCURLY 
                    | LCURLY DECLARATION_LIST RCURLY 
                    | LCURLY RCURLY 
                    ;

DECLARATION_LIST  : DECLARATION
                  | DECLARATION_LIST DECLARATION
                  ;

STATEMENT_LIST  : STATEMENT
                | STATEMENT_LIST STATEMENT                  
                ;

/* --------------------------------------------- 3.6.3 EXPRESSION AND NULL STATEMENTS ------------------------------------------- */

// not sure whether it can be empty and how to specify empty
EXPRESSION_STATEMENT :  EXPRESSION | ;

/* --------------------------------------------- 3.6.4 SELECTION STATEMENTS ------------------------------------------- */

SELECTION_STATEMENT : IF LBRACKET EXPRESSION RBRACKET STATEMENT
                    | IF LBRACKET EXPRESSION RBRACKET STATEMENT ELSE STATEMENT
                    | SWITCH LBRACKET EXPRESSION RBRACKET STATEMENT
                    ;

/* --------------------------------------------- 3.6.5 ITERATION STATEMENTS ------------------------------------------- */

ITERATION_STATEMENT : WHILE LBRACKET EXPRESSION RBRACKET STATEMENT
                    | DO STATEMENT WHILE LBRACKET EXPRESSION RBRACKET ;
                    | FOR LBRACKET EXPRESSION SEMI_COLON EXPRESSION SEMI_COLON EXPRESSION RBRACKET STATEMENT
                    | FOR LBRACKET SEMI_COLON EXPRESSION SEMI_COLON EXPRESSION RBRACKET STATEMENT
                    | FOR LBRACKET EXPRESSION SEMI_COLON SEMI_COLON EXPRESSION RBRACKET STATEMENT
                    | FOR LBRACKET EXPRESSION SEMI_COLON EXPRESSION SEMI_COLON RBRACKET STATEMENT
                    | FOR LBRACKET SEMI_COLON SEMI_COLON EXPRESSION RBRACKET STATEMENT
                    | FOR LBRACKET SEMI_COLON EXPRESSION SEMI_COLON RBRACKET STATEMENT
                    | FOR LBRACKET EXPRESSION SEMI_COLON SEMI_COLON RBRACKET STATEMENT
                    | FOR LBRACKET SEMI_COLON SEMI_COLON RBRACKET STATEMENT
                    ;

/* --------------------------------------------- 3.6.6 JUMP STATEMENTS ------------------------------------------- */
JUMP_STATEMENT  : GOTO IDENTIFIER SEMI_COLON
                | CONTINUE SEMI_COLON
                | BREAK SEMI_COLON
                | RETURN EXPRESSION SEMI_COLON
                | RETURN SEMI_COLON
                ;


/* ============================================== 3.7 EXTERNAL DEFINITIONS ============================================== */

TRANSLATION_UNIT  : EXTERNAL_DECLARATION
                  | TRANSLATION_UNIT EXTERNAL_DECLARATION
                  ;

EXTERNAL_DECLARATION  : FUNCTION_DEFINITION
                      | DECLARATION
                      ;

/* --------------------------------------------- 3.7.1 FUNCTION DEFINITIONS ------------------------------------------- */

FUNCTION_DEFINITION : DECLARATION_SPECIFIERS DECLARATOR     {cout<<"%1 "<<$1<<" "<<$2<<endl;}
                    | DECLARATOR                            {cout<<"%2 "<<$1<<endl;}
                    | DECLARATION_LIST COMPOUND_STATEMENT   {cout<<"%3 "<<$1<<" "<<$2<<endl;}
                    | COMPOUND_STATEMENT                    {cout<<"%4 "<<$1<<endl;}
                    ;



%%  

int yyerror(const char* s){ 
    std::cout <<"yyerror "<< s << std::endl;
    return -1;
}

int main(){
  cout<<"Parsing starts"<<endl;
  yyparse();
}





