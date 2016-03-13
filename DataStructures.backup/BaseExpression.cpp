#include "BaseExpression.h"

BaseExpression::BaseExpression(const ExprT& expr_type_in) : expr_type(expr_type_in) {}
/*BaseExpression(BaseExpression* expr_ptr_in){
	this=expr_ptr_in;
}
*/
BaseExpression::~BaseExpression(){}
