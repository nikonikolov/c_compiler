#include "CompoundStatement.h"

CompoundStatement::CompoundStatement(vector<VarDeclaration*>* declarations_in, vector<Statement*>* statements_in) :
	Statement(ST_compound), declarations(declarations_in), statements(statements_in) {
}
	
CompoundStatement::CompoundStatement(vector<VarDeclaration*>* declarations_in, vector<Statement*>* statements_in, 
																	const int& line_in, const string& src_file_in) :
	Statement(ST_compound, line_in, src_file_in), declarations(declarations_in), statements(statements_in) {}


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


// Used by single scope appearing without any other statement. It should copy the context and call exit_scope to restore proper
// $sp on its own
void CompoundStatement::renderasm(ASMhandle& context){
	if(debug) cerr<<"CompoundStatement: renderasm enter"<<endl;

	ASMhandle new_context(context);

	if(declarations!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			(*it)->renderasm(new_context, true);
		}
	}

	if(debug) cerr<<"CompoundStatement: renderasm declarations successful"<<endl;

	// Execute the statements
	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			(*it)->renderasm(new_context);
		}
	}

	if(debug) cerr<<"CompoundStatement: renderasm statements successful"<<endl;

	context.exit_scope(new_context);
}

/* For subroutines, conditionals, loops - NOTE that these statements need to appear at the beginning and the end of their renderasm
	ASMhandle new_context(context);
	context.exit_scope(new_context);				// Correct $sp in branch delay slot if necessary
	NOTE: Correction of $sp is performed by the caller for IF/FOR statements
*/
void CompoundStatement::renderasm(ASMhandle& context, const bool& function){

	if(debug) cerr<<"CompoundStatement: renderasm enter"<<endl;

	// Not needed by any of the callers - they copy it on their own
	// ASMhandle new_context(context);

	if(declarations!=NULL){
		vector<VarDeclaration*>::iterator it;
		for(it=declarations->begin(); it!=declarations->end(); ++it){
			(*it)->renderasm(context, true);
		}
	}

	if(debug) cerr<<"CompoundStatement: renderasm declarations successful"<<endl;

	bool return_stat=false;
	// Execute the statements
	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			if((*it)->get_stat_type()==ST_return) return_stat=true;
			(*it)->renderasm(context);
		}
	}

	if(debug) cerr<<"CompoundStatement: renderasm statements successful"<<endl;

	if(!return_stat && function) context.subroutine_exit(NULL);
}

