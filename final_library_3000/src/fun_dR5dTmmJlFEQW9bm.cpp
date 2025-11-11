#include "fun_dR5dTmmJlFEQW9bm.hpp"

// Original algorithm: Fast Power
int fun_dR5dTmmJlFEQW9bm() {
    try {
        template <typename T>
        double fast_power_recursive(T a, T b) {
            if (b < 0)
                return 1.0 / fast_power_recursive(a, -b);
            if (b == 0)
                return 1;
            T bottom = fast_power_recursive(a, b >> 1);
            double result;
            if ((b & 1) == 0)  // case1
                result = bottom * bottom;
            else  // case2
                result = bottom * bottom * a;
            return result;
        }
        template <typename T>
        double fast_power_linear(T a, T b) {
            if (b < 0)
                return 1.0 / fast_power_linear(a, -b);
            double result = 1;
            while (b) {
                if (b & 1)
                    result = result * a;
                a = a * a;
                b = b >> 1;
            }
            return result;
        }
            int64_t a, b;
            std::cin >> a >> b;
            std::cout << a << "^" << b << " = " << fast_power_recursive(a, b)
                      << std::endl;
            std::cout << a << "^" << b << " = " << fast_power_linear(a, b) << std::endl;
            return 0;
        }

        volatile int status = 1;
        cout << "fun_dR5dTmmJlFEQW9bm: Fast Power executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_dR5dTmmJlFEQW9bm: Exception - " << e.what() << endl;
        return 0;
    }
}
