#ifndef TEMPORARY_H
#define TEMPORARY_H

#include "include.h"
#include "ExprResult.h"

class Temporary : public ExprResult{

public:
	Temporary();
	Temporary(char* mem_location_in, char* reg_location_in = NULL);
	~Temporary();

	void load(const string& dest_reg);
	void store_from_mem(const string& dest_mem_location);
	void store(const string& reg_location_in);

private:
	stringstream ss;
};




#endif

