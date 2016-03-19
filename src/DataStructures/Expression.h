#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BaseExpression.h"
#include "Constant.h"
#include <string.h>


/*	REQUIRED FIXES:
		1. Support for all types of variables
		2. Cast variables and manage the returned struct properly
		3. Operators not yet supported: all pointer related such as . -> & * and sizeof. Note that [] translates to a variable
		4. Sizeof operator returning constant result
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

	BaseExpression* simplify(snum_t& value);
	void pretty_print(const int& indent);
	virtual void renderasm(ASMhandle& context, char** destination=NULL);

protected:
	void load_lhs(char* arg, const string& dest_reg, const string& lhs_reg ="$t8");
	void load_rhs(char* arg, const string& dest_reg, const string& rhs_reg ="$t9");


	void arithmetic_ins(char* destination, char* arg1, char* arg2, const string& instruction);
	void logical_or_ins(ASMhandle& context, char* destination, char* arg1, char* arg2);
	void logical_and_ins(ASMhandle& context, char* destination, char* arg1, char* arg2);
	void logical_not_ins(ASMhandle& context, char* destination, char* arg);
	void logical_comparison_ins(ASMhandle& context, char* destination, char* arg1, char* arg2, const string& instruction, 
																									const bool& subtract=true);
	void div_rem_ins(char* destination, char* arg1, char* arg2, const string& instruction);
	void sign_ins(char* destination, char* arg, const bool& get_negative);
	void bitwise_not_ins(char* destination, char* arg);
	void sizeof_ins(char* destination, char* arg);


	char* oper;
	BaseExpression* lhs;
	BaseExpression* rhs;

	bool lhs_global;
	bool rhs_global;
};


#endif

