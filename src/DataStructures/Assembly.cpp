#include "Assembly.h"

Assembly::Assembly(){
	instructions = new list<string>;
}

Assembly::~Assembly(){
	if(instructions!=NULL)	delete instructions;	
}

void Assembly::push_back(stringstream& ss){
	string line;
	while( getline(ss, line, '\n') ){
    	instructions->push_back(line+"\n");
	}
}

void Assembly::print(){
	list<string>::iterator it;
	for(it=instructions->begin(); it!=instructions->end(); ++it){
		cout<<(*it);
		//cout<<(*it)<<endl;
	}

}
