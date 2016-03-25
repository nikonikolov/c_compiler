#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstdint>
#include "include.h"
#include "BaseExpression.h"
#include "Constant.h"

/* 	Variable Class: Describes a Variable that participates only in declarations. Variables appearing in Expressions are 
	described by VarExpr class. This class is also capable of describing pointers

	Template version instead of using var_type would not be a good idea since you would not know the types of Variables
	appearing in BaseExpressions. Enum type instead of string would not be useful as well because you won't be able to
	describe structs and unions. Note that the string contains only type-names such as int, double, etc and no * or [].
	Pointers and levels of dereferencing are dealt with by the dereferecer structure below 
*/


/*	FIX:
		1. Currently only integers assumed. Don't forger to account for template type at 
		casting to Constant in renderasm_global_var as well
*/

class Variable : public ExprResult{

public:
	// NOTE: you need to overload constructor to build dereferencepretty_print(const int& indent)r
	
	/* ------------------------------------------------- CONSTRUCTORS ------------------------------------------------- */

	//Variable(char* name_in);
	//Variable(char* name_in, const int& line_in, const string& src_file_in);
	
	Variable(char* type_name_in, char* name_in);
	Variable(char* type_name_in, char* name_in, const int& line_in, const string& src_file_in);

	~Variable();

	/* ------------------------------------------------- GETTERS AND SETTERS ------------------------------------------------- */

	const char* get_name() const;
	string get_name_str() const;

	void set_type_name(char* type_name_in);
	void set_init_val(BaseExpression* init_val_in);
	void set_asm_location(const string& str_in);
	void set_asm_location(char* str_in);

	/* ------------------------------------------------- ExprResult METHODS  ------------------------------------------------- */

	void load(const string& dest_reg);
	void store(const string& reg_location_in);
	void store_from_mem(const string& dest_mem_location);
//	bool dereferencable();

	/* ------------------------------------------------- GLOBALLY USED METHODS ------------------------------------------------- */

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, const bool& local = true);

	/* ------------------------------------------------- POINTER RELATED ------------------------------------------------- */

	void inc_deref_lvl(const int& increment);
	void inc_array_size(BaseExpression* mult_by);

	/* ------------------------------------------------- ERROR GENERATION ------------------------------------------------- */

	void generate_error(const string& msg_out);

private:
	/* ------------------------------------------------- PRIVATE METHODS ------------------------------------------------- */
	void simplify_init_val();
	
	/* ------------------------------------------------- GLOBAL SCOPE RELATED ------------------------------------------------- */
	void renderasm_global(ASMhandle& context);


	/* ------------------------------------------------- SPECIFICATION MEMBER DATA --------------------------------------------- */
	
	char* type_name = NULL;			// Contains the typename of the variable, i.e. int, double, etc. No * or []
	char* name = NULL;				// Name given to the variable in the program
	BaseExpression* init_val = NULL;// Contains the value to be assigned to the variable at initialization
	
	/* ------------------------------------------------- MEMBER DATA FOR ASSEMBLY ---------------------------------------------- */
	bool initialized = false;
	bool global = false;
	static bool first_global;		// Needed to identify when to print .data

	/* ------------------------------------------------- GENERAL MEMBER DATA ------------------------------------------------- */

	int line;
	string src_file;
	stringstream ss;

	/* ------------------------------------------------- MEMBER DATA FOR POINTERS ---------------------------------------------- */

	// NOTE: at most one dimension is allowed to be missing
	vector<int>* size = NULL;  // Specifies the size of arrays at declaration. 0-valued member means size deduced by initializer expr	
	int dereference_level = 0; // Specifies how many times the variable can be dereferenced. 0 for non-pointer types

};



#endif

