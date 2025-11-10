#include "fun_g2lyQqWrH2Cnnv3A.hpp"

int fun_g2lyQqWrH2Cnnv3A() {
    // LeetCode Problem: Maximum Profit From Valid Topological Order In Dag

    // Solution class
    class Solution {

    public:
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            vector<int> adj(n);
            for (const auto& e : edges) {
                adj[e[1]] |= 1 << e[0];
            }
            vector<int> dp(1 << n, -1);
            dp[0] = 0;
            for (int mask = 0; mask < size(dp); ++mask) {
                if (dp[mask] == -1) {
                    continue;
                }
                const int l = __builtin_popcount(mask) + 1;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        continue;
                    }
                    if ((mask & adj[i]) == adj[i]) {
                        dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + l * score[i]);
                    }
                }
            }
            return dp.back();
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
        volatile auto result = sol.maxProfit(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_g2lyQqWrH2Cnnv3A: Executed maxProfit() from Maximum Profit From Valid Topological Order In Dag" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_g2lyQqWrH2Cnnv3A: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
