#ifndef PROGRAM_H
#define PROGRAM_H

#include "VarDeclaration.h"
#include "Function.h"
#include "Variable.h"
#include "Statement.h"

class Program{

public:
	Program();
	//Program(vector<VarDeclaration*>* global_vars_decl_in, vector<Function*>* functions_in);
	~Program();

	void insert_fn(Function* fn_in);
	void insert_fn_prototype(Function* fn_in);
	void push_var_back(VarDeclaration* var_in);

	void pretty_print(const int& indent);
	void renderasm();

private:
	//vector<Function*>* functions;				// Pointer to a vector of all the functions defined. The MAIN is included here
	vector<VarDeclaration*>* global_vars_decl;	// Pointer to a vector of all global variables defined in the scope of the program

	ASMhandle* context;
	map<string, Function*>* functions;			// Pointer to a map of all the functions defined. The MAIN is included here
	map<string, Variable*>* global_vars; 		// Pointer to a map of all the global variables defined

	map<string, Function*>* fn_prototypes;		// Pointer to a map of all the function prototypes defined

	stringstream ss;
};



#endif

