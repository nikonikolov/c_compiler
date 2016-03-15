#ifndef VAREXPR_H
#define VAREXPR_H

#include <string.h>

#include "BaseExpression.h"

/*	Class used to implement Variables appearing in expressions. Note that Variable class cannot be used for this purpose
	because of ASMhandle inclusion in BaseExpression and ASMhandle having Variable as its member
	
*/

class VarExpr : public BaseExpression{

public:
	VarExpr(char* name_in);
	~VarExpr();
	const char* get_name() const;
	
	void pretty_print(const int& indent) const;
	void renderasm(ASMhandle& context);
	snum_t simplify();

private:
	char* name;

};



#endif

