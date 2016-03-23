


/* ============================================== 3.4 CONSTANT EXPRESSIONS ============================================== */

CONSTANT_EXPRESSION : CONDITIONAL_EXPRESSION ;

/* ============================================== 3.5 DECLARATIONS ============================================== */


declaration : declaration_type init_declarator_list
            // Allowed but not sensible. Simply ignore
            | declaration_type     { cerr<<"Warning: Useless definition in file "<<source_file<<", Line: "<<input_file_line<<endl;}
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

// Initialization list
init_declarator_list  : init_declarator
                      | init_declarator_list COMMA init_declarator 
                      ;
                      
// Variable name and initialization/value (if provided) at declaration
init_declarator   : declarator
                  | declarator EQUALS initializer
                  ;

// LHS of variable initialization
declarator  : direct_declarator
            //| pointer direct_declarator
            ;

// Variable name, Array cell or function
direct_declarator : IDENTIFIER
                  | LBRACKET declarator RBRACKET
                  // Array cell
                  | direct_declarator LSQUARE constant_expression RSQUARE
                  | direct_declarator LSQUARE RSQUARE
                  // Function declaration: name and arguments
                  //| direct_declarator LBRACKET parameter_type_list RBRACKET
                  //| direct_declarator LBRACKET identifier_list RBRACKET
                  //| direct_declarator LBRACKET RBRACKET
                  ;

// RHS of variable initialization
initializer // Expression value for a variable
            : assignment_expression
            // Array initialization
            | LCURLY initializer_list RCURLY
            | LCURLY initializer_list COMMA RCURLY
            ;

// List for array elements initialization
initializer_list  : initializer
                  | initializer_list COMMA initializer
                  ;



/* -------------------------------------------- TYPE AND STORAGE SPECIFIERS -------------------------------------------- */

// void not allowed for variables 
TYPE_SPECIFIER  : VOID 
                | CHAR 
                | INT 
                | FLOAT 
                | DOUBLE 
                | LONG 
                | SHORT 
                | SIGNED 
                | UNSIGNED 
                //| ENUM_SPECIFIER 
                //| STRUCT_OR_UNION_SPECIFIER 
                //| TYPEDEF_NAME
                ;
/*
TYPE_QUALIFIER  : CONST
                | VOLATILE
                ;

STORAGE_SPECIFIER : TYPEDEF
                  | EXTERN
                  | STATIC
                  | AUTO
                  | REGISTER
                  ;
*/

/* ---------------------------------------------- 3.5.5 TYPE NAMES -------------------------------------------- */

TYPE_NAME : specifier_qualifier_list abstract_declarator
          | specifier_qualifier_list
          ;

specifier_qualifier_list  : TYPE_SPECIFIER specifier_qualifier_list
                          | TYPE_QUALIFIER specifier_qualifier_list
                          | TYPE_SPECIFIER
                          | TYPE_QUALIFIER
                          ;

ABSTRACT_DECLARATOR   : POINTER
                      | DIRECT_ABSTRACT_DECLARATOR
                      | POINTER DIRECT_ABSTRACT_DECLARATOR
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

POINTER : MULT TYPE_QUALIFIER_LIST
        | MULT 
        | MULT TYPE_QUALIFIER_LIST POINTER
        | MULT POINTER
        ;

TYPE_QUALIFIER_LIST : TYPE_QUALIFIER
                    | TYPE_QUALIFIER_LIST TYPE_QUALIFIER
                    ;

/* ---------------------------------------------- 3.5.6 TYPE DEFINITIONS -------------------------------------------- */

TYPEDEF_NAME : IDENTIFIER ;

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



STRUCT_DECLARATOR_LIST  : STRUCT_DECLARATOR
                        | STRUCT_DECLARATOR_LIST COMMA STRUCT_DECLARATOR
                        ;

STRUCT_DECLARATOR   : DECLARATOR
                    | DECLARATOR COLON CONSTANT_EXPRESSION
                    | COLON CONSTANT_EXPRESSION
                    ;


/* ------------------------------------------ FN PARAMS ---------------------------------------- */


PARAMETER_TYPE_LIST : PARAMETER_LIST
                    | PARAMETER_LIST COMMA THREE_DOTS
                    ;

PARAMETER_LIST  : PARAMETER_DECLARATION
                | PARAMETER_LIST COMMA PARAMETER_DECLARATION
                ;

PARAMETER_DECLARATION : declaration_type DECLARATOR
                      | declaration_type ABSTRACT_DECLARATOR
                      | declaration_type
                      ;

IDENTIFIER_LIST : IDENTIFIER
                | IDENTIFIER_LIST COMMA IDENTIFIER
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


/* --------------------------------------------- 3.6.4 SELECTION STATEMENTS ------------------------------------------- */

SELECTION_STATEMENT : IF LBRACKET EXPRESSION RBRACKET STATEMENT
                    | IF LBRACKET EXPRESSION RBRACKET STATEMENT ELSE STATEMENT
                    | SWITCH LBRACKET EXPRESSION RBRACKET STATEMENT
                    ;


/* ============================================== 3.7 EXTERNAL DEFINITIONS ============================================== */

TRANSLATION_UNIT  : EXTERNAL_DECLARATION
                  | TRANSLATION_UNIT EXTERNAL_DECLARATION
                  ;

EXTERNAL_DECLARATION  : FUNCTION_DEFINITION
                      | DECLARATION
                      ;

/* --------------------------------------------- 3.7.1 FUNCTION DEFINITIONS ------------------------------------------- */

FUNCTION_DEFINITION : declaration_type DECLARATOR     {cout<<"%1 "<<$1<<" "<<$2<<endl;}
                    | DECLARATOR                            {cout<<"%2 "<<$1<<endl;}
                    | DECLARATION_LIST COMPOUND_STATEMENT   {cout<<"%3 "<<$1<<" "<<$2<<endl;}
                    | COMPOUND_STATEMENT                    {cout<<"%4 "<<$1<<endl;}
                    ;






