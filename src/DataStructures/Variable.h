#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstdint>
#include "include.h"
#include "BaseExpression.h"
#include "Constant.h"

typedef std::pair<BaseExpression*,int> PtrDeref;

/*	FIX:
		1. Currently only integers assumed. Don't forger to account for template type at 
		casting to Constant in renderasm_global_var as well
*/

class Variable{

public:
	// NOTE: you need to overload constructor to build dereferencepretty_print(const int& indent)r
	
	/* ------------------------------------------------- CONSTRUCTORS ------------------------------------------------- */

	Variable(char* name_in);
	Variable(char* type_name_in, char* name_in, list<PtrDeref>* dereferencer_in=NULL);

	Variable(char* name_in, const int& line_in, const string& src_file_in);
	Variable(char* type_name_in, char* name_in, const int& line_in, const string& src_file_in, list<PtrDeref>* dereferencer_in=NULL);

	~Variable();

	/* ------------------------------------------------- GETTERS AND SETTERS ------------------------------------------------- */

	const char* get_name() const;
	string get_name_str() const;
	//bool initialized() const;

	void set_type_name(char* type_name_in);
	void set_init_val(BaseExpression* init_val_in);
	void set_asm_location(const string& str_in);
	void set_asm_location(char* str_in);
	char* get_asm_location(ASMhandle& context, bool& global_var);

	/* ------------------------------------------------- GLOBALLY USED METHODS ------------------------------------------------- */

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context, const bool& local = true);

	/* ------------------------------------------------- GLOBAL SCOPE RELATED ------------------------------------------------- */
	void renderasm_global(ASMhandle& context);

	/* ------------------------------------------------- POINTER RELATED ------------------------------------------------- */

	// You should probably use a tuple of 3 rather than a pair. 
	//The third code should tell you how to deduce the size. Do it when pointers come up
	void dereference_back(BaseExpression* expr_in, const int& size=INTNAN);
	void dereference_front(BaseExpression* expr_in, const int& size=INTNAN);

	/* ------------------------------------------------- ERROR GENERATION ------------------------------------------------- */

	void generate_error(const string& msg_out);

private:
	void simplify_init_val();
	

	/* 	Template version instead of using var_type would not be a good idea since you would not know the types of Variables
		appearing in BaseExpressions. Enum type instead of string would not be useful as well because you won't be able to
		describe structs and unions. Note that the string contains only type-names such as int, double, etc and no * or [].
		Pointers and levels of dereferencing are dealt with by the dereferecer structure below 
	*/
	
	char* type_name;				// Contains the typename of the variable, i.e. int, double, etc. No * or []
	snum_t num_val;					// Contains the numerical value of token_val cast to the specified type
	char* name;						// Name given to the variable in the program
	BaseExpression* init_val;		// Contains the value to be assigned to the variable at initialization
	
	
	/* 	The following structure allows for describing Variables appearing both in declarations or in BaseExpressions.
	 	Arrays and pointers are treated exactly the same way - using dereferencing
	*/
	
	list<PtrDeref>* dereferencer;			
	/* 	The value of the BaseExpression in the list specifies the offset of the memory location pointed to. 
		If you encounter a simple * in the parser, then push back a Constant equal to 0. 
		The size of the list specifies how many times you need to dereference the variable. The integer value corresponding to
		each BaseExpression in the list specifies the max offset of the memory that you can access. If you don't know it, set it
		to Nan
	*/


	/* Fields for assembly */
	char* location;						// Holds the location of the variable, e.g. 4($sp) or $t0
	bool initialized;
	
	bool global;
	static bool first_global;			// Needed to identify when to print .data

	int line;
	string src_file;

	stringstream ss;
};



#endif

