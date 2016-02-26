%code requires{
  #include <iostream>
  #include <string>  
  #include "helper.hpp"
  #include "DataStructures/Function.h"
  #include "DataStructures/Loop.h"
  #include "DataStructures/Variable.h"
  #include "DataStructures/Conditional.h"
  #include "DataStructures/VarDeclaration.h"
  
  using namespace std;

  //! This is to fix problems when generating C++
  int yylex();
  int yyerror(const char* s);

  //extern Function* root;
  
}

%union{
  char* strval;
  int intval;
  Variable* varptr;
  list<Variable>* list_var_ptr=NULL;
  
  vector<Variable>* vector_var_ptr;
  vector<Statement*>* vector_statement_pointers_ptr;
  
  vector<ConditionalCase*>* vector_conditional_case_pointers_ptr;
  
  Function* fn_ptr;
  Statement* statement_ptr;
}

/* --------------------------------------------------- TOKENS KEYWORDS --------------------------------------------------- */

%token <strval> AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT 
%token <strval> UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE

/* --------------------------------------------------- TOKENS OPERATORS --------------------------------------------------- */

%token <strval> LSQUARE RSQUARE LBRACKET RBRACKET LCURLY RCURLY THREE_DOTS DOT PTR_OP PLUS_PLUS MINUS_MINUS SIZEOF LSHIFT RSHIFT 
%token <strval> LESS_OR_EQUAL MORE_OR_EQUAL LOGICAL_EQUALITY LOGICAL_INEQUALITY LOGICAL_AND LOGICAL_OR Q_MARK COLON MULT_EQUALS 
%token <strval> DIV_EQUALS PERCENT_EQUALS PLUS_EQUALS MINUS_EQUALS LSHIFT_EQUALS RSHIFT_EQUALS AND_EQUALS XOR_EQUALS OR_EQUALS 
%token <strval> COMMA HASH HASH_HASH SEMI_COLON EQUALS BITWISE_OR BITWISE_AND MULT PLUS MINUS WAVE EXL_MARK DIV PERCENT LOGICAL_LESS 
%token <strval> LOGICAL_MORE BITWISE_XOR

/* --------------------------------------------------- TOKENS CONSTANTS --------------------------------------------------- */

%token <strval> FLOATING_CONST INTEGER_CONST CHAR_CONST

/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token <strval> IDENTIFIER STRING_LITERAL PREPROCESSOR_INCLUDE EOLINE

/* **** Only types that you use in the C++ code need to be defined **** */
%type <vector_var_ptr> fn_params_list initialization_list

// NOTE: assignment_expression_list and assignment_expression are defined like that only for the purposes of the MILESTONE. 
// Need to think of a better solution for the final version. You will probably need some special class that can be both 
// a variable and a statement. Probably variable can inherit Statement. Or you make a new class called expression. It can be
// useful when dealing with arithmetic expressions. Variable can inherit from it, as a Variable is practically an expression 
// Expressions and Statements need to be related somehow. You can make Expression inferit from Statement
%type <vector_var_ptr> assignment_expression_list
%type <strval> assignment_expression

%type <strval> bracketed_identifier

//%type <fn_ptr> fn_declaration

%type <statement_ptr> loop for_loop while_loop if_block_statement fn_declaration declaration statement 

%type <vector_statement_pointers_ptr> compound_statement declaration_list statement_list

%type <vector_statement_pointers_ptr> program

%type <vector_conditional_case_pointers_ptr> if_statement else_statement else_statement_list


/* ---------------------------------------------- FOR DEBUGGING PURPOSES -------------------------------------------- */

/* Generate the parser description file.  */
%verbose
/* Enable run-time traces (yydebug).  */
%define parse.trace

/* Formatting semantic values.  */
//%printer { fprintf (yyoutput, "%s", $$.strval); } <char*>;
%printer { cerr<<$$.strval; } <char*>;
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

/*  THINGS NOT TO FORGET:
      1. Multiple brackets around expressions 
      2. Types can be pointers as well
      3. You can often have casting, assignment, or increment
*/

/*  THINGS TO NOTE:
    1. GRAMMAR: Terminals are upper case while non-terminals are lower-case
      NB: To have a correct grammar, whenever you use recursion you should have a terminating rule, i.e. an alternative rule
      from the recursion path
    2. RECURSION: You should always use left recursion, otherwise you can blow the stack. Left recursion looks like:
        expseq1 : exp
                | expseq1 ',' exp
                ;

*/


program : fn_declaration                                   { root = new vector<Statement*>; root->push_back($1);}
        | declaration                                      { root = new vector<Statement*>; root->push_back($1);}
        | PREPROCESSOR_INCLUDE                             { }
        | program fn_declaration                           { root->push_back($2); }
        | program declaration                              { root->push_back($2); }
        | program PREPROCESSOR_INCLUDE                     { }
        ;
        

/* ============================================== 3.1 LEXICAL ELEMENTS ============================================== */

/* ---------------------------------------------- 3.1.3 CONSTANTS -------------------------------------------- */

// Ready
// Final version should include ENUMERATION_CONSTANT
//CONSTANT : FLOATING_CONST | INTEGER_CONST | ENUMERATION_CONSTANT | CHAR_CONST ;

//CONSTANT : FLOATING_CONST | INTEGER_CONST | CHAR_CONST ;



/* -------------------------------------------- 3.5.2.2. ENUMERATION SPECIFIERS ------------------------------------------ */

//ENUMERATION_CONSTANT : IDENTIFIER ; 


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


bracketed_identifier  : IDENTIFIER                                  { $$ = $1; }
                      | LBRACKET bracketed_identifier RBRACKET      { $$ = $2; }
                      ;


/* 
  NOTE this is different from assignment_expression as it combines the expressions in a list and therefore makes
  sure they can only appear in a declaration statement. In terms of loops, you can simply ignore the list and destroy it
*/
// needs fixing
assignment_expression_list  : assignment_expression              { $$ = new vector<Variable>; $$->push_back(Variable($1));}
                            | assignment_expression_list COMMA assignment_expression        { $$->push_back(Variable($3));}
                            ;


/* ============================================== EXPRESSIONS ============================================== */

/* ---------------------------------------------- 3.3.9 EQUALITY OPERATORS -------------------------------------------- */
/* Essentially a comparison for an if condition*/

/*
equality_expression : relational_expression
                    | equality_expression LOGICAL_EQUALITY relational_expression
                    | equality_expression LOGICAL_INEQUALITY relational_expression                
                    ;
*/
// needs fixing
// This can also be a bracketed_identifier only
logical_condition   : bracketed_identifier COMPARISON_OPERATOR bracketed_identifier
                    ; 

// Probably needs fixing
COMPARISON_OPERATOR : LOGICAL_EQUALITY
                    | LOGICAL_INEQUALITY
                    | LOGICAL_AND
                    | LOGICAL_OR
                    | LOGICAL_MORE
                    | LOGICAL_LESS
                    | LESS_OR_EQUAL
                    | MORE_OR_EQUAL
                    ;
/* -------------------------------------------- 3.3.16 ASSIGNMENT OPERATOR ------------------------------------------ */

/* This is the version you are going for for the MILESTONE
assignment_expression : conditional_expression  /* e.g. the if statement with question mark */
/*                      | bracketed_identifier ASSIGNMENT_OPERATOR arithmetic_expression
                      ;
*/

assignment_expression   : bracketed_identifier ASSIGNMENT_OPERATOR bracketed_identifier { $$=$1; }
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

/* ============================================== BLOCK EXECUTION DECLARATIONS ============================================== */


/* -------------------------------------------- FUNCTION DECLARATIONS ------------------------------------------ */

// NB: ACCOUNT FOR RETURNS IN A FUNCTION !!!

/* For both fn_params_list and fn_declaration: include other types than int: void, double, char, structs, pointers, etc.
  Try to make function pointers work. Try const, long, etc.. Actually in the end you should have one rule that defines 
  a variable and change only that one */

fn_declaration  : INT IDENTIFIER LBRACKET fn_params_list RBRACKET compound_statement          
                                                                { $$ = new Function(int_type, $2, $4, $6); }
                ;

fn_params_list  : INT bracketed_identifier                      { $$ = new vector<Variable>; $$->push_back(Variable(int_type, $2));}
                | fn_params_list COMMA INT bracketed_identifier { $$->push_back(Variable(int_type, $4)); }
                |                                               { $$ = NULL; }
                ;   


/* -------------------------------------------- LOOP DECLARATIONS ------------------------------------------ */

// Add do while for final version
loop  : for_loop                                                  { $$=$1; }
      | while_loop                                                { $$=$1; }
      ;

for_loop  : FOR LBRACKET for_loop_decl_statement RBRACKET compound_statement                { $$ = new Loop($5); }
          | FOR LBRACKET for_loop_decl_statement RBRACKET statement SEMI_COLON              { $$ = new Loop($5); }
          ;

// NB: to prevent memory leaks, at this stage you need to delete the structures returned in the following conditions
// undefined: logical_condition, var_declaration, update_statement(this can be assignment expression)          
for_loop_decl_statement : assignment_expression_list SEMI_COLON logical_condition SEMI_COLON assignment_expression_list 
                              { delete $1; delete $5; }
                        | assignment_expression_list SEMI_COLON logical_condition SEMI_COLON
                              { delete $1; }
                        | assignment_expression_list SEMI_COLON SEMI_COLON assignment_expression_list
                              { delete $1; delete $4; }
                        | SEMI_COLON logical_condition SEMI_COLON assignment_expression_list
                              { delete $4; }
                        | assignment_expression_list SEMI_COLON SEMI_COLON
                              { delete $1; }
                        | SEMI_COLON SEMI_COLON assignment_expression_list
                              { delete $3; }
                        | SEMI_COLON logical_condition SEMI_COLON
                        | SEMI_COLON SEMI_COLON
                        ;

while_loop  : WHILE LBRACKET logical_condition RBRACKET compound_statement                { $$ = new Loop($5); }
            | WHILE LBRACKET logical_condition RBRACKET statement SEMI_COLON              { $$ = new Loop($5); }
            ;

/* -------------------------------------------- CONDITIONAL STATEMENTS ------------------------------------------ */
/* Similar to SELECTION STATEMENT 3.6.4 in the c grammar. You need to add switch statements later */

/* Be very careful - this can be function call, comparison, number or even assignment - maybe you can put it as a statement
logical_condition : LBRACKET logical_condition
*/

// arithmetic expressions etc
if_block_statement  : if_statement                            { $$ = new Conditional($1); }
                    | if_statement else_statement_list        { $$ = new Conditional(vec_append($1,$2)); }
                    ;

else_statement_list : else_statement                          { $$ = $1; }
                    | else_statement_list else_statement      { $$ = vec_append($1, $2); }
                    ;

// undefined: logical_condition
if_statement  : IF LBRACKET logical_condition RBRACKET compound_statement               
                                              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($5)); }
              | IF LBRACKET logical_condition RBRACKET statement SEMI_COLON
                                              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($5)); }
              ;

else_statement  : ELSE if_statement           { $$ = $2; }
                | ELSE compound_statement     { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                | ELSE statement              { $$ = new vector<ConditionalCase*>; $$->push_back(new ConditionalCase($2)); }
                ;

       
/* ============================================== 3.6 STATEMENTS ============================================== */


/* ---------------------------------------------- 3.6.2 COMPOUND STATEMENTS -------------------------------------------- */

// This represents a block of code - e.g. body of a function, body of a loop, or body of a an if statement
compound_statement  : LCURLY declaration_list statement_list RCURLY   { $$=vec_append($2, $3); }
                    | LCURLY statement_list RCURLY                    { $$=$2; }
                    | LCURLY declaration_list RCURLY                  { $$=$2; }
                    | LCURLY RCURLY                                   { $$=NULL; }
                    ;

// undefined - declaration
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
          | assignment_expression                                   { $$=NULL; }
          | SEMI_COLON                                              { $$=NULL; }
          ;


/* ============================================== EXPRESSIONS ============================================== */


%%  

int yyerror(const char* s){ 
    std::cerr <<"************ Parser error in file: "<< source_file<<" at line: "<<input_file_line << std::endl;
    return -1;
}

int main(){

  yydebug=1;

  cerr<<" ************************** Parsing starts **************************"<<endl;
  yyparse();
  cerr<<"************************** Parsing successful **************************"<<endl;

  if(root==NULL) return 0;

  cerr<<"************************** Printing starts **************************"<<endl;

  vector<Statement*>::iterator it;
  for(it=root->begin(); it!=root->end(); ++it){
    if(*it!=NULL) (*it)->pretty_print(0);
  }

  cerr<<"************************** Printing successful **************************"<<endl;

  return 0;
}





