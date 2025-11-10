#include "fun_r4pE8GWwc56viofM.hpp"

int fun_r4pE8GWwc56viofM() {
    // LeetCode Problem: Minimum Operations To Make A Uni Value Grid

    // Solution class
    class Solution {

    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for (const auto& row : grid) {
                nums.insert(end(nums), cbegin(row), cend(row));
            }
            int mod_group = -1;
            for (const auto& num : nums) {
                if (mod_group == -1) {
                    mod_group = num % x;
                } else if (mod_group != num % x) {
                    return -1;
                }
            }
            nth_element(begin(nums), begin(nums) + size(nums) / 2, end(nums));
            const auto& median = nums[size(nums) / 2];
            return accumulate(cbegin(nums), cend(nums), 0,
                              [&median, &x](const auto& total, const auto& a) {
                                  return total + abs(a - median) / x;
                              });
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.minOperations(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_r4pE8GWwc56viofM: Executed minOperations() from Minimum Operations To Make A Uni Value Grid" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_r4pE8GWwc56viofM: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
