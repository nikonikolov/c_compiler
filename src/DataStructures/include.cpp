#include "include.h"

Assembly assembler;

std::ostream& pad(std::ostream& os) {
	return os <<"\t"<<std::left<< std::setfill(' ') << std::setw(8);
}

void snum_t::operator=(const snum_t& obj_in){
	if(this != &obj_in){
		this->tname = obj_in.tname;
		this->numval = obj_in.numval;
	}
}
