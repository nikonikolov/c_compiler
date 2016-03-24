#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "BaseExpression.h"
#include "Constant.h"

class ArrayExpression : public BaseExpression{

public:
	ArrayExpression(BaseExpression* first_dim_mem, const int& line_in, const string& src_file_in);
	~ArrayExpression();

	void push_back_mem(BaseExpression* expr_in);

	BaseExpression* simplify();
	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, ExprResult** dest=NULL);

private:
	vector<BaseExpression*>* dimension;
};



#endif

