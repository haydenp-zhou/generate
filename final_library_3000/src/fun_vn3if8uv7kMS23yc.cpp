#include "fun_vn3if8uv7kMS23yc.hpp"

int fun_vn3if8uv7kMS23yc() {
    // LeetCode Problem: Minimum Cost Path With Teleportations

    // Solution class
    class Solution {

    public:
        int minCost(vector<vector<int>>& grid, int k) {
            static const int INF = numeric_limits<int>::max();

            const int m = size(grid), n = size(grid[0]);
            int mx = 0;
            for (const auto& row: grid) {
                const auto& v = ranges::max(row);
                if (v > mx) {
                    mx = v;
                }
            }
            vector<vector<int>> dp(m, vector<int>(n, INF));
            dp[m - 1][n - 1]= 0;
            vector<int> prefix(mx + 1, INF);
            for (int i = 0; i <= k; ++i) {
                for (int r = m - 1; r >= 0; --r) {
                    for (int c = n - 1; c >= 0; --c) {
                        if (r + 1 < m) {
                            if (dp[r + 1][c] + grid[r + 1][c] < dp[r][c]) {
                                dp[r][c] = dp[r + 1][c] + grid[r + 1][c];
                            }
                        }
                        if (c + 1 < n) {
                            if (dp[r][c + 1] + grid[r][c + 1] < dp[r][c]) {
                                dp[r][c] = dp[r][c + 1] + grid[r][c + 1];
                            }
                        }
                        if (prefix[grid[r][c]] < dp[r][c]) {
                            dp[r][c] = prefix[grid[r][c]];
                        }
                    }
                }
                for (int r = 0; r < m; ++r) {
                    for (int c = 0; c < n; ++c) {
                        if (dp[r][c] < prefix[grid[r][c]]) {
                            prefix[grid[r][c]] = dp[r][c];
                        }
                    }
                }
                for (int i = 0; i + 1 <= mx; ++i) {
                    if (prefix[i] < prefix[i + 1]) {
                        prefix[i + 1] = prefix[i];
                    }
                }
            }
            return dp[0][0];
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
        volatile auto result = sol.minCost(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_vn3if8uv7kMS23yc: Executed minCost() from Minimum Cost Path With Teleportations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_vn3if8uv7kMS23yc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
