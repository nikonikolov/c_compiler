#include "TerneryExpression.h"

TerneryExpression::TerneryExpression(BaseExpression* lhs_in, BaseExpression* mid_in, BaseExpression* rhs_in) : 
	BaseExpression(ST_ternery_expr), lhs(lhs_in), mid(mid_in), rhs(rhs_in) {}

TerneryExpression::~TerneryExpression(){
	if(lhs!=NULL) delete lhs;		// Note that destructors for the objects down the tree get recursively called
	if(mid!=NULL) delete mid;
	if(rhs!=NULL) delete rhs;
}

NumT TerneryExpression::eval(){
	//return mid->eval();
}

void TerneryExpression::set_lhs(BaseExpression* lhs_in){
	if(lhs!=NULL) return;
	lhs=lhs_in;
}

void TerneryExpression::set_mid(BaseExpression* mid_in){
	if(mid!=NULL) return;
	mid=mid_in;
}

void TerneryExpression::set_rhs(BaseExpression* rhs_in){
	if(rhs!=NULL) return;
	rhs=rhs_in;
}


void TerneryExpression::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	if(mid!=NULL){
		mid->pretty_print(indent);
		cout<<" ";		
	} 
	if(rhs!=NULL) {
		rhs->pretty_print(0);
		cout<<" ";		
	}
	if(lhs!=NULL){
		lhs->pretty_print(0);
		cout<<" ";		
	}
}
