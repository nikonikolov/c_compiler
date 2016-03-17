#include "Statement.h"	


/* =============================================== ASMHANDLE CLASS =============================================== */


/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

uint32_t ASMhandle::label_idx = 3;

/*
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
	
	this->return_address = new stack<string>(*(orig.return_address));

	this->sp_offset=orig.sp_offset;
	this->allocated_mem=orig.allocated_mem;
	this->fp_offset=orig.fp_offset;
	cerr<<"Local vars done"<<endl;
}
*/
ASMhandle::ASMhandle(ASMhandle& orig){
	local_vars = new map<string, Variable*>;
	if(orig.local_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=(orig.local_vars)->begin(); it!=(orig.local_vars)->end(); ++it){
			(local_vars)->insert(*it);
		}
	}

	global_vars = new map<string, Variable*>;
	if(orig.global_vars!=NULL){
		map<string, Variable*>::iterator it;
		for(it=(orig.global_vars)->begin(); it!=(orig.global_vars)->end(); ++it){
			(global_vars)->insert(*it);
		}
	}
	
	functions = new map<string, Function*>;
	if(orig.functions!=NULL){
		map<string, Function*>::iterator it;
		for(it=(orig.functions)->begin(); it!=(orig.functions)->end(); ++it){
			(functions)->insert(*it);
		}
	}
	
	return_address = new stack<string>(*(orig.return_address));
	
	sp_offset=orig.sp_offset;
	allocated_mem=orig.allocated_mem;
	fp_offset=orig.fp_offset;
}


ASMhandle::ASMhandle(map<string, Function*>* functions_in) :
	functions(functions_in) {
	global_vars = new map<string, Variable*>;
	local_vars = new map<string, Variable*>;
	return_address = new stack<string>;
	
	sp_offset = 0;
	allocated_mem = 0;
	fp_offset = 0;
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE MAPS
ASMhandle::~ASMhandle(){
	if(local_vars!=NULL) delete local_vars; 
	if(global_vars!=NULL) delete global_vars; 
	if(functions!=NULL) delete functions; 
	if(return_address!=NULL) delete return_address; 
}

/* ----------------------------------------------- CODEGEN METHODS ----------------------------------------------- */

void ASMhandle::subroutine_enter(const int& mem_amount /*= 24*/){
	// Note that mem_amount is always postive integer

	sp_offset = mem_amount;
	allocated_mem = mem_amount-8;
	fp_offset = 0;

	// Allocate memory on the stack
	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<"\t\t# Allocate memory on the stack"<<endl; 		
	// Store the value of the frame pointer on the bottom of the stack
	cout<<pad<<"sw"<<"$fp, "<<mem_amount-4<<"($sp)"<<"\t\t# Store value of fp on the bottom of the stack"<<endl; 		

	// Modify the frame pointer to point to the memory location above the one that stores its previous value
	cout<<pad<<"addiu"<<"$fp, $sp, "<<mem_amount-8<<"\t\t# Modify fp to point to the the bottom of the available stack memory"<<endl; 			

	// You should push this to a new method that gets called only on function calls
	string ret_address = allocate_str_var();
	cout<<pad<<"sw"<<"$ra, "<<ret_address<<"\t\t# Store the return address for the subroutine"<<endl;
	return_address->push(ret_address);
	
}

void ASMhandle::subroutine_exit(char* return_val){
	cout<<pad<<"lw"<<"$v0, "<<return_val<<endl;								// Load return value

	string ret_address = return_address->top();								// Ger return address
	return_address->pop();

	// Load return address
	cout<<pad<<"lw"<<"$ra, "<<ret_address<<"\t\t# Load return address in register 31"<<endl;
	//cout<<pad<<"lw"<<"$2, "<<ret_address<<"\t\t# Load return address in register 31"<<endl;

	// Restore frame pointer. This should be load and should be -4
	//cout<<pad<<"move"<<"$fp, 4($fp)"<<"\t\t# Restore the value of the frame pointer"<<endl; 								
	cout<<pad<<"lw"<<"$fp, -4($fp)"<<"\t\t# Restore the value of the frame pointer"<<endl; 								
	
	// Restore stack pointer		
	cout<<pad<<"addiu"<<"$sp, $sp, "<<sp_offset<<"\t\t# Restore the value of the stack pointer"<<endl; 						

	cout<<pad<<"j"<<"$ra"<<endl;											// Go back to caller
	cout<<pad<<"nop"<<endl;
}

void ASMhandle::allocate_mem(const int& mem_amount /*= 24*/){
	// Allocate memory
	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<"\t\t# Allocate more memory"<<endl;
	allocated_mem+=mem_amount;
	sp_offset+=mem_amount;
}

char* ASMhandle::allocate_var(pair<string, Variable*>& var_in, const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	insert_local_var(var_in);
	char* address=strdup(string(std::to_string(fp_offset)+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

// Used for temporaries only
char* ASMhandle::allocate_var(const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	char* address=strdup(string(std::to_string(fp_offset)+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

string ASMhandle::allocate_str_var(pair<string, Variable*>& var_in, const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	insert_local_var(var_in);
	string address(std::to_string(fp_offset)+"($fp)");										// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

// Used for temporaries only
string ASMhandle::allocate_str_var(const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	string address(std::to_string(fp_offset)+"($fp)");										// Get the location of the temporary
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
	// Check for global variable name matching local variable name
}

void ASMhandle::clash_check(){
	// Check for global variable name matching function name
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