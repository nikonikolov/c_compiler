#ifndef WHILELOOP_H
#define WHILELOOP_H

#include "Statement.h"
#include "CompoundStatement.h"
#include "Variable.h"


class WhileLoop : public Statement{

public:
	WhileLoop(BaseExpression* condition_in, Statement* single_statement_in, const StatementT& stat_type_in);
	WhileLoop(BaseExpression* condition_in, CompoundStatement* loop_body_in, const StatementT& stat_type_in);
	~WhileLoop();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);
private:

	// Note: only one can be initialized to a non-NULL value
	Statement* single_statement;		// Single Statement defining the function body
	CompoundStatement* loop_body;		// Compound Statement defining the function body

	BaseExpression* condition;
};



#endif