#include "AssignmentExpression.h"

/* =============================================== CONSTRUCTION =============================================== */


AssignmentExpression::AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) : 
	Expression(lhs_in, oper_in, rhs_in, EXPR_assignment_expr) {}

AssignmentExpression::AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const int& line_in, 
	const string& src_file_in) : Expression(lhs_in, oper_in, rhs_in, EXPR_assignment_expr, line_in, src_file_in) {}

AssignmentExpression::~AssignmentExpression(){
}


/* =============================================== VIRTUAL METHODS IMPLEMENTATION =============================================== */

void AssignmentExpression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){

	ExprResult** lhs_result = NULL;
	ExprResult** rhs_result = NULL;
	if(lhs!=NULL){
		lhs_result = new ExprResult*(NULL);
		lhs->renderasm(context, lhs_result);
	} 
	if(rhs!=NULL){
		rhs_result = new ExprResult*(NULL);
		rhs->renderasm(context, rhs_result);
	} 

	if(dest!=NULL){
		if(*dest!=NULL) generate_error("Assignment Expression cannot be RHS of another expression");
		*dest = new Temporary(context.allocate_var());
	} 

	if(lhs!=NULL && rhs!=NULL){
		if(!strcmp(oper,"=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result); 	
		if(!strcmp(oper,"+=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "addu"); 	
		if(!strcmp(oper,"-=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "subu"); 	
		if(!strcmp(oper,"|=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "or"); 	
		if(!strcmp(oper,"&=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "and"); 	
		if(!strcmp(oper,"^=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "xor"); 	
		if(!strcmp(oper,"<<=")) assignment_ins 	(dest, *lhs_result, *rhs_result, "sllv"); 	
		if(!strcmp(oper,">>=")) assignment_ins 	(dest, *lhs_result, *rhs_result, "srav"); 	

		if(!strcmp(oper,"*=")) 	assignment_ins 	(dest, *lhs_result, *rhs_result, "mul"); 	
		if(!strcmp(oper,"%=")) 	div_rem_ins 	(dest, *lhs_result, *rhs_result, "mfhi"); 	
		if(!strcmp(oper,"/=")) 	div_rem_ins 	(dest, *lhs_result, *rhs_result, "mflo"); 	

	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins 	(dest, *rhs_result, 1, false);
		if(!strcmp(oper,"--")) 	inc_dec_ins 	(dest, *rhs_result, -1, false);
	}
	if(lhs!=NULL && rhs==NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins 	(dest, *lhs_result, 1, true);
		if(!strcmp(oper,"--")) 	inc_dec_ins 	(dest, *lhs_result, -1, true);
	}

	if(lhs_result!=NULL) {
		if((*lhs_result)->get_result_type()==RESULT_tmp) delete *lhs_result;
		delete lhs_result;
	}
	if(rhs_result!=NULL){
		if((*rhs_result)->get_result_type()==RESULT_tmp) delete *rhs_result;
		delete rhs_result;
	} 
}

/* =============================================== CODEGEN METHODS =============================================== */

void AssignmentExpression::assignment_ins(ExprResult** dest, ExprResult* lhs_result, ExprResult* rhs_result, 
																								const string& instruction /*=""*/){
	bool lhs_loaded=true;

	// Arithmetic operation required
	if(!instruction.empty()) arithmetic_ins(lhs_result, rhs_result, instruction);
	// Simple assignment
	else{
		rhs_result->load("$t2");
		lhs_loaded=false;
	} 

	lhs_result->store("$t2");
	if(dest!=NULL)	(*dest)->store("$t2");
}

void AssignmentExpression::arithmetic_ins(ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction){
	lhs_result->load("$t0");
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<instruction<<"$t2, $t0, $t1"<<endl);
}

void AssignmentExpression::inc_dec_ins(ExprResult** dest, ExprResult* arg, const int& val, const bool& post_inc){
	arg->load("$t0");
	
	if(dest!=NULL && post_inc) 	(*dest)->store("$t0");					// Assign the old value to the destination
	assembler.push_back(ss<<pad<<"addiu"<<"$t0, $t0, "<<val<<endl);
	
	arg->store("$t0");													// Assign the new value to the variable
	if(dest!=NULL && !post_inc) (*dest)->store("$t0");					// Assign the new value to the destination
}

void AssignmentExpression::div_rem_ins(ExprResult** dest, ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction){
	lhs_result->load("$t0");
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<"teq"<<"$t1, $0, 7"<<endl);
	assembler.push_back(ss<<pad<<"div"<<"$t0, $t1"<<endl);
	assembler.push_back(ss<<pad<<instruction<<"$t2"<<endl);
	lhs_result->store("$t2");
	if(dest!=NULL)	(*dest)->store("$t2");
}



