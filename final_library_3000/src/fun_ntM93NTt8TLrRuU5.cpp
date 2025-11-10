#include "fun_ntM93NTt8TLrRuU5.hpp"

int fun_ntM93NTt8TLrRuU5() {
    // LeetCode Problem: Best Time To Buy And Sell Stock. I I

    // Solution class
    class Solution {

    public:
        int maxProfit(vector<int>& prices) {
            return maxProfit02(prices);
            return maxProfit01(prices);
        }
        // Solution 1 
        // find all of ranges: which start a valley with the nearest peak after
        // add their delta together 
        //
        int maxProfit01(vector<int> &prices) {

            int max = 0;
            int low = -1;
    	int len = prices.size();
            for (int i=0; i < len - 1; i++){
                //meet the valley, then goes up
                if (prices[i] < prices[i+1] && low < 0 ) {
                    low = i;
                }
                //meet the peak, then goes down
                if (prices[i] > prices[i+1] && low >= 0) {
                    max += ( prices[i] - prices[low] ) ;
                    low = -1; // reset the `low`
                }
            }

            // edge case
            if ( low >= 0 ) {
                max += ( prices[prices.size()-1] - prices[low] );
            }

            return max;
        }

        // Solution 2 
        // if we find we can earn money, we just sell
        int maxProfit02(vector<int>& prices) {
            int profit = 0 ;
            for(int i=1; i< prices.size(); i++) {
                profit += max(0, prices[i] - prices[i-1]);
            }
            return profit;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxProfit(nums);

        // Print result to prevent optimization
        cout << "fun_ntM93NTt8TLrRuU5: Executed maxProfit() from Best Time To Buy And Sell Stock. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ntM93NTt8TLrRuU5: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
