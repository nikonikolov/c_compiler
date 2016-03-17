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
	cerr<<"AssignmentExpression 0"<<endl;
	char **lhs_dest, **rhs_dest;
	if(lhs!=NULL){
		//*lhs_dest = context.allocate_var();
	cerr<<"AssignmentExpression 1"<<endl;
		lhs_dest = new char*(context.allocate_var());
		//context.allocate_var(lhs_dest);
	cerr<<"AssignmentExpression 2"<<endl;
		lhs->renderasm(context, lhs_dest);
	cerr<<"AssignmentExpression 3"<<endl;
	} 
	if(rhs!=NULL){
	cerr<<"AssignmentExpression 4"<<endl;
		//*rhs_dest = context.allocate_var();
		rhs_dest = new char*(context.allocate_var());
	cerr<<"AssignmentExpression 5"<<endl;
		rhs->renderasm(context, rhs_dest);
	cerr<<"AssignmentExpression 6"<<endl;
	} 

	if(lhs!=NULL && rhs!=NULL){

		if(!strcmp(oper,"=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest); 	
		if(!strcmp(oper,"+=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest, "addu"); 	
		if(!strcmp(oper,"-=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest, "subu"); 	
		if(!strcmp(oper,"|=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest, "or"); 	
		if(!strcmp(oper,"&=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest, "and"); 	
		if(!strcmp(oper,"^=")) 	assignment_ins(*destination, *lhs_dest, *rhs_dest, "xor"); 	
		if(!strcmp(oper,"<<=")) assignment_ins(*destination, *lhs_dest, *rhs_dest, "sllv"); 	
		if(!strcmp(oper,">>=")) assignment_ins(*destination, *lhs_dest, *rhs_dest, "srlv"); 	

		//if(!strcmp(oper,"*=")) 	arithmetic_ins("mult", destination, lhs_dest, rhs_dest); 	
		//if(!strcmp(oper,"%=")) 	arithmetic_ins("addu", destination, lhs_dest, rhs_dest); 	
		//if(!strcmp(oper,"/=")) 	arithmetic_ins("addu", destination, lhs_dest, rhs_dest); 	

	}
	/* ----------------------------------- SINGLE OPERAND ----------------------------------- */
	if(lhs==NULL && rhs!=NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins(*destination, *rhs_dest, 1, false);
		if(!strcmp(oper,"--")) 	inc_dec_ins(*destination, *rhs_dest, -1, false);
	}
	if(lhs!=NULL && rhs==NULL){
		if(!strcmp(oper,"++")) 	inc_dec_ins(*destination, *lhs_dest, 1, true);
		if(!strcmp(oper,"--")) 	inc_dec_ins(*destination, *lhs_dest, -1, true);
	}


}


void AssignmentExpression::assignment_ins(char* destination, char* lhs_dest, char* rhs_dest, const string& instruction /*=""*/){
	// Arithmetic operation required
	if(!instruction.empty()) arithmetic_ins(lhs_dest, rhs_dest, instruction);
	// Simple assignment
	else cout<<pad<<"lw"<<"$t0, "<<rhs_dest<<endl;
	
	cout<<pad<<"sw"<<"$t0, "<<lhs_dest<<endl;
	if(destination!=NULL)	cout<<pad<<"sw"<<"$t0, "<<destination<<endl;
}

void AssignmentExpression::arithmetic_ins(char* lhs_dest, char* rhs_dest, const string& instruction){
	cout<<pad<<"lw"<<"$t0, "<<lhs_dest<<endl;
	cout<<pad<<"lw"<<"$t1, "<<rhs_dest<<endl;
	cout<<pad<<instruction<<"$t0, $t0, $t1"<<endl;
}

void AssignmentExpression::inc_dec_ins(char* destination, char* arg, const int& val, const bool& post_inc){
	cout<<pad<<"lw"<<"$t0, "<<arg<<endl;
	if(destination!=NULL && post_inc) cout<<pad<<"sw"<<"$t0, "<<destination<<endl;	// Assign the old value to the destination
	cout<<pad<<"addiu"<<"$t0, $t0, "<<val<<endl;
	cout<<pad<<"sw"<<"$t0, "<<arg<<endl;											// Assign the new value to the variable
	if(destination!=NULL && !post_inc) cout<<pad<<"sw"<<"$t0, "<<destination<<endl;	// Assign the new value to the destination
}
