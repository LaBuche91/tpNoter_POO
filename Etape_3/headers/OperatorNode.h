#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Expression.h"
#include "Operator_t.h"
#include <memory>

class OperatorNode : public Expression {
public:
    Operator_t op;
    std::shared_ptr<Expression> left, right;
    OperatorNode(char symbol, std::shared_ptr<Expression> l, std::shared_ptr<Expression> r) 
        : op(symbol), left(std::move(l)), right(std::move(r)) {}
    void accept(Visitor &v) const override;
};

#endif // OPERATORNODE_H