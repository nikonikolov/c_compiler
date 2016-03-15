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
	ASMhandle(const ASMhandle& orig);
	ASMhandle(vector<Function*>* functions_in, vector<Variable*>* global_vars_in);
	~ASMhandle();

	void redefinition_check();
	void subroutine_enter(const int& mem_amount = 24);
	void subroutine_exit();
	void allocate_mem(const int& mem_amount = 24);
	string allocate_var(Variable* var_in, const int& mem_amount = 4);
	//void allocate_var(Variable* var_in, const int& mem_amount = 4);
	string allocate_var(const int& mem_amount = 4);
	void deallocate_var(const int& mem_amount = 4);

	int sp_offset; 					// Indicates by how much of the stack pointer needs to be incremented on subroutine exit
	// Indicates how much memory is allocated for the current subroutine. Needs to be incremented when frame_offset becomes equal
	int allocated_mem;					
	int fp_offset; 					// Indicates how much of the currently allocated stack memory is used

	vector<Variable*>* local_vars;
	vector<Variable*>* global_vars;	
	
	// Probably a function prototype class will be better when it is ready
	vector<Function*>* functions;		
private:
};


/* =============================================== STATEMENT CLASS =============================================== */

/*	
	An abstract class that can cover expressions, function declarations and calls, if statements, loops
*/

class Statement{

public:
	Statement(const StatementT stat_type_in);
	virtual ~Statement();

	virtual void pretty_print(const int& indent) const =0;		// parameter specifies the starting column for the printing
	virtual void renderasm(ASMhandle& context)=0;
	void set_stat_type(const StatementT& stat_type_in); 
	StatementT get_stat_type() const ;
protected:
	StatementT stat_type;
};



#endif

