#include "Statement.h"	


/* =============================================== ASMHANDLE CLASS =============================================== */


/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

uint64_t ASMhandle::label_idx = 3;
int ASMhandle::default_mem_increase = 40;
string ASMhandle::label = "$LKDHGF";

map<string, Function*>* ASMhandle::functions=NULL;		
map<string, Function*>* ASMhandle::fn_prototypes=NULL;		


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

	//return_address = new stack<string>(*(orig.return_address));
	if(orig.return_address!=NULL) return_address = strdup(orig.return_address);

	sp_offset=orig.sp_offset;
	allocated_mem=orig.allocated_mem;
	fp_offset=orig.fp_offset;
	stack_args_offset=16;
}


ASMhandle::ASMhandle(map<string, Function*>* functions_in, map<string, Function*>* fn_prototypes_in){
	functions=functions_in;
	fn_prototypes=fn_prototypes_in;
	global_vars = new map<string, Variable*>;
	local_vars = new map<string, Variable*>;
	return_address = NULL;
	
	sp_offset = 0;
	allocated_mem = 0;
	fp_offset = 0;
	stack_args_offset=16;
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE MAPS. You can try handling the deletion of functions and fn_prototypes
ASMhandle::~ASMhandle(){
	if(local_vars!=NULL) delete local_vars; 
	if(global_vars!=NULL) delete global_vars; 
	//if(return_address!=NULL) delete return_address; 
	if(return_address!=NULL) free(return_address); 
}

/* ----------------------------------------------- SUBROUTINES AND SCOPES ----------------------------------------------- */

void ASMhandle::subroutine_enter(const int& mem_amount /*= 24*/){
	// Note that mem_amount is always postive integer
	sp_offset = mem_amount;
	allocated_mem = mem_amount-8;
	fp_offset = 0;

	// Allocate memory on the stack
	assembler.push_back(ss<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<"\t\t# Allocate memory on the stack"<<endl); 		
	// Store the value of the frame pointer on the bottom of the stack
	assembler.push_back(ss<<pad<<"sw"<<"$fp, "<<mem_amount-4<<"($sp)"<<"\t\t# Store value of $fp on the bottom of the stack"<<endl); 		

	// Modify the frame pointer to point to the memory location above the one that stores its previous value
	assembler.push_back(ss<<pad<<"addiu"<<"$fp, $sp, "<<mem_amount-8<<"\t\t# Point $fp to the bottom of the available memory"<<endl); 			

	// You should push this to a new method that gets called only on function calls
	return_address = allocate_var();
	assembler.push_back(ss<<pad<<"sw"<<"$ra, "<<return_address<<"\t\t# Store the return address for the current subroutine"<<endl);
}

void ASMhandle::subroutine_exit(ExprResult** return_val){
	if(return_val!=NULL) (*return_val)->load("$v0");						// Load return value

	//string return_address = return_address->top();								// Get return address
	//return_address->pop(); // Not actually needed, because a subroutine will make a copy of the ASMhandle object 

	// Load return address
	assembler.push_back(ss<<pad<<"lw"<<"$ra, "<<return_address<<"\t\t# Load return address in register 31"<<endl);
	// Restore frame pointer. This should be load and should be -4
	assembler.push_back(ss<<pad<<"lw"<<"$fp, 4($fp)"<<"\t\t# Restore the value of the frame pointer"<<endl); 								
	// Restore stack pointer		
	assembler.push_back(ss<<pad<<"addiu"<<"$sp, $sp, "<<sp_offset<<"\t\t# Restore the value of the stack pointer"<<endl); 						
	// Go back to caller
	assembler.push_back(ss<<pad<<"j"<<"$ra"<<endl);											
	assembler.push_back(ss<<pad<<"nop"<<endl);
}


// For subroutine definition assembly
char* ASMhandle::allocate_subroutine_stack_param(pair<string, Variable*>& var_in, const int& mem_amount /*= 4*/){
	insert_local_var(var_in);
	/* 	Get the location of the argument on the stack. NOTE that the convention says: arg5 will be at 16($sp), arg6 at 20($sp),
		arg7 at 24($sp) and so on. $sp in this case is the value of the stack pointer at entering the function. This means that
		arg5 will be at the top and the rest of the arguments will be below it
	*/
	char* address=strdup(string(std::to_string(8+stack_args_offset)+"($fp)").c_str());	
	stack_args_offset+=mem_amount;			// Increment stack_args_offset
	return address;
}

// For subroutine definition assembly
void ASMhandle::push_subroutine_stack_params(vector<ExprResult**>& params){
	// Note params includes all arguments, including the ones already in registers
	int more_memory=(params.size()-4)*4+16, free_memory=allocated_mem-fp_offset;
	// Allocate more memory if necessary
	if(more_memory>free_memory) allocate_mem(more_memory-free_memory+16);
	for(int i=4, param_offset=16; i<params.size(); i++, param_offset+=4){
		(*params[i])->store_from_mem(string(std::to_string(param_offset) + "($sp)").c_str());
	}
}

// Used at the exit of a scope so that newly allocated memory will be accounted for
void ASMhandle::exit_scope(const ASMhandle& new_context){
	if(allocated_mem!=new_context.allocated_mem) 
					assembler.push_back(ss<<pad<<"addiu"<<"$sp, $sp, "<<new_context.allocated_mem-allocated_mem<<endl);
	//allocated_mem = new_context.allocated_mem;
	//sp_offset=new_context.sp_offset;
	//fp_offset=new_context.fp_offset;
}
/* ----------------------------------------------- FUNCTION CALLS ----------------------------------------------- */

Function* ASMhandle::find_function_definition(char* name_in){
	map<string, Function*>::iterator it;
	it=functions->find(string(name_in));
	if(it!=functions->end()) return (*it).second;
	
	if(fn_prototypes!=NULL){
		it=fn_prototypes->find(string(name_in));
		if(it!=fn_prototypes->end()) return (*it).second;
	}

	throw ERROR_fn_undefined;
}


/* ----------------------------------------------- LOCAL VARIABLES ----------------------------------------------- */

void ASMhandle::allocate_mem(const int& mem_amount /*= 24*/){
	// Allocate memory
	assembler.push_back(ss<<pad<<"addiu"<<"$sp, $sp, "<<-mem_amount<<"\t\t# Allocate more memory"<<endl);
	allocated_mem+=mem_amount;
	sp_offset+=mem_amount;
}

char* ASMhandle::allocate_var(pair<string, Variable*>& var_in, const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	insert_local_var(var_in);
	char* address=strdup(string(std::to_string(-fp_offset)+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}

// Used for temporaries mainly
char* ASMhandle::allocate_var(const int& mem_amount /*= 4*/){
	if( (fp_offset+mem_amount)>allocated_mem ) 
		allocate_mem(fp_offset + mem_amount - allocated_mem + 24);			// Allocate memory if necessary
	char* address=strdup(string(std::to_string(-fp_offset)+"($fp)").c_str());				// Get the location of the temporary
	fp_offset+=mem_amount;													// Increment fp_offset
	return address;
}


// Used for destruction/deallocation of temporaries
void ASMhandle::deallocate_var(const int& mem_amount/* = 4*/){
	fp_offset-=mem_amount;
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

/* ----------------------------------------------- GLOBAL VARIABLES ----------------------------------------------- */

void ASMhandle::insert_global_var(pair<string, Variable*>& var_in){
	if(debug) cerr<<"ASMhandle: insert_global_var(): start"<<endl;
	
	pair<map<string, Variable*>::iterator,bool> ret;
	ret = global_vars->insert(var_in);									// Put Variable* in global_vars
  	if(ret.second==false) throw ERROR_redefinition;
	
	if(debug) cerr<<"ASMhandle: insert_global_var(): no clash with other globals"<<endl;
	// Check for name clashes with functions
	map<string, Function*>::iterator it;
	it=functions->find(var_in.first);
	if(it!=functions->end()) throw ERROR_fn_var_clash;
	
	if(debug) cerr<<"ASMhandle: insert_global_var(): no clash with function definitions"<<endl;
	
	// Check for name clashes with function prototypes
	if(fn_prototypes!=NULL){
		it=fn_prototypes->find(var_in.first);
		if(it!=fn_prototypes->end()) throw ERROR_fn_var_clash;
	}
	if(debug) cerr<<"ASMhandle: insert_global_var(): no clash with function prototypes"<<endl;
}


/* ----------------------------------------------- GETTERS AND SETTERS ----------------------------------------------- */

string ASMhandle::get_assembly_label(){
	if(label_idx==0) label=string(label+std::to_string(label_idx));
	return string(label+std::to_string(label_idx++));
}



/* =============================================================================================================== */
/* =============================================== STATEMENT CLASS =============================================== */
/* =============================================================================================================== */



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

void Statement::generate_error(const string& msg_out){
  	cerr<<endl;
  	cerr<<"========================================= ERROR ========================================="<<endl;
  	cerr<<endl;
	if(src_file.empty()) 	cerr<<"Error in source file at line ";
	else 					cerr<<"Error in file "<<src_file<<" at line ";
	cerr<<line<<" : "<<msg_out<<endl;
	exit(EXIT_FAILURE);
}