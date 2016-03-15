#ifndef PROGRAM_H
#define PROGRAM_H

#include "VarDeclaration.h"
#include "Function.h"
#include "Statement.h"

class Program{

public:
	Program();
	Program(vector<VarDeclaration*>* global_vars_in, vector<Function*>* functions_in);
	~Program();

	void push_fn_back(Function* fn_in);
	void push_var_back(VarDeclaration* var_in);

	void pretty_print(const int& indent) const;

private:
	vector<Function*>* functions;					// Pointer to a vector of all the functions defined. The MAIN is included here
	vector<VarDeclaration*>* global_vars;			// Pointer to a vector of all global variables defined in the scope of the program

	ASMhandle* context;
};



#endif

