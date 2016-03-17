#include "VarExpr.h"


VarExpr::VarExpr(char* name_in) : BaseExpression(EXPR_tmp_var){
	name = strdup(name_in);
}


VarExpr::~VarExpr(){}


const char* VarExpr::get_name() const{
	return name;
}



void VarExpr::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;
}


void VarExpr::renderasm(ASMhandle& context, char** destination /*=NULL*/){
	Variable* result;
	try{
		result = context.get_var_location(name);
	}
	catch(const int& error){
		generate_error();
	}
	//char* var_location = result->get_asm_location();
	//cout<<pad<<"lw"<<"$t0, "<<var_location<<endl;
	//cout<<pad<<"sw"<<"$t0, "<<*destination<<endl;

	*destination=result->get_asm_location();
}


BaseExpression* VarExpr::simplify(snum_t& value){
	throw 1;
}


void VarExpr::generate_error(){
	BaseExpression::generate_error();
	cerr<<"variable "<<name<<" not defined"<<endl;	
	exit(EXIT_FAILURE);
}
