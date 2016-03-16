#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BaseExpression.h"
#include "Constant.h"
#include <string.h>


/*	REQUIRED FIXES:
		1. Support for all types of variables
		2. Cast variables and manage the returned struct properly
		3. Operators not yet supported: all pointer related such as . -> & * and sizeof
*/	


class Expression : public BaseExpression{

public:
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const ExprT& expr_type_in);
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const ExprT& expr_type_in, 
																			const int& line_in, const string& src_file_in);
	
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in);
	Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const int& line_in, const string& src_file_in);
	virtual ~Expression();

	void set_lhs(Expression* lhs_in);	
	void set_rhs(Expression* rhs_in);

	virtual BaseExpression* simplify(snum_t& value);
	void pretty_print(const int& indent);
	virtual void renderasm(ASMhandle& context, char** destination=NULL);

protected:
	string gen_error() const;
	/*void arithmetic_ins(char* instruction, char* destination, char* arg1, char* arg2);
	void logical_or_ins(char* destination, char* arg1, char* arg2);
	void logical_comparison_ins(char* instruction, char* destination, char* arg1,
																			char* arg2, const bool& subtract=true);
	*/
	void arithmetic_ins(char* destination, char* arg1, char* arg2, const string& instruction);
	void logical_or_ins(ASMhandle& context, char* destination, char* arg1, char* arg2);
	void logical_and_ins(ASMhandle& context, char* destination, char* arg1, char* arg2);
	void logical_not_ins(ASMhandle& context, char* destination, char* arg);
	void logical_comparison_ins(ASMhandle& context, char* destination, char* arg1, char* arg2, const string& instruction, const bool& subtract=true);
	void sign_ins(char* destination, char* arg, const bool& get_negative);


	char* oper;
	BaseExpression* lhs;
	BaseExpression* rhs;
};


#endif

