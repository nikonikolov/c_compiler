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


void Expression::renderasm(ASMhandle& context, char** destination /*=NULL*/){
	// Case when Expression appears just as arithmetical action with result saved nowhere
	if(destination==NULL) return;

	char **lhs_dest, **rhs_dest;
	if(lhs!=NULL){
		*lhs_dest = context.allocate_var();
		lhs->renderasm(context, lhs_dest);
	} 
	if(rhs!=NULL){
		*rhs_dest = context.allocate_var();
		rhs->renderasm(context, rhs_dest);
	} 

	if(lhs!=NULL && rhs!=NULL){
		if(!strcmp(oper,"+")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "addu"); 	
		if(!strcmp(oper,"-")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "subu"); 	
		if(!strcmp(oper,"|")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "or"); 	
		if(!strcmp(oper,"&")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "and"); 	
		if(!strcmp(oper,"^")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "xor"); 	
		if(!strcmp(oper,"<<")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "sllv"); 	
		if(!strcmp(oper,">>")) 	arithmetic_ins(*destination, *lhs_dest, *rhs_dest, "srlv"); 	

		//if(!strcmp(oper,"*")) 	arithmetic_ins("mult", *destination, *lhs_dest, *rhs_dest); 	
		//if(!strcmp(oper,"%")) 	arithmetic_ins("addu", *destination, *lhs_dest, *rhs_dest); 	
		//if(!strcmp(oper,"/")) 	arithmetic_ins("addu", *destination, *lhs_dest, *rhs_dest); 	

		if(!strcmp(oper,"||")) 	logical_or_ins(context, *destination, *lhs_dest, *rhs_dest); 	
		if(!strcmp(oper,"&&")) 	logical_and_ins(context, *destination, *lhs_dest, *rhs_dest); 	
		if(!strcmp(oper,"<=")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "blez"); 	
		if(!strcmp(oper,">=")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "bgez"); 	
		if(!strcmp(oper,"<")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "bltz"); 	
		if(!strcmp(oper,">")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "bgtz"); 	
		if(!strcmp(oper,"==")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "beq", true); 	
		if(!strcmp(oper,"!=")) 	logical_comparison_ins(context, *destination, *lhs_dest, *rhs_dest, "bne", true); 
	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"+"))	sign_ins(*destination, *rhs_dest, false);
		if(!strcmp(oper,"-"))	sign_ins(*destination, *rhs_dest, true);
		if(!strcmp(oper,"!")) 	logical_not_ins(context, *destination, *rhs_dest);
		//if(!strcmp(oper,"~")) 	 (~(rhs_val.numval.intmem));
		//if(!strcmp(oper,"sizeof")) 	 (sizeof(rhs_val.numval.intmem));
	}

}




/* 	Note the caller to simplify has to handle the exception. Usually that would be renderasm(ASMhandle& context) member method
	of a BaseExpression implementation. Note you cannot have Constant as return type as this is a pure virtual function 
 	defined in BaseExpression which cannot have visibility of the Constant class

	Returns:
		1. NULL means a Constant => no need to change the pointer
		2. Exception thrown means no optimization currently possible for this expression
*/
BaseExpression* Expression::simplify(snum_t& value){
	
	snum_t lhs_val, rhs_val;
	BaseExpression* tmp_expr=NULL;
	int exception = 0;
	// Optimize LHS
	try{
		if(lhs!=NULL){
			tmp_expr = lhs->simplify(lhs_val);
			if(tmp_expr!=NULL){
				delete lhs;
				lhs = tmp_expr;			// In case RHS cannot be simplified
			}
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}
	// Optimize RHS
	try{
		if(rhs!=NULL){
			tmp_expr = rhs->simplify(rhs_val);
			if(tmp_expr!=NULL){
				delete rhs;
				rhs = tmp_expr; 		// In case LHS was not simplified
			}
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}

	if(exception) throw exception;

	/* 	Do the casting here: Find the higher precedence, deallocate old Constant and create a new one cast to the required type.
	 	Note you will need to perform semantics checks before making the operation as well. E.g. - you cannot shift by a double 
		value, you cannot assign integer to a struct, etc.
	*/

	Constant<int>* res_ptr=NULL;
	
	/* ----------------------------------- TWO OPERANDS ----------------------------------- */
	if(lhs!=NULL && rhs!=NULL){
		if(!strcmp(oper,"+")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem + rhs_val.numval.intmem); 	
		if(!strcmp(oper,"-")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem - rhs_val.numval.intmem); 	
		if(!strcmp(oper,"*")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem * rhs_val.numval.intmem); 	
		if(!strcmp(oper,"%")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem % rhs_val.numval.intmem); 	
		if(!strcmp(oper,"/")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem / rhs_val.numval.intmem); 	
		if(!strcmp(oper,"|")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem | rhs_val.numval.intmem); 	
		if(!strcmp(oper,"&")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem & rhs_val.numval.intmem); 	
		if(!strcmp(oper,"^")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem ^ rhs_val.numval.intmem); 	
		if(!strcmp(oper,"||")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem || rhs_val.numval.intmem); 	
		if(!strcmp(oper,"&&")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem && rhs_val.numval.intmem); 	
		if(!strcmp(oper,"<<")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem << rhs_val.numval.intmem); 	
		if(!strcmp(oper,">>")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem >> rhs_val.numval.intmem); 	
		if(!strcmp(oper,"<=")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem <= rhs_val.numval.intmem); 	
		if(!strcmp(oper,">=")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem >= rhs_val.numval.intmem); 	
		if(!strcmp(oper,">")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem > rhs_val.numval.intmem); 	
		if(!strcmp(oper,"<")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem < rhs_val.numval.intmem); 	
		if(!strcmp(oper,"==")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem == rhs_val.numval.intmem); 	
		if(!strcmp(oper,"!=")) 	res_ptr = new Constant<int>(lhs_val.numval.intmem != rhs_val.numval.intmem); 
	
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
		if(!strcmp(oper,"+"))	res_ptr = new Constant<int>(+(rhs_val.numval.intmem));
		if(!strcmp(oper,"-"))	res_ptr = new Constant<int>(-(rhs_val.numval.intmem));
		if(!strcmp(oper,"!")) 	res_ptr = new Constant<int>(!(rhs_val.numval.intmem));
		if(!strcmp(oper,"~")) 	res_ptr = new Constant<int>(~(rhs_val.numval.intmem));
		if(!strcmp(oper,"sizeof")) 	res_ptr = new Constant<int>(sizeof(rhs_val.numval.intmem));
	}
	/* ----------------------------------- RETURN DECISION ----------------------------------- */
	
	if(res_ptr!=NULL){
		value.numval.intmem = res_ptr->get_value();
		value.tname = tint;
		tmp_expr = res_ptr;
		return tmp_expr;
	} 
	//throw gen_error();			// Invalid semantics of the expression
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

/* =============================================== CODEGEN METHODS =============================================== */

string Expression::gen_error() const{
	string result = "Error in file " + src_file +" at line " + std::to_string(line) + " around symbol " + oper;
	return result;
}


void Expression::arithmetic_ins(char* destination, char* arg1, char* arg2, const string& instruction){
	cout<<pad<<"lw"<<"$t0, "<<arg1<<endl;
	cout<<pad<<"lw"<<"$t1, "<<arg2<<endl;
	cout<<pad<<instruction<<"$t2, $t0, $t1"<<endl;
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
}


void Expression::logical_or_ins(ASMhandle& context, char* destination, char* arg1, char* arg2){
	string non_default_action = context.get_label();		
	string continued_exec = context.get_label();		
	
	cout<<pad<<"lw"<<"$t0, "<<arg1<<endl;
	cout<<pad<<"bne"<<"$0, $t0, "<<non_default_action<<endl;	// If arg1 is not 0, go to non_default action
	cout<<pad<<"nop"<<endl;
	cout<<pad<<"lw"<<"$t1, "<<arg2<<endl;
	cout<<pad<<"bne"<<"$0, $t1, "<<non_default_action<<endl; 	// If arg2 is not 0, go to non_default action
	cout<<pad<<"nop"<<endl;
	cout<<pad<<"move"<<"$t2"<<", $0"<<endl; 					// Default action reached, result is 0
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<non_default_action<<":"<<endl;
	cout<<"li"<<"$t2, 1"<<endl; 								// non-default action reached, result is 1
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<continued_exec<<":"<<endl; 							// continue execution of the program
}


void Expression::logical_and_ins(ASMhandle& context, char* destination, char* arg1, char* arg2){
	string non_default_action = context.get_label();		
	string continued_exec = context.get_label();		
	
	cout<<pad<<"lw"<<"$t0, "<<arg1<<endl;
	cout<<pad<<"beq"<<"$0, $t0, "<<non_default_action<<endl;	// If arg1 is 0, go to non_default action
	cout<<pad<<"nop"<<endl;
	cout<<pad<<"lw"<<"$t1, "<<arg2<<endl;
	cout<<pad<<"beq"<<"$0, $t1, "<<non_default_action<<endl; 	// If arg2 is 0, go to non_default action
	cout<<pad<<"nop"<<endl;
	cout<<"li"<<"$t2, 1"<<endl; 								// Default action reached, result is 1
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<non_default_action<<":"<<endl;
	cout<<pad<<"move"<<"$t2"<<", $0"<<endl; 					// non-default action reached, result is 0
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<continued_exec<<":"<<endl; 							// continue execution of the program
}


void Expression::logical_not_ins(ASMhandle& context, char* destination, char* arg){
	string non_default_action = context.get_label();		
	string continued_exec = context.get_label();		
	
	cout<<pad<<"lw"<<"$t0, "<<arg<<endl;
	cout<<pad<<"bne"<<"$0, $t0, "<<non_default_action<<endl;	// If arg1 is not 0, go to non_default action
	cout<<pad<<"nop"<<endl;
	cout<<pad<<"move"<<"$t2"<<", $0"<<endl; 					// Default action reached, result is 0
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<non_default_action<<":"<<endl;
	cout<<"li"<<"$t2, 1"<<endl; 								// non-default action reached, result is 1
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<continued_exec<<":"<<endl; 							// continue execution of the program
}

// if comparison of arg1-arg2 is true, then 1, otherwise 0
void Expression::logical_comparison_ins(ASMhandle& context, char* destination, char* arg1, char* arg2, 
														const string& instruction, const bool& subtract/*=true*/){
	string non_default_action = context.get_label();		
	string continued_exec = context.get_label();		
	
	cout<<pad<<"lw"<<"$t0, "<<arg1<<endl;
	cout<<pad<<"lw"<<"$t1, "<<arg2<<endl;
	
	if(subtract) 	cout<<pad<<"subu"<<"$t2, $t0, $t1"<<endl;
	if(subtract) 	cout<<pad<<instruction<<"$t2, "<<non_default_action<<endl;		// Branch if comparison is true
	
	if(!subtract) 	cout<<pad<<instruction<<"$t0, $t1, "<<non_default_action<<endl; // Branch if comparison is true
	cout<<pad<<"nop"<<endl;

	cout<<pad<<"move"<<"$t2"<<", $0"<<endl; 						// Default action reached, result is 0
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<non_default_action<<":"<<endl;
	cout<<"li"<<"$t2, 1"<<endl; 									// non-default action reached, result is 1
	cout<<pad<<"sw"<<"$t2, "<<destination<<endl;
	cout<<pad<<"b"<<continued_exec<<endl;
	cout<<pad<<"nop"<<endl;
	cout<<continued_exec<<":"<<endl; 								// continue execution of the program
}


void Expression::sign_ins(char* destination, char* arg, const bool& get_negative){
	cout<<pad<<"lw"<<"$t0, "<<arg<<endl;
	cout<<pad<<"sra"<<"$t1, $t0, 31"<<endl;
	cout<<pad<<"xor"<<"$t0, $t0, $t1"<<endl;
	cout<<pad<<"sub"<<"$t0, $t0, $t1"<<endl;	// Absolute value in $t0
	if(get_negative) cout<<pad<<"sub"<<"$t0, $0, $t0"<<endl;
	cout<<pad<<"sw"<<"$t0, "<<arg<<endl;
	if(destination==NULL)	cout<<pad<<"sw"<<"$t0, "<<destination<<endl;
}