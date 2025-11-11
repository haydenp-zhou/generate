#include "fun_CcnbOXLR6cZRwKuN.hpp"

// Original algorithm: Count Of Trailing Ciphers In Factorial N
int fun_CcnbOXLR6cZRwKuN() {
    try {
        namespace count_of_trailing_ciphers_in_factorial_n {
        uint64_t numberOfCiphersInFactorialN(uint64_t n) {
            uint64_t count = 0;
            for (uint64_t i = 5; n / i >= 1; i *= 5) {
                count += static_cast<uint64_t>(n) / i;

                // Test the algorithm implementation
                cout << "Testing Count Of Trailing Ciphers In Factorial N..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_CcnbOXLR6cZRwKuN: Count Of Trailing Ciphers In Factorial N executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_CcnbOXLR6cZRwKuN: Exception - " << e.what() << endl;
        return 0;
    }
}
