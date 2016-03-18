#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(BaseExpression* return_expr_in /*=NULL*/) : Statement(ST_return), return_expr(return_expr_in){}
ReturnStatement::ReturnStatement(BaseExpression* return_expr_in, const int& line_in, const string& src_file_in) : 
	Statement(ST_return, line_in, src_file_in), return_expr(return_expr_in){}

ReturnStatement::~ReturnStatement(){
	if(return_expr!=NULL) delete return_expr;
}


void ReturnStatement::pretty_print(const int& indent){
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<"RETURN ";
	if(return_expr!=NULL)	return_expr->pretty_print(0);
	cout<<endl;
}


void ReturnStatement::renderasm(ASMhandle& context){
	char* destination = context.allocate_var();
	if(return_expr!=NULL) return_expr->renderasm(context, &destination);
	context.subroutine_exit(destination);
}


