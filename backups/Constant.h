#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdint>
#include <string.h>
#include "Expression.h"


template<class Type>
class Constant : public Expression{

public:
	Constant(const Type& num_val);
	~Constant();
	void pretty_print(const int& indent) const;



private:
	// Note: you can extract the exact type from the name of the Temaplate Type
	Type num_val;					// Contains the numerical value of the constant
	//char* assembler_name;			// Name associated with the assembler code
	uint32_t address;				// Contains the address of the Constant 
};



#endif

template<class Type>
Constant<Type>::Constant(const Type& num_val_in) :
	Expression(ST_constant), num_val(num_val_in){}

template<class Type>
Constant<Type>::~Constant(){}


template<class Type>
void Constant<Type>::pretty_print(const int& indent) const{
	cout<<num_val;
}

