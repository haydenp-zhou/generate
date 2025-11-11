#include "fun_3e8Yt7ypzzETgiaw.hpp"

// Original algorithm: Binary Exponent
int fun_3e8Yt7ypzzETgiaw() {
    try {
        int binExpo(int a, int b) {
            if (b == 0) {
                return 1;
            }
            int res = binExpo(a, b / 2);
            if (b % 2) {
                return res * res * a;
            } else {
                return res * res;
            }
        }
        int binExpo_alt(int a, int b) {
            int res = 1;
            while (b > 0) {
                if (b % 2) {
                    res = res * a;
                }
                a = a * a;
                b /= 2;
            }
            return res;
        }
         else if (b < 0) {
                std::cout << "Exponent must be positive !!" << std::endl;
            } else {
                int resRecurse = binExpo(a, b);
                std::cout << resRecurse << std::endl;
            }
        }

                // Test the algorithm implementation
                cout << "Testing Binary Exponent..." << endl;
                auto result = binExpo(2, 10, 1000);
                cout << "Result: " << result << endl;

        volatile int status = 1;
        cout << "fun_3e8Yt7ypzzETgiaw: Binary Exponent executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_3e8Yt7ypzzETgiaw: Exception - " << e.what() << endl;
        return 0;
    }
}
