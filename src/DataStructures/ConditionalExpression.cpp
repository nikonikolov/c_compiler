#include "ConditionalExpression.h"

/* =============================================== CONSTRUCTION =============================================== */


ConditionalExpression::ConditionalExpression(BaseExpression* condition_in, BaseExpression* lhs_in, BaseExpression* rhs_in, 
													const int& line_in, const string& src_file_in) : 
	Expression(lhs_in, NULL, rhs_in, EXPR_conditional_expr, line_in, src_file_in), condition(condition_in) {}

ConditionalExpression::~ConditionalExpression(){
	if(condition!=NULL) delete condition;
}

void ConditionalExpression::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space;

	if(condition!=NULL) {
		cout<<"(";
		condition->pretty_print(0);
		cout<<") ";
	}
	cout<<"? ";
	if(lhs!=NULL) {
		cout<<"(";
		lhs->pretty_print(0);
		cout<<") ";
	}
	cout<<": ";
	if(rhs!=NULL){
		cout<<"(";
		rhs->pretty_print(0);
		cout<<")";
	}
}

void ConditionalExpression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
	if(debug) cerr<<"ConditionalExpression: renderasm : start"<<endl;

	if(lhs==NULL || rhs==NULL || condition ==NULL) generate_error("Omitting any part of Condtional Expression is forbidden");

	ExprResult** lhs_result = new ExprResult*(NULL);
	ExprResult** rhs_result = new ExprResult*(NULL);
	ExprResult** cond_result = new ExprResult*(NULL);
	lhs->renderasm(context, lhs_result);
	rhs->renderasm(context, rhs_result);
	condition->renderasm(context, cond_result);
	
	if(debug) cerr<<"ConditionalExpression: renderasm : all expressions renderasm successful"<<endl;
	
	if(dest!=NULL){
		*dest = new Temporary(context.allocate_var());

		string rhs_assign = context.get_assembly_label();		
		string continued_exec = context.get_assembly_label();		

		(*cond_result)->load("$t0");
		assembler.push_back(ss<<pad<<"beq"<<"$0, $t0, "<<rhs_assign<<endl);
		(*lhs_result)->load("$t1");
		assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
		assembler.push_back(ss<<pad<<"nop"<<endl);
		assembler.push_back(ss<<rhs_assign<<":"<<endl);
		(*rhs_result)->load("$t1");
		assembler.push_back(ss<<continued_exec<<":"<<endl);
		(*dest)->store("$t1");
	} 

	if(debug) cerr<<"ConditionalExpression: renderasm : result calculation successful"<<endl;

	if((*lhs_result)->get_result_type()==RESULT_tmp) delete *lhs_result;
	delete lhs_result;
	if((*rhs_result)->get_result_type()==RESULT_tmp) delete *rhs_result;
	delete rhs_result;
	if((*cond_result)->get_result_type()==RESULT_tmp) delete *cond_result;
	delete cond_result;

	if(debug) cerr<<"ConditionalExpression: renderasm : successful"<<endl;
}


BaseExpression* ConditionalExpression::simplify(){
	if(debug) cerr<<"ConditionalExpression: simplify enter"<<endl;
	
	BaseExpression* tmp_expr=NULL;
	int exception = 0;

	try{									// Optimize LHS
		if(lhs!=NULL){
			tmp_expr = lhs->simplify();
			if(tmp_expr!=NULL){
				delete lhs;
				lhs = tmp_expr;				// In case RHS cannot be simplified
			}
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}
	if(debug) cerr<<"ConditionalExpression: simplify LHS successful"<<endl;
	tmp_expr=NULL;
	try{ 									// Optimize RHS
		if(rhs!=NULL){
			tmp_expr = rhs->simplify();
			if(tmp_expr!=NULL){
				delete rhs;
				rhs = tmp_expr; 			// In case LHS was not simplified
			}
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}
	if(debug) cerr<<"ConditionalExpression: simplify RHS successful"<<endl;
	tmp_expr=NULL;
	try{ 									// Optimize RHS
		if(condition!=NULL){
			tmp_expr = condition->simplify();
			if(tmp_expr!=NULL){
				delete condition;
				condition = tmp_expr; 			// In case LHS was not simplified
			}
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}
	if(debug) cerr<<"ConditionalExpression: simplify Condtion successful"<<endl;
	
	if(exception) throw exception;

	if(debug) cerr<<"ConditionalExpression: simplify : casting pointers"<<endl;

	Constant<uint64_t>* res_ptr=NULL;
	Constant<uint64_t>* condition_ptr = static_cast<Constant<uint64_t>*>(condition);
	Constant<uint64_t>* lhs_ptr = static_cast<Constant<uint64_t>*>(lhs);
	Constant<uint64_t>* rhs_ptr = static_cast<Constant<uint64_t>*>(rhs);
	int lhs_val=lhs_ptr->get_value(), rhs_val=rhs_ptr->get_value(), condition_val=condition_ptr->get_value();
	
	if(debug) cerr<<"ConditionalExpression: simplify : calculating new result"<<endl;

	if(condition_val) res_ptr= new Constant<uint64_t>(lhs_val);
	else 	 		  res_ptr= new Constant<uint64_t>(rhs_val);

	tmp_expr = res_ptr;
	return tmp_expr;
}
