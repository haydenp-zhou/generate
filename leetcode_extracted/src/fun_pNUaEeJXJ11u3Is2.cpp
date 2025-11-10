#include "fun_pNUaEeJXJ11u3Is2.hpp"

int fun_pNUaEeJXJ11u3Is2() {
    // LeetCode Problem: Equal Sum Arrays With Minimum Number Of Operations

    // Solution class
    class Solution {

    public:
        int minOperations(vector<int>& nums1, vector<int>& nums2) {
            if (6 * size(nums1) < 1 * size(nums2) || 6 * size(nums2) < 1 * size(nums1)) {
                return -1;
            }
            vector<int> count(6);
            int diff = accumulate(cbegin(nums2), cend(nums2), 0) - accumulate(cbegin(nums1), cend(nums1), 0);
            if (diff < 0) {
                swap(nums1, nums2);
                diff = -diff;
            }
            for (const auto& num : nums1) {
                ++count[6 - num];
            }
            for (const auto& num : nums2) {
                ++count[num - 1];
            }
            int result = 0;
            for (int i = 5; i >= 1; --i) {
                if (!count[i]) {
                    continue;
                }
                int cnt = min(count[i], (diff + i - 1) / i);
                result += cnt;
                diff -= i * cnt;
                if (diff <= 0) {
                    break;
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
        volatile auto result = sol.minOperations(nums);

        // Print result to prevent optimization
        cout << "fun_pNUaEeJXJ11u3Is2: Executed minOperations() from Equal Sum Arrays With Minimum Number Of Operations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_pNUaEeJXJ11u3Is2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
