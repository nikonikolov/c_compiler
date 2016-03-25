#include "AddressExpression.h"

// Memory leak at strdup
AddressExpression::AddressExpression(BaseExpression* expr_in, const int& line_in, const string& src_file_in) :
	Expression(NULL, strdup("&"), expr_in, EXPR_address_expr, line_in, src_file_in) {}

AddressExpression::~AddressExpression(){}

void AddressExpression::renderasm(ASMhandle& context, ExprResult** dest /*=NULL*/){
	if(dest==NULL) return;

	if(rhs->get_expr_type()!=EXPR_tmp_var && rhs->get_expr_type()!=EXPR_dereference_expr){
		generate_error("Cannot take the address of a temporary");
	}

	ExprResult** mem_location = new ExprResult*(NULL);
	rhs->renderasm(context, mem_location);

	// *dest!=NULL when renderasm is called by a Variable at the time of assigning new value to it
	// *dest is NULL when you have assignments expressions of the type ptr=&a or
	// when you have nested Address and Dereference expressions of the type &(*(&a)). This one is &a in the example
	
	if(*dest==NULL)	*dest = new Temporary(context.allocate_var()); 		

	// when you have nested Address and Dereference expressions of the type &(*(&a)). This one is &a in the example
	if(rhs->get_expr_type()==EXPR_dereference_expr){
		//char* address_value=(*mem_location)->get_mem_location();
		//assembler.push_back(ss<<pad<<"lw"<<"$t0, "<<address_value<<endl);
		ExprResult* to_cast = *mem_location;
		Pointer* tmp = static_cast<Pointer*>(to_cast);
		tmp->load_memory_location("$t0");
		(*dest)->store("$t0");
	}
	else{
		string location = string((*mem_location)->get_mem_location());
		size_t lbracket = location.find("(");
		size_t rbracket = location.find(")");
		string offset = location.substr(0,lbracket);
		string address = location.substr(lbracket+1, rbracket-lbracket-1);
		assembler.push_back(ss<<pad<<"addiu"<<"$t0, "<<address<<", "<<offset<<endl);
		(*dest)->store("$t0");
	}
	if((*mem_location)->get_result_type()==RESULT_tmp || (*mem_location)->get_result_type()==RESULT_ptr) delete *mem_location;
	delete mem_location;
}


