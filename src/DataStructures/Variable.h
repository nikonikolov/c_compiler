#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstdint>
#include <string.h>

enum VarT{
	int_type 	= 248,
	double_type = 247,
	char_type	= 246,
	void_type	= 245
};

union NumValue{
	int 	intval;
	double 	dval;

};

class Variable{

public:
	Variable(const VarT& var_type_in, char* token_val_in, char* name_in);
	Variable(const VarT& var_type_in, char* name_in);
	~Variable();
	const char* get_name() const;

private:
	VarT var_type;					// Specifies the type of the variable
	NumValue num_val;				// Contains the numerical value of token_val cast to the specified type
	char* token_val;				// Contains the string recognized by the tokenizer
	char* name;						// Name given to the variable in the program
	char* assembler_name;			// Name associated with the assembler code
	uint32_t address;				// Contains the address of the variable 
};



#endif

