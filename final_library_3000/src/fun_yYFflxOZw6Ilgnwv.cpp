#include "fun_yYFflxOZw6Ilgnwv.hpp"

int fun_yYFflxOZw6Ilgnwv() {
    // LeetCode Problem: Move Zeroes

    // Solution class
    class Solution {

    public:
        /* 
         * Solution (Calinescu Valentin)
         * ==============================
         *
         * One solution would be to store the position of the next non-zero element of the array.
         * Every position of the array, starting with position 0, must store this next non-zero
         * element until we can no more do that, case in which we need to add the remaining zeros
         * that we skipped.
         * 
         * 
         * Time Complexity: O(N)
         * Space Complexity: O(1)
         * 
         */
        void moveZeroes(vector<int>& nums) {
            int i = 0, poz = 0;
            for(i = 0; i < nums.size() && poz < nums.size(); i++)
            {
                    while(poz < nums.size() && nums[poz] == 0)
                        poz++;
                    if(poz < nums.size())
                        nums[i] = nums[poz];
                    else
                        i--; // we need 0 on position i, but i is increasing one last time
                    poz++;
            }
            for(; i < nums.size(); i++)
                nums[i] = 0;
        }



        /*
         * Another implemtation which is easy to understand (Hao Chen)
         * ===========================================================
         *
         * We have two pointers to travel the array, assume they named `p1` and `p2`.
         * 
         *   1) `p1` points the tail of current arrays without any ZEROs.
         *   2) `p2` points the head of the rest array which skips the ZEROs.
         * 
         * Then we can just simply move the item from `p2` to `p1`.
         *
         */
        void moveZeroes(vector<int>& nums) {
            int p1=0, p2=0;

            // Find the first ZERO, where is the tail of the array.
            // (Notes: we can simply remove this!)
            for (; p1<nums.size() && nums[p1]!=0; p1++);

            // copy the item from p2 to p1, and skip the ZERO
            for (p2=p1; p2<nums.size(); p2++) {
                if ( nums[p2] == 0 ) continue;
                nums[p1++] = nums[p2]; 
            }    

            //set ZERO for rest items 
            while ( p1<nums.size() ) nums[p1++] = 0;
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.Solution(nums);

        // Print result to prevent optimization
        cout << "fun_yYFflxOZw6Ilgnwv: Executed Solution() from Move Zeroes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_yYFflxOZw6Ilgnwv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
