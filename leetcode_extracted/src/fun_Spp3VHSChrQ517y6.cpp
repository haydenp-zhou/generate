#include "fun_Spp3VHSChrQ517y6.hpp"

int fun_Spp3VHSChrQ517y6() {
    // LeetCode Problem: Max Dot Product Of Two Subsequences

    // Solution class
    class Solution {

    public:
        int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() < nums2.size()) {
                return maxDotProduct(nums2, nums1);
            }
            vector<vector<int64_t>> dp(2, vector<int64_t>(nums2.size()));
            for (int i = 0; i < nums1.size(); ++i) {
                for (int j = 0; j < nums2.size(); ++j) {
                    dp[i % 2][j] = int64_t(nums1[i]) * nums2[j];
                    if (i && j) {
                        dp[i % 2][j] += max(dp[(i - 1) % 2][j - 1], int64_t(0));
                    }
                    if (i) {
                        dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
                    }
                    if (j) {
                        dp[i % 2][j] = max(dp[i % 2][j], dp[i % 2][j - 1]);
                    }
                }
            }
            return dp[(nums1.size() - 1) % 2].back();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxDotProduct(nums);

        // Print result to prevent optimization
        cout << "fun_Spp3VHSChrQ517y6: Executed maxDotProduct() from Max Dot Product Of Two Subsequences" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Spp3VHSChrQ517y6: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
