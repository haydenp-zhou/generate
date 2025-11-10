#include "fun_KQy0qZ0YUGLCQeRK.hpp"

int fun_KQy0qZ0YUGLCQeRK() {
    // LeetCode Problem: Find The Least Frequent Digit

    // Solution class
    class Solution {

    public:
        int getLeastFrequentDigit(int n) {
            vector<int> cnt(10);
            for (; n; n /= 10) {
                ++cnt[n % 10];
            }
            int mn = numeric_limits<int>::max();
            for (const auto& x : cnt) {
                if (x) {
                    mn = min(mn, x);
                }
            }
            int i = 0;
            for (; i < size(cnt); ++i) {
                if (cnt[i] == mn) {
                    break;
                }
            }
            return i;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.getLeastFrequentDigit(nums);

        // Print result to prevent optimization
        cout << "fun_KQy0qZ0YUGLCQeRK: Executed getLeastFrequentDigit() from Find The Least Frequent Digit" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KQy0qZ0YUGLCQeRK: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
