#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include "Statement.h"
#include "BaseExpression.h"

class ReturnStatement : public Statement{

public:
	ReturnStatement(BaseExpression* return_expr_in=NULL);
	~ReturnStatement();

	void pretty_print(const int& indent) const;
	void renderasm();
private:

	BaseExpression* return_expr;
};



#endif

