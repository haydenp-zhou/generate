#include "fun_HHGD9DvzdL8JQcfp.hpp"

int fun_HHGD9DvzdL8JQcfp() {
    // LeetCode Problem: Maximum Weight In Two Bags

    // Solution class
    class Solution {

    public:
        int maxWeight(vector<int>& weights, int w1, int w2) {
            static const int MAX_W = 300;

            vector<bitset<MAX_W + 1>> dp(w1 + 1), new_dp(w1 + 1);
            dp[0][0] = 1;
            for (const auto& w : weights) {
                for (int i = 0; i <= w1; ++i) {
                    new_dp[i] = dp[i] | (i - w >= 0 ? dp[i - w] : 0) | (dp[i] << w);
                }
                swap(dp, new_dp);
            }
            int result = 0;
            for (int i = 0; i <= w1; ++i) {
                for (int j = w2; j >= 0; --j) {
                    if (dp[i][j]) {
                        result = max(result, i + j);
                        break;
                    }
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
        volatile auto result = sol.maxWeight(nums);

        // Print result to prevent optimization
        cout << "fun_HHGD9DvzdL8JQcfp: Executed maxWeight() from Maximum Weight In Two Bags" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HHGD9DvzdL8JQcfp: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
