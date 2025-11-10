#include "fun_BGeJiyo1rIGDQHzf.hpp"

int fun_BGeJiyo1rIGDQHzf() {
    // LeetCode Problem: Maximize Score After N Operations

    // Solution class
    class Solution {

    public:
        int maxScore(vector<int>& nums) {
            vector<int> dp(1 << size(nums));
            for (int mask = 3; mask < size(dp); ++mask) {
                int cnt = __builtin_popcount(mask);
                if (cnt % 2) {
                    continue;
                }
                vector<int> bits;
                for (int i = 0, m = mask; m; ++i, m >>= 1) {
                    if (m & 1) {
                        bits.emplace_back(i);
                    }
                }
                for (int i = 0; i < size(bits); ++i) {
                    for (int j = i + 1; j < size(bits); ++j) {
                        dp[mask] = max(dp[mask], cnt / 2 * gcd(nums[bits[i]], nums[bits[j]]) + dp[mask ^ (1 << bits[i]) ^ (1 << bits[j])]);
                    }
                }
            }
            return dp.back();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxScore(nums);

        // Print result to prevent optimization
        cout << "fun_BGeJiyo1rIGDQHzf: Executed maxScore() from Maximize Score After N Operations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BGeJiyo1rIGDQHzf: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
