#ifndef TERNERYEXPRESSION_H
#define TERNERYEXPRESSION_H

#include "BaseExpression.h"


class TerneryExpression : public BaseExpression{

public:
	TerneryExpression(BaseExpression* lhs_in, BaseExpression* mid_in, BaseExpression* rhs_in);
	~TerneryExpression();

	void set_lhs(BaseExpression* lhs_in);
	void set_mid(BaseExpression* mid_in);
	void set_rhs(BaseExpression* rhs_in);

	NumT eval();
	void pretty_print(const int& indent) const;

private:
	BaseExpression* lhs;			// Bottom node
	BaseExpression* mid; 			// This node
	BaseExpression* rhs; 			// Left node
};



#endif

