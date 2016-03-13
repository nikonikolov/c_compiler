#include "Loop.h"

Loop::Loop(Statement* loop_statement_in) :
	Statement(ST_loop), loop_body(NULL), loop_statement(loop_statement_in) {}

Loop::Loop(CompoundStatement* loop_body_in) :
	Statement(ST_loop), loop_body(loop_body_in), loop_statement(NULL) {}

Loop::~Loop(){
	if(loop_body!=NULL) delete loop_body;
	if(loop_statement!=NULL) delete loop_statement;
}


void Loop::pretty_print(const int& indent) const{
	if(loop_body!=NULL)	loop_body->pretty_print(indent);
	if(loop_statement!=NULL)	loop_statement->pretty_print(indent);
}


void Loop::renderasm(){
}


