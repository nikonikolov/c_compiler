#include "DereferenceExpression.h"

// Memory leak at strdup
DereferenceExpression::DereferenceExpression(BaseExpression* expr_in, const int& line_in, const string& src_file_in) :
	Expression(NULL, strdup("*"), expr_in, EXPR_dereference_expr, line_in, src_file_in) {}

DereferenceExpression::~DereferenceExpression(){}

void DereferenceExpression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
	if(dest==NULL) return;

	if(rhs->get_expr_type()==EXPR_expression){
		Expression* tmp = static_cast<Expression*>(rhs);
		tmp->fix_dereference();
	}
/*	else if(rhs->get_expr_type()!=EXPR_tmp_var){
		generate_error("Invalid dereference argument");
	}
*/
	ExprResult** mem_location = new ExprResult*(NULL);
	rhs->renderasm(context, mem_location);
	
	if(*dest==NULL)	*dest = new Pointer(*mem_location, context); 		

	// *dest!=NULL when renderasm is called by a Variable at the time of assigning new value to it
	else{
		(*mem_location)->load("$t0");
		assembler.push_back(ss<<pad<<"lw"<<"$t1, 0($t0)"<<endl);
		(*dest)->store("$t1");
	}


	if((*mem_location)->get_result_type()==RESULT_tmp ||(*mem_location)->get_result_type()==RESULT_ptr) delete *mem_location;
	delete mem_location;
}


