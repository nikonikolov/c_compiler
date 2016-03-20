#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "include.h"

class Assembly{

public:
	Assembly();
	~Assembly();

	void push_back(stringstream& ss);

	void print();

private:
	// Add iterators to keep track of data, global vars, strings, etc
	//list<string>::iterator assembly;
	
	list<string>* instructions;
};



#endif

