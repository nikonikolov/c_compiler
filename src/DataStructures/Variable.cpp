#include "Variable.h"


Variable::Variable(const VarT& var_type_in, char* token_val_in, char* name_in) :
	var_type(var_type_in){
		name = strdup(name_in);
		token_val = strdup(token_val_in);
}

Variable::Variable(const VarT& var_type_in, char* name_in) :
	var_type(var_type_in){
		name = strdup(name_in);
}

Variable::Variable(char* name_in){
	name = strdup(name_in);
}


Variable::~Variable(){}

const char* Variable::get_name() const{
	return name;
}


