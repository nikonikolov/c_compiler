#include "Conditional.h"


ConditionalCase::ConditionalCase(vector<Statement*>* statements_in, Statement* condition_in /*= NULL*/) :
	Statement(stat_conditional_case), single_statement(NULL), statements(statements_in), condition(condition_in) {}

ConditionalCase::ConditionalCase(Statement* single_statement_in, Statement* condition_in /*= NULL*/) :
	Statement(stat_conditional_case), single_statement(single_statement_in), statements(NULL), condition(condition_in){}


ConditionalCase::~ConditionalCase(){
	if(condition!=NULL) delete condition;

	if(single_statement!=NULL) delete single_statement;

	if(statements!=NULL){
		vector<Statement*>::iterator it;
		for(it=statements->begin(); it!=statements->end(); ++it){
			delete *it;
		}

		delete statements;
	}
}

void ConditionalCase::pretty_print(const int& indent) const{
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	if(single_statement!=NULL)	single_statement->pretty_print(indent);

	if(statements==NULL) return;

	cout<<white_space<<"SCOPE"<<endl;
	// Print variables and statements defined inside the Loop
	vector<Statement*>::iterator it;
	for(it=statements->begin(); it!=statements->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent+4);
	}
}



Conditional::Conditional(vector<ConditionalCase*>* conditions_in) : Statement(stat_conditional), conditions(conditions_in) {}

Conditional::~Conditional(){
	//if(conditions!=NULL) delete conditions;

	if(conditions!=NULL){
		vector<ConditionalCase*>::iterator it;
		for(it=conditions->begin(); it!=conditions->end(); ++it){
			delete *it;
		}

		delete conditions;
	}
}


void Conditional::pretty_print(const int& indent) const{
	vector<ConditionalCase*>::iterator it;
	for(it=conditions->begin(); it!=conditions->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent);
	}

}
