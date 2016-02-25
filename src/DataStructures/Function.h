#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <list>
#include "Variable.h"
#include <iomanip>
#include <iostream>
#include <string>

using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::string;
class Function{

public:
	Function(const VarT& return_type_in, char* name_in);
	Function(const VarT& return_type_in, char* name_in, list<Variable>* params_in);
	~Function();

	void pretty_print(const int& indent) const;
private:
	VarT return_type;						// Specifies the return type of the function
	char* name;								// Name given to the function in the source code
	char* assembler_name;					// Name associated with the assembler code
	list<Variable>* params;					// Pointer to a list of the parameters the function takes in the exact order specified
											// The list is dynamically allocated
	vector<Variable> local_vars;			// Vector of the variables defined in the scope of the function
	uint32_t address;						// Contains the address of the function 
};



#endif

