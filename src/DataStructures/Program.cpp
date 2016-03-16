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
  	if (ret.second==false) fn_in->generate_error();
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
	/*// Repair the following loop. You have to create global_vars and the vars inside need to know they are global vars. You might 
	// be able to do it without the Variable knowing it's global by defining a member function that renders assembly for global var
	if(global_vars_decl!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars_decl->begin(); it!=global_vars_decl->end(); ++it){
			if(*it!=NULL) (*it)->pretty_print(indent);
		}
	} 
	// Here will be the point to perform semantics check and make sure no function name matches a variable name. You can also try
	// doing it when you traverse the vectors

	// Initialize assembly names for both functions and global variables
	if(functions!=NULL){
		vector<Function*>::iterator it;
		for(it=functions->begin(); it!=functions->end(); ++it){
			(*it)->init_asm_name(indent);
		}
	}
	if(global_vars!=NULL){
		vector<Variable*>::iterator it;
		for(it=global_vars->begin(); it!=global_vars->end(); ++it){
			(*it)->init_asm_name(indent);
		}
	}
*/
}

