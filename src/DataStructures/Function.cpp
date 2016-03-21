#include "Function.h"


Function::Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in) :
	return_type(return_type_in), params(params_in), fn_body(fn_body_in){
	name=strdup(name_in);
}

Function::Function(Variable* return_type_in, char* name_in, vector<Variable*>* params_in, CompoundStatement* fn_body_in, 
																			const int& line_in, const string& src_file_in) :
	return_type(return_type_in), params(params_in), fn_body(fn_body_in), line(line_in), src_file(src_file_in) {
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
	if(return_type!=NULL) delete return_type;
	free(name);
}

string Function::get_name() const{
	return string(name);
}

void Function::generate_error(const string& msg_out) const{
	cerr<<endl;
  	cerr<<"========================================= ERROR ========================================="<<endl;
  	cerr<<endl;
	//if(src_file.empty()) 	cerr<<"Error in source file at line ";
	//else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<"Error : "<<msg_out<<" \""<<name<<"\""<<endl;
	exit(EXIT_FAILURE);
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

void Function::renderasm(ASMhandle& context){
	if(debug) cerr<<"Function: renderasm start"<<endl;

	/* Function header assembly */
	assembler.push_back(ss<<"\t.align	2"<<endl);
	assembler.push_back(ss<<"\t.globl "<<name<<endl);		// This has to be ommitted for functions declared static
	assembler.push_back(ss<<"\t.ent "<<name<<endl);
	assembler.push_back(ss<<"\t.type "<<name<<", @function"<<endl);
	assembler.push_back(ss<<name<<":"<<endl);

	ASMhandle new_context(context);

	new_context.subroutine_enter();

	init_args(new_context);

	if(debug) cerr<<"Function: renderasm of parameters successful"<<endl;

	if(fn_body!=NULL) fn_body->renderasm(new_context, true);
	else	context.subroutine_exit(NULL);

	if(debug) cerr<<"Function: renderasm of body successful"<<endl;
	
	/* Function end assembly */
	assembler.push_back(ss<<endl<<"\t.end "<<name<<endl<<endl);
}



void Function::init_args(ASMhandle& context){
	if(params==NULL) return;

	// Repair - put arguments on the stack and account for arguments bigger than 32bits
	for(int i=0; i<params->size() && i<4; i++){
		try{
			pair<string, Variable*> tmp((*params)[i]->get_name_str(), (*params)[i]);
			char* asm_location = context.allocate_var(tmp);
			(*params)[i]->set_asm_location(asm_location);
			assembler.push_back(ss<<pad<<"sw"<<"$a"<<i<<", "<<asm_location<<endl);
		}
		catch(const ErrorgenT& error_in){
			(*params)[i]->generate_error("Function parameters cannot have the same name");
		}
	}

	for(int i=4; i<params->size(); i++){
		pair<string, Variable*> tmp((*params)[i]->get_name_str(), (*params)[i]);
		try{
			char* asm_location=context.allocate_subroutine_stack_param(tmp);
			(*params)[i]->set_asm_location(asm_location);
		}
		catch(const ErrorgenT& error_in){
			(*params)[i]->generate_error("Function parameters cannot have the same name");
		}
	}
}