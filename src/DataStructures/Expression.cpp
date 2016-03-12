#include "Expression.h"


Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) : 
	BaseExpression(ST_expression), lhs(lhs_in), rhs(rhs_in), oper(oper_in) {}


Expression::~Expression(){
	if(lhs!=NULL) delete lhs;		// Note that destructors for the objects down the tree get recursively called
	if(rhs!=NULL) delete rhs;
}

NumT Expression::eval(){
	// use recursion
	// return type might be a memory location as well??
}

void Expression::set_lhs(Expression* lhs_in){
	if(lhs!=NULL) return;
	lhs=lhs_in;
}

void Expression::set_rhs(Expression* rhs_in){
	if(rhs!=NULL) return;
	rhs=rhs_in;
}

void Expression::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	if(lhs!=NULL || rhs!=NULL) cout<<white_space;

	if(lhs!=NULL) {
		cout<<"(";
		lhs->pretty_print(0);
		cout<<")";
	}
	if(oper!=NULL) cout<<oper;
	if(rhs!=NULL){
		cout<<"(";
		rhs->pretty_print(0);
		cout<<")";
	}

	//if(indent!=0) cout<<endl;
}




void Expression::renderasm(){
}
