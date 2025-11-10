#include "fun_HW5uX3Z7xSXPlwU0.hpp"

int fun_HW5uX3Z7xSXPlwU0() {
    // LeetCode Problem: Maximum Number Of Integers To Choose From A Range Ii

    // Solution class
    class Solution {

    public:
        int maxCount(vector<int>& banned, int n, long long maxSum) {
            int k = min(static_cast<int>(((-1 + sqrt(1 + 8 * maxSum)) / 2)), n);  // k = argmax((k+1)*k//2 <= maxSum)
            int64_t total = static_cast<int64_t>(k + 1) * k / 2;
            int result = k;
            unordered_set<int> lookup(cbegin(banned), cend(banned));
            for (const auto& x : lookup) {
                if (x <= k) {
                    total -= x;
                    --result;
                }
            }
            for (int i = k + 1; i <= n; ++i) {
                if (lookup.count(i)) {
                    continue;
                }
                if (total + i > maxSum) {
                    break;
                }
                total += i;
                ++result;
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
        volatile auto result = sol.maxCount(nums);

        // Print result to prevent optimization
        cout << "fun_HW5uX3Z7xSXPlwU0: Executed maxCount() from Maximum Number Of Integers To Choose From A Range Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HW5uX3Z7xSXPlwU0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
