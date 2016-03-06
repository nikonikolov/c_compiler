#include "Variable.h"


Variable::Variable(char* type_name_in, char* name_in, Expression* init_val_in /*=NULL*/) :
	Expression(ST_var_declaration), init_val(init_val_in), dereferencer(NULL) {
		type_name = strdup(type_name_in);
		name = strdup(name_in);
}

Variable::Variable(char* name_in, Expression* init_val_in /*=NULL*/) :
	Expression(ST_var_expr), init_val(init_val_in), dereferencer(NULL){
	name = strdup(name_in);
}

Variable::Variable(char* some_name_in, const StatementT& stat_type_in, list<Expression*>* dereferencer_in= /*=NULL*/) :
	Expression(stat_type_in){
	if(stat_type_in==ST_var_return) 		type_name = strdup(some_name_in);
	if(stat_type_in==ST_var_declaration) 	name = strdup(some_name_in);
}
/*
Variable::Variable(char* type_name_in, const StatementT& stat_type_in, list<Expression*>* dereferencer_in/*=NULL) :
	Expression(stat_type_in), init_val(NULL), dereferencer(dereferencer_in){
	type_name = strdup(type_name_in);
}
*/

Variable::Variable(char* type_name_in, char* name_in, const StatementT& stat_type_in, list<Expression*>* dereferencer_in/*=NULL*/) :
	Expression(stat_type_in), init_val(NULL), dereferencer(dereferencer_in){
	type_name = strdup(type_name_in);
	name = strdup(name_in);
}

Variable::~Variable(){
	if(init_val!=NULL) delete init_val;

	if(dereferencer!=NULL){
		list<Expression*>::iterator it;
		for(it=dereferencer->begin(); it!=dereferencer->end(); ++it){
			delete *it;
		}
		delete dereferencer;
	}
}


void Variable::set_type_name(char* type_name_in){
	type_name=strdup(type_name_in);
}

void Variable::set_init_val(Expression* init_val_in){
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

void Variable::dereference_back(Expression* expr_in){
	if(dereferencer==NULL) dereferencer = new list<Expression*>;
	dereferencer->push_back(expr_in);
}

void Variable::dereference_front(Expression* expr_in){
	if(dereferencer==NULL) dereferencer = new list<Expression*>;
	dereferencer->push_front(expr_in);
}


