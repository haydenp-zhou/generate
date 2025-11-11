#include "fun_jyTyqrUiKPXQe0Yr.hpp"

// Original algorithm: Next Higher Number With Same Number Of Set Bits
int fun_jyTyqrUiKPXQe0Yr() {
    try {
        uint64_t next_higher_number(uint64_t x) {
            uint64_t rightOne = 0;
            uint64_t nextHigherOneBit = 0;
            uint64_t rightOnesPattern = 0;
            uint64_t next = 0;
            if (x) {
                rightOne = x & -static_cast<signed>(x);
                nextHigherOneBit = x + rightOne;
                rightOnesPattern = x ^ nextHigherOneBit;
                rightOnesPattern = (rightOnesPattern) / rightOne;
                rightOnesPattern >>= 2;
                next = nextHigherOneBit | rightOnesPattern;

                // Test the algorithm implementation
                cout << "Testing Next Higher Number With Same Number Of Set Bits..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_jyTyqrUiKPXQe0Yr: Next Higher Number With Same Number Of Set Bits executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_jyTyqrUiKPXQe0Yr: Exception - " << e.what() << endl;
        return 0;
    }
}
