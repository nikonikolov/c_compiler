#ifndef FNCALL_H
#define FNCALL_H

#include "Variable.h"
#include "include.h"
#include "BaseExpression.h"


/*	FIX:
		1. Currently only 32bit wide arguments and INTs only assumed as function parameters
		2. Move function arguments on the stack
*/

/*
class FnCall{

public:
	FnCall(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in);
	FnCall(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in, 
																				const int& line_in, const string& src_file_in);
	~FnCall();

	string get_name() const;
	void generate_error(const string& msg_out) const;

	void renderasm(ASMhandle& context);
	void pretty_print(const int& indent);

private:
	void init_args(ASMhandle& context);

	
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
*/


#endif

