#ifndef VARDECLARATION_H
#define VARDECLARATION_H

#include "Statement.h"
#include "Variable.h"

/*
	This class serves as a container of declared variables and provides methods to operate on them as a whole.
	It also allows to treat a declaration of multiple variables as a single Statement
*/

class VarDeclaration : public Statement{

public:
	VarDeclaration(vector<Variable*>* variables_in);
	VarDeclaration(char* type_name_in, vector<Variable*>* variables_in); 
	~VarDeclaration();

	void set_types(char* type_name_in);

	void pretty_print(const int& indent) const;
	void renderasm(ASMhandle* context);
	void renderasm(vector<Variable*>* vars_in);

private:

	vector<Variable*>* variables;			// Pointer to a vector of the variables defined
};



#endif

