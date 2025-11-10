#include "fun_4Frnjt7dAc9kOroG.hpp"

int fun_4Frnjt7dAc9kOroG() {
    // LeetCode Problem: Kth Smallest Number In Multiplication Table

    // Solution class
    class Solution {

    public:
        int findKthNumber(int m, int n, int k) {
            int left = 1, right = m * n;
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (count(mid, m, n) >= k) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        int count(int target, int m, int n) {
            auto count = 0;
            for (int i = 1; i <= m; ++i) {
                count += min(target / i , n);
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findKthNumber(n);

        // Print result to prevent optimization
        cout << "fun_4Frnjt7dAc9kOroG: Executed findKthNumber() from Kth Smallest Number In Multiplication Table" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_4Frnjt7dAc9kOroG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
