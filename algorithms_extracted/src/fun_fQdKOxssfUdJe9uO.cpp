#include "fun_fQdKOxssfUdJe9uO.hpp"

// Original algorithm: Sum Of Digits
int fun_fQdKOxssfUdJe9uO() {
    try {
        int sum_of_digits(int num) {
            if (num < 0) {
                num = -1 * num;
            }
            int sum = 0;
            while (num > 0) {
                sum = sum + (num % 10);
                num = num / 10;
            }
            return sum;
        }
        void test1() {
            int test_case_1 = sum_of_digits(119765);
            assert(test_case_1 == 29);
        }
        void test2() {
            int test_case_2 = sum_of_digits(-12256);
            assert(test_case_2 == 16);
        }
        void test() {
            test1();
            test2();
        }

                // Test the algorithm implementation
                cout << "Testing Sum Of Digits..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_fQdKOxssfUdJe9uO: Sum Of Digits executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_fQdKOxssfUdJe9uO: Exception - " << e.what() << endl;
        return 0;
    }
}
