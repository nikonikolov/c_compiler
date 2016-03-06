/*#ifndef PROGRAM_H
#define PROGRAM_H

#include "Variable.h"
#include "Statement.h"

class Program{

public:
	Program();
	Program(list<Function>* functions_in, list<Variable>* global_vars_in);
	~Program();

	//void pretty_print(const int& indent) const;
private:
	//char* name;								// Name given to the function in the source code
	//char* assembler_name;					// Name associated with the assembler code
	list<Function>* functions;				// Pointer to a list of all the functions defined. The MAIN is included here
											// The list is dynamically allocated
	vector<Variable> global_vars;			// Vector of all global variables defined in the scope of the program
	//uint32_t address;						// Contains the address of the program - needed?? 
};



#endif

*/