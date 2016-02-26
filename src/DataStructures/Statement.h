#ifndef STATEMENT_H
#define STATEMENT_H

#include <vector>
#include <list>
#include <iomanip>
#include <iostream>
// You will need to delete that eventually
#include "Variable.h"

using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::string;
/*	
	An abstract class that can cover arithmetic expressions, function declarations and calls, if statements, loops
*/

enum StatementT{
	stat_fn_def = 1,
	stat_loop = 2,
	stat_fn_call = 3,
	// function_prototype = 4; // maybe??
	stat_conditional = 5,
	stat_conditional_case = 6,
	stat_arithmetic = 7,
	stat_var_declaration = 8
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

