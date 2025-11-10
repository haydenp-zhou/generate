#include "fun_drmR7lXztpOc3Xf4.hpp"

int fun_drmR7lXztpOc3Xf4() {
    // LeetCode Problem: Maximum Gcd Sum Of A Subarray

    // Solution class
    class Solution {

    public:
        long long maxGcdSum(vector<int>& nums, int k) {
            int64_t result = 0;
            vector<tuple<int, int, int64_t>> dp;
            for (int64_t right = 0, prefix = 0; right < size(nums); ++right) {
                dp.emplace_back(right, nums[right], prefix);
                prefix += nums[right];
                vector<tuple<int, int, int64_t>> new_dp;
                new_dp.reserve(size(dp));
                for (const auto& [left, g, p] : dp) {  // Time: O(logr)
                    const int ng = gcd(g, nums[right]);  // Total Time: O(nlogr)
                    if (empty(new_dp) || get<1>(new_dp.back()) != ng) {
                        new_dp.emplace_back(left, ng, p);  // left and ng are both strictly increasing
                    }
                }
                dp = move(new_dp);
                for (const auto& [left, g, p] : dp) {
                    if (right - left + 1 < k) {
                        break;
                    }
                    result = max(result, (prefix - p) * g);
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxGcdSum(nums);

        // Print result to prevent optimization
        cout << "fun_drmR7lXztpOc3Xf4: Executed maxGcdSum() from Maximum Gcd Sum Of A Subarray" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_drmR7lXztpOc3Xf4: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
