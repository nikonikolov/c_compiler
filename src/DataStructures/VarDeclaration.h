#ifndef VARDECLARATION_H
#define VARDECLARATION_H

#include "Statement.h"
#include "Variable.h"

class VarDeclaration : public Statement{

public:
	VarDeclaration(const VarT type_in, vector<Variable>* variables_in);
	~VarDeclaration();

	void pretty_print(const int& indent) const;
private:
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	VarT type;								// Specifies the type of variables defined

	vector<Variable>* variables;			// Pointer to a vector of the variables defined

	uint32_t address;						// Contains the address of the function 

};



#endif

