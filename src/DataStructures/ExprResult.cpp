#include "ExprResult.h"

ExprResult::ExprResult(const ResultT& res_type_in, char* mem_location_in /*=NULL*/, char* reg_location_in /*=NULL*/) :	
	res_type(res_type_in){
	if(mem_location_in!=NULL) mem_location = strdup(mem_location_in);
	else mem_location = NULL;
	if(reg_location_in!=NULL) reg_location = strdup(reg_location_in);
	else reg_location = NULL;
} 

ResultT ExprResult::get_result_type() const{
	return res_type;
}


void ExprResult::set_reg_location(char* reg_location_in){
	if(reg_location_in!=NULL) reg_location = strdup(reg_location_in);
}

void ExprResult::set_mem_location(char* mem_location_in){
	if(mem_location_in!=NULL) mem_location = strdup(mem_location_in);
}

char* ExprResult::get_mem_location(){
	return mem_location;
}

ExprResult::~ExprResult(){
	if(mem_location!=NULL) free(mem_location);
	if(reg_location!=NULL) free(reg_location);
}



