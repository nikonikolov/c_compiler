#ifndef LOOP_H
#define LOOP_H

#include "Statement.h"
#include "Variable.h"

class Loop : public Statement{

public:
	Loop(vector<Statement*>* statements_in);
	Loop(Statement* single_statement_in);
	~Loop();

	void pretty_print(const int& indent) const;
private:
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	// For the final version it will be a good idea to add some loop control statements as member data
	vector<Statement*>* statements;			// Pointer to a vector of the statements appearing in the scope of the loop

	Statement* single_statement;			// Dynamically allocated. Used when the body isn't scoped but consists of a single statement

	vector<Variable> local_vars;			// Gets built after construction and analyzation of statements
	uint32_t address;						// Contains the address of the loop 

};



#endif

