#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H
#include "Expression.h"

class ExpressionStatement : public Statement{

public:
	ExpressionStatement(vector<Expression*>* expr_list_in);
	ExpressionStatement(Expression* expr_in);
	~ExpressionStatement();

	void push_back(Expression* expr_in);

	void pretty_print(const int& indent) const;
private:
	
	/* 
	NOTE: All vector pointers point to dynamically allocated vectors. In case of vector of pointers	
	the objects in the vector are dynamically allocated as well
	*/

	vector<Expression*>* expr_list;
};



#endif

