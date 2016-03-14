/*#include "ASMhandle.cpp"

ASMhandle::ASMhandle(ASMhandle* orig){
	if(orig->vars!=NULL){
		vector<Variable*>::iterator it;
		for(it=(orig->vars)->begin(); it!=(orig->vars)->end(); ++it){
			(this->vars).push_back(*it);
		}
	}
}

// NOTE: YOU MUST NOT BE DESTROYING THE VARIABLES IN THE VECTOR
ASMhandle::~ASMhandle(){}
*/