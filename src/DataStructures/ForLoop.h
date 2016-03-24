#ifndef FORLOOP_H
#define FORLOOP_H

#include "Statement.h"
#include "CompoundStatement.h"
#include "Variable.h"

/* =============================================== ForLoopTuple CLASS =============================================== */

class ForLoopTuple{
public:
	ForLoopTuple(vector<BaseExpression*>* mem1_in, vector<BaseExpression*>* mem2_in, vector<BaseExpression*>* mem3_in);	
	~ForLoopTuple();	

	vector<BaseExpression*>* 	mem1;
	BaseExpression* 			mem2;
	vector<BaseExpression*>* 	mem3;
};


/* =============================================== ForLoop CLASS =============================================== */

class ForLoop : public Statement{

public:
	ForLoop(ForLoopTuple* tuple_in, Statement* single_statement_in);
	ForLoop(ForLoopTuple* tuple_in, CompoundStatement* loop_body_in);
	~ForLoop();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);
private:

	// Note: only one can be initialized to a non-NULL value
	Statement* single_statement;		// Single Statement defining the function body
	CompoundStatement* loop_body;		// Compound Statement defining the function body

	vector<BaseExpression*>* init_block;
	BaseExpression* condition_block;
	vector<BaseExpression*>* update_block;
};



#endif