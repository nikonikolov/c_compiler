#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <sstream>
#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>

using std::list;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

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



// Appends the second vector at the end of the first one and accounts for memory leaks
template<class T>
vector<T>* vec_append(vector<T>*& vec1, vector<T>*& vec2){
	
	typename vector<T>::iterator it;
	for(it=vec2->begin(); it!=vec2->end(); ++it){
		vec1->push_back(*it);
	}

	// Note you only need to delete the dynamically allocated vector. 
	// You want to keep the objects the pointers inside the vector point to
	delete vec2;

	return vec1;
}


/*
// Appends the second vector at the end of the first one and accounts for memory leaks
template<class T>
vector<T*>* vec_append(vector<T*>*& vec1, vector<T*>*& vec2){
	
	typename vector<T*>::iterator it;
	for(it=vec2->begin(); it!=vec2->end(); ++it){
		vec1->push_back(*it);
	}

	// Note you only need to delete the dynamically allocated vector. 
	// You want to keep the objects the pointers inside the vector point to
	delete vec2;

	return vec1;
}
*/
#endif


