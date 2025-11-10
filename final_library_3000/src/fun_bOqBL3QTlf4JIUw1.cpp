#include "fun_bOqBL3QTlf4JIUw1.hpp"

int fun_bOqBL3QTlf4JIUw1() {
    // LeetCode Problem: House Robber. I I

    // Solution class
    class Solution {

    public:
        int orginal_rob(vector<int> &money, int start, int end) {
            int n2=0; 
            int n1=0; 

            for (int i=start; i<end; i++){
                int current = max(n1, n2 + money[i]);
                n2 = n1;
                n1 = current;
            }
            return n1;
        }

        int rob(vector<int>& nums) {
            int n = nums.size();
            switch (n) {
                case 0:
                    return 0;
                case 1:
                    return nums[0];
                case 2:
                    return max(nums[0], nums[1]);
                default:
                    /*
                     * the idea is we cannot rob[0] and rob[n-1] at same time
                     * so, we rob [0 .. n-2] or [1 .. n-1], can return the maxinum one.
                     */
                    int m1 = orginal_rob(nums, 0, n-1);
                    int m2 = orginal_rob(nums, 1, n);

                    return max(m1, m2);
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.orginal_rob(nums);

        // Print result to prevent optimization
        cout << "fun_bOqBL3QTlf4JIUw1: Executed orginal_rob() from House Robber. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_bOqBL3QTlf4JIUw1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
