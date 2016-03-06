#include "BaseExpression.h"

BaseExpression::BaseExpression(const StatementT& stat_type_in) : Statement(stat_type_in) {}
/*BaseExpression(BaseExpression* expr_ptr_in){
	this=expr_ptr_in;
}
*/
BaseExpression::~BaseExpression(){}
