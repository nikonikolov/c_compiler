#ifndef INCLUDE_H
#define INCLUDE_H

#include <vector>
#include <list>
#include <map>
#include <stack>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>

#include <tuple>

#include <stdio.h>
#include <stdlib.h>

#include "Assembly.h"


using std::list;
using std::vector;
using std::map;
using std::stack;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::pair;
using std::tuple;
using std::get;


#define INTNAN std::numeric_limits<int>::quiet_NaN()

std::ostream& pad(std::ostream& os);

/* =============================================== DECLARE ASSEMBLY OBJECT =============================================== */

extern Assembly assembler;
extern bool debug;

/* =============================================== STATEMENT TYPES =============================================== */

enum StatementT{
	// Block Statements
	ST_fn_def = 1,
	ST_loop = 2,
	// function_prototype = 4; // maybe??
	ST_conditional = 5,
	ST_conditional_case = 6,
	ST_var_declaration_container = 7,
	ST_return = 7,
	ST_compound = 8,
	ST_for_loop = 9,
	ST_while_loop = 10,
	ST_dowhile_loop = 11,
	ST_expr_statement = 12
};

/* =============================================== EXPRESSION TYPES =============================================== */


enum ExprT{

	EXPR_expression = 20,
	EXPR_expr_statement = 21,
	EXPR_constant = 22,
	EXPR_assignment_expr = 23,
	EXPR_tmp_var = 24,
	EXPR_ternery_expr = 28,
	EXPR_fn_call = 29
};

/* =============================================== EXPRRESULT TYPES =============================================== */

enum ResultT{
	
	RESULT_const = 20,
	RESULT_var = 21,
	RESULT_tmp = 22
};


/* =============================================== FUNCTION TYPES =============================================== */
/*
enum FnT{
	FN_declaration = 1,
	FN_prototype = 2
}
*/
/* =============================================== ERROR TYPES =============================================== */

enum ErrorgenT{
	ERROR_redefinition = 1,
	ERROR_fn_var_clash = 2,
	ERROR_fn_undefined = 3
};

/* =============================================== VARIOUS EXPRESSION RETURN TYPE =============================================== */

union unum_t{
	long double ldoublemem;
	double 	doublemem;
	float 	floatmem;
	int 	intmem;
};

// NOTE: Order by precedence
enum enumt{
	tldouble = 100,
	tdouble = 98,
	tfloat = 96,
	tint = 80
};

class snum_t{
public:
	enumt tname;	// identifies which member the union currently employs
	unum_t numval;	// the union itself
	void operator=(const snum_t& obj_in);
};


#endif

