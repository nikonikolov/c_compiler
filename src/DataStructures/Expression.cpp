#include "Expression.h"

/* =============================================== CONSTRUCTION =============================================== */

Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const ExprT& expr_type_in) : 
	BaseExpression(expr_type_in), lhs(lhs_in), rhs(rhs_in) {
	oper = strdup(oper_in);
}

Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, 
		const ExprT& expr_type_in, const int& line_in, const string& src_file_in) :
	BaseExpression(expr_type_in, line_in, src_file_in), lhs(lhs_in), rhs(rhs_in){
	oper = strdup(oper_in);
}

Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) : 
	BaseExpression(EXPR_expression), lhs(lhs_in), rhs(rhs_in) {
	oper = strdup(oper_in);
}

Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const int& line_in, const string& src_file_in) :
	BaseExpression(EXPR_expression, line_in, src_file_in), lhs(lhs_in), rhs(rhs_in){
	oper = strdup(oper_in);
}

Expression::~Expression(){
	if(lhs!=NULL) delete lhs;		// Note that destructors for the objects down the tree get recursively called
	if(rhs!=NULL) delete rhs;
}

/* =============================================== GETTERS AND SETTERS =============================================== */


void Expression::set_lhs(Expression* lhs_in){
	if(lhs!=NULL) return;
	lhs=lhs_in;
}

void Expression::set_rhs(Expression* rhs_in){
	if(rhs!=NULL) return;
	rhs=rhs_in;
}


/* =============================================== VIRTUAL METHODS IMPLEMENTATION =============================================== */

void Expression::pretty_print(const int& indent){
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
}


/* 	Note the caller to simplify has to handle the exception. Usually that would be renderasm(ASMhandle& context) member method
	of a BaseExpression implementation. Note you cannot have Constant as return type as this is a pure virtual function 
 	defined in BaseExpression which,"<< cannot have visibility of the Constant class

	Returns:
		1. NULL means a Constant => no need to change the pointer
		2. Exception thrown means no optimization currently possible for this expression
		3. Meaningful pointer means optimization performed
*/
BaseExpression* Expression::simplify(){
	if(debug) cerr<<"Expression: simplify enter"<<endl;
	
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
	if(debug) cerr<<"Expression: simplify LHS successful"<<endl;
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
	if(debug) cerr<<"Expression: simplify RHS successful"<<endl;

	if(exception) throw exception;

	/* 	Do the casting here: Find the higher precedence, deallocate old Constant and create a new one cast to the required type.
	 	Note you will need to perform semantics checks before making the operation as well. E.g. - you cannot shift by a double 
		value, you cannot assign integer to a struct, etc.
	*/

	if(debug) cerr<<"Expression: simplify : casting pointers"<<endl;

	Constant<uint64_t>* res_ptr=NULL;
	Constant<uint64_t>* lhs_ptr = static_cast<Constant<uint64_t>*>(lhs);
	Constant<uint64_t>* rhs_ptr = static_cast<Constant<uint64_t>*>(rhs);
	int lhs_val=lhs_ptr->get_value(), rhs_val=rhs_ptr->get_value();
	
	if(debug) cerr<<"Expression: simplify : calculating new result"<<endl;

	/* ----------------------------------- TWO OPERANDS ----------------------------------- */
	if(lhs!=NULL && rhs!=NULL){
		if(!strcmp(oper,"+")) 	res_ptr = new Constant<uint64_t>(lhs_val + rhs_val); 	
		if(!strcmp(oper,"-")) 	res_ptr = new Constant<uint64_t>(lhs_val - rhs_val); 	
		if(!strcmp(oper,"*")) 	res_ptr = new Constant<uint64_t>(lhs_val * rhs_val); 	
		if(!strcmp(oper,"%")) 	res_ptr = new Constant<uint64_t>(lhs_val % rhs_val); 	
		if(!strcmp(oper,"/")) 	res_ptr = new Constant<uint64_t>(lhs_val / rhs_val); 	
		if(!strcmp(oper,"|")) 	res_ptr = new Constant<uint64_t>(lhs_val | rhs_val); 	
		if(!strcmp(oper,"&")) 	res_ptr = new Constant<uint64_t>(lhs_val & rhs_val); 	
		if(!strcmp(oper,"^")) 	res_ptr = new Constant<uint64_t>(lhs_val ^ rhs_val); 	
		if(!strcmp(oper,"||")) 	res_ptr = new Constant<uint64_t>(lhs_val || rhs_val); 	
		if(!strcmp(oper,"&&")) 	res_ptr = new Constant<uint64_t>(lhs_val && rhs_val); 	
		if(!strcmp(oper,"<<")) 	res_ptr = new Constant<uint64_t>(lhs_val << rhs_val); 	
		if(!strcmp(oper,">>")) 	res_ptr = new Constant<uint64_t>(lhs_val >> rhs_val); 	
		if(!strcmp(oper,"<=")) 	res_ptr = new Constant<uint64_t>(lhs_val <= rhs_val); 	
		if(!strcmp(oper,">=")) 	res_ptr = new Constant<uint64_t>(lhs_val >= rhs_val); 	
		if(!strcmp(oper,">")) 	res_ptr = new Constant<uint64_t>(lhs_val > rhs_val); 	
		if(!strcmp(oper,"<")) 	res_ptr = new Constant<uint64_t>(lhs_val < rhs_val); 	
		if(!strcmp(oper,"==")) 	res_ptr = new Constant<uint64_t>(lhs_val == rhs_val); 	
		if(!strcmp(oper,"!=")) 	res_ptr = new Constant<uint64_t>(lhs_val != rhs_val); 
	
		if(!strcmp(oper,"=")) 	throw 1; 	
		if(!strcmp(oper,"+=")) 	throw 1; 	
		if(!strcmp(oper,"-=")) 	throw 1; 	
		if(!strcmp(oper,"|=")) 	throw 1; 	
		if(!strcmp(oper,"&=")) 	throw 1; 	
		if(!strcmp(oper,"^=")) 	throw 1; 	
		if(!strcmp(oper,"<<=")) throw 1; 	
		if(!strcmp(oper,">>=")) throw 1; 	

	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"+"))	res_ptr = new Constant<uint64_t>(+(rhs_val));
		if(!strcmp(oper,"-"))	res_ptr = new Constant<uint64_t>(-(rhs_val));
		if(!strcmp(oper,"!")) 	res_ptr = new Constant<uint64_t>(!(rhs_val));
		if(!strcmp(oper,"~")) 	res_ptr = new Constant<uint64_t>(~(rhs_val));
		if(!strcmp(oper,"sizeof")) 	res_ptr = new Constant<uint64_t>(sizeof(rhs_val));
	}
	/* ----------------------------------- RETURN DECISION ----------------------------------- */
	
	if(res_ptr!=NULL){
		tmp_expr = res_ptr;
		return tmp_expr;
	} 
	//generate_error("unrecognized operator \""+string(oper)+"\" in expression");			// Invalid semantics of the expression
	// Temporary for testing only. Uncomment above for final version
	throw 1;						// Invalid semantics of the expression
}

/*	First, if either operand has type long double, the other operand is converted to long double . Otherwise, if either operand 
	has type double, the other operand is converted to double. Otherwise, if either operand has type float, the other operand 
	is converted to float. Otherwise, the integral promotions are performed on both operands. Then the following rules are 
	applied: If either operand has type unsigned long int, the other operand is converted to unsigned long int. Otherwise, if one 
	operand has type long int and the other has type unsigned int, if a long int can represent all values of an unsigned int, the 
	operand of type unsigned int is converted to long int ; if a long int cannot represent all the values of an unsigned int, both 
	operands are converted to unsigned long int. Otherwise, if either operand has type long int, the other operand is converted to 
	long int. Otherwise, if either operand has type unsigned int, the other operand is converted to unsigned int. Otherwise, both 
	operands have type int.
*/


void Expression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
	if(dest==NULL) return;

	ExprResult** lhs_result = NULL;
	ExprResult** rhs_result = NULL;
	if(lhs!=NULL){
		lhs_result = new ExprResult*(NULL);
		lhs->renderasm(context, lhs_result);
	} 
	if(rhs!=NULL){
		rhs_result = new ExprResult*(NULL);
		rhs->renderasm(context, rhs_result);
	} 

	if(*dest==NULL) *dest = new Temporary(context.allocate_var()); 		// Not null when called by Variables

	if(lhs!=NULL && rhs!=NULL){
		if(!strcmp(oper,"+")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "addu"); 	
		if(!strcmp(oper,"-")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "subu"); 	
		if(!strcmp(oper,"|")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "or"); 	
		if(!strcmp(oper,"&")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "and"); 	
		if(!strcmp(oper,"^")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "xor"); 	
		if(!strcmp(oper,"<<")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "sllv"); 	
		if(!strcmp(oper,">>")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "srav"); 	

		if(!strcmp(oper,"*")) 	arithmetic_ins			(*dest, *lhs_result, *rhs_result, "mul"); 	
		if(!strcmp(oper,"%")) 	div_rem_ins				(*dest, *lhs_result, *rhs_result, "mfhi"); 	
		if(!strcmp(oper,"/")) 	div_rem_ins				(*dest, *lhs_result, *rhs_result, "mflo"); 	

		if(!strcmp(oper,"||")) 	logical_or_ins 			(*dest, *lhs_result, *rhs_result, context); 	
		if(!strcmp(oper,"&&")) 	logical_and_ins 		(*dest, *lhs_result, *rhs_result, context); 	
		if(!strcmp(oper,"<=")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "blez"); 	
		if(!strcmp(oper,">=")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "bgez"); 	
		if(!strcmp(oper,"<")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "bltz"); 	
		if(!strcmp(oper,">")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "bgtz"); 	
		if(!strcmp(oper,"==")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "beq", false); 	
		if(!strcmp(oper,"!=")) 	logical_comparison_ins 	(*dest, *lhs_result, *rhs_result, context, "bne", false); 
	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"+"))		sign_ins 			(*dest, *rhs_result, false);
		if(!strcmp(oper,"-"))		sign_ins 			(*dest, *rhs_result, true);
		if(!strcmp(oper,"!")) 		logical_not_ins 	(*dest, *rhs_result, context);
		if(!strcmp(oper,"~")) 		bitwise_not_ins 	(*dest, *rhs_result);
		if(!strcmp(oper,"sizeof"))	sizeof_ins 			(*dest, *rhs_result);
	}

	if(lhs_result!=NULL) {
		if((*lhs_result)->get_result_type()==RESULT_tmp) delete *lhs_result;
		delete lhs_result;
	}
	if(rhs_result!=NULL){
		if((*rhs_result)->get_result_type()==RESULT_tmp) delete *rhs_result;
		delete rhs_result;
	} 
}


/* =============================================== CODEGEN METHODS =============================================== */


/* ---------------------------------------------- ARITHMETIC INSTRUCTIONS ---------------------------------------------- */

void Expression::arithmetic_ins(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction){
	lhs_result->load("$t0");
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<instruction<<"$t2, $t0, $t1"<<endl);
	dest->store("$t2");
}

void Expression::div_rem_ins(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, const string& instruction){
	lhs_result->load("$t0");
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<"teq"<<"$t1, $0, 7"<<endl);
	assembler.push_back(ss<<pad<<"div"<<"$t0, $t1"<<endl);
	assembler.push_back(ss<<pad<<instruction<<"$t2"<<endl);
	dest->store("$t2");
}


/* ---------------------------------------------- LOGICAL INSTRUCTIONS ---------------------------------------------- */

void Expression::logical_or_ins(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context){
	string non_default_action = context.get_assembly_label();		
	string continued_exec = context.get_assembly_label();		
	
	lhs_result->load("$t0");
	assembler.push_back(ss<<pad<<"bne"<<"$0, $t0, "<<non_default_action<<endl);		// If arg1 is not 0, go to non_default action
	assembler.push_back(ss<<pad<<"nop"<<endl);
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<"bne"<<"$0, $t1, "<<non_default_action<<endl); 	// If arg2 is not 0, go to non_default action
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<pad<<"move"<<"$t2"<<", $0"<<endl); 						// Default action reached, result is 0
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<non_default_action<<":"<<endl);
	assembler.push_back(ss<<pad<<"li"<<"$t2, 1"<<endl); 							// non-default action reached, result is 1
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<continued_exec<<":"<<endl); 							// continue execution of the program
}


void Expression::logical_and_ins(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context){
	string non_default_action = context.get_assembly_label();		
	string continued_exec = context.get_assembly_label();		
	
	lhs_result->load("$t0");
	assembler.push_back(ss<<pad<<"beq"<<"$0, $t0, "<<non_default_action<<endl);		// If arg1 is 0, go to non_default action
	//assembler.push_back(ss<<pad<<"nop"<<endl);
	rhs_result->load("$t1");
	assembler.push_back(ss<<pad<<"beq"<<"$0, $t1, "<<non_default_action<<endl); 	// If arg2 is 0, go to non_default action
	//assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<pad<<"li"<<"$t2, 1"<<endl); 							// Default action reached, result is 1
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	//assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<non_default_action<<":"<<endl);
	assembler.push_back(ss<<pad<<"move"<<"$t2"<<", $0"<<endl); 						// non-default action reached, result is 0
	dest->store("$t2");
//	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
//	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<continued_exec<<":"<<endl); 							// continue execution of the program

}


void Expression::logical_not_ins(ExprResult* dest, ExprResult* arg, ASMhandle& context){
	string non_default_action = context.get_assembly_label();		
	string continued_exec = context.get_assembly_label();		
	
	arg->load("$t0");
	assembler.push_back(ss<<pad<<"bne"<<"$0, $t0, "<<non_default_action<<endl);		// If arg1 is not 0, go to non_default action
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<pad<<"li"<<"$t2, 1"<<endl); 							// non-default action reached, result is 1
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<non_default_action<<":"<<endl);
	dest->store("$0");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<continued_exec<<":"<<endl); 							// continue execution of the program
}

// if comparison of arg1-arg2 is true, then 1, otherwise 0
void Expression::logical_comparison_ins(ExprResult* dest, ExprResult* lhs_result, ExprResult* rhs_result, ASMhandle& context,
																	const string& instruction, const bool& subtract/*=true*/){
	string non_default_action = context.get_assembly_label();		
	string continued_exec = context.get_assembly_label();		
	
	lhs_result->load("$t0");
	rhs_result->load("$t1");
	
	if(subtract){
	 	assembler.push_back(ss<<pad<<"subu"<<"$t2, $t0, $t1"<<endl);
		assembler.push_back(ss<<pad<<instruction<<"$t2, "<<non_default_action<<endl);			// Branch if comparison is true
	}
	
	else assembler.push_back(ss<<pad<<instruction<<"$t0, $t1, "<<non_default_action<<endl); 	// Branch if comparison is true
	assembler.push_back(ss<<pad<<"nop"<<endl);

	assembler.push_back(ss<<pad<<"move"<<"$t2"<<", $0"<<endl); 							// Default action reached, result is 0
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<non_default_action<<":"<<endl);
	assembler.push_back(ss<<pad<<"li"<<"$t2, 1"<<endl); 								// non-default action reached, result is 1
	dest->store("$t2");
	assembler.push_back(ss<<pad<<"b"<<continued_exec<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);
	assembler.push_back(ss<<continued_exec<<":"<<endl); 								// continue execution of the program
}


/* ---------------------------------------------- SINGLE OPERAND ---------------------------------------------- */

void Expression::sign_ins(ExprResult* dest, ExprResult* arg, const bool& get_negative){
	arg->load("$t0");
	if(get_negative){
		assembler.push_back(ss<<pad<<"li"<<"$t1, 0xFFFFFFFF"<<endl);
		assembler.push_back(ss<<pad<<"xor"<<"$t0, $t0, $t1"<<endl);						// Invert
		assembler.push_back(ss<<pad<<"addi"<<"$t0, $t0, 1"<<endl);						// Add 1
	}
	dest->store("$t0");
}

void Expression::bitwise_not_ins(ExprResult* dest, ExprResult* arg){
	arg->load("$t0");
	assembler.push_back(ss<<pad<<"li"<<"$t1, 0xFFFFFFFF"<<endl);
	assembler.push_back(ss<<pad<<"xor"<<"$t2, $t0, $t1"<<endl);
	dest->store("$t2");
}

void Expression::sizeof_ins(ExprResult* dest, ExprResult* arg){
	assembler.push_back(ss<<pad<<"li"<<"$t2, 4"<<endl);
	dest->store("$t2");
}



