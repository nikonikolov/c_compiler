#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include "include.h"
#include "Statement.h"

class BaseExpression{

public:
	BaseExpression(const ExprT& expr_type_in);
	BaseExpression(const ExprT& expr_type_in, const int& line_in, const string& src_file_in);
	virtual ~BaseExpression();

	virtual void pretty_print(const int& indent) =0;		// parameter specifies the starting column for the printing
	virtual void renderasm(ASMhandle& context, char** destination=NULL)=0;
	virtual BaseExpression* simplify(snum_t& value) =0;

	virtual void generate_error();

protected:
	ExprT expr_type;	
	int line;
	string src_file;
};



#endif

