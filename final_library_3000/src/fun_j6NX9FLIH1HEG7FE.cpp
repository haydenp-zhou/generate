#include "fun_j6NX9FLIH1HEG7FE.hpp"

int fun_j6NX9FLIH1HEG7FE() {
    // LeetCode Problem: Minimum Time To Make Array Sum At Most X

    // Solution class
    class Solution {

    public:
        int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
            vector<int> idx(size(nums1));
            iota(begin(idx), end(idx), 0);
            sort(begin(idx), end(idx), [&](const auto& a, const auto& b) {
                return nums2[a] < nums2[b];
            });
            vector<int> dp(size(nums1) + 1);
            for (int i = 0; i < size(idx); ++i) {
                const auto& a = nums1[idx[i]], &b = nums2[idx[i]];
                for (int j = i + 1; j >= 1; --j) {
                    dp[j] = max(dp[j], dp[j - 1] + (a + j * b));
                }
            }
            const auto& total1 = accumulate(cbegin(nums1), cend(nums1), 0);
            const auto& total2 = accumulate(cbegin(nums2), cend(nums2), 0);
            for (int j = 0; j < size(dp); ++j) {
                if ((total1 + j * total2) - dp[j] <= x) {
                    return j;
                }
            }
            return -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minimumTime(nums);

        // Print result to prevent optimization
        cout << "fun_j6NX9FLIH1HEG7FE: Executed minimumTime() from Minimum Time To Make Array Sum At Most X" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_j6NX9FLIH1HEG7FE: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
