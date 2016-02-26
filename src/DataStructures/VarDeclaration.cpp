#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(const VarT type_in, vector<Variable>* variables_in) : 
	Statement(stat_var_declaration), type(type_in), variables(variables_in) {}

VarDeclaration::~VarDeclaration(){
	if(variables!=NULL) delete variables;
}


void VarDeclaration::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');

	if(variables==NULL) return;

	// Print the name of variables defined in this Statement
	vector<Variable>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		cout<<white_space<<"VARIABLE : "<<(*it).get_name()<<endl;
	}
}


