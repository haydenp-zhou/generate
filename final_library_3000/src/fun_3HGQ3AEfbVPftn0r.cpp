#include "fun_3HGQ3AEfbVPftn0r.hpp"

int fun_3HGQ3AEfbVPftn0r() {
    // LeetCode Problem: Minimum Absolute Sum Difference

    // Solution class
    class Solution {

    public:
        int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
            int max=0, idx=0;
            long sum=0;
            int len = nums1.size();
            for (int i=0; i<len; i++) {
                int m = abs(nums1[i] - nums2[i]);
                if (max < m) {
                    max = m; 
                    idx = i;
                }
                sum += m ;
            }
            int min = max;
            for (int i=0; i<len; i++) {
                int m = abs(nums1[i] - nums2[idx]);
                if (m < min) {
                    min = m;
                }
            }

            sum -= (max - min);
            return sum % 1000000007 ;
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
        cout << "fun_3HGQ3AEfbVPftn0r: Executed minAbsoluteSumDiff() from Minimum Absolute Sum Difference" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_3HGQ3AEfbVPftn0r: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
