#ifndef POINTER_H
#define POINTER_H

#include "include.h"
#include "ExprResult.h"
#include "Statement.h"

class Pointer : public ExprResult{

public:
	Pointer();
	Pointer(ExprResult* expr_res_in, ASMhandle& context); 
	~Pointer();

	void load_memory_location(const string& dest_reg);
	void load(const string& dest_reg);
	void store_from_mem(const string& dest_mem_location);
	void store(const string& reg_location_in);

private:
	stringstream ss;
};




#endif

