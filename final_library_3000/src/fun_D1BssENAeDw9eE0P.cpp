#include "fun_D1BssENAeDw9eE0P.hpp"

int fun_D1BssENAeDw9eE0P() {
    // LeetCode Problem: Maximum Product Of Three Numbers

    // Solution class
    class Solution {

    public:
        int maximumProduct(vector<int>& nums) {
            auto min1 = numeric_limits<int>::max();
            auto min2 = numeric_limits<int>::max();
            auto max1 = numeric_limits<int>::min();
            auto max2 = numeric_limits<int>::min();
            auto max3 = numeric_limits<int>::min();
            for (const auto& n: nums) {
                if (n <= min1) {
                    min2 = min1;
                    min1 = n;
                } else if (n <= min2) {
                    min2 = n;
                }
                if (n >= max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = n;
                } else if (n >= max2) {
                    max3 = max2;
                    max2 = n;
                } else if (n >= max3) {
                    max3 = n;
                }
            }
            return max(min1 * min2 * max1, max1 * max2 * max3);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maximumProduct(nums);

        // Print result to prevent optimization
        cout << "fun_D1BssENAeDw9eE0P: Executed maximumProduct() from Maximum Product Of Three Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_D1BssENAeDw9eE0P: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
