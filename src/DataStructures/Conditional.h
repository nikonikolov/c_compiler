#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Statement.h"
#include "CompoundStatement.h"
#include "BaseExpression.h"

/*
	ConditionalCase: Represents a single if, else if, else, case or default statement as part of a bigger block of if or switch 
	statement. You can think of it as a single branch condition and body opposed to a block of branches

	NOTE: single_statement_in might be a ConditionalCase itself. This combined with condition_in==NULL means you have an else if
	statement. If condition_in==NULL and single_statement is NULL or is not ConditionalCase, then you have the else statement

	NOTE: it is possible that you have else and then else if. You have to analyze that and generate_error if this happens
*/

class ConditionalCase : public Statement{

public:
	// Defaults used for else statements
	ConditionalCase(Statement* single_statement_in, BaseExpression* condition_in);
	ConditionalCase(CompoundStatement* block_statement_in, BaseExpression* condition_in);

	ConditionalCase(Statement* single_statement_in, BaseExpression* condition_in, const int& line_in, const string& src_file_in);
	ConditionalCase(CompoundStatement* block_statement_in, BaseExpression* condition_in, const int& line_in, const string& src_file_in);

	~ConditionalCase();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);
	void renderasm(ASMhandle& context, const string& continued_execution, const string& next_jump);
	
private:

	BaseExpression* condition;				// Condition for the block to be executed. If NULL, then the you have else statement
	
	Statement* single_statement;			// Dynamically allocated. Used when the body isn't scoped but consists of a single statement

	CompoundStatement* block_statement;		// Pointer to a vector of the statements appearing in the scope of the condition
};


/*
	Conditional: Represents a whole if/switch block as a single statment. It is composed of a vector of ConditionalCases, where
	each Case represens one if, else if, else, case or default. The vector is ordered in the way conditions appear in the program
*/
class Conditional : public Statement{

public:
	Conditional(vector<ConditionalCase*>* conditions_in);
	Conditional(vector<ConditionalCase*>* conditions_in, const int& line_in, const string& src_file_in);
	~Conditional();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);

private:
	vector<ConditionalCase*>* conditions;			// Pointer to a vector that keeps the order of the conditions checked

};




#endif

