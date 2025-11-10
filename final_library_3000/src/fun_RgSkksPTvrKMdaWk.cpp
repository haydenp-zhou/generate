#include "fun_RgSkksPTvrKMdaWk.hpp"

int fun_RgSkksPTvrKMdaWk() {
    // LeetCode Problem: Partition  Equal  Subset  Sum

    // Solution class
    class Solution {

    public:

        // using 0/1 knapsack top down approach
        bool subsetSum(vector<int>& nums, int sum)
        {
            // size = nums+1, sum+1
            bool t[nums.size()+1][sum+1];

            for(int i= 0;i<=nums.size();i++)
            {
                t[i][0] = true;
            }

            for(int i= 0;i<=sum;i++)
            {
                t[0][i] = false;
            }

            t[0][0] = true;

            for(int i= 1;i<nums.size();i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(nums[i-1] <= j)
                    {
                        //get max by including number in the subset || by not including in subset sum
                        t[i][j] = t[i-1][j - nums[i-1]] || t[i-1][j];
                    }
                    else{
                        t[i][j] = t[i-1][j];
                    }
                }
            }
            return t[nums.size()-1][sum];
        }

        bool canPartition(vector<int>& nums) {

            int n = nums.size();

            int sum = 0;
            for(int  i = 0;i<n;i++)
            {
                sum+=nums[i];
            }

            if(sum%2 != 0 )
                return false;

            return subsetSum(nums, sum/2);

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.subsetSum(nums);

        // Print result to prevent optimization
        cout << "fun_RgSkksPTvrKMdaWk: Executed subsetSum() from Partition  Equal  Subset  Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_RgSkksPTvrKMdaWk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
