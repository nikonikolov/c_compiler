#include "Statement.h"	


/* =============================================== ASMHANDLE CLASS =============================================== */


/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

uint32_t ASMhandle::label_idx = 3;


ASMhandle::ASMhandle(const ASMhandle& orig){
	if(orig.local_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=(orig.local_vars)->begin(); it!=(orig.local_vars)->end(); ++it){
			(this->local_vars)->insert(*it);
		}
	}
	else this->local_vars = new map<string, Variable*>;

	if(orig.global_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=(orig.global_vars)->begin(); it!=(orig.global_vars)->end(); ++it){
			(this->global_vars)->insert(*it);
		}
	}
	else this->global_vars = new map<string, Variable*>;

	if(orig.functions!=NULL){
		map<string, Function*>::iterator it;
		for(it=(orig.functions)->begin(); it!=(orig.functions)->end(); ++it){
			(this->functions)->insert(*it);
		}
	}
	else this->functions = new map<string, Function*>;
	
	this->sp_offset=orig.sp_offset;
	this->allocated_mem=orig.allocated_mem;
	this->fp_offset=orig.fp_offset;
}

ASMhandle::ASMhandle(map<string, Function*>* functions_in, map<string, Variable*>* global_vars_in) :
	functions(functions_in), global_vars(global_vars_in) {
	local_vars = new map<string, Variable*>;
	
	sp_offset = 0;
	allocated_mem = 0;
	fp_offset = 0;
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE MAPS
ASMhandle::~ASMhandle(){
	if(local_vars!=NULL) delete local_vars; 
	if(global_vars!=NULL) delete global_vars; 
	if(functions!=NULL) delete functions; 
}

/* ----------------------------------------------- CODEGEN METHODS ----------------------------------------------- */

void ASMhandle::subroutine_enter(const int& mem_amount /*= 24*/){
	// Note that mem_amount is always postive integer

	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<endl; 		// Allocate memory
	cout<<pad<<"sw"<<"$fp, "<<mem_amount-4<<"($sp)"<<endl; 		// Store the value of the frame pointer on the bottom of the stack

	// Modify the frame pointer to point to the memory location above the one that stores its previous value
	cout<<pad<<"addiu"<<"$fp, $sp, "<<mem_amount-8<<endl; 			

	sp_offset = mem_amount;
	allocated_mem = mem_amount-8;
	fp_offset = 0;
}

void ASMhandle::subroutine_exit(){
	cout<<pad<<"move"<<"$fp, 4($fp)"<<endl; 								// Restore frame pointer
	cout<<pad<<"addiu"<<"$sp, $sp, "<<sp_offset<<endl; 						// Restore stack pointer		
}

void ASMhandle::allocate_mem(const int& mem_amount /*= 24*/){
	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<endl; 					// Allocate memory
	allocated_mem+=mem_amount;
}

char* ASMhandle::allocate_var(pair<string, Variable*>& var_in, const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	insert_local_var(var_in);
	char* address=strdup(string(fp_offset+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

// Used for temporaries only
char* ASMhandle::allocate_var(const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	char* address=strdup(string(fp_offset+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

// Used for destruction/deallocation of temporaries
void ASMhandle::deallocate_var(const int& mem_amount/* = 4*/){
	fp_offset-=mem_amount;
}


/* ----------------------------------------------- GETTERS AND SETTERS ----------------------------------------------- */

string ASMhandle::get_label(){
	label_idx++;
	return string("$L"+std::to_string(label_idx-1));
}

Variable* ASMhandle::get_var_location(char* name){
	map<string, Variable*>::iterator it;
	it=local_vars->find(string(name));
	if(it==local_vars->end()){
		it=global_vars->find(string(name));
		if(it==global_vars->end()) throw 1;
	}
	return (*it).second;
}


void ASMhandle::insert_local_var(pair<string, Variable*>& var_in){
	pair<map<string, Variable*>::iterator,bool> ret;
	ret = local_vars->insert(var_in);									// Put Variable* in local_vars
  	if (ret.second==false) throw ERROR_redefinition;
}

/* ----------------------------------------------- ERROR CHECKERS ----------------------------------------------- */

void ASMhandle::redefinition_check(){
	// Check for function name matching variable name
}

/* =============================================== STATEMENT CLASS =============================================== */



Statement::Statement(const StatementT& stat_type_in) : stat_type(stat_type_in){}
	
Statement::Statement(const StatementT& stat_type_in, const int& line_in, const string& src_file_in) :
	stat_type(stat_type_in), line(line_in), src_file(src_file_in) {}

Statement::~Statement(){}

void Statement::set_stat_type(const StatementT& stat_type_in){
	stat_type=stat_type_in;
}
StatementT Statement::get_stat_type() const{
	return stat_type;
}

void Statement::generate_error(){
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : ";
}