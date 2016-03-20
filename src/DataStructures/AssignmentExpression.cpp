#include "AssignmentExpression.h"

/* =============================================== CONSTRUCTION =============================================== */


AssignmentExpression::AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in) : 
	Expression(lhs_in, oper_in, rhs_in, EXPR_assignment_expr) {}

AssignmentExpression::AssignmentExpression(BaseExpression* lhs_in, char* oper_in, BaseExpression* rhs_in, const int& line_in, 
	const string& src_file_in) : Expression(lhs_in, oper_in, rhs_in, EXPR_assignment_expr, line_in, src_file_in) {}

AssignmentExpression::~AssignmentExpression(){
}


/* =============================================== VIRTUAL METHODS IMPLEMENTATION =============================================== */

void AssignmentExpression::renderasm(ASMhandle& context, char** destination /*=NULL*/){

	char **lhs_dest, **rhs_dest;
	//Variable* var=NULL;
	//lhs_global=false;
	//rhs_global=false;

	if(lhs!=NULL){
		if(lhs->get_expr_type()!=EXPR_tmp_var) lhs_dest = new char*(context.allocate_var());
		else lhs_dest=new char*;
		try 					{ lhs->renderasm(context, lhs_dest); }
		catch(const bool& glob) { lhs_global=glob; }
	} 
	if(rhs!=NULL){
		if(rhs->get_expr_type()!=EXPR_tmp_var) rhs_dest = new char*(context.allocate_var());
		else rhs_dest=new char*;
		try 					{ rhs->renderasm(context, rhs_dest); }
		catch(const bool& glob) { rhs_global=glob; }
	} 

	if(lhs!=NULL && rhs!=NULL){

		if(!strcmp(oper,"=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest); 	
		if(!strcmp(oper,"+=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "addu"); 	
		if(!strcmp(oper,"-=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "subu"); 	
		if(!strcmp(oper,"|=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "or"); 	
		if(!strcmp(oper,"&=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "and"); 	
		if(!strcmp(oper,"^=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "xor"); 	
		if(!strcmp(oper,"<<=")) assignment_ins(destination, *lhs_dest, *rhs_dest, "sllv"); 	
		if(!strcmp(oper,">>=")) assignment_ins(destination, *lhs_dest, *rhs_dest, "srav"); 	

		if(!strcmp(oper,"*=")) 	assignment_ins(destination, *lhs_dest, *rhs_dest, "mul"); 	
		if(!strcmp(oper,"%=")) 	div_rem_ins(destination, *lhs_dest, *rhs_dest, "mfhi"); 	
		if(!strcmp(oper,"/=")) 	div_rem_ins(destination, *lhs_dest, *rhs_dest, "mflo"); 	

	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins(destination, *rhs_dest, 1, false);
		if(!strcmp(oper,"--")) 	inc_dec_ins(destination, *rhs_dest, -1, false);
	}
	if(lhs!=NULL && rhs==NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins(destination, *lhs_dest, 1, true);
		if(!strcmp(oper,"--")) 	inc_dec_ins(destination, *lhs_dest, -1, true);
	}

}

/* =============================================== CODEGEN METHODS =============================================== */

void AssignmentExpression::assignment_ins(char** destination, char* lhs_dest, char* rhs_dest, const string& instruction /*=""*/){
	bool lhs_loaded=true;

	// Arithmetic operation required
	if(!instruction.empty()) arithmetic_ins(lhs_dest, rhs_dest, instruction);
	// Simple assignment
	else{
		load_rhs(rhs_dest, "$t0");
		lhs_loaded=false;
	} 

	store_lhs(lhs_dest, "$t0", lhs_loaded);
	if(destination!=NULL)	assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<*destination<<endl);
}

void AssignmentExpression::arithmetic_ins(char* lhs_dest, char* rhs_dest, const string& instruction){
	load_lhs(lhs_dest, "$t0");
	load_rhs(rhs_dest, "$t1");
	assembler.push_back(ss<<pad<<instruction<<"$t0, $t0, $t1"<<endl);
}

void AssignmentExpression::inc_dec_ins(char** destination, char* arg, const int& val, const bool& post_inc){
	if(post_inc) 	load_lhs(arg, "$t0");
	else			load_rhs(arg, "$t0");
	
	if(destination!=NULL && post_inc) assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<*destination<<endl);	// Assign the old value to the destination
	assembler.push_back(ss<<pad<<"addiu"<<"$t0, $t0, "<<val<<endl);
	
	// Assign the new value to the variable
	if(post_inc) 	store_lhs(arg, "$t0", true);
	else			store_rhs(arg, "$t0", true);
	if(destination!=NULL && !post_inc) assembler.push_back(ss<<pad<<"sw"<<"$t0, "<<*destination<<endl);	// Assign the new value to the destination
}

void AssignmentExpression::div_rem_ins(char** destination, char* lhs_dest, char* rhs_dest, const string& instruction){
	load_lhs(lhs_dest, "$t0");
	load_rhs(rhs_dest, "$t1");
	assembler.push_back(ss<<pad<<"teq"<<"$t1, $0, 7"<<endl);
	assembler.push_back(ss<<pad<<"div"<<"$t0, $t1"<<endl);
	assembler.push_back(ss<<pad<<instruction<<"$t2"<<endl);
	store_lhs(lhs_dest, "$t2", true);
	if(destination!=NULL)	assembler.push_back(ss<<pad<<"sw"<<"$t2, "<<*destination<<endl);
}


/* ---------------------------------------------- STORING OPERANDS ---------------------------------------------- */

void AssignmentExpression::store_lhs(char* arg, const string& dest_reg, const bool& loaded, const string& lhs_reg /*="$t8"*/){
	if(!lhs_global) assembler.push_back(ss<<pad<<"sw"<<dest_reg<<", "<<arg<<endl);	
	else{
		if(!loaded) assembler.push_back(ss<<pad<<"lui"<<lhs_reg<<", %hi("<<arg<<")"<<endl);
		assembler.push_back(ss<<pad<<"sw"<<dest_reg<<", %lo("<<arg<<")("<<lhs_reg<<")"<<endl);
	} 
}

void AssignmentExpression::store_rhs(char* arg, const string& dest_reg, const bool& loaded, const string& rhs_reg /*="$t9"*/){
	if(!rhs_global) assembler.push_back(ss<<pad<<"sw"<<dest_reg<<", "<<arg<<endl);	
	else{
		if(!loaded) assembler.push_back(ss<<pad<<"lui"<<rhs_reg<<", %hi("<<arg<<")"<<endl);
		assembler.push_back(ss<<pad<<"sw"<<dest_reg<<", %lo("<<arg<<")("<<rhs_reg<<")"<<endl);
	} 
}
