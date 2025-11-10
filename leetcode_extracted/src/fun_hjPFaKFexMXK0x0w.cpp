#include "fun_hjPFaKFexMXK0x0w.hpp"

int fun_hjPFaKFexMXK0x0w() {
    // LeetCode Problem: Find The Largest Almost Missing Integer

    // Solution class
    class Solution {

    public:
        int largestInteger(vector<int>& nums, int k) {
            if (k == size(nums)) {
                return ranges::max(nums);
            }
            unordered_map<int, int> cnt;
            for (const auto& x : nums) {
                ++cnt[x];
            }
            int result = -1;
            if (k == 1) {
                for (const auto& [x, v] : cnt) {
                    if (v == 1) {
                        result = max(result, x);
                    }
                }
                return result;
            }
            if (cnt[nums[0]] == 1) {
                result = max(result, nums[0]);
            }
            if (cnt[nums.back()] == 1) {
                result = max(result, nums.back());
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
        volatile auto result = sol.largestInteger(nums);

        // Print result to prevent optimization
        cout << "fun_hjPFaKFexMXK0x0w: Executed largestInteger() from Find The Largest Almost Missing Integer" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hjPFaKFexMXK0x0w: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
