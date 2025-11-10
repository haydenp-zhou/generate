#include "fun_YLHvCMfNlUlR0aNg.hpp"

int fun_YLHvCMfNlUlR0aNg() {
    // LeetCode Problem: Choose Numbers From Two Arrays In Range

    // Solution class
    class Solution {

    public:
        int countSubranges(vector<int>& nums1, vector<int>& nums2) {
            static const int MOD = 1e9 + 7;

            int result = 0;
            unordered_map<int, int> dp;
            for (int i = 0; i < size(nums1); ++i) {
                unordered_map<int, int> new_dp;
                ++new_dp[nums1[i]];
                ++new_dp[-nums2[i]];
                for (const auto& [v, c] : dp) {
                    new_dp[v + nums1[i]] = (new_dp[v + nums1[i]] + c) % MOD;
                    new_dp[v - nums2[i]] = (new_dp[v - nums2[i]] + c) % MOD;
                }
                dp = move(new_dp);
                if (dp.count(0)) {
                    result = (result + dp[0]) % MOD;
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
        volatile auto result = sol.countSubranges(nums);

        // Print result to prevent optimization
        cout << "fun_YLHvCMfNlUlR0aNg: Executed countSubranges() from Choose Numbers From Two Arrays In Range" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YLHvCMfNlUlR0aNg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
