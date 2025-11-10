#include "fun_oNsJefAqGTsljzzt.hpp"

int fun_oNsJefAqGTsljzzt() {
    // LeetCode Problem: Race Car

    // Solution class
    class Solution {

    public:
        int racecar(int target) {
            vector<int> dp(target + 1);
            for (int i = 1; i <= target; ++i) {
                int k = bitLength(i);
                if (i == (1 << k) - 1) {
                    dp[i] = k;
                    continue;
                }
                dp[i] = dp[(1 << k) - 1 - i] + k + 1;
                for (int j = 0; j < k; ++j) {
                    dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k + j + 1);
                }
            }
            return dp.back();
        }

    private:
        uint32_t bitLength(uint32_t n) {
            uint32_t left = 1, right = 32;
            while (left <= right) {
                auto mid = left + (right - left) / 2;
                if ((1 << mid) > n) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.racecar(nums);

        // Print result to prevent optimization
        cout << "fun_oNsJefAqGTsljzzt: Executed racecar() from Race Car" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_oNsJefAqGTsljzzt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
