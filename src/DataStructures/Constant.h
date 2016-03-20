#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdint>
#include "BaseExpression.h"


template<class Type>
class Constant : public BaseExpression{

public:
	Constant(const Type& num_val);
	Constant(const Type& num_val, const int& line_in, const string& src_file_in);
	~Constant();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, char** destination=NULL);
	BaseExpression* simplify(snum_t& value);

	Type get_value();
	/*template<class T>
	friend std::ostream& operator<<(std::ostream& out, Constant<T>& obj);
	*/
private:
	// Note: you can extract the exact type from the name of the Temaplate Type
	Type num_val;					// Contains the numerical value of the constant
};




template<class Type>
Constant<Type>::Constant(const Type& num_val_in) :
	BaseExpression(EXPR_constant), num_val(num_val_in){}

template<class Type>
Constant<Type>::Constant(const Type& num_val_in, const int& line_in, const string& src_file_in) :
	BaseExpression(EXPR_constant, line_in, src_file_in), num_val(num_val_in){}

template<class Type>
Constant<Type>::~Constant(){}


template<class Type>
void Constant<Type>::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<num_val;
}

template<class Type>
void Constant<Type>::renderasm(ASMhandle& context, char** destination /*=NULL*/){
	assembler.push_back(ss<<pad<<"li"<<"$t0, "<<num_val<<endl);
	assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<*destination<<endl);
}

template<class Type>
BaseExpression* Constant<Type>::simplify(snum_t& value){
	value.tname = tint;
	value.numval.intmem = (int)num_val;
	return NULL;
}

template<class Type>
Type Constant<Type>::get_value(){
	return num_val;
}
/*
template<class T>
friend std::ostream& operator<<(std::ostream& out, Constant<T>& obj){
	out<<obj.num_val;
	return out;
}
*/

#endif
