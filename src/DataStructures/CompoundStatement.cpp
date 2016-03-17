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

void CompoundStatement::pretty_print(const int& indent){
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

	ASMhandle new_context(context);

	
	if(declarations!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			(*it)->renderasm(new_context, true);
		}
	}
	cerr<<"VarDeclaration done"<<endl;

	new_context.redefinition_check();

	// Initialize uninitialized variables	
	/*if(new_context.local_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=(new_context.local_vars)->begin(); it!=(new_context.local_vars)->end(); ++it){
			if(!((*it).second->get_initialized())) (*it).second->renderasm(new_context);
		}
	}*/

	// Execute the statements
	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			(*it)->renderasm(new_context);
		}
	}
}
