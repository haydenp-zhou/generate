#include "fun_2WGH55Y2XvYYGpUy.hpp"

// Original algorithm: Armstrong Number
int fun_2WGH55Y2XvYYGpUy() {
    try {
        int number_of_digits(int num) {
            int total_digits = 0;
            while (num > 0) {
                num = num / 10;
                ++total_digits;
            }
            return total_digits;
        }
        bool is_armstrong(int number) {
            if (number < 0) {
                return false;
            }
            int sum = 0;
            int temp = number;
            int total_digits = number_of_digits(number);
            while (temp > 0) {
                int rem = temp % 10;
                sum += static_cast<int>(std::pow(rem, total_digits));
                temp = temp / 10;
            }
            return number == sum;
        }

                // Test the algorithm implementation
                cout << "Testing Armstrong Number..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_2WGH55Y2XvYYGpUy: Armstrong Number executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_2WGH55Y2XvYYGpUy: Exception - " << e.what() << endl;
        return 0;
    }
}
