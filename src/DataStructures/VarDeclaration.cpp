#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(vector<Variable*>* variables_in) : 
	variables(variables_in) {}

VarDeclaration::VarDeclaration(char* type_name_in, vector<Variable*>* variables_in) : 
	variables(variables_in) {
	set_types(type_name_in);
}

VarDeclaration::VarDeclaration(vector<Variable*>* variables_in, const int& line_in, const string& src_file_in) :
	variables(variables_in), line(line_in), src_file(src_file_in) {}

VarDeclaration::VarDeclaration(char* type_name_in, vector<Variable*>* variables_in, const int& line_in, const string& src_file_in) : 
	variables(variables_in), line(line_in), src_file(src_file_in) {
	set_types(type_name_in);
}

VarDeclaration::~VarDeclaration(){
	if(variables!=NULL){
		vector<Variable*>::iterator it;
		for(it=variables->begin(); it!=variables->end(); ++it){
			delete *it;
		}
		delete variables;
	}
}

void VarDeclaration::generate_error(const string& msg_out){
	cerr<<endl;
  	cerr<<"========================================= ERROR ========================================="<<endl;
  	cerr<<endl;
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : "<<msg_out<<endl;
	exit(EXIT_FAILURE);
}


void VarDeclaration::set_types(char* type_name_in){
	if(variables==NULL) return;
	vector<Variable*>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		(*it)->set_type_name(type_name_in);
	}
}


void VarDeclaration::pretty_print(const int& indent){
	string white_space;
	white_space.resize(indent, ' ');
	if(variables==NULL) return;

	// Print the name of variables defined in this Statement
	vector<Variable*>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		cout<<white_space<<"VARIABLE : ";
		(*it)->pretty_print(0);
		cout<<endl;
	}
}


void VarDeclaration::renderasm(ASMhandle& context, const bool& local /*=true*/){
	vector<Variable*>::iterator it;
	for(it=variables->begin(); it!=variables->end(); ++it){
		(*it)->renderasm(context, local);
	}
}