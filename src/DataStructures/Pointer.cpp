#include "Pointer.h"

Pointer::Pointer() : ExprResult(RESULT_ptr) {}

Pointer::Pointer(ExprResult* expr_res_in, ASMhandle& context) : 
	ExprResult(RESULT_ptr){
	if(expr_res_in->get_result_type()!=RESULT_const) set_mem_location(expr_res_in->get_mem_location());
	else{
		set_mem_location(context.allocate_var());
		expr_res_in->load("$t6");
		assembler.push_back(ss<<pad<<"sw"<<"$t6, "<<mem_location<<endl);
	}
}

Pointer::~Pointer(){
}

void Pointer::load(const string& dest_reg){
	assembler.push_back(ss<<pad<<"lw"<<"$t6, "<<mem_location<<endl);
	assembler.push_back(ss<<pad<<"lw"<<dest_reg<<", 0($t6)"<<endl);
}

void Pointer::store(const string& reg_location_in){
	assembler.push_back(ss<<pad<<"lw"<<"$t6, "<<mem_location<<endl);
	assembler.push_back(ss<<pad<<"sw"<<reg_location_in<<", 0($t6)"<<endl);
}

void Pointer::store_from_mem(const string& dest_mem_location){
	assembler.push_back(ss<<pad<<"lw"<<"$t7, "<<mem_location<<endl);
	assembler.push_back(ss<<pad<<"sw"<<"$t7, "<<dest_mem_location<<endl);
}
