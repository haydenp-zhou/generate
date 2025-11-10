#include "fun_p94LQnlKNu3pkuXr.hpp"

int fun_p94LQnlKNu3pkuXr() {
    // LeetCode Problem: Number Of Good Binary Strings

    // Solution class
    class Solution {

    public:
        int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
            static const int MOD = 1e9 + 7;

            int result = 0;
            const int w = max(oneGroup, zeroGroup) + 1;
            vector<int> dp(w);
            for (int i = 0; i <= maxLength; ++i) {
                dp[i % w] = i == 0 ? 1 : 0;
                if (i - oneGroup >= 0) {
                    dp[i % w] = (dp[i % w] + dp[(i - oneGroup) % w]) % MOD;
                }
                if (i - zeroGroup >= 0 ) {
                    dp[i % w] = (dp[i % w] + dp[(i - zeroGroup) % w]) % MOD;
                }
                if (i >= minLength) {
                    result = (result + dp[i % w]) % MOD;
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.goodBinaryStrings(nums);

        // Print result to prevent optimization
        cout << "fun_p94LQnlKNu3pkuXr: Executed goodBinaryStrings() from Number Of Good Binary Strings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_p94LQnlKNu3pkuXr: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
