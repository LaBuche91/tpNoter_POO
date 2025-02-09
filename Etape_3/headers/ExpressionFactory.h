#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H

#include <memory>
#include <stack>
#include <string>
#include "Expression.h"
#include "Variable.h"
#include "Constante.h"
#include "OperatorNode.h"

std::shared_ptr<Expression> parseExpression(const std::string &expr);

#endif // EXPRESSION_FACTORY_H