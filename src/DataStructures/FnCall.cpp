#include "FnCall.h"

FnCall::FnCall(char* name_in, vector<BaseExpression*>* arguments_in, const int& line_in, const string& src_file_in) :
	BaseExpression(EXPR_fn_call, line_in, src_file_in), arguments(arguments_in){
	name=strdup(name_in);
}


FnCall::~FnCall(){
	if(arguments!=NULL){
		vector<BaseExpression*>::iterator it;
		for(it=arguments->begin(); it!=arguments->end(); ++it){
			delete *it;
		}
		delete arguments;
	}
}


string FnCall::get_name() const{
	return string(name);
}


void FnCall::pretty_print(const int& indent){
	string white_space, new_scope_indent="    ";
	white_space.resize(indent, ' ');

	cout<<white_space<<name<<"(";
	if(arguments!=NULL){
		vector<BaseExpression*>::iterator it, it_end;
		it_end=arguments->end();
		--it_end;
		for(it=arguments->begin(); it!=arguments->end(); ++it){
			(*it)->pretty_print(0);
			if(it!=it_end) cout<<", ";
		}
	} 
	cout<<")";
}


BaseExpression* FnCall::simplify(){
	BaseExpression* tmp_expr=NULL;
	if(arguments!=NULL){
		// Simplify the values of the parameters that you need to pass
		vector<BaseExpression*>::iterator it;
		for(it=arguments->begin(); it!=arguments->end(); ++it){
			try{
				tmp_expr = (*it)->simplify();
				if(tmp_expr!=NULL){
					delete (*it);
					(*it) = tmp_expr;			// In case RHS cannot be simplified
				}
			}
			catch(const int& exception_in){}
		}
	}
	throw 1;
}

void FnCall::renderasm(ASMhandle& context, char** destination /*=NULL*/){
	
	try{
		Function* fncalled = context.find_function_definition(name);
	}
	catch(const ErrorgenT& error_in){
		generate_error("No function with name \""+string(name)+"\" defined");
	}

	vector<pair<char**,bool>> params_results;
	if(arguments!=NULL){
		
		// Calculate the values of the parameters that you need to pass
		vector<BaseExpression*>::iterator it;
		for(it=arguments->begin(); it!=arguments->end(); ++it){
			char** param_destination;
			bool param_global=false;
			if((*it)->get_expr_type()!=EXPR_tmp_var) 	param_destination = new char*(context.allocate_var());
			else 										param_destination=new char*;
			try 					{ (*it)->renderasm(context, param_destination); }
			catch(const bool& glob)	{ param_global=glob; }
			params_results.push_back(pair<char**,bool>(param_destination, param_global));
		}
	
		// Load register parameters
		for(int i=0; i<4; i++){
			if(!params_results[i].second) assembler.push_back(ss<<pad<<"lw"<<"$a"<<i<<", "<<*(params_results[i].first)<<endl);
			else{
				assembler.push_back(ss<<pad<<"lui"<<"$t0"<<", %hi("<<*(params_results[i].first)<<")"<<endl);
				assembler.push_back(ss<<pad<<"lw"<<"$a"<<i<<", %lo("<<*(params_results[i].first)<<")($t0)"<<endl);
			}
		}
		// Load stack parameters
		if(params_results.size()>4) context.push_subroutine_stack_params(params_results);
	} 

	assembler.push_back(ss<<pad<<"la"<<"$t0, "<<name<<endl);
	assembler.push_back(ss<<pad<<"jalr"<<"$t0"<<endl);
	assembler.push_back(ss<<pad<<"nop"<<endl);

	// Load the return value in the destination
	if(destination!=NULL){
		assembler.push_back(ss<<pad<<"sw"<<"$v0, "<<*destination<<endl);
	}

}
