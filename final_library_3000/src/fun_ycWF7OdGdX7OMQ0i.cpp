#include "fun_ycWF7OdGdX7OMQ0i.hpp"

int fun_ycWF7OdGdX7OMQ0i() {
    // LeetCode Problem: Count Pairs With Xor In A Range

    // Solution class
    class Solution {

    public:
        int countPairs(vector<int>& nums, int low, int high) {
            return count(nums, high + 1) - count(nums, low);
        }

    private:
        int count(const vector<int>& nums, int x) {
            unordered_map<int, int> dp;
            for (const auto& x : nums) {
                ++dp[x];
            }
            int result = 0;
            for (; x; x >>= 1) {
                unordered_map<int, int> new_dp;
                for (auto const& [k, v] : dp) {
                    new_dp[k >> 1] += v;
                    if ((x & 1) == 0) {
                        continue;
                    }
                    if (dp.count((x ^ 1) ^ k)) {
                        result += v * dp[(x ^ 1) ^ k];  // current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
                    }
                }
                dp = move(new_dp);
            }
            return result / 2;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countPairs(nums);

        // Print result to prevent optimization
        cout << "fun_ycWF7OdGdX7OMQ0i: Executed countPairs() from Count Pairs With Xor In A Range" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ycWF7OdGdX7OMQ0i: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
