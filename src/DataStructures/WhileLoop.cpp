#include "WhileLoop.h"

WhileLoop::WhileLoop(BaseExpression* condition_in, Statement* single_statement_in, const StatementT& stat_type_in) :
	Statement(stat_type_in), condition(condition_in), loop_body(NULL), single_statement(single_statement_in) {}

WhileLoop::WhileLoop(BaseExpression* condition_in, CompoundStatement* loop_body_in, const StatementT& stat_type_in) :
	Statement(stat_type_in), condition(condition_in), loop_body(loop_body_in), single_statement(NULL) {}


WhileLoop::~WhileLoop(){
	if(loop_body!=NULL) 		delete loop_body;
	if(single_statement!=NULL) 	delete single_statement;
	if(condition!=NULL) 		delete condition;
}


void WhileLoop::pretty_print(const int& indent){
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"WHILE LOOP"<<endl;

	cout<<white_space<<"CONDITION: ";
	if(condition!=NULL) condition->pretty_print(0);
	cout<<endl;

	if(loop_body!=NULL)	loop_body->pretty_print(indent);
	if(single_statement!=NULL)	single_statement->pretty_print(indent);
}


void WhileLoop::renderasm(ASMhandle& context){
	ASMhandle new_context(context);

	string condition_check = new_context.get_assembly_label();
	string loop_body_label = new_context.get_assembly_label();

	if(stat_type==ST_while_loop){
		// Branch to condition check
		assembler.push_back(ss<<pad<<"b"<<condition_check<<endl);
		assembler.push_back(ss<<pad<<"nop"<<endl);
	}
	assembler.push_back(ss<<loop_body_label<<":"<<endl);

	// Execute loop body
	if(single_statement!=NULL) single_statement->renderasm(new_context);
	if(loop_body!=NULL) loop_body->renderasm(new_context, false);

	assembler.push_back(ss<<condition_check<<":"<<endl);

	// Perform condition check
	if(condition==NULL) generate_error("Loop condition must be present");
	ExprResult** cond_result = new ExprResult*(NULL);
	condition->renderasm(new_context, cond_result);
	(*cond_result)->load("$t5");	
	assembler.push_back(ss<<pad<<"bne"<<"$0, $t5, "<<loop_body_label<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);

	context.exit_scope(new_context);				// Correct $sp in branch delay slot if necessary
}


