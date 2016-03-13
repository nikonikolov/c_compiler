#include "VarExpr.h"


VarExpr::VarExpr(char* name_in) : type_name(NULL){
	name = strdup(name_in);
}


VarExpr::~VarExpr(){}


const char* VarExpr::get_name() const{
	return name;
}



void VarExpr::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;
}


void VarExpr::renderasm(ASMhandle* context){
	return;
}
