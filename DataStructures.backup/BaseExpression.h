#ifndef BASEEXPRESSION_H
#define BASEEXPRESSION_H

#include <vector>
#include <list>
#include <iomanip>
#include <iostream>
//#include "ASMhandle.h"

using std::list;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

enum ExprT{
	//EXPR_fn_call = 3,
	
	EXPR_expression = 20,
	EXPR_expr_statement = 21,
	EXPR_constant = 22,
	EXPR_var = 24,
	EXPR_ternery_expr = 28
};

union unum_t{
	long double ldoubleval;
	double 	doubleval;
	float 	floatval;
	int 	intval;
};

// NOTE: Order by precedence
enum enumt{
	tldouble = 100,
	tdouble = 98,
	tfloat = 96,
	tint = 80
};

struct snum_t{
	enumt tname;	// identifies which member the union currently employs
	unum_t number;	// the union itself
};





class BaseExpression{

public:
	BaseExpression(const ExprT& expr_type_in);
	//BaseExpression(BaseExpression* expr_ptr_in);
	virtual ~BaseExpression();

	virtual void pretty_print(const int& indent) const =0;		// parameter specifies the starting column for the printing
	virtual void renderasm(ASMhandle* context)=0;

	// Not const =0 because at evaluation, there might be optimizations and reductions to be done
	// Uncomment for Codegen
	//virtual snum_t eval()=0;
protected:
	ExprT expr_type;
};



#endif

