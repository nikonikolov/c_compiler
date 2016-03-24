#ifndef EXPRRESULT_H
#define EXPRRESULT_H

#include "include.h"

class ExprResult{

public:
	ExprResult(const ResultT& res_type_in, char* mem_location_in = NULL, char* reg_location_in = NULL);
	virtual ~ExprResult();

	ResultT get_result_type() const;

	void set_reg_location(char* reg_location_in);
	void set_mem_location(char* mem_location_in);

	virtual void load(const string& dest_reg) =0;
	virtual void store(const string& reg_location_in) =0;
	// When the value of the object is not loaded in any register
	virtual void store_from_mem(const string& dest_mem_location) =0;

protected:
	char* mem_location;
	char* reg_location;

	ResultT res_type;
};




#endif

