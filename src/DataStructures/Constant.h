#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdint>
#include <string.h>
#include "BaseExpression.h"


template<class Type>
class Constant : public BaseExpression{

public:
	Constant(const Type& num_val);
	~Constant();

	void pretty_print(const int& indent) const;
	void renderasm();

private:
	// Note: you can extract the exact type from the name of the Temaplate Type
	Type num_val;					// Contains the numerical value of the constant
	//char* assembler_name;			// Name associated with the assembler code
	uint32_t address;				// Contains the address of the Constant 
};



#endif

template<class Type>
Constant<Type>::Constant(const Type& num_val_in) :
	BaseExpression(ST_constant), num_val(num_val_in){}

template<class Type>
Constant<Type>::~Constant(){}


template<class Type>
void Constant<Type>::pretty_print(const int& indent) const{
	cout<<num_val;
}

template<class Type>
void Constant<Type>::renderasm(){
	return;
}
