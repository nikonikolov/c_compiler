#include "CompoundStatement.h"

CompoundStatement::CompoundStatement(vector<VarDeclaration*>* declarations_in, vector<Statement*>* statements_in) :
	Statement(ST_compound), declarations(declarations_in), statements(statements_in) {
}


CompoundStatement::~CompoundStatement(){
	if(declarations!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			delete *it;
		}

		delete declarations;
	}

	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			delete *it;
		}

		delete statements;
	}
}

void CompoundStatement::pretty_print(const int& indent) const{
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"SCOPE"<<endl;

	if(declarations==NULL && statements==NULL) return;

	if(declarations!=NULL){
		// Print Variable Declarations defined inside the CompoundStatement
		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			if(*it!=NULL) (*it)->pretty_print(indent+4);
		}
	}

	if(statements!=NULL){
		// Print Statements defined inside the CompoundStatement
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			if(*it!=NULL) (*it)->pretty_print(indent+4);
		}
	}
}


void CompoundStatement::renderasm(ASMhandle& context){
}

void CompoundStatement::renderasm(vector<Variable*>* vars_in, int& stack_offset){
	vector<Variable*>* local_vars;

	if(declarations!=NULL){
		local_vars = new vector<Variable*>;

		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			(*it)->renderasm(local_vars);
		}
	}


	// At this point local_vars contains a vector of all locally declared variables
	// vars_in contains the parameters of the function or variables visible from the parent scope

	// This will be a good point to make sure no redefinition occurs



}
