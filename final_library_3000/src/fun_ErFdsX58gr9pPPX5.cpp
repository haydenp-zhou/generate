#include "fun_ErFdsX58gr9pPPX5.hpp"

// Original algorithm: Power For Huge Numbers
int fun_ErFdsX58gr9pPPX5() {
    try {
        #define MAX 100000
        int multiply(int x, int res[], int res_size) {
            int carry = 0;
            for (int i = 0; i < res_size; i++) {
                int prod = res[i] * x + carry;
                res[i] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                res[res_size] = carry % 10;
                carry = carry / 10;
                res_size++;
            }
            return res_size;
        }
        void power(int x, int n) {
            if (n == 0) {
                std::cout << "1";
                return;
            }
            int res[MAX];
            int res_size = 0;
            int temp = x;
            while (temp != 0) {
                res[res_size++] = temp % 10;
                temp = temp / 10;
            }
            for (int i = 2; i <= n; i++) res_size = multiply(x, res, res_size);
            std::cout << x << "^" << n << " = ";
            for (int i = res_size - 1; i >= 0; i--) std::cout << res[i];
        }

                // Test the algorithm implementation
                cout << "Testing Power For Huge Numbers..." << endl;
                auto result = multiply(2, 10, 1000);
                cout << "Result: " << result << endl;

        volatile int status = 1;
        cout << "fun_ErFdsX58gr9pPPX5: Power For Huge Numbers executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_ErFdsX58gr9pPPX5: Exception - " << e.what() << endl;
        return 0;
    }
}
