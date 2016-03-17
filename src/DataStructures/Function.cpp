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

string Function::get_name() const{
	return string(name);
}

void Function::generate_error() const{
	
}


void Function::pretty_print(const int& indent){
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

void Function::init_asm_name(){
	if(strcmp(name,"main")){
		asm_name=strdup("abcdefg");
		strcat(asm_name, name);
	} 
	else asm_name=name;
}

void Function::renderasm(ASMhandle& context){
	// Initialize assembly name
	init_asm_name();

	/* Function header assembly */
	cout<<"\t.align	2"<<endl;
	cout<<"\t.globl "<<asm_name<<endl;		// This has to be ommitted for functions declared static
	cout<<"\t.ent "<<asm_name<<endl;
	cout<<"\t.type "<<asm_name<<", @function"<<endl;
	cout<<asm_name<<":"<<endl;

	ASMhandle new_context(context);

	new_context.subroutine_enter();

	prep_for_asm(new_context);

	new_context.redefinition_check();
		
	fn_body->renderasm(new_context);


	/* Function end assembly */
	cout<<endl<<"\t.end "<<asm_name<<endl<<endl;
}



void Function::prep_for_asm(ASMhandle& context){
	if(params==NULL) return;

	// Repair - put arguments on the stack and account for arguments bigger than 32bits
	for(int i=0; i<params->size() && i<4; i++){
		(*params)[i]->set_asm_location("$a"+std::to_string(i));
		pair<string, Variable*> tmp((*params)[i]->get_name_str() ,(*params)[i]);
		try{
			context.insert_local_var(tmp);
		}
		catch(const ErrorgenT& error_in){
			(*params)[i]->generate_error();
		}
	}

	for(int i=4; i<params->size(); i++){
		pair<string, Variable*> tmp((*params)[i]->get_name_str() ,(*params)[i]);
		try{
			char* tmp_location=context.allocate_var(tmp);
			(*params)[i]->set_asm_location(tmp_location);
		}
		catch(const ErrorgenT& error_in){
			(*params)[i]->generate_error();
		}
	}
}