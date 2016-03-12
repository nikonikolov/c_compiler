#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(vector<Variable*>* variables_in) : 
	Statement(ST_var_declaration_container), variables(variables_in) {}

VarDeclaration::VarDeclaration(char* type_name_in, vector<Variable*>* variables_in) : 
	Statement(ST_var_declaration_container), variables(variables_in) {
	set_types(type_name_in);
}

VarDeclaration::~VarDeclaration(){
	if(variables!=NULL){
		vector<Variable*>::iterator it;
		for(it=variables->begin(); it!=variables->end(); ++it){
			delete *it;
		}
		delete variables;
	}
}


void VarDeclaration::set_types(char* type_name_in){
	if(variables==NULL) return;
	vector<Variable*>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		(*it)->set_type_name(type_name_in);
	}
}


void VarDeclaration::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	if(variables==NULL) return;

	// Print the name of variables defined in this Statement
	vector<Variable*>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		cout<<white_space<<"VARIABLE : "<<(*it)->get_name()<<endl;
	}
}


void VarDeclaration::renderasm(){
	return;
}
