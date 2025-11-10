#include "fun_QNDLT66Z6pJLoAlM.hpp"

int fun_QNDLT66Z6pJLoAlM() {
    // LeetCode Problem: Burst Balloons

    // Solution class
    class Solution {

    public:
        int maxCoins(vector<int>& nums) {
            //remove all of zero item
            nums.erase(remove_if(nums.begin(), nums.end(), [](int n){return n==0;}), nums.end());

            //add 1 for head and tail
            nums.insert(nums.begin(),1);
            nums.push_back(1);

            int n = nums.size();
            vector< vector<int> > matrix(n, vector<int>(n,0));

            return maxCoins_DP(nums, matrix);
            return maxCoins_DC(nums, matrix, 0, n-1);
        }


        //Divide and Conquer
        //
        //  If we seprate the array to two part, left part and right part.
        //
        //  Then, we will find in this problem the left and right become adjacent 
        //  and have effects on the maxCoins in the future.
        //
        //  So, if we think reversely, if the balloon i is the last balloon of all to burst, 
        //  the left and right section now has well defined boundary and do not affect each other! 
        //  Therefore we can do either recursive method with memoization
        //
        int maxCoins_DC(vector<int>& nums, vector<vector<int>>& matrix, int low, int high) {
            if (low + 1 == high) return 0;
            if (matrix[low][high] > 0) return matrix[low][high];
            int result = 0;
            for (int i = low + 1; i < high; ++i){
                result = max(result,  nums[low] * nums[i] * nums[high] 
                                        + maxCoins_DC(nums, matrix, low, i) 
                                        + maxCoins_DC(nums, matrix, i, high));
            }
            matrix[low][high] = result;
            return result;
        }

        //Dynamic Programming
        // 
        //  using the same idea of above 
        //
        int maxCoins_DP(vector<int>& nums, vector<vector<int>>& dp) {
            int n = nums.size();
            for (int k = 2; k < n; ++k) {
                for (int low = 0; low < n - k; low++){
                    int high = low + k;
                    for (int i = low + 1; i < high; ++i)
                        dp[low][high] = max( dp[low][high],
                             nums[low] * nums[i] * nums[high] + dp[low][i] + dp[i][high]);
                }
            }
            return dp[0][n - 1];
        }

    private:
        void printVector(vector<int>& nums) {
            cout << "nums: ";
            for (auto n: nums) {
                cout << n << ' ';
            }
            cout << '\n';
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxCoins(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_QNDLT66Z6pJLoAlM: Executed maxCoins() from Burst Balloons" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QNDLT66Z6pJLoAlM: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
