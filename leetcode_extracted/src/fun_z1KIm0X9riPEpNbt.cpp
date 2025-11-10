#include "fun_z1KIm0X9riPEpNbt.hpp"

int fun_z1KIm0X9riPEpNbt() {
    // LeetCode Problem: Constructing Two Increasing Arrays

    // Solution class
    class Solution {

    public:
        int minLargest(vector<int>& nums1, vector<int>& nums2) {
            static const int INF = numeric_limits<int>::max();

            if (size(nums1) < size(nums2)) {
                swap(nums1, nums2);
            }
            vector<int> dp(size(nums2) + 1, INF);
            dp[0] = 0;
            for (int i = 0; i <= size(nums1); ++i) {
                for (int j = 0; j <= size(nums2); ++j) {
                    if (!i && !j) {
                        continue;
                    }
                    int curr = INF;
                    if (i - 1 >= 0) {
                        if (dp[j] != INF) {
                            curr = min(curr, dp[j] + (dp[j] % 2 == nums1[i - 1] % 2 ? 2 : 1));
                        }
                    }
                    if (j - 1 >= 0) {
                        if (dp[j - 1] != INF) {
                            curr = min(curr, dp[j - 1] + (dp[j - 1] % 2 == nums2[j - 1] % 2 ? 2 : 1));
                        }
                    }
                    dp[j] = curr;
                }
            }
            return dp.back();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minLargest(nums);

        // Print result to prevent optimization
        cout << "fun_z1KIm0X9riPEpNbt: Executed minLargest() from Constructing Two Increasing Arrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_z1KIm0X9riPEpNbt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
