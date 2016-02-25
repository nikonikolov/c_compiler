%code requires{
  #include <iostream>
  #include <string>  
  #include "helper.hpp"
  #include "DataStructures/Function.h"
  #include "DataStructures/Variable.h"
  
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
  Function* fnptr;
}

/* --------------------------------------------------- TOKENS KEYWORDS --------------------------------------------------- */

%token <strval> AUTO DOUBLE INT STRUCT BREAK ELSE LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR EXTERN RETURN UNION CONST FLOAT SHORT 
%token <strval> UNSIGNED CONTINUE FOR SIGNED VOID DEFAULT GOTO VOLATILE DO IF STATIC WHILE

/* --------------------------------------------------- TOKENS OPERATORS --------------------------------------------------- */

%token <strval> LSQUARE RSQUARE LBRACKET RBRACKET LCURLY RCURLY THREE_DOTS DOT PTR_OP PLUS_PLUS MINUS_MINUS SIZEOF LSHIFT RSHIFT 
%token <strval> LESS_OR_EQUAL MORE_OR_EQUAL LOGICAL_EQUALITY LOGICAL_INEQUALITY LOGICAL_AND LOGICAL_OR Q_MARK COLON MULT_EQUALS 
%token <strval> DIV_EQUALS PERCENT_EQUALS PLUS_EQUALS MINUS_EQUALS LSHIFT_EQUALS RSHIFT_EQUALS AND_EQUALS XOR_EQUALS OR_EQUALS 
%token <strval> COMMA HASH HASH_HASH SEMI_COLON EQUALS BITWISE_OR BITWISE_AND MULT PLUS MINUS WAVE EXL_MARK DIV PERCENT LOGICAL_LESS 
%token <strval> LOGICAL_MORE OP_HAT

/* --------------------------------------------------- TOKENS CONSTANTS --------------------------------------------------- */

%token <strval> FLOATING_CONST INTEGER_CONST CHAR_CONST

/* --------------------------------------------------- TOKENS OTHER --------------------------------------------------- */

%token <strval> IDENTIFIER STRING_LITERAL PREPROCESSOR_INCLUDE EOLINE

%type <list_var_ptr> fn_params_list

%type <strval> fn_param_identifier

%type <fnptr> fn_declaration

/* Only types that you use in the C++ code need to be defined */
//%type <strval> IDENTIFIER 
//%type <intval> INTEGER_CONST 

%start fn_declaration

%{
  Function* root=NULL;
  /* put additional C++ code here */
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

/* ============================================== 3.1 LEXICAL ELEMENTS ============================================== */

/* ---------------------------------------------- 3.1.3 CONSTANTS -------------------------------------------- */

// Ready
//CONSTANT : FLOATING_CONST | INTEGER_CONST | ENUMERATION_CONSTANT | CHAR_CONST ;



/* -------------------------------------------- ENUMERATION SPECIFIERS ------------------------------------------ */
/* ---------------------------------------------c grammar: 3.5.2.2 enumeration specifiers ----------------------- */


//ENUMERATION_CONSTANT : IDENTIFIER ; 

//START : fn_declaration { root = $1; }

/* -------------------------------------------- FUNCTION DECLARATIONS ------------------------------------------ */

// undefined fn_body. YOu have to add other return types as well
fn_declaration  : INT IDENTIFIER LBRACKET fn_params_list RBRACKET LCURLY RCURLY          
                    { root = new Function(int_type, $2, $4);
                      root->pretty_print(0);}
//                | INT IDENTIFIER LBRACKET fn_params_list RBRACKET LCURLY fn_body RCURLY  { cout<<"FUNCTION :"<<$2<<endl;}
                ;

// need to add other types than int; add void and const
//fn_params_list  : INT fn_param_identifier                           { cout<<"fn_param1 "<<$$<<endl; list_push_to_front($$, Variable(int_type, $2)); cout<<"fn_param1"<<endl;}
//                | fn_params_list COMMA INT fn_param_identifier      { cout<<"fn_param2"<<endl; list_push_to_front($$, Variable(int_type, $4)); }
fn_params_list  : INT fn_param_identifier                         { $$ = new list<Variable>; $$->push_back(Variable(int_type, $2));}
                | fn_params_list COMMA INT fn_param_identifier    { $$->push_back(Variable(int_type, $4)); }
                |                                                 { $$ = NULL; }
                ;   

fn_param_identifier : IDENTIFIER                                    { $$ = $1; }
                    | LBRACKET fn_param_identifier RBRACKET
                    ;


//fn_body : ;

/* -------------------------------------------- LOOP DECLARATIONS ------------------------------------------ */
/*
// Add loop_body, single_line_loop_body
for_loop  : FOR LBRACKET for_loop_decl_statement RBRACKET LCURLY RCURLY
          | FOR LBRACKET for_loop_decl_statement RBRACKET single_line_loop_body SEMI_COLON 
          //| FOR LBRACKET for_loop_decl_statement RBRACKET LCURLY loop_body RCURLY
          ;

// undefined: logical_condition, var_declaration, update_statement(this can be assignment expression)          
for_loop_decl_statement : var_declaration SEMI_COLON logical_condition SEMI_COLON update_statement
                        | var_declaration SEMI_COLON logical_condition SEMI_COLON
                        | var_declaration SEMI_COLON SEMI_COLON update_statement
                        | SEMI_COLON logical_condition SEMI_COLON update_statement
                        | var_declaration SEMI_COLON SEMI_COLON
                        | SEMI_COLON SEMI_COLON update_statement
                        | SEMI_COLON logical_condition SEMI_COLON
                        | SEMI_COLON SEMI_COLON
                        ;

// Add loop_body, single_line_loop_body
while_loop  : WHILE LBRACKET logical_condition RBRACKET LCURLY RCURLY  
            | WHILE LBRACKET logical_condition RBRACKET single_line_loop_body SEMI_COLON  
            //| WHILE LBRACKET logical_condition RBRACKET LCURLY loop_body RCURLY  
            ;

/* -------------------------------------------- CONDITIONAL STATEMENTS ------------------------------------------ */

// Be very careful - this can be function call, comparison, or even assignment
//logical_condition

// NOTE: fn_body, loop_body, if_body can all be defined the same and recursively with loops, ifs, functions, var declarations
// arithmetic expressions etc
/*
if_block_statement  : if_statement
                    | if_statement else_statement
                    | if_statement else_if_statement_list
                    | if_statement else_if_statement_list else_statement
                    ;

if_statement  : scoped_if_statement
              | single_line_if_statement
              ;

else_if_statement_list  : single_line_else_if_statement
                        | scoped_else_if_statement
                        | else_if_statement_list scoped_else_if_statement
                        | else_if_statement_list single_line_else_if_statement
                        ;

else_statement  : scoped_else_statement
                | single_line_else_statement
                ;


single_line_if_statement  : IF LBRACKET logical_condition RBRACKET single_line_if_body SEMI_COLON
                          ;

single_line_else_if_statement : ELSE IF LBRACKET logical_condition RBRACKET single_line_if_body SEMI_COLON
                              ;

single_line_else_statement  : ELSE single_line_if_body SEMI_COLON
                            ;


scoped_if_statement : IF LBRACKET logical_condition RBRACKET LCURLY if_body RCURLY 
                    ;

scoped_else_if_statement : ELSE IF LBRACKET logical_condition RBRACKET LCURLY if_body RCURLY 
                    ;

scoped_else_if_statement : ELSE LCURLY if_body RCURLY 
                    ;
*/
%%  

int yyerror(const char* s){ 
    //std::cout <<"yyerror: "<< s<< std::endl;
    std::cout <<"Parser error in file: "<< source_file<<" at line: "<<input_file_line << std::endl;
    return -1;
}

int main(){
  cout<<"Parsing starts"<<endl;
  yyparse();
  cout<<"Parsing ended"<<endl;

}





