#include "fun_1owam6I8BbLep3kV.hpp"

int fun_1owam6I8BbLep3kV() {
    // LeetCode Problem: Min Cost Climbing Stairs

    // Solution class
    class Solution {

        public:
            int minCostClimbingStairs(vector<int>& cost) {
                return minCostClimbingStairs02(cost); 
                return minCostClimbingStairs01(cost); 
            }
            int minCostClimbingStairs01(vector<int>& cost) {
                vector<int> dp(cost.size() , 0);
                dp[0] = cost[0];
                dp[1] = cost[1];
                for (int i=2; i<cost.size(); i++) {
                    dp[i] = min( dp[i-1], dp[i-2] ) + cost[i];
                }
                return min(dp[dp.size()-1], dp[dp.size()-2]);
            }

            int minCostClimbingStairs02(vector<int>& cost) {
                int dp1 = cost[0], dp2 = cost[1];
                for (int i=2; i<cost.size(); i++) {
                    int dp = min( dp1, dp2 ) + cost[i];
                    dp1 = dp2;
                    dp2 = dp;
                }
                return min (dp1, dp2);
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minCostClimbingStairs(nums);

        // Print result to prevent optimization
        cout << "fun_1owam6I8BbLep3kV: Executed minCostClimbingStairs() from Min Cost Climbing Stairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_1owam6I8BbLep3kV: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
