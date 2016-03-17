#include "Variable.h"


Variable::Variable(char* name_in) :
	type_name(NULL), init_val(NULL), dereferencer(NULL), initialized(false), location(NULL) {
		name = strdup(name_in);
}

Variable::Variable(char* type_name_in, char* name_in, list<PtrDeref>* dereferencer_in/*=NULL*/) :
	init_val(NULL), dereferencer(dereferencer_in), initialized(false), location(NULL) {
	type_name = strdup(type_name_in);
	if(name_in!=NULL) name = strdup(name_in);
}


Variable::~Variable(){
	if(init_val!=NULL) delete init_val;

	if(dereferencer!=NULL){
		list<PtrDeref>::iterator it;
		for(it=dereferencer->begin(); it!=dereferencer->end(); ++it){
			delete (*it).first;
		}
		delete dereferencer;
	}
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
	location=strdup(str_in.c_str());
}

void Variable::set_asm_location(char* str_in){
	location=strdup(str_in);
	initialized = true;			// Called by function parameters
}

/*void Variable::get_asm_location(char** location_in){
	location_in = &location;
}
*/
char* Variable::get_asm_location(){
	return location;
}

bool Variable::get_initialized() const{
	return initialized;
}

void Variable::init_asm_name(){
	strcpy(asm_name, "abcdefg");
	strcat(asm_name, name);
}

void Variable::generate_error(){
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : Redefinition of variable \""<<name<<"\""<<endl;
	exit(EXIT_FAILURE);
}



/* ================================================== VIRTUAL OVERRIDE ================================================== */


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
	if(initialized) return;
	initialized = true;
	// Variable local
	if(local){
		try{	// Allocate variable on the stack
			pair<string, Variable*> tmp(string(name), this);
			location = context.allocate_var(tmp);
		//	location = context.allocate_var(&location, tmp);
		}
		catch(const ErrorgenT& error_in){
			generate_error();
		}
		if(init_val==NULL) return;
		simplify_init_val();
		init_val->renderasm(context, &location);
	}
	// Variable global
	else{

	}
}



/* ================================================== POINTER RELATED ================================================== */

// You should probably use a tuple of 3 rather than a pair. 
//The third code should tell you how to deduce the size. Do it when pointers come up
void Variable::dereference_back(BaseExpression* expr_in, const int& size/*=INTNAN*/){
	if(dereferencer==NULL) dereferencer = new list<PtrDeref>;
	dereferencer->push_back(PtrDeref(expr_in,size));
}

void Variable::dereference_front(BaseExpression* expr_in, const int& size/*=INTNAN*/){
	if(dereferencer==NULL) dereferencer = new list<PtrDeref>;
	dereferencer->push_front(PtrDeref(expr_in,size));
}


/* ================================================== PRIVATE ================================================== */

void Variable::simplify_init_val(){
	BaseExpression* tmp_expr=NULL;
	try{
		if(init_val!=NULL){
			snum_t tmp;
			tmp_expr = init_val->simplify(tmp);
			if(tmp_expr!=NULL){
				delete init_val;
				init_val = tmp_expr; 		// In case LHS was not simplified
			}
		} 
	}
	catch(const int& exception_in){}
}




