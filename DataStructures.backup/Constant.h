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
	void renderasm(ASMhandle& context);

private:
	// Note: you can extract the exact type from the name of the Temaplate Type
	Type num_val;					// Contains the numerical value of the constant
};




template<class Type>
Constant<Type>::Constant(const Type& num_val_in) :
	BaseExpression(EXPR_constant), num_val(num_val_in){}

template<class Type>
Constant<Type>::~Constant(){}


template<class Type>
void Constant<Type>::pretty_print(const int& indent) const{
	cout<<num_val;
}

template<class Type>
void Constant<Type>::renderasm(ASMhandle& context){
	return;
}

#endif
