#include "fun_yhTIEffs9ZWdvZf8.hpp"

int fun_yhTIEffs9ZWdvZf8() {
    // LeetCode Problem: Number Of Ways To Split A String

    // Solution class
    class Solution {

    public:
        int numWays(string s) {
            static const int MOD = 1e9 + 7;
            int ones = count_if(cbegin(s), cend(s),
                                [](const auto& x) {
                                    return x == '1';
                                });
            if (ones % 3) {
                return 0;
            }
            ones /= 3;
            if (ones == 0) {
                return static_cast<int64_t>(s.length() - 1) * (s.length() - 2) / 2 % MOD;
            }
            int count = 0, left = 0, right = 0;
            for (const auto& c : s) {
                if (c == '1') {
                    ++count;
                }
                if (count == ones) {
                    ++left;
                } else if (count == 2 * ones) {
                    ++right;
                }
            }
            return static_cast<int64_t>(left) * right % MOD;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numWays(s);

        // Print result to prevent optimization
        cout << "fun_yhTIEffs9ZWdvZf8: Executed numWays() from Number Of Ways To Split A String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_yhTIEffs9ZWdvZf8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
