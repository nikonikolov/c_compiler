#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BaseExpression.h"
#include "Constant.h"
#include <string>


/*	REQUIRED FIXES:
		1. Support for all types of variables
		2. Cast variables and manage the returned struct properly
		3. Operators not yet supported: all pointer related such as . -> & * and sizeof
*/	


class Expression : public BaseExpression{

public:
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in);
	Expression(const int& line_in, char* src_file_in, BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in);
	~Expression();

	void set_lhs(Expression* lhs_in);	
	void set_rhs(Expression* rhs_in);

	//snum_t eval();
	void pretty_print(const int& indent) const;
	void renderasm();

private:
	string gen_error() const;
	void init_subexpr(BaseExpression* expr_ptr, const snum_t& result);
	
	char* oper;
	BaseExpression* lhs;
	BaseExpression* rhs;

	int line;
	string src_file;
};



#endif

