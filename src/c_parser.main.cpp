#include <iostream>
#include "c_parser.tab.hpp"

using namespace std;


int main(){

  yydebug=1;

  cerr<<"========================================= Parsing starts ========================================="<<endl;
  yyparse();
  cerr<<"========================================= Parsing successful ========================================="<<endl;

  if(root==NULL) return 0;

  cerr<<"========================================= Printing starts ========================================="<<endl;

  root->pretty_print(0);

  cerr<<"========================================= Printing successful ========================================="<<endl;

  return 0;
}