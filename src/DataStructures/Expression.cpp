#include "Expression.h"

Expression::Expression(Expression* lhs_in, char* oper_in, Expression* rhs_in) : Statement(stat_expression), lhs(lhs_in), rhs(rhs_in), oper(oper_in) {}

Expression::Expression(const StatementT stat_type_in) : Statement(stat_type_in), lhs(NULL), rhs(NULL), oper(NULL) {}


Expression::~Expression(){
	if(lhs!=NULL) delete lhs;		// Note that destructors for the objects down the tree get recursively called
	if(rhs!=NULL) delete rhs;
}

NumT Expression::eval(){
	// use recursion
	// return type might be a memory location as well??
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

/*
void Expression::pretty_print_oper() const{
	if(oper==plus) 	cout<<"+";
	if(oper==mult) 	cout<<"*";
	if(oper==minus) cout<<"-";
	if(oper==div) 	cout<<"/";
}
*/
