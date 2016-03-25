#ifndef ADDRESSXPRESSION_H
#define ADDRESSXPRESSION_H

#include "Expression.h"
#include "Constant.h"
#include "Pointer.h"
#include <string.h>

class AddressExpression : public Expression{

public:
	AddressExpression(BaseExpression* expr_in, const int& line_in, const string& src_file_in);
	~AddressExpression();

	void renderasm(ASMhandle& context, ExprResult** dest=NULL);

private:
};


#endif

