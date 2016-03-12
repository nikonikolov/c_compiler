#include "Statement.h"	

Statement::Statement(const StatementT stat_type_in) : stat_type(stat_type_in){}
	
Statement::~Statement(){}

void Statement::set_stat_type(const StatementT& stat_type_in){
	stat_type=stat_type_in;
}
StatementT Statement::get_stat_type() const{
	return stat_type;
}

