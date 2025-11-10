#include "fun_DxIZ9wnpLy8GQovj.hpp"

int fun_DxIZ9wnpLy8GQovj() {
    // LeetCode Problem: Minimized Maximum Of Products Distributed To Any Store

    // Solution class
    class Solution {

    public:
        int minimizedMaximum(int n, vector<int>& quantities) {
            int left = 1, right = *max_element(cbegin(quantities), cend(quantities));
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(n, quantities, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool check(int n, const vector<int>& quantities, int x) {
            return accumulate(cbegin(quantities), cend(quantities), 0,
                              [this, &x](const auto& total, const auto& q) {
                                  return total + ceil_divide(q, x);
                              }) <= n;
        }

        int ceil_divide(int a, int b) {
            return (a + (b - 1)) / b;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimizedMaximum(nums);

        // Print result to prevent optimization
        cout << "fun_DxIZ9wnpLy8GQovj: Executed minimizedMaximum() from Minimized Maximum Of Products Distributed To Any Store" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_DxIZ9wnpLy8GQovj: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
