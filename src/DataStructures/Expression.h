#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BaseExpression.h"

class Expression : public BaseExpression{

public:
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in);
	~Expression();

	void set_lhs(Expression* lhs_in);	
	void set_rhs(Expression* rhs_in);

	NumT eval();
	void pretty_print(const int& indent) const;
	void renderasm();
private:
	char* oper;
	BaseExpression* lhs;
	BaseExpression* rhs;
};



#endif

