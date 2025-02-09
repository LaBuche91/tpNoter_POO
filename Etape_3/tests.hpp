#include "headers/Constante.h"
#include "headers/Variable.h"
#include "headers/Operator_t.h" 
#include "headers/Expression.h"
#include "headers/OperatorNode.h"
#include "headers/DisplayVisitor.h"
#include "headers/EvalVisitor.h"
#include "headers/ExpressionFactory.h"
#include <cassert>
#include <memory>
#include <iostream>

void test_simple_constant() {
    // Constante 5
    auto expr = parseExpression("5");
    
    DisplayVisitor dv;
    expr->accept(dv);
    assert(dv.result == "5");
    
    EvalVisitor ev;
    expr->accept(ev);
    assert(ev.result == 5);
}

void test_simple_variable() {
    // Variable x
    auto expr = parseExpression("x");
    
    DisplayVisitor dv;
    expr->accept(dv);
    assert(dv.result == "x");
    
    EvalVisitor ev;
    ev.varValues = {{'x', 10}};
    expr->accept(ev);
    assert(ev.result == 10);
}

void test_simple_operation() {
    // 2 + 3
    auto expr = parseExpression("23+");
    
    DisplayVisitor dv;
    expr->accept(dv);
    assert(dv.result == "(2 + 3)");
    
    EvalVisitor ev;
    expr->accept(ev);
    assert(ev.result == 5);
}

void test_complex_expression() {
    // (x + 1) * y
    auto expr = parseExpression("x1+y*");
    
    DisplayVisitor dv;
    expr->accept(dv);
    assert(dv.result == "((x + 1) * y)");
    
    EvalVisitor ev;
    ev.varValues = {{'x', 2}, {'y', 3}};
    expr->accept(ev);
    assert(ev.result == 9);
}