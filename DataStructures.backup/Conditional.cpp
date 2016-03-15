#include "Conditional.h"


ConditionalCase::ConditionalCase(CompoundStatement* block_statement_in, BaseExpression* condition_in /*= NULL*/) :
	Statement(ST_conditional_case), single_statement(NULL), block_statement(block_statement_in), condition(condition_in) {}

ConditionalCase::ConditionalCase(Statement* single_statement_in, BaseExpression* condition_in /*= NULL*/) :
	Statement(ST_conditional_case), single_statement(single_statement_in), block_statement(NULL), condition(condition_in) {}



ConditionalCase::~ConditionalCase(){
	if(condition!=NULL) delete condition;
	if(single_statement!=NULL) delete single_statement;
	if(block_statement!=NULL) delete single_statement;

}

void ConditionalCase::pretty_print(const int& indent) const{
	if(single_statement!=NULL)	single_statement->pretty_print(indent);
	if(block_statement!=NULL)	block_statement->pretty_print(indent);
}


void ConditionalCase::renderasm(ASMhandle& context){
}



Conditional::Conditional(vector<ConditionalCase*>* conditions_in) : Statement(ST_conditional), conditions(conditions_in) {}

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


void Conditional::renderasm(ASMhandle& context){
}
