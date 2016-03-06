#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Statement.h"

/*	Class designed in this way instead of having pure BaseExpression class in order to allow for block initializations of arrays
*/

class Expression : public Statement{

public:
	Expression(Expression* lhs_in, char* oper_in, Expression* rhs_in);
	Expression(const StatementT& stat_type_in);
	virtual ~Expression();

	void set_lhs(Expression* lhs_in);
	void set_rhs(Expression* rhs_in);

	virtual NumT eval();
	virtual void pretty_print(const int& indent) const;

protected:
	char* oper;
	Expression* lhs;
	Expression* rhs;
};



#endif

