#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(vector<BaseExpression*>* expr_list_in) : Statement(ST_expr_statement), expr_list(expr_list_in){}

ExpressionStatement::ExpressionStatement(BaseExpression* expr_in) : 
	Statement(ST_expr_statement){
	expr_list = new vector<BaseExpression*>;
	expr_list->push_back(expr_in);
}

ExpressionStatement::~ExpressionStatement(){
	if (expr_list!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			delete *it;
		}
		delete expr_list;
	}
}


void ExpressionStatement::push_back(BaseExpression* expr_in){
	if(expr_list==NULL)	expr_list = new vector<BaseExpression*>;
	expr_list->push_back(expr_in);
}

void ExpressionStatement::pretty_print(const int& indent){
	simplify();
	
	if(expr_list!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			(*it)->pretty_print(indent);
			cout<<endl;
		}
	}
}


void ExpressionStatement::renderasm(ASMhandle& context){
	simplify();
}

void ExpressionStatement::simplify(){
	if(expr_list!=NULL){
		BaseExpression* tmp_expr=NULL;
		snum_t tmp;
		vector<BaseExpression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			try{
				if(*it!=NULL){
					tmp_expr = (*it)->simplify(tmp);
					if(tmp_expr!=NULL){
						delete *it;
						*it = tmp_expr;
					}
				} 
			}	
			catch(const int& exception_in){
			}
		}
	}
}
