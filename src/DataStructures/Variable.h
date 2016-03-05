#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstdint>
#include <string.h>
#include "Expression.h"



class Variable : public Expression{

public:
	//Variable(const VarT& var_type_in, char* token_val_in, char* name_in);
	Variable(const VarT& var_type_in, char* name_in);
	Variable(char* name_in);
	~Variable();
	const char* get_name() const;
	void pretty_print(const int& indent) const;

private:
	VarT var_type;					// Specifies the type of the variable
	NumT num_val;					// Contains the numerical value of token_val cast to the specified type
	char* name;						// Name given to the variable in the program
	char* assembler_name;			// Name associated with the assembler code
	uint32_t address;				// Contains the address of the variable 
};



#endif

