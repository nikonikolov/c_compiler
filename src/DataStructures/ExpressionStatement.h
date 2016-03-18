#ifndef EXPRESSIONSTATEMENT_H
#define EXPRESSIONSTATEMENT_H
#include "Expression.h"

/* The function of the class is to allow for multiple expressions taking place at a single line.
*/
class ExpressionStatement : public Statement{

public:
	ExpressionStatement(vector<BaseExpression*>* expr_list_in);
	ExpressionStatement(BaseExpression* expr_in);

	ExpressionStatement(vector<BaseExpression*>* expr_list_in, const int& line_in, const string& src_file_in);
	ExpressionStatement(BaseExpression* expr_in, const int& line_in, const string& src_file_in);

	~ExpressionStatement();

	void push_back(BaseExpression* expr_in);

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);

	BaseExpression* get_last();

private:
	void simplify();
	
	vector<BaseExpression*>* expr_list;
};



#endif

