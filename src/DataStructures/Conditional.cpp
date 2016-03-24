#include "Conditional.h"


ConditionalCase::ConditionalCase(CompoundStatement* block_statement_in, BaseExpression* condition_in) :
	Statement(ST_conditional_case), single_statement(NULL), block_statement(block_statement_in), condition(condition_in) {}

ConditionalCase::ConditionalCase(Statement* single_statement_in, BaseExpression* condition_in) :
	Statement(ST_conditional_case), single_statement(single_statement_in), block_statement(NULL), condition(condition_in) {}


ConditionalCase::ConditionalCase(CompoundStatement* block_statement_in, BaseExpression* condition_in, const int& line_in, 
	const string& src_file_in) : Statement(ST_conditional_case, line_in, src_file_in), single_statement(NULL), 
	block_statement(block_statement_in), condition(condition_in) {}

ConditionalCase::ConditionalCase(Statement* single_statement_in, BaseExpression* condition_in, const int& line_in, 
	const string& src_file_in) : Statement(ST_conditional_case, line_in, src_file_in), single_statement(single_statement_in), 
	block_statement(NULL), condition(condition_in) {}



ConditionalCase::~ConditionalCase(){
	if(condition!=NULL) delete condition;
	if(single_statement!=NULL) delete single_statement;
	if(block_statement!=NULL) delete single_statement;

}

void ConditionalCase::pretty_print(const int& indent){
	if(single_statement!=NULL)	single_statement->pretty_print(indent);
	if(block_statement!=NULL)	block_statement->pretty_print(indent);
}

void ConditionalCase::renderasm(ASMhandle& context){}

// NOTE: single_statements must not copy context. Possible single_statements are Loop, Conditional, ExpressionStatement, 
// ReturnStatement, VarDeclaration. Last three don't do it. ConditionalCase and Loop will restore their own stack pointers,
// so you should not be worried
void ConditionalCase::renderasm(ASMhandle& context, const string& continued_execution, const string& next_jump){
	if(debug) cerr<<"ConditionalCase: renderasm enter"<<endl;

	ASMhandle new_context(context);
	
	// IF or ELSE IF; NOTE that bison will not parse sth invalid such as if() else if() do sth;
	if(condition!=NULL){
		ExprResult** result_condtion = new ExprResult*(NULL);
		condition->renderasm(context, result_condtion);

		(*result_condtion)->load("$t0");

		// If condition is false jump to the next CondtionalCase or to the end of the Conditional
		if(!next_jump.empty()) 	assembler.push_back(ss<<pad<<"beq"<<"$t0, $0, "<<next_jump<<endl);		 
		else 					assembler.push_back(ss<<pad<<"beq"<<"$t0, $0, "<<continued_execution<<endl);	
		context.exit_scope(new_context);				// Correct $sp in branch delay slot if necessary
		
		// IF/ELSE IF COMPOUND STATEMENT
		if(block_statement!=NULL)	block_statement->renderasm(new_context, false);
		// IF/ELSE IF single statement
		else						single_statement->renderasm(new_context);
		
		assembler.push_back(ss<<pad<<"b"<<continued_execution<<endl);		// Branch to continued execution
		context.exit_scope(new_context);				// Correct $sp in branch delay slot if necessary
	}
	// ELSE or ELSE IF statement
	else{
		// ELSE COMPOUND STATEMENT
		if(block_statement!=NULL){
			// else statement not the last in a condition - generate error
			if(!next_jump.empty()) generate_error("More conditions after the default, i.e. after \"else\", are not allowed");
			block_statement->renderasm(new_context, false);
			context.exit_scope(new_context);				// Correct $sp before reaching the end of the condition
		}
		
		// single_statement!=NULL && condition==NULL => ELSE/ELSE IF single statement
		else{
			// ELSE IF statement; NOTE: This CANNOT be else else statement - will not be parsed by bison
			if(single_statement->get_stat_type()==ST_conditional_case){
				ConditionalCase* else_if_stat = dynamic_cast<ConditionalCase*>(single_statement);
				else_if_stat->renderasm(context, continued_execution, next_jump);
			}
			// ELSE single statement
			else{
				if(!next_jump.empty()) generate_error("More conditions after the default, i.e. after \"else\", are not allowed");
				single_statement->renderasm(new_context);
				context.exit_scope(new_context);				// Correct $sp before reaching the end of the condition
			}
		}
	}

	if(debug) cerr<<"ConditionalCase: renderasm successful"<<endl;
}



Conditional::Conditional(vector<ConditionalCase*>* conditions_in) : Statement(ST_conditional), conditions(conditions_in) {}

Conditional::Conditional(vector<ConditionalCase*>* conditions_in, const int& line_in, const string& src_file_in) :
	Statement(ST_conditional, line_in, src_file_in), conditions(conditions_in) {}

Conditional::~Conditional(){
	if(conditions!=NULL){
		vector<ConditionalCase*>::iterator it;
		for(it=conditions->begin(); it!=conditions->end(); ++it){
			delete *it;
		}
		delete conditions;
	}
}


void Conditional::pretty_print(const int& indent){
	vector<ConditionalCase*>::iterator it;
	for(it=conditions->begin(); it!=conditions->end(); ++it){
		if(*it!=NULL) (*it)->pretty_print(indent);
	}

}


void Conditional::renderasm(ASMhandle& context){
	if(debug) cerr<<"Conditional: renderasm enter"<<endl;
	
	string continued_execution = context.get_assembly_label();
	string jump_next;
	if(conditions->size()==1){
		(*conditions)[0]->renderasm(context, continued_execution, "");
	} 	
	else{
		vector<ConditionalCase*>::iterator it, it_end;
		it_end=conditions->end();
		--it_end;
		for(it=conditions->begin(); it!=conditions->end(); ++it){
			if(it!=it_end){
				jump_next=context.get_assembly_label();
				// jump_next is the label to jump if condition is not true, i.e. the next else if
				// continued_execution it the label to jump after executing the block in the case that the condition evaluates to true
				(*it)->renderasm(context, continued_execution, jump_next);
				assembler.push_back(ss<<jump_next<<":"<<endl);
			}
			// Last ELSE/ELSE IF statement
			else (*it)->renderasm(context, continued_execution, "");
		}
	}

	if(debug) cerr<<"Conditional: renderasm successful"<<ss.str()<<endl;

	assembler.push_back(ss<<continued_execution<<":"<<endl);
}
