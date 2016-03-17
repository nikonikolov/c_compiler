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

using std::list;
using std::vector;
using std::map;
using std::stack;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::pair;

//#define MOD "\t"<<left<<setfill(' ')<< setw(8)
#define INTNAN std::numeric_limits<int>::quiet_NaN()

std::ostream& pad(std::ostream& os);

/* =============================================== STATEMENT TYPES =============================================== */

enum StatementT{
	// Block Statements
	ST_fn_def = 1,
	ST_loop = 2,
	ST_fn_call = 3,
	// function_prototype = 4; // maybe??
	ST_conditional = 5,
	ST_conditional_case = 6,
	ST_var_declaration_container = 7,
	ST_return = 7,
	ST_compound = 8,
	
	// Expressions
	ST_expression = 20,
	ST_expr_statement = 21,
	ST_constant = 22,
	ST_var_expr = 24,
	ST_var_return = 25,
	ST_var_fn_param = 26,
	ST_base_expr = 27,
	ST_ternery_expr = 28
};

/* =============================================== EXPRESSION TYPES =============================================== */


enum ExprT{
	//EXPR_fn_call = 3,
	
	EXPR_expression = 20,
	EXPR_expr_statement = 21,
	EXPR_constant = 22,
	EXPR_assignment_expr = 23,
	EXPR_tmp_var = 24,
	EXPR_ternery_expr = 28
};

/* =============================================== ERROR TYPES =============================================== */

enum ErrorgenT{
	ERROR_redefinition = 1 
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

