#ifndef VAREXPR_H
#define VAREXPR_H

#include "BaseExpression.h"


/*	Class used to implement Variables appearing in expressions. Note that Variable class cannot be used for this purpose
	because of ASMhandle inclusion in BaseExpression and ASMhandle having Variable as its member
	
*/

class VarExpr : public BaseExpression{

public:
	VarExpr(char* name_in);
	~VarExpr();
	const char* VarExpr::get_name() const;
	
	void pretty_print(const int& indent) const;
	void renderasm(ASMhandle* context);

private:
	char* name;

};



#endif

