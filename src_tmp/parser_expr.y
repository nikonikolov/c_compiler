%code requires{
  #include <iostream>
  #include <string>  
  #include "../src/helper.hpp"
  #include "../src/DataStructures/Function.h"
  #include "../src/DataStructures/Loop.h"
  #include "../src/DataStructures/Variable.h"
  #include "../src/DataStructures/Constant.h"
  #include "../src/DataStructures/Conditional.h"
  #include "../src/DataStructures/VarDeclaration.h"
  #include "../src/DataStructures/ExpressionStatement.h"
  #include "../src/DataStructures/Expression.h"
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);

  //extern Function* root;
  
}

%union{
  char* strval;
  uint64_t intval;
  //int intval;
  double64_t floatval;

  Variable* varptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable>* vector_vars_ptr;
  vector<Statement*>* vector_statement_pointers_ptr;
  vector<Expression*>* vector_expr_pointers_ptr;
  
  vector<ConditionalCase*>* vector_conditional_case_pointers_ptr;
  
  Function* fn_ptr;
  Statement* statement_ptr;
  Expression* expr_ptr;
  ExpressionStatement* expr_statement_ptr;
}

/* --------------------------------------------------- TOKENS KEYWORDS --------------------------------------------------- */

%token <strval> AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT 
%token <strval> UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE

/* --------------------------------------------------- TOKENS OPERATORS --------------------------------------------------- */

%token <strval> LSQUARE RSQUARE LBRACKET RBRACKET LCURLY RCURLY THREE_DOTS DOT PTR_OP PLUS_PLUS MINUS_MINUS SIZEOF LSHIFT RSHIFT 
%token <strval> LESS_OR_EQUAL MORE_OR_EQUAL LOGICAL_EQUALITY LOGICAL_INEQUALITY LOGICAL_AND LOGICAL_OR Q_MARK COLON MULT_EQUALS 
%token <strval> DIV_EQUALS PERCENT_EQUALS PLUS_EQUALS MINUS_EQUALS LSHIFT_EQUALS RSHIFT_EQUALS AND_EQUALS XOR_EQUALS OR_EQUALS 
%token <strval> COMMA HASH HASH_HASH SEMI_COLON EQUALS BITWISE_OR BITWISE_AND BITWISE_XOR MULT PLUS MINUS WAVE EXL_MARK DIV PERCENT 
%token <strval> LOGICAL_MORE LOGICAL_LESS


/* --------------------------------------------------- TOKENS CONSTANTS --------------------------------------------------- */

%token <intval> INTEGER_CONST 
%token <floatval> FLOATING_CONST
%token CHAR_CONST 
/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token <strval> IDENTIFIER STRING_LITERAL

/* **** Only types that you use in the C++ code need to be defined **** */
/*%type <vector_vars_ptr> fn_params_list initialization_list

// NOTE: assignment_expression_list and assignment_expression are defined like that only for the purposes of the MILESTONE. 
// Need to think of a better solution for the final version. You will probably need some special class that can be both 
// a variable and a statement. Probably variable can inherit Statement. Or you make a new class called expression. It can be
// useful when dealing with arithmetic expressions. Variable can inherit from it, as a Variable is practically an expression 
// Expressions and Statements need to be related somehow. You can make Expression inferit from Statement
%type <vector_vars_ptr> assignment_expression_list
%type <strval> assignment_expression
%type <strval> expression

%type <strval> bracketed_identifier

%type <statement_ptr> loop for_loop while_loop do_while_loop if_block_statement fn_declaration declaration statement 

%type <vector_statement_pointers_ptr> compound_statement declaration_list statement_list

%type <vector_statement_pointers_ptr> program

%type <vector_conditional_case_pointers_ptr> if_statement else_statement else_statement_list
*/

/* ---------------------------------------------- EXPRESSION TYPES -------------------------------------------- */

%type <expr_ptr> CONSTANT primary_expression postfix_expression unary_expression cast_expression expression
%type <expr_ptr> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <expr_ptr> and_expression inclusive_or_expression exclusive_or_expression logical_and_expression logical_or_expression
%type <expr_ptr> conditional_expression assignment_expression 
%type <expr_statement_ptr> expression_list 

%type <statement_ptr> expression_statement 

%type <strval> UNARY_OPERATOR type_name ASSIGNMENT_OPERATOR
/* ---------------------------------------------- FOR DEBUGGING PURPOSES -------------------------------------------- */

/* Generate the parser description file.  */
%verbose
/* Enable run-time traces (yydebug).  */
%define parse.trace

/* Formatting semantic values.  */
//%printer { fprintf (yyoutput, "%s", $$.strval); } <char*>;
//%printer { cerr<<$$.strval; } <char*>;
//%printer { fprintf (yyoutput, "%s()", $$->strval); } FNCT;
//%printer { fprintf (yyoutput, "%g", $$); } <double>;

/* ---------------------------------------------- END FOR DEBUGGING PURPOSES -------------------------------------------- */



%start program

%{
  /* put additional C++ code here */
  // Probably a better idea to make root pointer to Program in the end as function will not inherit from statement
  vector<Statement*>* root=NULL;
%}

%%




/* ============================================== PROGRAM START ELEMENTS ============================================== */


program : expression_statement                                   { root = new vector<Statement*>; root->push_back($1);}
        | program expression_statement                           { root->push_back($2);}
        ;
        

/* ============================================== 3.1 LEXICAL ELEMENTS ============================================== */

/* ---------------------------------------------- 3.1.3 CONSTANTS -------------------------------------------- */

// Ready
// Final version should include ENUMERATION_CONSTANT
//CONSTANT : FLOATING_CONST | INTEGER_CONST | ENUMERATION_CONSTANT | CHAR_CONST ;

CONSTANT  : FLOATING_CONST                            { $$ = new Constant<double64_t>($1);} 
          | INTEGER_CONST                             { $$ = new Constant<uint64_t>($1);}
          | CHAR_CONST                                
          ;


/* ============================================== 3.3 EXPRESSIONS ============================================== */


/* ---------------------------------------------- 3.3.1 PRIMARY EXPRESSIONS -------------------------------------------- */

// Basic structure: Level 0 Precedence; corressponds to factor
primary_expression  // Identifier
                    : IDENTIFIER                            { $$ = new Variable($1);}
                    // Constant
                    | CONSTANT                              { $$ = $1;}
                    // string_literal
                    | STRING_LITERAL
                    // Reduction to bracketed expression
                    | LBRACKET expression RBRACKET          { $$ = $2; }
                    ;


/* ---------------------------------------------- 3.3.2 POSTFIX OPERATORS -------------------------------------------- */

// Level 1 Precedence
postfix_expression  // Reduction to Level 0 
                    : primary_expression                                                { $$ = $1; }
                    // Array access
                    | postfix_expression LSQUARE expression RSQUARE     
                    // Function call
                    | postfix_expression LBRACKET argument_expression_list RBRACKET     
                    // Function call with no arguments
                    | postfix_expression LBRACKET RBRACKET
                    // Structs and Unions member access
                    | postfix_expression DOT IDENTIFIER                                 //{ Expression* tmp = new Variable($3);
                                                                                        //  $$ = new Expression($1, $2, tmp);}
                    // Structs and Unions member access via pointers
                    | postfix_expression PTR_OP IDENTIFIER                              //{ Expression* tmp = new Variable($3);
                                                                                        //  $$ = new Expression($1, $2, tmp);}
                    // Post increment
                    | postfix_expression PLUS_PLUS                                      { $$ = new Expression($1, $2, NULL);}
                    // Post decrement
                    | postfix_expression MINUS_MINUS                                    { $$ = new Expression($1, $2, NULL);}
                    ;

// Note: Arguments to functions can be expressions. If so, the evaluation is executed
argument_expression_list  : assignment_expression
                          | argument_expression_list COMMA assignment_expression
                          ;


/* ---------------------------------------------- 3.3.3 UNARY OPERATORS -------------------------------------------- */

// Level 2 Precedence
unary_expression  // Reduction to Level 1 
                  : postfix_expression                                                  { $$ = $1;}
                  // Pre increment
                  | PLUS_PLUS unary_expression                                          { $$ = new Expression(NULL, $1, $2);}
                  // Pre decrement
                  | MINUS_MINUS unary_expression                                        { $$ = new Expression(NULL, $1, $2);}
                  // Type cast, see UNARY_OPERATOR
                  | UNARY_OPERATOR cast_expression                                      { $$ = new Expression(NULL, $1, $2);}
                  // Sizeof 
                  | SIZEOF unary_expression                                             { $$ = new Expression(NULL, $1, $2);}
                  // Sizeof type
                  | SIZEOF LBRACKET type_name RBRACKET                                  //{ $$ = new Expression(NULL, $1, $3);}
                  ;

UNARY_OPERATOR  // Address-of
                : BITWISE_AND                         { $$ = $1; }
                // Dereference(Contents of address) 
                | MULT                                { $$ = $1; }
                // Positive 
                | PLUS                                { $$ = $1; }
                // Negative
                | MINUS                               { $$ = $1; }
                // Bitwise negation 
                | WAVE                                { $$ = $1; }
                // Logical Negation
                | EXL_MARK                            { $$ = $1; }
                ;

cast_expression : unary_expression                                                      { $$ = $1; }
                | LBRACKET type_name RBRACKET cast_expression                           { $$ = new Expression(NULL, $2, $4);}
                ;


/* ---------------------------------------------- 3.3.5 MULTIPLICATIVE OPERATORS -------------------------------------------- */

// Level 3 Precedence
multiplicative_expression // Reduction to Level 2 
                          : cast_expression                                             { $$ = $1;}                                  
                          // Multiplication
                          | multiplicative_expression MULT cast_expression              { $$ = new Expression($1, $2, $3);}
                          // Division
                          | multiplicative_expression DIV cast_expression               { $$ = new Expression($1, $2, $3);}
                          // Remainder
                          | multiplicative_expression PERCENT cast_expression           { $$ = new Expression($1, $2, $3);}
                          ;


/* ---------------------------------------------- 3.3.6 ADDITIVE OPERATORS -------------------------------------------- */

// Level 4 Precedence
additive_expression // Reduction to Level 3 
                    : multiplicative_expression                                         { $$ = $1; }
                    // Addition
                    | additive_expression PLUS multiplicative_expression                { $$ = new Expression($1, $2, $3);}
                    // Subtraction
                    | additive_expression MINUS multiplicative_expression               { $$ = new Expression($1, $2, $3);}
                    ;


/* ---------------------------------------------- 3.3.7 BITWISE SHIFT OPERATORS -------------------------------------------- */

// Level 5 Precedence
shift_expression  // Reduction to Level 4
                  : additive_expression                                                 { $$ = $1;}
                  // Bitwise shift left
                  | shift_expression LSHIFT additive_expression                         { $$ = new Expression($1, $2, $3);}
                  // Bitwise shift right
                  | shift_expression RSHIFT additive_expression                         { $$ = new Expression($1, $2, $3);}
                  ;


/* ---------------------------------------------- 3.3.8 RELATIONAL OPERATORS -------------------------------------------- */

// Level 6 Precedence
relational_expression // Reduction to Level 5 
                      : shift_expression                                                { $$ = $1; }
                      // More than comparison
                      | relational_expression LOGICAL_LESS shift_expression             { $$ = new Expression($1, $2, $3);}
                      // Less than comparison
                      | relational_expression LOGICAL_MORE shift_expression             { $$ = new Expression($1, $2, $3);}
                      // Less than or equal comparison
                      | relational_expression LESS_OR_EQUAL shift_expression            { $$ = new Expression($1, $2, $3);}
                      // More than or equal comparison
                      | relational_expression MORE_OR_EQUAL shift_expression            { $$ = new Expression($1, $2, $3);}
                      ;   


/* ---------------------------------------------- 3.3.9 EQUALITY OPERATORS -------------------------------------------- */

// Level 7 Precedence
equality_expression // Reduction to Level 6
                    : relational_expression                                             { $$ = $1; }
                    // Logical equality comparison
                    | equality_expression LOGICAL_EQUALITY relational_expression        { $$ = new Expression($1, $2, $3);}
                    // Logical ineqality comparison
                    | equality_expression LOGICAL_INEQUALITY relational_expression      { $$ = new Expression($1, $2, $3);}          
                    ;

/* ---------------------------------------------- 3.3.10 BITWISE AND OPERATOR -------------------------------------------- */

// Level 8 Precedence
and_expression  // Reduction to Level 7
                : equality_expression                                                   { $$ = $1; } 
                // Bitwise AND operation between two arguments
                | and_expression BITWISE_AND equality_expression                        { $$ = new Expression($1, $2, $3);}
                ;


/* -------------------------------------------- 3.3.11 BITWISE EXCLUSIVE OR OPERATOR ------------------------------------------ */

// Level 9 Precedence
exclusive_or_expression // Reduction to Level 8
                        : and_expression                                                { $$ = $1; }
                        // Bitwise XOR operation between two arguments
                        | exclusive_or_expression BITWISE_XOR and_expression            { $$ = new Expression($1, $2, $3);}
                        ;


/* -------------------------------------------- 3.3.12 BITWISE INCLUSIVE OR OPERATOR ------------------------------------------ */

// Level 10 Precedence
inclusive_or_expression // Reduction to Level 9
                        : exclusive_or_expression                                       { $$ = $1; }
                        // Bitwise OR operation between two arguments
                        | inclusive_or_expression BITWISE_OR exclusive_or_expression    { $$ = new Expression($1, $2, $3);}         
                        ;


/* -------------------------------------------- 3.3.13 LOGICAL AND OPERATOR ------------------------------------------ */

// Level 11 Precedence
logical_and_expression  // Reduction to Level 10
                        : inclusive_or_expression                                       { $$ = $1; }
                        // Logical AND expression
                        | logical_and_expression LOGICAL_AND inclusive_or_expression    { $$ = new Expression($1, $2, $3);}
                        ;


/* -------------------------------------------- 3.3.14 LOGICAL OR OPERATOR ------------------------------------------ */

// Level 12 Precedence
logical_or_expression // Reduction to Level 11
                      : logical_and_expression                                          { $$ = $1; } 
                      // Logical OR expression
                      | logical_or_expression LOGICAL_OR logical_and_expression         { $$ = new Expression($1, $2, $3);}
                      ;


/* -------------------------------------------- 3.3.15 CONDITIONAL OPERATOR ------------------------------------------ */

// Level 13 Precedence
conditional_expression  // Reduction to Level 12
                        : logical_or_expression                                         { $$ = $1; }
                        // Ternary conditional
                        | logical_or_expression Q_MARK expression COLON conditional_expression   
                        ;

/* -------------------------------------------- 3.3.16 ASSIGNMENT OPERATOR ------------------------------------------ */

// You probably need to make some synchronizations with your grammar at this point

// Level 14 Precedence
assignment_expression // Reduction to Level 13
                      : conditional_expression                                          { $$ = $1; }
                      // Assignment
                      | unary_expression ASSIGNMENT_OPERATOR assignment_expression      { $$ = new Expression($1, $2, $3);}
                      ;

ASSIGNMENT_OPERATOR : EQUALS                      { $$ = $1;}
                    | MULT_EQUALS                 { $$ = $1;}
                    | DIV_EQUALS                  { $$ = $1;}
                    | PERCENT_EQUALS              { $$ = $1;}
                    | PLUS_EQUALS                 { $$ = $1;}
                    | MINUS_EQUALS                { $$ = $1;}
                    | LSHIFT_EQUALS               { $$ = $1;}
                    | RSHIFT_EQUALS               { $$ = $1;} 
                    | AND_EQUALS                  { $$ = $1;}
                    | XOR_EQUALS                  { $$ = $1;}
                    | OR_EQUALS                   { $$ = $1;}
                    ;

// Level 14 Precedence
expression  : assignment_expression               { $$ = $1;}
            ;

/* -------------------------------------------- 3.3.17 COMMA OPERATOR ------------------------------------------ */

// You probably need to make some synchronizations with your grammar at this point

// Level 15 Precedence
expression_list // Reduction to Level 14
                : expression                                        { $$ = new ExpressionStatement($1);}                                    
                // List of expressions
                | expression COMMA assignment_expression            { $$->push_back($3);}
                ;

expression_statement  : expression_list SEMI_COLON                  { $$ = $1;}
                      ;

/* ============================================== 3.4 CONSTANT EXPRESSIONS ============================================== */

// NB: Although not yeat needed, this might be very very useful for structs and enums. Check the C grammar
//CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION ;            

// Repair
type_name : INT                                       { $$ = $1; }
          | DOUBLE                                    { $$ = $1; }
          | CHAR                                      { $$ = $1; }
          ;
%%  

int yyerror(const char* s){ 
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
  std::cerr <<"File: "<< source_file<<", Line: "<<input_file_line << std::endl;
  return -1;
}

int main(){

  yydebug=1;

  cerr<<"========================================= Parsing starts ========================================="<<endl;
  yyparse();
  cerr<<"========================================= Parsing successful ========================================="<<endl;

  if(root==NULL) return 0;

  cerr<<"========================================= Printing starts ========================================="<<endl;

  vector<Statement*>::iterator it;
  for(it=root->begin(); it!=root->end(); ++it){
    if(*it!=NULL) (*it)->pretty_print(4);
  }

  cerr<<"========================================= Printing successful ========================================="<<endl;

  return 0;
}





