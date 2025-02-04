#include "headers/Constante.h"
#include "headers/Variable.h"
#include "headers/Operator_t.h"
#include "headers/Expression.h"
#include "headers/OperatorNode.h"
#include <unordered_map>
#include <memory>
#include <iostream>
#include "test.hpp"

int main() {
       try {
        test_simple_operations();
        test_complex_expressions();
        test_edge_cases();
        std::cout << "All tests passed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}