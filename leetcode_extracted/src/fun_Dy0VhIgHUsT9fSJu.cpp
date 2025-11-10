#include "fun_Dy0VhIgHUsT9fSJu.hpp"

int fun_Dy0VhIgHUsT9fSJu() {
    // LeetCode Problem: Cutting Ribbons

    // Solution class
    class Solution {

    public:
        int maxLength(vector<int>& ribbons, int k) {
            int64_t left = 1, right = accumulate(cbegin(ribbons), cend(ribbons), 0LL) / k;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (!check(ribbons, k, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

    private:
        bool check(const vector<int>& ribbons, int k, int s) {
            return accumulate(cbegin(ribbons), cend(ribbons), 0LL,
                              [&s](auto total, auto x) {
                                  return total + x / s;
                              }) >= k;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxLength(nums);

        // Print result to prevent optimization
        cout << "fun_Dy0VhIgHUsT9fSJu: Executed maxLength() from Cutting Ribbons" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Dy0VhIgHUsT9fSJu: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
