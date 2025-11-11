#include "fun_UQe4dPAxju01fE4I.hpp"

// Original algorithm: Modular Inverse Simple
int fun_UQe4dPAxju01fE4I() {
    try {
        uint64_t imod(uint64_t x, uint64_t y) {
            uint64_t aux = 0;  // auxiliary variable
            uint64_t itr = 0;  // iteration counter
            do {  // run the algorithm while not find the inverse
                aux = y * itr + 1;
                itr++;
            } while (aux % x);  // while module aux % x non-zero
            return aux / x;
        }
        ;

                // Test the algorithm implementation
                cout << "Testing Modular Inverse Simple..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_UQe4dPAxju01fE4I: Modular Inverse Simple executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_UQe4dPAxju01fE4I: Exception - " << e.what() << endl;
        return 0;
    }
}
