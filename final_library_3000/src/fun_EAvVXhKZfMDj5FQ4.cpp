#include "fun_EAvVXhKZfMDj5FQ4.hpp"

int fun_EAvVXhKZfMDj5FQ4() {
    // LeetCode Problem: Target Sum

    // Solution class
    class Solution {

    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            long int i,j,n,tot=0,sum,zero=0;
            n = nums.size();
            for(i=0;i<n;i++){
                tot+=nums[i];
                if(nums[i]==0){
                    zero++;
                }
            }
            if((S+tot)%2!=0 || S>tot){
                return 0;
            }
            sum = (S+tot)/2;
            int dp[n+1][sum+1];
            for(i=1;i<=sum;i++){
                dp[0][i]= 0;
            }
            for(i=0;i<=n;i++){
                dp[i][0]= 1;
            }
            for(i=1;i<=n;i++){
                for(j=1;j<=sum;j++){
                    if(nums[i-1]==0 || nums[i-1]>j){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                    }
                }
            }
            return pow(2,zero)*dp[n][sum];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.findTargetSumWays(nums);

        // Print result to prevent optimization
        cout << "fun_EAvVXhKZfMDj5FQ4: Executed findTargetSumWays() from Target Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_EAvVXhKZfMDj5FQ4: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
