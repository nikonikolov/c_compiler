#include "Temporary.h"

Temporary::Temporary() : ExprResult(RESULT_tmp) {}

Temporary::Temporary(char* mem_location_in, char* reg_location_in /*=NULL*/ ) : 
	ExprResult(RESULT_tmp, mem_location_in, reg_location_in) {}

Temporary::~Temporary(){
}

void Temporary::load(const string& dest_reg){
	assembler.push_back(ss<<pad<<"lw"<<dest_reg<<", "<<mem_location<<endl);
}

void Temporary::store(const string& reg_location_in){
	assembler.push_back(ss<<pad<<"sw"<<reg_location_in<<", "<<mem_location<<endl);
}

void Temporary::store_from_mem(const string& dest_mem_location){
	assembler.push_back(ss<<pad<<"lw"<<"$t7, "<<mem_location<<endl);
	assembler.push_back(ss<<pad<<"sw"<<"$t7, "<<dest_mem_location<<endl);
}
