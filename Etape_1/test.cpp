#include <cassert>
#include "headers/Constante.h"
#include "headers/Variable.h"
#include "headers/Operator_t.h"
#include "headers/Expression.h"
#include "headers/OperatorNode.h"
#include <unordered_map>
#include <memory>
#include <iostream>

void test_simple_operations() {
    std::unordered_map<char, int> context = {{'x', 2}, {'y', 3}, {'z', 4}};
    
    // Test addition
    auto add = std::make_unique<OperatorNode>(
        Operator_t('+'),
        std::make_unique<Constante>(5),
        std::make_unique<Variable>('x', context)
    );
    assert(add->evaluate() == 7);

    // Test multiplication
    auto mult = std::make_unique<OperatorNode>(
        Operator_t('*'),
        std::make_unique<Variable>('y', context),
        std::make_unique<Constante>(4)
    );
    assert(mult->evaluate() == 12);
}

void test_complex_expressions() {
    std::unordered_map<char, int> context = {{'x', 2}, {'y', 3}, {'z', 4}};
    
    // Test (x + y) * (z - 1)
    auto expr1 = std::make_unique<OperatorNode>(
        Operator_t('*'),
        std::make_unique<OperatorNode>(
            Operator_t('+'),
            std::make_unique<Variable>('x', context),
            std::make_unique<Variable>('y', context)
        ),
        std::make_unique<OperatorNode>(
            Operator_t('-'),
            std::make_unique<Variable>('z', context),
            std::make_unique<Constante>(1)
        )
    );
    assert(expr1->evaluate() == 15); // (2 + 3) * (4 - 1) = 5 * 3 = 15

    // Test (x * y + z) * (x + y * z)
    auto expr2 = std::make_unique<OperatorNode>(
        Operator_t('*'),
        std::make_unique<OperatorNode>(
            Operator_t('+'),
            std::make_unique<OperatorNode>(
                Operator_t('*'),
                std::make_unique<Variable>('x', context),
                std::make_unique<Variable>('y', context)
            ),
            std::make_unique<Variable>('z', context)
        ),
        std::make_unique<OperatorNode>(
            Operator_t('+'),
            std::make_unique<Variable>('x', context),
            std::make_unique<OperatorNode>(
                Operator_t('*'),
                std::make_unique<Variable>('y', context),
                std::make_unique<Variable>('z', context)
            )
        )
    );
    assert(expr2->evaluate() == 156); // (2 * 3 + 4) * (2 + 3 * 4) = 10 * 14 = 156
}

void test_edge_cases() {
    std::unordered_map<char, int> context = {{'x', 0}, {'y', 1}};
    
    // Test multiplication by zero
    auto zero_mult = std::make_unique<OperatorNode>(
        Operator_t('*'),
        std::make_unique<Variable>('x', context),
        std::make_unique<Constante>(5)
    );
    assert(zero_mult->evaluate() == 0);
    
    // Test identity operations
    auto identity_add = std::make_unique<OperatorNode>(
        Operator_t('+'),
        std::make_unique<Variable>('y', context),
        std::make_unique<Constante>(0)
    );
    assert(identity_add->evaluate() == 1);
}

int main() {
    try {
        test_simple_operations();
        test_complex_expressions();
        test_edge_cases();
        std::cout << "All additional tests passed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}