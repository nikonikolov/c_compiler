#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <list>

using namespace std;

extern int input_file_line;
extern int source_file_line;
extern string source_file;


void process_prep_include(const string& content);

template<class T>
void list_push_to_front(list<T>*& headptr, const T& element){
	if(headptr==NULL){
		headptr = new list<T>;
		headptr->push_front(element);
	}
	else headptr->push_front(element);
}


#endif


