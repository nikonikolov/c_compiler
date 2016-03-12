#include "Function.h"

Function::Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, vector<Statement*>* statements_in) :
	Statement(ST_fn_def), return_type(return_type_in), params(params_in), statements(statements_in) {
	name=strdup(name_in);
}

Function::~Function(){
	if(params!=NULL){
		vector<Variable*>::iterator it;
		for(it=params->begin(); it!=params->end(); ++it){
			delete *it;
		}

		delete params;
	}

	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			delete *it;
		}

		delete statements;
	}
}

void Function::pretty_print(const int& indent) const{
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"FUNCTION : "<<name<<endl;
	if(params!=NULL){
		vector<Variable*>::iterator it;
		for(it=params->begin(); it!=params->end(); ++it){
			cout<<white_space<<new_scope_indent<<"PARAM : "<<(*it)->get_name()<<endl;
		}
	} 
	cout<<white_space<<"SCOPE"<<endl;

	if(statements==NULL) return;

	// Print variables and statements defined inside the function
	vector<Statement*>::iterator it;
	for(it=statements->begin(); it!=statements->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent+4);
	}
}


void Function::renderasm(){
	/* Function header assembly */
	cout<<"\t.align	2"<<endl;
	cout<<"\t.globl "<<name<<endl;		// This has to be ommitted for functions declared static
	cout<<"\t.ent "<<name<<endl;
	cout<<"\t.type "<<name<<", @function"<<endl;



	/* Function end assembly */
	cout<<endl<<"\t.end "<<name<<endl<<endl;
}



