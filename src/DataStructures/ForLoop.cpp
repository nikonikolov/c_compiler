#include "ForLoop.h"

/* =============================================== ForLoopTuple CLASS =============================================== */

ForLoopTuple::ForLoopTuple(vector<BaseExpression*>* mem1_in, vector<BaseExpression*>* mem2_in, vector<BaseExpression*>* mem3_in) :
	mem1(mem1_in), mem3(mem3_in) {
	if(mem2_in!=NULL){
		int last = mem2_in->size()-1;
		mem2 = (*mem2_in)[last];
		for(int i=0; i<last; i++){
			delete (*mem2_in)[i];
		}
		delete mem2_in;
	}
}	

// Not supposed to deallocate the memory
ForLoopTuple::~ForLoopTuple(){}


/* =============================================== ForLoop CLASS =============================================== */

ForLoop::ForLoop(ForLoopTuple* tuple_in, Statement* single_statement_in) :
	Statement(ST_loop), init_block(tuple_in->mem1), condition_block(tuple_in->mem2), update_block(tuple_in->mem3),
	loop_body(NULL), single_statement(single_statement_in) {}

ForLoop::ForLoop(ForLoopTuple* tuple_in, CompoundStatement* loop_body_in) :
	Statement(ST_loop), init_block(tuple_in->mem1), condition_block(tuple_in->mem2), update_block(tuple_in->mem3),
	loop_body(loop_body_in), single_statement(NULL) {}


ForLoop::~ForLoop(){
	if(loop_body!=NULL) 		delete loop_body;
	if(single_statement!=NULL) 	delete single_statement;
	if(init_block!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=init_block->begin(); it!=init_block->end(); ++it){
			delete *it;
		}
		delete init_block;
	} 	
	if(update_block!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=update_block->begin(); it!=update_block->end(); ++it){
			delete *it;
		}
		delete update_block;
	} 	
	if(condition_block!=NULL) 	delete condition_block;
}


void ForLoop::pretty_print(const int& indent){
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"FOR LOOP"<<endl;

	cout<<white_space<<"INIT BLOCK: ";
	if(init_block!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=init_block->begin(); it!=init_block->end(); ++it){
			(*it)->pretty_print(0);
		}
		cout<<endl;
	} 	

	cout<<white_space<<"CONDITION BLOCK: ";
	if(condition_block!=NULL) condition_block->pretty_print(0);
	cout<<endl;

	cout<<white_space<<"UPDATE BLOCK: ";
	if(update_block!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=update_block->begin(); it!=update_block->end(); ++it){
			(*it)->pretty_print(0);
		}
		cout<<endl;
	} 	

	if(loop_body!=NULL)	loop_body->pretty_print(indent);
	if(single_statement!=NULL)	single_statement->pretty_print(indent);
}


void ForLoop::renderasm(ASMhandle& context){
	ASMhandle new_context(context);

	string condition_check = new_context.get_assembly_label();
	string loop_body_label = new_context.get_assembly_label();

	// Execute initialize expressions
	vector<BaseExpression*>::iterator it;
	if(init_block!=NULL){
		for(it=init_block->begin(); it!=init_block->end(); ++it){
			(*it)->renderasm(new_context, NULL);
		}
	}

	// Branch to condition check
	assembler.push_back(ss<<pad<<"b"<<condition_check<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<loop_body_label<<":"<<endl);

	// Execute loop body
	if(single_statement!=NULL) single_statement->renderasm(new_context);
	if(loop_body!=NULL) loop_body->renderasm(new_context, false);

	// Execute update statement
	if(update_block!=NULL){
		for(it=update_block->begin(); it!=update_block->end(); ++it){
			(*it)->renderasm(new_context, NULL);
		}
	}

	assembler.push_back(ss<<condition_check<<":"<<endl);

	// Perform condition check
	if(condition_block!=NULL){
		ExprResult** cond_result = new ExprResult*(NULL);
		condition_block->renderasm(new_context, cond_result);
		(*cond_result)->load("$t5");	
		assembler.push_back(ss<<pad<<"bne"<<"$0, $t5, "<<loop_body_label<<endl);
		assembler.push_back(ss<<pad<<"nop"<<endl);
	}

	context.exit_scope(new_context);				// Correct $sp in branch delay slot if necessary
}


