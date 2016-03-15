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

void Variable::set_asm_location(const string& str_in){
	location=strdup(str_in.c_str());
}

bool Variable::get_initialized() const{
	return initialized;
}


/* ================================================== VIRTUAL OVERRIDE ================================================== */


void Variable::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;
}


void Variable::renderasm(ASMhandle& context){
	if(initialized) return;
	initialized = true;
	if(init_val==NULL) return;/*{
		context->stack_offset+=4;
		cout<<"\taddiu $sp, $sp, 4"<<endl;
		location = stack_offset+"($sp)";
	} */
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







