#include "fun_3wzc5sBgpNDqrsMw.hpp"

// Original algorithm: Count Of Set Bits
int fun_3wzc5sBgpNDqrsMw() {
    try {
        namespace count_of_set_bits {
        std::uint64_t countSetBits(
            std ::uint64_t n) {  // uint64_t is preferred over int so that
            std::uint64_t count = 0;  // "count" variable is used to count number of set-bits('1')
            while (n != 0) {
                ++count;
                n = (n & (n - 1));

                // Test the algorithm implementation
                cout << "Testing Count Of Set Bits..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_3wzc5sBgpNDqrsMw: Count Of Set Bits executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_3wzc5sBgpNDqrsMw: Exception - " << e.what() << endl;
        return 0;
    }
}
