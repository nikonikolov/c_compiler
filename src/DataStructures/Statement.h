#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>
#include <list>
#include <iomanip>
#include <iostream>

using std::list;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
/*	
	An abstract class that can cover expressions, function declarations and calls, if statements, loops
*/

enum StatementT{
	stat_fn_def = 1,
	stat_loop = 2,
	stat_fn_call = 3,
	// function_prototype = 4; // maybe??
	stat_conditional = 5,
	stat_conditional_case = 6,
	stat_expression = 7,
	stat_var_declaration = 8,
	stat_constant = 9,
	stat_exprstat = 10
};

enum VarT{
	int_type 	= 248,
	double_type = 247,
	char_type	= 246,
	void_type	= 245
};

union NumT{
	int 	intval;
	double 	doubleval;

};

class Statement{

public:
	Statement(const StatementT stat_type_in);
	virtual ~Statement();

	virtual void pretty_print(const int& indent) const =0;		// parameter specifies the starting column for the printing

protected:
	StatementT stat_type;

};



#endif

