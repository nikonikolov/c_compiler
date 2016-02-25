#include "Function.h"


Function::Function(const VarT& return_type_in, char* name_in) :
	return_type(return_type_in){
	name=name_in;
}

Function::Function(const VarT& return_type_in, char* name_in, list<Variable>* params_in) :
	return_type(return_type_in), params(params_in) {
	name=name_in;
}

Function::~Function(){
	delete params;
}

void Function::pretty_print(const int& indent) const{
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"FUNCTION : "<<name<<endl;
	if(params!=NULL){
		list<Variable>::iterator it;
		for(it =(*params).begin(); it!=(*params).end(); ++it){
			cout<<white_space<<new_scope_indent<<"PARAM : "<<(*it).get_name()<<endl;
		}
	} 
	cout<<white_space<<"SCOPE"<<endl;
}


