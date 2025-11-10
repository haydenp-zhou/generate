#include "fun_q1prG7jSI65f1Zpl.hpp"

int fun_q1prG7jSI65f1Zpl() {
    // LeetCode Problem: Minimum Absolute Sum Difference

    // Solution class
    class Solution {

    public:
        int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
            static const int MOD = 1e9 + 7;

            vector<int> sorted_nums1(cbegin(nums1), cend(nums1));
            sort(begin(sorted_nums1), end(sorted_nums1));
            int result = 0, max_change = 0;
            for (int i = 0; i < size(nums2); ++i) {
                int diff = abs(nums1[i] - nums2[i]);
                result = (result + diff) % MOD;
                if (diff < max_change) {
                    continue;
                }
                const auto cit = lower_bound(cbegin(sorted_nums1), cend(sorted_nums1), nums2[i]);
                if (cit != cend(sorted_nums1)) {
                    max_change = max(max_change, diff - abs(*cit - nums2[i]));
                }
                if (cit != cbegin(sorted_nums1)) {
                    max_change = max(max_change, diff - abs(*prev(cit) - nums2[i]));
                }
            }
            return (result - max_change + MOD) % MOD;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minAbsoluteSumDiff(nums);

        // Print result to prevent optimization
        cout << "fun_q1prG7jSI65f1Zpl: Executed minAbsoluteSumDiff() from Minimum Absolute Sum Difference" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_q1prG7jSI65f1Zpl: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
