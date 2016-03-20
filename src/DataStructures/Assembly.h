#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <iostream>
#include <sstream>
#include <list>
#include <string>

using std::string;
using std::stringstream;
using std::list;
using std::cout;
using std::endl;


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

