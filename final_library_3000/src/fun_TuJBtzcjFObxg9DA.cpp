#include "fun_TuJBtzcjFObxg9DA.hpp"

int fun_TuJBtzcjFObxg9DA() {
    // LeetCode Problem: Number Of Different Subsequences Gcds

    // Solution class
    class Solution {

    public:
        int countDifferentSubsequenceGCDs(vector<int>& nums) {
            unordered_set<int> nums_set(cbegin(nums), cend(nums));
            int max_num = *max_element(cbegin(nums), cend(nums));
            int result = 0;
            for (int i = 1; i <= max_num; ++i) {
                int d = 0;
                for (int x = i; x <= max_num; x += i) {
                    if (!nums_set.count(x)) {
                        continue;
                    }
                    d = gcd(d, x);  // total time: O(log(min(d, x)) = O(logd), where d keeps the same or gets smaller
                    if (d == i) {
                        ++result;
                        break;
                    }
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countDifferentSubsequenceGCDs(nums);

        // Print result to prevent optimization
        cout << "fun_TuJBtzcjFObxg9DA: Executed countDifferentSubsequenceGCDs() from Number Of Different Subsequences Gcds" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TuJBtzcjFObxg9DA: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
