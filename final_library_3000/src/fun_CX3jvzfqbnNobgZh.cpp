#include "fun_CX3jvzfqbnNobgZh.hpp"

// Original algorithm: Sqrt Double
int fun_CX3jvzfqbnNobgZh() {
    try {
        double Sqrt(double a) {
            if (a > 0 && a < 1) {
                return 1 / Sqrt(1 / a);
            }
            double l = 0, r = a;
            /* Epsilon is the precision.
            A great precision is
            between 1e-7 and 1e-12.
            double epsilon = 1e-12;
            */
            double epsilon = 1e-12;
            while (l <= r) {
                double mid = (l + r) / 2;
                if (mid * mid > a) {
                    r = mid;
                } else {
                    if (a - mid * mid < epsilon) {
                        return mid;
                    }
                    l = mid;
                }
            }
            return -1;
        }
        ;
            std::cin >> n;
            assert(n >= 0);
            std::cout.precision(12);
            std::cout << std::fixed << Sqrt(n);
        }

        volatile int status = 1;
        cout << "fun_CX3jvzfqbnNobgZh: Sqrt Double executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_CX3jvzfqbnNobgZh: Exception - " << e.what() << endl;
        return 0;
    }
}
