#include "fun_YcrKjRHRU5bL5p9D.hpp"

int fun_YcrKjRHRU5bL5p9D() {
    // LeetCode Problem: Number Of Subsequences That Satisfy The Given Sum Condition

    // Solution class
    class Solution {

    public:
        int numSubseq(vector<int>& nums, int target) {
            static const int MOD = 1e9 + 7;
            sort(begin(nums), end(nums));
            int result = 0;
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                if (nums[left] + nums[right] > target) {
                    --right;
                } else {
                    result = (result + pow(2, right - left, MOD)) % MOD;
                    ++left;
                }
            }
            return result;
        }

    private:
        uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
            a %= m;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                b >>= 1;
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
        volatile auto result = sol.numSubseq(nums);

        // Print result to prevent optimization
        cout << "fun_YcrKjRHRU5bL5p9D: Executed numSubseq() from Number Of Subsequences That Satisfy The Given Sum Condition" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YcrKjRHRU5bL5p9D: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
