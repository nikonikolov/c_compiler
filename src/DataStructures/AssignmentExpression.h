#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H

#include "Expression.h"
#include "Constant.h"
#include <string.h>


/*	REQUIRED FIXES:
		1. Support for all types of variables
		2. Cast variables and manage the returned struct properly
		3. Operators not yet supported: all pointer related such as . -> & * and sizeof
*/	


class AssignmentExpression : public Expression{

public:
	AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in);
	AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, 
																	const int& line_in, const string& src_file_in);
	~AssignmentExpression();

	void renderasm(ASMhandle& context, char** destination=NULL);

private:
	void assignment_ins(char** destination, char* lhs_dest, char* rhs_dest, const string& instruction="");
	void arithmetic_ins(char* lhs_dest, char* rhs_dest, const string& instruction);
	void inc_dec_ins(char** destination, char* arg, const int& val, const bool& post_inc);

};


#endif

