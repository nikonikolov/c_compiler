#ifndef VARDECLARATION_H
#define VARDECLARATION_H

#include "Statement.h"
#include "Variable.h"

/*
	This class serves as a container of declared variables and provides methods to operate on them as a whole.
	It also allows to treat a declaration of multiple variables as a single Statement
*/

class VarDeclaration{

public:
	VarDeclaration(vector<Variable*>* variables_in);
	VarDeclaration(char* type_name_in, vector<Variable*>* variables_in); 
	VarDeclaration(vector<Variable*>* variables_in, const int& line_in, const string& src_file_in);
	VarDeclaration(char* type_name_in, vector<Variable*>* variables_in, const int& line_in, const string& src_file_in); 

	~VarDeclaration();

	void set_types(char* type_name_in);

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, const bool& local=true);
	
	void generate_error(const string& msg_out);

private:
	vector<Variable*>* variables;			// Pointer to a vector of the variables defined

	int line;
	string src_file;
};



#endif

