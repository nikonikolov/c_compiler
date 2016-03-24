#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "Statement.h"
#include "BaseExpression.h"
#include "ExprResult.h"

class ReturnStatement : public Statement{

public:
	ReturnStatement(BaseExpression* return_expr_in=NULL);
	ReturnStatement(BaseExpression* return_expr_in, const int& line_in, const string& src_file_in);
	~ReturnStatement();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);
private:

	BaseExpression* return_expr;
};



#endif

