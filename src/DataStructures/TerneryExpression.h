#ifndef TERNERYEXPRESSION_H
#define TERNERYEXPRESSION_H

#include "BaseExpression.h"


class TerneryExpression : public BaseExpression{

public:
	TerneryExpression(vector<BaseExpression*>* lhs_in, BaseExpression* mid_in, vector<BaseExpression*>* rhs_in);
	~TerneryExpression();

	void set_lhs(vector<BaseExpression*>* lhs_in);
	void set_mid(BaseExpression* mid_in);
	void set_rhs(vector<BaseExpression*>* rhs_in);
	void push_back_lhs(BaseExpression* expr_in);
	void push_back_rhs(BaseExpression* expr_in);

	snum_t eval();
	void pretty_print(const int& indent) const;
	void renderasm();

private:
	vector<BaseExpression*>* lhs;			// Bottom nodes
	BaseExpression* mid; 					// This node
	vector<BaseExpression*>* rhs; 			// Left nodes
};



#endif

