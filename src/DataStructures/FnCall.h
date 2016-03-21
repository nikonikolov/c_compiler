#ifndef FNCALL_H
#define FNCALL_H

#include "Variable.h"
#include "include.h"
#include "BaseExpression.h"


/*	FIX:
		1. Currently only 32bit wide arguments and INTs only assumed as function parameters - you have to compare whether 
		function call and function definition match
		2. Probably best to add a member function for Variable load_variable which can load any type of variable in register or 
		in memory instead of doing it in ASMhandle. You still need asm handle to figure out how much memory you need to allocate 
		though
*/


class FnCall : public BaseExpression{

public:
	FnCall(char* name_in, vector<BaseExpression*>* arguments_in, const int& line_in, const string& src_file_in);
	~FnCall();

	string get_name() const;

	void renderasm(ASMhandle& context, char** destination =NULL);
	void pretty_print(const int& indent);
	BaseExpression* simplify();

private:
	void init_args(ASMhandle& context);

	vector<BaseExpression*>* arguments;

	char* name;								// Name of the function called
};



#endif

