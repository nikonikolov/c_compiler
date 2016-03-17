#include <iostream>
#include "c_parser.tab.hpp"

using namespace std;


int main(){

	//yydebug=1;

  	cerr<<"========================================= Parsing starts ========================================="<<endl;
  	yyparse();
  	cerr<<"========================================= Parsing successful ========================================="<<endl;

  	if(root==NULL) return 0;

  	cerr<<"========================================= Codegen starts ========================================="<<endl;

  	root->renderasm();

  	cerr<<"========================================= Codegen successful ========================================="<<endl;

  	return 0;
}