#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H
#include "Expression.h"

/* The function of the class is to allow for multiple expressions taking place at a single line.
*/
class ExpressionStatement : public Statement{

public:
	ExpressionStatement(vector<Expression*>* expr_list_in);
	ExpressionStatement(Expression* expr_in);
	~ExpressionStatement();

	void push_back(Expression* expr_in);

	void pretty_print(const int& indent) const;
private:
	
	vector<Expression*>* expr_list;
};



#endif

