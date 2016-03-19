#include "VarExpr.h"


VarExpr::VarExpr(char* name_in) : BaseExpression(EXPR_tmp_var){
	name = strdup(name_in);
}

VarExpr::VarExpr(char* name_in, const int& line_in, const string& src_file_in) : 
	BaseExpression(EXPR_tmp_var, line_in, src_file_in){
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
		generate_error("variable \""+string(name)+"\" not defined for the current scope");
	}
	bool global_var=false;
	*destination=result->get_asm_location(context, global_var);
	if(global_var) throw result;
}


BaseExpression* VarExpr::simplify(snum_t& value){
	throw 1;
}

