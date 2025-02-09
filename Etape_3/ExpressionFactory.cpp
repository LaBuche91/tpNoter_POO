#include "headers/ExpressionFactory.h"
#include <stdexcept>

std::shared_ptr<Expression> parseExpression(const std::string &expr) {
    std::stack<std::shared_ptr<Expression>> stack;
    for (char c : expr) {
        if (isdigit(c)) {
            stack.push(std::make_shared<Constante>(c - '0'));
        } else if (isalpha(c)) {
            stack.push(std::make_shared<Variable>(c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.size() < 2) throw std::runtime_error("Expression invalide");
            auto right = stack.top(); stack.pop();
            auto left = stack.top(); stack.pop();
            stack.push(std::make_shared<OperatorNode>(c, left, right));
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Expression invalide");
    return stack.top();
}