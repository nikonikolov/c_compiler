#ifndef STATEMENT_H
#define STATEMENT_H

#include "include.h"
//#include "Variable.h"

/* =============================================== ASMHANDLE CLASS =============================================== */

class Variable;
class Function;

//extern void Variable::set_asm_location(const string& str_in);

class ASMhandle{

public:
	/* ----------------------------------------------- CONSTRUCTION ----------------------------------------------- */

	ASMhandle(const ASMhandle& orig);
	ASMhandle(map<string, Function*>* functions_in, map<string, Variable*>* global_vars_in);
	~ASMhandle();

	/* ----------------------------------------------- CODEGEN METHODS ----------------------------------------------- */

	void subroutine_enter(const int& mem_amount = 24);
	void subroutine_exit();
	void allocate_mem(const int& mem_amount = 24);
	char* allocate_var(pair<string, Variable*>& var_in, const int& mem_amount = 4);
	char* allocate_var(const int& mem_amount = 4);
	void deallocate_var(const int& mem_amount = 4);


	/* ----------------------------------------------- GETTERS AND SETTERS ----------------------------------------------- */

	string get_label();
	Variable* get_var_location(char* name);

	void insert_local_var(pair<string, Variable*>& var_in);

	/* ----------------------------------------------- ERROR CHECKERS ----------------------------------------------- */

	void redefinition_check();

	/* ----------------------------------------------- PUBLIC MEMBERS ----------------------------------------------- */

	map<string, Variable*>* global_vars;
	map<string, Variable*>* local_vars;
	map<string, Function*>* functions;		

private:
	int sp_offset; 					// Indicates by how much of the stack pointer needs to be incremented on subroutine exit
	// Indicates how much memory is allocated for the current subroutine. Needs to be incremented when frame_offset becomes equal
	int allocated_mem;					
	int fp_offset; 					// Indicates how much of the currently allocated stack memory is used

	static uint32_t label_idx;
	//static int mem_amount_default;
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
	virtual void generate_error();

protected:
	StatementT stat_type;
	int line;
	string src_file;
};



#endif

