#include <iostream>
#include "c_parser.tab.hpp"
#include "DataStructures/include.h"

using namespace std;


int main(int argc, char* argv[]){

	if(argc>1){
		for(int i=1; i<argc; i++){
			if(!strcmp(argv[i],"-debug")) debug=true;
		}
	}

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