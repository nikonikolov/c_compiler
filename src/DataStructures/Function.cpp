#include "Function.h"


Function::Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in) :
	return_type(return_type_in), params(params_in), fn_body(fn_body_in){
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

	if(fn_body!=NULL) delete fn_body;
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

	if(fn_body!=NULL) fn_body->pretty_print(indent);

}


void Function::renderasm(){
	/* Function header assembly */
	cout<<"\t.align	2"<<endl;
	cout<<"\t.globl "<<name<<endl;		// This has to be ommitted for functions declared static
	cout<<"\t.ent "<<name<<endl;
	cout<<"\t.type "<<name<<", @function"<<endl;
	cout<<name<<":"<<endl;


	/* Function end assembly */
	cout<<endl<<"\t.end "<<name<<endl<<endl;
}


/*
void Function::prep_for_asm(){

	vector<Statement*>::iterator it;
	for(it=statements->begin(); it!=statements->end() || (*it)->get_stat_type==var_declaration_container ; ++it){
		
	}
}*/