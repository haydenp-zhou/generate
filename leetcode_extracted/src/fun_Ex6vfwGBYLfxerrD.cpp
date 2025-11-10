#include "fun_Ex6vfwGBYLfxerrD.hpp"

int fun_Ex6vfwGBYLfxerrD() {
    // LeetCode Problem: Minimum Cost To Equalize Array

    // Solution class
    class Solution {

    public:
        int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
            static const int MOD = 1e9 + 7;

            const int n = size(nums);
            const int64_t mx = ranges::max(nums);
            int64_t total = mx * n - accumulate(cbegin(nums), cend(nums), 0ll);
            // fill until mx with only cost1 operations
            if (n <= 2 || 2 * cost1 <= cost2) {
                return total * cost1 % MOD;
            }

            int64_t result = numeric_limits<int64_t>::max();
            // fill until mx with more cost2 operations and fewer cost1 operations
            const int64_t mn = ranges::min(nums);
            int64_t cnt1 = max((mx - mn) - (total - (mx - mn)), static_cast<int64_t>(0));
            int64_t cnt2 = total - cnt1;
            result = min(result, (cnt1 + cnt2 % 2) * cost1 + cnt2 / 2 * cost2);

            // fill until mx+x with most cost2 operations and fewest cost1 operations,
            // where x is the max of x s.t. cnt1+x >= (n-1)*x => cnt1 >= (n-2)*x
            const int64_t x = cnt1 / (n - 2);
            cnt1 %= n - 2;
            total += n * x;
            cnt2 = total - cnt1;
            result = min(result, (cnt1 + cnt2 % 2) * cost1 + (cnt2 / 2) * cost2);

            // fill until mx+x+1 or mx+x+2 with nearly all cost2 operations and at most one cost1 operation
            for (int _ = 0; _ < 2; ++_) {  // increase twice is for odd n
                total += n;
                result = min(result, total % 2 * cost1 + total / 2 * cost2);
            }
            return result % MOD;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minCostToEqualizeArray(nums);

        // Print result to prevent optimization
        cout << "fun_Ex6vfwGBYLfxerrD: Executed minCostToEqualizeArray() from Minimum Cost To Equalize Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Ex6vfwGBYLfxerrD: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
