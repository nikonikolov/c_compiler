#include "Program.h"

Program::Program() :
	global_vars_decl(NULL), functions(NULL), context(NULL), global_vars(NULL) {}

/*
Program::Program(vector<VarDeclaration*>* global_vars_decl_in, vector<Function*>* functions_in) :
	global_vars_decl(global_vars_decl_in), functions(functions_in), context(NULL), global_vars(NULL) {}
*/

Program::~Program(){
	if(global_vars_decl!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars_decl->begin(); it!=global_vars_decl->end(); ++it){
			delete *it;
		}

		delete global_vars_decl;
	}

	if(functions!=NULL){
		map<string, Function*>::iterator it;
		for(it=functions->begin(); it!=functions->end(); ++it){
			delete (*it).second;
		}

		delete functions;
	}

	if(global_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=global_vars->begin(); it!=global_vars->end(); ++it){
			delete (*it).second;
		}

		delete global_vars;
	}
}

void Program::insert_fn(Function* fn_in){
	if(functions==NULL) functions = new map<string, Function*>;
	
	pair<map<string, Function*>::iterator,bool> ret;
  	ret = functions->insert( pair<string, Function*>(fn_in->get_name(),fn_in) );
  	if(ret.second==false) fn_in->generate_error("redefinition of function");
}

void Program::push_var_back(VarDeclaration* var_in){
	if(global_vars_decl==NULL) global_vars_decl = new vector<VarDeclaration*>;
	global_vars_decl->push_back(var_in);
}


void Program::pretty_print(const int& indent){

	if(global_vars_decl!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars_decl->begin(); it!=global_vars_decl->end(); ++it){
			if(*it!=NULL) (*it)->pretty_print(indent);
		}
	} 

	if(functions==NULL) return;

	// Print Function declarations
	map<string, Function*>::iterator it;
	for(it=functions->begin(); it!=functions->end(); ++it){
		(*it).second->pretty_print(indent);
	}
}


void Program::renderasm(){

	// Create ASMhandle that manages the stack and the function calls
	ASMhandle context(functions);
	
	// Render assembly for global variables. Note that name clashes with functions are performed at insertion
	if(global_vars_decl!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars_decl->begin(); it!=global_vars_decl->end(); ++it){
			(*it)->renderasm(context, false);
		}
	} 

	cout<<pad<<".text"<<endl;
	
	if(functions!=NULL){
		map<string, Function*>::iterator it;
		// Render assembly for functions	
		for(it=functions->begin(); it!=functions->end(); ++it){
			(*it).second->renderasm(context);
		}
	}

	cerr<<"Code Generation Successful"<<endl;
}

