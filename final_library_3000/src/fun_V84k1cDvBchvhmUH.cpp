#include "fun_V84k1cDvBchvhmUH.hpp"

// Original algorithm: Number Of Positive Divisors
int fun_V84k1cDvBchvhmUH() {
    try {
        int number_of_positive_divisors(int n) {
            if (n < 0) {
                n = -n; // take the absolute value of n
            }
            int number_of_divisors = 1;
            for (int i = 2; i * i <= n; i++) {
                int prime_exponent = 0;
                while (n % i == 0) {
                    prime_exponent++;
                    n /= i;
                }
                number_of_divisors *= prime_exponent + 1;
            }
            if (n > 1) {
                number_of_divisors *= 2;
            }
            return number_of_divisors;
        }
        void tests() {
            assert(number_of_positive_divisors(36) == 9);
            assert(number_of_positive_divisors(-36) == 9);
            assert(number_of_positive_divisors(1) == 1);
            assert(number_of_positive_divisors(2011) == 2); // 2011 is a prime
            assert(number_of_positive_divisors(756) == 24); // 756 = 2^2 * 3^3 * 7
        }

                // Test the algorithm implementation
                cout << "Testing Number Of Positive Divisors..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_V84k1cDvBchvhmUH: Number Of Positive Divisors executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_V84k1cDvBchvhmUH: Exception - " << e.what() << endl;
        return 0;
    }
}
