#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "BaseExpression.h"
#include "Constant.h"
#include "Temporary.h"
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

	virtual BaseExpression* simplify();
	virtual void pretty_print(const int& indent);
	virtual void renderasm(ASMhandle& context, ExprResult** dest=NULL);

protected:
	
	/* ---------------------------------------------- ARITHMETIC INSTRUCTIONS ---------------------------------------------- */
	void arithmetic_ins			(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction);
	void div_rem_ins 			(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction);
	
	/* ---------------------------------------------- LOGICAL INSTRUCTIONS ---------------------------------------------- */
	void logical_or_ins 		(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context);
	void logical_and_ins 		(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context);
	void logical_not_ins 		(ExprResult* dest, ExprResult* arg, ASMhandle& context);
	void logical_comparison_ins (ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context,
																		const string& instruction, const bool& subtract=true);
	
	/* ---------------------------------------------- SINGLE OPERAND ---------------------------------------------- */
	void sign_ins 				(ExprResult* dest, ExprResult* arg, const bool& get_negative);
	void bitwise_not_ins 		(ExprResult* dest, ExprResult* arg);
	void sizeof_ins 			(ExprResult* dest, ExprResult* arg);


	char* oper;
	BaseExpression* lhs;
	BaseExpression* rhs;
};


#endif

