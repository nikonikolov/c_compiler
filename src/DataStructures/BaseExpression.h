#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include "include.h"
#include "Statement.h"
#include "ExprResult.h"

class BaseExpression{

public:
	BaseExpression(const ExprT& expr_type_in);
	BaseExpression(const ExprT& expr_type_in, const int& line_in, const string& src_file_in);
	virtual ~BaseExpression();

	ExprT get_expr_type() const ;

	virtual void pretty_print(const int& indent) =0;		// parameter specifies the starting column for the printing
	// If expression result is required, dest must be allocated to an ExprResult*(NULL) - note NULL value is obligatory for proper 
	// processing down the tree. However, the function must assign to *dest a meaningful ExprResult object 
	virtual void renderasm(ASMhandle& context, ExprResult** dest=NULL)=0;
	virtual BaseExpression* simplify() =0;

	virtual void generate_error(const string& msg_out);

protected:
	ExprT expr_type;	
	
	int line;
	string src_file;

	stringstream ss;
};



#endif

