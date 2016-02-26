#include "Loop.h"

Loop::Loop(vector<Statement*>* statements_in) : Statement(stat_loop), statements(statements_in), single_statement(NULL) {}
Loop::Loop(Statement* single_statement_in) : Statement(stat_loop), statements(NULL), single_statement(single_statement_in) {}

Loop::~Loop(){
	if(single_statement!=NULL) delete single_statement;

	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			delete *it;
		}
		delete statements;
	}
}


void Loop::pretty_print(const int& indent) const{
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	if(single_statement!=NULL)	single_statement->pretty_print(indent);

	cout<<white_space<<"SCOPE"<<endl;

	if(statements==NULL) return;

	// Print variables and statements defined inside the Loop
	vector<Statement*>::iterator it;
	for(it=statements->begin(); it!=statements->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent+4);
	}
}


