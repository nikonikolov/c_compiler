#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstdint>
#include <string.h>
#include "Expression.h"



class Variable : public Expression{

public:
	// NOTE: you need to make overload constructor to build dereferencer

	Variable(char* type_name_in, char* name_in, Expression* init_val_in=NULL);
	
	// Usually used for variable declaration - not currently used
	Variable(char* name_in, Expression* init_val_in=NULL);
	
	// Usually used for function return types
	Variable(const StatementT& stat_type_in, char* some_name_in, list<Expression*>* dereferencer_in=NULL);

	// Usually used for function parameters
	Variable(char* type_name_in, char* name_in, const StatementT& stat_type_in, list<Expression*>* dereferencer_in=NULL);
	
	~Variable();

	void set_type_name(char* type_name_in);
	void set_init_val(Expression* init_val_in);
	const char* get_name() const;
	
	void pretty_print(const int& indent) const;
	void dereference_back(Expression* expr_in);
	void dereference_front(Expression* expr_in);

private:
	/* 	Template version instead of using var_type would not be a good idea since you would not know the types of Variables
		appearing in Expressions. Enum type instead of string would not be useful as well because you won't be able to
		describe structs and unions. Note that the string contains only type-names such as int, double, etc and no * or [].
		Pointers and levels of dereferencing are dealt with by the dereferecer structure below 
	*/
	
	char* type_name;				// Contains the typename of the variable, i.e. int, double, etc. No * or []
	snum_t num_val;					// Contains the numerical value of token_val cast to the specified type
	char* name;						// Name given to the variable in the program
	char* assembler_name;			// Name associated with the assembler code
	uint32_t address;				// Contains the address of the variable 
	Expression* init_val;			// Contains the value to be assigned to the variable at initialization
	
	
	/* 	The following structure allows for describing Variables appearing both in declarations or in Expressions.
	 	Arrays and pointers are treated exactly the same way - using dereferencing
	*/
	
	list<Expression*>* dereferencer;			
	/* 	The value of the Expression in the list specifies the offset of the memory location pointed to. 
		If you encounter a simple * in the parser, then push back a Constant equal to 0. 
		The size of the list specifies how many times you need to dereference the variable
	*/


	/* Fields for assembly */
	string location;				// Holds the location of the variable, e.g. 4($sp) or $t0

};



#endif

