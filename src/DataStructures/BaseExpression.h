#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include "Statement.h"

class BaseExpression : public Statement{

public:
	BaseExpression(const StatementT& stat_type_in);
	//BaseExpression(BaseExpression* expr_ptr_in);
	virtual ~BaseExpression();

	// Not const =0 because at evaluation, there might be optimizations and reductions to be done
	// Uncomment for Codegen
	//virtual snum_t eval()=0;
};



#endif

