#include "fun_IGbzmzo9G2Tb4V2c.hpp"

int fun_IGbzmzo9G2Tb4V2c() {
    // LeetCode Problem: Missing Number

    // Solution class
    class Solution {

    public:
        // This problem can be converted to the classic problem --
        //    `There is an array, all of numbers except one appears twice, and that one only appears once`
        // It means, we can combin two arrays together, one is [1..n], another one is `nums`.
        // Then, you know, we can use the XOR solve this problem.

        int missingNumber01(vector<int>& nums) {
            int result = 0;
            for(int i=0; i<nums.size(); i++){
                result ^=  nums[i];
            }
            for(int i=1; i<=nums.size(); i++){
                result ^=(i);
            }
            return result;
        }

        // We can simplify the previous solution as below
        int missingNumber02(vector<int>& nums) {
            int result = 0;
            for(int i=0; i<nums.size(); i++){
                result = result ^ (i+1) ^ nums[i];
            }
            return result;
        }

        int missingNumber(vector<int>& nums) {
            //By Leetcode running result, they all are same performance
            return missingNumber02(nums); //36ms
            return missingNumber01(nums); //36ms
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.missingNumber01(nums);

        // Print result to prevent optimization
        cout << "fun_IGbzmzo9G2Tb4V2c: Executed missingNumber01() from Missing Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_IGbzmzo9G2Tb4V2c: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
