#include "TerneryExpression.h"

TerneryExpression::TerneryExpression(vector<BaseExpression*>* lhs_in, BaseExpression* mid_in, vector<BaseExpression*>* rhs_in) :
	BaseExpression(ST_ternery_expr), lhs(lhs_in), mid(mid_in), rhs(rhs_in) {}

TerneryExpression::~TerneryExpression(){
	if(lhs!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=lhs->begin(); it!=lhs->end(); ++it){
			delete *it;
		}
		delete lhs;
	}
	if(rhs!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=rhs->begin(); it!=rhs->end(); ++it){
			delete *it;
		}
		delete rhs;
	}

	if(mid!=NULL) delete mid;
}

NumT TerneryExpression::eval(){
	//return mid->eval();
}

void TerneryExpression::set_lhs(vector<BaseExpression*>* lhs_in){
	if(lhs!=NULL) return;
	lhs=lhs_in;
}

void TerneryExpression::set_mid(BaseExpression* mid_in){
	if(mid!=NULL) return;
	mid=mid_in;
}

void TerneryExpression::set_rhs(vector<BaseExpression*>* rhs_in){
	if(rhs!=NULL) return;
	rhs=rhs_in;
}

void TerneryExpression::push_back_rhs(BaseExpression* expr_in){
	if(rhs==NULL) rhs=new vector<BaseExpression*>;
	rhs->push_back(expr_in);
}

void TerneryExpression::push_back_lhs(BaseExpression* expr_in){
	if(lhs==NULL) lhs=new vector<BaseExpression*>;
	lhs->push_back(expr_in);
}

void TerneryExpression::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	if(mid!=NULL){
		mid->pretty_print(indent);
		cout<<" ";		
	} 
	if(rhs!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=rhs->begin(); it!=rhs->end(); ++it){
			(*it)->pretty_print(0);
			cout<<" ";		
		}
	}

	if(lhs!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=lhs->begin(); it!=lhs->end(); ++it){
			(*it)->pretty_print(0);
			cout<<" ";		
		}
	}
}


void TerneryExpression::renderasm(){
}
