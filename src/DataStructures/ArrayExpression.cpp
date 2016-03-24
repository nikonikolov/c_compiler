#include "ArrayExpression.h"


ArrayExpression::ArrayExpression(BaseExpression* first_dim_mem, const int& line_in, const string& src_file_in) :
	BaseExpression(EXPR_array_expr, line_in, src_file_in) {
	dimension = new vector<BaseExpression*>;
	dimension->push_back(first_dim_mem);
}

ArrayExpression::~ArrayExpression(){
	if(dimension!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=dimension->begin(); it!=dimension->end(); ++it){
			delete *it;
		}
		delete dimension;
	}
}

void ArrayExpression::push_back_mem(BaseExpression* expr_in){
	if(dimension==NULL) dimension=new vector<BaseExpression*>;
	dimension->push_back(expr_in);
}

void ArrayExpression::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<"{";
	if(dimension!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=dimension->begin(); it!=dimension->end(); ++it){
			(*it)->pretty_print(0);
			cout<<", ";		
		}
	}
	cout<<"}";
}


void ArrayExpression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
}

BaseExpression* ArrayExpression::simplify(){
	vector<BaseExpression*>::iterator it;
	for(it=dimension->begin(); it!=dimension->end(); ++it){
		BaseExpression* tmp_expr=NULL;
		try{
			tmp_expr = (*it)->simplify();
			if(tmp_expr!=NULL){
				delete (*it);
				(*it) = tmp_expr; 		
			}
		}
		catch(const int& exception_in){
			(*it)->generate_error("Variable type expression not allowed for array value initialization");
		}
	}
	return NULL;
}