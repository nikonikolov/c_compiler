#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(vector<Expression*>* expr_list_in) : Statement(stat_exprstat), expr_list(expr_list_in){}

ExpressionStatement::ExpressionStatement(Expression* expr_in) : 
	Statement(stat_exprstat){
	expr_list = new vector<Expression*>;
	expr_list->push_back(expr_in);
}

ExpressionStatement::~ExpressionStatement(){
	if (expr_list!=NULL){
		vector<Expression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			delete *it;
		}
		delete expr_list;
	}
}


void ExpressionStatement::push_back(Expression* expr_in){
	if(expr_list!=NULL){
		expr_list->push_back(expr_in);
	}
	else{
		expr_list = new vector<Expression*>;
		expr_list->push_back(expr_in);
	}
}

void ExpressionStatement::pretty_print(const int& indent) const{
	if(expr_list!=NULL){
		vector<Expression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			(*it)->pretty_print(indent);
			cout<<endl;
		}
	}
}


