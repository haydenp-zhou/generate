#include "fun_ewPSzRe1mQQzmUam.hpp"

int fun_ewPSzRe1mQQzmUam() {
    // LeetCode Problem: Max Profit I I I

    // Solution class
    class Solution {

        public:
            int maxProfit(vector<int> &prices) {
                const int n = prices.size();

                if(n < 2)
                    return 0;

                vector<int> f(n, 0);
                vector<int> g(n, 0);

                for(int i = 1, valley = prices[0]; i < n; ++i) {
                    f[i] = max(f[i - 1], prices[i] - valley);
                    valley = min(valley, prices[i]);
                }

                for(int i = n - 2, peak = prices[n - 1]; i >= 0; --i) {
                    g[i] = max(g[i + 1], peak - prices[i]);
                    peak = max(peak, prices[i]);
                }

                int ans = 0;
                for(int i = 0; i < n; ++i) {
                    ans = max(ans, f[i] + g[i]);
                }

                return ans;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxProfit(nums);

        // Print result to prevent optimization
        cout << "fun_ewPSzRe1mQQzmUam: Executed maxProfit() from Max Profit I I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ewPSzRe1mQQzmUam: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
