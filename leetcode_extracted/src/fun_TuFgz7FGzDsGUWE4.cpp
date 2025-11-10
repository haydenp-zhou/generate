#include "fun_TuFgz7FGzDsGUWE4.hpp"

int fun_TuFgz7FGzDsGUWE4() {
    // LeetCode Problem: Integer Replacement

    // Solution class
    class Solution {

    public:
        int integerReplacement(int n) {
            if (n == 2147483647) {
                return 2 + integerReplacement(n / 2 + 1);
            }

            int result = 0;
            while (n != 1) {
                const auto b = n & 3;
                if (n == 3) {
                    --n;
                } else if (b == 3) {
                    ++n;
                } else if (b == 1) {
                    --n;
                } else {
                    n /= 2;
                }
                ++result;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.integerReplacement(n);

        // Print result to prevent optimization
        cout << "fun_TuFgz7FGzDsGUWE4: Executed integerReplacement() from Integer Replacement" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TuFgz7FGzDsGUWE4: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
