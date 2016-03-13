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


void Function::renderasm(ASMhandle* context){
	/* Function header assembly */
	cout<<"\t.align	2"<<endl;
	cout<<"\t.globl "<<name<<endl;		// This has to be ommitted for functions declared static
	cout<<"\t.ent "<<name<<endl;
	cout<<"\t.type "<<name<<", @function"<<endl;
	cout<<name<<":"<<endl;

	int stack_offset=0;
	prep_for_asm(stack_offset);
	fn_body->renderasm(params, stack_offset);

	/* Function end assembly */
	cout<<endl<<"\t.end "<<name<<endl<<endl;
}



void Function::prep_for_asm(int& stack_offset){
	if(params==NULL) return;

	for(int i=0; i<params->size() && i<4; i++){
		(*params)[i]->set_asm_location("$a"+std::to_string(i));
	}

	for(int i=4; i<params->size(); i++){
		(*params)[i]->set_asm_location(std::to_string((i-3)*4)+"($sp)");
		stack_offset+=4;
	}

}