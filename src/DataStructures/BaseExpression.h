#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include "Statement.h"

class BaseExpression : public Statement{

public:
	BaseExpression(const StatementT& stat_type_in);
	//BaseExpression(BaseExpression* expr_ptr_in);
	virtual ~BaseExpression();

	virtual snum_t simplify() =0;
};



#endif

