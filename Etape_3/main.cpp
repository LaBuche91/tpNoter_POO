#include <unordered_map>
#include <memory>
#include <iostream>
#include "tests.hpp"

int main() {
    test_simple_constant();
    test_simple_variable();
    test_simple_operation();
    test_complex_expression();
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}