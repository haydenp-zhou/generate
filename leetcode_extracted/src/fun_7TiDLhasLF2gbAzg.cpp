#include "fun_7TiDLhasLF2gbAzg.hpp"

int fun_7TiDLhasLF2gbAzg() {
    // LeetCode Problem: Form Smallest Number From Two Digit Arrays

    // Solution class
    class Solution {

    public:
        int minNumber(vector<int>& nums1, vector<int>& nums2) {
            static const int INF = numeric_limits<int>::max();

            int mn = INF;
            unordered_set<int> lookup(cbegin(nums1), cend(nums1));
            for (const auto& x : nums2) {
                if (lookup.count(x)) {
                    mn = min(mn, x);
                }
            }
            if (mn != INF) {
                return mn;
            }
            int mn1 = *min_element(cbegin(nums1), cend(nums1));
            int mn2 = *min_element(cbegin(nums2), cend(nums2));
            if (mn1 > mn2) {
                swap(mn1, mn2);
            }
            return 10 * mn1 + mn2;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minNumber(nums);

        // Print result to prevent optimization
        cout << "fun_7TiDLhasLF2gbAzg: Executed minNumber() from Form Smallest Number From Two Digit Arrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_7TiDLhasLF2gbAzg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
