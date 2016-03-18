#include "BaseExpression.h"

BaseExpression::BaseExpression(const ExprT& expr_type_in) : expr_type(expr_type_in) {}

BaseExpression::BaseExpression(const ExprT& expr_type_in, const int& line_in, const string& src_file_in) :
	expr_type(expr_type_in), line(line_in), src_file(src_file_in) {}

BaseExpression::~BaseExpression(){}

ExprT BaseExpression::get_expr_type() const {
	return expr_type;
}


void BaseExpression::generate_error(const string& msg_out){
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : "<<msg_out<<endl;
	exit(EXIT_FAILURE);
}