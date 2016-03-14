#include "Statement.h"	

ASMhandle::ASMhandle(ASMhandle* orig){
	if(orig->vars!=NULL){
		vector<Variable*>::iterator it;
		for(it=(orig->vars)->begin(); it!=(orig->vars)->end(); ++it){
			(this->vars)->push_back(*it);
		}
	}

	this->stack_offset=orig->stack_offset;
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE VECTOR
ASMhandle::~ASMhandle(){}

void ASMhandle::redefinition_check(){

}


Statement::Statement(const StatementT stat_type_in) : stat_type(stat_type_in){}
	
Statement::~Statement(){}

void Statement::set_stat_type(const StatementT& stat_type_in){
	stat_type=stat_type_in;
}
StatementT Statement::get_stat_type() const{
	return stat_type;
}

