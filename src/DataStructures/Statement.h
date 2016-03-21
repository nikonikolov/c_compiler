#ifndef STATEMENT_H
#define STATEMENT_H

#include "include.h"

/* =============================================== ASMHANDLE CLASS =============================================== */

class Variable;
class Function;

/*	TO FIX:
	1. Only 4byte wide variables assumed
	3. Insertion of global variables - check vs other global variables and vs function names 

	4. Think about making fn_prototypes and functions static - this would however make it difficult to track static function
		declarations - if you ever decide to do them
*/

class ASMhandle{

public:
	/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

	ASMhandle();
	ASMhandle(ASMhandle& orig);
	ASMhandle(map<string, Function*>* functions_in, map<string, Function*>* fn_prototypes_in);
	~ASMhandle();


	/* ----------------------------------------------- SUBROUTINES AND SCOPES ----------------------------------------------- */

	void subroutine_enter(const int& mem_amount = default_mem_increase);
	void subroutine_exit(char* return_val);
	
	char* allocate_subroutine_stack_param(pair<string, Variable*>& var_in, const int& mem_amount = 4);

	void exit_scope(const ASMhandle& new_context);

	void push_subroutine_stack_params(vector<pair<char**, bool>>& params);

	Function* find_function_definition(char* name_in);

	/* ----------------------------------------------- LOCAL VARIABLES ----------------------------------------------- */
	void allocate_mem(const int& mem_amount = default_mem_increase);
	char* allocate_var(pair<string, Variable*>& var_in, const int& mem_amount = 4);
	char* allocate_var(const int& mem_amount = 4);
	string allocate_str_var(pair<string, Variable*>& var_in, const int& mem_amount = 4);
	string allocate_str_var(const int& mem_amount = 4);
	void deallocate_var(const int& mem_amount = 4);

	Variable* get_var_location(char* name);
	void insert_local_var(pair<string, Variable*>& var_in);

	/* ----------------------------------------------- GLOBAL VARIABLES ----------------------------------------------- */

	void insert_global_var(pair<string, Variable*>& var_in);

	/* ----------------------------------------------- GETTERS AND SETTERS ----------------------------------------------- */

	string get_assembly_label();

	/* ----------------------------------------------- PUBLIC MEMBERS ----------------------------------------------- */

	map<string, Variable*>* global_vars;
	map<string, Variable*>* local_vars;
	static map<string, Function*>* functions;		
	static map<string, Function*>* fn_prototypes;		

private:
	// Indicates how much memory is allocated for the current subroutine. Needs to be incremented when fp_offset becomes equal
	int allocated_mem;					
	int sp_offset; 					// Indicates by how much of the stack pointer needs to be incremented on subroutine exit
	int fp_offset; 					// Indicates how much of the currently allocated stack memory is used

	int stack_args_offset;			// Used to allocate locations for parameters to functions with index bigger than 4

	stack<string>* return_address;
	static uint64_t label_idx;
	static string label; 

	static int default_mem_increase;
	//static int mem_amount_default;
	stringstream ss;
};


/* =============================================== STATEMENT CLASS =============================================== */

/*	
	An abstract class that can cover expressions, function declarations and calls, if statements, loops
*/

class Statement{

public:
	Statement(const StatementT& stat_type_in);
	Statement(const StatementT& stat_type_in, const int& line_in, const string& src_file_in);
	virtual ~Statement();

	virtual void pretty_print(const int& indent) =0;		// parameter specifies the starting column for the printing
	virtual void renderasm(ASMhandle& context)=0;
	void set_stat_type(const StatementT& stat_type_in); 
	StatementT get_stat_type() const ;
	virtual void generate_error(const string& msg_out);

protected:
	StatementT stat_type;
	int line;
	string src_file;

	stringstream ss;
};



#endif

