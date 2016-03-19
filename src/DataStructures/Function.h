#ifndef FUNCTION_H
#define FUNCTION_H

#include "CompoundStatement.h"
#include "Variable.h"
#include "include.h"


/*	FIX:
		1. Currently only 32bit wide arguments assumed as function parameters
		2. Move function arguments on the stack
*/


class Function{

public:
	Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in);
	Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in, 
																				const int& line_in, const string& src_file_in);
	~Function();

	string get_name() const;
	void generate_error(const string& msg_out) const;

	void renderasm(ASMhandle& context);
	void pretty_print(const int& indent);

private:
	void init_args(ASMhandle& context);

	
	/* 	return_type specifies what type the return value should be. This structure allows for handling pointers as well. 
		Not sure about function pointers
	*/
	Variable* return_type;					
	
	snum_t return_val;						// Holds the result of the return value for the function

	char* name;								// Name given to the function in the source code
	vector<Variable*>* params;				// Pointer to a vector of the parameters the function takes in the exact order specified
	vector<Statement*>* statements;			// Pointer to a vector of the statements appearing in the scope of the function

	CompoundStatement* fn_body;				// CompoundStatement corresponding to function body

	char* asm_name;

	int line;
	string src_file;
};



#endif

