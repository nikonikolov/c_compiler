#include "Program.h"

Program::Program() :
	global_vars(NULL), functions(NULL), context(NULL) {}

Program::Program(vector<VarDeclaration*>* global_vars_in, vector<Function*>* functions_in) :
	global_vars(global_vars_in), functions(functions_in), context(NULL) {}


Program::~Program(){
	if(global_vars!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars->begin(); it!=global_vars->end(); ++it){
			delete *it;
		}

		delete global_vars;
	}

	if(functions!=NULL){
		vector<Function*>::iterator it;
		for(it=functions->begin(); it!=functions->end(); ++it){
			delete *it;
		}

		delete functions;
	}
}

void Program::push_fn_back(Function* fn_in){
	if(functions==NULL) functions = new vector<Function*>;
	functions->push_back(fn_in);
}

void Program::push_var_back(VarDeclaration* var_in){
	if(global_vars==NULL) global_vars = new vector<VarDeclaration*>;
	global_vars->push_back(var_in);
}


void Program::pretty_print(const int& indent) const{

	if(global_vars!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=global_vars->begin(); it!=global_vars->end(); ++it){
			if(*it!=NULL) (*it)->pretty_print(indent);
		}
	} 

	if(functions==NULL) return;

	// Print Function declarations
	vector<Function*>::iterator it;
	for(it=functions->begin(); it!=functions->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent);
	}
}



