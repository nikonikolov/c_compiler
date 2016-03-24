#ifndef CONSTANT_H
#define CONSTANT_H

#include <cstdint>
#include "BaseExpression.h"


template<class Type>
class Constant : public BaseExpression, public ExprResult{

public:
	/* ---------------------------------------------- CONSTRUCTION ---------------------------------------------- */
	Constant(const Type& num_val_in);
	Constant(const Type& num_val_in, const int& line_in, const string& src_file_in);
	~Constant();

	/* ---------------------------------------------- BaseExpression METHODS ---------------------------------------------- */

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, ExprResult** dest=NULL);
	BaseExpression* simplify();

	/* ---------------------------------------------- ExprResult METHODS ---------------------------------------------- */

	void load(const string& dest_reg);
	void store(const string& reg_location_in);
	void store_from_mem(const string& dest_mem_location);

	/* ---------------------------------------------- CLASS-SPECIFIC METHODS ---------------------------------------------- */

	Type get_value();

private:
	// Note: you can extract the exact type from the name of the Temaplate Type
	Type num_val;					// Contains the numerical value of the constant
};



/* ---------------------------------------------- CONSTRUCTION ---------------------------------------------- */

template<class Type>
Constant<Type>::Constant(const Type& num_val_in) :
	BaseExpression(EXPR_constant), ExprResult(RESULT_const), num_val(num_val_in){}

template<class Type>
Constant<Type>::Constant(const Type& num_val_in, const int& line_in, const string& src_file_in) :
	BaseExpression(EXPR_constant, line_in, src_file_in), ExprResult(RESULT_const), num_val(num_val_in){}

template<class Type>
Constant<Type>::~Constant(){}

/* ---------------------------------------------- BaseExpression METHODS ---------------------------------------------- */

template<class Type>
void Constant<Type>::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<num_val;
}

template<class Type>
void Constant<Type>::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
	if(dest==NULL) return;
	
	// When Constant is the RHS of assignment, e.g. call by Variable
	if(*dest!=NULL){
		load("$t0");
		(*dest)->store("$t0");
	}

	// When Constant is part of arithmetic expression
	else *dest = this;
}

template<class Type>
BaseExpression* Constant<Type>::simplify(){
	return NULL;
}

/* ---------------------------------------------- ExprResult METHODS ---------------------------------------------- */

template<class Type>
void Constant<Type>::load(const string& dest_reg){
	assembler.push_back(ss<<pad<<"li"<<dest_reg<<", "<<num_val<<endl);
}

template<class Type>
void Constant<Type>::store(const string& reg_location_in){
	generate_error("Destination for expression cannot be a temporary or a constant");
}

template<class Type>
void Constant<Type>::store_from_mem(const string& dest_mem_location){
	load("$t0");
	assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<dest_mem_location<<endl);
}

/* ---------------------------------------------- CLASS-SPECIFIC METHODS ---------------------------------------------- */

template<class Type>
Type Constant<Type>::get_value(){
	return num_val;
}


#endif
