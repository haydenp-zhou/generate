#include "fun_keLl9rrpcvp1k5V9.hpp"

int fun_keLl9rrpcvp1k5V9() {
    // LeetCode Problem: Find The Smallest Divisor Given A Threshold

    // Solution class
    class Solution {

    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int left = 1, right = *max_element(nums.cbegin(), nums.cend());
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(nums, mid, threshold)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool check(const vector<int>& nums, int x, int threshold) {
            return accumulate(nums.cbegin(), nums.cend(), 0,
                              [&x](const auto& a, const auto& b) {
                                  return a + (b - 1) / x + 1;
                              })
                   <= threshold;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.smallestDivisor(nums);

        // Print result to prevent optimization
        cout << "fun_keLl9rrpcvp1k5V9: Executed smallestDivisor() from Find The Smallest Divisor Given A Threshold" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_keLl9rrpcvp1k5V9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
