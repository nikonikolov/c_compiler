#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Statement.h"

/*
	ConditionalCase: Represents a single if, else if, else, case or default statement as part of a bigger block of if or switch 
	statement. You can think of it as a single branch condition and body opposed to a block of branches
*/
class ConditionalCase : public Statement{

public:
	ConditionalCase(Statement* single_statement_in, Statement* condition_in = NULL);
	ConditionalCase(vector<Statement*>* statements_in, Statement* condition_in = NULL);
	~ConditionalCase();

	void pretty_print(const int& indent) const;
	void renderasm();
private:
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	Statement* condition;					// Dynamically allocated
	
	Statement* single_statement;			// Dynamically allocated. Used when the body isn't scoped but consists of a single statement

	vector<Statement*>* statements;			// Pointer to a vector of the statements appearing in the scope of the condition
};


/*
	Conditional: Represents a whole if/switch block as a single statment. It is composed of a vector of ConditionalCases, where
	each Case represens one if, else if, else, case or default. The vector is ordered in the way conditions appear in the program
*/
class Conditional : public Statement{

public:
	Conditional(vector<ConditionalCase*>* conditions_in);
	~Conditional();

	void pretty_print(const int& indent) const;
	void renderasm();
private:
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	vector<ConditionalCase*>* conditions;			// Pointer to a vector that keeps the order of the conditions checked

};




#endif

