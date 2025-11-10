#include <iostream>
#include "FuncRunner.hpp"

int main() {
    std::cout << "LeetCode Functions Library - Test Runner" << std::endl;
    std::cout << "========================================" << std::endl;

    try {
        FuncRunner::initFuncRunner();
        std::cout << "\n✓ All functions executed successfully!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n✗ Error: " << e.what() << std::endl;
        return 1;
    }
}
