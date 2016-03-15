#include "Statement.h"	


/* =============================================== ASMHANDLE CLASS =============================================== */


/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

ASMhandle::ASMhandle(const ASMhandle& orig){
	if(orig.local_vars!=NULL){
		vector<Variable*>::iterator it;
		for(it=(orig.local_vars)->begin(); it!=(orig.local_vars)->end(); ++it){
			(this->local_vars)->push_back(*it);
		}
	}
	else this->local_vars = new vector<Variable*>;

	if(orig.global_vars!=NULL){
		vector<Variable*>::iterator it;
		for(it=(orig.global_vars)->begin(); it!=(orig.global_vars)->end(); ++it){
			(this->global_vars)->push_back(*it);
		}
	}
	else this->global_vars = new vector<Variable*>;

	if(orig.functions!=NULL){
		vector<Function*>::iterator it;
		for(it=(orig.functions)->begin(); it!=(orig.functions)->end(); ++it){
			(this->functions)->push_back(*it);
		}
	}
	else this->functions = new vector<Function*>;
	
	//this->sp_offset=orig.sp_offset;
	//this->allocated_mem=orig.allocated_mem;
	this->sp_offset=orig.sp_offset;
	this->allocated_mem=orig.allocated_mem;
	this->fp_offset=orig.fp_offset;
}

ASMhandle::ASMhandle(vector<Function*>* functions_in, vector<Variable*>* global_vars_in) :
	functions(functions_in), global_vars(global_vars_in) {
	local_vars = new vector<Variable*>;
	
	sp_offset = 0;
	allocated_mem = 0;
	fp_offset = 0;
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE VECTORS
ASMhandle::~ASMhandle(){
	if(local_vars!=NULL) delete local_vars; 
	if(global_vars!=NULL) delete global_vars; 
	if(functions!=NULL) delete functions; 
}

/* ----------------------------------------------- MANIPULATION ----------------------------------------------- */

void ASMhandle::redefinition_check(){

}

void ASMhandle::subroutine_enter(const int& mem_amount /*= 24*/){
	// Note that mem_amount is always postive integer

	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<endl; 		// Allocate memory
	cout<<pad<<"sw"<<"$fp, "<<mem_amount-4<<"($sp)"<<endl; 						// Store the value of the frame pointer on the bottom of the stack

	// Modify the frame pointer to point to the memory location above the one that stores its previous value
	cout<<pad<<"addiu"<<"$fp, $sp, "<<mem_amount-8<<endl; 			

	sp_offset = mem_amount;
	allocated_mem = mem_amount-8;
	fp_offset = 0;
}

void ASMhandle::subroutine_exit(){
	cout<<pad<<"move"<<"$fp, 4($fp)"<<endl; 			// Restore frame pointer
	cout<<pad<<"addiu"<<"$sp, $sp, "<<sp_offset<<endl; 	// Restore stack pointer		
}

void ASMhandle::allocate_mem(const int& mem_amount /*= 24*/){
	cout<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<endl; 		// Allocate memory
	allocated_mem+=mem_amount;
}
/*
void ASMhandle::allocate_var(Variable* var_in, const int& mem_amount /*= 4/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);		// Allocate memory if necessary
	var_in->set_asm_location(fp_offset+"($fp)");							// Set the location of the Variable
	fp_offset+=mem_amount;												// Increment fp_offset
	local_vars->push_back(var_in);										// Put Variable* in local_vars
}
*/
string ASMhandle::allocate_var(Variable* var_in, const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);		// Allocate memory if necessary
	local_vars->push_back(var_in);										// Put Variable* in local_vars
	string address(fp_offset+"($fp)");									// Get the location of the temporary
	fp_offset+=mem_amount;												// Increment fp_offset
	return address;
}

// Used for temporaries only
string ASMhandle::allocate_var(const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);		// Allocate memory if necessary
	string address(fp_offset+"($fp)");									// Get the location of the temporary
	fp_offset+=mem_amount;												// Increment fp_offset
	return address;
}

// Used for destruction/deallocation of temporaries
void ASMhandle::deallocate_var(const int& mem_amount/* = 4*/){
	fp_offset-=mem_amount;
}

/* =============================================== STATEMENT CLASS =============================================== */



Statement::Statement(const StatementT stat_type_in) : stat_type(stat_type_in){}
	
Statement::~Statement(){}

void Statement::set_stat_type(const StatementT& stat_type_in){
	stat_type=stat_type_in;
}
StatementT Statement::get_stat_type() const{
	return stat_type;
}

