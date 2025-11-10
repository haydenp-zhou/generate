#include "fun_QmxfxWh1uzTsekck.hpp"

int fun_QmxfxWh1uzTsekck() {
    // LeetCode Problem: K Concatenation Maximum Sum

    // Solution class
    class Solution {

    public:
        int kConcatenationMaxSum(vector<int>& arr, int k) {
            static const int MOD = 1e9 + 7;
            if (k == 1) {
                return max(maxSubKArray(arr, 1), 0) % MOD;
            }
            return (max(maxSubKArray(arr, 2), 0) +
                    (k - 2) * max(accumulate(arr.cbegin(), arr.cend(), 0ll), 0ll)) % MOD;
        }

    private:
        int maxSubKArray(const vector<int>& nums, int k) {
            int result = numeric_limits<int>::min();
            int curr = numeric_limits<int>::min();
            for (int i = 0; i < k; ++i) {
                for (const auto& x : nums) {
                    curr = (curr == numeric_limits<int>::min()) ? x : max(curr + x, x);
                    result = max(result, curr);
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
        volatile auto result = sol.kConcatenationMaxSum(nums);

        // Print result to prevent optimization
        cout << "fun_QmxfxWh1uzTsekck: Executed kConcatenationMaxSum() from K Concatenation Maximum Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QmxfxWh1uzTsekck: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
