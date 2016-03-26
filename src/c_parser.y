%code requires{
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

}

%union{
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

%token <uint64val>   INTEGER_CONST 
%token <floatval> FLOATING_CONST
%token <strval>   CHAR_CONST      // Probably needs changing

/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token <strval> IDENTIFIER STRING_LITERAL


/* --------------------------------------------------------------------------------------------------------------------- */

/* --------------------------------------------------- NON TERMINALS --------------------------------------------------- */

/* --------------------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------- DECALRATION TYPES -------------------------------------------- */

%type <vector_vars_ptrs_ptr> fn_params_list init_declarator_list

%type <var_ptr> init_declarator direct_declarator declarator
%type <base_expr_ptr> initializer
%type <arr_expr_ptr> initializer_list

%type <vector_var_declarations_ptrs_ptr> declaration_list
%type <var_declaration_ptr> declaration

%type <fn_ptr> fn_declaration fn_prototype

%type <intval>   pointer 

/* ---------------------------------------------- STATEMENT TYPES -------------------------------------------- */

%type <strval> bracketed_identifier

%type <statement_ptr> if_block_statement statement semi_colon_statement return_statement 

%type <vector_statement_pointers_ptr> statement_list

%type <vector_statement_pointers_ptr> program

%type <vector_conditional_case_pointers_ptr> if_statement else_statement else_statement_list

%type <compound_statement_ptr> compound_statement

/* ---------------------------------------------- LOOPS -------------------------------------------- */

%type <statement_ptr> loop for_loop while_loop do_while_loop

%type <fl_tuple> for_loop_decl_statement

/* ---------------------------------------------- EXPRESSION TYPES -------------------------------------------- */

%type <base_expr_ptr> CONSTANT primary_expression postfix_expression unary_expression cast_expression expression
%type <base_expr_ptr> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <base_expr_ptr> and_expression inclusive_or_expression exclusive_or_expression logical_and_expression logical_or_expression
%type <base_expr_ptr> conditional_expression assignment_expression constant_expression
%type <vector_base_expression_ptrs_ptr> argument_expression_list expression_list

%type <statement_ptr> expression_statement 

%type <strval> UNARY_OPERATOR type_name ASSIGNMENT_OPERATOR

/* ---------------------------------------------- FOR DEBUGGING PURPOSES -------------------------------------------- */

/* Generate the parser description file.  */
%verbose
/* Enable run-time traces (yydebug).  */
%define parse.trace

/* ---------------------------------------------- END FOR DEBUGGING PURPOSES -------------------------------------------- */

%start program

%{
  /* put additional C++ code here */
  Program* root=NULL;
%}

%%

/*  NOTES:
    1. GRAMMAR: Terminals are upper case while non-terminals are lower-case
    2. RECURSION: You should always use left recursion, otherwise you can blow the stack. Left recursion looks like:
        expseq  : exp
                | expseq ',' exp
                ;
    3. Types:
      Lexer converts all types to their proper representation for use by the parser
*/




/* ============================================== PROGRAM START ELEMENTS ============================================== */


program : fn_declaration                                   { root = new Program(); root->insert_fn($1);}
        | declaration                                      { root = new Program(); root->push_var_back($1);}
        | fn_prototype                                     { root = new Program(); root->insert_fn_prototype($1);}
        | program fn_declaration                           { root->insert_fn($2); }
        | program declaration                              { root->push_var_back($2); }
        | program fn_prototype                             { root->insert_fn_prototype($2);}
        ;
        
/* ===================================================================================================================== */

/* ============================================== 3.1 LEXICAL ELEMENTS ============================================== */

/* ===================================================================================================================== */


/* ---------------------------------------------- 3.1.3 CONSTANTS -------------------------------------------- */

CONSTANT  : FLOATING_CONST                            { $$ = new Constant<double64_t>($1);} 
          | INTEGER_CONST                             { $$ = new Constant<uint64_t>($1);}
          | CHAR_CONST 
          //| ENUMERATION_CONSTANT                               
          ;



/* -------------------------------------------- 3.5.2.2. ENUMERATION SPECIFIERS ------------------------------------------ */

/*
// The whole ENUM statement
enum_specifier  : ENUM IDENTIFIER LCURLY enumerator_list RCURLY SEMI_COLON
                | ENUM LCURLY enumerator_list RCURLY SEMI_COLON
                | ENUM IDENTIFIER SEMI_COLON
                ;

enumerator_list : enumerator
                | enumerator_list COMMA enumerator
                ;

// enumerator value/constant
enumerator  : ENUMERATION_CONSTANT
            | ENUMERATION_CONSTANT EQUALS constant_expression
            ;

ENUMERATION_CONSTANT : IDENTIFIER ;           
*/


/* -------------------------------------------- TYPE NAMES AND SPECIFIERS ------------------------------------------ */

type_name : INT                                       { $$ = $1; }
          | DOUBLE                                    { $$ = $1; }
          | CHAR                                      { $$ = $1; }
          ;

/* ===================================================================================================================== */

/* ============================================== 3.5 DECLARATIONS ============================================== */

/* ===================================================================================================================== */


/* -------------------------------------------- VARIABLE DECLARATIONS ------------------------------------------ */

// Declaration of a variable; C-grammar uses declaration_type instead of INT
declaration : INT init_declarator_list SEMI_COLON              { $$ = new VarDeclaration($1, $2); }
            // Allowed but not sensible. Simply ignore
            | INT SEMI_COLON   { cerr<<"Warning: Useless definition in file "<<source_file<<", Line: "<<input_file_line<<endl;}
            ;

// Initialization list (List of variable declarations)
init_declarator_list  : init_declarator                                   { $$ = new vector<Variable*>; $$->push_back($1); }
                      | init_declarator_list COMMA init_declarator        { $$->push_back($3); }
                      ;
                      
// Variable name and initialization/value (if provided) at declaration
init_declarator   : declarator                                            { $$ = $1;}
                  | declarator EQUALS initializer                         { $$ = $1; $$->set_init_val($3);}
                  ;

/* ---------------------------------------------- LHS OF INITIALIZATION -------------------------------------------- */

// LHS of variable initialization
declarator  : direct_declarator                                           { $$ = $1; }
            | pointer direct_declarator                                   { $$ = $2; $$->inc_deref_lvl($1); }
            ;

// Variable name, Array cell or function
direct_declarator : IDENTIFIER                                            { $$ = new Variable(NULL, $1, source_line, source_file); }
                  | LBRACKET declarator RBRACKET                          { $$ = $2; }
                  // Array cell
                  | direct_declarator LSQUARE constant_expression RSQUARE { $$ = $1; $$->inc_array_size($3); }
                  | direct_declarator LSQUARE RSQUARE                     { $$ = $1; $$->inc_array_size(NULL); }
                  ;

// Pointer
pointer : MULT                    { $$=1; }
        | pointer MULT            { $$=$1; $$++; }
        ;

/* ---------------------------------------------- RHS OF INITIALIZATION -------------------------------------------- */

// RHS of variable initialization
initializer // Expression value for a variable              
            : expression                                            { $$ = $1;}
            // 1D or final reduction for multidimensional array
            | LCURLY initializer_list RCURLY                        { $$ = $2; }
            // Indicates single dimension of a multidimensional array
            | LCURLY initializer_list COMMA RCURLY                  { $$ = new ArrayExpression($2, source_line, source_file); }
            ;

// List for array elements initialization
initializer_list  : initializer                                     { $$ = new ArrayExpression($1, source_line, source_file);}
                  // Indicates either more than 1 dimension or a list for 1 dimension
                  | initializer_list COMMA initializer              { $$ = $1; $$->push_back_mem($3);}
                  ;


/* ===================================================================================================================== */

/* ================================================== 3.3 EXPRESSIONS ================================================== */

/* ===================================================================================================================== */


/* ---------------------------------------------- 3.3.1 PRIMARY EXPRESSIONS -------------------------------------------- */

// Basic structure: Level 0 Precedence; corressponds to factor
primary_expression  // Identifier
                    : IDENTIFIER                            { $$ = new VarExpr($1, source_line, source_file);}
                    // Constant
                    | CONSTANT                              { $$ = $1;}
                    // string_literal
                    | STRING_LITERAL
                    // Reduction to bracketed expression
                    | LBRACKET expression RBRACKET          { $$ = $2; }
                    ;

/* ---------------------------------------------- 3.3.2 POSTFIX OPERATORS -------------------------------------------- */

/* C-grammar uses: 
                    | postfix_expression LBRACKET argument_expression_list RBRACKET 
                    | postfix_expression LBRACKET RBRACKET                       
*/

// Level 1 Precedence
postfix_expression  // Reduction to Level 0 
                    : primary_expression                                        { $$ = $1; }
                    // Array access
                    | postfix_expression LSQUARE expression RSQUARE             
                              { BaseExpression* deref = new Expression($1, strdup("+"), $3, source_line, source_file);
                                                                $$ = new DereferenceExpression(deref, source_line, source_file); }
                    // Function call
                    | bracketed_identifier LBRACKET argument_expression_list RBRACKET 
                                                                                { $$ = new FnCall($1,$3,source_line,source_file); } 
                    // Function call with no arguments
                    | bracketed_identifier LBRACKET RBRACKET                    { $$ = new FnCall($1,NULL,source_line,source_file); }
                    // Structs and Unions member access
                    | postfix_expression DOT IDENTIFIER                                 //{ Expression* tmp = new VarExpr($3);
                                                                                        //  $$ = new Expression($1, $2, tmp);}
                    // Structs and Unions member access via pointers
                    | postfix_expression PTR_OP IDENTIFIER                              //{ Expression* tmp = new VarExpr($3);
                                                                                        //  $$ = new Expression($1, $2, tmp);}
                    // Post increment
                    | postfix_expression PLUS_PLUS          { $$ = new AssignmentExpression($1, $2, NULL, source_line, source_file);}
                    // Post decrement
                    | postfix_expression MINUS_MINUS        { $$ = new AssignmentExpression($1, $2, NULL, source_line, source_file);}
                    ;

// Note: Arguments to functions can be expressions. If so, the evaluation is executed
argument_expression_list  : expression                                  { $$ = new vector<BaseExpression*>; $$->push_back($1); }
                          | argument_expression_list COMMA expression   { $$->push_back($3); }
                          ;

bracketed_identifier  : IDENTIFIER                                  { $$ = $1; }
                      | LBRACKET bracketed_identifier RBRACKET      { $$ = $2; }
                      ;

/* ---------------------------------------------- 3.3.3 UNARY OPERATORS -------------------------------------------- */

// Level 2 Precedence
unary_expression  // Reduction to Level 1 
                  : postfix_expression                                                  { $$ = $1;}
                  // Pre increment
                  | PLUS_PLUS unary_expression           { $$ = new AssignmentExpression(NULL, $1, $2, source_line, source_file);}
                  // Pre decrement
                  | MINUS_MINUS unary_expression         { $$ = new AssignmentExpression(NULL, $1, $2, source_line, source_file);}
                  // Type cast, see UNARY_OPERATOR
                  | UNARY_OPERATOR cast_expression       { $$ = new Expression(NULL, $1, $2, source_line, source_file);}
                  // Pointer dereference
                  | MULT cast_expression                 { $$ = new DereferenceExpression($2, source_line, source_file);}
                  // Address-of
                  | BITWISE_AND cast_expression          { $$ = new AddressExpression($2, source_line, source_file);}
                  // Sizeof 
                  | SIZEOF unary_expression              { $$ = new Expression(NULL, $1, $2, source_line, source_file);}
                  // Sizeof type
                  //| SIZEOF LBRACKET type_name RBRACKET                   { $$ = new Expression(NULL, $1, $3);}
                  | SIZEOF LBRACKET INT RBRACKET         { $$ = new Constant<uint64_t>(sizeof(int), source_line, source_file);}
                  ;

UNARY_OPERATOR  // Positive 
                : PLUS                                { $$ = $1; }
                // Negative
                | MINUS                               { $$ = $1; }
                // Bitwise negation 
                | WAVE                                { $$ = $1; }
                // Logical Negation
                | EXL_MARK                            { $$ = $1; }
                ;

// Fix for non-INT data types
// Level 2 Precedence
cast_expression : unary_expression                               { $$ = $1; }
                | LBRACKET type_name RBRACKET cast_expression    { $$ = $4; }
                //| LBRACKET type_name RBRACKET cast_expression    { $$ = new Expression(NULL, $2, $4, source_line, source_file);}
                ;

/* ---------------------------------------------- 3.3.5 MULTIPLICATIVE OPERATORS -------------------------------------------- */

// Level 3 Precedence
multiplicative_expression // Reduction to Level 2 
                          : cast_expression                                             { $$ = $1;}                                  
                          // Multiplication
                          | multiplicative_expression MULT cast_expression    
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                          // Division
                          | multiplicative_expression DIV cast_expression     
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                          // Remainder
                          | multiplicative_expression PERCENT cast_expression 
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                          ;

/* ---------------------------------------------- 3.3.6 ADDITIVE OPERATORS -------------------------------------------- */

// Level 4 Precedence
additive_expression // Reduction to Level 3 
                    : multiplicative_expression                   { $$ = $1; }
                    // Addition
                    | additive_expression PLUS multiplicative_expression      
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                    // Subtraction
                    | additive_expression MINUS multiplicative_expression     
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                    ;

/* ---------------------------------------------- 3.3.7 BITWISE SHIFT OPERATORS -------------------------------------------- */

// Level 5 Precedence
shift_expression  // Reduction to Level 4
                  : additive_expression                           { $$ = $1;}
                  // Bitwise shift left
                  | shift_expression LSHIFT additive_expression   { $$ = new Expression($1, $2, $3, source_line, source_file);}
                  // Bitwise shift right
                  | shift_expression RSHIFT additive_expression   { $$ = new Expression($1, $2, $3, source_line, source_file);}
                  ;

/* ---------------------------------------------- 3.3.8 RELATIONAL OPERATORS -------------------------------------------- */

// Level 6 Precedence
relational_expression // Reduction to Level 5 
                      : shift_expression                          { $$ = $1; }
                      // More than comparison
                      | relational_expression LOGICAL_LESS shift_expression             
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                      // Less than comparison
                      | relational_expression LOGICAL_MORE shift_expression             
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                      // Less than or equal comparison
                      | relational_expression LESS_OR_EQUAL shift_expression            
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                      // More than or equal comparison
                      | relational_expression MORE_OR_EQUAL shift_expression            
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                      ;   

/* ---------------------------------------------- 3.3.9 EQUALITY OPERATORS -------------------------------------------- */

// Level 7 Precedence
equality_expression // Reduction to Level 6
                    : relational_expression                       { $$ = $1; }
                    // Logical equality comparison
                    | equality_expression LOGICAL_EQUALITY relational_expression        
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                    // Logical ineqality comparison
                    | equality_expression LOGICAL_INEQUALITY relational_expression      
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}          
                    ;

/* ---------------------------------------------- 3.3.10 BITWISE AND OPERATOR -------------------------------------------- */

// Level 8 Precedence
and_expression  // Reduction to Level 7
                : equality_expression                             { $$ = $1; } 
                // Bitwise AND operation between two arguments
                | and_expression BITWISE_AND equality_expression                        
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                ;

/* -------------------------------------------- 3.3.11 BITWISE EXCLUSIVE OR OPERATOR ------------------------------------------ */

// Level 9 Precedence
exclusive_or_expression // Reduction to Level 8
                        : and_expression                          { $$ = $1; }
                        // Bitwise XOR operation between two arguments
                        | exclusive_or_expression BITWISE_XOR and_expression            
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                        ;

/* -------------------------------------------- 3.3.12 BITWISE INCLUSIVE OR OPERATOR ------------------------------------------ */

// Level 10 Precedence
inclusive_or_expression // Reduction to Level 9
                        : exclusive_or_expression                 { $$ = $1; }
                        // Bitwise OR operation between two arguments
                        | inclusive_or_expression BITWISE_OR exclusive_or_expression    
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}         
                        ;

/* -------------------------------------------- 3.3.13 LOGICAL AND OPERATOR ------------------------------------------ */

// Level 11 Precedence
logical_and_expression  // Reduction to Level 10
                        : inclusive_or_expression                 { $$ = $1; }
                        // Logical AND expression
                        | logical_and_expression LOGICAL_AND inclusive_or_expression    
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                        ;

/* -------------------------------------------- 3.3.14 LOGICAL OR OPERATOR ------------------------------------------ */

// Level 12 Precedence
logical_or_expression // Reduction to Level 11
                      : logical_and_expression                    { $$ = $1; } 
                      // Logical OR expression
                      | logical_or_expression LOGICAL_OR logical_and_expression         
                                                                  { $$ = new Expression($1, $2, $3, source_line, source_file);}
                      ;

/* -------------------------------------------- 3.3.15 CONDITIONAL OPERATOR ------------------------------------------ */

// Level 13 Precedence
conditional_expression  // Reduction to Level 12
                        : logical_or_expression                   { $$ = $1; }
                        // Ternary conditional
                        | logical_or_expression Q_MARK expression COLON conditional_expression   
                                                        { $$ = new ConditionalExpression($1, $3, $5, source_line, source_file);}
                        ;

/* -------------------------------------------- 3.3.16 ASSIGNMENT OPERATOR ------------------------------------------ */

// Level 14 Precedence
assignment_expression // Reduction to Level 13
                      : conditional_expression                    { $$ = $1; }
                      // Assignment
                      | unary_expression ASSIGNMENT_OPERATOR assignment_expression  
                                                        { $$ = new AssignmentExpression($1, $2, $3, source_line, source_file);}
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

// Level 15 Precedence
expression_list // Reduction to Level 14
                : expression                                        { $$ = new vector<BaseExpression*>; $$->push_back($1);}                                    
                // List of expressions
                | expression_list COMMA expression                  { $$->push_back($3);}
                ;


/* ============================================== 3.4 CONSTANT EXPRESSIONS ============================================== */

// Used when a value needs to be initialized to a constant. Excludes only assignment expressions
constant_expression : conditional_expression ;            


/* ===================================================================================================================== */
                    
/* ============================================== BLOCK EXECUTION DECLARATIONS ============================================== */

/* ===================================================================================================================== */


/* -------------------------------------------- FUNCTION DECLARATIONS ------------------------------------------ */

 /* 
fn_return_type  : INT                                 { $$ = new Variable($1, NULL); }
                | INT pointer                         { $$ = new Variable($1, NULL); $$->inc_deref_lvl($2); }
                | VOID                                { $$ = new Variable($1, NULL); }
                ;
*/

fn_prototype  : INT IDENTIFIER LBRACKET fn_params_list RBRACKET SEMI_COLON          
                                                      { $$ = new Function(new Variable($1, NULL), $2, $4, NULL); }
              | VOID IDENTIFIER LBRACKET fn_params_list RBRACKET SEMI_COLON          
                                                      { $$ = new Function(new Variable($1, NULL), $2, $4, NULL); }
              | INT pointer IDENTIFIER LBRACKET fn_params_list RBRACKET SEMI_COLON          
                                                      { $$ = new Function(new Variable($1, NULL), $3, $5, NULL); }
              ;

// NOTE: You cannot have an array as return type
// You need to modify the grammar for return type and Variable* to be returned from the reduction of the rule
fn_declaration  : INT IDENTIFIER LBRACKET fn_params_list RBRACKET compound_statement          
                                                      { $$ = new Function(new Variable($1, NULL), $2, $4, $6); }
                | VOID IDENTIFIER LBRACKET fn_params_list RBRACKET compound_statement          
                                                      { $$ = new Function(new Variable($1, NULL), $2, $4, $6); }
                | INT pointer IDENTIFIER LBRACKET fn_params_list RBRACKET compound_statement          
                                                      { $$ = new Function(new Variable($1, NULL), $3, $5, $7); }

                ;

fn_params_list  : INT declarator                         { $$ = new vector<Variable*>; $2->set_type_name($1); $$->push_back($2);}
                | fn_params_list COMMA INT declarator             { $4->set_type_name($3); $$->push_back($4);}
                |                                                 { $$ = NULL; }
                ;   

/* -------------------------------------------- LOOP STATEMENTS ------------------------------------------ */

loop  : for_loop                                                  { $$=$1; }
      | while_loop                                                { $$=$1; }
      | do_while_loop                                             { $$=$1; }
      ;

// Memory leak expression_list
do_while_loop : DO compound_statement WHILE LBRACKET expression_list RBRACKET SEMI_COLON
                { int last = $5->size()-1; $$ = new WhileLoop(((*($5))[last]), $2, ST_dowhile_loop); } 
              | DO statement WHILE LBRACKET expression_list RBRACKET SEMI_COLON     
                { int last = $5->size()-1; $$ = new WhileLoop(((*($5))[last]), $2, ST_dowhile_loop); }
              ;

for_loop  : FOR LBRACKET for_loop_decl_statement RBRACKET compound_statement     { $$ = new ForLoop($3, $5); }
          | FOR LBRACKET for_loop_decl_statement RBRACKET statement              { $$ = new ForLoop($3, $5); }
          ;

for_loop_decl_statement : expression_list SEMI_COLON expression_list SEMI_COLON expression_list { $$ = new ForLoopTuple($1, $3, $5); }
                        | expression_list SEMI_COLON expression_list SEMI_COLON               { $$ = new ForLoopTuple($1, $3, NULL); }
                        | expression_list SEMI_COLON SEMI_COLON expression_list               { $$ = new ForLoopTuple($1, NULL, $4); }
                        | SEMI_COLON expression_list SEMI_COLON expression_list               { $$ = new ForLoopTuple(NULL, $2, $4); }
                        | expression_list SEMI_COLON SEMI_COLON                             { $$ = new ForLoopTuple($1, NULL, NULL); }
                        | SEMI_COLON SEMI_COLON expression_list                             { $$ = new ForLoopTuple(NULL, NULL, $3); }
                        | SEMI_COLON expression_list SEMI_COLON                             { $$ = new ForLoopTuple(NULL, $2, NULL); }
                        | SEMI_COLON SEMI_COLON                                           { $$ = new ForLoopTuple(NULL, NULL, NULL); }
                        ;

// Memory leak expression_list
while_loop  : WHILE LBRACKET expression_list RBRACKET compound_statement              
            { int last = $3->size()-1; $$ = new WhileLoop(((*($3))[last]), $5, ST_while_loop); }
            | WHILE LBRACKET expression_list RBRACKET statement 
            { int last = $3->size()-1; $$ = new WhileLoop(((*($3))[last]), $5, ST_while_loop); }
            ;

/* -------------------------------------------- CONDITIONAL STATEMENTS ------------------------------------------ */

/* --------------------------------------------- 3.6.4 SELECTION STATEMENTS ------------------------------------------- */

/*SELECTION_STATEMENT : IF LBRACKET EXPRESSION RBRACKET STATEMENT
                    | IF LBRACKET EXPRESSION RBRACKET STATEMENT ELSE STATEMENT
                    | SWITCH LBRACKET EXPRESSION RBRACKET STATEMENT
                    ;

LABELED_STATEMENT : IDENTIFIER COLON STATEMENT
                  | CASE CONSTANT_EXPRESSION COLON STATEMENT
                  | DEFAULT COLON STATEMENT
                  ;
*/


if_block_statement  : if_statement                            { $$ = new Conditional($1); }
                    | if_statement else_statement_list        { $$ = new Conditional(vec_append($1,$2)); }
                    ;

else_statement_list : else_statement                          { $$ = $1; }
                    | else_statement_list else_statement      { $$ = vec_append($1, $2); }
                    ;

// Memory leak for expression_list
if_statement  : IF LBRACKET expression_list RBRACKET compound_statement               
                { $$ = new vector<ConditionalCase*>; int last = $3->size()-1;
                  $$->push_back(new ConditionalCase($5,((*($3))[last]), source_line, source_file)); }
              | IF LBRACKET expression_list RBRACKET statement
                { $$ = new vector<ConditionalCase*>; int last = $3->size()-1;
                  $$->push_back(new ConditionalCase($5,((*($3))[last]), source_line, source_file)); }
              ;

else_statement  : ELSE compound_statement     
                  { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2, NULL, source_line, source_file)); }
                | ELSE statement              
                  { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2, NULL, source_line, source_file)); }
                ;

/* ===================================================================================================================== */
       
/* ============================================== 3.6 STATEMENTS ============================================== */

/* ===================================================================================================================== */


/* ---------------------------------------------- 3.6.2 COMPOUND STATEMENTS -------------------------------------------- */

// A {} block of code - e.g. body of a function, body of a loop, or body of a an if statement
compound_statement  : LCURLY declaration_list statement_list RCURLY   { $$=new CompoundStatement($2, $3);}
                    | LCURLY statement_list RCURLY                    { $$=new CompoundStatement(NULL,$2);}
                    | LCURLY declaration_list RCURLY                  { $$=new CompoundStatement($2,NULL);}
                    | LCURLY RCURLY                                   { $$=NULL; }
                    ;

// Simply a list of declarations. Note this implies one or more occurences of INT keyword
declaration_list  : declaration                                     { $$ = new vector<VarDeclaration*>; $$->push_back($1);}
                  | declaration_list declaration                    { $$->push_back($2);}
                  ;

statement_list  : statement                                         { $$ = new vector<Statement*>; $$->push_back($1);}
                | statement_list statement                          { $$->push_back($2);}
                ;

statement : loop                                                    { $$=$1; }
          | if_block_statement                                      { $$=$1; }
          | expression_statement                                    { $$=$1; }
          | semi_colon_statement                                    { $$=$1; }
          | compound_statement                                      { $$=$1; }
          ;


/* ---------------------------------------------- EXPRESSION STATEMENT -------------------------------------------- */
expression_statement  : expression_list SEMI_COLON                  { $$ = new ExpressionStatement($1);}
                      ;

/* ---------------------------------------------- SEMI COLON STATEMENTS -------------------------------------------- */
semi_colon_statement  : return_statement                            { $$=$1;}
                      | SEMI_COLON                                  { $$=NULL;}
                      ;

/* --------------------------------------------- 3.6.6 JUMP STATEMENTS ------------------------------------------- */
/*JUMP_STATEMENT  : GOTO IDENTIFIER SEMI_COLON
                | CONTINUE SEMI_COLON
                | BREAK SEMI_COLON
                | RETURN EXPRESSION SEMI_COLON
                | RETURN SEMI_COLON
                ;
*/
return_statement  : RETURN expression SEMI_COLON                    { $$ = new ReturnStatement($2, source_line, source_file);}
                  | RETURN SEMI_COLON                               { $$ = new ReturnStatement(NULL, source_line, source_file);}
                  ;


/* ============================================== END RULES ============================================== */

%%  

int yyerror(const char* s){ 
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
  std::cerr <<"File: "<< source_file<<", Line: "<<input_file_line << std::endl;
  cerr<<"========================================= Parser ERROR ========================================="<<endl;
  return -1;
}



