#include "fun_Lj8QIC62f3x3hmnE.hpp"

// Original algorithm: Inv Sqrt
int fun_Lj8QIC62f3x3hmnE() {
    try {
        template <typename T = double, char iterations = 2>
        inline T Fast_InvSqrt(T x) {
            using Tint = typename std::conditional<sizeof(T) == 8, std::int64_t,
                                                   std::int32_t>::type;
            T y = x;
            T x2 = y * 0.5;
            Tint i =
                *reinterpret_cast<Tint *>(&y);  // Store floating-point bits in integer
            i = (sizeof(T) == 8 ? 0x5fe6eb50c7b537a9 : 0x5f3759df) -
                (i >> 1);  // Initial guess for Newton's method
            y = *reinterpret_cast<T *>(&i);  // Convert new bits into float
            y = y * (1.5 - (x2 * y * y));  // 1st iteration Newton's method
            if (iterations == 2) {
                y = y * (1.5 - (x2 * y * y));  // 2nd iteration, the more exact result
            }
            return y;
        }
        template <typename T = double>
        T Standard_InvSqrt(T number) {
            T squareRoot = sqrt(number);
            return 1.0f / squareRoot;
        }


        volatile int status = 1;
        cout << "fun_Lj8QIC62f3x3hmnE: Inv Sqrt executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_Lj8QIC62f3x3hmnE: Exception - " << e.what() << endl;
        return 0;
    }
}
