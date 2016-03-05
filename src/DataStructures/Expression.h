#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Statement.h"
/*
enum OpT{
	empty_oper=1,
	plus=2,
	mult=3,
	minus=4

};
*/

class Expression : public Statement{

public:
	Expression(Expression* lhs_in, char* oper_in, Expression* rhs_in);
	Expression(const StatementT stat_type_in);
	virtual ~Expression();

	virtual NumT eval();

	virtual void pretty_print(const int& indent) const;
private:
	//pretty_print_oper() const;
	
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of Statement* 
	the objects in the vector are dynamically allocated as well
	*/

	char* oper;
	Expression* lhs;
	Expression* rhs;
	int a;
};



#endif

