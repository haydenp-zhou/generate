#include "fun_iul7sCriht85C7B0.hpp"

int fun_iul7sCriht85C7B0() {
    // LeetCode Problem: Minimum Size Subarray In Infinite Array

    // Solution class
    class Solution {

    public:
        int minSizeSubarray(vector<int>& nums, int target) {
            static const int INF = numeric_limits<int>::max();

            const int64_t total = accumulate(cbegin(nums), cend(nums), 0ll);
            const int64_t q = target / total;
            target %= total;
            if (!target) {
                return q * size(nums);
            }
            int result = INF;
            int curr = 0;
            for (int right = 0, left = 0; right < (size(nums) - 1) + (size(nums) - 1); ++right) {
                curr += nums[right % size(nums)];
                while (curr > target) {
                    curr -= nums[left++ % size(nums)];
                }
                if (curr == target) {
                    result = min(result, right - left + 1);
                }
            }
            return result != INF ? result + q * size(nums) : -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minSizeSubarray(nums);

        // Print result to prevent optimization
        cout << "fun_iul7sCriht85C7B0: Executed minSizeSubarray() from Minimum Size Subarray In Infinite Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_iul7sCriht85C7B0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
