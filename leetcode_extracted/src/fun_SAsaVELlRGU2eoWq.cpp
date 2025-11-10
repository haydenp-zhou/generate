#include "fun_SAsaVELlRGU2eoWq.hpp"

int fun_SAsaVELlRGU2eoWq() {
    // LeetCode Problem: Coin Change

    // Solution class
    class Solution {

    public:
        int coinChange(vector<int>& coins, int amount) {  
            int result = INT_MAX;
            if ( amount == 0 ) return 0;
            if ( amount < 0 ) return -1;
            for (int i=0; i<coins.size(); i++) {
                if ( amount - coins[i] < 0 ) continue;
                int r = coinChange(coins, amount - coins[i]);
                if ( r == -1 ) continue;
                if (result > r )  result = r + 1;
            }
            return result == INT_MAX ? -1 : result;
        }
    }


     /* 
     * Solution 1 - O(N * amount)
     * =========
     *
     * This problem can be solved using dynamic programming, thus building the optimal
     * solution from previous smaller ones. For every coin of value t and every sum of money
     * i the sum can be traced back to a previous sum i - t that was already computed and uses
     * the smallest number of coins possible. This way we can construct every sum i as the
     * minimum of all these previous sums for every coin value. To be sure we'll find a minimum
     * we can populate the solution vector with an amount bigger than the maximum possible, 
     * which is amount + 1(when the sum is made up of only coins of value 1). The only exception
     * is sol[0] which is 0 as we need 0 coins to have a sum of 0. In the end we need to look
     * if the program found a solution in sol[amount] or it remained the same, in which case we
     * can return -1.
     * 
     */
    class Solution {
    public:

        int coinChange(vector<int>& coins, int amount) {
            int sol[amount + 1];
            sol[0] = 0;
            for(int i = 1; i <= amount; i++)
                sol[i] = amount + 1;
            for(int i = 0; i < coins.size(); i++)
            {
                for(int j = coins[i]; j <= amount; j++)
                    sol[j] = min(sol[j], sol[j - coins[i]] + 1);
            }
            if(sol[amount] != amount + 1)
                return sol[amount];
            else
                return -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.coinChange(nums);

        // Print result to prevent optimization
        cout << "fun_SAsaVELlRGU2eoWq: Executed coinChange() from Coin Change" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_SAsaVELlRGU2eoWq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
