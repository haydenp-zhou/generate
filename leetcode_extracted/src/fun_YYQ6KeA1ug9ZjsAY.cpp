#include "fun_YYQ6KeA1ug9ZjsAY.hpp"

int fun_YYQ6KeA1ug9ZjsAY() {
    // LeetCode Problem: Count Stepping Numbers In Range

    // Solution class
    class Solution {

    public:
        int countSteppingNumbers(string low, string high) {
            static const int MOD = 1e9 + 7;

            const auto& f = [](const auto& s) {
                vector<vector<int>> dp(2, vector<int>(10));
                for (int j = 1; j <= s[0] - '0'; ++j) {
                    dp[0][j] = 1;
                }
                bool prefix = true;
                for (int i = 1; i < size(s); ++i) {
                    for (int j = 0; j < 10; ++j) {
                        dp[i % 2][j] = static_cast<int>(j != 0);
                        if (j - 1 >= 0) {
                            dp[i % 2][j] = (dp[i % 2][j] + (((dp[(i - 1) % 2][j - 1] - static_cast<int>(prefix && (s[i - 1] - '0') == j - 1 && j > s[i] - '0' )) % MOD + MOD) % MOD)) % MOD;
                        }
                        if (j + 1 < 10) {
                            dp[i % 2][j] = (dp[i % 2][j] + (((dp[(i - 1) % 2][j + 1] - static_cast<int>(prefix && (s[i - 1] - '0') == j + 1 && j > s[i] - '0' )) % MOD + MOD) % MOD)) % MOD;
                        }
                    }
                    if (abs(s[i] - s[i - 1]) != 1) {
                        prefix = false;
                    }
                }
                return accumulate(cbegin(dp[(size(s) - 1) % 2]), cend(dp[(size(s) - 1) % 2]), 0, [&](const auto& accu, const auto& x) {
                    return (accu + x) % MOD;
                });

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.countSteppingNumbers(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_YYQ6KeA1ug9ZjsAY: Executed countSteppingNumbers() from Count Stepping Numbers In Range" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YYQ6KeA1ug9ZjsAY: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
