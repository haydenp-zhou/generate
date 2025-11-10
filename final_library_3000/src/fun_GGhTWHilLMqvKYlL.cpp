#include "fun_GGhTWHilLMqvKYlL.hpp"

int fun_GGhTWHilLMqvKYlL() {
    // LeetCode Problem: Best Time To Buy And Sell Stock. I V

    // Solution class
    class Solution {

        public:
            /*
             *  profits[trans, day]
             *  - `trans` represents the number of transactions we've done so far. ( 0 <= trans <= k )
             *  - `day` represents the number of days so far. ( 0 <= day <= prices.size() )
             *
             *  So, we have the initialization as below:
             *
             *  profits[0, day] = 0; // 0 <= day <= prices.size()
             *  profits[trans, 0] = 0; // 0 <= trans <= k
             *
             *  And the iteration logic as below:
             *
             *  profits[trans, day] = max (
             *                              profits[trans, day-1], // same times transactions, but one days before.
             *                              profits[trans-1, i-1] + (prices[day] - prices[i]) // for all of (0 <= i < day )
             *                                                                                // this means find max profit from
             *                                                                                // previous any of days
             *                            )
             *
             */

            int maxProfit(int k, vector<int> &prices) {
                int ndays = prices.size();

                // error case
                if (ndays<=1) return 0;

                // Edge case
                // ---------
                // if the number of transactions is too many, it means we can make
                // as many transactions as we can, that brings us the problem back to
                // Best-Time-To-Buy-And-Sell-Stock-II which can be simply solve in O(n)
                // by using a greedy approach.
                if(k > ndays/2){
                    int sum = 0;
                    for (int i=1; i<ndays; i++) {
                        sum += max(prices[i] - prices[i-1], 0);
                    }
                    return sum;
                }

                return maxProfit_DP03(k, prices);//8ms
                return maxProfit_DP02(k, prices);//8ms
                return maxProfit_DP01(k, prices);//492ms
            }


            //DP solution - O(kn^2) complexity
            int maxProfit_DP01 (int k, vector<int> &prices) {
                int ndays = prices.size();
                vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
                for(int trans=1; trans<=k; trans++) {
                    for (int day=1; day<=ndays; day++) {
                        int m=0;
                        for (int i=1; i<=day; i++) {
                            m = max(m, profits[trans-1][i-1]+ prices[day-1] - prices[i-1]);
                        }
                        profits[trans][day] =  max( profits[trans][day-1], m);
                    }
                }
                return profits[k][ndays];
            }

            //DP solution - O(kn) complexity
            //Actually, we could save the loop in above- for(int i=1; i<=day; i++)
            //Becasue there are so many dupliations

            int maxProfit_DP02 (int k, vector<int> &prices) {

                int ndays = prices.size();

                vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
                vector<int> m(ndays+1, 0); // tracking the max profits of previous days

                for(int trans=1; trans<=k; trans++) {
                    m[0] = profits[trans-1][0] - prices[0];
                    for (int day=1; day<=ndays; day++) {
                        profits[trans][day] =  max( profits[trans][day-1], m[day-1]+prices[day-1]);
                        if (day < ndays) {
                            m[day] = max(m[day-1], profits[trans-1][day] - prices[day]);
                        }
                    }
                }
                return profits[k][ndays];
            }


            // save the memory, remove the m[ ] array
            int maxProfit_DP03 (int k, vector<int> &prices) {
                int ndays = prices.size();
                vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));

                for(int trans=1; trans<=k; trans++) {
                    int m = profits[trans-1][0] - prices[0];
                    for (int day=1; day <= ndays; day++) {
                        profits[trans][day] = max(profits[trans][day-1], m + prices[day-1]);
                        if ( day < ndays ) {
                            m = max(m, profits[trans-1][day] - prices[day]);
                        }
                    }
                }

                return profits[k][ndays];
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.size(nums);

        // Print result to prevent optimization
        cout << "fun_GGhTWHilLMqvKYlL: Executed size() from Best Time To Buy And Sell Stock. I V" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_GGhTWHilLMqvKYlL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
