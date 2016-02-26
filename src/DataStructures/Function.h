#ifndef FUNCTION_H
#define FUNCTION_H

#include "Statement.h"
#include "Variable.h"

// NB: Defined like that for the purposes of the MILESTONE. You need to Function as a base object and not to associate it with
// Statements. However, you have to define a function call as a class that inherits from statement
class Function : public Statement{

public:
	Function(const VarT& return_type_in, char* name_in, vector<Variable>* params_in, vector<Statement*>* statements_in);
	~Function();

	void pretty_print(const int& indent) const;
private:
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	VarT return_type;						// Specifies the return type of the function
	NumValue return_val;					// Holds the result of the return value for the function

	char* name;								// Name given to the function in the source code
	vector<Variable>* params;				// Pointer to a vector of the parameters the function takes in the exact order specified
	vector<Statement*>* statements;			// Pointer to a vector of the statements appearing in the scope of the function

	char* assembler_name;					// Name associated with the assembler code
	vector<Variable> local_vars;			// Gets built after construction and analyzation of statements
	uint32_t address;						// Contains the address of the function 

};



#endif

