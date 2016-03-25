#ifndef DEREFERENCEEXPRESSION_H
#define DEREFERENCEEXPRESSION_H

#include "Expression.h"
#include "Constant.h"
#include "Pointer.h"
#include <string.h>

class DereferenceExpression : public Expression{

public:
	DereferenceExpression(BaseExpression* expr_in, const int& line_in, const string& src_file_in);
	~DereferenceExpression();

	void renderasm(ASMhandle& context, ExprResult** dest=NULL);

private:
};


#endif

