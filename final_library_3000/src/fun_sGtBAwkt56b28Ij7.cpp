#include "fun_sGtBAwkt56b28Ij7.hpp"

int fun_sGtBAwkt56b28Ij7() {
    // LeetCode Problem: Best Time To Buy And Sell Stock. I I I

    // Solution class
    class Solution {

    public:
        // Dynamic Programming
        //
        //     Considering prices[n], and we have a position "i", we could have
        //       1) the maxProfit1 for prices[0..i]  
        //       2) the maxProfit2 for proices[i..n]
        //
        //    So, 
        //      for 1) we can go through the prices[n] forwardly.
        //          forward[i] = max( forward[i-1], price[i] - lowestPrice[0..i] ) 
        //      for 2) we can go through the prices[n] backwoardly.
        //          backward[i] = max( backward[i+1], highestPrice[i..n] - price[i]) 
        //
        int maxProfit(vector<int> &prices) {
            if (prices.size()<=1) return 0;

            int n = prices.size();

            vector<int> forward(n);
            forward[0] = 0;
            int lowestBuyInPrice = prices[0];
            for(int i=1; i<n; i++){
                forward[i] = max(forward[i-1], prices[i] - lowestBuyInPrice);
                lowestBuyInPrice = min(lowestBuyInPrice, prices[i]);
            }

            vector<int> backward(n);
            backward[n-1] = 0;
            int highestSellOutPrice = prices[n-1];
            for(int i=n-2; i>=0; i--){
                backward[i] = max(backward[i+1], highestSellOutPrice - prices[i]);
                highestSellOutPrice = max(highestSellOutPrice, prices[i]);
            }

            int max_profit = 0;
            for(int i=0; i<n; i++){
                max_profit = max(max_profit, forward[i]+backward[i]);
            }

            return max_profit;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.max(nums);

        // Print result to prevent optimization
        cout << "fun_sGtBAwkt56b28Ij7: Executed max() from Best Time To Buy And Sell Stock. I I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sGtBAwkt56b28Ij7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
