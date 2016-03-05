#include "Variable.h"

/*
Variable::Variable(const VarT& var_type_in, char* token_val_in, char* name_in) :
	Expression(stat_var_declaration), var_type(var_type_in){
		name = strdup(name_in);
		token_val = strdup(token_val_in);
}
*/
Variable::Variable(const VarT& var_type_in, char* name_in) :
	Expression(stat_var_declaration), var_type(var_type_in){
		name = strdup(name_in);
}

Variable::Variable(char* name_in) : 
	Expression(stat_var_declaration){
	name = strdup(name_in);
}


Variable::~Variable(){}

const char* Variable::get_name() const{
	return name;
}

void Variable::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;
}

