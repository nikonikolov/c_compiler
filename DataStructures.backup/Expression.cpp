#include "Expression.h"


Expression::Expression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) : 
	BaseExpression(EXPR_expression), lhs(lhs_in), rhs(rhs_in) {
	oper = strdup(oper_in);
}

Expression::Expression(const int& line_in, char* src_file_in, BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) :
	BaseExpression(EXPR_expression), lhs(lhs_in), rhs(rhs_in), line(line_in), src_file(src_file_in) {
	oper = strdup(oper_in);
}

Expression::~Expression(){
	if(lhs!=NULL) delete lhs;		// Note that destructors for the objects down the tree get recursively called
	if(rhs!=NULL) delete rhs;
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


void Expression::renderasm(ASMhandle* context){
}

// Add support for other types later
void Expression::init_subexpr(BaseExpression* expr_ptr, const snum_t& result){
	if(result.tname==tint) expr_ptr = new Constant<int>(result.number.intval);
	if(result.tname==tdouble) expr_ptr = new Constant<double>(result.number.doubleval);
	if(result.tname==tldouble) expr_ptr = new Constant<float>(result.number.ldoubleval);
	if(result.tname==tfloat) expr_ptr = new Constant<float>(result.number.floatval);
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

string Expression::gen_error() const{
	string result = "Error in file " + src_file +" at line " + std::to_string(line) + " around symbol " + oper;
	return result;
}

// Note the top level is the caller to eval and the caller has to handle the exception. Usually that would be renderasm(ASMhandle* context)
// Note you cannot have Constant as return type as this is a pure virtual function defined in BaseExpression which cannot have
// visibility of the Constant class
/*snum_t Expression::eval(){
	snum_t lhs_result, rhs_result;
	int exception = 0;
	
	// Optimize LHS
	try{
		if(lhs!=NULL){
			lhs_result = lhs->eval();
			delete lhs;
			init_subexpr(lhs, lhs_result);
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}

	// Optimize RHS
	try{
		if(rhs!=NULL){
			rhs_result = rhs->eval();
			delete rhs;
			init_subexpr(rhs, rhs_result);
		} 
	}
	catch(const int& exception_in){
		exception = exception_in;
	}

	if(exception) throw exception;

	/* 	Do the casting: Find the higher precedence, deallocate old Constant and create a new one cast to the required type.
	 	Note you will need to perform semantics checks before making the operation as well. E.g. - you cannot shift by a double 
		value, you cannot assign integer to a struct, etc.
	
	
	snum_t returnval;
	returnval.tname = tint;
	if(oper=="+"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(+(rhs->eval())); 
			return returnval;
		}
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() + rhs->eval()); 
			return returnval;
		}
		throw gen_error();
	}	
	if(oper=="-"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(-(rhs->eval())); 
			return returnval;
		}
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() - rhs->eval()); 
			return returnval;
		}
		throw gen_error();
	}	
	if(oper=="*"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(*(rhs->eval())); 
			return returnval;
		}
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() * rhs->eval()); 
			return returnval;
		}
		throw gen_error();
	}	
	if(oper=="%"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() % rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="/"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() / rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="|"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() | rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="&"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() & rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="^"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() ^ rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="||"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() || rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="&&"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() && rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="<<"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() << rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper==">>"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() >> rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="<="){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() <= rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper==">="){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() >= rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper==">"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() > rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="<"){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() < rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="=="){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() == rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}	
	if(oper=="!="){
		if(lhs!=NULL && rhs!=NULL){
			returnval.number.intval=(lhs->eval() != rhs->eval()); 
			return returnval;
		}
		throw gen_error();	
	}

	// SINGLE OPERAND EXPRESSIONS
	if(oper=="++"){
		if((lhs==NULL && rhs==NULL) || (lhs!=NULL && rhs!=NULL)) throw gen_error();
		if(lhs!=NULL){
			returnval.number.intval=((lhs->eval())++); 
			return returnval;
		}
		if(rhs!=NULL){ 
			returnval.number.intval=(++(rhs->eval())); 
			return returnval;
		}
	}	
	if(oper=="--"){
		if((lhs==NULL && rhs==NULL) || (lhs!=NULL && rhs!=NULL)) throw gen_error();
		if(lhs!=NULL){ 
			returnval.number.intval=((lhs->eval())--); 
			return returnval;
		}
		if(rhs!=NULL){ 
			returnval.number.intval=(++(rhs->eval())); 
			return returnval;
		}
	}	
	if(oper=="!"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(!(rhs->eval())); 
			return returnval;
		}
		throw gen_error();
	}	
	if(oper=="~"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(~(rhs->eval())); 
			return returnval;
		}
		throw gen_error();
	}	
	if(oper=="sizeof"){
		if(lhs==NULL && rhs!=NULL){
			returnval.number.intval=(sizeof(rhs->eval())); 
			return returnval;
		}
		throw gen_error();
	}	

	throw gen_error();
}
*/