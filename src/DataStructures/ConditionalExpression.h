#ifndef CONDITIONALEXPRESSION_H
#define CONDITIONALEXPRESSION_H

#include "Expression.h"
#include "Constant.h"
#include <string.h>


/*	REQUIRED FIXES:
		1. Support for all types of variables
		2. Cast variables and manage the returned struct properly
		3. Operators not yet supported: all pointer related such as . -> & * and sizeof
*/	


class ConditionalExpression : public Expression{

public:
	ConditionalExpression(BaseExpression* condition_in, BaseExpression* lhs_in, BaseExpression* rhs_in, 
																	const int& line_in, const string& src_file_in);
	~ConditionalExpression();

	void renderasm(ASMhandle& context, ExprResult** dest=NULL);
	BaseExpression* simplify();
	void pretty_print(const int& indent);

private:
	BaseExpression* condition;
};


#endif

