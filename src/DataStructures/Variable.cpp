#include "Variable.h"


Variable::Variable(char* type_name_in, char* name_in, BaseExpression* init_val_in /*=NULL*/) :
	BaseExpression(ST_var_declaration), init_val(init_val_in), dereferencer(NULL) {
		type_name = strdup(type_name_in);
		name = strdup(name_in);
}

Variable::Variable(char* name_in, BaseExpression* init_val_in /*=NULL*/) :
	BaseExpression(ST_var_expr), init_val(init_val_in), dereferencer(NULL){
	name = strdup(name_in);
}

Variable::Variable(char* some_name_in, const StatementT& stat_type_in, list<PtrDeref>* dereferencer_in /*=NULL*/) :
	BaseExpression(stat_type_in){
	cerr<<"variable declaration"<<endl;
	if(stat_type_in==ST_var_return) 		type_name = strdup(some_name_in);
	if(stat_type_in==ST_var_declaration) 	name = strdup(some_name_in);
	cerr<<"exiting declaration"<<endl;
}
/*
Variable::Variable(char* type_name_in, const StatementT& stat_type_in, list<PtrDeref>* dereferencer_in/*=NULL) :
	BaseExpression(stat_type_in), init_val(NULL), dereferencer(dereferencer_in){
	type_name = strdup(type_name_in);
}
*/

Variable::Variable(char* type_name_in, char* name_in, const StatementT& stat_type_in, list<PtrDeref>* dereferencer_in/*=NULL*/) :
	BaseExpression(stat_type_in), init_val(NULL), dereferencer(dereferencer_in){
	type_name = strdup(type_name_in);
	name = strdup(name_in);
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


void Variable::set_type_name(char* type_name_in){
	type_name=strdup(type_name_in);
}

void Variable::set_init_val(BaseExpression* init_val_in){
	init_val=init_val_in;
}

const char* Variable::get_name() const{
	return name;
}

void Variable::pretty_print(const int& indent) const{
	string white_space;
	white_space.resize(indent, ' ');
	cout<<white_space<<name;
}

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


