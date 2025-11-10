#include "fun_eG9iNQpoHfmo0284.hpp"

int fun_eG9iNQpoHfmo0284() {
    // LeetCode Problem: String Without Aaa Or Bbb

    // Solution class
    class Solution {

    public:
        string strWithout3a3b(int A, int B) {
            string result;
            bool put_A = false;
            while (A || B) {
                if (result.length() >= 2 &&
                    result.back() == result[result.length() - 2]) {
                    put_A = (result.back() == 'b');
                } else {
                    put_A = (A >= B);
                }
                if (put_A) {
                    --A;
                    result.push_back('a');
                } else {
                    --B;
                    result.push_back('b');
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.strWithout3a3b(s);

        // Print result to prevent optimization
        cout << "fun_eG9iNQpoHfmo0284: Executed strWithout3a3b() from String Without Aaa Or Bbb" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eG9iNQpoHfmo0284: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
