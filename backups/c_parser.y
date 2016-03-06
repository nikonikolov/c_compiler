%code requires{
  #include <iostream>
  #include <string>  
  #include "helper.hpp"
  #include "DataStructures/Function.h"
  #include "DataStructures/Loop.h"
  #include "DataStructures/Variable.h"
  #include "DataStructures/Constant.h"
  #include "DataStructures/Conditional.h"
  #include "DataStructures/VarDeclaration.h"
  #include "DataStructures/Expression.h"
  #include "DataStructures/ExpressionStatement.h"
  
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

  Variable* var_ptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable*>*        vector_vars_ptrs_ptr;
  vector<Statement*>*       vector_statement_pointers_ptr;
  vector<Expression*>*      vector_expr_pointers_ptr;
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

%token <intval>   INTEGER_CONST 
%token <floatval> FLOATING_CONST
%token <strval>   CHAR_CONST      // Probably needs changing

/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token <strval> IDENTIFIER STRING_LITERAL


/* --------------------------------------------------------------------------------------------------------------------- */

/* --------------------------------------------------- NON TERMINALS --------------------------------------------------- */

/* --------------------------------------------------------------------------------------------------------------------- */

/* ---------------------------------------------- DECALRATION TYPES -------------------------------------------- */

%type <vector_vars_ptrs_ptr> fn_params_list initialization_list init_declarator_list

%type <var_ptr> init_declarator direct_declarator declarator
%type <expr_ptr> initializer

/* ---------------------------------------------- STATEMENT TYPES -------------------------------------------- */

%type <strval> bracketed_identifier

%type <statement_ptr> loop for_loop while_loop do_while_loop if_block_statement fn_declaration declaration statement 

%type <vector_statement_pointers_ptr> compound_statement declaration_list statement_list

%type <vector_statement_pointers_ptr> program

%type <vector_conditional_case_pointers_ptr> if_statement else_statement else_statement_list

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

/*  NOTES ON ARCHITECTURE:
    1. GRAMMAR: Terminals are upper case while non-terminals are lower-case
      NB: To have a correct grammar, whenever you use recursion you should have a terminating rule, i.e. an alternative rule
      from the recursion path
    2. RECURSION: You should always use left recursion, otherwise you can blow the stack. Left recursion looks like:
        expseq1 : exp
                | expseq1 ',' exp
                ;
    3. Managing constants:
      The lexer converts the constant to a uint64_t representation and passes that value to the parser. The parser saves the value 
      in a Variable or Constant object and casts it to the required type. NOTE: you are compiling for MIPS 32 bit so every 32 bit 
      constant can be cast to unsigned 64 bit constant without losing any information, even long and negative 
*/




/* ============================================== PROGRAM START ELEMENTS ============================================== */


program : fn_declaration                                   { root = new vector<Statement*>; root->push_back($1);}
        | declaration                                      { root = new vector<Statement*>; root->push_back($1);}
        | program fn_declaration                           { root->push_back($2); }
        | program declaration                              { root->push_back($2); }
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

/* ===================================================================================================================== */

/* ============================================== 3.5 DECLARATIONS ============================================== */

/* ===================================================================================================================== */

// Declaration of a variable
declaration : declaration_type init_declarator_list SEMI_COLON              { $$ = new VarDeclaration('int', $2); }
            // Allowed but not sensible. Simply ignore
            | declaration_type SEMI_COLON   { cerr<<"Useless definition in file "<<source_file<<", Line: "<<input_file_line<<endl;}
            ;

// Any combination of type specifier(int, struct, etc), storage specifier(register, auto, etc) and type qualifier (const, volatile)
declaration_type  : TYPE_SPECIFIER
                  | TYPE_SPECIFIER declaration_type
                  // Can try making constants work at some point
                  //| TYPE_QUALIFIER
                  //| TYPE_QUALIFIER declaration_type
                  // Can try making typedefs, externs and statics work at some point
                  //| STORAGE_SPECIFIER 
                  //| STORAGE_SPECIFIER declaration_type
                  ;

// Initialization list (List of variable declarations)
init_declarator_list  : init_declarator
                      | init_declarator_list COMMA init_declarator 
                      ;
                      
// Variable name and initialization/value (if provided) at declaration
init_declarator   : declarator                                      { $$ = $1;}
                  | declarator EQUALS initializer                   { $$ = $1; $$->set_init_val($3);}
                  ;

/* ---------------------------------------------- LHS OF INITIALIZATION -------------------------------------------- */

// LHS of variable initialization
declarator  : direct_declarator                                     { $$ = $1; }
            //| pointer direct_declarator
            ;

// NB make a separate grammmar for function declarations and prototypes - they are definitely not the same as variables
// Variable name, Array cell or function
direct_declarator : IDENTIFIER                                      { $$ = new Variable($1, ST_var_declaration); }
                  | LBRACKET declarator RBRACKET                    { $$ = $1; }
                  // Array cell
                  | direct_declarator LSQUARE constant_expression RSQUARE     { $$= $1; $$->dereference_back($3); }
                  | direct_declarator LSQUARE RSQUARE               { $$= $1; $$->dereference_back(new Constant<int>(0));}
                  // Function declaration: name and arguments
                  //| direct_declarator LBRACKET parameter_type_list RBRACKET
                  //| direct_declarator LBRACKET identifier_list RBRACKET
                  //| direct_declarator LBRACKET RBRACKET
                  ;

/* ---------------------------------------------- RHS OF INITIALIZATION -------------------------------------------- */

// RHS of variable initialization
initializer // Expression value for a variable              
            : assignment_expression                                     { $$= $1;}
            // 1D array initialization
            | LCURLY initializer_list RCURLY
            // 2D array initialization
            | LCURLY initializer_list COMMA RCURLY
            ;

// List for array elements initialization
initializer_list  : initializer
                  | initializer_list COMMA initializer
                  ;

/* -------------------------------------------- VARIABLE DECLARATIONS ------------------------------------------ */
/* You need to define declaration here so that compound statement works. For the final version add other types as well 
    e.g. double, float, char, arrays, pointers, function pointers. You should also try to make structs work. Remember that
    arrays can be defined at initialization. You can try long and const as well. Question - can you cast variables on declaration? */

// Currently only INTs covered
declaration   : INT initialization_list SEMI_COLON                              { $$ = new VarDeclaration(int_type, $2);}
              ;

// arrays and pointers not currently accounted for
initialization_list : bracketed_identifier                              { $$ = new vector<Variable>; $$->push_back(Variable($1));}
                    | assignment_expression                             { $$ = new vector<Variable>; $$->push_back(Variable($1));}
                    | initialization_list COMMA assignment_expression   { $$->push_back(Variable($3));}
                    | initialization_list COMMA bracketed_identifier    { $$->push_back(Variable($3));}
                    ;





assignment_expression_list  : assignment_expression              
                            | assignment_expression_list COMMA assignment_expression        
                            ;

// Repair
type_name : INT                                       { $$ = $1; }
          | DOUBLE                                    { $$ = $1; }
          | CHAR                                      { $$ = $1; }
          ;


/* ===================================================================================================================== */

/* ============================================== 3.3 EXPRESSIONS ============================================== */

/* ===================================================================================================================== */


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


/* ============================================== 3.4 CONSTANT EXPRESSIONS ============================================== */

// NB: Although not yet needed, this might be very very useful for structs and enums. Check the C grammar
//CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION ;            



/* ===================================================================================================================== */
                    
/* ============================================== BLOCK EXECUTION DECLARATIONS ============================================== */

/* ===================================================================================================================== */


/* -------------------------------------------- FUNCTION DECLARATIONS ------------------------------------------ */

/* For both fn_params_list and fn_declaration: include other types than int: void, double, char, structs, pointers, etc.
  Try to make function pointers work. Try const, long, etc.. Actually in the end you should have one rule that defines 
  a variable and change only that one */

// You need to modify the grammar for return type and Variable* to be returned from the reduction of the rule
fn_declaration  : INT IDENTIFIER LBRACKET fn_params_list RBRACKET compound_statement          
                                                      { $$ = new Function(new Variable('int', ST_var_return), $2, $4, $6); }
                ;

fn_params_list  : INT bracketed_identifier                      { $$ = new vector<Variable*>; 
                                                                  $$->push_back(new Variable('int', $2, ST_var_fn_param));}

                | fn_params_list COMMA INT bracketed_identifier { $$->push_back(new Variable('int', $4, ST_var_fn_param)); }
                |                                               { $$ = NULL; }
                ;   

// Get rid of this at the end. You most probably need declarator, still you might have arrays passed on to functions
bracketed_identifier  : IDENTIFIER                                  { $$ = $1; }
                      | LBRACKET bracketed_identifier RBRACKET      { $$ = $2; }
                      ;

/* -------------------------------------------- LOOP STATEMENTS ------------------------------------------ */

// Add do while for final version
loop  : for_loop                                                  { $$=$1; }
      | while_loop                                                { $$=$1; }
      | do_while_loop                                             { $$=$1; }
      ;

do_while_loop : DO compound_statement WHILE LBRACKET expression_list RBRACKET SEMI_COLON;
              | DO statement WHILE LBRACKET expression_list RBRACKET SEMI_COLON;
              ;

for_loop  : FOR LBRACKET for_loop_decl_statement RBRACKET compound_statement     { $$ = new Loop($5); }
          | FOR LBRACKET for_loop_decl_statement RBRACKET statement              { $$ = new Loop($5); }
          ;

// NB: to prevent memory leaks, at this stage you need to delete the structures returned in the following conditions
// Fix memory management. Some pointer does not get deleted
/*for_loop_decl_statement : assignment_expression_list SEMI_COLON equality_expression SEMI_COLON assignment_expression_list 
                              { delete $1; delete $5; }
                        | assignment_expression_list SEMI_COLON equality_expression SEMI_COLON
                              { delete $1; }
                        | assignment_expression_list SEMI_COLON SEMI_COLON assignment_expression_list
                              { delete $1; delete $4; }
                        | SEMI_COLON equality_expression SEMI_COLON assignment_expression_list
                              { delete $4; }
                        | assignment_expression_list SEMI_COLON SEMI_COLON
                              { delete $1; }
                        | SEMI_COLON SEMI_COLON assignment_expression_list
                              { delete $3; }
                        | SEMI_COLON equality_expression SEMI_COLON
                        | SEMI_COLON SEMI_COLON
                        ;
*/
for_loop_decl_statement : expression_list SEMI_COLON expression_list SEMI_COLON expression_list 
                        | expression_list SEMI_COLON expression_list SEMI_COLON
                        | expression_list SEMI_COLON SEMI_COLON expression_list
                        | SEMI_COLON expression_list SEMI_COLON expression_list
                        | expression_list SEMI_COLON SEMI_COLON
                        | SEMI_COLON SEMI_COLON expression_list
                        | SEMI_COLON expression_list SEMI_COLON
                        | SEMI_COLON SEMI_COLON
                        ;

while_loop  : WHILE LBRACKET expression_list RBRACKET compound_statement                { $$ = new Loop($5); }
            | WHILE LBRACKET expression_list RBRACKET statement                         { $$ = new Loop($5); }
            ;

/* -------------------------------------------- CONDITIONAL STATEMENTS ------------------------------------------ */
/* --------------------------------------------- 3.6.4 SELECTION STATEMENTS ------------------------------------------- */

/*SELECTION_STATEMENT : IF LBRACKET EXPRESSION RBRACKET STATEMENT
                    | IF LBRACKET EXPRESSION RBRACKET STATEMENT ELSE STATEMENT
                    | SWITCH LBRACKET EXPRESSION RBRACKET STATEMENT
                    ;
/* ---------------------------------------------- 3.6.1 LABELED STATEMENTS -------------------------------------------- */
/*
LABELED_STATEMENT : IDENTIFIER COLON STATEMENT
                  | CASE CONSTANT_EXPRESSION COLON STATEMENT
                  | DEFAULT COLON STATEMENT
                  ;
*/

/* Be very careful - this can be function call, comparison, number or even assignment - maybe you can put it as a statement
equality_expression : LBRACKET equality_expression
*/

// arithmetic expressions etc
if_block_statement  : if_statement                            { $$ = new Conditional($1); }
                    | if_statement else_statement_list        { $$ = new Conditional(vec_append($1,$2)); }
                    ;

else_statement_list : else_statement                          { $$ = $1; }
                    | else_statement_list else_statement      { $$ = vec_append($1, $2); }
                    ;

if_statement  : IF LBRACKET equality_expression RBRACKET compound_statement               
                                              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($5)); }
              | IF LBRACKET equality_expression RBRACKET statement
                                              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($5)); }
              ;

/*
// if_statement can be reduced to a statement so basically the first rule is useless
else_statement  : ELSE if_statement           { $$ = $2; }
                | ELSE compound_statement     { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                | ELSE statement              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                ;
*/


else_statement  : ELSE compound_statement     { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                | ELSE statement              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                ;


/* ===================================================================================================================== */
       
/* ============================================== 3.6 STATEMENTS ============================================== */

/* ===================================================================================================================== */


/* ---------------------------------------------- 3.6.2 COMPOUND STATEMENTS -------------------------------------------- */

// This represents a block of code - e.g. body of a function, body of a loop, or body of a an if statement
compound_statement  : LCURLY declaration_list statement_list RCURLY   { $$=vec_append($2, $3); }
                    | LCURLY statement_list RCURLY                    { $$=$2; }
                    | LCURLY declaration_list RCURLY                  { $$=$2; }
                    | LCURLY RCURLY                                   { $$=NULL; }
                    ;

// Simply a list of declarations. Note this implies one or more occurences of INT keyword
declaration_list  : declaration                                     { $$ = new vector<Statement*>; $$->push_back($1);}
                  | declaration_list declaration                    { $$->push_back($2);}
                  ;

statement_list  : statement                                         { $$ = new vector<Statement*>; $$->push_back($1);}
                | statement_list statement                          { $$->push_back($2);}
                ;

// For the purposes of the milestone restricted to for, while, if statements and arithmetic expressions
// Add return statements as well
statement : loop                                                    { $$=$1; }
          | if_block_statement                                      { $$=$1; }
          | expression_statement                                    { $$=$1; }
          | semi_colon_statement                                    { $$=NULL; }
          ;


/* ---------------------------------------------- EXPRESSION STATEMENT -------------------------------------------- */
expression_statement  : expression_list SEMI_COLON                  { $$ = $1;}
                      ;

/* ---------------------------------------------- SEMI COLON STATEMENTS -------------------------------------------- */
semi_colon_statement  : return_statement
                      | SEMI_COLON
                      ;

/* --------------------------------------------- 3.6.6 JUMP STATEMENTS ------------------------------------------- */
/*JUMP_STATEMENT  : GOTO IDENTIFIER SEMI_COLON
                | CONTINUE SEMI_COLON
                | BREAK SEMI_COLON
                | RETURN EXPRESSION SEMI_COLON
                | RETURN SEMI_COLON
                ;
*/
return_statement  : RETURN equality_expression SEMI_COLON
                  | RETURN SEMI_COLON
                  ;


/* ============================================== END RULES ============================================== */

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
    if(*it!=NULL) (*it)->pretty_print(0);
  }

  cerr<<"========================================= Printing successful ========================================="<<endl;

  return 0;
}




