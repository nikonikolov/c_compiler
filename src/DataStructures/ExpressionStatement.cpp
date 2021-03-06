#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(vector<BaseExpression*>* expr_list_in) : Statement(ST_expr_statement), expr_list(expr_list_in){}

ExpressionStatement::ExpressionStatement(BaseExpression* expr_in) : 
	Statement(ST_expr_statement){
	expr_list = new vector<BaseExpression*>;
	expr_list->push_back(expr_in);
}

ExpressionStatement::ExpressionStatement(vector<BaseExpression*>* expr_list_in, const int& line_in, const string& src_file_in) : 
	Statement(ST_expr_statement, line_in, src_file_in), expr_list(expr_list_in){}

ExpressionStatement::ExpressionStatement(BaseExpression* expr_in, const int& line_in, const string& src_file_in) : 
	Statement(ST_expr_statement, line_in, src_file_in){
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

	if(expr_list!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			(*it)->renderasm(context);
		}
	}
}

void ExpressionStatement::simplify(){
	if(expr_list!=NULL){
		BaseExpression* tmp_expr=NULL;
		vector<BaseExpression*>::iterator it;
		for(it=expr_list->begin(); it!=expr_list->end(); ++it){
			try{
				if(*it!=NULL){
					tmp_expr = (*it)->simplify();
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


BaseExpression* ExpressionStatement::get_last(){
	int idx=expr_list->size()-1;
	return (*expr_list)[idx];
}
