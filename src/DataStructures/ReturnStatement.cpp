#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(BaseExpression* return_expr_in /*=NULL*/) : Statement(ST_return), return_expr(return_expr_in){}

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
}


