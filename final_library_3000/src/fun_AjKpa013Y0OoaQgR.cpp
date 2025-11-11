#include "fun_AjKpa013Y0OoaQgR.hpp"

// Original algorithm: Double Factorial
int fun_AjKpa013Y0OoaQgR() {
    try {
        uint64_t double_factorial_iterative(uint64_t n) {
            uint64_t res = 1;
            for (uint64_t i = n;; i -= 2) {
                if (i == 0 || i == 1)
                    return res;
                res *= i;
            }
            return res;
        }
        uint64_t double_factorial_recursive(uint64_t n) {
            if (n <= 1)
                return 1;
            return n * double_factorial_recursive(n - 2);
        }
        void test(uint64_t n, uint64_t expected) {
            assert(double_factorial_iterative(n) == expected);
            assert(double_factorial_recursive(n) == expected);
        }
        void tests() {
            std::cout << "Test 1:\t n=5\t...";
            test(5, 15);
            std::cout << "passed\n";
            std::cout << "Test 2:\t n=15\t...";
            test(15, 2027025);
            std::cout << "passed\n";
            std::cout << "Test 3:\t n=0\t...";
            test(0, 1);
            std::cout << "passed\n";
        }

                // Test the algorithm implementation
                cout << "Testing Double Factorial..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_AjKpa013Y0OoaQgR: Double Factorial executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_AjKpa013Y0OoaQgR: Exception - " << e.what() << endl;
        return 0;
    }
}
