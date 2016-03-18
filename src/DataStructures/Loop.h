#ifndef LOOP_H
#define LOOP_H

#include "Statement.h"
#include "CompoundStatement.h"
#include "Variable.h"

class Loop : public Statement{

public:
	Loop(CompoundStatement* loop_body_in);
	Loop(Statement* loop_statement_in);
	Loop(Statement* loop_statement_in, const int& line_in, const string& src_file_in);
	Loop(CompoundStatement* loop_body_in, const int& line_in, const string& src_file_in);
	~Loop();

	void pretty_print(const int& indent);
	void renderasm(ASMhandle& context);
private:

	// Note: only one can be initialized to a non-NULL value
	Statement* loop_statement;			// Single Statement defining the function body
	CompoundStatement* loop_body;		// Compound Statement defining the function body


};



#endif

