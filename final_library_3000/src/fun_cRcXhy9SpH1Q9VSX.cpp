#include "fun_cRcXhy9SpH1Q9VSX.hpp"

int fun_cRcXhy9SpH1Q9VSX() {
    // LeetCode Problem: Remove Element

    // Solution class
    class Solution {

    public:
        int removeElement(vector<int>& nums, int val) {
            int pos = 0;
            for (int i=0; i<nums.size(); i++){
                if (nums[i] != val){
                    nums[pos++] = nums[i]; 
                }
            }
            return pos;
        }

        int removeElement(int A[], int n, int elem) {
            int tail = n-1;
            int i = 0;
            while ( i<=tail ){
                if (A[i]==elem){
                    A[i] = A[tail--];
                    continue;
                }
                i++;
            }

            return tail+1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.removeElement(nums);

        // Print result to prevent optimization
        cout << "fun_cRcXhy9SpH1Q9VSX: Executed removeElement() from Remove Element" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_cRcXhy9SpH1Q9VSX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
