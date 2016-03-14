/*#ifndef ASMHANDLE_H
#define ASMHANDLE_H

#include <vector>
using std::vector;

class Variable;

struct ASMhandle{
	ASMhandle(ASMhandle* orig);
	~ASMhandle();

	int stack_offset;
	vector<Variable*>* vars;	
};


#endif

*/