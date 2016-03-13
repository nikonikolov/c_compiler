#ifndef ASMHANDLE_H
#define ASMHANDLE_H

#include "Variable.h"
#include <vector>
using std::vector;

struct ASMhandle{
	int stack_offset;
	vector<Variable*>* vars;	
};




#endif

