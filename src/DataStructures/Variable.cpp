#include "Variable.h"

bool Variable::first_global = true;
/*
Variable::Variable(char* name_in) :
	ExprResult(RESULT_var), type_name(NULL), init_val(NULL), dereferencer(NULL), initialized(false) {
		name = strdup(name_in);
}

Variable::Variable(char* name_in, const int& line_in, const string& src_file_in) : 
	ExprResult(RESULT_var), type_name(NULL), init_val(NULL), line(line_in), src_file(src_file_in) {
	name = strdup(name_in);
}

*/

Variable::Variable(char* type_name_in, char* name_in) :
	ExprResult(RESULT_var), init_val(NULL) {
	if(name_in!=NULL) name = strdup(name_in);
	if(type_name_in!=NULL) type_name = strdup(type_name_in);
}


Variable::Variable(char* type_name_in, char* name_in, const int& line_in, const string& src_file_in) : 
	ExprResult(RESULT_var), line(line_in), src_file(src_file_in),
	init_val(NULL) {
	if(name_in!=NULL) name = strdup(name_in);
	if(type_name_in!=NULL) type_name = strdup(type_name_in);
}


Variable::~Variable(){
	if(init_val!=NULL) 	delete init_val;
	if(size!=NULL) 		delete size;
	if(type_name!=NULL) free(type_name);
	if(name!=NULL) 		free(name);
}

/* ================================================== GETTERS AND SETTERS ================================================== */


void Variable::set_type_name(char* type_name_in){
	type_name=strdup(type_name_in);
}

void Variable::set_init_val(BaseExpression* init_val_in){
	init_val=init_val_in;
}

const char* Variable::get_name() const{
	return name;
}

string Variable::get_name_str() const{
	return string(name);
}

void Variable::set_asm_location(const string& str_in){
	set_asm_location(str_in.c_str());
}

void Variable::set_asm_location(char* str_in){
	mem_location=strdup(str_in);
	initialized = true;							// When called by function parameters
}

/* ================================================== GLOBALLY USED METHODS ================================================== */


void Variable::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;

	if(init_val!=NULL){
		cout<<" = ";
		init_val->pretty_print(0);
	}
}


void Variable::renderasm(ASMhandle& context, const bool& local /*=true*/){
	if(debug) cerr<<"Variable: renderasm start"<<endl;
	
	if(initialized) return;
	initialized = true;
	// Variable local
	if(local){
		try{	// Allocate variable on the stack
			pair<string, Variable*> tmp(string(name), this);
			mem_location = context.allocate_var(tmp);
		}
		catch(const ErrorgenT& error_in){
			generate_error("Redefinition of variable \""+string(name)+"\"");
		}
		if(init_val==NULL) return;
		if(init_val->get_expr_type()==EXPR_assignment_expr) generate_error("Invalid syntax for variable initialization value");
		simplify_init_val();

		// Automatically assigns the value to the Variable location by invoking store
		ExprResult** dest = new ExprResult*(this);
		init_val->renderasm(context, dest);
	
		delete dest;
		if(debug) cerr<<"Variable: renderasm successful"<<endl;
	}

	// Variable global
	else renderasm_global(context);

}

/* ================================================== GLOBAL SCOPE RELATED ================================================== */

void Variable::renderasm_global(ASMhandle& context){
	if(debug) cerr<<"Variable: renderasm_global start"<<endl;
	
	global=true;
	try{
		pair<string, Variable*> tmp(string(name), this);
		context.insert_global_var(tmp);
	}
	catch(const ErrorgenT& error_in){
		if(error_in == ERROR_redefinition) generate_error("Redefinition of global variable \""+string(name)+"\"");
		if(error_in == ERROR_fn_var_clash) generate_error("\""+string(name)+"\" redeclared as different kind of symbol");
	}

	if(debug) cerr<<"Variable: renderasm_global(): variable inserted in ASMhandle"<<endl;

	if(init_val!=NULL){
		// Try to optimize the expression if not already a Constant
		simplify_init_val();
		if(init_val->get_expr_type()!=EXPR_constant) generate_error("Initializer for global variable not constant");
		if(debug) cerr<<"Variable: renderasm_global() : initializer expression optimized"<<endl;
	}

	assembler.push_back(ss<<pad<<".globl"<<name<<endl);
	if(first_global){
		first_global=false;
		assembler.push_back(ss<<pad<<".data"<<endl);
	}
	
	assembler.push_back(ss<<pad<<".align"<<2<<endl);
	assembler.push_back(ss<<pad<<".type"<<name<<", @object"<<endl);
	assembler.push_back(ss<<pad<<".size"<<name<<", 4"<<endl);
	assembler.push_back(ss<<name<<":"<<endl);
	if(init_val!=NULL && init_val->get_expr_type()==EXPR_constant){
		Constant<uint64_t> *value = static_cast<Constant<uint64_t>*>(init_val);		
		assembler.push_back(ss<<pad<<".word"<<value->get_value()<<endl);
	} 
	assembler.push_back(ss<<endl);

	if(debug) cerr<<"Variable: renderasm_global successful"<<endl;
}

/* ================================================== ExprResult METHODS ================================================== */

void Variable::load(const string& dest_reg){
	if(!global) assembler.push_back(ss<<pad<<"lw"<<dest_reg<<", "<<mem_location<<endl);
	else{
		assembler.push_back(ss<<pad<<"lui"<<"$t9"<<", %hi("<<name<<")"<<endl);
		assembler.push_back(ss<<pad<<"lw"<<dest_reg<<", %lo("<<name<<")($t9)"<<endl);
	}
}

void Variable::store_from_mem(const string& dest_mem_location){
	if(!global){
		assembler.push_back(ss<<pad<<"lw"<<"$t0, "<<mem_location<<endl);
		assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<dest_mem_location<<endl);
	} 
	else{
		assembler.push_back(ss<<pad<<"lui"<<"$t9"<<", %hi("<<name<<")"<<endl);
		assembler.push_back(ss<<pad<<"lw"<<"$t8"<<", %lo("<<name<<")($t9)"<<endl);
		assembler.push_back(ss<<pad<<"sw"<<"$t8, "<<dest_mem_location<<endl);
	}
}

void Variable::store(const string& reg_location_in){
	if(!global) assembler.push_back(ss<<pad<<"sw"<<reg_location_in<<", "<<mem_location<<endl);
	else{
		assembler.push_back(ss<<pad<<"lui"<<"$t9"<<", %hi("<<name<<")"<<endl);
		assembler.push_back(ss<<pad<<"sw"<<reg_location_in<<", %lo("<<name<<")($t9)"<<endl);
	}
}


/* ================================================== POINTER RELATED ================================================== */

void Variable::inc_deref_lvl(const int& increment){
	dereference_level+=increment;
}

void Variable::inc_array_size(BaseExpression* dim_size){
	if(size==NULL) size = new vector<int>;
	
	dereference_level++;

	if(dim_size==NULL){
		size->push_back(0);
		return;
	} 

	BaseExpression* tmp_expr=NULL;
	try{
		tmp_expr = dim_size->simplify();
		if(tmp_expr!=NULL){
			delete dim_size;
			dim_size = tmp_expr; 		
			if(tmp_expr->get_expr_type()!=EXPR_constant) generate_error("Variable size array not allowed");
			Constant<uint64_t>* value = static_cast<Constant<uint64_t>*>(tmp_expr);		
			size->push_back((int)value->get_value());
		}
	}
	catch(const int& exception_in){
		generate_error("Invalid array dimensions size");
	}
}


/* ================================================== ERROR GENERATIONS ================================================== */

void Variable::generate_error(const string& msg_out){
	cerr<<endl;
  	cerr<<"========================================= ERROR ========================================="<<endl;
  	cerr<<endl;
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : "<<msg_out<<endl;
	exit(EXIT_FAILURE);
}

/* ================================================== PRIVATE ================================================== */

void Variable::simplify_init_val(){
	if(debug) cerr<<"Variable: simplify_init_val(): starting initializer optimization"<<endl;
	BaseExpression* tmp_expr=NULL;
	try{
		if(init_val!=NULL){
			tmp_expr = init_val->simplify();
			if(tmp_expr!=NULL){
				delete init_val;
				init_val = tmp_expr; 		
			}
		} 
	}
	catch(const int& exception_in){}
}




